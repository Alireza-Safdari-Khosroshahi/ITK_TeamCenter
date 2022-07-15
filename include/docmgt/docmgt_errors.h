/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2020.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/** 
    @file
    Error codes for Document Management
*/

#ifndef DOCMGT_ERRORS_H
#define DOCMGT_ERRORS_H

/**
    @defgroup DOCMGT_ERRORS Errors
    @ingroup DOCMGT
    @{
*/
#define DOCMGT_ERROR_BASE                               EMH_DOCMGT_error_base

/** 
    The DOCMGT module is not initialized properly. See system log for details. 
*/
#define DOCMGT_not_initialized                          (DOCMGT_ERROR_BASE + 1)

/**
    One or more parameters passed to the function '%1$' is invalid. See system log for details.
*/
#define DOCMGT_invalid_parameters                       (DOCMGT_ERROR_BASE + 2)

/**
    The user name is invalid.
*/
#define DOCMGT_invalid_user                             (DOCMGT_ERROR_BASE + 3)

/**
    Document Management test failed. See system log for details.
*/
#define DOCMGT_test_failed                              (DOCMGT_ERROR_BASE + 4)

/**
    Internal error in Document Management module: '%1$'. See system log for details.
*/
#define DOCMGT_internal_error                           (DOCMGT_ERROR_BASE + 5)

/**
    Document Management could not load ETS.
*/
#define DOCMGT_cant_load_ets                            (DOCMGT_ERROR_BASE + 6)

/**
    Document Management could not find ETS function '%1$'.
*/
#define DOCMGT_cant_find_ets_fn                         (DOCMGT_ERROR_BASE + 7)

/**
    The property '%1$' on workflow process could not be set.
*/
#define DOCMGT_workflow_properties_not_set              (DOCMGT_ERROR_BASE + 8)

/**
    You do not have the correct access privileges to delete one or more objects.
*/
#define DOCMGT_no_privilege_to_delete_object            (DOCMGT_ERROR_BASE + 9)

/**
    You do not have the correct access privileges to create one or more objects.
*/
#define DOCMGT_no_privilege_to_create_object            (DOCMGT_ERROR_BASE + 10)

/**
    You do not have the correct access privileges to modify one or more objects.
*/
#define DOCMGT_no_privilege_to_modify_object            (DOCMGT_ERROR_BASE + 11)

/* validation error numbers */

/**
    No source Dataset is found based on the attached Relation and the Dataset type defined in the Item Revision Definition Configuration for the Item Revision '%1$'
*/
#define DOCMGT_no_irdc_dataset_attached_to_itemrevision (DOCMGT_ERROR_BASE + 12)

/**
    No Item Revision Definition Configuration is configured for the Item Revision '%1$'.
*/
#define DOCMGT_no_irdc_configured_for_itemrevision      (DOCMGT_ERROR_BASE + 13)

/**
    No source Dataset type is defined in the Item Revision Definition Configuration for the Item Revision '%1$'.
*/
#define DOCMGT_no_irdc_source_dataset_type_defined      (DOCMGT_ERROR_BASE + 14)

/**
    No derived Dataset type is defined in the Item Revision Definition Configuration for the Item Revision '%1$'.
*/
#define DOCMGT_no_irdc_derived_dataset_type_defined     (DOCMGT_ERROR_BASE + 15)

/**
    No Dispatcher Service Configuration is defined.
*/
#define DOCMGT_no_dispatcher_service_config_defined     (DOCMGT_ERROR_BASE + 16)

/**
    No source Dataset type is matching between attached Dataset and Item Revision Definition Configuration for the Item Revision '%1$'.
*/
#define DOCMGT_no_irdc_and_dataset_source_matched       (DOCMGT_ERROR_BASE + 17)

/**
    No source Dataset type is matching between Item Revision Definition Configuration and Dispatcher Service Configuration for the Item Revision '%1$'.
*/
#define DOCMGT_no_irdc_and_dsp_svc_cfg_source_matched   (DOCMGT_ERROR_BASE + 18)

