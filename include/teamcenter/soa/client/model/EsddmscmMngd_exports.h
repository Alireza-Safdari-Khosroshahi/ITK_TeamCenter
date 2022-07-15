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

#define EXPORTLIBRARY            libtcsoamodelesddmscmmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOAESDDMSCMMODELMNGD_API, not TCSOAESDDMSCMMODELMNGDEXPORT */

#define TCSOAESDDMSCMMODELMNGD_API TCSOAESDDMSCMMODELMNGDEXPORT

/* Support TCSOAESDDMSCMMODELMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoamodelesddmscmmngd
#   if defined(__lint)
#       define TCSOAESDDMSCMMODELMNGDEXPORT       __export(tcsoamodelesddmscmmngd)
#       define TCSOAESDDMSCMMODELMNGDGLOBAL       extern __global(tcsoamodelesddmscmmngd)
#       define TCSOAESDDMSCMMODELMNGDPRIVATE      extern __private(tcsoamodelesddmscmmngd)
#   elif defined(_WIN32)
#       define TCSOAESDDMSCMMODELMNGDEXPORT       __declspec(dllexport)
#       define TCSOAESDDMSCMMODELMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOAESDDMSCMMODELMNGDPRIVATE      extern
#   else
#       define TCSOAESDDMSCMMODELMNGDEXPORT
#       define TCSOAESDDMSCMMODELMNGDGLOBAL       extern
#       define TCSOAESDDMSCMMODELMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOAESDDMSCMMODELMNGDEXPORT       __export(tcsoamodelesddmscmmngd)
#       define TCSOAESDDMSCMMODELMNGDGLOBAL       extern __global(tcsoamodelesddmscmmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOAESDDMSCMMODELMNGDEXPORT      __declspec(dllimport)
#       define TCSOAESDDMSCMMODELMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOAESDDMSCMMODELMNGDEXPORT
#       define TCSOAESDDMSCMMODELMNGDGLOBAL       extern
#   endif
#endif

