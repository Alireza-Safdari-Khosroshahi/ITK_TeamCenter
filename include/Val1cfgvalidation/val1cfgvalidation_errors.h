/*Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2018.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/
/**
    @file

    Configurable Validation Error Codes Declaration

*/

#ifndef VAL1CFGVALIDATION_ERRORS_H
#define VAL1CFGVALIDATION_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup VAL1CFGVALIDATION_ERRORS NX Validation errors
    @ingroup VAL1CFGVALIDATION
    @{
*/


/** Base module errors */
#define VAL1CFGVALIDATION_ERROR_BASE                                   EMH_CONFIGURABLE_VALIDATION_error_base

/**
 * An internal error has occurred in the module Configurable Validation. Please report this error to your system administrator.
 */
#define VAL1CFGVALIDATION_internal_error                               (VAL1CFGVALIDATION_ERROR_BASE + 1)

/**
 * The Validation Result object could not be created. Please refer to the Teamcenter server syslog file for more information.
 */
#define VAL1CFGVALIDATION_create_result_obj_failed                     (VAL1CFGVALIDATION_ERROR_BASE + 2)



/**

    @}
*/

#endif
