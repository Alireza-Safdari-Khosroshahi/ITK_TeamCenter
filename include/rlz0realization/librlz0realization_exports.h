//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2010.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/**
    @file

    This file contains the declaration for the Dispatch Library  Rlz0Realization

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            librlz0realization

#if !defined(LIBRLZ0REALIZATION) && !defined(IPLIB)
#   error IPLIB or LIBRLZ0REALIZATION is not defined
#endif

/* Handwritten code should use RLZ0REALIZATION_API, not RLZ0REALIZATIONEXPORT */

#define RLZ0REALIZATION_API RLZ0REALIZATIONEXPORT

#if IPLIB==librlz0realization || defined(LIBRLZ0REALIZATION)
#   if defined(__lint)
#       define RLZ0REALIZATIONEXPORT       __export(rlz0realization)
#       define RLZ0REALIZATIONGLOBAL       extern __global(rlz0realization)
#       define RLZ0REALIZATIONPRIVATE      extern __private(rlz0realization)
#   elif defined(_WIN32)
#       define RLZ0REALIZATIONEXPORT       __declspec(dllexport)
#       define RLZ0REALIZATIONGLOBAL       extern __declspec(dllexport)
#       define RLZ0REALIZATIONPRIVATE      extern
#   else
#       define RLZ0REALIZATIONEXPORT
#       define RLZ0REALIZATIONGLOBAL       extern
#       define RLZ0REALIZATIONPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define RLZ0REALIZATIONEXPORT       __export(rlz0realization)
#       define RLZ0REALIZATIONGLOBAL       extern __global(rlz0realization)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define RLZ0REALIZATIONEXPORT      __declspec(dllimport)
#       define RLZ0REALIZATIONGLOBAL       extern __declspec(dllimport)
#   else
#       define RLZ0REALIZATIONEXPORT
#       define RLZ0REALIZATIONGLOBAL       extern
#   endif
#endif
