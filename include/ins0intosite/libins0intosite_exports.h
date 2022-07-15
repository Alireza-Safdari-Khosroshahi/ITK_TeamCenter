/* 
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2018.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/
/** 
    @file 

    This file contains the declaration for the Dispatch Library  ins0intosite

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libins0intosite

#if !defined(LIBINS0INTOSITE) && !defined(IPLIB)
#   error IPLIB or LIBINS0INTOSITE is not defined
#endif

/* Handwritten code should use INS0INTOSITE_API, not INS0INTOSITEEXPORT */

#define INS0INTOSITE_API INS0INTOSITEEXPORT

#if IPLIB==libins0intosite || defined(LIBINS0INTOSITE)
#   if defined(__lint)
#       define INS0INTOSITEEXPORT       __export(ins0intosite)
#       define INS0INTOSITEGLOBAL       extern __global(ins0intosite)
#       define INS0INTOSITEPRIVATE      extern __private(ins0intosite)
#   elif defined(_WIN32)
#       define INS0INTOSITEEXPORT       __declspec(dllexport)
#       define INS0INTOSITEGLOBAL       extern __declspec(dllexport)
#       define INS0INTOSITEPRIVATE      extern
#   else
#       define INS0INTOSITEEXPORT
#       define INS0INTOSITEGLOBAL       extern
#       define INS0INTOSITEPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define INS0INTOSITEEXPORT       __export(ins0intosite)
#       define INS0INTOSITEGLOBAL       extern __global(ins0intosite)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define INS0INTOSITEEXPORT      __declspec(dllimport)
#       define INS0INTOSITEGLOBAL       extern __declspec(dllimport)
#   else
#       define INS0INTOSITEEXPORT
#       define INS0INTOSITEGLOBAL       extern
#   endif
#endif
