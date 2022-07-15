/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2016.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file
    Product Configurator Application Error Codes Declaration
*/

#ifndef CFG0CONFIGURATOR_ERRORS_HXX
#define CFG0CONFIGURATOR_ERRORS_HXX

#include <common/emh_const.h>
#include <common/tc_deprecation_macros.h>

/**
    @defgroup CFG0CONFIGURATOR_ERRORS Configurator Errors
    @ingroup CFG0CONFIGURATOR
    @{
*/

#define EMH_CFG0CONFIGURATOR_ERROR_BASE                                                 EMH_CFG0CONFIGURATOR_error_base

/**
 * An internal error has occurred in the module Cfg0configurator: %1$. Please report this error to your system administrator.
 */
#define CFG0CONFIGURATOR_internal_error                                                 ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 1 )

/**
 * The provided Thread CreateInput is of type "%1$". An object of type or subtype of "%2$" is expected.
 */
#define CFG0CONFIGURATOR_invalid_thread_type                                            ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 2 )

/**
 * A Unit of Measure cannot be specified for the non-numeric family "%1$".
 */
#define CFG0CONFIGURATOR_family_invalid_uom                                             ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 3 )

/**
 * The family "%1$" is not allowed to be set as a "%2$" family, because its data type "%3$" does not allow multiple values.
 */
#define CFG0CONFIGURATOR_invalid_logical_family                                         ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 4 )

/**
 * The operation has failed, because another object already uses this instance. Please refer to the preceding errors in this error stack for more information.
 */
#define CFG0CONFIGURATOR_inst_is_used_by_inaccessile_objects                            ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 5 )

/**
 * The Options referenced by the Rule "%1$" are not present in the following Product Items: %2$. Please refer to the syslog for more information.
 */
#define CFG0CONFIGURATOR_contexts_missing_options                                       ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 6 )

/**
 * The family "%1$" for the namespace "%2$" is in an invalid format.
 */
#define CFG0CONFIGURATOR_family_invalid_format                                          ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 7 )

/**
 * The value "%1$" for the family "%2$" is in an invalid format.
 */
#define CFG0CONFIGURATOR_value_invalid_format                                           ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 8 )

/**
 * The object "%2$" of type "%1$" cannot contain %4$ objects of type "%3$". Objects of type "%1$" can only contain %5$ such objects.
 */
#define CFG0CONFIGURATOR_opval_nesting_not_allowed                                      ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 9 )

/**
 * The object "%2$" of type "%1$" cannot contain the object "%3$" of type "%4$", because the member objects of type "%4$" are not allowed for "%1$".
 */
#define CFG0CONFIGURATOR_compound_opval_invalid_contents                                ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 10 )

/**
 * The provided input array for the property "%1$" contains the following duplicates: %2$.
 */
#define CFG0CONFIGURATOR_duplicate_exists                                               ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 11 )

/**
 * The Product Model "%1$" cannot belong to multiple Product Items.
 */
#define CFG0CONFIGURATOR_model_cannot_belong_to_mulitple_products                       ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 12 )

/**
 * The list of values for the property "%1$" of the object "%2$" cannot contain any null values.
 */
#define CFG0CONFIGURATOR_array_has_nulls                                                ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 13 )

/**
 * The object "%1$" cannot have a value for both properties "%2$" and "%3$".
 */
#define CFG0CONFIGURATOR_mutually_exclusive_properties                                  ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 14 )

/**
 * The object "%1$" of type "%2$" does not support allocation.
 */
#define CFG0CONFIGURATOR_invalid_bo_for_allocation                                      ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 15 )

/**
 * The object "%1$" of type "%2$" must contain a subject expression.
 */
#define CFG0CONFIGURATOR_missing_subject_for_rule                                       ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 16 )

/** @deprecated #CFG0CONFIGURATOR_missing_payload_for_rule deprecated in Teamcenter 11.2.3. Use #CFG0CONFIGURATOR_missing_subject_for_rule instead. */
#define CFG0CONFIGURATOR_missing_payload_for_rule                                       ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 16 )
TC_DEPRECATED_PREPROCESSOR( "11.2.3", CFG0CONFIGURATOR_missing_payload_for_rule, "CFG0CONFIGURATOR_missing_subject_for_rule" )
/**
 * The input boolean expression is null.
 */
