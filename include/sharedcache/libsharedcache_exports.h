/*==============================================================================
                Copyright (c) 2010 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that defines the export symbols for the SharedCache library
 */

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libsharedcache

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use SHAREDCACHE_API, not SHAREDCACHEEXPORT */

#define SHAREDCACHE_API SHAREDCACHEEXPORT

/* Support SHAREDCACHEEXPORT for autogenerated schema/pif code only */

#if IPLIB==libsharedcache
#   if defined(__lint)
#       define SHAREDCACHEEXPORT       __export(sharedcache)
#       define SHAREDCACHEGLOBAL       extern __global(sharedcache)
#       define SHAREDCACHEPRIVATE      extern __private(sharedcache)
#   elif defined(_WIN32)
#       define SHAREDCACHEEXPORT       __declspec(dllexport)
#       define SHAREDCACHEGLOBAL       extern __declspec(dllexport)
#       define SHAREDCACHEPRIVATE      extern
#   else
#       define SHAREDCACHEEXPORT
#       define SHAREDCACHEGLOBAL       extern
#       define SHAREDCACHEPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define SHAREDCACHEEXPORT       __export(sharedcache)
#       define SHAREDCACHEGLOBAL       extern __global(sharedcache)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define SHAREDCACHEEXPORT      __declspec(dllimport)
#       define SHAREDCACHEGLOBAL       extern __declspec(dllimport)
#   else
#       define SHAREDCACHEEXPORT
#       define SHAREDCACHEGLOBAL       extern
#   endif
#endif

