//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Mim0mesissue
    11-Feb-2013     Naveen Amesar       Initial Creation
*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libMim0mesissue

#if !defined(LIBMIM0MESISSUE) && !defined(IPLIB)
#   error IPLIB or LIBMIM0MESISSUE is not defined
#endif

/* Handwritten code should use MIM0MESISSUE_API, not MIM0MESISSUEEXPORT */

#define MIM0MESISSUE_API MIM0MESISSUEEXPORT

#if IPLIB==libMim0mesissue || defined(LIBMIM0MESISSUE)
#   if defined(__lint)
#       define MIM0MESISSUEEXPORT       __export(Mim0mesissue)
#       define MIM0MESISSUEGLOBAL       extern __global(Mim0mesissue)
#       define MIM0MESISSUEPRIVATE      extern __private(Mim0mesissue)
#   elif defined(_WIN32)
#       define MIM0MESISSUEEXPORT       __declspec(dllexport)
#       define MIM0MESISSUEGLOBAL       extern __declspec(dllexport)
#       define MIM0MESISSUEPRIVATE      extern
#   else
#       define MIM0MESISSUEEXPORT
#       define MIM0MESISSUEGLOBAL       extern
#       define MIM0MESISSUEPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define MIM0MESISSUEEXPORT       __export(Mim0mesissue)
#       define MIM0MESISSUEGLOBAL       extern __global(Mim0mesissue)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define MIM0MESISSUEEXPORT      __declspec(dllimport)
#       define MIM0MESISSUEGLOBAL       extern __declspec(dllimport)
#   else
#       define MIM0MESISSUEEXPORT
#       define MIM0MESISSUEGLOBAL       extern
#   endif
#endif
