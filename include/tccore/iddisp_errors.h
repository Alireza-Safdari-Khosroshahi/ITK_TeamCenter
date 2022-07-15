/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the interface to iddisp errors.
*/

/*  */

#ifndef IDDISP_ERRORS_H
#define IDDISP_ERRORS_H

/**
    @defgroup IDDISP_ERRORS IDDISP Errors
    @ingroup IDDISP
    @{
*/

/**
    @name General Errors
    @{
*/
#define IDDISPRULE_duplicate_name                   (EMH_IDDISPRULE_error_base + 1)
#define IDDISPRULE_invalid_tag                      (EMH_IDDISPRULE_error_base + 2)
#define IDDISPRULE_null_id                          (EMH_IDDISPRULE_error_base + 3)
#define IDDISPRULE_null_name                        (EMH_IDDISPRULE_error_base + 4)
#define IDDISPRULE_type_not_found                   (EMH_IDDISPRULE_error_base + 5)
#define IDDISPRULE_unable_to_create                 (EMH_IDDISPRULE_error_base + 6)

#define IDDISPRULELIST_incorrect_initialization     (EMH_IDDISPRULE_error_base + 21)
#define IDDISPRULELIST_invalid_tag                  (EMH_IDDISPRULE_error_base + 22)
#define IDDISPRULELIST_invalid_type                 (EMH_IDDISPRULE_error_base + 23)
#define IDDISPRULELIST_is_currentrule               (EMH_IDDISPRULE_error_base + 24)
#define IDDISPRULELIST_null_owner                   (EMH_IDDISPRULE_error_base + 25)
#define IDDISPRULELIST_null_rules                   (EMH_IDDISPRULE_error_base + 26)
#define IDDISPRULELIST_unable_getcurrent            (EMH_IDDISPRULE_error_base + 27)
#define IDDISPRULELIST_unable_to_create             (EMH_IDDISPRULE_error_base + 28)
#define IDDISPRULELIST_unable_to_setrule            (EMH_IDDISPRULE_error_base + 29)
#define IDDISPRULELIST_notin_rulelist               (EMH_IDDISPRULE_error_base + 30)
#define IDDISPRULELIST_duplicate_list               (EMH_IDDISPRULE_error_base + 31)
#define IDDISPRULELIST_invalid_owner                (EMH_IDDISPRULE_error_base + 32)
/** @} */

/**
    @name IDDISPRULESPEC Errors
    @{
*/
#define IDDISPRULESPEC_invalid_tag                  (EMH_IDDISPRULE_error_base + 10)
#define IDDISPRULESPEC_invalid_type                 (EMH_IDDISPRULE_error_base + 12)
#define IDDISPRULESPEC_unable_to_create             (EMH_IDDISPRULE_error_base + 11)
/** @} */

/** @} */

#endif
