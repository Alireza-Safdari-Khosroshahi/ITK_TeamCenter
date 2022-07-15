/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2008.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Content Management S1000D errors

*/


#ifndef CONTMGMTS1000D_ERRORS_H
#define CONTMGMTS1000D_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup CONTMGMTS1000D_ERRORS CONTMGMTS1000D Errors
    @ingroup CONTMGMTS1000D
    @{
*/

#define CONTMGMTS1000D_ERROR_BASE                               EMH_CONTMGMTS1000D_error_base
#define CONTMGMTS1000D_GENERAL_ERROR (CONTMGMTS1000D_ERROR_BASE + 0)

/**
    The creation of the Data Module failed.
*/
#define CONTMGMTS1000D_dm_fail                           (CONTMGMTS1000D_GENERAL_ERROR + 1)

/** @} */

#endif
