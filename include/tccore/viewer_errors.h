/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    Defines error codes used in VIEWER module
*/


#ifndef VIEWER_ERRORS_H
#define VIEWER_ERRORS_H

#include <common/emh_const.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup VIEWER_ERRORS Errors
    @ingroup VIEWER
    @{
*/

#define VIEWER_undefined_preference        (EMH_VIEWER_error_base + 1)
#define VIEWER_no_preference_value         (EMH_VIEWER_error_base + 2)
#define VIEWER_preference_is_malformed     (EMH_VIEWER_error_base + 3)

/** @} */

#include <tccore/libtccore_undef.h>
#endif
