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

#define EXPORTLIBRARY            libtcsoamodelcmtebopmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOACMTEBOPMODELMNGD_API, not TCSOACMTEBOPMODELMNGDEXPORT */

#define TCSOACMTEBOPMODELMNGD_API TCSOACMTEBOPMODELMNGDEXPORT

/* Support TCSOACMTEBOPMODELMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoamodelcmtebopmngd
#   if defined(__lint)
#       define TCSOACMTEBOPMODELMNGDEXPORT       __export(tcsoamodelcmtebopmngd)
#       define TCSOACMTEBOPMODELMNGDGLOBAL       extern __global(tcsoamodelcmtebopmngd)
#       define TCSOACMTEBOPMODELMNGDPRIVATE      extern __private(tcsoamodelcmtebopmngd)
#   elif defined(_WIN32)
#       define TCSOACMTEBOPMODELMNGDEXPORT       __declspec(dllexport)
#       define TCSOACMTEBOPMODELMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOACMTEBOPMODELMNGDPRIVATE      extern
#   else
#       define TCSOACMTEBOPMODELMNGDEXPORT
#       define TCSOACMTEBOPMODELMNGDGLOBAL       extern
#       define TCSOACMTEBOPMODELMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOACMTEBOPMODELMNGDEXPORT       __export(tcsoamodelcmtebopmngd)
#       define TCSOACMTEBOPMODELMNGDGLOBAL       extern __global(tcsoamodelcmtebopmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOACMTEBOPMODELMNGDEXPORT      __declspec(dllimport)
#       define TCSOACMTEBOPMODELMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOACMTEBOPMODELMNGDEXPORT
#       define TCSOACMTEBOPMODELMNGDGLOBAL       extern
#   endif
#endif