/**
    No derived Dataset type is matching between Item Revision Definition Configuration and Dispatcher Service Configuration for the Item Revision '%1$'.
*/
#define DOCMGT_no_irdc_and_dsp_svc_cfg_derived_matched  (DOCMGT_ERROR_BASE + 19)

/**
    No matching Dataset type is found for rendering for the Item Revision '%1$'.
*/
#define DOCMGT_no_matched_dataset_type_for_rendering    (DOCMGT_ERROR_BASE + 20)

/**
   The Item Revision '%1$' cannot be rendered because it is Checked-Out.
*/
#define DOCMGT_no_render_itemrevision_is_checkedout     (DOCMGT_ERROR_BASE + 21)

/**
    The Item Revision '%1$' cannot be rendered because its attached Dataset is Checked-Out.
*/
#define DOCMGT_no_render_attached_dataset_is_checkedout (DOCMGT_ERROR_BASE + 22)

/**
    No Dispatcher Client is installed for rendering for the Item Revision '%1$'.
*/
#define DOCMGT_no_dispatcher_client_installed           (DOCMGT_ERROR_BASE + 23)

/**
    The required derived Dataset cannot be generated for the Item Revision '%1$'.
*/
#define DOCMGT_required_derived_dataset_validation_fail (DOCMGT_ERROR_BASE + 24)

/**
    The validation of the "Render" operation failed.
*/
#define DOCMGT_render_validation_fail                   (DOCMGT_ERROR_BASE + 25)

/**
    The Dataset '%1$' does not have a referenced file for the rendering for the Item Revision '%2$'.
*/
#define DOCMGT_no_referenced_file_in_dataset_for_render (DOCMGT_ERROR_BASE + 26)

/**
    No source Dataset type (%1$) can be found for the rendering of Item Revision '%2$'.
*/
#define DOCMGT_no_required_src_dataset_found            (DOCMGT_ERROR_BASE + 27)

/**
    No Render Management Provider or Service Name Constants are setup for the Item Revision.
*/
#define DOCMGT_no_provider_service_constant_found       (DOCMGT_ERROR_BASE + 28)

/**
    The Item "%1$" cannot be rendered because it is neither an Item Revision nor a child of an Item Revision or System Stamp/Logo configuration error. Please check the Teamcenter syslog file and contact your system administrator.
*/
#define DOCMGT_not_a_revision_object_for_render         (DOCMGT_ERROR_BASE + 29)

/**
    No Dispatcher Service Configuration is defined or available for rendering from '%1$' to '%2$' for the Item Revision '%3$'.
*/
#define DOCMGT_no_dispatcher_service_config_def_avail   (DOCMGT_ERROR_BASE + 30)

/**
    No input Item Revision was provided.
*/
#define DOCMGT_no_input_item_revision                   (DOCMGT_ERROR_BASE + 31)

/**
    No input Item Revision Definition Configuration was provided.
*/
#define DOCMGT_no_input_irdc                            (DOCMGT_ERROR_BASE + 32)

/**
    The Dispatcher Request for Item Revision '%1$' could not be created.
*/
#define DOCMGT_no_dispatcher_request                    (DOCMGT_ERROR_BASE + 33)

/* IRDC markup validation error numbers */

/**
    The Based Dataset type '%1$' defined in the Item Revision Definition Configuration for the Item Revision '%2$' does not match the current Based Dataset type '%3$'.
*/
#define DOCMGT_irdc_wrong_markup_dataset_type           (DOCMGT_ERROR_BASE + 34)

/**
    The Markup Tool type '%1$' defined in the Item Revision Definition Configuration for the Item Revision '%2$' does not match the current Markup Tool type '%3$'.
*/
#define DOCMGT_irdc_wrong_markup_tool_type              (DOCMGT_ERROR_BASE + 35)

