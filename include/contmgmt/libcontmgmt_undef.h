//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2008.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBCONTMGMT) && !defined(IPLIB)
#   error IPLIB orLIBCONTMGMT is not defined
#endif

#undef CONTMGMT_API
#undef CONTMGMTEXPORT
#undef CONTMGMTGLOBAL
#undef CONTMGMTPRIVATE
