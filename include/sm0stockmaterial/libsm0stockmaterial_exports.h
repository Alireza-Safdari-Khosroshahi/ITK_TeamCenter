//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  sm0stockmaterial

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libsm0stockmaterial

#if !defined(LIBSM0STOCKMATERIAL) && !defined(IPLIB)
#   error IPLIB or LIBSM0STOCKMATERIAL is not defined
#endif

/* Handwritten code should use SM0STOCKMATERIAL_API, not SM0STOCKMATERIALEXPORT */

#define SM0STOCKMATERIAL_API SM0STOCKMATERIALEXPORT

#if IPLIB==libsm0stockmaterial || defined(LIBSM0STOCKMATERIAL)
#   if defined(__lint)
#       define SM0STOCKMATERIALEXPORT       __export(sm0stockmaterial)
#       define SM0STOCKMATERIALGLOBAL       extern __global(sm0stockmaterial)
#       define SM0STOCKMATERIALPRIVATE      extern __private(sm0stockmaterial)
#   elif defined(_WIN32)
#       define SM0STOCKMATERIALEXPORT       __declspec(dllexport)
#       define SM0STOCKMATERIALGLOBAL       extern __declspec(dllexport)
#       define SM0STOCKMATERIALPRIVATE      extern
#   else
#       define SM0STOCKMATERIALEXPORT
#       define SM0STOCKMATERIALGLOBAL       extern
#       define SM0STOCKMATERIALPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define SM0STOCKMATERIALEXPORT       __export(sm0stockmaterial)
#       define SM0STOCKMATERIALGLOBAL       extern __global(sm0stockmaterial)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define SM0STOCKMATERIALEXPORT      __declspec(dllimport)
#       define SM0STOCKMATERIALGLOBAL       extern __declspec(dllimport)
#   else
#       define SM0STOCKMATERIALEXPORT
#       define SM0STOCKMATERIALGLOBAL       extern
#   endif
#endif
