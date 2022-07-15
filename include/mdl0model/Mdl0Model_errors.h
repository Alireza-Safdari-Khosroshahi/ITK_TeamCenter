/*Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2016.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software*/

/**
    @file

    Application Model Error Codes Declaration

*/

#ifndef MDL0MODEL_ERRORS_H
#define MDL0MODEL_ERRORS_H

/*================================================================================================*/
#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif

#include <mdl0model/libmdl0model_exports.h>

/*================================================================================================*/

/**
    @defgroup MDL0MODEL_ERRORS MDL0MODEL Errors
    @ingroup MDL0MODEL
    @{
*/

#define MDL0MODEL_ERROR_BASE                                   EMH_MDL0MODEL_error_base

/**
 * An internal error has occurred: &quot;%1$&quot;.
 */
#define MDL0MODEL_internal_error                                    ( MDL0MODEL_ERROR_BASE + 1 )

/**
 *  The provided tag is null.
 */
#define MDL0MODEL_null_tag                                          ( MDL0MODEL_ERROR_BASE + 2 )

/**
 * The Model Behavior of object &quot;%1$&quot; needs to be specified.
 */
#define MDL0MODEL_missing_model_behavior                            ( MDL0MODEL_ERROR_BASE + 3 )

/**
 * The Model Content Behavior of object &quot;%1$&quot; needs to be specified.
 */
#define MDL0MODEL_missing_modelcontent_behavior                     ( MDL0MODEL_ERROR_BASE + 4 )

/**
 * The object &quot;%2$&quot; of type &quot;%1$&quot; is not allowed in the Model &quot;%3$&quot;.
 */
#define MDL0MODEL_element_not_allowed_in_model                      ( MDL0MODEL_ERROR_BASE + 5 )

/**
 * The Configuration Context and the Revision Rule cannot be NULL at the same time.
 */
#define MDL0MODEL_invalid_revision_rule_in_config_context           ( MDL0MODEL_ERROR_BASE + 6 )

/**
 * A NULL Application Model is not allowed in a Search Recipe.
 */
#define MDL0MODEL_invalid_application_model                         ( MDL0MODEL_ERROR_BASE + 7 )

/**
 * Saved Query has a class that is invalid for this Search Recipe.
 */
#define MDL0MODEL_invalid_saved_query_in_search                     ( MDL0MODEL_ERROR_BASE + 8 )

/**
 * Group Operators cannot be any other than AND, OR or NOT in a Group Search Recipe.
 */
#define Mdl0Model_invalid_group_operator                            ( MDL0MODEL_ERROR_BASE + 9 )

/**
 * An invalid Box Zone operator is specified in the Search Recipe.
 * Only Inside, Outside, BoxIntersect, InsideOrIntersects, and OutsideOrIntersects
 * are the supported values.
 */
#define Mdl0Model_invalid_box_operator                              ( MDL0MODEL_ERROR_BASE + 10 )

/**
 * Sort Attributes should be formatted as &quot;ClassName.AttributeName&quot; in Search Recipes.
 */
#define Mdl0Model_improper_format_for_sort_attribute                ( MDL0MODEL_ERROR_BASE + 11 )

/**
 * The OR predicate can only be used in Outer Most Search expressions.
*/
#define Mdl0Model_invalid_usage_of_or_predicate                     ( MDL0MODEL_ERROR_BASE + 12 )

/**
 * NOT is a unary operator; Multiple expressions beneath a NOT operator are invalid.
 */
#define Mdl0Model_invalid_usage_of_unary_not_predicate              ( MDL0MODEL_ERROR_BASE + 13 )

/**
 * NOT is restricted to be used only in conjunction with an IN List.
 */
#define Mdl0Model_invalid_sub_expression_for_not_expression         ( MDL0MODEL_ERROR_BASE + 14 )

/**
 * An invalid Plane Zone operator is specified in the Search Recipe.
 * Only PlaneAbove, PlaneBelow, PlaneIntersects, PlaneAboveOrIntersects, and
 * PlaneBelowOrIntersects are the supported values.
 */
#define Mdl0Model_invalid_plane_operator                            ( MDL0MODEL_ERROR_BASE + 15 )

/**
 * The user %1$ does not have the needed privilege to access the Model Object.
 */
#define MDL0MODEL_no_access_privilege                               ( MDL0MODEL_ERROR_BASE + 16 )

