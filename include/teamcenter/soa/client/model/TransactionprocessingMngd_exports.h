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

#define EXPORTLIBRARY            libtcsoamodeltransactionprocessingmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOATRANSACTIONPROCESSINGMODELMNGD_API, not TCSOATRANSACTIONPROCESSINGMODELMNGDEXPORT */

#define TCSOATRANSACTIONPROCESSINGMODELMNGD_API TCSOATRANSACTIONPROCESSINGMODELMNGDEXPORT

/* Support TCSOATRANSACTIONPROCESSINGMODELMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoamodeltransactionprocessingmngd
#   if defined(__lint)
#       define TCSOATRANSACTIONPROCESSINGMODELMNGDEXPORT       __export(tcsoamodeltransactionprocessingmngd)
#       define TCSOATRANSACTIONPROCESSINGMODELMNGDGLOBAL       extern __global(tcsoamodeltransactionprocessingmngd)
#       define TCSOATRANSACTIONPROCESSINGMODELMNGDPRIVATE      extern __private(tcsoamodeltransactionprocessingmngd)
#   elif defined(_WIN32)
#       define TCSOATRANSACTIONPROCESSINGMODELMNGDEXPORT       __declspec(dllexport)
#       define TCSOATRANSACTIONPROCESSINGMODELMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOATRANSACTIONPROCESSINGMODELMNGDPRIVATE      extern
#   else
#       define TCSOATRANSACTIONPROCESSINGMODELMNGDEXPORT
#       define TCSOATRANSACTIONPROCESSINGMODELMNGDGLOBAL       extern
#       define TCSOATRANSACTIONPROCESSINGMODELMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOATRANSACTIONPROCESSINGMODELMNGDEXPORT       __export(tcsoamodeltransactionprocessingmngd)
#       define TCSOATRANSACTIONPROCESSINGMODELMNGDGLOBAL       extern __global(tcsoamodeltransactionprocessingmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOATRANSACTIONPROCESSINGMODELMNGDEXPORT      __declspec(dllimport)
#       define TCSOATRANSACTIONPROCESSINGMODELMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOATRANSACTIONPROCESSINGMODELMNGDEXPORT
#       define TCSOATRANSACTIONPROCESSINGMODELMNGDGLOBAL       extern
#   endif
#endif
