// @<COPYRIGHT_START>@
// ==================================================
// Copyright 2007.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// @<COPYRIGHT_END>@


/** 
    @file 

    The header file that defines the export symbols for the CE library.

*/


#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#ifdef __lint
#   pragma uginclude only_in_error "libce_main.c", "*.h";
#endif

#define EXPORTLIBRARY            libce

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define CE_LIBRARY_NAME libce
#define CE_LIBRARY_ID_NAME ce
#define CE_API CEEXPORT

#if IPLIB==CE_LIBRARY_NAME
#   if defined(__lint)
#       define CEEXPORT       __export(CE_LIBRARY_ID_NAME)
#       define CEGLOBAL       extern __global(CE_LIBRARY_ID_NAME)
#       define CEPRIVATE      extern __private(CE_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define CEEXPORT       __declspec(dllexport)
#       define CEGLOBAL       extern __declspec(dllexport)
#       define CEPRIVATE      extern
#   else
#       define CEEXPORT
#       define CEGLOBAL       extern
#       define CEPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CEEXPORT       __export(CE_LIBRARY_ID_NAME)
#       define CEGLOBAL       extern __global(CE_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CEEXPORT       __declspec(dllimport)
#       define CEGLOBAL       extern __declspec(dllimport)
#   else
#       define CEEXPORT
#       define CEGLOBAL       extern
#   endif
#endif
