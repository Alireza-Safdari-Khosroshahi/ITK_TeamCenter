/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Error codes returned by the BOM ITK module.
*/

/*  */

#ifndef BOM_ERRORS_H
#define BOM_ERRORS_H

#include <common/emh_const.h>
#include <bom/libbom_exports.h>

/**
    @defgroup BOM_ERRORS Errors
    @ingroup BOM
    @{
*/

/**    Internal error in BOM Module
 %1$*/
#define BOM_internal_error                                                    (EMH_BOM_error_base +   0)

/**    Invalid tag received by BOM Module.*/
#define BOM_invalid_tag                                                       (EMH_BOM_error_base +   1)

/**    Attempt to call the BOM Module before it has been initialized.*/
#define BOM_not_yet_initialized                                               (EMH_BOM_error_base +   2)

/**    No revision of Item %1$ matches the current configuration rule.*/
#define BOM_no_configured_ir                                                  (EMH_BOM_error_base +   4)

/**    This Item Revision does not contain a BOMView Revision.*/
#define BOM_no_bvr_in_ir                                                      (EMH_BOM_error_base +   5)

/**    You are attempting to create a circular structure.*/
#define BOM_circular_structure                                                (EMH_BOM_error_base +   6)

/**    You may not replace the top line of a Window.*/
#define BOM_cant_replace_root                                                 (EMH_BOM_error_base +   7)

/**    You may not cut the top line of a BOM Window.*/
#define BOM_cant_cut_root                                                     (EMH_BOM_error_base +   8)

/**    No revision configured for Item %1$.*/
#define BOM_line_has_no_ir                                                    (EMH_BOM_error_base +   9)

/**    Invalid quantity value entered.*/
#define BOM_invalid_qty                                                       (EMH_BOM_error_base +  10)

/**    You may not edit some attributes of a Packed BOM Line.*/
#define BOM_is_packed_occurrence                                              (EMH_BOM_error_base +  11)

/**    You may not edit the notes of a Packed BOM Line.*/
#define BOM_is_packed_notes                                                   (EMH_BOM_error_base +  12)

/**    You may not edit occurrence attributes of the top line of a BOM Window.*/
#define BOM_cant_edit_root_line_occ                                           (EMH_BOM_error_base +  13)

/**    Unable to set the top line of a BOM to be Precise/Imprecise
 it has no defined parent.*/
#define BOM_cant_toggle_root                                                  (EMH_BOM_error_base +  14)

/**    Precise and imprecise occurrences may not be simultaneously replaced.*/
#define BOM_cant_replace_mixed                                                (EMH_BOM_error_base +  15)

/**    Select one line of the BOM only.*/
#define BOM_select_one_line                                                   (EMH_BOM_error_base +  16)

/**    You cannot access notes on the top line of the BOM.*/
#define BOM_no_notes_on_root                                                  (EMH_BOM_error_base +  17)

/**    You cannot edit occurrence attributes of a Substitute line.*/
#define BOM_cant_edit_substitute                                              (EMH_BOM_error_base +  18)

/**    You cannot have substitutes of the top line of the BOM.*/
#define BOM_no_substitutes_on_root                                            (EMH_BOM_error_base +  19)

/**    Line %1$ is not a substitute.*/
#define BOM_line_not_substitute                                               (EMH_BOM_error_base +  20)

/**    You cannot prefer multiple substitutes of the same occurrence.*/
#define BOM_cant_prefer_multiple                                              (EMH_BOM_error_base +  21)

/**    You may not replace an occurrence with substitutes.*/
#define BOM_cant_replace_substitute                                           (EMH_BOM_error_base +  22)

/**    You cannot add Substitutes to a Packed BOM Line.
Unpack and add/paste to a specific line.*/
#define BOM_cant_add_sub_to_packed                                            (EMH_BOM_error_base +  23)

/**    You cannot have variants of the top line of the BOM.*/
#define BOM_no_variants_on_root                                               (EMH_BOM_error_base +  24)

/**    Asking for the value of an option when it has been set to a different mode.*/
#define BOM_variant_wrong_mode                                                (EMH_BOM_error_base +  25)

/**    Index %1$ is outside the list of values defined for option %2$.*/
#define BOM_invalid_variant_value                                             (EMH_BOM_error_base +  26)

/**    Index references an obsolete value of option %1$.*/
#define BOM_obsolete_variant_value                                            (EMH_BOM_error_base +  27)

/**    Option has value %1$ already.*/
#define BOM_duplicate_variant_value                                           (EMH_BOM_error_base +  28)

/**    Invalid value given for option mode.*/
#define BOM_invalid_variant_mode                                              (EMH_BOM_error_base +  29)

/**    No name for the option.*/
#define BOM_no_variant_name                                                   (EMH_BOM_error_base +  30)

/**    No configured revision of item %1$ containing option %2$.*/
#define BOM_variant_no_configured                                             (EMH_BOM_error_base +  31)

/**    There is more than one Item that matches '%1$' and has an option '%2$'.*/
#define BOM_variant_not_unique                                                (EMH_BOM_error_base +  32)

/**    Value '%1$' not in option '%2$'.*/
#define BOM_value_not_in_variant                                              (EMH_BOM_error_base +  33)

/**    BOM variant error condition: %1$.*/
#define BOM_variant_error_condition                                           (EMH_BOM_error_base +  34)

/**    BOM variant error item: in evaluating an error check on %1$.*/
#define BOM_variant_error_item                                                (EMH_BOM_error_base +  35)

/**    Derived option %1$ was set to %2$, but we are now trying to change it to %3$.*/
#define BOM_variants_derived_conflict                                         (EMH_BOM_error_base +  36)

/**    Cannot find option %1$.*/
#define BOM_variant_cant_find                                                 (EMH_BOM_error_base +  37)

/**    Value field not empty -- did you forget to add the condition?*/
#define BOM_option_condition_not_added                                        (EMH_BOM_error_base +  38)

/**    You will not be able to save any changes you make.*/
#define BOM_item_rev_read_only                                                (EMH_BOM_error_base +  39)

/**    No description for the option.*/
#define BOM_no_variant_description                                            (EMH_BOM_error_base +  40)

/**    Item %1$ already contains option %2$.*/
#define BOM_option_already_exists                                             (EMH_BOM_error_base +  41)

/**    You are trying to delete an option that is still in use.*/
#define BOM_option_referenced                                                 (EMH_BOM_error_base +  42)

/**    Did you forget to Add the condition to check?
 (Add and then Remove it to suppress this message)*/
#define BOM_not_added_option_condition                                        (EMH_BOM_error_base +  43)

