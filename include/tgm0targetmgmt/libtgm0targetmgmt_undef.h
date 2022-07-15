//@<COPYRIGHT>@
//==================================================
//Copyright $2021.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//@<COPYRIGHT>@


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBTGM0TARGETMGMT) && !defined(IPLIB)
#   error IPLIB or LIBTGM0TARGETMGMT is not defined
#endif

#undef TGM0TARGETMGMT_API
#undef TGM0TARGETMGMTEXPORT
#undef TGM0TARGETMGMTGLOBAL
#undef TGM0TARGETMGMTPRIVATE
