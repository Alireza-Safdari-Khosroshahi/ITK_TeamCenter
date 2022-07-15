/* Copyright 2020 Siemens Digital Industries Software
#===============================================================================
# Copyright 2017.
# Siemens Product Lifecycle Management Software Inc.
# All Rights Reserved.
#===============================================================================
# Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file
    Alignment of 4G PM with design PS represented as BVR related error codes declaration
*/

#ifndef BOM0PSDALIGNMENT_ERRORS_H
#define BOM0PSDALIGNMENT_ERRORS_H


#include <common/emh_const.h>

/**
    @defgroup BOM0PSDALIGNMENT_ERRORS Errors
    @ingroup BOMMGMT_ERRORS
    @{
*/

/**
* An internal error has occurred in the alignment of 4G Product Master data with Design Structure. Report this error to your system administrator.
*/
#define BOM0PSDALIGNMENT_internal_error                                  (EMH_BOM0PSDALIGNMENT_error_base + 1)

/**
* An alignment cannot be performed with the top line of a Design Structure.
*/
#define BOM0PSDALIGNMENT_top_line_for_alignment                          (EMH_BOM0PSDALIGNMENT_error_base + 2)

/** @} */
#endif
