/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2016.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    All the error codes are moved to constraintsolver/cfg_errors.h
    @deprecated This header file will be removed from Tc13.0. Use constraintsolver/cfg_errors.h
*/

#ifndef CFG_ERRORS_H_OLD
#define CFG_ERRORS_H_OLD

#if TC_MAJOR_VERSION + TC_MINOR_VERSION < 13000 /** Deprecated in Tc12.3, removed in Tc13.0 and later */
#include <constraintsolver/cfg_errors.h>

#ifdef WNT
/** 
    #pragma deprecated issues a C4995 warning which is treated as an error in Teamcenter,
    unlike __declspec(deprecated) which triggers a C4996 warning
 */
#pragma warning( push ) /* store the current warning state for all warnings */
#pragma warning( 1 : 4995 ) /* define warning level 1 (which is the default reporting level) for deprecation warnings */

#define ENUM_CONFIGURATOR_CFG_ERRORS_H_DEPRECATED
#pragma deprecated( "ENUM_CONFIGURATOR_CFG_ERRORS_H_DEPRECATED" ) /* activate the deprecation warning when using the macro name */
/* This header file(configurator/cfg_errors.h) will be removed from Tc13.0. Use constraintsolver/cfg_errors.h. */
ENUM_CONFIGURATOR_CFG_ERRORS_H_DEPRECATED /* use the deprecated macro so that the compiler issues the deprecation warning */

#pragma warning( pop ) /* pop the last warning state pushed onto the stack */
#endif /* #ifdef WNT */

#endif /** TC_MAJOR_VERSION + TC_MINOR_VERSION < 13000 */

#endif
