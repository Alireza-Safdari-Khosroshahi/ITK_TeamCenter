/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2017.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file
    The header file that defines the export symbols for the constraint solver library
*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libconstraintsolver

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use CONSTRAINTSOLVER_API, not CONSTRAINTSOLVEREXPORT */

#define CONSTRAINTSOLVER_API CONSTRAINTSOLVEREXPORT

/* Support CONSTRAINTSOLVEREXPORT for autogenerated schema/pif code only */

#if IPLIB==libconstraintsolver
#   if defined(__lint)
#       define CONSTRAINTSOLVEREXPORT       __export(libconstraintsolver)
#       define CONSTRAINTSOLVERGLOBAL       extern __global(libconstraintsolver)
#       define CONSTRAINTSOLVERPRIVATE      extern __private(libconstraintsolver)
#   elif defined(_WIN32)
#       define CONSTRAINTSOLVEREXPORT       __declspec(dllexport)
#       define CONSTRAINTSOLVERGLOBAL       extern __declspec(dllexport)
#       define CONSTRAINTSOLVERPRIVATE      extern
#   else
#       define CONSTRAINTSOLVEREXPORT
#       define CONSTRAINTSOLVERGLOBAL       extern
#       define CONSTRAINTSOLVERPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CONSTRAINTSOLVEREXPORT       __export(libconstraintsolver)
#       define CONSTRAINTSOLVERGLOBAL       extern __global(libconstraintsolver)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CONSTRAINTSOLVEREXPORT      __declspec(dllimport)
#       define CONSTRAINTSOLVERGLOBAL       extern __declspec(dllimport)
#   else
#       define CONSTRAINTSOLVEREXPORT
#       define CONSTRAINTSOLVERGLOBAL       extern
#   endif
#endif


