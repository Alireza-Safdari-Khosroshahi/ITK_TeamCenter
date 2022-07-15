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

#if !defined(LIBWPM0PKGMGMT) && !defined(IPLIB)
#   error IPLIB or LIBWPM0PKGMGMT is not defined
#endif

#undef WPM0PKGMGMT_API
#undef WPM0PKGMGMTEXPORT
#undef WPM0PKGMGMTGLOBAL
#undef WPM0PKGMGMTPRIVATE
