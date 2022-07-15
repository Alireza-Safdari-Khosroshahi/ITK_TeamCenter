// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2009.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software
 
/** 
    @file
    File Description:

    The header file that undefines the export symbols for the TCinit library
*/

/*  */

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef TCINIT_API
#undef TCINITEXPORT
#undef TCINITGLOBAL
#undef TCINITPRIVATE

