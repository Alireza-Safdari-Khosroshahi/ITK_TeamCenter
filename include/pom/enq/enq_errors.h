/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This include file contains all the error codes which may be returned by ENQ
*/

/*  */

#ifndef ENQ_ERRORS_H
#define ENQ_ERRORS_H

/**
    @defgroup ENQ_ERRORS Errors
    @ingroup ENQ
    @{
*/

#define ENQ_ok                          0
#define ENQ_fail                        1
#define ENQ_UNKNOWN_TYPE               -1
#define ENQ_okToClearText               0
#define ENQ_doNotClearText              1

#include <pom/pom/pom_errors.h>

#define ENQ_ERROR_BASE                  ERROR_ENQ_base
#define ENQ_min_err_code                ENQ_ERROR_BASE

/**
    Cause:  Anything not covered by a more specific error code.
            May be caused by -
            <ul>
            <li>Error returned from another module called by ENQ.
            <li>Corrupt environment e.g. schema file and database out of sync.
            <li>Access violation when dereferencing an invalid pointer given
                as an argument to ENQ.
            <li>Programming error within ENQ.
            </ul>
    Action: Please report this error with journal file and trace files
            if available.
*/
#define ENQ_internal_error              ENQ_ERROR_BASE + 1

/**
    Cause:  The operation may work in a future version, but not yet.
            This may refer to an operation being available in a
            particular context.

    Action: Check for availability of feature in later release.
*/
#define ENQ_not_implemented             ENQ_ERROR_BASE + 2

/**
    Cause:  The ENQ has not been initialized.

    Action: The function ENQ_init_module must be called prior to any
            other ENQ activities.
*/
#define ENQ_not_initialised             ENQ_ERROR_BASE + 3

#define ENQ_invalid_attribute           ENQ_ERROR_BASE + 4

#define ENQ_invalid_class               ENQ_ERROR_BASE + 7

#define ENQ_invalid_query               ENQ_ERROR_BASE + 11

#define ENQ_invalid_set_expression      ENQ_ERROR_BASE + 12

#define ENQ_invalid_expression          ENQ_ERROR_BASE + 20

#define ENQ_invalid_value               ENQ_ERROR_BASE + 21

/**
    Cause:  The date passed is not a valid date.

    Action: Correct date.
*/
#define ENQ_invalid_date                ENQ_ERROR_BASE + 24

/**
    Cause:  POM out of memory caught in ENQ.

    Action: Check application is freeing used memory.
*/
#define ENQ_out_of_memory               (ENQ_ERROR_BASE + 27)

/**
    Cause:  POM timeout caught.

    Action: Retry operation, or setup automatic retries via POM.
*/
#define ENQ_timeout                     (ENQ_ERROR_BASE + 30)

/**
    Cause:  The alias is already used by an existing object.

    Action: Use different alias id.
*/
#define ENQ_invalid_pseudo_calias       (ENQ_ERROR_BASE + 33)

/**
    Cause:  The alias is already used by an existing object.

    Action: Use different alias id.
*/
#define ENQ_invalid_pseudo_attr         (ENQ_ERROR_BASE + 36)

#define ENQ_max_err_code                ENQ_ERROR_BASE + 37

/** @} */

#endif

