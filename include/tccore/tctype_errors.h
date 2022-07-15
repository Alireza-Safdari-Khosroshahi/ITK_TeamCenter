/*=============================================================================
Copyright 2020
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
===============================================================================
@file

    TYPE errors

    File Name: TCTYPE_ERRORS.H
    Subsystem: TCCORE

===============================================================================
*/

/*  */

#ifndef TCTYPE_ERRORS_H
#define TCTYPE_ERRORS_H

#include <common/emh_const.h>
#include <common/tc_deprecation_macros.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup TCTYPE_ERRORS Type Errors
    @ingroup TCTYPE
    @{
*/

#define TYPE_not_initialized                (EMH_TYPE_error_base + 1)
#define TYPE_no_load_class                  (EMH_TYPE_error_base + 2)
#define TYPE_no_register_object             (EMH_TYPE_error_base + 3)
#define TYPE_no_load_type                   (EMH_TYPE_error_base + 4)
#define TYPE_invalid_class                  (EMH_TYPE_error_base + 5)
#define TYPE_invalid_class_name             (EMH_TYPE_error_base + 6)
#define TYPE_invalid_type_name              (EMH_TYPE_error_base + 7)
#define TYPE_type_already_exists            (EMH_TYPE_error_base + 8)
#define TYPE_class_already_exists           (EMH_TYPE_error_base + 9)
/** @if DOX_IGNORE
#define TYPE_no_save                        (EMH_TYPE_error_base + 10)
@endif */
#define TYPE_privileged_operation           (EMH_TYPE_error_base + 11)
#define TYPE_no_extent                      (EMH_TYPE_error_base + 12)
#define TYPE_no_create_enquiry              (EMH_TYPE_error_base + 13)
#define TYPE_unknown_type                   (EMH_TYPE_error_base + 14)
#define TYPE_duplicate_prop_name            (EMH_TYPE_error_base + 15)
#define TYPE_instances_exist                (EMH_TYPE_error_base + 16)

/**
    @name Compound Property Definition related errors
    @{
*/
#define TYPE_cpdef_results_duplicate_prop   (EMH_TYPE_error_base + 17)
#define TYPE_failed_to_create_cpdefinition  (EMH_TYPE_error_base + 18)
/** @} */

#define TYPE_invalid_accessor               (EMH_TYPE_error_base + 19)
#define TYPE_cannot_delete_system_rule      (EMH_TYPE_error_base + 20)
#define TYPE_no_find_type                   (EMH_TYPE_error_base + 21)
#define TYPE_no_create_type                 (EMH_TYPE_error_base + 22)
#define TYPE_invalid_Preference             (EMH_TYPE_error_base + 23)
#define TYPE_invalid_props                  (EMH_TYPE_error_base + 24)
#define TYPE_msg_not_supported              (EMH_TYPE_error_base + 25)
#define TYPE_class_names_not_same      ( EMH_TYPE_error_base + 26)
#define TYPE_primary_type_not_allowed  ( EMH_TYPE_error_base + 27)
/**No paste relations were found for the type "%1$". Please contact your system administrator.*/
#define TYPE_no_paste_relations_found             ( EMH_TYPE_error_base + 28)
/**No expandable paste relations were found for the type "%1$". Please contact your system administrator.*/
#define TYPE_no_expandable_paste_relations_found  ( EMH_TYPE_error_base + 29)
/**No preferred paste relations were found for the type "%1$". Please contact your system administrator.*/
#define TYPE_no_preferred_paste_relations_found   ( EMH_TYPE_error_base + 30)

/**The requested context is not supported. The supported context names are: "subtypes".*/
#define TYPE_invalid_context_name              ( EMH_TYPE_error_base + 31 )

/**The operation input descriptor "%1$" requires a value for the property "%2$" for business objects of type "%3$.*/
#define TYPE_missing_property_for_operation    ( EMH_TYPE_error_base + 32 )

/**Objects of type "%1$" are not supported for ID generation. Only objects of type "Item" or any of its subtypes are allowed.*/
#define TYPE_unsupported_type_for_id_generation   ( EMH_TYPE_error_base + 33 )

/**
 * The provided Thread CreateInput is of type "%1$". An object of type or subtype of "%2$" is expected.
 */
#define TYPE_unsupported_invalid_thread_type      ( EMH_TYPE_error_base + 34 )

/**
 * The specified type "%1$" is not the type or subtype of "Fnd0LogicalObject".
 */
#define TYPE_invalid_logical_object_type          ( EMH_TYPE_error_base + 35 )

/**
 * The specified type "%1$" is not a valid parent Logical Object Type. A subtype of "Fnd0LogicalObject" is expected.
 */
#define TYPE_invalid_parent_logical_object_type   ( EMH_TYPE_error_base + 36 )

/**
 * The specified type "%1$" is not a valid root type. A persistent subtype of "POM_object" is expected.
 */
#define TYPE_invalid_root_type                    ( EMH_TYPE_error_base + 37 )

/**
 * The specified type "%1$" cannot have an empty display name.
 */
#define TYPE_empty_display_name                   ( EMH_TYPE_error_base + 38 )

/**
 * The specified type "%1$" cannot have an empty description.
 */
#define TYPE_empty_description                    ( EMH_TYPE_error_base + 39 )

/**
 * No Logical Object instance is found for Logical Object Type "%1$" and root object "%2$".
 */
#define TYPE_lo_instance_not_found                ( EMH_TYPE_error_base + 40 )

/**
 * @deprecated #TYPE_invalid_lo_display_name deprecated in Teamcenter 11.5. Use #TYPE_invalid_add_lo_display_name instead.
 */
#define TYPE_invalid_lo_display_name              ( EMH_TYPE_error_base + 41 )
TC_DEPRECATED_PREPROCESSOR( "11.5", TYPE_invalid_lo_display_name, "TYPE_invalid_add_lo_display_name" )

/**
 * The creation of the Logical Object Type "%1$" has failed due to invalid characters in its name. Please enter text that belongs to the character set "%2$".
 */
#define TYPE_invalid_add_lo_display_name          ( EMH_TYPE_error_base + 41 )

/**
 * The specified Logical Object Type "%1$" was not found.
 */
#define TYPE_lo_type_not_found                    ( EMH_TYPE_error_base + 42 )

/**
 * The specified Logical Object Type "%1$" cannot be deleted because it has child Logical Object Types. Please delete all child Logical Object Types of "%1$" first.
 */
#define TYPE_lo_type_has_child_types              ( EMH_TYPE_error_base + 43 )

/**
 * The specified Logical Object Type "%1$" cannot be deleted because it is still referenced.
 */
#define TYPE_lo_type_referenced                   ( EMH_TYPE_error_base + 44 )

/**
 * @deprecated #TYPE_invalid_lo_name deprecated in Teamcenter 11.5. Use #TYPE_invalid_add_lo_name instead.
 */
#define TYPE_invalid_lo_name                      ( EMH_TYPE_error_base + 45 )
TC_DEPRECATED_PREPROCESSOR( "11.5", TYPE_invalid_lo_name, "TYPE_invalid_add_lo_name" )

/**
 * The creation of the Logical Object Type has failed due to invalid characters in its internal name. Please enter text that belongs to the character set "%1$".
 */
#define TYPE_invalid_add_lo_name                  ( EMH_TYPE_error_base + 45 )

/**
 * The member "%1$" cannot be created because "%2$" already exists on the Logical Object Type "%3$".
 */
#define TYPE_duplicate_member_add_in_hierarchy    ( EMH_TYPE_error_base + 46 )

/**
 * The provided object is not a valid Logical Object instance.
 */
#define TYPE_invalid_lo_instance                  ( EMH_TYPE_error_base + 47 )

/**
 * An internal error has occurred. Please report this error to your system administrator.
 */
#define TYPE_invalid_input_value                  ( EMH_TYPE_error_base + 48 )

/**
 * The presented property "%1$" cannot be created because "%2$" already exists on the Logical Object Type "%3$".
 */
#define TYPE_duplicate_presented_property_add_in_hierarchy            ( EMH_TYPE_error_base + 49 )

/**
 * The member "%1$" cannot be updated to "%2$" because it already exists on the Logical Object Type "%3$".
 */
#define TYPE_duplicate_member_update_in_hierarchy                     ( EMH_TYPE_error_base + 50 )

/**
 * The presented property "%1$" cannot be updated to "%2$" because it already exists on the Logical Object Type "%3$".
 */
#define TYPE_duplicate_presented_property_update_in_hierarchy         ( EMH_TYPE_error_base + 51 )

/**
 * The internal name of the Logical Object Type "%1$" cannot be updated due to invalid characters. Please enter text that belongs to the character set "%2$".
 */
#define TYPE_invalid_update_lo_name                                   ( EMH_TYPE_error_base + 52 )

/**
 * The display name of the Logical Object Type "%1$" cannot be updated due to invalid characters. Please enter text that belongs to the character set "%2$".
 */
#define TYPE_invalid_update_lo_display_name                           ( EMH_TYPE_error_base + 53 )

/**
 * The included logical object "%1$" cannot be added because "%2$" already exists on the Logical Object Type "%3$".
 */
#define TYPE_duplicate_included_lo_add_in_hierarchy                   ( EMH_TYPE_error_base + 54 )

/**
  * The included logical object "%1$" cannot be updated to "%2$" because it already exists on the Logical Object Type "%3$".
  */
#define TYPE_duplicate_included_lo_update_in_hierarchy                ( EMH_TYPE_error_base + 55 )

 /**
 * The creation of the Business Object has failed due to invalid characters in its internal name. Please enter text that belongs to the character set "%1$".
 */
#define TYPE_invalid_bo_name_create_failed                            ( EMH_TYPE_error_base + 56 )

 /**
 * The creation of the Business Object "%1$" has failed due to invalid characters in its name. Please enter text that belongs to the character set "%2$".
 */
#define TYPE_invalid_bo_display_name_create_failed                    ( EMH_TYPE_error_base + 57 )

 /**
 * The type "%1$" is not a valid parent Business Object. Only the type "Item" or any of its subtypes are allowed.
 */
#define TYPE_invalid_parent_business_object                           ( EMH_TYPE_error_base + 58 )

/**
 * The name of the type "%1$" cannot exceed "%2$" characters. 
 */
#define TYPE_name_max_length_exceed_create_failed                          ( EMH_TYPE_error_base + 60 )

/**
 * The name of the type "%1$" should contain US7ASCII characters only. 
 */
#define TYPE_name_non_US7ASCII_char_create_failed                          ( EMH_TYPE_error_base + 61 )

/**
 * The name of the type "%1$" should contain atleast one letter. 
 */
#define TYPE_name_not_contain_atleast_one_letter_create_failed             ( EMH_TYPE_error_base + 62 )

/**
 * The name of the type "%1$" should contain letter, digit and underscore only.
 */
#define TYPE_name_not_contain_word_chars_only_create_failed                ( EMH_TYPE_error_base + 63 )

/**
 * The name of the type "%1$" cannot contain trailing spaces.
 */
#define TYPE_name_contain_trailing_space_create_failed                     ( EMH_TYPE_error_base + 64 )

/**
 * The name of the type "%1$" cannot contain tabs.
 */
#define TYPE_name_contain_tabs_create_failed                               ( EMH_TYPE_error_base + 65 )

/**
 * The name of the type "%1$" cannot be C++ keywords.
 */
#define TYPE_name_contain_cpp_keyword_create_failed                        ( EMH_TYPE_error_base + 66 )

/**
 * The name of the type "%1$" cannot be SOA keywords.
 */
#define TYPE_name_contain_soa_keyword_create_failed                        ( EMH_TYPE_error_base + 67 )

/**
 * The name of the type "%1$" cannot be Metamodel keywords.
 */
#define TYPE_name_contain_metamodel_keyword_create_failed                   ( EMH_TYPE_error_base + 68 )

/**
 * The display name of the type "%1$" cannot exceed "%2$" characters. 
 */
#define TYPE_display_name_max_length_exceed_create_failed                   ( EMH_TYPE_error_base + 69 )

/**
 * The display name of the type "%1$" cannot contain trailing spaces.
 */
#define TYPE_display_name_contain_trailing_space_create_failed              ( EMH_TYPE_error_base + 70 ) 

/**
 * The display name of the type "%1$" cannot contain tabs.
 */
#define TYPE_display_name_contain_tabs_create_failed                        ( EMH_TYPE_error_base + 71 )

/**
 * The display name of the type "%1$" cannot contain XML characters.
 */
#define TYPE_display_name_contain_xml_chars_create_failed                   ( EMH_TYPE_error_base + 72 )

/**
 * The description of the type "%1$" cannot exceed "%2$" characters.
 */
#define TYPE_description_max_length_exceed_create_failed                    ( EMH_TYPE_error_base + 73 )

/**
 * The description of the type "%1$" cannot contain trailing spaces.
 */
#define TYPE_description_contain_trailing_space_create_failed               ( EMH_TYPE_error_base + 74 )

/**
 * The description of the type "%1$" cannot contain tabs.
 */
#define TYPE_description_contain_tabs_create_failed                         ( EMH_TYPE_error_base + 75 )

/**
 * The description of the type "%1$" cannot contain line breaks.
 */
#define TYPE_description_contain_line_breaks_create_failed                  ( EMH_TYPE_error_base + 76 )

/**
 * The type "%1$" cannot be created because following validations have failed: "%2$"
 */
#define TYPE_creation_failed                                                ( EMH_TYPE_error_base + 77 )

/**
 * The name of the type cannot be empty.
 */
#define TYPE_name_empty_create_failed                                       ( EMH_TYPE_error_base + 78 )

 /**
 * The presented property "%1$" cannot be written back for the Logical Object "%2$" because it does not support write back for multiple revisions.
 */
#define TYPE_lo_write_back_multi_revisions_not_supported                    ( EMH_TYPE_error_base + 79 )

/** @} */
#include <tccore/libtccore_undef.h>
#endif
