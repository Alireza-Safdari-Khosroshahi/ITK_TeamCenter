/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2016
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Collaborative Design Error Codes Declaration

*/

#ifndef CPD0CD_ERRORS_H
#define CPD0CD_ERRORS_H

#include <common/emh_const.h>
#include <common/tc_deprecation_macros.h>

/**
    @defgroup CPD0CD_ERRORS Errors
    @ingroup CPD0CD
    @{
*/

#define CPD0CD_ERROR_BASE                                   EMH_CPD0CD_error_base

/**
 * An internal error has occurred in the Collaborative Design module.
 */
#define CPD0CD_internal_error                                        ( EMH_CPD0CD_error_base + 1 )

/**
 * The input object &quot;%1$&quot; is not a &quot;reuse&quot; Design Element.
 */
#define CPD0CD_invalid_input_error                                   ( EMH_CPD0CD_error_base + 2 )

/**
 * The source object &quot;%1$&quot; must be a sub-class of Shape Design Revision type (internal name Cpd0ShapeDesignRevision).
 */
#define CPD0CD_sourceobject_type_error                               ( EMH_CPD0CD_error_base + 3 )

/**
 * Reuse of Shape Design objects is not supported.
 */
#define CPD0CD_reuse_shapedesign_error                               ( EMH_CPD0CD_error_base + 4 )

/**
 * The following Shape Design objects are from a different model, therefore they cannot be referenced in this model &quot;%1$&quot;: %2$.
 */
#define CPD0CD_reference_shapedesign_error                           ( EMH_CPD0CD_error_base + 5 )

/**
 * The source object for a Design Control Element (internal name Cpd0DesignControlElement) must be of type
 * Shape Design Revision (internal name Cpd0ShapeDesignRevision).
 */
#define CPD0CD_sourceojcet_type2_error                               ( EMH_CPD0CD_error_base + 6 )

/**
 * The Create Input object cannot be created from the source input.
 */
#define CPD0CD_sourceinput1_error                                    ( EMH_CPD0CD_error_base + 7 )

/**
 * The source input cannot be null for the property &quot;Source Input&quot; (internal name cpd0sourceInput) of the
 * type Shape Design (internal name Cpd0ShapeDesign).
 */
#define CPD0CD_sourceinput2_error                                    ( EMH_CPD0CD_error_base + 8 )

/**
 * The source input for the creation of a Shape Design Revision object is not specified.
 */
#define CPD0CD_sourceinput3_error                                    ( EMH_CPD0CD_error_base + 9 )

/**
 * Design Control Element objects (internal name Cpd0DesignControlElement) must have a source object.
 */
#define CPD0CD_source_error                                          ( EMH_CPD0CD_error_base + 10 )

/**
 * The Item object cannot be found for the Item Revision object &quot;%1$&quot;.
 */
#define CPD0CD_item_error                                            ( EMH_CPD0CD_error_base + 11 )

/**
 * The base class for Design Element State objects cannot be used for the substitute operation.
 * Use a Design Element State of category &quot;%1$&quot;.
 */
#define CPD0CD_substitute1_not_supported                             ( EMH_CPD0CD_error_base + 12 )

/**
 * The following Design Element objects cannot be deleted, because they are checked-out by other users: %1$.
 */
#define CPD0CD_checkedout_error                                      ( EMH_CPD0CD_error_base + 13 )

/**
 * Substitution of a Subordinate Design Element is not supported.
 */
#define CPD0CD_substitute2_not_supported                             ( EMH_CPD0CD_error_base + 14 )

/**
 * Substitution of a Reuse Design Element as Reuse is not supported.
 * Use the &quot;Update&quot; operation instead of the &quot;Substitute&quot; operation in order to change the source object of a Reuse.
 */
#define CPD0CD_substitute3_not_supported                             ( EMH_CPD0CD_error_base + 15 )

/**
 * Substitution of a Shape Design Element as Shape is not supported.
 */
