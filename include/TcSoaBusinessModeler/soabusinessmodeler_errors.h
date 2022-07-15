/* =================================================================================================
           Copyright (c) 1999,2000,2001,2003 Unigraphics Solutions Inc., An EDS Company
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
====================================================================================================*/

/**
    @file

    Errors for the soa core services


*/

#ifndef SOABUSINESSMODELER_ERRORS_H
#define SOABUSINESSMODELER_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SOABUSINESSMODELER_ERRORS TCWS Errors
    @ingroup SOABUSINESSMODELER
    @{
*/

/** Invalid login username */
//#define SOABUSINESSMODELER_bad_username                                     (EMH_SOABUSINESSMODELER_error_base + 0)

/*
 * Error messages for importDataModel SOA
 */
#define SOABUSINESSMODELER_bmide_processtemplates_not_found                 (EMH_SOABUSINESSMODELER_error_base + 1)

#define SOABUSINESSMODELER_tcdata_not_defined                               (EMH_SOABUSINESSMODELER_error_base + 2)

#define SOABUSINESSMODELER_deltaxml_does_not_exist                          (EMH_SOABUSINESSMODELER_error_base + 3)

#define SOABUSINESSMODELER_upgrade_not_allowed                              (EMH_SOABUSINESSMODELER_error_base + 4)

#define SOABUSINESSMODELER_install_mode_not_allowed                         (EMH_SOABUSINESSMODELER_error_base + 5)

#define SOABUSINESSMODELER_file_does_not_exist                              (EMH_SOABUSINESSMODELER_error_base + 6)

#define SOABUSINESSMODELER_extract_data_model_failed                        (EMH_SOABUSINESSMODELER_error_base + 7)

#define SOABUSINESSMODELER_bmide_setupknowledgebase_not_found               (EMH_SOABUSINESSMODELER_error_base + 8)

#define SOABUSINESSMODELER_CLIPS_dataset_upload_failed                      (EMH_SOABUSINESSMODELER_error_base + 9)

#define SOABUSINESSMODELER_invalid_deploy_option                            (EMH_SOABUSINESSMODELER_error_base + 10)

#define SOABUSINESSMODELER_dependency_files_not_found                       (EMH_SOABUSINESSMODELER_error_base + 11)

#define SOABUSINESSMODELER_directory_does_not_exist                         (EMH_SOABUSINESSMODELER_error_base + 12)

#define SOABUSINESSMODELER_invalid_deployment_file_type                     (EMH_SOABUSINESSMODELER_error_base + 13)

#define SOABUSINESSMODELER_deployment_inputs_error                          (EMH_SOABUSINESSMODELER_error_base + 14)

#define SOABUSINESSMODELER_delta_langxml_does_not_exist                     (EMH_SOABUSINESSMODELER_error_base + 15)

#define SOABUSINESSMODELER_template_does_not_exist                          (EMH_SOABUSINESSMODELER_error_base + 16)

#define SOABUSINESSMODELER_deployment_lock_in_effect                        (EMH_SOABUSINESSMODELER_error_base + 17)

#define SOABUSINESSMODELER_ops_data_deploy_not_allowed                      (EMH_SOABUSINESSMODELER_error_base + 18)

#define SOABUSINESSMODELER_process_tmplt_manage_template_failed             (EMH_SOABUSINESSMODELER_error_base + 19)

#define SOABUSINESSMODELER_process_tmplt_getsiteinfo_failed                 (EMH_SOABUSINESSMODELER_error_base + 20)

#define SOABUSINESSMODELER_process_tmplt_outofsync_incorp                   (EMH_SOABUSINESSMODELER_error_base + 21)

#define SOABUSINESSMODELER_process_tmplt_outofsync_synch                    (EMH_SOABUSINESSMODELER_error_base + 22)

#define SOABUSINESSMODELER_process_tmplt_locale_check                       (EMH_SOABUSINESSMODELER_error_base + 23)

#define SOABUSINESSMODELER_process_tmplt_ops_pref_failed                    (EMH_SOABUSINESSMODELER_error_base + 24)

#define SOABUSINESSMODELER_process_tmplt_delta_load_fail                    (EMH_SOABUSINESSMODELER_error_base + 25)

#define SOABUSINESSMODELER_process_tmplt_delta_not_valid                    (EMH_SOABUSINESSMODELER_error_base + 26)

#define SOABUSINESSMODELER_process_tmplt_pref_fetch_fail                    (EMH_SOABUSINESSMODELER_error_base + 27)

#define SOABUSINESSMODELER_process_tmplt_encoding_check                     (EMH_SOABUSINESSMODELER_error_base + 28)

#define SOABUSINESSMODELER_process_tmplt_encoding_reading_fail              (EMH_SOABUSINESSMODELER_error_base + 29)

#define SOABUSINESSMODELER_unknown_error                                    (EMH_SOABUSINESSMODELER_error_base + 30)

#define SOABUSINESSMODELER_cannot_parse_xml_file                            (EMH_SOABUSINESSMODELER_error_base + 31)

#define SOABUSINESSMODELER_dependent_template_not_deployed                  (EMH_SOABUSINESSMODELER_error_base + 32)

/*
 * An error has occurred while adding the entries to the master file.
 */
#define SOABUSINESSMODELER_add_entries_to_master_file_failed                (EMH_SOABUSINESSMODELER_error_base + 33)

/*
 * An error has occurred while creating the backup of the file "model.xml".
 */
#define SOABUSINESSMODELER_create_backup_of_model_failed                    (EMH_SOABUSINESSMODELER_error_base + 34)

/*
 * An error has occurred while creating the backup of the file "model_lang.xml".
 */
#define SOABUSINESSMODELER_create_backup_of_model_lang_failed               (EMH_SOABUSINESSMODELER_error_base + 35)

/*
 * An error has occurred while consolidating the templates from the master file into the file "model.xml".
 */
#define SOABUSINESSMODELER_consolidation_to_model_failed                    (EMH_SOABUSINESSMODELER_error_base + 36)

/*
 * An error has occurred while consolidating the localization files into the file "model_lang.xml".
 */
#define SOABUSINESSMODELER_consolidation_to_model_lang_failed               (EMH_SOABUSINESSMODELER_error_base + 37)

/** @} */

#endif

