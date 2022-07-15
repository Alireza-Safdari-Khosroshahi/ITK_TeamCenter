/*==============================================================================
   Copyright 2007 UGS Corp. All Rights Reserved.
 ==============================================================================*/

/**
    @file

    The BOM module attempts to present a higher level interface to product structure than the PS module,
    at a level that is useful to the programmer writing a user interface to product structure manipulation.

    This interface might be a Product Structure Editor on a workstation, or on a VT100 or PC,
    equally it might be a report --
    eg a bill of materials on a printer or a file to be exported to some other system.

    Basically the BOM module has the concept of windows onto bills of material,
    which consist of lines containing attributes such as item name, structure revision,
    sequence number or user-defined attributes attached to items, item revisions, BOMViews,
    BOMView revisions and occurrences.

    These windows may have different associated configuration rules, so the bills they display may overlap;
    it is the responsibility of the BOM module to ensure that changes made in one window are
    notified to users of other windows which happen to be displaying the same data.
    (Note that this refers to multiple windows within one session,
    this is not attempting to synchronise two separate sessions even if
    they happen to be displaying windows on the same X server display.)

    The simple user of the BOM module, for example someone who wants to print an exploded bill,
    can write a program along the lines of:
    @code
        create BOM Window,  set a configuration rule on it
        open that window on some assemblGG
        print_bill
    @endcode
    where print_bill is a recursive routine that resembles:
    @code
        print data for current line of bill
        if current line has any child lines
            expand child lines
            for each child line, print_bill.
    @endcode
    The programmer writing a Product Structure Editor can create many BOM windows,
    can register callbacks for notification of changes to BOM lines within those windows and
    can do all the obvious operations on given BOM lines (create, delete, modify, enquire attributes).

    <b>Packing</b>

    There is a flag (which defaults to off) to say whether to pack all lines where possible.
    The user can call pack for any particular line,
    in which case it is collapsed with any matching lines in the same assembly.
    Matching is defined by a user-registered callback function,
    which is defaulted to one that compares IRFs and BVRs and if they match deem the lines to match.
    All lines have a pack count attribute, which will be zero for unpacked lines,
    and non-zero for the pack master line.
    Pack master lines may not be modified. Apart from the pack master line packed lines are not reported.
    If a line is packed it will become the master, and all others in the pack will disappear.
*/

/*  */

#ifndef BOM_H_INCLUDED
#define BOM_H_INCLUDED

#include <unidefs.h>

#include <bom/bom_attr.h>
#include <bom/bom_errors.h>
#include <bom/bom_tokens.h>
#include <bom/bomwriter.h>
#include <bom/bomove_errors.h>
#include <fclasses/tc_basic.h>
#include <rdv/rdv.h>
#include <tccore/workspaceobject.h>
#include <common/tc_deprecation_macros.h>

#include <bom/libbom_exports.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*================================================================================================*/
/* END OF HEADER */

/**
    @defgroup BOM Bill Of Materials (BOM)

    The Bill of Material (BOM) module is intended to give a consistent interface to
    the separate elements that make up a line in a BOM. The design assumes that you
    have a BOM window (this can be a printed report or a screen window)
    showing a BOM made up of BOM lines. Each BOM line shows attributes derived from Items,
    Item Revision, occurrences, and so on along with some attributes belonging to the BOM line
    itself and not any of the individual objects the line represents (i.e., is_packed).

    The names of these attributes give a clue as to which object they have been derived from.
    The programmer using them can ignore this and treat them all as BOM line attributes.
    Although some attributes are standard (and listed in bom_attr.h) others are defined at run time
    (i.e., the note types on occurrences) and have to be found by inquiry.

    Since the BOM module keeps all of its windows synchronized, it is possible for changes to
    structure in one window to cause a BOM line in some other window to disappear.
    Therefore, be careful about storing BOM line tags when using multiple windows onto the
    same structure if that structure is open to editing.

    <b>Common Return Values</b>

    <table>
    <tr><td>Return Value</td>             <td>Description</td></tr>
    <tr><td>#BOM_compare_invalid_dest</td><td>The output parameter is set to an illegal value.</td></tr>
    <tr><td>#BOM_compare_invalid_mode</td><td>The mode parameter is not set to one of the legal values.</td></tr>
    <tr><td>#BOM_compare_nested_roots</td><td>The specified BOM lines are nested (i.e., one is an ancestor of the other).</td></tr>
    <tr><td>#BOM_compare_no_report</td>   <td>No report output was generated because a report was not requested by #BOM_compare.</td></tr>
    <tr><td>#VRULE_invalid_rule</td>      <td>The supplied variant rule is not valid.</td></tr>
    </table>
    @{
*/


/**
    @name BOM Setup Functions
    @{
*/

/**
    Initializes the BOM module.
    This function must be called before using any other BOM module functions.
    This function will be called by the standard ITK startup code.
    The ITK programmer can ignore this function.

    @note A second call is ignored.
*/
extern BOM_API int BOM_init_module( void );

/** @} */

extern BOM_API int BOM_exit_module( void );

/**
    @name BOM Window Functions
    @{
*/

/**
    Creates a new BOM window and returns the tag of the newly created window.
*/
extern BOM_API int BOM_create_window(
    tag_t*         window           /**< (O) Tag of the newly created window */
    );

/**
    Closes the BOM window.

    @note Any changes to the structure of the bill in the window will be lost
    unless the #BOM_save_window function is called first.
*/
extern BOM_API int BOM_close_window(
    tag_t          window           /**< (I) Tag of the window */
    );

/**
    Refreshes the BOM window from the database.
*/
extern BOM_API int BOM_refresh_window(
    tag_t          window           /**< (I) Tag of the window */
    );

/**
    Retrieves the Revision (configuration) Rule used by the window.
    <br/>To change the contents of the Revision Rule, edit it using the CFM functions.

    By default, the window will have been created with the user's default Revision Rule.
*/
extern BOM_API int BOM_ask_window_config_rule(
    tag_t          window,                 /**< (I) Window to be modified */
    tag_t*         config_rule             /**< (O) Window's configuration rule */
    );

/**
    Sets the Revision (configuration) Rule for the window.

    By default, the window will have been created with the user's default Revision Rule.
    This function should be used to apply a different Revision Rule to the window.
    All Items in the BOM will automatically be reconfigured using the new Rule.
*/
extern BOM_API int BOM_set_window_config_rule(
    tag_t          window,             /**< (I) Window for which Revision Rule is to be set */
    tag_t          config_rule         /**< (I) Revision Rule to apply to window */
    );

/**
    Sets a flag to say whether BOM lines are packed by default. By default all BOM lines are reported.
    If this function is called to set the default packing true,
    then packable lines will be reported as one BOM line.

    Individual lines can be packed or unpacked by calling #BOM_line_pack or #BOM_line_unpack, respectively.
*/
extern BOM_API int BOM_set_window_pack_all(
    tag_t          window,              /**< (I) Window to have its default packing set */
    logical        pack_all             /**< (I) */
    );

/**
    Retrieves the current setting for various window states.
    The particular state being enquired about is specified by the state argument
    that is one of the BOM_WINDOW_STATE_XXX tokens in bom_tokens.h.
    Currently these include enquiries for pack_by_default,
    show variants, show substitutes and hide unconfigured.
*/
extern BOM_API int BOM_window_ask_state_logical(
    tag_t          window,           /**< (I) Tag of the window */
    int            state,            /**< (I) State to enquire about, defined in bom_tokens.h */
    logical*       answer            /**< (O) Answer */
    );

/**
    Retrieves if @p bom_window skipped by closure rule will be visible.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if @p bom_window is invalid
    </ul>
*/
extern BOM_API int BOM_window_ask_skipped_bomlines_by_closure_rule(
    tag_t          bom_window,       /**< (I) The bom window */
    logical*       answer            /**< (O) Indicates if the bomline skipped by closure rule will be visible or not */
    );

/**
    Sets @p bom_window to either show or not show the skipped bomlines by closure rule.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if @p bom_window is invalid
    </ul>
*/
extern BOM_API int BOM_window_show_skipped_bomlines_by_closure_rule(
    tag_t          bom_window,       /**< (I) The bom window */
    logical        value             /**< (I) value (true or false) indicates if the bomline skipped by closure rule will be visible or not */
    );

/**
    Sets the top line of the BOM window to contain the specified Item.
    If Item is #NULLTAG, then it will use item_revision instead.
    If bom_view is #NULLTAG, then it will take the default.
    Any existing BOM in this window is lost.
*/
extern BOM_API int BOM_set_window_top_line(
    tag_t          window,                 /**< (I) Window to set BOM on */
    tag_t          item,                   /**< (I) Item for top line of Bill (can be #NULLTAG) */
    tag_t          item_revision,          /**< (I) Item revision for top line of Bill (if item is #NULLTAG) */
    tag_t          bv,                     /**< (I) View to use (#NULLTAG implies use default) */
    tag_t*         top_bom_line            /**< (O) Returned top BOM line set on window */
    );

/**
    Sets the top line of the BOM window to contain the specified occurrence group
    which provide its root item and bv as input for loading the bom.
    Any existing BOM in this window is lost.
*/
extern BOM_API int BOM_set_window_top_line_using_occgrp(
    tag_t          window,                 /**< (I) Window to set BOM on */
    tag_t          occGrp,                 /**< (I) occurrence group tag */
    tag_t*         top_bom_line            /**< (O) Returned top BOM line set on window */
    );

/**
    Sets the top line of the BOM window to contain a proxy object representing a part or
    part use from Teamcenter BOM database.
    Any existing BOM in this window is lost.
*/
extern BOM_API int BOM_set_window_top_line_using_proxy(
    tag_t          window,                 /**< (I) Window to set BOM on */
    tag_t          proxy,                  /**< (I) Teamcenter BOM proxy object */
    tag_t*         top_bom_line            /**< (O) Returned top BOM line set on window */
    );

/**
    Sets a top line from a BVR.
    This will not work with shared BVRs (pre-v3.3 concept!): returns #PS_shared_bvr
*/
extern BOM_API int BOM_set_window_top_line_bvr(
    tag_t          window,                 /**< (I) */
    tag_t          bvr,                    /**< (I) */
    tag_t*         top_bom_line            /**< (O) */
    );

/**
    Retrieves the top line of the window. This will be #NULLTAG if no top line has been set.
*/
extern BOM_API int BOM_ask_window_top_line(
    tag_t          window,                 /**< (I) Tag of window */
    tag_t*         top_bom_line            /**< (O) Returns the tag of the top line in this window */
    );

/**
    Gathers whether Options and Variants Engine(OVE) problems should be ignored when we expand lines.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the specified @p bom_window is invalid
    </ul>
*/
extern BOM_API int BOM_ask_window_ignore_ove_errors_on_expand(
    tag_t          bom_window,            /**< (I) The BOMWindow */
    logical*       ignore                 /**< (O) The ignore flag */
    );

/**
    Sets whether Options and Variants Engine(OVE) problems should be ignored when we expand lines.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the specified @p bom_window is invalid
    </ul>
 */
extern BOM_API int BOM_set_window_ignore_ove_errors_on_expand(
    tag_t          bom_window,           /**< (I) The BOMWindow */
    logical        ignore                /**< (I) The ignore flag for @p bom_window */
    );

/**
    Retrieves the level of Options and Variants Engine(OVE) error check that generates actual errors.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the specified @p bom_window is invalid
    </ul>
*/
extern BOM_API int BOM_ask_window_ove_message_error_level(
    tag_t          bom_window,            /**< (I) */
    int*           level                  /**< (O) The level of OVE error check. Expected values are:
                                                    <ul>
                                                    <li>#BOM_OVE_INFO: all will generate errors
                                                    <li>#BOM_OVE_WARN: warnings and above
                                                    <li>#BOM_OVE_ERROR: only errors (default)
                                                    <li>#BOM_OVE_IGNORE_ALL: ignore all
                                                    </ul>
                                                    */
    );

/**
    Sets the level of Options and Variants Engine(OVE) error check that generates actual errors.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the specified @p bom_window is invalid
    </ul>
*/
extern BOM_API int BOM_set_window_ove_message_error_level(
    tag_t          bom_window,          /**< (I) */
    int            level                /**< (I) The level of OVE error check. Expected values are:
                                                    <ul>
                                                    <li>#BOM_OVE_INFO: all will generate errors
                                                    <li>#BOM_OVE_WARN: warnings and above
                                                    <li>#BOM_OVE_ERROR: only errors (default)
                                                    <li>#BOM_OVE_IGNORE_ALL: ignore all
                                                    </ul>
                                                    */
    );

/**
   Retrieves the Active Arrangement set on a BOMWindow.

   @note If a @p bom_window does not have an Active Arrangement the @p arrangement for the BOMWindow will be a NULLTAG.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#BOM_invalid_tag if the specified @p bom_window is invalid
   </ul>
*/
extern BOM_API int BOM_ask_window_active_arrangement(
    tag_t          bom_window,            /**< (I) The BOMWindow to check for the Active Arrangement on */
    tag_t*         arrangement            /**< (O) The Active Arrangement for @p bom_window, can be a NULLTAG */
    );

/**
   Sets the Active Arrangement on a BOMWindow.

   @note The @p arrangement must be an Arrangement that exists on the top-level BOMLine of the @p bom_window.
   <br> Or the @p arrangement can be a NULLTAG which means no Active Arrangement is set on the BOMWindow
        (even if there are arrangements on the top-level BOMLine of the @p bom_window).

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#BOM_invalid_tag if the specified @p bom_window is invalid
   </ul>
*/
extern BOM_API int BOM_set_window_active_arrangement(
    tag_t          bom_window,          /**< (I) The BOMWindow to set the Active Arrangement on */
    tag_t          arrangement          /**< (I) The Active Arrangement to set for @p bom_window, can be a NULLTAG */
    );

/**
   Sets the Ignore Arrangements flag on a BOMWindow.

   The following are the valid values for @p ignore and the expected BOMWindow behavior.
   <ul>
   <li>If @p ignore is set to "false" the @p bom_window will not Ignore Arrangements and allow the BOM to be configured by an Active Arrangement.
   <li>If @p ignore is set to "true" the @p bom_window will Ignore Arrangements and not allow the BOM to be configured by an Active Arrangement.
   </ul>

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#BOM_invalid_tag if the specified @p bom_window is invalid
   </ul>
*/
extern BOM_API int BOM_set_window_ignore_arrangements(
    tag_t          bom_window,         /**< (I) The BOMWindow to set the Ignore Arrangements flag on */
    logical        ignore              /**< (I) The Ignore Arrangements flag to set for @p bom_window */
    );

/**
    Retrieves the effectivity group revision associated with BOMWindow.
*/
extern BOM_API int BOM_window_ask_effectivity_grprevs(
    tag_t          window,                 /**< (I) Window for which EffectivityGroup Revs are to be set */
    int*           count,                  /**< (O) EffectivityGroup Revs set on BOMWindow */
    tag_t**        effGrpRevList           /**< (OF) count EffectivityGroup Revs set on BOMWindow */
    );

/**
    Sets effectivity group revisions on the BOMWindow.
*/
extern BOM_API int BOM_window_set_effectivity_grprevs(
    tag_t          window,                /**< (I) Window for which EffectivityGroup Revs are to be set */
    int            n_effrevs,             /**< (I) Number of effectivity group revisions to be set */
    tag_t *        effGrpRevList          /**< (I)  n_effrevs EffectivityGroup Revs to be set on BOMWindow */
    );

/**
    Determines if the specified BOM window contains a modified bill.
    <br/>This can be useful to know whether you need to call #BOM_save_window in order to update the database.
*/
extern BOM_API int BOM_window_ask_is_modified(
    tag_t          window,              /**< (I) The window you are asking about */
    logical*       is_modified          /**< (O) True if the bill has been modified and needs saving */
    );

/**
    Saves any changes made to BOM lines in the window.

    @note Any changes to the structure of the Bill in the window do not
          get saved to the database until this function is called.
*/
extern BOM_API int BOM_save_window(
    tag_t          window           /**< (I) Tag of the window */
    );

/**
    Removes all pending edits in the specified window.
    <br/>Restores the bomline properties (and underlying occurrence attributes) to original  values.
    <br/>If a bomline has not yet been saved to the database and there are no unsaved modifications,
    deletes the unsaved occurrence. If a bomline had been marked for cut, remove that designation.
*/
extern BOM_API int BOM_window_revert_all_pending_edits(
    tag_t          window           /**< (I) revert all pending edits in this window */
    );

/**
    Removes any pending edits to the specified bom line(s).
    <br/>Restores the bomline properties (and underlying occurrence attributes) to original  values.
    <br/>If a bomline has not yet been saved to the database and there are no unsaved modifications,
    deletes the unsaved occurrence. If a bomline had been marked for cut, remove that designation.
*/
extern BOM_API int BOM_line_revert_pending_edits(
    int            bom_line_count,  /**< (I) number of selected BOM Lines */
    tag_t*         bom_lines        /**< (I) bom_line_count revert all pending edits for these lines */
    );

/**
    Registers a function to define the sort order for lines in this window.
    When #BOM_line_ask_child_lines returns the list of components of some assembly,
    the list will be sorted according to this sort function.
    By default the compare function compares sequence numbers.
    If they are the same then it compares the component item names.

    The supplied function must be of type int function (tag_t line1, tag_t line2, void*client_data).
    It should return -1, 0, +1 according to whether line1 and line 2 should be in that order;
    are equivalent; or should be reversed in order.
    client_data is an arbitrary pointer value supplied by the caller to this function and passed through to the sort function.
*/
extern BOM_API int BOM_set_window_sort_compare_fn(
    tag_t          window,          /**< (I) Window to have its compare function set */
    void*          function,        /**< (I) Compare function to be registered */
    void*          client_data      /**< (I) Pointer value to be passed through to the compare function,
                                            typically as a flag for ascending/descending sort, or an attribute to sort on. */
    );

/** @} */

/**
    @name BOM Line Functions
    @{
*/


/**
   Retrieves the Used Arrangement of a BOMLine.

   @note The @p arrangement can be a NULLTAG which means no Used Arrangement is set on the BOMLine.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#BOM_invalid_tag, the specified @p bomline is invalid, make sure a valid BOMLine tag is being passed in.
   </ul>
*/
extern BOM_API int BOM_line_ask_used_arrangement(
    tag_t           bomline, /**< (I) The BOMLine to check for the Used Arrangement on */
    tag_t           *arrangement /**< (O) The Used Arrangement for @p bomline, can be a NULLTAG */
    );

/**
    Lists the visible ImanItemLines below the specified parent line.
    The first time this function is called it will load the components from the database.
    @note Use the ITK #BOM_line_ask_all_child_lines to retrieve all children including GDELines.
    @note The ITK will clear ADD events from bulletin board queue
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input parent tag is invalid
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_line_ask_child_lines(
    tag_t          bom_line,             /**< (I) Parent BOM line whose children are wanted */
    int*           count,                /**< (O) Number of child lines returned */
    tag_t**        children              /**< (OF) count Returned lines */
    );

/**
    Retrieves all child lines (including GDELine) of a BOMLine
    @note The ITK will clear ADD events from bulletin board queue
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input parent tag is invalid
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_line_ask_all_child_lines(
    tag_t          bom_line,           /**< (I) Parent BOM line whose children are wanted */
    int*           count,              /**< (O) Number of child lines returned */
    tag_t**        children            /**< (OF) count Returned lines */
    );

/**
    Lists just the subset of all visible configured child lines for the given occurrence (thread) tags.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input parent tag is invalid
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_line_subset_child_lines_occs(
      tag_t          bom_line,         /**< (I) Parent BOM line whose children are wanted */
      int            n_occs,           /**< (I) Number of occurrence threads */
      const tag_t *  occs,             /**< (I) n_occs The occurrence (thread) tags for lines to be retrieved */
      int *          n_child_lines,    /**< (O) Number of child lines returned */
      tag_t **       children          /**< (OF) n_child_lines Returned lines */
    );

/**
    Lists just the subset of child lines with occurrence notes that match the given patterns
    (.* pattern matching).
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input parent tag is invalid
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_line_subset_child_lines_occ_notes(
      tag_t          bom_line,         /**< (I) Parent BOM line whose children are wanted */
      tag_t          occ_note_type,    /**< (I) The note type criteria for the query */
      int            n_note_patterns,  /**< (I) Number of note patterns */
      const char **  notes_patterns,   /**< (I) n_note_patterns The note patterns */
      int *          n_child_lines,    /**< (O) Number of child lines returned */
      tag_t **       children          /**< (OF) n_child_lines Returned lines */
    );

/**
    For a line in load state #BOM_line_remote, retrieves the remote object
    (item, or for precise occurrence, item rev) represented by this line.
    For all other lines a #NULLTAG value is given.
*/
extern BOM_API int BOM_line_ask_remote_object(
    tag_t          bom_line,               /**< (I) The BOMLine */
    tag_t*         remote_object           /**< (O) The remote object */
    );


/**
    Cuts the specified line from its parent.
    <br/>The parent structure must be available for the user to modify.
*/
extern BOM_API int BOM_line_cut(
    tag_t          bom_line                 /**< (I) Tag of the line to cut */
    );

/**
    Cuts the pendingcut lines from its parent and move them to the new parent
*/
extern BOM_API int BOM_line_move_to(
    tag_t  new_parent,       /**< (I) Tag of the BOM line to be attached */
    int    count,            /**< (I) Number of BOM lines to be moved */
    tag_t  *bom_lines        /**< (I) count The bom lines to be moved */
    );

/**
    Removes the selected lines and reparent their children to the parent of the removed lines
*/
extern BOM_API int BOM_line_remove_level(
    int    count,       /**< (I) Number of BOM lines to be removed */
    tag_t  *bom_lines   /**< (I) count The BOM lines to be removed */
    );

/**
    Splits a BOM line from the selected line
*/
extern BOM_API int BOM_line_split_occurrence(
    const char * quantity,       /**< (I) Quantity to split from the BOM line */
    tag_t  bom_line              /**< (I) The BOM line to be splitted */
    );

/**
    Replaces the item of the line with the given item (item revision if the original BOM is precise)
*/
extern BOM_API int BOM_line_replace_in_context(
    tag_t  bom_line,        /**< (I) The line to be replace */
    tag_t  item_rev        /**< (I) The item revision to be used for replace */
    );

/**
    Inserts an object (Item, Item Revision or GDE) as a new level above the given BOM line(s).
    @note All lines in @p bom_lines must be under the same parent.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_insert_targets_in_multiple_parents if the lines in @p bom_lines do not all belong to the same parent.
    <li>#CXPOM_wrong_class if @p object is not an Item, Item Revision or GDE.
    <li>Possibly other BOM errors.
    </ul>
*/
extern BOM_API int BOM_line_insert_level(
    int    n_bom_lines,  /**< (I) Number of BOM lines to which to insert a new level */
    tag_t  *bom_lines,   /**< (I) n_bom_lines The BOM lines above which to insert a new level */
    tag_t  object,       /**< (I) The object (Item, Item Revision, or GDE) to be inserted above the given lines as a new level */
    tag_t  view_type     /**< (I) The BOMView type to be used for the new level */
    );

/**
    Adds a copy of the BOMLine to a parent with all attached data including
    transform data, notes, etc. Absolute occurrence and replaces are preserved too.
*/
extern BOM_API int BOM_line_copy(
    tag_t  new_parent,       /**< (I) Tag of the BOM line to be attached */
    tag_t  to_be_copied,     /**< (I) The line to be copied */
    tag_t  view_type,        /**< (I) The BOMView type to be used for the new child if there is none */
    tag_t  *new_line         /**< (O) The new line */
    );

/**
    Fixes broken links
*/
extern BOM_API int BOM_line_fix_broken_links(
    int count,                    /**< (I) number of broken links */
    const tag_t * broken_links,   /**< (I) count broken links */
    const tag_t * candidate_lines /**< (I) count the candidates for the broken links */
    );

/**
    Finds broken links under a BOM line
*/
extern BOM_API int BOM_line_find_broken_links(
    tag_t bom_line,         /**< (I) selected BOM line */
    logical quick_search,   /**< (I) quick search? */
    int * count,            /**< (O) number of broken links */
    tag_t ** broken_links   /**< (OF) count the broken links found */
    );

/**
    Resequences the find numbers of the children of a line based on the predecessor relationship.
*/
extern BOM_API int BOM_line_resequence(
    tag_t  bom_line,     /**< (I) The parent of the BOM lines to resequence find numbers */
    int    start_number, /**< (I) The start number of new find numbers */
    int    incre_number, /**< (I) The incremental number of new find numbers */
    logical recursive    /**< (I) Perform resequence on children? */
    );


/**
    Unloads the BOMViewRevision and any loaded Variant Expressions for the specified line and any descendant BOMLines.
*/
extern BOM_API int BOM_line_unload_below(
    tag_t line                            /**< (I) Tag of the line to unload below */
    );

/**
    Adds a new component to the specified parent line.
    As with setting the top line on an assembly,
    if the Item is specified as #NULLTAG then the Item Revision is used instead.
    If the bom_view is specified as #NULLTAG then the default view is used.
*/
extern BOM_API int BOM_line_add(
    tag_t          bom_line,                   /**< (I) Tag of the line to add the component to */
    tag_t          item_folder,                /**< (I) Item to add (can be #NULLTAG) */
    tag_t          item_revision_folder,       /**< (I) Item Revision to add (if Item is #NULLTAG) */
    tag_t          bv,                         /**< (I) View to use (#NULLTAG implies use default) */
    tag_t*         new_line                    /**< (O) Returned new BOM line */
    );

