/*
//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2015.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software
*/
/**
    @file

    This file contains the declaration for the Library diagramming

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libDia0diagramming

#if !defined(LIBDIA0DIAGRAMMING) && !defined(IPLIB)
#   error IPLIB or LIBMDC0MDC is not defined
#endif

/* Handwritten code should use DIA0DIAGRAMMING_API, not DIA0DIAGRAMMINGEXPORT */

#define DIA0DIAGRAMMING_API DIA0DIAGRAMMINGEXPORT

#if IPLIB==libDia0diagramming || defined(LIBDIA0DIAGRAMMING)
#   if defined(__lint)
#       define DIA0DIAGRAMMINGEXPORT       __export(Dia0diagramming)
#       define DIA0DIAGRAMMINGGLOBAL       extern __global(Dia0diagramming)
#       define DIA0DIAGRAMMINGPRIVATE      extern __private(Dia0diagramming)
#   elif defined(_WIN32)
#       define DIA0DIAGRAMMINGEXPORT       __declspec(dllexport)
#       define DIA0DIAGRAMMINGGLOBAL       extern __declspec(dllexport)
#       define DIA0DIAGRAMMINGPRIVATE      extern
#   else
#       define DIA0DIAGRAMMINGEXPORT
#       define DIA0DIAGRAMMINGGLOBAL       extern
#       define DIA0DIAGRAMMINGPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define DIA0DIAGRAMMINGEXPORT       __export(Dia0diagramming)
#       define DIA0DIAGRAMMINGGLOBAL       extern __global(Dia0diagramming)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define DIA0DIAGRAMMINGEXPORT      __declspec(dllimport)
#       define DIA0DIAGRAMMINGGLOBAL       extern __declspec(dllimport)
#   else
#       define DIA0DIAGRAMMINGEXPORT
#       define DIA0DIAGRAMMINGGLOBAL       extern
#   endif
#endif
