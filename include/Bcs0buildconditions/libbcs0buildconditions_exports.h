/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2015.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/** 
    @file 
    This file contains the declaration for the Dispatch Library  Bcs0buildconditions
*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libBcs0buildconditions

#if !defined(LIBBCS0BUILDCONDITIONS) && !defined(IPLIB)
#   error IPLIB or LIBBCS0BUILDCONDITIONS is not defined
#endif

/* Handwritten code should use BCS0BUILDCONDITIONS_API, not BCS0BUILDCONDITIONSEXPORT */

#define BCS0BUILDCONDITIONS_API BCS0BUILDCONDITIONSEXPORT

#if IPLIB==libBcs0buildconditions || defined(LIBBCS0BUILDCONDITIONS)
#   if defined(__lint)
#       define BCS0BUILDCONDITIONSEXPORT       __export(Bcs0buildconditions)
#       define BCS0BUILDCONDITIONSGLOBAL       extern __global(Bcs0buildconditions)
#       define BCS0BUILDCONDITIONSPRIVATE      extern __private(Bcs0buildconditions)
#   elif defined(_WIN32)
#       define BCS0BUILDCONDITIONSEXPORT       __declspec(dllexport)
#       define BCS0BUILDCONDITIONSGLOBAL       extern __declspec(dllexport)
#       define BCS0BUILDCONDITIONSPRIVATE      extern
#   else
#       define BCS0BUILDCONDITIONSEXPORT
#       define BCS0BUILDCONDITIONSGLOBAL       extern
#       define BCS0BUILDCONDITIONSPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define BCS0BUILDCONDITIONSEXPORT       __export(Bcs0buildconditions)
#       define BCS0BUILDCONDITIONSGLOBAL       extern __global(Bcs0buildconditions)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define BCS0BUILDCONDITIONSEXPORT      __declspec(dllimport)
#       define BCS0BUILDCONDITIONSGLOBAL       extern __declspec(dllimport)
#   else
#       define BCS0BUILDCONDITIONSEXPORT
#       define BCS0BUILDCONDITIONSGLOBAL       extern
#   endif
#endif
