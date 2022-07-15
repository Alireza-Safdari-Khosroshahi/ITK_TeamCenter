/*=============================================================================

===============================================================================
File Description:

    The header file that undefines the export symbols for the
    USER_EXITS library

===============================================================================
Date          Name                   Description
12-Mar-2007              Ram Narsimha               Initial Version
12-Mar-2007              Ram Kishore                Initial Version

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

#undef VM_API
#undef VMEXPORT
#undef VMGLOBAL
#undef VMPRIVATE
