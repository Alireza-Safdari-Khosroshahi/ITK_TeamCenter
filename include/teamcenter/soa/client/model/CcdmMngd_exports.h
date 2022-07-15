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

#define EXPORTLIBRARY            libtcsoamodelccdmmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOACCDMMODELMNGD_API, not TCSOACCDMMODELMNGDEXPORT */

#define TCSOACCDMMODELMNGD_API TCSOACCDMMODELMNGDEXPORT

/* Support TCSOACCDMMODELMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoamodelccdmmngd
#   if defined(__lint)
#       define TCSOACCDMMODELMNGDEXPORT       __export(tcsoamodelccdmmngd)
#       define TCSOACCDMMODELMNGDGLOBAL       extern __global(tcsoamodelccdmmngd)
#       define TCSOACCDMMODELMNGDPRIVATE      extern __private(tcsoamodelccdmmngd)
#   elif defined(_WIN32)
#       define TCSOACCDMMODELMNGDEXPORT       __declspec(dllexport)
#       define TCSOACCDMMODELMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOACCDMMODELMNGDPRIVATE      extern
#   else
#       define TCSOACCDMMODELMNGDEXPORT
#       define TCSOACCDMMODELMNGDGLOBAL       extern
#       define TCSOACCDMMODELMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOACCDMMODELMNGDEXPORT       __export(tcsoamodelccdmmngd)
#       define TCSOACCDMMODELMNGDGLOBAL       extern __global(tcsoamodelccdmmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOACCDMMODELMNGDEXPORT      __declspec(dllimport)
#       define TCSOACCDMMODELMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOACCDMMODELMNGDEXPORT
#       define TCSOACCDMMODELMNGDGLOBAL       extern
#   endif
#endif

