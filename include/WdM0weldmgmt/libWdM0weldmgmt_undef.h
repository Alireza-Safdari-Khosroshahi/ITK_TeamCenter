//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2011.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBWDM0WELDMGMT) && !defined(IPLIB)
#   error IPLIB orLIBWDM0WELDMGMT is not defined
#endif

#undef WDM0WELDMGMT_API
#undef WDM0WELDMGMTEXPORT
#undef WDM0WELDMGMTGLOBAL
#undef WDM0WELDMGMTPRIVATE
