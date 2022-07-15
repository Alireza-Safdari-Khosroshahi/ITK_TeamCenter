/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Define error codes used with system administration.
*/

/*  */

#ifndef SA_ERRORS_H
#define SA_ERRORS_H

#include <common/emh_const.h>
#include <sa/libsa_exports.h>

/**
    @defgroup SA_ERRORS Errors
    @ingroup SA
    @{
*/

#define SA_ERROR_BASE                           EMH_SA_error_base

#define SA_user_already_exists                  (SA_ERROR_BASE + 1)
#define SA_not_initialized                      (SA_ERROR_BASE + 2)
#define SA_finding_person                       (SA_ERROR_BASE + 3)
#define SA_finding_role                         (SA_ERROR_BASE + 4)
#define SA_finding_group                        (SA_ERROR_BASE + 5)
#define SA_invalid_password                     (SA_ERROR_BASE + 6)
#define SA_finding_groupmember                  (SA_ERROR_BASE + 7)
#define SA_finding_groupmember_by_group         (SA_ERROR_BASE + 8)
#define SA_finding_groupmember_by_user          (SA_ERROR_BASE + 9)
#define SA_finding_groupmember_by_role          (SA_ERROR_BASE + 10)
#define SA_finding_user                         (SA_ERROR_BASE + 11)
#define SA_not_a_system_administrator           (SA_ERROR_BASE + 12)
#define SA_not_a_group_administrator            (SA_ERROR_BASE + 13)
#define SA_group_pfile_not_set                  (SA_ERROR_BASE + 14)
#define SA_group_pfile_not_found                (SA_ERROR_BASE + 15)
#define SA_group_pfile_dir_bad                  (SA_ERROR_BASE + 16)
#define SA_finding_site                         (SA_ERROR_BASE + 17)
#define SA_no_mes_info_class                    (SA_ERROR_BASE + 18)
#define SA_role_pfile_not_set                   (SA_ERROR_BASE + 19)
#define SA_role_pfile_not_found                 (SA_ERROR_BASE + 20)
#define SA_role_pfile_dir_bad                   (SA_ERROR_BASE + 21)
#define SA_no_group_and_role                    (SA_ERROR_BASE + 22)
#define SA_riog_not_found                       (SA_ERROR_BASE + 23)
#define SA_cant_deactivate_infodba              (SA_ERROR_BASE + 24)
#define SA_bad_user_group_role_combo            (SA_ERROR_BASE + 25)
#define SA_invalid_group                        (SA_ERROR_BASE + 26)
#define SA_cant_delete_default_groupmember      (SA_ERROR_BASE + 27)
#define SA_cant_delete_system_group             (SA_ERROR_BASE + 28)
#define SA_user_pfile_not_set                   (SA_ERROR_BASE + 29)
#define SA_user_pfile_not_found                 (SA_ERROR_BASE + 30)
#define SA_user_pfile_dir_bad                   (SA_ERROR_BASE + 31)
#define SA_invalid_person_attribute             (SA_ERROR_BASE + 32)
#define SA_undefined_role                       (SA_ERROR_BASE + 33)
#define SA_find_member_failed                   (SA_ERROR_BASE + 34)
#define SA_duplicate_role_for_member            (SA_ERROR_BASE + 35)
#define SA_delete_member_failed                 (SA_ERROR_BASE + 36)
#define SA_person_not_found                     (SA_ERROR_BASE + 37)
#define SA_group_not_found                      (SA_ERROR_BASE + 38)
#define SA_cannot_set_bypass                    (SA_ERROR_BASE + 39)
#define SA_user_inactive                        (SA_ERROR_BASE + 40)
#define SA_group_has_no_group_admin             (SA_ERROR_BASE + 41)

#define SA_rfile_empty                          (SA_ERROR_BASE + 50)
#define SA_rfile_invalid_first_line             (SA_ERROR_BASE + 51)
#define SA_rfile_one_root_allowed               (SA_ERROR_BASE + 52)
#define SA_rfile_invalid_data                   (SA_ERROR_BASE + 53)
#define SA_rule_tree_locked                     (SA_ERROR_BASE + 54)
#define SA_rule_tree_undefined_types            (SA_ERROR_BASE + 55)
#define SA_some_acls_exist                      (SA_ERROR_BASE + 56)
#define SA_some_acls_replaced                   (SA_ERROR_BASE + 57)
#define SA_nonexistent_accessor                 (SA_ERROR_BASE + 58)
#define SA_nonexistent_acl                      (SA_ERROR_BASE + 59)
#define SA_nonexistent_privilege                (SA_ERROR_BASE + 60)
#define SA_invalid_rule_arg                     (SA_ERROR_BASE + 61)

#define SA_user_owns_released_objects           (SA_ERROR_BASE + 70)
#define SA_user_owns_signoff_objects            (SA_ERROR_BASE + 71)
#define SA_member_owns_released_objects         (SA_ERROR_BASE + 72)
#define SA_user_has_checkouts                   (SA_ERROR_BASE + 73)
#define SA_user_is_currently_logged_in          (SA_ERROR_BASE + 74)

#define SA_cannot_load_user                     (SA_ERROR_BASE + 80)
#define SA_cannot_lock_user                     (SA_ERROR_BASE + 81)
#define SA_cannot_save_user                     (SA_ERROR_BASE + 82)

#define SA_no_archive_file_name                 (SA_ERROR_BASE + 90)
#define SA_error_create_archive_dir             (SA_ERROR_BASE + 91)
#define SA_error_write_site_id                  (SA_ERROR_BASE + 92)
#define SA_error_set_archive_info               (SA_ERROR_BASE + 93)
#define SA_error_deleting_os_file               (SA_ERROR_BASE + 94)
#define SA_error_closing_archive_files          (SA_ERROR_BASE + 95)
#define SA_error_invalid_directory              (SA_ERROR_BASE + 96)
#define SA_not_same_site_id                     (SA_ERROR_BASE + 97)
#define SA_objects_has_dif_time_stamp           (SA_ERROR_BASE + 98)
#define SA_archive_obj_has_dif_site             (SA_ERROR_BASE + 99)
#define SA_error_restoring_osfile               (SA_ERROR_BASE + 100)
#define SA_fail_to_restore                      (SA_ERROR_BASE + 101)
#define SA_dataset_has_no_file                  (SA_ERROR_BASE + 102)