#define CFG0CONFIGURATOR_boolean_expression_is_null                                     ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 17 )

/**
 * The input Product Context is null.
 */
#define CFG0CONFIGURATOR_product_context_is_null                                        ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 18 )

/**
 * Setting a value range for the family "%1$" has failed, because its setting "%2$" does not support feature ranges.
 */
#define CFG0CONFIGURATOR_family_value_range_error                                       ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 19 )

/**
 * The date value "%1$" for the family "%2$" is not formatted according to ISO-8601, or is missing the time zone information.
 */
#define CFG0CONFIGURATOR_invalid_date_format                                            ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 20 )

/**
 * The value "%1$" for the family "%2$" is in an invalid numeric format.
 */
#define CFG0CONFIGURATOR_invalid_numeric_format                                         ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 21 )

/**
 * The creation or update of values for the object "%1$" of type "Boolean Option" family is not allowed.
  */
#define CFG0CONFIGURATOR_logical_data_type_values_error                                 ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 22 )

/**
 * No Family "%1$" with the namespace "%2$" can be found.
 */
#define CFG0CONFIGURATOR_option_family_not_found                                        ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 23 )

/**
 * The object "%2$" of type "%1$" cannot be created, because it belongs to the object "%4$" of type "%3$" which accepts free-form values. Please refer to documentation for more details.
 */
#define CFG0CONFIGURATOR_free_form_family_option_value_not_allowed                      ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 24 )

/**
 * The operation has failed, because the Family "%1$" contains mixture of positive and negative values.
 */
#define CFG0CONFIGURATOR_pos_neg_terms_not_allowed_in_group                             ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 25 )

/**
 * The object "%2$" of type "%1$" contains Features from the following families: %3$, %4$. Objects of type "%2$" can summarize Features only from a single family.
 */
#define CFG0CONFIGURATOR_summary_options_should_belongs_to_same_family                  ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 26 )

/**
 * The object "%2$" of type "%1$" is not supported for availability creation. Availability can be created for objects of type "%3$" and "%4$" only.
 */
#define CFG0CONFIGURATOR_unsupported_type_for_availability                              ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 27 )

/**
 * The object "%2$" of type "%1$" cannot contain multiple Features that belong to the same family "%3$". Please refer to documentation for more details.
 */
#define CFG0CONFIGURATOR_multiple_values_from_single_select_family                      ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 28 )

/**
 * The availability for the object "%1$" of type "%2$" cannot be removed, because it is a member of the object "%3$" of type "%4$".
 */
#define CFG0CONFIGURATOR_model_member_availability_error                                ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 29 )

/**
 * The definition of the search criteria object of type "%1$" is invalid.
 */
#define CFG0CONFIGURATOR_invalid_search_criteria                                        ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 30 )

/**
 * The value "%1$" for the family "%2$" cannot be saved, because it is outside the provided minimum/maximum value range "%3$".
 */
#define CFG0CONFIGURATOR_min_max_range_values_error                                     ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 31 )

/**
 * The value range limit for the family "%1$" cannot be set to "%2$", because it would exclude the existing Feature "%3$": %4$ %5$ %6$.
 */
#define CFG0CONFIGURATOR_min_max_values_error                                           ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 32 )

/**
 * The operation has failed, because the Product Item "%1$" contains legacy variant data. Use a Product Item that does not contain any legacy variant data.
 */
#define CFG0CONFIGURATOR_product_item_has_legacy_variant                                ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 33 )

/**
 * The provided variant expression types for the object "%1$" of type "%2$" are invalid: %4$. Valid values are: %3$.
 */
#define CFG0CONFIGURATOR_unsupported_variant_expression_types                           ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 34 )

/**
 * The object type "%1$" should not be attached to an Item of type "%2$".
 */
#define CFG0CONFIGURATOR_dictionary_item_type_used                                      ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 35 )

/**
 * The sort attribute "%1$" for search results is not formatted properly. It should be formatted as follows: "className.attributeName" or "className.attributeName.columnIndex".
 */
#define CFG0CONFIGURATOR_improper_format_for_sort_attribute                             ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 36 )