#define CPD0CD_substitute4_not_supported                             ( EMH_CPD0CD_error_base + 16 )

/**
 * The Shape Design object &quot;%1$&quot; cannot be used for a &quot;Substitute&quot; operation because its
 * delegate object is already set.
 */
#define CPD0CD_sourceinput4_error                                    ( EMH_CPD0CD_error_base + 17 )

/**
 * The input source assembly &quot;%1$&quot; contains effectivity data.
 * Carrying forward effectivity data to Design Element is not supported because it requires a manual mapping.
 * Please refer to the Teamcenter Technical Documentation for further information.
 */
#define CPD0CD_source_has_effectivity                                ( EMH_CPD0CD_error_base + 18 )

/**
 * The Subordinate Design Element &quot;%1$&quot; cannot be deleted explicitly.
 * It will be deleted automatically during the update of the Reuse Design Element.
*/
#define CPD0CD_de_cannot_be_deleted                                  ( EMH_CPD0CD_error_base + 19 )

/**
 * A Subordinate Design Element cannot be checked-out individually.
 * Instead, please check-out the associated Reuse Design Element &quot;%1$&quot;.
 */
#define CPD0CD_checkout_subordinate_not_allowed                      ( EMH_CPD0CD_error_base + 20 )

/**
 * A Subordinate Design Element cannot be checked-in individually.
 * Instead, please check-in the associated Reuse Design Element &quot;%1$&quot;.
 */
#define CPD0CD_checkin_subordinate_not_allowed                       ( EMH_CPD0CD_error_base + 21 )

/**
 * The check-out status of a Subordinate Design Element cannot be transferred individually.
 * Instead, please transfer the check-out status from the associated Reuse Design Element &quot;%1$&quot;.
 */
#define CPD0CD_transfer_checkout_on_subordinate_not_allowed          ( EMH_CPD0CD_error_base + 22 )

/**
 * The check-out status of a Subordinate Design Element cannot be cancelled individually.
 * Instead, please cancel the check-out status on the associated Reuse Design Element &quot;%1$&quot;.
 */
#define CPD0CD_cancel_checkout_on_subordinate_not_allowed            ( EMH_CPD0CD_error_base + 23 )

/**
 * The object &quot;%1$&quot; cannot be deleted because it contains children.
 * Please expand the object and delete all its children first.
 */
#define CPD0CD_dme_has_children                                      ( EMH_CPD0CD_error_base + 24 )

/**
 * The attachment of the object type &quot;%1$&quot; is not supported.
 */
#define CPD0CD_objecttype_not_supported                              ( EMH_CPD0CD_error_base + 25 )

/**
 * A Subordinate Design Element cannot be saved-as individually. Instead, please save-as the associated Reuse Design Element.
 */
#define CPD0CD_saveas_subordinate_not_allowed                        ( EMH_CPD0CD_error_base + 26 )

/**
 * A Subordinate Design Element cannot be revised individually. Instead, please revise the associated Reuse Design Element.
 */
#define CPD0CD_revise_subordinate_not_allowed                        ( EMH_CPD0CD_error_base + 27 )

/**
 * A missing attribute group type or relation type has caused a failure while processing pending attachments.
 * Please contact your system administrator.
 */
#define CPD0CD_objecttype_or_relationtype_missing                    ( EMH_CPD0CD_error_base + 28 )

/**
 * The Shape Design Revision and the Shape Design Element behave as a single unit, and therefore one cannot be cut from the other.
 * Deleting the Shape Design Element first, however, will enable deletion of both of them.
 */
#define CPD0CD_source_object_cannot_be_cut                           ( EMH_CPD0CD_error_base + 29 )

/**
 * An object of type "%1$" was encountered, when an object of type "%2$" was expected.
 */
#define CPD0CD_not_design_element_type                               ( EMH_CPD0CD_error_base + 30 )

