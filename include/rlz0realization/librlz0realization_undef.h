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

#if !defined(LIBRLZ0REALIZATION) && !defined(IPLIB)
#   error IPLIB orLIBRLZ0REALIZATION is not defined
#endif

#undef RLZ0REALIZATION_API
#undef RLZ0REALIZATIONEXPORT
#undef RLZ0REALIZATIONGLOBAL
#undef RLZ0REALIZATIONPRIVATE
