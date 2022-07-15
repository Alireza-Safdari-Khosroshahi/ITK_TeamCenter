//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2010.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBFND0NWEDITOR) && !defined(IPLIB)
#   error IPLIB orLIBFND0NWEDITOR is not defined
#endif

#undef FND0NWEDITOR_API
#undef FND0NWEDITOREXPORT
#undef FND0NWEDITORGLOBAL
#undef FND0NWEDITORPRIVATE
