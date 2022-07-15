/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2014.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/** 
    @file 

    This file contains the declaration for the Dispatch Library  SAS0SVCAUTOSCHEDULING

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libSAS0SVCAUTOSCHEDULING

#if !defined(LIBSAS0SVCAUTOSCHEDULING) && !defined(IPLIB)
#   error IPLIB or LIBSAS0SVCAUTOSCHEDULING is not defined
#endif

/* Handwritten code should use SAS0SVCAUTOSCHEDULING_API, not SAS0SVCAUTOSCHEDULINGEXPORT */

#define SAS0SVCAUTOSCHEDULING_API SAS0SVCAUTOSCHEDULINGEXPORT

#if IPLIB==libSAS0SVCAUTOSCHEDULING || defined(LIBSAS0SVCAUTOSCHEDULING)
#   if defined(__lint)
#       define SAS0SVCAUTOSCHEDULINGEXPORT       __export(SAS0SVCAUTOSCHEDULING)
#       define SAS0SVCAUTOSCHEDULINGGLOBAL       extern __global(SAS0SVCAUTOSCHEDULING)
#       define SAS0SVCAUTOSCHEDULINGPRIVATE      extern __private(SAS0SVCAUTOSCHEDULING)
#   elif defined(_WIN32)
#       define SAS0SVCAUTOSCHEDULINGEXPORT       __declspec(dllexport)
#       define SAS0SVCAUTOSCHEDULINGGLOBAL       extern __declspec(dllexport)
#       define SAS0SVCAUTOSCHEDULINGPRIVATE      extern
#   else
#       define SAS0SVCAUTOSCHEDULINGEXPORT
#       define SAS0SVCAUTOSCHEDULINGGLOBAL       extern
#       define SAS0SVCAUTOSCHEDULINGPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define SAS0SVCAUTOSCHEDULINGEXPORT       __export(SAS0SVCAUTOSCHEDULING)
#       define SAS0SVCAUTOSCHEDULINGGLOBAL       extern __global(SAS0SVCAUTOSCHEDULING)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define SAS0SVCAUTOSCHEDULINGEXPORT      __declspec(dllimport)
#       define SAS0SVCAUTOSCHEDULINGGLOBAL       extern __declspec(dllimport)
#   else
#       define SAS0SVCAUTOSCHEDULINGEXPORT
#       define SAS0SVCAUTOSCHEDULINGGLOBAL       extern
#   endif
#endif