/**
 * The object "%2$" of type "%1$" cannot be deallocated, unless dependent objects allocated by the Product Context "%3$" are deallocated. Please refer to the preceding errors in this error stack for more information.
 */
#define CFG0CONFIGURATOR_object_deallocation_error                                      ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 37 )

/**
 * The object "%1$" of type "%2$" is implicitly available to the object "%3$" of type "%4$".
 */
#define CFG0CONFIGURATOR_object_implicitly_available                                    ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 38 )

/**
 * The object "%2$" of type "%1$" cannot be defined as belonging to a "%3$" family, because as such it would need to only contain a collection (AND/OR combination) of Features.
 */
#define CFG0CONFIGURATOR_compound_family_invalid_property_value                         ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 39 )

/**
 * The provided object type is invalid: %4$. The family object "%1$" of type "%2$" must be associated with value objects of type "%3$" or any of its sub-types.
 */
#define CFG0CONFIGURATOR_incompatible_value_type_for_family                             ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 40 )

/**
 * The provided value data type is invalid: "%4$". The property "%1$" for the object of type "%2$" must have its value as "%3$".
 */
#define CFG0CONFIGURATOR_invalid_property_value_for_model_family                        ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 41 )

/**
 * The value "%1$" for the family "%2$" is invalid, because it is not an integer.
 */
#define CFG0CONFIGURATOR_invalid_integer_format                                         ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 42 )

/**
 * The object "%2$" of type "%1$" is used by the object "%4$" of type "%3$".
 */
#define CFG0CONFIGURATOR_object_is_used                                                 ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 43 )

/**
 * The object "%1$" is not unique, because the Feature "%2$" already exists in the family "%3$" which belongs to the namespace "%4$".
 */
#define CFG0CONFIGURATOR_option_value_not_unique                                        ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 44 )

/**
 * The object "%1$" violates a uniqueness constraint for the family "%2$" in the family namespace "%3$".
 */
#define CFG0CONFIGURATOR_family_not_unique                                              ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 45 )

/**
 * The object "%1$" of type "%2$" cannot be saved, because the settings for the following properties are incompatible: %3$.
 */
#define CFG0CONFIGURATOR_invalid_property_combination                                   ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 46 )

/**
 * The object "%1$" of type "%2$" cannot have members "%3$", because they belong to the same mutually exclusive family "%4$".
 */
#define CFG0CONFIGURATOR_package_option_invalid_members                                 ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 47 )

/**
 * The definition of the search result column at index %1$ is invalid for search definitions of type "%2$".
 */
#define CFG0CONFIGURATOR_invalid_search_result_column                                   ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 48 )

/**
 * The cursor of type "%1$" has no results to fetch, because it is at the end of the results.
 */
#define CFG0CONFIGURATOR_cursor_exhausted_error                                         ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 49 )

/**
 * The object "%1$" is not suitable to verify data consistency for the object "%2$".
 */
#define CFG0CONFIGURATOR_data_inconsistency                                             ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 50 )

/**
 * The availability for the object "%1$" of type "%2$" cannot be removed from the object "%3$" of type "%4$", because there are dependent objects of type "%5$" available to the object "%3$".
 */
#define CFG0CONFIGURATOR_availability_removal_error                                     ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 51 )

/**
 * The object "%1$" of type "%2$" is now deallocated, but is referenced in objects of type "%3$". This means that the reference to this object is now broken.
 */
#define CFG0CONFIGURATOR_member_value_deallocation_problem                              ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 52 )

/**
 * The value for the property "%1$" for the object "%2$" of type "%3$" cannot contain the object "%4$" of type "%5$".
 */
#define CFG0CONFIGURATOR_invalid_expression_for_rule                                    ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 53 )

/**
 * The property "%1$" defined in the object "%2$" of type "%3$" cannot contain multiple Features.
 */
#define CFG0CONFIGURATOR_invalid_subject_expression_for_rule                            ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 54 )

/** @deprecated #CFG0CONFIGURATOR_invalid_payload_expression_for_default_rule deprecated in Teamcenter 11.2.3. Use #CFG0CONFIGURATOR_invalid_subject_expression_for_rule instead. */
#define CFG0CONFIGURATOR_invalid_payload_expression_for_default_rule                    ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 54 )
TC_DEPRECATED_PREPROCESSOR( "11.2.3", CFG0CONFIGURATOR_invalid_payload_expression_for_default_rule, "CFG0CONFIGURATOR_invalid_subject_expression_for_rule" )