/**
 * n invalid recipe container object &quot;%1$&quot; is used in the recipe container adaptor &quot;%2$&quot;.<
 */
#define Mdl0Model_invalid_recipe_container                          ( MDL0MODEL_ERROR_BASE + 17 )

/**
 * The lock of the next ID for the property &quot;%1$&quot; on the type &quot;%2$&quot; has failed after %3$ retries.
 */
#define Mdl0Model_next_id_lock_failed                               ( MDL0MODEL_ERROR_BASE + 18 )

/**
 * The type &quot;%1$&quot; is not supported for ID auto-generation.
 */
#define Mdl0Model_unsupported_type                                  ( MDL0MODEL_ERROR_BASE + 19 )

/**
 * The customized ID value &quot;%1$&quot; for the property &quot;%3$&quot; on the type &quot;%2$&quot; is already used.
 */
#define Mdl0Model_customized_id_does_exist                          ( MDL0MODEL_ERROR_BASE + 20 )

/**
 * An object of type &quot;%2$&quot; is expected instead of a type &quot;%1$&quot;.
 */
#define MDL0MODEL_type_not_expected                                 ( MDL0MODEL_ERROR_BASE + 21 )

/**
 * The transformation matrix is invalid. A valid transformation matrix must contain 16 double values.
 */
#define MDL0MODEL_invalid_transform_matrix                          ( MDL0MODEL_ERROR_BASE + 22 )

/**
 * The revision rule &quot;%1$&quot; does not have any valid clause.
 */
#define MDL0MODEL_no_valid_clause_in_revision_rule                  ( MDL0MODEL_ERROR_BASE + 23 )

/**
 * The working user entry is invalid in the revision rule. A valid user entry must be attached.
 */
#define MDL0MODEL_invalid_working_user_entry                        ( MDL0MODEL_ERROR_BASE + 24 )

/**
 * The working group entry is invalid in the revision rule. A valid group entry must be attached.
 */
#define MDL0MODEL_invalid_working_group_entry                       ( MDL0MODEL_ERROR_BASE + 25 )

/**
 * The status entry is invalid in the revision rule. A valid status entry must be attached.
 */
#define MDL0MODEL_invalid_status_entry                              ( MDL0MODEL_ERROR_BASE + 26 )

/**
 * The given Search Recipe to load is invalid because it contains invalid Recipe criteria objects.
 */
#define MDL0MODEL_invalid_recipe_to_load                            ( MDL0MODEL_ERROR_BASE + 27 )

/**
 * The given Search Recipe contains an invalid set of sort attributes. Sort attributes must be completely valid for all results.
 */
#define MDL0MODEL_invalid_set_of_sort_attributes                    ( MDL0MODEL_ERROR_BASE + 28 )

/**
 * The sort attribute &quot;%1$&quot; is not part of the sort list.
 */
#define MDL0MODEL_attribute_not_part_of_the_sortlist                ( MDL0MODEL_ERROR_BASE + 29 )

/**
 * The revision rule &quot;%1$&quot; contains an invalid clause &quot;%2$&quot; for configuring major revisions in Model Context.
 */
#define MDL0MODEL_invalid_revision_rule_clause                      ( MDL0MODEL_ERROR_BASE + 30 )

/**
 * A NOT expression cannot be a root of the Search Recipe.
 */
#define MDL0MODEL_not_expression_cannot_be_root                     ( MDL0MODEL_ERROR_BASE + 31 )

/**
 * The Model object cannot be deleted because it is not empty. Remove its contents first and try again to delete it.
 */
#define MDL0MODEL_cannot_delete_has_contents                        ( MDL0MODEL_ERROR_BASE + 32 )

/**
 * The following proximity targets are missing valid bounding box definitions: %1$.
 */
#define MDL0MODEL_invalid_proximity_target                          ( MDL0MODEL_ERROR_BASE + 33 )

/**
 * The following selected proximity targets are missing their TrueShape information: %1$.
 */
#define MDL0MODEL_invalid_trushape_data_target                      ( MDL0MODEL_ERROR_BASE + 34 )

/**
 * A Business Object &quot;%1$&quot; already exists with properties &quot;%2$&quot;.
 * Please specify at least one unique value to create the Business Object &quot;%3$&quot;.
 */
#define MDL0MODEL_inst_violates_unique                              ( MDL0MODEL_ERROR_BASE + 35 )

/**
 * The object &quot;%1$&quot; cannot be revised because the object &quot;%2$&quot; does not have a status.
 */
