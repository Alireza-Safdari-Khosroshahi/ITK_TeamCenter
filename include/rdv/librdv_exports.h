/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that defines the export symbols for the RDV library
 */

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            librdv

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use RDV_API, not RDVEXPORT */

#define RDV_API RDVEXPORT

/* Support QRYEXPORT for autogenerated schema/pif code only */

#if IPLIB==librdv
#   if defined(__lint)
#       define RDVEXPORT       __export(rdv)
#       define RDVGLOBAL       extern __global(rdv)
#       define RDVPRIVATE      extern __private(rdv)
#   elif defined(_WIN32)
#       define RDVEXPORT       __declspec(dllexport)
#       define RDVGLOBAL       extern __declspec(dllexport)
#       define RDVPRIVATE      extern
#   else
#       define RDVEXPORT
#       define RDVGLOBAL       extern
#       define RDVPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define RDVEXPORT       __export(rdv)
#       define RDVGLOBAL       extern __global(rdv)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define RDVEXPORT       __declspec(dllimport)
#       define RDVGLOBAL       extern __declspec(dllimport)
#   else
#       define RDVEXPORT
#       define RDVGLOBAL       extern
#   endif
#endif
