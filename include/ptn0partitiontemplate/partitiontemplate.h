/*
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2013.
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
*/
/**
    @file partitiontemplate.h

    This header file declares Partition Template cloning and realization ITKs

*/

/*  */

#ifndef PARTITION_PARTITIONTEMPLATE_H
#define PARTITION_PARTITIONTEMPLATE_H

#include <unidefs.h>

#include <ptn0partitiontemplate/libptn0partitiontemplate_exports.h>

/**
    @defgroup PTN0PARTITIONTEMPLATE Template
    @ingroup PTN0PARTITION
    @{
*/
#ifdef __cplusplus
extern "C"{
#endif

/**
 * PARTITIONTEMPLATE_clone_rlz_input_option_t is the enum used to specify possible carry over options for cloning and realization operations.
*/
typedef enum PARTITIONTEMPLATE_clone_rlz_input_option_e
{
    PARTITION_checkout_on_create = 0,          /**< Option to checkout target partitions on create after cloning/realization */
    PARTITION_include_attribute_groups,        /**< Option to include Attribute Groups during cloning/realization */
    PARTITION_include_child_partitions,        /**< Option to include child Partitions during cloning/realization */
    PARTITION_include_variant_expressions,     /**< Option to include variant expressions during cloning/realization */
    PARTITION_include_effectivity_expressions, /**< Option to include effectivity expressions during cloning/realization. Reserved for future use */
    PARTITION_exclude_local_partitions,        /**< Option to exclude local Partitions during cloning */
    PARTITION_copy_rlz_references              /**< Option to copy realization references during cloning */
} PARTITIONTEMPLATE_clone_rlz_input_option_t;

/**
 * PARTITIONTEMPLATE_carry_over_input_option_t is the structure that holds the carry over option and its corresponding value.
*/
typedef struct PARTITIONTEMPLATE_carry_over_input_option_s
{
    PARTITIONTEMPLATE_clone_rlz_input_option_t      input_option;   /**< Option to update realized Partitions */
    logical                                         value;          /**< TRUE or FALSE */
} PARTITIONTEMPLATE_carry_over_input_option_t;


/**
Clones partition breakdowns from a source Application Model to a target Application Model. Source and target models may be Partition Templates or
Collaborative Designs or Product Architecture Models.
<br>This ITK function can optionally carry over variant expressions, attribute groups and child Partitions from source partitions to target partitions.
@returns
<ul>
<li>#ITK_ok on success.
<li>#PTN0PARTITIONTEMPLATE_cannot_clone_duplicate_partition if the Partitions cannot be cloned into the target model, because one or more duplicate Partitions are found.
<li>#PTN0PARTITIONTEMPLATE_missing_mandatory_input_arguments if not all mandatory input arguments are passed.
<li>#PTN0PARTITIONTEMPLATE_cannot_clone_no_input_ptns if the "Partial Cloning" operation cannot be performed because no Partitions are provided to clone.
<li>#PTN0PARTITIONTEMPLATE_variablity_of_source_n_target_no_match if the variability of source and target model does not match.
<li>#PTN0PARTITIONTEMPLATE_exclude_local_no_realized_scheme if the "Cloning" operation cannot be performed, because "Exclude Local Partitions" option is selected, but the Partition Schemes are unrealized.
<li>#PTN0PARTITIONTEMPLATE_copy_rlz_ref_not_allowed_for_pt if the "Copy Realization References" option is not allowed for a Partition Template
</ul>
@note Either source_model_tag, source_schemes or source_partitions should be supplied to clone partition breakdowns.
<ul>
<li>If source_partitions is not null, given partitions will be cloned and both source_model_tag and source_schemes arguments will be ignored.
<li>If source_partitions is null and source_schemes is not null, Partitions under the given schemes will be cloned and source_model_tag argument will be ignored.
<li>If both source_partitions and source_schemes are null, Partitions under all schemes in the source model will be cloned.
</ul>
*/
extern PTN0PARTITIONTEMPLATE_API int PARTITIONTEMPLATE_clone_partitions_partial_and_full(
    tag_t        source_model_tag,                                      /**< (I) Source application model tag. If both source_schemes and source_partitions are null, partitions under all schemes in the source model will be cloned */
    tag_t        target_model_tag,                                      /**< (I) Target application model tag */
    tag_t        revision_rule,                                         /**< (I) Revision rule tag */
    tag_t        variant_rule,                                          /**< (I) Variant rule tag */
    int          num_schemes,                                           /**< (I) Number of schemes to be cloned on the source application model */
    const tag_t  *source_schemes,                                       /**< (I) Source partition scheme tags. If source_partitions is null, partitions under the given schemes will be cloned and source_model_tag argument will be ignored  */
    int          num_partitions,                                        /**< (I) Number of partitions to be cloned from different source application models */
    const tag_t  *source_partitions,                                    /**< (I) Source partition tags. Given partitions will be cloned and both source_model_tag and source_schemes arguments will be ignored */
    int          no_of_clone_options,                                   /**< (I) Number of carry over options */
    const PARTITIONTEMPLATE_carry_over_input_option_t   *clone_options  /**< (I) Array of input carry over option structure */
    );


/**
Realizes partition breakdowns from Partition Template to a target Collaborative Design or Product Architecture Model. 
<br>This ITK function can optionally carry over variant expressions, attribute groups and child Partitions from source partitions to target partitions.
@returns
<ul>
<li>#ITK_ok on success.
<li>#PTN0PARTITIONTEMPLATE_cannot_realize_duplicate_partition when the partitions cannot be realized into the target model if one or more duplicate Partitions are found.
<li>#PTN0PARTITIONTEMPLATE_missing_mandatory_input_arguments if not all mandatory input arguments are passed.
<li>#PTN0PARTITIONTEMPLATE_rlz_possible_only_from_PT_to_CD if realization not performed from Partition Template to Collaborative Design or Product Architecture Model.
<li>#PTN0PARTITIONTEMPLATE_variablity_of_source_n_target_no_match if the variability of source and target model does not match.
</ul>
@note Either source_model_tag, source_schemes or source_partitions should be supplied to realize partition breakdowns.
<ul>
<li>If source_partitions is not null, given partitions will be realized and both source_model_tag and source_schemes arguments will be ignored.
<li>If source_partitions is null and source_schemes is not null, partitions under the given schemes will be realized and source_model_tag argument will be ignored.
<li>If both source_partitions and source_schemes are null, partitions under all schemes in the source model will be realized.
</ul>
*/
extern PTN0PARTITIONTEMPLATE_API int PARTITIONTEMPLATE_realize_partitions(
    tag_t        source_model_tag,                                 /**< (I) Source application model tag. If both source_schemes and source_partitions are null, partitions under all schemes in the source model will be realized */
    tag_t        target_model_tag,                                 /**< (I) Target application model tag */
    tag_t        revision_rule,                                    /**< (I) Revision rule tag */
    tag_t        variant_rule,                                     /**< (I) Variant rule tag */
    int          nb_of_schemes,                                    /**< (I) Number of schemes to be realized on the source application model */
    tag_t        *source_schemes,                                  /**< (I) Source partition scheme tags. If source_partitions is null, partitions under the given schemes will be realized and source_model_tag argument will be ignored  */
    int          nb_of_partitions,                                 /**< (I) Number of partitions to be realized from different source application models */
    tag_t        *source_partitions,                               /**< (I) Source partition tags. Given partitions will be realized and both source_model_tag and source_schemes arguments will be ignored */
    int          nb_of_rlz_options,                                /**< (I) Number of carry over options */
    PARTITIONTEMPLATE_carry_over_input_option_t   *rlz_options     /**< (I) Array of input carry over option structure */
    );

/**
Updates the realized partition from the source partition on source Partition Template.
<br>This ITK function uses the original carry over options selected during realization of this partition.
@returns
<ul>
<li>#ITK_ok on success.
<li>#PTN0PARTITIONTEMPLATE_cannot_realize_duplicate_partition when the partitions cannot be realized into the target model if one or more duplicate Partitions are found.
<li>#PTN0PARTITIONTEMPLATE_missing_mandatory_input_arguments if not all mandatory input arguments are passed.
<li>#PTN0PARTITIONTEMPLATE_null_partition_for_update if no partition exists in source model with selected Revision Rule.
<li>#PTN0PARTITIONTEMPLATE_null_realization_instance if the Realization instance is null for the input partition.
<li>#PTN0PARTITIONTEMPLATE_rlz_possible_only_from_PT_to_CD if realization not performed from Partition Template to Collaborative Design.
<li>#PTN0PARTITIONTEMPLATE_variablity_of_source_n_target_no_match if the variability of source and target model does not match.
</ul>
*/
extern PTN0PARTITIONTEMPLATE_API int PARTITIONTEMPLATE_update_realized_partition(
    tag_t        rlzd_partition,               /**< (I) Realized partition tag */
    tag_t        revision_rule,                /**< (I) Revision rule tag */
    tag_t        variant_rule                  /**< (I) Variant rule tag */
    );
#ifdef __cplusplus
}
#endif
/**
  @}
*/

#include <ptn0partitiontemplate/libptn0partitiontemplate_undef.h>
#endif
