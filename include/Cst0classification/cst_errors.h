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
    The Classification Standard Taxonomy (CST) related errors.
*/



#ifndef CST_ERRORS_H
#define CST_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup CST_ERRORS Errors
    @ingroup CST
    @{
*/

/** An unknown place holder error */
#define CST_err_unknown                                             (EMH_CST_error_base + 0)

/** A schema validation error has occurred. */
#define CST_err_schema_not_valid                                    (EMH_CST_error_base + 1)

/** Neither IRDI nor ID is provided for this object. */
#define CST_err_object_no_id_given                                  (EMH_CST_error_base + 2)

/** Multiple objects were found for the given values. */
#define CST_err_multiple_objects_found                              (EMH_CST_error_base + 3)

/** "%1$" could not be parsed. */
#define CST_err_parse_json_error                                    (EMH_CST_error_base + 4)

/** The property definition "%1$" could not be found. */
#define CST_err_property_definition_not_found                       (EMH_CST_error_base + 5)

/** No namespace is provided for "%1$". */
#define CST_err_object_no_namespace_given                           (EMH_CST_error_base + 6)

/** No revision is provided for "%1$". */
#define CST_err_object_no_revision_given                            (EMH_CST_error_base + 7)

/** The property "%1$" does not exist in the class "%2$". */
#define CST_err_property_does_not_exists_in_class                   (EMH_CST_error_base + 8)

/** The block definition "%1$" could not be found. */
#define CST_err_block_not_found                                     (EMH_CST_error_base + 9)

/** The file "%1$" could not be found. */
#define CST_err_file_not_found                                      (EMH_CST_error_base + 10)

/** The input request is not a valid JSON file. */
#define CST_err_no_valid_json                                       (EMH_CST_error_base + 11)

/** The schema file "%1$" for schema version "%2$" could not be found. */
#define CST_err_schema_file_not_found                               (EMH_CST_error_base + 12)

/** The schema validation has failed. The path to the violated rule in the schema file is "%1$" and the violated schema keyword is "%2$". */
#define CST_err_schema_validation                                   (EMH_CST_error_base + 13)

/** New revisions are not allowed if one is in "Develop" status. */
#define CST_err_new_revision_not_allowed_when_develop_exists        (EMH_CST_error_base + 14)

/** Revisions not in "Develop" status cannot be updated.*/
#define CST_err_save_not_possible_for_non_develop                   (EMH_CST_error_base + 15)

/** The status cannot be changed from "%1$" to "%2$".*/
#define CST_err_update_status_not_allowed                           (EMH_CST_error_base + 16)

/** The status cannot be updated to "Released" because a referencing object "%1$" is in status "%2$". */
#define CST_err_update_status_to_released_not_allowed               (EMH_CST_error_base + 17)

/** New revisions cannot be auto-assigned.*/
#define CST_err_auto_assign_revision                                (EMH_CST_error_base + 18)

/** The provided IRDI "%1$" is not valid. */
#define CST_err_irdi_not_valid                                      (EMH_CST_error_base + 19)

/** Multiple values are given for the non-VLA property "%1$". */
#define CST_err_multivalue_given_for_nonvla                         (EMH_CST_error_base + 20)

/** Several objects cannot be saved/updated because they have the same namespace and ID. */
#define CST_err_save_not_possible_for_duplicates                    (EMH_CST_error_base + 21)

/** Some partial errors have occurred. Refer to the result information for each object. */
#define CST_err_partial_errors                                      (EMH_CST_error_base + 22)

/** More than one entry is marked with "isMasterLocale:true". */
#define CST_err_multiple_master_locales                             (EMH_CST_error_base + 23)

/** A localizable property cannot be created without any entry with "isMasterLocale:true". */
#define CST_err_no_master_locale                                    (EMH_CST_error_base + 24)

/** The defined master locale is different from the database master locale. */
#define CST_err_wrong_master_locale                                 (EMH_CST_error_base + 25)

/** Classification in the class "%1$" cannot be achieved because its status is "%2$".  */
#define CST_err_cannot_classify_in_not_released_class               (EMH_CST_error_base + 26)

/** The attribute reference "%1$" is not unique in the class definition. */
#define CST_err_attr_not_unique                                     (EMH_CST_error_base + 27)

/** IRDI reference "%1$" is not a "%2$". */
#define CST_err_reference_wrong_type                                (EMH_CST_error_base + 28)

/** The creation of a Classification class has failed because the out-of-the-box limit for the number of attributes (as set by the "dbindex" property) has been reached (up to 100 string, 60 integer, 140 double, 60 boolean and 10 date attributes). Please contact your system administrator in order to change these limitations. */
#define CST_err_no_free_dbindex                                     (EMH_CST_error_base + 29)

/** %1$ "%2$" cannot be deleted because it is referenced by "%3$".*/
#define CST_err_delete_referenced_obj_not_allowed                   (EMH_CST_error_base + 30)

/** The classification has failed because the class "%1$" is abstract. */
#define CST_err_cannot_classify_in_abstract_class                   (EMH_CST_error_base + 31)

/** The classification in the class "%1$" has failed because it is not an "Application" class. */
#define CST_err_cannot_classify_in_non_application_class            (EMH_CST_error_base + 32)

/** No object with %1$ "%2$" exists in the system.*/
#define CST_err_object_does_not_exist                               (EMH_CST_error_base + 33)

/** The option "%1$" is not supported for "%2$".*/
#define CST_err_option_not_supported                                (EMH_CST_error_base + 34)

/** The aspect definition "%1$" could not be found. */
#define CST_err_aspect_not_found                                    (EMH_CST_error_base + 35)

/** The "BlockReference" "%1$" references a class which is not of type "Aspect".*/
#define CST_err_reference_no_aspect                                 (EMH_CST_error_base + 36)

/** "Aspect" classes can only be referenced in "Application" classes.*/
#define CST_err_aspect_in_non_app_class                             (EMH_CST_error_base + 37)

/** The value for property "%1$" of attribute "%2$" must be of type "%3$". */
#define CST_err_prop_value_wrong_datatype                           (EMH_CST_error_base + 38)

/** The value "%1$" of the property "%2$" is less than the minimum constraint value "%3$". */
#define CST_err_prop_value_lesser_than_min                          (EMH_CST_error_base + 39)

/** The value "%1$" of the property "%2$" is more than the maximum constraint value "%3$". */
#define CST_err_prop_value_greater_than_max                         (EMH_CST_error_base + 40)

/** New revisions cannot be set to the "Released" status if a revision already exists. */
#define CST_err_new_released_revision_not_allowed_when_existing     (EMH_CST_error_base + 41)

/** The required "Classification User" license is missing or not installed. Please contact your system administrator. */
#define CST_err_user_license_missing                                (EMH_CST_error_base + 43)

/** The required "Eclass User" license is missing or not installed. Please contact your system administrator. */
#define CST_err_eclass_license_missing                              (EMH_CST_error_base + 44)

/** Property values for PropertyDefinition "%1$" could not be copied because cardinality has changed in new released class "%2$". */
#define CST_err_cannot_copy_all_property_values                     (EMH_CST_error_base + 45)

/** The property "%1$" is defined as cardinality controller but was not added to the class definition. */
#define CST_err_cardinality_controller_not_added                    (EMH_CST_error_base + 46)

/** The attribute "%1$" defined as cardinality controller cannot have a "Cardinality" set. */
#define CST_err_cardinality_set_on_cardinality_controller           (EMH_CST_error_base + 47)

/** Key LOV "%1$" is of type "%2$" and cannot be assigned in Property Definition "%3$" of type "%4$" because there is a datatype mis-match. */
#define CST_err_datatype_mismatch                                   (EMH_CST_error_base + 48)

/** Key LOV "%1$" cannot be attached to Property Definition "%2$" because it does not exist. */
#define CST_err_keylov_does_not_exist                               (EMH_CST_error_base + 49)

/** The view "%1$" of type "%2$" has attribute "%3$" which does not exist in class "%4$". */
#define CST_err_view_attribute_does_not_exist                       (EMH_CST_error_base + 50)

/** The base view attributes provided for class "%1$" are not valid. Regardless of the ordering, all class attributes must be provided for creating a base view. */
#define CST_err_base_view_attributes_not_valid                      (EMH_CST_error_base + 51)

/** The view cannot be created for the class "%1$" because its status is "%2$". The status of the class must be "Released" for creating its view. */
#define CST_err_cannot_create_view_for_not_released_class           (EMH_CST_error_base + 52)

/** The view cannot be created for the class "%1$" because its type is "%2$". The type of the class must be "Application Class" for creating its view. */
#define CST_err_cannot_create_view_for_not_application_class        (EMH_CST_error_base + 53)

/** No View Object exists in the system with value "%2$" for the property "%1$". */
#define CST_err_view_object_one_input_does_not_exist                (EMH_CST_error_base + 54)

/** No View Object exists in the system with value "%2$" for the property "%1$" and value "%4$" for the property "%3$". */
#define CST_err_view_object_two_inputs_does_not_exist               (EMH_CST_error_base + 55)

/** No View Object exists in the system with value "%2$" for the property "%1$", value "%4$" for the property "%3$" and value "%6$" for the property "%5$". */
#define CST_err_view_object_three_inputs_does_not_exist             (EMH_CST_error_base + 56)

/** Class Definition "%1$" cannot be created because the attribute "%2$" already exists in parent class "%3$". */
#define CST_err_duplicate_attribute                                 (EMH_CST_error_base + 57)

/** Adding "%1$" to class "%2$" is not allowed as a class definition cannot be added as a child to itself or to any of its children. */
#define CST_err_cannot_create_class_with_invalid_parent             (EMH_CST_error_base + 58)

/** The enquiry with ID "%1$" does not exist. */
#define CST_err_enquiry_name_does_not_exist                         (EMH_CST_error_base + 59)

/** The value for property "%1$" cannot be empty. */
#define CST_err_enquiry_empty_value_specified                       (EMH_CST_error_base + 60)

/** The property "%1$" is defined as 'cardinal' or 'localizable'. Search on such a property is not supported. */
#define CST_err_enquiry_search_not_supported                        (EMH_CST_error_base + 61)

/** The value of property "%1$" on the object "%2$" must be of type "%3$". */
#define CST_err_wrong_property_value                                (EMH_CST_error_base + 62)

/** The property "%1$" does not exist on the object "%2$". */
#define CST_err_property_does_not_exist                             (EMH_CST_error_base + 63)

/** The search on the property "LOVItems" in the key LOV definition is not supported. */
#define CST_err_lovitems_search_not_supported                       (EMH_CST_error_base + 64)

/** The select operation on an array property is not supported. */
#define CST_err_array_select_not_supported                          (EMH_CST_error_base + 65)

/** Access is denied because user does not have required privilege. Please contact your system administrator.*/
#define CST_err_access_denied                                       (EMH_CST_error_base + 66)

/** @} */

#endif
