//@<COPYRIGHT>@
//==================================================
//Copyright $2021.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//@<COPYRIGHT>@

/** 
    @file 

    This file contains the declaration for the Dispatch Library  uiconfig

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libuiconfig

#if !defined(LIBUICONFIG) && !defined(IPLIB)
#   error IPLIB or LIBUICONFIG is not defined
#endif

/* Handwritten code should use UICONFIG_API, not UICONFIGEXPORT */

#define UICONFIG_API UICONFIGEXPORT

#if IPLIB==libuiconfig || defined(LIBUICONFIG)
#   if defined(__lint)
#       define UICONFIGEXPORT       __export(uiconfig)
#       define UICONFIGGLOBAL       extern __global(uiconfig)
#       define UICONFIGPRIVATE      extern __private(uiconfig)
#   elif defined(_WIN32)
#       define UICONFIGEXPORT       __declspec(dllexport)
#       define UICONFIGGLOBAL       extern __declspec(dllexport)
#       define UICONFIGPRIVATE      extern
#   else
#       define UICONFIGEXPORT
#       define UICONFIGGLOBAL       extern
#       define UICONFIGPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define UICONFIGEXPORT       __export(uiconfig)
#       define UICONFIGGLOBAL       extern __global(uiconfig)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define UICONFIGEXPORT      __declspec(dllimport)
#       define UICONFIGGLOBAL       extern __declspec(dllimport)
#   else
#       define UICONFIGEXPORT
#       define UICONFIGGLOBAL       extern
#   endif
#endif