/**
 * Provide a valid Revision Rule for the preference "Cfg0DefaultRevisionRule".
 */
#define CFG0CONFIGURATOR_revision_rule_preference_undefined                             ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 55 )

/**
 * The Revision Rule "%1$" specified in the preference "Cfg0DefaultRevisionRule" could not be found.
 */
#define CFG0CONFIGURATOR_revision_rule_not_found                                        ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 56 )

/**
 * The context object "%2$" of type "%1$" is invalid for availability creation. Availability can be created for context object of type and subtype "%3$" only.
 */
#define CFG0CONFIGURATOR_invalid_context_for_availability                               ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 57 )

/**
 * The operation has failed, because the group for "%1$" has both positive and negative terms, which is not allowed.
 */
#define CFG0CONFIGURATOR_pos_neg_terms_not_allowed                                      ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 58 )

/**
 * The object "%1$" of type "%2$" cannot have members "%3$", because they belong to object "%4$" of type "%5$". Feature summaries cannot have members from a non-mutually exclusive, boolean, or free-form family.
 */
#define CFG0CONFIGURATOR_summary_option_invalid_members_family                          ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 59 )

/**
 * The object "%1$" of type "%2$" cannot have members "%3$", because they belong to a different Family.
 */
#define CFG0CONFIGURATOR_summary_option_invalid_members                                 ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 60 )

/**
 * An invalid revision rule was found in the context "%1$". Please provide a correct Revision Rule as defined by the preference "Cfg0DefaultRevisionRule" and try again.
 */
#define CFG0CONFIGURATOR_invalid_revision_rule                                          ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 61 )

/**
 * The object "%1$" of type "%2$" cannot be summarized with the object "%3$" of type "%4$", because it is already summarized by another object from the same mutually exclusive family.
 */
#define CFG0CONFIGURATOR_invalid_summary_option_value_creation                          ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 62 )

/**
 * The Global Rule "%1$" of type "%2$" cannot be attached to the object "%3$" of type "%4$", because Global Rule can only be attached to objects of type "%5$".
 */
#define CFG0CONFIGURATOR_invalid_rule_association_product_context                       ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 63 )

/**
 * The object "%1$" of type "%2$" cannot be attached to the object "%3$" of type "%4$", because only Global Rules can be attached to objects of type "%5$".
 */
#define CFG0CONFIGURATOR_invalid_rule_association_dictionary                            ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 64 )

/**
 * The Global Rule "%1$" of type "%2$" cannot be attached to this Dictionary or Product Context, because it is already attached to a Dictionary. Please contact your system administrator in order to change the Global Rule assignment.
 */
#define CFG0CONFIGURATOR_global_rule_sharing_not_allowed                                ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 65 )

/**
 * The variability for the object "%1$" of type "%2$" cannot be displayed, because the operation "%3$" expects at least one Product Item in the Configurator Perspective.
 */
#define CFG0CONFIGURATOR_empty_configuration_perspective_display                        ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 66 )

/**
 * The variability for the object "%1$" of type "%2$" cannot be displayed, because the operation "%3$" expects at least one Revision Rule in the Configurator Perspective.
 */
#define CFG0CONFIGURATOR_no_revision_rule_display                                       ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 67 )

/**
 * The variability for the object "%1$" of type "%2$" cannot be updated, because an invalid Configurator Perspective is passed to the operation "%3$".
 */
#define CFG0CONFIGURATOR_invalid_configuration_perspective_update                       ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 68 )

/**
 * The variability for the object "%1$" of type "%2$" cannot be updated, because the operation "%3$" expects at least one Product Item in the Configurator Perspective.
 */
#define CFG0CONFIGURATOR_empty_configuration_perspective_update                         ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 69 )

/**
 * The variability for the object "%1$" of type "%2$" cannot be updated, because the operation "%3$" expects at least one Revision Rule in the Configurator Perspective.
 */
#define CFG0CONFIGURATOR_no_revision_rule_update                                        ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 70 )

/**
 * The variability for the object "%1$" of type "%2$" cannot be displayed, because an invalid Configurator Perspective is passed to the operation "%3$".
 */
