/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains function declaration of AIWS User Extension functions.
*/

/*  */

#ifndef  AIWSEXTENTION_H
#define  AIWSEXTENTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ai/aiws_extensions.h>
#include <user_exits/libuser_exits_exports.h>

/**
    @defgroup AIWS_EXT AIWS User Extension
    @ingroup USER_EXITS
    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif

extern USER_EXITS_API int AIWS_Create_AI(
    const char*           xmlIn,
    char**                xmlOut
    );

extern USER_EXITS_API int AIWS_Create_AI(const char *xmlIn,char **xmlOut);
extern USER_EXITS_API int AIWS_Open_Eda_Dataset(const char *xmlIn, char **xmlOut);
extern USER_EXITS_API int AIWS_CheckOut_Item(const char *xmlIn, char **xmlOut);
extern USER_EXITS_API int AIWS_Search_Item(const char *xmlIn, char **xmlOut);
extern USER_EXITS_API int AIWS_Search_Dataset(const char *xmlIn, char **xmlOut);
/* Add other functions */


#ifdef __cplusplus
}
#endif

/** @} */

#include <user_exits/libuser_exits_undef.h>

#endif
