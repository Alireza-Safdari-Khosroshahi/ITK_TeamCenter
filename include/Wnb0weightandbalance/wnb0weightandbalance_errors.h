/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2020.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Weight and Balance Management Error Codes Declaration

*/

#ifndef WNB0WEIGHTANDBALANCE_ERRORS_H
#define WNB0WEIGHTANDBALANCE_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup WNB0WEIGHTANDBALANCE_ERRORS Errors for the Weight And Balance Management solution
    @ingroup WNB0WEIGHTANDBALANCE
    @{
*/

#define WNB0WEIGHTANDBALANCE_error_base                                         EMH_WNB0WEIGHTANDBALANCE_error_base

/** The conversion factor from "%1$" to "%2$" was not found. Please contact the system administrator.*/
#define WNB0WEIGHTANDBALANCE_conversion_factor_not_found                        ( WNB0WEIGHTANDBALANCE_error_base + 1 )

/** The Mass Attribute Definition "%1$" was not found. Please contact the system administrator.*/
#define WNB0WEIGHTANDBALANCE_attribute_def_not_found                            ( WNB0WEIGHTANDBALANCE_error_base + 2 )

/** "%1$" was not saved because the "%2$" value is greater than the "%3$" value. **/
#define WNB0WEIGHTANDBALANCE_invalid_min_max_value                              ( WNB0WEIGHTANDBALANCE_error_base + 3 )

/** @} */

#endif
