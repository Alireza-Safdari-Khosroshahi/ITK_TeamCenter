/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2017.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file
    The header file that undefines the export symbols for the constraint solver library
*/

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef CONSTRAINTSOLVER_API
#undef CONSTRAINTSOLVEREXPORT
#undef CONSTRAINTSOLVERGLOBAL
#undef CONSTRAINTSOLVERPRIVATE


