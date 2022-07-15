/*==============================================================================
                Copyright (c) 2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    File Description:

    The header file that undefines the export symbols for the USAGEWC library
 */

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef USAGEWC_API
#undef USAGEWCEXPORT
#undef USAGEWCGLOBAL
#undef USAGEWCPRIVATE