#define CFG0CONFIGURATOR_invalid_configuration_perspective_display                      ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 71 )

/**
 * The Global Rule "%1$" of type "%2$" cannot be created with more than one Dictionary.
 */
#define CFG0CONFIGURATOR_global_rule_creation_error                                     ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 72 )

/**
* The operation "%1$" has failed, because an invalid Configurator Perspective was passed.
*/
#define CFG0CONFIGURATOR_invalid_configuration_perspective                              ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 73 )

/**
* The operation "%1$" must contain a product item in the Configurator Perspective.
*/
#define CFG0CONFIGURATOR_invalid_product_item_count                                     ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 74 )

/**
* The operation "%1$" has failed, because at least one Family is expected in the input.
*/
#define CFG0CONFIGURATOR_invalid_family_count                                           ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 75 )

/**
* The value range limit for the family "%1$" cannot be set from "%2$" to "%3$", because the provided maximum value is less than or equal to the minimum value.
*/
#define CFG0CONFIGURATOR_invalid_family_range_error                                     ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 76 )

/**
* The object "%1$" of type "%2$" does not support Effectivity Conditions.
*/
#define CFG0CONFIGURATOR_bo_effectivity_not_supported                                   ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 77 )

/**
* The date of the Effectivity condition cannot be set for the object "%1$" of type "%2$", because the object cannot be effective before its creation date.
*/
#define CFG0CONFIGURATOR_invalid_effectivity_date                                       ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 78 )

/**
* The Effectivity validation has failed for the object "%1$" of type "%2$", because not all of its member's revisions are effective in the range of input object Effectivity.
*/
#define CFG0CONFIGURATOR_invalid_members_effectivity                                    ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 79 )

/**
* The Effectivity validation has failed for the object "%1$" of type "%2$", because no member revision is effective in the range of input object Effectivity.
*/
#define CFG0CONFIGURATOR_invalid_summary_effectivity                                    ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 80 )

/**
* The Effectivity validation has failed for the object "%1$" of type "%2$" which is allocating the object "%3$", because allocation cannot be more effective than its feature revisions.
*/
#define CFG0CONFIGURATOR_invalid_allocation_effectivity_value                           ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 81 )

/**
* The object "%1$" of type "%2$" is not a member of any "%3$" or its subtype, and only members of a "%3$" or its subtype can be assigned to the object "%4$" of type "%5$".
*/
#define CFG0CONFIGURATOR_invalid_member_for_product_line                                ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 82 )

/**
* The Effectivity validation has failed for the object "%1$" of type "%2$" which is allocating the object "%3$", because the allocation cannot be less effective than its feature availability.
*/
#define CFG0CONFIGURATOR_invalid_allocation_effectivity_availability                    ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 83 )

/**
* The Effectivity validation has failed for the object "%1$" of type "%2$", because the Effectivity of a Feature availability cannot be wider than its allocation Effectivity.
*/
#define CFG0CONFIGURATOR_invalid_availability_effectivity_allocation                    ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 84 )

/**
* The Effectivity validation has failed for the object "%1$" of type "%2$", because the Effectivity of a Feature availability cannot be wider than its Models Effectivity.
*/
#define CFG0CONFIGURATOR_invalid_availability_effectivity_model                         ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 85 )

/**
* The operation "setVariantExpression" on the object "%1$" of type "%2$" has failed, because the subject expression and the applicability expression are the same.
*/
#define CFG0CONFIGURATOR_same_subject_and_applicability_not_supported                   ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 86 )

/** @deprecated #CFG0CONFIGURATOR_same_payload_and_applicability_not_supported deprecated in Teamcenter 11.2.3. Use #CFG0CONFIGURATOR_same_subject_and_applicability_not_supported instead. */
#define CFG0CONFIGURATOR_same_payload_and_applicability_not_supported                   ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 86 )
TC_DEPRECATED_PREPROCESSOR( "11.2.3", CFG0CONFIGURATOR_same_payload_and_applicability_not_supported, "CFG0CONFIGURATOR_same_subject_and_applicability_not_supported" )

/**
* The Effectivity validation has failed for the object "%1$" of type "%2$", because the Effectivity of a Product Model cannot be narrower than the available Feature "%3$" of type "%4$".
*/
#define CFG0CONFIGURATOR_invalid_model_effectivity_value_availability                   ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 87 )

