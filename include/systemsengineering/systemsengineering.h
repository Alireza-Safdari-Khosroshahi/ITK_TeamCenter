/*==============================================================================
//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2010.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software
 ==============================================================================*/

/**
    @file

    This header file declares all data types and constants to be used by clients of
    Systems Engineering module.
*/

#ifndef SYSTEMSENGINEERING_H
#define SYSTEMSENGINEERING_H

#include <systemsengineering/libsystemsengineering_exports.h>


#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup SYSTEMSENGINEERING Systems Engineering
    The Systems Engineering module.
    @{
*/

/**
    Deletes a Function structure
*/
extern SYSTEMSENGINEERING_API int SE_delete_function_structure(
    tag_t  funcBomLine,                        /**< (I) Functional BOMLine to be deleted */
    logical  isDeleteChildren                  /**< (I) True if children also are to be deleted */
    );

/** @} */

#ifdef __cplusplus
    }
#endif

#include <systemsengineering/libsystemsengineering_undef.h>

#endif
