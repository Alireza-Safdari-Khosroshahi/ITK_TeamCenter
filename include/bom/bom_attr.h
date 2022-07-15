/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Tokens and types associated with BOM's handling of attributes.
*/

/*  */

#ifndef BOM_ATTR_H
#define BOM_ATTR_H

#include <bom/libbom_exports.h>

/**
    @defgroup BOM_ATTR Attributes
    @ingroup BOM
    @{
*/

/**
    Attribute modes -- note that string should not be subject to translation (eg a person's name),
    but string_intl should be (eg a process name)
*/
typedef enum {
    BOM_attribute_mode_string,
    BOM_attribute_mode_string_intl,
    BOM_attribute_mode_logical,
    BOM_attribute_mode_int,
    BOM_attribute_mode_tag,
    BOM_attribute_mode_double
} BOM_attribute_mode_t;

/**
    @name Class tokens
    @{
*/
#define  bomClass_item                      "Item"
#define  bomClass_itemRev                   "Item Revision"
#define  bomClass_bvr                       "BOMView Revision"
#define  bomClass_occurrence                "Occurrence"
#define  bomClass_line                      "BOMLine"
/** @} */

/**
    @name Attribute tokens

    Note that these are the attribute names,
    the user-name values comes via TC_text
    @{
*/
#define  bomAttr_itemId                     "bl_item_item_id"
#define  bomAttr_itemName                   "bl_item_object_name"
#define  bomAttr_itemDesc                   "bl_item_object_desc"
#define  bomAttr_itemType                   "bl_item_object_type"
#define  bomAttr_itemUom                    "bl_item_uom_tag"
#define  bomAttr_itemRevId                  "bl_rev_item_revision_id"
#define  bomAttr_itemRevName                "bl_rev_object_name"
#define  bomAttr_itemRevDesc                "bl_rev_object_desc"
#define  bomAttr_itemRevStatus              "bl_rev_release_status_list"
#define  bomAttr_itemRevStage               "bl_rev_process_stage"
#define  bomAttr_itemRevVariants            "bl_rev_has_variants"
#define  bomAttr_viewType                   "bl_view_type"
#define  bomAttr_occSeqNo                   "bl_sequence_no"
#define  bomAttr_occQty                     "bl_quantity"
#define  bomAttr_occSource                  "bl_part_source"
#define  bomAttr_occUoM                     "bl_uom"
#define  bomAttr_refDesignator              "bl_ref_designator"
#define  bomAttr_occPosRef                  "bl_pos_ref"
#define  bomAttr_occAllNotes                "bl_all_notes"
#define  bomAttr_absOccAllNVEs              "bl_all_nves"
#define  bomAttr_occName                    "bl_occurrence_name"
#define  bomAttr_lineName                   "bl_line_name"
#define  bomAttr_linePrecise                "bl_is_precise"
#define  bomAttr_lineHasChildren            "bl_has_children"
#define  bomAttr_lineIsPacked               "bl_is_packed"
#define  bomAttr_linePackCount              "bl_pack_count"
#define  bomAttr_lineParentTag              "bl_parent"
#define  bomAttr_lineItemTag                "bl_item"
#define  bomAttr_lineItemRevTag             "bl_revision"
#define  bomAttr_lineBvTag                  "bl_bomview"
#define  bomAttr_lineBvrTag                 "bl_bomview_rev"
#define  bomAttr_lineGdeBvrTag              "bl_gde_bomview_rev"
#define  bomAttr_lineOccTag                 "bl_occurrence"
#define  bomAttr_lineWindowTag              "bl_window"
#define  bomAttr_lineConfigString           "bl_config_string"
#define  bomAttr_lineSubstitute             "bl_substitute"
#define  bomAttr_lineIsOccConfigured        "bl_is_occ_configured"
#define  bomAttr_lineHasDateEff             "bl_has_date_effectivity"
#define  bomAttr_lineVariantState           "bl_variant_state"
#define  bomAttr_lineVariantCondition       "bl_variant_condition"
#define  bomAttr_variantFormula             "bl_formula"
#define  bomAttr_lineCompareChange          "bl_compare_change"
#define  bomAttr_lineCompareChangeId        "bl_compare_change_id"
#define  bomAttr_lineCompareChangeInt       "bl_compare_change_int"
#define  bomAttr_lineQuantityChange         "bl_quantity_change"
#define  bomAttr_lineRevisionChange         "bl_revision_change"
#define  bomAttr_indentedTitle              "bl_indented_title"
#define  bomAttr_lineIsLastChild            "bl_is_last_child"
#define  bomAttr_occNoteTypes               "bl_note_types"
#define  bomAttr_childLines                 "bl_child_lines"
#define  bomAttr_packedLines                "bl_packed_lines"
#define  bomAttr_numChildren                "bl_num_children"
#define  bomAttr_quickNumChildren           "bl_quick_num_children"
#define  bomAttr_lineConditionTag           "bl_condition_tag"
#define  bomAttr_hasSubstitutes             "bl_has_substitutes"
#define  bomAttr_hasGlobalAlternates        "bl_has_global_alternates"
#define  bomAttr_isVariant                  "bl_is_variant"
#define  bomAttr_AbsTransformMatrix         "bl_abs_xform_matrix"
#define  bomAttr_OccTransformMatrix         "bl_occ_xform_matrix"
#define  bomAttr_StandardAbsTransform       "bl_plmxml_abs_xform"
#define  bomAttr_StandardOccTransform       "bl_plmxml_occ_xform"
#define  bomAttr_DefaultAbsTransform        "bl_plmxml_def_abs_xform"
#define  bomAttr_DefaultOccTransform        "bl_plmxml_def_occ_xform"
#define  bomAttr_occurrenceUid              "bl_occurrence_uid"
#define  bomAttr_appearanceUid              "bl_appearance_uid"
#define  bomAttr_apnUid                     "bl_apn_uid_in_topline_context"
#define  bomAttr_JTDatasetTag               "bl_jt_dataset_tag"
#define  bomAttr_JTRefset                   "bl_jt_refsetname"
#define  bomAttr_JTOverrideChildren         "bl_jt_override_children"
#define  bomAttr_lineBvUid                  "bl_bomview_uid"
#define  bomAttr_isPendingCut               "bl_is_pending_cut"
#define  bomAttr_fgColourInt                "bl_fg_colour_int"
#define  bomAttr_fgColourIntAsStr           "bl_fg_colour_int_as_str"
#define  bomAttr_bgColourInt                "bl_bg_colour_int"
#define  bomAttr_bgColourIntAsStr           "bl_bg_colour_int_as_str"
#define  bomAttr_formattedIndentedTitle     "bl_formatted_title"
#define  bomAttr_formattedViewType          "bl_formatted_view_type"
#define  bomAttr_formattedOccQty            "bl_formatted_quantity"
#define  bomAttr_occurrenceDateRange        "bl_occ_date_range"
#define  bomAttr_revisionEffectivity        "bl_revision_effectivity"
#define  bomAttr_predLines                  "bl_predecessor_lines"
#define  bomAttr_occUILocation              "bl_location"
#define  bomAttr_occType                    "bl_occ_type"
#define  bomAttr_productAppearance          "bl_appearance"
#define  bomAttr_appearanceValidityIn       "bl_appearance_validity_in"
#define  bomAttr_appearanceValidityOut      "bl_appearance_validity_out"

