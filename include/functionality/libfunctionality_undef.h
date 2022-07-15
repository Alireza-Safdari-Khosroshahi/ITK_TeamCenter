//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2009.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/**
    @file

    The header file that undefines the export symbols for the functionality library
===============================================================================
Date          Name                   Description
02-Jun-2009   Zhang Lin              Init file
$HISTORY$
============================================================================
 */


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef FUNCTIONALITY_API
#undef FUNCTIONALITYEXPORT
#undef FUNCTIONALITYGLOBAL
#undef FUNCTIONALITYPRIVATE

