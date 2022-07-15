// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2014.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software

/**
    @libLis0lisfmwrk_undef.h
    undefines for the Lifecycle Interoperability Services library

*/

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif


#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef LIS0LISFMWRK_API
#undef LIS0LISFMWRKEXPORT
#undef LIS0LISFMWRKGLOBAL
#undef LIS0LISFMWRKPRIVATE

