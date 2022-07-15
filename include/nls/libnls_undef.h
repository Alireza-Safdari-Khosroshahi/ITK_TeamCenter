// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software

/*
    File Description:

    The header file that undefines the export symbols for the NLS library
 */

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef NLS_API
#undef NLSEXPORT
#undef NLSGLOBAL
#undef NLSPRIVATE

