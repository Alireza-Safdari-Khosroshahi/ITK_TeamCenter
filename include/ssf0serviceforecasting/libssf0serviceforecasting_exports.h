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

    This file contains the declaration for the Dispatch Library  SSF0SERVICEFORECASTING

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libSSF0SERVICEFORECASTING

#if !defined(LIBSSF0SERVICEFORECASTING) && !defined(IPLIB)
#   error IPLIB or LIBSSF0SERVICEFORECASTING is not defined
#endif

/* Handwritten code should use SSF0SERVICEFORECASTING_API, not SSF0SERVICEFORECASTINGEXPORT */

#define SSF0SERVICEFORECASTING_API SSF0SERVICEFORECASTINGEXPORT

#if IPLIB==libSSF0SERVICEFORECASTING || defined(LIBSSF0SERVICEFORECASTING)
#   if defined(__lint)
#       define SSF0SERVICEFORECASTINGEXPORT       __export(SSF0SERVICEFORECASTING)
#       define SSF0SERVICEFORECASTINGGLOBAL       extern __global(SSF0SERVICEFORECASTING)
#       define SSF0SERVICEFORECASTINGPRIVATE      extern __private(SSF0SERVICEFORECASTING)
#   elif defined(_WIN32)
#       define SSF0SERVICEFORECASTINGEXPORT       __declspec(dllexport)
#       define SSF0SERVICEFORECASTINGGLOBAL       extern __declspec(dllexport)
#       define SSF0SERVICEFORECASTINGPRIVATE      extern
#   else
#       define SSF0SERVICEFORECASTINGEXPORT
#       define SSF0SERVICEFORECASTINGGLOBAL       extern
#       define SSF0SERVICEFORECASTINGPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define SSF0SERVICEFORECASTINGEXPORT       __export(SSF0SERVICEFORECASTING)
#       define SSF0SERVICEFORECASTINGGLOBAL       extern __global(SSF0SERVICEFORECASTING)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define SSF0SERVICEFORECASTINGEXPORT      __declspec(dllimport)
#       define SSF0SERVICEFORECASTINGGLOBAL       extern __declspec(dllimport)
#   else
#       define SSF0SERVICEFORECASTINGEXPORT
#       define SSF0SERVICEFORECASTINGGLOBAL       extern
#   endif
#endif
