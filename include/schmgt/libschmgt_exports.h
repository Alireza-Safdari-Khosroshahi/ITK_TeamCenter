// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2006 UGS Corp. All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@


/** 
    @libschmgt_exports.h 
    Export defines for the Schedule Management library

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libschmgt

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use SCHMGT_API, not SCHMGTEXPORT */
#define SCHMGT_API SCHMGTEXPORT

/* Support SCHMGTEXPORT for autogenerated code only */
#if IPLIB==libschmgt
#   if defined(__lint)
#       define SCHMGTEXPORT       __export(schmgt)
#       define SCHMGTGLOBAL       extern __global(schmgt)
#       define SCHMGTPRIVATE      extern __private(schmgt)
#   elif defined(_WIN32)
#       define SCHMGTEXPORT       __declspec(dllexport)
#       define SCHMGTGLOBAL       extern __declspec(dllexport)
#       define SCHMGTPRIVATE      extern
#   else
#       define SCHMGTEXPORT
#       define SCHMGTGLOBAL       extern
#       define SCHMGTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define SCHMGTEXPORT       __export(schmgt)
#       define SCHMGTGLOBAL       extern __global(schmgt)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define SCHMGTEXPORT      __declspec(dllimport)
#       define SCHMGTGLOBAL       extern __declspec(dllimport)
#   else
#       define SCHMGTEXPORT
#       define SCHMGTGLOBAL       extern
#   endif
#endif