#define SA_has_attribute_invalid_class          (SA_ERROR_BASE + 110)
#define SA_has_attribute_invalid_attr           (SA_ERROR_BASE + 111)
#define SA_has_attribute_invalid_type           (SA_ERROR_BASE + 112)
#define SA_has_attribute_invalid_value          (SA_ERROR_BASE + 113)
#define SA_NOT_ENOUGH_ACS_BITS                  (SA_ERROR_BASE + 114)

#define SA_class_not_initialized                (SA_ERROR_BASE + 115)
#define SA_invalid_dataset_tag                  (SA_ERROR_BASE + 116)
#define SA_error_last_mod_date                  (SA_ERROR_BASE + 117)
#define SA_invalid_datasettype_tag              (SA_ERROR_BASE + 118)
#define SA_ref_obj_not_found                    (SA_ERROR_BASE + 119)
#define SA_invalid_tool_tag                     (SA_ERROR_BASE + 120)
#define SA_sfrVolume_unset                      (SA_ERROR_BASE + 121)
#define SA_archived_object                      (SA_ERROR_BASE + 122)
#define SA_recovery_info                        (SA_ERROR_BASE + 123)
#define SA_invalid_sfr_tag                      (SA_ERROR_BASE + 124)
#define SA_error_checking_member_status         (SA_ERROR_BASE + 125)
#define SA_inactive_member                      (SA_ERROR_BASE + 126)
#define SA_can_not_deactivate_groupmember       (SA_ERROR_BASE + 127)
#define SA_groupmember_has_inprocess_signoffs   (SA_ERROR_BASE + 128)
#define SA_last_gm_in_default_group             (SA_ERROR_BASE + 129)
#define SA_cannot_switch_to_inactive_role       (SA_ERROR_BASE + 130)
/** The password contains invalid special characters. Must be one of {}. */
#define SA_PASSWORD_INVALID_SPEC_CHAR           (SA_ERROR_BASE + 131)
 /** The password is too short. The minimum length is #. */
#define SA_PASSWORD_TOO_SHORT                   (SA_ERROR_BASE + 132)
/** The password contains too few digits. The minimum is #. */
#define SA_PASSWORD_TOO_FEW_DIGITS              (SA_ERROR_BASE + 133)
/** The password has too few alphabetic characters. The minimum is #. */
#define SA_PASSWORD_TOO_FEW_ALPHA_CHARS         (SA_ERROR_BASE + 134)
/** The password must have both upper and lower case characters in it. */
#define SA_PASSWORD_NOT_MIXED_CASE              (SA_ERROR_BASE + 135)
/** The password contains too few special characters. The minimum is #. */
#define SA_PASSWORD_TOO_FEW_SPEC_CHARS          (SA_ERROR_BASE + 136)
/** No special characters are allowed in passwords. */
#define SA_PASSWORD_NO_SPEC_CHARS               (SA_ERROR_BASE + 137)
#define SA_bad_user_role_combo                  (SA_ERROR_BASE + 138)
#define SA_bad_user_group_combo                 (SA_ERROR_BASE + 139)
#define SA_bad_workcontext_user                 (SA_ERROR_BASE + 140)
#define SA_invalid_user_teammember              (SA_ERROR_BASE + 141)
#define SA_invalid_gm_teammember                (SA_ERROR_BASE + 142)
#define SA_invalid_proj_teammember              (SA_ERROR_BASE + 143)
#define SA_group_chg_not_allowed                (SA_ERROR_BASE + 144)
#define SA_project_chg_not_allowed              (SA_ERROR_BASE + 145)
#define SA_discipline_not_found                 (SA_ERROR_BASE + 146)
#define SA_tccalendar_invalid_parameter         (SA_ERROR_BASE + 147)
#define SA_tccalendar_already_exists            (SA_ERROR_BASE + 148)
#define SA_tccalendar_does_not_exist            (SA_ERROR_BASE + 149)
#define SA_no_access_create_resource_calendar   (SA_ERROR_BASE + 150)
#define SA_no_access_update_resource_calendar   (SA_ERROR_BASE + 151)
#define SA_no_access_delete_resource_calendar   (SA_ERROR_BASE + 152)
#define SA_no_access_create_base_calendar       (SA_ERROR_BASE + 153)
#define SA_no_access_update_base_calendar       (SA_ERROR_BASE + 154)
#define SA_cannot_delete_base_calendar          (SA_ERROR_BASE + 155)

/** An unknown error has occurred during the creation of a Calendar: %1$. */
#define SA_tccalendar_unknown_error             (SA_ERROR_BASE + 156)
#define SA_cannot_create_schedule_calendar      (SA_ERROR_BASE + 157)
#define SA_cannot_create_sch_member_calendar    (SA_ERROR_BASE + 158)
#define SA_base_calendar_allreadyexists         (SA_ERROR_BASE + 159)
#define SA_invalidcalendar_withall_nonworkingdays (SA_ERROR_BASE + 160)

#define SA_no_ip_admin_for_ip_clearance         (SA_ERROR_BASE + 161)
#define SA_no_ip_admin_for_ip_classification    (SA_ERROR_BASE + 162)
#define SA_no_ip_admin_for_attach_license       (SA_ERROR_BASE + 163)
#define SA_no_ip_admin_for_detach_license       (SA_ERROR_BASE + 164)
#define SA_no_itar_admin_for_gov_clearance      (SA_ERROR_BASE + 165)
#define SA_no_itar_admin_for_gov_classification (SA_ERROR_BASE + 166)
#define SA_no_itar_admin_for_geography          (SA_ERROR_BASE + 167)
#define SA_no_itar_admin_for_nationality        (SA_ERROR_BASE + 168)
#define SA_no_itar_admin_for_ttcdate            (SA_ERROR_BASE + 169)
#define SA_no_itar_admin_for_attach_license     (SA_ERROR_BASE + 170)
#define SA_no_itar_admin_for_detach_license     (SA_ERROR_BASE + 171)
#define SA_person_already_exists                (SA_ERROR_BASE + 172)

#define SA_group_does_not_belong_to_org         (SA_ERROR_BASE + 173)

