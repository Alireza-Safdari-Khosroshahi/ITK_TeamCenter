//@<COPYRIGHT>@
//==================================================
//Copyright $2021.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//e
//==================================================
//@<COPYRIGHT>@


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBQC0QUALITYBASE) && !defined(IPLIB)
#   error IPLIB or LIBQC0QUALITYBASE is not defined
#endif

#undef QC0QUALITYBASE_API
#undef QC0QUALITYBASEEXPORT
#undef QC0QUALITYBASEGLOBAL
#undef QC0QUALITYBASEPRIVATE
