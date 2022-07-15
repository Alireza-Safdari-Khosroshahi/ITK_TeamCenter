/* 
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2016
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
*/

/*
    File Description:

    The header file that undefines the export symbols for the Fnd0Mrm library
 */

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef MRM_API
#undef MRMEXPORT
#undef MRMGLOBAL
#undef MRMPRIVATE
