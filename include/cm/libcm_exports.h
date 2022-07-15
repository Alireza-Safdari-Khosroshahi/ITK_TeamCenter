//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2008.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  cm

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libcm

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use CM_API, not CMEXPORT */

#define CM_API CMEXPORT

#if IPLIB==libcm
#   if defined(__lint)
#       define CMEXPORT       __export(cm)
#       define CMGLOBAL       extern __global(cm)
#       define CMPRIVATE      extern __private(cm)
#   elif defined(_WIN32)
#       define CMEXPORT       __declspec(dllexport)
#       define CMGLOBAL       extern __declspec(dllexport)
#       define CMPRIVATE      extern
#   else
#       define CMEXPORT
#       define CMGLOBAL       extern
#       define CMPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CMEXPORT       __export(cm)
#       define CMGLOBAL       extern __global(cm)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CMEXPORT      __declspec(dllimport)
#       define CMGLOBAL       extern __declspec(dllimport)
#   else
#       define CMEXPORT
#       define CMGLOBAL       extern
#   endif
#endif
