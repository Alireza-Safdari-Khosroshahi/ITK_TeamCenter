//@<COPYRIGHT>@
//==================================================
//Copyright $2021.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//e
//==================================================
//@<COPYRIGHT>@


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBCPA0CAPADATAMODEL) && !defined(IPLIB)
#   error IPLIB or LIBCPA0CAPADATAMODEL is not defined
#endif

#undef CPA0CAPADATAMODEL_API
#undef CPA0CAPADATAMODELEXPORT
#undef CPA0CAPADATAMODELGLOBAL
#undef CPA0CAPADATAMODELPRIVATE
