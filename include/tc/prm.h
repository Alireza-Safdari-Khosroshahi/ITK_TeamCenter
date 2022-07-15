/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Include file for ITK Process Management routines
*/

/*  */

#ifndef PRM_H
#define PRM_H

#include <ss/ss_types.h>

/**
    @defgroup PRM Process Management
    @ingroup EPM
    @{
*/

typedef void* (*PM_HandlerFp)(void*);

#include <tc/libtc_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Starts the process for a specified symbol with input as arguments to the symbol.
    The handler is a pointer to a function, with handler_args as arguments,
    to be called once the process is finished executing. 
    The pid is the process ID of the process.
*/
extern TC_API int PM_start_process (
    const char*     symbol,         /**< (I) */
    void**          input,          /**< (I) */
    PM_HandlerFp    handler,        /**< (I) */
    void*           handler_args,   /**< (I) */
    SS_pid*         pid             /**< (I) */
    );

/**
    Gets the first argument from the argument list.
*/
extern TC_API void* PM_get_args(
    void**            args      /**< (O) */
    );

/**
    Puts the args at the end of the argument list.
*/
extern TC_API int PM_put_args(
    void*           value,      /**< (I) */
    int             size,       /**< (I) */
    void**          args        /**< (I) */
    );

/**
    Returns a pointer to an argument in the argument list at a specified position. 
*/
extern TC_API void* PM_view_args(
    int               pos,      /**< (I) */
    void*             args      /**< (I) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tc/libtc_undef.h>

#endif

