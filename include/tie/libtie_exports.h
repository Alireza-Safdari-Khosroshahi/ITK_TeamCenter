// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2006 UGS Corp. All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@


/** 
    @file 

    Defines the export symbols for the TIE library

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#ifdef __lint
#   pragma uginclude only_in_error "libtie_main.c", "*.h";
#endif

#define EXPORTLIBRARY            libtie

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define TIE_LIBRARY_NAME libtie
#define TIE_LIBRARY_ID_NAME tie

#if IPLIB==TIE_LIBRARY_NAME
#   if defined(__lint)
#       define TIEEXPORT       __export(TIE_LIBRARY_ID_NAME)
#       define TIEGLOBAL       extern __global(TIE_LIBRARY_ID_NAME)
#       define TIEPRIVATE      extern __private(TIE_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define TIEEXPORT       __declspec(dllexport)
#       define TIEGLOBAL       extern __declspec(dllexport)
#       define TIEPRIVATE      extern
#   else
#       define TIEEXPORT
#       define TIEGLOBAL       extern
#       define TIEPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TIEEXPORT       __export(TIE_LIBRARY_ID_NAME)
#       define TIEGLOBAL       extern __global(TIE_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TIEEXPORT       __declspec(dllimport)
#       define TIEGLOBAL       extern __declspec(dllimport)
#   else
#       define TIEEXPORT
#       define TIEGLOBAL       extern
#   endif
#endif
#define TIE_API TIEEXPORT
