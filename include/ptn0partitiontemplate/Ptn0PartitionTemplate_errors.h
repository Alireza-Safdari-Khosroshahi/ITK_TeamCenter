/** Copyright 2020 Siemens Digital Industries Software
* ==================================================
* Copyright $2012.
* Siemens Product Lifecycle Management Software Inc.
* All Rights Reserved.
* ==================================================
* Copyright 2020 Siemens Digital Industries Software
*/
/**
    @file

    Partition Template Error Codes Declaration

*/
/*#=============================================================================================
# DATE                 NAME                          DESCRIPTION OF CHANGE
# --------------------------------------------------------------------------------------------
# 10-Aug-2012    Chinnaswamy Jannumahanthi           Initial Creation
# $HISTORY$
#=============================================================================================*/

#ifndef PTN0PARTITIONTEMPLATE_ERRORS_H
#define PTN0PARTITIONTEMPLATE_ERRORS_H

/*================================================================================================*/
#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif

#include <ptn0partitiontemplate/libptn0partitiontemplate_exports.h>

/*================================================================================================*/

#define PTN0PARTITIONTEMPLATE_ERROR_BASE                                          EMH_PTN0PARTITIONTEMPLATE_error_base
/**
 * An internal error has occurred in the partitiontemplate module.
 */
#define PTN0PARTITIONTEMPLATE_internal_error                                      ( EMH_PTN0PARTITIONTEMPLATE_error_base + 1 )

/**
 * The input source model and input Partition Schemes for cloning are invalid. Please supply valid input source model or Partition Schemes.
 */
#define PTN0PARTITIONTEMPLATE_invalid_cloning_source_model_or_scheme              ( EMH_PTN0PARTITIONTEMPLATE_error_base + 2 )

/**
 * The input target model is invalid for cloning. Please supply a valid target model.
 */
#define PTN0PARTITIONTEMPLATE_invalid_cloning_target_model                        ( EMH_PTN0PARTITIONTEMPLATE_error_base + 3 )

/**
 * The input list of Partition Schemes does not contain any Partitions to clone. Please supply Partition Schemes with Partitions.
 */
#define PTN0PARTITIONTEMPLATE_invalid_cloning_partition                           ( EMH_PTN0PARTITIONTEMPLATE_error_base + 4 )

/**
 * The "Cloning" operation cannot be performed because the current user "%1$" does not have ADD_CONTENT privilege on the target model with Model ID "%2$".
 */
#define PTN0PARTITIONTEMPLATE_no_access_to_clone_on_target_model                  ( EMH_PTN0PARTITIONTEMPLATE_error_base + 5 )

/**
 * The Partitions cannot be cloned into one or more Partition Schemes, because they contain realized Partitions. Delete all the realized Partitions and the Partition Schemes for cloning.
 */
#define PTN0PARTITIONTEMPLATE_cannot_clone_realized_scheme                        ( EMH_PTN0PARTITIONTEMPLATE_error_base + 6 )

/**
 * The Partitions cannot be realized into the target model, because one or more duplicate Partitions are found.
 */
#define PTN0PARTITIONTEMPLATE_cannot_realize_duplicate_partition                  ( EMH_PTN0PARTITIONTEMPLATE_error_base + 7 )

/**
 * The "Realization operation" can be performed only from a Partition Template to a Collaborative Design or a Product Architecture Model.
 */
#define PTN0PARTITIONTEMPLATE_rlz_possible_only_from_PT_to_CD                     ( EMH_PTN0PARTITIONTEMPLATE_error_base + 8 )

/**
 * The "Update from Partition Template" operation cannot be performed, because the source Partition is invalid.
 */
#define PTN0PARTITIONTEMPLATE_invalid_partition_for_update                        ( EMH_PTN0PARTITIONTEMPLATE_error_base + 9 )

/**
 * The "Update from Partition Template" operation cannot be performed, because the Realization instance is null for the input Partition "%1$".
 */
#define PTN0PARTITIONTEMPLATE_null_realization_instance                           ( EMH_PTN0PARTITIONTEMPLATE_error_base + 10 )

/**
 * The "Update from Partition Template" operation cannot be performed, because no Partition exists in source model with selected Revision Rule.
 */
#define PTN0PARTITIONTEMPLATE_null_partition_for_update                           ( EMH_PTN0PARTITIONTEMPLATE_error_base + 11 )

/**
 * The "Realization" operation cannot be performed, because the current user "%1$" does not have ADD_CONTENT privilege on the target model with Model ID "%2$".
 */
#define PTN0PARTITIONTEMPLATE_no_access_for_realization                           ( EMH_PTN0PARTITIONTEMPLATE_error_base + 12 )

/**
 * The "Cloning" operation cannot be perfomed because the target model with Model ID "%1$" is owned by a remote site.
 */
