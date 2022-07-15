/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    USER EXIT specific Message definitions.

*/

/*  */

#ifndef BMF_USER_EXIT_MSG_H
#define BMF_USER_EXIT_MSG_H

#include <tccore/libtccore_exports.h>

/**
    @defgroup USER_EXIT_MSG Messages
    @ingroup USER_EXIT
    @{
*/

/**

*/


#define APPR_update_enditem_search_results_msg              "BMF_APPR_update_enditem_search_results"
#define USER_ITEM_create_msg                                "BMF_ITEM_create"
#define ITEMREVISION_create_msg                             "BMF_ITEMREVISION_create"
#define EC_get_base_revision_rules_msg                      "BMF_EC_get_base_revision_rules"
#define EC_define_never_used_relations_msg                  "BMF_EC_define_never_used_relations"
#define EC_get_problem_affected_assembly_relation_msg       "BMF_EC_get_problem_affected_assembly_relation"
#define EC_get_process_name_msg                             "BMF_EC_get_process_name"
#define TOOL_register_handler_msg                           "BMF_TOOL_register_handler"
#define ITEM_create_post_msg                                "BMF_ITEM_create_post"
#define TOOL_init_module_msg                                "BMF_TOOL_init_module"
#define SITE_string_compare_with_sort_msg                   "BMF_SITE_string_compare_with_sort"
#define IDFR_validate_alternate_msg                         "BMF_IDFR_validate_alternate"
#define USER_group_role_change_msg                          "BMF_USER_group_role_change"
#define PR_has_read_access_msg                              "BMF_PR_has_read_access"
#define QRY_search_client_program_msg                       "BMF_QRY_search_client_program"
#define QRY_search_keyword_msg                              "BMF_QRY_search_keyword"
#define QRY_execute_msg                                     "BMF_QRY_execute"
#define QRY_free_rows_msg                                   "BMF_QRY_free_rows"
#define QRY_map_row_msg                                     "BMF_QRY_map_row"
#define QRY_custom_execute_msg                              "BMF_QRY_custom_execute"
#define PSBVR_copy_eff_data_for_copy_msg                    "BMF_PSBVR_copy_eff_data_for_copy"
#define PSOCC_add_eff_objs_for_deletion_msg                 "BMF_PSOCC_add_eff_objs_for_deletion"
#define PSBVR_copy_eff_data_for_revise_msg                  "BMF_PSBVR_copy_eff_data_for_revise"
#define PSBVR_save_unsaved_eff_objects_msg                  "BMF_PSBVR_save_unsaved_eff_objects"
#define SFR_recover_files_msg                               "BMF_SFR_recover_files"
#define HSM_migrate_files_msg                               "BMF_HSM_migrate_files"
#define PSBVR_list_diffs_msg                                "BMF_PSBVR_list_diffs"
#define REPORT_print_bvr_diffs_msg                          "BMF_REPORT_print_bvr_diffs"
#define REPORT_mrp_print_bvr_diffs_msg                      "BMF_REPORT_mrp_print_bvr_diffs"
#define DATASET_copy_dataset_name_msg                       "BMF_DATASET_copy_dataset_name"
#define DATASET_copied_dataset_details_msg                  "BMF_DATASET_copied_dataset_details"
#define DATASET_new_id_msg                                  "BMF_DATASET_new_id"
#define DATASET_new_name_msg                                "BMF_DATASET_new_name"
#define ALLOC_new_name_msg                                  "BMF_ALLOC_new_name"
#define ALLOCATION_is_allocation_correct_msg                "BMF_ALLOCATION_is_correct"
#define ALLOCATION_is_allocation_complete_msg               "BMF_ALLOCATION_is_complete"
#define ALLOCATION_is_allocation_configured_msg             "BMF_ALLOCATION_is_configured"
#define DATASET_validate_name_msg                           "BMF_DATASET_validate_name"
#define DATASET_get_rev_msg                                 "BMF_DATASET_get_rev"
#define FOLDER_new_name_msg                                 "BMF_FOLDER_new_name"
#define FORM_new_name_msg                                   "BMF_FORM_new_name"
#define IDFR_new_id_msg                                     "BMF_IDFR_new_id_msg"
#define IDFR_validate_id_msg                                "BMF_IDFR_validate_id"
#define ITEM_check_above_erct_msg                           "BMF_ITEM_check_above_erct"
#define ITEM_ask_display_revisions_msg                      "BMF_ITEM_ask_display_revisions"
#define ITEM_assign_new_id_msg                              "BMF_ITEM_assign_new_id"
#define ITEMREVISION_assign_rev_id_msg                      "BMF_ITEMREVISION_assign_rev_id"
#define ITEMREVISION_assign_rev_id_from_altrule_msg         "BMF_ITEMREVISION_assign_rev_id_from_altrule"
#define ITEMREVISION_validate_id_msg                        "BMF_ITEMREVISION_validate_id"
#define PSBV_get_default_name_msg                           "BMF_PSBV_get_default_name"
#define PSBVR_get_default_name_msg                          "BMF_PSBVR_get_default_name"
#define PSO_ask_new_sequence_no_msg                         "BMF_PSO_ask_new_sequence_no"
#define PSO_ask_for_sequence_no_msg                         "BMF_PSO_ask_for_sequence_no"
#define PSO_ask_all_seq_no_msg                              "BMF_PSO_ask_all_seq_no"
#define ERP_get_custom_check_funcs_msg                      "BMF_ERP_get_custom_check_funcs"
#define ERP_get_custom_derive_funcs_msg                     "BMF_ERP_get_custom_derive_funcs"
#define FILE_new_name_msg                                   "BMF_FILE_new_name"
#define FILE_get_batch_meshing_nr_name_msg                  "BMF_FILE_get_batch_meshing_nr_name"
#define FS_check_system_code_for_conversion_msg             "BMF_FS_check_system_code_for_conversion"
#define FS_convert_code_cln_to_svr_msg                      "BMF_FS_convert_code_cln_to_svr"
#define FS_convert_code_svr_to_cln_msg                      "BMF_FS_convert_code_svr_to_cln"
#define PLMXML_register_actions_msg                         "BMF_PLMXML_register_actions"
#define PLMXML_filter_registrations_msg                     "BMF_PLMXML_filter_registrations"
#define PLMXML_register_schema_mappings_msg                 "BMF_PLMXML_register_schema_mappings"
#define TIEPLMXML_register_actions_msg                      "BMF_TIEPLMXML_register_actions"
#define TIEPLMXML_filter_registrations_msg                  "BMF_TIEPLMXML_filter_registrations"
#define SESSION_register_properties_msg                     "BMF_SESSION_register_properties"
#define REPORT_include_row_msg                              "BMF_REPORT_include_row"
#define REPORT_item_data_msg                                "BMF_REPORT_item_data"
#define REPORT_object_inquiry_data_msg                      "BMF_REPORT_object_inquiry_data"
#define REPORT_object_search_data_msg                       "BMF_REPORT_object_search_data"
#define REPORT_items_released_msg                           "BMF_REPORT_items_released"
#define REPORT_release_levels_for_group_msg                 "BMF_REPORT_release_levels_for_group"
#define REPORT_print_row_msg                                "BMF_REPORT_print_row"
#define REPORT_wso_data_msg                                 "BMF_REPORT_wso_data"
#define REPORT_employee_summary_msg                         "BMF_REPORT_employee_summary"
#define REPORT_item_admin_data_msg                          "BMF_REPORT_item_admin_data"
#define REPORT_import_export_data_msg                       "BMF_REPORT_import_export_data"
#define REPORT_item_summary_msg                             "BMF_REPORT_item_summary"
#define REPORT_item_summary_by_project_msg                  "BMF_REPORT_item_summary_by_project"
#define REPORT_items_by_dataset_msg                         "BMF_REPORT_items_by_dataset"
#define REPORT_storage_data_msg                             "BMF_REPORT_storage_data"
#define REPORT_items_not_released_msg                       "BMF_REPORT_items_not_released"
#define REPORT_get_group_access_levels_msg                  "BMF_REPORT_get_group_access_levels"
#define SESSION_add_canned_methods_msg                      "BMF_SESSION_add_canned_methods"
#define SESSION_archive_file_name_msg                       "BMF_SESSION_archive_file_name"
#define SESSION_archive_tape_name_msg                       "BMF_SESSION_archive_tape_name"
#define SESSION_build_notify_sub_msg                        "BMF_SESSION_build_notify_sub"
#define SESSION_preinit_registrations_msg                   "BMF_SESSION_preinit_registrations"
#define SESSION_user_exit_module_msg                        "BMF_SESSION_user_exit_module"
#define REPORT_register_report_columns_msg                  "BMF_REPORT_register_report_columns"
#define PLMXML_register_import_methods_msg                  "BMF_PLMXML_register_import_methods"
#define PLMXML_register_export_methods_msg                  "BMF_PLMXML_register_export_methods"
#define SESSION_register_functions_msg                      "BMF_SESSION_register_functions"
#define SESSION_register_epm_handlers_msg                   "BMF_SESSION_register_epm_handlers"
#define SESSION_register_aiws_extension_msg                 "BMF_SESSION_register_aiws_extension"
#define IMPORT_end_item_msg                                 "BMF_IMPORT_end_item"
#define PUBLISH_extra_attribute_msg                         "BMF_USER_ods_client_publish_extra_attributes"
#define ASK_extra_attribute_msg                             "BMF_USER_ods_client_ask_extra_attributes"
#define IMPORT_local_msg                                    "BMF_IMPORT_local"
#define SITE_archive_export_directory_msg                   "BMF_SITE_archive_export_directory"
#define SITE_check_txn_remote_site_msg                      "BMF_SITE_check_txn_remote_site"
#define SITE_publish_object_msg                             "BMF_SITE_publish_object"
#define BOM_compare_modes_msg                               "BMF_BOM_compare_modes"
#define APPR_update_mapped_attr_data_msg                    "BMF_APPR_update_mapped_attr_data"
#define ITEMREVISION_baseline_sync_msg                      "BMF_ITEMREVISION_baseline_sync"
#define ITEMREVISION_dryrun_msg                             "BMF_ITEMREVISION_dryrun"
#define VARESULT_eval_compound_result_msg                   "BMF_VARESULT_eval_compound_result"
#define REPORT_bom_cmp_start_msg                            "BMF_REPORT_bom_cmp_start"
#define REPORT_bom_cmp_end_msg                              "BMF_REPORT_bom_cmp_end"
#define BOMLINE_is_preferred_ancester_msg                   "BMF_BOMLINE_is_preferred_ancester"
#define SESSION_invoke_pdm_server_msg                       "BMF_SESSION_invoke_pdm_server"
#define SESSION_invoke_user_code_string_msg                 "BMF_SESSION_invoke_user_code_string"
#define SESSION_invoke_user_code_taglist_msg                "BMF_SESSION_invoke_user_code_taglist"
#define SESSION_invoke_user_create_objs_msg                 "BMF_SESSION_invoke_user_create_objs"

