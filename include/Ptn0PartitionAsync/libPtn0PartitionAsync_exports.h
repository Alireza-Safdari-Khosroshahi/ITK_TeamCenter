/*Copyright 2020 Siemens Digital Industries Software
 * ==================================================
 * Copyright $2018.
 * Siemens Product Lifecycle Management Software Inc.
 * All Rights Reserved.
 * ==================================================
 * Copyright 2020 Siemens Digital Industries Software
 */

/** 
    @file 

    This file contains the declaration for the Dispatch Library  Ptn0PartitionAsync

*/

#include <common/library_indicators.h>

#ifdef EXPORTLIBRARY
#define EXPORTLIBRARY something else
#error ExportLibrary was already defined
#endif

#define EXPORTLIBRARY            libPtn0PartitionAsync

#if !defined(LIBPTN0PARTITIONASYNC) && !defined(IPLIB)
#   error IPLIB or LIBPTN0PARTITIONASYNC is not defined
#endif

/* Handwritten code should use PTN0PARTITIONASYNC_API, not PTN0PARTITIONASYNCEXPORT */

#define PTN0PARTITIONASYNC_API PTN0PARTITIONASYNCEXPORT

#if IPLIB==libPtn0PartitionAsync || defined(LIBPTN0PARTITIONASYNC)
#   if defined(__lint)
#       define PTN0PARTITIONASYNCEXPORT       __export(Ptn0PartitionAsync)
#       define PTN0PARTITIONASYNCGLOBAL       extern __global(Ptn0PartitionAsync)
#       define PTN0PARTITIONASYNCPRIVATE      extern __private(Ptn0PartitionAsync)
#   elif defined(_WIN32)
#       define PTN0PARTITIONASYNCEXPORT       __declspec(dllexport)
#       define PTN0PARTITIONASYNCGLOBAL       extern __declspec(dllexport)
#       define PTN0PARTITIONASYNCPRIVATE      extern
#   else
#       define PTN0PARTITIONASYNCEXPORT
#       define PTN0PARTITIONASYNCGLOBAL       extern
#       define PTN0PARTITIONASYNCPRIVATE      extern
#   endif
#else
#   if defined(__lint)
#       define PTN0PARTITIONASYNCEXPORT       __export(Ptn0PartitionAsync)
#       define PTN0PARTITIONASYNCGLOBAL       extern __global(Ptn0PartitionAsync)
#   elif defined(_WIN32) && !defined(WNT_STATIC_LINK)
#       define PTN0PARTITIONASYNCEXPORT      __declspec(dllimport)
#       define PTN0PARTITIONASYNCGLOBAL       extern __declspec(dllimport)
#   else
#       define PTN0PARTITIONASYNCEXPORT
#       define PTN0PARTITIONASYNCGLOBAL       extern
#   endif
#endif
