/*
  Copyright 2020 Siemens Digital Industries Software
  ==================================================
  Copyright 2014.
  Siemens Product Lifecycle Management Software Inc.
  All Rights Reserved.
  ==================================================
  Copyright 2020 Siemens Digital Industries Software
*/
/**
   @file

   Include file to define entry points for user defined entry points.
*/

/*  */

#ifndef ME_USER_EXITS_H
#define ME_USER_EXITS_H

#include <unidefs.h>
#include <me/libme_exports.h>

/**
   @defgroup ME_USER_EXITS User exits for mbom creation
   @ingroup USER_EXIT
   The user exits defined here are called during mirroring of Engineering BOM (EBOM) to Manufacturing BOM (MBOM).
   @{
*/

/**
   Used by the user exit extension to instruct the user exit ITK implementation to continue to execute the out-of-the-box behavior.
*/
#define ME_USER_EXIT_CONTINUE        101

/** @name Modes to be used when aligning a design BOM Line to part BOM Line.
@{
*/
/**
    Indicates that the revision of the design line and revision of part line should be aligned.
*/
#define ME_DESIGN_BOM_REV                              1

/**
    Indicates that the design line must be instantiated below part line on align.
*/
#define ME_DESIGN_BOM_DESIGN                           2

/**
    Indicates that the revision of design line should be disconnected from the revision part line.
*/
#define ME_DESIGN_BOM_UNLINK                           3
/** @} */

/** @name Action to be used when updating the alignment to a released part revision for the new design revision.
@{
*/
/**
    Indicates that an error should be returned if the part revision to be aligned with is not writable.
*/
#define ME_ERROR_IF_PART_RELEASED                      0

/**
    Indicates that bypass should be used if the part revision to be aligned with is not writable.
*/
#define ME_UPDATE_RELEASED_PART_REVISION               1

/**
    Indicates that the part revision should be revised if the part revision to be aligned with is not writable.
*/
#define ME_REVISE_PART_REVISION                        2
/** @} */

