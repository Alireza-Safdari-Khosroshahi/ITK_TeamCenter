
/*=============================================================================
 ===============================================================================
File Description:

    The header file that defines the export symbols for the
    SSPSPRALIGNMENT library

===============================================================================
Date                     Name                       Description

$HISTORY$
=============================================================================*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libsspspralignment

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use the SSPSPRALIGNMENT_API version, not SSPSPRALIGNMENTEXPORT */

#define SSPSPRALIGNMENT_API SSPSPRALIGNMENTEXPORT

/* Support SSPSPRALIGNMENTEXPORT for autogenerated schema/pif code only */

#if IPLIB==libsspspralignment
#   if defined(__lint)
#       define SSPSPRALIGNMENTEXPORT       __export(sspspralignment)
#       define SSPSPRALIGNMENTGLOBAL       extern __global(sspspralignment)
#       define SSPSPRALIGNMENTPRIVATE      extern __private(sspspralignment)
#   elif defined(_WIN32)
#       define SSPSPRALIGNMENTEXPORT       __declspec(dllexport)
#       define SSPSPRALIGNMENTGLOBAL       extern __declspec(dllexport)
#       define SSPSPRALIGNMENTPRIVATE      extern
#   else
#       define SSPSPRALIGNMENTEXPORT
#       define SSPSPRALIGNMENTGLOBAL       extern
#       define SSPSPRALIGNMENTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define SSPSPRALIGNMENTEXPORT       __export(sspspralignment)
#       define SSPSPRALIGNMENTGLOBAL       extern __global(sspspralignment)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define SSPSPRALIGNMENTEXPORT       __declspec(dllimport)
#       define SSPSPRALIGNMENTGLOBAL       extern __declspec(dllimport)
#   else
#       define SSPSPRALIGNMENTEXPORT
#       define SSPSPRALIGNMENTGLOBAL       extern
#   endif
#endif
