//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2013.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBPTN0PARTITIONTEMPLATE) && !defined(IPLIB)
#   error IPLIB orLIBPTN0PARTITIONTEMPLATE is not defined
#endif

#undef PTN0PARTITIONTEMPLATE_API
#undef PTN0PARTITIONTEMPLATEEXPORT
#undef PTN0PARTITIONTEMPLATEGLOBAL
#undef PTN0PARTITIONTEMPLATEPRIVATE