/**
   Adds a new component to a given line.
   Only enough of item_folder, item_revision_folder, bv and bvr need be given to identify the component.
   The window's configuration rules will be applied to determine the rest.
   If item_revision_folder is given, then a precise occurrence will be created.
*/
extern BOM_API int BOM_line_add_with_occ_type(
    tag_t          bom_line,                   /**< (I) */
    tag_t          item_folder,                /**< (I) */
    tag_t          item_revision_folder,       /**< (I) */
    tag_t          bv,                         /**< (I) */
    char*          occType,                    /**< (I) */
    tag_t*         new_line                    /**< (O) */
    );

/**
    Adds a new gde to given line, and retrieves the gde line
*/
extern BOM_API int BOM_line_add_gde(
    tag_t          bomline,                /**< (I) */
    tag_t          childGDE,               /**< (I) */
    char*          occType,                /**< (I) */
    tag_t*         newLine                 /**< (O) */
    );

/** @} */

/**
    @name BOM Occurrence Sequencing
    @{
*/

/**
    Adds a predecessor to the bom line.

    <b>Restrictions:</b>
    Both bom_line and predline share the same parent bvr.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_cyclic_pred_structure if this relationship creates a circular sequence.
    </ul>
*/
extern BOM_API int BOM_line_add_predecessor(
    tag_t          bom_line,                  /**< (I) Tag of the successor bom line */
    tag_t          predline                   /**< (I) Tag of the predecessor bom line */
    );

/**
    Removes a predecessor from a BOM line.

    <b>Restrictions:</b>
    <OL>
    <LI>Both bom_line and predline must share the same parent bvr.
    <LI>predline is already in the predecessor list of bom_line.
    </OL>
*/
extern BOM_API int BOM_line_remove_predecessor(
    tag_t          bom_line,          /**< (I) Tag of the successor bom line */
    tag_t          predline           /**< (I) Tag of the predecessor bom line */
    );

/**
    Replaces this component instead of adding a new one.
    <br/>You may not change the occurrence from precise to imprecise (or vice-versa) by this routine.

    The component can be specified as either an Item or
    an Item Revision depending on which has a non-#NULLTAG value.
*/
extern BOM_API int BOM_line_replace(
    tag_t          bom_line,                   /**< (I) Tag of the line to replace the component in */
    tag_t          item_folder,                /**< (I) Replacement Item (can be #NULLTAG) */
    tag_t          item_revision_folder,       /**< (I) Replacement Item Revision (if Item is #NULLTAG) */
    tag_t          bv                          /**< (I) Tag of the View for the new child line.
                                                    This tag should be #NULLTAG if the child line has no sub-structure.
                                                    For a line with substructure, use #NULLTAG to use the default bomview. */
    );

/**
    In a single operation, deletes a BOM Line and adds a new one in the Product Structure.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>#BOM_line_get_occ_failed if the Occurrence cannot be retrieved from the deleted or the added BOM Line
    <li>#BOM_no_bvr_in_ir if the BOM View Revision of the deleted or the added BOM Line is invalid
    <li>Possibly other BOM errors
    </ul>
*/

extern BOM_API int BOM_line_change_to_replace(
      tag_t deleted_bom_line,    /**< (I) The tag of the BOM Line to delete. This can be NULLTAG if no BOM Line is to be deleted. */
      tag_t added_bom_line       /**< (I) The tag of the BOM Line to add. This can be NULLTAG if no BOM Line is to be added. */
    );

/**
    Checks if the component in the structure can be replaced by another component.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_line_is_replaceable(
    tag_t          bom_line,               /**< (I) Tag of BOMLine */
    logical*       verdict                 /**< (O) False for GDELine */
    );

/**
    Sets the specified line's BOMView Revision to be precise (precise true) or
    imprecise (precise false).
*/
extern BOM_API int BOM_line_set_precise(
    tag_t          bom_line,                 /**< (I) Tag of the line to set precision on */
    logical        precise                   /**< (I) True if set line precise, false if imprecise */
    );

/**
    Scans all sibling BOM lines in the same parent to see if any can be packed with the specified line.
    If they are, they are packed into this line.
    Subsequent calls to #BOM_line_ask_child_lines on the parent only list this line;
    none of the ones packed into it.

    It is not an error if no lines are found to pack into this one.
    Trying to pack the top line of a bill is not an error, but does nothing (it has no siblings).
*/
extern BOM_API int BOM_line_pack(
    tag_t          bom_line            /**< (I) Tag of the line to pack lines into */
    );

/**
    Unpacks any lines packed into this line.
    It is not an error to call this for a line that has no lines packed into it.
*/
extern BOM_API int BOM_line_unpack(
    tag_t          bom_line            /**< (I) Tag of the line to unpack lines from */
    );

/**
    Checks if the BOM Line is packed.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_line_is_packed(
    tag_t          bom_line,           /**< (I) Tag of BOMLine */
    logical*       verdict             /**< (O) False for GDELine */
    );

/**
    Replaces a GDE for a GDELine
*/
extern BOM_API int BOM_line_replace_gde(
    tag_t          gde_line,            /**< (I) */
    tag_t          new_gde              /**< (I) */
    );

/** @} */

/**
    Takes a logical function (tag_t line_1, tag_t line_2) argument.
    The function should return true if the two lines may be packed.
    Registers a function that compares two BOM lines to see if they can be packed for display purposes.
    By default, BOM lines will be packed if they contain the same Item Revision and the same sequence number.
    The function will never be called when two BOM lines represent different Item Revisions,
    thus BOM lines representing different Item Revisions can not be packed together.

    The function that is registered must be a logical (tag_t bom_line1, tag_t bom_line2) function
    that returns true if the two lines can be packed, and false otherwise.

    @note The function registered by #BOM_set_pack_compare is called differently from Version 7.0.2.
    Previously, two BOM lines that showed different Item Revisions could be packed together by
    the registered function returning true when called with them.
    Now, as a significant performance improvement for some cases,
    the function will never be called for two BOM lines representing the same Item Revision,
    and hence those lines can not be made to pack together.
*/
extern BOM_API int BOM_set_pack_compare(
    void*          function           /**< (I) Function to compare two BOM lines */
    );

/**
    Lists any lines packed into this one.
    It is not an error to call this for a line that has no lines packed into it.

    @note This function does not return the original line; it returns the 'invisible' lines.

    Be aware that this function does not affect the packing of the lines,
    and that for example setting the sequence number of a packed line will not cause re-packing;
    it merely makes the existing packing inconsistent.
    There are side-effects of packing on the 'visible' line.
    Setting its sequence number updates all the packed lines,
    attempts to read some of its attributes
    (i.e., notes that can vary among the packed lines) will return NULL.

    In general it is safer to unpack the lines before operating on them,
    but this can have unwanted side-effects such as updating a PSE display.
*/
extern BOM_API int BOM_line_ask_packed_lines(
    tag_t          bom_line,           /**< (I) Tag of the line to ask pack lines of */
    int*           count,              /**< (O) Number of `hidden' packed lines */
    tag_t**        packed              /**< (OF) count Returned lines */
    );

/**
    Retrieves a list of the predecessor lines of the bom line.
*/
extern BOM_API int BOM_line_list_predecessors(
    tag_t          bom_line,           /**< (I) Tag of the bom line that predecessors are needed for */
    int*           count,              /**< (O) Number of predecessors */
    tag_t**        pred                /**< (OF) count MEM_alloc()ed array of the list of predecessor tags */
    );

/**
    Retrieves the BOM window that contains the specified BOM line.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_line_ask_window(
    tag_t          bom_line,              /**< (I) Tag of the BOM line */
    tag_t*         window                 /**< (O) Tag of the BOM window */
    );

/**
    Flags a BOMLine representing a remote child item/rev,
    or one for which the user does not have read access.
    load_state = #BOM_line_loaded | #BOM_line_remote | #BOM_line_no_read_access
    - defined in bom_tokens.h.
*/
extern BOM_API int BOM_line_ask_load_state(
    tag_t          bom_line,     /**< (I) */
    int*           load_state    /**< (O) */
    );

/**
    @name BOM Attribute Functions

    Used to ask about attributes of a BOM line, and update some of them.
    After updating the attribute, BOM_save_window must be called to commit the change.
    @{
*/

/**
    Lists all the attributes defined for BOM lines.
*/
extern BOM_API int BOM_line_list_attributes(
    int*           count,                 /**< (O) Number of attributes */
    int**          attributes             /**< (OF) count Defined attributes */
    );

/**
    Specified the name of a BOM line attribute, this returns the attribute_id.
*/
extern BOM_API int BOM_line_look_up_attribute(
    const char*    attribute_name,       /**< (I) */
    int*           attribute             /**< (O) */
    );

/**
    Retrieves the BOM line attribute which maps onto an attribute of a super class.
*/
extern BOM_API int BOM_line_look_up_inherited_attr(
    const char*    class_name,           /**< (I) Name of the super class */
    const char*    attribute_name,       /**< (I) Name of the super class attribute */
    int*           attribute             /**< (O) Tag of the equivalent BOM line attribute */
    );

/**
    Retrieves the name of the specified attribute.

    @note This is a unique name that identifies the attribute.
          For a name that should be presented to the user see #BOM_line_ask_attribute_uname.
*/
extern BOM_API int BOM_line_ask_attribute_name(
    int            attribute,                 /**< (I) */
    char**         attribute_name             /**< (OF) */
    );

/**
    Retrieves the user-name of the specified attribute.

    @note This is a name to be presented to the user, it is not necessarily unique.
        In PSE these names are used as keys for the internationalization lookup in tc_text_locale.xml.
*/
extern BOM_API int BOM_line_ask_attribute_uname(
    int            attribute,                 /**< (I) */
    char**         attribute_user_name        /**< (OF) */
    );

/**
    Retrieves the mode of a specified attribute.
    The mode is one of BOM_attribute_mode_\<mode\>, where \<mode\> is
    either string, string_intl, logical, int, tag or double.
    A string should not be subject to internationalization (i.e., it is a person's name).
    A string_intl should be translated before being presented to a user.
*/
extern BOM_API int BOM_line_ask_attribute_mode(
    int            attribute,                   /**< (I) */
    int*           attribute_mode               /**< (O) A value from the #BOM_attribute_mode_t enumerated type */
    );

/**
    Retrieves whether the attribute is a read-only attribute.
    You can never set a read-only attribute.
    The fact that it is not read-only does not necessarily mean
    you can set it on some particular BOM line:
    that line might contain released data that is protected against you.
*/
extern BOM_API int BOM_line_ask_attribute_ro(
    int            attribute,                  /**< (I) */
    logical*       attribute_is_read_only      /**< (O) True if you can never set this attribute */
    );

/**
    Sets the value of some attribute of a BOM line.
*/
extern BOM_API int BOM_line_set_attribute_int(
    tag_t          bom_line,               /**< (I) */
    int            attribute,              /**< (I) */
    int            value                   /**< (I) */
    );

/**
    Retrieves the value of some attribute of a BOM line.
*/
extern BOM_API int BOM_line_ask_attribute_int(
    tag_t          bom_line,                   /**< (I) Tag of the line being enquired about */
    int            attribute,                  /**< (I) */
    int*           value                       /**< (O) Returned result */
    );

/**
    Sets the value of some attribute of a BOM line.
*/
extern BOM_API int BOM_line_set_attribute_logical(
    tag_t          bom_line,             /**< (I) */
    int            attribute,            /**< (I) */
    logical        value                 /**< (I) */
    );

/**
    Retrieves the value of some attribute of a BOM line.
*/
extern BOM_API int BOM_line_ask_attribute_logical(
    tag_t          bom_line,              /**< (I) Tag of the line being enquired about */
    int            attribute,             /**< (I) */
    logical*       value                  /**< (O) Returned result */
    );

/**
    Sets the value of some attribute of a BOM line.
*/
extern BOM_API int BOM_line_set_attribute_tag(
    tag_t          bom_line,                 /**< (I) */
    int            attribute,                /**< (I) */
    tag_t          value                     /**< (I) */
    );

/**
    Retrieves the value of some attribute of a BOM line.
*/
extern BOM_API int BOM_line_ask_attribute_tag(
    tag_t          bom_line,               /**< (I) Tag of the line being enquired about */
    int            attribute,              /**< (I) */
    tag_t*         value                   /**< (O) Returned result */
    );

/**
    Sets the value of some attribute of a BOM line.
*/
extern BOM_API int BOM_line_set_attribute_string(
    tag_t          bom_line,             /**< (I) */
    int            attribute,            /**< (I) */
    const char*    value                 /**< (I) */
    );

/**
    Retrieves the display value of BOM line attribute.
*/
extern BOM_API int BOM_line_ask_attribute_string(
    tag_t          bom_line,             /**< (I) Tag of the line being enquired about */
    int            attribute,            /**< (I) */
    char**         value                 /**< (OF) Returned result */
    );

/**
    Sets the value of some attribute of a BOM line.
*/
extern BOM_API int BOM_line_set_attribute_double(
    tag_t          bom_line,              /**< (I) */
    int            attribute,             /**< (I) */
    double         value                  /**< (I) */
    );

/**
    Retrieves the value of some attribute of a BOM line.
*/
extern BOM_API int BOM_line_ask_attribute_double(
    tag_t          bom_line,              /**< (I) Tag of the line being enquired about */
    int            attribute,             /**< (I) */
    double*        value                  /**< (O) Returned result */
    );

/** @} */

/**
    Clears cache on a BOMView Revision and informs the BOM module that a specified BOMView Revision
    has been modified by calls outside the BOM module.<br>
    In an interactive session the effect will be to update any PSE display
    showing that BOMView Revision to show the new structure.<br>

    @note In ITK programming it will make later #BOM_line_ask_child_lines calls
          in that session return the new structure.
    @note The BOMView Revision object will not be reloaded, but its occurrences will be retrieved from
          matabase, new occurrences will be added and deleted occurrences will be removed.
    @note Occurrence changes will not be updated.

    Calling this function for an unmodified BOMView Revision or for one that
    is not currently in use in any BOM window is harmless.
*/
extern BOM_API int BOM_update_pse(
    tag_t          bvr             /**< (I) Tag of a modified BOMView Revision */
    );

/**
    Marks the BOM View Revision related to the BOM line as modified.
    This allows changes to client data on occurrences to be saved by #BOM_save_window.
*/
extern BOM_API int BOM_modified_bvr(
    tag_t          line              /**< (I) Tag of the BOM line to mark as modified */
    );

/**
    @name BOM Substitute Functions
    @{
*/

/**
    This function returns 'true' for the 'preferred' line of a group of substitutes that represent an occurrence.

    If the line is packed, this function will return 'true' if
    any one of the packed lines has substitutes.
    Note however that in order to access these substitutes you will first need to unpack this line.
*/
extern BOM_API int BOM_line_ask_has_substitutes(
    tag_t          bom_line,               /**< (I) Tag of the BOM line */
    logical*       has_substitutes         /**< (O) True if the BOM line is a preferred substitute */
    );

/**
    Asks if the BOM line is a non-preferred substitute.
*/
extern BOM_API int BOM_line_ask_is_substitute(
    tag_t          bom_line,               /**< (I) Tag of the BOM line */
    logical*       is_substitute           /**< (O) True if the BOM line is a non-preferred substitute */
    );

/**
    Sets the preferred substitute BOM line to display its non-preferred substitutes.
*/
extern BOM_API int BOM_line_show_substitutes(
    tag_t          bom_line                /**< (I) Tag of the BOM line */
    );

/**
    Sets the preferred substitute BOM line to hide its non-preferred substitutes.
*/
extern BOM_API int BOM_line_hide_substitutes(
    tag_t          bom_line                /**< (I) Tag of the BOM line */
    );

/**
    Retrieves a list of substitutes for the BOM line.
*/
extern BOM_API int BOM_line_list_substitutes(
    tag_t          bom_line,               /**< (I) Tag of the BOM line */
    int*           n_substitutes,          /**< (O) Number of substitutes */
    tag_t**        substitute_lines        /**< (OF) n_substitutes Array of tags for the substitute BOM lines */
    );

/**
    Adds a component, identified by the Item, Item Revision, or BOM View as a substitute to the BOM line.
    If the input BOMLine is a packed line, substitute will be added to the packed lines as well.
    Callers only need to provide enough information to unambiguously identify the proposed component.
    #NULLTAG can be supplied instead of unnecessary input tags.
*/
extern BOM_API int BOM_line_add_substitute(
    tag_t          bom_line,               /**< (I) Tag of BOM line to add substitute to */
    tag_t          item,                   /**< (I) Tag of the Item to add as substitute */
    tag_t          item_revision,          /**< (I) Tag of the Item Revision to add as substitute */
    tag_t          bom_view,               /**< (I) Tag of the BOM View to add as substitute */
    tag_t*         new_line                /**< (O) Tag of the new substitute BOM line */
    );

/**
    Sets the non-preferred substitute BOM line to be the preferred substitute.
    The current preferred substitute becomes non-preferred.
    If the parent BOM View Revision cannot be modified,
    the change cannot be saved and the change is marked as temporary.
*/
extern BOM_API int BOM_line_prefer_substitute(
    tag_t          bom_line,               /**< (I) Tag of the BOM line */
    logical*       is_temporary            /**< (O) True if the parent BVR cannot be modified */
    );

/**
    Sets the BOM window to display substitutes.
*/
extern BOM_API int BOM_window_show_substitutes(
    tag_t          bom_window              /**< (I) Tag of the window */
    );

/**
    Sets the BOM window to hide substitutes.
*/
extern BOM_API int BOM_window_hide_substitutes(
    tag_t          bom_window              /**< (I) Tag of the window */
    );

/** @} */

/**
    @name BOM Window Variation Functions

    <b>Common Return Values</b>

    #BOM_variant_error_condition - The new variant data triggered a variant rule check in one
                                   (or more) of the BOM windows being updated.
    @{
*/


/**
    Retrieves different Saved Variant Rules types associated with a given BOM Window,
    depending on the value for the preference "PSM_Enable_product_configurator":
    <ul>
    <li>"true": retrieves Product Configurator Authored Saved Variant Rules applied on given BOM Window.
    <li>"false": retrieves Saved Variant Rules associated with the BOM Variant Rules of given BOM Window (legacy Variant Rules).
    </ul>
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if the given BOM Window is invalid.
    </ul>
 */
extern BOM_API int BOM_window_ask_vrules(
    tag_t        window,                /**< (I) The BOM Window */
    int*         count,                 /**< (O) The Number of saved variant rules associated with BOM Window */
    tag_t**      variant_rules,         /**< (OF) count The Array of saved variant rules. Returned as array of #NULLTAG if there is no Saved Variant Rules. */
    logical**    modified               /**< (OF) count The Array of logical flags. Contain True if any option values have been changed since the current Variant Rule was loaded.
                                              <br/>This includes loading partial variant rules.
                                              <br/>For Product Configurator Authored Variant Rules, a @c true value indicates that the variant rule object is modified in another session. */
    );

/**
    Sets the given variant rule to be the current rule for the given BOM window.
    This call unsets all existing option values prior to loading the new values defined by the rule.
*/
extern BOM_API int BOM_window_apply_full_vrule(
    tag_t          bom_window,             /**< (I) BOM window to query */
    tag_t          vrule                   /**< (I) Variant rule to apply */
    );

/**
    Sets the options in the given BOM window to the values defined in the rule.
    Only those BOM window options which are defined in the rule will have their values changed.
    All other options will remain unaffected.
*/
extern BOM_API int BOM_window_apply_partial_vrule(
    tag_t          bom_window,             /**< (I) BOM window to query */
    tag_t          vrule                   /**< (I) Variant rule to apply */
    );


/**
    Overrides or adds or removes Saved Variant Rules to list of BOM Variant Rules of BOM Window and apply them to BOM Window when BOM Window is in #BOM_var_config_overlay mode.
    It retrieves BOM Variant rules associated with BOM Window after updating and applying Saved Variant Rules.
    The function returns:
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if the given BOM Window is invalid.
    <li>#BOM_window_multiple_variant_rules_unsupported if the given BOM Window is not in #BOM_var_config_overlay mode.
    </ul>
*/
extern BOM_API int BOM_window_apply_overlay_variant_rules(
    tag_t          window,              /**< (I) The BOMWindow */
    int            svr_count,           /**< (I) The Number of Saved Variant Rules, needs to be overidden, added or removed from BOM Window. */
    tag_t*         svr_list,            /**< (I) svr_count The Array of Saved Variant Rules, needs to be overidden, added or removed to list of BOM Variant Rules of BOM Window. */
    int            svr_mode,            /**< (I) The mode of Saved Variant Rule action.
                                            <ul>
                                            <li>#SVRACTION_OVERLAY_ADD_RULE: Use when BOM Window mode is #BOM_var_config_overlay and user wants to add Saved Variant Rule to BOM Window.
                                            <li>#SVRACTION_OVERLAY_REMOVE_RULE: Use when BOM Window mode is #BOM_var_config_overlay and user wants to remove Saved Variant Rule from BOM Window.
                                            <li>#SVRACTION_OVERRIDE_RULE: Use when BOM Window mode changed from #BOM_var_config_singlerule_singlevalue or #BOM_var_config_singlerule_multivalue to #BOM_var_config_overlay. Input Saved Variant Rules will be Overridden to BOM Window.
                                            </ul> */
    int*           count,               /**< (O) The Number of BOM Variant Rules associated with BOM Window. */
    tag_t**        variant_rule_list    /**< (OF) count The Array of current BOM Variant Rule objects of BOM Window. */
    );

/**
    Flags the BOM window to display lines of the BOM,
    even if the line is a not selected by its variant conditions.
*/
extern BOM_API int BOM_window_show_variants(
    tag_t          bom_window           /**< (I) Tag of the BOM window */
    );

/**
    Flags the BOM window to suppress display of lines of the BOM when
    the line is a not selected by its variant conditions.
    After a call to this function,
    #BOM_line_ask_child_lines will not list lines whose variant conditions are not satisfied.
*/
extern BOM_API int BOM_window_hide_variants(
    tag_t          bom_window           /**< (I) Tag of the BOM window */
    );

/** @} */

/**
    Creates a new option with an initial empty revision.

    @note For now mode should only be #BOM_option_mode_enum

    <b>Restrictions:</b>

    At present options are only implemented for enumerated values;
    in the future the mode argument might allow for integer option values.
*/
extern BOM_API int BOM_create_option(
    tag_t          owning_item,         /**< (I) Item to own the new option */
    const char*    name,                /**< (I) Name for the new option */
    const char*    description,         /**< (I) Description the new option (can be NULL) */
    int            mode,                /**< (I) Declares the mode of the option,
                                                currently it can only be #BOM_option_mode_enum. */
    tag_t*         option,              /**< (O) Tag of the newly-created option */
    tag_t*         option_rev           /**< (O) Tag of the initially-created revision */
    );

/**
    Creates a new classic (legacy) option with an initial empty revision,
    and declares the new option against the given Item Revision. After creation of
    options, save the newly created option and save the Item Revision by AOM_save.

    <b>Restrictions:</b>

    At present, options are only implemented for enumerated values;
    in the future the mode argument might allow for integer option values.
*/
extern BOM_API int BOM_new_option(
    tag_t          itemrev,          /**< (I) The Item Revision to declare the new option against.
                                        The option will actually be created against the owning Item. */
    const char*    optname,          /**< (I) Name for the new option */
    const char*    optdesc,          /**< (I) Description for the new option (may be null) */
    int            mode,             /**< (I) The mode of the option, currently it may only be #BOM_option_mode_enum */
    tag_t*         option,           /**< (O) Tag of the newly created option */
    tag_t*         optionrev,        /**< (O) Tag of the initially created option revision */
    tag_t*         ve,               /**< (O) Tag of the option declaration Variant Expression */
    tag_t*         veb               /**< (O) Tag of the Item Revision's Variant Expression Block which
                                        the option declaration is contained in */
    );

/**
    Declares the given option revision against the given Item Revision.
*/
extern BOM_API int BOM_declare_option(
    tag_t          itemrev,       /**< (I) The Item Revision to declare the option revision against */
    tag_t          optionrev,     /**< (I) The option revision to declare */
    tag_t*         ve,            /**< (O) Tag of the option declaration Variant Expression */
    tag_t*         veb            /**< (O) Tag of the Item Revision's Variant Expression Block which
                                        the option declaration is contained in */
    );

/**
    Retrieves the data stored in classic (legacy) option. See also #BOM_list_option_rev_values for option_rev data.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid input option
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_ask_option_data(
    tag_t          option,              /**< (I) Tag of the option */
    tag_t*         owning_item,         /**< (O) Item that owns the option */
    char**         name,                /**< (OF) Option name */
    char**         description          /**< (OF) Option description */
    );



/**
    Changes the name and description of an option.

    <b>Restrictions:</b>

    There is no way to move an option to a different item.
*/
extern BOM_API int BOM_set_option_data(
    tag_t          option,              /**< (I) Tag of the option */
    const char*    name,                /**< (I) New option name */
    const char*    description          /**< (I) New option description */
    );

/**
    Copies an option revision to a new revision.

    <b>Restrictions:</b>

    New revisions always belong to the original option.
*/
extern BOM_API int BOM_revise_option(
    tag_t          revision_in,         /**< (I) Tag of the base revision */
    tag_t*         new_revision         /**< (O) New option revision */
    );

