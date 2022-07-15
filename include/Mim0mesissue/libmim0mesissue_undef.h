//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBMIM0MESISSUE) && !defined(IPLIB)
#   error IPLIB orLIBMIM0MESISSUE is not defined
#endif

#undef MIM0MESISSUE_API
#undef MIM0MESISSUEEXPORT
#undef MIM0MESISSUEGLOBAL
#undef MIM0MESISSUEPRIVATE
