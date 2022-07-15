/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains all the query error numbers. It was originally named
    as query_errors.h  It is now qry_errors.h so that it is consistent
    with the module naming convention.
*/

/*  */

#ifndef qry_errors_h
#define qry_errors_h

#include <common/emh_const.h>

/**
    @defgroup QRY_ERRORS Errors
    @ingroup QRY
    @{
*/

#define QRY_invalid_class                   (EMH_QRY_error_base + 1)
#define QRY_invalid_query                   (EMH_QRY_error_base + 2)
#define QRY_invalid_token                   (EMH_QRY_error_base + 3)
#define QRY_invalid_command                 (EMH_QRY_error_base + 4)
#define QRY_invalid_attribute               (EMH_QRY_error_base + 5)
#define QRY_enquiry_not_available           (EMH_QRY_error_base + 6)
#define QRY_not_a_number                    (EMH_QRY_error_base + 7)
#define QRY_not_a_char                      (EMH_QRY_error_base + 8)
#define QRY_not_a_date                      (EMH_QRY_error_base + 9)
#define QRY_not_a_double                    (EMH_QRY_error_base + 10)
#define QRY_not_an_integer                  (EMH_QRY_error_base + 11)
#define QRY_not_a_logical                   (EMH_QRY_error_base + 12)
#define QRY_not_combo_attr                  (EMH_QRY_error_base + 13)
#define QRY_invalid_ref_list                (EMH_QRY_error_base + 14)
#define QRY_not_a_subquery                  (EMH_QRY_error_base + 15)
#define QRY_invalid_result_id               (EMH_QRY_error_base + 16)
#define QRY_no_selections_found             (EMH_QRY_error_base + 17)
#define QRY_not_a_WSO                       (EMH_QRY_error_base + 18)
#define QRY_no_attribute_specified          (EMH_QRY_error_base + 19)
#define QRY_no_value_specified              (EMH_QRY_error_base + 20)
#define QRY_no_query_specified              (EMH_QRY_error_base + 21)
#define QRY_no_attributes                   (EMH_QRY_error_base + 22)
#define QRY_invalid_action                  (EMH_QRY_error_base + 23)
#define QRY_no_class_specified              (EMH_QRY_error_base + 24)
#define QRY_invalid_value                   (EMH_QRY_error_base + 25)
#define QRY_invalid_display_mode            (EMH_QRY_error_base + 26)
#define QRY_no_initialize_class             (EMH_QRY_error_base + 27)
#define QRY_no_create                       (EMH_QRY_error_base + 28)
#define QRY_null_not_allowed                (EMH_QRY_error_base + 29)
#define QRY_not_found                       (EMH_QRY_error_base + 30)
#define QRY_invalid_list_of_user_entries    (EMH_QRY_error_base + 31)
#define QRY_not_an_user_entry               (EMH_QRY_error_base + 32)
#define QRY_user_entry_not_allow_null       (EMH_QRY_error_base + 33)
#define QRY_invalid_query_mode              (EMH_QRY_error_base + 34)
#define QRY_enquiry_on_note_not_available   (EMH_QRY_error_base + 35)
#define QRY_parse_error                     (EMH_QRY_error_base + 36)
#define QRY_invalid_name_mode               (EMH_QRY_error_base + 37)
#define QRY_name_already_exist              (EMH_QRY_error_base + 38)
#define QRY_cannot_modify                   (EMH_QRY_error_base + 39)
#define QRY_cannot_execute                  (EMH_QRY_error_base + 40)
#define QRY_null_value_not_allowed          (EMH_QRY_error_base + 41)
#define QRY_unable_to_build_class_list      (EMH_QRY_error_base + 42)
#define QRY_invalid_attribute_selection     (EMH_QRY_error_base + 43)
#define QRY_invalid_search_domain           (EMH_QRY_error_base + 44)
#define QRY_keyword_not_supported           (EMH_QRY_error_base + 45)
#define QRY_remote_query_failure            (EMH_QRY_error_base + 46)
#define QRY_invalid_int_value               (EMH_QRY_error_base + 47)
#define QRY_cannot_display_output           (EMH_QRY_error_base + 48)
#define QRY_invalid_where_run               (EMH_QRY_error_base + 49)
#define QRY_no_row_mapping                  (EMH_QRY_error_base + 50)
#define QRY_is_user_query                   (EMH_QRY_error_base + 51)
#define QRY_not_user_query                  (EMH_QRY_error_base + 52)
#define QRY_invalid_wildcard                (EMH_QRY_error_base + 53)

