/*Copyright 2020 Siemens Digital Industries Software
  ==================================================
  Copyright 2014.
  Siemens Product Lifecycle Management Software Inc.
  All Rights Reserved.
  ==================================================
  Copyright 2020 Siemens Digital Industries Software

File description:

    File   : express_errors.h
    Module : Teamcenter Express

====================================================================================================
   date         name                 description of change

$HISTORY$
==================================================================================================*/
#ifndef EXPRESS_ERRORS_H
#define EXPRESS_ERRORS_H

#include <common/emh_const.h>

#define EXPRESS_ERROR_BASE         EMH_EXPRESS_error_base

#define EXPRESS_ERROR_RN_CHECKED_OUT                    ( EXPRESS_ERROR_BASE + 1 )
#define EXPRESS_ERROR_RN_NO_WRITE_PRIVILEGE             ( EXPRESS_ERROR_BASE + 2 )
#define EXPRESS_ERROR_RN_NOT_MODIFIABLE                 ( EXPRESS_ERROR_BASE + 3 )

#define EXPRESS_ERROR_FRG_NOTCHANGEPRIVILEGE            ( EXPRESS_ERROR_BASE + 4 )
#define EXPRESS_ERROR_FRG_FAILONSELECTEDWSO             ( EXPRESS_ERROR_BASE + 5 )
#define EXPRESS_ERROR_FRG_CHANGESTATENOTALLOW           ( EXPRESS_ERROR_BASE + 6 )
#define EXPRESS_ERROR_FRG_FAILONNEEDFIELDS              ( EXPRESS_ERROR_BASE + 7 )
#define EXPRESS_ERROR_FRG_FAILONCHECKOUT                ( EXPRESS_ERROR_BASE + 8 )
#define EXPRESS_ERROR_FRG_MENUCODENOTCONFIG             ( EXPRESS_ERROR_BASE + 9 )
#define EXPRESS_ERROR_FRG_NOT_INIT                      ( EXPRESS_ERROR_BASE + 10 )
#define EXPRESS_ERROR_FRG_INVALID_LASTREVSTATE          ( EXPRESS_ERROR_BASE + 11 )

#define EXPRESS_ERROR_ATTRCOPY_FAILONSELECTEDWSO        ( EXPRESS_ERROR_BASE + 12 )
#define EXPRESS_ERROR_ATTRCOPY_EMPTYCLIPBOARD           ( EXPRESS_ERROR_BASE + 13 )
#define EXPRESS_ERROR_RENAME_FAILONSELECTEDWSO          ( EXPRESS_ERROR_BASE + 14 )

#define RH_invalid_number_of_sheet                      ( EXPRESS_ERROR_BASE + 15 )
#define RH_get_form_value_failed                        ( EXPRESS_ERROR_BASE + 16 )
#define RH_wrong_decimal_sign                           ( EXPRESS_ERROR_BASE + 17 )
#define RH_bom_checked_out                              ( EXPRESS_ERROR_BASE + 18 )
#define RH_too_many_pref_values                         ( EXPRESS_ERROR_BASE + 19 )
#define RH_pref_value_too_long                          ( EXPRESS_ERROR_BASE + 20 )
#define RH_PrefListString_too_small                     ( EXPRESS_ERROR_BASE + 21 )
#define RH_no_pref_values                               ( EXPRESS_ERROR_BASE + 22 )
#define RH_no_valid_status                              ( EXPRESS_ERROR_BASE + 23 )

