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

#if !defined(LIBMDL0MODEL) && !defined(IPLIB)
#   error IPLIB orLIBMDL0MODEL is not defined
#endif

#undef MDL0MODEL_API
#undef MDL0MODELEXPORT
#undef MDL0MODELGLOBAL
#undef MDL0MODELPRIVATE
