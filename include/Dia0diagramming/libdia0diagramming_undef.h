/*
//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2015.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software
*/

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBDIA0DIAGRAMMING) && !defined(IPLIB)
#   error IPLIB orLIBMDC0MDC is not defined
#endif

#undef DIA0DIAGRAMMING_API
#undef DIA0DIAGRAMMINGEXPORT
#undef DIA0DIAGRAMMINGGLOBAL
#undef DIA0DIAGRAMMINGPRIVATE
