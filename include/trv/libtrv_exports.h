/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2015.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    The header file that defines the export symbols for the TRV library

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libtrv

#if !defined(LIBTRV) && !defined(IPLIB)
#   error IPLIB or LIBTRV is not defined
#endif

/* Handwritten code should use TRV_API, not TRVEXPORT */

#define TRV_API TRVEXPORT

#if IPLIB==libtrv || defined(LIBTRV)
#   if defined(__lint)
#       define TRVEXPORT       __export(trv)
#       define TRVGLOBAL       extern __global(trv)
#       define TRVPRIVATE      extern __private(trv)
#   elif defined(_WIN32)
#       define TRVEXPORT       __declspec(dllexport)
#       define TRVGLOBAL       extern __declspec(dllexport)
#       define TRVPRIVATE      extern
#   else
#       define TRVEXPORT
#       define TRVGLOBAL       extern
#       define TRVPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TRVEXPORT       __export(trv)
#       define TRVGLOBAL       extern __global(trv)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TRVEXPORT      __declspec(dllimport)
#       define TRVGLOBAL       extern __declspec(dllimport)
#   else
#       define TRVEXPORT
#       define TRVGLOBAL       extern
#   endif
#endif
