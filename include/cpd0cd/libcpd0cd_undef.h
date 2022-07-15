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

#if !defined(LIBCPD0CD) && !defined(IPLIB)
#   error IPLIB orLIBCPD0CD is not defined
#endif

#undef CPD0CD_API
#undef CPD0CDEXPORT
#undef CPD0CDGLOBAL
#undef CPD0CDPRIVATE
