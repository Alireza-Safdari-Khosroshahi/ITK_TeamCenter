/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2020.
Siemens Digital Industries Software.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/
/*
===================================================================================
File description:

Filename:  cae_errors.h
module:    cae.h

This file contains the error codes for the CAE module
====================================================================================================
Date         Name                    Description of Change
16-Apr-2004  Mike Novak              Initial creation
13-May-2004  Charles Cheng           Adds CAE_invalid_vault_data, and
CAE_item_rev_type_for_form_property.
03-Jun-2004  chengc                  New release
21-Jun-2004  chengc                  Attach LOV to properties of CAE loadcase sub-types.
01-Jul-2004  chengc                  For the support of external database via eInt
06-Jul-2004  scobel                  Correct CAE error text problems
22-Jul-2004  scobel                  Handle external files
17-Aug-2004  chengc                  Adds new vaultMode related error msg
01-Sep-2004  scobel                  Implement import ("internalize" external files)
16-Sep-2004  scobel                  Allow editing of result name, type, and description attributes
22-Sep-2004  chengc                  rename CAE_invalid_lov_ary to CAE_invalid_lov_name
13-Oct-2004  scobel                  Clean up after code review
12-Nov-2004  gibsong                 Adding BVR genrator errors
09-Feb-2006  reddyg                  Changes for TcSim(CAE)
24-Feb-2006  reddyg                  Merged to project branch
12-Jun-2006  kumarpra                Updated with Log information.
13-Jun-2006  kumarpra                Structure Map update.
14-Jun-2006  kumarpra                Merged to Team Branch.
15-Jun-2006  shahh                   added new entry
05-Jul-2006  kumarpra                Updated.
05-Jul-2006  shahh                   added new error codes
20-Jul-2006  shahh                   added new error codes for domain checks
21-Jul-2006  kumarpra                Additional Changes.
04-Aug-2006  kumarpra                Item nodeline definition missing.
16-Aug-2006  Gopal Reddy             Fix for PR 5543942
16-Aug-2006  Gopal Reddy             Fix for PR 5543942
18-Aug-2006  Gopal Reddy             Merge to Project Branch
29-Aug-2006  shahh                   PR # 5579362 fix. Made changes for BOMView type implementation
30-Aug-2006  Gopal Reddy             Fix for PR 5585163.
14-Sep-2006  kumarpra                Taking the latest changes from the team branch.
16-Oct-2006  kumarpra                Added "define CAE_XML_failed_to_parse_xml_file ".
15-Nov-2006  kumarpra                Added new errors for Validation of XML files.
$HISTORY$
==================================================================================*/

#ifndef CAE_ERRORS_H
#define CAE_ERRORS_H

#include <common/emh_const.h>
#include <cae/libcae_exports.h>

/* IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!

DO NOT use a message index over 500! This module is set up to use no more than 500 messages!

IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT! */

#define CAE_initialization_failed                                   (EMH_CAE_error_base + 1)
#define CAE_eint_form_type_not_specified                            (EMH_CAE_error_base + 2)
#define CAE_invalid_itemrev_type_for_form_property                  (EMH_CAE_error_base + 3)
#define CAE_undefined_form_storage_class_type                       (EMH_CAE_error_base + 4)
#define CAE_isolated_form_storage_obj                               (EMH_CAE_error_base + 5)
#define CAE_invalid_lov_name                                        (EMH_CAE_error_base + 6)
#define CAE_lov_exist                                               (EMH_CAE_error_base + 7)
#define CAE_cannot_create_eint_temp_file                            (EMH_CAE_error_base + 8)
#define CAE_cannot_delete_eint_temp_file                            (EMH_CAE_error_base + 9)
#define CAE_dataset_not_found                                       (EMH_CAE_error_base + 10)
#define CAE_link_path_not_specified                                 (EMH_CAE_error_base + 11)
#define CAE_file_for_named_ref_not_exist                            (EMH_CAE_error_base + 12)
#define CAE_circular_reference_not_allowed                          (EMH_CAE_error_base + 13)
#define CAE_primary_item_id_or_revid_empty                          (EMH_CAE_error_base + 14)
#define CAE_primary_itemrevision_not_existing                       (EMH_CAE_error_base + 15)
#define CAE_secondary_item_id_or_revid_empty                        (EMH_CAE_error_base + 16)
#define CAE_secondary_itemrevision_not_existing                     (EMH_CAE_error_base + 17)
#define CAE_relation_type_not_existing                              (EMH_CAE_error_base + 18)
#define CAE_relation_already_exists_for_two_revs                    (EMH_CAE_error_base + 19)
#define CAE_unable_to_create_relation                               (EMH_CAE_error_base + 20)
#define CAE_unable_to_save_relation                                 (EMH_CAE_error_base + 21)
#define CAE_primaryIR_has_attachments                               (EMH_CAE_error_base + 22)
#define CAE_unable_to_delete_relation                               (EMH_CAE_error_base + 23)
#define CAE_no_relations_to_delete                                  (EMH_CAE_error_base + 24)
#define CAE_error_in_fetch_relations                                (EMH_CAE_error_base + 25)
#define CAE_one_or_more_namedReferences_not_created                 (EMH_CAE_error_base + 26)
#define CAE_one_or_more_dataset_not_created                         (EMH_CAE_error_base + 27)
#define CAE_one_or_more_references_not_created                      (EMH_CAE_error_base + 28)
#define CAE_EPM_Handler_registration_failed                         (EMH_CAE_error_base + 29)

