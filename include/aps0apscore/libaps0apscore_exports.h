/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2016.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/


/* 
    @file 
    
    This file contains the declaration for the Dispatch Library  APS0APSCORE
*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libaps0apscore

#if !defined(libaps0apscore) && !defined(IPLIB)
#   error IPLIB or libaps0apscore is not defined
#endif

/* Handwritten code should use APS0APSCORE_API, not APS0APSCOREEXPORT */

#define APS0APSCORE_API APS0APSCOREEXPORT

#if IPLIB==libaps0apscore || defined(libaps0apscore)
#   if defined(__lint)
#       define APS0APSCOREEXPORT       __export(APS0APSCORE)
#       define APS0APSCOREGLOBAL       extern __global(APS0APSCORE)
#       define APS0APSCOREPRIVATE      extern __private(APS0APSCORE)
#   elif defined(_WIN32)
#       define APS0APSCOREEXPORT       __declspec(dllexport)
#       define APS0APSCOREGLOBAL       extern __declspec(dllexport)
#       define APS0APSCOREPRIVATE      extern
#   else
#       define APS0APSCOREEXPORT
#       define APS0APSCOREGLOBAL       extern
#       define APS0APSCOREPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define APS0APSCOREEXPORT       __export(APS0APSCORE)
#       define APS0APSCOREGLOBAL       extern __global(APS0APSCORE)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define APS0APSCOREEXPORT      __declspec(dllimport)
#       define APS0APSCOREGLOBAL       extern __declspec(dllimport)
#   else
#       define APS0APSCOREEXPORT
#       define APS0APSCOREGLOBAL       extern
#   endif
#endif
