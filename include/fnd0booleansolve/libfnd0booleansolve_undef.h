/*==============================================================================
                Copyright (c) 2003-2005 SIEMENS
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that undefines the export symbols for the PS library
 */

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef FND0BOOLEANSOLVE_API
#undef FND0BOOLEANSOLVEEXPORT
#undef FND0BOOLEANSOLVEGLOBAL
#undef FND0BOOLEANSOLVEPRIVATE


