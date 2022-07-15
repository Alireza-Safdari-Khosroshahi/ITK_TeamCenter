// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2011.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software

/**
    @file

    Undefines the export symbols for the Fnd0formulamgmt library

*/

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef FND0FORMULAMGMT_API
#undef FND0FORMULAMGMTEXPORT
#undef FND0FORMULAMGMTGLOBAL
#undef FND0FORMULAMGMTPRIVATE