/**
    Retrieves the mode of the specified option revision.

    <b>Restrictions:</b>

    At present all options are of mode #BOM_option_mode_enum.
*/
extern BOM_API int BOM_ask_option_rev_mode(
    tag_t          option_rev,          /**< (I) Tag of the option revision */
    int*           mode                 /**< (O) Its current mode */
    );

/**
    Specified an option revision returns its option.
*/
extern BOM_API int BOM_ask_option_of_rev(
    tag_t          option_rev,          /**< (I) Tag of the revision */
    tag_t*         option               /**< (O) Tag of the corresponding option */
    );

/**
    Retrieves the allowed index values for this classic (legacy) option revision
    (if option values get deleted then their index values do not get reused so
    the list of index values is the list of current ones).

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid input option revision
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_list_option_rev_values(
    tag_t          option_rev,          /**< (I) Tag of the option revision */
    int*           n_values,            /**< (O) Number of allowed values */
    int**          indexes              /**< (OF) n_values List of allowed values */
    );

/**
    Translates the specified index value of a classic (legacy) option into the
    corresponding text.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid input option revision
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_ask_option_rev_value(
    tag_t          option_rev,          /**< (I) Tag of the option revision */
    int            an_index,            /**< (I) Index value */
    char**         value                /**< (OF) Text equivalent */
    );

/**
    Replaces the current text value for the specified index by a new string.
*/
extern BOM_API int BOM_set_option_rev_value(
    tag_t          option_rev,          /**< (I) Tag of the option revision */
    int            an_index,            /**< (I) Index value */
    const char*    value                /**< (I) New text equivalent */
    );

/**
    Adds a new allowed value to the classic (legacy) option revision.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input option_rev associated with invalid Item Revision
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_add_option_rev_value(
    tag_t          option_rev,          /**< (I) Tag of the option revision */
    const char*    value,               /**< (I) New text value */
    int*           an_index             /**< (O) Index for the new value */
    );

/**
    Deletes an allowed value from the option revision.
*/
extern BOM_API int BOM_remove_option_rev_value(
    tag_t          option_rev,          /**< (I) Tag of the option revision */
    int            an_index             /**< (I) Index for the value to delete */
    );

/**
    Converts a specified text string into an index value.

    <b>Restrictions:</b>

    If the value is not valid for the option revision, it returns an index value of -1.
*/
extern BOM_API int BOM_ask_index_of_opt_rev_value(
    tag_t          option_rev,          /**< (I) Tag of the option revision */
    const char*    value,               /**< (I) Text value to look up */
    int*           an_index             /**< (O) Index for that value */
    );

/**
    Asks for the set of classic (legacy) options referenced by the bill being
    displayed in the specified window.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid input window
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_window_ask_options(
    tag_t          window,                   /**< (I) Tag of the BOM window */
    int*           n_options,                /**< (O) Number of options referenced */
    tag_t**        options,                  /**< (OF) n_options Tags of the options */
    tag_t**        option_revisions          /**< (OF) n_options Tags of the exact revisions of those options */
    );



/**
    Sets BOM Variant classic (legacy) option values to given BOM window Variant option. It accepts multiple integer values corresponding
    to enumerated indices of allowed values of BOM Variant.
    The function returns:
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if the given BOM Window or Variant option is invalid.
    <li>#BOM_variant_multiple_values_unsupported if the given BOM Window is in #BOM_var_config_singlerule_singlevalue mode and more than one value provided.
    <li>#BOM_variant_operation_unsupported if the given BOM Window is in #BOM_var_config_overlay mode.
    </ul>
*/
extern BOM_API int BOM_window_set_option_values(
    tag_t          window,        /**< (I) The BOM window tag. */
    tag_t          option,        /**< (I) The Variant option to which values needs to be set. */
    int            value_count,   /**< (I) The Number of values to set to Variant option. */
    int*           values         /**< (I) value_count The Array of integer values for the option.
                                        At present this should be indices into the enumerated list of allowed values. */
    );

/**
    Unsets the option within this window.
*/
extern BOM_API int BOM_window_unset_option_value(
    tag_t          window,             /**< (I) Tag of the BOM window */
    tag_t          option              /**< (I) Tag of the option to be unset */
    );


/**
    Retrieves BOM Variant option values for given BOM window Variant option, along with information as to how it was set.
    The function returns:
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if the given BOM Window or Variant option is invalid.
    </ul>
*/
extern BOM_API int BOM_window_ask_option_values(
    tag_t          window,            /**< (I) The BOM Window tag. */
    tag_t          option,            /**< (I) The Variant option tag. */
    tag_t*         option_rev,        /**< (O) The configured option revision of the Variant option. */
    int*           count,             /**< (O) The Number of values returned. */
    int**          values,            /**< (OF) count The Array of values of the Variant option */
    int**          how_sets,          /**< (OF) count The Array of elements of the #BOM_option_how_set_t enumeration defined in bom_tokens.h.
                                            Reports whether values were set by the user, a Saved Variant Rule, Variant Item or defaulted. */
    char***        where_sets         /**< (OF) count The Array of strings representing source of values. If this option was defaulted or derived then where_set is
                                            returned as the Item Id of the Item that contained the expression that
                                            defined this option value. */
    );

/**
    Looks in the database for an option with the specified name.
    If there are two options with the same name but in different items,
    then the item you want must be supplied;
    if item is specified as #NULLTAG then it will first look in items loaded in the specified window,
    and then in the database. If that gives an ambiguous result, then it returns an error.
*/
extern BOM_API int BOM_window_find_option(
    tag_t          window,               /**< (I) Tag of the BOM window */
    tag_t          item,                 /**< (I) Optional, can by #NULLTAG or a valid item.
                                            If a valid item is specified then it looks for the option in that item. */
    const char*    option_name,          /**< (I) Name of the option to find */
    tag_t*         option,               /**< (O) Tags of the found option */
    tag_t*         option_rev            /**< (O) Tags of the revision of the found option as configured by
                                            the window's configuration rules */
    );

/**
    @name BOM Variant Data Functions
    @{
*/

/**
    Creates a new variant expression. This can be deleted by a call to #AOM_delete.
    If this is the last reference to v1 or v2,
    then #AOM_delete will call itself on v1 and v2 as well.
*/
extern BOM_API int BOM_new_variant_expression(
    tag_t          v1,        /**< (I) The left hand operand */
    int            opcode,    /**< (I) An operator from the BOM_variant_operator_xxx values defined in bom_tokens.h */
    tag_t          v2,        /**< (I) The right hand operand */
    const char*    str,       /**< (I) A string alternative to v2 */
    tag_t*         expr       /**< (O) Tag of the newly-created expression */
    );

/**
    Overwrites a variant expression with new data.
*/
extern BOM_API int BOM_set_variant_expression(
    tag_t          expr,         /**< (I) Tag of the expression */
    tag_t          v1,           /**< (I) The left hand operand */
    int            opcode,       /**< (I) An operator from the BOM_variant_operator_xxx values defined in bom_tokens.h */
    tag_t          v2,           /**< (I) The right hand operand */
    const char*    str           /**< (I) A string alternative to v2 */
    );

/**
    Retrieves the contents of a variant expression.
*/
extern BOM_API int BOM_ask_variant_expression(
    tag_t          expr,     /**< (I) Tag of the expression */
    tag_t*         v1,       /**< (O) The left hand operand */
    int*           opcode,   /**< (O) An operator from the BOM_variant_operator_xxx values defined in bom_tokens.h */
    tag_t*         v2,       /**< (O) The right hand operand */
    char**         str       /**< (OF) A string alternative to v2 */
    );

/**
    Retrieves a variant expression as a text string.
*/
extern BOM_API int BOM_variant_expression_as_text(
    tag_t          expr,           /**< (I) Tag of the expression */
    char**         str             /**< (OF) The expression in a text form */
    );

/**
    Retrieves a newly-created variant expression block.
    To delete it call #AOM_delete, which will call itself recursively on
    any expressions in this block that are not referenced elsewhere.
*/
extern BOM_API int BOM_new_variant_e_block(
    tag_t*         block              /**< (O) Tag of the created block */
    );

/**
    Reads the expressions from a variant expression block.
*/
extern BOM_API int BOM_ask_variant_e_block(
    tag_t          block,              /**< (I) Tag of the expression block */
    int*           n,                  /**< (O) The number of expressions */
    tag_t**        exprs               /**< (OF) n The array of variant expressions */
    );

/**
    Overwrites a variant expression block with new data.
*/
extern BOM_API int BOM_set_variant_e_block(
    tag_t          block,               /**< (I) Tag of the expression block */
    int            n,                   /**< (I) The number of expressions */
    const tag_t*   exprs                /**< (I) n An array of variant expressions to store */
    );

/**
    Retrieves the variant expression block associated with some BOM line.
    A #NULLTAG block implies none set.
*/
extern BOM_API int BOM_line_ask_variant_e_block(
    tag_t          line,           /**< (I) Tag of the BOM line */
    tag_t*         block           /**< (O) The associated variant expression block */
    );

/**
    Sets the variant expression block associated with some BOM line.
    A #NULLTAG block clears the currently set value.
*/
extern BOM_API int BOM_line_set_variant_e_block(
    tag_t          line,           /**< (I) Tag of the BOM line */
    tag_t          block           /**< (I) The associated variant expression block */
    );

/**
    Appends a Variant Expression onto a Variant Expression Block.
*/
extern BOM_API int BOM_variant_e_block_add(
    tag_t          veb,            /**< (I) The tag of the Variant Expression Block to append onto */
    tag_t          ve              /**< (I) The tag of the Variant Expression to add */
    );

/**
    Removes a Variant Expression from a Variant Expression Block.
    This function does not delete the Variant Expression.
*/
extern BOM_API int BOM_variant_e_block_remove(
    tag_t          veb,        /**< (I) The tag of the Variant Expression Block to remove the Variant Expression from */
    tag_t          ve          /**< (I) The tag of the Variant Expression to remove */
    );

/**
    Replaces one Variant Expression in a Variant Expression Block with another.
    This function does not delete the replaced Variant Expression.
*/
extern BOM_API int BOM_variant_e_block_replace(
    tag_t          veb,          /**< (I) The tag of the Variant Expression Block in which to replace the Variant Expression */
    tag_t          veOut,        /**< (I) The tag of the Variant Expression to be replaced */
    tag_t          veIn          /**< (I) The tag of the Variant Expression to be inserted */
    );

/** @} */

/**
    @name BOM Variant Rule Functions
    @{
*/


/**
    Retrieves the current BOM variant rules for the given BOM Window.
    A BOM Variant Rule contains a set of variant options and their current values.
    The function returns:
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if the given BOM Window is invalid.
    </ul>
*/
extern BOM_API int BOM_window_ask_variant_rules(
    tag_t          window,                    /**< (I) The BOM Window to get the current BOM Variant Rules. */
    int*           count,                     /**< (O) The Number of BOM Variant Rule objects. */
    tag_t**        bom_variant_rules          /**< (OF) count The Array of current BOM Variant Rule objects of BOM Window.  */
    );

/**
    Retrieves Variant configuration mode for the given BOM Window. This mode controls the Variant Rule contents
    of BOM Window.
    The function returns:
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if the given BOM Window is invalid.
    </ul>
*/
extern BOM_API int BOM_window_ask_varconfig_mode(
    tag_t          window,                    /**< (I) The BOM Window to get the current variant configuration mode. */
    int*           var_config_mode            /**< (O) This can take one of the following values: <ul>
                                                <li>#BOM_var_config_singlerule_singlevalue: This is default mode.<br>
                                                BOM window can have one variant rule with only single value for any option. </li>
                                                <li>#BOM_var_config_singlerule_multivalue<br>
                                                BOM window can have one variant rule allowing multiple values for any option. </li>
                                                <li>#BOM_var_config_overlay<br>
                                                BOM window can have more than one variant rule allowing multiple values for any option.</li></ul> */
    );

/**
    Sets variant configuration mode for the given BOM Window. This mode will control the Variant Rule contents
    of BOM Window.
    The function returns:
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if the given BOM Window is invalid.
    </ul>
*/
extern BOM_API int BOM_window_set_varconfig_mode(
    tag_t          window,                    /**< (I) The BOM Window to set the variant configuration mode. */
    int            var_config_mode            /**< (I) Set this to one of the following values: <ul>
                                                <li>#BOM_var_config_singlerule_singlevalue<br>
                                                BOM window can have one variant rule with only single value for any option. </li>
                                                <li>#BOM_var_config_singlerule_multivalue<br>
                                                BOM window can have one variant rule allowing multiple values for any option. </li>
                                                <li>#BOM_var_config_overlay<br>
                                                BOM window can have more than one variant rule allowing multiple values for any option.</li></ul> */
    );

/**
    Creates a new copy of the source BOM variant rule,
    either within the same BOM window or in a different BOM window.
    The behavior of this can be controlled via the copy action
    (see #BOM_variant_rule_set_copy_action).
*/
extern BOM_API int BOM_variant_rule_copy(
    tag_t          src_bomvariantlist,    /**< (I) BOM variant rule to copy. Setting this to #NULLTAG will create a copy of
                                                the given BOM window's current rule. */
    tag_t          dst_window,             /**< (I) A BOM window. If src_bomvariantrule is not #NULLTAG,
                                                the new copy of the rule will be attached to this BOM window.
                                                Setting this argument to #NULLTAG will attach the new rule to
                                                the same window as the old rule. If src_bomvariantrule is #NULLTAG,
                                                this BOM window's current rule will be copied,
                                                and the new rule attached to this BOM window. */
    tag_t*         dst_bomvariantlist     /**< (O) The new copy of the source BOM variant rule */
    );

/**
    Sets the mechanism which will be used when copying a BOM variant rule onto
    different BOM variant rules and windows.
    The selected mechanism controls how the destination variant rule is formed as
    a combination of the source rule and the destination rule or window.
    There are three settings for this: source, destination, source and destination.
*/
extern BOM_API int BOM_variant_rule_set_copy_action(
    int            action      /**< (I) Set this to one of the following values: <br>
                                    #BOM_variant_rule_src -
                                    Destination rule will contain the same options as the source rule. <br>
                                    #BOM_variant_rule_src_and_dest -
                                    Destination rule will contain its existing options
                                    (with their values updated to match the source rule)
                                    plus those from the source rule. <br>
                                    #BOM_variant_rule_dest -
                                    Destination rule will contain only its existing options
                                    (but with their values updated to match the source rule). */
    );

/**
    Queries the mechanism which will be used when copying a BOM variant rule
    onto different BOM variant rules and windows.
    This mechanism controls how the destination variant rule is formed,
    as a combination of the source rule and the destination rule or window.
    There are three settings for this: source, destination, source and destination.
*/
extern BOM_API int BOM_variant_rule_ask_copy_action(
    int*           action           /**< (O) Returned as one of the following values: <br>
                                            #BOM_variant_rule_src -
                                            Destination rule will contain the same options and values as the source rule. <br>
                                            #BOM_variant_rule_src_and_dest -
                                            Destination rule will contain its existing options
                                            (with their values updated to match the source rule)
                                            plus those from the source rule. <br>
                                            #BOM_variant_rule_dest -
                                            Destination rule will contain only its existing options
                                            (but with their values updated to match the source rule). */
    );

/**
    Applies the given BOM variant rule to its owning BOM window.
*/
extern BOM_API int BOM_variant_rule_apply(
    tag_t          bomvariantlist          /**< (I) The BOM variant rule to apply */
    );

/**
    Applies the source BOM variant rule to the destination BOM variant rule.
    The behavior of this can be controlled via the copy action
    (see #BOM_variant_rule_set_copy_action).
*/
extern BOM_API int BOM_variant_rule_apply_to(
    tag_t          src_bomvariantlist,          /**< (I) The BOM variant rule to be applied */
    tag_t          dst_bomvariantlist           /**< (I) The BOM variant rule to apply the source rule to */
    );

/**
    Deletes the given BOM variant rule.
    @note Closing a BOM window automatically deletes all BOM variant rules owned by that window.
*/
extern BOM_API int BOM_variant_rule_delete(
    tag_t          bomvariantlist          /**< (I) The BOM variant rule to delete */
    );

/**
    Applies a saved variant rule to the given BOM variant rule.
    This function unsets the BOM variant rule's option values prior to loading the saved rule.
*/
extern BOM_API int BOM_variant_rule_apply_full_vrule(
    tag_t          bomvariantlist,         /**< (I) The BOM variant rule to apply the saved rule to */
    tag_t          vrule,                  /**< (I) The saved variant rule to load */
    logical*       list_changed            /**< (O) Returned as true if the saved variant rule contained any options
                                                which were not previously in the BOM variant rule
                                                (i.e., the BOM variant rule has had its set of options altered by this call). */
    );

/**
    Applies a saved variant rule to the given BOM variant rule.
    This function will not unset existing option values prior to loading the saved rule.
*/
extern BOM_API int BOM_variant_rule_apply_partial_vrule(
    tag_t          bomvariantlist,         /**< (I) The BOM variant rule to apply the saved rule to */
    tag_t          vrule,                  /**< (I) The saved variant rule to load */
    logical*       list_changed            /**< (O) Returned as true if the saved variant rule contained any options which
                                                were not previously in the BOM variant rule.
                                                i.e., the BOM variant rule has had its set of options altered by this call. */
    );

/**
    Retrieves the saved variant rule which is currently loaded into the given BOM variant rule.
*/
extern BOM_API int BOM_variant_rule_ask_vrule(
    tag_t          bomvariantlist,      /**< (I) The BOM variant rule to query */
    tag_t*         vrule,               /**< (O) The saved variant rule currently loaded in that BOM variant rule.
                                                Returned as #NULLTAG if no saved rule has been loaded. */
    logical*       modified             /**< (O) Returned as true if any of the BOM variant rule's option values
                                                have been altered since the saved variant rule was loaded */
    );

/**
    Searches for an option with the specified name.
    If an item is specified then it will search for the option attached to that item.
    If the item is #NULLTAG, then it will search for the option in the specified BOM variant rule.
    If it cannot find the option in the rule, then it will search the entire database.
    If more than one option is found with the same name then an error will occur.
*/
extern BOM_API int BOM_variant_rule_find_option(
    tag_t          bomvariantlist,        /**< (I) The BOM variant rule to search */
    tag_t          item,                  /**< (I) Optional item tag. If a valid item is specified, it looks for the option
                                                only in that item. If #NULLTAG is specified, the BOM variant rule is searched,
                                                followed by the whole database if the option is not in the rule. */
    const char*    name,                  /**< (I) Name of the option to find */
    tag_t*         option,                /**< (O) Tag of the option found */
    tag_t*         option_rev             /**< (O) Tag of the option revision as configured in the given BOM variant rule */
    );

/**
    Performs a general search for options.
    If both a name and an item is specified then it will search for the named option attached to that item.
    If the item is #NULLTAG, then it will search for the option in the specified BOM variant rule.
    If it cannot find the option in the rule (or if the rule is #NULLTAG), then it will search the entire database.
    If the name is NULL then it will return all options attached to the given item, or rule if the item is #NULLTAG.

    <b>Return Values</b>

    #BOM_no_variant_name - An option name was not specified. This will only occur if
                           the bomvariantrule and item arguments are set to #NULLTAG.
*/
extern BOM_API int BOM_variant_rule_find_options(
    tag_t          bomvariantlist,         /**< (I) The BOM variant rule to search.
                                                May be #NULLTAG to search the entire database. */
    tag_t          item,                   /**< (I) The item which the option is defined against.
                                                May be #NULLTAG to search the entire rule or database. */
    const char*    name,                   /**< (I) The name of the option to find.
                                                May be NULL to find all options against the given item or rule. */
    int*           n_options,              /**< (O) The number of options found */
    tag_t**        options                 /**< (OF) n_options Array of options found */
    );

/**
    Retrieves the option revision for the given option as configured in the given BOM variant rule.
*/
extern BOM_API int BOM_variant_rule_ask_option_rev(
    tag_t          bomvariantlist,        /**< (I) The BOM variant rule */
    tag_t          option,                /**< (I) Tag of the option to query */
    tag_t*         option_rev             /**< (O) Tag of the option revision as configured in the given BOM variant rule */
    );

/**
    Retrieves the list of options and their revisions referenced by the given BOM variant rule.
*/
extern BOM_API int BOM_variant_rule_ask_options(
    tag_t          bomvariantlist,       /**< (I) The BOM variant rule */
    int*           n,                    /**< (O) The number of options in the rule */
    tag_t**        options,              /**< (OF) n Array of options in the rule */
    tag_t**        option_revs           /**< (OF) n Array of the configured option revisions for those options */
    );


/**
    Sets BOM Variant option values to given Variant option of BOM Variant Rule. It accepts multiple integer values corresponding
    to enumerated indices of allowed values of BOM Variant.
    The function returns:
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if the given BOM Variant Rule or Variant option is invalid.
    <li>#BOM_variant_multiple_values_unsupported if the given BOM Window is in #BOM_var_config_singlerule_singlevalue mode and more than one value provided.
    <li>#BOM_variant_operation_unsupported if the given BOM Window is in #BOM_var_config_overlay mode.
    </ul>
*/
extern BOM_API int BOM_variant_rule_set_option_values(
    tag_t          bom_variant_list,       /**< (I) The BOM Variant Rule tag. */
    tag_t          option,                 /**< (I) The Variant option to which values to be set. */
    int            value_count,            /**< (I) Number of values passed in */
    int*           values                  /**< (I) value_count Array of integer values for the option.
                                                At present this should be indices into the enumerated list of allowed values. */
    );


/**
    Retrieves BOM Variant option values for given Variant option of BOM Variant Rule, along with information as to how it was set.
    The function returns:
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if the given BOM Window or Variant option is invalid.
    </ul>
*/
extern BOM_API int BOM_variant_rule_ask_option_values(
    tag_t          bom_variant_list,      /**< (I) The BOM variant rule */
    tag_t          option,                /**< (I) The Variant option to query for values. */
    tag_t*         option_rev,            /**< (O) The configured option revision of the Variant option. */
    int*           count,                 /**< (O) The Number of values returned. */
    int**          values,                /**< (OF) count The current integer values of the option.
                                                At present these are always an indices into the enumerated list of allowed values. */
    int**          how_sets,              /**< (OF) count The array of elements of the #BOM_option_how_set_t enumeration defined in bom_tokens.h.
                                                Reports whether values were set by the user, a saved variant rule, variant item or defaulted. */
    char***        where_sets             /**< (OF) count The Array of strings representing source of values. If the option was defaulted or derived,
                                                this is returned as the Id of the Item that contained
                                                the expression that defined this option value.
                                                If the option was set by a saved variant rule,
                                                this is returned as the name of the rule. */
    );

/**
    Unsets an option within the given BOM variant rule.
*/
extern BOM_API int BOM_variant_rule_unset_option_value(
    tag_t          bomvariantlist,         /**< (I) The BOM variant rule */
    tag_t          option                  /**< (I) The option to unset */
    );

/**
    Unsets a group of options within the given BOM variant rule.
*/
extern BOM_API int BOM_variant_rule_unset_option_values(
    tag_t          bomvariantlist,        /**< (I) The BOM variant rule */
    int            n_options,             /**< (I) The number of options to unset */
    tag_t*         options                /**< (I) n_options Array of options to unset */
    );

/**
    Unsets all the option values in the given BOM variant rule,
    and unloads the saved variant rule if you have one loaded.
*/
extern BOM_API int BOM_variant_rule_clear_option_values(
    tag_t          bomvariantlist          /**< (I) The BOM variant rule to clear */
    );

/**
    Evaluates the given BOM variant rule. This will set option defaults,
    derived values and perform option rule checks.
    Note that this function is called automatically by all
    BOM_variant_rule ITK functions which change the BOM variant rule.
    For this reason, you only need to call this function if you are altering
    low level variant data such as Variant Expressions and Variant Expression Blocks.

    <b>Return Values</b>

    #BOM_variant_error_condition - The evaluation triggered a variant rule check.
*/
extern BOM_API int BOM_variant_rule_evaluate(
    tag_t          bomvariantlist          /**< (I) The BOM variant rule to clear */
    );

/** @} */

/**
    Informs all BOM windows in the current Teamcenter Engineering session that the variant data
    on the given occurrence has been updated.
    This action is automatically performed if #BOM_line_set_variant_e_block or #PS_set_variant_data is called.
    However, if you have altered an existing Occurrence Variant Expression Block or
    one of its component Variant Expressions then you will need to call this function.
*/
extern BOM_API int BOM_update_for_variants_on_occ(
    tag_t          parent_bvr,             /**< (I) The Occurrence's parent BOM View Revision */
    tag_t          occurrence              /**< (I) The Occurrence */
    );

/**
    Informs all BOM windows in the current Teamcenter Engineering session that
    the variant data on the given Item Revision has been updated.
    This action is automatically performed if #ITEM_set_rev_variants is called.
    However, if you have altered an existing Item Revision Variant Expression Block,
    or one of its component Variant Expressions then you will need to call this function.
*/
extern BOM_API int BOM_update_for_variants_on_itemrev(
    tag_t          item_rev       /**< (I) The Item Revision which owns the variant data which has been updated */
    );

/**
    Informs all BOM windows in the current Teamcenter Engineering session that
    the variant data on the given BOMLine's Occurrence has been updated.
    This action is automatically performed if #BOM_line_set_variant_e_block or
    #PS_set_variant_data is called.
    However, if you have altered an existing BOMLine Occurrence's Variant Expression Block or
    one of its component Variant Expressions then you will need to call this function.
*/
extern BOM_API int BOM_update_for_variants_on_bomline(
    tag_t          bomline             /**< (I) The BOM line which owns the variant data which has been updated */
    );

