/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Interface definition for the CFM module
*/

/*  */

#ifndef CFM_H
#define CFM_H

#include <unidefs.h>

#include <cfm/cfm_errors.h>
#include <cfm/cfm_tokens.h>
#include <common/tc_deprecation_macros.h>
#include <cfm/libcfm_exports.h>

/**
    @defgroup CFM Configuration Management (CFM)

    The Configuration Management (CFM) module provides the ability to configure Items and
    the definition of the rules that drive that configuration.

    The CFM module works with the following classes of object:
    <ul>
    <li>Revision Rule
    <li>Revision Rule Entry
    </ul>

    <b>Common Return Values</b>

    #CFM_invalid_tag - The rule and/or preset_rule tags are invalid. <br>
    #CFM_value_not_found - No rule of that name could be found.

    @{
*/

/**
    @name Entry Types for Revision Rules
    @{
*/

/** @if DOX_IGNORE
    Obviously these should be an enum, but this is process_pif we're talking about...
    If you extend this list then please extend CFMRuleEntry::entryTypeAsString too
@endif */

#define CFM_entry_working           0
#define CFM_entry_status            1
#define CFM_entry_override          2
#define CFM_entry_date              3
#define CFM_entry_unit_no           4
#define CFM_entry_group             5
#define CFM_entry_precise           6
#define CFM_entry_latest            7
#define CFM_entry_end_item          8
#define CFM_entry_group_item_type   9
#define CFM_entry_branch            10
#define CFM_entry_nested_eff        11
#define CFM_entry_group_occ_type    12
/** @} */

/**
    @name Config Types for Status Entries
    @{
*/
#define CFM_status_released_date    0
#define CFM_status_effective_date   1
#define CFM_status_unit_no          2
/** @} */

/**
    @name Config Types for Latest Entries
    @{
*/
#define CFM_latest_creation_date    0
#define CFM_latest_alphanumeric     1
#define CFM_latest_numeric          2
#define CFM_latest_alpha_plus_no    3
/** @} */

