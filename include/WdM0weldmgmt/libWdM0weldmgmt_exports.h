//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2011.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  WdM0weldmgmt

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libWdM0weldmgmt

#if !defined(LIBWDM0WELDMGMT) && !defined(IPLIB)
#   error IPLIB or LIBWDM0WELDMGMT is not defined
#endif

/* Handwritten code should use WDM0WELDMGMT_API, not WDM0WELDMGMTEXPORT */

#define WDM0WELDMGMT_API WDM0WELDMGMTEXPORT

#if IPLIB==libWdM0weldmgmt || defined(LIBWDM0WELDMGMT)
#   if defined(__lint)
#       define WDM0WELDMGMTEXPORT       __export(WdM0weldmgmt)
#       define WDM0WELDMGMTGLOBAL       extern __global(WdM0weldmgmt)
#       define WDM0WELDMGMTPRIVATE      extern __private(WdM0weldmgmt)
#   elif defined(_WIN32)
#       define WDM0WELDMGMTEXPORT       __declspec(dllexport)
#       define WDM0WELDMGMTGLOBAL       extern __declspec(dllexport)
#       define WDM0WELDMGMTPRIVATE      extern
#   else
#       define WDM0WELDMGMTEXPORT
#       define WDM0WELDMGMTGLOBAL       extern
#       define WDM0WELDMGMTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define WDM0WELDMGMTEXPORT       __export(WdM0weldmgmt)
#       define WDM0WELDMGMTGLOBAL       extern __global(WdM0weldmgmt)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define WDM0WELDMGMTEXPORT      __declspec(dllimport)
#       define WDM0WELDMGMTGLOBAL       extern __declspec(dllimport)
#   else
#       define WDM0WELDMGMTEXPORT
#       define WDM0WELDMGMTGLOBAL       extern
#   endif
#endif
