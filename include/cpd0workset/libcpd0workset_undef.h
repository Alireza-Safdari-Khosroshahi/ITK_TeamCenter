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

#if !defined(LIBCPD0WORKSET) && !defined(IPLIB)
#   error IPLIB orLIBCPD0WORKSET is not defined
#endif

#undef CPD0WORKSET_API
#undef CPD0WORKSETEXPORT
#undef CPD0WORKSETGLOBAL
#undef CPD0WORKSETPRIVATE
