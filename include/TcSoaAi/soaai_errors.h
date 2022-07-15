/* =================================================================================================
           Copyright (c) 2010 Unigraphics Solutions Inc., A Siemens Company
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
====================================================================================================*/

/**
    @file

    Errors for the soa structure management services

    
*/

/** @if HISTORY_SECTION
   date         name                 description of change
$HISTORY$
==================================================================================================
@endif */

#ifndef SOAAI_ERRORS_H
#define SOAAI_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SOAAI_ERRORS Errors
    @ingroup SOAAI
    @{
*/

#define SOAAI_invalid_transfermode_name               (EMH_SOAAI_error_base + 0)
#define SOAAI_invalid_ai_object                       (EMH_SOAAI_error_base + 1)
#define SOAAI_empty_objects_to_process                (EMH_SOAAI_error_base + 2)
#define SOAAI_empty_xpaths_to_evaluate                (EMH_SOAAI_error_base + 3)
#define SOAAI_cannot_find_plmxml_file                 (EMH_SOAAI_error_base + 4)
#define SOAAI_cannot_create_Alias_object_factory      (EMH_SOAAI_error_base + 5)
#define SOAAI_cannot_create_Alias_object_handler      (EMH_SOAAI_error_base + 6)
#define SOAAI_cannot_load_structure_file              (EMH_SOAAI_error_base + 7)
#define SOAAI_alias_xpath_eval_error                  (EMH_SOAAI_error_base + 8)

/**
At least one label must be specified for processing.
*/
#define SOAAI_empty_labels_specified                  (EMH_SOAAI_error_base + 9)
/**
The specified label is not a valid PLMXML label. A label must be a valid PLMXML ApplicationRef element attribute.
*/
#define SOAAI_invalid_label_string                    (EMH_SOAAI_error_base + 10)

/**
Objects of type "%1$" could not be retrieved.
*/
#define SOAAI_failed_to_get_ai_types                  (EMH_SOAAI_error_base + 11)
/** @} */

#endif