/* Results management error codes */
#define CAE_duplicate_result_reference                              (EMH_CAE_error_base + 50)
#define CAE_non_existent_xml_file                                   (EMH_CAE_error_base + 51)
#define CAE_non_existent_data_file                                  (EMH_CAE_error_base + 52)
#define CAE_cant_delete_data_file                                   (EMH_CAE_error_base + 53)
#define CAE_cant_find_data_file                                     (EMH_CAE_error_base + 54)
#define CAE_result_not_found                                        (EMH_CAE_error_base + 55)
#define CAE_result_name_required                                    (EMH_CAE_error_base + 56)
#define CAE_cant_find_results_datasettype                           (EMH_CAE_error_base + 57)
#define CAE_cant_find_results_dataset                               (EMH_CAE_error_base + 58)
#define CAE_too_many_results_datasets                               (EMH_CAE_error_base + 59)
#define CAE_result_name_arg_required                                (EMH_CAE_error_base + 60)
#define CAE_item_id_arg_required                                    (EMH_CAE_error_base + 61)
#define CAE_rev_id_arg_required                                     (EMH_CAE_error_base + 62)
#define CAE_xml_file_arg_required                                   (EMH_CAE_error_base + 63)
#define CAE_result_dir_arg_required                                 (EMH_CAE_error_base + 64)
#define CAE_non_existent_directory                                  (EMH_CAE_error_base + 65)

/* BVR generator error codes */
#define CAE_badly_formatted_mapping                                 (EMH_CAE_error_base + 90)
#define CAE_fail_to_open_file                                       (EMH_CAE_error_base + 91)
#define CAE_mapping_addition_failed                                 (EMH_CAE_error_base + 92)
#define CAE_row_removal_failed                                      (EMH_CAE_error_base + 93)
#define CAE_no_mapping_data_found                                   (EMH_CAE_error_base + 94)

/* STRUCTURE MAP ENGINE generator error codes */
#define CAE_no_collapse_single_compAssy_rules                       (EMH_CAE_error_base + 116)
#define CAE_no_rm_empty_subAssy_rules                               (EMH_CAE_error_base + 117)
#define CAE_no_mv_to_collector_rules                                (EMH_CAE_error_base + 118)
#define CAE_no_create_collector_rules                               (EMH_CAE_error_base + 119)
#define CAE_no_skip_rules                                           (EMH_CAE_error_base + 120)
/** 
* The Structure Engine is unable to load/read/parse the StructureMap. 
*/
#define CAE_unable_to_load_read_parse_structure_map                 (EMH_CAE_error_base + 121)
/** 
* The Structure Engine is unable to load/read/parse the Data Map. 
*/
#define CAE_unable_to_load_read_parse_data_map                      (EMH_CAE_error_base + 122)
/** 
* The Structure Engine is able to load/read/parse the StructureMap. 
*/
#define CAE_successful_load_read_parse_structure_map                (EMH_CAE_error_base + 123)
#define CAE_no_filter_rules                                         (EMH_CAE_error_base + 124)
#define CAE_no_mapping_rules                                        (EMH_CAE_error_base + 125)
#define CAE_no_reuse_rules                                          (EMH_CAE_error_base + 126)
#define CAE_no_include_rules                                        (EMH_CAE_error_base + 127)

#define CAE_invalid_structure_map                                   (EMH_CAE_error_base + 128)
#define CAE_invalid_collector_name                                  (EMH_CAE_error_base + 129)

