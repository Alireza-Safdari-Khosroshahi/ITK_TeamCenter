/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This module contains canned EPM action handlers
*/

/*  */

#ifndef EPM_ACTION_HANDLERS_H
#define EPM_ACTION_HANDLERS_H

#include <epm/epm.h>

#include <user_exits/libuser_exits_exports.h>

/**
    @defgroup EPM_ACTION_HANDLERS EPM Action Handlers
    @ingroup USER_EXITS
    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif

#if 0
extern USER_EXITS_API int EPM_display_form(
    EPM_action_message_t  msg   /**< (I) */
    );

extern USER_EXITS_API int EPM_create_form(
    EPM_action_message_t  msg   /**< (I) */
    );
#endif

extern USER_EXITS_API int EPM_send_target_objects(
    EPM_action_message_t  msg   /**< (I) */
    );

#if 0
extern USER_EXITS_API int EPM_create_sub_process (
    EPM_action_message_t  msg   /**< (I) */
    );
#endif

#ifdef __cplusplus
}
#endif

/** @} */

#include <user_exits/libuser_exits_undef.h>

#endif
