/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the interface to idcontext errors.
*/

/*  */

#ifndef IDCXT_ERRORS_H
#define IDCXT_ERRORS_H

/**
    @defgroup IDCXT_ERRORS IDCXT Errors
    @ingroup IDCXT
    @{
*/

#define IDCONTEXT_invalid_tag                  (EMH_IDCONTEXT_error_base + 1)
#define IDCONTEXT_invalid_user                 (EMH_IDCONTEXT_error_base + 2)

/**
    @name IDCONTEXT Errors
    @{
*/
#define IDCONTEXT_unable_to_create             (EMH_IDCONTEXT_error_base + 3)
#define IDCONTEXT_invalid_type                 (EMH_IDCONTEXT_error_base + 4)
#define IDCONTEXT_null_name                    (EMH_IDCONTEXT_error_base + 5)
#define IDCONTEXT_duplicate_name               (EMH_IDCONTEXT_error_base + 6)
/** @} */

/**
    @name IDCONTEXT_rule errors
    @{
*/
#define IDCONTEXT_rule_null_idfr_type          (EMH_IDCONTEXT_error_base + 7)
#define IDCONTEXT_rule_null_idcontext          (EMH_IDCONTEXT_error_base + 8)
#define IDCONTEXT_rule_invalid_idcontext       (EMH_IDCONTEXT_error_base + 9)
#define IDCONTEXT_rule_invalid_idfbl_type      (EMH_IDCONTEXT_error_base + 10)
#define IDCONTEXT_rule_invalid_idfr_type       (EMH_IDCONTEXT_error_base + 11)
#define IDCONTEXT_rule_unable_to_create        (EMH_IDCONTEXT_error_base + 12)
#define IDCONTEXT_rule_duplicate_rule          (EMH_IDCONTEXT_error_base + 13)
/** @} */

/** @} */

#endif
