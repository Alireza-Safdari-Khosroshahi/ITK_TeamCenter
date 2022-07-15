//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright 2014.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @libOsl0lisoslc_exports.h
    Export defines for the Lifecycle Interoperability Services for OSLC support library

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libOsl0lisoslc

#if !defined(LIBOSL0LISOSLC) && !defined(IPLIB)
#   error IPLIB or LIBOSL0LISOSLC is not defined
#endif

/* Handwritten code should use OSL0LISOSLC_API, not OSL0LISOSLCEXPORT */

#define OSL0LISOSLC_API OSL0LISOSLCEXPORT

#if IPLIB==libOsl0lisoslc || defined(LIBOSL0LISOSLC)
#   if defined(__lint)
#       define OSL0LISOSLCEXPORT       __export(Osl0lisoslc)
#       define OSL0LISOSLCGLOBAL       extern __global(Osl0lisoslc)
#       define OSL0LISOSLCPRIVATE      extern __private(Osl0lisoslc)
#   elif defined(_WIN32)
#       define OSL0LISOSLCEXPORT       __declspec(dllexport)
#       define OSL0LISOSLCGLOBAL       extern __declspec(dllexport)
#       define OSL0LISOSLCPRIVATE      extern
#   else
#       define OSL0LISOSLCEXPORT
#       define OSL0LISOSLCGLOBAL       extern
#       define OSL0LISOSLCPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define OSL0LISOSLCEXPORT       __export(Osl0lisoslc)
#       define OSL0LISOSLCGLOBAL       extern __global(Osl0lisoslc)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define OSL0LISOSLCEXPORT      __declspec(dllimport)
#       define OSL0LISOSLCGLOBAL       extern __declspec(dllimport)
#   else
#       define OSL0LISOSLCEXPORT
#       define OSL0LISOSLCGLOBAL       extern
#   endif
#endif
