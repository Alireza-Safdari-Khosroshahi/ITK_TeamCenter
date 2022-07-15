/*Copyright 2020 Siemens Digital Industries Software
 * ==================================================
 * Copyright $2018.
 * Siemens Product Lifecycle Management Software Inc.
 * All Rights Reserved.
 * ==================================================
 * Copyright 2020 Siemens Digital Industries Software
 */

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBPTN0PARTITIONASYNC) && !defined(IPLIB)
#   error IPLIB or LIBPTN0PARTITIONASYNC is not defined
#endif

#undef PTN0PARTITIONASYNC_API
#undef PTN0PARTITIONASYNCEXPORT
#undef PTN0PARTITIONASYNCGLOBAL
#undef PTN0PARTITIONASYNCPRIVATE
