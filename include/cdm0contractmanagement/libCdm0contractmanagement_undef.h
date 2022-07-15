
//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2010.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

     The header file that undefines the export symbols for the CDM library

*/

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef CDM0CONTRACTMANAGEMENT_API
#undef CONTRACTMANAGEMENTEXPORT
#undef CONTRACTMANAGEMENTGLOBAL
#undef CONTRACTMANAGEMENTPRIVATE
