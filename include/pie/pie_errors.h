/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Error code definitions for the PLM XML Import/Export (PIE) module.
*/

/*  */

#ifndef PIE_ERRORS_H
#define PIE_ERRORS_H

#include <common/emh_const.h>
#include <pie/libpie_exports.h>

/**
    @defgroup PIE_ERRORS PIE Errors
    @ingroup PIE
    @{
*/

#define PIE_error_base                                  EMH_PIE_error_base

/** PIE internal error. */
#define PIE_internal_error                              (PIE_error_base + 1)

/** Insufficent privilege to perform this Import/Export operation. */
#define PIE_insufficient_privilege                      (PIE_error_base + 2)

/** Specified clause value is not valid. */
#define PIE_invalid_clause                              (PIE_error_base + 3)

/** Transfer mode with given name already exists. */
#define PIE_duplicate_transfer_mode                     (PIE_error_base + 4)

/** Transfer mode not created. */
#define PIE_transfer_mode_not_created                   (PIE_error_base + 5)

/** Closure rule with given name already exists. */
#define PIE_duplicate_closure_rule                      (PIE_error_base + 6)

/** Closure rule not created. */
#define PIE_closure_rule_not_created                    (PIE_error_base + 7)

/** Filter rule with given name already exists. */
#define PIE_duplicate_filter_rule                       (PIE_error_base + 8)

/** Filter rule not created. */
#define PIE_filter_rule_not_created                     (PIE_error_base + 9)

/** Property set with given name already exists. */
#define PIE_duplicate_property_set                      (PIE_error_base + 10)

/** PropertySet not created. */
#define PIE_property_set_not_created                    (PIE_error_base + 11)

/**  The PLMXML file could not be loaded. The possible causes are: non-existence, permission problem, invalid format, unsupported schema. Please check and try again. */
#define PIE_document_load_error                         (PIE_error_base + 12)

/** PLMAppUID not created. */
#define PIE_plmappuid_not_created                       (PIE_error_base + 13)

/** PLMAppUID Object could not be found. */
#define PIE_plmappuid_illegal_parameter                 (PIE_error_base + 14)

/** Transfer action with given name already exists. */
#define PIE_duplicate_transfer_action                   (PIE_error_base + 15)

/** Transfer action not created. */
#define PIE_transfer_action_not_created                 (PIE_error_base + 16)

/** No Item or Product Identifier. */
#define PIE_bad_item_product_id                         (PIE_error_base + 18)

/** Object has no Parent Tc Tag. */
#define PIE_no_parent_tc_tag                            (PIE_error_base + 19)

#define PIE_imp_can_not_create_appgrp                   (PIE_error_base + 20)

/** Value not set for property: */
#define PIE_bad_object_prop                             (PIE_error_base + 22)

/**  The Object is Not Modifiable. */
#define PIE_object_not_modifiable                       (PIE_error_base + 23)

/** The BOM Item has no Parent Line. */
#define PIE_bom_item_no_parent_line                     (PIE_error_base + 24)

/** The TC Object on External Reference does not Exist. */
#define PIE_imp_tc_object_not_present                   (PIE_error_base + 25)

/** No URI resource identifier found during Delta Processing. */
#define PIE_delta_process_no_uri                        (PIE_error_base + 26)

/** There is No External Reference during PLMXML delta processing */
#define PIE_bad_plmxml_ext_ref                          (PIE_error_base + 27)

/** The Delta object has attributes having both Values and Value References. */
#define PIE_delta_field_value_and_refs                  (PIE_error_base + 28)

/** The Delta Operation Add and Replace have bad Values or ValueReferences. */
#define PIE_delta_opadd_oprepl_bad_values               (PIE_error_base + 29)

/** The Delta Operation of Modify for User Data, has a bad attribute name. */
#define PIE_delta_opmod_udata_bad_attname               (PIE_error_base + 30)

/** No Target Object Found. */
#define PIE_no_target_object                            (PIE_error_base + 31)

/** Delta Process bad new or old object tags. */
#define PIE_delta_new_old_bad_tags                      (PIE_error_base + 32)

/** Delta Process bad Object Tag. */
#define PIE_delta_bad_object_tags                       (PIE_error_base + 33)

/** Delta Process had no PLMXML Child Element. */
#define PIE_no_child_ele                                (PIE_error_base + 34)

/** Delta Process contains bad New Object tag. */
#define PIE_no_new_object_tag                           (PIE_error_base + 35)

/** Delta Process error during addition of an object. */
#define PIE_delta_error_during_add                      (PIE_error_base + 36)

/** Delta Process error during Replacement of an object. */
#define PIE_delta_error_during_replace                  (PIE_error_base + 37)

/** Delta Process error during Remove of an object. */
#define PIE_delta_error_during_remove                   (PIE_error_base + 38)

