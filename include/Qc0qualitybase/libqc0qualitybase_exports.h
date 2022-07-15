//@<COPYRIGHT>@
//==================================================
//Copyright $2021.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//e
//==================================================
//@<COPYRIGHT>@

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Qc0qualitybase

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libQc0qualitybase

#if !defined(LIBQC0QUALITYBASE) && !defined(IPLIB)
#   error IPLIB or LIBQC0QUALITYBASE is not defined
#endif

/* Handwritten code should use QC0QUALITYBASE_API, not QC0QUALITYBASEEXPORT */

#define QC0QUALITYBASE_API QC0QUALITYBASEEXPORT

#if IPLIB==libQc0qualitybase || defined(LIBQC0QUALITYBASE)
#   if defined(__lint)
#       define QC0QUALITYBASEEXPORT       __export(Qc0qualitybase)
#       define QC0QUALITYBASEGLOBAL       extern __global(Qc0qualitybase)
#       define QC0QUALITYBASEPRIVATE      extern __private(Qc0qualitybase)
#   elif defined(_WIN32)
#       define QC0QUALITYBASEEXPORT       __declspec(dllexport)
#       define QC0QUALITYBASEGLOBAL       extern __declspec(dllexport)
#       define QC0QUALITYBASEPRIVATE      extern
#   else
#       define QC0QUALITYBASEEXPORT
#       define QC0QUALITYBASEGLOBAL       extern
#       define QC0QUALITYBASEPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define QC0QUALITYBASEEXPORT       __export(Qc0qualitybase)
#       define QC0QUALITYBASEGLOBAL       extern __global(Qc0qualitybase)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define QC0QUALITYBASEEXPORT      __declspec(dllimport)
#       define QC0QUALITYBASEGLOBAL       extern __declspec(dllimport)
#   else
#       define QC0QUALITYBASEEXPORT
#       define QC0QUALITYBASEGLOBAL       extern
#   endif
#endif
