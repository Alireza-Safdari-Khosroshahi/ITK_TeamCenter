/*==============================================================================
                 Copyright 2006 UGS Corp. All Rights Reserved.
==============================================================================*/

/**
    @file

    The header file that defines the export symbols for the
    TCSOACLIENT library

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

#undef TCSOACLIENTMNGD_API
#undef TCSOACLIENTMNGDEXPORT
#undef TCSOACLIENTMNGDGLOBAL
#undef TCSOACLIENTMNGDPRIVATE
