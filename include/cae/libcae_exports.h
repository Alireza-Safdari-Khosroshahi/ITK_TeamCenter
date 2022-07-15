/*HEAD LIBCAE_EXPORTS HHH CAE */
/*=============================================================================
                Copyright (c) 1999 Unigraphics Solutions Inc.
                             Unpublished - All rights reserved
===============================================================================
File Description:

     The header file that defines the export symbols for the
     CAE library

===============================================================================
Date          Name                   Description
09-May-2004   Charles Cheng          Initial creation
03-Jun-2004  chengc                  New release
$HISTORY$
============================================================================*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libcae

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use CAE_API, not CAEEXPORT */

#define CAE_API CAEEXPORT

/* Support CAEEXPORT for autogenerated schema/pif code only */

#if IPLIB==libcae
#   if defined(__lint)
#       define CAEEXPORT       __export(cae)
#       define CAEGLOBAL       extern __global(cae)
#       define CAEPRIVATE      extern __private(cae)
#   elif defined(_WIN32)
#       define CAEEXPORT       __declspec(dllexport)
#       define CAEGLOBAL       extern __declspec(dllexport)
#       define CAEPRIVATE      extern
#   else
#       define CAEEXPORT
#       define CAEGLOBAL       extern
#       define CAEPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CAEEXPORT       __export(cae)
#       define CAEGLOBAL       extern __global(cae)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CAEEXPORT      __declspec(dllimport)
#       define CAEGLOBAL       extern __declspec(dllimport)
#   else
#       define CAEEXPORT
#       define CAEGLOBAL       extern
#   endif
#endif

