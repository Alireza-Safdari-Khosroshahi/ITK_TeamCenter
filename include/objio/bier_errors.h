/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Define error codes used with BIER
*/

/*  */

#ifndef BIER_ERRORS_H
#define BIER_ERRORS_H

#include <common/emh_const.h>
#include <objio/libobjio_exports.h>

/**
    @defgroup BIER_ERRORS Backup Import Export Recovery Errors
    @ingroup OBJIO
    @{
*/

#define BIER_ERROR_BASE                                         EMH_BIER_error_base

/** Instance to recover was not stored in this file */
#define BIER_instance_not_in_file                               (BIER_ERROR_BASE + 1)

/** Encountered a problem extracting an instance from the file */
#define BIER_failed_to_extract_instance                         (BIER_ERROR_BASE + 2)

/** Instances of this class are not exportable/importable (archivable?) */
#define BIER_class_not_storable                                 (BIER_ERROR_BASE + 3)

/** Perhaps somebody removed the site half-way through the export operation? */
#define BIER_site_lookup_failed                                 (BIER_ERROR_BASE + 4)

/** Perhaps somebody removed the site half-way through the export operation? */
#define BIER_site_not_pom_object                                (BIER_ERROR_BASE + 5)

/** Perhaps somebody removed the site half-way through the export operation? */
#define BIER_set_site_failed                                    (BIER_ERROR_BASE + 6)

#define BIER_exclude_failed                                     (BIER_ERROR_BASE + 7)

#define BIER_store_failed                                       (BIER_ERROR_BASE + 8)

#define BIER_write_failed                                       (BIER_ERROR_BASE + 9)

/**
    @name More "cannot export" type errors
    @{
*/
#define BIER_cannot_transfer_released                           (BIER_ERROR_BASE + 10)
#define BIER_cannot_transfer_checked_out                        (BIER_ERROR_BASE + 11)
/** @} */

#define BIER_cannot_import_with_missing_ref                     (BIER_ERROR_BASE + 12)
#define BIER_missing_ref_description                            (BIER_ERROR_BASE + 13)

#define BIER_missing_item                                       (BIER_ERROR_BASE + 14)

#define BIER_set_export_ds_failed                               (BIER_ERROR_BASE + 15)

#define BIER_local_site                                         (BIER_ERROR_BASE + 16)
#define BIER_invalid_site                                       (BIER_ERROR_BASE + 17)
#define BIER_no_target_site                                     (BIER_ERROR_BASE + 18)
#define BIER_cannot_xfer_to_multiple_sites                      (BIER_ERROR_BASE + 19)
#define BIER_cannot_xfer_to_local_site                          (BIER_ERROR_BASE + 20)
#define BIER_cannot_export_imported_object                      (BIER_ERROR_BASE + 21)

#define BIER_fail_to_export                                     (BIER_ERROR_BASE + 22)
#define BIER_out_of_memory                                      (BIER_ERROR_BASE + 23)
#define BIER_unable_to_locate                                   (BIER_ERROR_BASE + 24)