/**
    @name BOM Variant Clause List Functions

    <b>Common Return Values</b>

    #BOM_variant_invalid_cond_clause - The specified clause position is not valid. <br>
    #BOM_variant_invalid_operation - This operation cannot be performed on the given list of clauses.
    @{
*/

/**
    Creates a new empty clause list. This is used to create a new variant condition.
*/
extern BOM_API int BOM_variant_new_clause_list(
    tag_t          bom_window,      /**< (I) The BOM window which will provide the context for the edit operation */
    tag_t*         clause_list      /**< (O) The new empty clause list */
    );

/**
    Creates a new clause list populated by the specified variant condition.
    This is used to edit an existing variant condition.
    A suitable variant condition can be obtained using #BOM_variant_expr_split_load_if,
    #BOM_variant_expr_split_error_if, or #BOM_variant_expr_split_set_if.
*/
extern BOM_API int BOM_variant_condition_to_clause_list(
    tag_t          bom_window,             /**< (I) The BOM window which will provide the context for the edit operation */
    tag_t          condition_ve,           /**< (I) The condition variant expression to be loaded into the new clause list */
    tag_t*         clause_list             /**< (O) The new clause list */
    );

/**
    Creates a new condition Variant Expression from the clause list.
    This new variant condition can be used for several purposes by passing it into #BOM_variant_expr_load_if,
    #BOM_variant_expr_error_if, or #BOM_variant_expr_set_if.
*/
extern BOM_API int BOM_variant_join_clause_list(
    tag_t          clause_list,           /**< (I) The clause list to produce the new variant condition from */
    tag_t*         conditon_ve            /**< (O) The newly created condition variant expression */
    );

/**
    Deletes a clause list.
*/
extern BOM_API int BOM_variant_delete_clause_list(
    tag_t          clause_list             /**< (I) The clause list to delete */
    );

/**
    Appends a new clause onto the end of a clause list.
*/
extern BOM_API int BOM_variant_clause_append(
    tag_t          clause_list,      /**< (I) The clause list to append to */
    int            join,             /**< (I) How this clause is related to its predecessor.
                                        Must be either #BOM_variant_operator_and or #BOM_variant_operator_or. */
    tag_t          option,           /**< (I) The option to compare */
    int            op,               /**< (I) The comparison operator. Must be one of #BOM_variant_operator_is_equal,
                                        #BOM_variant_operator_not_equal, #BOM_variant_operator_lt,
                                        #BOM_variant_operator_gt, #BOM_variant_operator_lt_eq, or #BOM_variant_operator_gt_eq. */
    const char*    value             /**< (I) The value to compare the option against.
                                        This is passed in as the option value's text representation rather than
                                        the enum value to allow a UIF to simply pass in a user typed value. */
    );

/**
    Inserts a new clause into a clause list.
*/
extern BOM_API int BOM_variant_clause_insert(
    tag_t          clause_list,      /**< (I) The clause list to insert into */
    int            pos,              /**< (I) The position to insert at. Position 0 is the top of the list. */
    int            join,             /**< (I) How this clause is related to its predecessor.
                                        Must be either #BOM_variant_operator_and or #BOM_variant_operator_or. */
    tag_t          option,           /**< (I) The option to compare */
    int            op,               /**< (I) The comparison operator. Must be one of #BOM_variant_operator_is_equal,
                                        #BOM_variant_operator_not_equal, #BOM_variant_operator_lt,
                                        #BOM_variant_operator_gt, #BOM_variant_operator_lt_eq, or #BOM_variant_operator_gt_eq. */
    const char*    value             /**< (I) The value to compare the option against.
                                        This is passed in as the option value's text representation rather than
                                        the enum value to allow a UIF to simply pass in a user typed value. */
    );

/**
    Replaces an existing clause in a clause list with a new clause.
*/
extern BOM_API int BOM_variant_clause_replace(
    tag_t          clause_list,      /**< (I) The clause list */
    int            pos,              /**< (I) The position of the clause being replaced.
                                        Position 0 is the first clause in the list. */
    int            join,             /**< (I) How the new clause is related to its predecessor.
                                        Must be either #BOM_variant_operator_and or #BOM_variant_operator_or. */
    tag_t          option,           /**< (I) The new option to compare */
    int            op,               /**< (I) The new comparison operator. Must be one of #BOM_variant_operator_is_equal,
                                        #BOM_variant_operator_not_equal, #BOM_variant_operator_lt,
                                        #BOM_variant_operator_gt, #BOM_variant_operator_lt_eq, or #BOM_variant_operator_gt_eq. */
    const char*    value             /**< (I) The new value to compare the option against.
                                        This is passed in as the option value's text representation rather than
                                        the enum value to allow a UIF to simply pass in a user typed value. */
    );

/**
    Deletes a set of clauses from a clause list.
*/
extern BOM_API int BOM_variant_clause_delete(
    tag_t          clause_list,            /**< (I) The clause list to delete the clauses from */
    int            n_clauses,              /**< (I) The number of clauses to be deleted */
    int            pos[]                   /**< (I) n_clauses Array containing the positions of the clauses to be deleted.
                                                Position 0 is the first clause in the list. */
    );

/**
    Moves a set of clauses one place up a clause list.

    <b>Restrictions:</b>

    If the system is unable to move one (or more) of the clauses, then none of the clauses will be moved.
*/
extern BOM_API int BOM_variant_clause_move_up(
    tag_t          clause_list,            /**< (I) The clause list to move the clauses within */
    int            n_clauses,              /**< (I) The number of clauses to be moved */
    int            pos[]                   /**< (I) n_clauses Array containing the current positions of the clauses to be moved.
                                                Position 0 is the first clause in the list. */
    );

/**
    Moves a set of clauses one place down a clause list.

    <b>Restrictions:</b>

    If the system is unable to move one (or more) of the clauses, then none of the clauses will be moved.
*/
extern BOM_API int BOM_variant_clause_move_down(
    tag_t          clause_list,            /**< (I) The clause list to move the clauses within */
    int            n_clauses,              /**< (I) The number of clauses to be moved */
    int            pos[]                   /**< (I) n_clauses Array containing the current positions of the clauses to be moved.
                                                Position 0 is the first clause in the list. */
    );

/**
    Toggles a pair of brackets around a given set of clauses in a clause list
    (i.e., if a matching pair of brackets already exists around the selected clauses,
    the brackets will be removed. Otherwise, a new set of brackets will be inserted).
*/
extern BOM_API int BOM_variant_clause_toggle_brackets(
    tag_t          clause_list,            /**< (I) The clause list to apply the brackets operation to */
    int            n_clauses,              /**< (I) The number of clauses selected */
    int            pos[]                   /**< (I) n_clauses Array containing the positions of the clauses selected.
                                                Position 0 is the first clause in the list. */
    );

/**
    Retrieves the number of clauses in a clause list.
*/
extern BOM_API int BOM_variant_clause_list_size(
    tag_t          clause_list,            /**< (I) The clause list to queried the size of */
    int*           n_clauses               /**< (O) The number of clauses in the list */
    );

/**
    Retrieves the clause list in indented text format.
*/
extern BOM_API int BOM_variant_clause_list_text(
    tag_t          clause_list,          /**< (I) The clause list to convert to text */
    int*           n_clauses,            /**< (O) The number of clauses in the list.
                                                Each clause is returned a separate text string. */
    char***        text                  /**< (OF) n_clauses Array of text strings. One string for each clause. */
    );

/**
    Retrieves a single clause in indented text format.
*/
extern BOM_API int BOM_variant_clause_text(
    tag_t          clause_list,           /**< (I) The clause list which contains the clause to be queried */
    int            pos,                   /**< (I) The position of the clause to be queried.
                                                Position 0 is the first clause in the list. */
    char**         text                   /**< (OF) The formatted text string for the clause */
    );

/**
    Retrieves details of a clause in a clause list.
*/
extern BOM_API int BOM_variant_clause_details(
    tag_t          clause_list,           /**< (I) The clause list which contains the clause to be queried */
    int            pos,                   /**< (I) The position of the clause to be queried.
                                                Position 0 is the first clause in the list. */
    int*           join,                  /**< (O) How this clause is related to its predecessor.
                                                Will be either #BOM_variant_operator_and or #BOM_variant_operator_or. */
    tag_t*         option,                /**< (O) The option being compared */
    int*           op,                    /**< (O) The comparison operator. Will be one of #BOM_variant_operator_is_equal,
                                                #BOM_variant_operator_not_equal, #BOM_variant_operator_lt,
                                                #BOM_variant_operator_gt, #BOM_variant_operator_lt_eq, or #BOM_variant_operator_gt_eq. */
    char**         value                  /**< (OF) The value that the option is being compared against.
                                                This is returned as the option value's text representation rather than the enum value. */
    );

/**
    Retrieves a bit encoded representation of the valid operations for a given set of clauses.
    Macros are supplied for extracting individual operations from the returned value.
    See the BOM_variant_clause_op_* entries in this section.
*/
extern BOM_API int BOM_variant_clause_valid_ops(
    tag_t          clause_list,            /**< (I) The clause list to validate operations against */
    int            n_clauses,              /**< (I) The number of clauses selected */
    int            pos[],                  /**< (I) n_clauses Array containing the positions of the clauses selected.
                                                Position 0 is the first clause in the list. */
    int*           op_flags                /**< (O) */
    );

/**
    Controls whether or not the system will automatically validate
    each operation that an ITK programmer attempts on a clause list.
    This value defaults to true for new clause lists.
    If this is set to false, then an ITK programmer should call
    #BOM_variant_clause_valid_ops to ensure that the call that they are about to make is legal.
    This feature is useful for user interface programmers where a dialog may call
    #BOM_variant_clause_valid_ops whenever the user selection changes
    in order to grey out inappropriate action buttons.
    This means that a user could never invoke an illegal operation,
    so a small performance gain can be made by disabling unnecessary checking.

    Be aware that switching off automatic validation without using #BOM_variant_clause_valid_ops
    is dangerous and could lead to unpredictable results.
*/
extern BOM_API int BOM_variant_clause_validate_ops(
    tag_t          clause_list,          /**< (I) The clause list that this new validation will refer to */
    logical        auto_validate         /**< (I) Set this to false to prevent the system from checking
                                                the validity of each operation automatically */
    );

/** @} */

/**
    Creates a "load if" type Variant Expression which can be attached to a BOM Line
    (or Occurrence) to control variant configuration of an assembly.
    A suitable condition Variant Expression can be obtained using #BOM_variant_join_clause_list.
*/
extern BOM_API int BOM_variant_expr_load_if(
    tag_t          cond_ve,                /**< (I) The variant expression representing the variant condition
                                                under which the BOMLine will be configured */
    tag_t*         load_if_ve             /**< (O) The "load if" variant expression which can be added to
                                                a BOMLine's variant expression block */
    );

/**
    Creates an "error if" type Variant Expression which can be attached to an Item Revision for variant rule checks.
    A suitable condition Variant Expression can be obtained using #BOM_variant_join_clause_list.
*/
extern BOM_API int BOM_variant_expr_error_if(
    tag_t          cond_ve,          /**< (I) The variant expression representing the variant condition
                                        under which the error will occur */
    const char*    warning_text,     /**< (I) The text which will be displayed when the error condition occurs */
    tag_t*         error_if_ve       /**< (O) The resulting variant expression which can be added to
                                        an Item Revision's variant expression block */
    );

/**
    Creates a "set if" type Variant Expression which can be attached to
    an Item Revision for derived option defaults.
    A suitable condition Variant Expression can be obtained using
    #BOM_variant_join_clause_list.
*/
extern BOM_API int BOM_variant_expr_set_if(
    tag_t          cond_ve,         /**< (I) The variant expression representing the variant condition
                                        under which the option default will be set */
    tag_t          option,          /**< (I) The option that will be set when the variant condition is met */
    int            value,           /**< (I) The value to set the option to when the variant condition is met */
    tag_t*         set_if_ve,       /**< (O) The resulting variant expression which can be added to
                                        an item revision's variant expression block */
    tag_t*         assign_ve        /**< (O) The variant expression for the actual assignment section of the derived default */
    );

/**
    Creates a fixed default Variant Expression which can be attached to an Item Revision.
*/
extern BOM_API int BOM_variant_expr_default(
    tag_t          option,          /**< (I) The option that will be set */
    int            value,           /**< (I) The value to set the option to */
    tag_t*         default_ve       /**< (O) The resulting variant expression which can be added to
                                        an item revision's variant expression block */
    );

/**
    Extracts the variant condition from a "load if" type Variant Expression obtained from a BOM Line (or Occurrence).
    The resulting condition Variant Expression can then be edited using #BOM_variant_new_clause_list.
*/
extern BOM_API int BOM_variant_expr_split_load_if(
    tag_t          load_if_ve,      /**< (I) The "load if" variant expression obtained from a BOMLine's variant expression block */
    tag_t*         cond_ve          /**< (O) The variant condition extracted from the "load if" variant expression */
    );

/**
    Extracts the variant condition and the display text from
    an "error if" type Variant Expression obtained from an Item Revision.
    The resulting condition Variant Expression can then be edited using #BOM_variant_new_clause_list.
*/
extern BOM_API int BOM_variant_expr_split_error_if(
    tag_t          error_if_ve,           /**< (I) The "error if" variant expression obtained from
                                                an Item Revision's variant expression block */
    char**         warning_text,          /**< (OF) The text which will be displayed when the error condition occurs */
    tag_t*         cond_ve                /**< (O) The variant condition under which the error occurs */
    );

/**
    Extracts the variant condition, the option, and the value from
    a "set if" type Variant Expression obtained from an Item Revision.
    The resulting condition Variant Expression can then be edited using
    #BOM_variant_new_clause_list.
*/
extern BOM_API int BOM_variant_expr_split_set_if(
    tag_t          set_if_ve,       /**< (I) The "set if" variant expression obtained from
                                        an Item Revision's variant expression block */
    tag_t*         option,          /**< (O) The option that will be set when the variant condition is met */
    int*           value,           /**< (O) The value that the option will be set to when the variant condition is met */
    tag_t*         cond_ve          /**< (O) The variant condition under which the default will be derived */
    );

/**
    Extracts the option, and the value from a fixed default Variant Expression obtained from an Item Revision.
*/
extern BOM_API int BOM_variant_expr_split_default(
    tag_t          default_ve,           /**< (I) The default variant expression obtained from
                                            an Item Revision's variant expression block */
    tag_t*         option,               /**< (O) The option that will be set */
    int*           value                 /**< (O) The value that the option will be set to */
    );

/**
    @name BOM Modular Variants Functions

    <b>Configuration</b>

    This is the set of ITK functions required to configure a structure.

    #BOM_line_ask_sos <br>
    #BOM_line_clear_sos <br>
    #BOM_sos_apply <br>
    #BOM_sos_apply_list <br>
    #BOM_sos_free <br>
    #BOM_window_ask_ove_messages  <br>
    #BOM_line_ove_validate <br>
    #BOM_sos_ask_entries <br>
    BOM_sos_ask_entry_\<type\> <br>
    BOM_sos_set_entry_\<type\> <br>
    #BOM_sos_unset_entry <br>
    #BOM_option_ask_allowed_ints <br>
    #BOM_option_ask_allowed_reals <br>
    #BOM_option_ask_allowed_strings

    <b>Authoring ITK</b>

    The following ITKs deal with the creation and editing of Modular Variants.
    It essentially provides a way to getting and setting MVL.
    MVL has 2 distinct areas - the option declaration statements and the language expressions.
    These are dealt with via separate functions in the ITK.

    #BOM_line_ask_mvl_condition <br>
    #BOM_line_set_mvl_condition <br>
    #BOM_line_ask_mvl <br>
    #BOM_line_set_mvl <br>
    #BOM_item_module_list_options <br>
    #BOM_module_ask_option_text <br>
    #BOM_line_delete_option <br>
    #BOM_line_define_option

    <b>Additional ITK</b>
    #BOM_option_where_declared2 <br>
    #BOM_option_where_used2
    @{
*/

/**
    Ask the BOM line for it's current SOS - or selected option set.
    The SOS objects that are created are owned by a particular BOMLine.
    When the bomline becomes invalid this will invalidate all the SOS objects it owns.
    An SOS can be deleted earlier by calling #BOM_sos_free.
*/
extern BOM_API int BOM_line_ask_sos(
    tag_t          bom_line,             /**< (I) */
    tag_t*         sos                   /**< (O) */
    );

/**
    Effectively applies an "empty" SOS to the bomline,
    so that on the next evaluation all options will be unset.
*/
extern BOM_API int BOM_line_clear_sos(
    tag_t          bom_line,            /**< (I) */
    logical        doUpdates            /**< (I) */
    );

/**
    This applies the SOS to its associated BOMLine.
    The structure will be evaluated and any changes will be reflected in this SOS.
    This also makes this SOS the current one for the bom line.
    (i.e. calling #BOM_line_ask_sos will return the same SOS object).
    The do updates means that the window will be updated with changes (and the UI).
    Otherwise an evaluation occurs, but the results are not kept.
*/
extern BOM_API int BOM_sos_apply(
    tag_t          sos,                 /**< (I) */
    logical        doUpdates            /**< (I) */
    );

/**
    This applies the SOS to its associated BOMLine.
    The structure will be evaluated and any changes will be reflected in this SOS.
    This also makes this SOS the current one for the bom line.
    (i.e. calling #BOM_line_ask_sos will return the same SOS object)
*/
extern BOM_API int BOM_sos_apply_list(
    int            count,               /**< (I) */
    tag_t*         sos,                 /**< (I) count */
    logical        doUpdates            /**< (I) */
    );

/**
    Frees the memory associated with the current SOS.
    The tag will be made invalid.
*/
extern BOM_API int BOM_sos_free(
    tag_t          sos                  /**< (I) */
    );

/**
    Displays any Options and Variants Engine(OVE) messages that occur as a consequence of the MVL expressions "error",
    "warn" or "inform" are executed.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_window_ask_ove_messages(
    tag_t          bom_window,         /**< (I) The BOM Window */
    int*           n_errors,           /**< (O) Number of errors  */
    int**          severities,         /**< (OF) n_errors The error severities */
    char***        messages,           /**< (OF) n_errors The error messages. <br/>The array is packed, which means that the memory is deallocated calling #MEM_free on the container only. */
    tag_t**        lines               /**< (OF) n_errors BOMLines having OVE errors */
    );

/**
    Performs Options and Variants Engine(OVE) validation on a bom line,
    and optionally on all structure below the line as well.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_line_ove_validate(
    tag_t          line,               /**< (I) Tag of BOM Line */
    logical        recurse,            /**< (I) If true then recursively all structure under @p line would be validated */
    int*           count,              /**< (O) Count of errors */
    int**          error_types,        /**< (OF) count Types of Error */
    tag_t**        lines,              /**< (OF) count Tags of BOM Lines having OVE errors */
    int**          options             /**< (OF) count OVE options */
    );

/**
    Parses the input Options and Variants Engine(OVE) path and generates an array of Path Elements.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>Possibly other OVE errors.
    </ul>
*/
extern BOM_API int BOM_decompose_ove_path(
    const char*    path,             /**< (I) Options and Variants Engine(OVE) path */
    int*           count,            /**< (O) Count of Options and Values specified in @p path */
    char***        pathElements      /**< (OF) Strings of Options and Values specified in @p path as per the @p count */
    );

/**
    Asks the current options that are in the SOS. The return is 4 lists.
    The item and option name define a unique option, and the type is an enum describing each option' type
    -    string/real/integer/logical. The how_set list describes how the option is set (unset/default/user set/etc.)
*/
extern BOM_API int BOM_sos_ask_entries(
    tag_t          sos,                 /**< (I) */
    int*           count,               /**< (O) */
    int**          options,             /**< (OF) count */
    char***        paths                /**< (OF) count */
    );

/**
    This gets the value that the option is set to in the SOS.
*/
extern BOM_API int BOM_sos_ask_entry_int(
    tag_t          sos,             /**< (I) */
    int            option,          /**< (I) */
    const char*    path,            /**< (I) */
    int*           value,           /**< (O) */
    int*           how_set          /**< (O) An element of the #BOM_option_how_set_t enumeration defined in bom_tokens.h */
    );

/**
    This gets the value that the option is set to in the SOS.
*/
extern BOM_API int BOM_sos_ask_entry_double(
    tag_t          sos,             /**< (I) */
    int            option,          /**< (I) */
    const char*    path,            /**< (I) */
    double*        value,           /**< (O) */
    int*           how_set          /**< (O) An element of the #BOM_option_how_set_t enumeration defined in bom_tokens.h */
    );

/**
    This gets the value that the option is set to in the SOS.
*/
extern BOM_API int BOM_sos_ask_entry_logical(
    tag_t          sos,             /**< (I) */
    int            option,          /**< (I) */
    const char*    path,            /**< (I) */
    logical*       value,           /**< (O) */
    int*           how_set          /**< (O) An element of the #BOM_option_how_set_t enumeration defined in bom_tokens.h */
    );

/**
    This gets the value that the option is set to in the SOS.
*/
extern BOM_API int BOM_sos_ask_entry_display(
    tag_t          sos,             /**< (I) */
    int            option,          /**< (I) */
    const char*    path,            /**< (I) */
    char**         value,           /**< (OF) */
    int*           how_set          /**< (O) An element of the #BOM_option_how_set_t enumeration defined in bom_tokens.h */
    );

/**
    This sets the value that the option is set to in the SOS.
*/
extern BOM_API int BOM_sos_set_entry_int(
    tag_t          sos,             /**< (I) */
    int            option,          /**< (I) */
    const char*    path,            /**< (I) */
    int            value,           /**< (I) */
    int            how_set          /**< (I) An element of the #BOM_option_how_set_t enumeration defined in bom_tokens.h */
    );

/**
    This sets the value that the option is set to in the SOS.
*/
extern BOM_API int BOM_sos_set_entry_double(
    tag_t          sos,             /**< (I) */
    int            option,          /**< (I) */
    const char*    path,            /**< (I) */
    double         value,           /**< (I) */
    int            how_set          /**< (I) An element of the #BOM_option_how_set_t enumeration defined in bom_tokens.h */
    );

/**
    This sets the value that the option is set to in the SOS.
*/
extern BOM_API int BOM_sos_set_entry_logical(
    tag_t          sos,             /**< (I) */
    int            option,          /**< (I) */
    const char*    path,            /**< (I) */
    logical        value,           /**< (I) */
    int            how_set          /**< (I) An element of the #BOM_option_how_set_t enumeration defined in bom_tokens.h */
    );

/**
    This sets the value that the option is set to in the SOS.
*/
extern BOM_API int BOM_sos_set_entry_string(
    tag_t          sos,             /**< (I) */
    int            option,          /**< (I) */
    const char*    path,            /**< (I) */
    const char*    value,           /**< (I) */
    int            how_set          /**< (I) An element of the #BOM_option_how_set_t enumeration defined in bom_tokens.h */
    );

/**
    This unsets the value that the option is set to in the SOS.
*/
extern BOM_API int BOM_sos_unset_entry(
    tag_t          sos,             /**< (I) */
    int            option,          /**< (I) */
    const char*    path             /**< (I) */
    );


/**
    Retrieves the option path from input Options and Variants Engine(OVE) option.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>Possibly other OVE errors.
    </ul>
*/
extern BOM_API int BOM_ask_option_path(
    int            option,                 /**< (I) Options and Variants Engine(OVE) option */
    char**         path                    /**< (OF) Options and Variants Engine(OVE) path */
    );

/**
    This asks what string values are allowed on
*/
extern BOM_API int BOM_option_ask_allowed_strings(
    int            option,              /**< (I) */
    int*           count,               /**< (O) */
    char***        values,              /**< (OF) count */
    char**         default_value        /**< (OF) */
    );

/**
    This asks what integer values are allowed on an option.
    As an option may consist of multiple discontinuous ranges each value is given as a min and max and a range_type.
    Range type can be as follows:

    <table>
    <tr><td>Range Type</td><td>Min contains</td><td>Max contains</td><td>Means                 </td></tr>
    <tr><td>Fixed     </td><td>The value   </td><td>N/A         </td><td>A single fixed value  </td></tr>
    <tr><td>Min       </td><td>Min value   </td><td>N/A         </td><td>Allow values are \>min</td></tr>
    <tr><td>Max       </td><td>N/A         </td><td>Max value   </td><td>Allow values are \<max</td></tr>
    <tr><td>Range     </td><td>Min value   </td><td>Max value   </td><td>min \< value \< max   </td></tr>
    <tr><td>Open      </td><td>N/A         </td><td>N/A         </td><td>Any valid integer     </td></tr>
    </table>
*/
extern BOM_API int BOM_option_ask_allowed_ints(
    int            option,                /**< (I) */
    int*           count,                 /**< (O) */
    int**          mins,                  /**< (OF) count */
    int**          maxs,                  /**< (OF) count */
    int**          range_types,           /**< (OF) count */
    int*           default_value          /**< (O) */
    );

/**
    This asks what real values are allowed on an option.
    As an option may consist of multiple discontinuous ranges each value is given as a min and max and a range_type.
*/
extern BOM_API int BOM_option_ask_allowed_reals(
    int            option,             /**< (I) */
    int*           count,              /**< (O) */
    double**       mins,               /**< (OF) count */
    double**       maxs,               /**< (OF) count */
    int**          range_types,        /**< (OF) count */
    double*        default_value       /**< (O) */
    );