/** The report dataset has been generated in the "Newstuff" folder. */
#define QRY_keyword_search_engine_not_set   (EMH_QRY_error_base + 54)
#define QRY_keyword_search_client_error     (EMH_QRY_error_base + 55)
#define QRY_no_pff_DTD                      (EMH_QRY_error_base + 57)
#define QRY_pff_format_error                (EMH_QRY_error_base + 58)
#define QRY_autonomy_lib_failed             (EMH_QRY_error_base + 59)
#define QRY_autonomy_api_failed             (EMH_QRY_error_base + 60)
#define QRY_autonomy_api_call_failed        (EMH_QRY_error_base + 61)
#define QRY_autonomy_aci_bad_parameter      (EMH_QRY_error_base + 62)
#define QRY_autonomy_aci_cannot_connect     (EMH_QRY_error_base + 63)
#define QRY_autonomy_aci_memory_error       (EMH_QRY_error_base + 64)
#define QRY_autonomy_aci_tag_not_found      (EMH_QRY_error_base + 65)
#define QRY_autonomy_aci_bad_value          (EMH_QRY_error_base + 66)
#define QRY_autonomy_aci_not_multiple       (EMH_QRY_error_base + 67)
#define QRY_autonomy_aci_file_not_found     (EMH_QRY_error_base + 68)
#define QRY_autonomy_aci_unknown_error      (EMH_QRY_error_base + 69)
#define QRY_fts_type_not_indexed            (EMH_QRY_error_base + 70)
#define QRY_fts_index_fileop_error          (EMH_QRY_error_base + 71)
#define QRY_fts_not_set                     (EMH_QRY_error_base + 72)
#define QRY_preference_not_retrieved        (EMH_QRY_error_base + 73)
#define QRY_cannot_create_directory         (EMH_QRY_error_base + 74)
#define QRY_cannot_add_namedrefs            (EMH_QRY_error_base + 75)
#define QRY_error_compress_failure          (EMH_QRY_error_base + 76)
#define QRY_fts_import_error                (EMH_QRY_error_base + 77)
#define MSS_key_value_counts_not_match      (EMH_QRY_error_base + 78)
#define MSS_input_count_is_less_than_one    (EMH_QRY_error_base + 79)
#define QRY_cannot_set_results_type         (EMH_QRY_error_base + 80)

/** A keyword search is attempted, but the functionality is not enabled yet. Please contact your administrator to configure and enable the text search functionality. */
#define QRY_execution_failed                (EMH_QRY_error_base + 81)
#define QRY_wildcard_specify_error          (EMH_QRY_error_base + 82)
#define QRY_specify_valid_report_name_or_tag (EMH_QRY_error_base + 83)
#define QRY_mss_key_length_exceeds_limit    (EMH_QRY_error_base + 84)
#define QRY_keyword_search_error            (EMH_QRY_error_base + 85)
#define QRY_invalid_ics_multiapp_search     (EMH_QRY_error_base + 86)
#define REP_transformation_error            (EMH_QRY_error_base + 87)
#define QRY_names_validation_failed         (EMH_QRY_error_base + 88)
#define QRY_descs_validation_failed         (EMH_QRY_error_base + 89)
#define QRY_translations_validation_failed  (EMH_QRY_error_base + 90)
#define REP_invalid_input_value             (EMH_QRY_error_base + 91)

#define SSR_invalid_report_execution_type   (EMH_QRY_error_base + 92)
#define SSR_parameter_name_value_mismatch   (EMH_QRY_error_base + 93)
#define SSR_xml_exception                   (EMH_QRY_error_base + 94)
#define SSR_invalid_xml_filename            (EMH_QRY_error_base + 95)
#define SSR_null_tags_not_allowed           (EMH_QRY_error_base + 96)

/** The definition of the saved query cannot be retrieved. Please refer to the Teamcenter server log file for details, and contact your system administrator to ensure the saved query definition exists. */
#define QRY_cannot_retrieve_query_definition (EMH_QRY_error_base + 97)

/** The report dataset has been generated in the "Newstuff" folder. */
#define CRF_report_created_in_newstuff      (EMH_QRY_error_base + 98)

/** The extended multi-application search capacity is not supported from the web client. Please ensure that the saved search executed from the web client does not contain any classification attributes, and try again. */
#define QRY_multi_app_search_not_supported  (EMH_QRY_error_base + 99)

/** Too many objects were found to check for the latest Item Revision. Please redefine your search so that it returns less objects, or change the value for the preference "QRY_latest_ItemRevision_limit". */
#define QRY_too_many_objects_for_latest_item_revision  (EMH_QRY_error_base + 100)

/** The value "%1$" provided for the Digital Signature State is incorrect. Allowed values are "Valid", "Invalid", "Voided" and "Revoked". */
#define QRY_incorrect_ds_status_value                  (EMH_QRY_error_base + 101)

/** The report path is either null or empty */
#define CRF_report_path_null_or_empty                  (EMH_QRY_error_base + 102)

/** No report definition is found for the provided business objects */
#define CRF_no_report_definition_found                 (EMH_QRY_error_base + 103)

/** The report cannot be generated asynchronously, because the dispatcher is not installed. Please contact your system administrator to install and configure the dispatcher for the asynchronous framework. */
#define CRF_dispatcher_not_installed                   (EMH_QRY_error_base + 104)

/** The tuple query contains an "OR" clause, which is not supported. */
#define QRY_tuples_with_or                             (EMH_QRY_error_base + 105)

/** The custom report "%1$" does not provide method definition name. */
#define CRF_custom_report_no_name                      (EMH_QRY_error_base + 106)

/** The custom report "%1$" does not support the definition name "%2$". */
#define CRF_custom_report_unsupported_name             (EMH_QRY_error_base + 107)

/** The custom report "%1$" does not contain any object in context. */
#define CRF_custom_report_no_context_obj               (EMH_QRY_error_base + 108)

/** The custom report "%1$" does not have any data to report. */
#define CRF_custom_report_no_data_to_report            (EMH_QRY_error_base + 109)

/** The custom report "%1$" does not provide a defined method. */
#define CRF_custom_report_missing_method               (EMH_QRY_error_base + 110)

/** The custom report "%1$" uses an unsupported method "%2$". */
#define CRF_custom_report_unsupported_method           (EMH_QRY_error_base + 111)

/** No custom report library is defined by the preference "TC_custom_item_report_itk_library" */
#define CRF_custom_report_no_custom_lib_defined        (EMH_QRY_error_base + 112)

/** No callback obtained for saved query "%1$". This saved query requires a callback to be registered which creates a POM enquiry. */
#define QRY_no_callback_for_query                      (EMH_QRY_error_base + 113)

/** @} */

#endif
