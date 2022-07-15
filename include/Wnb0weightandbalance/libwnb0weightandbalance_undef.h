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

#if !defined(LIBWNB0WEIGHTANDBALANCE) && !defined(IPLIB)
#   error IPLIB or LIBWNB0WEIGHTANDBALANCE is not defined
#endif

#undef WNB0WEIGHTANDBALANCE_API
#undef WNB0WEIGHTANDBALANCEEXPORT
#undef WNB0WEIGHTANDBALANCEGLOBAL
#undef WNB0WEIGHTANDBALANCEPRIVATE