#define MDL0MODEL_object_has_no_status                              ( MDL0MODEL_ERROR_BASE + 36 )

/**
 * The object &quot;%1$&quot; cannot be modified because it has been obsoleted.
 */
#define MDL0MODEL_obsolete_object_not_modifiable                    ( MDL0MODEL_ERROR_BASE + 37 )

/**
 * The object &quot;%1$&quot; cannot be checked-out because it has been obsoleted.
 */
#define MDL0MODEL_obsolete_object_not_checkoutable                  ( MDL0MODEL_ERROR_BASE + 38 )

/**
 * The Deep Copy Data for the selected object "%1$" cannot be retrieved. Please refer to the following Teamcenter server syslog file for more information: %2$.
 */
#define MDL0MODEL_object_deepcopy_data_cannot_be_retrieved          ( MDL0MODEL_ERROR_BASE + 39 )

/**
 * A relation of type &quot;%5$&quot; cannot be created between given model content objects of types &quot;%1$&quot; and &quot;%3&quot;.
 * The reason is that the model content objects belong to different model objects (&quot;%2$&quot; and &quot;%4$&quot;).
 */
#define MDL0MODEL_content_from_different_models                     ( MDL0MODEL_ERROR_BASE + 40 )

/**
 * The following object type is not configured to allow the revise operation: %1$. If this is needed, please contact your
 * system administrator to make the needed changes in Business Modeler IDE (BMIDE).
 */
#define MDL0MODEL_revise_not_supported                              ( MDL0MODEL_ERROR_BASE + 41 )

 /**
 * The option set search expression must be at the top level of a recipe.
 */
#define MDL0MODEL_option_set_expression_not_at_top                  ( MDL0MODEL_ERROR_BASE + 42 )

/**
 * An invalid argument has been given as input: &quot;%1$&quot;.
 */
#define MDL0MODEL_invalid_input                                     ( MDL0MODEL_ERROR_BASE + 43 )

/**
 * The proximity search distance exceeds the maximum allowed limit of "1000000000000000.0" meters
 */
#define MDL0MODEL_invalid_proximity_distance                        ( MDL0MODEL_ERROR_BASE + 44 )

/**
 * The model object of the importing model element object &quot;%1$&quot; is not valid.
 */
#define MDL0MODEL_invalid_model_object_for_import                   ( MDL0MODEL_ERROR_BASE + 45 )

/**
 * The selected objects are inactive. In order to make them active, please close the application and re-launch it.
 */
#define MDL0MODEL_invalid_ConfigurationContext                      ( MDL0MODEL_ERROR_BASE + 46 )

/**
 * An invalid snapshot date "%1$" has been provided. A valid value is between the purge limit (%2$) and the current time (%3$).
 */
#define MDL0MODEL_invalid_snapshot_date                             ( MDL0MODEL_ERROR_BASE + 47 )

/**
 * A snapshot date cannot be set on the baseline &quot;%1$&quot;, because the supporting baseline &quot;%2$&quot; has no snapshot date.
 */
#define MDL0MODEL_supporting_baseline_no_snapshot_date              ( MDL0MODEL_ERROR_BASE + 48 )

/**
 * A snapshot date cannot be set on the baseline &quot;%1$&quot;, because the supporting baseline &quot;%2$&quot; has no status.
 */
#define MDL0MODEL_supporting_baseline_no_status                     ( MDL0MODEL_ERROR_BASE + 49 )

/**
 * The promote transfer option set "%1$", for model type "%2$", could not be found.
 */
#define MDL0MODEL_promote_tos_not_found                             ( MDL0MODEL_ERROR_BASE + 50 )

/**
 * The promotion has failed, because the following non-revisable objects are not released: %1$.
 * These objects are related to the following promotion targets: %2$.
 */
#define MDL0MODEL_non_rev_promote_objects_not_released              ( MDL0MODEL_ERROR_BASE + 51 )

/**
 * The Configuration Context is not available. Please provide a valid Configuration Context.
 */
#define MDL0MODEL_no_config_context_provided                        ( MDL0MODEL_ERROR_BASE + 52 )

/**
 * The operation has no object to work on, because either the supplied input objects are invalid or the supplied subset definition is empty.
 */
#define MDL0MODEL_no_objects_found_to_perform_the_operation         ( MDL0MODEL_ERROR_BASE + 53 )

