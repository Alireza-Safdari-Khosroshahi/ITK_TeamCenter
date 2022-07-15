/* 
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2018.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/
 
/** 
    @file 
 
    The header file that undefines export symbols for the variabilityadaptor library.
 */

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef VARIABILITYADAPTOR_API
#undef VARIABILITYADAPTOREXPORT
#undef VARIABILITYADAPTORGLOBAL
#undef VARIABILITYADAPTORPRIVATE