#define SA_resource_calendar_is_referenced      (SA_ERROR_BASE + 174)
#define SA_base_calendar_not_available          (SA_ERROR_BASE + 175)

#define SA_organization_pref_not_valid          (SA_ERROR_BASE + 176)
#define SA_remote_export_not_support            (SA_ERROR_BASE + 177)
#define SA_deleted_member_referenced            (SA_ERROR_BASE + 178)

#define SA_role_name_empty                      (SA_ERROR_BASE + 179)
#define SA_group_full_name_invalid              (SA_ERROR_BASE + 180)
#define SA_group_name_already_used              (SA_ERROR_BASE + 181)
#define SA_role_name_already_used               (SA_ERROR_BASE + 182)
#define SA_discipline_name_already_used         (SA_ERROR_BASE + 183)

#define SA_cannot_set_lockdate_on_expired_licenses         (SA_ERROR_BASE + 184)
#define SA_lockdate_must_be_between_currentdate_expdate    (SA_ERROR_BASE + 185)
#define SA_InAccorWith_can_be_set_only_for_ITAR_Licenses   (SA_ERROR_BASE + 186)
#define SA_InAccorWith_cannot_be_greater_than_80           (SA_ERROR_BASE + 187)
#define SA_expdate_cannot_be_less_than_currentdate         (SA_ERROR_BASE + 188)
#define SA_cannot_add_users_groups_to_locked_licenses      (SA_ERROR_BASE + 189)
#define SA_insufficient_privilege_to_perform_the_action    (SA_ERROR_BASE + 190)
#define SA_group_length_cannot_be_greater_than_256         (SA_ERROR_BASE + 191)
#define SA_subgroup_support_not_enabled                    (SA_ERROR_BASE + 192)
#define SA_cannot_set_Authorizing_paragraph_information    (SA_ERROR_BASE + 193)
#define SA_cannot_attach_locked_or_expired_license         (SA_ERROR_BASE + 194)
#define SA_no_privilege_to_detach_itar_license             (SA_ERROR_BASE + 195)
#define SA_invalid_license_administration_privilege        (SA_ERROR_BASE + 196)
#define SA_cannot_change_type_for_existing_license         (SA_ERROR_BASE + 197)

#define SA_has_property_invalid_property                   (SA_ERROR_BASE + 198)
#define SA_has_property_invalid_type                       (SA_ERROR_BASE + 199)
#define SA_has_property_invalid_value_type                 (SA_ERROR_BASE + 200)
#define SA_has_property_invalid_value                      (SA_ERROR_BASE + 201)
#define SA_workcontext_invalid_group_member                (SA_ERROR_BASE + 202)

#define SA_low_on_available_licenses                       (SA_ERROR_BASE + 203)

#define SA_no_privilege_for_gov_classification             (SA_ERROR_BASE + 204)
#define SA_no_privilege_for_ip_classification              (SA_ERROR_BASE + 205)
#define SA_could_not_get_authorization                     (SA_ERROR_BASE + 206)
#define SA_cannot_create_clientsessioninfo                 (SA_ERROR_BASE + 207)
#define SA_cannot_find_clientsessioninfo                   (SA_ERROR_BASE + 208)
#define SA_cannot_delete_clientsessioninfo                 (SA_ERROR_BASE + 209)
#define SA_cannot_update_clientsessioninfo                 (SA_ERROR_BASE + 210)

/**The length of the "Category" value cannot be greater than 128 characters.*/
#define SA_category_length_cannot_be_greater_than_128      (SA_ERROR_BASE + 211)
/**No ADA License with the given License ID can be found.*/
#define SA_ada_license_with_given_licenseID_not_found      (SA_ERROR_BASE + 212)
/** The password violates password restrictions. */
#define SA_password_incorrectly_formatted                  (SA_ERROR_BASE + 213)
/** The specified User object is invalid. */
#define SA_Invalid_User                                    (SA_ERROR_BASE + 214)
/** The group member "%1$" cannot be deleted because it is the current session group member. */
#define SA_cannot_delete_session_groupmember               (SA_ERROR_BASE + 215)
/** Finding all group members has failed.Please check the server syslog file for more information.*/
#define SA_finding_all_groupmember_by_user                 (SA_ERROR_BASE + 216)
/**System administration privileges are needed in order to modify or add citizenship for the user. */
#define SA_no_system_admin_for_citizenship                 (SA_ERROR_BASE + 217)
/** The access rights are not sufficient to read the citizenship for the user. */
#define SA_no_privilege_for_citizenship                    (SA_ERROR_BASE + 218)
/** The citizenship is invalid, and, therefore,it cannot be added or removed from the User object.*/
#define SA_invalid_citizenship                             (SA_ERROR_BASE + 219)
/** The detailed license information could not be retrieved. Please check with your system administrator for more information..*/
#define SA_failed_retrieve_ADA_license_information         (SA_ERROR_BASE + 220)
/** The license could not be created or updated. Please check with your system administrator for more information.*/
#define SA_failed_create_update_ADA_license                (SA_ERROR_BASE + 221)

/** The number of available licenses is running low: &quot;%1$&quot; licenses of bundle &quot;%2$&quot; are left. */
#define SA_low_on_available_license_bundles                (SA_ERROR_BASE + 222)

/** System administration privileges are needed to set the property &quot;%1$&quot; for the user &quot;%2$&quot;. */
#define SA_no_system_admin_for_user_property               (SA_ERROR_BASE + 223)

/** Invalid search criteria were provided to find group members. The group name, role name, user ID and user name cannot all be empty. */
#define SA_find_group_members_invalid_argument             (SA_ERROR_BASE + 224)

/** The default group of the active user &quot;%1$&quot; cannot be switched to the group &quot;%2$&quot;, because the user does not belong to any active role in this group. */
#define SA_cannot_switch_active_user_default_group         (SA_ERROR_BASE + 225)

/** Some errors occurred during the execution of the &quot;make_user&quot; utility. Please check the standard error file for details. */
#define SA_make_user_utility_has_errors                    (SA_ERROR_BASE + 226)

/** The batch file ticket &quot;%1$&quot; specified as input for the &quot;make_user&quot; utility is invalid. */
#define SA_invalid_make_user_batch_file_ticket             (SA_ERROR_BASE + 227)

