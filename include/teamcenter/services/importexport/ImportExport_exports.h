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

#define EXPORTLIBRARY            libtcsoaimportexportstrongmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOAIMPORTEXPORTSTRONGMNGD_API, not TCSOAIMPORTEXPORTSTRONGMNGDEXPORT */

#define TCSOAIMPORTEXPORTSTRONGMNGD_API TCSOAIMPORTEXPORTSTRONGMNGDEXPORT

/* Support TCSOAIMPORTEXPORTSTRONGMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoaimportexportstrongmngd
#   if defined(__lint)
#       define TCSOAIMPORTEXPORTSTRONGMNGDEXPORT       __export(tcsoaimportexportstrongmngd)
#       define TCSOAIMPORTEXPORTSTRONGMNGDGLOBAL       extern __global(tcsoaimportexportstrongmngd)
#       define TCSOAIMPORTEXPORTSTRONGMNGDPRIVATE      extern __private(tcsoaimportexportstrongmngd)
#   elif defined(_WIN32)
#       define TCSOAIMPORTEXPORTSTRONGMNGDEXPORT       __declspec(dllexport)
#       define TCSOAIMPORTEXPORTSTRONGMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOAIMPORTEXPORTSTRONGMNGDPRIVATE      extern
#   else
#       define TCSOAIMPORTEXPORTSTRONGMNGDEXPORT
#       define TCSOAIMPORTEXPORTSTRONGMNGDGLOBAL       extern
#       define TCSOAIMPORTEXPORTSTRONGMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOAIMPORTEXPORTSTRONGMNGDEXPORT       __export(tcsoaimportexportstrongmngd)
#       define TCSOAIMPORTEXPORTSTRONGMNGDGLOBAL       extern __global(tcsoaimportexportstrongmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOAIMPORTEXPORTSTRONGMNGDEXPORT      __declspec(dllimport)
#       define TCSOAIMPORTEXPORTSTRONGMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOAIMPORTEXPORTSTRONGMNGDEXPORT
#       define TCSOAIMPORTEXPORTSTRONGMNGDGLOBAL       extern
#   endif
#endif
