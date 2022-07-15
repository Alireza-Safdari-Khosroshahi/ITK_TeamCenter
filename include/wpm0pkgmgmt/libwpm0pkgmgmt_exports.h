//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  wpm0pkgmgmt

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libwpm0pkgmgmt

#if !defined(LIBWPM0PKGMGMT) && !defined(IPLIB)
#   error IPLIB or LIBWPM0PKGMGMT is not defined
#endif

/* Handwritten code should use WPM0PKGMGMT_API, not WPM0PKGMGMTEXPORT */

#define WPM0PKGMGMT_API WPM0PKGMGMTEXPORT

#if IPLIB==libwpm0pkgmgmt || defined(LIBWPM0PKGMGMT)
#   if defined(__lint)
#       define WPM0PKGMGMTEXPORT       __export(wpm0pkgmgmt)
#       define WPM0PKGMGMTGLOBAL       extern __global(wpm0pkgmgmt)
#       define WPM0PKGMGMTPRIVATE      extern __private(wpm0pkgmgmt)
#   elif defined(_WIN32)
#       define WPM0PKGMGMTEXPORT       __declspec(dllexport)
#       define WPM0PKGMGMTGLOBAL       extern __declspec(dllexport)
#       define WPM0PKGMGMTPRIVATE      extern
#   else
#       define WPM0PKGMGMTEXPORT
#       define WPM0PKGMGMTGLOBAL       extern
#       define WPM0PKGMGMTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define WPM0PKGMGMTEXPORT       __export(wpm0pkgmgmt)
#       define WPM0PKGMGMTGLOBAL       extern __global(wpm0pkgmgmt)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define WPM0PKGMGMTEXPORT      __declspec(dllimport)
#       define WPM0PKGMGMTGLOBAL       extern __declspec(dllimport)
#   else
#       define WPM0PKGMGMTEXPORT
#       define WPM0PKGMGMTGLOBAL       extern
#   endif
#endif
