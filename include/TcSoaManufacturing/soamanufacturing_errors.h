/*
Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2014.
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
*/
/**
    @file

    This header file defines the errors for Teamcenter Manufacturing
    SOA related services (soamanufacturing library).
*/

#ifndef SOAMANUFACTURING_ERRORS_H
#define SOAMANUFACTURING_ERRORS_H

#include <common/emh_const.h>

/** 
    @defgroup SOAMANUFACTURING_ERRORS Errors
    @ingroup SOAMANUFACTURING
    @{
*/
/** createOrUpdateMENXObjects Service (0 - 19) */
#define SOAMANUFACTURING_failed_to_update_MENXObject    (EMH_SOAMANUFACTURING_error_base +   0 )

/** createOrUpdateMEActivity Service (20 - 35) */
#define SOAMANUFACTURING_failed_to_update_MEActivity    (EMH_SOAMANUFACTURING_error_base +   20)

#define SOAMANUFACTURING_internal_error                 (EMH_SOAMANUFACTURING_error_base + 40)
#define SOAMANUFACTURING_illegal_source_type            (EMH_SOAMANUFACTURING_error_base + 41)
#define SOAMANUFACTURING_illegal_target_type            (EMH_SOAMANUFACTURING_error_base + 42)
#define SOAMANUFACTURING_la_from_different_objects      (EMH_SOAMANUFACTURING_error_base + 43)
#define SOAMANUFACTURING_wrong_source_type              (EMH_SOAMANUFACTURING_error_base + 44)
#define SOAMANUFACTURING_not_mfg_node                   (EMH_SOAMANUFACTURING_error_base + 45)
#define SOAMANUFACTURING_plane_zone_search_not_impl     (EMH_SOAMANUFACTURING_error_base + 46)
#define SOAMANUFACTURING_classification_search_not_impl (EMH_SOAMANUFACTURING_error_base + 47)
#define SOAMANUFACTURING_search_by_size_not_impl        (EMH_SOAMANUFACTURING_error_base + 48)

/** The previous value of the selected change cannot be displayed, because the BOM Line is configured-out.
    This happens when the structure is configured with the "Already Reviewed" effectivity through the "Change Tracker" dialog.
*/
#define SOAMANUFACTURING_scope_has_no_bomline           (EMH_SOAMANUFACTURING_error_base + 49)
#define SOAMANUFACTURING_invalid_value_in_vector        (EMH_SOAMANUFACTURING_error_base + 50)
#define SOAMANUFACTURING_invalid_root                   (EMH_SOAMANUFACTURING_error_base + 51)
#define SOAMANUFACTURING_invalid_node                   (EMH_SOAMANUFACTURING_error_base + 52)
#define SOAMANUFACTURING_invalid_value                  (EMH_SOAMANUFACTURING_error_base + 53)
#define SOAMANUFACTURING_invalid_type                   (EMH_SOAMANUFACTURING_error_base + 54)
#define SOAMANUFACTURING_invalid_context                (EMH_SOAMANUFACTURING_error_base + 55)
#define SOAMANUFACTURING_one_entry_only                 (EMH_SOAMANUFACTURING_error_base + 56)
#define SOAMANUFACTURING_too_many_entries               (EMH_SOAMANUFACTURING_error_base + 57)
#define SOAMANUFACTURING_invalid_constraint_type        (EMH_SOAMANUFACTURING_error_base + 58)
#define SOAMANUFACTURING_unknown_type                   (EMH_SOAMANUFACTURING_error_base + 59)
#define SOAMANUFACTURING_disparate_contexts             (EMH_SOAMANUFACTURING_error_base + 60)
#define SOAMANUFACTURING_invalid_traversal_level        (EMH_SOAMANUFACTURING_error_base + 61)
/**
    No variant rule is associated with the product variant "%1$".
*/
#define SOAMANUFACTURING_missing_variant_rule           (EMH_SOAMANUFACTURING_error_base + 62)

/**
    The configuration of the structure "%1$" does not include the variant rule "%2$".
*/
#define SOAMANUFACTURING_config_svr_mismatch            (EMH_SOAMANUFACTURING_error_base + 63)