#define ITEMREVISION_ask_is_mature                          "BMF_ITEMREVISION_ask_is_mature"
#define PARTREVISION_make_primary_representation            "BMF_PARTREVISION_make_primary_representation"
#define SEARCHCURSOR_process_search_results_msg             "BMF_SEARCHCURSOR_process_search_results"
#define BMF_ICS_exec_custom_attribute_logic_msg             "BMF_ICS_exec_custom_attribute_logic"
#define DATASET_is_exportable_msg                           "BMF_USER_is_dataset_exportable"
#define BMF_BOMLINE_compute_net_effectivity                 "BMF_BOMLINE_compute_net_effectivity"
#define BMF_validate_id_msg                                 "BMF_validate_id"
#define BMF_where_used                                      "BMF_where_used"
#define BMF_USER_new_item_ids_msg                           "BMF_USER_new_item_ids"
#define BMF_USER_new_item_ids_for_saveas_msg                "BMF_USER_new_item_ids_for_saveas_msg"
#define BMF_USER_new_item_ids_for_saveas2_msg               "BMF_USER_new_item_ids_for_saveas2_msg"

/**
 * This User Exit API returns a list of process templates based on given criteria.
 * based on current User Group and TargetObjects/ Object Types.
 *
 * Underconstruction Templates are part of result only for users who are part of
 * DBA Group when include_under_construction = true.
 *
 * The Group and object type based template filter is used as a legacy template Filter from Teamcenter 11.2.
 *<br/>A new condition based filter is introduced in Teamcenter 11.2.
 *<br/>The new assigned template filter works on the target object input and filter condition associated with the respective template.
 *<br/>The preference WRKFLW_use_legacy_template_filter decides which template filter to use.
 *
 *  logical      include_under_construction,     < (I) Show Under Construction Templates
 *   logical      assigned_templates,             < (I) Show Assigned Templates
 *   int          number_of_objects,              < (I) Number of object types or target objects
 *   tag_t*       target_objects,                 < (I) Target objects
 *   char**       object_types,                   < (I) Object types
 *   const char*  group,                          < (I) Group
 *   int*         count,                          < (O) Output count
 *   tag_t**      process_templates               < (OF) Count output Templates
*/
#define BMF_EPMTaskTemplate_get_filtered_templates_msg      "BMF_EPMTaskTemplate_get_filtered_templates"

#define WSOM_assign_new_rev_id_msg                          "BMF_WSOM_assign_new_rev_id"
#define WSOM_new_thread_id_msg                              "BMF_WSOM_new_thread_id"

/** @} */

#include <tccore/libtccore_undef.h>
#endif
