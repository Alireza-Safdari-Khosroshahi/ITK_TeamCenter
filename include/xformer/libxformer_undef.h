/* 
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2016.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    The header file that undefines the export symbols for the XFORMER library

*/

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBXFORMER) && !defined(IPLIB)
#   error IPLIB orLIBXFORMER is not defined
#endif

#undef XFORMER_API
#undef XFORMEREXPORT
#undef XFORMERGLOBAL
#undef XFORMERPRIVATE
