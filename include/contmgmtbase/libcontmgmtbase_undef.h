/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2008.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    The header file that undefines the export symbols for the CONTMGMTBASE library

*/

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef CONTMGMTBASE_API
#undef CONTMGMTBASEEXPORT
#undef CONTMGMTBASEGLOBAL
#undef CONTMGMTBASEPRIVATE
