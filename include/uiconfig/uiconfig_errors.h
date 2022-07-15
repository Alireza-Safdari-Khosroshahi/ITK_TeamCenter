/* =================================================================================================
           Copyright (c) 2014 Unigraphics Solutions Inc., An EDS Company
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
====================================================================================================*/

/**
    @file

    Errors for uiconfig module


*/
#ifndef UICONFIG_ERRORS_H
#define UICONFIG_ERRORS_H

#include <common/emh_const.h>

#define UICONFIG_ERROR_BASE                                     EMH_UICONFIG_error_base

/**
The column configuration ID &quot;%1$&quot; is invalid.
*/
#define UICONFIG_invalid_column_config_id                       (UICONFIG_ERROR_BASE + 1)

/**
The column definition ID &quot;%1$&quot; is invalid.
*/
#define UICONFIG_invalid_column_def_id                          (UICONFIG_ERROR_BASE + 2)

/**
The object type &quot;%1$&quot; is invalid.
*/
#define UICONFIG_invalid_object_type_name                       (UICONFIG_ERROR_BASE + 3)

/**
The Property &quot;%1$&quot; is invalid.
*/
#define UICONFIG_invalid_property_name                           (UICONFIG_ERROR_BASE + 4)

/**
The pixel width &quot;%1$&quot; is invalid. The valid value must be an integer.
*/
#define UICONFIG_invalid_pixel_width                             (UICONFIG_ERROR_BASE + 5)

/**
The sort by column &quot;%1$&quot; is invalid because it does not exist.
*/
#define UICONFIG_invalid_sort_by_column                          (UICONFIG_ERROR_BASE + 6)

/**
The sort by column &quot;%1$&quot; is invalid because it does not exist.
*/
#define UICONFIG_invalid_sort_direction                          (UICONFIG_ERROR_BASE + 7)

/**
The object type &quot;%1$&quot; is different from existing object type of the column definition &quot;%2&quot;.
*/
#define UICONFIG_different_object_type_name                      (UICONFIG_ERROR_BASE + 8)

/**
The property &quot;%1$&quot; is different from existing property name of column definition &quot;%2&quot;.
*/
#define UICONFIG_different_property_name                         (UICONFIG_ERROR_BASE + 9)

/**
The client scope uri &quot;%1$&quot; does not exist.
*/
#define UICONFIG_no_such_client_scope_uri                        (UICONFIG_ERROR_BASE + 10)

/**
The command ID &quot;%1$&quot; is invalid.
*/
#define UICONFIG_invalid_command_id                              (UICONFIG_ERROR_BASE + 11)

#endif
