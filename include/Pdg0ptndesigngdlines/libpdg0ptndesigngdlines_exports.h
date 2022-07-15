//@<COPYRIGHT>@
//==================================================
//Copyright $2021.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//@<COPYRIGHT>@

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Pdg0ptndesigngdlines

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libPdg0ptndesigngdlines

#if !defined(LIBPDG0PTNDESIGNGDLINES) && !defined(IPLIB)
#   error IPLIB or LIBPDG0PTNDESIGNGDLINES is not defined
#endif

/* Handwritten code should use PDG0PTNDESIGNGDLINES_API, not PDG0PTNDESIGNGDLINESEXPORT */

#define PDG0PTNDESIGNGDLINES_API PDG0PTNDESIGNGDLINESEXPORT

#if IPLIB==libPdg0ptndesigngdlines || defined(LIBPDG0PTNDESIGNGDLINES)
#   if defined(__lint)
#       define PDG0PTNDESIGNGDLINESEXPORT       __export(Pdg0ptndesigngdlines)
#       define PDG0PTNDESIGNGDLINESGLOBAL       extern __global(Pdg0ptndesigngdlines)
#       define PDG0PTNDESIGNGDLINESPRIVATE      extern __private(Pdg0ptndesigngdlines)
#   elif defined(_WIN32)
#       define PDG0PTNDESIGNGDLINESEXPORT       __declspec(dllexport)
#       define PDG0PTNDESIGNGDLINESGLOBAL       extern __declspec(dllexport)
#       define PDG0PTNDESIGNGDLINESPRIVATE      extern
#   else
#       define PDG0PTNDESIGNGDLINESEXPORT
#       define PDG0PTNDESIGNGDLINESGLOBAL       extern
#       define PDG0PTNDESIGNGDLINESPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define PDG0PTNDESIGNGDLINESEXPORT       __export(Pdg0ptndesigngdlines)
#       define PDG0PTNDESIGNGDLINESGLOBAL       extern __global(Pdg0ptndesigngdlines)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define PDG0PTNDESIGNGDLINESEXPORT      __declspec(dllimport)
#       define PDG0PTNDESIGNGDLINESGLOBAL       extern __declspec(dllimport)
#   else
#       define PDG0PTNDESIGNGDLINESEXPORT
#       define PDG0PTNDESIGNGDLINESGLOBAL       extern
#   endif
#endif