/**
* The Effectivity validation has failed for the object "%1$" of type "%2$", because the Effectivity of a Feature availability cannot be wider than its Feature Effectivity.
*/
#define CFG0CONFIGURATOR_invalid_availability_effectivity_value                         ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 88 )

/**
* The request to compile a Configurator Rule Set was not processed, because the specified date "%1$" represents a date in the future. Please use a date before the current date "%2$".
*/
#define CFG0CONFIGURATOR_cannot_compile_for_future_dates                                ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 89 )

/**
* The creation of the object "%1$" of type "%2$" is not supported in the module "%3$".
*/
#define CFG0CONFIGURATOR_creation_of_object_not_supported_in_editcontext                ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 90 )

/**
* The "Save As" operation for the object "%1$" of type "%2$" is not supported in the module "%3$".
*/
#define CFG0CONFIGURATOR_saveas_not_supported_in_editcontext                            ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 91 )

/**
* The "Revise" operation for the object "%1$" of type "%2$" is not supported in the module "%3$".
*/
#define CFG0CONFIGURATOR_revise_not_supported_in_editcontext                            ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 92 )

/**
* Range operators (>, <, >= or <=) are not allowed for the value of the data type "String".
*/
#define CFG0CONFIGURATOR_range_not_allowed_for_string_value_type                        ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 93 )

/**
 * No discrete Features can be found for at least one of the following freeform families: "%1$".
 */
#define CFG0CONFIGURATOR_discrete_option_values_mandatory_for_free_form_family          ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 94 )

/**
 * The validation has failed for the object "%1$" of type "%2$", because it is not configured for the current Configurator Perspective "%3$".
 */
#define CFG0CONFIGURATOR_unconfigured_revision_in_validation                            ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 95 )

/**
 * The Availability object creation has been deprecated and replaced by Availability Rules. Please contact your system administrator for more details.
 */
#define CFG0CONFIGURATOR_availability_deprecated                                        ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 96 )

/**
 * The Feasibility Rule object creation has been deprecated and replaced by Availability Rules. Please contact your system administrator for more details.
 */
#define CFG0CONFIGURATOR_feasibility_deprecated                                         ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 97 )

/**
 * The requested object "%1$" of type "%2$" is already allocated to "%3$" of type "%4$".
 */
#define CFG0CONFIGURATOR_already_allocated                                              ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 98 )

/**
 * The requested object "%1$" of type "%2$" cannot be allocated to the Product Context "%3$", unless the object "%4$" of type "%5$" is allocated.
 */
#define CFG0CONFIGURATOR_option_value_cannot_be_allocated                               ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 99 )

/**
 * The value "%1$" for the family "%2$" is invalid or not configured.
 */
#define CFG0CONFIGURATOR_unknown_value_for_the_family                                   ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 100 )

/**
 * The value for the property "%1$" for the object "%2$" of type "%3$" is invalid, because it is unable to identify a unique value in the feature family "%4$". Use "%5$" operator to define the "%1$" of "%3$".
 */
#define CFG0CONFIGURATOR_invalid_operator_subject_expression_for_rule                   ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 101 )

/**
 * The operation "%1$" has failed, because the session configurable object is unavailable.
 */
#define CFG0CONFIGURATOR_input_session_configurable_object_unavailable                  ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 102 )

/**
 * The operation "%3$" has failed, because the input object "%1$" of type "%2$" is not session configurable.
 */
#define CFG0CONFIGURATOR_input_object_is_not_session_configurable                       ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 103 )

/**
 * The operation "%1$" has failed, because unsupported configuration profile information is provided. Only string type configuration solver profile entries are supported.
 */
#define CFG0CONFIGURATOR_unsupported_config_profile_info_provided                       ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 104 )

/**
 * The operation "%1$" has failed, because the number of rules is invalid.
 */
#define CFG0CONFIGURATOR_invalid_rules                                                  ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 105 )

/**
 * The operation "%1$" has failed, because an invalid family is provided.
 */
#define CFG0CONFIGURATOR_invalid_family                                                 ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 106 )

/**
 * The operation "%1$" has failed, because no family is present in the solution.
 */
