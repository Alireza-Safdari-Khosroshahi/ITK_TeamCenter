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

#define EXPORTLIBRARY            libtcsoamodelpartitionmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOAPARTITIONMODELMNGD_API, not TCSOAPARTITIONMODELMNGDEXPORT */

#define TCSOAPARTITIONMODELMNGD_API TCSOAPARTITIONMODELMNGDEXPORT

/* Support TCSOAPARTITIONMODELMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoamodelpartitionmngd
#   if defined(__lint)
#       define TCSOAPARTITIONMODELMNGDEXPORT       __export(tcsoamodelpartitionmngd)
#       define TCSOAPARTITIONMODELMNGDGLOBAL       extern __global(tcsoamodelpartitionmngd)
#       define TCSOAPARTITIONMODELMNGDPRIVATE      extern __private(tcsoamodelpartitionmngd)
#   elif defined(_WIN32)
#       define TCSOAPARTITIONMODELMNGDEXPORT       __declspec(dllexport)
#       define TCSOAPARTITIONMODELMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOAPARTITIONMODELMNGDPRIVATE      extern
#   else
#       define TCSOAPARTITIONMODELMNGDEXPORT
#       define TCSOAPARTITIONMODELMNGDGLOBAL       extern
#       define TCSOAPARTITIONMODELMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOAPARTITIONMODELMNGDEXPORT       __export(tcsoamodelpartitionmngd)
#       define TCSOAPARTITIONMODELMNGDGLOBAL       extern __global(tcsoamodelpartitionmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOAPARTITIONMODELMNGDEXPORT      __declspec(dllimport)
#       define TCSOAPARTITIONMODELMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOAPARTITIONMODELMNGDEXPORT
#       define TCSOAPARTITIONMODELMNGDGLOBAL       extern
#   endif
#endif