/**    Option has no values;  you must add at least one before creating the option.*/
#define BOM_option_has_no_values                                              (EMH_BOM_error_base +  44)

/**    Invalid token value handed to function.*/
#define BOM_invalid_token                                                     (EMH_BOM_error_base +  45)

/**    Invalid class tag handed to function.*/
#define BOM_invalid_class                                                     (EMH_BOM_error_base +  46)

/**    Did you forget to Add the last value?
 (Add and then Remove it to suppress this message)*/
#define BOM_option_value_not_added                                            (EMH_BOM_error_base +  47)

/**    Invalid BOM lines for BOM compare.*/
#define BOM_compare_invalid_data                                              (EMH_BOM_error_base +  48)

/**    Invalid destination for BOM compare output.*/
#define BOM_compare_invalid_dest                                              (EMH_BOM_error_base +  49)

/**    Invalid mode for BOM compare.*/
#define BOM_compare_invalid_mode                                              (EMH_BOM_error_base +  50)

/**    Multiple revisions of %1$ detected under %2$.*/
#define BOM_compare_multiple_revs                                             (EMH_BOM_error_base +  51)

/**    Nested BOM Lines cannot be compared.
 If you really want to do this, open a second window.*/
#define BOM_compare_nested_roots                                              (EMH_BOM_error_base +  52)

/**    You cannot compare a BOM line with itself.*/
#define BOM_compare_identical_data                                            (EMH_BOM_error_base +  53)

/**    May not rename an option with more than one revision.*/
#define BOM_variant_many_revs                                                 (EMH_BOM_error_base +  54)

/**    In %2$ trying to compare option against '%1$' which is a bad number.*/
#define BOM_options_bad_compare_string                                        (EMH_BOM_error_base +  55)

/**    In %3$ trying to compare against option %1$ set to '%2$' which is a bad number.*/
#define BOM_options_bad_compare_enum                                          (EMH_BOM_error_base +  56)

/**    Bad value '%1$' to compare against -- must be numeric.*/
#define BOM_options_bad_compare_value                                         (EMH_BOM_error_base +  57)

/**    Derived option is used in the condition -- may not derive an option from itself.*/
#define BOM_option_derived_from_itself                                        (EMH_BOM_error_base +  58)

/**    No report exists for this BOM compare.*/
#define BOM_compare_no_report                                                 (EMH_BOM_error_base +  59)

/**    You may not use Change View on the top line of a BOM Window.*/
#define BOM_cant_change_view_on_root                                          (EMH_BOM_error_base +  60)

/**    The item is unreadable.*/
#define BOM_unreadable_item                                                   (EMH_BOM_error_base +  61)

/**    The BOM cannot be expanded because it contains an unreadable item.*/
#define BOM_cant_expand_unreadable                                            (EMH_BOM_error_base +  62)

/**    The item is remote.*/
#define BOM_remote_item                                                       (EMH_BOM_error_base +  63)

/**    The BOM cannot be expanded because it contains a remote item.*/
#define BOM_cant_expand_remote                                                (EMH_BOM_error_base +  64)

/**    The assembly contains unpublished components.*/
#define BOM_child_not_published                                               (EMH_BOM_error_base +  65)

/**    You cannot pack a non-preferred substitute. Try packing the preferred substitute.*/
#define BOM_cant_pack_non_preferred_sub                                       (EMH_BOM_error_base +  66)

/**    Invalid variant condition clause.*/
#define BOM_variant_invalid_cond_clause                                       (EMH_BOM_error_base +  67)

/**    Invalid variant clause operation.*/
#define BOM_variant_invalid_operation                                         (EMH_BOM_error_base +  68)

/**    Invalid variant clause range selected.*/
#define BOM_variant_invalid_range                                             (EMH_BOM_error_base +  69)

/**    Invalid BOM variant rule.*/
#define BOM_variant_invalid_bom_vrule                                         (EMH_BOM_error_base +  70)

/**    Conflicting derived defaults on %1$ and %2$.*/
#define BOM_variant_derived_error_item                                        (EMH_BOM_error_base +  71)

/**    You may not list the substitutes of a non-preferred component.*/
#define BOM_cant_list_subs_of_non_preferred                                   (EMH_BOM_error_base +  72)

/**    The expression supplied should have been a condition, got non-logical op code %1$.*/
#define BOM_expr_not_condition                                                (EMH_BOM_error_base +  73)

/**    Variant data for this item revision has been edited in another session. Refresh required.*/
#define BOM_veb_needs_refresh                                                 (EMH_BOM_error_base +  74)

/**    You cannot prefer a Substitute on a Packed BOM Line.
 Unpack and perform the operation on a specific line.*/
#define BOM_cant_prefer_when_packed                                           (EMH_BOM_error_base +  75)

/**    BOMCompareMode '%1$' already exists.*/
#define BOM_duplicate_bom_compare_mode                                        (EMH_BOM_error_base +  76)

/**    BOMCompareMode '%1$' does not exist.*/
#define BOM_no_such_bom_compare_mode                                          (EMH_BOM_error_base +  77)

/**    Not an active compare.*/
#define BOM_no_current_compare                                                (EMH_BOM_error_base +  78)

/**    Released BOM View Revision is found.*/
#define BOM_bl_released_bvr                                                   (EMH_BOM_error_base +  79)

/**    BOM_writer parameter '%1$' is null.*/
#define BOM_writer_parameter_is_null                                          (EMH_BOM_error_base +  80)

/**    BOM_writer parameter '%1$' is wrong type.*/
#define BOM_writer_parameter_is_wrong_type                                    (EMH_BOM_error_base +  81)

/**    BOM_writer (legacy) matrix is missing or null.*/
#define BOM_writer_matrix_missing_or_null                                     (EMH_BOM_error_base +  82)

/**    Baseline creation rolled back because of an error.*/
#define BOM_bl_rollback_error                                                 (EMH_BOM_error_base +  83)

/**    NXmanager refile program has exited with errors.*/
#define BOM_bl_refile_error                                                   (EMH_BOM_error_base +  84)

/**    Baseline for Item Type '%1$' cannot be created.*/
#define BOM_bl_restricted_item_type                                           (EMH_BOM_error_base +  85)

/**    BOM_writer: plmxml returned '%1$' on save.*/
#define BOM_writer_plmxml_save_error                                          (EMH_BOM_error_base +  86)

/**    BOM_writer: format was given NULL output mechanism.*/
#define BOM_writer_format_requires_output                                     (EMH_BOM_error_base +  87)

