/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Function callback for generic aiws interface

This file contains methods related to Application Interface module.
*/

/*  */

#ifndef AIWS_EXTENSIONS_062804_C_H
#define AIWS_EXTENSIONS_062804_C_H

/**
    @defgroup AIWS_EXTENSIONS AIWS Extensions
    @ingroup PIE
    @{
*/

typedef int (*AIWS_Invoke_CBFunc)(
    const char* xmlin,
    char**      xmlOut
    );

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Register AIWebservice methods
*/
typedef struct AIWS_ext_entry_s
{
    const char*         method_name;
    AIWS_Invoke_CBFunc  ext_method;
} AIWS_ext_entry_t;

#ifdef __cplusplus
}
#endif

#include <ai/libai_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

extern AI_API int AIWS_addextensions(
    AIWS_ext_entry_t*   extensions
    );

#ifdef __cplusplus
}
#endif

/** @} */

#include <ai/libai_undef.h>

#endif
