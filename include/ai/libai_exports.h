//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2010.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  ai

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libai

#if !defined(LIBAI) && !defined(IPLIB)
#   error IPLIB or LIBAI is not defined
#endif

/* Handwritten code should use AI_API, not AIEXPORT */

#define AI_API AIEXPORT

#if IPLIB==libai || defined(LIBAI)
#   if defined(__lint)
#       define AIEXPORT       __export(ai)
#       define AIGLOBAL       extern __global(ai)
#       define AIPRIVATE      extern __private(ai)
#   elif defined(_WIN32)
#       define AIEXPORT       __declspec(dllexport)
#       define AIGLOBAL       extern __declspec(dllexport)
#       define AIPRIVATE      extern
#   else
#       define AIEXPORT
#       define AIGLOBAL       extern
#       define AIPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define AIEXPORT       __export(ai)
#       define AIGLOBAL       extern __global(ai)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define AIEXPORT      __declspec(dllimport)
#       define AIGLOBAL       extern __declspec(dllimport)
#   else
#       define AIEXPORT
#       define AIGLOBAL       extern
#   endif
#endif
