
/*=============================================================================
 ===============================================================================
File Description:

    The header file that defines the export symbols for the
    MROCORE library

===============================================================================
Date                     Name                       Description

$HISTORY$
=============================================================================*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libcba

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif


#define CBA_API CBAEXPORT


#if IPLIB==libcba
#   if defined(__lint)
#       define CBAEXPORT       __export(cba)
#       define CBAGLOBAL       extern __global(cba)
#       define CBAPRIVATE      extern __private(cba)
#   elif defined(_WIN32)
#       define CBAEXPORT       __declspec(dllexport)
#       define CBAGLOBAL       extern __declspec(dllexport)
#       define CBAPRIVATE      extern
#   else
#       define CBAEXPORT
#       define CBAGLOBAL       extern
#       define CBAPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CBAEXPORT       __export(cba)
#       define CBAGLOBAL       extern __global(cba)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CBAEXPORT       __declspec(dllimport)
#       define CBAGLOBAL       extern __declspec(dllimport)
#   else
#       define CBAEXPORT
#       define CBAGLOBAL       extern
#   endif
#endif
