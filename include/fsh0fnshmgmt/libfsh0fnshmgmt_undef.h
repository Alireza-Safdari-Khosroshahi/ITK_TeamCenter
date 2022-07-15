//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBFSH0FNSHMGMT) && !defined(IPLIB)
#   error IPLIB orLIBFSH0FNSHMGMT is not defined
#endif

#undef FSH0FNSHMGMT_API
#undef FSH0FNSHMGMTEXPORT
#undef FSH0FNSHMGMTGLOBAL
#undef FSH0FNSHMGMTPRIVATE