/**
    The configuration of the structure "%1$" does not include the product variant "%2$".
*/
#define SOAMANUFACTURING_config_pv_mismatch             (EMH_SOAMANUFACTURING_error_base + 64)

/**
    The configuration of the structure "%1$" does not include the following variant rules: %2$.
*/
#define SOAMANUFACTURING_config_svrs_mismatch           (EMH_SOAMANUFACTURING_error_base + 65)

/**
    The configuration of the structure "%1$" does not include the following product variants: %2$.
*/
#define SOAMANUFACTURING_config_pvs_mismatch            (EMH_SOAMANUFACTURING_error_base + 66)

/**
    The configuration of the structure "%1$" does not include the following variant rules and product variants: %2$.
*/
#define SOAMANUFACTURING_config_svrs_pvs__mismatch      (EMH_SOAMANUFACTURING_error_base + 67)

/**
    An invalid node has been passed to the operation "%1$" in the service "%2$". If the property "%3$" is requested, only nodes of
type "%4$" are accepted. Please report this error to your system administrator.
*/
#define SOAMANUFACTURING_invalid_node2                  (EMH_SOAMANUFACTURING_error_base + 68)

/**
    An invalid object "%1$" is passed to the "Find Affected Collaboration Contexts" command. Valid types are "Item" and "Item Revision".
*/
#define SOAMANUFACTURING_invalid_object_to_find_cc      (EMH_SOAMANUFACTURING_error_base + 69)

/**
    The "Where Referenced" operation has failed, because the type "%1$" is not supported. Valid types are "Item" and "Item Revision".
*/
#define SOAMANUFACTURING_where_reference_failed         (EMH_SOAMANUFACTURING_error_base + 70)

/**
    @name MRM_GTC_ERRORS Manufacturing Resource Manager (MRM) Generic Tool Catalog (GTC) Service Oriented Architecture (SOA) Operation Errors

    This section defines errors to support the Manufacturing Resource Manager (MRM) Generic Tool Catalog (GTC) Service Oriented Architecture (SOA) Operations.
    @{
*/

/** The Generic Tool Catalog (GTC) preference "%1$" is not set. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_preference_not_set              (EMH_SOAMANUFACTURING_error_base + 300)

/** The Generic Tool Catalog (GTC) root directories "%1$" do not exist. There are no vendor catalogs to import. Verify that the "MRMGTCVendorCatalogRootDir" preference is set correctly. */
#define SOAMANUFACTURING_MRM_GTC_root_dir_not_found              (EMH_SOAMANUFACTURING_error_base + 301)

/** No Generic Tool Catalog (GTC) vendor catalog can be found. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_cannot_open_info_file           (EMH_SOAMANUFACTURING_error_base + 302)

/** No valid vendor catalog can be found in the root directories "%1$". Copy at least one vendor catalog into one of the root directories. */
#define SOAMANUFACTURING_MRM_GTC_no_valid_vendor_catalog_found   (EMH_SOAMANUFACTURING_error_base + 303)

/** The transfer mode "%1$" cannot be found. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_transfermode_not_found          (EMH_SOAMANUFACTURING_error_base + 320)

/** The tag for the transfer mode "%1$" is invalid. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_transfermode_tag_invalid        (EMH_SOAMANUFACTURING_error_base + 321)

/** The transfer mode object for the transfer mode "%1$" does not exist. */
#define SOAMANUFACTURING_MRM_GTC_transfermode_no_object          (EMH_SOAMANUFACTURING_error_base + 322)

/* The vendor catalog PLMXML import file "%1$" does not exist. */
#define SOAMANUFACTURING_MRM_GTC_vendor_catalog_no_file          (EMH_SOAMANUFACTURING_error_base + 323)

/* The provided import option is invalid. Please select one of the import options 'Ignore' or 'Overwrite'. */
#define SOAMANUFACTURING_MRM_GTC_import_invalid_import_option    (EMH_SOAMANUFACTURING_error_base + 324)

