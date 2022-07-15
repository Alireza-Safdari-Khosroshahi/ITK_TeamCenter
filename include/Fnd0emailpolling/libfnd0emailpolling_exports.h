/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2014.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file libfnd0emailpolling_exports.h

    The header file that defines the export symbols for the fnd0emailpolling library.
*/


/*  */

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libfnd0emailpolling

#if !defined(LIBFND0EMAILPOLLING) && !defined(IPLIB)
#   error IPLIB or LIBFND0EMAILPOLLING is not defined
#endif

/* Handwritten code should use FND0EMAILPOLLING_API, not FND0EMAILPOLLINGEXPORT */

#define FND0EMAILPOLLING_API FND0EMAILPOLLINGEXPORT

#if IPLIB==libfnd0emailpolling || defined(LIBFND0EMAILPOLLING)
#   if defined(__lint)
#       define FND0EMAILPOLLINGEXPORT       __export(fnd0emailpolling)
#       define FND0EMAILPOLLINGGLOBAL       extern __global(fnd0emailpolling)
#       define FND0EMAILPOLLINGPRIVATE      extern __private(fnd0emailpolling)
#   elif defined(_WIN32)
#       define FND0EMAILPOLLINGEXPORT       __declspec(dllexport)
#       define FND0EMAILPOLLINGGLOBAL       extern __declspec(dllexport)
#       define FND0EMAILPOLLINGPRIVATE      extern
#   else
#       define FND0EMAILPOLLINGEXPORT
#       define FND0EMAILPOLLINGGLOBAL       extern
#       define FND0EMAILPOLLINGPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define FND0EMAILPOLLINGEXPORT       __export(fnd0emailpolling)
#       define FND0EMAILPOLLINGGLOBAL       extern __global(fnd0emailpolling)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define FND0EMAILPOLLINGEXPORT      __declspec(dllimport)
#       define FND0EMAILPOLLINGGLOBAL       extern __declspec(dllimport)
#   else
#       define FND0EMAILPOLLINGEXPORT
#       define FND0EMAILPOLLINGGLOBAL       extern
#   endif
#endif
