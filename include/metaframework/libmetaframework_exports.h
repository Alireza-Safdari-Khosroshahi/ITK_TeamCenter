// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2007 UGS Corp. All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@


#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libmetaframework

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use METAFRAMEWORK_API, not METAFRAMEWORKEXPORT */

#define METAFRAMEWORK_API METAFRAMEWORKEXPORT

/* Support METAFRAMEWORKEXPORT for autogenerated schema/pif code only */

#if IPLIB==libmetaframework
#   if defined(__lint)
#       define METAFRAMEWORKEXPORT       __export(metaframework)
#       define METAFRAMEWORKGLOBAL       extern __global(metaframework)
#       define METAFRAMEWORKPRIVATE      extern __private(metaframework)
#   elif defined(_WIN32)
#       define METAFRAMEWORKEXPORT       __declspec(dllexport)
#       define METAFRAMEWORKGLOBAL       extern __declspec(dllexport)
#       define METAFRAMEWORKPRIVATE      extern
#   else
#       define METAFRAMEWORKEXPORT
#       define METAFRAMEWORKGLOBAL       extern
#       define METAFRAMEWORKPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define METAFRAMEWORKEXPORT       __export(metaframework)
#       define METAFRAMEWORKGLOBAL       extern __global(metaframework)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define METAFRAMEWORKEXPORT      __declspec(dllimport)
#       define METAFRAMEWORKGLOBAL       extern __declspec(dllimport)
#   else
#       define METAFRAMEWORKEXPORT
#       define METAFRAMEWORKGLOBAL       extern
#   endif
#endif
