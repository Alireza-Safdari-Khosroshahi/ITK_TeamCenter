/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    FORM errors
*/

/*  */

#ifndef FORM_ERRORS_H
#define FORM_ERRORS_H

#include <common/emh_const.h>
#include <form/libform_exports.h>

/**
    @defgroup FORM_ERRORS Errors
    @ingroup FORM
    @{
*/

/** Unknown internal error in Form */
#define FORM_unknown                        EMH_FORM_error_base +  0

/** Def file doesn't exist or POMClassName not defined in file */
#define FORM_definition_file                EMH_FORM_error_base +  1

/** POM class doesn't exist */
#define FORM_invalid_POM_class              EMH_FORM_error_base +  2

/** Value for attribute is bad */
#define FORM_bad_value                      EMH_FORM_error_base +  3

/** POMClassName in uil file is missing or invalid */
#define FORM_POMClassName                   EMH_FORM_error_base +  4

#define FORM_create_error                   EMH_FORM_error_base +  5
#define FORM_delete_error                   EMH_FORM_error_base +  6
#define FORM_load_error                     EMH_FORM_error_base +  7
#define FORM_unload_error                   EMH_FORM_error_base +  8
#define FORM_save_error                     EMH_FORM_error_base +  9
#define FORM_refresh_error                  EMH_FORM_error_base + 10
#define FORM_copy_error                     EMH_FORM_error_base + 11
#define FORM_bad_name                       EMH_FORM_error_base + 12

#define FORM_duplicate_widget_name          EMH_FORM_error_base + 13
#define FORM_invalid_form_entry_string      EMH_FORM_error_base + 14
#define FORM_invalid_non_null_data          EMH_FORM_error_base + 15
#define FORM_no_field_for_label             EMH_FORM_error_base + 16
#define FORM_invalid_class_name             EMH_FORM_error_base + 17
#define FORM_no_change_type                 EMH_FORM_error_base + 18
#define FORM_no_read_values                 EMH_FORM_error_base + 19
#define FORM_no_top_level_dialog_widget     EMH_FORM_error_base + 20

#define FORM_type_already_exits             EMH_FORM_error_base + 21
#define FORM_type_no_type_exists            EMH_FORM_error_base + 22
#define FORM_type_instance_referenced       EMH_FORM_error_base + 23
#define FORM_cannot_open_pref_file          EMH_FORM_error_base + 24
#define FORM_type_cant_modify_name          EMH_FORM_error_base + 25
#define FORM_type_wrong_type                EMH_FORM_error_base + 26
#define FORM_type_no_uid_or_class           EMH_FORM_error_base + 27
#define FORM_type_nota_privileged_user      EMH_FORM_error_base + 28
#define FORM_no_form_data                   EMH_FORM_error_base + 29
#define FORM_type_name_clash_with_classname EMH_FORM_error_base + 30
#define FORM_type_wrong_class            EMH_FORM_error_base + 31

/** @} */


#include <form/libform_undef.h>
#endif
