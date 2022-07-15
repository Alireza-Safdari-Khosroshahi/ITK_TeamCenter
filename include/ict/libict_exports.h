/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that defines the export symbols for the ICT library
 */

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libict

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use ICT_API, not ICTEXPORT */

#define ICT_API ICTEXPORT

/* Support ICTEXPORT for autogenerated schema/pif code only */

#if IPLIB==libict
#   if defined(__lint)
#       define ICTEXPORT       __export(ict)
#       define ICTGLOBAL       extern __global(ict)
#       define ICTPRIVATE      extern __private(ict)
#   elif defined(_WIN32)
#       define ICTEXPORT       __declspec(dllexport)
#       define ICTGLOBAL       extern __declspec(dllexport)
#       define ICTPRIVATE      extern
#   else
#       define ICTEXPORT
#       define ICTGLOBAL       extern
#       define ICTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define ICTEXPORT       __export(ict)
#       define ICTGLOBAL       extern __global(ict)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define ICTEXPORT      __declspec(dllimport)
#       define ICTGLOBAL       extern __declspec(dllimport)
#   else
#       define ICTEXPORT
#       define ICTGLOBAL       extern
#   endif
#endif
