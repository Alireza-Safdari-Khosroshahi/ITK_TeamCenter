//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2011.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/**
    @file

    This file contains the error codes of Fnd0formulamgmt

*/

#ifndef FND0FORMULAMGMT_ERRORS_H
#define FND0FORMULAMGMT_ERRORS_H

#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif

#include <Fnd0formulamgmt/libfnd0formulamgmt_exports.h>
/**
    @defgroup FND0FORMULAMGMT_ERRORS FND0FORMULAMGMT Errors
    @ingroup FND0FORMULAMGMT
    @{
*/

#define FND0FORMULAMGMT_ERROR_BASE                              EMH_FND0FORMULAMGMT_error_base

/**
Invalid constant
*/
#define FND0FORMULAMGMT_invalid_constant                        (FND0FORMULAMGMT_ERROR_BASE + 1)

/**
Invalid variable
*/
#define FND0FORMULAMGMT_invalid_variable                        (FND0FORMULAMGMT_ERROR_BASE + 2)

/**
Missing definition for constant/variable
*/
#define FND0FORMULAMGMT_missing_constant_or_variable            (FND0FORMULAMGMT_ERROR_BASE + 3)

/**
The Expression is NULL.
*/
#define FND0FORMULAMGMT_expression_is_empty                     (FND0FORMULAMGMT_ERROR_BASE + 4)

/**
The Inverse Expression is NULL.
*/
#define FND0FORMULAMGMT_inverse_expression_is_empty             (FND0FORMULAMGMT_ERROR_BASE + 5)

/**
The lengths for the constnat names and values are different
*/
#define FND0FORMULAMGMT_constant_length_not_match               (FND0FORMULAMGMT_ERROR_BASE + 6)

/**
The lengths for the varialbe names and values are different
*/
#define FND0FORMULAMGMT_variable_length_not_match               (FND0FORMULAMGMT_ERROR_BASE + 7)

/**
Duplicate constant/variable
*/
#define FND0FORMULAMGMT_duplicate_constant_or_variable          (FND0FORMULAMGMT_ERROR_BASE + 8)

/**
The denominator for a rational expression cannot be zero.
*/
#define FND0FORMULAMGMT_denominator_is_zero                     (FND0FORMULAMGMT_ERROR_BASE + 9)

/** @} */

#include <Fnd0formulamgmt/libfnd0formulamgmt_undef.h>
#endif // FND0FORMULAMGMT_ERRORS_H
