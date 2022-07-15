/*Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2018.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Val1cfgvalidation

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libVal1cfgvalidation

#if !defined(LIBVAL1CFGVALIDATION) && !defined(IPLIB)
#   error IPLIB or LIBVAL1CFGVALIDATION is not defined
#endif

/* Handwritten code should use VAL1CFGVALIDATION_API, not VAL1CFGVALIDATIONEXPORT */

#define VAL1CFGVALIDATION_API VAL1CFGVALIDATIONEXPORT

#if IPLIB==libVal1cfgvalidation || defined(LIBVAL1CFGVALIDATION)
#   if defined(__lint)
#       define VAL1CFGVALIDATIONEXPORT       __export(Val1cfgvalidation)
#       define VAL1CFGVALIDATIONGLOBAL       extern __global(Val1cfgvalidation)
#       define VAL1CFGVALIDATIONPRIVATE      extern __private(Val1cfgvalidation)
#   elif defined(_WIN32)
#       define VAL1CFGVALIDATIONEXPORT       __declspec(dllexport)
#       define VAL1CFGVALIDATIONGLOBAL       extern __declspec(dllexport)
#       define VAL1CFGVALIDATIONPRIVATE      extern
#   else
#       define VAL1CFGVALIDATIONEXPORT
#       define VAL1CFGVALIDATIONGLOBAL       extern
#       define VAL1CFGVALIDATIONPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define VAL1CFGVALIDATIONEXPORT       __export(Val1cfgvalidation)
#       define VAL1CFGVALIDATIONGLOBAL       extern __global(Val1cfgvalidation)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define VAL1CFGVALIDATIONEXPORT      __declspec(dllimport)
#       define VAL1CFGVALIDATIONGLOBAL       extern __declspec(dllimport)
#   else
#       define VAL1CFGVALIDATIONEXPORT
#       define VAL1CFGVALIDATIONGLOBAL       extern
#   endif
#endif