/**
 * An internal error has occurred while performing the clone operation. Please check the Teamcenter server syslog file for more information.
 */
#define MDL0MODEL_clone_internal_error                              ( MDL0MODEL_ERROR_BASE + 54 )

/**
 * The following unsupported objects of type &quot;%1$&quot; are ignored for the operation: %2$.
 */
#define MDL0MODEL_unsupported_objects_ignored                       ( MDL0MODEL_ERROR_BASE + 55 )

/**
 * No target Application Model was provided as input.
 */
#define MDL0MODEL_no_target_applicationmodel_provided_as_input      ( MDL0MODEL_ERROR_BASE + 56 )

/**
 * No source Application Model was provided as input.
 */
#define MDL0MODEL_no_source_applicationmodel_provided_as_input      ( MDL0MODEL_ERROR_BASE + 57 )

/**
 * The Baseline Revision &quot;%1$&quot; used for a configured export has not been closed. Only closed Baseline Revisions can be selected to export, or used for a configured export.
 */
#define MDL0MODEL_open_baselinerevision_export_error                ( MDL0MODEL_ERROR_BASE + 58 )

/**
 * Missing Attribute, The attribute &quot;%1$&quot; is ignored for the override operation.
 */
#define MDL0MODEL_override_attribute_ignored                        ( MDL0MODEL_ERROR_BASE + 59 )

 /**
 * The flag for deleting &quot;%1$&quot; override is ignored for the remove override operation.
 */
#define MDL0MODEL_removeoverride_attribute_ignored                  ( MDL0MODEL_ERROR_BASE + 60 )

/**
 * Cannot create and delete position override in the same operation.
 */
#define MDL0MODEL_positionoverride_error                            ( MDL0MODEL_ERROR_BASE + 61 )

/**
 * The Positioned Geometry for the Model Element &quot;%1$&quot; is not found.
 */
#define MDL0MODEL_position_geometry_not_found_error                 ( MDL0MODEL_ERROR_BASE + 62 )

/**
 * The Bounding Box matrix is invalid. A valid Bounding Box matrix must contain 6 double values.
 */
#define MDL0MODEL_invalid_bounding_box_matrix                       ( MDL0MODEL_ERROR_BASE + 63 )

/**
 * The Transfer Option Set &quot;%1$&quot; specified for the business constant "Mdl0M2MTOS" either does not exist or is invalid. Please provide a valid Transfer Option Set
 */
#define MDL0MODEL_invalid_tos_for_m2m                               ( MDL0MODEL_ERROR_BASE + 64 )

/**
 * The Model-to-Model operation cannot be performed on the Application Model &quot;%1$&quot;, because no product is associated to it. Attach a valid product to the Application Model in order to perform this operation.
 */
#define MDL0MODEL_no_product_attached                               ( MDL0MODEL_ERROR_BASE + 65 )

/**
 * The Model-to-Model operation cannot be performed on the Application Model &quot;%1$&quot;, because the variability of the product &quot;%2$/%3$&quot; associated to it does not match the variability associated to the source model &quot;%4$&quot;. Check at least a product is attached to the source and the target Application Models.
 */
#define MDL0MODEL_product_mismatch_in_source_and_target_model       ( MDL0MODEL_ERROR_BASE + 66 )

/**
 * Model-to-Model operations do not support multiple revisions of the same Element. Please check if the effectivity is specified as a range.
 */
#define MDL0MODEL_multipe_revisions_not_supported                   ( MDL0MODEL_ERROR_BASE + 67 )

/**
 * An internal error has occurred while reading the Business Object Constant &apos;Mdl0M2MCopyReuseAndAllSubordinates&apos;. Please check the Teamcenter server syslog file for more information.
 */
#define MDL0MODEL_reuse_and_subordinate_bo_error                    ( MDL0MODEL_ERROR_BASE + 68 )

/**
 * An invalid Process Control Flag (%1$) is specified in the Geometric Constraint Search. Supported values are &quot;5-7&quot; and &quot;13-15&quot;.
 */
#define Mdl0Model_invalid_process_control_flag                      ( MDL0MODEL_ERROR_BASE + 69 )

 /**
 * No source criteria is provided for the Geometric Constraint Search.
 */
#define MDL0MODEL_no_source_criteria                                ( MDL0MODEL_ERROR_BASE + 70 )

/**
 * A recipe, a container, or both must be supplied to the "search" operation. Please report this error to your system administrator.
 */