/**
    The 'Markup in Change Context' property is set to true in Item Revision Definition Configuration for the Item Revision '%1$', but no Change object or Control object is found.
*/
#define DOCMGT_irdc_no_control_object                   (DOCMGT_ERROR_BASE + 36)

/**
    You do not have the 'MARKUP' access privilege on the Item '%1$' to create or update its Markup.
*/
#define DOCMGT_no_markup_priv_create_update_item        (DOCMGT_ERROR_BASE + 37)

/**
    You do not have the 'MARKUP' access privilege on the Item Revision '%1$' to create or update its Markup
*/
#define DOCMGT_no_markup_priv_create_update_itemrev     (DOCMGT_ERROR_BASE + 38)

/**
    You do not have the 'MARKUP' access privilege on the Based Dataset '%1$' to create or update its Markup.
*/
#define DOCMGT_no_markup_priv_create_update_dataset     (DOCMGT_ERROR_BASE + 39)

/**
    The Markup cannot be created or updated because the base Dataset is checked-out by somebody else or is out-of-date.  Refresh the base Dataset to obtain its latest version.
*/
#define DOCMGT_not_checkedout_based_dataset_owner       (DOCMGT_ERROR_BASE + 40)

/* Batch Print validation */

/**
    Access privilege 'BATCH_PRINT' on object '%1$' is requested to print.
*/
#define DOCMGT_batchprint_no_privilege                  (DOCMGT_ERROR_BASE + 41)

/**
    The Item "%1$" cannot be printed because it is neither an Item Revision nor a child of an Item Revision or System Stamp/Logo configuration error. Please check the Teamcenter syslog file and contact your system administrator.
*/
#define DOCMGT_not_a_revision_object_for_print          (DOCMGT_ERROR_BASE + 42)

/**
    The validation of the "Print" operation failed.
*/
#define DOCMGT_print_validation_fail                    (DOCMGT_ERROR_BASE + 43)

/**
    The rendering of the document is not required.
*/
#define DOCMGT_irdc_not_required_render                 (DOCMGT_ERROR_BASE + 44)

/** @name Update Document Property (UDP) errors 
@{ 
*/

/**
    The local file extension "%1$" does not match the valid source file extension "%2$".
*/
#define DOCMGT_local_file_extension_not_matched         (DOCMGT_ERROR_BASE + 45)

/**
    The "Update Document Property" operation has failed. Please refer to the Teamcenter syslog file for more details.
*/
#define DOCMGT_update_doc_prop_validation_fail          (DOCMGT_ERROR_BASE + 46)

/**
    The object "%1$" cannot be processed for the "Update Document Property" operation, because it is neither an Item, an Item Revision, a Dataset, nor any of their subtypes.
*/
#define DOCMGT_object_not_for_upd_validation_fail       (DOCMGT_ERROR_BASE + 47)

/**
    The object "%1$" cannot be processed for the "Update Document Property" operation, because no attribute exchange is setup, no attribute is to be updated, or the attribute is not supported for the selected object.
*/
#define DOCMGT_no_attr_exch_upd_validation_fail         (DOCMGT_ERROR_BASE + 48)

/**
    The XML file cannot be generated for the "Update Document Property" operation, because an unknown error has occurred. Please check the Teamcenter syslog file and contact your system administrator.
*/
#define DOCMGT_upd_xmlplatformutils_initialize_fail     (DOCMGT_ERROR_BASE + 49)
/** @} */ 

/** @name PDF Control (PDFControl) errors 
@{ 
*/

/**
    The object "%1$" cannot be processed for the "PDF Control" operation, because it is neither an Item, nor an Item Revision.
*/
#define DOCMGT_not_a_revision_object_for_pdfctrl        (DOCMGT_ERROR_BASE + 50)

/**
    The object "%1$" cannot be processed for the "PDF Control" operation, because it is neither an Item, an Item Revision, a Dataset, nor any of their subtypes.
*/
#define DOCMGT_object_not_for_pdfctrl_validation_fail   (DOCMGT_ERROR_BASE + 51)