/**
 * @deprecated #CPD0CD_source_has_quantity_value deprecated in Teamcenter 11.3. Use #RLZ0REALIZATION_source_has_quantity_value instead.
 *
 * At least one BOM Line contains a quantity value on an occurrence.
 * Carrying forward of quantity values to Design Elements is not supported.
 * Please check the syslog file for the list of all such BOM Lines.
 */
#define CPD0CD_source_has_quantity_value                             ( EMH_CPD0CD_error_base + 31 )
TC_DEPRECATED_PREPROCESSOR( "11.3", CPD0CD_source_has_quantity_value, "RLZ0REALIZATION_source_has_quantity_value" )

/**
 * The source object of the Reuse Design Element &quot;%1$&quot; cannot be removed once set, because it would transform the Reuse Design Element into a Promissory Design Element.
 */
#define CPD0CD_cannot_change_source_object                           ( EMH_CPD0CD_error_base + 32 )

/**
 * Subordinate Design Elements cannot be updated individually.
 * Instead, please perform an update Item Realization operation on the associated
 * Reuse Design Element "%1$".
 */
#define CPD0CD_MUR_subordinate_de_not_modifiable                     ( EMH_CPD0CD_error_base + 33 )

/** The Design Element is not modifiable. */
#define CPD0CD_MUR_designelement_not_modifiable                      ( EMH_CPD0CD_error_base + 34 )

/**
 * The Design Element has been checked-out by the user "%1$".
 */
#define CPD0CD_MUR_checkedout_designelement_not_modifiable           ( EMH_CPD0CD_error_base + 35 )

/**
 * The Design Element is not revisable by the current user, because of a copy permissions issue on the object.
 */
#define CPD0CD_MUR_nonrevisable_designelement_not_modifiable         ( EMH_CPD0CD_error_base + 36 )

/**
 * Design Elements of type other than 'Reuse' are not valid for Mass Update Realization operations.
 */
#define CPD0CD_MUR_designelement_type_not_supported                  ( EMH_CPD0CD_error_base + 37 )

/**
 * The Mass Update operation has failed, because the object "%1$" is of type "%2$" and only objects of type "%3$" are supported.
 */
#define CPD0CD_MUR_invalid_object_type                               ( EMH_CPD0CD_error_base + 38 )

/**
 * An internal error has occurred during the Instantiation operation. Please check the Teamcenter server syslog file for more information.
 */
#define CPD0CD_Instantiation_internal_error                          ( EMH_CPD0CD_error_base + 39 )

/**
 * An Item of type "%1$" is not allowed as source object for a Design Element of type "%2$".
 */
#define CPD0CD_item_type_not_allowed_as_source                       ( EMH_CPD0CD_error_base + 40 )

/**
 * A Subordinate Design Element cannot be checked-in individually.
 * Instead, please check-in the associated Model Reuse Design Element &quot;%1$&quot;.
 */
#define CPD0CD_M2M_checkin_subordinate_not_allowed                   ( EMH_CPD0CD_error_base + 41 )

/**
 * A Subordinate Design Element cannot be checked-out individually.
 * Instead, please check-out the associated Model Reuse Design Element &quot;%1$&quot;.
 */
#define CPD0CD_M2M_checkout_subordinate_not_allowed                  ( EMH_CPD0CD_error_base + 42 )

/**
 * The check-out status of a Subordinate Design Element cannot be cancelled individually.
 * Instead, please cancel the check-out status on the associated Model Reuse Design Element &quot;%1$&quot;.
 */
#define CPD0CD_M2M_cancel_checkout_on_subordinate_not_allowed        ( EMH_CPD0CD_error_base + 43 )

/**
 * The check-out status of a Subordinate Design Element cannot be transferred individually.
 * Instead, please transfer the check-out status from the associated Model Reuse Design Element &quot;%1$&quot;.
 */
#define CPD0CD_M2M_transfer_checkout_on_subordinate_not_allowed      ( EMH_CPD0CD_error_base + 44 )

/**
 * An invalid Find Number (%1$) is given for the object "%2$" of type "%3$".
 */
