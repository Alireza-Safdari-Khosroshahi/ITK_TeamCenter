/* =================================================================================================
           Copyright (c) 1999,2000,2001,2003 Unigraphics Solutions Inc., An EDS Company
                   Unpublished - All rights reserved

   THIS PROGRAM IS AN UNPUBLISHED WORK FULLY PROTECTED BY THE UNITED STATES
  COPYRIGHT LAWS AND IS CONSIDERED A TRADE SECRET BELONGING TO THE COPYRIGHT
                                   HOLDER.
====================================================================================================*/

/**
    @file

    Errors for the soa cad services


*/

/** @if HISTORY_SECTION
====================================================================================================
23-Mar-2006  Ron Brickley         Error codes for soacad
28-Mar-2006  pmbrickl                Error listings for cad services
31-Mar-2006  gexu                    Code for createOrUpdateRelativeStructure
03-Apr-2006  x_chanda                Updates to soa cad error handling
05-Apr-2006  Stan Sharpe             Add new error message for createOrUpdateParts
11-Apr-2006  Stan Sharpe             Code for createOrUpdateAbsoluteStructure, CreateBOMWindows, CloseBOMWindow
11-Apr-2006  Stan Sharpe             Add new error msg
11-Apr-2006  gexu                    Code for createOrUpdateAbsoluteStructure, CreateBOMWindows, CloseBOMWindow
13-Apr-2006  peschell                initial delete relative occurrences service errors/warnings
19-Apr-2006  Stan Sharpe             Add new error code
20-Apr-2006  peschell                additional delete relative occurrence service error codes
27-Apr-2006  Stan Sharpe             Add error code for createOrUpdateRelations
15-Sep-2006  Kishore Pattnaik        Fix for PR # 5590489 for all the expand services
13-Sep-2006  pmbrickl                backport of CAD Services from TC2007
15-Sep-2006  pmbrickl                additional CAD Services backport
28-Sep-2006  pmbrickl                add error codes for backport
05-Nov-2006  pmbrickl                additional backport from TC2007 for CAD Services
08-Jan-2007  pmbrickl                backport from TC2007
16-Jan-2007  x_chanda                Added 0706 iPEM
19-Jan-2007  x_chanda                Incorporate the review comments
24-Jan-2007  x_chanda                Incorporate the review comments
25-Jan-2007  x_chanda                Added SOACAD_get_configuredItemRev_failed error string
19-Feb-2007  pmbrickl                add attribute mapping errors
01-Mar-2007  pesharpe                Make updates to createOrUpdateParts
02-Mar-2007  pesharpe                PR 5704440 Add support for attirbutes on forms for item and item revision
11-Mar-2007  pmbrickl                merge from developer branch
25-Nov-2007  Ashok C                 Add error code for datamanagement0712impl
01-Jul-2008  Charles Cheng           Add error code for internaldatamanagement0805impl
17-Aug-2009  Kishore Pattnaik        Fix for PR # 6180644 : Supress duplicate context error # 7.
$HISTORY$
==================================================================================================
@endif */

