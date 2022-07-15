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

#define EXPORTLIBRARY            libtcsoamodelappmodelmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOAAPPMODELMODELMNGD_API, not TCSOAAPPMODELMODELMNGDEXPORT */

#define TCSOAAPPMODELMODELMNGD_API TCSOAAPPMODELMODELMNGDEXPORT

/* Support TCSOAAPPMODELMODELMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoamodelappmodelmngd
#   if defined(__lint)
#       define TCSOAAPPMODELMODELMNGDEXPORT       __export(tcsoamodelappmodelmngd)
#       define TCSOAAPPMODELMODELMNGDGLOBAL       extern __global(tcsoamodelappmodelmngd)
#       define TCSOAAPPMODELMODELMNGDPRIVATE      extern __private(tcsoamodelappmodelmngd)
#   elif defined(_WIN32)
#       define TCSOAAPPMODELMODELMNGDEXPORT       __declspec(dllexport)
#       define TCSOAAPPMODELMODELMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOAAPPMODELMODELMNGDPRIVATE      extern
#   else
#       define TCSOAAPPMODELMODELMNGDEXPORT
#       define TCSOAAPPMODELMODELMNGDGLOBAL       extern
#       define TCSOAAPPMODELMODELMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOAAPPMODELMODELMNGDEXPORT       __export(tcsoamodelappmodelmngd)
#       define TCSOAAPPMODELMODELMNGDGLOBAL       extern __global(tcsoamodelappmodelmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOAAPPMODELMODELMNGDEXPORT      __declspec(dllimport)
#       define TCSOAAPPMODELMODELMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOAAPPMODELMODELMNGDEXPORT
#       define TCSOAAPPMODELMODELMNGDGLOBAL       extern
#   endif
#endif