#define CPD0CD_invalid_find_number                                   ( EMH_CPD0CD_error_base + 45 )

/**
 * The Find Number object "%1$" is not associated with any object.
 */
#define CPD0CD_no_primary_for_infoInContext                          ( EMH_CPD0CD_error_base + 46 )

 /**
 * Only Design Model Element objects are allowed by the Instantiation operation.
 */
#define CPD0CD_M2M_only_design_model_elements_allowed                ( EMH_CPD0CD_error_base + 47 )

/**
 * A Subordinate Design Element cannot be released individually.
 * Instead, please release the associated Reuse Design Element &quot;%1$&quot;.
 */
#define CPD0CD_add_release_on_subordinate_not_allowed                ( EMH_CPD0CD_error_base + 48 )

/**
 * Release statuses cannot be removed from a Subordinate Design Element individually.
 * Instead, please remove the status from the associated Reuse Design Element &quot;%1$&quot;.
 */
#define CPD0CD_remove_release_from_subordinate_not_allowed           ( EMH_CPD0CD_error_base + 49 )

/**
 * Release statuses cannot be renamed for a Subordinate Design Element individually.
 * Instead, please rename the associated Reuse Design Element &quot;%1$&quot;.
 */
#define CPD0CD_rename_release_on_subordinate_not_allowed             ( EMH_CPD0CD_error_base + 50 )

/*
 * @deprecated #CPD0CD_cannot_perform_realization_with_var_data deprecated in Teamcenter 11.3. Use #RLZ0REALIZATION_cannot_perform_realization_with_var_data instead.
 *
 * The realization operation has failed because the "Synchronize Variant" option is enabled and
 * the Product Configurator module is not installed. Please contact your system administrator.   
 */
#define CPD0CD_cannot_perform_realization_with_var_data              ( EMH_CPD0CD_error_base + 51 )
TC_DEPRECATED_PREPROCESSOR( "11.3", CPD0CD_cannot_perform_realization_with_var_data, "RLZ0REALIZATION_cannot_perform_realization_with_var_data" )

/**
 * An empty value is not allowed for the 4GD Model name in Populate 4G preview-based
 * Item Realization operations.
 */
#define CPD_4GPopulate_invalid_input_modelname                       ( EMH_CPD0CD_error_base + 52 )

/**
 * An invalid map file is provided for the Populate 4G preview-based Item Realization operation.
 */
#define CPD_4GPopulate_invalid_input_mapfilename                     ( EMH_CPD0CD_error_base + 53 )

/**
 * An invalid input preview file "%1$" is provided for the Populate 4G preview-based
 * Item Realization operation.
 */
#define CPD_4GPopulate_invalid_input_previewfilename                 ( EMH_CPD0CD_error_base + 54 )

/**
 * An unexpected error encountered during the Populate 4G preview-based Item Realization operation.
 * Please contact your system administrator.
 */
#define CPD_4GPopulate_unexpected_error                              ( EMH_CPD0CD_error_base + 55 )

/**
 * An internal error occurred during the Populate 4G preview-based Item Realization operation.
 * Please contact your system administrator.
 */
#define CPD_4GPopulate_realization_error                             ( EMH_CPD0CD_error_base + 56 )

/**
 * An internal error occurred during the Populate 4G save operation on 4GD Objects.
 * Please contact your system administrator.
 */
#define CPD_4GPopulate_save_error                                    ( EMH_CPD0CD_error_base + 57 )

/**
 * An internal error occurred during the Populate 4G tag unload operation on 4GD objects.
 * Please contact your system administrator.
 */
#define CPD_4GPopulate_tagunload_error                               ( EMH_CPD0CD_error_base + 58 )

/**
 * An invalid value is provided for the Item ID in the Populate 4G preview-based Item Realization operation.
 */
#define CPD_4GPopulate_invalid_input_itemid                          ( EMH_CPD0CD_error_base + 59 )