#define CAE_NodeXML_config_unreadable                               (EMH_CAE_error_base + 132)
#define CAE_XML_representation_null                                 (EMH_CAE_error_base + 133)
#define CAE_no_mapping_rules_applicable                             (EMH_CAE_error_base + 138)
#define CAE_invalid_node_schema_in_include_rule                     (EMH_CAE_error_base + 139)
#define CAE_no_include_object_found                                 (EMH_CAE_error_base + 140)

#define CAE_invalid_data_map                                        (EMH_CAE_error_base + 141)
#define CAE_xml_libraries_unavailable                               (EMH_CAE_error_base + 142)
/**
*  The Data Map definition file is not configured. Please contact your system administrator to
*  configure the Item Revision for data mapping through the StructureMap page in the "Edit->Options" command.
*/
#define CAE_data_mapping_preference_not_defined                     (EMH_CAE_error_base + 143)
#define CAE_TC_TMP_DIR_not_defined                                  (EMH_CAE_error_base + 144)

#define CAE_context_state_not_mapping                               (EMH_CAE_error_base + 145)
#define CAE_item_created_successfully                               (EMH_CAE_error_base + 146)
#define CAE_item_creation_failed                                    (EMH_CAE_error_base + 147)
#define CAE_occurrence_creation_failed                              (EMH_CAE_error_base + 148)
#define CAE_object_attribute_not_found                              (EMH_CAE_error_base + 149)
#define CAE_object_not_modifiable                                   (EMH_CAE_error_base + 150)
#define CAE_form_creation_failed                                    (EMH_CAE_error_base + 151)
#define CAE_BOMView_creation_failed                                 (EMH_CAE_error_base + 152)

/**
* The Item "%1$" could not be saved to the "Newstuff" folder. Please check the Teamcenter server syslog file for more information.
*/
#define CAE_unable_to_save_item_in_newstuff_folder                  (EMH_CAE_error_base + 153)

#define CAE_orphan_nodeline_reference_detected                      (EMH_CAE_error_base + 154)
#define CAE_set_attribute_operation_failed                          (EMH_CAE_error_base + 155)
#define CAE_multiple_parents_to_form_detected                       (EMH_CAE_error_base + 156)
#define CAE_multiple_relationship_to_node_detected                  (EMH_CAE_error_base + 157)
#define CAE_existing_relationship_found                             (EMH_CAE_error_base + 158)
#define CAE_relationship_successfully_established                   (EMH_CAE_error_base + 159)
#define CAE_object_attribute_not_modifiable                         (EMH_CAE_error_base + 160)
#define CAE_unable_to_find_rev_tag                                  (EMH_CAE_error_base + 161)
#define CAE_variant_condition_creation_failed                       (EMH_CAE_error_base + 162)
#define CAE_no_implementation_for_object_type                       (EMH_CAE_error_base + 163)
#define CAE_create_relationship_failed                              (EMH_CAE_error_base + 164)
#define CAE_Item_nodeline_definition_missing                        (EMH_CAE_error_base + 165)
#define CAE_StructureMap_domain_not_found                           (EMH_CAE_error_base + 166)

/**
* The extraction of rules from the StructureMap has failed.
*/
#define CAE_extraction_of_rules_failed                              (EMH_CAE_error_base + 171)

/**
* Rules with different domains are found in the same StructureMap/Data Map.
*/
#define CAE_domain_not_uniform_for_rules                            (EMH_CAE_error_base + 172)

/**
* Rules with no defined domain are found in the StructureMap/Data Map.
*/
#define CAE_rules_with_no_domain                                    (EMH_CAE_error_base + 173)

#define CAE_mapping_rules_with_invalid_domain                       (EMH_CAE_error_base + 174)

