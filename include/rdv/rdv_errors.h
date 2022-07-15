/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Error codes returned by the RDV ITK module
*/

/*  */

#ifndef RDV_ERRORS_H
#define RDV_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup RDV_ERRORS Errors
    @ingroup RDV
    @{
*/

#define RDV_invalid_installation                     (EMH_RDV_error_base +   0)
#define RDV_invalid_composite_prop_name              (EMH_RDV_error_base +   1)
#define RDV_invalid_composite_prop_type              (EMH_RDV_error_base +   2)
#define RDV_cannot_add_null_tag                      (EMH_RDV_error_base +   3)
#define RDV_maximum_exceeded                         (EMH_RDV_error_base +   4)
#define RDV_context_not_searchable                   (EMH_RDV_error_base +   5)
#define RDV_invalid_context                          (EMH_RDV_error_base +   6)
#define RDV_illegal_parameter                        (EMH_RDV_error_base +   7)
#define RDV_object_not_found                         (EMH_RDV_error_base +   8)
#define RDV_export_nx_no_parts                       (EMH_RDV_error_base +   9)
#define RDV_error_in_nxclone                         (EMH_RDV_error_base +   10)
#define RDV_cannot_create_file                       (EMH_RDV_error_base +   11)
#define RDV_input_log_does_not_exist                 (EMH_RDV_error_base +   12)
#define RDV_cannot_create_directory                  (EMH_RDV_error_base +   13)
#define RDV_error_in_nxmgr_selective_export          (EMH_RDV_error_base +   14)
#define RDV_error_compress_failure                   (EMH_RDV_error_base +   15)
#define RDV_cannot_initialize_search_criteria        (EMH_RDV_error_base +   16)
#define RDV_cannot_instantiate_class                 (EMH_RDV_error_base +   17)
#define RDV_cannot_save_search_criteria_obj          (EMH_RDV_error_base +   18)
#define RDV_cannot_refresh_search_criteria_obj       (EMH_RDV_error_base +   19)
#define RDV_cannot_lock_search_criteria_obj          (EMH_RDV_error_base +   20)
#define RDV_cannot_cannot_unlock_search_criteria_obj (EMH_RDV_error_base +   21)
#define RDV_cannot_set_search_criteria_attr          (EMH_RDV_error_base +   22)
#define RDV_cannot_retrieve_attr                     (EMH_RDV_error_base +   23)
#define RDV_cannot_find_object                       (EMH_RDV_error_base +   24)
#define RDV_cannot_delete_object                     (EMH_RDV_error_base +   25)
#define RDV_cannot_find_bvr                          (EMH_RDV_error_base +   26)
#define RDV_duplicate_nve_found_with_content         (EMH_RDV_error_base +   27)
#define RDV_cannot_create_nve_with_null_ve           (EMH_RDV_error_base +   28)
#define RDV_duplicate_nve_found_with_code            (EMH_RDV_error_base +   29)
#define RDV_var_exp_hierarchy_too_deep               (EMH_RDV_error_base +   30)
#define RDV_var_exp_tree_too_many_nodes              (EMH_RDV_error_base +   31)
#define RDV_var_opt_no_revision                      (EMH_RDV_error_base +   32)
#define RDV_var_exp_opcode_no_opposite               (EMH_RDV_error_base +   33)
#define RDV_var_exp_opcode_unknown                   (EMH_RDV_error_base +   34)
#define RDV_var_exp_not_satisfiable                  (EMH_RDV_error_base +   35)
#define RDV_no_named_variant_expression              (EMH_RDV_error_base +   36)
#define RDV_var_exp_table_redundant_cols             (EMH_RDV_error_base +   37)
#define RDV_var_exp_duplicate_content                (EMH_RDV_error_base +   38)
#define RDV_part_br_check_fail                       (EMH_RDV_error_base +   39)
#define RDV_occ_br_check_fail                        (EMH_RDV_error_base +   40)
#define RDV_touchpoint_failed                        (EMH_RDV_error_base +   41)
#define RDV_overlapping_nve_detected                 (EMH_RDV_error_base +   42)
#define RDV_variability_is_in_use                    (EMH_RDV_error_base +   43)
#define RDV_no_overlap_with_variability              (EMH_RDV_error_base +   44)
#define RDV_outside_variability_limits               (EMH_RDV_error_base +   45)
#define RDV_variability_unavailable                  (EMH_RDV_error_base +   46)
#define RDV_variability_unavailable_in_context       (EMH_RDV_error_base +   47)
#define RDV_default_revrule_not_found                (EMH_RDV_error_base +   48)
#define RDV_var_exp_invalid                          (EMH_RDV_error_base +   49)

#define ARCH_duplicate_generic_id                    (EMH_RDV_error_base +   50)
#define ARCH_incomptable_type                        (EMH_RDV_error_base +   51)
#define ARCH_instance_already_member                 (EMH_RDV_error_base +   52)
#define ARCH_not_breakdown_element                   (EMH_RDV_error_base +   53)
#define ARCH_multiple_breakdown_element              (EMH_RDV_error_base +   54)
#define ARCH_unconfigured_breakdown_element          (EMH_RDV_error_base +   55)
#define ARCH_target_context_failed                   (EMH_RDV_error_base +   56)
#define RDV_invalid_data_entered                     (EMH_RDV_error_base +   57) 
#define ARCH_no_result_for_prod_query                (EMH_RDV_error_base +   58)
#define ARCH_not_existing_prod_query                 (EMH_RDV_error_base +   59)

#define RDV_preference_has_no_value                  (EMH_RDV_error_base +   70)
#define RDV_nve_remotely_owned                       (EMH_RDV_error_base +   90)
#define RDV_cannot_create_apr                        (EMH_RDV_error_base +   91)
#define RDV_invalid_sco_tag                          (EMH_RDV_error_base +   92)
#define RDV_no_revision_rule                         (EMH_RDV_error_base +   93)

/*Error messages used in Global RDV*/
#define RDV_auditlines_notfound                      (EMH_RDV_error_base +   100)
#define RDV_cannot_open_file                         (EMH_RDV_error_base +   101)
#define RDV_garbage_at_end                           (EMH_RDV_error_base +   102)

/*Error messages used in Adhoc Configurator*/
#define RDV_unconfig_plmxml_not_found_in_dataset     (EMH_RDV_error_base +   105)
#define RDV_VAS_not_defined_global_option            (EMH_RDV_error_base +   106)

/*Error messages used for retry lock mechanism*/
#define RDV_invalid_TC_retry_time                    (EMH_RDV_error_base +   107)
#define RDV_invalid_TC_max_number_of_retries         (EMH_RDV_error_base +   108)
#define RDV_failed_to_lock                           (EMH_RDV_error_base +   109)
#define RDV_cannot_create_topline_absoccdata_object  (EMH_RDV_error_base +   110)

/* Error messages for invalid view type */
#define RDV_invalid_view_type                        (EMH_RDV_error_base +   111)

/* Error messages for NVE meta-expressions */
#define RDV_null_nve_tag                             (EMH_RDV_error_base +   200)
#define RDV_variant_expr_is_not_meta_expr            (EMH_RDV_error_base +   201)
#define RDV_token_is_not_nve                         (EMH_RDV_error_base +   202)
#define RDV_token_is_out_of_range                    (EMH_RDV_error_base +   203)
#define RDV_invalid_nve_reference                    (EMH_RDV_error_base +   204)
#define RDV_bracket_mismatch                         (EMH_RDV_error_base +   205)
#define RDV_nve_ref_expected                         (EMH_RDV_error_base +   206)
#define RDV_balancing_mismatch                       (EMH_RDV_error_base +   207)
#define RDV_meta_expr_syntax_error                   (EMH_RDV_error_base +   208)
#define RDV_invalid_meta_expr                        (EMH_RDV_error_base +   209)
#define RDV_meta_expr_always_true                    (EMH_RDV_error_base +   210)
#define RDV_meta_expr_always_false                   (EMH_RDV_error_base +   211)
#define RDV_cannot_modify_nve                        (EMH_RDV_error_base +   212)
#define RDV_cannot_find_Architecture                 (EMH_RDV_error_base +   213)
#define RDV_special_chars_in_code                    (EMH_RDV_error_base +   214)
/* Error messages for query_scos, rdvcontextdbdownload/rdv_contextnondbdownload  Translators */
#define RDV_invalid_input                            (EMH_RDV_error_base +   215)
#define RDV_invalid_tc_plmxml_sync_dataset_preference (EMH_RDV_error_base +   216)
#define RDV_cannot_save_sco_without_ownership        (EMH_RDV_error_base +   217)
#define RDV_cannot_find_ABE                          (EMH_RDV_error_base +   218)

/** The object "%1$" could not be exported to PLMXML because its data is corrupted. Please contact your system administrator. */
#define RDV_plmxml_export_error                      (EMH_RDV_error_base +   219)

/** The element "%1$" could not be imported from PLMXML, because its data is corrupted. Please check the plmxml file and contact your system administrator. */
#define RDV_plmxml_import_error                      (EMH_RDV_error_base +   220)

/** The logged-in user does not have permission to import the object "%1$". */
#define RDV_import_permission_issue                  (EMH_RDV_error_base +   221)

/** The validation for the object "%1$" has failed because of data corruption. Please contact your system administrator. */
#define RDV_invalid_object                           (EMH_RDV_error_base +   222)

/** The Structure Context Object (SCO) cannot be saved with Absolute Path Nodes (APN), because the ownership of a top line (Product Item) is not transferred from the owning site. Please set the value of preference "RDV_CREATE_SCO_WITHOUT_APN" to "true" in order to create the SCO on the replicated product. */
#define RDV_cannot_save_sco_without_topline_ownership (EMH_RDV_error_base +   223)

/** The object &quot;%1$&quot; is an invalid recipe container object. */
#define RDV_invalid_recipe_container                  (EMH_RDV_error_base +   224)

/** The "Persist Results" functionality is not supported in this release. */
#define RDV_persist_results_not_supported             (EMH_RDV_error_base +   225)

/** Multiple search criteria groups are associated to the context "%1$". */
#define RDV_sco_has_multiple_search_criteria          (EMH_RDV_error_base +   226)

/** Multiple products are associated to the context "%1$". */
#define RDV_sco_has_multiple_products                 (EMH_RDV_error_base +   227)

/** Invalid content is associated with "%1$". */
#define RDV_invalid_content                           (EMH_RDV_error_base +   228)

/** A valid object of type "%1$" must be provided. */
#define RDV_invalid_input_object                      (EMH_RDV_error_base +   229)

/** The filter recipe could not be read correctly. */
#define RDV_cannot_read_recipe                        (EMH_RDV_error_base +   230)

/** The json expression input is invalid. */
#define RDV_invalid_json                              (EMH_RDV_error_base +   231)

/** The filter recipe input is invalid. */
#define RDV_invalid_recipe                            (EMH_RDV_error_base +   232)

/** The filter recipe could not be created correctly. */
#define RDV_cannot_create_recipe                      (EMH_RDV_error_base +   233)

/** An internal error has occurred in the RDV module.*/
#define RDV_internal_error                            (EMH_RDV_error_base +   234)

/** No product is associated with the context "%1$". */
#define RDV_context_has_no_product_associated         (EMH_RDV_error_base +   235)

/** The Product Structure cannot be added to the Session because it is invalid. Valid structures are of type Structure Context, BOM Window, BOM Line, Item, Item Revision or PS BOM View Revision. */
#define RDV_appsess_invalid_product_structure_object  (EMH_RDV_error_base +   236)

/** No stable ID "%1$" is found as associated to the application Session "%2$". */
#define RDV_appsess_object_with_matching_stable_id_not_found     (EMH_RDV_error_base +   237)

/** Input structure context "%1$" is not found associated to the application Session "%2$". */
#define RDV_appsess_structure_not_found_associated_with_session  (EMH_RDV_error_base +   238)

/** NULL structure context provided as input. Provide valid structure context object. */
#define RDV_appsess_null_structure_context                       (EMH_RDV_error_base +   239)

/** Invalid structure context type object as input. Valid structure context types are VisStructureContext and Fnd0StructureContext. */
#define RDV_appsess_invalid_structure_context                    (EMH_RDV_error_base +   240)

/** Empty stable ID provided as input. Provide valid stable ID. */
#define RDV_appsess_empty_stable_id                              (EMH_RDV_error_base +   241)

/** Could not create VisStructureContext to associate with VisManagedDocument relation. */
#define RDV_appsess_vissco_creation_error                        (EMH_RDV_error_base +   242)

/** The input tag for the Application Session Object is invalid. */
#define RDV_appsess_invalid_session_tag                          (EMH_RDV_error_base +   243)

/** The operation is blocked to maintain integrity of Application Session associated with VisStructureContext. */
#define RDV_appsess_invalid_operation                            (EMH_RDV_error_base +   244)

/** Combined varint condtion is not valid. */
#define RDV_combined_variant_condition_invalid                   (EMH_RDV_error_base +   245)

/** Invalid operation on Fnd0TempAppSession. Can not add multiple products to Temporary Application Session. */
#define RDV_tempappsess_invalid_add_operation                    (EMH_RDV_error_base +   246)

/** The Product Structure cannot be added to the Temporary Session because it is invalid. Fnd0StructureContext is the only valid structure type for Temporary Application Session. */
#define RDV_tempappsess_invalid_product_structure_object         (EMH_RDV_error_base +   247)

/** @} */
#endif
