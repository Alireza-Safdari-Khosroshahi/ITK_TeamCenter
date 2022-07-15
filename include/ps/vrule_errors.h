/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Error codes returned by the Variant Rule ITK module.
*/

/*  */

#ifndef VRULE_ERRORS_H
#define VRULE_ERRORS_H

#include <common/emh_const.h>
#include <ps/libps_exports.h>

/**
    @defgroup VRULE_ERRORS Errors
    @ingroup VRULE
    @{
*/

#define VRULE_invalid_rule         (EMH_VRULE_error_base +   0)
#define VRULE_no_rule              (EMH_VRULE_error_base +   1)
#define VRULE_unable_to_create     (EMH_VRULE_error_base +   2)
#define VRULE_empty_rule           (EMH_VRULE_error_base +   3)
#define VRULE_deleted_rule         (EMH_VRULE_error_base +   4)
#define VRULE_invalid_operator     (EMH_VRULE_error_base +   5)
#define VRULE_invalid_value        (EMH_VRULE_error_base +   6)
#define VRULE_invalid_bom_window   (EMH_VRULE_error_base +   7)
#define VRULE_invalid_current_rule (EMH_VRULE_error_base +   8)
#define VRULE_rule_no_longer_valid (EMH_VRULE_error_base +   8)

/** @} */

#include <ps/libps_undef.h>
#endif