#define MDL0MODEL_no_recipe_or_container                            ( MDL0MODEL_ERROR_BASE + 71 )

/**
 * The sample object &quot;%1$&quot; is not configurable.
 */
#define MDL0MODEL_invalid_minor_configuration_sample                ( MDL0MODEL_ERROR_BASE + 72 )

/**
 * The source object &quot;%1$&quot; is not configurable.
 */
#define MDL0MODEL_invalid_minor_configuration_source                ( MDL0MODEL_ERROR_BASE + 73 )

/**
 * The operation has failed, because the object &quot;%1$&quot; is a remote object.
 */
#define MDL0MODEL_remote_object                                     ( MDL0MODEL_ERROR_BASE + 74 )

/**
 * No supporting recipe is available for the object &quot;%1$&quot;.
 */
#define MDL0MODEL_supporting_recipe_unavailable                     ( MDL0MODEL_ERROR_BASE + 75 )

/**
 * The input list of objects provided for the "%1$" operation are from different Application Models.
 * Please select Model Elements from the same Application Model.
 */
#define MDL0MODEL_objects_from_different_models                     ( MDL0MODEL_ERROR_BASE + 76 )

/**
 * The Model-to-Model operation has failed, because the Application Model "%1$" to which the list
 * of Model Elements belong and the Application Model "%2$" passed as input, are not the same.
 */
#define MDL0MODEL_different_application_models                      ( MDL0MODEL_ERROR_BASE + 77 )

/**
 * The operation has failed for the object "%1$", because selective historical objects are not supported for Model-to-Model operations.
 */
#define MDL0MODEL_historical_objects_not_supported                  ( MDL0MODEL_ERROR_BASE + 78 )

/**
 * The business constant "Mdl0M2MTOS" is not set for the Application Model &quot;%1$&quot;. Please refer to the technical documentation on Model-to-Model configuration to set a value.
 */
#define MDL0MODEL_tos_not_set_for_m2m                               ( MDL0MODEL_ERROR_BASE + 79 )

/**
 * The Transfer Option Set &quot;%1$&quot; specified for the business constant "Mdl0M2MTOS" is invalid. Either the Transfer Option Set is empty or no Closure Rule is specified.
 */
#define MDL0MODEL_invalid_option_set                                ( MDL0MODEL_ERROR_BASE + 80 )

/**
 * The operation has failed for the remote object &quot;%1$&quot; of type &quot;%2$&quot; and ID &quot;%3$&quot;, because the latest historical revision is missing locally.
 */
#define MDL0MODEL_remote_object_with_missing_latest_history         ( MDL0MODEL_ERROR_BASE + 81 )

/**
 * The operation has no object to work on, because either the source objects are invalid for the Clone operation, or the closure rule execution on the source Application Model resulted in zero objects.
 */
#define MDL0MODEL_no_objects_found_for_full_model_clone             ( MDL0MODEL_ERROR_BASE + 82 )

/**
 * The object &quot;%1$&quot; specified in auxiliary object list is not part of cloned data. Attribute set on objects is not supported if the objects are not cloned.
 */
#define MDL0MODEL_object_not_found_in_cloned_content                ( MDL0MODEL_ERROR_BASE + 83 )

/**
 * 4GD Baseline export for all revisions with "include contents" is not allowed. Please check option values in the "%1$" optionset or in the input argument.
 */
#define MDL0MODEL_4GD_baseline_allrevs_withcontents_disallowed      ( MDL0MODEL_ERROR_BASE + 84 )

/**
 * The viewing context stack contains no configuration context instances.
 */
#define MDL0MODEL_empty_viewing_context                             ( MDL0MODEL_ERROR_BASE + 85 )

/**
 * The cparam of the active configuration context and the cparam of the object are different.
 */
#define MDL0MODEL_inconsistent_cparam                               ( MDL0MODEL_ERROR_BASE + 86 )

/**
 * The object "%1$" cannot be updated, because it has been modified in a different session by the same user. Refresh the object before making new modifications.
 */
#define MDL0MODEL_object_is_modified                                ( MDL0MODEL_ERROR_BASE + 87 )

/**
 * The following objects cannot be revised, because they have been edited in a change space: %1$.
 */
#define MDL0MODEL_cannot_revise_objects_locked_by_change_space      ( MDL0MODEL_ERROR_BASE + 88 )

/**
 * The object "%1$" cannot be revised, because it was created in a markup or change space.
 */
