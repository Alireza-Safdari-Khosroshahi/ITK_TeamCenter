
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

#define EXPORTLIBRARY            libcbaext

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif


#define CBAEXT_API CBAEXTEXPORT


#if IPLIB==libcbaext
#   if defined(__lint)
#       define CBAEXTEXPORT       __export(cbaext)
#       define CBAEXTGLOBAL       extern __global(cbaext)
#       define CBAEXTPRIVATE      extern __private(cbaext)
#   elif defined(_WIN32)
#       define CBAEXTEXPORT       __declspec(dllexport)
#       define CBAEXTGLOBAL       extern __declspec(dllexport)
#       define CBAEXTPRIVATE      extern
#   else
#       define CBAEXTEXPORT
#       define CBAEXTGLOBAL       extern
#       define CBAEXTPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define CBAEXTEXPORT       __export(cbaext)
#       define CBAEXTGLOBAL       extern __global(cbaext)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define CBAEXTEXPORT       __declspec(dllimport)
#       define CBAEXTGLOBAL       extern __declspec(dllimport)
#   else
#       define CBAEXTEXPORT
#       define CBAEXTGLOBAL       extern
#   endif
#endif
