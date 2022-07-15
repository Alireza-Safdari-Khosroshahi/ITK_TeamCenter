
/*=============================================================================
 ===============================================================================
File Description:

    The header file that defines the export symbols for the
    ASMAINTAINED library

===============================================================================
Date                     Name                       Description

$HISTORY$
=============================================================================*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libasmaintained

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

/* Handwritten iMAN code should use the ASMAINTAINED_API version, not ASMAINTAINEDEXPORT */

#define ASMAINTAINED_API ASMAINTAINEDEXPORT

/* Support ASMAINTAINEDEXPORT for autogenerated schema/pif code only */

#if IPLIB==libasmaintained
#   if defined(__lint)
#       define ASMAINTAINEDEXPORT       __export(asmaintained)
#       define ASMAINTAINEDGLOBAL       extern __global(asmaintained)
#       define ASMAINTAINEDPRIVATE      extern __private(asmaintained)
#   elif defined(_WIN32)
#       define ASMAINTAINEDEXPORT       __declspec(dllexport)
#       define ASMAINTAINEDGLOBAL       extern __declspec(dllexport)
#       define ASMAINTAINEDPRIVATE      extern
#   else
#       define ASMAINTAINEDEXPORT
#       define ASMAINTAINEDGLOBAL       extern
#       define ASMAINTAINEDPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define ASMAINTAINEDEXPORT       __export(asmaintained)
#       define ASMAINTAINEDGLOBAL       extern __global(asmaintained)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define ASMAINTAINEDEXPORT       __declspec(dllimport)
#       define ASMAINTAINEDGLOBAL       extern __declspec(dllimport)
#   else
#       define ASMAINTAINEDEXPORT
#       define ASMAINTAINEDGLOBAL       extern
#   endif
#endif
