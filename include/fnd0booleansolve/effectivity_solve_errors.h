/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2017.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This header file contains error codes for the effectivity configuration module.
*/

#ifndef EFFECTIVITY_SOLVE_ERRORS_H
#define EFFECTIVITY_SOLVE_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup EFFECTIVITY_SOLVE_ERRORS Effectivity solve Errors
    @ingroup BOOLEANSOLVE
    @{
*/

#define EFFSOLVE_error_base                                     EMH_EFFSOLVE_error_base

/**
 * An Effectivity configuration internal error has occurred. Please contact your system administrator.
 */
#define EFFSOLVE_internal_error                                 (EFFSOLVE_error_base + 0)

/**
 * The object "%1$" of type "%2$" is not an effectivity configurable object.
 */
#define EFFSOLVE_object_is_not_effectivity_configurable         (EFFSOLVE_error_base + 1)

/**
 * The effectivity context object "%1$" of type "%2$" is invalid.
 */
#define EFFSOLVE_context_is_invalid                             (EFFSOLVE_error_base + 2)

/**
 * A Revision Rule must be provided for the effectivity context object "%1$" of type "%2$".
 */
#define EFFSOLVE_revision_rule_not_provided_for_item_context    (EFFSOLVE_error_base + 3)

/**
 * The Revision Rule "%3$" is unable to configure a valid Item Revision for the effectivity context object "%1$" of type "%2$". 
 */
#define EFFSOLVE_unable_to_configure_itemrev_for_item_context   (EFFSOLVE_error_base + 4)

/** @} */

#endif
