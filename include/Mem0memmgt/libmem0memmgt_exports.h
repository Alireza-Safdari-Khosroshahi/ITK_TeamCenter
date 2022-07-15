//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2011.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Mem0memmgt

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libMem0memmgt

#if !defined(LIBMEM0MEMMGT) && !defined(IPLIB)
#   error IPLIB or LIBMEM0MEMMGT is not defined
#endif

/* Handwritten code should use MEM0MEMMGT_API, not MEM0MEMMGTEXPORT */

#define MEM0MEMMGT_API MEM0MEMMGTEXPORT

#if IPLIB==libMem0memmgt || defined(LIBMEM0MEMMGT)
#   if defined(__lint)
#       define MEM0MEMMGTEXPORT       __export(Mem0memmgt)
#       define MEM0MEMMGTGLOBAL       extern __global(Mem0memmgt)
#       define MEM0MEMMGTPRIVATE      extern __private(Mem0memmgt)
#   elif defined(_WIN32)
#       define MEM0MEMMGTEXPORT       __declspec(dllexport)
#       define MEM0MEMMGTGLOBAL       extern __declspec(dllexport)
#       define MEM0MEMMGTPRIVATE      extern
#   else
#       define MEM0MEMMGTEXPORT
#       define MEM0MEMMGTGLOBAL       extern
#       define MEM0MEMMGTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define MEM0MEMMGTEXPORT       __export(Mem0memmgt)
#       define MEM0MEMMGTGLOBAL       extern __global(Mem0memmgt)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define MEM0MEMMGTEXPORT      __declspec(dllimport)
#       define MEM0MEMMGTGLOBAL       extern __declspec(dllimport)
#   else
#       define MEM0MEMMGTEXPORT
#       define MEM0MEMMGTGLOBAL       extern
#   endif
#endif