#define CFG0CONFIGURATOR_family_not_available_in_solution                               ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 107 )

/**
 * The operation "%1$" has failed, because the provided user expression is not valid.
 */
#define CFG0CONFIGURATOR_convert_in_expr_unknown_value                                  ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 108 )

/**
 * The operation "%1$" has failed, because the locked user expression is not valid.
 */
#define CFG0CONFIGURATOR_convert_locked_expr_unknown_value                              ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 109 )

/**
 * The operation "%1$" has failed, because the configuration profile does not contain value for mandatory key(s) "%2$".
 */
#define CFG0CONFIGURATOR_invalid_config_profile_on_perspective                          ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 110 )

/**
 * The value for the property "%1$" for the object "%2$" of type "%3$" cannot contain the object "%4$" of type "%5$". The value can only contain objects of type "%6$" and any of its subtypes.
 */
#define CFG0CONFIGURATOR_unsupported_object_type                                        ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 111 )

/**
 * The association of the object "%1$" of type "%2$" to the object "%3$" of type "%4$" has failed. Ensure that both objects have the same value for the property "%5$".
 */
#define CFG0CONFIGURATOR_familynamespace_not_equal                                      ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 112 )

/**
 * The creation of an object of type "%1$" has failed because an invalid type is provided for the mandatory attribute "%2$".
 */
#define CFG0CONFIGURATOR_invalid_type_mandatory_attribute                               ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 113 )

/**
 * The operator specified for the property "%1$" for "%2$" (of type "%3$") is invalid.
 */
#define CFG0CONFIGURATOR_invalid_operator_default_expression_for_rule                   ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 114 )

/**
 * The features provided for the property "%1$" for "%2$" (of type "%3$") are invalid because they do not contain features specified in the property "%4$".
 */
#define CFG0CONFIGURATOR_invalid_features_default_expression_for_rule                   ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 115 )

/**
 * The expression in the property "%1$" for "%2$" (of type "%3$") is invalid because it contains multiple columns. Only single column expressions are allowed.
 */
#define CFG0CONFIGURATOR_multiple_columns_subject_expression_for_rule                   ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 116 )

/**
 * The expression in the property "%1$" for "%2$" (of type "%3$") is invalid because it contains multiple features. Only a single feature is allowed.
 */
#define CFG0CONFIGURATOR_multiple_feature_subject_expression_for_rule                   ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 117 )

/**
 * The expression in the property "%1$" for "%2$" (of type "%3$") cannot be set because it already contains "%4$".
 */
#define CFG0CONFIGURATOR_subject_expression_already_defined_for_rule                    ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 118 )

/**
 * The expression in the property "%1$" for "%2$" (type "%3$") is invalid because "%4$" (of type "%5$") is a multi-selection object in nature.
 */
#define CFG0CONFIGURATOR_multiselect_feature_family_subject_expression_for_rule         ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 119 )

/**
 * The "Revise" operation for "%1$"(of type "%2$") cannot be performed because no value is specified for the property "%3$".
 */
#define CFG0CONFIGURATOR_revise_action_denied_for_rule                                  ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 120 )

/**
 * The operation "%1$" on the object "%2$" of type "%3$" has failed, because the configuration profile does not contain product name and revision rule information.
 */
#define CFG0CONFIGURATOR_invalid_config_profile_product_info                            ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 121 )

/**
 * "%1$" is an invalid value for the property "%2$" of "%3$".
 */
#define CFG0CONFIGURATOR_invalid_config_criteria_keyname                                ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 122 )

/**
 * The property "%4$" is set to "%5$" for "%1$" with property "%2$" of value "%3$".
 */
#define CFG0CONFIGURATOR_config_criteria_key_property_error                             ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 123 )

/**
 * The property "%1$" is populated for "%2$" (associated to "%3$" with property "%4$" of value "%5$").
 */
#define CFG0CONFIGURATOR_missing_config_criteria_entry_value                            ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 124 )

/**
* The Effectivity condition cannot be set for "%1$" because only date Effectivities are allowed for objects of type "%2$".
*/
#define CFG0CONFIGURATOR_unsupported_effectivity_value                                  ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 125 )

/**
 * The external operation name "%1$" specified is not registered on the object type "%2$".
 */
