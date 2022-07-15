
/*=============================================================================
 ===============================================================================
File Description:

    The header file that defines the export symbols for the
    SYSTEMSENGINEERING library

===============================================================================
Date                     Name                       Description

$HISTORY$
=============================================================================*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libsystemsengineering

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten code should use the SYSTEMSENGINEERING_API version, not SYSTEMSENGINEERINGEXPORT */

#define SYSTEMSENGINEERING_API SYSTEMSENGINEERINGEXPORT

/* Support SYSTEMSENGINEERINGEXPORT for autogenerated schema/pif code only */

#if IPLIB==libsystemsengineering
#   if defined(__lint)
#       define SYSTEMSENGINEERINGEXPORT       __export(systemsengineering)
#       define SYSTEMSENGINEERINGGLOBAL       extern __global(systemsengineering)
#       define SYSTEMSENGINEERINGPRIVATE      extern __private(systemsengineering)
#   elif defined(_WIN32)
#       define SYSTEMSENGINEERINGEXPORT       __declspec(dllexport)
#       define SYSTEMSENGINEERINGGLOBAL       extern __declspec(dllexport)
#       define SYSTEMSENGINEERINGPRIVATE      extern
#   else
#       define SYSTEMSENGINEERINGEXPORT
#       define SYSTEMSENGINEERINGGLOBAL       extern
#       define SYSTEMSENGINEERINGPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define SYSTEMSENGINEERINGEXPORT       __export(systemsengineering)
#       define SYSTEMSENGINEERINGGLOBAL       extern __global(systemsengineering)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define SYSTEMSENGINEERINGEXPORT       __declspec(dllimport)
#       define SYSTEMSENGINEERINGGLOBAL       extern __declspec(dllimport)
#   else
#       define SYSTEMSENGINEERINGEXPORT
#       define SYSTEMSENGINEERINGGLOBAL       extern
#   endif
#endif