/** The time zone cannot be found for the calendar "%1$". Please specify a valid time zone in the input. */
#define SA_tccalendar_cannot_find_timezone                 (SA_ERROR_BASE + 228)

/** An internal error has occurred in the Calendar functionality. Please refer to the Teamcenter syslog file for more information. */
#define SA_tccalendar_invalid_calendar_input               (SA_ERROR_BASE + 229)

/** An error has occured in the calculations of the calendar "%1$". Please verify the input and try again. */
#define SA_tccalendar_error_during_calendar_calculations   (SA_ERROR_BASE + 230)

/** The Task length exceeds the maximum time of %1$ days. **/
#define SA_tccalendar_duration_too_long                    (SA_ERROR_BASE + 231)

/** The user ID "%1$" is invalid, because it contains one of the following characters: %2$. */
#define SA_user_id_invalid_chars                           (SA_ERROR_BASE + 232)

/** The given property &quot;%1$&quot; does not exist on Business Objects of type &quot;%2$&quot;. Please provide a correct property name as input. */
#define SA_invalid_custom_user_profile_property                  (SA_ERROR_BASE + 233)
/** The given string value &quot;%1$&quot; for the property &quot;%2$&quot; cannot be converted to the value type expected for this property.*/
#define SA_invalid_custom_user_profile_value                 (SA_ERROR_BASE + 234)
/** The operation to set the Custom User Profile properties has failed. Please refer to the Teamcenter server syslog file for more information.*/
#define SA_set_user_profile_prop_generic_err               (SA_ERROR_BASE + 235)
/** The property Custom User Profile is not set for the user &quot;%1$&quot; on the target/source site.*/
#define SA_custom_user_profile_not_found                   (SA_ERROR_BASE + 236)
/** A new owning user must be provided in order to be able to delete the user "%1$". */
#define SA_no_new_owning_user                              (SA_ERROR_BASE + 237)
/** The Schedule member or calendar for the user "%1$" cannot be created, modified nor deleted, because the user is inactive.*/
#define SA_cannot_update_calendar_for_inactive_user        (SA_ERROR_BASE + 238)
/** The password cannot contain only whitespace characters. */
#define SA_password_only_has_whitespace_characters         (SA_ERROR_BASE + 239)
/** Invalid combination of license level "%1$" and user ID "%2$". */
#define SA_invalid_license_level_userid_combination        (SA_ERROR_BASE + 240)
/** The user should have the "%1$" privilege in order to modify the "%2$" property of "%3$". */
#define SA_insufficient_privilege                          (SA_ERROR_BASE + 241)
/** The "%1$" property is not defined in the "ADA_Custom_Security_Mapping" preference. */
#define SA_no_security_mapping_entry_found                 (SA_ERROR_BASE + 242)
/** The "%1$" property of "%2$" cannot be modified because either an invalid or no privilege is specified in the "ADA_Custom_Security_Mapping" preference. */ 
#define SA_invalid_or_no_privilege_specified               (SA_ERROR_BASE + 243)
/** The "%1$" license cannot be modified because either an invalid or no privilege is specified in the "ADA_Custom_Security_Mapping" preference. */
#define SA_invalid_or_no_privilege_specified_for_license   (SA_ERROR_BASE + 244)
/** The privilege "%1$" specified in the "ADA_Custom_Security_Mapping" preference is invalid. */
#define SA_invalid_custom_license_admin_privilege          (SA_ERROR_BASE + 245)
/** Person should not be null */
#define SA_person_should_not_be_null                       (SA_ERROR_BASE + 246)
/** The Role "%1$" is already present in the Group "%2$". */ 
#define SA_role_already_exists_in_group                    (SA_ERROR_BASE + 247)

/** Only one Consent Statement Object is permitted at a time. Please revise the existing Consent Statement revision object for the new Consent Statement.*/ 
#define SA_only_one_consent_statement_object_permitted_at_a_time                    (SA_ERROR_BASE + 248)

/**No released consent statement is found in the system.*/
#define SA_no_consent_statement_found                      ( SA_ERROR_BASE + 249 )

/*Consent dataset with locale "%1$" is already attached to this consent statement revision.*/
#define SA_only_one_consent_dataset_for_one_locale_allowed                ( SA_ERROR_BASE + 250 )




/**  No Business Object is provided for the evaluation of Access Controls for  "%1$".  Please provide one or more Business Objects. */
#define SA_oar_no_object_input                             (SA_ERROR_BASE + 260)

/**  The accessor %1$" is not authorized for operation "%2$".*/
#define SA_oar_access_denied                               (SA_ERROR_BASE + 261)

/**  Access Controls evaluation failed with code: %1$": "%2$". Please contact your Teamcenter administrator. */
#define SA_check_oar_failed                                (SA_ERROR_BASE + 262)

/**  Teamcenter is not configured to use Access Controls.  Please contact your Teamcenter administrator. */
#define SA_oar_not_configured                              (SA_ERROR_BASE + 263)

/**  Teamcenter is not configured to validate %$1 using Access Controls.  Please contact your Teamcenter administrator. */
#define SA_oar_invalid_accessor                            (SA_ERROR_BASE + 264)

/** AM condition %$1 is not registered in the system. Please provide a valid condition name. */
#define SA_oar_invalid_condition_name                      (SA_ERROR_BASE + 265)

/** The input AM condition name is empty or null. Please provide a valid condition name. */
#define SA_oar_null_condition_name                         (SA_ERROR_BASE + 266)

/**  Input "%1$" is empty or null. Please provide a valid value. */
#define SA_oar_null_empty_input                            (SA_ERROR_BASE + 267)

/** The AM accessor type "%1$" is invalid. Please provide a valid AM accessor type. */
#define SA_oar_invalid_accessor_type                       (SA_ERROR_BASE + 268)

/** The Access Controls system function "%1$" is not valid. Please contact your Teamcenter adminstrator. */
#define SA_oar_invalid_system_function                     (SA_ERROR_BASE + 269)

/** The Access Controls have not been loaded. Please contact your Teamcenter administrator. */
#define SA_oar_rule_not_loaded                             (SA_ERROR_BASE + 270)

/** The Access Controls rule expression is invalid. Please check the Teamcenter system log for more information and contact your Teamcenter administrator. */
#define SA_oar_invalid_rule_expression                     (SA_ERROR_BASE + 271)

