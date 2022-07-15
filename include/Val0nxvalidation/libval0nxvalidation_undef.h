/*Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2015.
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

#if !defined(LIBVAL0NXVALIDATION) && !defined(IPLIB)
#   error IPLIB or LIBVAL0NXVALIDATION is not defined
#endif

#undef VAL0NXVALIDATION_API
#undef VAL0NXVALIDATIONEXPORT
#undef VAL0NXVALIDATIONGLOBAL
#undef VAL0NXVALIDATIONPRIVATE