extern BOM_API int BOM_option_ask_logical_default(
    int            option,             /**< (I) */
    logical*       default_value       /**< (O) */
    );

/**
    Retrieves the condition string.
*/
extern BOM_API int BOM_line_ask_mvl_condition(
    tag_t          line,                 /**< (I) */
    char**         condition             /**< (OF) */
    );

/**
    Sets the MVL condition.
*/
extern BOM_API int BOM_line_set_mvl_condition(
    tag_t          line,            /**< (I) */
    const char*    condition        /**< (I) */
    );

/**
    Gets the MVL from the item (revision) that is configured by this line
*/
extern BOM_API int BOM_line_ask_mvl(
    tag_t          line,                 /**< (I) */
    char**         mvl                   /**< (OF) */
    );

/**
    Sets the MVL on the item (revision) that is configured by this line.
    Note that this will attempt to lock the item revision for modify.
    #BOM_save_window must be called to commit this change and unlock the item rev.
    #BOM_refresh_window will lose all changes (on all bom lines in the current window)
    and unlock the item rev.
*/
extern BOM_API int BOM_line_set_mvl(
    tag_t          line,            /**< (I) */
    const char*    mvl              /**< (I) */
    );


/**
    Gets the MVL declaration of the option
*/
extern BOM_API int BOM_module_ask_option_text(
    int            option,               /**< (I) */
    char**         text                  /**< (OF) */
    );


/**
    Creates or replaces the modular option defined by option text.
    <br/>It also checks if an option with the same name already exists before adding the new option.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_option_already_exists if the option already exists
    <li>#BOM_invalid_tag for invalid line tag
    <li>#BOM_line_type_is_not_supported if the input @p line is GDE Line
    <li>Possibly other OVE errors
    </ul>
*/
extern BOM_API int BOM_line_define_option(
    tag_t          line,            /**< (I) The BOM Line */
    const char*    text             /**< (I) Modular option text */
    );

/**
    Removes the option from the module.
*/
extern BOM_API int BOM_line_delete_option(
    tag_t          line,                   /**< (I) */
    int            option                  /**< (I) */
    );

/**
   Modifies an existing option
*/
extern BOM_API int BOM_line_modify_option
    ( tag_t line,                   /**< (I) */
      int option,                   /**< (I) */
      const char *text              /**< (I) */
    );

/** @} */

/**
    @name SOS Storage and Retrieval
    @{
*/

/**
    Reads input StoredOptionSet into the given BOMVariantConfig.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_no_bomsos_target for no StoredOptionSet
    <li>#BOM_invalid_tag for invalid input config
    <li>#BOM_no_variantrule_target for invalid input config having NULL Variant rule
    </ul>
*/
extern BOM_API int BOM_sos_db_read(
    tag_t          db_sos,                /**< (I) Stored Option Set */
    tag_t          config                 /**< (I) BOM Variant Configuration */
    );

/**
    Creates a selection of options and their values as a new StoredOptionSet
    using input StoredOptionSet name and BOMVariantConfig.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid input config
    <li>Possibly other OVE errors
    </ul>
*/
extern BOM_API int BOM_sos_db_create(
    const char*    db_sos_name,     /**< (I) StoredOptionSet name */
    tag_t          config,          /**< (I) BOMVariantConfig */
    tag_t*         db_sos           /**< (O) StoredOptionSet */
    );

/**
    Writes a selection of options and their values. Creates or updates
    the StoredOptionValues for the current configuration.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid input config
    <li>Possibly other OVE errors
    </ul>
*/
extern BOM_API int BOM_sos_db_set(
    tag_t          db_sos,                /**< (I) StoredOptionSet */
    tag_t          config                 /**< (I) BOMVariantConfig */
    );

/**
    Writes explicit selection of options and their values as a new StoredOptionSet.
    Note an option that does not match the StorageRule will not be written out
    even if it is explicitly listed.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid input config
    <li>Possibly other OVE errors
    </ul>
*/
extern BOM_API int BOM_sos_db_create_partial(
    const char*    db_sos_name,     /**< (I) StoredOptionSet name */
    tag_t          config,          /**< (I) BOMVariantConfig */
    int            count,           /**< (I) Count of Items having modularOptions */
    tag_t*         items,           /**< (I) count */
    char**         options,         /**< (I) count */
    logical*       is_modular,      /**< (I) count */
    tag_t*         db_sos           /**< (O) StoredOptionSet */
    );

/**
    Writes explicit selection of options and their values.

    <br/>The @p is_modular array defines if each specified option is modular or legacy (true => modular).
    <br/>If only one source (BOM StoredOptionSet or BOM Variant rule) is specified then @p is_modular can be passed as null.
    <br/>If both sources are defined but @p is_modular is null, then it will try both.

    @note An option that does not match the StorageRule will not be written out even if it is explicitly listed.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid input config
    <li>Possibly other OVE errors
    </ul>
*/
extern BOM_API int BOM_sos_db_set_partial(
    tag_t          db_sos,           /**< (I) StoredOptionSet */
    tag_t          config,           /**< (I) BOMVariantConfig */
    int            count,            /**< (I) Count of Items having modularOptions */
    tag_t*         items,            /**< (I) count */
    char**         options,          /**< (I) count */
    logical*       is_modular        /**< (I) count */
    );

/**
    Retrieves details of all options in StoredOptionSet, along with values in string form.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_internal_error with user defined error message for any invalid operation
    <li>Possibly other OVE errors
    </ul>
*/
extern BOM_API int BOM_sos_db_contents(
    tag_t          db_sos,              /**< (I) StoredOptionSet */
    int*           count,               /**< (O) Count of Items having modularOptions */
    tag_t**        items,               /**< (OF) count Tags of Items having modularOptions */
    char***        options,             /**< (OF) count Modular Options */
    int**          option_types,        /**< (OF) count Option Types */
    int**          value_types,         /**< (OF) count Option ValueTypes */
    int**          how_set,             /**< (OF) count An element of the #BOM_option_how_set_t enumeration defined in bom_tokens.h */
    char***        values               /**< (OF) count Option Values. The array is packed, which means that the memory is deallocated by calling #MEM_free on the container only */
    );

/**
    Finds StoredOptionSets that contain all input options.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_internal_error with user defined error message for any invalid operation
    <li>Possibly other OVE errors
    </ul>
*/
extern BOM_API int BOM_sos_db_option_query(
    int            n,                   /**< (I) Count of Items having modularOptions */
    tag_t*         items,               /**< (I) n Tags of Items having modularOptions */
    char**         options,             /**< (I) n Modular Options */
    int*           n_matches,           /**< (O) Count of StoredOptionSets matched all input options */
    tag_t**        matches              /**< (OF) n_matches Tags of StoredOptionSets */
    );

/**
    Finds StoredOptionSets that have all input options with operator based value matching.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_internal_error with user defined error message for any invalid operation
    <li>Possibly other OVE errors
    </ul>
*/
extern BOM_API int BOM_sos_db_query(
    int            n,                   /**< (I) Count of Items having modularOptions */
    tag_t*         items,               /**< (I) n Tags of Items having modularOptions */
    char**         options,             /**< (I) n Modular Options */
    int*           ops,                 /**< (I) n Operators */
    int*           value_types,         /**< (I) n Option ValueTypes */
    char**         low_values,          /**< (I) n Low Expression Values. If no values then just query for StoredOptionSets containing input options */
    char**         high_values,         /**< (I) n High Expression Values */
    int*           n_matches,           /**< (O) Count of matched StoredOptionSets */
    tag_t**        matches              /**< (OF) n_matches Tags of StoredOptionSets */
    );

/** @} */

/**
    @name BOM Variant configuration functions
    @{
*/

/**
    Creates BOMVariantConfig based on input BOM variant rule and StoredOptionSets.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid BOM Variant rule or BOM StoredOptionSets
    </ul>
*/
extern BOM_API int BOM_create_variant_config(
    tag_t          bom_vrule,           /**< (I) BOM Variant rule */
    int            count,               /**< (I) Count of BOM StoredOptionSets */
    tag_t*         bom_sos_list,        /**< (I) count Tags of BOM StoredOptionSets */
    tag_t*         bom_variant_config   /**< (O) BOMVariantConfig */
    );

/**
    Creates BOMVariantConfig based on input BOM window and BOM Variant Configuration.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the specified @p bom_window is invalid
    </ul>
*/
extern BOM_API int BOM_create_window_variant_config(
    tag_t          bom_window,          /**< (I) The BOM Window */
    int            mode,                /**< (I) The default mode is #BOM_VARIANT_CONFIG_REF: 0. Expected values are:
                                                <ul>
                                                <li>#BOM_VARIANT_CONFIG_COPY: 1
                                                <li>#BOM_VARIANT_CONFIG_MANAGED: 2
                                                <li>#BOM_VARIANT_CONFIG_DEEP: 4
                                                </ul>
                                                */
    tag_t*         bom_variant_config   /**< (O) BOMVariantConfig */
    );

/**
    Creates BOMVariantConfig based on input BOM Line and BOM Variant Configuration.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid BOM Line
    </ul>
*/
extern BOM_API int BOM_create_bomline_variant_config(
    tag_t          bom_line,            /**< (I) Tag of BOM Line */
    int            mode,                /**< (I) The default mode is #BOM_VARIANT_CONFIG_REF: 0. Expected values are:
                                                <ul>
                                                <li>#BOM_VARIANT_CONFIG_COPY: 1
                                                <li>#BOM_VARIANT_CONFIG_MANAGED: 2
                                                <li>#BOM_VARIANT_CONFIG_DEEP: 4
                                                </ul>
                                                */
    tag_t*         bom_variant_config   /**< (O) BOMVariantConfig */
    );

/**
    Deletes input BOMVariantConfig.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid BOMVariantConfig
    </ul>
*/
extern BOM_API int BOM_delete_variant_config(
    tag_t          bom_variant_config   /**< (I) BOMVariantConfig */
    );

/**
    Applies BOM StoredOptionSets and then BOM variant rule from input BOMVariantConfig and attaches the same rule with current window.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid BOMVariantConfig
    </ul>
*/
extern BOM_API int BOM_variant_config_apply(
    tag_t          bom_variant_config   /**< (I) BOMVariantConfig */
    );

/**
    Clears BOM StoredOptionSets and BOM variant rule from input BOMVariantConfig.
    Unsets all option values, and unloads the current SVR. BOMWindow gets refreshed by the clear.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid BOMVariantConfig
    </ul>
*/
extern BOM_API int BOM_variant_config_clear(
    tag_t          bom_variant_config   /**< (I) BOMVariantConfig */
    );

/**
    Applies BOM StoredOptionSets and then BOM variant rule from input BOMVariantConfig and restores the BOMWindow's previous config.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid BOMVariantConfig
    </ul>
*/
extern BOM_API int BOM_variant_config_evaluate(
    tag_t          bom_variant_config   /**< (I) BOMVariantConfig */
    );

/**
    Copies input BOMVariantConfig.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid BOMVariantConfig
    </ul>
*/
extern BOM_API int BOM_variant_config_copy(
    tag_t          source_config,       /**< (I) BOMVariantConfig */
    logical        deepCopy,            /**< (I) If true, BOM Variant Configuration mode would be #BOM_VARIANT_CONFIG_COPY + #BOM_VARIANT_CONFIG_DEEP otherwise #BOM_VARIANT_CONFIG_COPY
                                                */
    tag_t*         new_config           /**< (O) BOMVariantConfig */
    );

/**
    Sets the input BOM Variant rule.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid BOMVariantConfig
    </ul>
*/
extern BOM_API int BOM_set_variant_config_bomvrule(
    tag_t          bom_variant_config,  /**< (I) BOMVariantConfig */
    tag_t          bom_vrule,           /**< (I) Can be #NULLTAG to delete the current BOM Variant rule */
    int            mode                 /**< (I) Dedicated operation mode. Valid values are:
                                              <ul>
                                              <li>#BOM_VARIANT_CONFIG_REF</li>
                                              <li>#BOM_VARIANT_CONFIG_COPY</li>
                                              <li>#BOM_VARIANT_CONFIG_MANAGED</li>
                                              <li>#BOM_VARIANT_CONFIG_DEEP</li>
                                              </ul> */
    );

/**
    Sets the input BOM StoredOptionSet. When input bom_sos is NULL then existing
    BOM StoredOptionSet would be removed which means existing modes would be Shuffled up one place.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid BOMVariantConfig or BOM Line or BOM StoredOptionSet
    </ul>
*/
extern BOM_API int BOM_set_variant_config_bomsos(
    tag_t          bom_variant_config,  /**< (I) BOMVariantConfig */
    tag_t          bom_line,            /**< (I) Tag of BOM Line */
    tag_t          bom_sos,             /**< (I) StoredOptionSet */
    int            mode                 /**< (I) Dedicated operation mode. Valid values are:
                                                <ul>
                                                <li>#BOM_VARIANT_CONFIG_REF</li>
                                                <li>#BOM_VARIANT_CONFIG_COPY</li>
                                                <li>#BOM_VARIANT_CONFIG_MANAGED</li>
                                                <li>#BOM_VARIANT_CONFIG_DEEP</li>
                                                </ul> */
    );

/**
    Retrieves BOM Variant rule and BOM StoredOptionSets for input BOMVariantConfig.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid BOMVariantConfig
    </ul>
*/
extern BOM_API int BOM_ask_variant_config(
    tag_t          bom_variant_config,    /**< (I) BOMVariantConfig */
    tag_t*         bom_vrule,             /**< (O) BOM Variant rule */
    int*           count,                 /**< (O) count of BOM StoredOptionSet */
    tag_t**        bomsoslist             /**< (OF) count */
    );

/**
    Retrieves BOM Window and Root BOM Line for input BOMVariantConfig.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag for invalid BOMVariantConfig
    </ul>
*/
extern BOM_API int BOM_ask_variant_config_context(
    tag_t          bom_variant_config,     /**< (I) BOMVariantConfig */
    tag_t*         bom_window,             /**< (O) BOM Window */
    tag_t*         root_bom_line           /**< (O) Root BOM Line */
    );

/** @} */

/**
    Creates a variant item (VI) to store the BOM line's configuration.
    A VI is an item created as an instantiation of a generic component.
    It contains a saved selected option set (SOS) for the module that the BOM line represents.
    This SOS cannot be changed throughout the lifetime of the item.

    <b>Restrictions:</b>

    The BOM line must be fully configured: each option must have a value.
*/
extern BOM_API int BOM_line_create_vi(
    tag_t          line,                               /**< (I) The BOM line for which a VI will be created */
    logical        is_linked_to_generic_component,     /**< (I) True if the VI structure is to be validated against
                                                            the structure that it instantiates.
                                                            If false, the VI structure can be altered so that it is
                                                            different from that of its generic component's structure. */
    const char*    item_id,                            /**< (I) Item identification number. No two Items can have
                                                            the same identification string. A null is allowed.
                                                            If null, the system will automatically generate an Item ID. */
    const char*    item_name,                          /**< (I) Item name. A common name or short description of the Item. */
    const char*    type_name,                          /**< (I) A null is allowed for this argument.
                                                            It can be used to specify a defined Item type. */
    const char*    rev_id,                             /**< (I) Identification string (revision ID)
                                                            of the Item Revision being created. A null is allowed.
                                                            If null, the system will automatically generate a revision ID */
    tag_t*         new_item,                           /**< (O) Tag for identifying the Item in the current program */
    tag_t*         new_rev                             /**< (O) Tag for identifying the Item Revision in the current program */
    );

/**
    Takes the values of the stored option set contained within a variant item and
    uses these to populate the values of a BOM line's selected option set.
*/
extern BOM_API int BOM_line_configure_in_vi(
    tag_t          line,              /**< (I) The BOM line to be configured using the variant item stored option set */
    tag_t          variant_item       /**< (I) The variant item to be configured into the BOM line (item tag) */
    );

/**
    For a given BOM window, this method provides an array of currently loaded BOM lines that represent generic components.
*/
extern BOM_API int BOM_window_ask_generic_components(
    tag_t          window,                      /**< (I) The BOM window being queried */
    int*           generic_component_count,     /**< (O) The number of BOM lines that are generic (not variant items) */
    tag_t**        generic_component_lines      /**< (OF) generic_component_count The BOM lines whose item revisions are modules */
    );

/**
    Determines if it is possible to identify variant item reuse of the
    given BOM line using the parent search criteria.
    Reuse identification of variant items of a BOM line is only possible if
    all the options in the BOM line have been presented to the parent.
*/
extern BOM_API int BOM_line_ask_can_search_for_vi_from_parent(
    tag_t          line,                   /**< (I) The BOM line being queried */
    logical*       reuseIdIsPossible       /**< (O) True if reuse identification is possible, otherwise false */
    );

/**
    This method is used aid identification of component reuse within a module structure.
    It identifies search criteria needed to find VIs within the given BOM line from
    criteria defined for a VI search within the parent.
    Reuse identification of VIs of the BOM line is only possible if
    all the options in the BOM line have been presented to the parent.
*/
extern BOM_API int BOM_line_map_vi_requirements_from_parent(
    tag_t          line,                 /**< (I) The BOM line (variant module) within which
                                            reuse identification is to be carried out */
    int            n,                    /**< (I) Search criteria used to find VIs in the parent BOM line (see #ITEM_vi_find) */
    tag_t*         items,                /**< (I) n Search criteria used to find VIs in the parent BOM line (see #ITEM_vi_find) */
    char**         options,              /**< (I) n Search criteria used to find VIs in the parent BOM line (see #ITEM_vi_find) */
    int*           ops,                  /**< (I) n Search criteria used to find VIs in the parent BOM line (see #ITEM_vi_find) */
    int*           valueTypes,           /**< (I) n Search criteria used to find VIs in the parent BOM line (see #ITEM_vi_find) */
    char**         lowValues,            /**< (I) n Search criteria used to find VIs in the parent BOM line (see #ITEM_vi_find) */
    char**         highValues,           /**< (I) n Search criteria used to find VIs in the parent BOM line (see #ITEM_vi_find) */
    int*           n_out,                /**< (O) Search criteria that can be used to identify VIs in the
                                            BOM line passed in as argument line.
                                            If reuse identification is not possible, then an error code is returned. */
    tag_t**        items_out,            /**< (OF) n_out Search criteria that can be used to identify VIs in the
                                            BOM line passed in as argument line.
                                            If reuse identification is not possible, then an error code is returned. */
    char***        options_out,          /**< (OF) n_out Search criteria that can be used to identify VIs in the
                                            BOM line passed in as argument line.
                                            If reuse identification is not possible, then an error code is returned. */
    int**          ops_out,              /**< (OF) n_out Search criteria that can be used to identify VIs in the
                                            BOM line passed in as argument line.
                                            If reuse identification is not possible, then an error code is returned. */
    int**          valueTypes_out,       /**< (OF) n_out Search criteria that can be used to identify VIs in the
                                            BOM line passed in as argument line.
                                            If reuse identification is not possible, then an error code is returned. */
    char***        lowValues_out,        /**< (OF) n_out Search criteria that can be used to identify VIs in the
                                            BOM line passed in as argument line.
                                            If reuse identification is not possible, then an error code is returned. */
    char***        highValues_out        /**< (OF) n_out Search criteria that can be used to identify VIs in the
                                            BOM line passed in as argument line.
                                            If reuse identification is not possible, then an error code is returned. */
    );

/**
    This function returns true if the specified BOM Line has had its stop flag set.
    The stop flag is used to control the scope of structure traversal in a BOM compare.
*/
extern BOM_API int BOM_line_is_stopped(
    tag_t          line,                   /**< (I) The BOM line being queried */
    logical*       is_stopped              /**< (O) True if the specified BOM line has its stop flag set */
    );

/**
    This function sets the stop flag on the specified BOM Line.
    The stop flag is used to control the scope of structure traversal in a BOM compare.
*/
extern BOM_API int BOM_line_set_stop(
    tag_t          line             /**< (I) The BOM line being stopped */
    );

/**
    This function clears the stop flag on the specified BOM Line.
    The stop flag is used to control the scope of structure traversal in a BOM compare.
*/
extern BOM_API int BOM_line_clear_stop(
    tag_t          line             /**< (I) The BOM line being cleared */
    );

/**
    Clears the stop flag on the specified BOM Line and all BOM Lines below it in the product structure.
    The stop flag is used to control the scope of structure traversal in a BOM compare.
*/
extern BOM_API int BOM_line_clear_all_stops(
    tag_t          line            /**< (I) The root BOM line being cleared */
    );

/**
    Assigns a child line to a BOM line,
    and keeps the association between the source line and the new created child line.
*/
extern BOM_API int BOM_line_assign_child_line(
    tag_t          line,                   /**< (I) */
    tag_t          sourceLine,             /**< (I) */
    char*          occType,                /**< (I) */
    tag_t*         newChildLine            /**< (O) */
    );

/**
    Asks if the BOM window is displaying unconfigured BOM lines.
*/
extern BOM_API int BOM_window_shows_unconfigured(
    tag_t          window,                 /**< (I) Tag of the window */
    logical*       shows_unconfigured      /**< (O) True if unconfigured BOM lines are shown */
    );

/**
    Flags the BOMWindow to display BOMLines that are not configured for Occurrence Effectivity.

    @note The window supplied must have a root line:
          You cannot call this immediately after #BOM_create_window.
*/
extern BOM_API int BOM_window_show_unconfigured(
    tag_t          window           /**< (I) Tag of the window */
    );

/**
    Flags the BOMWindow to hide BOMLines that are not configured for Occurrence Effectivity.

    @note The window supplied must have a root line:
          You cannot call this immediately after #BOM_create_window.
*/
extern BOM_API int BOM_window_hide_unconfigured(
    tag_t          window          /**< (I) Tag of the window */
    );

/**
    Make the BOM window to filter creating unconfigured bomlines due to classic variants
*/
extern BOM_API int BOM_window_filter_unconfigured_classic_variants(
    tag_t          window                 /**< (I) Tag of the window */
    );

/**
    Asks if the BOM window is displaying unconfigured BOM lines.
*/
extern BOM_API int BOM_window_filters_unconfigured_classic_variants(
    tag_t          window,                 /**< (I) Tag of the window */
    logical*       filter_unconfigured     /**< (O) True if filters unconfigured BOM lines due to classic variants */
    );

/**
    Set closure rule for the BOM window.
*/
extern BOM_API int BOM_window_set_closure_rule(
    tag_t          window,                 /**< (I) Tag of the window */
    tag_t          closure_rule,           /**< (I) Tag of Closure Rule */
    int            n_variables,            /**< (I) number of variables in closure rule */
    char**         variable_names,         /**< (I) variable names */
    char**         variable_values         /**< (I) variable values */
    );

/**
    Asks if the BOM window is displaying Guided Component Search Connection Point BOM lines.
*/
extern BOM_API int BOM_window_shows_gcs_cps(
    tag_t          window,                 /**< (I) Tag of the window */
    logical*       shows_gcs_cp            /**< (O) True if GCS CP BOM lines are shown */
    );

/**
    Sets the BOM window to display Guided Component Search Connection Point BOM lines.

    @note The window supplied must have a root line:
          You cannot call this immediately after #BOM_create_window.
*/
extern BOM_API int BOM_window_show_gcs_cps(
    tag_t          window           /**< (I) Tag of the window */
    );

/**
    Sets the BOM window to hide Guided Component Search Connection Point BOM lines.

    @note The window supplied must have a root line:
          You cannot call this immediately after #BOM_create_window.
*/
extern BOM_API int BOM_window_hide_gcs_cps(
    tag_t          window          /**< (I) Tag of the window */
    );

/**
    Asks the value of the show_suppressed_occurrences flag property

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_window_shows_suppressed(
      tag_t window,                    /**< (I) Tag of BOMWindow */
      logical *shows_suppressed        /**< (O) show_suppressed_occurrences flag */
    );
/**
    Shows the suppressed occurrences when the show_suppressed_occurrences flag property is true

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_window_show_suppressed(
      tag_t window                     /**< (I) Tag of BOMWindow */
    );
/**
    Hides the suppressed occurrences when the show_suppressed_occurrences flag property is false

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_window_hide_suppressed(
      tag_t window                     /**< (I) Tag of BOMWindow */
    );

/**
    @name BOM Compare Functions

    <b>Common Return Values</b>

    #BOM_no_current_compare - The BOMCompare has not yet been supplied to #BOM_compare_execute
                              (or #BOM_compare, for the standard internal compare),
                              or an error occurred during the last such call that invalidated the comparison.<br>
    #BOM_no_such_bom_compare_mode - No mode by that name yet registered.
    @{
*/

/**
    Creates a new BOM Compare object.
    This new compare object can then be used in preference to the internal pre-defined object
    used by the #BOM_compare call and the User Interface.
    This allows multiple BOM Compares to be performed simultaneously.
*/
extern BOM_API int BOM_compare_create(
    tag_t*         bomcompare        /**< (O) New empty BOM Compare object that can be passed into #BOM_compare_execute */
    );

/**
    Deletes a BOM Compare object.
*/
extern BOM_API int BOM_compare_delete
    ( tag_t bomcompare              /**< (I) BOM Compare object to be deleted */
    );

/**
    Retrieves an array of valid compare mode names.
    Compare modes can set a visibility flag to control whether a
    specific mode will show up in the user interface or not.
*/
extern BOM_API int BOM_compare_ask_modes (
    logical        visible_only,        /**< (I) This is for future expansion, and should be set false */
    int*           n_modes,             /**< (O) Number of mode names returned */
    char***        mode_names           /**< (OF) n_modes Array of mode names */
    );

