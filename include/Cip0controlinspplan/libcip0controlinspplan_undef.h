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

#if !defined(LIBCIP0CONTROLINSPPLAN) && !defined(IPLIB)
#   error IPLIB or LIBCIP0CONTROLINSPPLAN is not defined
#endif

#undef CIP0CONTROLINSPPLAN_API
#undef CIP0CONTROLINSPPLANEXPORT
#undef CIP0CONTROLINSPPLANGLOBAL
#undef CIP0CONTROLINSPPLANPRIVATE