#ifndef SOACAD_ERRORS_H
#define SOACAD_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SOACAD_ERRORS TCWS Errors
    @ingroup SOACAD
    @{
*/

/** CAD Integration Services error code definitions: */

/** NOTE: The error numbers assigned in this file must match those in the soacad_errors.xml file **/

/** CreateOrUpdateRelativeOccurrence Service (0 - 19) **/

#define SOACAD_invalid_bomview_type                 (EMH_SOACAD_error_base +   0 )
#define SOACAD_bvr_precision_mismatch               (EMH_SOACAD_error_base +   1 )
#define SOACAD_bomline_for_absocc_not_found         (EMH_SOACAD_error_base +   2 )
#define SOACAD_used_arrangement_not_created         (EMH_SOACAD_error_base +   3 )
#define SOACAD_bomline_not_found                    (EMH_SOACAD_error_base +   4 )
#define SOACAD_bvr_not_checkedout                   (EMH_SOACAD_error_base +   5 )
#define SOACAD_bvr_checked_out_by_another_user      (EMH_SOACAD_error_base +   6 )
#define SOACAD_duplicate_parent_exists              (EMH_SOACAD_error_base +   8 )
#define SOACAD_item_type_does_not_exist             (EMH_SOACAD_error_base +   9 )
#define SOACAD_invalid_cadoccid                     (EMH_SOACAD_error_base +   10 )
/** The source node data for the "move" operation cannot be null. Please report this error to your system administrator. */
#define SOACAD_move_invalid_source_node             (EMH_SOACAD_error_base +   11 )
/** The target parent data for the "move" operation cannot be null. Please report this error to your system administrator. */
#define SOACAD_move_invalid_target_parent           (EMH_SOACAD_error_base +   12 )
/** The BOM Line corresponding to the "move" target node "%1$" could not be found. */
#define SOACAD_move_target_node_not_found           (EMH_SOACAD_error_base +   13 )
/** The BOM Line corresponding to the input Occurrence Thread Equivalent ID "%1$" could not be found. */
#define SOACAD_move_bomline_not_found               (EMH_SOACAD_error_base +   14 )


/** CreateOrUpdateParts Service (20 - 39) **/

#define SOACAD_dataset_checked_out_by_another_user  (EMH_SOACAD_error_base +  20 )
#define SOACAD_item_tag_not_match_item_revision     (EMH_SOACAD_error_base +  21 )
#define SOACAD_null_return_from_ask_type            (EMH_SOACAD_error_base +  22 )
#define SOACAD_null_return_from_create_item         (EMH_SOACAD_error_base +  23 )
#define SOACAD_null_return_from_create_form         (EMH_SOACAD_error_base +  24 )
#define SOACAD_null_return_from_create_relation     (EMH_SOACAD_error_base +  25 )
#define SOACAD_null_return_from_create_dataset      (EMH_SOACAD_error_base +  26 )
#define SOACAD_null_return_from_default_folder      (EMH_SOACAD_error_base +  27 )
#define SOACAD_null_return_from_find_relation       (EMH_SOACAD_error_base +  28 )
#define SOACAD_must_supply_named_reference_name     (EMH_SOACAD_error_base +  29 )
#define SOACAD_dataset_not_checkedout               (EMH_SOACAD_error_base +  30 )
#define SOACAD_dataset_default_tool_not_exist       (EMH_SOACAD_error_base +  31 )
#define SOACAD_related_form_object_not_found        (EMH_SOACAD_error_base +  32 )
#define SOACAD_last_modified_date_changed           (EMH_SOACAD_error_base +  33 )
#define SOACAD_overwrite_with_modified_date         (EMH_SOACAD_error_base +  34 )
#define SOACAD_null_input_for_object_type_name      (EMH_SOACAD_error_base +  35 )

/** DeleteRelativeOccurrence Service (40 - 49) **/

#define SOACAD_sm_dro_itemrev_invalid_tag          (EMH_SOACAD_error_base +  40 )
#define SOACAD_sm_dro_parent_not_itemrev           (EMH_SOACAD_error_base +  41 )
#define SOACAD_sm_dro_item_not_found               (EMH_SOACAD_error_base +  42 )
#define SOACAD_sm_dro_bvr_not_found                (EMH_SOACAD_error_base +  43 )
#define SOACAD_sm_dro_bv_not_found                 (EMH_SOACAD_error_base +  44 )
#define SOACAD_sm_dro_child_invalid_tag            (EMH_SOACAD_error_base +  45 )
#define SOACAD_sm_dro_no_occ_spec                  (EMH_SOACAD_error_base +  46 )
#define SOACAD_sm_dro_no_occ_to_delete             (EMH_SOACAD_error_base +  47 )
#define SOACAD_sm_dro_child_not_found              (EMH_SOACAD_error_base +  48 )

/** CreateOrUpdateRelations Service (50 - 59) **/

#define SOACAD_null_return_from_find_relation_type  (EMH_SOACAD_error_base +  50 )
#define SOACAD_primary_object_tag_invalid           (EMH_SOACAD_error_base +  51 )
#define SOACAD_secondary_object_tag_invalid         (EMH_SOACAD_error_base +  52 )
#define SOACAD_user_data_tag_invalid                (EMH_SOACAD_error_base +  53 )
#define SOACAD_relation_tag_invalid                 (EMH_SOACAD_error_base +  54 )
#define SOACAD_relation_already_exists              (EMH_SOACAD_error_base +  55 )

/** ExpandPrimaryObjects Service (60 - 69) **/

#define SOACAD_null_preference_filters              (EMH_SOACAD_error_base +  60 )
#define SOACAD_dm_epo_invalid_object                (EMH_SOACAD_error_base +  62 )

/** CAD Attribute Mapping Services (70 - 119) **/

#define SOACAD_dm_am_unknown_ds_type_name           (EMH_SOACAD_error_base +  70 )
#define SOACAD_dm_am_unknown_item_type_name         (EMH_SOACAD_error_base +  71 )
#define SOACAD_dm_am_list_all_mappings_failed       (EMH_SOACAD_error_base +  72 )
#define SOACAD_dm_am_list_mappings_failed           (EMH_SOACAD_error_base +  73 )

#define SOACAD_dm_am_dataset_invalid_tag            (EMH_SOACAD_error_base +  74 )
#define SOACAD_dm_am_itemrev_invalid_tag            (EMH_SOACAD_error_base +  75 )
#define SOACAD_dm_am_mapping_def_invalid_tag        (EMH_SOACAD_error_base +  76 )
#define SOACAD_dm_am_ask_mapping_title_failed       (EMH_SOACAD_error_base +  77 )
#define SOACAD_dm_am_ask_mapping_dstype_failed      (EMH_SOACAD_error_base +  78 )
#define SOACAD_dm_am_ask_dstype_name_failed         (EMH_SOACAD_error_base +  79 )
#define SOACAD_dm_am_ask_mapping_itemtype_failed    (EMH_SOACAD_error_base +  80 )
#define SOACAD_dm_am_ask_itemtype_name_failed       (EMH_SOACAD_error_base +  81 )

#define SOACAD_dm_am_ask_mapping_string_failed      (EMH_SOACAD_error_base +  82 )
#define SOACAD_dm_am_empty_mapping_string           (EMH_SOACAD_error_base +  83 )
#define SOACAD_dm_am_ask_dataset_failed             (EMH_SOACAD_error_base +  84 )
#define SOACAD_dm_am_resolve_failed                 (EMH_SOACAD_error_base +  85 )
#define SOACAD_dm_am_resolve_with_ir_failed         (EMH_SOACAD_error_base +  86 )
#define SOACAD_dm_am_resolved_no_object_to_lock     (EMH_SOACAD_error_base +  87 )
#define SOACAD_dm_am_resolved_no_property_object    (EMH_SOACAD_error_base +  88 )
#define SOACAD_dm_am_resolved_get_prop_name_failed  (EMH_SOACAD_error_base +  89 )
#define SOACAD_dm_am_resolved_invalid_prop_name     (EMH_SOACAD_error_base +  90 )
#define SOACAD_dm_am_unknown_attr_mapping_type      (EMH_SOACAD_error_base +  91 )

#define SOACAD_dm_am_get_item_type_failed           (EMH_SOACAD_error_base +  92 )
#define SOACAD_dm_am_empty_attr_name                (EMH_SOACAD_error_base +  93 )
#define SOACAD_dm_am_empty_attr_value               (EMH_SOACAD_error_base +  94 )
#define SOACAD_dm_am_get_hard_coded_failed          (EMH_SOACAD_error_base +  95 )
#define SOACAD_dm_am_get_cad_master_failed          (EMH_SOACAD_error_base +  96 )
#define SOACAD_dm_am_get_modifiable_failed          (EMH_SOACAD_error_base +  97 )
#define SOACAD_dm_am_lock_failed                    (EMH_SOACAD_error_base +  98 )
#define SOACAD_dm_am_set_value_failed               (EMH_SOACAD_error_base +  99 )
#define SOACAD_dm_am_save_dataset_failed            (EMH_SOACAD_error_base + 100 )
#define SOACAD_dm_am_save_object_failed             (EMH_SOACAD_error_base + 101 )
#define SOACAD_dm_am_unsupported_attr_mapping_type  (EMH_SOACAD_error_base + 102 )

#define SOACAD_dm_am_resolve_const_not_supported    (EMH_SOACAD_error_base + 103 )
#define SOACAD_dm_am_resolve_pref_not_supported     (EMH_SOACAD_error_base + 104 )

/** Asking if the mapping is a one-to-many master failed (%1$). */
#define SOACAD_dm_am_ask_mapping_one_to_many_master_failed (EMH_SOACAD_error_base + 105 )

#define SOACAD_dm_am_alloc_mem_failed               (EMH_SOACAD_error_base + 110 )
#define SOACAD_dm_am_get_prop_value_type_failed     (EMH_SOACAD_error_base + 111 )
#define SOACAD_dm_am_set_values_failed              (EMH_SOACAD_error_base + 112 )
#define SOACAD_dm_am_get_max_string_len_failed      (EMH_SOACAD_error_base + 113 )
#define SOACAD_dm_am_get_max_num_elem_failed        (EMH_SOACAD_error_base + 114 )
#define SOACAD_dm_am_unsupported_max_num_elem       (EMH_SOACAD_error_base + 115 )
#define SOACAD_dm_am_unsupported_prop_value_type    (EMH_SOACAD_error_base + 116 )

#define SOACAD_dm_am_ask_propdesc                   (EMH_SOACAD_error_base + 117 )
#define SOACAD_dm_am_ask_lov                        (EMH_SOACAD_error_base + 118 )
#define SOACAD_dm_am_no_datasetoritemrev_tag        (EMH_SOACAD_error_base + 119 )

#define SOACAD_conflict_datasetInfo_input            (EMH_SOACAD_error_base + 120 )

/** ExpandFoldersForCAD Service (120 - 129) **/

#define SOACAD_dm_efl_invalid_folder                (EMH_SOACAD_error_base +  121 )

/** ExpandGRMs Service (130 - 139) **/

#define SOACAD_dm_egr_invalid_object                (EMH_SOACAD_error_base +  131 )

/** CreateOrUpdateAbsoluteStructure Service (140 - 149) **/

#define SOACAD_sm_abs_cadoccidpath_not_specified    (EMH_SOACAD_error_base +  140 )
#define SOACAD_sm_abs_cadoccidpath_direct_child     (EMH_SOACAD_error_base +  141 )
#define SOACAD_sm_abs_override_already_exists       (EMH_SOACAD_error_base +  142 )

/** getConfiguredItemRevision Service (150 - 159) **/

#define SOACAD_get_configuredItemRev_failed         (EMH_SOACAD_error_base + 150)

/** create update and delete variant condition and option (160 - 169) **/

#define SOACAD_invalidOperation                     (EMH_SOACAD_error_base + 160)
#define SOACAD_varCond_invalidVarExprBlock          (EMH_SOACAD_error_base + 161)
#define SOACAD_itemrev_not_found                    (EMH_SOACAD_error_base + 162)
#define SOACAD_option_not_valid                     (EMH_SOACAD_error_base + 163)
#define SOACAD_unmatched_bracket                    (EMH_SOACAD_error_base + 164)

#define SOACAD_exportConfiguredNXAssembly_failed    (EMH_SOACAD_error_base + 165)
#define SOACAD_failed_to_save_bomwindow             (EMH_SOACAD_error_base + 166)

/** AskChildPathBomLines Service (170 - 189) **/

#define SOACAD_not_supported                        (EMH_SOACAD_error_base + 170 )
#define SOACAD_sm_acpbl_reserved                    (EMH_SOACAD_error_base + 171 )
#define SOACAD_sm_acpbl_no_child_paths              (EMH_SOACAD_error_base + 172 )
#define SOACAD_sm_acpbl_empty_child_path            (EMH_SOACAD_error_base + 173 )
#define SOACAD_sm_acpbl_psoccthread_not_found       (EMH_SOACAD_error_base + 174 )
#define SOACAD_sm_acpbl_psoccthread_no_bomline      (EMH_SOACAD_error_base + 175 )
#define SOACAD_sm_acpbl_psoccthread_mult_bomlines   (EMH_SOACAD_error_base + 176 )
/* in use, unrelated to this operation              (EMH_SOACAD_error_base + 177 ) */
#define SOACAD_sm_acpbl_get_clone_stable_bl_failed  (EMH_SOACAD_error_base + 178 )
/* No parent BOM Line of ID "%2$" can be found for the input number "%1$".*/
#define SOACAD_sm_acpbl_parentbomline_is_null       (EMH_SOACAD_error_base + 179 )

#define SOACAD_empty_mappingAttributes              (EMH_SOACAD_error_base + 177 )

/** InternalEnquiry Service (190 - 199) **/

#define SOACAD_item_not_found                        (EMH_SOACAD_error_base + 190 )
#define SOACAD_revision_not_found                    (EMH_SOACAD_error_base + 191 )
#define SOACAD_item_uid_or_id_not_specified          (EMH_SOACAD_error_base + 192 )
#define SOACAD_item_revision_uid_or_id_not_specified (EMH_SOACAD_error_base + 193 )
#define SOACAD_display_rule_not_specified            (EMH_SOACAD_error_base + 194 )
#define SOACAD_display_rule_not_found                (EMH_SOACAD_error_base + 195 )
#define SOACAD_item_alternate_id_not_found           (EMH_SOACAD_error_base + 196 )
#define SOACAD_item_revision_alternate_id_not_found  (EMH_SOACAD_error_base + 197 )

/** Generic SOA CAD errors  (200 - 209) **/
#define SOACAD_invalid_clientId                     (EMH_SOACAD_error_base + 200)
#define SOACAD_duplicate_clientId                   (EMH_SOACAD_error_base + 201)
#define SOACAD_failure_to_initialize_module         (EMH_SOACAD_error_base + 202)

/** queryRelatedFeatures Service (220 - 229) **/

#define SOACAD_input_mismatch                       (EMH_SOACAD_error_base + 220)
#define SOACAD_empty_clientID                       (EMH_SOACAD_error_base + 221)
#define SOACAD_missing_gdeocc_itemrev               (EMH_SOACAD_error_base + 222)

/** internaldatamanagement0805impl for NX-specific attr sync SOA errors  (230 - 249) **/

#define SOACAD_NXTC__is_mapped_prop_modifiable_err  (EMH_SOACAD_error_base + 230)
#define SOACAD_prop_ask_property_by_name_err        (EMH_SOACAD_error_base + 231)
#define SOACAD_prop_is_modifiable_err               (EMH_SOACAD_error_base + 232)
#define SOACAD_ae_ask_dataset_err                   (EMH_SOACAD_error_base + 233)
#define SOACAD_am_check_privilege_err               (EMH_SOACAD_error_base + 234)
#define SOACAD_wsom_ask_status_err                  (EMH_SOACAD_error_base + 235)
#define SOACAD_attrmap_ask_mapping_freezable_err    (EMH_SOACAD_error_base + 236)
#define SOACAD_attrmap_ask_mapping_cad_master_err   (EMH_SOACAD_error_base + 237)
#define SOACAD_attrmap_ask_mapping_write_once_err   (EMH_SOACAD_error_base + 238)
#define SOACAD_attrmap_ask_mapping_map_type_err     (EMH_SOACAD_error_base + 239)
#define SOACAD_attrmap_ask_constant_err             (EMH_SOACAD_error_base + 240)
#define SOACAD_attrmap_ask_preference_err           (EMH_SOACAD_error_base + 241)
#define SOACAD_pref_ask_char_value_err              (EMH_SOACAD_error_base + 244)

#define SOACAD_unable_to_create_variantrule         (EMH_SOACAD_error_base + 251)
#define SOACAD_no_input_for_relationname            (EMH_SOACAD_error_base + 253)
#define SOACAD_unable_to_associate_variantrulewithparent    (EMH_SOACAD_error_base + 254)
#define SOACAD_invalid_variant_rule_name            (EMH_SOACAD_error_base + 255 )
#define SOACAD_invalid_item_revision                (EMH_SOACAD_error_base + 256 )
#define SOACAD_invalid_input_is_null                (EMH_SOACAD_error_base + 257 )

/** saveAsNewItem - SOA errors - internaldatamanagement1004impl  (260 - 279) **/

#define SOACAD_dm_unsupported_named_reference_object        (EMH_SOACAD_error_base + 260 )
#define SOACAD_dm_null_otherSideObject_newName_input        (EMH_SOACAD_error_base + 262 )
#define SOACAD_dm_input_itemid_already_exists               (EMH_SOACAD_error_base + 263 )
#define SOACAD_dm_no_master_form_props_input                (EMH_SOACAD_error_base + 264 )
#define SOACAD_dm_null_returned_from_copy_dataset           (EMH_SOACAD_error_base + 265 )
#define SOACAD_dm_invalid_deepCopy_otherSideObject          (EMH_SOACAD_error_base + 266 )
#define SOACAD_dm_null_returned_from_copy_form              (EMH_SOACAD_error_base + 267 )
#define SOACAD_dm_deepCopy_otherSideObject_not_supported    (EMH_SOACAD_error_base + 268 )
#define SOACAD_dm_null_returned_from_create_form            (EMH_SOACAD_error_base + 269 )
#define SOACAD_dm_invalid_master_form_input                 (EMH_SOACAD_error_base + 270 )
#define SOACAD_dm_null_master_form                          (EMH_SOACAD_error_base + 271 )
#define SOACAD_dm_null_retuned_from_create_relation         (EMH_SOACAD_error_base + 272 )
#define SOACAD_dm_namedRef_not_deleted                      (EMH_SOACAD_error_base + 273 )
#define SOACAD_dm_namedRef_not_updated                      (EMH_SOACAD_error_base + 274 )
#define SOACAD_dm_deepCopy_action_not_supported             (EMH_SOACAD_error_base + 275 )
#define SOACAD_dm_deepCopy_namedRef_action_not_supported    (EMH_SOACAD_error_base + 276 )
#define SOACAD_dm_named_reference_not_found                 (EMH_SOACAD_error_base + 277 )
#define SOACAD_dm_multiple_named_references_found           (EMH_SOACAD_error_base + 278 )
#define SOACAD_dm_form_properties_and_copy_specified        (EMH_SOACAD_error_base + 279 )

/** itemCreateUtil - SOA errors -  (280 - 289) **/

#define SOACAD_attribute_does_not_exist                     (EMH_SOACAD_error_base + 280 )

/** queryPartRelatedFeatures - SOA errors -  (290 - 299) **/
/** The Note type "%1$" does not exist. Please contact your system administrator to report this error. */
#define SOACAD_note_type_does_not_exist                     (EMH_SOACAD_error_base + 290 )
/** The related Appearence Path Node object for the Item Revision "%1$" was not found. Please contact your system administrator to report this error. */
#define SOACAD_related_APN_not_found                        (EMH_SOACAD_error_base + 291 )
/** The related Absolute Occurrence for the Item Revision "%1$" was not found. Please contact your system administrator to report this error. */
#define SOACAD_related_abs_occ_not_found                    (EMH_SOACAD_error_base + 292 )
/** The related Absolute Occurrence Data for the Item Revision "%1$" was not found. Please contact your system administrator to report this error. */
#define SOACAD_related_abs_occ_data_not_found               (EMH_SOACAD_error_base + 293 )
/** The related Feature Form for the Item Revision "%1$" was not found. Please contact your system administrator to report this error. */
#define SOACAD_related_feature_form_not_found               (EMH_SOACAD_error_base + 294 )

/** Multiple stored option sets are not allowed in the input of the SOA operation.
    Please contact your system administrator to report this error. */
#define SOACAD_multiple_stored_option_set_input              (EMH_SOACAD_error_base + 295 )






/** 
    @name Model View Proxy errors
    @{
*/
/** The service operation "%1$" request has no input. */
#define SOACAD_invalid_request_error                         (EMH_SOACAD_error_base + 300 )

/** The input parameter "%1$" contains an invalid value: %2$.*/
#define SOACAD_invalid_parameter_error                       (EMH_SOACAD_error_base + 301 )

/** The required parameter "%1$" is not specified on the request. */
#define SOACAD_missing_parameter_error                       (EMH_SOACAD_error_base + 302 )

/** Only the update of the object "%1$" was done, because the object was requested to be both deleted and updated.*/
#define SOACAD_mvproxy_delete_with_update_error              (EMH_SOACAD_error_base + 303 )

/** Another transaction is holding the object "%1$". Refresh the object and try again. */
#define SOACAD_unable_to_lock_error                          (EMH_SOACAD_error_base + 304 )

/** An error has occurred while creating an object of type "%1$". */
#define SOACAD_unable_to_create_object_error                 (EMH_SOACAD_error_base + 305 )

/** The option "%1$" is set to "true", which requires that the parameter "%2$" be specified on the request. */
#define SOACAD_option_to_require_disclosure_error            (EMH_SOACAD_error_base + 306 )

/** The product structure arrangement could not be retrieved because either an invalid or no input was provided in the list "%1$". */
#define SOACAD_invalid_input_to_getproductstructurearrangement (EMH_SOACAD_error_base + 310 )

/** An error has occurred while retrieving the arrangement data for the structure "%1$". Please contact your system administrator for more information. */
#define SOACAD_error_retrieving_arrangement_data             (EMH_SOACAD_error_base + 311 )

/** An error has occurred while retrieving the product structure arrangement data. Please contact your system administrator for more information. */
#define SOACAD_error_in_getproductstructurearrangement       (EMH_SOACAD_error_base + 312 )

/** @} */

/** 
    @name Session errors
    @{
*/
/** AppSession - SOA errors -  (400 - 499) **/


/** The object type "%1$" is not a valid Session object type. The object type must be a "Session" type or its sub-type.*/
#define SOACAD_appsess_invalid_session_type                          (EMH_SOACAD_error_base + 400 )

/** The object instance "%1$" is not a valid session object instance. The type of the object instance must be a "Session" type.*/
#define SOACAD_appsess_invalid_session_object                        (EMH_SOACAD_error_base + 401 )

/** The object with stable ID "%1$" is not associated to the application Session object. */
#define SOACAD_appsess_object_with_matching_stable_id_not_found      (EMH_SOACAD_error_base + 402 )

/** The product %1$" is an invalid product structure object. The valid objects are StructureContext, BOM Window, BOM Line, Item, Item Revision and PSBOMViewRevision. */
#define SOACAD_appsess_invalid_product_structure_object              (EMH_SOACAD_error_base + 403 )

/** The service operation "createOrUpdateSavedSession" is not supported. Please report this error to your system administrator. */
#define SOACAD_appsess_create_or_update_not_supported                (EMH_SOACAD_error_base + 404 )

/** @} */

/** @} */

#endif
