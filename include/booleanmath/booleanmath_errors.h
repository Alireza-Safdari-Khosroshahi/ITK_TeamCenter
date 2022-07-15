/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2016.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This file describes the error codes for the foundation/booleanmath module.
*/

/*  */

#ifndef BOOLEANMATH_ERRORS_H
#define BOOLEANMATH_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup BOOLEANMATH_ERRORS BOOLEANMATH Errors
    @ingroup BOOLEANMATH
    @{
*/

/** An internal Boolean math error has occurred. */
#define BOOLEANMATH_internal_error                                      (EMH_BOOLEANMATH_error_base + 1)

/** The following Boolean math error has occurred: %1$. */
#define BOOLEANMATH_generic_error                                       (EMH_BOOLEANMATH_error_base + 2)

/** An invalid operation code was found: %1$. */
#define BOOLEANMATH_invalid_operation                                   (EMH_BOOLEANMATH_error_base + 3)

/** The operation has timed out. */
#define BOOLEANMATH_timed_out                                           (EMH_BOOLEANMATH_error_base + 4)

/** The operator "%1$" is not supported for the Option Family "%2$" of type "%3$". The following operators are supported: %4$. */
#define BOOLEANMATH_unsupported_operator                                (EMH_BOOLEANMATH_error_base + 5)

/** The operator "%1$" is not supported for the creation of the Boolean expression with variant option value: %2$. The following operators are supported: %3$. */
#define BOOLEANMATH_unsupported_operator_for_variant_option             (EMH_BOOLEANMATH_error_base + 6)

/** The operator "%1$" is not supported for joining left (%2$) and right (%3$) Boolean expressions. The following operators are supported: %4$. */
#define BOOLEANMATH_unsupported_operator_for_join_expressions           (EMH_BOOLEANMATH_error_base + 7)

/** The operation "%1$" is causing an arithmetic overflow. */
#define BOOLEANMATH_arithmetic_overflow                                 (EMH_BOOLEANMATH_error_base + 8)

/** The Boolean expression creation has failed because the variant option value cannot be null for the operator "%1$". */
#define BOOLEANMATH_unsupported_option_value_for_literal_expressions    (EMH_BOOLEANMATH_error_base + 9)

/** The Object "%1$" of type "Dynamic Family" cannot have value "%2$". Only 0 value is allowed as feature. */
#define BOOLEANMATH_unsupported_value_for_dynamic_family                (EMH_BOOLEANMATH_error_base + 10)

/** The Object "%1$" of type "Multi Select Family" cannot have empty value. Only non empty values are allowed as feature. */
#define BOOLEANMATH_unsupported_value_for_multi_select_family            (EMH_BOOLEANMATH_error_base + 11)

/** @} */

#endif
