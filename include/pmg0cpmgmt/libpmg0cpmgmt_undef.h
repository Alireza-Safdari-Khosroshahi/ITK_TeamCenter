/*
//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2017.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software
*/

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBPMG0CPMGMT) && !defined(IPLIB)
#   error IPLIB or LIBPMG0CPMGMT is not defined
#endif

#undef PMG0CPMGMT_API
#undef PMG0CPMGMTEXPORT
#undef PMG0CPMGMTGLOBAL
#undef PMG0CPMGMTPRIVATE
