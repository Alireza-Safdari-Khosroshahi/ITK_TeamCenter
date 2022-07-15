/*
  Copyright 2020 Siemens Digital Industries Software
  ==================================================
  Copyright 2020.
  Siemens Product Lifecycle Management Software Inc.
  All Rights Reserved.
  ==================================================
  Copyright 2020 Siemens Digital Industries Software
*/
/**
   @file

   Include file to define entry points for user defined entry points.
*/

#ifndef SOLUTION_VARIANT_USER_EXITS_H
#define SOLUTION_VARIANT_USER_EXITS_H

#include <unidefs.h>
#include <Smc0psmcfgsupport/libsmc0psmcfgsupport_exports.h>

/**
    @defgroup SOLUTIONVARIANT_BMF_USER_EXIT_MSG User exit messages for solution variant
    @ingroup USER_EXIT
    The user exits defined here are called during search, create and update of reuse solution variant.
    
    For USER_match_reuse_solution_variant - 
        1. First Generic Variant(GV) BOMWindow has to be created with input Generic Variant input Item Revision,
           input revision rule and input Saved Variant rule(SVR).
        2. Create the Solution Variant BOMWindow using SolutionVariant(SV) Item Revision.
        3. Compare the GV BOMLines with SV BOMLines using bl_clone_stable_occurrence_id property.
        4. If match found, associate the input Saved Variant Rule with Solution Variant Item Revision.
        5. Populate the result in match output.
    @{
*/


/** Message name to be keyed off of in BMIDE for adding user exit for search solution variant.*/
#define BMF_USER_match_reuse_solution_variant_msg                "BMF_USER_match_reuse_solution_variant"

/** Message name to be keyed off of in BMIDE for adding user exit for match solution variant.*/
#define BMF_USER_search_reuse_solution_variant_msg               "BMF_USER_search_reuse_solution_variant"

/**
    @{
*/
typedef struct Generic_solution_variant_info_s
{
    tag_t   generic_variant_item_rev;                          /**< Generic Variant Item Revision. */
    tag_t   solution_variant_item_rev;                         /**< Solution Variant Item Revision. */
    tag_t   relation;                                          /**< Generic Variant to Solution Variant relation */
    tag_t   svr;                                               /**< Saved Variant Rule */
}Generic_solution_variant_info_t;

typedef struct SV_additional_svr_recipe_info_s
{
    tag_t   solution_variant_item_rev;            /**< Solution Variant Item Revision */
    int     index_of_solution_variant_item_rev;   /**< Index of input Solution Variant Item Revision */
    int     n_svrs;                               /**< Number of Saved Variant Rule associated with Solution Variant Item Revision */
    tag_t*  svrs;                                 /**< n_svrs Saved Variant Rules associated with Solution Variant Item Rev */
}SV_additional_svr_recipe_info_t;
/** @} */

#ifdef __cplusplus
extern "C" {
#endif
/**
    Determines if a Generic Variant BOM matches a Solution Variant BOM for a given Saved Variant Rule. 
    <br/>For successful matches, it associates the Saved Variant Rule  to the Solution Variant Item Revision with a relation (may be custom).
    Customizers need to replace the base action for the user exit BMF_USER_match_reuse_solution_variant, if they want to support multiple SVR recipe for solution variant creation.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if @p sv_gv_match_info is invalid.
    <li>#BOM_invalid_tag if @p revision_rule is invalid.
    </ul>
*/
extern SMC0PSMCFGSUPPORT_API int USER_match_reuse_solution_variant(
    int n_sv_gv_match_info,                                /**< (I)  Number of @p sv_gv_match_info */
    Generic_solution_variant_info_t* sv_gv_match_info,     /**< (I)  sv_gv_match_info having input SVR to compare the structure */
    tag_t revision_rule,                                   /**< (I)  Input revision rule with which Generic Variant Item Revision BOMWindow has to be configured */
    int* n_match,                                          /**< (O)  Number of @p sv_gv_match_info found */
    logical** match                                        /**< (OF) n_match list of match found  for which relation has been create for Solution Variant Item Revision with input Saved Variant Rule*/
);

/**
    For the input solution variant item revision, retrieve additional Saved Variant Rules associated with it via relation( may be custom ).
    
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if @p svItemRevision is invalid.
    </ul>
*/
extern SMC0PSMCFGSUPPORT_API int USER_search_reuse_solution_variant(
    int n_solution_variant_item_rev,                  /**< (I)  Number of SolutionVariant Item Revision  */
    tag_t* solution_variant_item_rev,                 /**< (I)  n_solution_variant_item_rev of SolutionVariant Item Revision  for which addtional SVR recipe has to be searched */
    int* n_svr_recipe_info,                           /**< (O)  Number of Solution Variant Item Revisoin saved variant rule*/
    SV_additional_svr_recipe_info_t** svr_recipe_info /**< (OF) n_svr_recipe_info list of Solution Variant Item Revisoin saved variant rule. Output order should be same as input @p solution_variant_item_rev order. Ensure response structure is packed, which means that the memory is to be deallocated by calling #MEM_free on the it.*/
);

/** @} */

#ifdef __cplusplus
}
#endif

#include <Smc0psmcfgsupport/libsmc0psmcfgsupport_undef.h>
#endif
