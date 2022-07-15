/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    TCAE function prototypes
*/

/*  */

#ifndef TCAEHELPER_H
#define TCAEHELPER_H

#include <tccore/libtccore_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup TCAE TCAE
    @{
*/

extern TCCORE_API int TCAE_has_license(
    int*                hasLicense /**< (O) Returns the TCAE license level. If the returned value is: 
                                        <ul>
                                        <li>1 indicates license is not available
                                        <li>2 indicates has TCAE license
                                        <li>3 indicates has both TCAE license and GM Overlay license
                                        </ul> */
    );

/**
    Registers LDAP authentication function.
*/
extern TCCORE_API int TCAE_register_auth_func();

/** @} */

#ifdef __cplusplus
}
#endif

#include <tccore/libtccore_undef.h>

#endif
