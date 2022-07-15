// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2007 UGS Corp. All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@


/** 
    @file 

    The header file that defines the export symbols for the CONSTANTS library.

*/


#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#ifdef __lint
#   pragma uginclude only_in_error "libconstants_main.c", "*.h";
#endif

#define EXPORTLIBRARY            libconstants

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define CONSTANTS_LIBRARY_NAME libconstants
#define CONSTANTS_LIBRARY_ID_NAME constants
#define CONSTANTS_API CONSTANTSEXPORT

#if IPLIB==CONSTANTS_LIBRARY_NAME
#   if defined(__lint)
#       define CONSTANTSEXPORT       __export(CONSTANTS_LIBRARY_ID_NAME)
#       define CONSTANTSGLOBAL       extern __global(CONSTANTS_LIBRARY_ID_NAME)
#       define CONSTANTSPRIVATE      extern __private(CONSTANTS_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define CONSTANTSEXPORT       __declspec(dllexport)
#       define CONSTANTSGLOBAL       extern __declspec(dllexport)
#       define CONSTANTSPRIVATE      extern
#   else
#       define CONSTANTSEXPORT
#       define CONSTANTSGLOBAL       extern
#       define CONSTANTSPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CONSTANTSEXPORT       __export(CONSTANTS_LIBRARY_ID_NAME)
#       define CONSTANTSGLOBAL       extern __global(CONSTANTS_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CONSTANTSEXPORT       __declspec(dllimport)
#       define CONSTANTSGLOBAL       extern __declspec(dllimport)
#   else
#       define CONSTANTSEXPORT
#       define CONSTANTSGLOBAL       extern
#   endif
#endif
