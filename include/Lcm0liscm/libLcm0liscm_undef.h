/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2017.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @libLcm0liscm_undef.h
    undefines for the Change Management integration using Linked Data Framework library

*/

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif


#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef LCM0LISCM_API
#undef LCM0LISCMEXPORT
#undef LCM0LISCMGLOBAL
#undef LCM0LISCMPRIVATE

