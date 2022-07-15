/*=============================================================================
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
 ===============================================================================*/

/**
    @file
    CFILTER error codes.
*/

#ifndef CFILTER_ERRORS_H
#define CFILTER_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup CFILTER_ERRORS CFILTER Errors
    @ingroup CFILTER
    @{
*/

/** An internal error has occurred in the CFILTER module: %1$. */
#define CFILTER_internal_error                   (EMH_CFILTER_error_base + 1)

/** Filter that returns the union of the sets of configured objects cannot be instantiated with an empty list of filters. */
#define CFILTER_empty_union_cfilter              (EMH_CFILTER_error_base + 2)

/**
    @}
*/

#endif
