/*Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2015.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Val0nxvalidation

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libVal0nxvalidation

#if !defined(LIBVAL0NXVALIDATION) && !defined(IPLIB)
#   error IPLIB or LIBVAL0NXVALIDATION is not defined
#endif

/* Handwritten code should use VAL0NXVALIDATION_API, not VAL0NXVALIDATIONEXPORT */

#define VAL0NXVALIDATION_API VAL0NXVALIDATIONEXPORT

#if IPLIB==libVal0nxvalidation || defined(LIBVAL0NXVALIDATION)
#   if defined(__lint)
#       define VAL0NXVALIDATIONEXPORT       __export(Val0nxvalidation)
#       define VAL0NXVALIDATIONGLOBAL       extern __global(Val0nxvalidation)
#       define VAL0NXVALIDATIONPRIVATE      extern __private(Val0nxvalidation)
#   elif defined(_WIN32)
#       define VAL0NXVALIDATIONEXPORT       __declspec(dllexport)
#       define VAL0NXVALIDATIONGLOBAL       extern __declspec(dllexport)
#       define VAL0NXVALIDATIONPRIVATE      extern
#   else
#       define VAL0NXVALIDATIONEXPORT
#       define VAL0NXVALIDATIONGLOBAL       extern
#       define VAL0NXVALIDATIONPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define VAL0NXVALIDATIONEXPORT       __export(Val0nxvalidation)
#       define VAL0NXVALIDATIONGLOBAL       extern __global(Val0nxvalidation)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define VAL0NXVALIDATIONEXPORT      __declspec(dllimport)
#       define VAL0NXVALIDATIONGLOBAL       extern __declspec(dllimport)
#   else
#       define VAL0NXVALIDATIONEXPORT
#       define VAL0NXVALIDATIONGLOBAL       extern
#   endif
#endif
