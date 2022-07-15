// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2006 UGS Corp. All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@


/** 
    @libdocmgt_exports.h 
    Export defines for the Document Management library

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libdocmgt

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use DOCMGT_API, not DOCMGTEXPORT */
#define DOCMGT_API DOCMGTEXPORT

/* Support DOCMGTEXPORT for autogenerated code only */
#if IPLIB==libdocmgt
#   if defined(__lint)
#       define DOCMGTEXPORT       __export(docmgt)
#       define DOCMGTGLOBAL       extern __global(docmgt)
#       define DOCMGTPRIVATE      extern __private(docmgt)
#   elif defined(_WIN32)
#       define DOCMGTEXPORT       __declspec(dllexport)
#       define DOCMGTGLOBAL       extern __declspec(dllexport)
#       define DOCMGTPRIVATE      extern
#   else
#       define DOCMGTEXPORT
#       define DOCMGTGLOBAL       extern
#       define DOCMGTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define DOCMGTEXPORT       __export(docmgt)
#       define DOCMGTGLOBAL       extern __global(docmgt)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define DOCMGTEXPORT      __declspec(dllimport)
#       define DOCMGTGLOBAL       extern __declspec(dllimport)
#   else
#       define DOCMGTEXPORT
#       define DOCMGTGLOBAL       extern
#   endif
#endif