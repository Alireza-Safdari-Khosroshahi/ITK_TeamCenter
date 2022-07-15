/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2014.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/


#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBFND0QUALIFICATION) && !defined(IPLIB)
#   error IPLIB orLIBFND0QUALIFICATION is not defined
#endif

#undef FND0QUALIFICATION_API
#undef FND0QUALIFICATIONEXPORT
#undef FND0QUALIFICATIONGLOBAL
#undef FND0QUALIFICATIONPRIVATE
