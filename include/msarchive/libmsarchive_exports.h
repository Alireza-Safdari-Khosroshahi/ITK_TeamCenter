/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2017.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    The header file that defines the export symbols for the MSARCHIVE library
*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libmsarchive

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define MSARCHIVE_LIBRARY_NAME libmsarchive
#define MSARCHIVE_LIBRARY_ID_NAME msarchive

#if IPLIB==MSARCHIVE_LIBRARY_NAME
#   if defined(__lint)
#       define MSARCHIVEEXPORT       __export(MSARCHIVE_LIBRARY_ID_NAME)
#       define MSARCHIVEGLOBAL       extern __global(MSARCHIVE_LIBRARY_ID_NAME)
#       define MSARCHIVEPRIVATE      extern __private(MSARCHIVE_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define MSARCHIVEEXPORT       __declspec(dllexport)
#       define MSARCHIVEGLOBAL       extern __declspec(dllexport)
#       define MSARCHIVEPRIVATE      extern
#   else
#       define MSARCHIVEEXPORT
#       define MSARCHIVEGLOBAL       extern
#       define MSARCHIVEPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define MSARCHIVEEXPORT       __export(MSARCHIVE_LIBRARY_ID_NAME)
#       define MSARCHIVEGLOBAL       extern __global(MSARCHIVE_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define MSARCHIVEEXPORT       __declspec(dllimport)
#       define MSARCHIVEGLOBAL       extern __declspec(dllimport)
#   else
#       define MSARCHIVEEXPORT
#       define MSARCHIVEGLOBAL       extern
#   endif
#endif
#define MSARCHIVE_API MSARCHIVEEXPORT
