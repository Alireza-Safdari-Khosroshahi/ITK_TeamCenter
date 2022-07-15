//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2010.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBPTN0PARTITION) && !defined(IPLIB)
#   error IPLIB orLIBPTN0PARTITION is not defined
#endif

#undef PTN0PARTITION_API
#undef PTN0PARTITIONEXPORT
#undef PTN0PARTITIONGLOBAL
#undef PTN0PARTITIONPRIVATE
