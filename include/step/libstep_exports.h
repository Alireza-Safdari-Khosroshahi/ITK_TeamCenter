/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that defines the export symbols for the STEP library
 */

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libstep

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use STEP_API, not STEPEXPORT */

#define STEP_API STEPEXPORT

/* Support STEPEXPORT for autogenerated schema/pif code only */

#if IPLIB==libstep
#   if defined(__lint)
#       define STEPEXPORT       __export(step)
#       define STEPGLOBAL       extern __global(step)
#       define STEPPRIVATE      extern __private(step)
#   elif defined(_WIN32)
#       define STEPEXPORT       __declspec(dllexport)
#       define STEPGLOBAL       extern __declspec(dllexport)
#       define STEPPRIVATE      extern
#   else
#       define STEPEXPORT
#       define STEPGLOBAL       extern
#       define STEPPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define STEPEXPORT       __export(step)
#       define STEPGLOBAL       extern __global(step)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define STEPEXPORT      __declspec(dllimport)
#       define STEPGLOBAL       extern __declspec(dllimport)
#   else
#       define STEPEXPORT
#       define STEPGLOBAL       extern
#   endif
#endif

