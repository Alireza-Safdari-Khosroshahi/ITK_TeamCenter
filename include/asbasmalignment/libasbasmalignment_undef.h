/*=============================================================================

===============================================================================
File Description:

    The header file that undefines the export symbols for the
    USER_EXITS library

===============================================================================
Date          Name                   Description

$HISTORY$
=============================================================================*/

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef ASBASMALIGNMENT_API
#undef ASBASMALIGNMENTEXPORT
#undef ASBASMALIGNMENTGLOBAL
#undef ASBASMALIGNMENTPRIVATE
