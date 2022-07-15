/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2015.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file
*/

#ifndef SMC0PSMCFGSUPPORT_ERRORS_H
#define SMC0PSMCFGSUPPORT_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SMC0PSMCFGSUPPORT_ERRORS Errors for Product Configurator Support for Structure Manager
    @ingroup SMC0PSMCFGSUPPORT
    @{
*/

#define EMH_SMC0CONFIGURATOR_ERROR_BASE                                                  EMH_SMC0CONFIGURATOR_error_base

/**
 * The current user does not have Manage Variability access privileges to perform this operation.
 */
#define SMC0CONFIGURATOR_no_manage_variability_access                                    ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 1 )

/**
 * The received Variant Rule is either null or invalid, when the operation expects a Product Configurator-authored Variant Rule.
 */
#define SMC0PSMCFGSUPPORT_invalid_variant_rule_error                                     ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 2 )

/**
 * Either a Variant Formula or a Saved Variant Rule must be provided as input for the variant configuration criteria.
 */
#define SMC0PSMCFGSUPPORT_invalid_config_input_error                                     ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 3 )

/**
 * The Configurator Context "%1$" cannot be associated with the Item "%2$", because its latest Item Revision has Modular Variability.
 */
#define SMC0PSMCFGSUPPORT_cannot_associate_configurator_error                            ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 4 )

/**
 * The creation of a Configurator Variant Expression on the line "%1$" has failed, because it contains a Modular Variant Expression.
 */
#define SMC0PSMCFGSUPPORT_has_modular_variant_expression                                 ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 5 )

/**
 * Configuration is not supported if the preference "Cfg0UseRuleForContentConfigure" is turned on and variant conditions are not migrated 
 to Product Configurator. Either turn off the preference or migrate all BOM Lines's variant condition of BOM Window to Product Configurator.
 Any modification to the preference value requires restart of Teamcenter.
 */
#define SMC0PSMCFGSUPPORT_invalid_config_for_nvm                                         ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 6 )


/**
 * An invalid Item type is provided while creating the solution variant.
 */
#define SMC0PSMCFGSUPPORT_invalid_input_item_type_for_sv_creation                        ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 7 )

/**
 * The input BOM Lines must be from the same BOM Window.
 */
#define SMC0PSMCFGSUPPORT_lines_are_from_different_window                                ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 8 )

/**
 * The input BOM Line must be expanded.
 */
#define SMC0PSMCFGSUPPORT_line_not_expanded                                              ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 9 )

/**
 * The configuration criteria is not applied on the BOM Window.
 */
#define SMC0PSMCFGSUPPORT_config_criteria_not_applied                                    ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 10 )

/**
 * The input BOM Line does not have configured childlines for solution variant creation.
 */
#define SMC0PSMCFGSUPPORT_no_configured_childlines                                       ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 11 )

/**
 * The variability is not defined on the input structure.
 */
#define SMC0PSMCFGSUPPORT_no_variability_defined                                         ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 12 )

/**
 * An invalid Solution Variant category is provided.
 */
#define SMC0PSMCFGSUPPORT_invalid_sv_category                                            ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 13 )

/**
 * An invalid configurator criteria is provided.
 */
#define SMC0PSMCFGSUPPORT_invalid_configurator_criteria                                  ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 14 )

/**
 * The Solution Variant search control parameters are invalid.
 */
#define SMC0PSMCFGSUPPORT_invalid_sv_search_control_params                               ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 15 )

/**
 * An invalid key string was provided in the "svItemObjectsToBeLoadedList" map.
 */
#define SMC0PSMCFGSUPPORT_invalid_key_string                                             ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 16 )

/**
 * The property "Solution Variant Category" is not modifiable for Solution Variant Item.
 */
#define SMC0PSMCFGSUPPORT_svcategory_not_modifiable                                      ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 17 )

/**
 * Invalid preference provided for the Multilevel Solution Variant creation.
 */
#define SMC0PSMCFGSUPPORT_invalid_Multilevel_preferences                                 ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 18 )

/**
 * Variant configurable object should always be saved in context of PSOccurrence/AbsOcc.
 */
#define SMC0PSMCFGSUPPORT_no_affected_object_for_vco                                     ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 19 )

/**
 * The variant rule is not applied on the BOM Window.
 */

#define SMC0PSMCFGSUPPORT_variant_rule_not_applied                                       ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 20 )

 /**
 * An invalid variant rule is provided.
 */
#define SMC0PSMCFGSUPPORT_invalid_variant_rule                                           ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 21 )

/**
 * Invalid BOM Line is provided for update of Solution Variant Item Revision.
 */
#define SMC0PSMCFGSUPPORT_invalid_bl_SV_Update                                           ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 22 )

/**
 * Invalid input list of Item Revision is provided for update of Solution Variant Item Revision.
 */
#define SMC0PSMCFGSUPPORT_invalid_input_SVList_SV_Update                                 ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 23 )

/**
 * Updating Revision Rule for multiple Solution Variant update is not supported.
 */
#define SMC0PSMCFGSUPPORT_revRule_Update_multiple_SV_Update_notSupported                 ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 24 )

/**
 * Solution Variant Item Revisions with different category cannot be updated together.
 */
#define SMC0PSMCFGSUPPORT_SolVarItemRev_mixedCategory_SV_Update_notSupported             ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 25 )

/**
 * The source Item Revision of input Solution variant and input Generic Variant Item does not refer to same Generic Variant Item.
 */
#define SMC0PSMCFGSUPPORT_SourceSV_Item_and_input_GVItem_are_different_SV_Update         ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 26 )

/**
 * The input Solution Variant Item Revision has invalid Configuration Context.
 */
#define SMC0PSMCFGSUPPORT_SolVarItemRev_with_invalid_ConfigurationContext_SV_Update      ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 27 )

/**
 * No structural difference found between the input Solution Variant Item Revision and Generic Variant Item Revision.
 */
#define SMC0PSMCFGSUPPORT_No_diff_found_SolVarItemRev_GenericItemRev                     ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 28 )

 /**
 * A Single Level Solution Variant of a Reuse category cannot be created.
 */
#define SMC0PSMCFGSUPPORT_blocked_single_level_reuse_sv_creation                         ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 29 )

 /**
 * A Solution Variant of a Reuse category cannot be revised.
 */
#define SMC0PSMCFGSUPPORT_blocked_revise_for_reuse_sv                                    ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 30 )

 /**
 * Solution Variant cannot be created for the input generic BOM Line "%1$" with invalid and incomplete subset Variant Rule.
 */
#define SMC0PSMCFGSUPPORT_Invalid_subset_variantRule                                     ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 31 )

 /**
 * No effective Configurator Context can be found on the BOM Window.
 */
#define SMC0PSMCFGSUPPORT_window_without_configuratorcontext                             ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 32 )

 /**
 * The Variant Rule is invalid or incomplete..
 */
#define SMC0PSMCFGSUPPORT_invalid_or_incomplete_variant_rule                             ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 33 )

 /**
 * The input variant rule does not match with the rule reported from BOMWindow while creating solution variants.
 */
#define SMC0PSMCFGSUPPORT_invalid_variant_rule_applied                                   ( EMH_SMC0CONFIGURATOR_ERROR_BASE + 34 )

/** @} */
#endif
