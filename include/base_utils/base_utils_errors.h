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

    Defines error codes used within the base_utils module.
*/

#ifndef BASE_UTILS_ERRORS_H
#define BASE_UTILS_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup BASE_UTILS_ERRORS Errors
    @ingroup BASE_UTILS
    @{
*/

#define BASE_UTILS_ERROR_BASE               EMH_BASE_UTILS_error_base

/**
    An unexpected error has occurred in the Foundation module. Please report this error to the system administrator.
*/
#define BASE_UTILS_internal_error           (BASE_UTILS_ERROR_BASE + 1)

/**
    A method of the Foundation module was called with improper parameters. Please check the server syslog file for more information.
*/
#define BASE_UTILS_invalid_parameter        (BASE_UTILS_ERROR_BASE + 2)

/**
    The requested memory cannot be allocated.
*/
#define BASE_UTILS_no_memory                (BASE_UTILS_ERROR_BASE + 3)

/**
    An invalid reference is being passed.
*/
#define BASE_UTILS_invalid_reference        (BASE_UTILS_ERROR_BASE + 4)

/**
    The object "%1$" has already been initialized.
*/
#define BASE_UTILS_already_initialized      (BASE_UTILS_ERROR_BASE + 5)

/**
    The expected data is missing in the object "%1$".
*/
#define BASE_UTILS_expected_data_missing    (BASE_UTILS_ERROR_BASE + 6)

/**
    An invalid UID is being passed.
    UID is NULL pointer -or-
    UID contains invalid characters -or- 
    UID length is not 14 or 27 ASCII characters
*/
#define BASE_UTILS_invalid_uid             (BASE_UTILS_ERROR_BASE + 7)

/**    
    The generated city hash UID is invalid.
*/
#define BASE_UTILS_invalid_city_hash_uid   (BASE_UTILS_ERROR_BASE + 8)

/** @} */

#endif
