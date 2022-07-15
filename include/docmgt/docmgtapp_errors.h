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

    This file defines errors constants for the DOCMGTAPP module.
*/

#ifndef DOCMGTAPP_ERRORS_H
#define DOCMGTAPP_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup DOCMGTAPP_ERRORS Errors
    @ingroup DOCMGTAPP
    @{
*/
#define DOCMGTAPP_ERROR_BASE                                  EMH_DOCMGTAPP_error_base

/** 
    No Gather Markup input object ID is given. 
*/
#define DOCMGTAPP_gather_no_input_id                          ( DOCMGTAPP_ERROR_BASE + 1 )

/** 
    The ID of the selected object is invalid for the Gather Markup. 
*/
#define DOCMGTAPP_gather_invalid_object                       ( DOCMGTAPP_ERROR_BASE + 2 )

/** 
    The ID of the selected object is a markup control object, and it does not match the provided related control object.
*/
#define DOCMGTAPP_gather_control_obj_not_matched              ( DOCMGTAPP_ERROR_BASE + 3 )

/** 
    No related Item object can be found for the input control object ID. 
*/
#define DOCMGTAPP_gather_no_control_related_items             ( DOCMGTAPP_ERROR_BASE + 4 )

/** 
    No View/Markup permission for the object. 
*/
#define DOCMGTAPP_gather_no_permission_for_view_markup        ( DOCMGTAPP_ERROR_BASE + 5 )

/** 
    The ID of the selected object refers to an Item, and it does not match the provided related Item. 
*/
#define DOCMGTAPP_gather_item_not_matched                     ( DOCMGTAPP_ERROR_BASE + 6 )

/** 
    The ID of the selected object refers to an Item Revision, and it does not match the provided related Item Revision. 
*/
#define DOCMGTAPP_gather_item_rev_not_matched                 ( DOCMGTAPP_ERROR_BASE + 7 )

/** 
    No parent tag is found. 
*/
#define DOCMGTAPP_gather_no_parent_tag_is_found               ( DOCMGTAPP_ERROR_BASE + 8 )

/** 
    The message ID for operation '%1$' cannot be found. 
*/
#define DOCMGTAPP_fail_to_find_operation_msg_id               ( DOCMGTAPP_ERROR_BASE + 9 )

/** 
    The XMLDocument for launch definition, could not be created. 
*/
#define DOCMGTAPP_fail_to_create_launch_def_DOMDocument       ( DOCMGTAPP_ERROR_BASE + 10 )

/** 
   No file name was found for the Dataset. 
*/
#define DOCMGTAPP_file_name_found                             ( DOCMGTAPP_ERROR_BASE + 11 )

/** 
   No tool was found. The launch definition cannot be built without a tool. 
*/
#define DOCMGTAPP_no_tool_found                               ( DOCMGTAPP_ERROR_BASE + 12 )

/** 
   No Dataset was found for the View/Markup of Item Revision. 
*/
#define DOCMGTAPP_no_dataset_found_for_view_markup            ( DOCMGTAPP_ERROR_BASE + 13 )

/** 
   No Dataset was found. The launch definition cannot be built without a Dataset. 
*/
#define DOCMGTAPP_no_data_found_for_view_markup               ( DOCMGTAPP_ERROR_BASE + 14 )

/** 
   The Tool type is not configured as a View/Markup capable Tool type. 
*/
#define DOCMGTAPP_not_view_markup_capable_tool                ( DOCMGTAPP_ERROR_BASE + 15 )

/** 
   No Tool type is set in the 'TCViewMarkupApplicationPref' preference. 
*/
#define DOCMGTAPP_no_tool_defined_in_the_TCViewMarkupAppPref  ( DOCMGTAPP_ERROR_BASE + 16 )

/** 
   The provided Item Revision is not valid for the Item. 
*/
#define DOCMGTAPP_invalid_item_rev_provided                   ( DOCMGTAPP_ERROR_BASE + 17 )

/** 
   The Set Properties input is empty. 
*/
#define DOCMGTAPP_invalid_set_props_input                     ( DOCMGTAPP_ERROR_BASE + 18 )

/** 
   The Mapping object's Attribute Name is empty. 
*/
#define DOCMGTAPP_empty_mapping_object_attribute_name         ( DOCMGTAPP_ERROR_BASE + 19 ) 

/** 
  The Mapping object's Relation size is not 1.
*/
#define DOCMGTAPP_invalid_mapping_object_relation_size        ( DOCMGTAPP_ERROR_BASE + 20 )

/** 
   The Relation object is not valid. 
*/
#define DOCMGTAPP_invalid_relation_object                     ( DOCMGTAPP_ERROR_BASE + 21 )

/** 
   The Mapping path is not valid. 
*/ 
#define DOCMGTAPP_invalid_mapping_path                        ( DOCMGTAPP_ERROR_BASE + 22 )

/** 
   There are more than one similar objects of the same Relation. 
*/
#define DOCMGTAPP_more_similar_related_objects                ( DOCMGTAPP_ERROR_BASE + 23 )

/** 
   No object matches the provided Relation. 
*/    
#define DOCMTAPP_no_related_objects                           ( DOCMGTAPP_ERROR_BASE + 24 )

/** 
   The entry is not a supported value type.
*/
#define DOCMGTAPP_not_supported_value_type                    ( DOCMGTAPP_ERROR_BASE + 25 )

/** 
   The Teamcenter property is either localizable or is based on a list of values (LOV) for which attribute exchange is not supported. 
*/
#define DOCMGTAPP_localizable_lov_attribute_name_notsupported ( DOCMGTAPP_ERROR_BASE + 26 )

/** 
   The setting of the Teamcenter property has failed. The provided input value might not be correct. 
*/
#define DOCMGTAPP_set_prop_val_fail                           ( DOCMGTAPP_ERROR_BASE + 27 )

/** 
   An error has occurred when checking that the property is localizable. 
*/
#define DOCMGTAPP_error_checking_islocalizable                ( DOCMGTAPP_ERROR_BASE + 28 )

/** 
   An error has occurred when checking that the property is based on a list of values (LOV). 
*/   
#define DOCMGTAPP_error_checking_islov_attached               ( DOCMGTAPP_ERROR_BASE + 29 )

/** 
   The mapping did not resolve to a valid Teamcenter object for the reference. 
*/
#define DOCMGTAPP_error_referenced_object_not_valid           ( DOCMGTAPP_ERROR_BASE + 30 )

/** 
   The value for the property is not set for the language. 
*/ 
#define DOCMGTAPP_error_localized_value_not_defined           ( DOCMGTAPP_ERROR_BASE + 31 )

/** 
   The View/Markup action cannot be completed on the dataset with version number. It can only be done on the current version of the dataset.
*/ 
#define DOCMGTAPP_error_viewmarkup_backup_version_dataset     ( DOCMGTAPP_ERROR_BASE + 32 )

/** 
    The input object is not a valid object. Please contact your system administrator.     
*/
#define DOCMGTAPP_sign_invalid_tag                               ( DOCMGTAPP_ERROR_BASE + 33 )

/** 
    The object is not a Dataset object. 
*/
#define DOCMGTAPP_sign_not_dataset                            ( DOCMGTAPP_ERROR_BASE + 34 )

/** 
    The Dataset object is not configured for signing.
*/
#define DOCMGTAPP_sign_not_signable                           ( DOCMGTAPP_ERROR_BASE + 35 )

/** 
    The object is empty. 
*/
#define DOCMGTAPP_sign_null_object                            ( DOCMGTAPP_ERROR_BASE + 36 )

/** 
    The Dataset object is already checked-out. A checked-out Dataset object cannot be signed. 
*/
#define DOCMGTAPP_sign_already_checked_out                    ( DOCMGTAPP_ERROR_BASE + 37 )

/** 
    The Dataset object does not have permission. 
*/
#define DOCMGTAPP_sign_no_sign_priv                           ( DOCMGTAPP_ERROR_BASE + 38 )

/** 
    The Dataset object does not have permission.
*/
#define DOCMGTAPP_sign_no_write_priv                          ( DOCMGTAPP_ERROR_BASE + 39 )

/** 
    The Tool type is not configured as a signable Tool type. 
*/
#define DOCMGTAPP_sign_not_sign_capable_tool                  ( DOCMGTAPP_ERROR_BASE + 40 )

/** 
    No signable Tool type found. 
*/
#define DOCMGTAPP_sign_no_sign_tool_found                     ( DOCMGTAPP_ERROR_BASE + 41 )

/** 
    No Tool type is set in the TCDigitalSignApplicationPref preference. 
*/
#define DOCMGTAPP_sign_no_sign_tool_pref_set                  ( DOCMGTAPP_ERROR_BASE + 42 )

/** 
    The Dataset object is not checked-out for signing.
*/
#define DOCMGTAPP_sign_not_co_for_sign                        ( DOCMGTAPP_ERROR_BASE + 43 )

/** 
    The digital signature is invalid. The dataset will not be checked-in. Please contact your system administrator. 
*/
#define DOCMGTAPP_sign_invalid_sig                            ( DOCMGTAPP_ERROR_BASE + 44 )

/** 
    The Dataset object is checked-out by another user. 
*/
#define DOCMGTAPP_sign_co_by_other                            ( DOCMGTAPP_ERROR_BASE + 45 )

/** 
    The Sign Relation type is not found.
*/
#define DOCMGTAPP_sign_cannot_find_rel_type                   ( DOCMGTAPP_ERROR_BASE + 46 )

/** 
    The Sign Relation between the Dataset object and the user is not found. Please contact your system administrator.
*/
#define DOCMGTAPP_sign_cannot_find_sign_rel                   ( DOCMGTAPP_ERROR_BASE + 47 )

/** 
    The Dataset object cannot be checked-in for signing. Please contact your system administrator. 
*/
#define DOCMGTAPP_sign_cannot_checkin                         ( DOCMGTAPP_ERROR_BASE + 48 )

/** 
    The input user for saving the Dataset object with a digital signature, does not match the login user. 
    Please contact your system administrator.
*/
#define DOCMGTAPP_sign_save_invalid_input_userid              ( DOCMGTAPP_ERROR_BASE + 49 )

/** 
    The Dataset object "%1$" is already signed by the current user.
*/
#define DOCMGTAPP_already_sign                                ( DOCMGTAPP_ERROR_BASE + 50 )

/** 
    The Dataset object "%1$" cannot be signed, because it has been released. 
*/
#define DOCMGTAPP_cannot_sign_released_dataset                ( DOCMGTAPP_ERROR_BASE + 51 )


/**
    The base Dataset "%1$" does not have a named reference. The View/Markup action requires the base Dataset to have a named reference.
*/
#define DOCMGTAPP_base_dataset_no_named_reference             ( DOCMGTAPP_ERROR_BASE + 52 ) 

/**
    The markup Dataset "%1$" does not have a named reference. The View/Markup action requires the markup Dataset to have a named reference.
*/
#define DOCMGTAPP_markup_dataset_no_named_reference           ( DOCMGTAPP_ERROR_BASE + 53 ) 

/**
    The base Dataset "%1$" is currently checked-out. Please try again when the Dataset is checked-in.
*/
#define DOCMGTAPP_base_dataset_checked_out                    ( DOCMGTAPP_ERROR_BASE + 54 ) 

/**
    The markup Dataset "%1$" is currently checked-out. Please try again when the Dataset is checked-in.
*/
#define DOCMGTAPP_markup_dataset_checked_out                  ( DOCMGTAPP_ERROR_BASE + 55 ) 

/**
    The Dataset "%1$" was marked up by the Rich, Thin or Office clients' View/Markup action. Please use one of these clients to perform the View/Markup action on this dataset.
*/
#define DOCMGTAPP_rich_thin_office_markup                     ( DOCMGTAPP_ERROR_BASE + 56 ) 

/**
    "%1$" has an Active Workspace markup that cannot be shown. The file should be viewed in Active Workspace to view both the Acrobat and Active Workspace markup.
*/
#define DOCMGTAPP_awc_markup                                  ( DOCMGTAPP_ERROR_BASE + 57 )

/** @name PDF Control (PDFControl) errors 
@{ 
*/

/**
    The "PDF Control" operation requires the Dataset "%1$" to contain a named reference file.
*/
#define DOCMGTAPP_missing_named_ref_file                      (DOCMGTAPP_ERROR_BASE + 58)

/**
    The "PDF Control" operation "%1$" is not supported.
*/
#define DOCMGTAPP_pdf_operation_not_supported                 (DOCMGTAPP_ERROR_BASE + 59)

/**
    The object "%1$" is not enabled for "PDF Control" operations. Check the System Stamp Configuration Condition.
*/
#define DOCMGTAPP_not_enabled_for_pdf_control                 (DOCMGTAPP_ERROR_BASE + 60)

/**
    The input object must be of type Item, Item Revision or Dataset.
*/
#define DOCMGTAPP_not_supported_type                          (DOCMGTAPP_ERROR_BASE + 61)

/**
    "PDF Control" operations are only supported for Windows platforms.
*/
#define DOCMGTAPP_windows_platform_only                       (DOCMGTAPP_ERROR_BASE + 62)

/**
    The environment variable "TC_ROOT" must be set.
*/
#define DOCMGTAPP_getenv_tc_root_error                        (DOCMGTAPP_ERROR_BASE + 63)

/**
    The current user does not have the "PDF_CONTROL" access privilege on the object "%1$" needed to perform "PDF Control" operations.
*/
#define DOCMGTAPP_pdf_control_no_privilege                    (DOCMGTAPP_ERROR_BASE + 64)

/**
    The PDF-controlled output file "%1$" could not be found.
*/
#define DOCMGTAPP_no_pdf_output_file_found                    (DOCMGTAPP_ERROR_BASE + 65)

/**
    The PDF-controlled output file "%1$" is empty.
*/
#define DOCMGTAPP_file_size_is_zero                           (DOCMGTAPP_ERROR_BASE + 66)

/**
    The "PDF Control" command "%1$" file could not be found.
*/
#define DOCMGTAPP_pdf_control_exe_not_found                   (DOCMGTAPP_ERROR_BASE + 67)

/**
    The "PDF Control" input file "%1$" could not be found
*/
#define DOCMGTAPP_pdf_control_input_file_not_found            (DOCMGTAPP_ERROR_BASE + 68)

/**
    The file name is empty.
*/
#define DOCMGTAPP_file_name_is_empty                          (DOCMGTAPP_ERROR_BASE + 69)

/**
    The input object "%1$" must be a PDF Dataset in order to perform the "PDF Control" operation.
*/
#define DOCMGTAPP_is_not_pdf_dataset                          (DOCMGTAPP_ERROR_BASE + 70)

/**
    The PDF-controlled output vector size is empty. Nothing needs to be updated in Teamcenter.
*/
#define DOCMGTAPP_no_pdf_enable_object_to_update              (DOCMGTAPP_ERROR_BASE + 71)

/**
    The "PDF Control" template file "%1$" cannot be read. The XML might be malformed.
*/
#define DOCMGTAPP_cannot_read_pdf_control_template            (DOCMGTAPP_ERROR_BASE + 72)

/**
    The "PDF Control" file "%1$" cannot be written.
*/
#define DOCMGTAPP_cannot_create_pdf_control_input             (DOCMGTAPP_ERROR_BASE + 73)

/**
    The "PDF Control" command "%1$" has failed. Please consult the following log file for more information: %2$.
*/
#define DOCMGTAPP_pdf_control_command_return_error            (DOCMGTAPP_ERROR_BASE + 74)

/**
    The PDF dataset "%1$" must be relate to an Item Revision.
*/
#define DOCMGTAPP_pdf_not_relate_to_item_revision             (DOCMGTAPP_ERROR_BASE + 75)

/**
    No PDF datasets are related to the input object "%1$".
*/
#define DOCMGTAPP_zero_pdf_related_to_input_object            (DOCMGTAPP_ERROR_BASE + 76)

/**
    The input object "%1$" must be associated to an Item Revision.
*/
#define DOCMGTAPP_input_obj_not_associated_to_item_revision   (DOCMGTAPP_ERROR_BASE + 77)

/**
    The "PDF Control" operation cannot find the following Document Page Template object: %1$.
*/
#define DOCMGTAPP_doc_page_template_not_found                 (DOCMGTAPP_ERROR_BASE + 78)

/**
    The following Document Page Template object does not have an attached PDF dataset: %1$.
*/
#define DOCMGTAPP_doc_page_template_no_pdf_dataset            (DOCMGTAPP_ERROR_BASE + 79)

/**
    The following Document Page Template object does not have a Release Status: %1$.
*/
#define DOCMGTAPP_doc_page_template_not_released              (DOCMGTAPP_ERROR_BASE + 80)

/**
    Input objects must either have an attached PDF dataset or be PDF datasets.
*/
#define DOCMGTAPP_no_pdf_dataset_inputs                       (DOCMGTAPP_ERROR_BASE + 81)

/**
    The input object "%1$" must be an Item Revision or a child of an Item Revision.
*/
#define DOCMGTAPP_is_not_an_item_revision_object              (DOCMGTAPP_ERROR_BASE + 82)

/**
    The following Dataset does not have a Release Status: %1$.
*/
#define DOCMGTAPP_dataset_not_released                        (DOCMGTAPP_ERROR_BASE + 83)

/**
    The Item Revision object "%1$" does not have a PDF cover page Dataset.
*/
#define DOCMGTAPP_no_pdf_cover_page_dataset                   (DOCMGTAPP_ERROR_BASE + 84)

/**
    None of the workflow targets contain PDF cover page Dataset.
*/
#define DOCMGTAPP_wf_targets_no_pdf_cover_page_dataset        (DOCMGTAPP_ERROR_BASE + 85)

/**
    The PDF control operation has failed because it cannot process the following Datasets: %1$.
*/
#define DOCMGTAPP_pdf_control_error_messages                  (DOCMGTAPP_ERROR_BASE + 86)

/**
    No Dataset is attached as Document Template object for the System Stamp Configuration object "%1$". 
*/
#define DOCMGTAPP_no_document_template_dataset_found          (DOCMGTAPP_ERROR_BASE + 87)

/**
    The file "%1$" could not be found.
*/
#define DOCMGTAPP_file_not_found                              (DOCMGTAPP_ERROR_BASE + 88)

/** @} */

/** @} */

#endif
