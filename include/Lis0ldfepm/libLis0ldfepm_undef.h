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

    @libLis0ldfepm_undef.h
    undefines for the Lifecycle Interoperability Services Workflow library

**/

#include <common/library_indicators.h>


#if !defined(EXPORTLIB)
#   error EXPORTLIBRARY is not defined
#endif


#undef EXPORTLIB

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef LIS0LDFEPM_API
#undef LIS0LDFEPMEXPORT
#undef LIS0LDFEPMGLOBAL
#undef LIS0LDFEPMPRIVATE