/** A valid set of objects to evaluate must be provided. */
#define SA_oar_invalid_objects                             (SA_ERROR_BASE + 272)

/** Either the Business Object constant name "%1$" or the value to compare "2$" is invalid. */
#define SA_oar_invalid_constant                            (SA_ERROR_BASE + 273)

/** The requested action "%1$" is not allowed when Access Controls are enabled. Please disable Access Controls and try again. */
#define SA_oar_action_not_allowed                          (SA_ERROR_BASE + 274)

/** Expressions for Access Controls have failed to be regenerated. Please check the Teamcenter system log for more information or contact your system administrator. */
#define SA_oar_regenerate_all_failed                       (SA_ERROR_BASE + 275)

/** The Access Controls data could not be exported: %1$. Please check the Teamcenter system log for more information or contact your system administrator. */
#define SA_oar_export_failed                               (SA_ERROR_BASE + 276)

/** The Access Controls data could not be imported: %1$. Please check the Teamcenter system log for more information or contact your system administrator. */
#define SA_oar_import_failed                               (SA_ERROR_BASE + 277)

/** The Access Controls Condition argument "%1$" is invalid. The valid values are %2$. */
#define SA_ac_invalid_condition_argument                   (SA_ERROR_BASE + 278)  

/** Access Manager data import failed. The 'GSIdentity' label value for AM_Privileges is not up-to-date in the given input XML file. Please ensure that the input XML file was generated with the minimum Teamcenter version 13.1.*/
#define SA_am_import_failed                                (SA_ERROR_BASE + 279)