#define MDL0MODEL_cannot_revise_objects_created_in_space            ( MDL0MODEL_ERROR_BASE + 89 )

/**
  *  The proximity search node could not be created, because the proximity search does not
  *  return the same number of target elements and their corresponding offsets
  */
#define MDL0MODEL_no_matching_offsets_to_targets                    ( MDL0MODEL_ERROR_BASE + 90 )

/**
  * The Plane normal coordinates are invalid. A valid set of plane normal coordinates must have the magnitude as 1 (unit normal vector).
  */
#define MDL0MODEL_invalid_plane_coordinates                         ( MDL0MODEL_ERROR_BASE + 91 )

/**
 * The Saved Query Filter "%1$" should return at least one result.
 */
#define MDL0MODEL_saved_query_filter_returns_no_results             ( MDL0MODEL_ERROR_BASE + 92 )

/**
 * The number of related objects does not correspond to the number of results columns in the Saved Query Filter "%1$".
 */
#define MDL0MODEL_mismatch_in_expected_configurable_related_objects ( MDL0MODEL_ERROR_BASE + 93 )

/**
 * Revisions are missing when performing a cut and paste. Please select all revisions.
 */
#define MDL0MODEL_revision_missing_for_cut_paste                    ( MDL0MODEL_ERROR_BASE + 94 )

/**
 * The value for the property "%1$" on "%2$" exceeds the limit of 999.
 */
#define MDL0MODEL_invalid_revision_id_value                         ( MDL0MODEL_ERROR_BASE + 95)

/**
 * The comparison is skipped for the following objects, because the relation "Attach Attribute Group" contains more than one instance of the secondary attached to either of the primary conditional elements: %1$.
 */
#define MDL0MODEL_attr_group_has_more_than_one_instance             ( MDL0MODEL_ERROR_BASE + 96 )

/**
 * The Application Model "%1$" does not have "ConfiguredSearchable" behavior
 */
#define MDL0MODEL_no_configuredsearchable_behavior                  ( MDL0MODEL_ERROR_BASE + 97 )

/**
 * The "promote to history" feature has been disabled by the preference "MDL_enable_preproduction_promote_to_history".
 * Please contact your system administrator for more information.
 */
#define MDL0MODEL_promote_to_history_disabled                       ( MDL0MODEL_ERROR_BASE + 98 )

/**
 * The following object type does not allow setting the Effectivity formula: %1$.
 */

#define MDL0MODEL_effectivity_setting_not_supported                 ( MDL0MODEL_ERROR_BASE + 99 )

/**
 * The following object type does not allow setting the Variant formula: %1$.
 */
#define MDL0MODEL_variant_setting_not_supported                     ( MDL0MODEL_ERROR_BASE + 100 )

/**
 * "%1$" cannot be revised for discontinuation because it is already a discontinued revision.
 */
#define MDL0MODEL_invalid_discontinue_operation                     ( MDL0MODEL_ERROR_BASE + 101 )

/**
 * No relation can be created between "%1$" and "%2$" because they are both present in unrelated change contexts.
 */
#define MDL0MODEL_unable_to_relate_objects                          ( MDL0MODEL_ERROR_BASE + 102 )

/**
 * "%1$" cannot be revised because its thread has been deleted.
 */
#define MDL0MODEL_cannot_revise_objects_thread_is_deleted           ( MDL0MODEL_ERROR_BASE + 103 )

/**
 * The Traversable adapter was not found for the given business object "%1$" and the Traversal Key "%2$".
 */
#define MDL0MODEL_traversable_adapter_not_found                     ( MDL0MODEL_ERROR_BASE + 104 )

/**
 * The Traversable adapter did not set information on column "%1$", as required to perform a configured search.
 */
#define MDL0MODEL_traversable_adapter_missing_required_column       ( MDL0MODEL_ERROR_BASE + 105 )

/**
 * "%1$" is not a valid Composite Search Type.
 */
#define MDL0MODEL_invalid_composite_search_type                     ( MDL0MODEL_ERROR_BASE + 106 )

/**
 * The Composite Search term cannot be created with empty search definitions.
 */
#define MDL0MODEL_invalid_composite_search_defs                     ( MDL0MODEL_ERROR_BASE + 107 )

/**
 * "%1$" is not a valid root object type
 */
#define MDL0MODEL_invalid_root_type                                 ( MDL0MODEL_ERROR_BASE + 108 )

