/* 
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2017
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
*/


#ifndef PMM_ERRORS_H
#define PMM_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup PMM_ERRORS PMM Errors
    @ingroup PMM
    @{
*/

/**An internal error "%1$" has occurred in the Product Master Management (PMM) module. Please report this error to your system administrator. */
#define PMM_internal_error                                                                                  (EMH_USAGEWC_error_base +   0)

/** SOAP Error (%1$): %2$%3$. */
#define PMM_soap_error                                                                                      (EMH_USAGEWC_error_base +   1)

/** FSC Proxy Error %1$. */
#define PMM_fsc_proxy_error                                                                                 (EMH_USAGEWC_error_base +   2)

/** Proxy class (%1$) not registered. */
#define PMM_proxy_class_not_registered                                                                      (EMH_USAGEWC_error_base +   3)

/** Required site preference (%1$) not set. */
#define PMM_required_site_preference_not_set                                                                (EMH_USAGEWC_error_base +   4)

/** An error of code "%1$" has occurred in the Usage server: %2$. */
#define PMM_usage_server_error                                                                              (EMH_USAGEWC_error_base +   5)

/** Failed to upload dataset (%1$) to usage. */
#define PMM_failed_to_upload                                                                                (EMH_USAGEWC_error_base +   6)

/** Failed to align. Select only LOU(s)/SubUsage(s) or Part Occurrenc(s). */
#define PMM_select_homogeneous_objects                                                                      (EMH_USAGEWC_error_base +   7)

/** Conflicts detected while aligning some CAD Occurrences due to one of the following reasons:
- The target Part Occurrence(s) is already aligned to some CAD Occurrence(s)
- The same Design Occurrence cannot be aligned to multiple Part Occurrences from the same Sub-Usage
  Operation was not performed. */
#define PMM_cannot_link_occurrences                                                                         (EMH_USAGEWC_error_base +   8)

/** The number of Design Occurrences selected exceeds the number of Position Designators available. */
#define PMM_designOcc_exceeds_size                                                                          (EMH_USAGEWC_error_base +   9)

/** One or more CAD occurrences being aligned have Position Designator attribute values which do not match the Position Designator attribute value of any target Sub-Usage objects. */
#define PMM_position_designator_values_mismatch                                                             (EMH_USAGEWC_error_base +   10)

/** One or more Design Occurrences have not been aligned to a Part Occurrence. */
#define PMM_design_occ_not_aligned                                                                          (EMH_USAGEWC_error_base +   11)

/** One or more of the Design Occurrences does not have a JT/PLMXML attached to it. */
#define PMM_no_dataset_attached                                                                             (EMH_USAGEWC_error_base +   12)

/** User (%1$) not logged into usage server. */
#define PMM_not_logged_in                                                                                   (EMH_USAGEWC_error_base +   13)

/** None of the Part Occurrences selected are aligned to any Design Occurrence. */
#define PMM_part_occs_not_aligned                                                                           (EMH_USAGEWC_error_base +   14)

/** Unable to delete temporary file %1$. */
#define PMM_unable_to_delete_tempfile                                                                       (EMH_USAGEWC_error_base +   15)

/** Invalid input(s). Select SubUsage(s) for a valid one. */
#define PMM_subusage_not_selected                                                                           (EMH_USAGEWC_error_base +   16)

/** Invalid inputs. Select SubUsages under the same Line Of Usage. */
#define PMM_subusages_from_different_lous                                                                   (EMH_USAGEWC_error_base +   17)

/** Unable to login specified user to the Usage Server. Please contact your system administrator. */
#define PMM_failed_to_login                                                                                 (EMH_USAGEWC_error_base +   18)

/** The provided BOM Line is not in context of an Installation Assembly. */
#define PMM_bomline_not_in_context_of_ia                                                                     (EMH_USAGEWC_error_base +   19)

/** The top line of the structure cannot be aligned or unaligned because it is not supported. Select a BOM line other than the top line. */
#define PMM_cannot_align_a_topline                                                                          (EMH_USAGEWC_error_base +   20)

/** The Teamcenter server is having difficulty connecting to Teamcenter BOM. Please contact your site administrator. */
#define PMM_soap_tcp_error                                                                                  (EMH_USAGEWC_error_base +   21)

/** No subusage resulted from split request.  This occurs when the splitting condition is incompatible with the existing subusage feature expression or incompatible with the existing usage feature expression. */
#define PMM_split_resulted_in_no_subusage                                                                   (EMH_USAGEWC_error_base +   22)

/** There is no expression specified on the LOU. Subusage could not be created. */
#define PMM_cannot_create_subusage                                                                          (EMH_USAGEWC_error_base +   23)

/** Insufficient BOM Solve parameters. Enter %1$ value for BOM Solve search. */
#define PMM_insufficient_bom_solve_attr_1                                                                   (EMH_USAGEWC_error_base +   24)

/** Invalid value set for the preference - UsageWC_DefaultDesignMaturity. Please contact your site administrator. */
#define PMM_invalid_maturity_value                                                                          (EMH_USAGEWC_error_base +   25)

/** Saved BOM Solve query (%1$) may only contain "AND" clauses. Please contact your site administrator. */
#define PMM_complex_bom_solve_query                                                                         (EMH_USAGEWC_error_base +   26)

/** Saved BOM Solve query (%1$) is not properly formed.Please contact your site administrator. Expecting the following attributes: %2$. */
#define PMM_illformed_bom_solve_query                                                                       (EMH_USAGEWC_error_base +   27)

/** The search has failed because some mandatory fields are not specified: %1$. */
#define PMM_mandatory_fields_not_specified                                                                  (EMH_USAGEWC_error_base +   28)

/** Unable to determine drawing sheet attributes - some datasets have no forms attached. */
#define PMM_no_drawingsheet_attr_form                                                                       (EMH_USAGEWC_error_base +   29)

/** Unable to determine drawing sheet attributes - some datasets have more than 1 form attached. */
#define PMM_multiple_forms_attached                                                                         (EMH_USAGEWC_error_base +   30)

/** Multiple selections unsupported - please select one document revision for this operation. */
#define PMM_multiple_drawings_selected                                                                      (EMH_USAGEWC_error_base +   31)

/** Insufficient BOM Solve parameters. Enter %1$ and %2$ values for BOM Solve search. */
#define PMM_insufficient_bom_solve_attr_2                                                                   (EMH_USAGEWC_error_base +   32)

/** Insufficient BOM Solve parameters. Enter %1$, %2$ and %3$ values for BOM Solve search. */
#define PMM_insufficient_bom_solve_attr_3                                                                   (EMH_USAGEWC_error_base +   33)

/** Publish operation failed due to improper multisite setup for distributed mode. */
#define PMM_multisite_error                                                                                 (EMH_USAGEWC_error_base +   34)

/** Invalid SiteID(USAGEWC_SITEID) or SiteID might not be set. Please contact your site administrator. */
#define PMM_siteid_error                                                                                    (EMH_USAGEWC_error_base +   35)

/** Failed to create Line Of Assembly. */
#define PMM_loa_creation_failed                                                                             (EMH_USAGEWC_error_base +   36)

/** Failed to delete Line Of Usages. */
#define PMM_lou_deletion_failed                                                                             (EMH_USAGEWC_error_base +   37)

/** Failed to delete Line Of Assemblies. */
#define PMM_loa_deletion_failed                                                                             (EMH_USAGEWC_error_base +   38)

/** Top Line's Parent Item Revision in the Source Structure should be a Representation of Topline's Component Part in the Target Structure. */
#define PMM_bomline_not_representation_of_act_topline                                                       (EMH_USAGEWC_error_base +   39)

/** Conflicts detected while aligning some CAD Occurrences due to one of the following reasons:
- The target ACT Line(s) is already aligned to some CAD Occurrence(s)
- The same Design Occurrence cannot be aligned to multiple ACT Lines in the same structure. */
#define PMM_already_aligned                                                                                 (EMH_USAGEWC_error_base +   40)

/** The number of Design Occurrences selected mismatches with the number of ACT Lines Selected. */
#define PMM_mismatch_of_selected_lines                                                                      (EMH_USAGEWC_error_base +   41)

/** Failed to create Corporate Part. */
#define PMM_pm_creation_failed                                                                              (EMH_USAGEWC_error_base +   42)

/** Failed to create Line Of Usage. */
#define PMM_lou_creation_failed                                                                             (EMH_USAGEWC_error_base +   43)

/** An invalid object is selected for this operation. */
#define PMM_invalid_object                                                                                  (EMH_USAGEWC_error_base +   44)

/** Trying to unlink CAD Occurrence(s) and ACT Line(s) that are not aligned. */
#define PMM_not_aligned                                                                                     (EMH_USAGEWC_error_base +   45)

/** The attribute value "%2$" of the drawing dataset "%1$" exceeds the maximum length (4) on the attached form. */
#define PMM_invalid_attr_length                                                                             (EMH_USAGEWC_error_base +   46)

/** The items selected for the Publish operation are not aligned to any Corporate Part. */
#define PMM_not_aligned_for_publish                                                                         (EMH_USAGEWC_error_base +   47)

/** The usage server has failed to process the update request. */
#define PMM_usageserver_update_failed                                                                       (EMH_USAGEWC_error_base +   48)

/** Error while processing platform locale. */
#define PMM_usageserver_errors_in_locale_settings                                                           (EMH_USAGEWC_error_base +   49)

/** Some of the selected lines are packed. Please unpack them for this operation. */
#define PMM_selected_lines_packed                                                                           (EMH_USAGEWC_error_base +   50)

/** The BOM line %1$ or ACT line %2$ is already aligned. */
#define PMM_act_validation1_failed                                                                          (EMH_USAGEWC_error_base +   51)

/** The BOM line "%1$" cannot be aligned to the ACT line "%2$" due to following reasons:
An ancestor of the BOM line "%1$" is aligned, but not with an ancestor of the ACT line "%2$".
An ancestor of the ACT line "%2$" is aligned, but not with an ancestor of the BOM line "%1$". */
#define PMM_act_validation2_failed                                                                          (EMH_USAGEWC_error_base +   52)

/** The ACT alignment operation has failed due to any one of the reasons below:
- One or more sibling of the selected CAD Occurrence is already aligned with descendent of the selected ACT line.
- One or more ancestor of the selected CAD Occurrence is already aligned with descendent of the selected ACT line.
- One or more ancestor of the selected CAD Occurrence is already aligned with sibling of the selected ACT line. */
#define PMM_act_validation3_failed                                                                          (EMH_USAGEWC_error_base +   53)

/** The BOM line "%1$" cannot be aligned to the ACT line "%2$" due to following reasons:
- A descendant of the BOM line "%1$" is aligned, but not with a descendant of the ACT line "%2$".
- A descendant of the ACT line "%2$" is aligned, but not with a descendant of the BOM line "%1$". */
#define PMM_act_validation4_failed                                                                          (EMH_USAGEWC_error_base +   54)

/** The ACT alignment operation has failed due to any one of the reasons below:
- One or more sibling of the selected CAD Occurrence is already aligned with ancestor of the selected ACT line.
- One or more descendent of the selected CAD Occurrence is already aligned with ancestor of the selected ACT line.
- One or more descendent of the selected CAD Occurrence is already aligned with sibling of the selected ACT line. */
#define PMM_act_validation5_failed                                                                          (EMH_USAGEWC_error_base +   55)

/** The ACT alignment operation has failed:
- The ACT alignment validation has received corrupted data. */
#define PMM_act_validation_currupt_data_failed                                                              (EMH_USAGEWC_error_base +   56)

/** The dataset has failed to save during the "Distributed Publish" operation. */
#define PMM_distpub_dataset_save_error                                                                      (EMH_USAGEWC_error_base +   57)

/** CAD-Part unalignment is being prevented because this Corporate Part(s) is either associated with an Assembly Component Tree Alignment (ACT Alignment) or a context for an existing ACT Alignment. */
#define PMM_part_not_allowed_for_unalign                                                                    (EMH_USAGEWC_error_base +   58)

/** Datasets for Item Revisions %1$ contain no JT files. */
#define PMM_missing_jt_file_encountered                                                                     (EMH_USAGEWC_error_base +   59)

/** The parameters specified for BOM search/solve are invalid: %1$ should not be specified with %2$.Please correct the parameters and retry the action. */
#define PMM_large_solve_scope                                                                               (EMH_USAGEWC_error_base +   60)

/** The BOM search/solve scope has invalid set of effectivity fields. The criteria must specify a combination of either
%1$ [for Precise search] Or %2$ [for Imprecise search].
Criteria for both Precise and Imprecise search/solve cannot be specified at the same time. */
#define PMM_precise_and_imprecise_search_scope_present                                                      (EMH_USAGEWC_error_base +   61)

/** The CAD Occurrence alignment cannot be performed because the Line of Usage (LOU) contains an alpha quantity specification. */
#define PMM_lou_alpha_quantity_validation_failure                                                           (EMH_USAGEWC_error_base +   62)

/** There is no CAD structure aligned to the selected solutions. */
#define PMM_lou_no_alignedcad                                                                               (EMH_USAGEWC_error_base +   63)

/** There is no CAD structure aligned to the selected Assembly Component Tree Line. */
#define PMM_act_no_alignedcad                                                                               (EMH_USAGEWC_error_base +   64)

/** The selected object is not of a valid type for this operation. The only supported types are Assembly Component Tree (ACT) Line (other than Top Line of ACT structure) and Line Of Usage. */
#define PMM_invalid_objectfor_alignedcad                                                                    (EMH_USAGEWC_error_base +   65)

/** The parameters specified for BOM search/solve are invalid: %1$ cannot be specified if Effectivity Stream is Production. Correct the parameters and retry the action. */
#define PMM_invalid_scope_for_production_stream                                                             (EMH_USAGEWC_error_base +   66)

/** The parameters specified for BOM search/solve are invalid: %1$ must be specified for precise search
Or
%2$ must be specified for imprecise search.. */
#define PMM_invalid_scope_for_nonproduction_stream                                                          (EMH_USAGEWC_error_base +   67)

/** There is remote CAD structure aligned to the selected Usage object. */
#define PMM_remote_alignedcad                                                                               (EMH_USAGEWC_error_base +   68)

/** The CAD occurrence alignment cannot be performed because the Unit Of Measure property for the Line of Usage (LOU) %1$ has a value of "%2$".
Only the "EA" value (stands for "each") for the Unit Of Measure property is valid for a Line Of Usage to align to a CAD occurrence. */
#define PMM_lou_uom_validation_failure                                                                      (EMH_USAGEWC_error_base +   69)

/** The CAD occurrence alignment cannot be performed because the Assembly Component Tree (ACT) lines %1$ have non "EA" Unit Of Measure specifications.
Only the "EA" value (stands for "each") for the Unit Of Measure property is valid for Assembly Component Tree (ACT) lines to align to a CAD occurrence. */
#define PMM_act_uom_validation_failure                                                                      (EMH_USAGEWC_error_base +   70)

/** Assembly Component Tree (ACT) alignment is only allowed in Present Time Mode of Teamcenter Product Master Management (TcPMM) system. */
#define PMM_alignment_not_allowed_in_perpetual_mode                                                         (EMH_USAGEWC_error_base +   71)

/** The "Publish" operation has failed because the assembly "%1$" contains embedded JT elements. */
#define PMM_assembly_with_embedded_jt                                                                       (EMH_USAGEWC_error_base +   72)

/** The "Publish" operation has failed because the assembly to publish contains invalid bounding box values. */
#define PMM_invalid_bbox_value                                                                              (EMH_USAGEWC_error_base +   73)

/** The corresponding CAD data could not be found for the specified target Line Of Usages (LOU). */
#define PMM_spatial_no_target_absocc                                                                        (EMH_USAGEWC_error_base +   74)

/** The Teamcenter Product Master Management (TcPMM) spatial search resulted with zero background occurrences. */
#define PMM_spatial_no_background_absocc                                                                    (EMH_USAGEWC_error_base +   75)

/** Target occurrences could not be resolved to valid BOM Lines. */
#define PMM_spatial_no_target_apns                                                                          (EMH_USAGEWC_error_base +   76)

/** Background occurrences could not be resolved to valid BOM Lines. */
#define PMM_spatial_no_background_apns                                                                      (EMH_USAGEWC_error_base +   77)

/** Because the Assembly "%1$" (which is being published) has no associated bounding box, it will not appear in spatial search results. */
#define PMM_assembly_publish_no_bbox                                                                        (EMH_USAGEWC_error_base +   78)

/** The Sub-Usage has failed to be created as an invalid expression is specified on the Line of Usage (LOU) "%1$". Please ensure that the LOU expression is valid. */
#define PMM_su_creation_failed                                                                              (EMH_USAGEWC_error_base +   79)

/** The "Save" operation is not allowed on the Business Object "%1$". These proxy objects are saved when they are dropped into a folder or added to the favorites. */
#define PMM_persistent_proxy_not_allowed_for_save                                                           (EMH_USAGEWC_error_base +   80)

/** Multiple proxy objects were found for the given key values. */
#define PMM_multiple_proxies_returned                                                                       (EMH_USAGEWC_error_base +   81)

/** This error code corresponds to the error coming from Teamcenter Product Master Management (TcPMM) server. Error message : "%1$" */
#define PMM_blanket_as_is_error                                                                             (EMH_USAGEWC_error_base +   82)

/** The Line of Usage "%1$" does not contain any Corporate Part. */
#define PMM_lou_no_part_send_to_msm_failure                                                                 (EMH_USAGEWC_error_base +   83)

/** The number of CAD Item Revisions is different from the number of Product Master Manager Parts. */
#define PMM_mismatch_of_item_rev_and_part                                                                   (EMH_USAGEWC_error_base +   84)

/** The datasets attached to the Item Revisions to be published do not contain any files. */
#define PMM_no_files_to_upload                                                                              (EMH_USAGEWC_error_base +   85)

/** The input list of Item Revisions for alignment is not homogeneous. The input list should contain only CAD or only Drawing Item Revisions. */
#define PMM_mix_of_item_and_drawing                                                                         (EMH_USAGEWC_error_base +   86)

/** The Item Revision "%1$" contains duplicate drawing datasets. */
#define PMM_duplicate_drawing_dataset                                                                       (EMH_USAGEWC_error_base +   87)

/** The Item Revision "%1$" contains some datasets with no files. */
#define PMM_mismatch_of_dataset_and_file                                                                    (EMH_USAGEWC_error_base +   88)

/** No criterion is provided. */
#define PMM_no_query_criteria_input                                                                         (EMH_USAGEWC_error_base +   89)

/** The part breakdown operation has failed. */
#define PMM_part_breakdown_failed                                                                           (EMH_USAGEWC_error_base +   90)

/** The Line Of Usage unalignment operation has failed. Please check the error details for more information. */
#define PMM_lou_unalign_operation_failed                                                                    (EMH_USAGEWC_error_base +   91)

/** The alignment operation has failed. */
#define PMM_alignment_failed                                                                                (EMH_USAGEWC_error_base +   92)

/** The unalignment operation has failed. */
#define PMM_unalignment_failed                                                                              (EMH_USAGEWC_error_base +   93)

/** The publish operation has failed. */
#define PMM_publish_failed                                                                                  (EMH_USAGEWC_error_base +   94)

/** The make primary operation has failed. */
#define PMM_make_primary_failed                                                                             (EMH_USAGEWC_error_base +   95)

/** The consistency stamp is not present for the object "%2$" of type "%1$". */
#define PMM_null_consistency_stamp                                                                          (EMH_USAGEWC_error_base +   96)

/** The Assembly Component Tree unalignment action has failed. */
#define PMM_act_unalignment_failed                                                                          (EMH_USAGEWC_error_base +   97)

/** No aligned Assembly Component Tree Lines could be found in the BOM window for CAD occurrences. Please check the Teamcenter server syslog file for more information. */
#define PMM_find_aligned_act_for_cad_failed                                                                 (EMH_USAGEWC_error_base +   98)

/** The Spatial Search operation has failed. */
#define PMM_execute_spatial_search_failed                                                                   (EMH_USAGEWC_error_base +   99)

/** The Item Revision "%1$" is required to have at least a "Direct Model" dataset or an "Assembly PLMXML" file attached with "Rendering" relation. */
#define PMM_design_rev_has_no_rendering                                                                     (EMH_USAGEWC_error_base +   100)

/** The Drawing Revision "%1$" is required to have at least one "Drawing" or "Documentation" dataset attached with "Specification" relation. */
#define PMM_drawing_rev_has_no_specification_dataset                                                        (EMH_USAGEWC_error_base +   101)

/** The Dataset "%1$" may have zero or many "Direct Model" or "Text" (PLMXML) datasets with a Rendering relation. It is required to have only one valid Rendering dataset. */
#define PMM_dataset_has_no_rendering                                                                        (EMH_USAGEWC_error_base +   102)

/** An error has occurred while retrieving the primary representation of the parts. Please check the syslog file and report this error to your system administrator. */
#define PMM_ask_primary_representation_failed                                                               (EMH_USAGEWC_error_base +   103)

/** No primary representation is found for the Corporate Part "%1$". Set the default representation for the part to enable part visualization. */
#define PMM_no_primary_representation_found                                                                 (EMH_USAGEWC_error_base +   104)

/** The operation has failed because it expects an object of type "%1$". */
#define PMM_object_not_of_expected_type                                                                     (EMH_USAGEWC_error_base +   105)

/** The property constants could not be loaded for type "%1$". Please check the Teamcenter server syslog file for more information, or contact your system administrator. */
#define PMM_failed_to_load_property_constant                                                                (EMH_USAGEWC_error_base +   106)

/**No Product Master Management components information is provided.*/
#define PMM_empty_pmm_components_information                                                                (EMH_USAGEWC_error_base +   107)

/**No Product Master Management component attribute details are not provided.*/
#define PMM_empty_pmm_component_attribute_details                                                           (EMH_USAGEWC_error_base +   108)

/**Retrieving the Product Master Management Proxy objects from the Product Master Management Components operation has failed. Please contact your system administrator.*/
#define PMM_get_pmm_proxy_object_from_pmm_component_failed                                                  (EMH_USAGEWC_error_base +   109)

/**Finding the aligned CAD for the Product Master Management Part operation has failed.*/
#define  PMM_find_aligned_cad_for_part_failed                                                               (EMH_USAGEWC_error_base +   110)

/**Finding the aligned Product Master Management Part for CAD operation has failed.*/
#define  PMM_find_aligned_drawing_for_part_failed                                                           (EMH_USAGEWC_error_base +   111)

/**No Design objects information is provided.*/
#define  PMM_empty_design_object_information                                                                (EMH_USAGEWC_error_base +   112)

/**Finding aligned CAD for Product Master Management Part operation has failed.*/
#define  PMM_find_aligned_part_for_cad_failed                                                               (EMH_USAGEWC_error_base +   113)

/**Finding aligned Product Master Management Part for Drawing operation has failed.*/
#define  PMM_find_aligned_part_for_drawing_failed                                                           (EMH_USAGEWC_error_base +   114)

/**No Design proxy object information is provided.*/
#define  PMM_empty_design_proxy_object_information                                                          (EMH_USAGEWC_error_base +   115)

/**Finding aligned Product Master Management Part for Drawing Proxy operation has failed.*/
#define  PMM_find_aligned_part_for_drawing_proxy_failed                                                     (EMH_USAGEWC_error_base +   116)

/**No properties for the Product Master Management proxy objects are present in the Product Master Management server response. Please contact your system administrator.*/
#define  PMM_column_name_do_not_match                                                                       (EMH_USAGEWC_error_base +   117)

/**The Engineering Work Order state could not be updated.*/
#define  PMM_failed_to_update_ewo_state                                                                     (EMH_USAGEWC_error_base +   118)

/**Teamcenter proxy object properties are not in sync with Product Master Manager's objects. Please contact your system administrator.*/
#define  PMM_values_do_not_match                                                                            (EMH_USAGEWC_error_base +   119)

/**The conversion to UTF8 encoding has failed. Please contact your system administrator.*/
#define  PMM_utf8_conversion_failed                                                                         (EMH_USAGEWC_error_base +   120)

/**Finding the aligned Product Master Management Solution for Design operation has failed.*/
#define  PMM_find_aligned_solution_for_cad_failed                                                           (EMH_USAGEWC_error_base +   121)

/**Finding the aligned Design for Product Master Management Solution operation has failed.*/
#define  PMM_find_aligned_cad_for_solution_failed                                                           (EMH_USAGEWC_error_base +   122)

/**No Design/Part/Authorization information is provided.*/
#define  PMM_invalid_input_empty_part_design_auth                                                           (EMH_USAGEWC_error_base +   123)

/**No operation name is provided in the request.*/
#define  PMM_invalid_operation                                                                              (EMH_USAGEWC_error_base +   124)

/**No Solution information is provided.*/
#define  PMM_empty_solution_information                                                                     (EMH_USAGEWC_error_base +   125)

/**The initialization of the Product Master Management (PMM) proxy class has failed. Please contact your system administrator.*/
#define  PMM_class_initialization_failed                                                                    (EMH_USAGEWC_error_base +   126)

/**No alignable Design types are specified in the preference "USAGE_AlignableDesignTypes".*/
#define  PMM_alignable_drawings_not_specified                                                               (EMH_USAGEWC_error_base +   127)

/**No alignable Drawing types are specified in the preference "USAGE_AlignableDrawingItemRevisions".*/
#define  PMM_alignable_designs_not_specified                                                                (EMH_USAGEWC_error_base +   128)

/**No Assembly Component Tree Line information is provided.*/
#define  PMM_empty_act_information                                                                          (EMH_USAGEWC_error_base +   129)

/**Finding the aligned Design for Assembly Component Tree Line operation has failed.*/
#define  PMM_find_aligned_cad_for_act_failed                                                                (EMH_USAGEWC_error_base +   130)

/**The class instantiation has failed. Check the system log for more information.*/
#define  PMM_class_instantiation_failed                                                                     (EMH_USAGEWC_error_base +   131)

/**No Product Master Management Structure Context object information is provided.*/
#define  PMM_empty_pmmsco_information                                                                       (EMH_USAGEWC_error_base +   132)

/**The creation of the Product Master Management Structure Context object operation has failed.*/
#define  PMM_creation_of_pmmsco_object_failed                                                               (EMH_USAGEWC_error_base +   133)

/**Retrieving PLMXML from Product Master Management Structure Context object recipe operation has failed. Check the system log for more information.*/
#define  PMM_get_plmxml_from_pmmsco_recipe_failed                                                           (EMH_USAGEWC_error_base +   134)

/**The search criterion (Scope/Recipe) cannot be created. Check the system log for more information. */
#define  PMM_appr_search_criterion_cannot_be_created                                                        (EMH_USAGEWC_error_base +  135)

/**The BOM View Revision could not be refreshed as part of the Product Master Management refresh operation. Please contact your system administrator.*/
#define  PMM_bvr_sync_internal_error                                                                        (EMH_USAGEWC_error_base +  136)

/**The Scope/Recipe information could not be retrieved from the Item Revision "%1$".*/
#define  PMM_failed_to_find_appr_search_criterion_container                                                 (EMH_USAGEWC_error_base + 137)

/**The Item revision could not be retrieved from the BOM Line. Check the system log for more information.*/
#define  PMM_failed_to_find_item_revision                                                                   (EMH_USAGEWC_error_base + 138)

/**The "%1$" Product Master Management Query input object creation has failed. Please contact your system administrator.*/
#define  PMM_failed_to_create_input                                                                         (EMH_USAGEWC_error_base + 139)

/**The "%1$" Product Master Management Query object creation has failed. Please contact your system administrator.*/
#define  PMM_failed_to_create_bo                                                                            (EMH_USAGEWC_error_base + 140)

/**The attributes and values could not be set for Search criterion Product Master Management Query. Please contact your system administrator.*/
#define  PMM_failed_to_set_attrs_values_on_cba0apprsearchcrtpmmquery                                        (EMH_USAGEWC_error_base + 141)

/**The attributes could not be set on "%1$" Product Master Management Query. Please contact your system administrator.*/
#define  PMM_failed_to_set_attributes_on_bo                                                                 (EMH_USAGEWC_error_base + 142)

/**The attribute values could not be set on Search criterion Product Master Management Query. Please contact your system administrator.*/
#define  PMM_failed_to_set_attribute_values_on_apprsearchcrtpmmquery                                        (EMH_USAGEWC_error_base + 143)

/**The Recipe information container could not be deleted. Check the system log for more information.*/
#define  PMM_failed_to_delete_container                                                                     (EMH_USAGEWC_error_base + 144)

/**The creation or updation of Search criterion operation has failed. Check the system log for more information.*/
#define PMM_appr_search_criterion_create_update_failed                                                      (EMH_USAGEWC_error_base + 145)

/**Retrieving the Search criteria has failed. Check the system log for more information.*/
#define PMM_get_appr_search_criterion_failed                                                                (EMH_USAGEWC_error_base + 146)

/**The selected designs are not owned by this site.*/
#define PMM_design_from_non_owning_site                                                                     (EMH_USAGEWC_error_base + 147)

/** All or some of the Drawings aligned to the selected Part are not owned by this site.*/
#define PMM_drawings_from_non_owning_site                                                                   (EMH_USAGEWC_error_base + 148)

/**The Occurrence path creation is disallowed if the root node is a remote item. To create the Occurrence path, remote check-out the BOM View or perform an ownership transfer on the root item "%1$".*/
#define PMM_find_appearance_path_node_failed_for_replica                                                    (EMH_USAGEWC_error_base + 149)

/**The publish operation is not allowed on "%1$" because it is a remote item. To publish, perform an ownership transfer on the item or publish from the owning site.*/
#define PMM_remote_item_not_allowed_for_publish                                                             (EMH_USAGEWC_error_base + 150)

/**The "Object List" creation has failed. Please contact your system administrator.*/
#define PMM_failed_while_setting_cba0object_type_and_cba0object_list                                        (EMH_USAGEWC_error_base + 151)

/**The Structure Context object creation has failed. Please contact your system administrator.*/
#define PMM_failed_while_setting_cba0plmxml_file_cba0snapshot_type_cba0pmm_service_name_and_context_name    (EMH_USAGEWC_error_base + 152)

/**The "Object List Selection State" object creation has failed. Please contact your system administrator.*/
#define PMM_failed_while_setting_cba0selected_list_and_cba0unselected_list                                  (EMH_USAGEWC_error_base + 153)

/**The "Add to Layout" operation has failed due to an invalid input.*/
#define  PMM_empty_input_for_add_to_layout                                                                  (EMH_USAGEWC_error_base + 154)

/**The "Add to Layout" operation has failed. The input layout "Item Revision" already has a BOM View Revision with improper precision.*/
#define  PMM_improper_precision_of_bvr_for_add_to_layout                                                    (EMH_USAGEWC_error_base + 155)

/**Retrieving the PLMXML static structure file from the Structure Context object operation has failed.*/
#define  PMM_get_plmxml_static_structure_file_from_pmmsco_failed                                            (EMH_USAGEWC_error_base + 156)

/**The Structure Context object contains an empty search criterion.*/
#define  PMMSCO_empty_search_criterion                                                                      (EMH_USAGEWC_error_base +   157)

/**The Structure Context object contains an invalid search criterion.*/
#define  PMMSCO_invalid_search_criterion                                                                    (EMH_USAGEWC_error_base +   158)

/**The following file could not be opened: %1$.*/
#define  PMMSCO_unable_to_open_file                                                                         (EMH_USAGEWC_error_base +   159)

/**The "Save" or "Clone" operation of the Structure Context object has failed.*/
#define  PMM_save_or_clone_of_pmmsco_failed                                                                 (EMH_USAGEWC_error_base +   160)

/**Retrieving the Structure Context object information operation has failed.*/
#define  PMM_get_pmmsco_info_failed                                                                         (EMH_USAGEWC_error_base +   161)

/**This operation is not supported on the top line of a structure.*/
#define  PMM_operation_not_supported_on_topline                                                             (EMH_USAGEWC_error_base +   162)

/**The Product Master Management "Create object" operation has failed while creating the object "%1$".*/
#define  PMM_object_creation_failed                                                                         (EMH_USAGEWC_error_base +   163)

/**The Product Master Management "Add to Layout" operation has failed.*/
#define  PMM_add_to_layout_failed                                                                           (EMH_USAGEWC_error_base +   164)

/**Details of all the CAD Occurrences aligned to the Solutions could not be retrieved. The CAD Occurrences may not be owned by this site.*/
#define  PMM_failed_get_bomline_details                                                                     (EMH_USAGEWC_error_base +   165)

/**The Solution "%1$" does not have any aligned design.*/
#define  PMM_solution_no_align                                                                              (EMH_USAGEWC_error_base +   166)

/**An effective point or date must be specified.*/
#define  PMM_effectivity_point_date_not_specified                                                           (EMH_USAGEWC_error_base +   167)

/**The "Save" operation has failed, because an object of name "%1$" already exists in the database. Give a unique name for the Structure Context.*/
#define  PMM_sco_name_not_unique                                                                            (EMH_USAGEWC_error_base +   168)

/**Details of all the CAD Occurrences aligned to Assembly Component Tree component could not be retrieved. The CAD Occurrences may not be owned by this site.*/
#define  PMM_failed_get_act_bomline_details                                                                 (EMH_USAGEWC_error_base +   169)

/**The "Update BOM View Revision from Product Master Management" operation has failed due to an invalid input.*/
#define  PMM_update_bvr_from_pmm_failed                                                                     (EMH_USAGEWC_error_base +   170)

/**The "Processing of BOM Lines during refresh from Product Master Management" operation has failed due to an invalid input.*/
#define  PMM_processing_of_bomlines_failed                                                                  (EMH_USAGEWC_error_base +   171)

/**The "Attaching the design items during refresh from Product Master Management" operation has failed due to an invalid input.*/
#define  PMM_attach_design_item_failed                                                                      (EMH_USAGEWC_error_base +   172)

/**The GSOAP operation has failed to get a response from the Product Master Management Usage server.\n
The Product Master Management Usage server may not be running, or there may be a problem with network connectivity to the host on which the Product Master Management Usage server runs.\n
Please contact your system administrator for assistance.*/
#define  PMM_gsoap_failed_to_get_response                                                                   (EMH_USAGEWC_error_base +   173)

/**The scope of the top node could not be retrieved. Check the Teamcenter server system log file for more information.*/
#define  PMM_failed_to_find_scope                                                                           (EMH_USAGEWC_error_base +   174)

/**A Model must be provided.*/
#define  PMM_validate_spatial_search_request_failed_for_model                                               (EMH_USAGEWC_error_base +   175)

/**An Expression must be provided.*/
#define  PMM_validate_spatial_search_request_failed_for_expression                                          (EMH_USAGEWC_error_base +   176)

/**The run-time properties of the PMM (Product Master Management) object of type "%1$" and identifier "%2$" cannot be loaded from the PMM server. Please contact your system administrator.*/
#define  PMM_load_runtime_properties_failed                                                                 (EMH_USAGEWC_error_base +   177)

/**An effective stream must be specified.*/
#define  PMM_effectivity_stream_not_specified                                                               (EMH_USAGEWC_error_base +   178)

/**The scope of the top node cannot be deleted once the "Refresh from PMM" operation is performed.*/
#define  PMM_failed_to_delete_scope                                                                         (EMH_USAGEWC_error_base +   179)

/** The Product Master Management query resulted with zero occurrences for the given criteria. */
#define PMM_query_no_occurrence                                                                             (EMH_USAGEWC_error_base +   180)

/** The Product Master Management Recipe information is not provided on any of the input Item Revisions. */
#define PMM_failed_to_find_recipe                                                                           (EMH_USAGEWC_error_base +   181)

/**The Teamcenter query did not find all the items for given scope and recipe. Create the missing items with the same names as the Product Master Management parts.*/
#define PMM_failed_to_find_teamcenter_items                                                                 (EMH_USAGEWC_error_base +   182)
/** @} */

#endif
