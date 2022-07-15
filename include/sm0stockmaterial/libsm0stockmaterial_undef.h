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

#if !defined(LIBSM0STOCKMATERIAL) && !defined(IPLIB)
#   error IPLIB orLIBSM0STOCKMATERIAL is not defined
#endif

#undef SM0STOCKMATERIAL_API
#undef SM0STOCKMATERIALEXPORT
#undef SM0STOCKMATERIALGLOBAL
#undef SM0STOCKMATERIALPRIVATE