/** @if DOX_IGNORE
    (TB) 23-Aug-2001 This directive introduces the header containing the typedefs required for
    BOM_compare_visit_engine's auto-generated journalling code. The <p> directive marks a
    non-void black-box pointer, in this case, a function pointer. Customers needn't worry about
    such lower-case flags.

    ##include bom/bom_tokens.h
@endif */

/**
    Performs a recursive depth-first traversal of the root compare engine and its children,
    calling the enter_engine callback for each engine before any of its children,
    and calling the leave_engine callback immediately after the final child of that engine.
    Apart from the topmost (depth=0) engine, compare engines have an associated compare set that
    you may interrogate to retrieve the root lines' key values.
    Only compare sets with differing sides, or engines that are the ancestors of such sets, are visited.

    For all the call-back functions, returning #ITK_ok indicates success.
    Any other value will abort the traversal and cause the function to fail with the same error code.
    Any error returned by your callbacks should be returned back to you by this call.
*/
extern BOM_API int BOM_compare_visit_engine (
    tag_t                          bomcompare,     /**< (I) BOM Compare object to be queried.
                                                        Set this to #NULLTAG to query the standard internal BOMCompare. */
    BOM_compare_engine_visitor_t*  enter_engine,   /**< (Ip) Engine entry callback */
    BOM_compare_engine_visitor_t*  leave_engine,   /**< (Ip) Engine departure callback */
    BOM_compare_set_visitor_t*     visit_set,      /**< (Ip) Set visiting callback */
    void*                          user_data       /**< (I) A pointer for the user's use: passed to all callbacks. */
    );

/**
    Retrieves the name of the mode of the given BOM Compare.
*/
extern BOM_API int BOM_compare_ask_mode (
    tag_t          bomcompare,     /**< (I) BOM Compare object, or #NULLTAG for the standard internal BOMCompare. */
    char**         mode_name       /**< (OF) Name of the BOM Compare's mode */
    );

/**
    Retrieves the output mode of the given BOM Compare.
*/
extern BOM_API int BOM_compare_ask_output_mode (
    tag_t          bomcompare,             /**< (I) BOM Compare object, or #NULLTAG for the standard internal BOMCompare. */
    int*           output_mode             /**< (O) BOM Compare's output mode */
    );

/**
    Retrieves the root BOMLines of the given BOM Compare.
*/
extern BOM_API int BOM_compare_ask_root_bomlines (
    tag_t          bomcompare,            /**< (I) BOM Compare object, or #NULLTAG for the standard internal BOMCompare */
    tag_t*         bomline1,              /**< (O) Root BOMLine of the first BOM being compared */
    tag_t*         bomline2               /**< (O) Root BOMLine of the second BOM being compared */
    );

/**
    Retrieves the root BOMLines of the given BOM Compare engine.
*/
extern BOM_API int BOM_compare_ask_engine_root_bomlines (
    tag_t          bomcompareengine,          /**< (I) BOM Compare Engine object */
    tag_t*         bomline1,                  /**< (O) Root BOMLine of the first BOM being compared */
    tag_t*         bomline2                   /**< (O) Root BOMLine of the second BOM being compared */
    );

/**
    Creates a new BOM Compare mode.
    <UL>
    <LI>Use auto-pack for any multi-level compare based on
        the same comparison as packing (by default, item ID and sequence number).
    <LI>Use virtual-unpack for comparisons with primary elements that
        aren't closely related to the packing condition.
    <LI>For multi-level compares based on a comparison that is not
        closely related to the packing condition, you're on your own:
        recommendation is to fully unpack the structure before you compare it.
    </UL>
    Six standard modes are pre-defined to support the modes offered by the old BOM_compare() function.

    Primary keys: item id; Aggregate keys: revision and quantity.

    #BOM_std_compare_single_level_name <br>
    #BOM_std_compare_lowest_level_name <br>
    #BOM_std_compare_var_level_name

    Primary keys: item id and sequence number; Aggregate keys: revision and quantity.

    #BOM_std_compare_single_level_seq_name <br>
    #BOM_std_compare_lowest_level_seq_name <br>
    #BOM_std_compare_var_level_seq_name

    All six have special support for the old style of text report output and bomline properties,
    which can be enabled by setting the preferences BOM_compare_legacy_report and
    BOM_compare_legacy_properties respectively. User-defined modes cannot have this legacy support.

    <b>Return Values:</b>

    #BOM_duplicate_bom_compare_mode - A mode by that name already exists.
*/
extern BOM_API int BOM_compare_define_mode (
    const char*    mode_name,          /**< (I) Name of the new compare mode */
    int            traversal_mode,     /**< (I) Will this compare mode be single level (#BOM_compare_singlelevel),
                                            lowest (leaf) level (#BOM_compare_lowestlevel),
                                            or multi-level (#BOM_compare_multilevel)? */
    tag_t          compare_desc,       /**< (I) Compare engine descriptor to be used */
    logical        visible,            /**< (I) This is for future expansion. Set it to false. */
    logical        autopack,           /**< (I) Set this to true if this mode should perform auto-packing */
    logical        virtualunpack       /**< (I) Set this to true if this mode should perform virtual-unpacking */
    );

/**
    Retrieves details of the named BOM Compare mode.
*/
extern BOM_API int BOM_compare_ask_mode_info (
    const char*    mode_name,         /**< (I) Name of the new compare mode */
    int*           traversal_mode,    /**< (O) Single level, lowest level, or multi level. */
    tag_t*         compare_desc,      /**< (O) Compare engine descriptor */
    logical*       visible,           /**< (O) For future expansion. Ignore this value. */
    logical*       autopack,          /**< (O) Autopacking flag */
    logical*       virtualunpack      /**< (O) Autounpacking flag */
    );

/**
    Sets the visibility mode for the specified BOM compare mode.

    @note This ITK is reserved for future use.
*/
extern BOM_API int BOM_compare_set_visibility (
    const char*    mode_name,   /**< (I) Name of the compare mode to be used (see #BOM_compare_define_mode) */
    logical        visible      /**< (I) The visibility flag is currently unused, set it to false */
    );

/**
    Retrieves the state of unchanged compare sets in report for specified BOM Compare mode.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_no_such_bom_compare_mode if compare mode is invalid
    </ul>

*/
extern BOM_API int BOM_compare_reports_unchanged(
    const char*    mode_name,           /**< (I) Name of the compare mode to be used (see #BOM_compare_define_mode) */
    logical*       reports_unchanged    /**< (O) True indicates unchanged compare sets wil be reported */
    );

/**
    Sets the state of unchanged compare sets in report for specified BOM Compare mode.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_no_such_bom_compare_mode if compare mode is invalid
    </ul>
*/
extern BOM_API int BOM_compare_set_rpt_unchanged(
    const char*    mode_name,           /**< (I) Name of the compare mode to be used (see #BOM_compare_define_mode) */
    logical        report_unchanged     /**< (I) Set to true if you want to report unchanged compare sets */
    );

/**
    Compares the specified BOM lines. Supports all three compare modes.
    Compare output can be directed to the BOM line compare columns,
    which can be accessed via the BOM line attribute functions.
    Report output can also be obtained.
    Alternatively, the BOM compare user exit functions can be used.
    All of these output mechanisms can be used simultaneously,

    The scope of the compare can be controlled via the BOM line stop flag ITK functions.
    These allow a flag to be set on a BOM line which will prevent
    the BOM compare from comparing anything below that BOM line.

    <b>Restrictions:</b>

    Compare does not allow nested BOM lines to be compared.
*/
extern BOM_API int BOM_compare(
    tag_t          line1,          /**< (I) Tag of the first BOM line to be compared */
    tag_t          line2,          /**< (I) Tag of the second BOM line to be compared */
    int            mode,           /**< (I) Compare mode to be used. Can be one of the following: <br>
                                        #BOM_compare_singlelevel <br>
                                        #BOM_compare_lowestlevel <br>
                                        #BOM_compare_multilevel */
    int            output          /**< (I) Output mechanism to be used.
                                        Constructed by adding the following values as required: <br>
                                        #BOM_compare_output_bomline <br>
                                        #BOM_compare_output_userexit <br>
                                        #BOM_compare_output_report */
    );

/**
    Compares the two BOMs defined by the given BOMLines.
*/
extern BOM_API int BOM_compare_execute(
    tag_t          bomcompare,         /**< (I) BOM Compare object to be used to perform the comparison.
                                            Set this to #NULLTAG to use the standard internal BOMCompare. */
    tag_t          bomline1,           /**< (I) Root BOMLine of the first BOM to be compared */
    tag_t          bomline2,           /**< (I) Root BOMLine of the second BOM to be compared */
    const char*    mode_name,          /**< (I) Name of the compare mode to be used (see #BOM_compare_define_mode) */
    int            output_to           /**< (I) Where to send the compare results (see #BOM_compare for details) */
    );

/**
    Clears the compare columns from all BOM lines relating to the last compare.
*/
extern BOM_API int BOM_compare_clear(
    tag_t          compare_context         /**< (I) Tag of the compare object (when using BOM_compare_create/execute), or #NULLTAG
                                                (or a relevant bomline tag) to access the global compare object (when using BOM_compare). */
    );

/**
    Suppresses the specified compare output for the given context.
    This is only useful when used in the BOM compare user exit functions.
    For example, it can be used to allow a user exit generated report to
    replace the standard internal report window.
    It seems unlikely you will want to use this other than with the default context.


    <b>Restrictions:</b>

    It cannot be used to suppress all output.
*/
extern BOM_API int BOM_compare_suppress(
    tag_t          compare_context,           /**< (I) Tag of the compare object (when using BOM_compare_create/execute), or #NULLTAG
                                                (or a relevant bomline tag) to access the global compare object (when using BOM_compare). */
    int            output                     /**< (I) Output modes to be suppressed.
                                                    Constructed by adding the following values as required: <br>
                                                    #BOM_compare_output_bomline <br>
                                                    #BOM_compare_output_userexit <br>
                                                    #BOM_compare_output_report */
    );

/**
    Retrieves two lists which contain the BOM lines relating to a particular compare item.

    @note The compare item required as an input parameter to this function
          is not the same as a Teamcenter Engineering Item.
          The tag of the compare item is passed to the BOM compare user exit functions.
          It can also be obtained via #BOM_compare_report.
*/
extern BOM_API int BOM_compare_list_bomlines(
    tag_t          cmp_item,                /**< (I) Tag of a compare item */
    int*           count1,                  /**< (O) Number of BOM lines in first list */
    tag_t**        bomline_list1,           /**< (OF) count1 Array of BOM line tags from the first compared BOM */
    int*           count2,                  /**< (O) Number of BOM lines in second list */
    tag_t**        bomline_list2            /**< (OF) count2 Array of BOM line tags from the second compared BOM */
    );

/**
    Retrieves a bit encoded representation of the changes which occurred in
    a particular compare item between the two compared BOMs.
    <br/>Macros are provided to extract the individual flags from the diff_flags.

    Use these macros to interrogate the flags:

    @code
        #include <bom/bom_tokens.h>

        BOM_cmp_no_diff(diff_flags)
        BOM_cmp_added(diff_flags)
        BOM_cmp_changed(diff_flags)
        BOM_cmp_chg_qty(diff_flags)
        BOM_cmp_chg_rev(diff_flags)
    @endcode

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>Possibly other BOM errors
    </ul>

    @note The compare item required as an input parameter to this function
          is not the same as a Teamcenter Engineering Item.
          The tag of the compare item is passed to the BOM compare user exit functions.
          It can also be obtained via #BOM_compare_report.
*/
extern BOM_API int BOM_compare_ask_difference(
    tag_t          cmp_item,         /**< (I) Tag of a compare item */
    int*           diff_flags        /**< (O) Bit encoded differences between the two BOMs relating to the compare item */
    );

/**
    Retrieves the quantities of the specified compare item in each of the compared BOMs.

    @note The compare item required as an input parameter to this function
          is not the same as a Teamcenter Engineering Item.
          The tag of the compare item is passed to the BOM compare user exit functions.
          It can also be obtained via #BOM_compare_report.
*/
extern BOM_API int BOM_compare_ask_qty(
    tag_t          cmp_item,       /**< (I) Tag of a compare item. */
    double*        qty1,           /**< (O) Quantity of the item in the first BOM selected for compare. */
    double*        qty2            /**< (O) Quantity of the item in the first BOM selected for compare.
                                        @note In the quantity output parameters,
                                        a value less than zero indicates a special case.
                                        The exact nature of this special case can be obtained using these macros:

                                        #BOM_cmp_asreq (qty) <br>
                                        If true, then quantity is As Required.

                                        #BOM_cmp_undef (qty) <br>
                                        If true, then quantity is undefined. */
    );

/**
    Retrieves the revisions of the specified compare item in each of the compared BOMs.

    @note The compare item required as an input parameter to this function
          is not the same as a Teamcenter Engineering Item.
          The tag of the compare item is passed to the BOM compare user exit functions.
          It can also be obtained via #BOM_compare_report.
    @note In the revision output parameters, ??? means no revision is configured
*/
extern BOM_API int BOM_compare_ask_rev(
    tag_t          cmp_item,      /**< (I) Tag of a compare item */
    char**         rev1,          /**< (OF) Revision of the item in the first BOM selected for compare */
    char**         rev2           /**< (OF) Revision of the item in the first BOM selected for compare */
    );

/**
    Retrieves the sequence number of the specified compare item in the compared BOMs.

    @note In single-level mode and multi-level mode, the sequence number will be the same in both BOMs. <br>
          In lowest-level mode, items with many different sequence numbers can be bundled together,
          and the return value from this function could be any one of them.
    @note The compare item required as an input parameter to this function
          is not the name as a Teamcenter Engineering Item.
          The tag of the compare item is passed to the BOM compare user exit functions.
          It can also be obtained via #BOM_compare_report.
*/
extern BOM_API int BOM_compare_ask_seqno(
    tag_t          cmp_item,        /**< (I) Tag of a compare item */
    char**         seqno            /**< (OF) Sequence number of the item in the both BOMs. (except in lowest-level mode). */
    );

/**
    Retrieves a list which contains the BOM lines which have a difference related to them.
    <br/>It also retrieves a bit encoded representation list of difference flags for those BOM Lines.
    <br/>Macros are provided to extract the individual flags from the diff_flags.

    Use these macros to interrogate the flags:

    @code
        #include <bom/bom_tokens.h>

        BOM_cmp_no_diff(diff_flags[i])
        BOM_cmp_added(diff_flags[i])
        BOM_cmp_changed(diff_flags[i])
        BOM_cmp_chg_qty(diff_flags[i])
        BOM_cmp_chg_rev(diff_flags[i])
    @endcode

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_compare_list_diffs(
    tag_t          line,             /**< (I) Tag of one of the BOM lines which the compare was performed on */
    int*           diff_count,       /**< (O) Number of BOM lines in the list */
    tag_t**        diff_lines,       /**< (OF) diff_count Array of BOM line tags */
    int**          diff_flags        /**< (OF) diff_count Array of flags indicating the disposition of the bomlines compared with the other side */
    );

/**
    For the nominated compare context (or the default context if the compare context is #NULLTAG),
    for the side of the compare on which the nominated bomline is the root,
    returns two arrays of length diff_count. One lists the different bomlines,
    the other holds flags indicating whether each line is added or different.
    For the standard (legacy) modes, additional flags indicate a change in revision and/or quantity also.

    Use these macros to interrogate the flags:

    @code
        #include <bom/bom_tokens.h>

        BOM_cmp_no_diff(diff_flags[i])
        BOM_cmp_added(diff_flags[i])
        BOM_cmp_changed(diff_flags[i])
        BOM_cmp_chg_qty(diff_flags[i])
        BOM_cmp_chg_rev(diff_flags[i])
    @endcode
*/
extern BOM_API int BOM_compare_list_diffs_context(
    tag_t          line,            /**< (I) The root line of one side of the compare performed in the compare context */
    tag_t          context,         /**< (I) A compare context (obtained from #BOM_compare_create)
                                            or #NULLTAG for the default context */
    int*           diff_count,      /**< (O) The number of lines in the following two arrays */
    tag_t**        diff_lines,      /**< (OF) diff_count Array of tags of the bomlines */
    int**          diff_flags       /**< (OF) diff_count Array of flags indicating the disposition of
                                            the bomlines compared with the other side */
    );

/**
    Retrieves a formatted text report of BOM differences.
    It also returns an list of the compare items which relate to each report line.
    These compare items can then be queried to obtain the original BOM Lines relating to that report line.

    @note The compare item returned by this function in the report_items list is not
          the same as a Teamcenter Engineering item.
          A compare item can only be used in certain BOM compare functions.
*/
extern BOM_API int BOM_compare_report(
    tag_t          compare_context,        /**< (I) Tag of the compare object (when using BOM_compare_create/execute), or #NULLTAG
                                                (or a relevant bomline tag) to access the global compare object (when using BOM_compare). */
    int*           report_length,          /**< (O) Number of lines in the report */
    char***        report_lines,           /**< (OF) report_length Array of report lines. The first array entry
                                                (report_lines[0]) contains the column headers. */
    tag_t**        report_items            /**< (OF) report_length Array of compare item tags.
                                                Entries which relate to report lines, but are not compare items
                                                (e.g., the column headers) will have their tag set to #NULLTAG. */
    );

/**
    Retrieves details of the column layout in the compare report generated via #BOM_compare_report.
    It returns the number of columns, the width of each column,
    the number of spaces between the columns, and the overall width of the report.
*/
extern BOM_API int BOM_compare_report_size(
    tag_t          compare_context,         /**< (I) Tag of the compare object (when using BOM_compare_create/execute), or #NULLTAG
                                                (or a relevant bomline tag) to access the global compare object (when using BOM_compare). */
    int*           report_width,            /**< (O) Width of the report */
    int*           column_spacer,           /**< (O) Number of spaces between each column */
    int*           column_count,            /**< (O) Number of columns */
    int**          column_width             /**< (OF) column_count Array of column widths */
    );

/** @} */

/**
    @name BOM Snapshot Folder creation functions
    @{
*/

extern BOM_API int BOM_create_snapshot(
    tag_t          bom_window,         /**< (I) */
    const char*    name,               /**< (I) */
    const char*    desc,               /**< (I) */
    tag_t*         snapshot_folder     /**< (O) */
    );

/** @} */

/**
    @name BOM Baseline Functions
    @{
*/

/**
    This ITK creates a Baseline Revision for the structure represented by the input configured BOM Window.
    The BOMWindow would be traversed recursively to create baselines for each of the child components,
    and creates baselines for each of the Work in Process Item Revisions.
    If the child component were released then, that would be reused.
    Precise PSBOMView Revision would be created for new structure, if the preference Baseline_precise_bvr is set as "1" or "2".
    It would create a snapshot folder that is attached to the baseline_rev, based on the preference.
    The ITK would generate a Baseline Revision ID using
    #USER_new_revision_id_from_alt_rule("PDR", , , , ,) for all the subcomponents.
    The description entered would be set as the description of the Baseline Revision.
    Once the creation of the Baseline Revision is completed,
    the Baseline Revision would undergo the release process as given by the rel_proc_name and
    having name and desc as jobName and jobDescription respectively.

    @note The infodba user is an admininstrative superuser account and should not be used for baseline operation.
*/
extern BOM_API int BOM_create_baseline(
    tag_t          bom_window,         /**< (I) Item Revision that needs to be Baselined */
    const char*    name,               /**< (I) The Revision Id of the Baseline Item Revision */
    const char*    desc,               /**< (I) Description that needs to be set on the Baseline Item Revision */
    const char*    rel_proc_name,      /**< (I) Name of the Release Procedure through which the Baseline Revision should under go */
    const char*    jobName,            /**< (I) Name of the Job */
    const char*    jobDescription,     /**< (I) Description of the Job */
    tag_t*         baseline_rev        /**< (O) Item Revision Tag of the Baseline Revision created */
    );

/**
    This ITK creates a Baseline Revision for the structure represented by the input configured BOM Window.
    The BOMWindow would be traversed recursively to create baselines for each of the child components,
    and creates baselines for each of the Work in Process Item Revisions.
    If the child component were released then, that would be reused.
    It would create a snapshot folder with baseline_label_name.
    The ITK would generate a Baseline Revision ID using
    #USER_new_revision_id_from_alt_rule("PDR", , , , ,) for all the subcomponents.
    The description entered would be set as the description of the Baseline Revision.
    Once the creation of the Baseline Revision is completed,
    the Baseline Revision would undergo the release process as given by the rel_proc_name and
    having name and desc as jobName and jobDescription respectively.
*/
extern BOM_API int BOM_create_baseline_with_baseline_label(
    tag_t          bom_window,         /**< (I) Item Revision that needs to be Baselined */
    const char*    name,               /**< (I) The Revision Id of the Baseline Item Revision */
    const char*    desc,               /**< (I) Description that needs to be set on the Baseline Item Revision */
    const char*    rel_proc_name,      /**< (I) Name of the Release Procedure through which the Baseline Revision should under go */
    const char*    jobName,            /**< (I) Name of the Job */
    const char*    baseline_label_name, /**< (I) Name of the Snapshot Folder */
    const char*    jobDescription,     /**< (I) Description of the Job */
    tag_t*         baseline_rev        /**< (O) Item Revision Tag of the Baseline Revision created */
    );

/**
    This ITK creates a does a dryrun of baseline creation for the input BOMWindow.
    It does not create the baseline but runs through all the pre-conditions, user error checks
    and places the results in the filename pointed by the logFileName. FullLogFileName provides
    the full path to the  LogFileName.
    If there is any error from the pre-conditions or the user checks, the error_registed would be set to TRUE.
*/
extern BOM_API int BOM_dryrun_baseline(
    tag_t         bom_window,          /**< (I)  Tag of the BOMWindow for which we are creating the baseline */
    const char*   rel_proc_name,       /**< (I)  Name of the Release Procedure through which the Baseline Revision should under go */
    char**        logFileName,         /**< (OF) Name of the LogFile Generated */
    char**        fullLogFileName,     /**< (OF) FullPath of the output logfile, including the logfilename */
    logical*      error_registered     /**< (O)  Flag that indicates atleast one of the bomline had errors in the validation */
    );

/** @} */

extern BOM_API int BOM_create_window_from_snapshot(
    tag_t          snapshot_folder,          /**< (I) */
    tag_t*         bom_window                /**< (O) */
    );


/** @if DOX_IGNORE
    (TB) 18-Feb-2002 This directive introduces the header containing the typedefs required for
    BOM_writer's auto-generated journalling code. The <p> directive marks a non-void black-box
    pointer, in this case a struct pointer. Customers needn't worry about such lower-case
    flags.

    ##include bom/bomwriter.h
@endif */

/**
    Allocates memory for the input-structure parameters required by BOM_writer_write_bomwindow(),
    and initializes each structure with suitable default values
    (including a hidden value that distinguishes the various different structures).
    The user changes any necessary values in each structure before using it.
*/
extern BOM_API int BOM_writer_new_output_file (
    BOM_writer_output** p     /**< (OFp) A BOM_writer_delete()able data-structure,
                                   to be passed to BOM_writer_write_bomwindow() */
    );

/**
    Allocates memory for the input-structure parameters required by BOM_writer_write_bomwindow(),
    and initializes each structure with suitable default values
    (including a hidden value that distinguishes the various different structures).
    The user changes any necessary values in each structure before using it.
*/
extern BOM_API int BOM_writer_new_output_smstring (
    BOM_writer_output** p     /**< (OFp) A BOM_writer_delete()able data-structure,
                                   to be passed to BOM_writer_write_bomwindow() */
    );

/**
    Allocates memory for the input-structure parameters required by BOM_writer_write_bomwindow(),
    and initializes each structure with suitable default values
    (including a hidden value that distinguishes the various different structures).
    The user changes any necessary values in each structure before using it.
*/
extern BOM_API int BOM_writer_new_format_empty (
    BOM_writer_format** p     /**< (OFp) A BOM_writer_delete()able data-structure,
                                   to be passed to BOM_writer_write_bomwindow() */
    );

/**
    Allocates memory for the input-structure parameters required by BOM_writer_write_bomwindow(),
    and initializes each structure with suitable default values
    (including a hidden value that distinguishes the various different structures).
    The user changes any necessary values in each structure before using it.
*/
extern BOM_API int BOM_writer_new_format_ajt (
    BOM_writer_format** p     /**< (OFp) A BOM_writer_delete()able data-structure,
                                   to be passed to BOM_writer_write_bomwindow() */
    );

/**
    Allocates memory for the input-structure parameters required by BOM_writer_write_bomwindow(),
    and initializes each structure with suitable default values
    (including a hidden value that distinguishes the various different structures).
    The user changes any necessary values in each structure before using it.
*/
extern BOM_API int BOM_writer_new_format_plmxml (
    BOM_writer_format** p     /**< (OFp) A BOM_writer_delete()able data-structure,
                                   to be passed to BOM_writer_write_bomwindow() */
    );

/**
    Allocates memory for the input-structure parameters required by BOM_writer_write_bomwindow(),
    and initializes each structure with suitable default values
    (including a hidden value that distinguishes the various different structures).
    The user changes any necessary values in each structure before using it.
*/
extern BOM_API int BOM_writer_new_format_flatten (
    BOM_writer_format** p     /**< (OFp) A BOM_writer_delete()able data-structure,
                                   to be passed to BOM_writer_write_bomwindow() */
    );