/**
 * The Presented Parent property is undefined on the input model element "%1$" of type "%2$".
 */
#define MDL0MODEL_presented_parent_is_empty                         ( MDL0MODEL_ERROR_BASE + 109 )

 /**
 * The operation is not supported for source objects that exist in a Change Context different from the target Change Context.
 */
#define MDL0MODEL_source_objects_exists_in_different_space          ( MDL0MODEL_ERROR_BASE + 110 )

/**
 * "%1$" is not a valid traversal key.
 */
#define MDL0MODEL_invalid_traversal_key                             ( MDL0MODEL_ERROR_BASE + 111 )

/**
 *  Model Element objects cannot be created in a Change Context inside Application Models for which the property "Supports Snapshots" is "true".
 */
#define MDL0MODEL_invalid_content_for_model_supporting_snapshot     ( MDL0MODEL_ERROR_BASE + 112 )

/**
 *  The "Supports Snapshot" property cannot be changed to "true" on a non-empty Application Model.
 */
#define MDL0MODEL_model_cannot_support_snapshot                     ( MDL0MODEL_ERROR_BASE + 113 )

/**
 *  Snapshots are supported only on Application Models for which the "Supports Snapshot" property is "true".
 */
#define MDL0MODEL_invalid_model_object_for_snapshot                 ( MDL0MODEL_ERROR_BASE + 114 )

/**
 * The input object "%1$" is not a Snapshot. A valid Snapshot must be provided.
 */
#define MDL0MODEL_invalid_snapshot                                  ( MDL0MODEL_ERROR_BASE + 115 )

/**
 * The Classification ID "%1$" is invalid.
 */
#define MDL0MODEL_invalid_classification                            ( MDL0MODEL_ERROR_BASE + 116 )

/**
 *  Snapshots cannot be reopened.
 */
#define MDL0MODEL_snapshot_cannot_reopened                          ( MDL0MODEL_ERROR_BASE + 117 )

/**
 * A value for search type filter must be provided when "Include All" expression is part of the search.
 */
#define MDL0MODEL_no_filter_list_found_with_include_all_search       ( MDL0MODEL_ERROR_BASE + 118 )

/**
 * The Domain View Key "%1$" is invalid, because it is not listed in the preference category "Interface.Common Client.DomainViews".
 */
#define MDL0MODEL_invalid_domain_view_key                           ( MDL0MODEL_ERROR_BASE + 119 )

/*
 * &quot;%1$&quot; was not submitted because it is configured by the Revision Rule &quot;%2$&quot;
 * which allows modification.
 */
#define MDL0MODEL_cannot_submit_revision_rule_allows_modification   ( MDL0MODEL_ERROR_BASE + 120 )

/*
 * Preferences for Smart Baseline are disabled. Enable the preferences &quot;1&quot; and &quot;1&quot; and try again.
 */
#define MDL0MODEL_smart_preferences_not_set_for_baseline            ( MDL0MODEL_ERROR_BASE + 121 )

/**
 *  Operation "Snapshot" or "Restore" are only supported on Application Models for which the "Supports Snapshot" property is "true".
 */
#define MDL0MODEL_invalid_operation_on_model_object                 ( MDL0MODEL_ERROR_BASE + 122 )

/**
 *  The operation "%1$" cannot be executed on model "%2$" because operation "%3$" is already running.
 */
#define MDL0MODEL_multiple_operation_on_model_not_supported         ( MDL0MODEL_ERROR_BASE + 123 )

 /**
 *  The Application Model with ID "%1$" does not exist.
 */
#define MDL0MODEL_model_does_not_exist                              ( MDL0MODEL_ERROR_BASE + 124 )


/**
    @}
    @defgroup MDL0MODELGEOMETRY_ERROR MDL0MODELGEOMETRY Errors
    @ingroup MDL0MODELGEOMETRY
    @{
*/

#define MDL0MODELGEOMETRY_ERROR_BASE                                                               ( MDL0MODEL_ERROR_BASE + 700 )

/**
 * An internal error has occurred: &quot;%1$&quot;.
 */
#define MDL0MODELGEOMETRY_internal_error                                                           ( MDL0MODELGEOMETRY_ERROR_BASE + 1 )

/**
 * For the input configuration, no foreground member revisions from any container iteration configure and hence no best iteration can be found for the geometric container %1.
 * Use a different configuration, change to precise navigation mode or confirm that this container is the desired constraint container.
 */
