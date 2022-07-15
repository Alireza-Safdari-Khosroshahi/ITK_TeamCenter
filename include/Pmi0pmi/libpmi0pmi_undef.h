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

#if !defined(LIBPMI0PMI) && !defined(IPLIB)
#   error IPLIB orLIBPMI0PMI is not defined
#endif

#undef PMI0PMI_API
#undef PMI0PMIEXPORT
#undef PMI0PMIGLOBAL
#undef PMI0PMIPRIVATE
