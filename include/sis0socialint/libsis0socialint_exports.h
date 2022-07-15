/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2018.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Defines the export symbols for the SIS0SOCIALINT library

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY                                   libsis0socialint

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define SIS0SOCIALINT_LIBRARY_NAME                     libsis0socialint
#define SIS0SOCIALINT_LIBRARY_ID_NAME                  sis0socialint

#if IPLIB==SIS0SOCIALINT_LIBRARY_NAME
#   if defined(__lint)
#       define SIS0SOCIALINTEXPORT                     __export(SIS0SOCIALINT_LIBRARY_ID_NAME)
#       define SIS0SOCIALINTGLOBAL                     extern __global(SIS0SOCIALINT_LIBRARY_ID_NAME)
#       define SIS0SOCIALINTPRIVATE                    extern __private(SIS0SOCIALINT_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define SIS0SOCIALINTEXPORT                     __declspec(dllexport)
#       define SIS0SOCIALINTGLOBAL                     extern __declspec(dllexport)
#       define SIS0SOCIALINTPRIVATE                    extern
#   else
#       define SIS0SOCIALINTEXPORT
#       define SIS0SOCIALINTGLOBAL                     extern
#       define SIS0SOCIALINTPRIVATE                    extern
#   endif
#else
#   if defined(__lint)
#       define SIS0SOCIALINTEXPORT                     __export(SIS0SOCIALINT_LIBRARY_ID_NAME)
#       define SIS0SOCIALINTGLOBAL                     extern __global(SIS0SOCIALINT_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define SIS0SOCIALINTEXPORT                     __declspec(dllimport)
#       define SIS0SOCIALINTGLOBAL                     extern __declspec(dllimport)
#   else
#       define SIS0SOCIALINTEXPORT
#       define SIS0SOCIALINTGLOBAL                     extern
#   endif
#endif

#define SIS0SOCIALINT_API SIS0SOCIALINTEXPORT