/**
* StructureMap and Data Map have defined for different domains.
*/
#define CAE_domain_mismatch_structuremap_datamap                    (EMH_CAE_error_base + 175)
#define CAE_no_rules_for_domain                                     (EMH_CAE_error_base + 176)
#define CAE_multiple_variant_clauses_found                          (EMH_CAE_error_base + 177)
#define CAE_error_in_variant_clause_exp_creation                    (EMH_CAE_error_base + 178)
#define CAE_invalid_viewtype_in_Mapping                             (EMH_CAE_error_base + 179)
#define CAE_XML_failed_to_parse_xml_file                            (EMH_CAE_error_base + 180)
#define CAE_error_in_retrieving_dataset                             (EMH_CAE_error_base + 181)
#define CAE_CAEStructureMap_dataset_not_found                       (EMH_CAE_error_base + 182)
#define CAE_error_extracting_file_from_dataset                      (EMH_CAE_error_base + 183)
#define CAE_no_named_references_found_dataset                       (EMH_CAE_error_base + 184)
#define CAE_found_empty_StructureMap_rule_file                      (EMH_CAE_error_base + 185)
#define CAE_OS_error_in_file_read_write_operation                   (EMH_CAE_error_base + 186)
#define CAE_error_in_preprocess_parser_initialization               (EMH_CAE_error_base + 187)
#define CAE_StructureMap_rule_file_already_validated                (EMH_CAE_error_base + 188)
#define CAE_StructureMap_rule_file_is_valid                         (EMH_CAE_error_base + 189)
#define CAE_XML_exception_in_parse_xml_file                         (EMH_CAE_error_base + 190)
#define CAE_no_error_message_from_parser                            (EMH_CAE_error_base + 191)
#define CAE_error_at_line_column                                    (EMH_CAE_error_base + 192)
#define CAE_fatal_error_at_line_column                              (EMH_CAE_error_base + 193)

#define CAE_unable_to_downlaod_primary_input                        (EMH_CAE_error_base + 196)
#define CAE_cant_find_temp_dir                                      (EMH_CAE_error_base + 197)

/**
* The configuration file "NodeXMLConfig.xml" has been updated. A system administrator needs to execute the configuration utility "cae_configure_dm_propertyset" before continuing.
*/
#define CAE_property_set_obsolete                                   (EMH_CAE_error_base + 198)

/**
The length of the domain name "%1$" exceeds the maximum length of %2$ characters.
*/
#define CAE_property_set_invalid_name                               (EMH_CAE_error_base + 199)

#define CAE_sim_process_operation_name                              (EMH_CAE_error_base + 300)
#define CAE_sim_process_operation_desc                              (EMH_CAE_error_base + 301)
#define CAE_sim_process_operation_info                              (EMH_CAE_error_base + 302)
#define CAE_sim_process_unable_to_downlaod_primary_input            (EMH_CAE_error_base + 303)
#define CAE_sim_process_unable_to_find_temp_dir                     (EMH_CAE_error_base + 304)
#define CAE_sim_process_unable_to_open_log_file                     (EMH_CAE_error_base + 305)
#define CAE_sim_process_unable_to_find_file                         (EMH_CAE_error_base + 306)
#define CAE_sim_process_one_or_more_dataset_not_created             (EMH_CAE_error_base + 307)
#define CAE_sim_process_cant_find_configured_tool                   (EMH_CAE_error_base + 308)
#define CAE_sim_process_more_info                                   (EMH_CAE_error_base + 309)

#define CAE_sim_process_launch_err_process_not_found                (EMH_CAE_error_base + 310)
#define CAE_sim_process_launch_err_config_file_not_found            (EMH_CAE_error_base + 311)
#define CAE_sim_process_launch_err_input_rule_config_error          (EMH_CAE_error_base + 312)
#define CAE_sim_process_launch_workflow_background_warning          (EMH_CAE_error_base + 313)
#define CAE_sim_process_launch_workflow_err_process_failure         (EMH_CAE_error_base + 314)

#define CAE_license_feature_not_available                           (EMH_CAE_error_base + 315)
#define CAE_sim_process_config_dataset_not_unique                   (EMH_CAE_error_base + 316)
#define CAE_sim_process_launch_err_output_rule_config_error         (EMH_CAE_error_base + 317)

#define CAE_sim_process_launch_log_file_not_created                 (EMH_CAE_error_base + 318)
#define CAE_sim_process_launch_working_dir_not_created              (EMH_CAE_error_base + 319)
#define CAE_sim_process_launch_process_not_specified                (EMH_CAE_error_base + 320)
#define CAE_sim_process_launch_process_input_types_undefined        (EMH_CAE_error_base + 321)
#define CAE_sim_process_launch_process_input_rule_undefined         (EMH_CAE_error_base + 322)
#define CAE_sim_process_launch_script_not_specified                 (EMH_CAE_error_base + 323)
#define CAE_sim_process_launch_no_file_to_export                    (EMH_CAE_error_base + 324)
#define CAE_sim_process_workingdir_empty_space                      (EMH_CAE_error_base + 325)
#define CAE_error_in_xerces_c_initialization                        (EMH_CAE_error_base + 326)
#define CAE_error_while_parsing_file                                (EMH_CAE_error_base + 327)
/**
* An error has occurred while marking the object "%1$" up-to-date. Please refer to the Teamcenter server log file for more information.
*/
#define CAE_error_while_markUpToDate                                (EMH_CAE_error_base + 328)

