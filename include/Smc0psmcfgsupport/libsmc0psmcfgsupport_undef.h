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

#if !defined(LIBSMC0PSMCFGSUPPORT) && !defined(IPLIB)
#   error IPLIB or LIBSMC0PSMCFGSUPPORT is not defined
#endif

#undef SMC0PSMCFGSUPPORT_API
#undef SMC0PSMCFGSUPPORTEXPORT
#undef SMC0PSMCFGSUPPORTGLOBAL
#undef SMC0PSMCFGSUPPORTPRIVATE
