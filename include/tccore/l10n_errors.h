/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    Defines error codes used in l10n module

*/


#ifndef L10N_ERRORS_H
#define L10N_ERRORS_H

#include <common/emh_const.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup L10N_ERRORS ITK Errors
    @ingroup L10N
    @{
*/


#define L10N_no_input_objects                   (EMH_L10N_error_base + 1)
#define L10N_no_matching_objects_found          (EMH_L10N_error_base + 2)
#define L10N_xml_parsing_error_1                (EMH_L10N_error_base + 3)
#define L10N_xml_parsing_error_2                (EMH_L10N_error_base + 4)
#define L10N_unknown_xml_parsing_error          (EMH_L10N_error_base + 5)
#define L10N_no_privilege                       (EMH_L10N_error_base + 6)
#define L10N_invalid_translation_locale         (EMH_L10N_error_base + 7)
#define L10N_import_failure                     (EMH_L10N_error_base + 8)
#define L10N_no_output_file_provided            (EMH_L10N_error_base + 9)
#define L10N_prop_value_not_approved_state      (EMH_L10N_error_base + 10)




/** @} */

#include <tccore/libtccore_undef.h>
#endif
