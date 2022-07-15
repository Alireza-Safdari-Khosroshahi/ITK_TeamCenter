// Copyright 2020 Siemens Digital Industries Software
// ========================================================================
// Copyright 2008.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ========================================================================
// Copyright 2020 Siemens Digital Industries Software

/*=============================================================================
    @file       : libadsfoundation_undef.h

    Description:
    The header file that undefines the export symbols for the ADSFOUNDATION library

=============================================================================*/

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef ADSFOUNDATION_API
#undef ADSFOUNDATIONEXPORT
#undef ADSFOUNDATIONGLOBAL
#undef ADSFOUNDATIONPRIVATE
