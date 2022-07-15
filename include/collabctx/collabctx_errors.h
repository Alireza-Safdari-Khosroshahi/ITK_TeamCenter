/*==============================================================================
Copyright (c) 2003-2005 UGS Corporation
Unpublished - All Rights Reserved
==============================================================================*/

/**
@file

Collaboration Context module errors
*/

/*  */

#ifndef COLLABCTX_ERRORS_H
#define COLLABCTX_ERRORS_H

#include <common/emh_const.h>

#include <collabctx/libcollabctx_exports.h>

/**
@defgroup COLLABCTX_ERRORS Errors
@ingroup COLLABCTX
@{
*/

/** Fail when initialize CC module */
#define COLLABCTX_initialization_failed                         (EMH_COLLABCTX_error_base + 1)

#define COLLABCTX_invalid_structure_context                     (EMH_COLLABCTX_error_base + 2)
#define COLLABCTX_invalid_closure_rule                          (EMH_COLLABCTX_error_base + 3)
#define COLLABCTX_fail_to_add_structure_context                 (EMH_COLLABCTX_error_base + 4)
#define COLLABCTX_application_id_not_defined                    (EMH_COLLABCTX_error_base + 5)
#define COLLABCTX_fail_to_add_content_object                    (EMH_COLLABCTX_error_base + 6)
#define COLLABCTX_fail_to_set_study                             (EMH_COLLABCTX_error_base + 7)
#define COLLABCTX_invalid_ccobject                              (EMH_COLLABCTX_error_base + 8)
#define COLLABCTX_invalid_sctype                                (EMH_COLLABCTX_error_base + 9)

#define COLLABCTX_duplicate_sctype_data                         (EMH_COLLABCTX_error_base + 10)
#define COLLABCTX_sctype_data_exists                            (EMH_COLLABCTX_error_base + 11)

#define COLLABCTX_single_end_item_error                         (EMH_COLLABCTX_error_base + 12)
#define COLLABCTX_not_structure_error                           (EMH_COLLABCTX_error_base + 13)
#define COLLABCTX_invalid_variant_rule                          (EMH_COLLABCTX_error_base + 14)
#define COLLABCTX_invalid_revision_rule                         (EMH_COLLABCTX_error_base + 15)

/**
@name For assign
@{
*/

#define COLLABCTX_assign_occgrp_to_noncomposition_disallowed    (EMH_COLLABCTX_error_base + 16)
#define COLLABCTX_assign_from_composition_disallowed            (EMH_COLLABCTX_error_base + 17)
#define COLLABCTX_bomlines_not_aligned                          (EMH_COLLABCTX_error_base + 18)

#define COLLABCTX_not_linked_structure                          (EMH_COLLABCTX_error_base + 19)
#define COLLABCTX_data_not_synchronized                         (EMH_COLLABCTX_error_base + 20)
#define COLLABCTX_packed_occurrence_disallowed                  (EMH_COLLABCTX_error_base + 21)
#define COLLABCTX_invalid_arrangement                           (EMH_COLLABCTX_error_base + 22)
#define COLLABCTX_cannot_create_report_data_xml                 (EMH_COLLABCTX_error_base + 23)

/*
Error codes for EBOP accountability checking
*/
#define COLLABCTX_no_apn                                        (EMH_COLLABCTX_error_base + 24)
#define COLLABCTX_no_absocc                                     (EMH_COLLABCTX_error_base + 25)
#define COLLABCTX_no_origin                                     (EMH_COLLABCTX_error_base + 26)
#define COLLABCTX_no_secondary                                  (EMH_COLLABCTX_error_base + 27)
#define COLLABCTX_not_bop_line                                  (EMH_COLLABCTX_error_base + 28)
#define COLLABCTX_no_primary                                    (EMH_COLLABCTX_error_base + 29)
#define COLLABCTX_test_fail                                     (EMH_COLLABCTX_error_base + 30)

#define COLLABCTX_no_net_eff_preference                         (EMH_COLLABCTX_error_base + 31)
#define COLLABCTX_expand_by_rule_fail                           (EMH_COLLABCTX_error_base + 32)
#define COLLABCTX_unreadable_child_lines                        (EMH_COLLABCTX_error_base + 33)