#define BIER_invalid_for_remote_bier_type                       (BIER_ERROR_BASE + 25)
#define BIER_invalid_for_local_bier_type                        (BIER_ERROR_BASE + 26)
#define BIER_no_target_sites_when_xferring                      (BIER_ERROR_BASE + 27)
#define BIER_unable_to_exclude                                  (BIER_ERROR_BASE + 28)
#define BIER_cannot_transfer_archived                           (BIER_ERROR_BASE + 29)
#define BIER_cannot_export_modifiable                           (BIER_ERROR_BASE + 30)
#define BIER_no_export_priv                                     (BIER_ERROR_BASE + 31)
#define BIER_require_import_site_priv                           (BIER_ERROR_BASE + 32)
#define BIER_cannot_transfer_in_process                         (BIER_ERROR_BASE + 33)
#define BIER_invalid_recover_mode                               (BIER_ERROR_BASE + 34)
#define BIER_exported_object_missing                            (BIER_ERROR_BASE + 35)
#define BIER_unable_to_include_rel                              (BIER_ERROR_BASE + 36)
#define BIER_unable_to_include_sec_obj                          (BIER_ERROR_BASE + 37)
#define BIER_no_transfer_out_priv                               (BIER_ERROR_BASE + 38)
#define BIER_conflicting_transfer_options                       (BIER_ERROR_BASE + 39)
#define BIER_conflicting_ie_options                             (BIER_ERROR_BASE + 40)
#define BIER_invalid_option_when_xferring                       (BIER_ERROR_BASE + 41)
#define BIER_invalid_option_when_not_xferring                   (BIER_ERROR_BASE + 42)
#define BIER_nothing_modified_to_export                         (BIER_ERROR_BASE + 43)
#define BIER_valid_for_assy_export_only                         (BIER_ERROR_BASE + 44)
#define BIER_require_transfer_in_site_priv                      (BIER_ERROR_BASE + 45)
#define BIER_no_exportable_revs                                 (BIER_ERROR_BASE + 46)
#define BIER_valid_with_all_revs_only                           (BIER_ERROR_BASE + 47)
#define BIER_no_revision_export_selector                        (BIER_ERROR_BASE + 48)
#define BIER_no_working_revision_to_export                      (BIER_ERROR_BASE + 49)
#define BIER_no_released_revision_to_export                     (BIER_ERROR_BASE + 50)
#define BIER_no_revision_selected_for_export                    (BIER_ERROR_BASE + 51)
#define BIER_unable_to_export_unpublished                       (BIER_ERROR_BASE + 52)
#define BIER_user_denied_remote_import_privilege_for_site       (BIER_ERROR_BASE + 53)
#define BIER_user_denied_transfer_ownership_privilege_for_site  (BIER_ERROR_BASE + 54)
#define BIER_cannot_import_preview_metafile                     (BIER_ERROR_BASE + 55)
#define BIER_preview_metafile_is_empty                          (BIER_ERROR_BASE + 56)
#define BIER_importing_local_object                             (BIER_ERROR_BASE + 57)
#define BIER_no_revision_of_given_status                        (BIER_ERROR_BASE + 58)
#define BIER_lastexp_valid_for_item_only                        (BIER_ERROR_BASE + 59)
#define BIER_no_post_export_script                              (BIER_ERROR_BASE + 60)
#define BIER_no_pre_import_script                               (BIER_ERROR_BASE + 61)
#define BIER_unable_to_execute_export_script                    (BIER_ERROR_BASE + 62)
#define BIER_unable_to_execute_import_script                    (BIER_ERROR_BASE + 63)
#define BIER_cannot_transfer_replica_from_hub                   (BIER_ERROR_BASE + 64)
#define BIER_nothing_to_export                                  (BIER_ERROR_BASE + 65)
#define BIER_type_does_not_exist                                (BIER_ERROR_BASE + 66)
#define BIER_tool_does_not_exist                                (BIER_ERROR_BASE + 67)
#define BIER_form_storage_class_does_not_exist                  (BIER_ERROR_BASE + 68)
#define BIER_class_not_directly_exportable                      (BIER_ERROR_BASE + 69)
#define BIER_class_not_directly_transferable                    (BIER_ERROR_BASE + 70)
#define BIER_remotely_checked_out_object_already_exported       (BIER_ERROR_BASE + 71)
#define BIER_check_out_site_not_found                           (BIER_ERROR_BASE + 72)
#define BIER_object_not_checked_out_by_site                     (BIER_ERROR_BASE + 73)
#define BIER_invalid_recover_mode_for_export_dir                (BIER_ERROR_BASE + 74)
#define BIER_invalid_read_tickets_file                          (BIER_ERROR_BASE + 75)
#define BIER_bulk_data_file_not_transfered                      (BIER_ERROR_BASE + 76)
#define BIER_no_fms_bootstrap_urls                              (BIER_ERROR_BASE + 77)
#define BIER_fsc_proxy_error                                    (BIER_ERROR_BASE + 78)
#define BIER_user_not_defined_at_remote_site                    (BIER_ERROR_BASE + 79)
#define BIER_group_not_defined_at_remote_site                   (BIER_ERROR_BASE + 80)
#define BIER_user_and_group_not_defined_at_remote_site          (BIER_ERROR_BASE + 81)
#define BIER_user_not_member_of_group_at_remote_site            (BIER_ERROR_BASE + 82)
#define BIER_unable_to_remote_export                            (BIER_ERROR_BASE + 83)
#define BIER_unable_to_remote_checkout                          (BIER_ERROR_BASE + 84)
#define BIER_user_has_no_privilege_on_object                    (BIER_ERROR_BASE + 85)
#define BIER_site_has_no_privilege_on_object                    (BIER_ERROR_BASE + 86)
#define BIER_cannot_remote_co_replica                           (BIER_ERROR_BASE + 87)
#define BIER_cannot_transfer_ownership_of_replica               (BIER_ERROR_BASE + 88)
#define BIER_user_not_defined_in_site_pref                      (BIER_ERROR_BASE + 89)
#define BIER_site_not_defined_in_site_pref                      (BIER_ERROR_BASE + 90)
#define BIER_user_no_import_priv_at_importing_site              (BIER_ERROR_BASE + 91)
#define BIER_user_no_transfer_in_priv_at_importing_site         (BIER_ERROR_BASE + 92)
#define BIER_site_no_import_priv_at_importing_site              (BIER_ERROR_BASE + 93)
#define BIER_site_no_transfer_in_priv_at_importing_site         (BIER_ERROR_BASE + 94)
#define BIER_user_no_import_priv                                (BIER_ERROR_BASE + 95)
#define BIER_user_no_transfer_in_priv                           (BIER_ERROR_BASE + 96)
#define BIER_no_configured_rev_for_rev_rule                     (BIER_ERROR_BASE + 97)
#define BIER_site_does_not_support_longer_id                    (BIER_ERROR_BASE + 98)
#define BIER_secondary_send_remote_checkin_failed               (BIER_ERROR_BASE + 99)
#define BIER_unknown_sst_state                                  (BIER_ERROR_BASE + 100)
#define BIER_ambiguous_sst                                      (BIER_ERROR_BASE + 101)
#define BIER_sst_recovery_required                              (BIER_ERROR_BASE + 102)
#define BIER_sst_in_progress                                    (BIER_ERROR_BASE + 103)
#define BIER_sst_cleanup_failed                                 (BIER_ERROR_BASE + 104)
#define BIER_unable_to_delete_staging_dir                       (BIER_ERROR_BASE + 105)
#define BIER_sst_recovery_replica_required                      (BIER_ERROR_BASE + 106)
#define BIER_sst_prev_recovery_required                         (BIER_ERROR_BASE + 107)
#define BIER_simulated_internal_error                           (BIER_ERROR_BASE + 108)
#define BIER_chkpt_transaction_in_progress                      (BIER_ERROR_BASE + 109)
#define BIER_sst_client_determined_alive                        (BIER_ERROR_BASE + 110)
#define BIER_sst_client_determined_dead                         (BIER_ERROR_BASE + 111)
#define BIER_sst_client_undetermined                            (BIER_ERROR_BASE + 112)
#define BIER_sst_server_determined_alive                        (BIER_ERROR_BASE + 113)
#define BIER_sst_server_undetermined                            (BIER_ERROR_BASE + 114)
#define BIER_sst_server_determined_alive_is_ours                (BIER_ERROR_BASE + 115)
#define BIER_sst_session_in_use                                 (BIER_ERROR_BASE + 116)
#define BIER_l10n_cannot_get_locale_pref_val                    (BIER_ERROR_BASE + 117)
#define BIER_l10n_locale_not_available                          (BIER_ERROR_BASE + 118)
#define BIER_l10n_cannot_set_localized_attribute                (BIER_ERROR_BASE + 119)
#define BIER_LOV_export_failed                                  (BIER_ERROR_BASE + 120)
#define BIER_LOV_import_failed                                  (BIER_ERROR_BASE + 121)
#define BIER_dataset_export_declined_by_custom_code             (BIER_ERROR_BASE + 122)