#define AH_no_folder_copy                               ( EXPRESS_ERROR_BASE + 24 )
#define AH_no_target_insert                             ( EXPRESS_ERROR_BASE + 25 )
#define AH_no_object_found                              ( EXPRESS_ERROR_BASE + 26 )
#define AH_log_entry_exists                             ( EXPRESS_ERROR_BASE + 27 )
#define AH_duplicate_object                             ( EXPRESS_ERROR_BASE + 28)
#define AH_no_object_remove                             ( EXPRESS_ERROR_BASE + 29 )
#define AH_no_form_write                                ( EXPRESS_ERROR_BASE + 30 )
#define AH_init_CR_failed                               ( EXPRESS_ERROR_BASE + 31 )
#define AH_no_abort_job                                 ( EXPRESS_ERROR_BASE + 32 )
#define AH_no_rev_attach                                ( EXPRESS_ERROR_BASE + 33 )
#define AH_multi_occurences                             ( EXPRESS_ERROR_BASE + 34 )
#define AH_relation_error                               ( EXPRESS_ERROR_BASE + 35 )
#define AH_type_error                                   ( EXPRESS_ERROR_BASE + 36 )
#define AH_memory_allocation_error                      ( EXPRESS_ERROR_BASE + 37)
#define AH_no_target_object_added                       ( EXPRESS_ERROR_BASE + 38 )
#define AH_multiple_forms_found                         ( EXPRESS_ERROR_BASE + 39 )
#define AH_CR_terminates                                ( EXPRESS_ERROR_BASE + 40 )
#define AH_wrong_field_pair                             ( EXPRESS_ERROR_BASE + 41 )
#define AH_wrong_argument_pair                          ( EXPRESS_ERROR_BASE + 42 )
#define AH_pref_not_defined                             ( EXPRESS_ERROR_BASE + 43 )
#define AH_invalid_attr_type                            ( EXPRESS_ERROR_BASE + 44 )
#define AH_invalid_pref_count                           ( EXPRESS_ERROR_BASE + 45 )
#define AH_no_errors                                    ( EXPRESS_ERROR_BASE + 46 )
#define AH_field_not_found                              ( EXPRESS_ERROR_BASE + 47 )
#define AH_prop_type_not_implemented                    ( EXPRESS_ERROR_BASE + 48 )
#define AH_attr_type_not_implemented                    ( EXPRESS_ERROR_BASE + 49 )
#define AH_attr_has_no_value                            ( EXPRESS_ERROR_BASE + 50 )
#define AH_frame_type_name_too_long                     ( EXPRESS_ERROR_BASE + 51 )
#define AH_user_mapfile_not_found                       ( EXPRESS_ERROR_BASE + 52 )
#define AH_user_map_not_found                           ( EXPRESS_ERROR_BASE + 53 )
#define AH_no_transfer_file_created                     ( EXPRESS_ERROR_BASE + 54 )
#define AH_env_var_perror_not_found                     ( EXPRESS_ERROR_BASE + 55 )
#define AH_ufunc_error                                  ( EXPRESS_ERROR_BASE + 56 )
#define AH_wrong_relation                               ( EXPRESS_ERROR_BASE + 57 )
#define AH_invalid_dtype                                ( EXPRESS_ERROR_BASE + 58 )
/*  */
#define AH_invalid_fext                                 ( EXPRESS_ERROR_BASE + 61 )
#define AH_no_image_file_created                        ( EXPRESS_ERROR_BASE + 62 )
#define AH_option_not_defined                           ( EXPRESS_ERROR_BASE + 63 )
#define AH_invalid_pref_set                             ( EXPRESS_ERROR_BASE + 64 )
#define AH_invalid_item_id                              ( EXPRESS_ERROR_BASE + 65 )
#define AH_time_convert_error                           ( EXPRESS_ERROR_BASE + 66 )
#define AH_argument_string_len                          ( EXPRESS_ERROR_BASE + 67 )
#define AH_prop_not_found                               ( EXPRESS_ERROR_BASE + 68 )
#define AH_drw_not_set                                  ( EXPRESS_ERROR_BASE + 69 )
#define AH_dataset_type_not_in_db                       ( EXPRESS_ERROR_BASE + 70 )
#define AH_tool_type_not_in_db                          ( EXPRESS_ERROR_BASE + 71 )
#define AH_no_tool_format                               ( EXPRESS_ERROR_BASE + 72 )
#define AH_reference_not_found                          ( EXPRESS_ERROR_BASE + 73 )
#define AH_format_string_invalid                        ( EXPRESS_ERROR_BASE + 74 )
#define AH_no_img_reference_found                       ( EXPRESS_ERROR_BASE + 75 )
#define AH_prop_value_string                            ( EXPRESS_ERROR_BASE + 76 )
/** AH_error_condition */ 
#define AH_wrong_password                               ( EXPRESS_ERROR_BASE + 77 )
#define AH_native_file_spec_too_long                    ( EXPRESS_ERROR_BASE + 78 )
#define AH_argument_does_not_exist                      ( EXPRESS_ERROR_BASE + 79 )


/** Nothing to Register, so continue with standard */ 
#define EXPRESS_DYN_BYPASS                              ( EXPRESS_ERROR_BASE + 80 )
/** Load Module Library Error          - library  */ 
#define EXPRESS_DYN_MODULE_LOAD_ERROR                   ( EXPRESS_ERROR_BASE + 81 ) 
/** Module Configuration Error         - ini-File */ 
#define EXPRESS_DYN_MODULE_CONF_ERROR                   ( EXPRESS_ERROR_BASE + 82 ) 
/** Load Function from Module Error    - library  */ 
#define EXPRESS_DYN_FUNCTION_LOAD_ERROR                 ( EXPRESS_ERROR_BASE + 83 ) 
/** Function Configuration Error       - ini-File */ 
#define EXPRESS_DYN_FUNCTION_CONF_ERROR                 ( EXPRESS_ERROR_BASE + 84 ) 
/** Method Type Configuration Error    - ini-File */ 
#define EXPRESS_DYN_METHOD_TYPE_CONF_ERROR              ( EXPRESS_ERROR_BASE + 85 ) 
/** Method Object Configuration Error  - ini-File */ 
#define EXPRESS_DYN_METHOD_OBJECT_CONF_ERROR            ( EXPRESS_ERROR_BASE + 86 ) 
#define EXPRESS_DYN_METHOD_MESSAGE_CONF_ERROR           ( EXPRESS_ERROR_BASE + 87 )

