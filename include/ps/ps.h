/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2019.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file


    Function prototypes for the Product Structure (PS) ITK.
*/

/*

*/

#ifndef PS_H_INCLUDED
#define PS_H_INCLUDED

#include <ps/ps_errors.h>
#include <ps/ps_tokens.h>
#include <unidefs.h>
#include <ps/libps_exports.h>

/* END OF HEADER */

/**
    @defgroup PS Product Structure (PS)

    The Product Structure (PS) ITK module manages the creation, manipulation, and storage of
    product structure data within Teamcenter.

    Product structure in Teamcenter is represented by assembly Items containing links to
    component Items which make up the assembly. The structure of Items is represented in BOMView objects.
    The links to component Items are known as occurrences.

    The PS ITK module covers the creation of BOMViews and BOMView Revisions for Items and Item Revisions,
    the creation and modification of occurrences to reference the component parts of an assembly and
    the attachment of structure related attributes to occurrences.

    <b>Common Return Values</b>

    <table>
    <tr><td>Return Value</td>                     <td>Description</td></tr>
    <tr><td>#CFM_invalid_tag</td>                 <td>Tag is not a valid config_rule.</td></tr>
    <tr><td>#POM_attr_null_forbidden</td>         <td>type_name is NULL or zero length.</td></tr>
    <tr><td>#POM_inst_referenced</td>             <td>BOMView or one of its Revisions is already referenced.</td></tr>
    <tr><td>#POM_inst_violates_unique</td>        <td>view_type or note_type of the same name already exists in the database.</td></tr>
    <tr><td>#POM_invalid_string</td>              <td>String is NULL, zero length or too long.</td></tr>
    <tr><td>#PS_no_seq_no</td>                    <td>No sequence number has been set for this occurrence.</td></tr>
    <tr><td>#PS_bvr_is_precise</td>               <td>For a precise parent BOMView Revision,
                                                      child_item must be the tag of a specific Item Revision, not an Item.</td></tr>
    <tr><td>#PS_cant_delete_preferred</td>        <td>child_item is the preferred substitute.</td></tr>
    <tr><td>#PS_cant_unattach_bvr</td>            <td>Revising an unshared BOMView Revision is not allowed,
                                                      as it would be left unattached.</td></tr>
    <tr><td>#PS_cyclic_structure</td>             <td>You cannot create an occurrence of the same Item whose revision contains
                                                      the parent BOMView Revision.
                                                      This would produce a structure which references itself.</td></tr>
    <tr><td>#PS_duplicate</td>                    <td>The combination of view_type and parent_item must be unique.</td></tr>
    <tr><td>#PS_insufficient_privilege</td>       <td>User must have Teamcenter Engineering system administrator privileges.</td></tr>
    <tr><td>#PS_invalid_attribute</td>            <td>No attribute of this name is registered with the occurrence class.</td></tr>
    <tr><td>#PS_invalid_bom_view</td>             <td>Tag is not a valid BOMView.</td></tr>
    <tr><td>#PS_invalid_bvr</td>                  <td>Tag is not a valid BOMView Revision.</td></tr>
    <tr><td>#PS_invalid_child_item</td>           <td>Tag is not an Item or Item Revision.</td></tr>
    <tr><td>#PS_invalid_class</td>                <td>Not a valid PS class identifier.</td></tr>
    <tr><td>#PS_invalid_item</td>                 <td>Tag is not a valid Item.</td></tr>
    <tr><td>#PS_invalid_note_type</td>            <td>Tag is not a valid note_type.</td></tr>
    <tr><td>#PS_invalid_occurrence</td>           <td>No such occurrence in this parent BOMView Revision.</td></tr>
    <tr><td>#PS_invalid_occurrence_flag</td>      <td>Not a valid occurrence flag token.</td></tr>
    <tr><td>#PS_invalid_ref_class</td>            <td>The client data is not an instance of the POM class specified in
                                                      the definition of this attribute.</td></tr>
    <tr><td>#PS_invalid_value</td>                <td>The new index is less than zero or greater than the number of
                                                      occurrences of the parent BOMView Revision minus one.</td></tr>
    <tr><td>#PS_invalid_view_type</td>            <td>Tag is not a valid view_type.</td></tr>
    <tr><td>#PS_no_default_view_type</td>         <td>View type was #NULLTAG but no default view_type defined.</td></tr>
    <tr><td>#PS_no_note_of_this_type</td>         <td>This occurrence does not have a note of this type.</td></tr>
    <tr><td>#PS_no_such_substitute</td>           <td>child_item is not a substitute of this occurrence.</td></tr>
    <tr><td>#PS_no_transform</td>                 <td>This occurrence has no transform set.</td></tr>
    <tr><td>#PS_not_found</td>                    <td>No such view_type.</td></tr>
    <tr><td>#PS_has_old_transform_only</td>       <td>Occurrence only has old format transform.</td></tr>
    <tr><td>#PS_could_not_convert_transform</td>  <td>Could not convert old format transform to PLMXML format.</td></tr>
    <tr><td>#PS_no_legacy_transform_factor</td>   <td>There is no legacy transform factor on the BVR.</td></tr>
    <tr><td>#PS_not_a_plmxml_transform</td>       <td>There is no PLMXML transform on this occurrence.</td></tr>
    <tr><td>#PS_two_transforms</td>               <td>This occurrence has a PLMXML transform and an old transform;
                                                      this is an invalid situation.</td></tr>
    <tr><td>#PS_allow_plmxml_pref_invalid</td>    <td>The preference PS_allow_plmxml_transforms_with_no_legacy_factor
                                                      is invalid or does not exist " "(should take values Yes or No).</td></tr>
    <tr><td>#PS_transform_format_pref_invalid</td><td>The preference PS_assume_old_transform_format must only take values
                                                      In_Legacy_Format, " ", Written_By_UG or Unknown (case sensitive).</td></tr>
    <tr><td>#PS_transform_units_pref_invalid</td> <td>The preference PS_assume_legacy_transform_units must only take values
                                                      Inches, Millimeters, " " or Unknown</td></tr>
    </table>
    @{
*/

