/* Copyright 2017 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2017 Siemens Product Lifecycle Management Software Inc. All Rights Reserved. */

/** 
    @file

    Error codes for libtcwebdav.dll
*/

#ifndef TCWEBDAV_ERRORS_H
#define TCWEBDAV_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup TCWEBDAV_ERRORS Errors
    @ingroup  TCWEBDAV
    @{
*/

#define TCWEBDAV_ERROR_BASE                                 EMH_TCWEBDAV_error_base

#define TCWEBDAV_dataset_type_not_found                   ( TCWEBDAV_ERROR_BASE + 1 )
#define TCWEBDAV_dataset_already_exists                   ( TCWEBDAV_ERROR_BASE + 2 )
#define TCWEBDAV_folder_already_exists                    ( TCWEBDAV_ERROR_BASE + 3 )
#define TCWEBDAV_form_already_exists                      ( TCWEBDAV_ERROR_BASE + 4 )
#define TCWEBDAV_invalid_item_id                          ( TCWEBDAV_ERROR_BASE + 5 )
#define TCWEBDAV_lock_is_required                         ( TCWEBDAV_ERROR_BASE + 6 )
#define TCWEBDAV_locked_resource_not_found                ( TCWEBDAV_ERROR_BASE + 7 )
#define TCWEBDAV_locked_by_other_user                     ( TCWEBDAV_ERROR_BASE + 8 )
#define TCWEBDAV_not_newly_created_file                   ( TCWEBDAV_ERROR_BASE + 9 )
#define TCWEBDAV_resource_not_checked_out                 ( TCWEBDAV_ERROR_BASE + 10 )
#define TCWEBDAV_resource_already_checked_out             ( TCWEBDAV_ERROR_BASE + 11 )
#define TCWEBDAV_unexpected_time_stamp                    ( TCWEBDAV_ERROR_BASE + 12 )
#define TCWEBDAV_implicit_checkout_failed                 ( TCWEBDAV_ERROR_BASE + 13 )
#define TCWEBDAV_implicit_checkout_not_allowed            ( TCWEBDAV_ERROR_BASE + 14 )
#define TCWEBDAV_invalid_item_rev_id                      ( TCWEBDAV_ERROR_BASE + 15 )

/** @} */
#endif