/* The file ticket for the PLMXML import log file cannot be created. Please report this error to your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_import_cannot_create_log_ticket (EMH_SOAMANUFACTURING_error_base + 325)

/* An error has occurred while importing the vendor catalog hierarchy. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_import_error_vendor_catalog     (EMH_SOAMANUFACTURING_error_base + 326)

/* An error has occurred while importing STEP 3D models. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_import_step_3d_model            (EMH_SOAMANUFACTURING_error_base + 330)

/* The specified 3D model file does not exist: %1$. */
#define SOAMANUFACTURING_MRM_GTC_import_3d_model_file_not_found  (EMH_SOAMANUFACTURING_error_base + 331)

/* The catalog Internal Classification Object (ICO) contains no 3D model file name. */
#define SOAMANUFACTURING_MRM_GTC_ICO_no_3D_model_file_name       (EMH_SOAMANUFACTURING_error_base + 332)

/* The Manufacturing Resource Library (MRL) Internal Classification Object (ICO) contains no reference to the specified catalog ICO "%1$". */
#define SOAMANUFACTURING_MRM_GTC_MRL_ICO_no_reference_to_catalog (EMH_SOAMANUFACTURING_error_base + 333)

/* An error has occurred while importing the STEP 3D model "%1$". Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_import_3d_model_error           (EMH_SOAMANUFACTURING_error_base + 334)

/* The BOM Window is invalid. */
#define SOAMANUFACTURING_MRM_GTC_invalid_BOMWindow               (EMH_SOAMANUFACTURING_error_base + 345)

/* The "Show GCS (Guided Component Search) Connection Points" option "%1$" is invalid. Valid values are 0 (hide all connection points), 1 (show all connection points), 2 (hide all connected connection points). */
#define SOAMANUFACTURING_MRM_GTC_invalid_show_GCS_option         (EMH_SOAMANUFACTURING_error_base + 346)

/* An error has occurred while updating the NX tool assemblies. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_error_update_NX_tool_assemblies (EMH_SOAMANUFACTURING_error_base + 350)

/* The NX Tool Type is not specified. */
#define SOAMANUFACTURING_MRM_GTC_NX_tool_type_not_specified      (EMH_SOAMANUFACTURING_error_base + 351)

/* The Tracking Point is not specified for the turning tool assembly "%1$". */
#define SOAMANUFACTURING_MRM_GTC_tracking_point_not_specified    (EMH_SOAMANUFACTURING_error_base + 352)

/* The Graphics Builder is not configured properly. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_GB_not_properly_configured      (EMH_SOAMANUFACTURING_error_base + 353)

/* An error has occurred while creating the tool assembly NX part file with the user function UF_CreateToolPartFile. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_error_create_tool_part_file     (EMH_SOAMANUFACTURING_error_base + 354)

/* An error has occurred while creating the tool base component in the tool assembly NX part file with the user function UF_CreateToolBaseComponent. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_error_create_tool_component     (EMH_SOAMANUFACTURING_error_base + 355)

/* An error has occurred while adding the tool junctions in the tool assembly NX part file with the user function UF_AddJunctions. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_error_add_tool_junctions        (EMH_SOAMANUFACTURING_error_base + 356)

/* An error has occurred while adding Cut and Nocut geometry to the tool assembly NX part file with the user function UF_AddGeometry. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_error_add_cut_nocut_geometry    (EMH_SOAMANUFACTURING_error_base + 357)

/* An error has occurred while creating Cut and Nocut spin geometry in the tool assembly NX part file with the user function UF_SpinGeometry. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_error_create_cut_nocut_spin     (EMH_SOAMANUFACTURING_error_base + 358)

/* An error has occurred while writing the part attributes in the tool assembly NX part file with the user function UF_WritePartAttributes. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_error_write_part_attributes     (EMH_SOAMANUFACTURING_error_base + 359)

/* An error has occurred while saving the work part of the tool assembly NX part file with the user function UF_Part_save_work_part. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_error_save_work_part            (EMH_SOAMANUFACTURING_error_base + 360)

/* The assortment file "%1$" cannot be found. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_assortment_file_not_found       (EMH_SOAMANUFACTURING_error_base + 361)

/* The mapping file "%1$" cannot be found. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_mapping_file_not_found          (EMH_SOAMANUFACTURING_error_base + 362)

/* The STEP P21 file "%1$" cannot be found. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_step_p21_file_not_found         (EMH_SOAMANUFACTURING_error_base + 363)

/* An error has occurred while importing the STEP P21 files. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_import_error_step_p21_files     (EMH_SOAMANUFACTURING_error_base + 364)

/* An error has occurred while counting the STEP P21 files. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_error_count_step_p21_files      (EMH_SOAMANUFACTURING_error_base + 365)

/* An error has occurred while checking the tool parameters. Please refer to the Teamcenter server syslog file for more information on this error, or contact your system administrator. */
#define SOAMANUFACTURING_MRM_error_tool_parameter_check_failed   (EMH_SOAMANUFACTURING_error_base + 370)

