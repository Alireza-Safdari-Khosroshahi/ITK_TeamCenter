/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2016.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This file contains the export declarations for the library Fgc0cm4g

    This file should be obsoleted once the autogenerated version is created in out/meta/Fgc0cm4g folder.
    The autogenerated version will be generated after any metamodel operation is defined or overridden
    in the fgc0cm4g template.

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libFgc0cm4g

#if !defined(LIBFGC0CM4G) && !defined(IPLIB)
#   error IPLIB or LIBFGC0CM4G is not defined
#endif

/* Handwritten code should use FGC0CM4G_API, not FGC0CM4GEXPORT */

#define FGC0CM4G_API FGC0CM4GEXPORT

#if IPLIB==libFgc0cm4g || defined(LIBFGC0CM4G)
#   if defined(__lint)
#       define FGC0CM4GEXPORT       __export(Fgc0cm4g)
#       define FGC0CM4GGLOBAL       extern __global(Fgc0cm4g)
#       define FGC0CM4GPRIVATE      extern __private(Fgc0cm4g)
#   elif defined(_WIN32)
#       define FGC0CM4GEXPORT       __declspec(dllexport)
#       define FGC0CM4GGLOBAL       extern __declspec(dllexport)
#       define FGC0CM4GPRIVATE      extern
#   else
#       define FGC0CM4GEXPORT
#       define FGC0CM4GGLOBAL       extern
#       define FGC0CM4GPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define FGC0CM4GEXPORT       __export(Fgc0cm4g)
#       define FGC0CM4GGLOBAL       extern __global(Fgc0cm4g)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define FGC0CM4GEXPORT      __declspec(dllimport)
#       define FGC0CM4GGLOBAL       extern __declspec(dllimport)
#   else
#       define FGC0CM4GEXPORT
#       define FGC0CM4GGLOBAL       extern
#   endif
#endif