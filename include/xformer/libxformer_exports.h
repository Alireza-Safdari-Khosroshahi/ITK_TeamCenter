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

    The header file that defines the export symbols for the XFORMER library

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libxformer

#if !defined(LIBXFORMER) && !defined(IPLIB)
#   error IPLIB or LIBXFORMER is not defined
#endif

/* Handwritten code should use XFORMER_API, not XFORMEREXPORT */

#define XFORMER_API XFORMEREXPORT

#if IPLIB==libxformer || defined(LIBXFORMER)
#   if defined(__lint)
#       define XFORMEREXPORT       __export(xformer)
#       define XFORMERGLOBAL       extern __global(xformer)
#       define XFORMERPRIVATE      extern __private(xformer)
#   elif defined(_WIN32)
#       define XFORMEREXPORT       __declspec(dllexport)
#       define XFORMERGLOBAL       extern __declspec(dllexport)
#       define XFORMERPRIVATE      extern
#   else
#       define XFORMEREXPORT
#       define XFORMERGLOBAL       extern
#       define XFORMERPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define XFORMEREXPORT       __export(xformer)
#       define XFORMERGLOBAL       extern __global(xformer)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define XFORMEREXPORT      __declspec(dllimport)
#       define XFORMERGLOBAL       extern __declspec(dllimport)
#   else
#       define XFORMEREXPORT
#       define XFORMERGLOBAL       extern
#   endif
#endif