/* An error has occurred while obtaining information on vendor catalogs. Please refer to the Teamcenter server syslog file for more information on this error, or contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_error_get_vendor_catalog_info   (EMH_SOAMANUFACTURING_error_base + 371)
/**
The source element for the Recipe is not a valid Business Object.
*/
#define SOAMANUFACTURING_invalid_recipe_anchor                   (EMH_SOAMANUFACTURING_error_base + 372)
/**
The specified application key cannot be empty and must be mapped to a resolvable key on the server.
*/
#define SOAMANUFACTURING_invalid_key                             (EMH_SOAMANUFACTURING_error_base + 373)
/**
At least one valid resolvable scope must be provided.
*/
#define SOAMANUFACTURING_invalid_scope                           (EMH_SOAMANUFACTURING_error_base + 374)
/**
The Recipe name cannot be empty.
*/
#define SOAMANUFACTURING_invalid_recipe_name                     (EMH_SOAMANUFACTURING_error_base + 375)
/**
The schema element "Mfg0MEMBOMRecipe" is missing, and is needed to be able to store the Recipe. Please contact your system administrator to ensure that the Foundation template is properly installed.
*/
#define SOAMANUFACTURING_missing_recipe_schema                   (EMH_SOAMANUFACTURING_error_base + 376)

/** The Generic Tool Catalog (GTC) package ZIP file having the transient File Management System (FMS) file ticket "%1$" cannot be unzipped to the server-sided directory "%2$". Please refer to the Teamcenter server syslog file for more information on this error, or contact your system administrator. */
#define SOAMANUFACTURING_MRM_GTC_error_unzip_gtc_package         (EMH_SOAMANUFACTURING_error_base + 380)

/** The resource having the Internal Classification Object (ICO) ID "%1$" cannot be mapped to the Teamcenter Classification class "%2$" and the item with the ID "%3$". Please refer to the Teamcenter server syslog file for more information on this error, or contact your system administrator. */
#define SOAMANUFACTURING_MRM_error_map_classification_object     (EMH_SOAMANUFACTURING_error_base + 381)

/** The Item Revision "%1$" is not marked for reuse. Please set the "Reuse Assembly" property to 1 on the Item Revision and try again.*/
#define SOAMANUFACTURING_invalid_reuse_rev                       (EMH_SOAMANUFACTURING_error_base + 382)

/** An error has occurred while searching equivalent lines for the selected lines. Please contact your system administrator. */
#define SOAMANUFACTURING_equivalent_search_error                 (EMH_SOAMANUFACTURING_error_base + 383)

/** An error has occurred while aligning lines between the two structures. Please look at the returned log file for details. */
#define SOAMANUFACTURING_alignment_error                         (EMH_SOAMANUFACTURING_error_base + 384)

/** An error has occurred while creating setup sheets. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_error_create_setup_sheets           (EMH_SOAMANUFACTURING_error_base + 385)

/** The creation of a setup sheet for the resource "%1$" has failed. Please refer to the NX syslog file for more information. */
#define SOAMANUFACTURING_MRM_error_create_setup_sheet            (EMH_SOAMANUFACTURING_error_base + 386)

/** An error has occurred while extracting holder data. Please contact your system administrator. */
#define SOAMANUFACTURING_MRM_error_extract_holder_data           (EMH_SOAMANUFACTURING_error_base + 387)

