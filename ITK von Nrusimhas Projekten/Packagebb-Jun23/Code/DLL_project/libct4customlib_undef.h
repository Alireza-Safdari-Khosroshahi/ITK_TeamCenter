//@<COPYRIGHT>@
//==================================================
//Copyright $2022.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//@<COPYRIGHT>@


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBCT4CUSTOMLIB) && !defined(IPLIB)
#   error IPLIB or LIBCT4CUSTOMLIB is not defined
#endif

#undef CT4CUSTOMLIB_API
#undef CT4CUSTOMLIBEXPORT
#undef CT4CUSTOMLIBGLOBAL
#undef CT4CUSTOMLIBPRIVATE
