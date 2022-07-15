/**
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

    Defines error codes used within the nls module.
*/

#ifndef NLS_ERRORS_H
#define NLS_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup NLS_ERRORS National Language Support Errors
    @ingroup NLS
    @{
*/

#define NLS_ERROR_BASE                                                   EMH_NLS_error_base

/**
    Some of the characters in the UTF-8 encoded string cannot be converted to the platform encoded format. These characters are replaced with the '#' character in the resulting string. 
*/
#define NLS_utf8_to_system_results_data_loss                             ( NLS_ERROR_BASE + 1 )

/**
    The original UTF-8 encoded string is being returned because an error has occurred when converting the UTF-8 encoded string to the platform encoding. Please check the server syslog file for more information.
*/
#define NLS_utf8_to_system_conversion_exception                          ( NLS_ERROR_BASE + 2 )

/**
    The original platform encoded string is being returned because an error has occurred when converting the platform encoded string to the UTF-8 encoding. Please check the server syslog file for more information.
*/
#define NLS_system_to_utf8_conversion_fail                               ( NLS_ERROR_BASE + 3 )

/** @} */

#endif
