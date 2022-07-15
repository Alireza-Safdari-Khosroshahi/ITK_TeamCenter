/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that defines the export symbols for the APPR library
 */

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libappr

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use APPR_API, not APPREXPORT */

#define APPR_API APPREXPORT

/* Support APPREXPORT for autogenerated schema/pif code only */

#if IPLIB==libappr
#   if defined(__lint)
#       define APPREXPORT       __export(appr)
#       define APPRGLOBAL       extern __global(appr)
#       define APPRPRIVATE      extern __private(appr)
#   elif defined(_WIN32)
#       define APPREXPORT       __declspec(dllexport)
#       define APPRGLOBAL       extern __declspec(dllexport)
#       define APPRPRIVATE      extern
#   else
#       define APPREXPORT
#       define APPRGLOBAL       extern
#       define APPRPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define APPREXPORT       __export(appr)
#       define APPRGLOBAL       extern __global(appr)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define APPREXPORT      __declspec(dllimport)
#       define APPRGLOBAL       extern __declspec(dllimport)
#   else
#       define APPREXPORT
#       define APPRGLOBAL       extern
#   endif
#endif
