//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2010.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  contmgmts1000d40

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libcontmgmts1000d40

#if !defined(LIBCONTMGMTS1000D40) && !defined(IPLIB)
#   error IPLIB or LIBCONTMGMTS1000D40 is not defined
#endif

/* Handwritten code should use CONTMGMTS1000D40_API, not CONTMGMTS1000D40EXPORT */

#define CONTMGMTS1000D40_API CONTMGMTS1000D40EXPORT

#if IPLIB==libcontmgmts1000d40 || defined(LIBCONTMGMTS1000D40)
#   if defined(__lint)
#       define CONTMGMTS1000D40EXPORT       __export(contmgmts1000d40)
#       define CONTMGMTS1000D40GLOBAL       extern __global(contmgmts1000d40)
#       define CONTMGMTS1000D40PRIVATE      extern __private(contmgmts1000d40)
#   elif defined(_WIN32)
#       define CONTMGMTS1000D40EXPORT       __declspec(dllexport)
#       define CONTMGMTS1000D40GLOBAL       extern __declspec(dllexport)
#       define CONTMGMTS1000D40PRIVATE      extern
#   else
#       define CONTMGMTS1000D40EXPORT
#       define CONTMGMTS1000D40GLOBAL       extern
#       define CONTMGMTS1000D40PRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CONTMGMTS1000D40EXPORT       __export(contmgmts1000d40)
#       define CONTMGMTS1000D40GLOBAL       extern __global(contmgmts1000d40)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CONTMGMTS1000D40EXPORT      __declspec(dllimport)
#       define CONTMGMTS1000D40GLOBAL       extern __declspec(dllimport)
#   else
#       define CONTMGMTS1000D40EXPORT
#       define CONTMGMTS1000D40GLOBAL       extern
#   endif
#endif