/**    BOM_writer: builder class '%1$' was not found.*/
#define BOM_writer_builder_class_not_found                                    (EMH_BOM_error_base +  88)

/**    BOM_writer: error in user attribute list for '%1$' position %2$: expected '%3$', found '%4$'.*/
#define BOM_writer_user_attribute_target_list_error                           (EMH_BOM_error_base +  89)

/**    BOM_writer: unknown or badly formed user attribute target '%1$'.*/
#define BOM_writer_user_attribute_target_unrecognised                         (EMH_BOM_error_base +  90)

/**    BOM_writer: in target specifier for '%1$', malformed or misplaced item '%2$'.*/
#define BOM_writer_user_attribute_target_specifier_error                      (EMH_BOM_error_base +  91)

/**    BOMWriter: in target '%1$', user attribute key '%2$' was given properties '%3$' and '%4$'.*/
#define BOM_writer_user_attributes_duplicate_key                              (EMH_BOM_error_base +  92)

/**    An invalid value for how an option is set was passed in. Can only be UserSet, UserFixed or Variant Item.*/
#define BOM_invalid_how_set                                                   (EMH_BOM_error_base +  93)

/**    No conditions are allowed on the top line.*/
#define BOM_no_condition_on_root_line                                         (EMH_BOM_error_base +  94)

/**    This itemrevision's variant data has been locked by another session.*/
#define BOM_mvl_is_locked                                                     (EMH_BOM_error_base +  95)

/**    Cannot replace non-generic component in a linked variant item.*/
#define BOM_vi_cannot_replace_non_generic                                     (EMH_BOM_error_base +  96)

/**    Cannot replace anything other than a variant item into a variant item structure.*/
#define BOM_vi_cannot_replace_in_non_vi                                       (EMH_BOM_error_base +  97)

/**    Cannot replace variant item with conflicting values into a variant item structure.*/
#define BOM_vi_cannot_replace_in_bad_config                                   (EMH_BOM_error_base +  98)

/**    Structure changes are not possible for a generic component linked to by variant items.*/
#define BOM_cannot_change_linked_gc                                           (EMH_BOM_error_base +  99)

/**    Cannot configure in an item that is not a variant.*/
#define BOM_configure_in_item_is_not_vi                                       (EMH_BOM_error_base + 100)

/**    Cannot configure a variant item into a structure line that is not a module.*/
#define BOM_line_to_configure_is_not_gc                                       (EMH_BOM_error_base + 101)

/**    Cannot identify variant reuse in component BOM line without a parent BOM line.*/
#define BOM_line_comp_reuse_no_parent                                         (EMH_BOM_error_base + 102)

/**    BOMWriter: Attempt to read unselected AncestorLines before traversal occurred.*/
#define BOM_writer_attempted_read_before_traversal                            (EMH_BOM_error_base + 103)

/**    All given BOMLines do not belong to this BOMWindow.*/
#define BOM_lines_in_different_windows                                        (EMH_BOM_error_base + 104)

/**    Unable to create '%1$'.*/
#define BOM_null_class_object                                                 (EMH_BOM_error_base + 105)

/**    Failed in create Relationship '%1$'.*/
#define BOM_promote_failed                                                    (EMH_BOM_error_base + 106)

/**    Unable to connect '%1$' to '%2$'.*/
#define BOM_connect_failed                                                    (EMH_BOM_error_base + 107)

/**    Unable to get Occurrence for '%1$'.*/
#define BOM_line_get_occ_failed                                               (EMH_BOM_error_base + 108)

/**    Must specify atleast 1 BOMLine for '%1$'.*/
#define BOM_zero_size_taglist                                                 (EMH_BOM_error_base + 109)

/**    Unable to find Parent for '%1$'.*/
#define BOM_no_common_parent                                                  (EMH_BOM_error_base + 110)

/**    Connection Line cannot be topLine.*/
#define BOM_connline_is_topline                                               (EMH_BOM_error_base + 111)

/**    Unable to get Interface for '%1$'.*/
#define BOM_line_get_gde_failed                                               (EMH_BOM_error_base + 112)

/**    NULLTAG(S) passed as inputs '%1$'.*/
#define BOM_input_is_nulltag                                                  (EMH_BOM_error_base + 113)

/**    Unable to create pathnode for '%1$'.*/
#define BOM_line_null_pathnode                                                (EMH_BOM_error_base + 114)

/**    The Type of BOMLine '%1$' is not supported for this functionality.*/
#define BOM_line_type_is_not_supported                                        (EMH_BOM_error_base + 115)

/**    One or more BOMLine(s) is/are at higher level than connection Line '%1$'.*/
#define BOM_line_at_higher_level                                              (EMH_BOM_error_base + 116)

/**    Input BOMLine is not a connectionLine '%1$'.*/
#define BOM_not_connection_line                                               (EMH_BOM_error_base + 117)

/**    Input BOMLine(s) is not a GDELine(s) '%1$'.*/
#define BOM_not_gde_line                                                      (EMH_BOM_error_base + 118)

/**    Failed to create Connection Line '%1$'.*/
#define BOM_create_connection_failed                                          (EMH_BOM_error_base + 119)

/**    BOMWriter: User Attributes preference depth exceeded.*/
#define BOM_writer_preference_depth_exceeded                                  (EMH_BOM_error_base + 120)

/**    Using parent requirements to identify VI reuse in this BOM line is not possible.*/
#define BOM_vi_reuse_id_not_possible                                          (EMH_BOM_error_base + 121)

/**    Unable to load modular option "%1$" from "%2$" without a BOMSos.*/
#define BOM_no_bomsos_target                                                  (EMH_BOM_error_base + 122)

/**    Unable to load legacy option "%1$" from "%2$" without a BOMVariantRule.*/
#define BOM_no_variantrule_target                                             (EMH_BOM_error_base + 123)

/**    Invalid data: '%1$'.*/
#define BOM_invalid_data                                                      (EMH_BOM_error_base + 124)

/**    In Context edit mode is not active or BOMLine being edited is outside context range.*/
#define BOM_absocc_edit_mode_off                                              (EMH_BOM_error_base + 125)

/**    Context must be set to top level BOM Line in order to assign an ID In Context.*/
#define BOM_absocc_context_not_topline                                        (EMH_BOM_error_base + 126)

/**    Window does not have any topline loaded.*/
#define BOM_window_topline_null                                               (EMH_BOM_error_base + 127)

/**    The root line is not visible in this window.*/
#define BOM_root_not_in_this_window                                           (EMH_BOM_error_base + 128)

