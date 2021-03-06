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

#define EXPORTLIBRARY            libtcsoamodelcdm0contractmanagementmngd

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use TCSOACDM0CONTRACTMANAGEMENTMODELMNGD_API, not TCSOACDM0CONTRACTMANAGEMENTMODELMNGDEXPORT */

#define TCSOACDM0CONTRACTMANAGEMENTMODELMNGD_API TCSOACDM0CONTRACTMANAGEMENTMODELMNGDEXPORT

/* Support TCSOACDM0CONTRACTMANAGEMENTMODELMNGDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libtcsoamodelcdm0contractmanagementmngd
#   if defined(__lint)
#       define TCSOACDM0CONTRACTMANAGEMENTMODELMNGDEXPORT       __export(tcsoamodelcdm0contractmanagementmngd)
#       define TCSOACDM0CONTRACTMANAGEMENTMODELMNGDGLOBAL       extern __global(tcsoamodelcdm0contractmanagementmngd)
#       define TCSOACDM0CONTRACTMANAGEMENTMODELMNGDPRIVATE      extern __private(tcsoamodelcdm0contractmanagementmngd)
#   elif defined(_WIN32)
#       define TCSOACDM0CONTRACTMANAGEMENTMODELMNGDEXPORT       __declspec(dllexport)
#       define TCSOACDM0CONTRACTMANAGEMENTMODELMNGDGLOBAL       extern __declspec(dllexport)
#       define TCSOACDM0CONTRACTMANAGEMENTMODELMNGDPRIVATE      extern
#   else
#       define TCSOACDM0CONTRACTMANAGEMENTMODELMNGDEXPORT
#       define TCSOACDM0CONTRACTMANAGEMENTMODELMNGDGLOBAL       extern
#       define TCSOACDM0CONTRACTMANAGEMENTMODELMNGDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TCSOACDM0CONTRACTMANAGEMENTMODELMNGDEXPORT       __export(tcsoamodelcdm0contractmanagementmngd)
#       define TCSOACDM0CONTRACTMANAGEMENTMODELMNGDGLOBAL       extern __global(tcsoamodelcdm0contractmanagementmngd)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TCSOACDM0CONTRACTMANAGEMENTMODELMNGDEXPORT      __declspec(dllimport)
#       define TCSOACDM0CONTRACTMANAGEMENTMODELMNGDGLOBAL       extern __declspec(dllimport)
#   else
#       define TCSOACDM0CONTRACTMANAGEMENTMODELMNGDEXPORT
#       define TCSOACDM0CONTRACTMANAGEMENTMODELMNGDGLOBAL       extern
#   endif
#endif

