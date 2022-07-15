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

#define EXPORTLIBRARY            libtcsoamesstrongmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOAMESSTRONGMNGD_API, not TCSOAMESSTRONGMNGDEXPORT */

#define TCSOAMESSTRONGMNGD_API TCSOAMESSTRONGMNGDEXPORT

/* Support TCSOAMESSTRONGMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoamesstrongmngd
#   if defined(__lint)
#       define TCSOAMESSTRONGMNGDEXPORT       __export(tcsoamesstrongmngd)
#       define TCSOAMESSTRONGMNGDGLOBAL       extern __global(tcsoamesstrongmngd)
#       define TCSOAMESSTRONGMNGDPRIVATE      extern __private(tcsoamesstrongmngd)
#   elif defined(_WIN32)
#       define TCSOAMESSTRONGMNGDEXPORT       __declspec(dllexport)
#       define TCSOAMESSTRONGMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOAMESSTRONGMNGDPRIVATE      extern
#   else
#       define TCSOAMESSTRONGMNGDEXPORT
#       define TCSOAMESSTRONGMNGDGLOBAL       extern
#       define TCSOAMESSTRONGMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOAMESSTRONGMNGDEXPORT       __export(tcsoamesstrongmngd)
#       define TCSOAMESSTRONGMNGDGLOBAL       extern __global(tcsoamesstrongmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOAMESSTRONGMNGDEXPORT      __declspec(dllimport)
#       define TCSOAMESSTRONGMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOAMESSTRONGMNGDEXPORT
#       define TCSOAMESSTRONGMNGDGLOBAL       extern
#   endif
#endif

