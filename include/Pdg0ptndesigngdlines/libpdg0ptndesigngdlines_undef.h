//@<COPYRIGHT>@
//==================================================
//Copyright $2021.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//@<COPYRIGHT>@


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBPDG0PTNDESIGNGDLINES) && !defined(IPLIB)
#   error IPLIB or LIBPDG0PTNDESIGNGDLINES is not defined
#endif

#undef PDG0PTNDESIGNGDLINES_API
#undef PDG0PTNDESIGNGDLINESEXPORT
#undef PDG0PTNDESIGNGDLINESGLOBAL
#undef PDG0PTNDESIGNGDLINESPRIVATE
