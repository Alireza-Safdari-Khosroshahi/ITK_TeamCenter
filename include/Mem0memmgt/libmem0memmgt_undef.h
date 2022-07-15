//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2011.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBMEM0MEMMGT) && !defined(IPLIB)
#   error IPLIB orLIBMEM0MEMMGT is not defined
#endif

#undef MEM0MEMMGT_API
#undef MEM0MEMMGTEXPORT
#undef MEM0MEMMGTGLOBAL
#undef MEM0MEMMGTPRIVATE
