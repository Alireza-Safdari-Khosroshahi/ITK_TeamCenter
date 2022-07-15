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

   Include file to define entry points for user defined entry points.
*/

#ifndef BOM_CLONE_USER_EXITS_H
#define BOM_CLONE_USER_EXITS_H

#include <unidefs.h>
#include <common/tc_deprecation_macros.h>
#include <bom/libbom_exports.h>

/**
    @defgroup BOM_CLONE_BMF_USER_EXIT_MSG User exit messages for structure clone
    @ingroup USER_EXIT
    The user exits defined here are called during cloning a structure.
    @{
*/

/**
    @{
    Duplicate operation valid values for structure clone.
*/
#define STRUCTURE_CLONE_OPERATION_CLONE       0   /**< Instructs structure clone to Clone the component. */
#define STRUCTURE_CLONE_OPERATION_REFERENCE   1   /**< Instructs structure clone to Reference the component */
#define STRUCTURE_CLONE_OPERATION_REVISE      2   /**< Instructs structure clone to Revise the component */
#define STRUCTURE_CLONE_OPERATION_REPLACE     3   /**< Instructs structure clone to Replace the component */
#define STRUCTURE_CLONE_OPERATION_IGNORE      5   /**< Instructs structure clone to Ignore the component */
/** @} */


/**
    @{
    Cloning type valid values for processing cloned structure.
*/
#define ITEM_REVISION_CLONE     0                       /**< Indicates if clone operation is being executed using Item Revisions */
#define BOMLINE_CLONE           1                       /**< Indicates if clone operation is being executed using BOMLines */
/** @} */

#ifdef __cplusplus
extern "C" {
#endif
/**
    Retrieves the clone action that would be used for a given BOM Line during a structure clone operation.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if @p bomline is invalid.
    </ul>
*/
extern BOM_API int USER_bom_clone_get_clone_action(
    const tag_t     bom_line,               /**< (I) BOM Line to get a clone action. */
    logical*        use_default_action,     /**< (O) Use default clone action for @p bom_line. If this is returned as true, @p clone_action will be ignored.*/
    int*            clone_action            /**< (O) The clone action. Expected values are:
                                                     <ul>
                                                       <li>#STRUCTURE_CLONE_OPERATION_CLONE
                                                       <li>#STRUCTURE_CLONE_OPERATION_REFERENCE
                                                       <li>#STRUCTURE_CLONE_OPERATION_REVISE
                                                       <li>#STRUCTURE_CLONE_OPERATION_REPLACE
                                                       <li>#STRUCTURE_CLONE_OPERATION_IGNORE
                                                     </ul> */
);

/**

    @deprecated #USER_bom_clone_process_cloned_structure deprecated in Teamcenter 12.3. Use #USER_bomline_process_cloned_structure instead.

    Processes cloned objects after clone operation is complete.
    <br/>Customizers need to replace the base action for the user exit BMF_USER_bom_clone_process_cloned_structure to address their business needs.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if the @p source_window is invalid.
    <li>#BOM_invalid_tag if the @p cloned_top_item_rev is invalid.
    </ul>
*/
TC_DEPRECATED("12.3","USER_bom_clone_process_cloned_structure","USER_bomline_process_cloned_structure")
extern BOM_API int USER_bom_clone_process_cloned_structure(
    const tag_t     source_window,                      /**< (I) BOM Window on which clone operation is initiated. */
    const tag_t     cloned_top_item_rev,                /**< (I) Top Item Revision of the cloned structure. */
    const int       n_source_items_or_revs_for_clone,   /**< (I) Number of Item Revisions to be cloned. */
    const tag_t*    source_items_or_revs_for_clone,     /**< (I) n_source_items_or_revs_for_clone List of Item Revisions to be cloned. */
    const tag_t*    cloned_items_or_revs,               /**< (I) n_source_items_or_revs_for_clone List of cloned Item Revisions. */
    const int       n_source_occurrences_for_clone,     /**< (I) Number of PSOccurrences to be cloned. */
    const tag_t*    source_occurrences_for_clone,       /**< (I) n_source_occurrences_for_clone List of PSOccurrences to be cloned. */
    const tag_t*    cloned_occurrences                  /**< (I) n_source_occurrences_for_clone List of cloned PSOccurrences. */
);


/**
    Processes cloned objects after clone operation is complete.
    <br/>Customizers need to replace the base action for the user exit BMF_USER_bomline_process_cloned_structure to address their business needs.

    The following are cloning type options for @p cloning_type.
    <ul>
    <li>#ITEM_REVISION_CLONE
    <li>#BOMLINE_CLONE
    </ul>

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if the @p cloned_top_item_rev is invalid.
    </ul>
*/

extern BOM_API int USER_bomline_process_cloned_structure(
    const tag_t     cloned_top_item_rev,                /**< (I) Top Item Revision of the cloned structure. */
    const int       cloning_type,                       /**< (I) Cloning type for clone operation. Expected values are:
                                                                 <ul>
                                                                 <li>#ITEM_REVISION_CLONE
                                                                 <li>#BOMLINE_CLONE
                                                                 </ul>
                                                                 */
    const int       n_source_bom_lines,                 /**< (I) Number of BOMLines to be cloned. */
    const tag_t*    source_bom_lines,                   /**< (I) n_source_bom_lines List of BOMLines to be cloned. */
    const tag_t*    cloned_occurrences                  /**< (I) n_source_bom_lines List of cloned PSOccurrences. */
);


/** @} */

#ifdef __cplusplus
}
#endif

#include <bom/libbom_undef.h>
#endif
