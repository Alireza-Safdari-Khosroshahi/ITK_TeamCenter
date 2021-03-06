// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software


/**
    @libEpl0edalibrary_exports.h
    Export defines for the EDA library

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libEpl0edalibrary

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define EPL0EDALIBRARY_LIBRARY_NAME libEpl0edalibrary
#define EPL0EDALIBRARY_LIBRARY_ID_NAME Epl0edalibrary

/* Handwritten code should use EPL0EDALIBRARY_API, not EPL0EDALIBRARYEXPORT */

#define EPL0EDALIBRARY_API EPL0EDALIBRARYEXPORT

/* Support EPL0EDALIBRARYEXPORT for autogenerated schema/pif code only */

#if IPLIB==EPL0EDALIBRARY_LIBRARY_NAME
#   if defined(__lint)
#       define EPL0EDALIBRARYEXPORT       __export(EPL0EDALIBRARY_LIBRARY_ID_NAME)
#       define EPL0EDALIBRARYGLOBAL       extern __global(EPL0EDALIBRARY_LIBRARY_ID_NAME)
#       define EPL0EDALIBRARYPRIVATE      extern __private(EPL0EDALIBRARY_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define EPL0EDALIBRARYEXPORT       __declspec(dllexport)
#       define EPL0EDALIBRARYGLOBAL       extern __declspec(dllexport)
#       define EPL0EDALIBRARYPRIVATE      extern
#   else
#       define EPL0EDALIBRARYEXPORT
#       define EPL0EDALIBRARYGLOBAL       extern
#       define EPL0EDALIBRARYPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define EPL0EDALIBRARYEXPORT       __export(EPL0EDALIBRARY_LIBRARY_ID_NAME)
#       define EPL0EDALIBRARYGLOBAL       extern __global(EPL0EDALIBRARY_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define EPL0EDALIBRARYEXPORT       __declspec(dllimport)
#       define EPL0EDALIBRARYGLOBAL       extern __declspec(dllimport)
#   else
#       define EPL0EDALIBRARYEXPORT
#       define EPL0EDALIBRARYGLOBAL       extern
#   endif
#endif
