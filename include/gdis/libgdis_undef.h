/*==============================================================================
                     Copyright (c) UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Header File that undefines the export symbols for gdis module
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

#undef GDIS_API
#undef GDISEXPORT
#undef GDISGLOBAL
#undef GDISPRIVATE
