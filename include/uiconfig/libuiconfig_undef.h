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

#if !defined(LIBUICONFIG) && !defined(IPLIB)
#   error IPLIB or LIBUICONFIG is not defined
#endif

#undef UICONFIG_API
#undef UICONFIGEXPORT
#undef UICONFIGGLOBAL
#undef UICONFIGPRIVATE
