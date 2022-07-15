
/*==================================================================================================

                          Copyright (c) 2002 EDS/PLM
                       Unpublished - All rights reserved

====================================================================================================
File description:

    Collaboration Context module errors.

This file contains Error definitions related to Application Interface module.

====================================================================================================
   Date      Name                    Description of Change
23-Oct-2003  Shyam Arigapudi         Created
20-Nov-2003  Shyam Arigapudi         created
11-Dec-2003  Shyam Arigapudi         add unknown err
19-Dec-2003  Shyam Arigapudi         ai recording
26-Dec-2003  Shyam Arigapudi         fix date format
02-Mar-2004  arigapud                update
08-Mar-2004  arigapud                upd
30-Jun-2004  Shyam Arigapudi         add more codes
25-Oct-2004  Shyam Arigapudi         add fms
17-Jul-2005  arigapud                add errors
17-Jul-2005  arigapud                fix typo
27-Jul-2005  arigapud                add more strings
25-Jan-2006  arigapud                updated
30-Jan-2006  arigapud                updated
11-Feb-2006  arigapud                upated
28-Mar-2006  arigapud                updated
$HISTORY$
==================================================================================================*/

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//Whenever you change this header - make sure to update the aiws_errors.xml
//in /src/textsrv/xml folder
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#ifndef AI_AIWS_ERRORS_H
#define AI_AIWS_ERRORS_H

#include <common/emh_const.h>

#include <ai/libai_exports.h>

