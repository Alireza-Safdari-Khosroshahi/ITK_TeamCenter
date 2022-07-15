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

#define EXPORTLIBRARY            libtcsoamodelproductvariantmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOAPRODUCTVARIANTMODELMNGD_API, not TCSOAPRODUCTVARIANTMODELMNGDEXPORT */

#define TCSOAPRODUCTVARIANTMODELMNGD_API TCSOAPRODUCTVARIANTMODELMNGDEXPORT

/* Support TCSOAPRODUCTVARIANTMODELMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoamodelproductvariantmngd
#   if defined(__lint)
#       define TCSOAPRODUCTVARIANTMODELMNGDEXPORT       __export(tcsoamodelproductvariantmngd)
#       define TCSOAPRODUCTVARIANTMODELMNGDGLOBAL       extern __global(tcsoamodelproductvariantmngd)
#       define TCSOAPRODUCTVARIANTMODELMNGDPRIVATE      extern __private(tcsoamodelproductvariantmngd)
#   elif defined(_WIN32)
#       define TCSOAPRODUCTVARIANTMODELMNGDEXPORT       __declspec(dllexport)
#       define TCSOAPRODUCTVARIANTMODELMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOAPRODUCTVARIANTMODELMNGDPRIVATE      extern
#   else
#       define TCSOAPRODUCTVARIANTMODELMNGDEXPORT
#       define TCSOAPRODUCTVARIANTMODELMNGDGLOBAL       extern
#       define TCSOAPRODUCTVARIANTMODELMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOAPRODUCTVARIANTMODELMNGDEXPORT       __export(tcsoamodelproductvariantmngd)
#       define TCSOAPRODUCTVARIANTMODELMNGDGLOBAL       extern __global(tcsoamodelproductvariantmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOAPRODUCTVARIANTMODELMNGDEXPORT      __declspec(dllimport)
#       define TCSOAPRODUCTVARIANTMODELMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOAPRODUCTVARIANTMODELMNGDEXPORT
#       define TCSOAPRODUCTVARIANTMODELMNGDGLOBAL       extern
#   endif
#endif
