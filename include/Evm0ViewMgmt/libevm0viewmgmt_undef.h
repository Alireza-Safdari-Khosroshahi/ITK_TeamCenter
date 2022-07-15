/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2019.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
==================================================
===============================================================================
File Description:

    The header file that undefines the export symbols for the
    USER_EXITS library

===============================================================================
Date                     Name                       Description

$HISTORY$
=============================================================================*/

#include <common/library_indicators.h>

#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(LIBEVM0VIEWMGMT) && !defined(IPLIB)
#   error IPLIB or LIBEVM0VIEWMGMT is not defined
#endif

#undef EVM0VIEWMGMT_API
#undef EVM0VIEWMGMTEXPORT
#undef EVM0VIEWMGMTGLOBAL
#undef EVM0VIEWMGMTPRIVATE