#define CFG0CONFIGURATOR_externaloperation_is_not_registered                            ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 126 )

/**
 * The External Operation "%1$" execution has failed, because the current object "%2$" of type "%3$" does not exist in the allocated Configurator Contexts of the external operation object.
 */
#define CFG0CONFIGURATOR_externaloperation_invalid_context                              ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 127 )

/**
 * The External Operation "%1$" execution has failed, because the input object "%2$" of type "%3$" of this external operation is not present in the input criteria.
 */
#define CFG0CONFIGURATOR_externaloperation_family_not_in_criteria                       ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 128 )

/**
 * The input Configuration Set at index "%1$" is not valid, because the input Configuration Set has no variant or effectivity expression to validate.
 */
#define CFG0CONFIGURATOR_invalid_configuration_set                                      ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 129 )

/**
 * The value for the input parameter "%1$" at index "%2$" is NULL or empty. Only valid expression inputs are allowed.
 */
#define CFG0CONFIGURATOR_invalid_condition_to_compare                                   ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 130 )

/**
 * The value for the property "%1$" for the object "%2$" of type "%3$" is invalid for the feature family "%4$". Use "%5$" operator against a feature to define the "%1$" of "%3$".
 */
#define CFG0CONFIGURATOR_invalid_subject_expression_for_availability_rule                ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 131 )

/**
 * The execution of the External Operation "%1$" has failed because the external operation returned an invalid response.
 */
#define CFG0CONFIGURATOR_externaloperation_invalid_response                              ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 132 )

/**
 * The External Operation "%1$" has failed in the External Operation Block "%2$": %3$.
 */
#define CFG0CONFIGURATOR_externaloperation_external_calculation                          ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 133 )

/**
 * The expression in the property "%1$" for "%2$" (of type "%3$") is invalid: %4$.
 */
#define CFG0CONFIGURATOR_invalid_expression_script_for_rule                              ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 134 )

 /**
 * The property "%1$" for "%2$" (of type "%3$") cannot be set when the value for the property "%4$" is "%5$".
 */
#define CFG0CONFIGURATOR_invalid_property_for_other_property                             ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 135 )

 /**
 * The value "%1$" for the property "%2$" is invalid for "%3$" (of type "%4$").
 */
#define CFG0CONFIGURATOR_invalid_property_value_for_object                               ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 136 )

/**
 * The external operation "%1$" has failed with status "%2$". Please report this error to your system administrator and refer to the syslog for more information.
 */
#define CFG0CONFIGURATOR_external_operation_failed                                       ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 137 )

/**
 * The external operation "%1$" cannot be executed, because the value "%2$" for the property "%3$" is invalid.
 */
#define CFG0CONFIGURATOR_external_operation_invalid_property                             ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 138 )

/**
 * An error occurred while generating the authorization token for the external operation "%1$". Please report this error to your system administrator.
 */
#define CFG0CONFIGURATOR_external_operation_authorization_token_error                    ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 139 )


/**
 * The "Revise" operation for the object "%1$" of type "%2$" has failed, because the revision of a discontinued WSO object is not supported.
 */
#define CFG0CONFIGURATOR_invalid_revise_operation                                        ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 140 )

/**
 * The "Create" operation for Option Value with the object name:"%1$" and object ID:"%2$" has failed, because the numeric type of the name and ID of the object is different.
 */
#define CFG0CONFIGURATOR_invalid_option_value_for_create                                 ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 141 )

/**
 * The hierarchy for the object "%1$" of type "%2$" could not be retrieved because it is not configured for the Configurator Perspective "%3$".
 */
#define CFG0CONFIGURATOR_unconfigured_revision                                           ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 142 )

/**
  * The JSON schema validation for "%1$" has failed.
 */
#define CFG0CONFIGURATOR_JSON_schema_validation_failed                                   ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 143 )

/**
 * The configurator constraint type "%1$" is invalid. The supported constraint types are: %2$.
 */
#define CFG0CONFIGURATOR_invalid_configurator_constraint_type                            ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 144 )

/**
 * The column expression "%1$" is invalid: "%2$".
 */
#define CFG0CONFIGURATOR_invalid_column_expression                                       ( EMH_CFG0CONFIGURATOR_ERROR_BASE + 145 )

/**

   @}
*/

#endif
