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

#if !defined(LIBBOM0BOMMANAGEMENT) && !defined(IPLIB)
#   error IPLIB or LIBBOM0BOMMANAGEMENT is not defined
#endif

#undef BOM0BOMMANAGEMENT_API
#undef BOM0BOMMANAGEMENTEXPORT
#undef BOM0BOMMANAGEMENTGLOBAL
#undef BOM0BOMMANAGEMENTPRIVATE