/**
 * A Reuse Design Element corresponding to source installation assembly "%1$" already exists.
 */
#define CPD0CD_reuse_de_exist_with_true_ia                           ( EMH_CPD0CD_error_base + 60 )

/**
 * A Reuse Design Element corresponding to source non-installation assembly "%1$" already exists.
 */
#define CPD0CD_reuse_de_exist_without_true_ia                        ( EMH_CPD0CD_error_base + 61 )

/**
 * An invalid persistent Item property "%1$" is listed in the preference "%2$".
 *
 */
 #define CPD0CD_invalid_item_property_in_preference                  ( EMH_CPD0CD_error_base + 62 )

/**
 * A non-string Item property "%1$" is listed in the preference "%2$".
 *
 */
 #define CPD0CD_non_string_item_property_in_preference               ( EMH_CPD0CD_error_base + 63 )
/**
 * The present configuration is not supported by "Initial Population" functionality,
 * because the revision effectivities on the Item Revision "%1$" are not all
 * identical for all Release Statuses.
 */
#define CPD_4GPopulate_revision_effectivities_do_not_match           ( EMH_CPD0CD_error_base + 64 )

/**
 * The split directory value cannot be empty to perform a Populate 4G split preview-based
 * Item Realization operation.
 */
#define CPD_4GPopulate_empty_input_split_directory                   ( EMH_CPD0CD_error_base + 65 )

/**
 * An internal error has occurred while performing the Populate 4G split preview-based
 * Item Realization operation.
 */
#define CPD_4GPopulate_internal_split_error                          ( EMH_CPD0CD_error_base + 66 )

/**
 * No Revision Rule can be found for the Revision Rule name "%1$" configured in the preference "%2$".
 */
#define CPD_4GPopulate_rev_rule_not_found                            ( EMH_CPD0CD_error_base + 67 )

/**
 * The mandatory preference "%1$" for the Installation Assembly processing is unavailable.
 */
#define CPD_4GPopulate_mandatory_pref_not_available                  ( EMH_CPD0CD_error_base + 68 )

/**
 * The Item ID value cannot be empty to perform a Populate 4G preview-based
 * Item Realization operation.
 */
#define CPD_4GPopulate_empty_input_item_id                           ( EMH_CPD0CD_error_base + 69 )

/**
 * The map file name cannot be empty to perform a Populate 4G preview-based
 * Item Realization operation.
 */
#define CPD_4GPopulate_empty_input_mapfilename                       ( EMH_CPD0CD_error_base + 70 )

/**
 * An error has occurred while parsing the input mapping file "%1$" during the Populate 4G preview-based
 * Item Realization operation.
 */
#define CPD_4GPopulate_mapfilename_parsing_error                     ( EMH_CPD0CD_error_base + 71 )

/**
 * The input preview file name cannot be empty to perform a Populate 4G preview-based
 * Item Realization operation.
 */
#define CPD_4GPopulate_empty_input_previewfilename                   ( EMH_CPD0CD_error_base + 72 )

/**
 * An error has occurred while parsing the input preview file "%1$" during the Populate 4G
 * preview-based Item Realization operation.
 */
#define CPD_4GPopulate_previewfile_parsing_error                     ( EMH_CPD0CD_error_base + 73 )

/**
 * The Populate 4G split preview-based Item Realization operation has failed because the provided
 * directory "%1$" does not exist.
 */
#define CPD_4GPopulate_non_existing_input_split_directory            ( EMH_CPD0CD_error_base + 74 )

/**
 * The Populate 4G split preview-based Item Realization operation has failed because the current user has
 * no write permission on the provided directory "%1$".
 */
#define CPD_4GPopulate_write_access_unavailable_on_split_directory   ( EMH_CPD0CD_error_base + 75 )

/**
 * The initial population Revision Rule "%1$" configured in the "%2$" preference is not
 * a valid Revision Rule for Populate 4G preview-based Item Realization operation.
 */
