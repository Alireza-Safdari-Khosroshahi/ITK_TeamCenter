/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    Defines error codes used in authorization module

*/


#ifndef AUTH_ERRORS_H
#define AUTH_ERRORS_H

#include <common/emh_const.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup AUTH_ERRORS Errors
    @ingroup AUTH
    @{
*/

#define AUTHORIZATION_ERROR_BASE         EMH_AUTHORIZATION_error_base

#define AUTH_initialize_failed           (AUTHORIZATION_ERROR_BASE + 1)
#define AUTH_set_name_failed             (AUTHORIZATION_ERROR_BASE + 2)
#define AUTH_set_ruledomain_failed       (AUTHORIZATION_ERROR_BASE + 3)
#define AUTH_init_accessorlist_failed    (AUTHORIZATION_ERROR_BASE + 4)
#define AUTH_invalid_name                (AUTHORIZATION_ERROR_BASE + 5)
#define AUTH_invalid_rule_domain         (AUTHORIZATION_ERROR_BASE + 6)
#define AUTH_class_not_initialized       (AUTHORIZATION_ERROR_BASE + 7)
#define AUTH_create_failed               (AUTHORIZATION_ERROR_BASE + 8)
#define AUTH_get_accessors_failed        (AUTHORIZATION_ERROR_BASE + 9)
#define AUTH_duplicate_rules             (AUTHORIZATION_ERROR_BASE + 10)
#define AUTH_rule_not_found              (AUTHORIZATION_ERROR_BASE + 11)
#define AUTH_cannot_delete_system_rule   (AUTHORIZATION_ERROR_BASE + 12)
#define AUTH_check_authorization_failed   (AUTHORIZATION_ERROR_BASE + 13)


/** @} */

#include <tccore/libtccore_undef.h>
#endif
