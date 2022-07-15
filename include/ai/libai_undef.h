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

#if !defined(LIBAI) && !defined(IPLIB)
#   error IPLIB orLIBAI is not defined
#endif

#undef AI_API
#undef AIEXPORT
#undef AIGLOBAL
#undef AIPRIVATE
