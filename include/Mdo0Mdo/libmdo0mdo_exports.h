//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Mdo0 exports

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libMdo0Mdo

#if !defined(LIBMDO0MDO) && !defined(IPLIB)
#   error IPLIB or LIBMDO0MDO is not defined
#endif

/* Handwritten code should use MDO0MDO_API, not MDO0MDOEXPORT */

#define MDO0MDO_API MDO0MDOEXPORT

#if IPLIB==libMdo0Mdo || defined(LIBMDO0MDO)
#   if defined(__lint)
#       define MDO0MDOEXPORT       __export(Mdo0Mdo)
#       define MDO0MDOGLOBAL       extern __global(Mdo0Mdo)
#       define MDO0MDOPRIVATE      extern __private(Mdo0Mdo)
#   elif defined(_WIN32)
#       define MDO0MDOEXPORT       __declspec(dllexport)
#       define MDO0MDOGLOBAL       extern __declspec(dllexport)
#       define MDO0MDOPRIVATE      extern
#   else
#       define MDO0MDOEXPORT
#       define MDO0MDOGLOBAL       extern
#       define MDO0MDOPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define MDO0MDOEXPORT       __export(Mdo0Mdo)
#       define MDO0MDOGLOBAL       extern __global(Mdo0Mdo)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define MDO0MDOEXPORT      __declspec(dllimport)
#       define MDO0MDOGLOBAL       extern __declspec(dllimport)
#   else
#       define MDO0MDOEXPORT
#       define MDO0MDOGLOBAL       extern
#   endif
#endif
