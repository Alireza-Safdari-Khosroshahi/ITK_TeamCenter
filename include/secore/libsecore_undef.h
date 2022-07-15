//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2010.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBSECORE) && !defined(IPLIB)
#   error IPLIB or LIBSECORE is not defined
#endif

#undef SECORE_API
#undef SECOREEXPORT
#undef SECOREGLOBAL
#undef SECOREPRIVATE
