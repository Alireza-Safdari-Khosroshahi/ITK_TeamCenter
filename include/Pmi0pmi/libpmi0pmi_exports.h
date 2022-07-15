//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Pmi0pmi

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libPmi0pmi

#if !defined(LIBPMI0PMI) && !defined(IPLIB)
#   error IPLIB or LIBPMI0PMI is not defined
#endif

/* Handwritten code should use PMI0PMI_API, not PMI0PMIEXPORT */

#define PMI0PMI_API PMI0PMIEXPORT

#if IPLIB==libPmi0pmi || defined(LIBPMI0PMI)
#   if defined(__lint)
#       define PMI0PMIEXPORT       __export(Pmi0pmi)
#       define PMI0PMIGLOBAL       extern __global(Pmi0pmi)
#       define PMI0PMIPRIVATE      extern __private(Pmi0pmi)
#   elif defined(_WIN32)
#       define PMI0PMIEXPORT       __declspec(dllexport)
#       define PMI0PMIGLOBAL       extern __declspec(dllexport)
#       define PMI0PMIPRIVATE      extern
#   else
#       define PMI0PMIEXPORT
#       define PMI0PMIGLOBAL       extern
#       define PMI0PMIPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define PMI0PMIEXPORT       __export(Pmi0pmi)
#       define PMI0PMIGLOBAL       extern __global(Pmi0pmi)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define PMI0PMIEXPORT      __declspec(dllimport)
#       define PMI0PMIGLOBAL       extern __declspec(dllimport)
#   else
#       define PMI0PMIEXPORT
#       define PMI0PMIGLOBAL       extern
#   endif
#endif