/*
Error code for assign and carrying forward the absocc attachments
*/
#define COLLABCTX_invalid_preference_value                      (EMH_COLLABCTX_error_base + 34)

#define COLLABCTX_no_target_line                                (EMH_COLLABCTX_error_base + 35)
#define COLLABCTX_return_exceed_limit                           (EMH_COLLABCTX_error_base + 36)
#define COLLABCTX_equivalence_service_not_initialized           (EMH_COLLABCTX_error_base + 37)
#define COLLABCTX_ebop_compare_not_set                          (EMH_COLLABCTX_error_base + 38)

/*
Error code to handle auototest errors
*/
#define COLLABCTX_cpd_equivalence_test_fail                     (EMH_COLLABCTX_error_base + 39)

#define COLLABCTX_async_not_working                             (EMH_COLLABCTX_error_base + 40)

/** The accountability check report cache is null. No report data is generated. Please contact your system administrator to correct the report cache. */
#define COLLABCTX_null_cache_in_accountability_report           (EMH_COLLABCTX_error_base + 41)

/** The operation has failed due to invalid input data. Please consult the syslog file for more information.*/
#define COLLABCTX_invalid_input_data                            (EMH_COLLABCTX_error_base + 42)

/** The selected operation does not support usage of the multiple variant rules for Configuration Context. Please use a single variant rule.*/
#define COLLABCTX_multiple_variant_rule_not_supported           (EMH_COLLABCTX_error_base + 43)

/** @} */

/**
@name For Accountability Check Favorites
@{
*/

/**
The specified favorite is from a version of Teamcenter that is not supported in this release.
*/
#define COLLABCTX_acfavorites_version_not_supported                 (EMH_COLLABCTX_error_base + 44)

/**
The specified dataset UID "%1$" does not belong to a valid dataset.
*/
#define COLLABCTX_acfavorites_not_valid_dataset                     (EMH_COLLABCTX_error_base + 45)

/**
The favorites XML file cannot be created, because no transient volume directory is specified.
*/
#define COLLABCTX_acfavorites_no_transient_vol_dir                  (EMH_COLLABCTX_error_base + 46)

/**
The accountability check favorite XML file for the favorite "%1$" is invalid. It may contain entries that are not understood by the parser. Please report this error to your system administrator.
*/
#define COLLABCTX_acfavorites_invalid_xml                           (EMH_COLLABCTX_error_base + 47)

/**
The Dataset "%1$" is missing a named reference file.
*/
#define COLLABCTX_acfavorites_missing_ref_file                      (EMH_COLLABCTX_error_base + 48)

/**
The reference file "%1$" under the Dataset "%2$" has an invalid extension. It must be ".xml".
*/
#define COLLABCTX_acfavorites_invalid_ref_file_extension            (EMH_COLLABCTX_error_base + 49)

/**
Either no value or an invalid value is specified for the activities property preference "MEAccountabilityCheckIncludedActivityProperties".
*/
#define COLLABCTX_acfavorites_invalid_activity_pref                 (EMH_COLLABCTX_error_base + 50)

/**
No reconstructed line is found.
*/
#define COLLABCTX_no_reconstructed_line                             (EMH_COLLABCTX_error_base + 51)

/**
The following object types cannot be compared because no property is specified for comparison: %1$.
*/
#define COLLABCTX_no_property_specified_for_comparison              (EMH_COLLABCTX_error_base + 52)

/**
The following object types specified in the custom equivalence global constant "%2$" are invalid: %1$.
*/
#define COLLABCTX_invalid_object_type                               (EMH_COLLABCTX_error_base + 53)

/**
The following properties specified in the custom equivalence global constant "%2$" are invalid: %1$.
*/
#define COLLABCTX_invalid_property_for_object_type                  (EMH_COLLABCTX_error_base + 54)

/**
* The Workset "%1$" cannot be compared by the "4GD to 4GD compare and accountability" functionality, because it contains subset elements belonging to more than one Application Model. Please select individual subset elements to compare.
*/
#define COLLABCTX_subset_different_models_error                     (EMH_COLLABCTX_error_base + 55)