#define CPD_4GPopulate_invalid_initial_population_rev_rule           ( EMH_CPD0CD_error_base + 77 )

/**
 * The initial population starting effectivity value defined in the preference "%1$"
 * is not in the correct format.
 */
#define CPD_4GPopulate_start_effectivity_incorrect_format            ( EMH_CPD0CD_error_base + 78 )

/**
 * The Collaborative Design "%1$" already exists.
 */
#define CPD_4GPopulate_coll_design_already_existing_error            ( EMH_CPD0CD_error_base + 79 )

/**
 * The value "%1$" specified in the preference "%2$" does not correspond to an existing
 * Effectivity Group Item Revision for the Item ID "%3$".
 */
#define CPD0CD_invalid_effectivity_group_id                          ( EMH_CPD0CD_error_base + 80 )

/**
 * @deprecated #CPD_4GPopulate_coll_design_does_not_exist_error deprecated in Teamcenter 11.6.
 *
 * The Collaborative Design "%1$" does not exist. Please specify an existing Collaborative Design for the update mode.   
 */
#define CPD_4GPopulate_coll_design_does_not_exist_error              ( EMH_CPD0CD_error_base + 81 )
TC_DEPRECATED_PREPROCESSOR( "11.6", CPD_4GPopulate_coll_design_does_not_exist_error, "" )

/**
 * The pre-validation report file name cannot be empty.
 */
#define CPD_4GPopulate_empty_prevalidation_file_name                 ( EMH_CPD0CD_error_base + 82 )

/**
 * The creation of the preview model has failed because no dataset with a map file reference is attached to the Collaborative Design "%1$".
 */
#define CPD_4GPopulate_coll_design_does_not_contain_map_file         ( EMH_CPD0CD_error_base + 83 )

/**
 * The Partition Scheme type "%1$" does not exist.
 */
#define CPD_4GPopulate_partition_scheme_unavailable                  ( EMH_CPD0CD_error_base + 84 )

/**
 * The organization mapping contains the following dynamic partitions, which is not supported by the Populate 4G preview-based Item
 * Realization operation: %1$. Please correct the organization mapping information.
 */
#define CPD_4GPopulate_dynamic_partition_not_supported               ( EMH_CPD0CD_error_base + 85 )

/**
 * The update of the Collaborative Design "%3$" has failed because the top line of its related Item ID "%2$" (relation "Cpd0CollDesignToToplineBVR")
 * does not match the top line Item ID "%1$" in the preview file.
 */
#define CPD_4GPopulate_topline_item_mismatch_error                   ( EMH_CPD0CD_error_base + 86 )

/**
 * The provided object type "%1$" is not a valid Application Model type.
 */
#define CPD_4GPopulate_bo_type_not_of_appmodel_type                  ( EMH_CPD0CD_error_base + 87 )

/**
 * The output file path does not exist.
 */
#define CPD_4GPopulate_invalid_output_directory_path                 ( EMH_CPD0CD_error_base + 88 )

/**
 * The item "%1$" does not contain any associated Configurator Context.
 */
#define CPD_4GPopulate_item_does_not_have_configurator_context       ( EMH_CPD0CD_error_base + 89 )

/**
 * The provided Business Object type "%1$" does not exist.
 */
#define CPD_4GPopulate_bo_type_does_not_exist                        ( EMH_CPD0CD_error_base + 90 )

/**
 * The mapping file "%1$" is ignored because a mapping file "%2$" is already attached to the Collaborative Design "%3$".
 * The latter file is used to generate the preview model.
 */
#define CPD_4GPopulate_ignore_provided_mapping_file                  ( EMH_CPD0CD_error_base + 91 )

/**
 * The Populate 4G split preview-based Item Realization for the Item Assembly "%1$" has completed with some errors. Please check the teamcenter syslog for more details.
 */
#define CPD_4GPopulate_realization_message_for_errors                ( EMH_CPD0CD_error_base + 92 )