/**    BOM Window is not in Incremental Change Context.*/
#define BOM_not_in_ic_context                                                 (EMH_BOM_error_base + 129)

/**    Cannot change Incremental Change Context with unsaved BOM edits.*/
#define BOM_ic_change_unsaved_edits                                           (EMH_BOM_error_base + 130)

/**    The absolute occurrence edit context line is not an ancestor of the BOMLine being edited.*/
#define BOM_absocc_context_not_ancestor                                       (EMH_BOM_error_base + 131)

/**    There is no absolute occurrence for the BOMLine being edited.*/
#define BOM_no_absocc_for_context                                             (EMH_BOM_error_base + 132)

/**    This operation is not valid on the top line.*/
#define BOM_op_invalid_on_root                                                (EMH_BOM_error_base + 133)

/**    Cannot Disconnect.*/
#define BOM_can_not_disconnect                                                (EMH_BOM_error_base + 134)

/**    Cannot remove this Relation.*/
#define BOM_can_not_remove_relation                                           (EMH_BOM_error_base + 135)

/**    Cannot edit occurrence effectivity of a packed line.*/
#define BOM_can_not_edit_packed_occ_eff                                       (EMH_BOM_error_base + 136)

/**    You may not edit some attributes of a Packed BOM Line when In Context edit mode is turned on.*/
#define BOM_absocc_is_packed_occurrence                                       (EMH_BOM_error_base + 137)

/**    The BOM Line does not contain any Item Revision.*/
#define BOM_no_item_rev                                                       (EMH_BOM_error_base + 138)

/**    The occurrence "%1$" is not a valid predecessor of the whatever_this_is "%2$".*/
#define BOM_not_valid_pred                                                    (EMH_BOM_error_base + 139)

/**    The line cannot be deleted because it is referenced by incremental changes on its relation with predecessors.*/
#define BOM_ices_on_pred_reln                                                 (EMH_BOM_error_base + 140)

/**    The line cannot be deleted because it is referenced by incremental changes on its relation with successors.*/
#define BOM_ices_on_succ_reln                                                 (EMH_BOM_error_base + 141)

/**    The suppression state of this occurrence is constrained and cannot be modified.*/
#define BOM_suppression_constrained                                           (EMH_BOM_error_base + 142)

/**    The position of this occurrence is constrained and cannot be modified.*/
#define BOM_position_constrained                                              (EMH_BOM_error_base + 143)

/**    Not able to set absocc compound property value.*/
#define BOM_set_failure_absocc_compound_prop_value                            (EMH_BOM_error_base + 144)

/**    Unable to locate absocc form...  attachment type = "%1$",  dataset type = "%2$",  form type = "%3$".*/
#define BOM_not_find_absocc_compound_prop_attachment                          (EMH_BOM_error_base + 145)

/**    Access denied on absocc form...  attachment type = "%1$",  dataset type = "%2$",  form type = "%3$".*/
#define BOM_access_denied_absocc_form                                         (EMH_BOM_error_base + 146)

/**    The child cannot be added to the selected parent because the child type "%1$" is not valid for parent type "%2$".*/
#define BOM_invalid_child_item_type                                           (EMH_BOM_error_base + 147)

/**    The BOM module has encountered a serious internal error %1$.  Please restart your session or data integrity may be affected.*/
#define BOM_serious_error                                                     (EMH_BOM_error_base + 148)

/**    Line %1$ is affected by Incremental Changes (IC). Cannot restructure without setting an active IC context.*/
#define BOM_restructure_ic_context_required                                   (EMH_BOM_error_base + 149)

/**    Line %1$ is already removed by Incremental Change %2$.*/
#define BOM_restructure_duplicate_ic_remove_attempted                         (EMH_BOM_error_base + 150)

/**    Cannot restructure Line %1$ with Incremental Change %2$ as it is affected by other Incremental Changes.*/
#define BOM_restructure_ices_of_other_contexts                                (EMH_BOM_error_base + 151)

/**    The line "%1$" cannot be restructured because it contains pending edits.*/
#define BOM_restructure_with_pending_edit                                     (EMH_BOM_error_base + 152)

/**    The line "%1$" is a context line for an absolute occurrence. Removing it will lose the absolute occurrence data.*/
#define BOM_restructure_removing_context_line                                 (EMH_BOM_error_base + 153)

/**    The lines "%1$" and "%2$" are not in the same structure.*/
#define BOM_restructure_move_to_invalid_branch                                (EMH_BOM_error_base + 154)

/**    Cannot replace the BOMLine since either the replacing node or the replaced node has substructure.*/
#define BOM_cant_replace_substructure                                         (EMH_BOM_error_base + 155)

/**    The move to action cannot handle the absolute occurrence data. Line %1$ has multiple appearance path nodes, and occurrence thread of %2$ has multiple lines.*/
#define BOM_restructure_move_to_multi_line                                    (EMH_BOM_error_base + 156)

/**    The move to action dropped some absolute occurrences. Line %1$ has one or more appearance path nodes that are not in the current context.*/
#define BOM_restructure_lost_absocc                                           (EMH_BOM_error_base + 157)

/**    The structure is stale. Please refresh it.*/
#define BOM_restructure_invalid_tag                                           (EMH_BOM_error_base + 158)

/**    The action can only be performed in the "Display Pending Edits" mode.*/
#define BOM_not_in_redline_mode                                               (EMH_BOM_error_base + 160)

/**    The line cannot be added under a line marked to be removed.*/
#define BOM_cant_add_under_removed_line                                       (EMH_BOM_error_base + 161)

/**    The attributes cannot be edited because its line is marked to be removed.*/
#define BOM_cant_edit_attributes_of_removed_line                              (EMH_BOM_error_base + 162)

/**    The absolute occurrence context cannot be set while the display pending edits mode is enabled.*/
#define BOM_absocc_not_allowed_in_redline_mode                                (EMH_BOM_error_base + 163)

/**    The comparison cannot be performed if either window has pending edits.*/
#define BOM_compare_not_allowed_in_redline_mode                               (EMH_BOM_error_base + 164)

/**    Cannot find PSOccurrence of this line to edit this attribute.*/
#define BOM_cant_edit_no_psocc                                                (EMH_BOM_error_base + 165)

/**    Cannot set IC context while the display pending edits mode is enabled.*/
#define BOM_ic_not_allowed_in_redline_mode                                    (EMH_BOM_error_base + 166)

/**    This restructure action is not allowed with lines that are using absolute occurrences.*/
#define BOM_restructure_not_allowed_with_absocc                               (EMH_BOM_error_base + 167)