//Whenever an error code is added below - make sure to update MakeErrors function in aiws_utils.cxx
#define AIWS_filepermission_error                  (EMH_AI_error_base + 101)
#define AIWS_lock_fail_error                       (EMH_AI_error_base + 102)
#define AIWS_unlock_fail_error                     (EMH_AI_error_base + 103)
#define AIWS_invalid_section                       (EMH_AI_error_base + 104)
#define AIWS_invalid_login                         (EMH_AI_error_base + 105)
#define AIWS_memory_error                          (EMH_AI_error_base + 106)
#define AIWS_cannot_create_writer                  (EMH_AI_error_base + 107)
#define AIWS_cannot_create_reader                  (EMH_AI_error_base + 108)
#define AIWS_invalid_attr_id                       (EMH_AI_error_base + 109)
#define AIWS_invalid_attr_format                   (EMH_AI_error_base + 110)
#define AIWS_invalid_targetAppId                   (EMH_AI_error_base + 111)
#define AIWS_error_creating_reqobj                 (EMH_AI_error_base + 112)
#define AIWS_error_structure_file                  (EMH_AI_error_base + 113)
#define AIWS_unknown_error                         (EMH_AI_error_base + 114)
#define AIWS_Date_Error                            (EMH_AI_error_base + 115)
#define AIWS_unable_to_add_pub_request             (EMH_AI_error_base + 116)
#define AIWS_unable_to_add_sync_request            (EMH_AI_error_base + 117)
#define AIWS_invalid_id                            (EMH_AI_error_base + 118)
#define AIWS_invalid_array_sizes                   (EMH_AI_error_base + 119)
#define AIWS_invalid_transfermode                  (EMH_AI_error_base + 120)
#define AIWS_invalid_revision_rule                 (EMH_AI_error_base + 121)
#define AIWS_unable_to_create_pie_session          (EMH_AI_error_base + 122)
#define AIWS_unable_to_find_function               (EMH_AI_error_base + 123)
#define AIWS_unable_to_find_reader                 (EMH_AI_error_base + 124)
#define AIWS_unable_to_find_writer                 (EMH_AI_error_base + 125)
#define AIWS_unable_to_create_kv_pair              (EMH_AI_error_base + 126)
#define AIWS_src_file_folders_and_ids_do_not_match (EMH_AI_error_base + 127)
#define AIWS_invalid_input_xml_string              (EMH_AI_error_base + 128)
#define AIWS_invalid_journal                       (EMH_AI_error_base + 129)
#define AIWS_no_tickets_section_found              (EMH_AI_error_base + 130)
#define AIWS_mismatched_tickets_and_filenames      (EMH_AI_error_base + 131)
#define AIWS_no_tickets_specified                  (EMH_AI_error_base + 132)
#define AIWS_no_fileIds_specified                  (EMH_AI_error_base + 133)
#define AIWS_mismatched_tickets_and_appnames       (EMH_AI_error_base + 134)
#define AIWS_missing_original_filename             (EMH_AI_error_base + 135)
#define AIWS_missing_original_filenames            (EMH_AI_error_base + 136)
#define AIWS_filenames_and_filetypes_do_not_match  (EMH_AI_error_base + 137)
#define AIWS_no_filenames_specified                (EMH_AI_error_base + 138)
#define AIWS_invalid_ai_type                       (EMH_AI_error_base + 139)
#define AIWS_invalid_import_tmode                  (EMH_AI_error_base + 140)
#define AIWS_invalid_export_tmode                  (EMH_AI_error_base + 141)
#define AIWS_invalid_description_specified         (EMH_AI_error_base + 142)
#define AIWS_invalid_name_specified                (EMH_AI_error_base + 143)
#define AIWS_partial_export_ids_must               (EMH_AI_error_base + 144)
#define AIWS_full_AI_baseref_exist                 (EMH_AI_error_base + 145)
#define AIWS_incorrect_name_length                 (EMH_AI_error_base + 146)
#define AIWS_incorrect_desc_length                 (EMH_AI_error_base + 147)
#define AIWS_incorrect_type_length                 (EMH_AI_error_base + 148)
#define AIWS_incorrect_userid_length               (EMH_AI_error_base + 149)
#define AIWS_incorrect_groupname_length            (EMH_AI_error_base + 150)
#define AIWS_incorrect_applicationid_length        (EMH_AI_error_base + 151)
#define AIWS_incorrect_siteid_length               (EMH_AI_error_base + 152)
#define AIWS_incorrect_targetappid_length          (EMH_AI_error_base + 153)
#define AIWS_no_request_objects_found_after_processing   (EMH_AI_error_base + 154)
#define AIWS_no_sync_requests_with_any_status      (EMH_AI_error_base + 155)
#define AIWS_no_uid_for_ticket                     (EMH_AI_error_base + 156)
#define AIWS_error_importing_structure             (EMH_AI_error_base + 157)
#define AIWS_invalid_plmxml_file_id                (EMH_AI_error_base + 158)
#define AIWS_cannot_create_temp_file               (EMH_AI_error_base + 159)
#define AIWS_mismatched_projectId_projectInfo      (EMH_AI_error_base + 160)
#define AIWS_mismatched_array_sizes                (EMH_AI_error_base + 161)
#define AIWS_property_set_not_found                (EMH_AI_error_base + 162)
#define AIWS_proxy_exoprt_new_process              (EMH_AI_error_base + 163)
#define AIWS_proxy_get_trace_report                (EMH_AI_error_base + 164)
#define AIWS_proxy_set_last_sync_date              (EMH_AI_error_base + 165)
#define AIWS_proxy_get_class_names                 (EMH_AI_error_base + 166)
#define AIWS_proxy_failed_creating_process         (EMH_AI_error_base + 167)
#define AIWS_proxy_set_properties_to_master        (EMH_AI_error_base + 168)
#define AIWS_proxy_no_user_in_db                   (EMH_AI_error_base + 169)
#define AIWS_proxy_get_type_names                  (EMH_AI_error_base + 170)
#define AIWS_proxy_update_properties               (EMH_AI_error_base + 171)
#define AIWS_proxy_no_keys_values                  (EMH_AI_error_base + 172)
#define AIWS_proxy_get_proxy_uid                   (EMH_AI_error_base + 173)
#define AIWS_proxy_exp_obj_not_in_db               (EMH_AI_error_base + 174)
#define AIWS_proxy_get_class_relation_types        (EMH_AI_error_base + 175)
#define AIWS_proxy_revise_item                     (EMH_AI_error_base + 176)
#define AIWS_proxy_failed_creating_proxy           (EMH_AI_error_base + 177)
#define AIWS_proxy_not_in_db                       (EMH_AI_error_base + 178)
#define AIWS_proxy_create_wso_instance             (EMH_AI_error_base + 179)
#define AIWS_proxy_no_process_template             (EMH_AI_error_base + 180)
#define AIWS_proxy_get_latest_revision             (EMH_AI_error_base + 181)
#define AIWS_proxy_destroy_process_link            (EMH_AI_error_base + 182)
#define AIWS_proxy_no_templates                    (EMH_AI_error_base + 183)
#define AIWS_proxy_failed_exp_obj_record           (EMH_AI_error_base + 184)
#include <ai/libai_undef.h>
#endif
