//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2010.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  PnM0penetration

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libPnM0penetration

#if !defined(LIBPNM0PENETRATION) && !defined(IPLIB)
#   error IPLIB or LIBPNM0PENETRATION is not defined
#endif

/* Handwritten code should use PNM0PENETRATION_API, not PNM0PENETRATIONEXPORT */

#define PNM0PENETRATION_API PNM0PENETRATIONEXPORT

#if IPLIB==libPnM0penetration || defined(LIBPNM0PENETRATION)
#   if defined(__lint)
#       define PNM0PENETRATIONEXPORT       __export(PnM0penetration)
#       define PNM0PENETRATIONGLOBAL       extern __global(PnM0penetration)
#       define PNM0PENETRATIONPRIVATE      extern __private(PnM0penetration)
#   elif defined(_WIN32)
#       define PNM0PENETRATIONEXPORT       __declspec(dllexport)
#       define PNM0PENETRATIONGLOBAL       extern __declspec(dllexport)
#       define PNM0PENETRATIONPRIVATE      extern
#   else
#       define PNM0PENETRATIONEXPORT
#       define PNM0PENETRATIONGLOBAL       extern
#       define PNM0PENETRATIONPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define PNM0PENETRATIONEXPORT       __export(PnM0penetration)
#       define PNM0PENETRATIONGLOBAL       extern __global(PnM0penetration)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define PNM0PENETRATIONEXPORT      __declspec(dllimport)
#       define PNM0PENETRATIONGLOBAL       extern __declspec(dllimport)
#   else
#       define PNM0PENETRATIONEXPORT
#       define PNM0PENETRATIONGLOBAL       extern
#   endif
#endif