#define SA_W_LOAD_PERSON_FAILED                 EMH_SA_W_ERROR_BASE + 1
#define SA_W_CREATE_ROLE_FAILED                 EMH_SA_W_ERROR_BASE + 3
#define SA_W_CREATE_PERSON_FAILED               EMH_SA_W_ERROR_BASE + 4
#define SA_W_SAVE_PERSON_FAILED                 EMH_SA_W_ERROR_BASE + 5
#define SA_W_DELETE_PERSON_FAILED               EMH_SA_W_ERROR_BASE + 6
#define SA_W_LOCK_OBJECT_FAILED                 EMH_SA_W_ERROR_BASE + 7
#define SA_W_UNLOCK_OBJECT_FAILED               EMH_SA_W_ERROR_BASE + 9
#define SA_W_LOAD_ROLE_FAILED                   EMH_SA_W_ERROR_BASE + 10
#define SA_W_NO_ROLE_NAME                       EMH_SA_W_ERROR_BASE + 11
#define SA_W_SAVE_ROLE_FAILED                   EMH_SA_W_ERROR_BASE + 12
#define SA_W_DELETE_ROLE_FAILED                 EMH_SA_W_ERROR_BASE + 13
#define SA_W_LOAD_GROUP_FAILED                  EMH_SA_W_ERROR_BASE + 14
#define SA_W_NO_GROUP_SELECTED                  EMH_SA_W_ERROR_BASE + 15
#define SA_W_NO_GROUP_NAME                      EMH_SA_W_ERROR_BASE + 16
#define SA_W_CREATE_GROUP_FAILED                EMH_SA_W_ERROR_BASE + 17
#define SA_W_ADD_ROLE_TO_GROUP                  EMH_SA_W_ERROR_BASE + 18
#define SA_W_SAVE_GROUP_FAILED                  EMH_SA_W_ERROR_BASE + 19
#define SA_W_DELETE_GROUP_FAILED                EMH_SA_W_ERROR_BASE + 20
#define SA_W_MODIFY_GROUP_FAILED                EMH_SA_W_ERROR_BASE + 21
#define SA_W_LOAD_USER_FAILED                   EMH_SA_W_ERROR_BASE + 22
#define SA_W_LOAD_USER_DEFGROUP                 EMH_SA_W_ERROR_BASE + 23
#define SA_W_NO_PERSON_SELECTED                 EMH_SA_W_ERROR_BASE + 24
#define SA_W_NO_USERID_ENTERED                  EMH_SA_W_ERROR_BASE + 25
#define SA_W_NO_USERNAME_ENTERED                EMH_SA_W_ERROR_BASE + 26
#define SA_W_NO_PASSWORD_ENTERED                EMH_SA_W_ERROR_BASE + 27
#define SA_W_CREATE_USER_FAILED                 EMH_SA_W_ERROR_BASE + 28
#define SA_W_CREATE_MEMBER_FAILED               EMH_SA_W_ERROR_BASE + 29
#define SA_W_SAVE_MEMBER_FAILED                 EMH_SA_W_ERROR_BASE + 30
#define SA_W_SAVE_USER_FAILED                   EMH_SA_W_ERROR_BASE + 31
#define SA_W_CHANGE_PASSWORD_FAILED             EMH_SA_W_ERROR_BASE + 32
#define SA_W_CHANGE_OWNERSHIP                   EMH_SA_W_ERROR_BASE + 34
#define SA_W_DELETE_USER_FAILED                 EMH_SA_W_ERROR_BASE + 35
#define SA_W_SAVE_NEWOWNER_FAILED               EMH_SA_W_ERROR_BASE + 36
#define SA_W_LOAD_MEMBER_FAILED                 EMH_SA_W_ERROR_BASE + 37
#define SA_W_INVALID_GROUP                      EMH_SA_W_ERROR_BASE + 38
#define SA_W_UNDEFINED_ROLE                     EMH_SA_W_ERROR_BASE + 39
#define SA_W_GETTING_USER_FAILED                EMH_SA_W_ERROR_BASE + 40
#define SA_W_GETTING_GROUP_FAILED               EMH_SA_W_ERROR_BASE + 41
#define SA_W_GETTING_ROLE_FAILED                EMH_SA_W_ERROR_BASE + 42
#define SA_W_DELETE_MEMBER_FAILED               EMH_SA_W_ERROR_BASE + 43
#define SA_W_LOAD_DATASETTYPE_FAILED            EMH_SA_W_ERROR_BASE + 44
#define SA_W_CREATE_DATASETTYPE_FAILED          EMH_SA_W_ERROR_BASE + 45
#define SA_W_ADD_TOOL_TO_DATASETTYPE            EMH_SA_W_ERROR_BASE + 46
#define SA_W_SAVE_DATASETTYPE_FAILED            EMH_SA_W_ERROR_BASE + 47
#define SA_W_DELETE_DATASETTYPE_FAILED          EMH_SA_W_ERROR_BASE + 48
#define SA_W_LOAD_TOOL_FAILED                   EMH_SA_W_ERROR_BASE + 49
#define SA_W_TOOL_SNAME_NOT_ENTERED             EMH_SA_W_ERROR_BASE + 50
#define SA_W_TOOL_NAME_NOT_ENTERED              EMH_SA_W_ERROR_BASE + 51
#define SA_W_TOOL_VERSION_NOT_SET               EMH_SA_W_ERROR_BASE + 52
#define SA_W_TOOL_DESCRIPTION_NOT_SET           EMH_SA_W_ERROR_BASE + 53
#define SA_W_SAVE_TOOL_FAILED                   EMH_SA_W_ERROR_BASE + 54
#define SA_W_CREATE_TOOL_FAILED                 EMH_SA_W_ERROR_BASE + 55
#define SA_W_DELETE_TOOL_FAILED                 EMH_SA_W_ERROR_BASE + 56
#define SA_W_NO_TOOL_SELECTED                   EMH_SA_W_ERROR_BASE + 57
#define SA_W_TOOL_INITIALIZE_FAILED             EMH_SA_W_ERROR_BASE + 58
#define SA_W_LOAD_TASKTYPE_FAILED               EMH_SA_W_ERROR_BASE + 59
#define SA_W_TTNAME_NOT_ENTERED                 EMH_SA_W_ERROR_BASE + 60
#define SA_W_SAVE_TASKTYPE_FAILED               EMH_SA_W_ERROR_BASE + 61
#define SA_W_CREATE_TASKTYPE_FAILED             EMH_SA_W_ERROR_BASE + 62
#define SA_W_DELETE_TASKTYPE_FAILED             EMH_SA_W_ERROR_BASE + 63
#define SA_W_TASKTYPE_NOT_SELECTED              EMH_SA_W_ERROR_BASE + 64
#define SA_W_NO_DATASETTYPE_SELECTED            EMH_SA_W_ERROR_BASE + 65
#define SA_W_ERROR_LOADING_WSO                  EMH_SA_W_ERROR_BASE + 66
#define SA_W_FIND_USER_FAILED                   EMH_SA_W_ERROR_BASE + 68
#define SA_W_FIND_GROUP_FAILED                  EMH_SA_W_ERROR_BASE + 69
#define SA_W_CHANGE_PROTECTION_FAILED           EMH_SA_W_ERROR_BASE + 70
#define SA_W_UNLOAD_USER_FAILED                 EMH_SA_W_ERROR_BASE + 71
#define SA_W_ERROR_GET_ACLLENGTH                EMH_SA_W_ERROR_BASE + 72
#define SA_W_ERROR_GET_ACLENTRIES               EMH_SA_W_ERROR_BASE + 73
#define SA_W_GRANT_ACL_FAILED                   EMH_SA_W_ERROR_BASE + 74
#define SA_W_REVOKE_ACL_FAILED                  EMH_SA_W_ERROR_BASE + 75
#define SA_W_NO_ACL_SELECTED                    EMH_SA_W_ERROR_BASE + 76
#define SA_W_DELETE_OBJECT_FAILED               EMH_SA_W_ERROR_BASE + 77
#define SA_W_NO_USER_SELECTED                   EMH_SA_W_ERROR_BASE + 78
#define SA_W_NO_ROLE_SELECTED                   EMH_SA_W_ERROR_BASE + 79
#define SA_W_NO_MEMBER_SELECTED                 EMH_SA_W_ERROR_BASE + 80
#define SA_W_INVALID_INPUT_DATASETTYPE          EMH_SA_W_ERROR_BASE + 81
#define SA_W_NO_PERSON_FNAME                    EMH_SA_W_ERROR_BASE + 82
#define SA_W_PERSON_NAME_NOT_UNIQUE             EMH_SA_W_ERROR_BASE + 83
#define SA_W_NO_SA_GA_PRIVILEGE                 EMH_SA_W_ERROR_BASE + 84
#define SA_W_NO_SA_PRIVILEGE                    EMH_SA_W_ERROR_BASE + 85
#define SA_W_MUST_BE_GA_OF_GROUP                EMH_SA_W_ERROR_BASE + 86
#define SA_W_INPUT_PERSON_NOT_FOUND             EMH_SA_W_ERROR_BASE + 87
#define SA_W_NO_PERSON_EXISTED                  EMH_SA_W_ERROR_BASE + 88
#define SA_W_TASKTYPE_DESC_NOT_SET              EMH_SA_W_ERROR_BASE + 89
#define SA_W_TASKTYPE_FORM_NOT_SET              EMH_SA_W_ERROR_BASE + 90
#define SA_W_FOLLOW_ACTION_NOT_SET              EMH_SA_W_ERROR_BASE + 91
#define SA_W_PLACE_MARK_POINT_FAILED            EMH_SA_W_ERROR_BASE + 93
#define SA_W_NO_NEW_PASSWORD_ENTERED            EMH_SA_W_ERROR_BASE + 95
#define SA_W_ERROR_CHANGING_PASSWORD            EMH_SA_W_ERROR_BASE + 96
#define SA_W_NO_OS_USERNAME_ENTERED             EMH_SA_W_ERROR_BASE + 101
#define SA_W_NO_IO_FORMAT_ENTERED               EMH_SA_W_ERROR_BASE + 102
#define SA_W_DUPLICATED_FORMAT                  EMH_SA_W_ERROR_BASE + 103
#define SA_W_NO_IO_FORMAT_SELECTED              EMH_SA_W_ERROR_BASE + 104
#define SA_W_NO_APPROVER_ROLE                   EMH_SA_W_ERROR_BASE + 105
#define SA_W_NO_AUTHORIZER_ROLE                 EMH_SA_W_ERROR_BASE + 106
#define SA_W_NOT_SAME_ARCHIVE_DATE              EMH_SA_W_ERROR_BASE + 107
#define SA_W_UNABLE_TO_LIST_VOLUME              EMH_SA_W_ERROR_BASE + 116
#define SA_W_NO_DELETE_LOGIN_USER               EMH_SA_W_ERROR_BASE + 124
#define SA_W_NO_TOOL_FOR_DATASETTYPE            EMH_SA_W_ERROR_BASE + 125
#define SA_W_ROLE_NAME_IS_NOT_UNIQUE            EMH_SA_W_ERROR_BASE + 126
#define SA_W_GROUP_NAME_IS_NOT_UNIQUE           EMH_SA_W_ERROR_BASE + 127
#define SA_W_USER_ID_IS_NOT_UNIQUE              EMH_SA_W_ERROR_BASE + 128
#define SA_W_MODIFY_USER_FAILED                 EMH_SA_W_ERROR_BASE + 129
#define SA_W_DOUBLE_CLICK_IS_REQUIRED           EMH_SA_W_ERROR_BASE + 130
#define SA_W_MODIFY_TOOL_FAILED                 EMH_SA_W_ERROR_BASE + 131
#define SA_W_TOOL_NAME_IS_NOT_UNIQUE            EMH_SA_W_ERROR_BASE + 132
#define SA_W_TASKTYPE_NAME_IS_NOT_UNIQUE        EMH_SA_W_ERROR_BASE + 133
#define SA_W_DATASETTYPE_NAME_NOT_UNIQUE        EMH_SA_W_ERROR_BASE + 134
#define SA_NO_SET_BYPASS                        (EMH_SA_W_ERROR_BASE + 135)
#define SA_NO_REVOKE_BYPASS                     (EMH_SA_W_ERROR_BASE + 136)
#define SA_USER_REFERENCED                      EMH_SA_W_ERROR_BASE + 137
#define SA_GROUP_REFERENCED                     EMH_SA_W_ERROR_BASE + 138
#define SA_REMOVE_GROUP_ROLE_FAIL               EMH_SA_W_ERROR_BASE + 139
#define SA_NO_SUCH_TOOL                         (EMH_SA_W_ERROR_BASE + 140)
#define SA_INVALID_ACTION                       (EMH_SA_W_ERROR_BASE + 141)
#define SA_NO_DEFAULT_VOLUME                    EMH_SA_W_ERROR_BASE + 143
#define SA_NO_MEMBER_IN_CLIPBOARD               EMH_SA_W_ERROR_BASE + 144
#define SA_UNDEFINED_ROLE_IN_GROUP              EMH_SA_W_ERROR_BASE + 145
#define SA_FAIL_TO_REMOVE_ACL                   EMH_SA_W_ERROR_BASE + 146
#define SA_STATUS_NOT_FOUND                     EMH_SA_W_ERROR_BASE + 147
#define SA_FAIL_TO_ARCHIVE                      EMH_SA_W_ERROR_BASE + 148
#define SA_GROUP_ALREADY_EXIST                  EMH_SA_W_ERROR_BASE + 154
#define SA_W_CHANGE_ACL_FAILED                  EMH_SA_W_ERROR_BASE + 155
#define SA_W_FIND_ROLE_FAILED                   EMH_SA_W_ERROR_BASE + 156
#define SA_W_NO_PRIV_SELECTED                   EMH_SA_W_ERROR_BASE + 157
#define SA_W_ONLY_SA_CAN_EDIT_RULE_TREE         EMH_SA_W_ERROR_BASE + 158
#define SA_W_UNSAVED_CHANGES_IN_RULE_TREE       EMH_SA_W_ERROR_BASE + 160
#define SA_W_NONEXISTENT_ACCESSOR               EMH_SA_W_ERROR_BASE + 167
#define SA_W_DUPLICATE_ACCESSOR_IN_ACL          EMH_SA_W_ERROR_BASE + 170
#define SA_W_ACL_ALREADY_DELETED                EMH_SA_W_ERROR_BASE + 171
#define SA_W_ACE_ALREADY_DELETED                EMH_SA_W_ERROR_BASE + 172
#define SA_W_ACL_ALREADY_EXIST                  EMH_SA_W_ERROR_BASE + 173
#define SA_W_NO_CURRENT_PASSWORD                EMH_SA_W_ERROR_BASE + 174
#define SA_W_NO_SITE_SELECTED                   EMH_SA_W_ERROR_BASE + 177
#define SA_W_PRIV_NOT_DEFINED                   EMH_SA_W_ERROR_BASE + 178
#define SA_W_USER_GROUP_MISMATCH                EMH_SA_W_ERROR_BASE + 179
#define SA_W_USER_GROUP_ROLE_MISMATCH           EMH_SA_W_ERROR_BASE + 180
#define SA_W_DELEGATION_PREVENTS_CHANGE         EMH_SA_W_ERROR_BASE + 181
#define SA_W_CANT_CUT_AM_ROOT                   EMH_SA_W_ERROR_BASE + 182
#define SA_W_INVALID_CONTENTS                   EMH_SA_W_ERROR_BASE + 183
#define SA_W_ADD_ACE_WITH_NO_PRIVS_SET          EMH_SA_W_ERROR_BASE + 185
#define SA_W_AMBIGUOUS_ACCESSOR                 EMH_SA_W_ERROR_BASE + 188
#define SA_W_DEFAULT_GROUP_FOUND                EMH_SA_W_ERROR_BASE + 189
#define SA_W_DEACTIVATE_SUGG                    EMH_SA_W_ERROR_BASE + 190
#define SA_W_AMBIGUOUS_SUBGROUP_NAME            EMH_SA_W_ERROR_BASE + 191
#define SA_USER_NOT_FOUND_IN_REMOTE_DB          EMH_SA_W_ERROR_BASE + 192
#define SA_ENCHANCED_SECURITY_ENABLED           EMH_SA_W_ERROR_BASE + 193
#define SA_SHARED_VOL_REPLICA_DEL_DISALLOW      EMH_SA_W_ERROR_BASE + 194
#define SA_ADD_REPLICA_GROUP_DISALLOW           EMH_SA_W_ERROR_BASE + 195

