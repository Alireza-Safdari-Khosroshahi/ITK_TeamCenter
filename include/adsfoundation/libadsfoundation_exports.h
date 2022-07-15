
// Copyright 2020 Siemens Digital Industries Software
// ========================================================================
// Copyright 2008.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// =========================================================================
// Copyright 2020 Siemens Digital Industries Software

/*===========================================================================
    @file       : libadsfoundation_exports.h

    Description:
      The header file that defines the export symbols for the ADSFOUNDATION library

===========================================================================*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libadsfoundation

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use ADSFOUNDATION_API, not ADSFOUNDATIONEXPORT */

#define ADSFOUNDATION_API ADSFOUNDATIONEXPORT

/* Support ADSFOUNDATIONEXPORT for autogenerated code only */

#if IPLIB==libadsfoundation
#   if defined(__lint)
#       define ADSFOUNDATIONEXPORT       __export(adsfoundation)
#       define ADSFOUNDATIONGLOBAL       extern __global(adsfoundation)
#       define ADSFOUNDATIONPRIVATE      extern __private(adsfoundation)
#   elif defined(_WIN32)
#       define ADSFOUNDATIONEXPORT       __declspec(dllexport)
#       define ADSFOUNDATIONGLOBAL       extern __declspec(dllexport)
#       define ADSFOUNDATIONPRIVATE      extern
#   else
#       define ADSFOUNDATIONEXPORT
#       define ADSFOUNDATIONGLOBAL       extern
#       define ADSFOUNDATIONPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define ADSFOUNDATIONEXPORT       __export(adsfoundation)
#       define ADSFOUNDATIONGLOBAL       extern __global(adsfoundation)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define ADSFOUNDATIONEXPORT      __declspec(dllimport)
#       define ADSFOUNDATIONGLOBAL       extern __declspec(dllimport)
#   else
#       define ADSFOUNDATIONEXPORT
#       define ADSFOUNDATIONGLOBAL       extern
#   endif
#endif
