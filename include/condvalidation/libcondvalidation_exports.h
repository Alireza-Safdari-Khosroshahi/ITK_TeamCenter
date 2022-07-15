//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2009.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/**
    @file

    Defines the export symbols for the condvalidation (Condition Validation) library

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY                                   libcondvalidation

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define CONDVALIDATION_LIBRARY_NAME                     libcondvalidation
#define CONDVALIDATION_LIBRARY_ID_NAME                  condvalidation

#if IPLIB==CONDVALIDATION_LIBRARY_NAME
#   if defined(__lint)
#       define CONDVALIDATIONEXPORT                     __export(CONDVALIDATION_LIBRARY_ID_NAME)
#       define CONDVALIDATIONGLOBAL                     extern __global(CONDVALIDATION_LIBRARY_ID_NAME)
#       define CONDVALIDATIONPRIVATE                    extern __private(CONDVALIDATION_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define CONDVALIDATIONEXPORT                     __declspec(dllexport)
#       define CONDVALIDATIONGLOBAL                     extern __declspec(dllexport)
#       define CONDVALIDATIONPRIVATE                    extern
#   else
#       define CONDVALIDATIONEXPORT
#       define CONDVALIDATIONGLOBAL                     extern
#       define CONDVALIDATIONPRIVATE                    extern
#   endif
#else
#   if defined(__lint)
#       define CONDVALIDATIONEXPORT                     __export(CONDVALIDATION_LIBRARY_ID_NAME)
#       define CONDVALIDATIONGLOBAL                     extern __global(CONDVALIDATION_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CONDVALIDATIONEXPORT                     __declspec(dllimport)
#       define CONDVALIDATIONGLOBAL                     extern __declspec(dllimport)
#   else
#       define CONDVALIDATIONEXPORT
#       define CONDVALIDATIONGLOBAL                     extern
#   endif
#endif

#define CONDVALIDATION_API CONDVALIDATIONEXPORT
