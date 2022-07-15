//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2011.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  sss0svcscheduling

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libsss0svcscheduling

#if !defined(LIBSSS0SVCSCHEDULING) && !defined(IPLIB)
#   error IPLIB or LIBSSS0SVCSCHEDULING is not defined
#endif

/* Handwritten code should use SSS0SVCSCHEDULING_API, not SSS0SVCSCHEDULINGEXPORT */

#define SSS0SVCSCHEDULING_API SSS0SVCSCHEDULINGEXPORT

#if IPLIB==libsss0svcscheduling || defined(LIBSSS0SVCSCHEDULING)
#   if defined(__lint)
#       define SSS0SVCSCHEDULINGEXPORT       __export(sss0svcscheduling)
#       define SSS0SVCSCHEDULINGGLOBAL       extern __global(sss0svcscheduling)
#       define SSS0SVCSCHEDULINGPRIVATE      extern __private(sss0svcscheduling)
#   elif defined(_WIN32)
#       define SSS0SVCSCHEDULINGEXPORT       __declspec(dllexport)
#       define SSS0SVCSCHEDULINGGLOBAL       extern __declspec(dllexport)
#       define SSS0SVCSCHEDULINGPRIVATE      extern
#   else
#       define SSS0SVCSCHEDULINGEXPORT
#       define SSS0SVCSCHEDULINGGLOBAL       extern
#       define SSS0SVCSCHEDULINGPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define SSS0SVCSCHEDULINGEXPORT       __export(sss0svcscheduling)
#       define SSS0SVCSCHEDULINGGLOBAL       extern __global(sss0svcscheduling)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define SSS0SVCSCHEDULINGEXPORT      __declspec(dllimport)
#       define SSS0SVCSCHEDULINGGLOBAL       extern __declspec(dllimport)
#   else
#       define SSS0SVCSCHEDULINGEXPORT
#       define SSS0SVCSCHEDULINGGLOBAL       extern
#   endif
#endif
