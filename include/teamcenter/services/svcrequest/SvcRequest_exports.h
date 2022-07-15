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

#define EXPORTLIBRARY            libtcsoasvcrequeststrongmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOASVCREQUESTSTRONGMNGD_API, not TCSOASVCREQUESTSTRONGMNGDEXPORT */

#define TCSOASVCREQUESTSTRONGMNGD_API TCSOASVCREQUESTSTRONGMNGDEXPORT

/* Support TCSOASVCREQUESTSTRONGMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoasvcrequeststrongmngd
#   if defined(__lint)
#       define TCSOASVCREQUESTSTRONGMNGDEXPORT       __export(tcsoasvcrequeststrongmngd)
#       define TCSOASVCREQUESTSTRONGMNGDGLOBAL       extern __global(tcsoasvcrequeststrongmngd)
#       define TCSOASVCREQUESTSTRONGMNGDPRIVATE      extern __private(tcsoasvcrequeststrongmngd)
#   elif defined(_WIN32)
#       define TCSOASVCREQUESTSTRONGMNGDEXPORT       __declspec(dllexport)
#       define TCSOASVCREQUESTSTRONGMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOASVCREQUESTSTRONGMNGDPRIVATE      extern
#   else
#       define TCSOASVCREQUESTSTRONGMNGDEXPORT
#       define TCSOASVCREQUESTSTRONGMNGDGLOBAL       extern
#       define TCSOASVCREQUESTSTRONGMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOASVCREQUESTSTRONGMNGDEXPORT       __export(tcsoasvcrequeststrongmngd)
#       define TCSOASVCREQUESTSTRONGMNGDGLOBAL       extern __global(tcsoasvcrequeststrongmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOASVCREQUESTSTRONGMNGDEXPORT      __declspec(dllimport)
#       define TCSOASVCREQUESTSTRONGMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOASVCREQUESTSTRONGMNGDEXPORT
#       define TCSOASVCREQUESTSTRONGMNGDGLOBAL       extern
#   endif
#endif

