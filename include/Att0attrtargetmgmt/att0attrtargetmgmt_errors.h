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

    Attribute and Product Target Management Error Codes Declaration

*/

#ifndef ATT0ATTRTARGETMGMT_ERRORS_H
#define ATT0ATTRTARGETMGMT_ERRORS_H

#include <common/emh_const.h>
#include <common/tc_deprecation_macros.h>

/**
    @defgroup ATT0ATTRTARGETMGMT_ERRORS Errors for the Attribute and Product Target Management solution
    @ingroup ATT0ATTRTARGETMGMT
    @{
*/

#define ATT0ATTRTARGETMGMT_ERROR_BASE                                         EMH_ATT0ATTRTARGETMGMT_error_base

/** The license "%1$" for the Attribute and Product Target Management module is not available. Please contact the system administrator.*/
#define ATT0ATTRTARGETMGMT_validate_license_failed                            ( EMH_ATT0ATTRTARGETMGMT_error_base + 1 )

/** The attribute type cannot be set, because the attribute definition revision "%1$" was released. */
#define ATT0ATTRTARGETMGMT_set_attribute_definition_revision_type_failed      ( EMH_ATT0ATTRTARGETMGMT_error_base + 2 )

/** The unit of the attribute definition cannot be set, because the attribute definition revision "%1$" was released. */
#define ATT0ATTRTARGETMGMT_set_attribute_defintion_unit_failed                ( EMH_ATT0ATTRTARGETMGMT_error_base + 3 )

/** An attribute definition with name "%1$" and unit "%2$" already exists. Please provide a unique attribute definition name and unit.*/
#define ATT0ATTRTARGETMGMT_duplicated_attrdef_name_error                      ( EMH_ATT0ATTRTARGETMGMT_error_base + 4 )

/** The List of Values for the attribute definition revision "%1$" cannot be set, because the value "%2$" is out of the allowed range for the type "%3$".*/
#define ATT0ATTRTARGETMGMT_set_listofvalues_failed                            ( EMH_ATT0ATTRTARGETMGMT_error_base + 5 )

/** The minimum value "%1$" cannot be set, because it is not type of "%2$".*/
#define ATT0ATTRTARGETMGMT_set_minimum_value_failed                           ( EMH_ATT0ATTRTARGETMGMT_error_base + 6 )

/** The maximum value "%1$" cannot be set, because it is not type of "%2$".*/
#define ATT0ATTRTARGETMGMT_set_maximum_value_failed                           ( EMH_ATT0ATTRTARGETMGMT_error_base + 7 )

/** The goal value "%1$" cannot be set, because it is not type of "%2$".*/
#define ATT0ATTRTARGETMGMT_set_goal_value_failed                              ( EMH_ATT0ATTRTARGETMGMT_error_base + 8 )

/** "%1$" was not saved because "%2$" is not one of the allowed values for the Minimum. Display the Measurable Attributes panel in edit mode to select an allowed value.*/
#define ATT0ATTRTARGETMGMT_invalid_minvalue_error                             ( EMH_ATT0ATTRTARGETMGMT_error_base + 9 )

/** "%1$" was not saved because "%2$" is not one of the allowed values for the Maximum. Display the Measurable Attributes panel in edit mode to select an allowed value.*/
#define ATT0ATTRTARGETMGMT_invalid_maxvalue_error                             ( EMH_ATT0ATTRTARGETMGMT_error_base + 10 )

/** "%1$" was not saved because "%2$" is not one of the allowed values for the Goal. Display the Measurable Attributes panel in edit mode to select an allowed value.*/
#define ATT0ATTRTARGETMGMT_invalid_goalvalue_error                            ( EMH_ATT0ATTRTARGETMGMT_error_base + 11 )

/** The attribute definition revision "%1$" is not enabled.*/
#define ATT0ATTRTARGETMGMT_disabled_attrdefrev_error                          ( EMH_ATT0ATTRTARGETMGMT_error_base + 12 )

/** The relation cannot be created, because the attribute "%1$" is referenced by "%2$".*/
#define ATT0ATTRTARGETMGMT_create_attr_relation_error                         ( EMH_ATT0ATTRTARGETMGMT_error_base + 13 )

/** Measurable attributes cannot be retrieved, because the provided context line "%1$" does not contain any BOM View Revision. */
#define ATT0ATTRTARGETMGMT_invalid_context_line                               ( EMH_ATT0ATTRTARGETMGMT_error_base + 14 )

/** A valid parent object or line must be provided. */
#define ATT0ATTRTARGETMGMT_parent_isnull                                      ( EMH_ATT0ATTRTARGETMGMT_error_base + 15 )

