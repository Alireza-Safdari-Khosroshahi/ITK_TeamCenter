/*Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2016.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/
/**
    @file

    NX Validation Error Codes Declaration

*/

#ifndef VAL0NXVALIDATION_ERRORS_H
#define VAL0NXVALIDATION_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup VAL0NXVALIDATION_ERRORS NX Validation errors
    @ingroup VAL0NXVALIDATION
    @{
*/


/** Base module errors */
#define VAL0NXVALIDATION_ERROR_BASE                                   EMH_NX_4GD_VALIDATION_error_base

/**
 * An internal error has occurred in the module Validation (Val0nxvalidation). Please report this error to your system administrator.
 */
#define VAL0NXVALIDATION_internal_error                               (VAL0NXVALIDATION_ERROR_BASE + 1)

/**
 * The Validation Result object could not be created. Please refer to the Teamcenter server syslog file for more information.
 */
#define VAL0NXVALIDATION_create_result_obj_failed                     (VAL0NXVALIDATION_ERROR_BASE + 2)

/*
 * The object type "%1$" is not supported for validation.
 * Only objects of type "Conditional Element" (Mdl0ConditionalElement) are supported for validation.
 */
#define VAL0NXVALIDATION_object_type_not_supported                    (VAL0NXVALIDATION_ERROR_BASE + 3)


/**

    @}
*/

#endif
