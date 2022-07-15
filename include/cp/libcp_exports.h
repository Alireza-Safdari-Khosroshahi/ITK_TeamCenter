// @<COPYRIGHT_START>@
// ==================================================
// Copyright 2007.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// @<COPYRIGHT_END>@


/** 
    @file 

    The header file that defines the export symbols for the CP library.

*/


#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#ifdef __lint
#   pragma uginclude only_in_error "libcp_main.c", "*.h";
#endif

#define EXPORTLIBRARY            libcp

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define CP_LIBRARY_NAME libcp
#define CP_LIBRARY_ID_NAME cp
#define CP_API CPEXPORT

#if IPLIB==CP_LIBRARY_NAME
#   if defined(__lint)
#       define CPEXPORT       __export(CP_LIBRARY_ID_NAME)
#       define CPGLOBAL       extern __global(CP_LIBRARY_ID_NAME)
#       define CPPRIVATE      extern __private(CP_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define CPEXPORT       __declspec(dllexport)
#       define CPGLOBAL       extern __declspec(dllexport)
#       define CPPRIVATE      extern
#   else
#       define CPEXPORT
#       define CPGLOBAL       extern
#       define CPPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CPEXPORT       __export(CP_LIBRARY_ID_NAME)
#       define CPGLOBAL       extern __global(CP_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CPEXPORT       __declspec(dllimport)
#       define CPGLOBAL       extern __declspec(dllimport)
#   else
#       define CPEXPORT
#       define CPGLOBAL       extern
#   endif
#endif
