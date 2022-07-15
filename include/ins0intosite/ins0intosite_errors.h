/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2018.
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
*/

#ifndef INS0INTOSITE_ERRORS_H
#define INS0INTOSITE_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup INS0INTOSITE_ERRORS Teamcenter Intosite Errors
    @ingroup TCINTOSITE 
    @{
*/

/**
The utility "%1$" has failed because the parameter "%2$" is invalid or missing.
*/
#define TCINTOSITE_feature_failed_invalid_or_missing                   (EMH_TCIINTOSITE_error_base + 1)

/**
The utility "%1$" has found an invalid XML entry. See the utility log file for additional information.
*/
#define TCINTOSITE_utility_invalid_xml                                 (EMH_TCIINTOSITE_error_base + 2)

/**
The utility "%1$" has found an error. See the utility log file for additional information.
*/
#define TCINTOSITE_utility_found_error                                 (EMH_TCIINTOSITE_error_base + 3)

/** @} */
#endif
