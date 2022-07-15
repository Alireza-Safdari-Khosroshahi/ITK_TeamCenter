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

#if !defined(LIBCONTMGMTS1000D40) && !defined(IPLIB)
#   error IPLIB orLIBCONTMGMTS1000D40 is not defined
#endif

#undef CONTMGMTS1000D40_API
#undef CONTMGMTS1000D40EXPORT
#undef CONTMGMTS1000D40GLOBAL
#undef CONTMGMTS1000D40PRIVATE
