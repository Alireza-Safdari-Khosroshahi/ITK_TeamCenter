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

#if !defined(LIBCFG0CONFIGURATOR) && !defined(IPLIB)
#   error IPLIB or LIBCFG0CONFIGURATOR is not defined
#endif

#undef CFG0CONFIGURATOR_API
#undef CFG0CONFIGURATOREXPORT
#undef CFG0CONFIGURATORGLOBAL
#undef CFG0CONFIGURATORPRIVATE