/**
* The Workset "%1$" cannot be compared by the "4GD to 4GD compare and accountability" functionality, because it contains subset elements having different Configuration Context. Please select individual subset elements to compare.
*/
#define COLLABCTX_subset_different_configuration_context_error      (EMH_COLLABCTX_error_base + 56)

/**
The following properties specified in the input do not exist in the global constant "%2$": %1$.
*/
#define COLLABCTX_property_does_not_exist_in_business_constant      (EMH_COLLABCTX_error_base + 57)

/**
The object "%1$" is not configured.
*/
#define COLLABCTX_object_not_configured_error                       (EMH_COLLABCTX_error_base + 58)

/**
There is a mismatch in the configuration context with that set on input request for the object "%1$".
*/
#define COLLABCTX_mismatch_in_configuration_context_error           (EMH_COLLABCTX_error_base + 59)

/**
The "4GD to 4GD compare and accountability" operation cannot be performed, because the source "%1$" does not have any content.
*/
#define COLLABCTX_source_contents_are_empty_error                   (EMH_COLLABCTX_error_base + 60)

/**
The "4GD to 4GD compare and accountability" operation cannot be performed, because either the source or target contains conditional elements from different application models.
*/
#define COLLABCTX_conditional_elements_from_different_models_error  (EMH_COLLABCTX_error_base + 61)

/**
The "4GD to 4GD compare and accountability" operation cannot be performed, because either the source or target contains conditional elements with different configuration contexts.
*/
#define COLLABCTX_conditional_elements_having_different_config_context  (EMH_COLLABCTX_error_base + 62)

/**
The "4GD to 4GD compare and accountability" operation cannot be performed, because either the source or target contains a vector of elements mixed with containers.
*/
#define COLLABCTX_conditional_elements_mixed_with_container         (EMH_COLLABCTX_error_base + 63)

/**
The "4GD to 4GD compare and accountability" operation cannot be performed, because either the source or target contains a vector of elements mixed with non-conditional elements.
*/
#define COLLABCTX_non_conditional_element_not_supported             (EMH_COLLABCTX_error_base + 64)

/**
Closure Rules are not supported by the 4GD to 4GD compare and accountability functionality.
*/
#define COLLABCTX_closure_rule_not_supported                        (EMH_COLLABCTX_error_base + 65)

/**
The Partition "%1$" is without any valid configuration context. It is, therefore, not supported by the 4GD to 4GD compare and accountability functionality.
*/
#define COLLABCTX_partition_without_configuration_context_not_supported      (EMH_COLLABCTX_error_base + 66)

/**
The parameter Mfg0connected_parts is not supported by the 4GD to 4GD compare and accountability functionality.
*/
#define COLLABCTX_parameter_mfg0connected_parts_is_not_supported             (EMH_COLLABCTX_error_base + 67)

/**
The parameter cpd_bom_effectivity is not supported by the 4GD to 4GD compare and accountability functionality.
*/
#define COLLABCTX_parameter_cpd_bom_effectivity_is_not_supported             (EMH_COLLABCTX_error_base + 68)

/**
Application Models are not supported as selected objects by the 4GD to 4GD compare and accountability functionality.
*/
#define COLLABCTX_application_model_not_supported_as_selected_object         (EMH_COLLABCTX_error_base + 69)

/**
Historical Partitions are not supported as selected objects by the 4GD to 4GD compare and accountability functionality.
*/
#define COLLABCTX_historical_partition_not_supported_as_selected_object      (EMH_COLLABCTX_error_base + 70)

/**
No valid criterion is found for the given input scope.
*/
#define COLLABCTX_valid_criteria_not_found                                   (EMH_COLLABCTX_error_base + 71)

/**
Changes can be propagated from alternative Collaboration Context (CC) only. Please select an alternative CC.
*/
#define COLLABCTX_easypropagation_invalid_input                              (EMH_COLLABCTX_error_base + 72)

/**
Partial errors while creating BOM Windows for the given list of Structure Context objects.
*/
#define COLLABCTX_partial_error_for_bom_window_create_for_structure_context  (EMH_COLLABCTX_error_base + 73)

/** @} */

/** @} */

#include <collabctx/libcollabctx_undef.h>
#endif