#define PTN0PARTITIONTEMPLATE_cannot_clone_if_model_is_not_local                  ( EMH_PTN0PARTITIONTEMPLATE_error_base + 13 )

/**
 * The "Realization" operation cannot be perfomed because the target model with Model ID "%1$" is owned by a remote site.
 */
#define PTN0PARTITIONTEMPLATE_cannot_realize_if_model_is_not_local                ( EMH_PTN0PARTITIONTEMPLATE_error_base + 14 )

/**
 * The "Cloning or Realization" operation cannot be performed on Partitions with Variant Expressions, because the variability on the target model does not match with the variability on the source model.
 */
#define PTN0PARTITIONTEMPLATE_variablity_of_source_n_target_no_match              ( EMH_PTN0PARTITIONTEMPLATE_error_base + 15 )

/**
 * The "Update from Partition Template" operation cannot be performed on the selected Partition "%1$", because it violates uniqueness criteria for Partition. Change the source object of the source Partition and try the operation again.
 */
#define PTN0PARTITIONTEMPLATE_update_realized_partition_violate_unique            ( EMH_PTN0PARTITIONTEMPLATE_error_base + 16 )

/**
 * One or several mandatory input parameters are missing when the "%1$" ITK function is invoked. Please report this error to your system administrator.
 */
#define PTN0PARTITIONTEMPLATE_missing_mandatory_input_arguments                   ( EMH_PTN0PARTITIONTEMPLATE_error_base + 17 )

/**
 * The "Update from Partition Template" operation cannot be performed on the selected Partition, because its source Partition is checked-out.
 */
#define PTN0PARTITIONTEMPLATE_update_realized_partition_checked_out               ( EMH_PTN0PARTITIONTEMPLATE_error_base + 18 )

/**
 * The "Copy Realization References" option is not allowed for a Partition Template.
 */
#define PTN0PARTITIONTEMPLATE_copy_rlz_ref_not_allowed_for_pt                     ( EMH_PTN0PARTITIONTEMPLATE_error_base + 19 )

/**
 * The "Copy Realization References" option can be performed only from a realized Application Model object.
 */
#define PTN0PARTITIONTEMPLATE_copy_rlz_ref_poss_only_frm_rlz_mdl                  ( EMH_PTN0PARTITIONTEMPLATE_error_base + 20 )

/**
 * The "Update from Partition Template" operation cannot be performed, because no Partition exists in target model with selected Revision Rule.
 */
#define PTN0PARTITIONTEMPLATE_null_target_partition_for_update                    ( EMH_PTN0PARTITIONTEMPLATE_error_base + 21 )

/**
 * The "Partial Cloning" operation cannot be performed because no Partitions are provided to clone.
 */
#define PTN0PARTITIONTEMPLATE_cannot_clone_no_input_ptns                          ( EMH_PTN0PARTITIONTEMPLATE_error_base + 22 )

/**
 * The "Partial Cloning" operation cannot be performed because all Partitions provided are inactive or local.
 */
#define PTN0PARTITIONTEMPLATE_cannot_clone_all_input_ptns_ina_or_local            ( EMH_PTN0PARTITIONTEMPLATE_error_base + 23 )

/**
 * The Partitions cannot be cloned into the target model, because one or more duplicate Partitions are found.
 */
#define PTN0PARTITIONTEMPLATE_cannot_clone_duplicate_partition                    ( EMH_PTN0PARTITIONTEMPLATE_error_base + 24 )

/**
 * The "Cloning" operation cannot be performed, because "Exclude Local Partitions" option is selected, but the Partition Schemes are unrealized.
 */
#define PTN0PARTITIONTEMPLATE_exclude_local_no_realized_scheme                    ( EMH_PTN0PARTITIONTEMPLATE_error_base + 25 )

/**
 * The "Update from Partition Template" operation cannot be performed on the selected Partition "%1$", because its source Partition is inactive.
 */
#define PTN0PARTITIONTEMPLATE_inactive_source_partition_for_update                ( EMH_PTN0PARTITIONTEMPLATE_error_base + 26 )

/**
 * The "Update from Partition Template" operation cannot be performed on the selected Partition "%1$", because selected Partition is inactive.
 */
#define PTN0PARTITIONTEMPLATE_inactive_target_partition_for_update                ( EMH_PTN0PARTITIONTEMPLATE_error_base + 27 )

/**
 * The "Exclude Local Partitions" option is not allowed for a Partition Template.
 */
#define PTN0PARTITIONTEMPLATE_exclude_local_not_allowed_for_pt                    ( EMH_PTN0PARTITIONTEMPLATE_error_base + 28 )

/**
 * The input source model and target model are the same. Cloning/Realizing on self is not allowed.
 */
#define PTN0PARTITIONTEMPLATE_source_target_models_identical                      ( EMH_PTN0PARTITIONTEMPLATE_error_base + 29 )

#include <ptn0partitiontemplate/libptn0partitiontemplate_undef.h>
#endif