/**Extracting holder data from the resource "%1$" has failed. Please refer to the NX syslog file for more information. */
#define SOAMANUFACTURING_MRM_error_extract_holder_data_single    (EMH_SOAMANUFACTURING_error_base + 388)

/** The Item Revision "%1$" is not classified in an assembly class. Use a tool assembly to be able to add a multitool cutter to it. */ 
#define SOAMANUFACTURING_MRM_error_multitool_non_asm_item_revision          (EMH_SOAMANUFACTURING_error_base + 389)

/** The Item Revision "%1$" is not classified. Classify the tool assembly to be able to add a multitool cutter to it. */
#define SOAMANUFACTURING_MRM_error_multitool_non_classified_item_revision   (EMH_SOAMANUFACTURING_error_base + 390)

/** The Item Revision "%1$" is classified in an assembly class which does not have multitool properties. Use appropriate tool assembly class to be able to add a multitool cutter to it.*/ 
#define SOAMANUFACTURING_MRM_error_multitool_non_multitool_item_revision    (EMH_SOAMANUFACTURING_error_base + 391)

/** A multi-tool cutter cannot be added to "%1$" because this Item Revision is classified in an assembly class for which the "Cutter ID" attribute is not set as "Local Value". Update MRL tools class hierarchy to MRL V4.1 or later.*/
#define SOAMANUFACTURING_MRM_error_multitool_cutter_id_not_local_value      (EMH_SOAMANUFACTURING_error_base + 392)

/** The "Auto Positioning" operation has failed.*/
#define SOAMANUFACTURING_MRM_autopositioning_error                          (EMH_SOAMANUFACTURING_error_base + 393)

/** One of the selected source BOM line is invalid.*/
#define SOAMANUFACTURING_MRM_autopositioning_invalid_source_bomline         (EMH_SOAMANUFACTURING_error_base + 394)

/** The target BOM line is invalid. */
#define SOAMANUFACTURING_MRM_autopositioning_invalid_target_bomline         (EMH_SOAMANUFACTURING_error_base + 395)

/** The source coordinate system BOM line is invalid. */
#define SOAMANUFACTURING_MRM_autopositioning_invalid_csys_source_bomline    (EMH_SOAMANUFACTURING_error_base + 396)

/** The target coordinate system BOM line is invalid. */
#define SOAMANUFACTURING_MRM_autopositioning_invalid_csys_target_bomline    (EMH_SOAMANUFACTURING_error_base + 397)

/** One of the input classification objects is invalid. */
#define SOAMANUFACTURING_MRM_geticomappingtargets_invalid_classification_object         (EMH_SOAMANUFACTURING_error_base + 398)

/** The view type is invalid. Valid view types are 0, 200 or 201.*/
#define SOAMANUFACTURING_MRM_geticomappingtargets_invalid_view_type                     (EMH_SOAMANUFACTURING_error_base + 399)

/** The input type name is NULL. */
#define SOAMANUFACTURING_null_type_input                                    (EMH_SOAMANUFACTURING_error_base + 400)

/** The input property is NULL. */
#define SOAMANUFACTURING_null_prop_input                                    (EMH_SOAMANUFACTURING_error_base + 401)

/** No parts in proximity were retrieved for the "%1$" Manufacturing Feature. Please check if the Manufacturing Feature is valid. */
#define SOAMANUFACTURING_no_parts_in_proximity_retrieved                    (EMH_SOAMANUFACTURING_error_base + 402)

/** Proximity distance should be a valid, non-negative number. */
#define SOAMANUFACTURING_invalid_proximity_distance                         (EMH_SOAMANUFACTURING_error_base + 403)

/** The type of input object "%1$" is not supported. Supported types are: Mfg0BvrProcess, Mfg0BvrProcessArea, Mfg0MESimStudy, Mfg0MEShdStudy, Mfg0BvrOperation and Mfg0BvrWorkarea.*/
#define SOAMANUFACTURING_unsupported_object_type_input                      (EMH_SOAMANUFACTURING_error_base + 404)


/** @} */
/** @} */

#endif