#ifdef __cplusplus
 extern "C"{
#endif

/**
    @name PS View Type Functions
    @{
*/

/**
    Retrieves the list of valid occurrence types for this view type, if defined
*/
extern PS_API int PS_view_type_ask_valid_occurrence_types(
    tag_t         type_tag,     /**< (I) */
    tag_t**       valid_occs,   /**< (O) */
    int*          count         /**< (O) */
    );

/**
    Retrieves the default occurrence type for this view type, if defined
*/
extern PS_API int PS_view_type_ask_default_occurrence_type(
    tag_t         view_type_tag,    /**< (I) */
    tag_t*        occ_type_tag      /**< (O) */
    );

/**
    Retrieves the name of a view type.
*/
extern PS_API int PS_ask_view_type_name(
    tag_t         view_type,    /**< (I) Tag of the view type */
    char**        type_name     /**< (OF) Name of the view type */
    );

/**
    Retrieves the tag of the view type with the specified name.
*/
extern PS_API int PS_find_view_type(
    const char*   type_name,    /**< (I) Name of the view type */
    tag_t*        view_type     /**< (O) Tag of the view type */
    );

/**
    Retrieves the list of BOMview types valid for this site.
*/
extern PS_API int PS_view_type_extent(
    int*          n_types,      /**< (O) Number of view types in the list */
    tag_t**       view_types    /**< (OF) n_types The view type tags */
    );

extern PS_API int PS_get_displayable_view_types(
    int*          n_types,      /**< (O) */
    tag_t**       view_types    /**< (OF) n_types */
    );

/**
    Looks at site/group/role/user/local preferences as appropriate
    to find the default view type defined for the current user.
    Retrieves #NULLTAG if a default view type is not defined.
*/
extern PS_API int PS_ask_default_view_type(
    tag_t*        view_type     /**< (O) User's default view type */
    );

/** @} */

/**
    @name PS Occurrence Types

    <b>Common Return Values:</b>

    #PS_duplicate - An occurrence type by the same name already exists in the database. <br>
    #PS_invalid_occ_type - Invalid occurrence type tag specified.
    @{
*/

/**
    Retrieves the tag of the occ classification with the given name.
*/
extern PS_API int PS_find_occurrence_type(
    const char*   type_name,    /**< (I) The name of the occurrence type to find */
    tag_t*        occ_type      /**< (O) Tag of the existing occurrence type of the given name */
    );

/**
    Lists all occurrence types in the database.
*/
extern PS_API int PS_occurrence_type_extent(
    int*          n_types,      /**< (O) Number of occcurrence types in the database */
    tag_t**       occ_types     /**< (OF) n_types Array of tags of all the occurrence types */
    );

/**
    Enquires the name of an existing occurrence type.
*/
extern PS_API int PS_ask_occurrence_type_name(
    tag_t         occ_type,     /**< (I) Tag of the occurrence type to enquire name for */
    char**        type_name     /**< (OF) The name of the occurrence type */
    );

/** @} */

/**
    @name PS BOM View Functions
    @{
*/

/**
    Creates a new BOMView. No BOMView Revisions exist yet. The BOMView is made a view of the specified item.
    If view_type is #NULLTAG, the default view type will be used (as given by #PS_ask_default_view_type).

    @note The new BOMView is not saved. It can be saved to the database using #AOM_save.
    Note that the parent_item is modified and must also be saved.
    The new BOMView must be saved before the parent_item is saved.
    Failure to do so results in the BOMView not being added to the parent.
*/
extern PS_API int PS_create_bom_view(
    tag_t         view_type,    /**< (I) Site-specific identifier for the type of view (e.g., DESIGN, Assembly) */
    const char*   view_name,    /**< (I) Name of the view. If NULL or empty string is specified,
                                        the default name is used. See also #PS_default_bom_view_name. */
    const char*   view_desc,    /**< (I) Optional description text (NULL if not required) */
    tag_t         parent_item,  /**< (I) Makes the new BOMView a view of this Item */
    tag_t*        bom_view      /**< (O) The new BOMView */
    );

/**
    Retrieves a default name for a BOMView.
    The default implementation creates a name of the form "<Item ID>-<view type name>" (e.g., 100-Design).

    @note To allow user customization of the default name format,
    this function calls out via the #USER_ps_default_bom_view_name user exit.
    The default implementation of this user exit uses the #PS_system_default_bom_view_name function
    to generate the default name format as described above.

    @note It is not necessary to call this function to pass a name to #PS_create_bom_view,
    as that function will automatically use the default name when passed a NULL or empty string ("")
    (e.g., to pre-populate a dialog box field with a default name for a BOMView to be created).

    @note If the view_type argument is #NULLTAG, the user's default view type is used.
*/
extern PS_API int PS_default_bom_view_name(
    tag_t         item,         /**< (I) Tag of the Item of the BOMView */
    tag_t         view_type,    /**< (I) Tag of the view type of the BOMView */
    char**        name          /**< (OF) */
    );

/**
    Deletes a BOMView and all of its BOMViewRevisions, provided none of them is referenced.
*/
extern PS_API int PS_delete_bom_view(
    tag_t         bom_view      /**< (I) Tag of the view to be deleted */
    );

/**
    Retrieves the tag of the item of which the BOMView is an attribute.
*/
extern PS_API int PS_ask_item_of_bom_view(
    tag_t         bom_view,     /**< (I) Tag of the BOMView */
    tag_t*        item          /**< (O) The item to which the BOMView is an attribute */
    );

/**
    Retrieves the view type of a BOMView.
*/
extern PS_API int PS_ask_bom_view_type(
    tag_t         bom_view,     /**< (I) Tag of the BOMView */
    tag_t*        view_type     /**< (O) Tag of the view type of BOMView */
    );

/**
    Sets the view type of a BOMView.
*/
extern PS_API int PS_set_bom_view_type(
    tag_t         bom_view,     /**< (I) Tag of the BOMView */
    tag_t         view_type     /**< (I) Tag of the view type of BOMView */
    );

/**
    Retrieves a list of all the revisions of the specified BOMView which have been saved to the database.
*/
extern PS_API int PS_list_bvrs_of_bom_view(
    tag_t         bom_view,     /**< (I) Tag of the BOMView */
    int*          n_bvrs,       /**< (O) Number of revisions of the specified BOMView */
    tag_t**       bvrs          /**< (OF) n_bvrs An array of the tags of the revisions of the BOMView */
    );

/** @} */

/**
    @name BOM View Revision Functions
    @{
*/

/**
    Creates an initial working revision of a BOMView, with no occurrences.
    The BOMView Revision created is made an attribute of the specified parent Item Revision.
    This Item Revision must be a revision of the Item that is the parent of the BOMView.

    @note The new BOMView Revision is not saved, it can be saved to the database using #AOM_save.
    Note that the parent Item Revision is modified and must also be saved.
    The new BOMView Revision must be saved before the parent Item Revision is saved.
    Failure to do so results in the BOMView Revision not being added to the parent.
*/
extern PS_API int PS_create_bvr(
    tag_t         bom_view,         /**< (I) Tag of the BOMView for which the first revision is to be created */
    const char*   revision_name,    /**< (I) Revision name. If NULL or empty string "" is specified,
                                            the default name is used. See also #PS_default_bvr_name. */
    const char*   revision_desc,    /**< (I) A description of the revision (can be NULL) */
    logical       precise,          /**< (I) If true the BOMView Revision can have precise occurrences of child Item Revisions.
                                            If false it can have imprecise occurrence of child Items. */
    tag_t         parent_ir,        /**< (I) The tag of the parent Item Revision of the BOMView Revision */
    tag_t*        bvr               /**< (O) The newly created BOMView Revision */
    );

/**
    Produces a new working BOMViewRevision based on the source BOMViewRevision.
    The new BOMView Revision is made an attribute of the specified parent Item Revision.
    This Item Revision must be a revision of the Item that is the parent of the BOMView
    of which the source BOMView Revision is a revision.

    Whenever an Item Revision is revised, the BOMView Revisions are automatically revised as well,
    rather than being shared between the old and new Item Revisions.
    Because BOMView Revisions are no longer shared between Item Revisions,
    it is no longer necessary to revise BOMView Revisions within the same Item Revision.

    The purpose of this function is to accommodate legacy data from iMAN 3.3 and earlier,
    which can contain shared BOMView Revisions.
    These BOMView Revisions can be revised within the same Item Revision in order to "unshare" them.

    @note Revising an unshared BOMView Revision is not allowed as it would "orphan" the previous revision,
    leaving it unattached to any Item Revision.

    @note The new BOMView Revision is not saved. It can be saved to the database using #AOM_save.
    Note that the parent Item Revision is modified and must also be saved.

    @note The reference to the new BOMView Revision replaces the reference to the old one,
    if the target parent Item Revision already references a revision of this BOMView.
*/
extern PS_API int PS_revise_bvr(
    tag_t         source_bvr,       /**< (I) Tag of the BOMViewRevision to base the new revision on */
    const char*   revision_name,    /**< (I) Revision name. If NULL or empty string "" is specified,
                                            the default name is used. See also #PS_default_bvr_name. */
    const char*   revision_desc,    /**< (I) A description of the revision (can be NULL) */
    tag_t         parent_ir,        /**< (I) Tag of the parent Item Revision of the new BOMView Revision */
    tag_t*        new_bvr           /**< (O) The newly created BOMView Revision */
    );

/**
    Produces a new working BOMViewRevision based on the source BOMViewRevision of a different BOMView.
    The new BOMView Revision is made an attribute of the specified parent Item Revision.
    This Item Revision must be a revision of the Item that is the parent of the target BOMView.

    @note The new BOMView Revision is not saved. It can be saved to the database using #AOM_save.
    Note that the parent Item Revision is modified and must also be saved.

    @note If the target parent Item Revision already references a revision of the specified BOMView,
    the reference to the new BOMView Revision replaces the reference to the old one.
*/
extern PS_API int PS_copy_bvr(
    tag_t         source_bvr,       /**< (I) Tag of the BOMViewRevision to base the new revision on */
    tag_t         bom_view,         /**< (I) Create a new revision of this BOMView */
    const char*   revision_name,    /**< (I) Revision name. If NULL or empty string "" is specified,
                                            the default name is used. See also #PS_default_bvr_name. */
    const char*   revision_desc,    /**< (I) A description of the revision (can be NULL) */
    tag_t         parent_ir,        /**< (I) Tag of the parent Item Revision of the new BOMView Revision */
    tag_t*        new_bvr           /**< (O) The newly created BOMView Revision */
    );

extern PS_API int PS_bvr_translate_mvl(
    tag_t         bvr,              /**< (I) */
    int           n_modules,        /**< (I) */
    char**        from_modules,     /**< (I) n_modules */
    char**        to_modules        /**< (I) n_modules */
    );

/**
    Retrieves a default name for a BOMView Revision.
    The default implementation creates a name of the form "<Item Revision ID>-<view type name>" (e.g., "100/A-Design").

    @note To allow user customization of the default name format,
    this function calls out via the #USER_ps_default_bvr_name user exit.
    The default implementation of this user exit uses the #PS_system_default_bvr_name function to
    generate the default name format as described above.

    @note It is not necessary to call this function to pass a name to #PS_create_bvr,
    #PS_revise_bvr or #PS_copy_bvr as any of those functions will automatically use
    the default name when passed a NULL or empty string ("").
    This function is intended for example to pre-populate a dialog box field with
    a default name for a BOMView Revision to be created.

    @note If the view type argument is #NULLTAG, the user's default view type is used.
*/
extern PS_API int PS_default_bvr_name(
    tag_t         item_revision,    /**< (I) Tag of the Item Revision the new BOMView Revision is to be created for */
    tag_t         view_type,        /**< (I) Tag of the intended type of the BOMView Revision to be created
                                            (if the BOMView already exists then this should be the type of that BOMView). */
    char**        name              /**< (OF) */
    );

/**
    Deletes the specified BOMViewRevision, provided it is not referenced.
*/
extern PS_API int PS_delete_bvr(
    tag_t         bvr   /**< (I) Tag of the BOMView Revision to be deleted */
    );

/**
    Retrieves the tag of the BOMView to which this is a revision.
*/
extern PS_API int PS_ask_bom_view_of_bvr(
    tag_t         bvr,      /**< (I) Tag of the BOMView Revision */
    tag_t*        bom_view  /**< (O) The BOMView of which bvr is revision */
    );

/**
    If "precise" a BOMView Revision can only contain precise occurrences of child Item Revisions.
    Otherwise it is "imprecise" and can only contain imprecise occurrences of child Items.
*/
extern PS_API int PS_ask_is_bvr_precise(
    tag_t         bvr,          /**< (I) Tag of the BOMView Revision */
    logical*      is_precise    /**< (O) True if the BOMView Revision is precise, false if it is imprecise. */
    );

/**
    Lists all of the occurrences of the specified BOMViewRevision.
*/
extern PS_API int PS_list_occurrences_of_bvr(
    tag_t         bvr,              /**< (I) Tag of the BOMView Revision */
    int*          n_occurrences,    /**< (O) Number of occurrences returned */
    tag_t**       occurrences       /**< (OF) n_occurrences The occurrences */
    );

/**
    Lists all the Item Revisions that reference this BOMView Revision.

    @note If this BOMView Revision is referenced by more than one Item Revision,
    then you will not be allowed to modify its structure.
    You must first revise the BOMView Revision in the Item Revision whose structure you want to change.

    @note From V3.4, BOMView Revisions are automatically revised when ItemRevisions are copied.
    This means that new BOMView Revisions will only ever be referenced by a single Item Revision,
    and only pre-V3.4 legacy data will contain shared BOMView Revisions.
*/
extern PS_API int PS_list_owning_revs_of_bvr(
    tag_t         bvr,          /**< (I) Tag of the BOMView Revision */
    int*          n_item_revs,  /**< (O) Number of referencing Item Revisions */
    tag_t**       item_revs     /**< (OF) n_item_revs The Item Revisions */
    );

/**
    Answers true if this BOMView Revision is referenced by more than one Item Revision.

    @note If this BOMView Revision is referenced by more than one Item Revision,
    then you will not be allowed to modify its structure.
    You must first revise the BOMView Revision in the Item Revision whose structure you want to change.

    @note From V3.4, BOMView Revisions are automatically revised when ItemRevisions are copied.
    This means that new BOMView Revisions will only ever be referenced by a single Item Revision,
    and only pre-V3.4 legacy data will contain shared BOMView Revisions.
*/
extern PS_API int PS_ask_is_bvr_shared(
    tag_t         bvr,          /**< (I) Tag of the BOMView Revision */
    logical*      is_shared     /**< (O) True if this BOMView Revision is referenced by more than one Item Revision */
    );

/**
    Retrieves the time/date at which the structure was changed by the change conditions and saved
*/
extern PS_API int PS_ask_struct_modified_date(
    tag_t         bvr,          /**< (I) */
    date_t*       struct_dlm    /**< (O) */
    );

/**
    Retrieves the legacy unit conversion factor for the specified BOMViewRevision.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#PS_invalid_bvr if the @p bvr parameter is not a valid BOMViewRevision.
    <li>#PS_no_legacy_transform_factor if no legacy transform factor is available.
    </ul>
*/
extern PS_API int PS_ask_legacy_transform_factor(
    tag_t         bvr,             /**< (I) Tag of the BVR */
    double*       legacy_factor    /**< (O) The legacy transform factor from the BVR */
    );

/**
    Sets the unit conversion factor for the specified BOMViewRevision.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_invalid_bvr if the @p bvr parameter is not a valid BOMViewRevision.
    <li>Possibly other PS errors
    </ul>
*/
extern PS_API int PS_set_legacy_transform_factor(
    tag_t         bvr,          /**< (I) Tag of the BVR */
    double        legacy_factor /**< (I) The legacy transform factor to be set on the BVR */
    );

/**
    Removes the unit conversion factor for the specified BOMViewRevision.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_invalid_bvr if the @p bvr parameter is not a valid BOMViewRevision.
    <li>Possibly other PS errors
    </ul>
*/
extern PS_API int PS_remove_legacy_transform_factor(
    tag_t         bvr   /**< (I) Tag of the BVR */
    );

/**
    Checks if the Item or Item Revisions is child of BOM View Revision.

    All Item under the imprecise BOM View Revision and Item Revision for precise BOM View Revision are considered as valid if they are referenced
    by any occurrence under respective BOM View Revision.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_invalid_bvr if the @p bvr is #NULLTAG or not a valid BOMViewRevision.
    <li>Possibly other PS errors
    </ul>
*/
extern PS_API int PS_ask_is_child_of_bvr(
    tag_t         bvr,                 /**< (I) The BOMView Revision. */
    tag_t         item_or_revision,    /**< (I) The child Item or Item Revision. */
    logical*      is_child             /**< (O) True if child Item or Item Revision are actually child of the input BOM View Revision. */
    );

/** @} */

/**
    @name PS Occurrence Sequencing
    @{
*/

/**
    Adds a predecessor directly to the occurrence.

    <b>Restrictions:</b>
    Both occ and predecessor share the same parent bvr.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_self_predecessor if the object is the predecessor.
    <li>#PS_pred_rel_exists if this predecessor relationship is already defined.
    <li>#PS_cyclic_pred_structure if that would created a circular precedence relationship.
    </ul>
*/
extern PS_API int PS_add_predecessor(
    tag_t         bvr,          /**< (I) Tag of the parent bvr */
    tag_t         occ,          /**< (I) Tag of the successor occurrence thread */
    tag_t         predecessor   /**< (I) Tag of the predecessor occurrence thread */
   );

/**
    Removes a predecessor directly to the occurrence.

    <b>Restrictions:</b>
    <ol>
    <li>Both occ and predecessor share the same parent bvr.
    <li>predecessor is already a predecessor of occ.
    </ol>
*/
extern PS_API int PS_remove_predecessor(
    tag_t         bvr,          /**< (I) Tag of the parent bvr */
    tag_t         occ,          /**< (I) Tag of the successor occurrence thread */
    tag_t         predecessor   /**< (I) Tag of the predecessor occurrence thread */
   );

/**
    Retrieves a list of the predecessor occurrences directly of the given occurrence.
*/
extern PS_API int PS_list_predecessors(
    tag_t         bvr,      /**< (I) Tag of the parent bvr */
    tag_t         occ,      /**< (I) Tag of the occurrence thread that predecessors are needed for */
    int*          count,    /**< (O) Number of predecessors */
    tag_t**       pred      /**< (OF) count MEM_alloc()ed array of the list of predecessor occurrence thread tags */
   );

/** @} */

/**
    @name PS Occurrence Functions
    @{
*/

/**
    Creates a number of occurrences linking the specified parent BOMView Revision and the child Item / BOMView pairing.

    If the parent BOMView Revision is "precise," child_item must be the tag of a specific Item Revision.

    If the parent BOMView Revision is "imprecise," child_item can be the tag of an Item or an Item Revision.
    If the tag of an Item Revision is given, the occurrence will store a reference to the Item of which it is a revision.

    The BOMView specified must belong to the child Item.
    When multiple views functionality is provided in a future release this will allow differentiation between the views of an item.

    If necessary, this function will load the parent BOMView Revision and lock it for modify.
    Note that this function creates occurrences in the loaded representation of the BOMView Revision only.
    The new occurrences will be stored in the database when the parent BOMView Revision is saved using #AOM_save.
*/
extern PS_API int PS_create_occurrences(
    tag_t         parent,           /**< (I) Tag of the parent BOMView Revision */
    tag_t         child_item,       /**< (I) Tag of the child Item or Item Revision */
    tag_t         child_bom_view,   /**< (I) Tag of the child BOMView */
    int           n_occurrences,    /**< (I) The number of occurrences to be created */
    tag_t**       occurrences       /**< (OF) n_occurrences The created Occurrences */
    );
/**
    Creates a number of occurrences linking the specified parent BOMView Revision and the child Item / BOMView pairing with
    a specific Occurrence Type.
*/
extern PS_API int PS_create_occurrences_with_occ_type(
    tag_t         parent,           /**< (I) Tag of the parent BOMView Revision */
    tag_t         child_item,       /**< (I) Tag of the child Item or Item Revision */
    tag_t         child_bom_view,   /**< (I) Tag of the child BOMView */
    int           n_occurrences,    /**< (I) The number of occurrences to be created */
    tag_t         occType,          /**< (I) Tag of the occurrence type */
    tag_t**       occurrences       /**< (OF) n_occurrences The created Occurrences */
    );

/**
Valites parent, child and occurrnces for PS_create_occurrences and PS_create_occurrences_with_occ_type
*/
extern PS_API int PS_create_occurrences_tag_validation(
    tag_t         parent,           /**< (I) Tag of the parent BOMView Revision */
    tag_t         child_item,       /**< (I) Tag of the child Item or Item Revision */
    int           n_occurrences     /**< (I) The number of occurrences to be created */
    );

/**
    Validate if the parent and the child satisfy occurrence conditions
*/
extern PS_API int PS_verify_occurrence_conditions
(
      tag_t     parent_rev_tag,     /**< (I)   */
      tag_t     child_rev_tag       /**< (I)   */
);
/**
    Deletes the occurrence from its parent BOMView Revision.

    If necessary, this function will load the parent BOMView Revision and lock it for modify.

    @note This function only removes the occurrence from the loaded representation of the BOMView Revision.
    It is not removed from the database until the parent BOMView Revision is saved using function #AOM_save.

    @note Equivalent occurrences referenced by the same tag from other revisions of the
    same parent BOMView are not effected by this deletion.
*/
extern PS_API int PS_delete_occurrence(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence    /**< (I) Tag of the occurrence */
    );

/**
    Sets the occurrence type of an existing occurrence.

    If necessary, this function will load the parent BOMView Revision and lock it for modify.
    Note that this function modifies the occurrence in the loaded representation of the BOMView Revision only.
    The modification will only be propagated to the database when the parent BOMView Revision is saved
    using #AOM_save_with_extensions/#AOM_save_without_extensions. After saving the BOMView Revision, it should be unlocked.
*/
extern PS_API int PS_set_occurrence_type(
    tag_t         parent,           /**< (I) Parent bvr of the occurrence */
    tag_t         occurrence,       /**< (I) Tag of the occurrence thread to ask the type for in the parent bvr */
    const char*   occTypeString     /**< (I) The tag of the occurrence type to be set */
    );

/**
    Asks the occurrence type of an existing occurrence.
*/
extern PS_API int PS_ask_occurrence_type(
    tag_t         parent,           /**< (I) Parent bvr of the occurrence */
    tag_t         occurrence,       /**< (I) Tag of the occurrence thread to ask the type for in the parent bvr */
    char**        occTypeString     /**< (OF) The tag of the occurrence type */
    );

/**
    Inquires the child Item or Item Revision and BOMView of an occurrence.
    If the occurrence has two or more substitutes, the preferred child is returned.

    If the parent BOMViewRevision is "precise," child_item will be the tag of an Item Revision.
    If the parent BOMViewRevision is "imprecise", child_item will be the tag of an Item.
*/
extern PS_API int PS_ask_occurrence_child(
    tag_t         parent,           /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,       /**< (I) Tag of the occurrence */
    tag_t*        child_item,       /**< (O) The child Item or Item Revision referenced by the occurrence */
    tag_t*        child_bom_view    /**< (O) The child BOMView referenced by the occurrence */
    );

/**
    Sets the child Item or Item Revision and BOMView referenced by an occurrence.

    If the parent BOMView Revision is "precise," child_item must be the tag of a specific Item Revision.

    If the parent BOMView Revision is "imprecise," child_item can be the tag of an Item or an Item Revision.
    If the tag of an Item Revision is, the occurrence will store a reference to the Item of which it is a revision.

    The BOMView specified must belong to the child Item.
    When multiple views functionality is provided in a future release this will allow differentiation between the views of an item.

    If necessary this function will load the parent BOMView Revision and lock it for modify.
    Note that this function modifies the occurrence in the loaded representation of the BOMView Revision only.
    The modification will only be propagated to the database when the parent BOMView Revision is saved using #AOM_save.
*/
extern PS_API int PS_set_occurrence_child(
    tag_t         parent,           /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,       /**< (I) Tag of the occurrence */
    tag_t         child_item,       /**< (I) Tag of the child Item or Item Revision referenced by the occurrence */
    tag_t         child_bom_view    /**< (I) Tag of the child BOMView referenced by the occurrence */
    );

/**
    Inquires the sequence number attribute of an occurrence.

    @note Sequence numbers are alphanumeric and are therefore stored as text strings.
*/
extern PS_API int PS_ask_seq_no(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    char**        seq_no        /**< (OF) The sequence number as a string */
    );

/**
    Sets the sequence number of an occurrence.

    @note Sequence numbers are alphanumeric and are therefore stored as text strings.

    If necessary this function will load the parent BOMView Revision and lock it for modify.
    Note that this function modifies the occurrence in the loaded representation of the BOMView Revision only.
    The modification will only be propagated to the database when the parent BOMView Revision is saved using #AOM_save.
*/
extern PS_API int PS_set_seq_no(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    const char*   seq_no        /**< (I) The sequence number as a string */
    );

/**
    Inquires the name attribute of an occurrence

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_invalid_occurrence if the occurrence is invalid
    <li>#PS_no_occurrence_name if the occurrence has no name
    <li>#PS_invalid_bvr if the parent BOMView Revision is invalid
    <li>Possibly other PS errors
    </ul>
*/
extern PS_API int PS_ask_occurrence_name(
    tag_t         parent,           /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,       /**< (I) Tag of the occurrence */
    char**        occurrence_name   /**< (OF) The occurrence name as a string */
    );

/**
    Sets the name attribute of an occurrence

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_invalid_occurrence if the occurrence is invalid
    <li>#PS_invalid_bvr if the parent BOMView Revision is invalid
    <li>Possibly other PS errors
    </ul>
*/
extern PS_API int PS_set_occurrence_name(
    tag_t         parent,           /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,       /**< (I) Tag of the occurrence */
    const char*   occurrence_name   /**< (I) The occurrence name as a string */
    );

/**
    When a bvr is copied to a different view (by #PS_copy_bvr) or to a different item (by item save
    as) then occurrence tags are _not_ carried over, however this value will be preserved between
    equivalent occurrences in the source and new bvr.
*/
extern PS_API int PS_ask_occ_clone_stable_uid(
    tag_t   parent,             /**< (I) */
    tag_t   occurrence,         /**< (I) */
    char**  clone_stable_uid    /**< (OF) */
    );

/**
    Inquires the attribute RefDesignator of an occurrence.
*/
extern PS_API int PS_ask_occurrence_ref_designator(
    tag_t         parentBVR,         /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occThread,         /**< (I) Tag of the occurrence */
    char**        refDesignator      /**< (OF) The RefDesignator attribute of the occurrence */
    );

/**
    Inquires the attribute RefDesignator of an occurrence.
*/
extern PS_API int PS_set_occurrence_ref_designator(
    tag_t         parentBVR,         /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occThread,      /**< (I) Tag of the occurrence */
    const char    *refDesignator  /**< (I) RefDesignator attribute of the occurrence */
    );

/**
    Inquires the attribute quantity of an occurrence.

    A negative quantity means "quantity undefined." This is the initial state for newly created occurrences.

    Note that a quantity of "as required" can be recorded on an occurrence by
    setting the #PS_qty_as_required occurrence flag.
    See also #PS_ask_occurrence_flag and #PS_set_occurrence_flag.
*/
extern PS_API int PS_ask_occurrence_qty(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    double*       qty           /**< (O) The quantity attribute of the occurrence */
    );

/**
    Sets the quantity attribute of an occurrence. A negative quantity means "quantity undefined."

    Note that a quantity of "as required" can be recorded on an occurrence by
    setting the #PS_qty_as_required occurrence flag. See also #PS_ask_occurrence_flag and #PS_set_occurrence_flag.

    If necessary, this function will load the parent BOMView Revision and lock it for modify.
    Note that this function modifies the occurrence in the loaded representation of the BOMView Revision only.
    The modification will only be propagated to the database when the parent BOMView Revision is saved using #AOM_save.
*/
extern PS_API int PS_set_occurrence_qty(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    double        qty           /**< (I) A new quantity value for the occurrence */
    );

/**
    Inquires the state (true or false) of a flag attribute of an occurrence.
    Currently, only one flag attribute, #PS_qty_as_required, is implemented.
    If set, this occurrence indicates the child Item it references is to be used as required.
    This interface is intended to support the addition of new flag attributes in the future.
*/
extern PS_API int PS_ask_occurrence_flag(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    int           flag,         /**< (I) Integer value defined in ps_tokens.h that identifies the flag.
                                        Currently, #PS_qty_as_required is the only flag supported. */
    logical*      is_set        /**< (O) @c true if the flag is set, otherwise @c false */
    );

/**
    Sets a flag attribute of an occurrence. Currently, only one flag attribute is implemented, #PS_qty_as_required.
    If set, this occurrence indicates the child Item it references is to be used as required.
    This interface is intended to support the addition of new flag attributes in the future.

    @note To clear the flag, use #PS_clear_occurrence_flag.

    If necessary, this function will load the parent BOMView Revision and lock it for modify.
    Note that this function modifies the occurrence in the loaded representation of the BOMView Revision only.
    The modification will only be propagated to the database when the parent BOMView Revision is saved using #AOM_save.
*/
extern PS_API int PS_set_occurrence_flag(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    int           flag          /**< (I) Integer value defined in ps_tokens.h that identifies the flag.
                                        Currently, #PS_qty_as_required is the only flag supported. */
    );

/**
    Clears a flag attribute of an occurrence. Currently, only one flag attribute is implemented, #PS_qty_as_required.
    If set, this occurrence indicates the child Item it references is to be used as required.
    This interface is intended to support the addition of new flag attributes in the future.

    @note To set the flag, use #PS_set_occurrence_flag.

    If necessary, this function will load the parent BOMView Revision and lock it for modify.
    Note that this function modifies the occurrence in the loaded representation of the BOMView Revision only.
    The modification will only be propagated to the database when the parent BOMView Revision is saved using #AOM_save.
*/
extern PS_API int PS_clear_occurrence_flag(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    int           flag          /**< (I) Integer value defined in ps_tokens.h that identifies the flag.
                                        Currently, #PS_qty_as_required is the only flag supported. */
    );

/**
    Retrieves and sets the PLM XML format transform.

    Retrieves the PLM XML transform of the specified occurrence.
    If no transform is set #PS_no_transform is returned.
    If both an PLM XML transform and a legacy transform are found, #PS_two_transforms is returned.
    If the occurrence only has a legacy transform, #PS_has_old_transform_only is returned.
*/
extern PS_API int PS_ask_plmxml_transform(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    double**      transform     /**< (OF) 16 A pointer to an MEM_alloc()ed array holding 16 doubles, which
                                represent a PLM XML format 4X4 transform matrix. The transform matrix looks like
                                [ R R R T ]         * 'R' is the rotation part;
                                [ R R R T ]         * 'T' is the transform vector;
                                [ R R R T ]         * 'P' is the perspective part;
                                [ P P P S ]         * 'S' is the inverse scale;
                                The components of the transform are specified as the following ( column order):
                                R R R P R R R P R R R P T T T S. With regards to mixed units, Transforms are always in
                                the units of the parent, not the child to which they're applied. In PLM XML, when the
                                attribute type=scale specified on Transform element, it takes priority over the entry 'S' above.
                                More information about PLM XML Transform definition can be found on
                                http://www.plm.automation.siemens.com/en_us/products/open/plmxml/schemas.shtml
                                */
    );

/**
    Retrieves and sets the PLM XML format transform.

    If the legacy factor is set,
    or the site preference PS_allow_plmxml_transforms_with_no_legacy_transform_factor is set to "Yes",
    this function sets the specified PLM XML transform for the given occurrence and removes the legacy transform.
    If this preference is set to "No" and there is no legacy factor, #PS_no_legacy_transform_factor is returned.
    If a null pointer is passed, both legacy and PLM XML transforms are removed if they exist.
    If the preference is not present or set to an unspecified value,
    #PS_allow_plmxml_pref_invalid is returned regardless of the presence of any stored transforms or the legacy factor.
    If necessary, this function will load the parent BOMView Revision and lock it for modify.
    Note that this function modifies the occurrence in the loaded representation of the BOMView Revision only.
    The modification will only be propagated to the database when the parent BOMView Revision is saved using #AOM_save.

    <b>Return Values:</b>

    #PS_allow_plmxml_pref_invalid - The PS_allow_plmxml_transforms_with_no_legacy_transform_factor preference is not valid.
*/
extern PS_API int PS_set_plmxml_transform(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    double*       transform     /**< (I) 16 A pointer to an array of 16 doubles representing a PLM XML format 4x4 transform matrix.
                                The transform matrix looks like
                                        [ R R R T ]         * 'R' is the rotation part;
                                        [ R R R T ]         * 'T' is the transform vector;
                                        [ R R R T ]         * 'P' is the perspective part;
                                        [ P P P S ]         * 'S' is the inverse scale;
                                The components of the transform are specified as the following ( column order):
                                R R R P R R R P R R R P T T T S. With regards to mixed units, Transforms are always in
                                the units of the parent, not the child to which they're applied. In PLM XML, when the
                                attribute type=scale specified on Transform element, it takes priority over the entry 'S' above.
                                More information about PLM XML Transform definition can be found on
                                http://www.plm.automation.siemens.com/en_us/products/open/plmxml/schemas.shtml
                                */
    );

/**
    Converts transforms from legacy to PLM XML format.

    This function generates the PLM XML transform for the specified occurrence and parent BOMView Revision.
    This function attempts to convert an existing old style transform,
    which must be in the correct "Legacy" format, to the corresponding PLM XML format transform.
    If necessary, the value of the PS_assume_legacy_transform_units preference is taken as the units of the parent.
    The value #PS_transform_units_pref_invalid is returned if this preference is invalid.
    If the occurrence already has a PLM XML format transform associated with it,
    #PS_already_plmxml_transform is returned, or if no conversion is possible,
    #PS_could_not_convert_transform is returned.

    <b>Return Values:</b>

    <table>
    <tr><td>#PS_already_plmxml_transform</td>    <td>The occurrence already has an PLM XML transform on it.</td></tr>
    <tr><td>#PS_no_transform</td>                <td>No legacy transform is found.</td></tr>
    </table>
*/
extern PS_API int PS_convert_legacy_transform(
    tag_t         parent,           /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,       /**< (I) Tag of the occurrence */
    double**      ext_transform     /**< (OF) 16 A pointer to an SM array of 16 doubles representing a PLM XML format 4x4 transform matrix
                                    or a null pointer if the conversion can't be done. The transform matrix looks like
                                        [ R R R T ]         * 'R' is the rotation part;
                                        [ R R R T ]         * 'T' is the transform vector;
                                        [ R R R T ]         * 'P' is the perspective part;
                                        [ P P P S ]         * 'S' is the inverse scale;
                                    The components of the transform are specified as the following ( column order):
                                    R R R P R R R P R R R P T T T S. With regards to mixed units, Transforms are always in
                                    the units of the parent, not the child to which they're applied. In PLM XML, when the
                                    attribute type=scale specified on Transform element, it takes priority over the entry 'S' above.
                                    More information about PLM XML Transform definition can be found on
                                    http://www.plm.automation.siemens.com/en_us/products/open/plmxml/schemas.shtml
                                    */
    );

/**
    By default the occurrences of a BOMView Revision are listed in the order in which they were created.
    This sequence can be altered via #PS_move_occurrence_to, #PS_move_occurrence_up and #PS_move_occurrence_down.

    This function moves the specified occurrence to be the new_index in the occurrences of
    its parent BOMView Revision (starting from zero).

    If necessary this function will load the parent BOMView Revision and lock it for modify.
    Note that this function modifies the occurrence in the loaded representation of the BOMView Revision only.
    The modification will only be propagated to the database when the parent BOMView Revision is saved using #AOM_save.
*/
extern PS_API int PS_move_occurrence_to(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    int           new_index     /**< (I) New ordering index number for the occurrence within the
                                        set of occurrences belonging to the parent BOMView Revision */
    );

/**
    By default, the occurrences of a BOMView Revision are listed in the order in which they were created.
    This sequence can be altered via #PS_move_occurrence_to, #PS_move_occurrence_up and #PS_move_occurrence_down.

    This function moves the specified occurrence one place up (i.e., towards the front of the list)
    in the occurrences of its parent BOMView Revision.

    If necessary, this function will load the parent BOMView Revision and lock it for modify.
    Note that this function modifies the occurrence in the loaded representation of the BOMView Revision only.
    The modification will only be propagated to the database when the parent BOMView Revision is saved using #AOM_save.
*/
extern PS_API int PS_move_occurrence_up(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence    /**< (I) Tag of the occurrence */
    );

/**
    By default, the occurrences of a BOMView Revision are listed in the order in which they were created.
    This sequence can be altered via #PS_move_occurrence_to, #PS_move_occurrence_up and #PS_move_occurrence_down.

    This function moves the specified occurrence one place down (i.e., towards the end of the list)
    in the occurrences of its parent BOMView Revision.

    If necessary, this function will load the parent BOMView Revision and lock it for modify.
    Note that this function modifies the occurrence in the loaded representation of the BOMView Revision only.
    The modification will only be propagated to the database when the parent BOMView Revision is saved using #AOM_save.
*/
extern PS_API int PS_move_occurrence_down(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence    /**< (I) Tag of the occurrence */
    );

/**
    An occurrence can have textual notes attached to it.
    Each note has a note type, which identifies the purpose of that note (e.g., "usage", "color").
    An occurrence can have any number of notes, as long as each note is of a different note type.
    Note types are defined for a Teamcenter installation by the Teamcenter system administrator.

    This function returns a list of the notes attached to the specified occurrence.
    Each note is identified by the tag of its note type. The note text can be found using #PS_ask_occurrence_note_text.
*/
extern PS_API int PS_list_occurrence_notes(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    int*          n_notes,      /**< (O) The number of notes attached to this occurrence */
    tag_t**       note_types    /**< (OF) n_notes An array of the tags of the note type of
                                        each note attached to this occurrence */
    );

/**
    An occurrence can have textual notes attached to it. Each note has a note type,
    which identifies the purpose of that note (e.g., "usage", "color").
    An occurrence can have any number of notes, as long as each note is of a different note type.
    Note types are defined for a Teamcenter installation by the Teamcenter system administrator.

    This function returns the text of a note of the specified note type attached to the specified occurrence.
*/
extern PS_API int PS_ask_occurrence_note_text(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    tag_t         note_type,    /**< (I) Tag of the note type */
    char**        text          /**< (OF) The text of the specified note */
    );

/**
    An occurrence can have textual notes attached to it. Each note has a note type,
    which identifies the purpose of that note (e.g., "usage," "color").
    An occurrence can have any number of notes, as long as each note is of a different note type.
    Note types are defined for a Teamcenter installation by the Teamcenter system administrator.

    This function sets the text of a note of the specified note type attached to the specified occurrence.
    If the occurrence does not currently have a note of this type then one is created.
    If the occurrence does already have a note of this type then its text is overwritten with this new string.

    If necessary this function will load the parent BOMView Revision and lock it for modify.
    Note that this function modifies the occurrence in the loaded representation of the BOMView Revision only.
    The modification will only be propagated to the database when the parent BOMView Revision is saved using #AOM_save.
*/
extern PS_API int PS_set_occurrence_note_text(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    tag_t         note_type,    /**< (I) Tag of the note type */
    const char*   text          /**< (I) A text string for the note */
    );

/**
    An occurrence can have textual notes attached to it. Each note has a note type,
    which identifies the purpose of that note (e.g., "usage," "color").
    An occurrence can have any number of notes, as long as each note is of a different note type.
    Note types are defined for a Teamcenter installation by the Teamcenter system administrator.

    This function deletes a note of the specified note type attached to the specified occurrence.

    If necessary, this function will load the parent BOMView Revision and lock it for modify.
    Note that this function modifies the occurrence in the loaded representation of the BOMView Revision only.
    The modification will only be propagated to the database when the parent BOMView Revision is saved using #AOM_save.
*/
extern PS_API int PS_delete_occurrence_note(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    tag_t         note_type     /**< (I) Tag of the note type */
    );

/** @} */

/**
    @name PS Substitutes Functions
    @{
*/

/**
    Retrieves a list of all substitutes for the specified occurrence.

    The child of a 'regular' occurrence is defined by a pair of tags,
    one is the Item or Item Revision (which depends on the parent BOMViewRevision being imprecise or precise),
    the other is a BOMView of the child Item/rev.
    The BOMView may be #NULLTAG presently,
    in the future this will be used to distinguish between multiple views of the same Item.

    V3.2 Substitutes allows a list of substitute children to be attached to a single occurrence.
    This list therefore contains pairs of Item/rev and BOMView tags.

    This function returns the Item/rev and BOMView tags on two MEM_alloc()ed arrays.
    An Item/rev tag from one array and the BOMView tag from the same position on the second array
    therefore defines one substitute child.

    If the occurrence has no substitutes, this function returns with n_substitutes equal to zero.
*/
extern PS_API int PS_list_substitutes(
    tag_t         parent,           /**< (I) Tag of the parent BOMView Revision */
    tag_t         occurrence,       /**< (I) Tag of the occurrence */
    int*          n_substitutes,    /**< (O) Number of substitute children */
    tag_t**       sub_items,        /**< (OF) n_substitutes List of substitute Item/Item Revisions */
    tag_t**       sub_views         /**< (OF) n_substitutes List of BOMViews */
    );

/**
    Retrieves true if the specified occurrence has two or more substitute children.
*/
extern PS_API int PS_ask_has_substitutes(
    tag_t         parent,           /**< (I) Tag of the parent BOMView Revision */
    tag_t         occurrence,       /**< (I) Tag of the occurrence */
    logical*      has_substitutes   /**< (O) Whether the occurrence has substitutes */
    );

/**
    Adds the specified Item or Item Revision / BOMView pair as a substitute child for the specified occurrence.
    If the occurrence has no substitutes already, the existing child becomes the preferred substitute.

    In future, the BOMView will be used to distinguish between multiple views of the same Item,
    but currently #NULLTAG can be used.
*/
extern PS_API int PS_add_substitute(
    tag_t         parent,           /**< (I) Tag of the parent BOMView Revision */
    tag_t         occurrence,       /**< (I) Tag of the occurrence */
    tag_t         child_item,       /**< (I) Tag of the child Item or Item Revision */
    tag_t         child_bom_view    /**< (I) Tag of the child BOMView */
    );

/**
    Removes the specified non-preferred substitute from the list of substitutes for this occurrence.
    This will not remove the preferred substitute, so in order to remove the preferred substitute,
    a different substitute must be preferred first.
*/
extern PS_API int PS_delete_substitute(
    tag_t         parent,       /**< (I) Tag of the parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    tag_t         child_item    /**< (I) Tag of the child Item or Item Revision */
    );

/**
    Makes the specified substitute the preferred substitute for the occurrence.
    This means it is the child that is given by default, e.g. when you call #PS_ask_occurrence_child.

    If the parent BOMView Revision is write protected or frozen,
    the change to which substitute is preferred is made in the loaded copy only,
    and cannot be saved to the database. In this case is_temporary is set to true.
*/
extern PS_API int PS_prefer_substitute(
    tag_t         parent,       /**< (I) Tag of the parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    tag_t         child_item,   /**< (I) Tag of the child Item or Item Revision */
    logical*      is_temporary  /**< (O) Flag whether the change can be saved */
    );

/** @} */

/**
    @name PS Variants

    The variant data is a pointer to a variant_expression block
    (see bom.h for routines to manipulate it)
    An occurrence may have either variant data or substitutes, but
    not both. It is an error to attempt to set the one if the
    occurrence currently has the other defined
    @{
*/

/**
    Retrieves a logical value to say whether this occurrence holds variant data (i.e., is subject to a variant condition).
*/
extern PS_API int PS_ask_has_variant_data(
    tag_t         parent,           /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,       /**< (I) Tag of the occurrence */
    logical*      has_variant_data  /**< (O) @c true if the occurrence holds variant data, @c false otherwise. */
    );

/**
    Retrieves the tag of a variant expression block which describes the variant condition that applies to this occurrence.
    If the occurrence has no variant data defined, then #NULLTAG is returned.
*/
extern PS_API int PS_ask_variant_data(
    tag_t         parent,                   /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,               /**< (I) Tag of the occurrence */
    tag_t*        variant_expression_block  /**< (O) POM object holding the variant condition.
                                                    Go to bom.h for routines to manipulate a variant expression block. */
    );

/**
    Sets the variant condition for this occurrence to be the specified variant expression block.
    To clear the variant condition, call this routine passing in a #NULLTAG value.
*/
extern PS_API int PS_set_variant_data(
    tag_t         parent,                   /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,               /**< (I) Tag of the occurrence */
    tag_t         variant_expression_block  /**< (I) POM object holding the variant condition.
                                                    Go to bom.h for routines to manipulate a variant expression block. */
    );

/**
    Loads all the variant expressions in the given set of variant expression blocks (if they are not
    already loaded). The force_sub_expr_check argument should be used if you've already loaded the
    root expressions (to check the opcodes for example).
*/
extern PS_API int PS_load_variant_expr_blocks(
    int           n_blocks,                  /**< (I) Number of variant expression blocks to load */
    tag_t *       variant_expression_blocks, /**< (I) n_blocks Tags of variant expression blocks to load */
    logical       force_sub_expr_check       /**< (I) Check that the first level sub-expressions are loaded too */
    );

/**
    Loads the given set of variant expressions (if they are not already loaded). The
    force_sub_expr_check argument should be used if you've already loaded the root
    expressions (to check the opcodes for example).
*/
extern PS_API int PS_load_variant_exprs(
    int           n_exprs,                   /**< (I) Number of variant expressions to load */
    tag_t *       variant_expressions,       /**< (I) n_blocks Tags of variant expressions to load */
    logical       force_sub_expr_check       /**< (I) Check that the first level sub-expressions are loaded too */
    );

/** @} */

/**
    @name PS Object Functions
    @{
*/

/**
    Adds an extra attribute to a PS class. This extra attribute must be a reference to a POM object.
    The type of the reference is the specified class.

    @note This function can only be called by a user with Teamcenter system administrator privilege.
*/
extern PS_API int PS_define_client_data(
    int           ps_class,     /**< (I) Token identifying the class of PS object to which this attribute is to be attached */
    const char*   attr_name,    /**< (I) Name of the attribute */
    tag_t         ref_class,    /**< (I) Tag of the POM class which this attribute is to reference */
    int           property      /**< (I) The attribute can have its property set to #PS_copyable,
                                        in which case this attribute is copied from one revision of the object to another.

                                        Client data attributes can be added to the classes #PS_bom_view,
                                        #PS_bom_view_revision, #PS_occurrence and #PS_view_type.
                                        Property #PS_copyable is only applicable to #PS_bom_view_revision and #PS_occurrence. */
    );

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
 extern "C"{
#endif

/**
    Remove definition of client data attribute. Only possible if attribute has not been populated.
*/
extern PS_API int PS_delete_client_data_defn(
    int           ps_class,     /**< (I) */
    const char*   attr_name     /**< (I) */
    );

/**
    Describes an attribute of a PS class. The class and property of the attribute are returned.

    The attribute name must be one that has previously been defined using #PS_define_client_data.
*/
extern PS_API int PS_describe_client_data(
    int           ps_class,     /**< (I) Token identifying the class of PS object to which this attribute is to be attached */
    const char*   attr_name,    /**< (I) Name of the attribute */
    tag_t*        ref_class,    /**< (O) Tag of the POM class which this attribute is to reference */
    int*          property      /**< (O) The attribute property that is returned will have a value of
                                        either #PS_copyable (the attribute will copied with the instance)
                                        or #PS_manage (all operations on the instance are
                                        automatically applied to the property). */
    );

/**
    Retrieves the client data attributed to the instance for the specified attribute name.
    The client data will be a tag of a POM object.

    @note This function is used to inquire about client data of all PS classes (except occurrence).
    Occurrences are referenced using a parent BOMView Revision,
    thus occurrence pairing a separate interface function #PS_ask_occurrence_client_data
    is provided to inquire about client data of an occurrence.
*/
extern PS_API int PS_ask_client_data(
    tag_t         instance,     /**< (I) Tag of an instance of a PS class */
    const char*   attr_name,    /**< (I) Name of the attribute to be retrieved */
    tag_t*        client_data   /**< (O) A POM object.
                                        <br/>If no client data is attached to this attribute of the occurrence,
                                        #NULLTAG is returned. */
    );

/**
    Sets the client data attributed to the instance for the specified attribute name.
    The client data must be a tag of a POM object of the class specified in the definition of this attribute.
    See also #PS_define_client_data.

    This function is also used to clear an attribute, in which case #NULLTAG is passed in place of the client data tag.

    @note This function is used for setting client data of all PS classes except occurrence.
    As occurrences are referenced using a parent BOMView Revision,
    occurrence pairing a separate interface function #PS_ask_occurrence_client_data
    is provided to set the client data of an occurrence.
*/
extern PS_API int PS_set_client_data(
    tag_t         instance,     /**< (I) Tag of an instance of a PS class */
    const char*   attr_name,    /**< (I) Name of the attribute to be retrieved */
    tag_t         client_data   /**< (I) Tag of a POM object, or #NULLTAG to clear the attribute. */
    );

/** @} */

/**
    Retrieves the client data attributed to the occurrence for the specified attribute name.
    The client data is a tag of a POM object.
*/
extern PS_API int PS_ask_occurrence_client_data(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    const char*   attr_name,    /**< (I) Name of the attribute to be retrieved */
    tag_t*        client_data   /**< (O) */
    );

/**
    Sets the client data attributed to the occurrence for the specified attribute name.
    The client data must be a tag of a POM object of the class specified in the definition of this attribute.
    See also #PS_define_client_data.

    This function is also used to clear an attribute of an occurrence,
    in which case #NULLTAG is passed in place of the client data tag.
*/
extern PS_API int PS_set_occurrence_client_data(
    tag_t         parent,       /**< (I) Tag of the occurrence's parent BOMView Revision */
    tag_t         occurrence,   /**< (I) Tag of the occurrence */
    const char*   attr_name,    /**< (I) Name of the attribute being set */
    tag_t         client_data   /**< (I) Tag of a POM object, or #NULLTAG to clear the attribute */
    );

/**
    @name PS Note Type Functions
    @{
*/

/**
    Retrieves the list of note types valid for this site.
*/
extern PS_API int PS_note_type_extent(
    int*          n_note_types,     /**< (O) Number of note types in the list */
    tag_t**       note_types        /**< (OF) n_note_types Returned array of tags of note types */
    );

/**
    Retrieves the tag of the note type with the specified name.
*/
extern PS_API int PS_find_note_type(
    const char*   name,         /**< (I) Name of the note type */
    tag_t*        note_type     /**< (O) The note type */
    );

/**
    Retrieves the name of a note type.
*/
extern PS_API int PS_ask_note_type_name(
    tag_t         note_type,    /**< (I) Tag of the note type */
    char**        name          /**< (OF) The name of the note type */
    );

/**
    Retrieves the description of a note type.
*/
extern PS_API int PS_ask_note_type_description(
    tag_t         note_type,    /**< (I) Tag of the note type */
    char**        description   /**< (OF) The description of the note type */
    );

/**
    Retrieves the default value of the note type
*/
extern PS_API int PS_ask_note_type_default_value(
    tag_t         note_type,        /**< (I) Tag of the note type */
    char**        default_value     /**< (OF) The default value of the note type */
    );

/** @} */

/**
    @name PS Where Used Functions
    @{
*/

/**
    Retrieves the list of all Item Revision and occurrence groups having structure which references the specified
    Item Revision:
    <ul>
    <li>either with a precise reference to the Item Revision itself,
    <li>or via an imprecise reference to the Item of which it is a revision.
    </ul>
    The following figure shows a where used tree structure to illustrate the result of a where used search on 6413/C.

    @image html psfi01.gif

    Calling a where used function on Item Revision 6413/C in the above example will return the following arrays:

    <table>
    <tr><td>index</td><td>level</td><td>parent</td></tr>
    <tr><td>0</td>    <td>1</td>    <td>6628/A</td></tr>
    <tr><td>1</td>    <td>2</td>    <td>8128/A</td></tr>
    <tr><td>2</td>    <td>2</td>    <td>6880/D</td></tr>
    <tr><td>3</td>    <td>3</td>    <td>5605/C</td></tr>
    <tr><td>4</td>    <td>3</td>    <td>6807/A</td></tr>
    <tr><td>5</td>    <td>4</td>    <td>5955/A</td></tr>
    <tr><td>6</td>    <td>3</td>    <td>4899/A</td></tr>
    <tr><td>7</td>    <td>4</td>    <td>5955/A</td></tr>
    <tr><td>8</td>    <td>1</td>    <td>4064/A</td></tr>
    <tr><td>9</td>    <td>2</td>    <td>5546/B</td></tr>
    <tr><td>10</td>   <td>3</td>    <td>3336/A</td></tr>
    </table>

    Note that as 5955/A includes two different sub-assemblies both of which ultimately use 6413/C,
    5955/A appears twice to indicate the different paths through the usage tree.

    <br/>To extract 'top-level-only' results from a where used, you need to do the following:
    <ol>
    <li>Call the appropriate where used function (#PS_where_used_all, #PS_where_used_precise, or
       #PS_where_used_configured) passing n_levels=#PS_where_used_all_levels to give you where used
       at all levels</li>
    <li>Process this result to identify only those entries that are 'top level'. If a particular
       entry is _not_ a top level, then you expect the following entry to have a value of level one
       greater than this one. So, it follows that if the following entry has a value of level that
       is _not_ one greater than the current one, or (special case) it's the last entry on the
       array, then that must be a top level.
    So for example this could be coded as:
    @code
    PS_where_used_all( item_revision, PS_where_used_all_levels, &n_parents, &levels, &parents );
    int  index;
    for ( index = 0; index < n_parents; index++ )
    {
        if ( index == n_parents - 1  ||  levels[index] >= levels[index+1] )
        {
            //  parents[index] is a top level item rev.
            //  Display result or whatever.
        }
        else
        {
            //  Not a top level so ignore.
        }
    }
    @endcode
    </li>
    </ol>
*/
extern PS_API int PS_where_used_all(
    tag_t         target,           /**< (I) The object whose parents are sought. */
    int           n_levels,         /**< (I) Depth of search. #PS_where_used_all_levels means
                                            report all grandparents up to top level products
                                            (for example, those assemblies which are not part of any larger assembly). */
    int*          n_parents,        /**< (O) Total number of parent Item Revisions found. */
    int**         levels,           /**< (OF) n_parents Array containing the level of each parent found,
                                            starting from 1 for an immediate parent of the specified Item Revision. */
    tag_t**       parents           /**< (OF) n_parents Array of tags of Occurrence Groups and/or Item Revisions (if @p target is an Occurrence Group), or
                                            only Item Revisions (if @p target is an Item Revision). */
    );

/**
    Retrieves a list of all the Item Revisions having structure with a precise reference to the specified Item Revision.
*/
extern PS_API int PS_where_used_precise(
    tag_t         target_tag,       /**< (I) Tag of the object whose parents are sought */
    int           n_levels,         /**< (I) Depth of search. #PS_where_used_all_levels means
                                            report all grandparents up to top level products
                                            (for example, those assemblies which are not part of any larger assembly). */
    int*          n_parents,        /**< (O) Total number of parent Item Revisions found */
    int**         levels,           /**< (OF) n_parents Array containing the level of each parent found,
                                            starting from 1 for an immediate parent of the specified Item Revision */
    tag_t**       parents           /**< (OF) n_parents Array of tags of occ grps and/or item revs if target_tag is occ grp,
                                            else only item revs if target_tag is Item Revision*/
    );

/**
    Retrieves a list of all the Item Revisions having structure which references the specified Item Revision,
    in the context of the specified Revision Rule.

    NOTE: If preference PS_wu_configd_imprecise_only is set to true, and the specified Revision Rule
    contains only non-precise entries, referencing Item Revisions which are not themselves
    configured by the Revision Rule will be omitted.
*/
extern PS_API int PS_where_used_configured(
    tag_t         target_tag,       /**< (I) Tag of the object whose parents are sought */
    tag_t         rev_rule,         /**< (I) Tag of the Revision Rule */
    int           n_levels,         /**< (I) Depth of search. #PS_where_used_all_levels means
                                            report all grandparents up to top level products
                                            (for example, those assemblies which are not part of any larger assembly). */
    int*          n_parents,        /**< (O) The total number of parent Item Revisions found */
    int**         levels,           /**< (OF) n_parents Array containing the level of each parent found,
                                            starting from 1 for an immediate parent of the specified Item Revision */
    tag_t**       parents           /**< (OF) n_parents Array of tags of occ grps and/or item revs if target_tag is occ grp,
                                            else only item revs if target_tag is Item Revision*/
    );

/** @} */

/**
    Creates the system default name for a BOMView.
    The name is of the form "<Item ID>-<view type name>" (e.g., 100-Design).

    @note This function is called by the default implementation of the #USER_ps_default_bom_view_name user exit.
    It should only ever be required for customizing versions of this user exit.
    It should never be called directly to create a BOMView name;
    #PS_default_bom_view_name should be used instead.

    @note If the view type argument is #NULLTAG, the user's default view type is used.
*/
extern PS_API int PS_system_default_bom_view_name(
    tag_t         item,         /**< (I) Tag of the Item the new BOMView is to be created for */
    tag_t         view_type,    /**< (I) Tag of the intended type of the BOMView to be created */
    char**        name          /**< (OF) */
    );

/**
    Creates the system default name for a BOMView Revision.
    The name is of the form "<Item Revision ID>-<view type name>", e.g. "100/A-Design."

    @note This function is called by the default implementation of the user exit #USER_ps_default_bvr_name.
    It should only ever be required for customizing versions of this user exit.
    It should never be called directly to create a BOMView Revision name;
    #PS_default_bvr_name should be used instead.

    @note If the view type argument is #NULLTAG, the user's default view type is used.
*/
extern PS_API int PS_system_default_bvr_name(
    tag_t         item_revision,    /**< (I) Tag of the Item Revision of the BOMView Revision */
    tag_t         view_type,        /**< (I) Tag of the view type of the BOMView Revision */
    char**        name              /**< (OF) */
    );

/**
    Retrieves whether UG dataset has attached form.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly some PS errors
    </ul>
*/
extern PS_API int PS_has_form_attached_to_ug_dataset(
    tag_t         item_rev,     /**< (I) */
    logical*      result        /**< (O) */
    );

/**
    Retrieves the occurrence threads and child items that are related with the
    given occurrence thread and child item

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_invalid_occurrence if the occurrence is invalid
    <li>Possibly other PS errors
    </ul>
*/
extern PS_API int PS_list_related_substitutes(
    tag_t    occurrence,     /**< (I)  Tag of the occurrence */
    tag_t    sub_item,       /**< (I)  Tag of the substitute item */
    int      *n_items,       /**< (O)  Number of related substitute items */
    tag_t    **related_occs, /**< (OF) n_items Array of related occurrences */
    tag_t    **related_items /**< (OF) n_items Array of related substitutes */
);

/**
    Relates the substitutes by creating the relation between selected occurrence threads

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly some PS errors
    </ul>
*/
extern PS_API int PS_add_related_substitutes(
    int      n_items,        /**< (I) Number of substitute items */
    tag_t    *occurrences,   /**< (I) Array of occurrence */
    tag_t    *sub_items,     /**< (I) Array of substitute items */
    tag_t    *substitute_set /**< (O) Array of related substitutes */
);

/**
    Removes the relation between given substitute items which are passed in as Occurrence threads
    and Child Items.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly some PS errors
    </ul>
*/
extern PS_API int PS_remove_related_substitutes(
    int      n_items,        /**< (I)  Number of related substitute items */
    tag_t    *occurrences,   /**< (I)  Array of related occurrence */
    tag_t    *sub_items      /**< (I)  Array of related substitute items */
);

/**
    Converts the separate delete and add operations into a single replacement operation during BOM comparison,
    deletes an item or part and subsequently add another item or part in the product structure.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_invalid_bvr if the new BOM View Revision is invalid
    <li>#PS_invalid_view_type if new view type is different from old view type
    <li>#PS_invalid_item if the new item is different from the old item
    <li>Possibly other PS errors
    </ul>
*/
extern PS_API int PS_change_to_replace(
    tag_t oldBvr,       /**< (I) BOM View Revision tag of left window */
    tag_t oldOccTag,    /**< (I) Occurrence thread tag of left window */
    tag_t newBvr,       /**< (I) BOM View Revision tag of right window */
    tag_t newOccTag     /**< (I) Occurrence thread tag of right window */
);
/**
    Generates next sequence number for the PS BOMView Revision.

    @note This function is called by the the user exit #USER_ask_new_seqno/USER_ask_for_new_sequence_no.
    the child item parameter need to be passed if user has preference PS_new_seqno_mode = existing
    otherwise just pass the NULLTAG to generate a new sequence number.- default behaviour.
*/
extern PS_API int PS_bvr_ask_default_next_seq_no(
    tag_t         bvr,          /**< (I)  BOM View Revision tag */
    tag_t         child_item,   /**< (I) child item tag  */
    char**        seq_no        /**< (OF) The sequence number as a string */
    );

/**
    @name PS Unified Occurrence Effecivity Functions
    @{
*/

/**
    Creates a new occurrence effectivity.

    If necessary, this function will load the parent BOMView Revision and lock it for modify.
    Note that this function modifies the occurrence in the loaded representation of the BOMView Revision only.
    The modification will only be propagated to the database when the parent BOMView Revision is saved
    using #AOM_save_with_extensions/#AOM_save_without_extensions. After saving the BOMView Revision, it should be unlocked.
*/
extern PS_API int PS_occ_eff_create(
    tag_t   bvr,         /**< (I) Parent BVR of occurrence */
    tag_t   occ,         /**< (I) Occurrence to attach effectivity to */
    tag_t * eff          /**< (O) The newly created occurrence effectivity */
    );

/**
    Adds an existing effectivity object to an occurrence.

    If necessary, this function will load the parent BOMView Revision and lock it for modify.
    Note that this function modifies the occurrence in the loaded representation of the BOMView Revision only.
    The modification will only be propagated to the database when the parent BOMView Revision is saved
    using #AOM_save_with_extensions/#AOM_save_without_extensions. After saving the BOMView Revision, it should be unlocked.
*/
extern PS_API int PS_occ_eff_add_eff(
    tag_t    bvr,           /**< (I) Parent BVR of occurrence */
    tag_t    occ,           /**< (I) Occurrence to attach effectivity to */
    tag_t    eff            /**< (I) The existing effectivity object that will be added to the occurrence */
    );

/**
    Removes an effectivity object from an occurrence.
*/
extern PS_API int PS_occ_eff_remove_eff(
    tag_t    bvr,           /**< (I) Parent BVR of occurrence */
    tag_t    occ,           /**< (I) Occurrence to remove effectivity from */
    tag_t    eff            /**< (I) The effectivity object that will be removed from the occurrence */
    );

/**
    Sets the Id that can be used to reference an effectivity object. Effectivity objects
    can be queried by Id using the CFM_find_effectivities function.
*/
extern PS_API int PS_occ_eff_set_id(
    tag_t        bvr,     /**< (I) Parent BVR of occurrence */
    tag_t        occ,     /**< (I) Occurrence to which effectivity is attached */
    tag_t        eff,     /**< (I) The effectivity object */
    const char * id       /**< (I) The Id to assign to the occurrence effectivity */
    );

/**
    Protects an effectivity object against being modified.
*/
extern PS_API int PS_occ_eff_set_protection(
    tag_t       bvr,        /**< (I) Parent BVR of occurrence */
    tag_t       occ,        /**< (I) Occurrence to which effectivity is attached */
    tag_t       eff,        /**< (I) The effectivity object */
    logical     protection  /**< (I) Set to true to prevent modification of effectivity. */
    );

/**
    Sets the end item for an occurrence effectivity.

    If necessary, this function will load the parent BOMView Revision and lock it for modify.
    Note that this function modifies the occurrence in the loaded representation of the BOMView Revision only.
    The modification will only be propagated to the database when the parent BOMView Revision is saved
    using #AOM_save_with_extensions/#AOM_save_without_extensions. After saving the BOMView Revision, it should be unlocked.
*/
extern PS_API int PS_occ_eff_set_enditem(
    tag_t    bvr,         /**< (I) Parent BVR of occurrence */
    tag_t    occ,         /**< (I) Occurrence to which effectivity is attached */
    tag_t    eff,         /**< (I) The effectivity object */
    tag_t    enditem      /**< (I) The new end item for this effectivity */
    );

/**
    Sets the end item revision for an occurrence effectivity.
*/
extern PS_API int PS_occ_eff_set_enditemrev(
    tag_t    bvr,         /**< (I) Parent BVR of occurrence */
    tag_t    occ,         /**< (I) Occurrence to which effectivity is attached */
    tag_t    eff,         /**< (I) The effectivity object */
    tag_t    enditemrev   /**< (I) The new end item revision for this effectivity */
    );

/**
    Sets or appends a unit range for an occurrence effectivity.

    If necessary, this function will load the parent BOMView Revision and lock it for modify.
    Note that this function modifies the occurrence in the loaded representation of the BOMView Revision only.
    The modification will only be propagated to the database when the parent BOMView Revision is saved
    using #AOM_save_with_extensions/#AOM_save_without_extensions. After saving the BOMView Revision, it should be unlocked.
*/
extern PS_API int PS_occ_eff_set_unit_range(
    tag_t        bvr,           /**< (I) Parent BVR of occurrence */
    tag_t        occ,           /**< (I) Occurrence to which effectivity is attached */
    tag_t        eff,           /**< (I) The effectivity object */
    const char * range_text,    /**< (I) Range of unit numbers that define the effectivity.
                                         For example, 100-199. Multiple ranges can be specified
                                         using a comma separator. For example, 100-199, 500-599. */
    logical      append         /**< (I) Set this to true to add the new range to any existing ranges.
                                         Set this to false to overwrite existing ranges. */
    );

/**
    Sets or appends a unit range for an occurrence effectivity.
*/
extern PS_API int PS_occ_eff_set_units(
    tag_t       bvr,                       /**< (I) Parent BVR of occurrence */
    tag_t       occ,                       /**< (I) Occurrence to which effectivity is attached */
    tag_t       eff,                       /**< (I) The effectivity object */
    int         n_units,                   /**< (I) The size of the array of start-end values*/
    int*        start_end_values,          /**< (I) n_units The array of start-end values of the discontinuous range.
                                                    For example, consider a discontinuous range consisting of
                                                    continuous ranges r1, r2, ..., rn where rx has start and end values,
                                                    rx.start and rx.end.
                                                    The array of start_end_vals for this discontinuous range will
                                                    be constructed as { r1.start, r1.end, r2.start, r2.end, ...,
                                                    rn.start, rn.end }. The last value, rn.end should be omitted if
                                                    the discontinuous range is open ended.*/
    int         open_ended_or_stock_out,   /**< (I) One of the following constants: #EFFECTIVITY_open_ended,
                                                    #EFFECTIVITY_stock_out or #EFFECTIVITY_closed. */
    logical     append                     /**< (I) If set to true, the values in the array will be added to
                                                    the unit range, otherwise they will replace them. */
    );

/**
    Sets or appends the date range for an occurrence effectivity.
*/
extern PS_API int PS_occ_eff_set_date_range(
    tag_t        bvr,            /**< (I) Parent BVR of occurrence */
    tag_t        occ,            /**< (I) Occurrence to which effectivity is attached */
    tag_t        eff,            /**< (I) The effectivity object */
    const char * range_text,     /**< (I) Range of dates that define the effectivity. For example,
                                          1-Jan-2000 to 31-Dec-2000. Multiple ranges can be
                                          specified using the semi-colon  separator 1-Jan-2000 to
                                          31-Dec-2000; 1-Apr-2001 to 30-Apr-2001. */
    logical      append          /**< (I) Set this to true to add the new range to any existing ranges.
                                          Set this to false to overwrite existing ranges. */
    );

/**
    Sets or appends the date range for an occurrence effectivity.
*/
extern PS_API int PS_occ_eff_set_dates(
    tag_t       bvr,                       /**< (I) Parent BVR of occurrence */
    tag_t       occ,                       /**< (I) Occurrence to which effectivity is attached */
    tag_t       eff,                       /**< (I) The effectivity object */
    int         n_dates,                   /**< (I) The size of the array of start-end values */
    date_t*     start_end_values,          /**< (I) n_dates The array of start-end values of the discontinuous range.
                                                    For example, consider a discontinuous range consisting of
                                                    continuous ranges r1, r2, ..., rn where rx has start and
                                                    end values, rx.start and rx.end.
                                                    The array of start_end_vals for this discontinuous range will
                                                    be constructed as { r1.start, r1.end, r2.start, r2.end, ...,
                                                    rn.start, rn.end }. The last value, rn.end should be omitted if
                                                    the discontinuous range is open ended. */
    int         open_ended_or_stock_out,   /**< (I) One of the following constants: #EFFECTIVITY_open_ended,
                                                    #EFFECTIVITY_stock_out or #EFFECTIVITY_closed.*/
    logical     append                     /**< (I) If set to true, the values in the array will be added to
                                                    the date range, otherwise they will replace them.*/
    );

/**
    Retrieves a list of effectivities on an occurrence.
*/
extern PS_API int PS_occ_eff_ask_effs(
    tag_t    bvr,           /**< (I) Parent BVR of occurrence */
    tag_t    occ,           /**< (I) Occurrence to query */
    int *    n_effs,        /**< (O) Number of effectivities on the occurrence */
    tag_t ** effs           /**< (OF) n_effs Array of effectivities */
    );

/**
    Retrieves the Id for an occurrence effectivity.
*/
extern PS_API int PS_occ_eff_ask_id(
    tag_t     bvr,         /**< (I) Parent BVR of occurrence */
    tag_t     occ,         /**< (I) Occurrence */
    tag_t     eff,         /**< (I) Effectivity to query */
    char **   id           /**< (OF) Effectivity id */
    );

/**
    Retrieves protection state of an occurrence effectivity
*/
extern PS_API int PS_occ_eff_ask_protection(
    tag_t     bvr,         /**< (I) Parent BVR of occurrence */
    tag_t     occ,         /**< (I) Occurrence */
    tag_t     eff,         /**< (I) Effectivity to query */
    logical * protection   /**< (O) True if effectivity is protected */
    );

/**
    Retrieves the end item for an occurrence effectivity.
*/
extern PS_API int PS_occ_eff_ask_enditem(
    tag_t    bvr,            /**< (I) Parent BVR of occurrence */
    tag_t    occ,            /**< (I) Occurrence */
    tag_t    eff,            /**< (I) Effectivity to query */
    tag_t *  enditem         /**< (O) End item */
    );

/**
    Retrieves the end item revision for an occurrence effectivity.
*/
extern PS_API int PS_occ_eff_ask_enditemrev(
    tag_t    bvr,            /**< (I) Parent BVR of occurrence */
    tag_t    occ,            /**< (I) Occurrence */
    tag_t    eff,            /**< (I) Effectivity to query */
    tag_t *  enditemrev      /**< (O) End item */
    );

/**
    Retrieves whether effectivity range is unit or date based.
*/
extern PS_API int PS_occ_eff_ask_range_type(
    tag_t       bvr,            /**< (I) Parent BVR of occurrence */
    tag_t       occ,            /**< (I) Occurrence */
    tag_t       eff,            /**< (I) Effectivity to query */
    int*        range_type      /**< (O) The type of range for this occurrence effectivity:
                                         0 No range, 1 Unit range, 2 Date range */
    );

/**
    Retrieves the unit range of an occurrence effectivity as a text string.
*/
extern PS_API int PS_occ_eff_ask_unit_range(
    tag_t       bvr,            /**< (I) Parent BVR of occurrence */
    tag_t       occ,            /**< (I) Occurrence */
    tag_t       eff,            /**< (I) Effectivity to query */
    char **     range_text      /**< (OF) Unit range text string */
    );

/**
    Retrieves the unit range of an occurrence effectivity as an array.
*/
extern PS_API int PS_occ_eff_ask_units(
    tag_t       bvr,                        /**< (I) Parent BVR of occurrence */
    tag_t       occ,                        /**< (I) Occurrence */
    tag_t       eff,                        /**< (I) Effectivity to query */
    int*        n_units,                    /**< (O) The size of the array of start-end values */
    int**       start_end_values,           /**< (OF) n_units The array of start-end units */
    int*        open_ended_or_stock_out     /**< (O) One of the following constants: #EFFECTIVITY_open_ended,
                                                     #EFFECTIVITY_stock_out or #EFFECTIVITY_closed. */
    );

/**
    Retrieves the date range of an occurrence effectivity as a text string.
*/
extern PS_API int PS_occ_eff_ask_date_range(
    tag_t       bvr,            /**< (I) Parent BVR of occurrence */
    tag_t       occ,            /**< (I) Occurrence */
    tag_t       eff,            /**< (I) Effectivity to query */
    char **     range_text      /**< (OF) Date range text string */
    );

/**
    Retrieves the date range of an occurrence effectivity as an array.
*/
extern PS_API int PS_occ_eff_ask_dates(
    tag_t       bvr,                        /**< (I) Parent BVR of occurrence */
    tag_t       occ,                        /**< (I) Occurrence */
    tag_t       eff,                        /**< (I) Effectivity to query */
    int*        n_dates,                    /**< (O) The size of the array of start-end values */
    date_t**    start_end_values,           /**< (OF) n_dates The array of start-end dates */
    int*        open_ended_or_stock_out     /**< (O) One of the following constants: #EFFECTIVITY_open_ended,
                                                     #EFFECTIVITY_stock_out or #EFFECTIVITY_closed. */
    );

/** @} */

/**
    Adds optional parts for any occurrence and its substitute parts.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_invalid_occurrence if the occurrence is invalid
    <li>#PS_invalid_bvr if the parent is invalid
    <li>#PS_invalid_opt_item if the optional item is invalid
    <li>Possibly other PS errors
    </ul>
*/
extern PS_API int PS_add_optional_item(
    tag_t   parent,           /**<   (I) Parent BVR of occurrence */
    tag_t   occurrence,       /**<   (I) Occurrence  */
    tag_t   child_item,       /**<   (I) Child Item */
    tag_t   opt_item,         /**<   (I) Optional Item */
    tag_t   opt_rev,          /**<   (I) Optional Item Rev */
    tag_t   opt_view,         /**<   (I) Optional View, it is not used  */
    tag_t   *optlist          /**<   (O) Optional Item List  */
);

/**
    Removes optional parts from any occurrence and its substitute parts.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_invalid_occurrence if the occurrence is invalid
    <li>#PS_invalid_bvr if the parent is invalid
    <li>#PS_invalid_opt_item if the optional item is invalid
    <li>Possibly other PS errors
    </ul>
*/
extern PS_API int PS_remove_optional_item(
    tag_t   parent,          /**<   (I) Parent BVR of occurrence */
    tag_t   occurrence,      /**<   (I) Occurrence */
    tag_t   child_item,      /**<   (I) Child Item  */
    tag_t   opt_item,        /**<   (I) Optional Item */
    tag_t   opt_rev,         /**<   (I) Optional Item Rev */
    tag_t   opt_view         /**<   (I) Optional View, it is not used  */
);

/**
    Lists previously defined optional parts of the selected occurrence.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_invalid_occurrence if the occurrence is invalid
    <li>#PS_invalid_bvr if the parent is invalid
    <li>Possibly other PS errors
    </ul>
*/
extern PS_API int PS_list_optional_items(
    tag_t   parent,           /**<   (I)  Parent BVR of occurrence */
    tag_t   occurrence,       /**<   (I)  Occurrence */
    tag_t   child_item,       /**<   (I)  Child Item */
    int     *count,           /**<   (O)  Number of Optional Items */
    tag_t   **opt_items       /**<   (OF) count Optional Item List */
);

/**
    Retrieves the declared VariantRevision of the most recently saved temRevision of the owning option Item.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly some PS errors
    </ul>
*/
extern PS_API int PS_ask_latest_option_rev(
      tag_t     variant,     /**<   (I)  Variant */
      tag_t    *variantRev   /**<   (I)  Variant Revision */
    );

/**
    Generates a unique ID, which is to be used as a persistent ID.
    A persistent ID is a key that uniquely identifies the boolean content of a Variant Expression. The same identifier will be assigned to logically equivalent expressions.
    The generated ID is consumed while authoring expression on Line of Usages.

   @return #ITK_ok always
*/
extern PS_API int PS_variant_expression_new_persistent_id(
    char** variant_expression_persistent_id     /**< (OF) The persistent ID that uniquely identifies the boolean content of a Variant Expression */
    );

/**
   Creates and saves the new BOMView and its Revision. The BOMView is made a view of the specified Item and
   BOMView Revision is made an attribute of the specified parent Item Revision.

   @note The new BOMView and modified item will get save into the database, also the BOMView is added to the parent Item.
   The new BOMView Revision and modified @p item_rev will get save into the database,also the BOMView Revision is added to the parent @p item_rev.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PS_invalid_item_rev if the @p item_rev is #NULLTAG or invalid
    <li>#CXPOM_wrong_class if class of @p item_rev is not of ItemRevision type
    <li>Possibly other PS errors
    </ul>
*/
extern PS_API int PS_create_bv_with_bvr(
    const char*   bv_name,   /**< (I) Name of the view. If NULL or empty string is specified,
                                       the default name is used. See also #PS_default_bom_view_name. */
    const char*   bv_desc,   /**< (I) Optional description text (NULL if not required) */
    tag_t         bv_type,    /**< (I) BOMView Type. If NULLTAG is specified,the default view type is used.
                                       See also #PS_ask_default_view_type. */
    const char*   bvr_name,  /**< (I) BOMView Revision name. If NULL or empty string "" is specified,
                                       the default name is used. See also #PS_default_bvr_name. */
    const char*   bvr_desc,  /**< (I) A description of the BOMView Revision (can be NULL) */
    logical       precise,   /**< (I) If true the BOMView Revision can have precise occurrences of child Item Revisions.
                                       If false it can have imprecise occurrence of child Items. */
    tag_t         item_rev,  /**< (I) The tag of the parent Item Revision of the BOMView Revision, This item_rev is modified internally. */
    tag_t*        bv_tag,    /**< (O) The new BOMView */
    tag_t*        bvr_tag    /**< (O) The newly created BOMView Revision */
    );

/**
   Retrieves occurrences that use the substitute groups.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other PS errors
    </ul>
*/

extern PS_API int PS_find_occ_with_substitute_group(
    int           n_substitute_groups,      /**< (I) Number of input substitute groups */
    tag_t*        substitute_groups,        /**< (I) n_substitute_groups The list of substitute groups */
    int *         n_occurences,             /**< (O) Number of occurrences found */
    tag_t**       occurrences               /**< (OF) n_occurences The list of occurrences found */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <ps/libps_undef.h>

#endif
