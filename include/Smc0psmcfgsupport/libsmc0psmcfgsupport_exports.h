//@<COPYRIGHT>@
//==================================================
//Copyright $2021.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//@<COPYRIGHT>@

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Smc0psmcfgsupport

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libSmc0psmcfgsupport

#if !defined(LIBSMC0PSMCFGSUPPORT) && !defined(IPLIB)
#   error IPLIB or LIBSMC0PSMCFGSUPPORT is not defined
#endif

/* Handwritten code should use SMC0PSMCFGSUPPORT_API, not SMC0PSMCFGSUPPORTEXPORT */

#define SMC0PSMCFGSUPPORT_API SMC0PSMCFGSUPPORTEXPORT

#if IPLIB==libSmc0psmcfgsupport || defined(LIBSMC0PSMCFGSUPPORT)
#   if defined(__lint)
#       define SMC0PSMCFGSUPPORTEXPORT       __export(Smc0psmcfgsupport)
#       define SMC0PSMCFGSUPPORTGLOBAL       extern __global(Smc0psmcfgsupport)
#       define SMC0PSMCFGSUPPORTPRIVATE      extern __private(Smc0psmcfgsupport)
#   elif defined(_WIN32)
#       define SMC0PSMCFGSUPPORTEXPORT       __declspec(dllexport)
#       define SMC0PSMCFGSUPPORTGLOBAL       extern __declspec(dllexport)
#       define SMC0PSMCFGSUPPORTPRIVATE      extern
#   else
#       define SMC0PSMCFGSUPPORTEXPORT
#       define SMC0PSMCFGSUPPORTGLOBAL       extern
#       define SMC0PSMCFGSUPPORTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define SMC0PSMCFGSUPPORTEXPORT       __export(Smc0psmcfgsupport)
#       define SMC0PSMCFGSUPPORTGLOBAL       extern __global(Smc0psmcfgsupport)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define SMC0PSMCFGSUPPORTEXPORT      __declspec(dllimport)
#       define SMC0PSMCFGSUPPORTGLOBAL       extern __declspec(dllimport)
#   else
#       define SMC0PSMCFGSUPPORTEXPORT
#       define SMC0PSMCFGSUPPORTGLOBAL       extern
#   endif
#endif
