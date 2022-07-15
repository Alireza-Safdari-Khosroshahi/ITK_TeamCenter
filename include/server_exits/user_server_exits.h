/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef USER_SERVER_EXITS_H
#define USER_SERVER_EXITS_H

#include <stdio.h>
#include <tc/tc_startup.h>
#include <ict/ict_userservice.h>
#include <server_exits/libserver_exits_exports.h>

/**
    @defgroup USER_SERVER_EXITS User Server Exits
    @{
*/

#ifdef __cplusplus
    extern "C"
    {
#endif

extern SERVER_EXITS_API int USERSERVICE_register_methods();

#ifdef __cplusplus
    }
#endif

/** @} */

#include <server_exits/libserver_exits_undef.h>

#endif
