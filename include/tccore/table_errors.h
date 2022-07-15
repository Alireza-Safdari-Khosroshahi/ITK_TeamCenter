/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2009.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    table errors

*/

#ifndef TABLE_ERRORS_H
#define TABLE_ERRORS_H

#include <common/emh_const.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup TABLE_ERRORS TABLE Errors
    @ingroup TABLE
    @{
*/

#define TABLE_ERROR_BASE                                           EMH_TABLE_error_base

#define TABLE_deserialize_tablecell_obj_failed_invalid_celltype    (TABLE_ERROR_BASE + 1)

/** @} */

#include <tccore/libtccore_undef.h>

#endif