/**    Invalid join operator for the clause.*/
#define BOM_invalid_join_operator                                             (EMH_BOM_error_base + 168)

/**    Invalid comparison operator.*/
#define BOM_invalid_comp_operator                                             (EMH_BOM_error_base + 169)

/**    Input for %1$ ITK is invalid! Please review Customization -> Integration Toolkit (ITK) Function Reference documentation for help.*/
#define BOM_invalid_broken_link_input                                         (EMH_BOM_error_base + 170)

/**    The occurrence about to be modified or deleted may have been removed by another session.*/
#define BOM_occ_removed_from_other_session                                    (EMH_BOM_error_base + 171)

/**    Value for reference designator is in wrong format.*/
#define BOM_ref_designator_format_error                                       (EMH_BOM_error_base + 172)

/**    Duplicate value for reference designator.*/
#define BOM_ref_designator_duplicate_value                                    (EMH_BOM_error_base + 173)

/**    Quantity can only be blank or 1 if reference designator is assigned.*/
#define BOM_ref_designator_quantity_error                                     (EMH_BOM_error_base + 174)

/**    The item %2$ cannot be added to the assembly since it is not a preferred part to assembly programs %1$.*/
#define BOM_AssmNotSetToUsePreferredPrt                                       (EMH_BOM_error_base + 175)

/**    The item is used as a preferred part in the assembly, and the relation cannot be removed.*/
#define BOM_revokingProgIsPrtOfAssmProgList                                   (EMH_BOM_error_base + 176)

/**    There is no owning project for the BOM View item.*/
#define BOM_noOwningProjectFound                                              (EMH_BOM_error_base + 177)

/**    The drawing item revision is prevented from being added as component in the product structure.*/
#define BOM_add_drawing_prevent_error                                         (EMH_BOM_error_base + 178)

/**    The value %1$ cannot be deleted since it is referenced by other objects.*/
#define BOM_option_value_referenced                                           (EMH_BOM_error_base + 179)

/**    The child cannot be added to the selected parent since the parent type %1$ is not valid for the child type %2$.*/
#define BOM_invalid_parent_item_type                                          (EMH_BOM_error_base + 180)

/**    The first common parent of selected parts and manufacturing feature is invalid.*/
#define BOM_invalid_first_common_parent                                       (EMH_BOM_error_base + 181)

/**    The line %1$ cannot be deleted because there are Incremental Changes in a context other than currently set in BOMWindow. Please refer to the Incremental Change information tab for more information.*/
#define BOM_ices_in_other_context                                             (EMH_BOM_error_base + 182)

/**    BOM Markup features are not enabled.*/
#define BOM_markup_not_enabled                                                (EMH_BOM_error_base + 183)

/**    A BOM Markup object cannot be attached to the selected line.*/
#define BOM_markup_cannot_attach                                              (EMH_BOM_error_base + 184)

/**    The BOM Markup relation does not exist.*/
#define BOM_markup_relation_not_exist                                         (EMH_BOM_error_base + 185)

/**    The selected object cannot be used for markup.*/
#define BOM_markup_wrong_obj                                                  (EMH_BOM_error_base + 186)

/**    This property cannot be used to create a markup.*/
#define BOM_markup_not_supported_prop                                         (EMH_BOM_error_base + 187)

/**    The line has been marked for removal.*/
#define BOM_markup_removed                                                    (EMH_BOM_error_base + 188)

/**    The line has been marked for changes. Therefore a remove markup cannot be created.*/
#define BOM_markup_removing                                                   (EMH_BOM_error_base + 189)

/**    A line with substitutes cannot be replaced.*/
#define BOM_markup_replace_substitute                                         (EMH_BOM_error_base + 190)

/**    The line has been marked for replacement.*/
#define BOM_markup_replace_replace                                            (EMH_BOM_error_base + 191)

/**    A duplicate substitute list change for the selected line cannot be created.*/
#define BOM_markup_substitute_substitute                                      (EMH_BOM_error_base + 192)

/**    The multi-unit configuration is not enabled. You may contact your System Administrator for help.*/
#define BOM_multi_unit_conf_not_enabled                                       (EMH_BOM_error_base + 193)

/**    An overlap in effectivity exists in source BOM Lines.*/
#define BOM_accountability_src_overlap_exists                                 (EMH_BOM_error_base + 194)

/**    An overlap in effectivity exists in target BOM Lines.*/
#define BOM_accountability_target_overlap_exists                              (EMH_BOM_error_base + 195)

/**    An overlap exists in source and target BOM Lines.*/
#define BOM_accountability_overlap_exists                                     (EMH_BOM_error_base + 196)

/**    No registered Extension to calculate the Net Effectivity could be found. Contact your System Administrator for assistance.*/
#define BOM_accountability_extension_not_attached                             (EMH_BOM_error_base + 197)

/**    The BOM Window is in &quot;Configured To Load&quot; mode. In this mode &quot;Show Unconfigured Variants&quot; is not possible.*/
#define BOM_cannot_show_unconfgd_variants_in_configtoload                     (EMH_BOM_error_base + 198)

/**    The sequence cannot be removed as it is referenced by incremental changes.*/
#define BOM_cant_delete_sequence                                              (EMH_BOM_error_base + 199)

/**    The BOM View or BOM View Revision object cannot be loaded. Check if you have proper access to it.*/
#define BOM_access_denied_bv_bvr_in_ir                                        (EMH_BOM_error_base + 200)

/**    The BOM writer PLMXML format is used with an invalid input structure.*/
#define BOM_writer_plmxml_invalid_input_structure                             (EMH_BOM_error_base + 201)

/**    The transform matrix value is not valid.*/
#define BOM_invalid_xform_value                                               (EMH_BOM_error_base + 202)

/**    The baseline operation has failed with the following error: &quot;%1$&quot;.
 During the &quot;Undo&quot; operation, the baseline has encountered the following error: &quot;%2$&quot;.*/
#define BOM_baseline_and_undo_failed                                          (EMH_BOM_error_base + 203)

/**    The Item Revision &quot;%1$&quot; does not belong to the underlying BOM Item &quot;%2$&quot;.
 Please contact your site administrator to review the customization done through BMIDE for the post action on the operation &quot;fnd0getCustomConfiguredIrf&quot;.
*/
#define BOM_invalid_custom_configured_ir                                      (EMH_BOM_error_base + 204)

/**    Product Element objects can only be assigned to a precise BOM View Revision.*/
#define BOM_cant_assign_de_to_imprecise_parent                                (EMH_BOM_error_base + 205)

/**    Product Element objects cannot be assigned to a Bill Of Process.*/
#define BOM_cant_assign_de_to_BOP                                             (EMH_BOM_error_base + 206)

