/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2017.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @libLcm0liscm_exports.h
    Export defines for the Change Management integration using Linked Data Framework Library

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libLcm0liscm

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define LCM0LISCM_LIBRARY_NAME libLcm0liscm
#define LCM0LISCM_LIBRARY_ID_NAME Lcm0liscm

/* Handwritten code should use LCM0LISCM_API, not LCM0LISCMEXPORT */

#define LCM0LISCM_API LCM0LISCMEXPORT

/* Support LCM0LISCMEXPORT for autogenerated schema/pif code only */

#if IPLIB==LCM0LISCM_LIBRARY_NAME
#   if defined(__lint)
#       define LCM0LISCMEXPORT       __export(LCM0LISCM_LIBRARY_ID_NAME)
#       define LCM0LISCMGLOBAL       extern __global(LCM0LISCM_LIBRARY_ID_NAME)
#       define LCM0LISCMPRIVATE      extern __private(LCM0LISCM_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define LCM0LISCMEXPORT       __declspec(dllexport)
#       define LCM0LISCMGLOBAL       extern __declspec(dllexport)
#       define LCM0LISCMPRIVATE      extern
#   else
#       define LCM0LISCMEXPORT
#       define LCM0LISCMGLOBAL       extern
#       define LCM0LISCMPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define LCM0LISCMEXPORT       __export(LCM0LISCM_LIBRARY_ID_NAME)
#       define LCM0LISCMGLOBAL       extern __global(LCM0LISCM_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define LCM0LISCMEXPORT       __declspec(dllimport)
#       define LCM0LISCMGLOBAL       extern __declspec(dllimport)
#   else
#       define LCM0LISCMEXPORT
#       define LCM0LISCMGLOBAL       extern
#   endif
#endif