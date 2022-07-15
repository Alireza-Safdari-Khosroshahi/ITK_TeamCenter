// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2006 UGS Corp. All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@


/** 
    @file 

    The header file that defines the export symbols for the RBF library.

*/


#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#ifdef __lint
#   pragma uginclude only_in_error "librbf_main.c", "*.h";
#endif

#define EXPORTLIBRARY            librbf

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#define RBF_LIBRARY_NAME librbf
#define RBF_LIBRARY_ID_NAME rbf
#define RBF_API RBFEXPORT

#if IPLIB==RBF_LIBRARY_NAME
#   if defined(__lint)
#       define RBFEXPORT       __export(RBF_LIBRARY_ID_NAME)
#       define RBFGLOBAL       extern __global(RBF_LIBRARY_ID_NAME)
#       define RBFPRIVATE      extern __private(RBF_LIBRARY_ID_NAME)
#   elif defined(_WIN32)
#       define RBFEXPORT       __declspec(dllexport)
#       define RBFGLOBAL       extern __declspec(dllexport)
#       define RBFPRIVATE      extern
#   else
#       define RBFEXPORT
#       define RBFGLOBAL       extern
#       define RBFPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define RBFEXPORT       __export(RBF_LIBRARY_ID_NAME)
#       define RBFGLOBAL       extern __global(RBF_LIBRARY_ID_NAME)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define RBFEXPORT       __declspec(dllimport)
#       define RBFGLOBAL       extern __declspec(dllimport)
#   else
#       define RBFEXPORT
#       define RBFGLOBAL       extern
#   endif
#endif
