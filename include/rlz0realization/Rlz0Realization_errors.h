/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2017.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Realization Error Codes Declaration

*/

#ifndef RLZ0REALIZATION_ERRORS_H
#define RLZ0REALIZATION_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup RLZ0REALIZATION_ERRORS Errors
    @ingroup RLZ0REALIZATION
    @{
*/
#define RLZ0REALIZATION_ERROR_BASE                                   EMH_RLZ0REALIZATION_error_base

/**
 * An internal error has occurred in the Realization module. Please report this error to your system administrator.
 */
#define RLZ0REALIZATION_internal_error                               ( EMH_RLZ0REALIZATION_error_base + 1 )

/**
 * The source model could not be configured.
 */
#define RLZ0REALIZATION_failed_to_configure_source_model             ( EMH_RLZ0REALIZATION_error_base + 2 )

/**
 * The input "%1$" is invalid.
 */
#define RLZ0REALIZATION_invalid_input                                ( EMH_RLZ0REALIZATION_error_base + 3 )

/**
 * The current user has no write access on the target model "%1$". Therefore, the source model cannot be created into the target model.
 */
#define RLZ0REALIZATION_no_add_content_access                        ( EMH_RLZ0REALIZATION_error_base + 4 )

/**
 * The default Revision Rule "%1$" is not set.
 */
#define RLZ0REALIZATION_no_default_DE_rev_rule_set                   ( EMH_RLZ0REALIZATION_error_base + 5 )

/**
 * The parent Design Element tag is null.
 */
#define RLZ0REALIZATION_null_parent_design_element_for_subordinate   ( EMH_RLZ0REALIZATION_error_base + 6 )

/**
 * A unique tag cannot be created. Please refer to the Teamcenter server syslog file for a possible cause of error.
 */
#define RLZ0REALIZATION_could_not_create_unique_tag                  ( EMH_RLZ0REALIZATION_error_base + 7 )

/**
 * The Design Element cannot be created. Please refer to the Teamcenter server syslog file for a possible cause of error.
 */
#define RLZ0REALIZATION_could_not_create_design_element              ( EMH_RLZ0REALIZATION_error_base + 8 )

/**
 * The Item Realization Map cannot be created. Please refer to the Teamcenter server syslog file for a possible cause of error.
 */
#define RLZ0REALIZATION_could_not_create_item_realization_map        ( EMH_RLZ0REALIZATION_error_base + 9 )

/**
 * The source model "%1$" is not valid.
 */
#define RLZ0REALIZATION_invalid_source_model                         ( EMH_RLZ0REALIZATION_error_base + 10 )

/**
 * The source assembly "%1$" is not precise. Please select a precise assembly, An assembly is a precise assembly when it contains specified revisions of components.
 */
#define RLZ0REALIZATION_source_not_precise                           ( EMH_RLZ0REALIZATION_error_base + 11 )

/**
 * The first entry for the Revision Rule "%1$" is not "Precise". Please select a Revision Rule which has first entry as Precise.
 */
#define RLZ0REALIZATION_revrule_first_entry_not_precise              ( EMH_RLZ0REALIZATION_error_base + 12 )

/**
 * The source revision "%1$" is not released.
 */
#define RLZ0REALIZATION_source_revisions_not_released                ( EMH_RLZ0REALIZATION_error_base + 13 )

/**
 * No Revision Rule is available to configure the source BOM. Please set the default Revision Rule.
 */
#define RLZ0REALIZATION_no_revision_rule                             ( EMH_RLZ0REALIZATION_error_base + 14 )

/**
 * More than one Realization instance exist for the Reuse Design Element "%1$". Please report this error to your system administrator.
 */
#define RLZ0REALIZATION_more_than_one_realization_exist              ( EMH_RLZ0REALIZATION_error_base + 15 )

/**
 * The realization updater could not find any Design Element for the parent BOM Line "%1$" while creating the child Design Element. Please report this error to your system administrator.
 */
#define RLZ0REALIZATION_parent_DE_does_not_exist                     ( EMH_RLZ0REALIZATION_error_base + 16 )

/**
 * The source model "%1$" has no configured revision. The Revision Rule used to configure the source model is "%2$". Please select a Revision Rule which will configure the source model so that there is at least one revision configured.
 */
#define RLZ0REALIZATION_no_configured_revision                       ( EMH_RLZ0REALIZATION_error_base + 17 )

/**
 * The source model contains remote objects, which is not allowed for the realization in the target model.
 */
#define RLZ0REALIZATION_remote_objects_not_allowed                   ( EMH_RLZ0REALIZATION_error_base + 18 )

/**
 * The Assembly Realization cannot be performed on the Application Model ";%1$";, because there is no product associated with the target model.
 */
#define RLZ0REALIZATION_no_product_itemrevision_attached             ( EMH_RLZ0REALIZATION_error_base + 19 )

/**
 * The Assembly Realization cannot be performed on the Application Model ";%1$";, because the variability of the product: ";%2$/%3$"; associated to the target model does not match the variability associated to the source assembly ";%4$";.
 */
#define RLZ0REALIZATION_product_mismatch_in_source_and_target_model  ( EMH_RLZ0REALIZATION_error_base + 20 )

/**
 * The Assembly Realization cannot be performed on the Application Model ";%1$";, because an invalid option ";%2$"; is identified in the Variant Condition of the object ";%3$";. Please ensure that all options families are defined in the Application Model Product Context ";%4$/%5$";.
 */
#define RLZ0REALIZATION_invalid_option_identified_in_source_model    ( EMH_RLZ0REALIZATION_error_base + 21 )

/**
 * No Source Model Configuration information is available for the object ";%1$"; while performing the operation ";%2$";.
 */
#define RLZ0REALIZATION_no_source_model_config_info                  ( EMH_RLZ0REALIZATION_error_base + 22 )

/**
 * The list of objects to be compared for update is empty.
 */
#define RLZ0REALIZATION_M2M_compare_list_empty                       ( EMH_RLZ0REALIZATION_error_base + 23 )

/**
 * The number of objects returned by the comparison engine for the source and target input lists is different. Please refer to the Teamcenter server syslog file for a possible cause of error.
 */
#define RLZ0REALIZATION_M2M_invalid_compared_list                    ( EMH_RLZ0REALIZATION_error_base + 24 )

/**
 * The input list of objects is empty. Properties cannot be retrieved from an empty list.
 */
#define RLZ0REALIZATION_M2M_invalid_list_of_elements                 ( EMH_RLZ0REALIZATION_error_base + 25 )

/**
 * The operation has failed, because the object ";%1$"; is of type ";%2$";, which is not supported.
 */
#define RLZ0REALIZATION_unsupported_bo_type_provided_as_input        ( EMH_RLZ0REALIZATION_error_base + 26 )

/**
 * No valid Source Model is provided as input.
 */
#define RLZ0REALIZATION_no_source_model_provided_as_input            ( EMH_RLZ0REALIZATION_error_base + 27 )

/**
 * No valid Target Model is provided as input.
 */
#define RLZ0REALIZATION_no_target_model_provided_as_input            ( EMH_RLZ0REALIZATION_error_base + 28 )

/**
 * No valid object name is provided as input for the Realization container.
 */
#define RLZ0REALIZATION_no_object_name_provided_as_input             ( EMH_RLZ0REALIZATION_error_base + 29 )

/**
 * No valid Realization container object is provided as input in order to update the Realization.
 */
#define RLZ0REALIZATION_no_realization_container_provided_as_input   ( EMH_RLZ0REALIZATION_error_base + 30 )

/**
 * The object ";%1$" is not a valid Realization container.
 */
#define RLZ0REALIZATION_not_realization_container                    ( EMH_RLZ0REALIZATION_error_base + 31 )

/**
 * No Realization object is available or has been created for the Realization container ";%1$";.
 */
#define RLZ0REALIZATION_no_realization_object                        ( EMH_RLZ0REALIZATION_error_base + 32 )

/**
 * The object referred by the Realization container ";%1$"; is not a valid Realization object.
 */
#define RLZ0REALIZATION_not_realization_object                       ( EMH_RLZ0REALIZATION_error_base + 33 )

/**
 * The Source Model information is not available for the Realization object from the Realization container ";%1$";.
 */
#define RLZ0REALIZATION_no_source_model                              ( EMH_RLZ0REALIZATION_error_base + 34 )

/**
 * The Target Model information is not available for the Realization object from the Realization container ";%1$";.
 */
#define RLZ0REALIZATION_no_target_model                              ( EMH_RLZ0REALIZATION_error_base + 35 )

/**
 * The search recipe information is not available for the Realization object from the Realization container ";%1$";.
 */
#define RLZ0REALIZATION_no_search_recipe                             ( EMH_RLZ0REALIZATION_error_base + 36 )

/**
 * The configuration context information is not available for the Realization object from the Realization container ";%1$";.
 */
#define RLZ0REALIZATION_no_config_context                            ( EMH_RLZ0REALIZATION_error_base + 37 )

/**
 * No valid Configuration Context is provided as input in order to perform Realization update.
 */
#define RLZ0REALIZATION_no_config_context_provided_as_input          ( EMH_RLZ0REALIZATION_error_base + 38 )

/**
 *  The Source Model for the Realization object and the input Application Model ";%1$"; do not match.
 */
#define RLZ0REALIZATION_source_model_mismatch                        ( EMH_RLZ0REALIZATION_error_base + 39 )

/**
 * No valid input list or subset definition or baseline revision is available for this Realization operation.
 */
#define RLZ0REALIZATION_no_configured_objects_to_realize             ( EMH_RLZ0REALIZATION_error_base + 40 )

/**
 * No valid list of objects to remove is available in order to perform the Realization update.
 */
#define RLZ0REALIZATION_no_configured_objects_to_remove              ( EMH_RLZ0REALIZATION_error_base + 41 )

/**
 * The ";check-out"; operation has failed on the object ";%1$";, because the operation is not allowed on Realization container objects.
 */
#define RLZ0REALIZATION_realization_container_checkout_not_allowed   ( EMH_RLZ0REALIZATION_error_base + 42 )

/**
 * The ";save as"; operation has failed on the object ";%1$";, because the operation is not allowed on Realization container objects.
 */
#define RLZ0REALIZATION_realization_container_saveas_not_allowed     ( EMH_RLZ0REALIZATION_error_base + 43 )

/**
 * The Business Constant ";%1$"; is not set for the Application Model ";%2$";. Please contact your system administrator to provide a property set to be used for the ";update"; operation.
 */
#define RLZ0REALIZATION_no_propertyset_for_update_operation          ( EMH_RLZ0REALIZATION_error_base + 44 )

/**
 * The value ";%1$"; provided for the synchronization flag ";%2$"; as input for this Realization operation is invalid. The only valid input values are "true" and "false".
 */
#define RLZ0REALIZATION_invalid_aux_info                             ( EMH_RLZ0REALIZATION_error_base + 45 )

/**
 * The input Model Element type must either be a Design Element or a Realization Container.
 */
#define RLZ0REALIZATION_invalid_modelelement_type                    ( EMH_RLZ0REALIZATION_error_base + 46 )

/**
 * No valid input object is provided in order to uncouple the Model Realization.
 */
#define RLZ0REALIZATION_uncouple_realization_invalid_input           ( EMH_RLZ0REALIZATION_error_base + 47 )

/**
 * The "Uncouple Model Realization" operation has failed, because no Model Realized content is selected.
 */
#define RLZ0REALIZATION_uncouple_realization_failed                  ( EMH_RLZ0REALIZATION_error_base + 48 )

/**
 * The current user does not have the requested ";%1$"; access privilege on the object ";%2$"; to be able to perform full or sparse realization.
 */
#define RLZ0REALIZATION_no_access_privilege                          ( EMH_RLZ0REALIZATION_error_base + 49 )

/**
 * The provided target model element is not of type ";Composition";.
 */
#define RLZ0REALIZATION_target_not_composition_type                  ( EMH_RLZ0REALIZATION_error_base + 50 )

/**
 * The ";Sparse Realization"; operation has failed to create the Subset business object. Please check the syslog for error message and take corrective actions.
 */
#define RLZ0REALIZATION_failed_to_create_subset                      ( EMH_RLZ0REALIZATION_error_base + 51 )

/**
 * The Baseline Definition of the provided Baseline Revision ";%1$"; does not contain any search recipe, which is needed to perform the ";Sparse Realization"; operation. Please add a search term to the Baseline Definition.
 */
#define RLZ0REALIZATION_empty_baseline_recipe                        ( EMH_RLZ0REALIZATION_error_base + 52 )

/**
 * No valid Revision Rule is provided as input to the realization operation.
 */
#define RLZ0REALIZATION_no_model_to_model_revision_rule              ( EMH_RLZ0REALIZATION_error_base + 53 )

/**
 * No valid Composition or Subset object is provided as input to the expand operation.
 */
#define RLZ0REALIZATION_no_object_to_expand                          ( EMH_RLZ0REALIZATION_error_base + 54 )

/**
 * The provided number of levels to expand is invalid. Valid values are 0 or 1 for this operation.
 */
#define RLZ0REALIZATION_invalid_range                                ( EMH_RLZ0REALIZATION_error_base + 55 )

/**
 * The required input for specifying the source model elements for realization is not provided. Please specify either a Configuration Context, or a Baseline Revision, or select a list of model elements as input for sparse realization.
 */
#define RLZ0REALIZATION_recipe_baseline_source_element               ( EMH_RLZ0REALIZATION_error_base + 56 )

/**
 * The required input for specifying the source model elements for realization is not provided. Provide either a search recipe or an outer recipe as input.
 */
#define RLZ0REALIZATION_recipe_baseline                              ( EMH_RLZ0REALIZATION_error_base + 57 )

/**
 * Open baselines are not supported as input for sparse realization. Please provide a closed baseline.
 */
#define RLZ0REALIZATION_provide_closed_baseline                      ( EMH_RLZ0REALIZATION_error_base + 58 )

/**
 * The object ";%1$"; cannot be deleted because it contains children. Please expand the object and delete all its children first
 */
#define RLZ0REALIZATION_element_has_children                         ( EMH_RLZ0REALIZATION_error_base + 59 )

/**
 * At least one BOM Line object contains a quantity value on an occurrence. Carrying forward of quantity values to Realized Items is not supported
 */
#define RLZ0REALIZATION_source_has_quantity_value                    ( EMH_RLZ0REALIZATION_error_base + 60 )

/**
    The preference ";%1$"; contains the invalid Item types: %2$. Please report this error to your system administrator.
*/
#define RLZ0REALIZATION_invalid_item_types                           ( EMH_RLZ0REALIZATION_error_base + 61 )

/**
 * The creation of the Item Realization was stopped, because the Closure Rule ";%1$"; is not available. Please provide a valid Closure Rule name.
 */
#define RLZ0REALIZATION_invalid_closure_rule_name                    ( EMH_RLZ0REALIZATION_error_base + 62 )

/**
 * The creation of the Item Realization was stopped, because no clause is configured on the Closure Rule ";%1$";. Please correct the Closure Rule definition or contact your system administrator.
 */
#define RLZ0REALIZATION_closure_rule_without_clauses                 ( EMH_RLZ0REALIZATION_error_base + 63 )

/**
 * The creation of the Item Realization was stopped, because the Closure Rule ";%1$"; requires parameterized information for evaluation. Please provide a Closure Rule that does not require parameterized information for evaluation.
 */
#define RLZ0REALIZATION_non_self_sufficient_closure_rule             ( EMH_RLZ0REALIZATION_error_base + 64 )

/**
 * The operation has failed, because the Model-to-Model source object ";%1$"; of type ";%2$"; is a remote object owned by the site ";%3$";.
 */
#define RLZ0REALIZATION_source_model_is_remote_object                ( EMH_RLZ0REALIZATION_error_base + 65 )

/**
 * No valid Composition input is provided for sparse realization. Please provide either a composition or the required attributes to create a composition.
 */
#define RLZ0REALIZATION_no_composition_input                         ( EMH_RLZ0REALIZATION_error_base + 66 )

/**
 * No matching Source Element can be found for the Sparse Element "%1$". Please refer to the Teamcenter server syslog file for a possible cause of error.
 */
#define RLZ0REALIZATION_no_matching_source_element                   ( EMH_RLZ0REALIZATION_error_base + 67 )

/**
 * The operation is not supported for sparse element. Instead, perform the same operation on the source object "%1$" from the source application model "%2$".
 */
#define RLZ0REALIZATION_operation_not_supported_for_sparse           ( EMH_RLZ0REALIZATION_error_base + 68 )

/**
 * A Subset object must be provided as input to the Update Sparse Realization operation.
 */
#define RLZ0REALIZATION_no_update_subset_input                       ( EMH_RLZ0REALIZATION_error_base + 69 )

/**
 * No Realization object is available or has been created for the input Subset object.
 */
#define RLZ0REALIZATION_no_subet_realization_object                  ( EMH_RLZ0REALIZATION_error_base + 70 )

/**
 * The object referred by the input Subset "%1$" is not a valid Realization object.
 */
#define RLZ0REALIZATION_subset_not_realization_object                ( EMH_RLZ0REALIZATION_error_base + 71 )

/**
 * The configuration context information is not available for the update of the Realization object of input Subset "%1$".
 */
#define RLZ0REALIZATION_no_config_context_for_subset_realization     ( EMH_RLZ0REALIZATION_error_base + 72 )

/**
 * The search recipe information is not available for the Realization object of input Subset "%1$".
 */
#define RLZ0REALIZATION_no_search_recipe_for_subset_realization      ( EMH_RLZ0REALIZATION_error_base + 73 )

/**
    The Assembly Realization cannot be performed, because the View Type "%1$" is not found on the source assembly "%2$".
*/
#define RLZ0REALIZATION_incorrect_viewtypename_identified_in_source_model  ( EMH_RLZ0REALIZATION_error_base + 74 )

/**
 * The search recipe execution has not returned any valid elements for the realization update operation for the input Subset "%1$".
 */
#define RLZ0REALIZATION_no_valid_objects_for_subset_realization      ( EMH_RLZ0REALIZATION_error_base + 75 )

/**
 * The input list of elements contain a mix of sparse elements and regular elements. The operation you are trying to perform is only supported for either sparse elements or regular elements.
 */
#define RLZ0REALIZATION_input_mix_elements                           ( EMH_RLZ0REALIZATION_error_base + 76 )

/**
 * The target object "%1$" is not a local object.
 */
#define RLZ0REALIZATION_not_a_local_object                           ( EMH_RLZ0REALIZATION_error_base + 77 )

/**
 * The provided object "%1$" is not of type "Subset".
 */
#define RLZ0REALIZATION_not_subset_type                              ( EMH_RLZ0REALIZATION_error_base + 78 )

/**
 * The objects provided for the update sparse realization operation do not have the same configuration as the target instance object "%1$".
 */
#define RLZ0REALIZATION_no_same_configured_objects_to_realize        ( EMH_RLZ0REALIZATION_error_base + 79 )

/**
 * The input product or plant ID is invalid.
 */
#define RLZ0REALIZATION_invalid_product_or_plant_id                  ( EMH_RLZ0REALIZATION_error_base + 80 )

/**
 * The Composition "%1$" cannot be compared by the "4GD to 4GD compare and accountability" functionality, because it contains subset belonging to more than one Application Model. Please select individual subset to compare.
 */
#define RLZ0REALIZATION_subset_different_models_error                ( EMH_RLZ0REALIZATION_error_base + 81 )

 /**
 * One or more of the input source model objects do not belong to the Subset "%1$".
 */
#define RLZ0REALIZATION_source_objects_not_belong_to_subset          ( EMH_RLZ0REALIZATION_error_base + 82 )

/**
 * No Subset is provided.
 */
#define RLZ0REALIZATION_null_subset                                  ( EMH_RLZ0REALIZATION_error_base + 83 )

/**
 * No Model Element is provided.
 */
#define RLZ0REALIZATION_empty_model_element_list                     ( EMH_RLZ0REALIZATION_error_base + 84 )

/**
 * The Composition "%1$" cannot be compared by the "4GD to 4GD compare and accountability" functionality, because it contains subsets having different Configuration Contexts. Please select an individual subset to compare.
 */
#define RLZ0REALIZATION_subset_different_configuration_context_error ( EMH_RLZ0REALIZATION_error_base + 85 )

/**
 * The operation only supports using sparse elements, but either a mix of sparse elements and regular elements or only regular elements are provided.
 */
#define RLZ0REALIZATION_input_not_sparse                             ( EMH_RLZ0REALIZATION_error_base + 86 )

/**
 * The provided object "%1$" is not of type "Subset" or "SubsetInstance".
 */
#define RLZ0REALIZATION_not_subset_or_subsetinstance_type            ( EMH_RLZ0REALIZATION_error_base + 87 )

/**
 * The operation has failed because no primary object is provided.
 */
#define RLZ0REALIZATION_invalid_primary_elements                     ( EMH_RLZ0REALIZATION_error_base + 88 )

/**
 * The operation has failed because no secondary object is provided.
 */
#define RLZ0REALIZATION_invalid_secondary_elements                   ( EMH_RLZ0REALIZATION_error_base + 89 )

/**
 * The Relation could not be created, because no Relation type input is provided.
 */
#define RLZ0REALIZATION_invalid_relation_types                       ( EMH_RLZ0REALIZATION_error_base + 90 )

/**
 * The operation has failed because no source element is provided.
 */
#define RLZ0REALIZATION_invalid_source_elements                      ( EMH_RLZ0REALIZATION_error_base + 91 )

/**
 * The "retrieve compositions content information" operation has failed because no valid Composition is provided.
 */
#define RLZ0REALIZATION_invalid_composition_reference                ( EMH_RLZ0REALIZATION_error_base + 92 )

/**
 * Attribute group types could not be created, because no valid attribute group type is provided.
 */
#define RLZ0REALIZATION_invalid_attribute_group_type                 ( EMH_RLZ0REALIZATION_error_base + 93 )

/**
 * Attribute groups could not be created, because no valid attribute group name is provided.
 */
#define RLZ0REALIZATION_invalid_attribute_group_name                 ( EMH_RLZ0REALIZATION_error_base + 94 )

/**
 * The operation has failed while looking for relations because of inconsistency in realization objects.
 */
#define RLZ0REALIZATION_input_size_mismatch                          ( EMH_RLZ0REALIZATION_error_base + 95 )

/**
 * The operation has failed because both primary and secondary provided objects are sparse objects.
 */
#define RLZ0REALIZATION_both_input_sparse                            ( EMH_RLZ0REALIZATION_error_base + 96 )

/*
 * The realization operation has failed because the "Synchronize Variant" option is enabled and
 * the Product Configurator module is not installed. Please contact your system administrator.
 */
#define RLZ0REALIZATION_cannot_perform_realization_with_var_data     ( EMH_RLZ0REALIZATION_error_base + 97 )

/**
 * The port "%1$" is a nested port. Realization of nested ports is not supported.
 */
#define RLZ0REALIZATION_port_contains_port                           ( EMH_RLZ0REALIZATION_error_base + 98 )

/**
 * The creation of objects of type "%1$" is not supported. Objects should be of type "%2$" or any of its subtypes. Please verify the mapping defined through business constant %3$ for "%4$".
 */

#define RLZ0REALIZATION_object_creation_not_supported                ( EMH_RLZ0REALIZATION_error_base + 99 )

/**
 * The provided override folder "%1$" and the one "%2$" (specified in the Revision Rule "%3$") must be the same.
 */

#define RLZ0REALIZATION_override_folder_not_same                     ( EMH_RLZ0REALIZATION_error_base + 100 )

/**
 * "%1$" does not support Item realization. Only objects of the following type support that: %2$.
 */

#define RLZ0REALIZATION_item_realization_not_supported               ( EMH_RLZ0REALIZATION_error_base + 101 )

/**
 * An invalid Revision rule "%1$" is provided while performing Imprecise Realization. Please provide a supported Revision rule.
 */

#define RLZ0REALIZATION_revision_rule_not_valid                      ( EMH_RLZ0REALIZATION_error_base + 102 )

 /**
 * The Logical Object "%1$" cannot be added to a Subset of the content type "Persistent". Please ensure that only persistent Business Objects are added to this Subset.
 */

#define RLZ0REALIZATION_invalid_logical_object_in_subset             ( EMH_RLZ0REALIZATION_error_base + 103 )

 /**
 * The persistent Business Object "%1$" cannot be added to a Subset of content type "Logical". Please ensure that only Logical Business Objects are added to this Subset.
 */

#define RLZ0REALIZATION_invalid_persistent_object_in_subset          ( EMH_RLZ0REALIZATION_error_base + 104 )

 /**
 * The session recoverable ID of the Logical Object that needs to be persisted in the Subset, cannot be obtained. Please ensure that the Logical Objects support session recovery.
 */

#define RLZ0REALIZATION_session_recovery_not_supported               ( EMH_RLZ0REALIZATION_error_base + 105 )

/**
    @}
*/
#endif