#define EXPRESS_ERROR_UNSPEC                            ( EXPRESS_ERROR_BASE + 88 )

#define EXPRESS_ERROR_TOOL_NOTAVALIBLE                  ( EXPRESS_ERROR_BASE + 89 )
/*  */
#define EXPRESS_ERROR_NAMREV_NOTAVALIBLE                ( EXPRESS_ERROR_BASE + 91 )
#define EXPRESS_ERROR_NOFOLDERSELECTION                 ( EXPRESS_ERROR_BASE + 92 )
#define EXPRESS_ERROR_FORMNOTFOUND                      ( EXPRESS_ERROR_BASE + 93 )
#define EXPRESS_ERROR_NOREFERENZFOUND                   ( EXPRESS_ERROR_BASE + 94 )
#define EXPRESS_ERROR_FORMNOTMODIFIABLE                 ( EXPRESS_ERROR_BASE + 95 )
#define EXPRESS_ERROR_PARTNOTMODIFIABLE                 ( EXPRESS_ERROR_BASE + 96 )
#define EXPRESS_ERROR_DSTYPE_NOTAVALIBLE                ( EXPRESS_ERROR_BASE + 97 )

#define EXPRESS_ERROR_NG_INVALID_ID                     ( EXPRESS_ERROR_BASE + 98 )
#define EXPRESS_ERROR_NG_INVALID_REVID                  ( EXPRESS_ERROR_BASE + 99 )
#define EXPRESS_ERROR_NG_INVALID_NAME                   ( EXPRESS_ERROR_BASE + 100 )

#define EXPRESS_ERROR_ME10_NOTSELECT_ME10PART           ( EXPRESS_ERROR_BASE + 101 )
#define EXPRESS_ERROR_ME10_MENU_NOTPOS_ATFIRST          ( EXPRESS_ERROR_BASE + 102 )
#define EXPRESS_ERROR_ME10_PART_REFERROR                ( EXPRESS_ERROR_BASE + 103 )

#define EXPRESS_ERROR_PLOT_UNDEFINED                    ( EXPRESS_ERROR_BASE + 118 )
#define EXPRESS_ERROR_PLOT_NOT_MODIFIABLE               ( EXPRESS_ERROR_BASE + 119 )
#define EXPRESS_ERROR_PLOT_NOJOBFOLDER                  ( EXPRESS_ERROR_BASE + 120 )
#define EXPRESS_ERROR_PLOT_TOOL_NOTFOUND                ( EXPRESS_ERROR_BASE + 121 )
#define EXPRESS_ERROR_PLOT_DATASET_NOTFOUND             ( EXPRESS_ERROR_BASE + 122 )
#define EXPRESS_ERROR_PLOT_INIT                         ( EXPRESS_ERROR_BASE + 123 )

#define EXPRESS_ERROR_CONNECT_TO_PPSDB                  ( EXPRESS_ERROR_BASE + 124 )
#define EXPRESS_ERROR_ORACLE                            ( EXPRESS_ERROR_BASE + 125 )

#define EXPRESS_MENUENTRY_OPENTIFF                      ( EXPRESS_ERROR_BASE + 126 )
#define EXPRESS_MENUENTRY_OPENCGM                       ( EXPRESS_ERROR_BASE + 127 )
#define EXPRESS_MENUENTRY_OPENHPP                       ( EXPRESS_ERROR_BASE + 128 )

#define EXPRESS_MENUENTRY_OPENPARTATTR                  ( EXPRESS_ERROR_BASE + 129 )
#define EXPRESS_MENUENTRY_RENAMEID                      ( EXPRESS_ERROR_BASE + 130 )

#define EXPRESS_MENUENTRY_FREIGABE                      ( EXPRESS_ERROR_BASE + 131 )