/**
    The object "%1$" cannot be processed for the "PDF Control" operation, because system stamping is not enabled. Please check System Stamp Configuration Condition.
*/
#define DOCMGT_system_stamp_not_enabled                 (DOCMGT_ERROR_BASE + 52)

/**
    The object "%1$" cannot be processed for the "PDF Control" operation, because the "applies to" field of the System Stamp Configuration "%2$" is not set for this operation.
*/
#define DOCMGT_system_stamp_applies_to_not_pdf_control  (DOCMGT_ERROR_BASE + 53)

/** @} */ 


/** @name Server Update Document Property (SUDP) errors 
@{ 
*/

/**
    The current directory cannot be retrieved due to an unknown error. Please check the Teamcenter syslog file and contact your system administrator.
*/
#define DOCMGT_cannot_get_current_dir                  (DOCMGT_ERROR_BASE + 54)

/**
    The compressing has failed because either the directory "%1$" or the file "%2$" is invalid. Please check the Teamcenter syslog file and contact your system administrator.
*/
#define DOCMGT_cannot_zip_dir_file                     (DOCMGT_ERROR_BASE + 55)

/**
    The uncompressing has failed because either the directory "%1$" or the file "%2$" is invalid. Please check the Teamcenter syslog file and contact your system administrator.
*/
#define DOCMGT_cannot_unzip_dir_file                   (DOCMGT_ERROR_BASE + 56)

/**    
    The directory "%1$" cannot be created due to an unknown error. Please check the Teamcenter syslog file and contact your system administrator.
*/
#define DOCMGT_cannot_create_working_dir               (DOCMGT_ERROR_BASE + 57)

/**
    The file "%1$" could not be found due to an unknown error. Please check the Teamcenter syslog file and contact your system administrator.
*/
#define DOCMGT_output_file_not_found                   (DOCMGT_ERROR_BASE + 58)

/**
    The file "%1$" is empty due to an unknown error. Please check the Teamcenter syslog file and contact your system administrator.
*/
#define DOCMGT_file_size_is_zero                       (DOCMGT_ERROR_BASE + 59)

/**
    The directory path is empty due to an unknown error. Please check the Teamcenter syslog file and contact your system administrator.
*/
#define DOCMGT_working_dir_is_empty                    (DOCMGT_ERROR_BASE + 60)

/**
    The Dataset "%1$" does not contain any named reference file to be exported. Please update the Dataset with a valid named reference file.
*/
#define DOCMGT_missing_named_ref_file                  (DOCMGT_ERROR_BASE + 61)

/**
    The exported named reference file "%2$" of the Dataset "%1$" could not be found due to an unknown error. Please check the Teamcenter syslog file and contact your system administrator.
*/
#define DOCMGT_exported_named_ref_file_not_found       (DOCMGT_ERROR_BASE + 62)

/**
    The file "%1$" cannot be processed because it is either invalid or contains invalid XML data: %2$. Please check the Teamcenter syslog file and contact your system administrator.
*/
#define DOCMGT_xml_xercesc_toolkit_exception           (DOCMGT_ERROR_BASE + 63)

/**
   The Dataset "%1$" cannot be processed for the Logical Object attribute exchange because it is checked-out.
*/
#define DOCMGT_dataset_is_checkedout_lo_ae             (DOCMGT_ERROR_BASE + 64)

/**
   The Dataset "%1$" cannot be processed for the Logical Object attribute exchange because the named reference file is either invalid, empty or password-protected.
*/
#define DOCMGT_dataset_file_invalid_empty_pwdprotected  (DOCMGT_ERROR_BASE + 65)

/**
   The property key "%3$" for the configuration "%2$" of the Document Management Template "%1$" must be a string. Please check the Teamcenter syslog file and contact your system administrator.
*/
#define DOCMGT_property_must_be_a_string_type           (DOCMGT_ERROR_BASE + 66)