/**
    Allocates memory for the input-structure parameters required by BOM_writer_write_bomwindow(),
    and initializes each structure with suitable default values
    (including a hidden value that distinguishes the various different structures).
    The user changes any necessary values in each structure before using it.
*/
extern BOM_API int BOM_writer_new_traversal (
    BOM_writer_traversal**  p  /**< (OFp) A BOM_writer_delete()able data-structure,
                                   to be passed to BOM_writer_write_bomwindow() */
    );

/**
    This function performs a depth-first traversal of the bom_window according to
    the values set in the parameter structures supplied, and emits the result as requested.

    You can nominate an output format (e.g. AJT, PLMXML) and an output mechanism
    (e.g. file handle) to decide how the BOM lines are presented.
    Most output formats have additional options.

    By default, all lines in the BOM window will appear in the output,
    but you can instead select one or more lines,
    and specify whether you want just the selected lines and their ancestors to appear,
    or to have the selected lines - descendants appear as well.

    Recommendation: bom_window should not have any packing. See bomwriter.h.

    <b>Return Values</b>
    <dl>
    <dt>#BOM_writer_parameter_is_null
    <dd>BOM_writer parameter '\<xxxx\>' is null - The named parameter was passed with with a null value.
    <dt>#BOM_writer_parameter_is_wrong_type
    <dd>BOM_writer parameter '\<xxxx\>' is wrong type - the named parameter was not an output, format,
        or traversal as it should have been, or was otherwise invalid.
    <dt>#BOM_writer_matrix_missing_or_null
    <dd>BOM_writer (legacy) matrix is missing or null - A legacy (pre-UG/NX) transform on a bomline was missing,
        and there was no conversion factor for new-style transforms. Consider -identity=true to circumvent this.
    <dt>#BOM_writer_plmxml_save_error
    <dd>PLMXML Toolkit save errors: \<xxx\> - an error was encountered while
        saving the PLMXML document through the Parasolid PLMXML toolkit.
        The message has been copied into the error report.
    <dt>#BOM_writer_format_requires_output
    <dd>BOM_writer format was given NULL output mechanism
    <dt>#BOM_writer_builder_class_not_found
    <dd>BOM_writer builder class '\<xxx\>' was not found -        The caller requested a PLMXML format build class that is not registered. <br>
    </dl>
*/
extern BOM_API int BOM_writer_write_bomwindow (
    tag_t                  bom_window,        /**< (I) The window is written as-is: you should set revision rule,
                                                   packing status, and hide unconfigured variants, etc */
    BOM_writer_output*     output_p,          /**< (Ip) The structure selecting and describing where the file-data should go */
    BOM_writer_format*     format_p,          /**< (Ip) The structure selecting and describing which file format to use */
    BOM_writer_traversal*  traversal_p        /**< (Ip) The structure giving traversal options */
    );

/**
    Retrieves the registered PLMXML Builder class names and descriptions.

    #BOM_writer_format_plmxml->builder_name should be set to one of these.
*/
extern BOM_API int BOM_writer_get_plmxml_builders (
    int*           count,          /**< (O) */
    char***        names,          /**< (OF) count */
    char***        descriptions    /**< (OF) count */
    );

/**
    Deletes "block" and any associated structures.
*/
extern BOM_API int BOM_writer_delete (
    void*          block         /**< (I) */
    );

/**
    Flags window to show unconfigured BOM lines by Incremental changes.
*/
extern BOM_API int BOM_window_show_incremental_changes(
    tag_t          bom_window              /**< (I) */
    );

/**
    Flags window to hide unconfigured BOM lines by Incremental changes.
*/
extern BOM_API int BOM_window_hide_incremental_changes(
    tag_t          bom_window              /**< (I) */
    );

/**
    Sets the config context to this window: it will set RevisionRule and Saved VRule to the window
*/
extern BOM_API int BOM_set_window_config_context(
    tag_t          window,                     /**< (I) */
    tag_t          config_context              /**< (I) */
    );

/**
    Gets a bomline from an apprPathNode
*/
extern BOM_API int BOM_window_get_bomline_from_apprPathNode(
    tag_t          window,                  /**< (I) Tag to bomwindow */
    tag_t          pathNode,                /**< (I) Tag to pathNode */
    tag_t          intermediateParentLine,  /**< (I) Tag to intermediate line for future - can be null */
    tag_t*         pathNodeBomLine          /**< (O) Pointer to a tag to bomline - null if not found */
    );

/**
    Adds an Incremental Change Element to a BOM line

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>#BOM_not_in_ic_context if BOM is not in IC context
    <li>#BOM_op_invalid_on_root if BOM line is root line
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_line_create_add_ice(
    tag_t          line,                     /**< (I) Tag of BOM line */
    tag_t*         new_ice                   /**< (O) Tag of the Incremental Change Element created */
    );

/**
    Removes an Incremental Change Element from a BOM line

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>#BOM_not_in_ic_context if BOM is not in IC context
    <li>#BOM_op_invalid_on_root if BOM line is root line
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_line_create_remove_ice(
    tag_t          line,                     /**< (I) Tag of BOM line */
    tag_t*         new_ice                   /**< (O) Tag of the Incremental Change Element removed */
    );

/**
    Removes a list of incremental changes from a bom line
*/
extern BOM_API int BOM_line_remove_incremental_changes(
    tag_t line,                   /**< (I) */
    int n,                        /**< (I) */
    tag_t * ices                  /**< (I) n */
    );

/**
    Retrieves all the related substitutes for the Occurrence Thread and Child Item from the BOMLine

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>Failed to get the occurrence error
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_line_list_related_substitutes(
    tag_t   bom_line,         /**< (I) Tag of BOMLine */
    int     *n_items,         /**< (O) Number of related substitutes */
    tag_t   **related_occs,   /**< (OF) Array of related occurrences */
    tag_t   **related_items   /**< (OF) Array of related substitutes */
);

/**
    Removes the relation between given substitute items, which are passed in as
    Occurrence threads and Child Items of this line.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tags are invalid
    <li>#PS_cant_modify_bvr if the parent BVR is not modifiable
    <li>Possibly other BOM/PS errors
    </ul>
*/
extern BOM_API int BOM_line_remove_related_substitutes(
    int    n_lines,    /**< (I) Number of related substitutes */
    tag_t  *lines      /**< (I) n_lines Tag of related substitutes */
);
/**
    Creates the relation between given substitute items, which are passed in as
    Occurrence threads and Child Items of this line.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tags are invalid
    <li>#PS_cant_modify_bvr if the parent BVR is not modifiable
    <li>Possibly other BOM/PS errors
    </ul>
*/
extern BOM_API int BOM_line_relate_substitutes(
    int     n_lines,            /**< (I) Number of related substitutes */
    tag_t   *bom_lines,         /**< (I) n_lines Tag of related substitutes */
    tag_t   *substitute_set     /**< (O) Array of related substitutes */
);
/**
    Adds optional item to any occurrence and its child items of this line.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tags are invalid
    <li>Possibly other BOM/PS errors
    </ul>
*/
extern BOM_API int BOM_line_add_optional_item(
    tag_t  bom_line,         /**< (I) The line to add optional item */
    tag_t  item,             /**< (I) The optional item */
    tag_t  rev,              /**< (I) The optional item rev */
    tag_t  bomview           /**< (I) The BV to add */
);

/**
    Removes optional item from any occurrence and its child items of this line.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tags are invalid
    <li>Possibly other BOM/PS errors
    </ul>
*/
extern BOM_API int BOM_line_remove_optional_item(
    tag_t  bom_line,         /**< (I) The line to remove optional item */
    tag_t  item,             /**< (I) The optional item */
    tag_t  rev,              /**< (I) The optional item rev */
    tag_t  bomview           /**< (I) The BV to remove */
);
/**
    Lists previously defined optional items for the occurrence of this line.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tags are invalid
    <li>Possibly other BOM/PS errors
    </ul>
*/
extern BOM_API int BOM_line_ask_optional_items(
    tag_t  bom_line,     /**< (I) The line to list optional items */
    int    *count,       /**< (O) Number of optional items */
    tag_t  **opt_items,   /**< (OF) count Array of optional items */
    tag_t  **opt_views    /**< (OF) count Array of optional views, always NULL */
);

/**
    @name BOM Post-Configuration functions
    @{
*/

/**
    Applies forced configurations on the BOMLine. For override_status as #BOM_LINE_FORCE_CONFIGURE_IN,
    set force_parents_too to true to force configurations on parent as well.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>Possibly other BOM/PS errors
    </ul>
*/
extern BOM_API int BOM_line_force_config(
    tag_t       bomline,            /**< (I) BOMLine to force configure in or out */
    logical     force_parents_too,  /**< (I) Set to true to force in parents too. Has no effect when
                                             forcing out, as this never effects parents. */
    int         override_status     /**< (I) BOM_LINE_FORCE_CONFIGURE_IN or BOM_LINE_FORCE_CONFIGURE_OUT */
    );

/**
    Clears forced configurations from the BOM Window.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>Possibly other BOM/PS errors
    </ul>
*/
extern BOM_API int BOM_window_clear_all_forced_configs(
    tag_t       bomwindow           /**< (I) BOMWindow in which to clear forced configurations */
    );

/**
   Creates a new BOM Forced Configuration Transaction.

    @returns #ITK_ok always
*/
extern BOM_API int BOM_start_forced_config(
    tag_t       *transaction        /**< (O) BOMConfigurationTransaction created */
    );

/**
    Deletes the BOM Forced Configuration Transaction.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    </ul>
*/
extern BOM_API int BOM_end_forced_config(
    tag_t       transaction         /**< (I) BOMConfigurationTransaction to be deleted */
    );

/** @} */

/**
    @name OccurrenceTypeFilters Occurrence Type Filters functions
    @{
*/

/**
    Displays bomlines based on the filter specified using Select Occurrence Type Filters command.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    </ul>
*/
extern BOM_API int  BOM_window_show_occ_type_filter(
  tag_t  window_tag           /**< (I) Tag of the window */
  );

/**
    Displays all bomlines ignoring the filter specified using Select Occurrence Type Filters command.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    </ul>
*/
extern BOM_API int BOM_window_hide_occ_type_filter(
  tag_t  window_tag           /**< (I) Tag of the window */
  );

/**
    Sets the input Occurrence Type Filters on the window.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>Possibly other BOM/PS errors
    </ul>
*/
extern BOM_API int BOM_window_set_occ_type_filter(
    tag_t window_tag,           /**< (I) Tag of the window */
    int count,                  /**< (I) Number of Occurrence Type Filters to be set on window */
    char **typeList             /**< (I) count The Occurrence Type Filters to be set on window */
    );

/**
    Retrieves the Occurrence Type Filters set on the window.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>Possibly other BOM/PS errors
    </ul>
*/
extern BOM_API int BOM_window_get_occ_type_filter(
    tag_t window_tag,           /**< (I) Tag of the window */
    int *count,                 /**< (O) Number of Occurrence Type Filters set on window */
    char ***typeList            /**< (OF) count The Occurrence Type Filters set on window */
    );

/** @} */

/**
     Checks number of generic components in the structure.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if the input tag is invalid
    <li>Possibly other BOM/PS errors
    </ul>
*/
extern BOM_API int BOM_line_create_vi_structures(
    tag_t line,                                 /**< (I) Tag of BOM Line */
    logical is_linked_to_generic_component,     /**< (I) True if the VI structure is to be validated against
                                                         the structure that it instantiates.
                                                         If false, the VI structure can be altered so that it is
                                                         different from that of its generic component's structure. */
    tag_t* new_item,                            /**< (O) Tag for identifying the Item in the current program */
    tag_t* new_rev                              /**< (O) Tag for identifying the Item Revision in the current program */
    );



/**
    Retrieves whether an object is modifiable in IC context or not

    @note The AM rule 'In IC context' gets applied during operations which are tracked by IC.
    This method assumes that an operation being tracked by IC is being performed and returns
    the value accordingly.
*/
extern BOM_API int BOM_ok_to_modify_obj_in_ic(
    tag_t window_tag,                           /**< (I) BOMWindow where IC context is set */
    tag_t object_tag,                           /**< (I) object tag whose access is to be checked */
    logical* modifiable                         /**< (O) output - true means object is modifiable */
    );

/**
    BOMWorld api to trigger update of all BOMWindows
    based on a changed ItemRev. This is needed after
    ITK call to create / copy itemrev was made and
    BOMWindow(s) happen to be open.
*/
extern BOM_API int BOM_world_newIrfWhereConfigured(
    tag_t rev           /**< (I) */
    );


/**
    Name:  BOM_line_find_candidates_with_fix_option

           This method will search structures for possible candidates
           to be used for repairing broken links.

    Input:
           n_broken_links - number of broken links to process
           broken_links   - broken links to process
           n_scope        - number of structures to search in
           scope          - structures to search in
           n_properties   - number of properties for search criteria
           properties     - properties for search criteria
           n_operators    - number of operators for search criteria
           operators      - operators for search criteria
           revision_rule  - revision rule for configuring scope structures
           quick_search   - logical that tells if a quick or thorough search
                            should be conducted
           auto_fix       - logical that indicates if broken links with only
                            one candidate found should be fixed automatically

    Output:
           n_candidates - number of candidates found for each broken link
           candidates   - all candidates found for all broken links

    Return:
           ITK_ok or some error number
*/
extern BOM_API int BOM_line_find_candidates_with_fix_option
(
    int        n_broken_links,    /**< (I) */
    tag_t    * broken_links,      /**< (I) n_broken_links */
    int        n_scope,           /**< (I) */
    tag_t    * scope,             /**< (I) n_scope */
    int        n_properties,      /**< (I) */
    char    ** properties,        /**< (I) n_properties */
    int        n_operators,       /**< (I) */
    char    ** operators,         /**< (I) n_operators */
    tag_t      revision_rule,     /**< (I) */
    logical    quick_search,      /**< (I) */
    logical    auto_fix,          /**< (I) */
    int     ** n_candidates,      /**< (OF) */
    tag_t   ** candidates         /**< (OF) candidates will equal the sum of n_candidates */
);


/**
    This method will create a new roll up report.

    @return #ITK_ok = successful, not #ITK_ok = failed
*/
extern BOM_API int BOM_line_create_rollup_report
(
    tag_t       bomline,            /**< (I) bomline tag to be used as the root line for the report */
    tag_t       rollup_template,    /**< (I) rollup template tag used to identify the content of the report */
    tag_t       folder,             /**< (I) */
    const char* name,               /**< (I) */
    const char* description,        /**< (I) */
    tag_t*      report_dataset      /**< (O) the dataset tag that will be versioned with revised report */
);

/**
    @name BOM Publish Functions
    @{
*/
/**
    Create PublishLink between absolute occurrences of source and targets.

    @note If a PublishLink for the source occurrence exists, an error will be thrown
    @note If any of the targets are already connected via PublishLink to a different source occurrence,
    an error will be thrown
*/
extern BOM_API int  BOM_create_publish_link(
    const char*       name,                           /**< (I) Name of PublishLink to be created */
    const char*       type,                           /**< (I) Type of PublishLink to be created */
    tag_t             source_line,                    /**< (I) source tag BOM line */
    int               target_count,                   /**< (I) no of of target tags */
    const tag_t       *target_lines,                   /**< (I) target_count */
    tag_t*            publishLink                     /**< (O) Tag of PublishLink created */
    );

/**
    Add targets to given source's PublishLink.

    @note  If a PublishLink for a source  doesnt exist, error is thrown
    @note  If a target  already has a PublishLink with another source, error is thrown
*/
extern BOM_API int  BOM_publishlink_add_targets(
    tag_t             source_line,                           /**< (I) source tag of BOM line */
    int               target_count,                          /**< (I) no of of target tags */
    const tag_t       *target_lines,                          /**< (I) target_count */
    tag_t             *publishLink                           /**< (O) Tag of PublishLink updated */
    );

/**
    Deletes targets from given source's PublishLink.

    @note  If the target being removed is the last one for PublishLink, then link is also deleted
*/
extern BOM_API int BOM_publishlink_delete_targets (
    tag_t           source_line,                         /**< (I) source tag of BOM line */
    int             target_count,                        /**< (I) no of of target tags */
    const tag_t     *target_lines,                       /**< (I) target_count */
    tag_t           *publishLink                         /**< (O) Tag of PublishLink updated */
    );

/**
    Find targets of a given source's PublishLink in given bom window.
*/
extern BOM_API int  BOM_publishlink_find_targets_in_window(
    tag_t       source_line,                            /**< (I) source tag of BOM line */
    tag_t       target_bom_window,                      /**< (I) target bom window */
    int         *targets_count,                         /**< (O) no of of target tags */
    tag_t       **target_lines                          /**< (OF) targets_count */
    );

/**
    Publish will copy data from source BOMLine to the target BOMLines based on the data flags

    @note data_flags - each bit in this denotes what data to be published
         Currently transform, shape, both transform and shape can be published.
         the flags values are: Transform (0x1), Shape (0x2).

    @note If absolute occurrence of any targetLines is found being referred as target in an existing PublishLink
            with a different source, an error is thrown.
    @note If a PublishLink exists for source line, the link is uppdated with absolute occurrences of targetLines
    @note If a PublishLink exists for source line, publishLinkName and publishLinkTypeName are optional
    @note If a PublishLink doesnt exist between absolute occurrence of source and targets it will be created.
*/
extern BOM_API int  BOM_publish_data(
    tag_t        source_line,                        /**< (I) source tag of BOM line */
    int          target_count,                       /**< (I) no of of target tags */
    const tag_t  *target_lines,                      /**< (I) target_count */
    const int    data_flags,                         /**< (I) data flags to denote publish data type */
    const char   *publishLinkName,                   /**< (I) publish link name */
    const char   *publishLinkTypeName,               /**< (I) publish link type */
    tag_t        *publishLink                        /**< (O) Tag of PublishLink */
    );

/**
    Delets Publish Link and its targets and source for given source bom line

    @note If absolute occurrence of any targetLines is found being referred as target in an existing PublishLink
          with a different source, an error is thrown.
    @note If a PublishLink exists for source line, the link is uppdated with absolute occurrences of targetLines
    @note If a PublishLink doesnt exist between absolute occurrence of source and targets it will be created.
*/

extern BOM_API int BOM_delete_publishlink_for_source(
    tag_t       source_line                      /**< (I) source tag of BOM line */
    );

/**
    @deprecated #BOM_publishlink_find_source_in_window deprecated in Teamcenter 11.2.3. Use #BOM_publishlink_find_sources_in_window instead.

    Find source BOM line for a given target's PublishLink in given bom window.
*/
TC_DEPRECATED("11.2.3","BOM_publishlink_find_source_in_window","BOM_publishlink_find_sources_in_window")
extern BOM_API int BOM_publishlink_find_source_in_window(
    tag_t       target_line,                      /**< (I) Tag of target BOM line */
    tag_t       source_bom_window,                /**< (I) Tag of source BOM Window */
    tag_t       *source_line                      /**< (O) Tags of source BOM line */
    );

/**
    Finds multiple source BOM Lines for a given target PublishLink in a BOM Window.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_publishlink_not_exist_for_target if no Publish Link exists for the target.
    <li>#BOM_invalid_tag if source_bom_window is not a valid BOM Window.
    <li>Possibly other errors
    </ul>
*/
extern BOM_API int  BOM_publishlink_find_sources_in_window(
    const tag_t target,                                 /**< (I) The target BOM Line  */
    const tag_t source_bom_window,                      /**< (I) The source BOM Window  */
    int *n_sources,                                     /**< (O) Number of found source BOM Lines */
    tag_t **sources                                     /**< (OF) n_sources The found BOM Lines */
    );

/**
    Deletes target from given source's PublishLink.

    @note  If the target being removed is the last one for PublishLink, then link is also deleted
*/
extern BOM_API int BOM_publishlink_delete_target(
    tag_t           target_line,                   /**< (I) Tag of target BOM line */
    tag_t           *publishLink                   /**< (O) Tag of PublishLink created */
    );

/**
    From the input line, assumed to be a target of a PublishLink, BOMView of source of
    PublishLink is returned
*/
extern BOM_API int  BOM_publishlink_ask_source_context_bv(
    tag_t       target_line,                      /**< (I) Tag of target BOMLine */
    tag_t       *source_bom_view                  /**< (O) Tag of source BOMView */
    );

/**
    Retrieves PublishLink where the input line is source
*/
extern BOM_API int  BOM_ask_publishlink_for_source(
    tag_t       source_line,                    /**< (I) Tag of source BOMLine */
    tag_t       *publish_link                   /**< (O) Tag of PublishLink */
    );

/**
    Retrieves PublishLink where the input line is a target
*/
extern BOM_API int  BOM_ask_publishlink_for_target(
    tag_t       target_line,                     /**< (I) Tag of target BOMLine */
    tag_t       *publish_link                    /**< (O) Tag of PublishLink */
    );

/** @} */

/**
    For the input line and its descendents completeness check is performed.

    The checks is valid for lines with underlying item of type Part. Other lines
    are skipped. For a line with underlying item's type as Part, the need for positioned
    design is verifed.

    The ITK returns the three array of lines:
    skipped - lines which were skipped and completess check not performed
    complete - lines satisfying the completeness criteria
    incomplete - lines not satisfying the completeness criteria
*/
extern BOM_API int  BOM_verify_part_structure(
    tag_t       line,                           /**< (I) */
    int*        cntCompleteLines,               /**< (O) */
    tag_t**     completeLinesTags,              /**< (OF) cntCompleteLines */
    int*        cntIncompleteLines,             /**< (O) */
    tag_t**     incompleteLinesTags,            /**< (OF) cntIncompleteLines */
    int*        cntSkippedLines,                /**< (O) */
    tag_t**     skippedLinesTags                /**< (OF) cntSkippedLines */
    );

/**
    Exports the UG assembly structure to Native NX after configuring using
    the given saved variant rule and revision rule
    This function exports packed (hidden) lines as well.
*/
extern BOM_API int BOM_export_configured_nx_assembly(
    tag_t          bomLine,                  /**< (I) bomline to export */
    const char*    namingFormat,             /**< (I) naming format */
    int            noOfValidExcludes,        /**< (I) number of excluded items */
    const tag_t*   excludedTags,             /**< (I) noOfValidExcludes An array of excluded item tag list */
    char**         zipFileTicket,            /**< (OF) Returns zipfile fms ticket */
    char**         logFileTicket             /**< (OF) Returns logfile fms ticket */
    );

/**
    Retrieves child bomline for given bomline that is the occurrence with the given clone stable uid
*/
extern BOM_API int BOM_line_get_child_bomlines_from_clone_stable_uid(
    tag_t          bom_line,             /**< (I) Parent BOM line whose children are wanted */
    int            countin,              /**< (I) Number of ids passed in */
    char**         clone_stable_uids,    /**< (I) Clone stable id */
    int*           count,                /**< (O) Number of child lines returned */
    tag_t**        children              /**< (OF) count Returned lines */
    );

/**
   Finds a preferred JT refset associated with a dataset on the given bom line. The JT_File_Priority_Refsets
   preference and optionally the JT_File_OverrideChildren_Refsets preference are used to determine which
   JT refset is preferred
*/
extern BOM_API int BOM_line_find_preferred_JT_refset(
    tag_t          bom_line,               /**< (I) Tag of BOM line to add substitute to */
    tag_t          item_revision,          /**< (I) Tag of the Item Revision to add as substitute */
    logical        ignore_overrides,       /**< (I) True if return should exclude assemblies that override children */
    tag_t*         jtfile,                 /**< (O) Tag of the selected JT file */
    char**         refset_name,            /**< (OF) Refset name of the selected JT file */
    logical*       jt_override             /**< (O) True if returned JT file is an override assembly */
    );

/**
    Removes the absocc override of a property on a bomline that was defined by a specific bomline context.
*/
extern BOM_API int BOM_line_remove_absocc_property
    (
        tag_t bomLine,                  /**<  (I) Tag of bomline that has property with absocc override. */
        char* propertyName,             /**<  (I) Char array of the property name that has absocc override. */
        tag_t contextBomLine            /**<  (I) Tag of bomline that is the context for absocc override of property, can be NULLTAG which will delete current configured property override. */
    );

/**
    Removes absocc GRM override of a bomline by using its Appearance Path Node and GRM relation type.
*/
extern BOM_API int BOM_line_remove_absocc_relation
    (
        tag_t lineTag,                 /**< (I) Tag of bomline. */
        tag_t sourceApn,               /**< (I) Tag of apn, can be NULLTAG which will try all possible apns that use GRM. */
        tag_t relation                 /**< (I) Tag of GRM. */
    );

/**
    Asks relations associated to bomline
*/
extern BOM_API int BOM_line_ask_absocc_relation
    (
        tag_t lineTag,                 /**< (I)  Tag of bomline. */
        tag_t sourceApn,               /**< (I)  Tag of apn, can be NULLTAG which will try all possible apns that use relation. */
        char *relName,                 /**< (I)  Name of the relation. */
        logical configuredOnly,        /**< (I)  Interested in configured relation only. */
        int *relCount,                 /**< (O)  Relation count. */
        tag_t **relations              /**< (OF) relCount Array of tags of bomline relations of given type. */
    );

/**
    Replaces the secoondary object of a specified Absocc GRM override relation on a bomline.
*/
extern BOM_API int BOM_line_replace_absocc_relation
    (
        tag_t lineTag,                 /**< (I) Tag of bomline. */
        tag_t sourceApn,               /**< (I) Tag of apn, can be NULLTAG which will try all possible apns that use relation. */
        tag_t relation,                /**< (I) Tag of GRM. */
        tag_t newSecondary,            /**< (I) Tag of new secondary object. */
        tag_t *newRelation             /**< (O) Tag of modified relation. */
    );