/** Missing BOM Window. */
#define PIE_no_bom_window                               (PIE_error_base + 40)

/** Missing BOM Line. */
#define PIE_no_bom_line                                 (PIE_error_base + 41)

/**  Missing Occurrence BOM View. */
#define PIE_no_occ_bv                                   (PIE_error_base + 42)

/** No Occurrences Found. */
#define PIE_no_occurr                                   (PIE_error_base + 43)

/** Invalid POM Tag. */
#define PIE_invalid_pom_tag                             (PIE_error_base + 44)

/** Invalid mapping to Plmxml Schema. */
#define PIE_bad_plmxml_schema_map                       (PIE_error_base + 45)

/** Bad PS Occurrence Values. */
#define PIE_bad_ps_occurr                               (PIE_error_base + 47)

/** Product Structure Property Write Error. */
#define PIE_prod_struct_write_error                     (PIE_error_base + 49)

/** Could Not Find the Tc Object being Searched For. */
#define PIE_bad_find_tc_obj                             (PIE_error_base + 50)

/** Could Not Export the Item Revision. */
#define PIE_bad_export_item_rev                         (PIE_error_base + 51)

/** Could Not Create an Application UID. */
#define PIE_bad_create_app_uid                          (PIE_error_base + 52)

/** Object Not Added to Root Document. */
#define PIE_cannot_add_to_root                          (PIE_error_base + 53)

/** One of the attributes in the xml refers invalid element. */
#define PIE_invalid_xmlattr_reference                   (PIE_error_base + 54)

/** Invalid xml element. */
#define PIE_invalid_xml_element                         (PIE_error_base + 55)

/** GRM Relation Type is NULL. */
#define PIE_no_grm_relation_type                        (PIE_error_base + 56)

/** Failed to find object uid %1$ in the local database. */
#define PIE_proxy_no_obj_uid_in_db                      (PIE_error_base + 79)

/** Invalid primary type specified. */
#define PIE_no_grm_primary_type                         (PIE_error_base + 87)

/** Invalid secondary type specified. */
#define PIE_no_grm_secondary_type                       (PIE_error_base + 88)

/** Invalid hide type specified. */
#define PIE_invalid_hide_type                           (PIE_error_base + 89)

/** Invalid property type specified. */
#define PIE_invalid_property_type                       (PIE_error_base + 90)

/** Invalid deep copy type specified. */
#define PIE_invalid_deepcopy_type                       (PIE_error_base + 91)

/** Invalid action rule type specified. */
#define PIE_invalid_actionrule_type                     (PIE_error_base + 93)

/** Invalid compound property display type specified. */
#define PIE_invalid_cp_display_type                     (PIE_error_base + 94)

/** Invalid compound property source type specified. */
#define PIE_invalid_cp_source_type                      (PIE_error_base + 95)

/** Invalid attach type specified. */
#define PIE_invalid_attach_type                         (PIE_error_base + 96)

/** Document could not be saved. */
#define PIE_document_save_error                         (PIE_error_base + 98)

/** Failed to establish connection to Remote Server. */
#define PIE_failed_to_connect                           (PIE_error_base + 99)

/** Socket error "%1$" while communicating with Remote Server. */
#define PIE_socket_error                                (PIE_error_base + 100)

/** PIE_string_length_exceed. */
#define PIE_string_length_exceed                        (PIE_error_base + 101)

/** The value "%1$" is not valid for property "%2$". */
#define PIE_INVALID_VALUE                               (PIE_error_base + 102)

/** tc_transform failed - "%1$". */
#define PIE_JT_TRANFORM_failed                          (PIE_error_base + 103)

/** There is an error in tc_transform application. Could not proceed. */
#define PIE_tc_tranform_appl_failed                     (PIE_error_base + 104)

/** Transfer Option Set with given criteria already exists. */
#define PIE_duplicate_transferoptionset                 (PIE_error_base + 105)

/** Transfer Option Set could not be created. */
#define PIE_transferoptionset_not_created               (PIE_error_base + 106)

/** Transfer Option Set could not be modified. */
#define PIE_transferoptionset_not_modified              (PIE_error_base + 107)

/** Transfer Option Set could not be found. */
#define PIE_transferoptionset_not_found                 (PIE_error_base + 108)

/** Transfer Option Sets could not be retrieved. */
#define PIE_transferoptionset_not_retrieved             (PIE_error_base + 109)

/** TransferMode could not be modified. */
#define PIE_transfermode_not_modified                   (PIE_error_base + 110)

/** ClosureRule could not be modified. */
#define PIE_closurerule_not_modified                    (PIE_error_base + 111)

/** ClosureRule could not be found. */
#define PIE_closurerule_not_found                       (PIE_error_base + 112)

