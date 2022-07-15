//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2013.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/**
    @file

    This file contains the declaration for the Library  MDConnectivity

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libMdc0mdc

#if !defined(LIBMDC0MDC) && !defined(IPLIB)
#   error IPLIB or LIBMDC0MDC is not defined
#endif

/* Handwritten code should use MDC0MDC_API, not MDC0MDCEXPORT */

#define MDC0MDC_API MDC0MDCEXPORT

#if IPLIB==libMdc0mdc || defined(LIBMDC0MDC)
#   if defined(__lint)
#       define MDC0MDCEXPORT       __export(Mdc0mdc)
#       define MDC0MDCGLOBAL       extern __global(Mdc0mdc)
#       define MDC0MDCPRIVATE      extern __private(Mdc0mdc)
#   elif defined(_WIN32)
#       define MDC0MDCEXPORT       __declspec(dllexport)
#       define MDC0MDCGLOBAL       extern __declspec(dllexport)
#       define MDC0MDCPRIVATE      extern
#   else
#       define MDC0MDCEXPORT
#       define MDC0MDCGLOBAL       extern
#       define MDC0MDCPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define MDC0MDCEXPORT       __export(Mdc0mdc)
#       define MDC0MDCGLOBAL       extern __global(Mdc0mdc)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define MDC0MDCEXPORT      __declspec(dllimport)
#       define MDC0MDCGLOBAL       extern __declspec(dllimport)
#   else
#       define MDC0MDCEXPORT
#       define MDC0MDCGLOBAL       extern
#   endif
#endif
