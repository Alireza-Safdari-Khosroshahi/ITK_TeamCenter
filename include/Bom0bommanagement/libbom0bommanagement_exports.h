//@<COPYRIGHT>@
//==================================================
//Copyright $2021.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//@<COPYRIGHT>@

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Bom0bommanagement

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libBom0bommanagement

#if !defined(LIBBOM0BOMMANAGEMENT) && !defined(IPLIB)
#   error IPLIB or LIBBOM0BOMMANAGEMENT is not defined
#endif

/* Handwritten code should use BOM0BOMMANAGEMENT_API, not BOM0BOMMANAGEMENTEXPORT */

#define BOM0BOMMANAGEMENT_API BOM0BOMMANAGEMENTEXPORT

#if IPLIB==libBom0bommanagement || defined(LIBBOM0BOMMANAGEMENT)
#   if defined(__lint)
#       define BOM0BOMMANAGEMENTEXPORT       __export(Bom0bommanagement)
#       define BOM0BOMMANAGEMENTGLOBAL       extern __global(Bom0bommanagement)
#       define BOM0BOMMANAGEMENTPRIVATE      extern __private(Bom0bommanagement)
#   elif defined(_WIN32)
#       define BOM0BOMMANAGEMENTEXPORT       __declspec(dllexport)
#       define BOM0BOMMANAGEMENTGLOBAL       extern __declspec(dllexport)
#       define BOM0BOMMANAGEMENTPRIVATE      extern
#   else
#       define BOM0BOMMANAGEMENTEXPORT
#       define BOM0BOMMANAGEMENTGLOBAL       extern
#       define BOM0BOMMANAGEMENTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define BOM0BOMMANAGEMENTEXPORT       __export(Bom0bommanagement)
#       define BOM0BOMMANAGEMENTGLOBAL       extern __global(Bom0bommanagement)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define BOM0BOMMANAGEMENTEXPORT      __declspec(dllimport)
#       define BOM0BOMMANAGEMENTGLOBAL       extern __declspec(dllimport)
#   else
#       define BOM0BOMMANAGEMENTEXPORT
#       define BOM0BOMMANAGEMENTGLOBAL       extern
#   endif
#endif
