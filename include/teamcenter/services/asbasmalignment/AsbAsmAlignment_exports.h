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

#define EXPORTLIBRARY            libtcsoaasbasmalignmentstrongmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOAASBASMALIGNMENTSTRONGMNGD_API, not TCSOAASBASMALIGNMENTSTRONGMNGDEXPORT */

#define TCSOAASBASMALIGNMENTSTRONGMNGD_API TCSOAASBASMALIGNMENTSTRONGMNGDEXPORT

/* Support TCSOAASBASMALIGNMENTSTRONGMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoaasbasmalignmentstrongmngd
#   if defined(__lint)
#       define TCSOAASBASMALIGNMENTSTRONGMNGDEXPORT       __export(tcsoaasbasmalignmentstrongmngd)
#       define TCSOAASBASMALIGNMENTSTRONGMNGDGLOBAL       extern __global(tcsoaasbasmalignmentstrongmngd)
#       define TCSOAASBASMALIGNMENTSTRONGMNGDPRIVATE      extern __private(tcsoaasbasmalignmentstrongmngd)
#   elif defined(_WIN32)
#       define TCSOAASBASMALIGNMENTSTRONGMNGDEXPORT       __declspec(dllexport)
#       define TCSOAASBASMALIGNMENTSTRONGMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOAASBASMALIGNMENTSTRONGMNGDPRIVATE      extern
#   else
#       define TCSOAASBASMALIGNMENTSTRONGMNGDEXPORT
#       define TCSOAASBASMALIGNMENTSTRONGMNGDGLOBAL       extern
#       define TCSOAASBASMALIGNMENTSTRONGMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOAASBASMALIGNMENTSTRONGMNGDEXPORT       __export(tcsoaasbasmalignmentstrongmngd)
#       define TCSOAASBASMALIGNMENTSTRONGMNGDGLOBAL       extern __global(tcsoaasbasmalignmentstrongmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOAASBASMALIGNMENTSTRONGMNGDEXPORT      __declspec(dllimport)
#       define TCSOAASBASMALIGNMENTSTRONGMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOAASBASMALIGNMENTSTRONGMNGDEXPORT
#       define TCSOAASBASMALIGNMENTSTRONGMNGDGLOBAL       extern
#   endif
#endif

