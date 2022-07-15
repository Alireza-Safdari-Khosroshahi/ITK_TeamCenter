/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */


/**
    @file
    Errors for the SOA BOM services
*/

#ifndef SOABOM_ERRORS_H
#define SOABOM_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SOABOM_ERRORS Errors
    @ingroup SOABOM
    @{
*/
#define SOABOM_input_parentline_is_nulltag                      (EMH_SOABOM_error_base + 0)

#define SOABOM_failed_to_create_bomview                         (EMH_SOABOM_error_base + 1)

#define SOABOM_child_input_objects_are_nulltag                  (EMH_SOABOM_error_base + 2)

#define SOABOM_child_input_itemelement_is_nulltag               (EMH_SOABOM_error_base + 3)

#define SOABOM_failed_to_update_bomline_properties              (EMH_SOABOM_error_base + 4)

#define SOABOM_unable_to_add_item_line                          (EMH_SOABOM_error_base + 5)

#define SOABOM_unable_to_add_itemelement_line                   (EMH_SOABOM_error_base + 6)

#define SOABOM_unable_to_remove_child_bomline                   (EMH_SOABOM_error_base + 7)

#define SOABOM_input_childline_is_nulltag                       (EMH_SOABOM_error_base + 8)

/** @} */

#endif

