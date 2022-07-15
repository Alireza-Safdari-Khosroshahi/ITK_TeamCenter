/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Errors for Object Directory Services
*/

/*  */

#ifndef ODS_ERRORS_H
#define ODS_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup ODS_ERRORS Errors
    @ingroup ODS
    @{
*/

#define ODS_no_connect                         (EMH_ODS_error_base + 1)
#define ODS_no_send                            (EMH_ODS_error_base + 2)
#define ODS_no_such_site                       (EMH_ODS_error_base + 3)
#define ODS_client_access_denied               (EMH_ODS_error_base + 4)
#define ODS_no_default_site                    (EMH_ODS_error_base + 5)
#define ODS_expected_site_mismatch             (EMH_ODS_error_base + 6)
#define GS_remote_function_failed              (EMH_ODS_error_base + 7)
#define GS_no_user_license_available           (EMH_ODS_error_base + 8)
#define GS_no_ods_license_available            (EMH_ODS_error_base + 9)
#define ODS_function_unavailable               (EMH_ODS_error_base + 10)
#define ODS_proxy_client_access_denied         (EMH_ODS_error_base + 11)
#define ODS_unable_to_publish_to_hub_ods       (EMH_ODS_error_base + 12)
#define ODS_no_handshake_was_performed         (EMH_ODS_error_base + 13)
#define ODS_version_info_not_available         (EMH_ODS_error_base + 14)
#define ODS_invalid_client_custom_pubr_attr    (EMH_ODS_error_base + 15)
#define ODS_invalid_client_custom_pub_obj_attr (EMH_ODS_error_base + 16)

#define ODS_attr_not_supported                 (EMH_ODS_error_base + 20)
#define ODS_not_permitted_interoperability     (EMH_ODS_error_base + 21)

/** @} */
#endif
