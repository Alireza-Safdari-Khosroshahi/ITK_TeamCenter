/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2013.
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

#if !defined(LIBLBR0LIBRARYMGMT) && !defined(IPLIB)
#   error IPLIB orLIBLBR0LIBRARYMGMT is not defined
#endif

#undef LBR0LIBRARYMGMT_API
#undef LBR0LIBRARYMGMTEXPORT
#undef LBR0LIBRARYMGMTGLOBAL
#undef LBR0LIBRARYMGMTPRIVATE