/** ActionRule could not be modified. */
#define PIE_actionrule_not_modified                     (PIE_error_base + 113)

/** ActionRule could not be found. */
#define PIE_actionrule_not_found                        (PIE_error_base + 114)

/** FilterRule could not be modified. */
#define PIE_filterrule_not_modified                     (PIE_error_base + 115)

/** FilterRule could not be found. */
#define PIE_filterrule_not_found                        (PIE_error_base + 116)

/** PropertySet could not be modified. */
#define PIE_propertyset_not_modified                    (PIE_error_base + 117)

/** PropertySet could not be found. */
#define PIE_propertyset_not_found                       (PIE_error_base + 118)

/** Invalid schema parameter. */
#define PIE_invalid_schema_parameter                    (PIE_error_base + 119)

/** Invalid scope parameter. */
#define PIE_invalid_scope_parameter                     (PIE_error_base + 120)

/** Failed to find Transfermode. */
#define PIE_transfermode_not_found                      (PIE_error_base + 121)

/** Failed to retrieve PropertySet. */
#define PIE_propertyset_not_retrieved                   (PIE_error_base + 122)

/** Failed to retrieve FilterRule. */
#define PIE_filterrule_not_retrieved                    (PIE_error_base + 123)

/** Failed to retrieve ActionRule. */
#define PIE_actionrule_not_retrieved                    (PIE_error_base + 124)

/** Failed to retrieve ClosureRule. */
#define PIE_closurerule_not_retrieved                   (PIE_error_base + 125)

/** Failed to understand action location. */
#define PIE_invalid_action_parameter                    (PIE_error_base + 126)

/** Cannot Process more than One Site for Push case. */
#define PIE_transferoptionset_invalid_site              (PIE_error_base + 127)

/** Preference points to more than one transfermodes. */
#define PIE_invalid_preference_value                    (PIE_error_base + 128)

/** The specified transfer mode is not an export TC XML transfer mode. */
#define PIE_invalid_export_tm_value                     (PIE_error_base + 129)

/** The specified transfer mode is not an import TCXML transfer mode. */
#define PIE_invalid_import_tm_value                     (PIE_error_base + 130)

/** Invalid xml file name. */
#define PIE_invalid_xml_file                            (PIE_error_base + 131)

/** Invalid file name. */
#define PIE_invalid_xml_filename                        (PIE_error_base + 132)

/** XML file parsing error. */
#define PIE_xml_parse_error                             (PIE_error_base + 133)

/** plmxml_export utility can not be used to export any scope rules. */
#define PIE_scope_rules_export_error                    (PIE_error_base + 134)

/** Failed to attach the child to the parent. */
#define PIE_fail_to_attach_to_parent                    (PIE_error_base + 135)

/** The site master locale in the xml does not match the site master locale of the import site. */
#define PIE_import_sml_mismatch                         (PIE_error_base + 138)

/** The Incremental Change Context set in the import session is invalid. */
#define PIE_import_invalid_ic                           (PIE_error_base + 140)

/** The property "%1$" of object "%2$" does not have a master value. */
#define PIE_property_no_master_value                    (PIE_error_base + 141)

/** Property "%1$" on object "%2$" is not localizable. */
#define PIE_property_not_localizable                    (PIE_error_base + 142)

/** Property "%1$" on object "%2$" does not have translation in "%3$". */
#define PIE_property_no_locale_translation              (PIE_error_base + 143)

/** A localizable attribute "%1$" of object "%2$", class "%3$", has multiple values. PLMXML SchemaMap does not support this scenario. */
#define PIE_schemamap_multivalue_loc                    (PIE_error_base + 145)

/** The attribute "%1$" of class "%2$" does not support multi-language in PLMXML Schema. */
#define PIE_schema_no_localizable_attr                  (PIE_error_base + 146)

/** No XML file was generated in the export session. */
#define PIE_export_no_xml_generated                     (PIE_error_base + 147)

/** No master locale was found when importing values for property "%1$" of object "%2$". */
#define PIE_import_no_master_locale                     (PIE_error_base + 148)

/** No export locale was set. */
#define PIE_export_no_locale_set                        (PIE_error_base + 149)

/** An error has occurred during the processing of some objects. */
#define PIE_error_in_the_session                        (PIE_error_base + 154)

/** No master locale was found for property "%1$" of object "%2$". */
#define PIE_no_property_master_locale                   (PIE_error_base + 155)

/** Export/Import with JT_PIE_CONTEXT_STRING is not supported. */
#define PIE_jt_not_supported                            (PIE_error_base + 157)

/** The parent object of the importing associate form does not exist or is a Product View. */
#define PIE_associate_form_error                        (PIE_error_base + 158)

/** The attachment window could not be created when importing. */
#define PIE_create_attachment_window_error              (PIE_error_base + 159)

