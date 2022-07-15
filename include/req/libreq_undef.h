/*==============================================================================
                Copyright (c) 2006 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that undefines the export symbols for the REQ library
 */

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef REQ_API
#undef REQEXPORT
#undef REQGLOBAL
#undef REQPRIVATE