#define BIER_site_mismatch_exclude_files                        (BIER_ERROR_BASE + 131)

/** 010454- Controlled Replication Project */
#define BIER_CntrlRep_assembly_invalid_for_replication          (BIER_ERROR_BASE + 132)
#define BIER_CntrlRep_no_revision_rule_provided                 (BIER_ERROR_BASE + 133)
#define BIER_CntrlRep_no_replication_sites                      (BIER_ERROR_BASE + 134)

#define BIER_invalid_revisions_when_xferring                    (BIER_ERROR_BASE + 135)

/** 010454- Controlled Replication Project */
#define BIER_CntrlRep_not_precise                               (BIER_ERROR_BASE + 136)
#define BIER_CntrlRep_not_released                              (BIER_ERROR_BASE + 137)
#define BIER_CntrlRep_stubbed                                   (BIER_ERROR_BASE + 138)

/** Global Organization Project */
#define BIER_verify_object_at_target_fail                       (BIER_ERROR_BASE + 139)

/** Some kind of inconsistency has been detected.  This is probably a coding error we
    would like reported, and there is no sensible recovery available */
#define BIER_internal_error                                     (BIER_ERROR_BASE + 140)

/** Importing failure. An unknown Class/Type encountered during import */
#define BIER_unknown_object                                     (BIER_ERROR_BASE + 141)

/** Importing failure. An unknown Class/Type encountered during import */
#define BIER_invalid_class_of_object_in_transaction             (BIER_ERROR_BASE + 142)

/** @} */

#include <objio/libobjio_undef.h>
#endif

