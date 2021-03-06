/*==============================================================================
                Copyright (c) 2009-2010 SIEMENS
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    @file
    The header file that defines the export symbols for the PS library
 */

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libbooleanmath

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use BOOLEANMATH_API, not BOOLEANMATHEXPORT */

#define BOOLEANMATH_API BOOLEANMATHEXPORT

/* Support BOOLEANMATHEXPORT for autogenerated schema/pif code only */

#if IPLIB==libbooleanmath
#   if defined(__lint)
#       define BOOLEANMATHEXPORT       __export(booleanmath)
#       define BOOLEANMATHGLOBAL       extern __global(booleanmath)
#       define BOOLEANMATHPRIVATE      extern __private(booleanmath)
#   elif defined(_WIN32)
#       define BOOLEANMATHEXPORT       __declspec(dllexport)
#       define BOOLEANMATHGLOBAL       extern __declspec(dllexport)
#       define BOOLEANMATHPRIVATE      extern
#   else
#       define BOOLEANMATHEXPORT
#       define BOOLEANMATHGLOBAL       extern
#       define BOOLEANMATHPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define BOOLEANMATHEXPORT       __export(booleanmath)
#       define BOOLEANMATHGLOBAL       extern __global(booleanmath)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define BOOLEANMATHEXPORT      __declspec(dllimport)
#       define BOOLEANMATHGLOBAL       extern __declspec(dllimport)
#   else
#       define BOOLEANMATHEXPORT
#       define BOOLEANMATHGLOBAL       extern
#   endif
#endif


