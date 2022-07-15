//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2014.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  mdl0modelgeometry

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libmdl0modelgeometry

#if !defined(LIBMDL0MODELGEOMETRY) && !defined(IPLIB)
#   error IPLIB or LIBMDL0MODELGEOMETRY is not defined
#endif

/* Handwritten code should use MDL0MODELGEOMETRY_API, not MDL0MODELGEOMETRYEXPORT */

#define MDL0MODELGEOMETRY_API MDL0MODELGEOMETRYEXPORT

#if IPLIB==libmdl0modelgeometry || defined(LIBMDL0MODELGEOMETRY)
#   if defined(__lint)
#       define MDL0MODELGEOMETRYEXPORT       __export(mdl0modelgeometry)
#       define MDL0MODELGEOMETRYGLOBAL       extern __global(mdl0modelgeometry)
#       define MDL0MODELGEOMETRYPRIVATE      extern __private(mdl0modelgeometry)
#   elif defined(_WIN32)
#       define MDL0MODELGEOMETRYEXPORT       __declspec(dllexport)
#       define MDL0MODELGEOMETRYGLOBAL       extern __declspec(dllexport)
#       define MDL0MODELGEOMETRYPRIVATE      extern
#   else
#       define MDL0MODELGEOMETRYEXPORT
#       define MDL0MODELGEOMETRYGLOBAL       extern
#       define MDL0MODELGEOMETRYPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define MDL0MODELGEOMETRYEXPORT       __export(mdl0modelgeometry)
#       define MDL0MODELGEOMETRYGLOBAL       extern __global(mdl0modelgeometry)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define MDL0MODELGEOMETRYEXPORT      __declspec(dllimport)
#       define MDL0MODELGEOMETRYGLOBAL       extern __declspec(dllimport)
#   else
#       define MDL0MODELGEOMETRYEXPORT
#       define MDL0MODELGEOMETRYGLOBAL       extern
#   endif
#endif
