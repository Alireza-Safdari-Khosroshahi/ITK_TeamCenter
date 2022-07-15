/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that defines the export symbols for the TCCORE library
 */

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libtccore

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCCORE_API, not TCCOREEXPORT */

#define TCCORE_API TCCOREEXPORT

/* Support TCCOREEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtccore
#   if defined(__lint)
#       define TCCOREEXPORT       __export(tccore)
#       define TCCOREGLOBAL       extern __global(tccore)
#       define TCCOREPRIVATE      extern __private(tccore)
#   elif defined(_WIN32)
#       define TCCOREEXPORT       __declspec(dllexport)
#       define TCCOREGLOBAL       extern __declspec(dllexport)
#       define TCCOREPRIVATE      extern
#   else
#       define TCCOREEXPORT
#       define TCCOREGLOBAL       extern
#       define TCCOREPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCCOREEXPORT       __export(tccore)
#       define TCCOREGLOBAL       extern __global(tccore)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCCOREEXPORT      __declspec(dllimport)
#       define TCCOREGLOBAL       extern __declspec(dllimport)
#   else
#       define TCCOREEXPORT
#       define TCCOREGLOBAL       extern
#   endif
#endif
