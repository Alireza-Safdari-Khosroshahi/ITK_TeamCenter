/*==============================================================================
                Copyright (c) 2006 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that defines the export symbols for the REQ library
 */

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libreq

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use REQ_API, not REQEXPORT */

#define REQ_API REQEXPORT

/* Support REQEXPORT for autogenerated schema/pif code only */

#if IPLIB==libreq
#   if defined(__lint)
#       define REQEXPORT       __export(req)
#       define REQGLOBAL       extern __global(req)
#       define REQPRIVATE      extern __private(req)
#   elif defined(_WIN32)
#       define REQEXPORT       __declspec(dllexport)
#       define REQGLOBAL       extern __declspec(dllexport)
#       define REQPRIVATE      extern
#   else
#       define REQEXPORT
#       define REQGLOBAL       extern
#       define REQPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define REQEXPORT       __export(req)
#       define REQGLOBAL       extern __global(req)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define REQEXPORT      __declspec(dllimport)
#       define REQGLOBAL       extern __declspec(dllimport)
#   else
#       define REQEXPORT
#       define REQGLOBAL       extern
#   endif
#endif