#define MDL0MODELGEOMETRY_no_constraint_container_configures                                       ( MDL0MODELGEOMETRY_ERROR_BASE + 2 )

/**
 * The NavigationMode is set to CONFIGURED but a configuration context has not been given.
 * Send a valid configuration context that can configure model content or change the NavigationMode to PRECISE.
 */
#define MDL0MODELGEOMETRY_missing_configuration_context                                            ( MDL0MODELGEOMETRY_ERROR_BASE + 3 )

/**
 * The positioned model element &quot;%1$&quot; is already a foreground member in the geometric constraint container &quot;%2$&quot;.
 * A model element may only be a foreground member in a single geometric constraint container.
 * Remove the object from its current constraint container prior to attempting to add it to a different collection.
 */
#define MDL0MODELGEOMETRY_only_foreground_in_single_constraint_collection                          ( MDL0MODELGEOMETRY_ERROR_BASE + 4 )

/**
 * A constraint container can only have one working iteration at a time.
 * The changes being attempted must be made against that working iteration ( iteration %1$ )
 * or the working iteration must have its members released in order to be superseded by another working iteration.
 */
#define MDL0MODELGEOMETRY_another_working_iteration_exists_in_constraint_container                 ( MDL0MODELGEOMETRY_ERROR_BASE + 5 )

/**
 * The addition of the remote geometry object &quot;%1$&quot; to a constraint collection as a foreground member has failed, because the object cannot be modified.
 */
#define MDL0MODELGEOMETRY_cannot_add_remote_object_in_constraint_collection                        ( MDL0MODELGEOMETRY_ERROR_BASE + 6 )

/**
 * The following members could not be added to the constraint collection as foreground members, because they are released: %1$.
 */
#define MDL0MODELGEOMETRY_cannot_add_released_member_as_foreground_in_constraint_collection        ( MDL0MODELGEOMETRY_ERROR_BASE + 7 )

/**
 * The object "%2$" of type "%1$" cannot be released, because the object "%4$" of type "%3$" corresponding to the %1$ is checked-out.
 * Please check-in the %3$, and submit the %1$ to the workflow once again.
 */
#define MDL0MODELGEOMETRY_source_object_checked_out                                                ( MDL0MODELGEOMETRY_ERROR_BASE + 8 )

/**
  * The "updateContainer2" operation has failed, because the "shouldOverwriteIteration" parameter is set to false and the constraint iteration cannot be overwritten. Please report this error to your system administrator.
  */
#define MDL0MODELGEOMETRY_cannot_overwrite_constraint_iteration                                    ( MDL0MODELGEOMETRY_ERROR_BASE + 9 )

/**
 * The Positioned Model Element cannot be added to the Geometric Connectivity Group "%1$", because the Geometric Connectivity Group is a remote object.
 */
#define MDL0MODELGEOMETRY_cannot_add_pme_to_remote_connectivity_group                              ( MDL0MODELGEOMETRY_ERROR_BASE + 10 )

/**
 * The positioned geometry of the Positioned Model Element "%1$" can only be deleted when "%1$" is deleted.
 */
#define MDL0MODELGEOMETRY_invalid_delete_positioned_geometry                                       ( MDL0MODELGEOMETRY_ERROR_BASE + 11 )

/**
 * The Positioned Model Element "%1$" does not contain any positioned geometry.
 */
#define MDL0MODELGEOMETRY_invalid_missing_positioned_geometry                                      ( MDL0MODELGEOMETRY_ERROR_BASE + 12 )

/**
 * Perspective values cannot be provided when setting the transformation on a Positioned Model Element.
 */

#define MDL0MODELGEOMETRY_invalid_perspective_values                                               ( MDL0MODELGEOMETRY_ERROR_BASE + 13 )

/**
 * The sorting request cannot be performed because of mismatch in number of sort attributes and sort orders provided.
 */
#define MDL0MODEL_mismatch_in_sortorders_and_sortattributes_size                                   ( MDL0MODELGEOMETRY_ERROR_BASE + 14 )

/**
* Rotation values do not form an orthogonal matrix in the transformation being set on the Positioned Model Element "%1$".
*/
#define MDL0MODELGEOMETRY_invalid_rotation_values                                                  ( MDL0MODELGEOMETRY_ERROR_BASE + 15 )

/**

    @}
*/

#include <mdl0model/libmdl0model_undef.h>
#endif