/** The measurable attribute type "%1$" does not match the attribute definition type "%2$".*/
#define ATT0ATTRTARGETMGMT_not_matched_attrdef_type                           ( EMH_ATT0ATTRTARGETMGMT_error_base + 16 )

/** The value "%1$" for the property "%2$" should be greater than or equal to the value "%3$" for the property "%4$".*/
#define ATT0ATTRTARGETMGMT_value_less_than_error                              ( EMH_ATT0ATTRTARGETMGMT_error_base + 17 )

/** The object type "%1$" is an invalid primary object type for the Input Measurable Attribute instance.*/
#define ATT0ATTRTARGETMGMT_invalid_input_primary_object                       ( EMH_ATT0ATTRTARGETMGMT_error_base + 18 )

/** The object type "%1$" is an invalid primary object for the Output Measurable Attribute instance.*/
#define ATT0ATTRTARGETMGMT_invalid_output_primary_object                      ( EMH_ATT0ATTRTARGETMGMT_error_base + 19 )

/** The Input Measurable Attribute cannot be attached to multiple parent objects.*/
#define ATT0ATTRTARGETMGMT_input_parent_already_exist                         ( EMH_ATT0ATTRTARGETMGMT_error_base + 20 )

/** The Output Measurable Attribute cannot be attached to multiple parent objects.*/
#define ATT0ATTRTARGETMGMT_output_parent_already_exist                        ( EMH_ATT0ATTRTARGETMGMT_error_base + 21 )

/** The Input and Output Measurable Attribute properties are not modifiable.*/
#define ATT0ATTRTARGETMGMT_input_output_attribute_not_modifiable              ( EMH_ATT0ATTRTARGETMGMT_error_base + 22 )

/** Measurement properties are not modifiable for Input Measurable Attribute objects.*/
#define ATT0ATTRTARGETMGMT_input_attribute_measurement_not_modifiable         ( EMH_ATT0ATTRTARGETMGMT_error_base + 23 )

/** The Input Measurable Attributes are out-of-date. Please run the synchronization to update.*/
#define ATT0ATTRTARGETMGMT_input_attribute_measurement_out_of_date            ( EMH_ATT0ATTRTARGETMGMT_error_base + 25 )

/** The target object type "%1$" does not match the source object type "%2$".*/
#define ATT0ATTRTARGETMGMT_type_not_matched                                   ( EMH_ATT0ATTRTARGETMGMT_error_base + 26 )

/** The validation object "%1$" is not allowed to publish Measurable Attributes, because its current release status is "%2$" and it must be "%3$" in order to publish.*/
#define ATT0ATTRTARGETMGMT_release_stauts_not_allowed_publish                 ( EMH_ATT0ATTRTARGETMGMT_error_base + 27 )

/** The Goal dataset cannot be attached, because the attribute definition revision "%1$" was released.*/
#define ATT0ATTRTARGETMGMT_create_goal_dataset_failed                         ( EMH_ATT0ATTRTARGETMGMT_error_base + 28 )

/** The Measurement dataset cannot be attached, because the attribute definition revision "%1$" was released.*/
#define ATT0ATTRTARGETMGMT_create_measurement_dataset_failed                  ( EMH_ATT0ATTRTARGETMGMT_error_base + 29 )

/** The Goal dataset cannot be deleted, because the attribute definition revision "%1$" was released.*/
#define ATT0ATTRTARGETMGMT_delete_goal_dataset_failed                         ( EMH_ATT0ATTRTARGETMGMT_error_base + 30 )

/** The Measurement dataset cannot be deleted, because the attribute definition revision "%1$" was released.*/
#define ATT0ATTRTARGETMGMT_delete_measurement_dataset_failed                  ( EMH_ATT0ATTRTARGETMGMT_error_base + 31 )

/** The Measurement value "%1$" must be defined in the List of Values "%2$", because the exhaustive flag is set to true.*/
#define ATT0ATTRTARGETMGMT_invalid_measure_value_error                        ( EMH_ATT0ATTRTARGETMGMT_error_base + 32 )

/** "%1$" cannot be modified in the "%2$" state.*/
#define ATT0ATTRTARGETMGMT_input_output_parent_modification_not_allowed        ( EMH_ATT0ATTRTARGETMGMT_error_base + 33 )

/** "%1$" was not saved because the operators entered for "Min" and "Max" are inconsistent.*/
#define ATT0ATTRTARGETMGMT_min_max_operator_inconsistent                       ( EMH_ATT0ATTRTARGETMGMT_error_base + 34 )

/** "%1$" was not saved because the "%2$" operator is missing.*/
#define ATT0ATTRTARGETMGMT_missing_operator                                    ( EMH_ATT0ATTRTARGETMGMT_error_base + 35 )

