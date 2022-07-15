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

#if !defined(LIBMAT1MATERIALMGMT) && !defined(IPLIB)
#   error IPLIB orLIBMAT1MATERIALMGMT is not defined
#endif

#undef MAT1MATERIALMGMT_API
#undef MAT1MATERIALMGMTEXPORT
#undef MAT1MATERIALMGMTGLOBAL
#undef MAT1MATERIALMGMTPRIVATE
