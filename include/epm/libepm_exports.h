/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that defines the export symbols for the EPM library
 */

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libepm

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use EPM_API, not EPMEXPORT */

#define EPM_API EPMEXPORT

/* Support EPMEXPORT for autogenerated schema/pif code only */

#if IPLIB==libepm
#   if defined(__lint)
#       define EPMEXPORT       __export(epm)
#       define EPMGLOBAL       extern __global(epm)
#       define EPMPRIVATE      extern __private(epm)
#   elif defined(_WIN32)
#       define EPMEXPORT       __declspec(dllexport)
#       define EPMGLOBAL       extern __declspec(dllexport)
#       define EPMPRIVATE      extern
#   else
#       define EPMEXPORT
#       define EPMGLOBAL       extern
#       define EPMPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define EPMEXPORT       __export(epm)
#       define EPMGLOBAL       extern __global(epm)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define EPMEXPORT      __declspec(dllimport)
#       define EPMGLOBAL       extern __declspec(dllimport)
#   else
#       define EPMEXPORT
#       define EPMGLOBAL       extern
#   endif
#endif

