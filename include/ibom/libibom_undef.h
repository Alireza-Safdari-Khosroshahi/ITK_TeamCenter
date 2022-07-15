/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2015.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    The header file that undefines the export symbols for the Index BOM library

*/
#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef IBOM_API
#undef IBOMEXPORT
#undef IBOMGLOBAL
#undef IBOMPRIVATE
