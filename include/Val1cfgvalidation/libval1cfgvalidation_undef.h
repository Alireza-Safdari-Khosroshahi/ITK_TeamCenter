/*Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2018.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBVAL1CFGVALIDATION) && !defined(IPLIB)
#   error IPLIB or LIBVAL1CFGVALIDATION is not defined
#endif

#undef VAL1CFGVALIDATION_API
#undef VAL1CFGVALIDATIONEXPORT
#undef VAL1CFGVALIDATIONGLOBAL
#undef VAL1CFGVALIDATIONPRIVATE