/**
   The property key "%3$" was not found for the configuration "%2$" of the Document Management Template "%1$". Please check the Teamcenter syslog file and contact your system administrator.
*/
#define DOCMGT_property_not_found                       (DOCMGT_ERROR_BASE + 67)

/**
   "%1$" could not be updated because the selected process cannot be used for a Logical Object Attribute Exchange. Please use a Logical Object Attribute Exchange process instead.
*/
#define DOCMGT_selected_process_invalid_for_LOAE_validation_fail (DOCMGT_ERROR_BASE + 68)

/**
   The extension type of the image file "%1$" is not supported. Please use image file that has one of the supported image file extension types "%2$" instead.
*/
#define DOCMGT_image_ext_type_not_supported             (DOCMGT_ERROR_BASE + 69)

/**
   The image file "%1$" does not have an extension type. Please use image file that has one of the supported image file extension types "%2$" instead.
*/
#define DOCMGT_image_does_not_have_extension            (DOCMGT_ERROR_BASE + 70)

/**
   The file "%1$" could not be processed due to an unknown error. Please check the Teamcenter syslog file and contact your system administrator.
*/
#define DOCMGT_file_process_unknown_error               (DOCMGT_ERROR_BASE + 71)

/**
    No input Dataset was provided.
*/
#define DOCMGT_no_input_dataset                         (DOCMGT_ERROR_BASE + 72)

/**
    No output Dataset type was provided.
*/
#define DOCMGT_no_output_dataset_type                   (DOCMGT_ERROR_BASE + 73)

/**
    The relation name for the source Dataset named reference cannot be empty.
*/
#define DOCMGT_src_ds_namedref_relname_cannot_be_empty   (DOCMGT_ERROR_BASE + 74)

/**
    The file name for the source Dataset named reference cannot be empty.
*/
#define DOCMGT_src_ds_namedref_filename_cannot_be_empty  (DOCMGT_ERROR_BASE + 75)

/**
    The derived Dataset "%1$" cannot be updated for released %2$ "%3$".
*/
#define DOCMGT_derived_ds_cannot_be_updated_for_released_object  (DOCMGT_ERROR_BASE + 76)

/**
    Derived Dataset objects "%1$" cannot be updated for released %2$ objects "%3$".
*/
#define DOCMGT_derived_ds_cannot_be_updated_for_released_objects  (DOCMGT_ERROR_BASE + 77)

/**
    The object "%1$" cannot be processed for the "update teamcenter property" operation, because no attribute exchange is setup, no attribute is to be updated, or the attribute is not supported for the selected object.
*/
#define DOCMGT_no_attr_exch_tc_upd_validation_fail                (DOCMGT_ERROR_BASE + 78)

/**
    The specified "%1$" preference relation name "%2$" not valid.
*/
#define DOCMGT_generate_pdf_itemrev_to_pdf_relation_not_valid     (DOCMGT_ERROR_BASE + 79)

/**
    Cannot update writable property to false because the presented property "%1$" has associated attribute exchange configuration with the direction "File to Teamcenter". System administrator should update the attribute exchange configuration's direction to "Teamcenter to File" first.
    */
#define DOCMGT_presented_prop_attr_exch_cannot_set_writable_false (DOCMGT_ERROR_BASE + 80)

/**
    Cannot update attribute exchange direction to "File to Teamcenter" because the related presented property "%1$" is not writable. System administrator should update the presented property to writable first.
*/
#define DOCMGT_attr_exch_direction_cannot_set_file_to_teamcenter (DOCMGT_ERROR_BASE + 81)

/**
    The Presented Property or related Attribute Exchange Configuration update has failed because only an adminstrator can do the update.
*/
#define DOCMGT_user_not_dba_no_update_attr_exch_config           (DOCMGT_ERROR_BASE + 82)

/** @} */


/** @} */
#endif

