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

#define EXPORTLIBRARY            libtcsoamodelrealizationmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOAREALIZATIONMODELMNGD_API, not TCSOAREALIZATIONMODELMNGDEXPORT */

#define TCSOAREALIZATIONMODELMNGD_API TCSOAREALIZATIONMODELMNGDEXPORT

/* Support TCSOAREALIZATIONMODELMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoamodelrealizationmngd
#   if defined(__lint)
#       define TCSOAREALIZATIONMODELMNGDEXPORT       __export(tcsoamodelrealizationmngd)
#       define TCSOAREALIZATIONMODELMNGDGLOBAL       extern __global(tcsoamodelrealizationmngd)
#       define TCSOAREALIZATIONMODELMNGDPRIVATE      extern __private(tcsoamodelrealizationmngd)
#   elif defined(_WIN32)
#       define TCSOAREALIZATIONMODELMNGDEXPORT       __declspec(dllexport)
#       define TCSOAREALIZATIONMODELMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOAREALIZATIONMODELMNGDPRIVATE      extern
#   else
#       define TCSOAREALIZATIONMODELMNGDEXPORT
#       define TCSOAREALIZATIONMODELMNGDGLOBAL       extern
#       define TCSOAREALIZATIONMODELMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOAREALIZATIONMODELMNGDEXPORT       __export(tcsoamodelrealizationmngd)
#       define TCSOAREALIZATIONMODELMNGDGLOBAL       extern __global(tcsoamodelrealizationmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOAREALIZATIONMODELMNGDEXPORT      __declspec(dllimport)
#       define TCSOAREALIZATIONMODELMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOAREALIZATIONMODELMNGDEXPORT
#       define TCSOAREALIZATIONMODELMNGDGLOBAL       extern
#   endif
#endif