/**
* A constant referencing the error message occurring during the retrieval of property comparison details.
* The property comparison details could not be found for the target BOM Line "%1$". Please refer to the Teamcenter server log file for more information.
*/
#define CAE_error_prop_compare_detail_not_found                     (EMH_CAE_error_base + 329)

/**
* The object of type "%1$" is not attached to the root model revision. As a consequence, a domain for data mapping is required to be specified through the &apos;-domain=&apos; option.
*/
#define CAE_AC_error_no_domain_specified                            (EMH_CAE_error_base + 330)
/**
* The number of inputs %1$ is not between the minimum criteria of %2$ and maximum criteria of %3$ defined for the simulation tool.
*/
#define CAE_sim_process_launch_workflow_min_max_error               (EMH_CAE_error_base + 331)
/**
* The number of named references is incorrect. The named references allowed in the Data Map Definition dataset is restricted to a single Data Mapping file and a single NodeXMLConfig file.
*/
#define CAE_data_map_definition_dataset_extra_files_present         (EMH_CAE_error_base + 332)
/**
* The "%1$" config file is not present in the Data Map Definition dataset.
*/
#define CAE_data_map_definition_nodexml_config_file_not_present     (EMH_CAE_error_base + 333)
/**
* The data mapping file in the Data Map Definition dataset is present with an invalid extension. Please use the .xml extension for the data mapping file.
*/
#define CAE_data_mapping_file_with_invalid_extension                (EMH_CAE_error_base + 334)
/**
* The selected launch script path contains spaces, and cannot, therefore, be executed: %1$.
*/
#define CAE_sim_process_launch_script_space_error                   (EMH_CAE_error_base + 335)
/**
* The CAE Accountability Check comparison is required before the propagation can be executed. Please run the CAE Accountability Check comparison first.
*/
#define CAE_AC_result_not_found_error                               (EMH_CAE_error_base + 336)

/**
* The data mapping log file cannot be imported into Teamcenter because the Teamcenter volume access has an issue. Please contact your system administrator.
*/
#define CAE_cannot_import_log_into_teamcenter                       (EMH_CAE_error_base + 337)

/**
* Text cannot be written to the detail log file. Check the protection of the temporary directory file "%1$" or the access to the temporary directory.
*/
#define CAE_cannot_write_to_detail_log_file                         (EMH_CAE_error_base + 338)

/**
* The detail log file cannot be closed. Check the protection of the temporary directory file "%1$" or the access to the temporary directory.
*/
#define CAE_cannot_close_detail_log_file                            (EMH_CAE_error_base + 339)

/**
* The imported log file cannot be closed. Check the protection of the temporary directory file "%1$" or the access to the temporary directory.
*/
#define CAE_cannot_close_final_log_file                             (EMH_CAE_error_base + 340)

/**
* The detail log file cannot be deleted. Check the protection of the temporary directory file "%1$" or the access to the temporary directory.
*/
#define CAE_cannot_delete_detail_log_file                           (EMH_CAE_error_base + 341)

/**
* The summary log file cannot be deleted. Check the protection of the temporary directory file "%1$" or the access to the temporary directory.
*/
#define CAE_cannot_delete_summary_log_file                          (EMH_CAE_error_base + 342)

/**
* The detail log file cannot be opened as read only. Check the protection of the temporary directory file "%1$" or the access to the temporary directory.
*/
#define CAE_cannot_open_ro_detail_log_file                          (EMH_CAE_error_base + 343)

/**
* The logging system has experienced an initialization error. Check the Teamcenter system log for details.
*/
#define CAE_logging_system_initialization_error                     (EMH_CAE_error_base + 344)

/**
* The Model Dashboard Location is not configured. Please contact your system administrator to configure the Item Revision for Model Dashboard through the Model Dashboard page in the "Edit->Options" command.
*/
#define CAE_sim_data_monitor_preference_not_defined                 (EMH_CAE_error_base + 345)

/**
* The Model Dashboard Configuration is not defined. Please configure the Model Dashboard in the toolbar drop-down "CAE Configuration->Model Dashboard Configuration" command.
*/
#define CAE_sim_data_monitor_config_file_path_empty                 (EMH_CAE_error_base + 346)

/**
* The Model Dashboard Configuration is invalid. Please correct the configuration in the toolbar drop-down "CAE Configuration->Model Dashboard Configuration" command.
*/
#define CAE_sim_data_monitor_config_file_invalid                    (EMH_CAE_error_base + 347)

