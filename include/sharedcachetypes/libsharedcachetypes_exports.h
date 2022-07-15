/* 
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2010.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/
 
/** 
    @file 
 
    The header file that defines the export symbols for the libsharedcachetypestypes library
 
*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libsharedcachetypes

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use SHAREDCACHETYPES_API, not SHAREDCACHETYPESEXPORT */

#define SHAREDCACHETYPES_API SHAREDCACHETYPESEXPORT

/* Support SHAREDCACHETYPESEXPORT for autogenerated schema/pif code only */

#if IPLIB==libsharedcachetypes
#   if defined(__lint)
#       define SHAREDCACHETYPESEXPORT       __export(sharedcachetypes)
#       define SHAREDCACHETYPESGLOBAL       extern __global(sharedcachetypes)
#       define SHAREDCACHETYPESPRIVATE      extern __private(sharedcachetypes)
#   elif defined(_WIN32)
#       define SHAREDCACHETYPESEXPORT       __declspec(dllexport)
#       define SHAREDCACHETYPESGLOBAL       extern __declspec(dllexport)
#       define SHAREDCACHETYPESPRIVATE      extern
#   else
#       define SHAREDCACHETYPESEXPORT
#       define SHAREDCACHETYPESGLOBAL       extern
#       define SHAREDCACHETYPESPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define SHAREDCACHETYPESEXPORT       __export(sharedcachetypes)
#       define SHAREDCACHETYPESGLOBAL       extern __global(sharedcachetypes)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define SHAREDCACHETYPESEXPORT      __declspec(dllimport)
#       define SHAREDCACHETYPESGLOBAL       extern __declspec(dllimport)
#   else
#       define SHAREDCACHETYPESEXPORT
#       define SHAREDCACHETYPESGLOBAL       extern
#   endif
#endif

