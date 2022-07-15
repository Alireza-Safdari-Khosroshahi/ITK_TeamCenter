/*Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2019.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software*/

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Pma0automation

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libPma0automation

#if !defined(LIBPMA0AUTOMATION) && !defined(IPLIB)
#   error IPLIB or LIBPMA0AUTOMATION is not defined
#endif

/* Handwritten code should use PMA0AUTOMATION_API, not PMA0AUTOMATIONEXPORT */

#define PMA0AUTOMATION_API PMA0AUTOMATIONEXPORT

#if IPLIB==libPma0automation || defined(LIBPMA0AUTOMATION)
#   if defined(__lint)
#       define PMA0AUTOMATIONEXPORT       __export(Pma0automation)
#       define PMA0AUTOMATIONGLOBAL       extern __global(Pma0automation)
#       define PMA0AUTOMATIONPRIVATE      extern __private(Pma0automation)
#   elif defined(_WIN32)
#       define PMA0AUTOMATIONEXPORT       __declspec(dllexport)
#       define PMA0AUTOMATIONGLOBAL       extern __declspec(dllexport)
#       define PMA0AUTOMATIONPRIVATE      extern
#   else
#       define PMA0AUTOMATIONEXPORT
#       define PMA0AUTOMATIONGLOBAL       extern
#       define PMA0AUTOMATIONPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define PMA0AUTOMATIONEXPORT       __export(Pma0automation)
#       define PMA0AUTOMATIONGLOBAL       extern __global(Pma0automation)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define PMA0AUTOMATIONEXPORT      __declspec(dllimport)
#       define PMA0AUTOMATIONGLOBAL       extern __declspec(dllimport)
#   else
#       define PMA0AUTOMATIONEXPORT
#       define PMA0AUTOMATIONGLOBAL       extern
#   endif
#endif
