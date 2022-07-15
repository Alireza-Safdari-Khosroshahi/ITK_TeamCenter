// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software

/**
    @libEpl0edalibrary_undef.h
    undefines for the EDA library

*/

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif


#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef EPL0EDALIBRARY_API
#undef EPL0EDALIBRARYEXPORT
#undef EPL0EDALIBRARYGLOBAL
#undef EPL0EDALIBRARYPRIVATE

