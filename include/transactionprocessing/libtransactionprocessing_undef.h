//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2008.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBTRANSACTIONPROCESSING) && !defined(IPLIB)
#   error IPLIB orLIBTRANSACTIONPROCESSING is not defined
#endif

#undef TRANSACTIONPROCESSING_API
#undef TRANSACTIONPROCESSINGEXPORT
#undef TRANSACTIONPROCESSINGGLOBAL
#undef TRANSACTIONPROCESSINGPRIVATE