/**
* An error has occurred during the "Derive" operation. Please refer to the Teamcenter syslog file for more information.
*/
#define CAE_derive_operation_error                                  (EMH_CAE_error_base + 348)

/**
* The Derive engine is unable to load, read or parse the "%1$". Please contact your system administrator.
*/
#define CAE_unable_to_load_read_parse_derive                        (EMH_CAE_error_base + 349)

/**
* There is no "OUT" focus property set found in the "%1$".  A system administrator or simulation administrator needs to configure with appropriate Focus and Domain.
*/
#define CAE_unable_to_locate_out_block                              (EMH_CAE_error_base + 350)

/**
* The current selected Derive configuration xml file is invalid. Please contact your system administrator.
*/
#define CAE_invalid_derive_xml                                      (EMH_CAE_error_base + 351)

/**
* The selected Ruleset was not found in the derive location. Please contact your system administrator.
*/
#define CAE_invalid_ruleset                                         (EMH_CAE_error_base + 352)

/**
* Rules with no selected domain or type defined are found in the "%1$" file. A system administrator or simulation administrator needs to configure it with an appropriate domain or type.
*/
#define CAE_invalid_derive_domain                                   (EMH_CAE_error_base + 353)

/**
* The database schema has not been updated for this functionality to execute. Please contact your system adminstrator.
*/
#define CAE_outdated_schema                                         (EMH_CAE_error_base + 354)

/** The Simulation Tool "%1$" is already released. */
#define CAE_object_aready_released                                  (EMH_CAE_error_base + 355)

/**
The Simulation Tool "%1$" cannot be released, because its parent is not yet released.
*/
#define CAE_parent_not_released                                      (EMH_CAE_error_base + 356)

/** A schema change is necessary to proceed with the installation of the Simulation Process Management template. Please refer to the Release Notes for more details. */
#define CAE_template_feature_not_installed                           (EMH_CAE_error_base + 357)

/**
A Simulation Tool with name "%1$" already exists under the selected parent category "%2$".
*/
#define CAE_duplicate_tool_found                                     (EMH_CAE_error_base + 358)

/**
The provided Owning User "%1$" could not be found.
*/
#define CAE_user_not_found                                           (EMH_CAE_error_base + 359)

/**
The provided Owning Group "%1$" could not be found.
*/
#define CAE_group_not_found                                          (EMH_CAE_error_base + 360)

/**
The Simulation Tool "%1$" could not be launched, because it is not yet released.
*/
#define CAE_unreleased_tool_launch                                   (EMH_CAE_error_base + 361)

/**
* The configuration file "%1$" has been updated. A system administrator needs to execute the configuration utility "cae_configure_dm_propertyset" before continuing.
*/
#define CAE_nodeconfigxml_updated                                   (EMH_CAE_error_base + 362)

/**
* CAE Scope rules are missing. A system administrator needs to import the "%1$" file present in TC_DATA directory.
*/
#define CAE_scope_rules_missing                                    (EMH_CAE_error_base + 363)

/** The Simulation Tool configuration is not migrated. Please contact your system administrator.*/
#define CAE_tools_are_not_migrated                                   (EMH_CAE_error_base + 364)

/** The Simulation Tool name "%1$" exceeds the allowed length of %2$.*/
#define CAE_name_length_exceeds_allowed                              (EMH_CAE_error_base + 365)

/** The current user does not have delete access to the object "%1$".*/
#define CAE_tools_no_delete_access                                   (EMH_CAE_error_base + 366)

/** The paste operation has failed, because the object "%1$" is not a valid Simulation Tool.*/
#define CAE_invalid_simulation_tool_paste                            (EMH_CAE_error_base + 367)

/**
* CAE Target References Scope rules are missing. Please contact your system administrator to import the "%1$" file present in the TC_DATA directory.
*/
#define CAE_scope_rules_missing_target_references_view               (EMH_CAE_error_base + 368)

/**
* CAE Composite Scope rules are missing. Please contact your system administrator to import the "%1$" file present in the TC_DATA directory.
*/
#define CAE_scope_rules_missing_composite_view                       (EMH_CAE_error_base + 369)

/**
* The Pedigree cannot be captured, because the source "%1$" has multiple relation instances.
*/
#define CAE_model_pedigree_multiple_instances                        (EMH_CAE_error_base + 370)

/**
* The Pedigree cannot be captured, because no relation exists as required by the preference "%2$" for relations of type "%1$".
*/
#define CAE_pedigree_no_relation_found                               (EMH_CAE_error_base + 371)

