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

#define EXPORTLIBRARY            libtcsoamultisitestrongmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOAMULTISITESTRONGMNGD_API, not TCSOAMULTISITESTRONGMNGDEXPORT */

#define TCSOAMULTISITESTRONGMNGD_API TCSOAMULTISITESTRONGMNGDEXPORT

/* Support TCSOAMULTISITESTRONGMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoamultisitestrongmngd
#   if defined(__lint)
#       define TCSOAMULTISITESTRONGMNGDEXPORT       __export(tcsoamultisitestrongmngd)
#       define TCSOAMULTISITESTRONGMNGDGLOBAL       extern __global(tcsoamultisitestrongmngd)
#       define TCSOAMULTISITESTRONGMNGDPRIVATE      extern __private(tcsoamultisitestrongmngd)
#   elif defined(_WIN32)
#       define TCSOAMULTISITESTRONGMNGDEXPORT       __declspec(dllexport)
#       define TCSOAMULTISITESTRONGMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOAMULTISITESTRONGMNGDPRIVATE      extern
#   else
#       define TCSOAMULTISITESTRONGMNGDEXPORT
#       define TCSOAMULTISITESTRONGMNGDGLOBAL       extern
#       define TCSOAMULTISITESTRONGMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOAMULTISITESTRONGMNGDEXPORT       __export(tcsoamultisitestrongmngd)
#       define TCSOAMULTISITESTRONGMNGDGLOBAL       extern __global(tcsoamultisitestrongmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOAMULTISITESTRONGMNGDEXPORT      __declspec(dllimport)
#       define TCSOAMULTISITESTRONGMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOAMULTISITESTRONGMNGDEXPORT
#       define TCSOAMULTISITESTRONGMNGDGLOBAL       extern
#   endif
#endif
