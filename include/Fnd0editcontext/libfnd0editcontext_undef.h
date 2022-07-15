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

#if !defined(LIBFND0EDITCONTEXT) && !defined(IPLIB)
#   error IPLIB or LIBFND0EDITCONTEXT is not defined
#endif

#undef FND0EDITCONTEXT_API
#undef FND0EDITCONTEXTEXPORT
#undef FND0EDITCONTEXTGLOBAL
#undef FND0EDITCONTEXTPRIVATE
