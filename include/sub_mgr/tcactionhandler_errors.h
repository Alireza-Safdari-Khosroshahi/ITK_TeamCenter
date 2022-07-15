/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Teamcenter action handler errors
*/

/*  */

#ifndef TCACTIONHANDLER_ERRORS_H
#define TCACTIONHANDLER_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup TCACTIONHANDLER_ERRORS Errors
    @ingroup TCACTIONHANDLER
    @{
*/

#define TCACTIONHANDLER_module_not_initialized        (EMH_HANDLER_error_base + 0)
#define TCACTIONHANDLER_internal_error                (EMH_HANDLER_error_base + 1)
#define TCACTIONHANDLER_invalid_handler               (EMH_HANDLER_error_base + 2)
#define TCACTIONHANDLER_invalid_handler_id            (EMH_HANDLER_error_base + 3)
#define TCACTIONHANDLER_invalid_handler_description   (EMH_HANDLER_error_base + 4)
#define TCACTIONHANDLER_invalid_function_name         (EMH_HANDLER_error_base + 5)
#define TCACTIONHANDLER_invalid_param_description     (EMH_HANDLER_error_base + 6)
#define TCACTIONHANDLER_does_not_exist                (EMH_HANDLER_error_base + 7)
#define TCACTIONHANDLER_already_exists                (EMH_HANDLER_error_base + 8)
#define TCACTIONHANDLER_cannot_delete_handler         (EMH_HANDLER_error_base + 9)
#define TCACTIONHANDLER_undefined_function            (EMH_HANDLER_error_base + 10)
#define TCACTIONHANDLER_unable_to_open_library        (EMH_HANDLER_error_base + 11)
#define TCACTIONHANDLER_unable_execute_handler        (EMH_HANDLER_error_base + 12)
#define TCACTIONHANDLER_user_insufficient_privilege   (EMH_HANDLER_error_base + 13)

/**
    The following error code is used to tell the action manager daemon that
    an error has occurred that cannot be corrected by retrying so it should
    not re-schedule a retry
*/
#define TCACTIONHANDLER_unretriable_error             (EMH_HANDLER_error_base + 14)

/** @} */

#endif
