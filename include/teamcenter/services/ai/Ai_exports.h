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

#define EXPORTLIBRARY            libtcsoaaistrongmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOAAISTRONGMNGD_API, not TCSOAAISTRONGMNGDEXPORT */

#define TCSOAAISTRONGMNGD_API TCSOAAISTRONGMNGDEXPORT

/* Support TCSOAAISTRONGMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoaaistrongmngd
#   if defined(__lint)
#       define TCSOAAISTRONGMNGDEXPORT       __export(tcsoaaistrongmngd)
#       define TCSOAAISTRONGMNGDGLOBAL       extern __global(tcsoaaistrongmngd)
#       define TCSOAAISTRONGMNGDPRIVATE      extern __private(tcsoaaistrongmngd)
#   elif defined(_WIN32)
#       define TCSOAAISTRONGMNGDEXPORT       __declspec(dllexport)
#       define TCSOAAISTRONGMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOAAISTRONGMNGDPRIVATE      extern
#   else
#       define TCSOAAISTRONGMNGDEXPORT
#       define TCSOAAISTRONGMNGDGLOBAL       extern
#       define TCSOAAISTRONGMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOAAISTRONGMNGDEXPORT       __export(tcsoaaistrongmngd)
#       define TCSOAAISTRONGMNGDGLOBAL       extern __global(tcsoaaistrongmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOAAISTRONGMNGDEXPORT      __declspec(dllimport)
#       define TCSOAAISTRONGMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOAAISTRONGMNGDEXPORT
#       define TCSOAAISTRONGMNGDGLOBAL       extern
#   endif
#endif

