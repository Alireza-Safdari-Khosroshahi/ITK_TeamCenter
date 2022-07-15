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

#if !defined(LIBMCI0MFGCHARACTERISTICSBVR) && !defined(IPLIB)
#   error IPLIB orLIBMCI0MFGCHARACTERISTICSBVR is not defined
#endif

#undef MCI0MFGCHARACTERISTICSBVR_API
#undef MCI0MFGCHARACTERISTICSBVREXPORT
#undef MCI0MFGCHARACTERISTICSBVRGLOBAL
#undef MCI0MFGCHARACTERISTICSBVRPRIVATE
