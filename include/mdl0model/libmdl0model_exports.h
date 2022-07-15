//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2010.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  mdl0model

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libmdl0model

#if !defined(LIBMDL0MODEL) && !defined(IPLIB)
#   error IPLIB or LIBMDL0MODEL is not defined
#endif

/* Handwritten code should use MDL0MODEL_API, not MDL0MODELEXPORT */

#define MDL0MODEL_API MDL0MODELEXPORT

#if IPLIB==libmdl0model || defined(LIBMDL0MODEL)
#   if defined(__lint)
#       define MDL0MODELEXPORT       __export(mdl0model)
#       define MDL0MODELGLOBAL       extern __global(mdl0model)
#       define MDL0MODELPRIVATE      extern __private(mdl0model)
#   elif defined(_WIN32)
#       define MDL0MODELEXPORT       __declspec(dllexport)
#       define MDL0MODELGLOBAL       extern __declspec(dllexport)
#       define MDL0MODELPRIVATE      extern
#   else
#       define MDL0MODELEXPORT
#       define MDL0MODELGLOBAL       extern
#       define MDL0MODELPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define MDL0MODELEXPORT       __export(mdl0model)
#       define MDL0MODELGLOBAL       extern __global(mdl0model)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define MDL0MODELEXPORT      __declspec(dllimport)
#       define MDL0MODELGLOBAL       extern __declspec(dllimport)
#   else
#       define MDL0MODELEXPORT
#       define MDL0MODELGLOBAL       extern
#   endif
#endif
