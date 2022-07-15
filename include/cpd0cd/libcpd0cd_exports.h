//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2010.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  cpd0cd

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libcpd0cd

#if !defined(LIBCPD0CD) && !defined(IPLIB)
#   error IPLIB or LIBCPD0CD is not defined
#endif

/* Handwritten code should use CPD0CD_API, not CPD0CDEXPORT */

#define CPD0CD_API CPD0CDEXPORT

#if IPLIB==libcpd0cd || defined(LIBCPD0CD)
#   if defined(__lint)
#       define CPD0CDEXPORT       __export(cpd0cd)
#       define CPD0CDGLOBAL       extern __global(cpd0cd)
#       define CPD0CDPRIVATE      extern __private(cpd0cd)
#   elif defined(_WIN32)
#       define CPD0CDEXPORT       __declspec(dllexport)
#       define CPD0CDGLOBAL       extern __declspec(dllexport)
#       define CPD0CDPRIVATE      extern
#   else
#       define CPD0CDEXPORT
#       define CPD0CDGLOBAL       extern
#       define CPD0CDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CPD0CDEXPORT       __export(cpd0cd)
#       define CPD0CDGLOBAL       extern __global(cpd0cd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CPD0CDEXPORT      __declspec(dllimport)
#       define CPD0CDGLOBAL       extern __declspec(dllimport)
#   else
#       define CPD0CDEXPORT
#       define CPD0CDGLOBAL       extern
#   endif
#endif
