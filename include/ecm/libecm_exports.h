/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that defines the export symbols for the ECM library
 */

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libecm

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use ECM_API, not ECMEXPORT */

#define ECM_API ECMEXPORT

/* Support ECMEXPORT for autogenerated schema/pif code only */

#if IPLIB==libecm
#   if defined(__lint)
#       define ECMEXPORT       __export(ecm)
#       define ECMGLOBAL       extern __global(ecm)
#       define ECMPRIVATE      extern __private(ecm)
#   elif defined(_WIN32)
#       define ECMEXPORT       __declspec(dllexport)
#       define ECMGLOBAL       extern __declspec(dllexport)
#       define ECMPRIVATE      extern
#   else
#       define ECMEXPORT
#       define ECMGLOBAL       extern
#       define ECMPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define ECMEXPORT       __export(ecm)
#       define ECMGLOBAL       extern __global(ecm)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define ECMEXPORT      __declspec(dllimport)
#       define ECMGLOBAL       extern __declspec(dllimport)
#   else
#       define ECMEXPORT
#       define ECMGLOBAL       extern
#   endif
#endif