/**    Product Element objects without Item Revisions cannot be assigned to a Manufacturing Bill Of Materials.*/
#define BOM_cant_assign_de_without_itemRev                                    (EMH_BOM_error_base + 207)

/**    Product Element objects of type "Promissory" cannot be assigned to a Manufacturing Bill Of Materials.*/
#define BOM_invaild_DE_for_assign                                             (EMH_BOM_error_base + 208)

/**    Checked-out Product Element objects cannot be assigned to a Manufacturing Bill Of Materials.*/
#define BOM_cant_assign_ckedout_de                                            (EMH_BOM_error_base + 209)

/**    Product Element objects without a Thread ID value cannot be assigned to a Manufacturing Bill Of Materials.*/
#define BOM_cant_assign_de_without_thread                                     (EMH_BOM_error_base + 210)

/**    BOM Lines do not support date and unit effectivity together.*/
#define BOM_cant_set_unit_multi_type_effectivities                            (EMH_BOM_error_base + 211)

/**    Error to indicate that the value given for a Substitute Groups preference is incorrect*/
#define BOM_subgroup_prefs_incorrect                                          (EMH_BOM_error_base + 212)

/**    Substitute Group error for restructure operations*/
#define BOM_restruct_not_allowed_for_lines_with_subgroups                     (EMH_BOM_error_base + 213)

/**    The BOMLine failed the occurrence condition validation.*/
#define BOM_line_failed_occ_condition                                         (EMH_BOM_error_base + 214)

/**    The substitute of the BOMLine failed the occurrence condition validation.*/
#define BOM_subst_failed_occ_condition                                        (EMH_BOM_error_base + 215)

/**    An invalid input for parent or child is being passed to the occurrence condition validation.*/
#define BOM_invalid_input                                                     (EMH_BOM_error_base + 216)

/**    An error has occurred while calculating the Rollup Variant Condition for the BOM Line &quot;%1$&quot;.*/
#define BOM_variant_cond_rollup_calculate_error                               (EMH_BOM_error_base + 217)

/** Engineering Bill of Materials and Manufacturing Bill of Materials must both be either precise or imprecise for alignment synchronization. */
#define BOM_alignment_precision_mismatch                                      (EMH_BOM_error_base + 218)

/** Creation of attachment data in absolute context mode is not allowed for substitute lines */
#define BOM_absocc_rel_not_allowed                                            (EMH_BOM_error_base + 219)

/** A child line cannot be added to a substitute line.*/
#define BOM_invalid_target_line                                               (EMH_BOM_error_base + 220)

/** The selection contains one or more substitute lines. Substitutes will not be pasted on the target Item. */
#define BOM_cannot_add_substitute_as_child_line                               (EMH_BOM_error_base + 221)

/** Variant data created in the Product Configurator application is not supported in the current application.
    Please use variant data created in the Structure Manager application.
*/
#define BOM_invalid_variant_option_mode                                       (EMH_BOM_error_base + 222)

/** An invalid input was provided for the BOM Window Variant Configuration Mode. Valid values are 0 (single rule - single value), 1 (single rule - multiple values), 2 (Overlay). */
#define BOM_invalid_variant_config_mode                                       (EMH_BOM_error_base + 223)

/** The BOM Window Variant configuration mode 0 (single rule - single value) does not support multiple BOM Variant values. Please change the BOM Window Variant configuration mode to 1 (single rule - multi value). */
#define BOM_variant_multiple_values_unsupported                               (EMH_BOM_error_base + 224)

/** The selected operation does not support usage of the BOM Window Variant configuration mode 2 (Overlay). Please change the BOM Window Variant configuration mode to 0 (single rule - single value) or 1 (single rule - multi value). */
#define BOM_variant_operation_unsupported                                     (EMH_BOM_error_base + 225)

/** The BOM Window Variant configuration modes 0 (single rule - single value) and 1 (single rule - multiple values) do not support multiple BOM Variant values. Please change the BOM Window Variant configuration mode to 2 (Overlay).*/
#define BOM_window_multiple_variant_rules_unsupported                         (EMH_BOM_error_base + 226)

/** An invalid variant action mode "%1$" is provided for the current BOM Window configuration mode "%2$". The configuration modes 0 (single rule - single value) and 1 (single rule - multi value) support the action modes 0, 3 and 4. The configuration mode 2 (Overlay) supports the action modes 0, 1, 2 and 3. */
#define BOM_window_invalid_variant_action_mode                                (EMH_BOM_error_base + 227)

/** The attribute name "%1$" is not supported for attribute-based partial expansion. */
#define BOM_attribute_not_supported_for_partial_expand                        (EMH_BOM_error_base + 228)

/**    Removing the BOM Line "%1$" would cause the BOM Line "%2$" to be moved beneath the BOM Line "%3$", which is not allowed because an object of type "%4$" cannot be child of an object of type "%5$". */
#define BOM_remove_level_invalid_child                                        (EMH_BOM_error_base + 229)

/** The "Clone Structure" operation has failed to duplicate the structure. Please check the Teamcenter server syslog file for more information. */
#define BOM_duplicate_failed                                                  (EMH_BOM_error_base + 230)

/** The "Clone Structure" operation was successful, but had some partial errors. Please check the Teamcenter server syslog file for more information. The cloned structure will need to be opened, and the levels of the structure that had errors will need to be corrected manually. */
#define BOM_duplicate_with_partial_errors                                     (EMH_BOM_error_base + 231)

/** The "Clone Structure" operation has failed during the validation of the structure to be cloned. Please check the Teamcenter server syslog file for more information. */
#define BOM_duplicate_validation_failed                                       (EMH_BOM_error_base + 232)

/** The "Clone Structure" operation has successfully submitted the asynchronous clone job to the dispatcher. */
#define BOM_duplicate_asynchronous_submitted                                  (EMH_BOM_error_base + 233)

/** The CAD Dependent data could not be retrieved for the structure "%1$". Please validate that the structure to be duplicated is fully loaded, by expanding the structure in the Structure Manager application. */
#define BOM_duplicate_expandorupdate_expand_failed                            (EMH_BOM_error_base + 234)

/** The auto-selection with top level structure projects has failed. Please ensure that the top level structure has projects, and that the user has read access to those projects. */
#define BOM_duplicate_expandorupdate_autoselect_failed                        (EMH_BOM_error_base + 235)

/** The CAD Dependents data could not be retrieved for Item Revision "%1". Please check that the Item Revision has CAD Dependencies on what?. Ensure also that the CAD Dependencies are configured correctly and have read access. */
#define BOM_duplicate_expandorupdate_search_failed                            (EMH_BOM_error_base + 236)

