// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2008 UGS Corp. All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef EXTENSIONFRAMEWORK_API
#undef EXTENSIONFRAMEWORKEXPORT
#undef EXTENSIONFRAMEWORKGLOBAL
#undef EXTENSIONFRAMEWORKPRIVATE

