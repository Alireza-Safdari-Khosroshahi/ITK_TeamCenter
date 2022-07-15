/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains declarations of ERP functions to be used by customers.
*/

/*  */

#ifndef  ERPCUSTOM_H
#define  ERPCUSTOM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    @defgroup ERPCUSTOM ERP Customization
    @ingroup USER_EXITS
    @{
*/

typedef int (* ERPCUSTOM_check_func_t )(
    int,
    char**,
    char**,
    char*,
    logical*,
    char**
    );

typedef int (* ERPCUSTOM_derive_func_t )(
    int,
    char**,
    char**,
    char**
    );

typedef struct ERPCUSTOM_check_func_names_s{
   char*                    key;
   ERPCUSTOM_check_func_t   func_name;
} ERPCUSTOM_check_func_names_t;

typedef struct ERPCUSTOM_derive_func_names_s{
   char*                    key;
   ERPCUSTOM_derive_func_t  func_name;
} ERPCUSTOM_derive_func_names_t;

#include <user_exits/libuser_exits_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

extern USER_EXITS_API ERPCUSTOM_check_func_names_t* ERPCUSTOM_get_custom_check_funcs(
    int*              n_funcs
    );

extern USER_EXITS_API ERPCUSTOM_derive_func_names_t* ERPCUSTOM_get_custom_derive_funcs(
    int*              n_funcs
    );

int BMF_ERPCUSTOM_derive_funcs_helper(ERPCUSTOM_derive_func_names_t** func_result,int *result);
int BMF_ERPCUSTOM_check_funcs_helper(ERPCUSTOM_check_func_names_t** func_result,int *result);


#ifdef __cplusplus
}
#endif

/** @} */

#include <user_exits/libuser_exits_undef.h>

#endif
