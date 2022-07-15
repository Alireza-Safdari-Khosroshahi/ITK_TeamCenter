/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Errors for the PublicationRecord Class
*/

/*  */

#ifndef IDSM_ERRORS_H
#define IDSM_ERRORS_H

#include <common/emh_const.h>
#include <publication/libpublication_exports.h>

/**
    @defgroup IDSM_ERRORS IDSM Errors
    @ingroup PUBR
    @{
*/

#define IDSM_no_connect                             (EMH_IDSM_error_base + 1)
#define IDSM_no_send                                (EMH_IDSM_error_base + 2)
#define IDSM_import_aborted                         (EMH_IDSM_error_base + 3)
#define IDSM_async_op_unsupported                   (EMH_IDSM_error_base + 4)
#define IDSM_async_op_in_progress                   (EMH_IDSM_error_base + 5)
#define IDSM_operation_out_of_sync                  (EMH_IDSM_error_base + 6)
#define IDSM_operation_complete                     (EMH_IDSM_error_base + 7)
#define IDSM_no_server_export_dir                   (EMH_IDSM_error_base + 8)
#define IDSM_no_such_site                           (EMH_IDSM_error_base + 9)
#define IDSM_object_is_local                        (EMH_IDSM_error_base + 10)
#define IDSM_client_access_denied                   (EMH_IDSM_error_base + 11)
#define IDSM_no_server_import_dir                   (EMH_IDSM_error_base + 12)
#define IDSM_expected_site_mismatch                 (EMH_IDSM_error_base + 13)
#define IDSM_export_with_xfer_no_import             (EMH_IDSM_error_base + 14)
#define IDSM_not_permitted_transfer_site            (EMH_IDSM_error_base + 15)
#define IDSM_function_unavailable                   (EMH_IDSM_error_base + 16)
#define IDSM_not_owning_site                        (EMH_IDSM_error_base + 17)
#define IDSM_unable_to_locate                       (EMH_IDSM_error_base + 18)
#define IDSM_ie_option_not_supported                (EMH_IDSM_error_base + 19)
#define IDSM_dataset_transfer_ownership_denied      (EMH_IDSM_error_base + 20)
#define IDSM_ft_socket_create_fail                  (EMH_IDSM_error_base + 21)
#define IDSM_ft_operation_in_progress               (EMH_IDSM_error_base + 22)
#define IDSM_ft_not_connected                       (EMH_IDSM_error_base + 23)
#define IDSM_ft_invalid_command                     (EMH_IDSM_error_base + 24)
#define IDSM_ft_state_error                         (EMH_IDSM_error_base + 25)
#define IDSM_ft_local_read_failed                   (EMH_IDSM_error_base + 26)
#define IDSM_ft_local_read_timeout                  (EMH_IDSM_error_base + 27)
#define IDSM_ft_local_write_failed                  (EMH_IDSM_error_base + 28)
#define IDSM_ft_local_write_timeout                 (EMH_IDSM_error_base + 29)
#define IDSM_ft_port_invalid_range                  (EMH_IDSM_error_base + 30)
#define IDSM_ft_accept_error                        (EMH_IDSM_error_base + 31)
#define IDSM_ft_accept_timeout                      (EMH_IDSM_error_base + 32)
#define IDSM_ft_connect_fail                        (EMH_IDSM_error_base + 33)
#define IDSM_ft_socket_set_buffer                   (EMH_IDSM_error_base + 34)
#define IDSM_ft_bind_failed                         (EMH_IDSM_error_base + 35)
#define IDSM_ft_incorrect_server_id                 (EMH_IDSM_error_base + 36)
#define IDSM_get_remote_stack_failed                (EMH_IDSM_error_base + 37)
#define IDSM_sync_option_not_supported              (EMH_IDSM_error_base + 38)
#define IDSM_no_modify_master_subscriptions         (EMH_IDSM_error_base + 39)
#define IDSM_proxy_client_access_denied             (EMH_IDSM_error_base + 40)
#define IDSM_not_permitted_user                     (EMH_IDSM_error_base + 41)
#define IDSM_not_permitted_transfer_user            (EMH_IDSM_error_base + 42)
#define IDSM_non_dsa_site                           (EMH_IDSM_error_base + 43)
#define IDSM_client_push_admin_data_access_denied   (EMH_IDSM_error_base + 44)
#define IDSM_restricted_archive_site                (EMH_IDSM_error_base + 45)
#define IDSM_restricted_restore_site                (EMH_IDSM_error_base + 46)
#define IDSM_not_permitted_checkout_site            (EMH_IDSM_error_base + 47)
#define IDSM_not_permitted_checkout_user            (EMH_IDSM_error_base + 48)
#define IDSM_not_original_sst_server                (EMH_IDSM_error_base + 49)
#define IDSM_no_global_export_context               (EMH_IDSM_error_base + 50)
#define IDSM_no_global_import_context               (EMH_IDSM_error_base + 51)
#define IDSM_sst_required                           (EMH_IDSM_error_base + 52)
#define IDSM_sst_not_supported                      (EMH_IDSM_error_base + 53)
#define IDSM_fms_error                              (EMH_IDSM_error_base + 54)
#define IDSM_not_permitted_interoperability         (EMH_IDSM_error_base + 55)
#define IDSM_sso_invalid_credentials                (EMH_IDSM_error_base + 56)
#define IDSM_internal_server_error                  (EMH_IDSM_error_base + 57)
#define IDSM_http_connect_failure                   (EMH_IDSM_error_base + 58)
#define IDSM_unable_to_get_info_for_hub_stub        (EMH_IDSM_error_base + 59)
#define IDSM_not_supported_tcxml_import             (EMH_IDSM_error_base + 60)

/**Multisite is not supported between "Production" and "Test" environments (namely sites "%1$" and "%2$" respectively).*/
#define IDSM_mix_env_multisite_not_supported        (EMH_IDSM_error_base + 61)

/** The SOA request for Proxy call to the site "%1$" on the host "%2$" has failed.*/
#define AIWS_no_connect                             (EMH_IDSM_error_base + 62)   

/** Target site does not support parallelization.*/
#define IDSM_not_supported_parallelization          (EMH_IDSM_error_base + 63)   


/** @} */

#include <publication/libpublication_undef.h>
#endif
