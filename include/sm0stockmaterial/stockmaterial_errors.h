/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2012.
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */

/**
     @file
     This file contains error messages for Stockmaterial.
*/

#ifndef STOCKMATERIAL_ERRORS_H
#define STOCKMATERIAL_ERRORS_H

#include <common/emh_const.h>
#include <sm0stockmaterial/libsm0stockmaterial_exports.h>

/**
    @defgroup STOCKMATERIAL_ERRORS Errors
    @ingroup STOCKMATERIAL
    @{
*/

/**
    The stock material is not program approved.
*/
#define STOCKMATERIAL_not_prefered                   (EMH_STOCKMATERIAL_error_base + 0)

/**
    An invalid cut dimension "%1$" is specified. The valid cut dimensions are "%2$".
*/
#define STOCKMATERIAL_invalid_cuts                   (EMH_STOCKMATERIAL_error_base + 1)

/**
    The operation has succeeded. The cut dimensions, however, have been saved but not used,
    because they are not applicable for relationships to a Part.
*/
#define STOCKMATERIAL_cuts_not_applicable            (EMH_STOCKMATERIAL_error_base + 2)

/**
    The "Made From" relation cannot be created between the same object.
*/
#define STOCKMATERIAL_cyclic_relation                (EMH_STOCKMATERIAL_error_base + 3)

/**
    The program preferred Item "%1$" cannot be deleted, because it is related to another Item Revision through the "Made From" relation. Please use the "Impact Analysis" tab view to find all the "Made From" related objects.
*/
#define STOCKMATERIAL_already_related                (EMH_STOCKMATERIAL_error_base + 4)

/**
    "%1$" was not saved because "%2$" is not modifiable.
*/
#define STOCKMATERIAL_cut_dimension_readonly_single  (EMH_STOCKMATERIAL_error_base + 5)

/**
    "%1$" was not saved because "%2$" are not modifiable.
*/
#define STOCKMATERIAL_cut_dimension_readonly_multi   (EMH_STOCKMATERIAL_error_base + 6)

/**
    "%1$" was not saved because "%2$" is required.
*/
#define STOCKMATERIAL_invalid_cuts_save_single       (EMH_STOCKMATERIAL_error_base + 7)

/**
    "%1$" was not saved because "%2$" are required.
*/
#define STOCKMATERIAL_invalid_cuts_save_multi        (EMH_STOCKMATERIAL_error_base + 8)
/**
    "%1$" was not added because "%2$" is required.
*/
#define STOCKMATERIAL_invalid_cuts_add_single        (EMH_STOCKMATERIAL_error_base + 9)

/**
    "%1$" was not added because "%2$" are required.
*/
#define STOCKMATERIAL_invalid_cuts_add_multi         (EMH_STOCKMATERIAL_error_base + 10)

/** @} */

#include <sm0stockmaterial/libsm0stockmaterial_undef.h>

#endif
