// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2006 UGS Corp. All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@


/** 
    @libdocmgt_undef.h 
    undefines for the Document Management library

*/

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif


#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef DOCMGT_API
#undef DOCMGTEXPORT
#undef DOCMGTGLOBAL
#undef DOCMGTPRIVATE

