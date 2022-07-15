/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains ITK functions to register/unregister DMI callback functions.
*/

/*  */

#ifndef IMANHANDLER_H
#define IMANHANDLER_H

#include <dmi/libdmi_exports.h>

/**
    @defgroup DMI_HANDLER Handler
    @ingroup DMI
    @{
*/

/**
    Function pointer for DMI (Document Management Interface) dataset openhandler
*/
typedef int (* OpenHandler_t)(
    tag_t dataset,            /**< (I) */
    tag_t datasetType,        /**< (I) */
    tag_t tool_tag,           /**< (I) */
    void* aUserData           /**< (O) */
    );

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @name Open handler callback functions
    @{
*/

extern DMI_API int DMI_registerOpenHandler(
    tag_t          datasetType,      /**< (I) */
    tag_t          tool,             /**< (I) */
    OpenHandler_t  action,           /**< (I) */
    void*          user_data         /**< (I) */
    );

extern void DMI_unregisterOpenHandler(
    tag_t   datasetType,        /**< (I) */
    tag_t   tool                /**< (I) */
    );

extern void DMI_unregisterAllHandlers();

/** @} */

#ifdef __cplusplus
}
#endif

/** @} */

#include <dmi/libdmi_undef.h>
#endif
