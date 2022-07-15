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

#define EXPORTLIBRARY            libtcsoagdisstrongmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOAGDISSTRONGMNGD_API, not TCSOAGDISSTRONGMNGDEXPORT */

#define TCSOAGDISSTRONGMNGD_API TCSOAGDISSTRONGMNGDEXPORT

/* Support TCSOAGDISSTRONGMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoagdisstrongmngd
#   if defined(__lint)
#       define TCSOAGDISSTRONGMNGDEXPORT       __export(tcsoagdisstrongmngd)
#       define TCSOAGDISSTRONGMNGDGLOBAL       extern __global(tcsoagdisstrongmngd)
#       define TCSOAGDISSTRONGMNGDPRIVATE      extern __private(tcsoagdisstrongmngd)
#   elif defined(_WIN32)
#       define TCSOAGDISSTRONGMNGDEXPORT       __declspec(dllexport)
#       define TCSOAGDISSTRONGMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOAGDISSTRONGMNGDPRIVATE      extern
#   else
#       define TCSOAGDISSTRONGMNGDEXPORT
#       define TCSOAGDISSTRONGMNGDGLOBAL       extern
#       define TCSOAGDISSTRONGMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOAGDISSTRONGMNGDEXPORT       __export(tcsoagdisstrongmngd)
#       define TCSOAGDISSTRONGMNGDGLOBAL       extern __global(tcsoagdisstrongmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOAGDISSTRONGMNGDEXPORT      __declspec(dllimport)
#       define TCSOAGDISSTRONGMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOAGDISSTRONGMNGDEXPORT
#       define TCSOAGDISSTRONGMNGDGLOBAL       extern
#   endif
#endif