#define  bomAttr_formattedParentName        "bl_formatted_parent_name"
#define  bomAttr_formattedAncestorName      "bl_formatted_ancestor_name"
#define  bomAttr_isSuppressed               "bl_is_suppressed"
#define  bomAttr_loadState                  "bl_load_state"
#define  bomAttr_remoteObject               "bl_remote_object"
#define  bomAttr_remoteObjPubRec            "bl_remote_obj_pub_rec"
#define  bomAttr_hasModule                  "bl_has_module"
#define  bomAttr_numPorts                   "bl_num_ports"
#define  bomAttr_lineObjectTag              "bl_line_object"
#define  bomAttr_allChildLines              "bl_all_child_lines"
#define  bomAttr_attachmentLines            "bl_attachments"
#define  bomAttr_realOccurrence             "bl_real_occurrence"
#define  bomAttr_allIces                    "bl_all_ices"
#define  bomAttr_isOccSuppressed            "bl_is_occ_suppressed"
#define  bomAttr_isOccPositionConstrained   "bl_is_occ_position_constrained"
#define  absOccAttr_ID                      "bl_abs_occ_id"
#define  bomAttr_absOccID                   "bl_abs_occ_id"
#define  bomAttr_absOccAllIDs               "bl_abs_occ_all_ids"
#define  bomAttr_networkViewerRoute         "bl_network_viewer_route"
#define  bomAttr_connectedTo                "bl_connected_lines"
#define  bomAttr_gdeAbsName                 "bl_gde_abs_name"
#define  bomAttr_realizedBy                 "bl_realizedBy_lines"
#define  bomAttr_implementedBy              "bl_implementedBy_lines"
#define  bomAttr_routedBy                   "bl_routedBy_lines"
#define  bomAttr_signalValue                "bl_signal_value"
#define  bomAttr_signalAssociatedSystem     "bl_signal_associated_system"
#define  bomAttr_signalRedundant            "bl_signal_redundant"
#define  bomAttr_signalProcessVariable      "bl_signal_process_variable"
#define  bomAttr_icList                     "bl_ic_list"
#define  bomAttr_absOccUid                  "bl_absocc_uid_in_topline_context"
#define  bomAttr_ProcessVariableValue       "bl_process_variable_value"
#define  bomAttr_occIsPrecise               "bl_occ_is_precise"
#define  bomAttr_configIcList               "bl_config_ic_list"
#define  bomAttr_lineIcState                "bl_ic_state"
#define  bomAttr_icEffectivity              "bl_ic_effectivity"
#define  bomAttr_icRelStatus                "bl_ic_release_status_list"
#define  bomAttr_icIntent                   "bl_ic_intent_list"
#define  bomAttr_connectedToAbsName         "bl_connected_to_absName"
#define  bomAttr_lineVisibleParentTag       "bl_visible_parent"
#define  bomAttr_forcedConfiguration        "bl_forced_configuration"
#define  bomAttr_lineVariantStateInt        "bl_variant_state_int"
#define  bomAttr_lineChildrenExpanded       "bl_children_expanded"
#define  bomAttr_revRuleModifier            "bl_rev_rule_modifier"
#define  bomAttr_revRuleParentModifier      "bl_rev_rule_parent_modifier"
#define  bomAttr_shownInViewer              "bl_is_shown_in_viewer"
#define  bomAttr_hasOccEffectivity          "bl_has_occ_effectivity"
#define  bomAttr_occEffectivity             "bl_occ_effectivity"
#define  bomAttr_hasLegacyOccEffectivity    "bl_has_legacy_occ_effectivity"
#define  bomAttr_hasUnifiedOccEffectivity   "bl_has_unified_occ_effectivity"
#define  bomAttr_usedArrangement            "bl_used_arrangement"
#define  bomAttr_usedArrangementName        "bl_used_arrangement_name"
#define  bomAttr_isOccSuppressionConstrained "bl_is_occ_suppression_constrained"
#define  bomAttr_positionDesignator         "bl_position_designator"
#define  bomAttr_usageAddress               "bl_usage_address"
#define  bomAttr_alignedPartOccs            "bl_aligned_part_occs"
#define  bomAttr_alignedActOccs             "bl_aligned_act_occs"
#define  bomAttr_isPublished                "bl_is_published"
#define  bomAttr_isPrevRevPublished         "bl_is_prev_rev_published"
#define  bomAttr_hasTraceLink               "bl_has_trace_link"
#define  bomAttr_fulltextBodyClearText      "bl_fulltext_body_cleartext"
#define  bomAttr_embeds                     "bl_embeds_lines"
#define  bomAttr_dependentOn                "bl_dependentOn_lines"
#define  bomAttr_gatewayOf                  "bl_gatewayOf_lines"
#define  bomAttr_embeds_tags                "bl_embeds_lines_tags"
#define  bomAttr_dependentOn_tags           "bl_dependentOn_lines_tags"
#define  bomAttr_gatewayOf_tags             "bl_gatewayOf_lines_tags"
#define  bomAttr_pendingEditStatus          "bl_pending_edit_status"
#define  bomAttr_isLinkOutOfDate            "bl_is_link_out_of_sync"
#define  bomAttr_WeldFeatureForm            "bl_weld_feature_form"
#define  bomAttr_partNumbers                "bl_part_numbers"
#define  bomAttr_cloneStableOccurrenceId    "bl_clone_stable_occurrence_id"
#define  bomAttr_isPublishLinkSource        "bl_is_publish_link_source"
#define  bomAttr_isPublishLinkTarget        "bl_is_publish_link_target"
#define  bomAttr_PublishedData              "bl_data_published_from_source"
#define  bomAttr_isDesignedInPlace          "bl_is_designed_in_place"
#define  bomAttr_reqPosDesign               "bl_req_pos_design"
#define  bomAttr_proxyShapeDataFlag         "bl_proxy_shape_data_flag"
#define  bomAttr_assignedOcc                "bl_occ_assigned"
#define  bomAttr_owningProject              "owning_project"
#define  bomAttr_projectList                "project_list"
#define  bomAttr_substituteList             "bl_substitute_list"
#define  bomAttr_childItem                  "bl_child_item"
#define  bomAttr_nveMetaExpression          "bl_nve_meta_expression"
#define  bomAttr_unitNetOccEffectivity      "fnd0UnitNetEffectivity"
#define  bomAttr_isUnitNetOccEffConfigured  "fnd0IsConfiguredForNetEff"
#define  bomAttr_occSubstituteGroupList     "bl_occ_fnd0SubstituteGrpList"
#define  bomAttr_substitutesGroupList       "bl_substitutes_list"
#define  bomAttr_fnd0bl_alternate_groups    "fnd0bl_alternate_groups"
#define  bomAttr_fnd0bl_has_alternate_group "fnd0bl_has_alternate_group"

/** @} */

/** @} */


#include <bom/libbom_undef.h>

#endif