/** An invalid value was provided for one of the Default Naming fields. Please check the input. */
#define BOM_duplicate_default_naming_invalid                                  (EMH_BOM_error_base + 237)

/** An invalid replacing data input (Item ID or Item Revision ID) was provided. Please check the inputs.*/
#define BOM_duplicate_replace_operation_invalid_input                         (EMH_BOM_error_base + 238)

/** A write privilege access issue has been detected on the folder "%1$" used for duplicate objects for the current user.*/
#define BOM_duplicate_folder_invalid_access                                   (EMH_BOM_error_base + 239)

/** The BOM Window cannot be closed, because it is shared. */
#define BOM_window_shared                                                     (EMH_BOM_error_base + 240)

/** "%1$" was removed, but could not be deleted, because it is used by "%2$". Details: %3$ */
#define BOM_instance_with_named_reference                                     (EMH_BOM_error_base + 241)

/** %1$" was removed, but could not be deleted, because it is used. Details: %2$ */
#define BOM_instance_with_unamed_reference                                    (EMH_BOM_error_base + 242)

/** "%1$" could not be removed because you do not have access to "%2$". Details: %3$ */
#define BOM_line_remove_error                                                 (EMH_BOM_error_base + 243)

/** The property "End Item Assembly State" of the root line "%1$" cannot be set, because the line does not contain any Occurrence. */
#define BOM_cannot_set_end_item_on_root                                       (EMH_BOM_error_base + 244)

/** No object is specified to be added. Please make sure that an object of type Item, Item Revision or General Design Element is provided, and/or that a line of type Iman Item Line or GDE Line is provided. */
#define BOM_no_object_to_add                                                  (EMH_BOM_error_base + 245)

/** An invalid input was provided for adding a substitute. Please make sure that an object of type Item, Item Revision or Iman Item Line is provided. */
#define BOM_invalid_input_for_substitute                                      (EMH_BOM_error_base + 246)

/** The action has failed, because the BOM Line "%1$" contains a null occurrence. Either the BOM Line is stale or it is of an occurrence group. */
#define BOM_line_occ_is_null                                                  (EMH_BOM_error_base + 247)

/** Search for broken link candidates is not supported for properties "%1$". Search will skip these properties.*/
#define BOM_property_not_supported_for_repair_broken_links                    (EMH_BOM_error_base + 248)

/** The configuration of the BOM Window on the Configuration Context cannot be saved, because either the BOM Window or the Configuration Context is not provided. */
#define BOM_configuration_save_error                                          (EMH_BOM_error_base + 249)

/** The required Change Management template is not installed. Please install it and try again. */
#define BOM_missing_change_mgmt_schema                                        (EMH_BOM_error_base + 250)

/** This action requires that a Change Notice Revision object be associated to the BOM Window. */
#define BOM_missing_change_notice_object                                      (EMH_BOM_error_base + 251)

/** This action requires that a Change Notice Revision object be associated to the BOM Window. Please repeat the current action with the revision "%1$/%2$" after associating a Change Notice Revision to the BOM Window. */
#define BOM_missing_change_notice_object_for_add                              (EMH_BOM_error_base + 252)

/** The condition "%1$" on the Change Notice Revision "%2$" cannot be used to verify the access to its impacted and solution folders. Please ensure that the conditions on the Change Notice Revision allow revisions to be added to both folders when it is used to track BOM Window changes. */
#define BOM_cannot_verify_ecn_condition                                       (EMH_BOM_error_base + 253)

/** The condition "%1$" on the Change Notice Revision "%2$" does not have suitable conditions to track BOM Window changes. Please ensure that the conditions on the Change Notice Revision allow revisions to be added to both folders when it is used to track BOM Window changes. */
#define BOM_invalid_ecn_condition_params                                      (EMH_BOM_error_base + 254)

/** The current Bill Of Material (BOM) structure cannot be tracked using a Change Notice Revision. */
#define BOM_ecn_currently_not_applicable                                      (EMH_BOM_error_base + 255)

/** The Item Revision "%1$" is referenced by other instances. Please manually remove the Item Revision from the Change Notice Revision "%2$". */
#define BOM_rev_multiply_referenced                                           (EMH_BOM_error_base + 256)

/** The baseline could not be created, because the smart baseline feature is turned on and there are no changes from the last baseline. */
#define BOM_cannot_create_baseline                                            (EMH_BOM_error_base + 257)

/** Product Configurator-authored Variant Rules cannot be applied when the Product Configurator is disabled. Enable Product Configurator support through the preference "PSM_enable_product_configurator" and try again. */
#define BOM_cannot_apply_product_configurator_authored_vrule                  (EMH_BOM_error_base + 258)

/** Classic Variant Conditions cannot be created, because the Product Configurator-authored Variant Condition already exists. Enable Product Configurator support through the preference "PSM_enable_product_configurator" and try again. */
#define BOM_cannot_create_legacy_variant_condition                            (EMH_BOM_error_base + 259)

/** An invalid Variant Rule is supplied for the Product Configurator mode. Please supply a Product-Configurator-authored Variant Rule. */
#define BOM_invalid_variant_rule_for_pca_mode                                 (EMH_BOM_error_base + 260)

/** The markup cannot be applied to "%1$". */
#define BOM_markup_apply_error                                                (EMH_BOM_error_base + 261)

/**The BOM Line "%1$" formula cannot be merged. This operation will be supported if parent and child have either Product Configurator authored or classic variant formula. */
#define BOM_cannot_remove_line                                                (EMH_BOM_error_base + 262)

/** An invalid input was provided for the Occurrence Type value. The value cannot be empty when the In-Context mode is activated or the value is already In-Context. */
#define BOM_invalid_occtype_context_value                                     (EMH_BOM_error_base + 263)

/** A mixed mode Variant Rule is supplied to the Product Configurator mode. Please supply a Product-Configurator-authored Variant Rule. */
#define BOM_mixed_variant_rule_for_pca_mode                                   (EMH_BOM_error_base + 264)

/** Reconfiguration for Solution Variant is not allowed. */
#define BOM_cannot_reconfigure_solution_variant                               (EMH_BOM_error_base + 265)

/** Cannot open solution variant without configuration context*/
#define BOM_cannot_open_solution_variant_without_configcontext                (EMH_BOM_error_base + 266)

/** The "Clone Structure" operation's post processing has been submitted as an asynchronous job to the dispatcher. */
#define BOM_duplicate_asynchronous_post_process_submitted                     (EMH_BOM_error_base + 267)

