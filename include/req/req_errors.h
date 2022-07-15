/*==============================================================================
                Copyright (c) 2006 UGS Corporation
                   Unpublished - All Rights Reserved
================================================================================

    @file

    Define error codes used with Tc Requirement.

==============================================================================*/

#ifndef REQ_ERRORS_H
#define REQ_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup REQ_ERRORS Errors
    @ingroup REQ
    @{
*/

/** Module level errors - ALLOCATING 20 positions */
#define REQ_module_initialization_failed        (EMH_REQ_error_base + 1)
#define REQ_EPM_Handler_registration_failed     (EMH_REQ_error_base + 2)
#define REQ_EMP_SM_handler_failed               (EMH_REQ_error_base + 3)
#define REQ_EMP_Gen_handler_failed              (EMH_REQ_error_base + 4)

/** Access to the object "%1$" is denied. Please refer to the Teamcenter server syslog file for more details.*/
#define REQ_access_denied                       (EMH_REQ_error_base + 5)

/** Unable to initialize FullText Attributes */
#define FTX_initialization_failed               (EMH_REQ_error_base + 21)
#define FTX_bad_position                        (EMH_REQ_error_base + 22)
#define FTX_internal_error                      (EMH_REQ_error_base + 23)

#define REQ_default_styles_template_not_found   (EMH_REQ_error_base + 26)
#define REQ_styles_template_not_found           (EMH_REQ_error_base + 27)
#define REQ_content_object_not_found            (EMH_REQ_error_base + 28)
#define REQ_export_template_inavlid_type        (EMH_REQ_error_base + 29)
#define REQ_excel_template_not_found           (EMH_REQ_error_base + 30)
#define REQ_invalid_excel_template_path         (EMH_REQ_error_base + 31)
#define REQ_excel_tags_not_found                (EMH_REQ_error_base + 32)
#define REQ_duplicate_tags_found                (EMH_REQ_error_base + 33)
#define REQ_invalid_column_order                (EMH_REQ_error_base + 34)
#define REQ_missing_columns                     (EMH_REQ_error_base + 35)
#define REQ_no_matching_rule                    (EMH_REQ_error_base + 36)
#define REQ_excel_template_revision_not_found   (EMH_REQ_error_base + 37)
#define REQ_excel_template_dataset_not_found    (EMH_REQ_error_base + 38)
#define REQ_excel_duplicate_columns_found       (EMH_REQ_error_base + 39)
#define REQ_no_attributes_for_export            (EMH_REQ_error_base + 40)
#define REQ_no_named_reference                  (EMH_REQ_error_base + 41)
#define REQ_cannot_export_precise               (EMH_REQ_error_base + 42)
#define REQ_cannot_export_multisheet            (EMH_REQ_error_base + 43)
#define REQ_invalid_relation_columns_pos        (EMH_REQ_error_base + 44)
#define REQ_cannot_export_by_view               (EMH_REQ_error_base + 45)
#define REQ_cannot_export_packing_template      (EMH_REQ_error_base + 46)
#define REQ_invalid_column_data                 (EMH_REQ_error_base + 47)
#define REQ_footer_not_supported                (EMH_REQ_error_base + 48)
#define REQ_flatlist_not_supported              (EMH_REQ_error_base + 49)

#define EXP_invalid_objectType                  (EMH_REQ_error_base + 50)
#define EXP_prop_metadata_not_found             (EMH_REQ_error_base + 51)
#define EXP_lov_error                           (EMH_REQ_error_base + 52)
#define EXP_invalid_transVolDir                 (EMH_REQ_error_base + 55)
#define EXP_filecreate_failed                   (EMH_REQ_error_base + 56)
#define EXP_createTransTicket_failed            (EMH_REQ_error_base + 57)
#define REQ_cleartext_unavailable               (EMH_REQ_error_base + 58)
#define REQ_string_exceeds_maxlength            (EMH_REQ_error_base + 59)

#define TEMPLATE_insufficient_privillage        (EMH_REQ_error_base + 70)
#define TEMPLATE_duplicate_name                 (EMH_REQ_error_base + 71)
#define TEMPLATE_empty_name                     (EMH_REQ_error_base + 72)

#define REQ_import_wordlive_partial_sucess      (EMH_REQ_error_base + 73)
#define TEMPLATE_insufficient_privillage_for_editing        (EMH_REQ_error_base + 74)
#define TEMPLATE_failed_to_add_parts            (EMH_REQ_error_base + 75)
#define REQ_non_workspace_objects               (EMH_REQ_error_base + 76)
#define REQ_TRANSCODING_ERROR                   (EMH_REQ_error_base + 77)
#define REQ_revision_already_associated         (EMH_REQ_error_base + 78)
#define REQ_customnote_already_associated       (EMH_REQ_error_base + 79)
#define REQ_not_well_formed_body_text           (EMH_REQ_error_base + 80)
#define REQ_delimiter_cannot_be_a_colon         (EMH_REQ_error_base + 81)
#define REQ_template_not_found                  (EMH_REQ_error_base + 82)
#define REQ_objects_not_found                   (EMH_REQ_error_base + 83)
#define REQ_invalid_template_type               (EMH_REQ_error_base + 84)
#define REQ_invalid_object_uid                  (EMH_REQ_error_base + 85)
#define REQ_invalid_report_uid                  (EMH_REQ_error_base + 86)
#define REQ_invalid_revrule_uid                 (EMH_REQ_error_base + 87)

/** Excel Import Error messages**/
#define EIMP_unknown_error                        (EMH_REQ_error_base + 88)
#define EIMP_tempdir_notfound                    (EMH_REQ_error_base + 89)
#define EIMP_no_object_to_process                (EMH_REQ_error_base + 90)
#define EIMP_xmldoc_InitializeFailed            (EMH_REQ_error_base + 91)
#define EIMP_attr_value_not_present               (EMH_REQ_error_base + 92)
#define EIMP_xmlelement_creation_failed           (EMH_REQ_error_base + 93)
#define EIMP_null_xmlelement_passed                   (EMH_REQ_error_base + 94)
#define EIMP_GSI_xmlelement_not_found               (EMH_REQ_error_base + 95)
#define EIMP_empty_node_value                       (EMH_REQ_error_base + 96)
#define EIMP_invalid_soa_output                       (EMH_REQ_error_base + 97)
#define EIMP_xml_element_absent                       (EMH_REQ_error_base + 98)
#define EIMP_itemrevision_element_absent        (EMH_REQ_error_base + 99)
#define EIMP_item_element_absent                (EMH_REQ_error_base + 100)
#define EIMP_invalid_revision_id                (EMH_REQ_error_base + 101)
#define EIMP_form_element_absent                (EMH_REQ_error_base + 102)
#define EIMP_GRM_element_absent                    (EMH_REQ_error_base + 103)
#define EIMP_latest_revision_absent                (EMH_REQ_error_base + 104)
#define EIMP_OCC_element_absent                    (EMH_REQ_error_base + 105)
#define EIMP_no_revision_type_present            (EMH_REQ_error_base + 106)
#define EIMP_type_not_supported                   (EMH_REQ_error_base + 107)
#define EIMP_new_revision_not_supported           (EMH_REQ_error_base + 108)
#define EIMP_invalid_extension                    (EMH_REQ_error_base + 109)

/** The presence of custom document properties is detected in the imported Word document, which is not supported. In the
Word application, use the following menu command sequence to remove them: File->Info->Properties->Advanced Properties. */
#define TEMPLATE_contains_custom_parts            (EMH_REQ_error_base + 110)

/** Excel Export Error messages Range 200 to 300**/
#define REQ_empty_columns_found                       (EMH_REQ_error_base + 200)

/** MS Excel's outlining feature can only display up to 8 levels. Since this structure exceeds that number of levels, it will be exported as a flat list. **/
#define REQ_excel_outline_limit_static                (EMH_REQ_error_base + 201)

/** MS Excel's outlining feature can only display up to 8 levels. Since this structure exceeds that number of levels, it will be exported as a flat list. 
Since the generated sheet will not accurately represent the levels, it cannot be used for re-import. **/
#define REQ_excel_outline_limit_reimport              (EMH_REQ_error_base + 202)
#define REQ_not_supported_for_reimport                (EMH_REQ_error_base + 203)
#define REQ_runtimeobjects_not_supported              (EMH_REQ_error_base + 204)
#define REQ_Word_template_not_found                   (EMH_REQ_error_base + 205)
#define REQ_external_references_found                 (EMH_REQ_error_base + 206)
#define REQ_excel_checkout_warning                    (EMH_REQ_error_base + 207)
#define REQ_summ_report_genurl_failed                 (EMH_REQ_error_base + 208)

/** The Trace View template "%1$" is invalid. The number of reports in Trace View should match the number of sheets in the template.
Please select an appropriate template as per the report type of Trace View.*/
#define REQ_invalid_traceview_template                (EMH_REQ_error_base + 209)

/** Word Offline Import/Export Error messages Range 300 to 400 **/
#define REQ_multiple_object_not_allowed         (EMH_REQ_error_base + 300)
#define REQ_transfer_mode_rule_found            (EMH_REQ_error_base + 301)

/** No input object is being provided. Please select the object to find the matching BOM Line. **/
#define REQ_no_input_objects                    (EMH_REQ_error_base + 302)

/**  The input object type "%1$" is invalid for this operation. Please select an Item Revision. **/
#define REQ_invalid_object_type                 (EMH_REQ_error_base + 303)

/**  The file could not be imported because the path is invalid. **/
#define REQ_invalid_file_path                   (EMH_REQ_error_base + 304)

/** "%1$" was not associated with "%2$" because it already is associated with "%3$".**/
#define REQ_template_already_assigned           (EMH_REQ_error_base + 305)

/** Markup and general REQ error messages Range 400 to 450 **/
#define REQ_unknown_error                       (EMH_REQ_error_base + 400)
#define REQ_memory_allocation_failed            (EMH_REQ_error_base + 401)
#define REQ_gather_markups_failed               (EMH_REQ_error_base + 402)
#define REQ_failed_to_get_class_id              (EMH_REQ_error_base + 403)
#define REQ_failed_to_find_markup_dataset_type  (EMH_REQ_error_base + 404)
#define REQ_failed_to_create_markup_dataset     (EMH_REQ_error_base + 405)
#define REQ_relation_type_not_found             (EMH_REQ_error_base + 406)
#define REQ_invalid_temp_directory              (EMH_REQ_error_base + 407)
#define REQ_invalid_tag_nulltag                 (EMH_REQ_error_base + 408)
#define REQ_bad_parameter                       (EMH_REQ_error_base + 409)
#define REQ_bad_param_nulltag                   (EMH_REQ_error_base + 410)
#define REQ_bad_param_empty_filename            (EMH_REQ_error_base + 411)
#define REQ_bad_param_empty_string              (EMH_REQ_error_base + 412)
#define REQ_bad_param_null_fileticket           (EMH_REQ_error_base + 413)
#define REQ_bad_param_null_value                (EMH_REQ_error_base + 414)
#define REQ_getTransientFileTickets_failed      (EMH_REQ_error_base + 415)
#define REQ_invalid_markup_comment_XML          (EMH_REQ_error_base + 416)
#define REQ_markup_file_empty_or_parse_failed   (EMH_REQ_error_base + 417)
#define REQ_xml_exception                       (EMH_REQ_error_base + 418)
#define REQ_no_fulltext_dataset_found           (EMH_REQ_error_base + 419)
#define REQ_no_datasets_found                   (EMH_REQ_error_base + 420)
#define REQ_create_markups_failed               (EMH_REQ_error_base + 421)
#define REQ_update_markups_failed               (EMH_REQ_error_base + 422)
#define REQ_unable_to_download_file             (EMH_REQ_error_base + 423)
#define REQ_markup_present                      (EMH_REQ_error_base + 424)

/** PIE error messages Range 451 to 500 **/
#define REQ_get_child_element_failed            (EMH_REQ_error_base + 451)
#define REQ_get_primary_secondary_failed        (EMH_REQ_error_base + 452)

/** The Link type specified in the configuration file is invalid. */
#define REQ_invalid_link_type                   (EMH_REQ_error_base + 453)

/** The "Content Type" property of the FullText dataset has been changed from "Rich Text" to "Plain Text", which has caused loss of formatting details.
In order to revert back the changes, open the earlier sequence of the FullText dataset version by performing a search, and copy its content to this current version */
#define REQ_richtext_to_plaintext_warning       (EMH_REQ_error_base + 454)

/** The action of changing the "Content Type" property of the FullText dataset from "Plain Text" to "HTML" is not currently supported.*/
#define REQ_plaintext_to_html_error             (EMH_REQ_error_base + 455)

/** The "Content Type" property of the FullText dataset has been changed from "HTML" to "Plain Text", which has caused loss of formatting details.
In order to revert back the changes, open the earlier sequence of the FullText dataset version by performing a search, and copy its content to this current version */
#define REQ_html_to_plaintext_warning           (EMH_REQ_error_base + 456)

/** The action of changing the "Content Type" property of the FullText dataset from "HTML" to "Rich Text" is not currently supported.*/
#define REQ_html_to_richtext_error              (EMH_REQ_error_base + 457)

/** The action of changing the "Content Type" property of the FullText dataset from "Rich Text" to "HTML" is not currently supported.*/
#define REQ_richtext_to_html_error              (EMH_REQ_error_base + 458)

/** An error has occurred while pasting the Specification "%1$" to the folder "%2$". The Specification has been pasted to the Newstuff folder instead. */
#define REQ_import_new_specification_in_folder  (EMH_REQ_error_base + 459)

/** Flat File error messages Range 501 to 550 **/
/** The object "%1$" cannot be revised, because a working revision already exists and the system does not support more than one working revision.*/
#define REQ_open_revision_exists                (EMH_REQ_error_base + 501)

/** The object "%1$" cannot be found in the database. */
#define REQ_flat_file_object_not_found          (EMH_REQ_error_base + 502)

/** The Trace Link cannot be created, because the source and the target objects are the same (%1$).*/
#define REQ_tracelink_to_self                   (EMH_REQ_error_base + 503)

/** The operation has failed, because multiple flat file datasets are attached to the specification revision "%1$".*/
#define REQ_multiple_flat_file_datasets         (EMH_REQ_error_base + 504)

/** An invalid object is passed for the Trace Link creation. A valid POM Object is expected.*/
#define REQ_invalid_resolution_object           (EMH_REQ_error_base + 505)

/** The following path used to import an HTML object template is invalid: %1$.*/
#define REQ_invalid_html_object_template_path   (EMH_REQ_error_base + 506)

/** An invalid Requirement Template file is provided.*/
#define REQ_invalid_template_path               (EMH_REQ_error_base + 507)

/** An invalid Requirement Template is provided.*/
#define REQ_invalid_requirement_template        (EMH_REQ_error_base + 508)

/** The selected objects were not exported because the Excel Template option "apply_bom_crawling" is not supported for "Excel Live" and "Excel Re-import".*/
#define REQ_crawlback_not_supported             (EMH_REQ_error_base + 509)

/** The selection cannot be edited because of an internal error. */
#define REQ_no_preference_for_word_edit         (EMH_REQ_error_base + 510)

/** The sheet contains an invalid object "%1$".*/
#define REQ_invalid_object_types_in_sheet       (EMH_REQ_error_base + 511)

/** File "%1$" could not be imported because column "A" header is incorrect.*/
#define REQ_invalid_header_level                (EMH_REQ_error_base + 512)

/** File "%1$" could not be imported because column "B" header is incorrect.*/
#define REQ_invalid_header_object_type          (EMH_REQ_error_base + 513)

/** File "%1$" could not be imported because column "A" data does not end with "&#38;lt;endtag&gt;".*/
#define REQ_no_endtag_in_sheet                  (EMH_REQ_error_base + 514)

/** File "%1$" could not be imported because the top line is not specified.*/
#define REQ_no_topline_in_sheet                 (EMH_REQ_error_base + 515)

/** The input application format is not supported.*/
#define REQ_applicaton_format_not_supported     (EMH_REQ_error_base + 516)

/** "%1$" could not be imported because no columns are present for import.*/
#define REQ_no_column_header_in_sheet           (EMH_REQ_error_base + 517)

/** "%1$" failed to import.*/
#define REQ_excel_import_failed                 (EMH_REQ_error_base + 518)

/** "%1$" has been imported successfully. "%2$" mapping could not be saved because of an internal error.*/
#define REQ_excel_failed_to_save_mapping        (EMH_REQ_error_base + 519)

/** "%1$" is being converted and will appear here.*/
#define REQ_object_being_converted                (EMH_REQ_error_base + 520)

/** "%1$" cannot be saved because it contains invalid characters.*/
#define REQ_invalid_chars                         (EMH_REQ_error_base + 521)

/** @} */
#endif
