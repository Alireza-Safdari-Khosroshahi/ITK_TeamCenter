/*Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2019.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
//Copyright 2020 Siemens Digital Industries Software*/


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBPMA0AUTOMATION) && !defined(IPLIB)
#   error IPLIB or LIBPMA0AUTOMATION is not defined
#endif

#undef PMA0AUTOMATION_API
#undef PMA0AUTOMATIONEXPORT
#undef PMA0AUTOMATIONGLOBAL
#undef PMA0AUTOMATIONPRIVATE