/** 
    @name Global Organization errors
    @{
*/
#define SA_IMPEXP_XFER_USER_NO_RELATED_OBJ                    (EMH_SA_W_ERROR_BASE + 196)
#define SA_IMPEXP_XFER_NOT_TOP_LEVEL_GROUP                    (EMH_SA_W_ERROR_BASE + 197)
#define SA_IMPEXP_duplicate_master_obj                        (EMH_SA_W_ERROR_BASE + 198)
#define SA_IMPEXP_organization_export_error                   (EMH_SA_W_ERROR_BASE + 199)
#define SA_IMPEXP_gsid_match_error_during_import              (EMH_SA_W_ERROR_BASE + 200)
#define SA_IMPEXP_gsid_creation_error                         (EMH_SA_W_ERROR_BASE + 201)
#define SA_IMPEXP_organization_import_error                   (EMH_SA_W_ERROR_BASE + 202)
#define SA_IMPEXP_user_default_group_not_exist                (EMH_SA_W_ERROR_BASE + 203)
#define SA_IMPEXP_user_match_person_not_exist                 (EMH_SA_W_ERROR_BASE + 204)
#define SA_IMPEXP_groupmember_no_match_user                   (EMH_SA_W_ERROR_BASE + 205)
#define SA_IMPEXP_groupmember_no_match_group                  (EMH_SA_W_ERROR_BASE + 206)
#define SA_IMPEXP_groupmember_no_match_role                   (EMH_SA_W_ERROR_BASE + 207)
#define SA_IMPEXP_site_not_permitted_push_admin_data          (EMH_SA_W_ERROR_BASE + 208)
#define SA_IMPEXP_cannot_export_replica_system_object         (EMH_SA_W_ERROR_BASE + 209)
#define SA_IMPEXP_migrate_extra_subgroup_on_master_site       (EMH_SA_W_ERROR_BASE + 210)
#define SA_IMPEXP_object_migration_fail                       (EMH_SA_W_ERROR_BASE + 211)
#define SA_IMPEXP_related_object_not_migrated                 (EMH_SA_W_ERROR_BASE + 212)
#define SA_IMPEXP_migrate_not_match_on_import                 (EMH_SA_W_ERROR_BASE + 213)
#define SA_IMPEXP_migrate_user_based_on_diff_person           (EMH_SA_W_ERROR_BASE + 214)
#define SA_IMPEXP_migrate_extra_groupmember_on_replica_site   (EMH_SA_W_ERROR_BASE + 215)
#define SA_IMPEXP_migrate_extra_subgroup_on_replica_site      (EMH_SA_W_ERROR_BASE + 216)
#define SA_IMPEXP_migrate_extra_role_on_replica_site          (EMH_SA_W_ERROR_BASE + 217)

