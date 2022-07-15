/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Defines error codes used with OBJIO Step
*/

/*  */

#ifndef OBJIO_STEP_ERRORS_H
#define OBJIO_STEP_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup OBJIO_STEP_ERRORS Step Errors
    @ingroup OBJIO_STEP
    @{
*/

#define EMH_OBJIO_STEP_ERROR_BASE                                       57000

/**
    @name Export Error Codes
    @{
*/
#define OBJIO_STEP_cannot_set_product_attrs                             (EMH_OBJIO_STEP_ERROR_BASE )
#define OBJIO_STEP_cannot_create_product_definition_formation           (EMH_OBJIO_STEP_ERROR_BASE + 1)
#define OBJIO_STEP_cannot_create_person_org                             (EMH_OBJIO_STEP_ERROR_BASE + 2)
#define OBJIO_STEP_cannot_create_product_category                       (EMH_OBJIO_STEP_ERROR_BASE + 3)
#define OBJIO_STEP_cannot_create_product_type                           (EMH_OBJIO_STEP_ERROR_BASE + 4)
#define OBJIO_STEP_cannot_create_applied_person_and_organization_asst   (EMH_OBJIO_STEP_ERROR_BASE + 5)
#define OBJIO_STEP_cannot_create_approval                               (EMH_OBJIO_STEP_ERROR_BASE + 6)
#define OBJIO_STEP_cannot_create_product_definition                     (EMH_OBJIO_STEP_ERROR_BASE + 7)
#define OBJIO_STEP_cannot_create_product_definition_with_ass_doc        (EMH_OBJIO_STEP_ERROR_BASE + 8)
#define OBJIO_STEP_cannot_create_security_class                         (EMH_OBJIO_STEP_ERROR_BASE + 9)
#define OBJIO_STEP_cannot_create_document_with_class                    (EMH_OBJIO_STEP_ERROR_BASE + 10)
#define OBJIO_STEP_cannot_create_document                               (EMH_OBJIO_STEP_ERROR_BASE + 11)
#define OBJIO_STEP_cannot_create_applied_person_and_org                 (EMH_OBJIO_STEP_ERROR_BASE + 12)
#define OBJIO_STEP_cannot_create_assembly                               (EMH_OBJIO_STEP_ERROR_BASE + 13)
#define OBJIO_STEP_cannot_create_digital_document                       (EMH_OBJIO_STEP_ERROR_BASE + 14)
#define OBJIO_STEP_cannot_create_date_and_time                          (EMH_OBJIO_STEP_ERROR_BASE + 15)
#define OBJIO_STEP_cannot_set_appl_context_attrs                        (EMH_OBJIO_STEP_ERROR_BASE + 16)
#define OBJIO_STEP_cannot_set_mechanical_context_attrs                  (EMH_OBJIO_STEP_ERROR_BASE + 17)
#define OBJIO_STEP_cannot_set_appl_prot_def_attrs                       (EMH_OBJIO_STEP_ERROR_BASE + 18)
#define OBJIO_STEP_cannot_set_doc_attrs                                 (EMH_OBJIO_STEP_ERROR_BASE + 19)
#define OBJIO_STEP_cannot_create_cc_design_spec_reference               (EMH_OBJIO_STEP_ERROR_BASE + 20)
#define OBJIO_STEP_cannot_create_applied_document_reference             (EMH_OBJIO_STEP_ERROR_BASE + 21)
#define OBJIO_STEP_cannot_set_doc_type_attrs                            (EMH_OBJIO_STEP_ERROR_BASE + 22)
#define OBJIO_STEP_cannot_create_applied_date_and_time                  (EMH_OBJIO_STEP_ERROR_BASE + 23)
#define OBJIO_STEP_cannot_set_applied_approval_asst_attr                (EMH_OBJIO_STEP_ERROR_BASE + 24)
#define OBJIO_STEP_unknown_object                                       (EMH_OBJIO_STEP_ERROR_BASE + 25)
#define OBJIO_STEP_cannot_create_approval_date_and_time                 (EMH_OBJIO_STEP_ERROR_BASE + 26)
#define OBJIO_STEP_cannot_create_cc_design_approval                     (EMH_OBJIO_STEP_ERROR_BASE + 27)
#define OBJIO_STEP_cannot_create_cc_design_person_and_org               (EMH_OBJIO_STEP_ERROR_BASE + 28)
#define OBJIO_STEP_cannot_create_cc_design_security_class               (EMH_OBJIO_STEP_ERROR_BASE + 29)
#define OBJIO_STEP_cannot_handle_this_datatype                          (EMH_OBJIO_STEP_ERROR_BASE + 30)
#define OBJIO_STEP_cannot_handle_this_dataset                           (EMH_OBJIO_STEP_ERROR_BASE + 31)
#define OBJIO_STEP_cannot_handle_this_bvr                               (EMH_OBJIO_STEP_ERROR_BASE + 32)
#define OBJIO_STEP_cannot_handle_this_ItemRevision                      (EMH_OBJIO_STEP_ERROR_BASE + 33)
#define OBJIO_STEP_cannot_handle_this_Item                              (EMH_OBJIO_STEP_ERROR_BASE + 34)
#define OBJIO_STEP_cannot_handle_this_occurrence                        (EMH_OBJIO_STEP_ERROR_BASE + 35)
#define OBJIO_STEP_export_message                                       (EMH_OBJIO_STEP_ERROR_BASE + 36)
#define OBJIO_STEP_invalid_object                                       (EMH_OBJIO_STEP_ERROR_BASE + 37)
#define OBJIO_STEP_cannot_get_tc_details                                (EMH_OBJIO_STEP_ERROR_BASE + 38)
#define OBJIO_STEP_cannot_copy_file                                     (EMH_OBJIO_STEP_ERROR_BASE + 39)
#define OBJIO_STEP_cannot_handle_this_attachment                        (EMH_OBJIO_STEP_ERROR_BASE + 40)
#define OBJIO_STEP_cannot_create_directed_action                        (EMH_OBJIO_STEP_ERROR_BASE + 41)
#define OBJIO_STEP_cannot_create_applied_action_assignment              (EMH_OBJIO_STEP_ERROR_BASE + 42)
#define OBJIO_STEP_cannot_create_action_status                          (EMH_OBJIO_STEP_ERROR_BASE + 43)
#define OBJIO_STEP_cannot_create_action_method                          (EMH_OBJIO_STEP_ERROR_BASE + 44)
#define OBJIO_STEP_cannot_create_action_directive                       (EMH_OBJIO_STEP_ERROR_BASE + 45)
#define OBJIO_STEP_cannot_create_applied_action_request_assignment      (EMH_OBJIO_STEP_ERROR_BASE + 46)
#define OBJIO_STEP_cannot_create_versioned_action_request               (EMH_OBJIO_STEP_ERROR_BASE + 47)
#define OBJIO_STEP_cannot_create_action_assignment_role                 (EMH_OBJIO_STEP_ERROR_BASE + 48)
#define OBJIO_STEP_cannot_create_action_request_assignment_role         (EMH_OBJIO_STEP_ERROR_BASE + 49)
#define OBJIO_STEP_cannot_create_action_request_status                  (EMH_OBJIO_STEP_ERROR_BASE + 50)
#define OBJIO_STEP_cannot_create_action_request_solution                (EMH_OBJIO_STEP_ERROR_BASE + 51)
#define OBJIO_STEP_cannot_create_action_request_role                    (EMH_OBJIO_STEP_ERROR_BASE + 52)
#define OBJIO_STEP_platform_not_supported                               (EMH_OBJIO_STEP_ERROR_BASE + 53)
/** @} */

#define OBJIO_STEP_invalid_application_protocol                         (EMH_OBJIO_STEP_ERROR_BASE + 301)
#define OBJIO_STEP_cannot_create_item                                   (EMH_OBJIO_STEP_ERROR_BASE + 302)
#define OBJIO_STEP_cannot_match_files                                   (EMH_OBJIO_STEP_ERROR_BASE + 303)
#define OBJIO_STEP_file_read_error                                      (EMH_OBJIO_STEP_ERROR_BASE + 304)
#define OBJIO_STEP_file_open_error                                      (EMH_OBJIO_STEP_ERROR_BASE + 306)
#define OBJIO_STEP_file_close_error                                     (EMH_OBJIO_STEP_ERROR_BASE + 307)

/**
    @name Errors For Step Import Modules
    @{
*/
#define  EMH_OBJIO_STEP_IMPORT_ERROR_BASE                                (EMH_OBJIO_STEP_ERROR_BASE + 500)
#define  OBJIO_STEP_cannot_initialize_text_services                      (EMH_OBJIO_STEP_IMPORT_ERROR_BASE )
#define  OBJIO_STEP_insufficent_arguments                              (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 1)
#define  OBJIO_STEP_cannot_read_pref_value                               (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 2)
#define  OBJIO_STEP_cannot_write_pref_value                              (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 3)
#define  OBJIO_STEP_cannot_create_rose_design                            (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 4)
#define  OBJIO_STEP_could_not_translate_data                             (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 5)
#define  OBJIO_STEP_error_while_importing_to_TC                          (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 6)
#define  OBJIO_STEP_could_not_release_object                             (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 7)
#define  OBJIO_STEP_out_of_memory                                        (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 8)
#define  OBJIO_STEP_null_attribute                                       (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 9)
#define  OBJIO_STEP_datset_instance_not_available                        (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 10)
#define  OBJIO_STEP_bom_view_revision_instance_not_available             (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 11)
#define  OBJIO_STEP_item_rev_instance_not_available                      (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 12)
#define  OBJIO_STEP_dummy_value                                          (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 13)
#define  OBJIO_STEP_unable_to_generate_new_id                            (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 14)
#define  OBJIO_STEP_unable_to_import_item                                (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 15)
#define  OBJIO_STEP_unable_to_import_item_revision                       (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 16)
#define  OBJIO_STEP_null_tag                                             (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 17)
#define  OBJIO_STEP_owning_user_not_set                                  (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 18)
#define  OBJIO_STEP_could_not_create_view_type                           (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 19)
#define  OBJIO_STEP_could_not_create_bom_view                            (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 20)
#define  OBJIO_STEP_invalid_file_type                                    (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 21)
#define  OBJIO_STEP_unable_to_import_primary_object                      (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 22)
#define  OBJIO_STEP_unable_to_import_secondary_object                    (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 23)
#define  OBJIO_STEP_invalid_value                                        (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 24)
#define  OBJIO_STEP_null_view_type                                       (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 25)
#define  OBJIO_STEP_could_not_create_bom_view_rev                        (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 26)
#define  OBJIO_STEP_file_not_imported                                    (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 27)
#define  OBJIO_STEP_attachment_failed                                    (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 28)
#define  OBJIO_STEP_unable_to_import_primary_obj                         (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 29)
#define  OBJIO_STEP_unable_to_import_secondary_obj                       (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 30)
#define  OBJIO_STEP_could_not_import_occurrences                         (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 31)
#define  OBJIO_STEP_dataset_instance_not_available                       (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 32)
#define  OBJIO_STEP_bom_view_instance_not_available                      (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 33)
#define  OBJIO_STEP_basic_info                                           (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 34)
#define  OBJIO_STEP_file_info                                            (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 35)
#define  OBJIO_STEP_directory_not_found                                  (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 36)
#define  OBJIO_STEP_file_does_not_exist                                  (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 37)
#define  OBJIO_STEP_import_message                                       (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 38)
#define  OBJIO_STEP_invalid_product_context                              (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 39)
#define  OBJIO_STEP_ap_definition_not_found                              (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 40)
#define  OBJIO_STEP_could_not_create_item                                (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 41)
#define  OBJIO_STEP_could_not_create_item_revision                       (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 42)
#define  OBJIO_STEP_could_not_save_item                                  (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 43)
#define  OBJIO_STEP_could_not_set_rev_description                        (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 44)
#define  OBJIO_STEP_owning_user_name_truncated                           (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 45)
#define  OBJIO_STEP_owning_user_not_available                            (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 46)
#define  OBJIO_STEP_file_exists                                          (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 47)
#define  OBJIO_STEP_os_file_error                                        (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 48)
#define  OBJIO_STEP_log_file_not_initialized                             (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 49)
#define  OBJIO_STEP_file_write_error                                     (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 50)
#define  OBJIO_STEP_invalid_schema                                       (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 51)
#define  OBJIO_STEP_invalid_product_type                                 (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 52)
#define  OBJIO_STEP_datasettype_does_not_exist                           (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 53)
#define  OBJIO_STEP_could_not_add_reviewers                              (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 54)
#define  OBJIO_STEP_could_not_set_decision                               (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 55)
#define  OBJIO_STEP_no_signoffs_for_the_object                           (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 56)
#define  OBJIO_STEP_valid_approver_not_found                             (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 57)
#define  OBJIO_STEP_start_message                                        (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 58)
#define  OBJIO_STEP_invalid_make_or_buy_value                            (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 59)
#define  OBJIO_STEP_owning_group_name_truncated                          (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 60)
#define  OBJIO_STEP_owning_group_not_available                           (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 61)
#define  OBJIO_STEP_step_realease_procedure_not_found                    (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 62)
#define  OBJIO_STEP_relation_not_found                                   (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 63)
/**
  The current user has insufficent privilege to perform this Import/Export operation.
*/
#define  OBJIO_STEP_insufficient_privilege                               (EMH_OBJIO_STEP_IMPORT_ERROR_BASE + 64)
/** @} */

/** @} */

#endif