#define RH_wrong_status                                 ( EXPRESS_ERROR_BASE + 132 )
#define RH_wrong_rev_format                             ( EXPRESS_ERROR_BASE + 133 )
#define RH_wrong_group                                  ( EXPRESS_ERROR_BASE + 134 )
#define RH_cr_job_running                               ( EXPRESS_ERROR_BASE + 135 )
#define RH_wrong_target                                 ( EXPRESS_ERROR_BASE + 136 )
#define RH_string_error                                 ( EXPRESS_ERROR_BASE + 137 )
#define RH_release_status_error                         ( EXPRESS_ERROR_BASE + 138 )
#define RH_relation_not_found                           ( EXPRESS_ERROR_BASE + 139 )
#define RH_option_not_defined                           ( EXPRESS_ERROR_BASE + 140 )
#define RH_check_part_error                             ( EXPRESS_ERROR_BASE + 141 )
#define RH_ufunc_error                                  ( EXPRESS_ERROR_BASE + 142 )
#define RH_invalid_pref_set                             ( EXPRESS_ERROR_BASE + 143 )
#define RH_no_ugpaform_found                            ( EXPRESS_ERROR_BASE + 144 )
#define RH_ugpaf_invalid_value                          ( EXPRESS_ERROR_BASE + 145 )
#define RH_invalid_sheet_number                         ( EXPRESS_ERROR_BASE + 146 )
#define EXPRESS_No_Dataset_NamedRef_Found               ( EXPRESS_ERROR_BASE + 147 )
#define EXPRESS_ItemRev_Attachemnts_Processing_Error    ( EXPRESS_ERROR_BASE + 148 )
#define EXPRESS_ItemRev_Processing_Error                ( EXPRESS_ERROR_BASE + 149 )
#define EXPRESS_Package_List_Not_Created                ( EXPRESS_ERROR_BASE + 150 )
#define EXPRESS_Transient_Volume_Error                  ( EXPRESS_ERROR_BASE + 151 )

/** An error has occurred while retrieving predefined mappings. Check the mapping definitions
    in the configuration file and reimport the mappings. Alternatively, please check the
    Teamcenter server syslog file for more information and contact your system administrator.*/
#define EXPRESS_unable_to_retrieve_mappings             ( EXPRESS_ERROR_BASE + 152 )

/** The master form could not be updated. Verify the "write" privilege on the master form..
    Alternatively, please check the Teamcenter syslog file for more information and contact
    your system administrator.*/
#define EXPRESS_unable_to_update_master_form            ( EXPRESS_ERROR_BASE + 153 )

/** The file properties could not be updated. Verify the "read" privilege on the master form.
    Alternatively, please check the Teamcenter syslog file for more information and contact
    your system administrator.*/
#define EXPRESS_unable_to_update_file_properties        ( EXPRESS_ERROR_BASE + 154 )

/** The summary information for the file "%1$" could not be retrieved. Please verify its "read" privilege.
    Alternatively, please check the Teamcenter syslog file for more information and contact your system administrator.*/
#define EXPRESS_unable_to_retrive_summary_information   ( EXPRESS_ERROR_BASE + 155 )

/** The properties information for the file "%1$" could not be retrieved. Please verify its "read" privilege.
    Alternatively, please check the Teamcenter syslog file for more information and contact your system administrator.*/
#define EXPRESS_unable_to_retrive_custom_information    ( EXPRESS_ERROR_BASE + 156 )

/** The file information for the file "%1$" could not be retrieved. Please verify its "read" privilege.
    Alternatively, please check the Teamcenter syslog file for more information and contact your system administrator.*/
#define EXPRESS_error_accessing_file_for_reading        ( EXPRESS_ERROR_BASE + 157 )

/** The current user has no Export privilege on the selected object "%1$".
    Alternatively, please check the Teamcenter syslog file for more information and contact your system administrator.*/
#define EXPRESS_error_no_export_privilege               ( EXPRESS_ERROR_BASE + 158 )

/** The following objects are skipped by the Export functionality, because the current user has no Export privilege on them: %1$.*/
#define EXPRESS_error_no_user_export_privilege          ( EXPRESS_ERROR_BASE + 159 )

/** No valid Teamcenter Rapid Start license is available. Please contact your system administrator.*/
#define EXPRESS_tcrs_no_license                         ( EXPRESS_ERROR_BASE + 160 )

/** The "Export Review Package" operation is not allowed on an Assembly. */
#define EXPRESS_error_export_review_not_allowed_on_assemblies ( EXPRESS_ERROR_BASE + 161 )

/**Export Review Package functionality is not supported for non-Windows platforms.*/
#define EXPRESS_error_no_support_for_non_windows_platforms    ( EXPRESS_ERROR_BASE + 162 )

/** Unable to check existence of: %1$.*/
#define EXPRESS_unable_to_check_existence                     ( EXPRESS_ERROR_BASE + 163 )

/** PCFUtil is not installed. Please contact your system administrator.*/
#define EXPRESS_pcfutil_not_installed                         ( EXPRESS_ERROR_BASE + 164 )

#endif
