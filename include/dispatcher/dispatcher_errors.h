/*
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2008.
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
*/
/**
    @file

    This file contains the definitions for the error
    codes for this application...
*/
#ifndef DISPATCHER_ERRORS_H
#define DISPATCHER_ERRORS_H

#include <tc/tc_errors.h>

#include <common/emh_const.h>

#define DISPATCHER_ok         0


/**
   @defgroup DISPATCHER_ERRORS Errors for Dispatcher functionality
   @ingroup DISPATCHER
   @{
*/
/**
    Dispatcher Programming Error: Bad Parameter
*/
#define DISPATCHER_ERROR_bad_parameter                           (EMH_DISPATCHER_error_base +    1)

/**
    Attempt to allocate memory failed.
*/
#define DISPATCHER_ERROR_out_of_memory                           (EMH_DISPATCHER_error_base +    2)

/**
    Unable to create instance of Dispatcher Request
*/
#define DISPATCHER_ERROR_create_instance_failed                  (EMH_DISPATCHER_error_base +    3)

/**
    Unable to create file.
*/
#define DISPATCHER_ERROR_unable_to_create_imanfile               (EMH_DISPATCHER_error_base +    4)

/**
    No file was found for specified key.
*/
#define DISPATCHER_ERROR_no_file_found_for_key                   (EMH_DISPATCHER_error_base +    5)

/**
    The tag specified is an invalid tag.
*/
#define DISPATCHER_ERROR_invalid_request_tag                     (EMH_DISPATCHER_error_base +    6)

/**
    Key already exists.
*/
#define DISPATCHER_ERROR_key_already_exist                       (EMH_DISPATCHER_error_base +    7)

/**
    Dispatcher Programming Error: Bad Parameter
*/
#define DISPATCHER_ERROR_state_unmatched                         (EMH_DISPATCHER_error_base +    8)

/** @} */
#endif