/** An error has occurred when importing the object element with id "%1$". */
#define PIE_fail_to_import_object                       (PIE_error_base + 160)

/** The Attribute Context cannot be added to the Occurrence object because the attribute name is empty. */
#define PIE_fail_to_add_context                         (PIE_error_base + 161)

/** The type of the imported XML object is not supported. */
#define PIE_plm_object_not_expected                     (PIE_error_base + 162)

/** The form "%1$" does not exist. */
#define PIE_form_not_found                              (PIE_error_base + 163)

/** The object has no parent PLMXML object. */
#define PIE_no_parent_plmxml_object                     (PIE_error_base + 164)

/** A traversal process function pointer error has occurred. */
#define PIE_no_traversal_function                       (PIE_error_base + 165)

/** A traversal parse condition error has occurred. */
#define PIE_traversal_parse_condition_error             (PIE_error_base + 166)

/** The PIE process function cannot be found. */
#define PIE_no_process_function                         (PIE_error_base + 167)

/** The data manager name of the object is not as expected. */
#define PIE_dm_name_not_IM                              (PIE_error_base + 168)

/** The file "%1$" could not be opened. */
#define PIE_file_not_existed                            (PIE_error_base + 169)

/** A parsing error has occurred in the xml file "%1$". Please check the Teamcenter server syslog file for more information or contact your system administrator.*/
#define PIE_xml_file_parse_failed                       (PIE_error_base + 170)

/** The attribute "%1$" is not supported in "%2$". */
#define PIE_xml_file_element_not_existed                (PIE_error_base + 171)

/** An error "%1$" has occurred while dynamically loading the function "%2$" from the library "%3$". */
#define PIE_xml_based_function_load_failed              (PIE_error_base + 172)

/** The current importing element has no PLMXML child elements. */
#define PIE_no_child_element                            (PIE_error_base + 173)

/** Some file names exceed the length limit ("%1$" characters). Please check the Teamcenter syslog file for more detailed information. */
#define PIE_filename_too_long                           (PIE_error_base + 174)

/** The object cannot be exported because it belongs to a revisable class. */
#define PIE_revisable_object_not_exported               (PIE_error_base + 175)

/** The role, group or user referenced by the Group Member "%1$" does not exist in the import file or has failed to be processed. */
#define PIE_ref_undefined_for_groupmember               (PIE_error_base + 176)

/** The source object of the attachment line is "%1$", which is not a persistent object. */
#define PIE_line_soure_is_not_pom                       (PIE_error_base + 177)

/** Multiple objects cannot be selected for performing Incremental Change based export. */
#define PIE_IC_delta_multiple_selection_not_allowed     (PIE_error_base + 178)

/** An intermediate line cannot be selected for performing Incremental Change based export. */
#define PIE_IC_delta_selection_is_not_topline           (PIE_error_base + 179)

/** An unexpected error has occurred while identifying the Incremental Change based delta candidates. Please refer to the Teamcenter server syslog file for more details. */
#define PIE_IC_delta_identification_error               (PIE_error_base + 180)

/** The export to a PLM XML file has failed, because the object of type "%1$" is not supported by the PLM XML Schema. Please contact your system administrator in order to add PIE (PLM XML Import Export) support to the data model. */
#define PIE_object_type_not_support                     (PIE_error_base + 181)

/** The property "%1$" on the object of type "%2$" and UID "%3$" was not processed due to some internal error. Please remove the property from the Property Set, and try again. */
#define PIE_property_process_internal_error             (PIE_error_base + 182)
/** The reference object "%1$" cannot be found.*/
#define PIE_reference_not_found                         (PIE_error_base + 183)

/** The specified Transfer Mode "%1$" is not for PLM XML export purpose. Please select a proper Transfer Mode and try again. */
#define PIE_tranfermode_not_for_plmxml_export           (PIE_error_base + 184)

/** The specified Transfer Mode "%1$" is not for PLM XML import purpose. Please select a proper Transfer Mode and try again. */
#define PIE_tranfermode_not_for_plmxml_import           (PIE_error_base + 185)

/** The specified file name "%1$" contains the invalid character "%2$". Please specify a valid file name (including the extension .xml or .plmxml) and try again. */
#define PIE_invalid_file_name                           (PIE_error_base + 186)

/** The PLMXML SDK validation of the file "%1$" has failed with the following error message: %2$. Please correct the file and try again. */
#define PIE_schema_validation_failed                    (PIE_error_base + 187)

/**   The value "%1$" in the "session_options" parameter is invalid. */
#define PIE_invalid_input_session_option                (PIE_error_base + 188)

#define PIE_error_ceiling                               (PIE_error_base + 199)

/** @} */

#include <pie/libpie_undef.h>
#endif