/** "%1$" was not saved because either the goal is not within the range defined by the "Min" and "Max" values or the "Min" value is greater than the "Max" value.*/
#define ATT0ATTRTARGETMGMT_invalid_goal_value                                  ( EMH_ATT0ATTRTARGETMGMT_error_base + 36 )

/** "%1$" was not saved because the value "%2$" is missing.*/
#define ATT0ATTRTARGETMGMT_missing_value                                       ( EMH_ATT0ATTRTARGETMGMT_error_base + 37 )

/** "%1$" was not saved because a "Max" can not be defined if +/- set for "Min".*/
#define ATT0ATTRTARGETMGMT_max_not_supportted                                  ( EMH_ATT0ATTRTARGETMGMT_error_base + 38 )

/** Edits to "%1$" were not saved because an Attribute Definition already exists with the same Name and Unit of Measure.*/
#define ATT0ATTRTARGETMGMT_update_attrdef_name_error                           ( EMH_ATT0ATTRTARGETMGMT_error_base + 39 )

/** @deprecated #ATT0ATTRTARGETMGMT_output_min_max_goal_not_modifiable deprecated in Teamcenter 11.5.

Edits to the Minimum, Maximum and Goal properties of the "%1$" were not saved because they are not modifiable for output attributes.*/
#define ATT0ATTRTARGETMGMT_output_min_max_goal_not_modifiable                  ( EMH_ATT0ATTRTARGETMGMT_error_base + 40 )
TC_DEPRECATED_PREPROCESSOR( "11.5", ATT0ATTRTARGETMGMT_output_min_max_goal_not_modifiable, "" )

/** Edits to the name were not saved because "%1$" already exists on the parent object "%2$".*/
#define ATT0ATTRTARGETMGMT_duplicated_attr_name                                ( EMH_ATT0ATTRTARGETMGMT_error_base + 41 )

/** The type name "%1$" is invalid because it is not a sub-type of "%2$". */
#define ATT0ATTRTARGETMGMT_invalid_subtype_name                                ( EMH_ATT0ATTRTARGETMGMT_error_base + 42 )

/** A valid context must be supplied. */
#define ATT0ATTRTARGETMGMT_context_is_null                                     ( EMH_ATT0ATTRTARGETMGMT_error_base + 43 )

/** The attribute mapping cannot be created or deleted because the related context object "%1$" is not modifiable.*/
#define ATT0ATTRTARGETMGMT_create_or_delete_attrmap_failed                     ( EMH_ATT0ATTRTARGETMGMT_error_base + 44 )

/** The attribute alignment cannot be created or deleted because the related context object "%1$" is not modifiable.*/
#define ATT0ATTRTARGETMGMT_create_or_delete_attralignment_failed               ( EMH_ATT0ATTRTARGETMGMT_error_base + 45 )

/** "%1$" was not saved because the string entered does not follow the correct format for the Coordinates, eg: 2.3, 5.6, 7.8.*/
#define ATT0ATTRTARGETMGMT_invalid_point_goal_value                            ( EMH_ATT0ATTRTARGETMGMT_error_base + 46 )

/** The given object type "%1$" is not supported for complex data. The supported types are "Att0MeasurableAttribute" and "Att0AttributeDefRevision" */
#define ATT0ATTRTARGETMGMT_invalid_object_type_complex_value                   ( EMH_ATT0ATTRTARGETMGMT_error_base + 47 )

/** No complex data was provided.*/
#define ATT0ATTRTARGETMGMT_invalid_data_complex_value                          ( EMH_ATT0ATTRTARGETMGMT_error_base + 48 )

/** The file type "%1$" is invalid for complex data. The supported types are "xlsx" and "xlsm".*/
#define ATT0ATTRTARGETMGMT_invalid_file_type_complex_value                     ( EMH_ATT0ATTRTARGETMGMT_error_base + 49 )

/** The property "%1$" does not exist for objects of type Attribute Table (Att0AttributeTable) and Value Table (Att0ValueTable).*/
#define ATT0ATTRTARGETMGMT_invalid_prop_complex_value                          ( EMH_ATT0ATTRTARGETMGMT_error_base + 50 )

/** The number of rows/colums are different across Min/Max/Goal/Measurement tables. The import of complex data will proceed nevertheless.*/
#define ATT0ATTRTARGETMGMT_invalid_dimension_complex_value_proceed             ( EMH_ATT0ATTRTARGETMGMT_error_base + 51 )

/** The column definition is different across Min/Max/Goal/Measurement tables. The import of complex data will proceed nevertheless.*/
#define ATT0ATTRTARGETMGMT_invalid_definition_complex_value_proceed            ( EMH_ATT0ATTRTARGETMGMT_error_base + 52 )

/** The number of rows/colums are different across Min/Max/Goal/Measurement tables. The import of complex data will not proceed.*/
#define ATT0ATTRTARGETMGMT_invalid_dimension_complex_value                     ( EMH_ATT0ATTRTARGETMGMT_error_base + 53 )