/** An invalid combination of duplicate operations was specified between parent "%1$" of operation "%2$" and child "%3$" of operation "%4$". */
#define BOM_duplicate_parent_child_operation_validation_failed                (EMH_BOM_error_base + 268)

/** An invalid combination of duplicate operations was specified between CAD-dependent parent "%1$" of operation "%2$" and child "%3$" of operation "%4$". */
#define BOM_duplicate_CAD_dependent_parent_child_operation_validation_failed  (EMH_BOM_error_base + 269)

/** A duplicate operation type "%1$" specified for the ItemRevision "%2$" is invalid. Valid values are "Clone", "Revise", "Replace" and "Reference". */
#define BOM_duplicate_unknown_operation                                       (EMH_BOM_error_base + 270)

/** All provided BOM Lines are invalid. */
#define BOM_invalid_input_bomlines                                            (EMH_BOM_error_base + 271)

/** The "Save Clone Structure Specifications" operation has failed. Please check the Teamcenter server syslog file for more information. */
#define BOM_save_clone_structure_specifications_failed                        (EMH_BOM_error_base + 272)

/**  Structure partitioning is disabled because the partition template is not installed. Please contact your system administrator. */
#define BOM_no_structure_partitioning                                         (EMH_BOM_error_base + 273)

/** Markup created via mass update cannot be modified outside the Mass Update feature. */
#define BOM_massupdate_cannot_modify_markup                                   (EMH_BOM_error_base + 274)

/**The provided Variant Rules cannot have a mix of Product-Configurator-authored Variant Rules and Classic Variant Rules */
#define BOM_invalid_multiple_variant_rules                                    (EMH_BOM_error_base + 275)

/** No Revision of the Revisable Occurrence of Item "%1$" matches the current Revision Rule. */
#define BOM_no_configured_rev_occ_revision                                    (EMH_BOM_error_base + 276)

/** The specified operation is not supported for Collaborative BOM View Revisions when the display pending edit mode is enabled. */
#define BOM_not_supported_for_collaborative_bvr_in_redline_mode               (EMH_BOM_error_base + 277)

/** "%1$" is an invalid duplicate operation for "%2$" topline. The topline of a structure must be a clone or a revise operation. */
#define BOM_duplicate_operation_invalid                                       (EMH_BOM_error_base + 278)

/** "%1$" is an invalid duplicate option for the duplicate operation. */
#define BOM_duplicate_option_invalid                                          (EMH_BOM_error_base + 279)

/** "%1$" BOM Line has an invalid configurable object. */
#define BOM_invalid_configurable_object                                       (EMH_BOM_error_base + 280)

/** The current user cannot perform the effectivity operation on "%1$", because the BOM Line is locked. */
#define BOM_cannot_perform_effectivity_operation                              (EMH_BOM_error_base + 281)

/** The BOM Window cannot be reconfigured, because it is modified. */
#define BOM_window_modified_no_reconfiguration                                (EMH_BOM_error_base + 282)

/** The type of "%1$" BOM Line is invalid for accountability check based on alignment. The supported types are "Design" for the source object and "Part" for the target object.*/
#define BOM_invalid_type_for_accountability_check                             (EMH_BOM_error_base + 283)

/** A new working revision for the "%1$" occurrence cannot be configured because the BOM Window configuration doesn't prefer working revisions. */
#define BOM_revocc_unable_to_reconfigure_after_auto_revise_split              (EMH_BOM_error_base + 284)

/** A substitute list change for the selected line already exists. A different substitute change cannot be accepted.*/
#define BOM_markup_substitute_prefer                                          (EMH_BOM_error_base + 285)

/** Expected Create Input for "%1$" (or sub-type), but was given "%2$". */
#define BOM_invalid_occ_create_input                                          (EMH_BOM_error_base + 286)

/** Parent object in Occurrence Create Input does not match that of the given Parent BOM Line. */
#define BOM_occ_create_input_parent_mismatch                                  (EMH_BOM_error_base + 287)

/** The BOM Window configuration mode "Overlay" does not support editing of BOM Variant Rule(s). Please change the BOM Window Variant configuration mode to "single rule - single value" or "single rule - multi value" to edit the BOM Variant Rules. */
#define BOM_edit_var_rule_unsupported                                         (EMH_BOM_error_base + 288)

/** BOM Variant Rules or Saved Variant Rules must be provided when applying Variant Rules. */
#define BOM_invalid_input_for_apply                                           (EMH_BOM_error_base + 289)

/** A single Variant Rule cannot be applied if the window is in overlay mode. Multiple Variant Rules are expected in this case. */
#define BOM_fail_to_apply_input_svr                                           (EMH_BOM_error_base + 290)

/** The variant option value entry is either empty or does not exist. */
#define BOM_invalid_option_value                                              (EMH_BOM_error_base + 291)

/** Provide a valid BOM Variant Rule. */
#define BOM_invalid_variant_rule                                              (EMH_BOM_error_base + 292)

/**TODO: This is a temporary error code added at last moment during 12.4 last build. This error should be removed when support is added for PCA variant conditions.*/
/** Insert level not supported for bomlines with PCA variant condition */
#define BOM_insert_level_unsupported_for_PCA_var_formula                      (EMH_BOM_error_base + 293)

/** All the target lines must be under the same parent in order to perform insert level. */
#define BOM_insert_targets_in_multiple_parents                                (EMH_BOM_error_base + 294)

/** Insert level is only supported for collaborative where all target lines have the same Revisable Occurrence Revision Type. */
#define BOM_insert_targets_with_mixed_occ_types                               (EMH_BOM_error_base + 295)

/** Error to indicate that the value given for preference BOM_Additional_Packing_Criteria is incorrect - not a valid property name. */
#define BOM_pack_criteria_pref_value_incorrect                                (EMH_BOM_error_base + 296)

/** Properties cannot be edited because the line is read-only. */
#define BOM_cannot_modify_qty_explode_line                                    (EMH_BOM_error_base + 297)

/** You do not have access to add child line under %1$. */
#define BOM_add_access_denied                                                 (EMH_BOM_error_base + 298)

/** You do not have access to remove lines from %1$. */
#define BOM_remove_access_denied                                              (EMH_BOM_error_base + 299)

/** Editing revision effectivity on a released Occurrence Revision is not supported through BOM Line properties. */
#define BOM_cannot_edit_rev_eff_on_released_occ_rev                           (EMH_BOM_error_base + 300)

/**
    @}
*/

#include <bom/libbom_undef.h>
#endif
