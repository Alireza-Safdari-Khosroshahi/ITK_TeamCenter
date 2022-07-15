/*==============================================================================
 Copyright 2011.
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==============================================================================*/
/*
    File Description:

    The header file that undefines the export symbols for the FND0AUDIT_MGR library
 */

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBFND0AUDIT_MGR) && !defined(IPLIB)
#   error IPLIB orLIBFND0AUDIT_MGR is not defined
#endif

#undef FND0AUDIT_MGR_API
#undef FND0AUDIT_MGREXPORT
#undef FND0AUDIT_MGRGLOBAL
#undef FND0AUDIT_MGRPRIVATE

