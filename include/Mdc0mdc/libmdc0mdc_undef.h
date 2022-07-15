//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2013.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBMDC0MDC) && !defined(IPLIB)
#   error IPLIB orLIBMDC0MDC is not defined
#endif

#undef MDC0MDC_API
#undef MDC0MDCEXPORT
#undef MDC0MDCGLOBAL
#undef MDC0MDCPRIVATE
