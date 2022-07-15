//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright 2014.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/**
    @libOsl0lisoslc_undef.h
    undefines for the Lifecycle Interoperability Services for OSLC support library

*/

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBOSL0LISOSLC) && !defined(IPLIB)
#   error IPLIB orLIBOSL0LISOSLC is not defined
#endif

#undef OSL0LISOSLC_API
#undef OSL0LISOSLCEXPORT
#undef OSL0LISOSLCGLOBAL
#undef OSL0LISOSLCPRIVATE
