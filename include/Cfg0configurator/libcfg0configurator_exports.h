//@<COPYRIGHT>@
//==================================================
//Copyright $2021.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//@<COPYRIGHT>@

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Cfg0configurator

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libCfg0configurator

#if !defined(LIBCFG0CONFIGURATOR) && !defined(IPLIB)
#   error IPLIB or LIBCFG0CONFIGURATOR is not defined
#endif

/* Handwritten code should use CFG0CONFIGURATOR_API, not CFG0CONFIGURATOREXPORT */

#define CFG0CONFIGURATOR_API CFG0CONFIGURATOREXPORT

#if IPLIB==libCfg0configurator || defined(LIBCFG0CONFIGURATOR)
#   if defined(__lint)
#       define CFG0CONFIGURATOREXPORT       __export(Cfg0configurator)
#       define CFG0CONFIGURATORGLOBAL       extern __global(Cfg0configurator)
#       define CFG0CONFIGURATORPRIVATE      extern __private(Cfg0configurator)
#   elif defined(_WIN32)
#       define CFG0CONFIGURATOREXPORT       __declspec(dllexport)
#       define CFG0CONFIGURATORGLOBAL       extern __declspec(dllexport)
#       define CFG0CONFIGURATORPRIVATE      extern
#   else
#       define CFG0CONFIGURATOREXPORT
#       define CFG0CONFIGURATORGLOBAL       extern
#       define CFG0CONFIGURATORPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CFG0CONFIGURATOREXPORT       __export(Cfg0configurator)
#       define CFG0CONFIGURATORGLOBAL       extern __global(Cfg0configurator)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CFG0CONFIGURATOREXPORT      __declspec(dllimport)
#       define CFG0CONFIGURATORGLOBAL       extern __declspec(dllimport)
#   else
#       define CFG0CONFIGURATOREXPORT
#       define CFG0CONFIGURATORGLOBAL       extern
#   endif
#endif
