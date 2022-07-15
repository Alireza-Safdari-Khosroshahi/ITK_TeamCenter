// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software

/*
    File Description:

    The header file that defines the export symbols for the NLS library
 */

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libnls

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use NLS_API, not NLSEXPORT */

#define NLS_API NLSEXPORT

/* Support NLSEXPORT for autogenerated schema/pif code only */

#if IPLIB==libnls
#   if defined(__lint)
#       define NLSEXPORT       __export(nls)
#       define NLSGLOBAL       extern __global(nls)
#       define NLSPRIVATE      extern __private(nls)
#   elif defined(_WIN32)
#       define NLSEXPORT       __declspec(dllexport)
#       define NLSGLOBAL       extern __declspec(dllexport)
#       define NLSPRIVATE      extern
#   else
#       define NLSEXPORT
#       define NLSGLOBAL       extern
#       define NLSPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define NLSEXPORT       __export(nls)
#       define NLSGLOBAL       extern __global(nls)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define NLSEXPORT      __declspec(dllimport)
#       define NLSGLOBAL       extern __declspec(dllimport)
#   else
#       define NLSEXPORT
#       define NLSGLOBAL       extern
#   endif
#endif
