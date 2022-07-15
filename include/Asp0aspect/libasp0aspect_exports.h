//@<COPYRIGHT>@
//==================================================
//Copyright $2021.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//@<COPYRIGHT>@

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Asp0aspect

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libAsp0aspect

#if !defined(LIBASP0ASPECT) && !defined(IPLIB)
#   error IPLIB or LIBASP0ASPECT is not defined
#endif

/* Handwritten code should use ASP0ASPECT_API, not ASP0ASPECTEXPORT */

#define ASP0ASPECT_API ASP0ASPECTEXPORT

#if IPLIB==libAsp0aspect || defined(LIBASP0ASPECT)
#   if defined(__lint)
#       define ASP0ASPECTEXPORT       __export(Asp0aspect)
#       define ASP0ASPECTGLOBAL       extern __global(Asp0aspect)
#       define ASP0ASPECTPRIVATE      extern __private(Asp0aspect)
#   elif defined(_WIN32)
#       define ASP0ASPECTEXPORT       __declspec(dllexport)
#       define ASP0ASPECTGLOBAL       extern __declspec(dllexport)
#       define ASP0ASPECTPRIVATE      extern
#   else
#       define ASP0ASPECTEXPORT
#       define ASP0ASPECTGLOBAL       extern
#       define ASP0ASPECTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define ASP0ASPECTEXPORT       __export(Asp0aspect)
#       define ASP0ASPECTGLOBAL       extern __global(Asp0aspect)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define ASP0ASPECTEXPORT      __declspec(dllimport)
#       define ASP0ASPECTGLOBAL       extern __declspec(dllimport)
#   else
#       define ASP0ASPECTEXPORT
#       define ASP0ASPECTGLOBAL       extern
#   endif
#endif
