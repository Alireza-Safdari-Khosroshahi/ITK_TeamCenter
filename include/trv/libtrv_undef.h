/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2015.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    The header file that undefines the export symbols for the TRV library

*/

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBTRV) && !defined(IPLIB)
#   error IPLIB orLIBTRV is not defined
#endif

#undef TRV_API
#undef TRVEXPORT
#undef TRVGLOBAL
#undef TRVPRIVATE
