/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    ITK wrappers for the TcActionHandler class methods
*/

/*  */

#ifndef TCACTIONHANDLER_H
#define TCACTIONHANDLER_H

#include <tc/tc_startup.h>
#include <common/emh_const.h>
#include <sub_mgr/tcactionhandler_errors.h>
#include <tc/tc_macros.h>
#include <sub_mgr/subscription.h>
#include <sub_mgr/libsub_mgr_exports.h>

/**
    @defgroup TCACTIONHANDLER Action Handler
    @ingroup SUBSCRIPTION
    @{
*/

#define MAX_TCACTIONHANDLER_ID_LEN        32
#define MAX_TCACTIONHANDLER_ATTR_STRLEN   240

#define USER_EXITS_LIB                      "user_exits"
#define EPM_LIB                             "epm"
#define SA_LIB                              "sa"

#define HANDLERS_INTERNAL_LIB              "sub_mgr"

/**
    Used in class TcActionHandler attr functionExecutionMode
*/
typedef enum HANDLER_exec_mode_e {
    HANDLER_execute_in_process,
    HANDLER_execute_in_separate_process
} HANDLER_exec_mode_t;

/**
    Used in class TcActionHandler attr functionType
*/
typedef enum HANDLER_function_type_e {
    HANDLER_is_library_function,
    HANDLER_is_standalone_executable
} HANDLER_function_type_t;

#ifdef __cplusplus
extern "C"{
#endif

extern SUB_MGR_API int TCACTIONHANDLER_execute_handler(
    tag_t              handler,
    void*              subscriptionActionMsg,
    int                nHandlerArgs,
    char**             handlerArgs,
    ...
    );

extern SUB_MGR_API int TCACTIONHANDLER_find_handler(
    const char*        handlerIdToFind,     /**< (I) */
    tag_t*             handler              /**< (O) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <sub_mgr/libsub_mgr_undef.h>

#endif
