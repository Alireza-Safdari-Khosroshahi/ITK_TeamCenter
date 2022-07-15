/**
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright $2017.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software

    @file

    This file contains the declaration for the Dispatch Library  cpd0mmv

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libcpd0mmv

#if !defined(LIBCPD0MMV) && !defined(IPLIB)
#   error IPLIB or LIBCPD0MMV is not defined
#endif

/* Handwritten code should use CPD0MMV_API, not CPD0MMVEXPORT */

#define CPD0MMV_API CPD0MMVEXPORT

#if IPLIB==libcpd0mmv || defined(LIBCPD0MMV)
#   if defined(__lint)
#       define CPD0MMVEXPORT       __export(cpd0mmv)
#       define CPD0MMVGLOBAL       extern __global(cpd0mmv)
#       define CPD0MMVPRIVATE      extern __private(cpd0mmv)
#   elif defined(_WIN32)
#       define CPD0MMVEXPORT       __declspec(dllexport)
#       define CPD0MMVGLOBAL       extern __declspec(dllexport)
#       define CPD0MMVPRIVATE      extern
#   else
#       define CPD0MMVEXPORT
#       define CPD0MMVGLOBAL       extern
#       define CPD0MMVPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CPD0MMVEXPORT       __export(cpd0mmv)
#       define CPD0MMVGLOBAL       extern __global(cpd0mmv)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CPD0MMVEXPORT      __declspec(dllimport)
#       define CPD0MMVGLOBAL       extern __declspec(dllimport)
#   else
#       define CPD0MMVEXPORT
#       define CPD0MMVGLOBAL       extern
#   endif
#endif