/** The Column definition is different across Min/Max/Goal/Measurement tables. The import of complex data will not proceed.*/
#define ATT0ATTRTARGETMGMT_invalid_definition_complex_value                    ( EMH_ATT0ATTRTARGETMGMT_error_base + 54 )

/** The point attribute "%1$" cannot be saved, because at least one of the values for (x,y,z) is empty.*/
#define ATT0ATTRTARGETMGMT_point_attr_invalid_goal_value                       ( EMH_ATT0ATTRTARGETMGMT_error_base + 55 )

/** The parameter "%1$" cannot be cut because it is used in the Verification Request or Study or the properties have been overridden on one or more occurrences of the element in a structure.*/
#define ATT0ATTRTARGETMGMT_cannot_cut_parameter                                ( EMH_ATT0ATTRTARGETMGMT_error_base + 56 )

/** The data type property is not editable. A new parameter definition with the required data type will need to be created.*/
#define ATT0ATTRTARGETMGMT_data_type_not_modifiable                            ( EMH_ATT0ATTRTARGETMGMT_error_base + 57 )

/** "%1$" was not cut because parameters are used in verification requests. */
#define ATT0ATTRTARGETMGMT_cannot_cut_group                                    ( EMH_ATT0ATTRTARGETMGMT_error_base + 58 )

/** "%1$" is already set at a higher level in the structure, which will take precedence. */
#define ATT0ATTRTARGETMGMT_already_overriden_higher_level                      ( EMH_ATT0ATTRTARGETMGMT_error_base + 59 )

/** The system cannot set the direction as "%1$" on the parameter "%2$" having parent "%3$", because it violates the cardinality rule.*/
#define ATT0ATTRTARGETMGMT_cannot_set_direction                                ( EMH_ATT0ATTRTARGETMGMT_error_base + 60 )

/** A valid parent object must be provided.*/
#define ATT0ATTRTARGETMGMT_invalid_parent                                      ( EMH_ATT0ATTRTARGETMGMT_error_base + 61 )

/** No write access on the parent object.*/
#define ATT0ATTRTARGETMGMT_no_write_access_on_parent                           ( EMH_ATT0ATTRTARGETMGMT_error_base + 62 )

/** The direction value "%1$" is invalid.*/
#define ATT0ATTRTARGETMGMT_invalid_direction                                   ( EMH_ATT0ATTRTARGETMGMT_error_base + 63 )

/** "%1$" with overrides cannot be reused. */
#define ATT0ATTRTARGETMGMT_single_param_paste_failed                           ( EMH_ATT0ATTRTARGETMGMT_error_base + 64 )

/** %1$ parameters with overrides cannot be reused. */
#define ATT0ATTRTARGETMGMT_referred_param_paste_failed                         ( EMH_ATT0ATTRTARGETMGMT_error_base + 65 )

/** "%1$" was not added because it already exists in the table. */
#define ATT0ATTRTARGETMGMT_single_same_param_paste_failed                      ( EMH_ATT0ATTRTARGETMGMT_error_base + 66 )

/** %1$ parameters were not added because they exist in the table. */
#define ATT0ATTRTARGETMGMT_same_params_paste_failed                            ( EMH_ATT0ATTRTARGETMGMT_error_base + 67 )

/** "%1$" was not attached because parameter with same name already exists with "%2$". */
#define ATT0ATTRTARGETMGMT_param_paste_same_name_failed                        ( EMH_ATT0ATTRTARGETMGMT_error_base + 68 )

/** %1$ parameters were not attached because parameters with same name already exists with "%2$". */
#define ATT0ATTRTARGETMGMT_params_paste_same_name_failed                       ( EMH_ATT0ATTRTARGETMGMT_error_base + 69 )

/** %1$ out of %2$ parameters were added to "%3$". */
#define ATT0ATTRTARGETMGMT_params_few_paste_failed                             ( EMH_ATT0ATTRTARGETMGMT_error_base + 70 )

/** %1$ parameters were not updated because you do not have permission on "%2$". */
#define ATT0ATTRTARGETMGMT_param_edit_failed                                   ( EMH_ATT0ATTRTARGETMGMT_error_base + 71 )

/** "%1$" parameter was not updated because you do not have permission on "%2$". */
#define ATT0ATTRTARGETMGMT_single_param_edit_failed                            ( EMH_ATT0ATTRTARGETMGMT_error_base + 72 )

/** The parameter "%1$" has already been overridden on the line "%2$" in the structure. */
#define ATT0ATTRTARGETMGMT_already_overriden_for_input_line_structure          ( EMH_ATT0ATTRTARGETMGMT_error_base + 73 )

/** @} */

#endif
