/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2015.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This file contains the declaration for the library srh0apsconfiguredsearch

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libsrh0apsconfiguredsearch

#if !defined(LIBSRH0APSCONFIGUREDSEARCH) && !defined(IPLIB)
#   error IPLIB or LIBSRH0APSCONFIGUREDSEARCH is not defined
#endif

/* Handwritten code should use SRH0APSCONFIGUREDSEARCH_API, not SRH0APSCONFIGUREDSEARCHEXPORT */

#define SRH0APSCONFIGUREDSEARCH_API SRH0APSCONFIGUREDSEARCHEXPORT

#if IPLIB==libsrh0apsconfiguredsearch || defined(LIBSRH0APSCONFIGUREDSEARCH)
#   if defined(__lint)
#       define SRH0APSCONFIGUREDSEARCHEXPORT       __export(srh0apsconfiguredsearch)
#       define SRH0APSCONFIGUREDSEARCHGLOBAL       extern __global(srh0apsconfiguredsearch)
#       define SRH0APSCONFIGUREDSEARCHPRIVATE      extern __private(srh0apsconfiguredsearch)
#   elif defined(_WIN32)
#       define SRH0APSCONFIGUREDSEARCHEXPORT       __declspec(dllexport)
#       define SRH0APSCONFIGUREDSEARCHGLOBAL       extern __declspec(dllexport)
#       define SRH0APSCONFIGUREDSEARCHPRIVATE      extern
#   else
#       define SRH0APSCONFIGUREDSEARCHEXPORT
#       define SRH0APSCONFIGUREDSEARCHGLOBAL       extern
#       define SRH0APSCONFIGUREDSEARCHPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define SRH0APSCONFIGUREDSEARCHEXPORT       __export(srh0apsconfiguredsearch)
#       define SRH0APSCONFIGUREDSEARCHGLOBAL       extern __global(srh0apsconfiguredsearch)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define SRH0APSCONFIGUREDSEARCHEXPORT      __declspec(dllimport)
#       define SRH0APSCONFIGUREDSEARCHGLOBAL       extern __declspec(dllimport)
#   else
#       define SRH0APSCONFIGUREDSEARCHEXPORT
#       define SRH0APSCONFIGUREDSEARCHGLOBAL       extern
#   endif
#endif