#ifdef __cplusplus
extern "C"{
#endif

/**
   Generates a Manufacturing BOM (MBOM) when an Engineering BOM (EBOM) is being used as a basis.
   <br/>The parameter @p user_data is a pass-through data from #ME_create_mbom_from_ebom or #ME_update_mbom_from_ebom.
   <br/>If the user exit is not overridden, default implementation creates a new item instance based on EBOM node if second argument is topline
   of structure. Implementator operation should always return NULL pointer for @p create_input to indicate referenced/shared item.

   @note The @p create_input object must be populated with all the details including compound create inputs.
   Potentially clients can override finalizeCreateInput and/or createPost. So, any additional data
   needed in those methods should be filled in here.

   @note When implementing the extension function registered against the operation "BMF_ITEM_create_or_ref_id" on Item (or any of its subclass), its arguments must match the exact same arguments as this ITK.

   @note This ITK must not be invoked directly. Teamcenter will call it during MBOM mirror creation or update. If there is custom implementation and that needs to subsequently call the default implementation, it should return #ME_USER_EXIT_CONTINUE.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#ME_invalid_input_data if an invalid item is provided for @p ebom_node or @p ebom_line_node.
   <li>Possibly other errors
   </ul>
*/
    extern ME_API int USER_create_or_ref_item(
        tag_t ebom_node,            /**< (I) The source item.*/
        tag_t ebom_line_node,       /**< (I) The BOMLine corresponding to the source item.*/
        const char* user_data,      /**< (I) Opaque data passed in. <br/>The out-of-the-box implementation of this user exit ITK does not leverage this data. Implementors of an override can, however, use it.*/
        int* num_mfk_keys,          /**< (O) number of mfk key value pairs. Set to 0 if unused.*/
        char*** mfk_keys,           /**< (OF) num_mfk_keys MFK keys if item_id is not unique. object_type and item_id need not be added. Array is packed.*/
        char*** mfk_values,         /**< (OF) num_mfk_keys MFK values corresponding to mfk keys. Array is packed..*/
        tag_t* to_be_created_type,  /**< (O) type of mbom item to be created. If referencing @p ebom_node , set value to @p ebom_node type.*/
        tag_t* create_input         /**< (O) The createInput object to be populated by callee. set to NULLTAG if referencing @p ebom_node.*/
        );

/**
   Generates a Manufacturing BOM (MBOM) when an Engineering BOM (EBOM) is being used as a basis.
   <br/>The parameter @p user_data is a pass-through data from #ME_create_mbom_from_ebom or #ME_update_mbom_from_ebom.
   <br/>If the user exit is not overridden, default implementation synchonizes occurrence level attributes.

   @note Synchronization of removed lines can be done by redefining the implementation of this user exit function.

   @note When implementing the extension function registered against the operation "BMF_ITEM_sync" on Item (or any of its subclass), its arguments must match the exact same arguments as this ITK.

   @note This ITK must not be invoked directly. Teamcenter will call it during MBOM mirror creation or update. If there is custom implementation and that needs to subsequently call the default implementation, it should return #ME_USER_EXIT_CONTINUE.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#ME_invalid_input_data if an invalid item is provided for @p ebom_item or @p ebom_line_node or @p mbom_line_node.
   <li>Possibly other errors
   </ul>
*/
    extern ME_API int USER_sync_item(
        tag_t ebom_item,       /**< (I) The source Item.*/
        tag_t ebom_line_node,  /**< (I) The BOMLine corresponding to the source Item whose children need to be synchronized.*/
        tag_t mbom_line_node,  /**< (I) The target BOMLine where the sync needs to be done.*/
        const char* user_data  /**< (I) Opaque data passed in. <br/>The out-of-the-box implementation of this user exit ITK does not leverage this data. Implementors of an override can, however, use it.*/
        );


/**
   Finds matching Engineering BOM (EBOM) lines given a list of Manufacturing BOM (MBOM) lines and search criteria.
   <br/>If the user exit is not overridden, the default implementation finds the candidates from the input EBOM lines based on the search criteria.

   @note Searching for matching candidates can be done by redefining the implementation of this user exit function.

   @note When implementing the extension function registered against the operation #BMF_BOMLINE_find_candidates_msg on BOMLine (or any of its subclasses), its arguments must match the exact same arguments as this ITK.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#ME_invalid_input_data if any of the @p n_mbom_lines, @p n_ebom_candidates, or @p n_criteria is not greater than 0.
   <li>#ME_invalid_input_data if any element of the @p mbom_lines or @p ebom_candidates is a NULLTAG or an invalid tag.
   <li>#ME_invalid_input_data if any element of the @p property_names is a NULL.
   <li>#ME_invalid_input_data if any element of the @p property_types, @p operators or @p is_mandatory is invalid.
   <li>Possibly other errors
   </ul>
*/
    extern ME_API int USER_BOMLINE_find_candidates(
        int n_mbom_lines,                    /**< (I) The number of MBOM lines.*/
        const tag_t* mbom_lines,             /**< (I) n_mbom_lines The MBOM lines to search candidates for.*/
        int n_ebom_candidates,               /**< (I) The number of EBOM candidate lines.*/
        const tag_t* ebom_candidates,        /**< (I) n_ebom_candidates The EBOM candidate lines to search from.*/
        int n_criteria,                      /**< (I) The number of search criteria.*/
        const char** property_names,         /**< (I) n_criteria The list of property names in the search criteria.*/
        const int* property_types,           /**< (I) n_criteria The list of primitive property types in the search criteria.
                                                <br/>Valid values are:
                                                <ul>
                                                <li>0 for integer</li>
                                                <li>1 for string</li>
                                                <li>2 for character</li>
                                                <li>3 for double</li>
                                                <li>4 for boolean</li>
                                                </ul>
                                             */
        const int* operators,                /**< (I) n_criteria The list of relational operators in the search criteria.
                                                <br/>Valid values are:
                                                <ul>
                                                <li>0 for =</li>
                                                <li>1 for <=</li>
                                                <li>2 for >=</li>
                                                <li>3 for <=/li>
                                                <li>4 for ></li>
                                                <li>5 for !=</li>
                                                </ul>
                                                <br/>Currently only = is supported.
                                             */
        const char** values,                 /**< (I) n_criteria The list of property values in the search criteria. To compare two property values to each other, specify NULL in the value.*/
        const int* is_empty_value_valid,     /**< (I) n_criteria Indicates if the value can be an empty string or not. Valid values are 0 (empty string invalid) and 1 (empty string valid).*/
        const int* is_mandatory,             /**< (I) n_criteria Whether a specific criteria is mandatory or not. Valid values are 0 (optional) and 1 (mandatory).*/
        const char* user_data,               /**< (I) Opaque data passed in. <br/>The out-of-the-box implementation of this user exit ITK does not leverage this data. Implementors of an override can, however, use it.*/
        tag_t*** matching_candidates,        /**< (OF) The matching EBOM candidates for all input mbom_lines. The first dimension of the list represents the candidate lists for
                                                all MBOM lines, and the size of it is specified by n_mbom_lines. The second dimension of the list represents
                                                the candidate list for each MBOM line, and this candidate list is terminated by a NULLTAG. If an MBOM line does not have matching
                                                EBOM candidates, its candidate list is NULL.
                                                                            <br/>The memory is deallocated by calling #MEM_free on each dimension container.*/
        int**** property_indices             /**< (OF) The indices of the property_names by which the EBOM candidates are matched. The first dimension of the list represents the
                                                property lists for all MBOM lines, and the size of it is specified by n_mbom_lines. The second dimension of the
                                                list represents the property list for each MBOM line, and this property list is terminated by NULL. The third dimension
                                                of the list represents the property list for each matching EBOM line, and this property list is terminated by -1.
                                                If an MBOM line does not have matching EBOM candidates, its matching property list is NULL.
                                                                            <br/>The memory is deallocated by calling #MEM_free on each dimension container.*/
        );


/**
   Repairs Manufacturing BOM (MBOM) lines from their equivalent Engineering BOM (EBOM) lines given a list of repair actions.
   <br/>If the user exit is not overridden, the default implementation either replaces the MBOM line or propagates the EBOM line properties.

   @note Repairing MBOM lines can be done by redefining the implementation of this user exit function.

   @note When implementing the extension function registered against the operation #BMF_BOMLINE_repair_bomlines_msg on BOMLine (or any of its subclasses), its arguments must match the exact same arguments as this ITK.

   @note If any value in @p statuses is 2, 3, or 4, the user exit function must return #ME_USER_EXIT_CONTINUE in order to delegate the custom repair action to the out-of-the-box repair action.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#ME_invalid_input_arguments if @p n_lines is not greater than 0.
   <li>#ME_invalid_input_arguments if any element of the @p mbom_lines or @p ebom_lines is a NULLTAG or an invalid tag.
   <li>#ME_invalid_input_arguments if any element of the @p repair_actions is invalid.
   <li>#ME_invalid_input_arguments if @p repair_actions is "Propagate" and @p n_propagation_properties is 0.
   <li>#ME_invalid_input_arguments if @p repair_actions is "Propagate" and any element of the @p propagation_properties is invalid.
   <li>Possibly other errors
   </ul>
*/
    extern ME_API int USER_BOMLINE_repair_bomlines(
        int n_lines,                         /**< (I) The number of MBOM lines to repair.*/
        const tag_t* mbom_lines,             /**< (I) n_lines The list of MBOM lines to repair.*/
        const tag_t* ebom_lines,             /**< (I) n_lines The parallel list of equivalent EBOM lines to repair from.*/
        const char** repair_actions,         /**< (I) n_lines The list of repair actions. The out-of-the-box values for the repair action are "Propagate", "Replace", and "Remove".*/
        int n_propagation_properties,        /**< (I) The number of properties to propagate for partial matched lines. If the repair action is "Propagate", n_propagation_properties must be greater than 0. Otherwise, it must be 0.*/
        const char** propagation_properties, /**< (I) n_propagation_properties The list of properties to propagate for partial matched lines. This list is applicable only if the repair action is "Propagate" or "Replace". It will be NULL for other repair actions.*/
        int** statuses,                      /**< (OF) List of statuses of MBOM lines' repair.
                                                <br/>Valid values are:
                                                <ul>
                                                <li>0 for succeeded</li>
                                                <li>1 for failed</li>
                                                <li>2 for delegate to Propagate</li>
                                                <li>3 for delegate to Replace/li>
                                                <li>4 for delegate to Remove/li>
                                                </ul>
                                                <br/>The customization code is expected to allocate memory for this variable using #MEM_alloc, and set one of the above statuses for each line it repairs.
                                                <br/>The memory is deallocated by calling #MEM_free on the array of statuses.

                                             */
        char**** error_messages              /**< (OF) The error strings for the repaired MBOM lines.
                                                <br/>The first dimension of the list represents the error strings for all MBOM lines, and the size of it is specified by n_lines.
                                                The second dimension of the list represents the error strings for each MBOM line, and this list is terminated by NULL.
                                                <br/>The customization code is expected to allocate memory for this variable using #MEM_alloc. If the customization code sets the
                                                status to 2, 3, or 4 for a line at index i, or if the customization code decides there is no error for that line, the corresponding error list for
                                                that line must be set to NULL, i.e., (*error_messages)[i] = NULL.
                                                <br/>The memory is deallocated by calling #MEM_free on each element and on each container for each dimension.
                                             */
        );

/**
   Generates a Manufacturing BOM (MBOM) when an Engineering BOM (EBOM) is being used as a basis.
   <br/>The parameter @p user_data is a pass-through data from #ME_create_mbom_from_ebom or #ME_update_mbom_from_ebom.
   <br/>If the user exit is not overridden, default implementation is empty. <br/><br/>This function is invoked only if Id in context (top level) equivalence is
   not met and occurrence threads are different.

   @note When implementing the extension function registered against the operation "BMF_ITEM_find_eqv_line" on Item (or any of its subclass), its arguments must match the exact same arguments as this ITK.

   @note This ITK must not be invoked directly. Teamcenter will call it during MBOM mirror creation or update.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#ME_invalid_input_data if an invalid item is provided for @p ebom_item or @p ebom_line_node or @p mbom_line_node.
   <li>Possibly other errors
   </ul>
*/
    extern ME_API int USER_item_find_equivalent_line(
        tag_t ebom_item,        /**< (I) The source Item */
        tag_t ebom_line_node,   /**< (I) The BOMLine corresponding to the source Item whose children need to be synchronized.*/
        tag_t mbom_parent_node, /**< (I) The target BOMLine where the synchronized needs to be done.*/
        const char* user_data,  /**< (I) Opaque data passed in. <br/>The out-of-the-box implementation of this user exit ITK does not leverage this data. Implementors of an override can, however, use it.*/
        tag_t* mbom_line_node   /**< (O) MBOM Line equivalent to the EBOM Line.*/
        );

/**
   Determines the action to take if the underlying item object to be modified is released.
   <br/>The parameter @p user_data is pass-through data from #ME_create_mbom_from_ebom or #ME_update_mbom_from_ebom.
   <br/>The parameter @p suggested_action_on_release is passed in from #ME_create_mbom_from_ebom or #ME_update_mbom_from_ebom.
   <br/>If the user exit is not overridden, the default implementation is to use the value for the parameter @p suggested_action_on_release.

   @note When implementing the extension function registered against the operation "BMF_ITEM_action_on_release" on Item (or any of its subclass), its arguments must match the exact same arguments as this ITK.

   @note This ITK must not be invoked directly. Teamcenter will call it during MBOM mirror creation or update.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#ME_invalid_input_data if an invalid item is provided for @p ebom_item or @p ebom_line_node or @p mbom_released_object or @p mbom_line_node or @p suggested_action_on_release.
   <li>Possibly other errors
   </ul>
*/
    extern ME_API int USER_item_action_on_release(
        tag_t ebom_item,            /**< (I) The source Item */
        tag_t ebom_line_node,       /**< (I) The BOM Line corresponding to the source Item whose children need to be synchronized.*/
        tag_t mbom_released_object, /**< (I) The released MBOM object. Currently, this can only be subtype (or subclass) of Item or ItemRevision or BOM View Revision.*/
        tag_t mbom_line_node,       /**< (I) The target BOM Line equivalent to the source ebom_line_node.*/
        const char* user_data,      /**< (I) Opaque data passed in. <br/>The out-of-the-box implementation of this user exit ITK does not leverage this data. Implementors of an override can, however, use it.*/
        int suggested_action_on_release,
        /**< (I) Default action to take. Valid values are:
           <ul>
           <li>#ME_SKIP_RELEASED_NODE if the MBOM node @p mbom_line_node is released and not modifiable skip it.
           <li>#ME_REVISE_ON_RELEASE if the MBOM node @p mbom_line_node is released, revise it and modify it.
           <li>#ME_UPDATE_PROP_ON_SELF_ON_RELEASE if the MBOM node @p mbom_line_node is released, update occurrence props on self only.
           <li>#ME_UPDATE_PROP_ON_SELF_AND_BELOW_ON_RELEASE if the MBOM node @p mbom_line_node is released, update properties only on self and recursively on children.
           </ul> */
        logical* modify_released,   /**< (O) If the released node @p mbom_released_object is currently modifiable, setting this flag to 1 will
                                       modify the released object, irrespective of the value of @p action_on_release.*/
        int *action_on_release      /**< (O) Action to perform. Valid values are:
                                       <ul>
                                       <li>#ME_SKIP_RELEASED_NODE if the MBOM node @p mbom_line_node is released and not modifiable skip it.
                                       <li>#ME_REVISE_ON_RELEASE if the MBOM node @p mbom_line_node is released, revise it and modify it.
                                       <li>#ME_UPDATE_PROP_ON_SELF_ON_RELEASE if the MBOM node @p mbom_line_node is released, update occurrence props on self only.
                                       <li>#ME_UPDATE_PROP_ON_SELF_AND_BELOW_ON_RELEASE if the MBOM node @p mbom_line_node is released, update properties only on self and recursively on children.
                                       </ul> */
        );

/**
 Default implementation to link the roots of the structure for use with a design part alignment.
 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_class if either @p design_root_line or @p part_root_line is a invalid BOM Line tag.
    <li>Possibly other errors.
    </ul>
*/
extern ME_API int USER_link_design_bom_roots(
    tag_t design_root_line,              /**< (I) The Root design BOM Line.*/
    tag_t part_root_line                 /**< (I) The Root part BOM Line.*/
    );

/**
 Default implementation to unlink the specified design and part structures.
 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_class if both of @p design_root_line and @p part_root_line are invalid.
    <li>Possibly other errors.
    </ul>
*/
extern ME_API int USER_unlink_design_bom_roots(
    tag_t design_root_line,             /**< (I) The Root design BOM Line. Specify NULLTAG if all design structures connected to part_root_line are to be unlinked. If NULLTAG will stop processing on first error.*/
    tag_t part_root_line                /**< (I) The Root part BOM Line. Specify NULLTAG if all part structures connected to design_root_line are to be unlinked. If NULLTAG will stop processing on first error.*/
    );


/**
 Default implementation to align the design and part line. Alignment type will be updated, if it already exists.
 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_class if both of @p design_root_line and @p part_root_line are invalid.
    <li>Possibly other errors.
    </ul>
*/
extern ME_API int USER_align_design_bom(
    tag_t design_line,             /**< (I) The Root design BOM Line. Specify NULLTAG if all design structures connected to part_root_line are to be unlinked. Ignored if alignMode is ME_DESIGN_BOM_UNLINK.*/
    tag_t part_line,               /**< (I) The Root part BOM Line. Specify NULLTAG if all part structures connected to design_root_line are to be unlinked.*/
    unsigned int alignMode         /**< (I) Perform action. Valid values are:
                                      <ul>
                                      <li>#ME_DESIGN_BOM_REV to just align the design revision and part revision.<br/>This is the default value if an invalid value is specified.
                                      <li>#ME_DESIGN_BOM_DESIGN to instantiate the design line below the part line on align.
                                      <li>#ME_DESIGN_BOM_UNLINK to disconnect the design revision from part revision across all connected design and part lines.
                                      </ul> */
    );

/**
 Default implementation to update the design revision on all part revisions aligned to the old_design_revision.
 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_tag if either one of @p new_design_revision and @p old_design_revision are invalid.
    <li>Possibly other errors.
    </ul>
*/
extern ME_API int USER_update_part_rev_from_design_rev(
    tag_t new_design_revision,              /**< (I) The new design revision that is to replace the old design revision.*/
    tag_t old_design_revision,              /**< (I) The old design revision that is to replaced with the new design revision.*/
    unsigned int actionIfPartRevIsReleased  /**< (I) Perform action. Valid values are:
                                               <ul>
                                               <li>#ME_ERROR_IF_PART_RELEASED to return an error if the part revision to be aligned is not modifiable. <br/>This is also the default value if an invalid action is specified.
                                               <li>#ME_UPDATE_RELEASED_PART_REVISION to overwrite released part revision on align.
                                               <li>#ME_REVISE_PART_REVISION to revise the non-modifiable part revision and align.
                                               </ul> */
    );

/**
 Provides the default implementation to find matching design candidates for a list of parts.
 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_tag if any part or design in @p part_lines and @p design_lines is invalid
    <li>Possibly other errors
    </ul>
*/
extern ME_API int USER_search_for_part_candidates(
    const unsigned int  n_part_lines,    /**< (I) The number of part lines.*/
    const tag_t * part_lines,            /**< (I) n_part_lines The part lines to search for candidate design lines.*/
    const unsigned int n_design_lines,   /**< (I) The number of design lines.*/
    const tag_t * design_lines,          /**< (I) n_design_lines The candidate design lines.*/
    int * n_matches,                     /**< (O) The number of matches found for the part lines.*/
    tag_t ** result_part_lines,          /**< (OF) n_matches The part lines for which a candidate design line was found.*/
    tag_t ** result_design_lines         /**< (OF) n_matches The matching design lines for the result part lines.*/
    );

/**
 Provides the default implementation to update the part bom alignment for mature designs.
 <br/>This method will recursively align previously aligned part lines to currently configured design revisions which match a maturity criterion.
 <br/>The maturity criterion can be customized by using  #USER_is_item_rev_mature.
 <br/>If the maturity check is turned off (via the preference MEDesignToBom_check_maturity), the alignment will consider the currently configured Design Revisions as mature.

 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_tag if the Collaboration Context, Part or Design in @p cc, @p design_scope_line or @p part_scope_line is invalid
    <li>Possibly other errors
    </ul>
*/
extern ME_API int USER_update_part_bom_alignment_to_mature_design(
    const tag_t cc,                 /**< (I) The collaboration context containing one design scope line and one part scope line.
                                    <br/>If this is provided then @p design_scope_line and @p part_scope_line both should be #NULLTAG.
                                    <br/>This can be #NULLTAG, in which case @p design_scope_line and @p part_scope_line are required.*/
    const tag_t design_scope_line , /**< (I) The design scope line. If provided, @p cc must be #NULLTAG.
                                    <br/>This can be #NULLTAG, in which case @p cc is required.*/
    const tag_t part_scope_line ,   /**< (I) The part scope line. If provided, @p cc must be #NULLTAG.
                                    <br/>This can be #NULLTAG, in which case @p cc is required.*/
    int * n_aligned_lines,          /**< (O) The number of aligned part design lines.*/
    tag_t ** aligned_part_lines,    /**< (OF) n_aligned_lines The part lines that have been aligned.*/
    tag_t ** aligned_design_lines,  /**< (OF) n_aligned_lines The design lines that have been aligned.*/
    int * n_failed_lines,           /**< (O) The number of lines that failed to be aligned.*/
    tag_t ** failed_part_lines,     /**< (OF) n_failed_lines The part lines that failed to be aligned.*/
    int ** error_codes,             /**< (OF) n_failed_lines The error codes for the part lines that failed to be aligned.*/
    char  *** error_messages        /**< (OF) n_failed_lines The error messages for the part lines that failed to be aligned.
                                    <br/>The array is packed and the memory is to be deallocated by calling #MEM_free on @p error_messages.*/
    );

/*
 * The result type sent back from USER_search_for_design_candidates.
 * The candidate Design lines found by the search for a Part line.
 */
typedef ME_API struct ME_part_design_match_s {
    int number_designline_matches;
    tag_t * matched_designlines;
} ME_part_design_match_t;

/**
 Provides the default implementation to find candidate design lines based on a search criteria.
 <br/>This method delegates its work to the ITK method: ME_search_for_design_candidates.
 <br/>This is done so customizations can leverage the search results returned from ME_search_for_design_candidates.

 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ME_partline_results_do_not_match if internally mapped number of Part lines does not match @p number_partlines.
    </ul>
*/
extern ME_API int USER_search_for_design_candidates(
    const unsigned int  number_partlines,          /**< (I) The number of Part lines.*/
    const tag_t * partlines,                       /**< (I) number_partlines Part lines to search for candidate Design lines.*/
    const unsigned int  number_contexts,           /**< (I) The number of design context lines.*/
    const tag_t * design_contexts,                 /**< (I) The Design line contexts, if more than one then the common parent is used.*/
    ME_part_design_match_t ** designline_matches   /**< (OF) number_partlines The matching candidate design lines.*/
    );


/**
   Finds the target Plant BOP stations where given BOP Lines are to be assigned.
   <br/>If the user exit is not overridden, the default implementation finds Plant BOP stations using the common the Bill of Equipment (BOE) station to the BOP Line or it's parent that has the same BOE.

   @note Custom criteria can be provided by redefining the implementation of this user exit function. The user exit function must return #ME_USER_EXIT_CONTINUE in order to further leverage the default equivalence

   @note When implementing the extension function registered against the operation #BMF_BOPLINE_find_target_stations_msg("BMF_BOPLINE_find_target_stations") on ImanItemBOPLine, its arguments must match the exact same arguments as this ITK.

   @note If default equivalence is not needed, return #BMF_USER_EXIT_RETURN.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#ME_invalid_input_data if @p n_lines is not greater than 0.
   <li>#ME_invalid_input_data if any element of the @p bop_lines is NULLTAG or not a valid BOP Line, or if @p bop_lines is NULL.
   <li>#ME_invalid_input_data if the @p plant_bop_scope is invalid.
   <li>Possibly other errors
   </ul>
*/
extern ME_API int USER_BOPLINE_find_target_stations(
    int n_lines,                         /**< (I) The number of bop lines.*/
    const tag_t* bop_lines,              /**< (I) n_lines The list of BOP Lines for which the target Plant BOP stations are to be found.
                                                <br/>The topline will not be part of this line set. These lines are collected using the closure rule
                                                supplied by the preference MEPasteByRuleClosureRule. These would typically be operation lines.
                                                <br/>All the lines must be from the same Bill of Process (BOP) window.
                                                <br/>The default implementation uses the BOE assigned to these lines or the parent (closest parent), to find the
                                                corresponding Plant BOP station.
                                         */
    const tag_t plant_bop_root ,         /**< (I) The root line of Plant BOP structure.*/
    tag_t** plant_bop_stations ,         /**< (OF) The list of found Plant BOP stations.
                                                <br/> If at least one matching station is found, the order will correspond to the order of @p bop_lines.
                                                <br/>If no equivalent station is found, the corresponding entry will be NULLTAG.                                                
                                         */
    tag_t** bop_stations                 /**< (OF) The list of classic BOP stations. If this list is not needed, use NULL.
                                                <br/> The bop_lines are typically operations.Each station will contain the parent process lines for which the BOE station is assigned.
                                                <br/> If at least one matching station is found, the order will correspond to the order of @p bop_lines.                                                
                                                <br/>If no equivalent station is found, the corresponding entry will be NULLTAG.                                                
                                         */
);

/**
 Retrieves the decision to generate ID in Context of top level (idic) based on the location of the line in BOM tree. Default value of @p verdict is false. It is invoked during idic being generated.
<br/>In some cases there is no good property to set to compute the idic - eg. StandardPart 
In such cases it is better to use the thread chain to generate the idic, instead of using the properties that are not unique.
 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if @p bom_line is invalid or #NULLTAG.
    <li>Possibly other errors.
    </ul>
*/
extern ME_API int USER_is_chain_needed_for_idic_generation(
    tag_t bom_line,       /**< (I) The BOM Line.*/
    logical* verdict      /**< (O) Indicates if an idic based on the location of the line in BOM tree needs to be generated.*/
);

/**
 Retrieves the decision to force generate ID in Context of top level (idic) based on the location of the line in BOM tree, if one already exists. Default value of @p verdict is false.
 <br/>This is invoked if idic already exists on a line for which #USER_is_chain_needed_for_idic_generation is true.
 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if @p bom_line is invalid or #NULLTAG.
    <li>Possibly other errors.
    </ul>
*/
extern ME_API int USER_force_update_of_chain_based_idic(
    tag_t bom_line,       /**< (I) The BOM Line.*/
    logical* verdict      /**< (O) Indicates if an idic is to be generated based on the location of the line in BOM tree, even if there is already an idic value.*/
);

#ifdef __cplusplus
}
#endif


#include <me/libme_undef.h>
/** @} */
#endif
