/*
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2018.
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
*/

/*
==============================================================================
File description:

    Filename: foundation_math.h
    Module  : base_utils

==============================================================================
   Date      Name                    Description of Change
08-Aug-2018  Balaram Dutta           Initial version
$HISTORY$
==================================================================================================
*/

#ifndef TEAMCENTER_BASE_UTILS_MATH_H
#define TEAMCENTER_BASE_UTILS_MATH_H

#include <unidefs.h>
#include <base_utils/libbase_utils_exports.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 *   Compares input double values.
 *   <br/>If the two numbers @p value1 and @p value2 are within DBL_EPSILON of each other, they are seen as being equal.
 *   DBL_EPSILON is the smallest value that could be added to 1.0 and change its value.
 */
    extern BASE_UTILS_API void MATH_compare_doubles(
        const double value1,                        /**< (I) first double value */
        const double value2,                        /**< (I) second double value */
        logical* are_equal                          /**< (O) @c true if both are equal
                                                             @c false otherwise. */
        );

/** @} */

#ifdef __cplusplus
}
#endif

#include <base_utils/libbase_utils_undef.h>
#endif
