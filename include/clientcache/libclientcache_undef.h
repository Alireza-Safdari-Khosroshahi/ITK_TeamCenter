// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2010 Siemens PLM Software. All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@

/**
    @file

    Abstract base class for a family of client cache manager classes. This
    class defines the required methods the derived classes must provide and also
    contains a number methods used by these classes.
*/

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef CLIENTCACHE_API
#undef CLIENTCACHEEXPORT
#undef CLIENTCACHEGLOBAL
#undef CLIENTCACHEPRIVATE

