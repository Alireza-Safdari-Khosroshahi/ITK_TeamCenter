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

#define EXPORTLIBRARY            libtcsoamodelcpdcmmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOACPDCMMODELMNGD_API, not TCSOACPDCMMODELMNGDEXPORT */

#define TCSOACPDCMMODELMNGD_API TCSOACPDCMMODELMNGDEXPORT

/* Support TCSOACPDCMMODELMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoamodelcpdcmmngd
#   if defined(__lint)
#       define TCSOACPDCMMODELMNGDEXPORT       __export(tcsoamodelcpdcmmngd)
#       define TCSOACPDCMMODELMNGDGLOBAL       extern __global(tcsoamodelcpdcmmngd)
#       define TCSOACPDCMMODELMNGDPRIVATE      extern __private(tcsoamodelcpdcmmngd)
#   elif defined(_WIN32)
#       define TCSOACPDCMMODELMNGDEXPORT       __declspec(dllexport)
#       define TCSOACPDCMMODELMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOACPDCMMODELMNGDPRIVATE      extern
#   else
#       define TCSOACPDCMMODELMNGDEXPORT
#       define TCSOACPDCMMODELMNGDGLOBAL       extern
#       define TCSOACPDCMMODELMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOACPDCMMODELMNGDEXPORT       __export(tcsoamodelcpdcmmngd)
#       define TCSOACPDCMMODELMNGDGLOBAL       extern __global(tcsoamodelcpdcmmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOACPDCMMODELMNGDEXPORT      __declspec(dllimport)
#       define TCSOACPDCMMODELMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOACPDCMMODELMNGDEXPORT
#       define TCSOACPDCMMODELMNGDGLOBAL       extern
#   endif
#endif

