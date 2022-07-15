/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2014.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file libfnd0emailpolling_undef.h

    The header file that undefines the export symbols for the Fnd0emailpolling library.
*/


/*  */

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBFND0EMAILPOLLING) && !defined(IPLIB)
#   error IPLIB orLIBFND0EMAILPOLLING is not defined
#endif

#undef FND0EMAILPOLLING_API
#undef FND0EMAILPOLLINGEXPORT
#undef FND0EMAILPOLLINGGLOBAL
#undef FND0EMAILPOLLINGPRIVATE
