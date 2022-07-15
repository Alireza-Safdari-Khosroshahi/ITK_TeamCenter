//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2010.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  cpd0workset

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libcpd0workset

#if !defined(LIBCPD0WORKSET) && !defined(IPLIB)
#   error IPLIB or LIBCPD0WORKSET is not defined
#endif

/* Handwritten code should use CPD0WORKSET_API, not CPD0WORKSETEXPORT */

#define CPD0WORKSET_API CPD0WORKSETEXPORT

#if IPLIB==cpd0workset || defined(LIBCPD0WORKSET)
#   if defined(__lint)
#       define CPD0WORKSETEXPORT       __export(cpd0workset)
#       define CPD0WORKSETGLOBAL       extern __global(cpd0workset)
#       define CPD0WORKSETPRIVATE      extern __private(cpd0workset)
#   elif defined(_WIN32)
#       define CPD0WORKSETEXPORT       __declspec(dllexport)
#       define CPD0WORKSETGLOBAL       extern __declspec(dllexport)
#       define CPD0WORKSETPRIVATE      extern
#   else
#       define CPD0WORKSETEXPORT
#       define CPD0WORKSETGLOBAL       extern
#       define CPD0WORKSETPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CPD0WORKSETEXPORT       __export(cpd0workset)
#       define CPD0WORKSETGLOBAL       extern __global(cpd0workset)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CPD0WORKSETEXPORT      __declspec(dllimport)
#       define CPD0WORKSETGLOBAL       extern __declspec(dllimport)
#   else
#       define CPD0WORKSETEXPORT
#       define CPD0WORKSETGLOBAL       extern
#   endif
#endif
