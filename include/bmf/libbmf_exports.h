/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that defines the export symbols for the BMF library
 */

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#ifdef __lint
#   pragma uginclude only_in_error "libbmf_main.c", "*.h";
#endif

#define EXPORTLIBRARY            libbmf

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define BMF_LIBRARY_NAME libbmf
#define BMF_LIBRARY_ID_NAME bmf
#define BMF_API BMFEXPORT

#if IPLIB==BMF_LIBRARY_NAME
#   if defined(__lint)
#       define BMFEXPORT       __export(BMF_LIBRARY_ID_NAME)
#       define BMFGLOBAL       extern __global(BMF_LIBRARY_ID_NAME)
#       define BMFPRIVATE      extern __private(BMF_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define BMFEXPORT       __declspec(dllexport)
#       define BMFGLOBAL       extern __declspec(dllexport)
#       define BMFPRIVATE      extern
#   else
#       define BMFEXPORT
#       define BMFGLOBAL       extern
#       define BMFPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define BMFEXPORT       __export(BMF_LIBRARY_ID_NAME)
#       define BMFGLOBAL       extern __global(BMF_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define BMFEXPORT       __declspec(dllimport)
#       define BMFGLOBAL       extern __declspec(dllimport)
#   else
#       define BMFEXPORT
#       define BMFGLOBAL       extern
#   endif
#endif
