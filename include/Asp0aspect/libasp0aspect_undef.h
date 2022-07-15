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

#if !defined(LIBASP0ASPECT) && !defined(IPLIB)
#   error IPLIB or LIBASP0ASPECT is not defined
#endif

#undef ASP0ASPECT_API
#undef ASP0ASPECTEXPORT
#undef ASP0ASPECTGLOBAL
#undef ASP0ASPECTPRIVATE
