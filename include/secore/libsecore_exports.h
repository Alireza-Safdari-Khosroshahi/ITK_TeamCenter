//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2010.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/**
    @file

    This file contains the declaration for the Dispatch Library  secore

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libsecore

#if !defined(libsecore) && !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use SECORE_API, not SECOREEXPORT */

#define SECORE_API SECOREEXPORT

#if IPLIB==libsecore || defined(LIBSECORE)
#   if defined(__lint)
#       define SECOREEXPORT       __export(secore)
#       define SECOREGLOBAL       extern __global(secore)
#       define SECOREPRIVATE      extern __private(secore)
#   elif defined(_WIN32)
#       define SECOREEXPORT       __declspec(dllexport)
#       define SECOREGLOBAL       extern __declspec(dllexport)
#       define SECOREPRIVATE      extern
#   else
#       define SECOREEXPORT
#       define SECOREGLOBAL       extern
#       define SECOREPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define SECOREEXPORT       __export(secore)
#       define SECOREGLOBAL       extern __global(secore)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define SECOREEXPORT      __declspec(dllimport)
#       define SECOREGLOBAL       extern __declspec(dllimport)
#   else
#       define SECOREEXPORT
#       define SECOREGLOBAL       extern
#   endif
#endif