/** The person "infodba" is not allowed to be replicated or migrated. */
#define SA_IMPEXP_infodba_person_export                       (EMH_SA_W_ERROR_BASE + 218)

/** The user "infodba" is not allowed to be replicated or migrated. */
#define SA_IMPEXP_infodba_based_person_user_export            (EMH_SA_W_ERROR_BASE + 219)

#define SA_IMPEXP_migrate_group_not_top_level                 (EMH_SA_W_ERROR_BASE + 220)
#define SA_IMPEXP_migrate_user_not_under_group_role           (EMH_SA_W_ERROR_BASE + 221)
#define SA_IMPEXP_migrate_missing_groupmember_objs            (EMH_SA_W_ERROR_BASE + 222)

/** The group "%1$" is not allowed to be migrated or replicated. The group should be other than "%2$" or its sub-groups. */
#define SA_IMPEXP_group_block_for_export                      (EMH_SA_W_ERROR_BASE + 223)

#define SA_IMPEXP_role_block_for_export                       (EMH_SA_W_ERROR_BASE + 224)
#define SA_IMPEXP_groupmember_block_for_export                (EMH_SA_W_ERROR_BASE + 225)
#define SA_IMPEXP_projteam_groupmember_block_for_export       (EMH_SA_W_ERROR_BASE + 226)
/**The local group "%1$" cannot be added to the replica parent group "%2$", because adding a local group to a replica parent group is not allowed.*/
#define SA_add_local_group_to_replica_group                   (EMH_SA_W_ERROR_BASE + 227)
/**The local group member for the user "%1$" cannot be added to the replica group "%2$", because adding a local group member to a replica group is not allowed.*/
#define SA_add_local_groupmember_to_replica_group             (EMH_SA_W_ERROR_BASE + 228)
/**The specified User ID is not the current session user, the old password for this user is invalid, or the new password is invalid. */
#define SA_invalid_login_user_or_password                     (EMH_SA_W_ERROR_BASE + 229)
/**The user "%1$" cannot be imported, because its home site "%2$" is not present at the replica site.*/
#define SA_IMPEXP_invalid_home_site_on_master_obj             (EMH_SA_W_ERROR_BASE + 230)

/**A provided object of type "%1$" is empty. Please report this error to your system administrator.*/
#define SA_null_user_group_or_role                            (EMH_SA_W_ERROR_BASE + 231)

/**Either the specified user ID is not the current session user, or the logged-in user is not a system administrator or an authorized user or a group administrator.*/
#define SA_invalid_login_user                                 (EMH_SA_W_ERROR_BASE + 232)

/**The logged-in user is not an authorized user, a system administrator or a group administrator.*/
#define SA_not_an_authorized_user                             (EMH_SA_W_ERROR_BASE + 233)

/**Licenses were attached to "%1$".*/
#define SA_single_attach_license_success                      (EMH_SA_W_ERROR_BASE + 234)

/**Licenses were attached to %1$ out of %2$ selections.*/
#define SA_multiple_attach_license_success                    (EMH_SA_W_ERROR_BASE + 235)

/**No license could be attached to "%1$" for the following reason: %2$*/
#define SA_attach_license_failure                             (EMH_SA_W_ERROR_BASE + 236)

/**Licenses were detached from "%1$".*/
#define SA_single_detach_license_success                      (EMH_SA_W_ERROR_BASE + 237)

/**Licenses were detached from %1$ of %2$ selections.*/
#define SA_multiple_detach_license_success                    (EMH_SA_W_ERROR_BASE + 238)

/**No license could be detached from "%1$" for the following reason: %2$*/
#define SA_detach_license_failure                             (EMH_SA_W_ERROR_BASE + 239)

/** @} */
/** @} */
/** @} */


#include <sa/libsa_undef.h>
#endif
