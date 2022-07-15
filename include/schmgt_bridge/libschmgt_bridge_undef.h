// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2006 UGS Corp. All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@


/** 
    @libschmgt_bridge_undef.h 
    undefines for the Schedule Management library

*/

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif


#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef SCHMGTBRI_API
#undef SCHMGTBRIEXPORT
#undef SCHMGTBRIGLOBAL
#undef SCHMGTBRIPRIVATE

