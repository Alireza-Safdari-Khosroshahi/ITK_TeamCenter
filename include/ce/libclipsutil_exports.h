// @<COPYRIGHT_START>@
// ==================================================
// Copyright 2007.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// @<COPYRIGHT_END>@


/** 
    @file 

    The header file that defines the export symbols for the CLIPSUTIL library.

*/


#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#ifdef __lint
#   pragma uginclude only_in_error "libclipsutil_main.c", "*.h";
#endif

#define EXPORTLIBRARY            libclipsutil

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define CLIPSUTIL_LIBRARY_NAME libclipsutil
#define CLIPSUTIL_LIBRARY_ID_NAME clipsutil
#define CLIPSUTIL_API CLIPSUTILEXPORT

#if IPLIB==CLIPSUTIL_LIBRARY_NAME
#   if defined(__lint)
#       define CLIPSUTILEXPORT       __export(CLIPSUTIL_LIBRARY_ID_NAME)
#       define CLIPSUTILGLOBAL       extern __global(CLIPSUTIL_LIBRARY_ID_NAME)
#       define CLIPSUTILPRIVATE      extern __private(CLIPSUTIL_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define CLIPSUTILEXPORT       __declspec(dllexport)
#       define CLIPSUTILGLOBAL       extern __declspec(dllexport)
#       define CLIPSUTILPRIVATE      extern
#   else
#       define CLIPSUTILEXPORT
#       define CLIPSUTILGLOBAL       extern
#       define CLIPSUTILPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CLIPSUTILEXPORT       __export(CLIPSUTIL_LIBRARY_ID_NAME)
#       define CLIPSUTILGLOBAL       extern __global(CLIPSUTIL_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CLIPSUTILEXPORT       __declspec(dllimport)
#       define CLIPSUTILGLOBAL       extern __declspec(dllimport)
#   else
#       define CLIPSUTILEXPORT
#       define CLIPSUTILGLOBAL       extern
#   endif
#endif
