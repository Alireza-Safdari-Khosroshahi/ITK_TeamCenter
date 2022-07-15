/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libtcsoaconfigurationstrongmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOACONFIGURATIONSTRONGMNGD_API, not TCSOACONFIGURATIONSTRONGMNGDEXPORT */

#define TCSOACONFIGURATIONSTRONGMNGD_API TCSOACONFIGURATIONSTRONGMNGDEXPORT

/* Support TCSOACONFIGURATIONSTRONGMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoaconfigurationstrongmngd
#   if defined(__lint)
#       define TCSOACONFIGURATIONSTRONGMNGDEXPORT       __export(tcsoaconfigurationstrongmngd)
#       define TCSOACONFIGURATIONSTRONGMNGDGLOBAL       extern __global(tcsoaconfigurationstrongmngd)
#       define TCSOACONFIGURATIONSTRONGMNGDPRIVATE      extern __private(tcsoaconfigurationstrongmngd)
#   elif defined(_WIN32)
#       define TCSOACONFIGURATIONSTRONGMNGDEXPORT       __declspec(dllexport)
#       define TCSOACONFIGURATIONSTRONGMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOACONFIGURATIONSTRONGMNGDPRIVATE      extern
#   else
#       define TCSOACONFIGURATIONSTRONGMNGDEXPORT
#       define TCSOACONFIGURATIONSTRONGMNGDGLOBAL       extern
#       define TCSOACONFIGURATIONSTRONGMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOACONFIGURATIONSTRONGMNGDEXPORT       __export(tcsoaconfigurationstrongmngd)
#       define TCSOACONFIGURATIONSTRONGMNGDGLOBAL       extern __global(tcsoaconfigurationstrongmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOACONFIGURATIONSTRONGMNGDEXPORT      __declspec(dllimport)
#       define TCSOACONFIGURATIONSTRONGMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOACONFIGURATIONSTRONGMNGDEXPORT
#       define TCSOACONFIGURATIONSTRONGMNGDGLOBAL       extern
#   endif
#endif