/**
    Adds a secondary object to a bomline using absocc GRM override with a specific relation type.
    Note: Before adding, the bom window needs to be in absOccEdit mode and a valid
          context has to be set too.
*/
extern BOM_API int BOM_line_add_absocc_relation
    (
        tag_t lineTag,                 /**< (I) Tag of bomline. */
        tag_t relType,                 /**< (I) Tag of GRM. */
        tag_t secObject,               /**< (I) Tag of new secondary object. */
        tag_t *newRelation             /**< (O) Tag of new relation. */
    );

/**
    Asks bom window for selected context bomline.
*/
extern BOM_API int BOM_window_ask_absocc_context
    (
        tag_t window,                 /**< (I) Tag of bom window. */
        tag_t *rootLine               /**< (O) Tag of bomline that is the selected context line, NULLTAG means no line selected. */
    );

/**
    Sets context bomline for absolute occurrence edit mode.
*/
extern BOM_API int BOM_window_set_absocc_context
    (
        tag_t window,                 /**< (I) Tag of bom window. */
        tag_t rootLine                /**< (I) Tag of higher level bom line. */
    );

/**
    Asks bom window status of absolute occurrence edit mode.
*/
extern BOM_API int BOM_window_ask_absocc_edit_mode
    (
        tag_t window,                 /**< (I) Tag of bom window. */
        logical *absOccEditMode       /**< (O) Status of absocc edit mode, on or off */
    );

/**
    Sets bom window absolute occurrence edit mode on or off.
    NOTE: Context is assumed and will be set to the topLine of the bom window.
          To change the context line use the BOM_window_set_absocc_context API.
*/
extern BOM_API int BOM_window_set_absocc_edit_mode
    (
        tag_t window,                 /**< (I) Tag of bom window. */
        logical absOccEditMode        /**< (I) Status to set absocc edit mode, on or off */
    );

/**
   Retrieves the unit occurrence effectivity of a bomline.
   If intersectWithConfigurationEff is true, the unit occurrence effectivity is intersected with the
   effectivity on the BOMWindow and the intersected effectivity will be returned.
   The ouput flag occEffExists indicates if unit occurrence effectivity is defined or not.

   The following will be the output configuration for special cases of infinite and zero effectivity :
   Infinite Effectivity Case  ( i.e No Effectivity defined ):
      *alwaysEffective = true;
      *netEffyInfoCount = 0;
   Zero Effectivity Case ( Same as Line Not Configured ):
      *alwaysEffective = false;
      *netEffyInfoCount = 0;

*/
extern BOM_API int BOM_line_ask_unit_occurrence_effectivity(
    tag_t                      bomline,                       /**< (I) Tag of BOM line whose Unit Occurrence Effectivity is being asked for */
    logical                    intersectWithConfigurationEff, /**< (I) if true the Occurrence Effectivity will be intersected with Effectivity on BOM Window Configuration */
    logical*                   occEffExists,                  /**< (O) True indicates the occurrence has effectivity defined on it */
    logical*                   isAlwaysEffective,             /**< (O) true if the occurrence is effective for any End Item/Unit. */
    int*                       effyInfoCount,                 /**< (O) Occurrence Effectivity Count */
    WSOM_effectivity_info_t***  effectivityInfo                /**< (OF) Occurrence Effectivity of the Given BOMLine */
    );

/**
Creates a new Effectivity object and applies it to an occurrence.

<b>Restrictions:</b>
<OL>
<li>Only one range type is permitted per effectivity.
<br/>Hence, it is possible to have date ranges or unit ranges, but not both.
<br/>Set date ranges first if they are provided, otherwise set unit ranges. They cannot be both NULL.
<li>Unit ranges must be qualified against an end item.
<br/>Set end item revision if it is specified, otherwise set end item.
<br/>End item and end item revision cannot be both NULL.
</OL>

@returns
<ul>
<li>#ITK_ok on success
<li>#BOM_invalid_tag if @p bom_line is invalid
<li>#CXPOM_wrong_class if @p end_item or @p end_item_rev is invalid
<li>#WSOM_units_and_no_end_item if Effectivity creation is requested with @p unit_range but no @p end_item or @p end_item_rev is provided
<li>#WSOM_closed_status_open_range if a closed-ended range is specified but no end date value is provided
<li>#WSOM_open_status_closed_range if an open-ended or stock-out range is specified but the range array is closed with an end value
<li>#WSOM_end_smaller_than_start if the end value is less than the start value
<li>Possibly some other WSOM or BOM errors
</ul>
*/
extern BOM_API int BOM_create_occurrence_effectivity(
    tag_t                    bom_line,              /**< (I) The BOMLine to which Effectivity is attached */
    const char*              eff_id,                /**< (I) The Effectivity ID. It can be NULL */
    tag_t                    end_item,              /**< (I) The Effectivity end item.
                                                    <br/>If Effectivity creation is requested with the unit range, it cannot be #NULLTAG. */
    tag_t                    end_item_rev,          /**< (I) The Effectivity end item revision. <br/>It can be #NULLTAG */
    const char*              unit_range,            /**< (I) The Effectivity unit range represented as text using the '-' separator (e.g. "100-199").
                                                    <br/>Multiple ranges can be specified using a comma separator (e.g. "100-199, 500-599"). */
    int                      n_dates,               /**< (I) The size of the array of Effectivity date */
    const date_t*            date_range,            /**< (I) n_dates The array of Effectivity date range.
                                                    <br/>For example, consider a discontinuous range consisting of
                                                    continuous ranges r1, r2, ..., rn where rx has the start and
                                                    end values rx.start and rx.end.
                                                    <br/>The array of start_end_vals for this discontinuous range will
                                                    be constructed as { r1.start, r1.end, r2.start, r2.end, ...,
                                                    rn.start, rn.end }. The last value, rn.end should be omitted if
                                                    the discontinuous range is open-ended. */
    WSOM_open_ended_status_t open_ended_status,     /**< (I) The open-ended status. */
    logical                  is_protected,          /**< (I) Set this to true to add the new range to any existing ranges.
                                                    <br/>Set this to false to overwrite existing ranges. */
    tag_t*                   effectivity_cmp        /**< (O) The created Effectivity object. */
);

/**
Associates an existing Effectivity object to an occurrence.

@returns
<ul>
<li>#ITK_ok on success
<li>#BOM_invalid_tag if @p bom_line is invalid
<li>#WSOM_invalid_eff if @p effectivity is invalid
<li>Possibly some other BOM or PS errors
</ul>
*/
extern BOM_API int BOM_apply_occurrence_effectivity(
    tag_t                    bom_line,             /**<  (I) The BOMLine to which Effectivity is attached */
    tag_t                    effectivity           /**<  (I) The existing Effectivity object that will be added to the BOM Line */
);

/**
Updates an existing effectivity object for the BOMLine.

<b>Restrictions:</b>
<OL>
<li>Only one range type is permitted per effectivity.
<br/>Hence, it is possible to have date ranges or unit ranges, but not both.
<br/>Set date ranges first if they are provided, otherwise set unit ranges. They cannot be both NULL.
<li>Unit ranges must be qualified against an end item.
<br/>Set end item revision if it is specified, otherwise set end item.
<br/>End item and end item revision cannot be both NULL.
</OL>

@returns
<ul>
<li>#ITK_ok on success
<li>#BOM_invalid_tag if @p bom_line is invalid
<li>#WSOM_invalid_eff @p eff_emp is invalid
<li>#CXPOM_wrong_class if @p end_item or @p end_item_rev is invalid
<li>#WSOM_units_and_no_end_item if Effectivity creation is requested with @p unit_range but no @p end_item or @p end_item_rev is provided
<li>#WSOM_closed_status_open_range if a closed-ended range is specified but no end date value is provided
<li>#WSOM_open_status_closed_range if an open-ended or stock-out range is specified but the range array is closed with an end value
<li>#WSOM_end_smaller_than_start if the end unit/date value is less than the start unit/date value
<li>Possibly some other WSOM or BOM errors
</ul>
*/
extern BOM_API int BOM_edit_occurrence_effectivity(
    tag_t                    bom_line,              /**< (I) The BOMLine for which effectivity is updated */
    tag_t                    eff_emp,               /**< (I) The existing effectivity object to be updated */
    const char*              eff_id,                /**< (I) The Effectivity ID. It can be NULL */
    tag_t                    end_item,              /**< (I) The Effectivity end item.
                                                    <br/>If Effectivity creation is requested with the unit range, it cannot be #NULLTAG. */
    tag_t                    end_item_rev,          /**< (I) The Effectivity end item revision. <br/>It can be #NULLTAG */
    const char*              unit_range,            /**< (I) The Effectivity unit range represented as text using the '-' separator (e.g. "100-199").
                                                    <br/>Multiple ranges can be specified using a comma separator (e.g. "100-199, 500-599"). */
    int                      n_dates,               /**< (I) The size of the array of Effectivity date */
    const date_t*            date_range,            /**< (I) n_dates The array of Effectivity date range.
                                                    <br/>For example, consider a discontinuous range consisting of
                                                    continuous ranges r1, r2, ..., rn where rx has the start and
                                                    end values rx.start and rx.end.
                                                    <br/>The array of start_end_vals for this discontinuous range will
                                                    be constructed as { r1.start, r1.end, r2.start, r2.end, ...,
                                                    rn.start, rn.end }. The last value, rn.end should be omitted if
                                                    the discontinuous range is open-ended. */
    WSOM_open_ended_status_t open_ended_status,     /**< (I) The open-ended status. */
    logical                  is_protected           /**< (I) Set this to true to add the new range to any existing ranges.
                                                    <br/>Set this to false to overwrite existing ranges. */
);

/**
   Retrieves the array of bomsets for given bomlines.
   A bomset is a chunk of bomlines. Dividing a BOM structure into fixed size bomsets can
   help in processing them such as expansion. BomSet creation can be based on given criteria such as
   available system memory, maximum size or maximum size as percentage of total structure size.
   A bomset, by default, contains number of bomlines those can be expanded within available system
   memory at the point of creation.
*/
extern BOM_API int BOM_create_bomsetlines_for_input_lines(
    BOM_bomset_create_criteria_t bomset_create_criteria, /**< (I) Structure having BOMSet creation criteria */
    tag_t* input_lines,                                 /**< (I) Tag array of structure top lines for which bomsets to be created */
    int input_lines_count,                              /**< (I) Integer size of Tag array of input lines */
    int* bomset_count,                                  /**< (OF) Number of bomsets created */
    BOM_bomset_input_info_t** bomset_input_info         /**< (OF) bomset_count Structure array of bomsets */
    );

/**
   This API expands a bomset.
   Retrieves a structure having expanded bomlines array for input bomset and its size.
   A bomset is a chunk of bomlines. Dividing a BOM structure into fixed size bomsets can
   help in processing them such as expansion.
   A bomset, by default, contains number of bomlines those can be expanded within available system
   memory at the point of creation.
*/
extern BOM_API int BOM_expand_bomset_lines(
    BOM_bomset_input_info_t bomset_input_info,     /**< (I) Structure of a bomset */
    BOM_bomset_output_info_t* bomset_output_info /**< (OF) Structure array of expanded bomlines for input bomset */
    );



/**
   Retrieves the list of option names on the item corresponding to the bom line.
   @returns int teamcenter error code, ITK_ok on success.
*/
    extern BOM_API int BOM_item_module_list_options (
        tag_t window,                 /**< (I) Tag of BOM Window */
        tag_t item,                   /**< (I) Tag of Item from which options should be search */
        int *count,                   /**< (O) Count of option found */
        int **options                 /**< (OF) count Option Handles found */
        );

/**
   Retrieves the Option id for the given item and Option name
   @returns int teamcenter error code, ITK_ok on success.
*/
    extern BOM_API int BOM_item_ask_option_handle(
        tag_t          window,         /**< (I) Tag of BOM Window */
        const tag_t    item,           /**< (I) Tag of Item from which options should be search */
        const char*    name,           /**< (I) Option name to find */
        int*           option          /**< (O) Option Handle */
        );

/**
   Retrieves the details for an Option defined on item.
   @returns int teamcenter error code, ITK_ok on success.
*/
    extern BOM_API int BOM_option_describe2(
        int            option,               /**< (I) Option handle */
        tag_t*         item,                 /**< (O) Tag of Item where option is defined */
        char**         option_name,          /**< (OF) Option Name */
        char**         desc,                 /**< (OF) Option Description */
        int*           visibility,           /**< (O) Option scope (Public, Private) */
        int*           option_type,          /**< (O) Option Type */
        int*           value_type,           /**< (O) Option Value type (String, Logical, Integer, Real) */
        int*           based_on,             /**< (O) Option Handle if option is presented or external */
        logical*       has_default           /**< (O) If Option has default value defined */
        );

/**
   For the given Item returns the item revision on which Option is declared
   @returns int teamcenter error code, ITK_ok on success.
*/
    extern BOM_API int BOM_option_where_declared2(
        const tag_t    item,                 /**< (I) Tag of Item */
        const char*    option,               /**< (I) Option Name to find */
        int*           count,                /**< (O) Count of matches */
        tag_t**        item_revs             /**< (OF) count Tags of found Item Revisions */
        );

/**
   For the given Item returns the item revision on which Option is Used
   @returns int teamcenter error code, ITK_ok on success.
*/
    extern BOM_API int BOM_option_where_used2(
        const tag_t    item,                 /**< (I) Tag of Item */
        const char*    option,               /**< (I) Option Name to find */
        int*           count,                /**< (O) Count of matches */
        tag_t**        objs                  /**< (OF) count Tags of found objects */
        );

/**
   Performs occurrence validation on bom lines and optionally on all occurrences below the lines as well.
   Note: When doing recursive validation, children will be loaded if not yet.
*/
    extern BOM_API int BOM_line_occ_validate(
        int            count,              /**< (I) The number of lines to be validated */
        tag_t*         lines,              /**< (I) count The input lines to perform occurrence validation */
        logical        recurse,            /**< (I) Do the validation recursively */
        int*           err_count,          /**< (O) The number of errors */
        int**          ifails,             /**< (OF) err_count The errors */
        tag_t**        err_lines           /**< (OF) err_count The lines that failed the validation */
        );

/**
   Retrieves the clone stable occurrence id chain for the given bom line.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>Possibly other errors
   </ul>
*/
    extern BOM_API int BOM_line_get_clone_stable_id_chain(
        tag_t        bomline,                /**< (I) Tag of the BOM line */
        const char * root_str,               /**< (I) The string to be appended at the front and can be one of the following:
                                                <ul>
                                                <li>bl_clone_stable_occurrence_id:\<StructureContextUID\>     or
                                                <li>bl_clone_stable_occurrence_id:\<CollaborationContextUID\> or
                                                <li>bl_clone_stable_occurrence_id:\<BOMViewUID\>              or
                                                <li>bl_clone_stable_occurrence_id:\<BOMViewRevisionUID\>      or
                                                <li>bl_clone_stable_occurrence_id if an external means of setting up the window is in place while evaluation (getting bomline from chain)
                                                </ul>
                                             */
        char **      cli_chain               /**< (OF) Chain of Clone Stable IDs */
        );

/**
   Retrieves the BOM line from clone stable occurrence id chain.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#BOM_invalid_tag if any clone stable Id in the chain does not resolve to a BOM line.
   <li>Possibly other errors
   </ul>
*/
    extern BOM_API int BOM_window_get_line_from_clone_stable_id_chain(
        tag_t        window,                /**< (I) Tag of BOM Window */
        const char * cs_chain,              /**< (I) The Clone Stable Id chain in the format csid1/csid2/... */
        tag_t *      line                   /**< (O) The Tag of line found */
        );

/**
   Suppresses or unsuppresses lines by using the flags.

   @note
    <ol>
    <li>This is a set based action to suppress lines. It provides dedicated handling in compare with calling generic set property functions.
    <li>Unsaved deferred save data will be saved. It is desired to save the BOM window before calling this ITK.
    <li>If any line failed to suppress/unsuppress, it will record the error and continue processing.
    <li>The function returns the value for the first encountered error, if any. It returns #ITK_ok otherwise.
    </ol>
    @returns
    <ul>
    <li>#ITK_ok on complete success
    <li>#BOM_cant_edit_root_line_occ if the line has no occurrence.
    <li>#BOM_suppression_constrained if the line is constrained and could not be suppressed or unsuppressed
    <li>Possibly other errors
    </ul>
*/
    extern BOM_API int BOM_line_suppress_lines(
        int            count,              /**< (I) Number of input lines. */
        const tag_t*   lines,              /**< (I) count The input lines to suppress/unsuppress */
        const logical* suppression_flags,  /**< (I) count The suppress/unsuppress flag for each of the lines */
        int*           err_count,          /**< (O) The number of errors */
        int**          ifails,             /**< (OF) err_count The errors */
        tag_t**        err_lines           /**< (OF) err_count The lines that failed the suppression/unsuppression */
        );

/**
   Retrieves the saved Variant Rules (SVRs) or Stored Option Set (SOS) attached to an Item Revision with the specified Relation type or by Variant Rule name.
   <br/>Depending on the value of the preference "PSEVariantsMode" and "PSM_Enable_product_configurator", different objects are retrieved:
   <br/>For preference "PSEVariantsMode":
   <ul>
   <li>"legacy": only SVRs.
   <li>"modular": only SOSs.
   <li>"hybrid": both SVR and SOS.
   </ul>
   <br/>For preference "PSM_Enable_product_configurator":
   <ul>
   <li>"true": Product Configurator Authored Variant Rules.
   <li>"false": the objects as defined by the preference "PSEVariantsMode".
   </ul>

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#BOM_invalid_input if @p item_revision is NULLTAG and @p relation_type is not a NULLTAG.
   <li>#GRM_invalid_relation_type if @p relation_type is an invalid tag.
   <li>#BOM_no_configured_ir if @p item_revision is an invalid tag.
   <li>Possibly other errors
   </ul>
*/
   extern BOM_API int BOM_find_variant_rule_and_or_sos(
       tag_t                       item_revision,                  /**< (I) Item Revison tag (optional). If #NULLTAG, the search of SVR/SOS will be made using the Rule name only */
       const char*                 rule_name,                      /**< (I) Saved Variant Rule name (optional). If null or empty, the SVRs/SOSs are searched using the Item Revision only */
       tag_t                       relation_type,                  /**< (I) The Relation type to search for (optional). If #NULLTAG, all relation types are taken into consideration */
       logical                     consider_PSEVariantsMode_pref,  /**< (I) Consider the preference "PSEVariantsMode" condition flag */
       int *                       n_objects_found,                /**< (O)  Number of objects found */
       tag_t **                    objects                         /**< (OF) n_objects_found Array of found SVRs/SOSs */
       );

/**
   Sets the given variant rules to be the current rules for the given BOM window and applies the configuration on BOM window.
   <br/>It will override any existing configuration.
   <br/>If no variant rule is passed, the default configuration will be applied on the window.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#BOM_invalid_tag if @p window is invalid.
   <li>#BOM_variant_invalid_bom_vrule if any member of @p svr is #NULLTAG or not a valid Saved Variant Rule.
   <li>#SMC0PSMCFGSUPPORT_invalid_variant_rule_error if the preference "PSM_Enable_product_configurator" is set to "true" and any Variant rule in @p svr is not a Product-Configurator-authored Variant Rule.
   <li>#BOM_cannot_apply_product_configurator_authored_vrule if the preference "PSM_Enable_product_configurator" is set to "false" and any Variant Rule in @p svr is not a Legacy Saved Variant Rule.
   </ul>
*/
    extern BOM_API int BOM_window_apply_variant_configuration(
        tag_t            window,        /**< (I) The BOM Window */
        int                n_svr,         /**< (I) The number of Saved Variant Rules to apply to the BOM Window. */
        const tag_t*    svr            /**< (I) n_svr The Saved Variant Rules to apply to the BOM Window. */
        );

/**
   Creates and saves the new interchangeable groups, Occurrence level substitute groups or Item Revision level (global) substitute alternate groups based on the input object type.
   Interchangeable Groups are groups of stockable parts that needs to be all replaced together as repairs are made. They can be defined at two levels:
   <ul>
    <li>Occurrence Level: List of occurrences that must be replaced together with a list of items within the same BVR.
    <li>Item/Item Revision (Global) Level: List of items/revisions that must be replaced together with another list of items, regardless of the assembly where they are used.
   </ul>

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_wrong_class if class of @p bo_name is not of Fnd0AbsInterchangeableGrp type
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_create_interchangeable_groups(
    const char*   bo_name,       /**< (I) The Business Object type name of the interchangeable group to create. */
    int           n_props,       /**< (I) Number of properties. */
    const char**  prop_names,    /**< (I) n_props Property names */
    const char**  prop_values,   /**< (I) n_props Property values */
    int           n_src_objs,    /**< (I) Number of source objects. */
    const tag_t*  src_objs,      /**< (I) n_src_objs The list of source objects. BOM Line objects when creating substitute groups or Item/Item Revisions when creating alternate groups */
    int           n_tgt_objs,    /**< (I) Number of interchangeable objects. */
    const tag_t*  tgt_objs,      /**< (I) n_tgt_objs Item/Item revision objects as interchangeable group */
    tag_t*        created_obj    /**< (O) The created interchangeable group object */
    );

/**
   Creates and saves the Occurrence Effectivity Expression on given BOM Line.
   <br/>If the BOM Window is In-context, the API will override Effectivity Expression on the BOM Line. Otherwise, it will set the relative effectivity expression on BOM Line.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_has_object_based_eff_cant_have_expr_based_eff if the occurrence has object-based effectivity.
    <li>#BOM_invalid_configurable_object if the occurrence is not available.
    <li>#BOM_cannot_perform_effectivity_operation if the occurrence is locked.
    <li>#BOM_invalid_tag for invalid BOM Line
    <li>Possibly other BOM errors
    </ul>
*/
extern BOM_API int BOM_set_line_occ_eff_formula(
    const tag_t bom_line,          /**< (I) The BOM Line. */
    const char * formula           /**< (I) Effectivity Expression Formula to set on the BOM Line. */
);

/**
   Retrieves the Effectivity Expressions on given BOM Lines.
   <br/>If a BOM Line overrides the Effectivity Expression, this will have precedence over any relative Effectivity Expression.
   <br/>This API supports partial errors,i.e. if an error occurs during the operation on any input BOM Line, that will be added to @p occ_effectivity_info and other inputs will be processed.

   @returns #ITK_ok always
*/
extern BOM_API int BOM_get_line_occ_eff_info(
    const int n_bomlines,                                /**< (I) Number of BOM Lines. */
    const tag_t* bomlines,                               /**< (I) n_bomlines BOM Lines to consider. */
    BOM_occ_effectivity_info_t**  occ_effectivity_info   /**< (OF) n_bomlines The Effectivity formula from the BOM Lines.
                                                         <br/>Note that it can also contain a processing error code for the corresponding input BOM Line.
                                                         <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
);

/**
    Aligns part occurrences with their corresponding design occurrences as specified by @p alignment_data.
    <br/>Global Part-CAD alignment between Parts and Designs will also be created.
    <br/>The API will first try to create alignments in bulk, and if this fails it will iterate through each input to create alignment.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_entcba_invalid_input_error if input from @p alignment_data is invalid.
    </ul>
*/
extern BOM_API int BOM_align_occurrences(
    const int                                          n_alignment_data,         /**< (I) Number of alignment objects to create. */
    const BOM_part_design_occurrence_alignment_data_t* alignment_data,           /**< (I) n_alignment_data The alignment data used to create the occurrence alignment objects. */
    tag_t**                                            occurrence_alignments,    /**< (OF) n_alignment_data The created occurrence alignment objects. */
    int**                                              error_codes,              /**< (OF) n_alignment_data Error code for the creation of each object. The content for a successful creation will be #ITK_ok. */
    char***                                            error_messages            /**< (OF) n_alignment_data Error message in case of error. This array is packed, which means that #MEM_free needs to be called on the container only to free all the memory. */
);

/**
    Deletes alignment between part occurrences corresponding design occurrences as specified by @p alignment_data.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_entcba_invalid_input_error if input from @p alignment_data is invalid.
    <li>#PS_entcba_alignment_not_found_error if alignment not found
    </ul>
*/
extern BOM_API int BOM_unalign_occurrences(
    const int                                          n_alignment_data,         /**< (I) Number of alignment objects to delete. */
    const BOM_part_design_occurrence_alignment_data_t* alignment_data,           /**< (I) n_alignment_data The alignment data used to delete the occurrence alignment objects. */
    int**                                              error_codes,              /**< (OF) n_alignment_data Error code for the deletion of each object. The content for a successful deletion will be #ITK_ok. */
    char***                                            error_messages            /**< (OF) n_alignment_data Error message in case of error. This array is packed, which means that #MEM_free needs to be called on the container only to free all the memory. */
);

/**
    Retrieves the aligned design line for part line.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if @p bom_line is invalid or #NULLTAG.
    </ul>
*/
extern BOM_API int BOM_line_get_aligned_design_line(
    tag_t  bom_line,            /**< (I) The BOM Line */
    tag_t* aligned_design_line  /**< (O) The aligned Design Line. It can be #NULLTAG if no Design Line is aligned to Part Line. */
);


/** @} */
/*================================================================================================*/


#ifdef __cplusplus
}
#endif
#include <bom/libbom_undef.h>
#endif