/**
* The Pedigree cannot be captured, because "%1$" is not a root BOM Line.
*/
#define CAE_pedigree_no_capture_root_bomline                         (EMH_CAE_error_base + 372)

/**
* The Pedigree cannot be captured, because no BOM Line is selected for "%1$".
*/
#define CAE_pedigree_no_bomline_selection                            (EMH_CAE_error_base + 373)

/**
* The Simulation Tool "%1$" cannot be unreleased because one of its children is released.
*/
#define CAE_child_tool_released                                      (EMH_CAE_error_base + 374)

/**
* A valid Configuration Item type must be provided.
*/
#define CAE_config_type_not_provided                                 (EMH_CAE_error_base + 375)

/**
* The migration mode of the Configuration Items must be provided.
*/
#define CAE_migration_mode_not_provided                              (EMH_CAE_error_base + 376)

/**
* The path to the XML file must be provided.
*/
#define CAE_xml_file_path_not_provided                               (EMH_CAE_error_base + 377)

/**
* Only the migration modes "export" and "import" are allowed.
*/
#define CAE_invalid_migration_mode                                   (EMH_CAE_error_base + 378)

/**
* Valid values for the scope are "Site", "Group" and "User".
*/
#define CAE_invalid_scope                                            (EMH_CAE_error_base + 379)

/**
* A valid Owning User must be provided.
*/
#define CAE_config_owning_user_not_provided                          (EMH_CAE_error_base + 380)

/**
* A valid Owning Group must be provided.
*/
#define CAE_config_owning_group_not_provided                         (EMH_CAE_error_base + 381)

/**
* A valid combination of Owning User and Owning Group must be provided.
*/
#define CAE_config_owning_user_and_owning_group_not_provided         (EMH_CAE_error_base + 382)

/**
* No matching CAE Configurations are found for export based on the input item type.
*/
#define CAE_configuration_matching_object_not_found                  (EMH_CAE_error_base + 383)

/**
* Valid values for the status are "Approved", "Obsolete", "Pending", "PlanningSyncDate", "Rejected", "TC Baselined", "TCM Released", "Validation" and any other value defined in the BMIDE through the menu command "Extensions -> Template_Name -> Options -> Status".
*/
#define CAE_invalid_status                                           (EMH_CAE_error_base + 384)

/**
* The Derive engine is unable to load, read or parse the "%1$" file. Please contact your system administrator.
*/
#define CAE_unable_to_load_read_parse_var_config                     (EMH_CAE_error_base + 385)

/**
* The provided input object "%1$" is invalid because only objects of type "CAEAnalysisRevision" and "CAEModelRevision" are supported.
*/
#define CAE_invalid_input_tag_to_get_cae_status                      (EMH_CAE_error_base + 386)

/**
*  An internal error "%1$" has occurred. Please report this to your system administrator.
*/
#define CAE_internal_error                                           (EMH_CAE_error_base + 387)

/**
* The CAE Item migration utility has failed because only system administrators can import CAE Configurations at the site level. Please contact your system administrator to import the objects at the site level.
*/
#define CAE_user_not_dba                                             (EMH_CAE_error_base + 388)

/**
* The CAE Item migration utility has failed because only a group administrator can import CAE Configurations at the group level. Please contact your group administrator to import the objects at the group level.
*/
#define CAE_user_not_group_admin                                     (EMH_CAE_error_base + 389)

/**
* The CAE Item migration utility has failed because only a group with system administration priviledge can import CAE Configurations at the site level. Please contact your system administrator to import the objects at the site level.
*/
#define CAE_owning_group_not_dba                                     (EMH_CAE_error_base + 390)

/**
* The simulation dashboard configuration is invalid because only simulation dashboards of type Model Dashboard are allowed to launch the dashboard for a model structure.
*/
#define CAE_invalid_dashbord_configuration                           (EMH_CAE_error_base + 391)

/**
* The CAE StructureMap Filter Item "%1$" does not have any released revision. Either release any revision or change the exclusion list configuration to use Latest Working Revision.
*/
#define CAE_structure_map_filter_latest_released_revision_not_found  (EMH_CAE_error_base + 392)

/**
* The CAE StructureMap Filter Revision "%1$" contains an invalid exclusion rule "%2$". The format for the exclusion rule should be ClassName::TypeName::AttributeInternalName::AttributeValue. e.g.- ItemRevision::ItemRevision::object_name::Engine
*/
#define CAE_structure_map_filter_incorrect_exclusion_list_format     (EMH_CAE_error_base + 393)

