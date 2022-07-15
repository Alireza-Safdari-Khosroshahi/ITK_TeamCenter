//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2010.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Ptn0Partition

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libptn0partition

#if !defined(LIBPTN0PARTITION) && !defined(IPLIB)
#   error IPLIB or LIBPTN0PARTITION is not defined
#endif

/* Handwritten code should use PTN0PARTITION_API, not PTN0PARTITIONEXPORT */

#define PTN0PARTITION_API PTN0PARTITIONEXPORT

#if IPLIB==libptn0partition || defined(LIBPTN0PARTITION)
#   if defined(__lint)
#       define PTN0PARTITIONEXPORT       __export(ptn0partition)
#       define PTN0PARTITIONGLOBAL       extern __global(ptn0partition)
#       define PTN0PARTITIONPRIVATE      extern __private(ptn0partition)
#   elif defined(_WIN32)
#       define PTN0PARTITIONEXPORT       __declspec(dllexport)
#       define PTN0PARTITIONGLOBAL       extern __declspec(dllexport)
#       define PTN0PARTITIONPRIVATE      extern
#   else
#       define PTN0PARTITIONEXPORT
#       define PTN0PARTITIONGLOBAL       extern
#       define PTN0PARTITIONPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define PTN0PARTITIONEXPORT       __export(ptn0partition)
#       define PTN0PARTITIONGLOBAL       extern __global(ptn0partition)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define PTN0PARTITIONEXPORT      __declspec(dllimport)
#       define PTN0PARTITIONGLOBAL       extern __declspec(dllimport)
#   else
#       define PTN0PARTITIONEXPORT
#       define PTN0PARTITIONGLOBAL       extern
#   endif
#endif
