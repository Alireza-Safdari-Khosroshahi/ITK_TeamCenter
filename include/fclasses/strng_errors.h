/* =================================================================================================
           Copyright (c) 1999-2005 Unigraphics Solutions Inc.
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
====================================================================================================*/

/**
    @file

    Errors for the STRNG module

*/

/*  */

#ifndef STRNG_ERRORS_H
#define STRNG_ERRORS_H

#include <common/emh_const.h>
#include <fclasses/libfclasses_exports.h>

/**
    @defgroup STRNG_ERRORS STRNG module errors
    @ingroup STRNG
    @{
*/

/** Specified value %1$ is not a double. */
#define STRNG_not_a_double                             (EMH_STRNG_error_base + 1)

/** Specified Value %1$ is not a date. */
#define STRNG_not_a_date                               (EMH_STRNG_error_base + 2)

/** Invalid date "%1$". Please use the following format: %2$. */
#define STRNG_use_date_format                          (EMH_STRNG_error_base + 3)

/** Specified value %1$ is not a character. */
#define STRNG_not_a_char                               (EMH_STRNG_error_base + 4)

/** Specified value %1$ is not a logical. */
#define STRNG_not_a_logical                            (EMH_STRNG_error_base + 5)

/** Specified value %1$ is not an integer. */
#define STRNG_not_an_integer                           (EMH_STRNG_error_base + 6)

/** Specified value %1$ is outside the valid range of integers. */
#define STRNG_integer_out_of_range                     (EMH_STRNG_error_base + 7)


/** @} */

#include <fclasses/libfclasses_undef.h>
#endif
