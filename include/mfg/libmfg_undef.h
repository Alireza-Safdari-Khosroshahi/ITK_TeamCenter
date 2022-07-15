//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2009.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/**
    @file

File description:
    The header file that undefines the export symbols for the MFG library
*/

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef MFG_API
#undef MFGEXPORT
#undef MFGGLOBAL
#undef MFGPRIVATE