#ifdef __cplusplus
extern "C"
{
#endif

/** @if DOX_IGNORE
    don't fiddle with anything below this lot -- it is processed by a program that
    builds the procedural interface code by parsing the definitions.
    To be precise the program ignores everything down to a line that
    starts (COMMENT) END OF HEADER (COMMENT) so you can safely add typedefs
    and hash defines to the top of this file
@endif */
/* END OF HEADER */

/**
    @name CFM Rule

    <b>Common Return Values:</b>

    <table>
    <tr><td>#CFM_invalid_entry_type      </td><td>The type given is not one of the valid entry types.</td></tr>
    <tr><td>#CFM_entry_not_in_rule       </td><td>The given entry is not contained in the given rule.</td></tr>
    <tr><td>#CFM_cant_move_entry_in_group</td><td>An entry that is in a group cannot be moved.</td></tr>
    <tr><td>#CFM_entry_already_in_group  </td><td>One or more of the entries is already in a group.</td></tr>
    <tr><td>#CFM_entry_is_not_groupable  </td><td>Only working and status entries may be grouped.</td></tr>
    </table>
    @{
*/

/**
    Creates a revision rule with given name and description.
    Use the WSOM functions if you need to change the name and/or description in the future.

    <b>Restrictions:</b>

    The rule name should be unique, otherwise the rule can not be saved.
*/
extern CFM_API int CFM_rule_create(
    const char*    rule_name,       /**< (I) Name for the new rule */
    const char*    description,     /**< (I) Description for the new rule */
    tag_t*         new_rule         /**< (O) Tag of the newly created rule */
    );

/**
    Copies the given revision rule and all its rule entries into a new revision rule with given name.

    <b>Restrictions:</b>

    The new rule name should be unique, otherwise the rule can not be saved.
*/
extern CFM_API int CFM_rule_copy(
    tag_t          rule_to_copy,    /**< (I) Tag of the rule to copy */
    const char*    new_name,        /**< (I) Name for the new copy */
    tag_t*         new_rule         /**< (O) Tag of the newly created copy */
    );

/**
    Forces a re-evaluation of a rule contents.
    This will pick up any changes in the contents of override folders.

    @note This function is automatically invoked whenever #BOM_set_window_config_rule is called,
    e.g. on setting revision rule in PSE.
*/
extern CFM_API int CFM_rule_reevaluate(
    tag_t          rule             /**< (I) Tag of the rule to reevaluate */
    );

/**
    Creates a new entry of given type and adds it to the end of the list of entries in the rule.

    Valid entry types are as follows:

    <table>
    <tr><td>Token</td>              <td>Entry Type</td>       <td>Default Settings</td></tr>
    <tr><td>#CFM_entry_working</td> <td>Working entry</td>    <td>No user or group specified</td></tr>
    <tr><td>#CFM_entry_status</td>  <td>Status entry</td>     <td>ANY status and type</td></tr>
    <tr><td>#CFM_entry_latest</td>  <td>Latest entry</td>     <td>Type #CFM_latest_creation_date</td></tr>
    <tr><td>#CFM_entry_override</td><td>Override entry</td>   <td>No override folder specified</td></tr>
    <tr><td>#CFM_entry_date</td>    <td>Date entry</td>       <td>"Today"</td></tr>
    <tr><td>#CFM_entry_unit_no</td> <td>Unit Number entry</td><td>Unit number 0</td></tr>
    <tr><td>#CFM_entry_end_item</td><td>End Item entry</td>   <td>No end item</td></tr>
    <tr><td>#CFM_entry_precise</td> <td>Precise entry</td>    <td>N/A</td></tr>
    <tr><td>#CFM_entry_branch</td>  <td>Branch entry</td>     <td>No branch definition specified</td></tr>
    </table>

    <b>Restrictions:</b>

    A rule may only contain at most one of each of the last three entry types listed above.
    An attempt to add a second will result in an error.

    <b>Return Values:</b>

    #CFM_duplicate_date_entry - Only one date entry is allowed per rule. <br>
    #CFM_duplicate_unitno_entry - Only one unit number entry is allowed per rule.
*/
extern CFM_API int CFM_rule_add_entry(
    tag_t          rule,            /**< (I) Tag of the rule */
    int            type,            /**< (I) Type of entry to add to rule */
    tag_t*         entry            /**< (O) Tag of the newly created entry */
    );

/**
    Removes the given entry from the given rule, and deletes the entry.
*/
extern CFM_API int CFM_rule_delete_entry(
    tag_t          rule,            /**< (I) Tag of the rule */
    tag_t          entry            /**< (I) Tag of the entry to delete from the rule */
    );

/**
    Removes the given old entry from the rule and puts the new entry
    in its former position in the list of entries of rule.
    The old entry is deleted.
*/
extern CFM_API int CFM_rule_replace_entry(
    tag_t          rule,            /**< (I) Tag of the rule */
    tag_t          old_entry,       /**< (I) Tag of the entry to be replaced */
    int            type,            /**< (I) Type of replacement entry */
    tag_t*         new_entry        /**< (O) Tag of the replacement entry */
    );

/**
    Provides the ordered list of entries in the given rule.
*/
extern CFM_API int CFM_rule_list_entries(
    tag_t          rule,            /**< (I) Tag of the rule */
    int*           n_entries,       /**< (O) Number of entries in the rule */
    tag_t**        entries,         /**< (OF) n_entries Ordered list of entries */
    int**          entry_types      /**< (OF) n_entries Ordered list of entry types */
    );

/**
    Moves the given entry up one place in the list of entries of rule.
    This has no effect if the entry is already at the head of the list.
*/
extern CFM_API int CFM_rule_move_entry_up(
    tag_t          rule,            /**< (I) Tag of the rule */
    tag_t          entry            /**< (I) Tag of the entry to move */
    );

/**
    Move an entry down within a rule - does nothing if at bottom already
    Moves the given entry down one place in the list of entries of rule.
    This has no effect if the
*/
extern CFM_API int CFM_rule_move_entry_down(
    tag_t          rule,            /**< (I) Tag of the rule */
    tag_t          entry            /**< (I) Tag of the entry to move */
    );

/**
    Groups together all the given entries (which must be in the rule) into a group entry.
    The group entry is placed into the rule at the former position of the first in the given list of entries.

    <b>Restrictions:</b>

    Only working and status entries may be grouped. All the entries in a group must be of the same
    type, i.e. all working or all status. For status entries, all must use the same criteria to
    decide 'latest' (release date, effective date, or effective unit number). For example, it is not
    possible to decide between a release date and a unit number which one is latest.

    <b>Return Values:</b>

    #CFM_entry_is_not_groupable - Only working and status entries may be grouped.<br>
    #CFM_entry_incompatible_w_group - All entries in the group must be the same type and use the same criterion for latest.
*/
extern CFM_API int CFM_rule_group_entries(
    tag_t          rule,            /**< (I) Tag of the rule */
    int            n_entries,       /**< (I) Number of entries to group */
    tag_t*         entries,         /**< (I) n_entries Tags of entries to group */
    tag_t*         group_entry      /**< (O) Tag of newly created group entry */
    );

/**
Groups together all the given entries (which must be in the rule) into a group item type entry.
The group entry is placed into the rule at the former position of the first in the given list of entries.
*/
extern CFM_API int CFM_rule_group_entries_by_itemtype(
    tag_t         rule,            /**< (I) Tag of the rule */
    int           n_entries,       /**< (I) Number of entries to group */
    tag_t*       entries,          /**< (I) n_entries Tags of entries to group */
    int n_itemtypes,               /**< (I) Number of entries itemm types */
    char**       item_types,       /**< (I) item_types char array */
    tag_t*       group_entry       /**< (O) Tag of newly created group entry */
    );

/**
    Groups together all the given entries (which must be in the revision rule) into a group occurrence type entry.
    Group entry is placed into the revision rule at the former position of the first in the given list of entries.

    @note If the entries contains something invalid or NULLTAG, further operation will be stopped.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_invalid_value if any value @p n_entries and n_occurrence_types is equal to zero
    <li>#CFM_invalid_revision_rule if value @p rule is not valid RevisionRule
    <li>#CFM_invalid_occurrence_type if any value in @p occurrence_types is invalid occurrence type.
    <li>#CFM_invalid_entry_type if any value in @p entries is invalid entry type.
    <li>Possibly some other cfm errors
    </ul>
*/
extern CFM_API int CFM_rule_group_entries_by_occurrence_type(
    const tag_t     rule,                /**< (I) The Revision Rule. */
    int             n_entries,           /**< (I) Number of entries to group. */
    const tag_t*    entries,             /**< (I) n_entries Entries to group. */
    int             n_occurrence_types,  /**< (I) Number of Occurrence Types. */
    const char**    occurrence_types,    /**< (I) n_occurrence_types The Occurrence types. */
    tag_t*          group_entry          /**< (O) The newly created group entry. */
    );

/** @} */

/**
    @name CFM Entry
    @{
*/

/**
    Finds the type of the given entry.

    Possible entry types are as follows:

    <table>
    <tr><td>#CFM_entry_working </td><td>Working entry    </td></tr>
    <tr><td>#CFM_entry_status  </td><td>Status entry     </td></tr>
    <tr><td>#CFM_entry_override</td><td>Override entry   </td></tr>
    <tr><td>#CFM_entry_date    </td><td>Date entry       </td></tr>
    <tr><td>#CFM_entry_unit_no </td><td>Unit number entry</td></tr>
    <tr><td>#CFM_entry_precise </td><td>Precise entry    </td></tr>
    </table>
*/
extern CFM_API int CFM_entry_ask_type(
    tag_t          entry,            /**< (I) Tag of the entry */
    int*           type              /**< (O) Type of the entry */
    );

/**
    Finds the user associated with the given working entry.
    There may be no user, in which case the current_user flag is false and the user tag is #NULLTAG.

    If the current_user flag is true, then the user tag should be ignored (it will be #NULLTAG anyway).
*/
extern CFM_API int CFM_working_entry_ask_user(
    tag_t          entry,             /**< (I) Tag of the working entry */
    logical*       current_user,      /**< (O) Set true if the user evaluates to the logged in user */
    tag_t*         user               /**< (O) Tag of the user */
    );

/**
    Sets the user associated with the given working entry.
    If you want not to have a user associated with the entry,
    then set the current_user flag to false, and the user tag to #NULLTAG.

    If the current_user flag is set to true, then the user tag will be ignored.
*/
extern CFM_API int CFM_working_entry_set_user(
    tag_t          entry,              /**< (I) Tag of the working entry */
    logical        current_user,       /**< (I) Set true to evaluate to the logged in user */
    tag_t          user                /**< (I) Tag of the user */
    );

/**
    Finds the group associated with the given working entry.
    There may be no group, in which case the current_group flag is false and the group tag is #NULLTAG.

    If the current_group flag is true, then the group tag should be ignored (it will be #NULLTAG anyway).
*/
extern CFM_API int CFM_working_entry_ask_group(
    tag_t          entry,             /**< (I) Tag of the working entry */
    logical*       current_group,     /**< (O) Set true if the group evaluates to the logged in group */
    tag_t*         user               /**< (O) Tag of the user */
    );

/**
    Sets the group associated with the given working entry.
    If you want not to have a group associated with the entry,
    then set the current_group flag to false, and the group tag to #NULLTAG.

    If the current_group flag is set to true, then the group tag will be ignored.
*/
extern CFM_API int CFM_working_entry_set_group(
    tag_t          entry,              /**< (I) Tag of the working entry */
    logical        current_group,      /**< (I) Set true to evaluate to the logged in group */
    tag_t          user                /**< (I) Tag of the group */
    );

/**
    Finds the tag of the status type for the given status entry.
    If the returned tag is #NULLTAG, this indicates "Any Release Status."
*/
extern CFM_API int CFM_status_entry_ask_status(
    tag_t          entry,              /**< (I) Tag of the status entry */
    tag_t*         status_type         /**< (O) Tag of the status type */
    );

/**
    Sets the status type for the given status entry.
*/
extern CFM_API int CFM_status_entry_set_status(
    tag_t          entry,              /**< (I) Tag of the status entry */
    tag_t          status_type         /**< (I) Tag of the status type. Set to #NULLTAG to specify ANY status type. */
    );

/**
    Finds the type of the given status entry. Possible types of status entry are:

    <table>
    <tr><td>#CFM_status_released_date</td>   <td>Configure using the date the status was added</td></tr>
    <tr><td>#CFM_status_effective_date</td>  <td>Configure using the date effectivity on the status</td></tr>
    <tr><td>#CFM_status_unit_no</td>         <td>Configure using the unit no effectivity on the status</td></tr>
    </table>
*/
extern CFM_API int CFM_status_entry_ask_type(
    tag_t          entry,   /**< (I) Tag of the status entry */
    int*           type     /**< (O) Type of status entry */
    );

/**
    Sets the type of the given status entry. Possible types of status entry are:

    <table>
    <tr><td>#CFM_status_released_date</td> <td>Configure using the date the status was added</td></tr>
    <tr><td>#CFM_status_effective_date</td><td>Configure using the date effectivity on the status</td></tr>
    <tr><td>#CFM_status_unit_no</td>       <td>Configure using the unit no effectivity on the status</td></tr>
    </table>

    <b>Restrictions:</b>

    Only #CFM_status_released_date may be used in conjunction with "Any Release Status."

    <b>Return Values:</b>

    #CFM_invalid_status_entry_type - The type given is not one of the valid configuration types. <br>
    #CFM_invalid_status_date_combo - Only Released Date configuration may be used with Status = Any.
*/
extern CFM_API int CFM_status_entry_set_type(
    tag_t          entry,   /**< (I) Tag of the status entry */
    int            type     /**< (I) Type of status entry */
    );

/**
    Finds the tag of the override folder for the given override entry.
    If the returned tag is #NULLTAG, this indicates a "place-holding" override folder,
    which can be used in Teamcenter Engineering UIF to allow
    non-privileged users to set an override folder for a Revision Rule.
*/
extern CFM_API int CFM_override_entry_ask_folder(
    tag_t          entry,   /**< (I) Tag of the override entry */
    tag_t*         folder   /**< (O) Tag of the override folder */
    );

/**
    Sets the override folder for the given override entry.

    Set the override folder to be #NULLTAG to indicate a "place-holding" override folder,
    which can be used in Teamcenter Engineering UIF to allow non-privileged users to
    set an override folder for a Revision Rule.
    (Whilst empty, this override entry will have no effect on configuration.)
*/
extern CFM_API int CFM_override_entry_set_folder(
    tag_t          entry,   /**< (I) Tag of the override entry */
    tag_t          folder   /**< (I) Tag of the override folder */
    );

/**
    Finds the tag of the branch for the given branch entry.

    If the returned tag is #NULLTAG, this indicates a "place-holding" branch,
    which can be used in Teamcenter Engineering UIF to allow
    non-privileged users to set a branch for a Revision Rule.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_wrong_class if the input tag is invalid
    </ul>

*/
extern CFM_API int CFM_branch_entry_ask_branch(
    tag_t          entry,   /**< (I) Tag of the branch entry */
    tag_t*         branch   /**< (O) Tag of the branch */
    );

/**
    Sets the branch for the given branch entry.

    Set the branch to be #NULLTAG to indicate a "place-holding" branch,
    which can be used in Teamcenter Engineering UIF to allow non-privileged users to
    set a branch for a Revision Rule.

    (Whilst empty, this branch entry will have no effect on configuration.)

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_wrong_class if any of the input tag is invalid
    </ul>
*/
extern CFM_API int CFM_branch_entry_set_branch(
    tag_t          entry,   /**< (I) Tag of the branch entry */
    tag_t          branch   /**< (I) Tag of the branch */
    );

/** @} */

/**
    Gives the date entry of the specified Revision Rule.
*/
extern CFM_API int CFM_rule_ask_date(
    tag_t          rule,    /**< (I) Revision Rule */
    date_t*        date     /**< (O) Date entry of the Revision Rule */
    );
/**
    Sets the date entry into the Revision Rule. If a date entry already exists
    with the revision rule it will be updated.
*/
extern CFM_API int CFM_rule_set_date(
    tag_t          rule,    /**< (I) Revision Rule to be modified */
    date_t         date     /**< (I) Date entry to be set on the Revision Rule */
    );

/**
    Asks the configuration type of a latest entry, which specifies how 'latest' is decided.
*/
extern CFM_API int CFM_latest_entry_ask_type(
    tag_t          entry,   /**< (I) Tag of the 'latest' entry */
    int*           type     /**< (O) Defines the way in which 'latest' is decided:
                                    #CFM_latest_creation_date, #CFM_latest_alphanumeric,
                                    #CFM_latest_alpha_plus_no or #CFM_latest_numeric */
    );

/**
    Sets the configuration type of a latest entry, which specifies how 'latest' is decided.
*/
extern CFM_API int CFM_latest_entry_set_type(
    tag_t          entry,   /**< (I) Tag of the 'latest' entry */
    int            type     /**< (I) Defines the way in which 'latest' is decided:
                                    #CFM_latest_creation_date, #CFM_latest_alphanumeric,
                                    #CFM_latest_alpha_plus_no or #CFM_latest_numeric */
    );

/**
    Provides the list of entries in the given group entry.
*/
extern CFM_API int CFM_group_entry_list_entries(
    tag_t          group_entry, /**< (I) Tag of the group entry */
    int*           n_entries,   /**< (O) Number of entries in the group */
    tag_t**        entries      /**< (OF) n_entries Ordered list of entries */
    );

/**
    Provides the list of item types in the given group item type entry.
*/
extern CFM_API int  CFM_group_itemtype_entry_ask_itemtypes(
    tag_t entry,                  /**< (I) Tag of the group IT entry */
    int*  n_itemtypes,            /**< (O) Number of item types */
    char***  itemtypes            /**< (OF) n_itemtypes List of item types */
    );

/**
    Sets the item types of a groupp item type entry.
*/
extern CFM_API int  CFM_group_itemtype_entry_set_itemtypes(
    tag_t entry,                 /**< (I) Tag of the group IT entry */
    int n_itemtypes,             /**< (I) Number of item types */
    char** itemtypes             /**< (I) n_itemtypes List of item types */
    );

/**
    Provides the list of occurrence types in a group occurrence type entry.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_invalid_value if input @p group_occurrence_type is NULLTAG
    <li>CFM_invalid_group_occurrence_entry if value @p group_occurrence_type is not valid group occurrence type
    <li>Possibly some other cfm errors
    </ul>
*/
extern CFM_API int  CFM_find_occurrence_types_in_group(
    const tag_t group_occurrence_type,    /**< (I) The Group Occurrence Type. */
    int*  n_occurrence_types,             /**< (O) Number of Occurrence Types. */
    char***  occurrence_types             /**< (OF) n_occurrence_types The Occurrence Types. */
    );
/**
    Sets the occurrence types on a group occurrence type entry.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_invalid_value if input @p group_occurrence_type is NULLTAG
    <li>CFM_invalid_group_occurrence_entry if value @p group_occurrence_type is not valid group occurrence type
    <li>#CFM_invalid_occurrence_type if any value in @p occurrence_types is invalid occurrence type.
    <li>Possibly some other cfm errors
    </ul>
*/
extern CFM_API int  CFM_set_occurrence_types_in_group(
    const tag_t group_occurrence_type,       /**< (I) The Group Occurrence Type. */
    int n_occurrence_types,                  /**< (I) Number of Occurrence Types. */
    const char** occurrence_types            /**< (I) n_occurrence_types The Occurrence Types. */
    );

/**
    Adds the given entry to the given group entry.

    <b>Restrictions:</b>

    Only working and status entries may be added into a group. All the entries in a group must be of
    the same type, i.e. all working or all status. For status entries, all must use the same
    criteria to decide 'latest' (release date, effective date, or effective unit number). For
    example, it is not possible to decide between a release date and a unit number which one is latest.

    <b>Return Values:</b>

    #CFM_entry_is_not_groupable - Only working and status entries may be grouped.<br>
    #CFM_entry_incompatible_w_group - New entry has different type or latest criterion from those already in the group.
*/
extern CFM_API int CFM_group_entry_add_entry(
    tag_t          group_entry,     /**< (I) Tag of the group entry */
    tag_t          entry_to_add     /**< (I) Tag of the entry to add to the group */
    );

/**
    Removes entry from group, entry is added back into rule.
    If group is left empty, it is deleted.

    <b>Return Values:</b>

    #CFM_entry_not_in_group - The entry is not in the given group.
*/
extern CFM_API int CFM_group_entry_remove_entry(
    tag_t          group_entry,     /**< (I) Tag of the group entry */
    tag_t          entry_in_group   /**< (I) Tag of the entry to remove from the group */
    );

extern CFM_API int CFM_rule_ask_unit(
    tag_t          rule,    /**< (I) */
    int*           unit     /**< (O) */
    );

extern CFM_API int CFM_rule_set_unit(
    tag_t          rule,    /**< (I) */
    int            unit     /**< (I) */
    );

/**
    Returns the revision rule modifier currently in effect. This modifier
    can define an End Item, End Item Revision, Date or Unit Number that
    will override those set in the revision rule itself.
*/
extern CFM_API int CFM_rule_ask_modifier(
    tag_t          rule,       /**< (I) */
    tag_t *        modifier    /**< (O) */
    );

/**
    Sets the current modifier of the revision rule. This modifier can define
    an End Item, End Item Revision, Date or Unit Number that will
    override those set in the revision rule itself.
*/
extern CFM_API int CFM_rule_set_modifier(
    tag_t          rule,       /**< (I) */
    tag_t          modifier    /**< (I) */
    );

/**
    Applies the revision rule to the effectivity mappings of the item revision
    in order to generate a revision rule modifier that can be applied to
    the rule using CFM_rule_set_modifier. If no mapping applies then
    new_modifier will be returned as NULLTAG.

    The override_parent flag indicates whether the mapping is allowed to
    override non-null settings in the parent configuration. This is usually
    set to true. It is only set to false for product structure roots when
    we want the values stored in the revision rule itself to take precedence
    over the root mapping.

    If old_modifier is input as NULLTAG then this function will create a new
    modifier for new_modifier. If old_modifier is input as non-NULLTAG then
    this function will update the existing modifier.

    Note that if old_modifier is not NULLTAG, but new_modifier is returned as
    NULLTAG, then it is up to the caller to delete the old_modifier object.
*/
extern CFM_API int CFM_rule_generate_modifier(
    tag_t          rule,                /**< (I) */
    tag_t          itemrev,             /**< (I) */
    logical        override_parent,     /**< (I) */
    tag_t          old_modifier,        /**< (I) */
    tag_t *        new_modifier         /**< (O) */
    );

/**
    Applies nested effectivity to the given set of items. It assumes that
    these items represent a path down a product structure. It will return
    the configured revision of each item and the modifier that was generated
    against that itemrev. This modifier can then be used to further configure
    sub-structure.

    The override_parent flag indicates whether the first mapping is allowed to
    override non-null settings in the parent configuration. This flag only
    affects the first item in the array. This will be set to true if the first
    item is not the root of the product structure. It is only set to false for
    product structure root items when we want the values stored in the revision
    rule itself to take precedence over the root mapping.
*/
extern CFM_API int CFM_rule_generate_modifier_chain(
    tag_t          rule,                /**< (I) */
    int            n_items,             /**< (I) */
    tag_t *        items,               /**< (I) n_items */
    logical        override_parent,     /**< (I) */
    tag_t **       itemrevs,            /**< (OF) n_items */
    tag_t **       modifiers            /**< (OF) n_items */
    );

/**
    Applies nested effectivity to the given set of configuration items, and
    returns the configured revision of hte last item and the last modifier
    (which does not necessarily belong to the last item). It assumes that
    these items represent a partial path down a product structure. Any
    non-configuration items in the list have no effect on the result. The
    last modifier can then be used to further configure sub-structure.

    The override_parent flag indicates whether the first mapping is allowed to
    override non-null settings in the parent configuration. This flag only
    affects the first item in the array. This will be set to true if the first
    item is not the root of the product structure. It is only set to false for
    product structure root items when we want the values stored in the revision
    rule itself to take precedence over the root mapping.
*/
extern CFM_API int CFM_rule_generate_end_modifier(
    tag_t          rule,                /**< (I) */
    int            n_items,             /**< (I) */
    tag_t *        items,               /**< (I) n_items */
    logical        override_parent,     /**< (I) */
    tag_t *        last_itemrev,        /**< (O) */
    tag_t *        last_modifier        /**< (O) */
    );

/**
    Deletes a revision rule modifier. For performance reasons, it is recommended
    that you use CFM_rule_set_modifier to ensure that your revision rule isn't
    referencing this modifier. It shouldn't do any harm if you don't do this,
    but it may slow down subsequent configuration calls.

    <b>Restrictions:</b>

    Only use this function on modifiers created by a call to CFM_rule_generate_modifier.
    Do not use it on modifiers generated on a BOMLine. Doing so will interfere with
    BOM level configuration management.
*/
extern CFM_API int CFM_rule_delete_modifier(
    tag_t          modifier    /**< (I) */
    );

/**
    Gives the end item set on the given rule.
*/
extern CFM_API int CFM_rule_ask_end_item(
    tag_t          rule,    /**< (I) The rule being queried */
    tag_t*         end_item /**< (O) The end item used by any of the rule status entries
                                    that are configured by effective date or unit */
    );

extern CFM_API int CFM_rule_ask_end_item_rev(
    tag_t          rule,        /**< (I) The rule being queried */
    tag_t*         end_item_rev /**< (O) The end item revision used by any of the rule status entries
                                    that are configured by effective date or unit */
    );

/**
    Sets the end item on the given rule.
*/
extern CFM_API int CFM_rule_set_end_item(
    tag_t          rule,    /**< (I) The rule being modified */
    tag_t          end_item /**< (I) The end item used by any of the rule status entries that
                                    are configured by effective date or unit */
    );

extern CFM_API int CFM_rule_set_end_item_rev(
    tag_t          rule,    /**< (I) The rule being modified */
    tag_t          end_item_rev /**< (I) The end item revision used by any of the rule status entries that
                                    are configured by effective date or unit */
    );

extern CFM_API int CFM_rule_add_intent(
    tag_t          rule,    /**< (I) */
    tag_t          intent   /**< (I) */
    );

extern CFM_API int CFM_rule_remove_intent(
    tag_t          rule,    /**< (I) */
    tag_t          intent   /**< (I) */
    );

extern CFM_API int CFM_rule_list_intents(
    tag_t          rule,        /**< (I) */
    int*           n_intents,   /**< (O) */
    tag_t**        intents      /**< (OF) n_intents */
    );

/**
    @name CFM Item
    @{
*/

/**
    Finds the revision of the given item that is configured when
    the given revision rule is used to configure the given item.
    Also returns a textual representation of which entry/entries
    in the rule caused the particular revision to be configured.

    If no revision of the item is configured by the rule,
    #NULLTAG is returned as the configured revision.

    By default, this call is not aware of nested effectivity.
    If you want to make it aware of nested effectivity, set
    the preference CFMNestedEffectivityOverride to -1.

    Callers that are aware of nested effectivity should use
    CFM_item_ask_configured_base instead of this. Callers
    that cannot handle nested effectivity, but would like
    to try, can call CFM_item_ask_configured_nested.
*/
extern CFM_API int CFM_item_ask_configured(
    tag_t          rule,            /**< (I) Tag of the revision rule to use for the configuration */
    tag_t          item,            /**< (I) Tag of the item to configure */
    tag_t*         configured_rev,  /**< (O) Tag of the configured revision (or #NULLTAG) */
    char**         how_configured   /**< (OF) An explanation of why the particular revision was configured */
    );

/**
    Retrieves the revisions of the Items configured by @p rev_rule.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CFM_invalid_tag if @p rev_rule is invalid or #NULLTAG or @p items_and_revs contains an invalid tag.
    </ul>
*/
extern CFM_API int CFM_items_ask_configured(
    tag_t          rev_rule,            /**< (I) The Revision rule to use for the configuration. */
    int            n_items_and_revs,    /**< (I) Number of Item and Item Revision objects. */
    const tag_t*   items_and_revs,      /**< (I) n_items_and_revs The objects to be configured.
                                        <br/>This can contain a mixture of Item and Item Revision objects.
                                        <br/>For precise revision rule, if an Item Revision is a match, the same revision will be the configured revision.
                                        <br/>For all other rules, the rule matches upon the Item of the given revision. */
    tag_t**        configured_revs,     /**< (OF) n_items_and_revs The configured revisions.
                                        <br/>If no revision of the item is configured by the rule, the associated value will be #NULLTAG.
                                        <br/>If the object provided in @p items_and_revs is #NULLTAG or of type other than Item or Item Revision,
                                        the associated value will be #NULLTAG. */
    char***        how_configured       /**< (OF) n_items_and_revs Provides the reason to explain how a specific revision is configured.
                                        <br/>If the revision is not configured, the associated value will be an empty string.
                                        <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
);

/**
    Finds the revision of the given item that is configured when
    the given revision rule is used to configure the given item.
    Also returns a textual representation of which entry/entries
    in the rule caused the particular revision to be configured.

    If no revision of the item is configured by the rule,
    #NULLTAG is returned as the configured revision.

    This call should be used by clients that are aware of
    nested effectivity, and are generating revision rule
    modifiers.
*/
extern CFM_API int CFM_item_ask_configured_base(
    tag_t          rule,            /**< (I) Tag of the revision rule to use for the configuration */
    tag_t          item,            /**< (I) Tag of the item to configure */
    tag_t*         configured_rev,  /**< (O) Tag of the configured revision (or #NULLTAG) */
    char**         how_configured   /**< (OF) An explanation of why the particular revision was configured */
    );

/**
    Finds the revision of the given item that is configured when
    the given revision rule is used to configure the given item.
    Also returns a textual representation of which entry/entries
    in the rule caused the particular revision to be configured.

    If no revision of the item is configured by the rule,
    #NULLTAG is returned as the configured revision.

    This call is different from CFM_item_ask_configured in that
    it attempts to resolve nested effectivity configuration
    internally.Note that in the absence of product structure this
    is only an approximation of the configuration. It cannot handle
    multiple revisions per product structure.

    This call should be used by clients that cannot handle nested
    effectivity.
*/
extern CFM_API int CFM_item_ask_configured_nested(
    tag_t          rule,            /**< (I) Tag of the revision rule to use for the configuration */
    tag_t          item,            /**< (I) Tag of the item to configure */
    tag_t*         configured_rev,  /**< (O) Tag of the configured revision (or #NULLTAG) */
    char**         how_configured   /**< (OF) An explanation of why the particular revision was configured */
    );

/**
    Where a revision is configured (configured_rev != #NULLTAG),
    returns a CFMHowConfigured record which describes how the rev was configured.
    See description of #CFM_latest_of_latest.

    @note After use you should free up the memory associated with
    a CFMHowConfigured record by calling #CFM_free_how_configured.
*/
extern CFM_API int CFM_item_ask_how_configured(
    tag_t          rule,            /**< (I) Tag of the revision rule to use for the configuration */
    tag_t          item,            /**< (I) Tag of the item to configure */
    tag_t*         configured_rev,  /**< (O) Tag of the configured revision (or #NULLTAG) */
    tag_t*         how_configured   /**< (O) Describes how the revision rule decided on the configured revision */
    );

/** @} */

/**
    Turns a CFMHowConfigured record into the equivalent text as displayed in 'how configured' column.
*/
extern CFM_API int CFM_how_configured_text(
    tag_t          how_configured,  /**< (I) Describes how the revision rule decided on a configured revision */
    char**         text             /**< (OF) Text describing how the revision rule decided on a configured revision */
    );

/**
    For use in conjunction with Incremental Change (IC) configuration.
    With IC you may find you have 'competing' states of data
    (e.g. several occ datas setting transform for the same occurrence).
    Where you have multiple such states configured, you will want to know which is 'latest'.
    For each configured IC revision #CFM_item_ask_how_configured will have given you back a
    CFMHowConfigured record describing how that revision was configured.
    You then assemble the tags of those CFMHowConfigureds into an array,
    and pass them to this function,
    which will pass back the tag of the 'latest' one according to this rev rule.
*/
extern CFM_API int CFM_latest_of_latest(
    tag_t          rule,            /**< (I) Tag of the revision rule to use for the configuration */
    int            n_candidates,    /**< (I) Number of candidate how configured records */
    tag_t*         candidates,      /**< (I) n_candidates Array of candidate how configured records */
    tag_t*         latest           /**< (O) Points to the candidate how configured record deemed 'latest' */
    );

/**
    'User ref' allows the caller to associate some tag value to a CFMHowConfigured record,
    and retrieve it again. With the example described for #CFM_latest_of_latest above,
    the caller might store the tag of the corresponding configured occ data
    against each candidate CFMHowConfigured record,
    and retrieve the value from the 'winner' identified by #CFM_latest_of_latest.
*/
extern CFM_API int CFM_ask_how_configured_user_ref(
    tag_t          how_configured,  /**< (I) Tag of the CFMHowConfigured record */
    tag_t*         user_ref         /**< (O) Gives tag value previously stored using #CFM_set_how_configured_user_ref */
    );

/**
    'User ref' allows the caller to associate some tag value to a CFMHowConfigured record,
    and retrieve it again. With the example described for #CFM_latest_of_latest above,
    the caller might store the tag of the corresponding configured occ data
    against each candidate CFMHowConfigured record,
    and retrieve the value from the 'winner' identified by #CFM_latest_of_latest.
*/
extern CFM_API int CFM_set_how_configured_user_ref(
    tag_t          how_configured,  /**< (I) Tag of the CFMHowConfigured record */
    tag_t          user_ref         /**< (I) Tag value to be associated to the CFMHowConfigured record */
    );

/**
    Frees up the memory allocated to a CFMHowConfigured record.
*/
extern CFM_API int CFM_free_how_configured(
    tag_t          how_configured   /**< (I) Tag of the CFMHowConfigured record no longer required */
    );

/**
    Finds the revision rule, either stored in the database or modified in the current session.
*/
extern CFM_API int CFM_find(
    const char*    name,    /**< (I) Identifier for the rule name */
    tag_t*         rule     /**< (O) Rule found */
    );

/**
    Lists the tags of all accessible preset rules stored in the database.
*/
extern CFM_API int CFM_list(
    int*           count,   /**< (O) Number of rule tags found */
    tag_t**        rules    /**< (OF) count Tags of the rules found in the database */
    );

/**
    Retrieves the list of all user-visible and non-suppressed Revision Rules in the database.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_internal_error if the system has failed to load Revision Rules.
    </ul>
*/
extern CFM_API int CFM_get_revision_rules(
    int*           count,   /**< (O) Number of rule tags found */
    tag_t**        rules    /**< (OF) count User-visible and non-suppressed Revision Rules found */
    );

/**
    This will force the rule to update the BOM window using the rule (if any).
    This should be used if the settings associated with the rule have been changed.
*/
extern CFM_API int CFM_updated(
    tag_t          rule     /**< (I) Tag of the rule to be updated */
    );

/**
    @name CFM Occurrence Effectivity
    @{
*/

/**
    Indicates if the occurrence is configured in the context of the given revision rule.
*/
extern CFM_API int CFM_is_occ_configured(
    tag_t          rule,    /**< (I) Tag of the revision rule (contains configuration date) */
    tag_t          bvr,     /**< (I) Tag of the parent BOMView Revision */
    tag_t          occ,     /**< (I) Tag of the occurrence */
    logical*       answer   /**< (O) True if the occurrence is configured, false otherwise. */
    );

/**
    Sets the date effectivity on the occurrence.

    If necessary, this function will load the parent BOMView Revision and lock it for modify.
    Note that this function modifies the occurrence in the loaded representation of the BOMView Revision only.
    The modification will only be propagated to the database when the parent BOMView Revision is saved
    using #AOM_save_with_extensions/#AOM_save_without_extensions. After saving the BOMView Revision, it should be unlocked.
*/
extern CFM_API int CFM_occ_set_effectivity(
    tag_t          bvr,         /**< (I) Tag of the parent BOMView Revision */
    tag_t          occ,         /**< (I) Tag of the occurrence */
    tag_t          eff_object   /**< (I) Tag of the effectivity object containing the required date effectivity */
    );

/**
    Gives the date effectivity on the occurrence.
*/
extern CFM_API int CFM_occ_ask_effectivity(
    tag_t          bvr,         /**< (I) Tag of the parent BOMView Revision */
    tag_t          occurrence,  /**< (I) Tag of the occurrence */
    tag_t*         eff_object   /**< (O) Tag of the effectivity object attached to the occurrence.
                                       #NULLTAG if no effectivity. */
    );

/**
    @deprecated #CFM_effectivity_create deprecated in Teamcenter 12.3. Use #PS_occ_eff_create instead.
    <br/>In order to migrate CFM_date_info to Effectivity, please refer to the link -
    http://docsstage.plm.automation.siemens.com/tdoc/tc/11.6/help#uid:occeff_understanding
    @code
        PS_occ_eff_create
        PS_occ_eff_set_id
    @endcode

    Creates a new date effectivity object.
*/
TC_DEPRECATED("12.3","CFM_effectivity_create","PS_occ_eff_create")
extern CFM_API int CFM_effectivity_create(
    const char*    id,          /**< (I) Unique identifier for the new effectivity object */
    tag_t*         eff_object   /**< (O) Tag of the newly created effectivity object */
    );

/**
    @deprecated #CFM_effectivity_find deprecated in Teamcenter 12.3. Use #CFM_find_effectivities instead.
    @code
        CFM_find_effectivities
    @endcode

    Finds a specified effectivity object.
*/
TC_DEPRECATED("12.3","CFM_effectivity_find","CFM_find_effectivities")
extern CFM_API int CFM_effectivity_find(
    const char*    id,          /**< (I) Identifier of the sought effectivity object */
    tag_t*         eff_object   /**< (O) Tag of the matching effectivity object */
    );

/**
    @deprecated #CFM_effectivity_ask_id deprecated in Teamcenter 12.3. Use #PS_occ_eff_ask_id instead.
    @code
        PS_occ_eff_ask_id
    @endcode

    Gives the ID of the effectivity object.
*/
TC_DEPRECATED("12.3","CFM_effectivity_ask_id","PS_occ_eff_ask_id")
extern CFM_API int CFM_effectivity_ask_id(
    tag_t          eff_object,  /**< (I) Tag of the effectivity object */
    char**         id           /**< (OF) ID of the effectivity object */
    );

/**
    @deprecated #CFM_effectivity_set_id deprecated in Teamcenter 12.3. Use #PS_occ_eff_set_id instead.
    @code
        PS_occ_eff_set_id
     @endcode

    Sets the ID of the effectivity object.
*/
TC_DEPRECATED("12.3","CFM_effectivity_set_id","PS_occ_eff_set_id")
extern CFM_API int CFM_effectivity_set_id(
    tag_t          eff_object,  /**< (I) Tag of the effectivity object */
    const char*    id           /**< (I) New ID for the effectivity object */
    );

/**
    @deprecated #CFM_effectivity_ask_date_ranges deprecated in Teamcenter 12.3. Use #PS_occ_eff_ask_date_range instead.
    @code
        PS_occ_eff_ask_date_range
    @endcode

    Gives the list of effective date ranges on the effectivity object.
*/
TC_DEPRECATED("12.3","CFM_effectivity_ask_date_ranges","PS_occ_eff_ask_date_range")
extern CFM_API int CFM_effectivity_ask_date_ranges(
    tag_t          eff_object,      /**< (I) Tag of the effectivity object */
    int*           n_ranges,        /**< (O) Number of date ranges attached to the effectivity object */
    date_t**       from_dates,      /**< (OF) n_ranges List of "from" dates for the date ranges */
    date_t**       to_dates         /**< (OF) n_ranges List of "to" dates for the date ranges */
    );

/**
    @deprecated #CFM_effectivity_set_date_ranges deprecated in Teamcenter 12.3. Use #PS_occ_eff_set_date_range instead.

    @code
        PS_occ_eff_set_date_range
    @endcode

    Sets the date ranges for the effectivity object, replacing all existing ranges on the object.

    <b>Restrictions:</b>

    Each date range range must be non-overlapping.
    The final "to-date" may be #NULLDATE to represent an open-ended final range.
    No other range may be open-ended
*/
TC_DEPRECATED("12.3","CFM_effectivity_set_date_ranges","PS_occ_eff_set_date_range")
extern CFM_API int CFM_effectivity_set_date_ranges(
    tag_t          eff_object,     /**< (I) Tag of the effectivity object */
    int            n_ranges,       /**< (I) Number of date ranges to attach to the effectivity object */
    date_t*        from_dates,     /**< (I) List of "from" dates for the date ranges */
    date_t*        to_dates        /**< (I) List of "to" dates for the date ranges */
    );

/** @} */

/**
    Create a new intent object
*/
extern CFM_API int CFM_create_intent(
    const char*    name,         /**< (I) */
    const char*    desc,         /**< (I) */
    tag_t*         new_intent    /**< (O) */
    );

/** @} */

/*================================================================================================*/

/**
    @name Unified Effectivity
    @{
*/

extern CFM_API int CFM_find_effectivities(
    const char * id,         /**< (I) */
    int *        n_effs,     /**< (O) */
    tag_t **     effs,       /**< (OF) */
    tag_t *      date_info   /**< (O) */
    );

/** @} */

/**
    @name Effectivity Mapping
    @{
*/

extern CFM_API int CFM_create_eff_mapping(
    tag_t       itemrev,        /**< (I) */
    tag_t*      mapping         /**< (O) */
    );

extern CFM_API int CFM_set_eff_mapping_eff(
    tag_t        mapping,      /**< (I) */
    tag_t        eff           /**< (I) */
    );

extern CFM_API int CFM_set_eff_mapping_eff_id(
    tag_t        mapping,   /**< (I) */
    const char * id         /**< (I) */
    );

extern CFM_API int CFM_set_eff_mapping_eff_protection(
    tag_t       mapping,        /**< (I) */
    logical     protection      /**< (I) */
    );

extern CFM_API int CFM_set_eff_mapping_enditem(
    tag_t       mapping,        /**< (I) */
    tag_t       enditem         /**< (I) */
    );

extern CFM_API int CFM_set_eff_mapping_enditemrev(
    tag_t       mapping,        /**< (I) */
    tag_t       enditemrev      /**< (I) */
    );

extern CFM_API int CFM_set_eff_mapping_unit_range(
    tag_t       mapping,        /**< (I) */
    const char* range_text,     /**< (I) */
    logical     append          /**< (I) */
    );

extern CFM_API int CFM_set_eff_mapping_units(
    tag_t       mapping,                   /**< (I) */
    int         n_units,                   /**< (I) */
    int*        start_end_values,          /**< (I) n_units */
    int         open_ended_or_stock_out,   /**< (I) */
    logical     append                     /**< (I) */
    );

extern CFM_API int CFM_set_eff_mapping_date_range(
    tag_t       mapping,        /**< (I) */
    const char* range_text,     /**< (I) */
    logical     append          /**< (I) */
    );

extern CFM_API int CFM_set_eff_mapping_dates(
    tag_t       mapping,                   /**< (I) */
    int         n_dates,                   /**< (I) */
    date_t*     start_end_values,          /**< (I) n_dates */
    int         open_ended_or_stock_out,   /**< (I) */
    logical     append                     /**< (I) */
    );

extern CFM_API int CFM_set_eff_mapping_subenditem(
    tag_t       mapping,        /**< (I) */
    tag_t       subenditem      /**< (I) */
    );
extern CFM_API int CFM_set_eff_mapping_subenditemrev(
    tag_t       mapping,        /**< (I) */
    tag_t       subenditemrev   /**< (I) */
    );
extern CFM_API int CFM_set_eff_mapping_subunit(
    tag_t       mapping,        /**< (I) */
    int         subunit         /**< (I) */
    );
extern CFM_API int CFM_set_eff_mapping_subdate(
    tag_t       mapping,        /**< (I) */
    date_t      subdate         /**< (I) */
    );

extern CFM_API int CFM_ask_eff_mapping_eff(
    tag_t        mapping,      /**< (I) */
    tag_t *      eff           /**< (O) */
    );

extern CFM_API int CFM_ask_eff_mapping_eff_id(
    tag_t       mapping,   /**< (I) */
    char **     id         /**< (OF) */
    );

extern CFM_API int CFM_ask_eff_mapping_eff_protection(
    tag_t       mapping,        /**< (I) */
    logical *   protection      /**< (O) */
    );

extern CFM_API int CFM_ask_eff_mapping_enditem(
    tag_t       mapping,        /**< (I) */
    tag_t *     enditem         /**< (O) */
    );

extern CFM_API int CFM_ask_eff_mapping_enditemrev(
    tag_t       mapping,        /**< (I) */
    tag_t*      enditemrev      /**< (O) */
    );

extern CFM_API int CFM_ask_eff_mapping_range_type(
    tag_t       mapping,        /**< (I) */
    int*        range_type      /**< (O) */
    );

extern CFM_API int CFM_ask_eff_mapping_unit_range(
    tag_t       mapping,        /**< (I) */
    char**      range_text      /**< (OF) */
    );

extern CFM_API int CFM_ask_eff_mapping_units(
    tag_t       mapping,                  /**< (I) */
    int*        n_units,                  /**< (O) */
    int**       start_end_values,         /**< (OF) n_units */
    int*        open_ended_or_stock_out   /**< (O) */
    );

extern CFM_API int CFM_ask_eff_mapping_date_range(
    tag_t       mapping,        /**< (I) */
    char**      range_text      /**< (OF) */
    );

extern CFM_API int CFM_ask_eff_mapping_dates(
    tag_t       mapping,                  /**< (I) */
    int*        n_dates,                  /**< (O) */
    date_t**    start_end_values,         /**< (OF) n_dates */
    int*        open_ended_or_stock_out   /**< (O) */
    );

extern CFM_API int CFM_ask_eff_mapping_subenditem(
    tag_t       mapping,        /**< (I) */
    tag_t*      subenditem      /**< (O) */
    );
extern CFM_API int CFM_ask_eff_mapping_subenditemrev(
    tag_t       mapping,        /**< (I) */
    tag_t*      subenditemrev   /**< (O) */
    );
extern CFM_API int CFM_ask_eff_mapping_subunit(
    tag_t       mapping,        /**< (I) */
    int*        subunit         /**< (O) */
    );
extern CFM_API int CFM_ask_eff_mapping_subdate(
    tag_t       mapping,        /**< (I) */
    date_t*     subdate         /**< (O) */
    );

/** @} */

/**
    @name Revision Rule Modifiers
    @{
*/

extern CFM_API int CFM_rule_modifier_ask_enditem(
    tag_t       modifier,       /**< (I) */
    tag_t*      enditem         /**< (O) */
    );
extern CFM_API int CFM_rule_modifier_ask_enditemrev(
    tag_t       modifier,       /**< (I) */
    tag_t*      enditemrev      /**< (O) */
    );
extern CFM_API int CFM_rule_modifier_ask_unit(
    tag_t       modifier,       /**< (I) */
    int*        unit            /**< (O) */
    );
extern CFM_API int CFM_rule_modifier_ask_date(
    tag_t       modifier,       /**< (I) */
    date_t*     date            /**< (O) */
    );

/** @} */

/*================================================================================================*/
#ifdef __cplusplus
}
#endif

#include <cfm/libcfm_undef.h>
#endif