/**
 * The Preview Model was generated with the "sync_variant" option set as false because the provided item of ID "%1$" is not associated with any Configurator context.
 */
#define CPD_4GPopulate_reset_variant_sync_warning                    ( EMH_CPD0CD_error_base + 93 )

/**
 * An invalid effectivity date "%1$" is provided for the "Populate 4G preview based Item Realization" operation. Please specify the date using the format "%2$".
 */
#define CPD_4GPopulate_invalid_input_effectivity_date                ( EMH_CPD0CD_error_base + 94 )

/**
 * The source installation assembly "%1$" is neither released, nor does it have a valid up-to-date baseline.
 */
#define CPD_source_object_not_valid_for_sharing                      ( EMH_CPD0CD_error_base + 95 )

/**
 * An invalid release date "%1$" is provided for the "Populate 4G preview based Item Realization" operation. Please specify the date using the format "%2$".
 */
#define CPD_4GPopulate_invalid_release_date                          ( EMH_CPD0CD_error_base + 96 )

/**
 * The Reuse Design Component "%1$" is not in sync with source installation assembly "%2$", which has either added or removed BOM lines. Please perform "Update Design Component" on Reuse Design Component before sharing "Change Notice Revision".
 */
#define CPD_reuse_not_in_sync_for_sharing                            ( EMH_CPD0CD_error_base + 97 )

/**
 * A valid object of type Item Revision or Promissory Design Element must be provided.
 */
#define CPD_invalid_input_tag                                        ( EMH_CPD0CD_error_base + 98 )

/**
 * Duplicate keys are provided, which is not supported.
 */
#define CPD_duplicate_keys                                           ( EMH_CPD0CD_error_base + 99 )

/**
 * "%1$" is not a supported key.
 */
#define CPD_invalid_key                                              ( EMH_CPD0CD_error_base + 100 )

/**
 * A valid object of type Reuse Design Element must be provided.
 */
#define CPD_invalid_input_tag_for_substitute_as_prom                 ( EMH_CPD0CD_error_base + 101 )

/**
 * The source object of Promissory Design Element "%1$" cannot be set to any value except NULLTAG.
 */
#define CPD0CD_cannot_change_source_object_for_prom                  ( EMH_CPD0CD_error_base + 102 )

/**
 * The Release Status "%1$" cannot be found. Please specify a valid Release Status to snapshot 4G design components created or updated using "4G Populate".
 */
#define CPD_4GPopulate_invalid_release_status_specified              ( EMH_CPD0CD_error_base + 103 )

/**
 * The update of the Collaborative Design with Partition Scheme "%3$" has failed because the top line item ID "%2$" related to the Partition Scheme does not match the top line item ID "%1$" in the preview file.
 */
#define CPD_4GPopulate_topline_item_with_scheme_mismatch_error       ( EMH_CPD0CD_error_base + 104 )

/**
 * An invalid map file is provided for the multisource mode of populate 4G. The provided map file is missing the required Partition Scheme.
 */
#define CPD_4GPopulate_invalid_input_mapfile_for_multisource         ( EMH_CPD0CD_error_base + 105 )

/**
 * An invalid Product Design was provided for the multisource mode of populate 4G. "%1$" Product Design which was created using normal mode was provided for the multisource mode.
 */
#define CPD_4GPopulate_invalid_product_design_for_multisource_mode   ( EMH_CPD0CD_error_base + 106 )

/**
 * An invalid Product Design was provided for the normal mode of populate 4G. "%1$" Product Design which was created using multisource mode was provided for the normal mode.
 */
#define CPD_4GPopulate_invalid_product_design_for_normal_mode        ( EMH_CPD0CD_error_base + 107 )

/**
 * A duplicate realization of the source BVR was found in scheme "%1$". A source structure cannot be realized under multiple partition schemes with multisource mode.
 */
#define CPD_4GPopulate_duplicate_realization_found_in_product_design ( EMH_CPD0CD_error_base + 108 )

/**
    @}
*/

#endif
