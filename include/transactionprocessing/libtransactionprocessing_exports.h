//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2008.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  transactionprocessing

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libtransactionprocessing

#if !defined(LIBTRANSACTIONPROCESSING) && !defined(IPLIB)
#   error IPLIB or LIBTRANSACTIONPROCESSING is not defined
#endif

/* Handwritten code should use TRANSACTIONPROCESSING_API, not TRANSACTIONPROCESSINGEXPORT */

#define TRANSACTIONPROCESSING_API TRANSACTIONPROCESSINGEXPORT

#if IPLIB==libtransactionprocessing || defined(LIBTRANSACTIONPROCESSING)
#   if defined(__lint)
#       define TRANSACTIONPROCESSINGEXPORT       __export(transactionprocessing)
#       define TRANSACTIONPROCESSINGGLOBAL       extern __global(transactionprocessing)
#       define TRANSACTIONPROCESSINGPRIVATE      extern __private(transactionprocessing)
#   elif defined(_WIN32)
#       define TRANSACTIONPROCESSINGEXPORT       __declspec(dllexport)
#       define TRANSACTIONPROCESSINGGLOBAL       extern __declspec(dllexport)
#       define TRANSACTIONPROCESSINGPRIVATE      extern
#   else
#       define TRANSACTIONPROCESSINGEXPORT
#       define TRANSACTIONPROCESSINGGLOBAL       extern
#       define TRANSACTIONPROCESSINGPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define TRANSACTIONPROCESSINGEXPORT       __export(transactionprocessing)
#       define TRANSACTIONPROCESSINGGLOBAL       extern __global(transactionprocessing)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define TRANSACTIONPROCESSINGEXPORT      __declspec(dllimport)
#       define TRANSACTIONPROCESSINGGLOBAL       extern __declspec(dllimport)
#   else
#       define TRANSACTIONPROCESSINGEXPORT
#       define TRANSACTIONPROCESSINGGLOBAL       extern
#   endif
#endif