/**
* The CAE StructureMap Filter Dataset "%1$" related with CAE StructureMap Filter Revision "%2$" does not contain any named references. Please add a file of type "*.txt" or "*.xml" as a named reference.
*/
#define CAE_structure_map_filter_named_reference_not_found           (EMH_CAE_error_base + 394)

/**
* The CAE StructureMap Filter Revision "%1$" does not have any CAE StructureMap Filter Dataset attached with CAE StructureMap Filter Relation.
*/
#define CAE_structure_map_filter_dataset_not_found                   (EMH_CAE_error_base + 395)

/**
* The CAE StructureMap Filter Dataset attached to the CAE StructureMap Filter Revision "%1$" does not contain a file of type "*.txt". The exclusion list is a "*.txt" file added as a named reference to the dataset.
*/
#define CAE_structure_map_filter_incorrect_filter_type_exclusion     (EMH_CAE_error_base + 396)

/**
* The CAE StructureMap Filter Dataset attached to the CAE StructureMap Filter Revision "%1$" does not contain a file of type "*.plmxml". The inclusion list is a "*.plmxml" file added as a named reference to the dataset.
*/
#define CAE_structure_map_filter_incorrect_filter_type_inclusion     (EMH_CAE_error_base + 397)

/**
* The CAE StructureMap Filter Dataset attached to the CAE StructureMap Filter Revision "%1$" contains an invalid format PLMXML file. The valid inclusion rule contains a PLMXML file generated by the Lifecycle Viewer application.
*/
#define CAE_structure_map_filter_incorrect_inclusion_list_format     (EMH_CAE_error_base + 398)

/**
* The provided input object "%1$" is not of type CAE StructureMap Filter Revision.
*/
#define CAE_structure_map_filter_invalid_type                        (EMH_CAE_error_base + 399)

/**
* The async StructureMap execution can be performed in 4-Tier environment only. Please contact your system administrator for details.
*/
#define CAE_structure_map_async_supported_platform                   (EMH_CAE_error_base + 400)

/**
* The CAE StructureMap Filter Item "%1$" does not have any working revision. Either create a working revision or change the exclusion list configuration to use the Latest Released Revision.
*/
#define CAE_structure_map_filter_latest_working_revision_not_found   (EMH_CAE_error_base + 401)

/**
* The target type "%1$" is not an Item Revision nor one of its subtypes.
*/
#define CAE_invalid_target_types                                     (EMH_CAE_error_base + 402)

/**
* A valid CAD Item ID or CAD Item Name must be provided.
*/
#define CAE_invalid_query_arguments                                  (EMH_CAE_error_base + 403)

/**
* No CAD Item Revisions found for the given inputs.
*/
#define CAE_no_cad_rev_found                                         (EMH_CAE_error_base + 404)

/**
* The use of list separator is not supported for CAD Revision ID field.
*/
#define CAE_separator_not_supported                                   (EMH_CAE_error_base + 405)

/**
* The scratch directory cannot be created.
*/
#define CAE_scratch_directory_not_created                             (EMH_CAE_error_base + 406)

/**
* The user staging directory cannot be created.
*/
#define CAE_staging_directory_not_created                            (EMH_CAE_error_base + 407)

/**
* The PropertySet is configured with partial errors. There are invalid object classes, types or properties found in the %1$. Please check log file %2$ for more details.
*/
#define CAE_NodeLine_Types_Properties_Skipped                        (EMH_CAE_error_base + 408)

/**
* The PropertySet is configured with partial errors. There are invalid object classes, types or properties found in the %1$. Please execute the utility with "-log" option and check log file for more details. 
*/
#define CAE_NodeLine_Types_Properties_Skipped_WithOut_Logging        (EMH_CAE_error_base + 409)

/**
* The file name "%1$" is invalid.
*/
#define CAE_invalid_file_name                                        (EMH_CAE_error_base + 410)

/**
* The material export filter name "%1$" is invalid.
*/
#define CAE_invalid_material_export_filter_name                      (EMH_CAE_error_base + 411)

/**
* No output files uploaded or weblinks created for the configured output rules.
*/
#define CAE_sim_process_no_files_uploaded_or_web_links_created       (EMH_CAE_error_base + 412)


/* IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!

DO NOT use a message index over 500! This module is set up to use no more than 500 messages!

IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT!  IMPORTANT! */

#include <cae/libcae_undef.h>
#endif
