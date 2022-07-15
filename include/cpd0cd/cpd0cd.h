/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2017
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This header file declares all functions,  data types and constants to be used by 4th Generation Designer.

*/

#ifndef CPD0CD_CPD0CD_H
#define CPD0CD_CPD0CD_H

#include <common/tc_deprecation_macros.h>
#include <cpd0cd/libcpd0cd_exports.h>
/**
    @defgroup CPD0CD 4th Generation Design (4GD)
    @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
   This is the size of 4th Generation Designer (4gd) matrices. Double arrays should be this big for 4th generation designer functions.
*/
#define CPD0CD_MATRIX_SIZE 16

/**
 * Provides an information to create preview file
 */
typedef struct CPD_target_model_create_input_s
{
    char* src_item_id;          /**< Mandatory argument - Item ID of the top line of the source Item-BVR Assembly */
    char* src_item_revision;    /**< Optional argument  - Item Revision ID of the top line of the source Item-BVR Assembly.
                                                          <br/>If not provided or invalid, the latest Revision is used.*/
    char* target_model_name;    /**< Mandatory argument - Name of 4GD Model to be created */
    int   partition_level;      /**< Optional argument  - Levels of default partition to be created ignoring the input mapping file.
                                                          To create 4G Model based on mapping file use default value -1.*/
    char* target_model_type;    /**< Optional argument  - Type of the 4GD Model which needs to be created */
    char* date_effectivity;     /**< Optional argument  - Input date in DD-MM-YYYY format which needs to be appended to the revision rule
                                                          for the input source structure expansion */
    int   unit_effectivity;     /**< Optional argument  - Input unit effectivity which needs to be appended to the revision rule
                                                          for the input source structure expansion */
    char* end_item_id;          /**< Optional argument  - Item ID of the end item which needs to be appended to the revision rule
                                                          for the input source structure expansion */
    char* release_date;         /**< Optional argument  - Release Date in DD-MM-YYYY format which needs to be appended to the revision rule
                                                          for the input source structure expansion based on the release date of the structure */
} CPD_target_model_create_input_t;


/**
Updates the Reuse Design Element and optionally its Subordinates in a Collaborative Design using the provided source Item Assembly.

@returns
<ul>
<li>#ITK_ok on success.
<li>#MDL0MODEL_object_has_no_status in case where the source Item Revision is not having a release status.
</ul>
*/
extern CPD0CD_API int CPD_update_item_realization2(
    tag_t          reuse_de_tag,                 /**< (I) Reuse Design Element Tag */
    tag_t          item_rev_tag,                 /**< (I) Optional Tag of the Item Revision for the source Item Assembly needed if new Source Assembly is selected for update */
    logical        sync_effectivity_expressions, /**< (I) Flag set to true to update Effectivity Expressions on Reuse Design Element structure*/
    logical        sync_variant_expressions,     /**< (I) Flag set to true to update Variant Expressions on Reuse Design Element structure*/
    logical        update_subordinates,          /**< (I) Flag set to true to update Subordinate Design Elements else set to false*/
    int*           num_added_subordinates,       /**< (O) Number of added Subordinate Design Elements after update Realization */
    tag_t**        added_subordinates,           /**< (OF) num_added_subordinates Added Subordinate Design Element tags after update Realization */
    int*           num_updated_subordinates,     /**< (O) Number of updated Subordinate Design Elements after update Realization */
    tag_t**        updated_subordinates,         /**< (OF) num_updated_subordinates Updated Subordinate Design Element tags after update Realization */
    int*           num_removed_subordinates,     /**< (O) Number of removed Subordinate Design Elements after update Realization */
    tag_t**        removed_subordinates          /**< (OF) num_removed_subordinates Removed Subordinate Design Element tags after update Realization */
);

/**
For each input Reuse Design Element, creates a baseline of the source Item Revision and updates the
Reuse Design Element to make the baseline its source Item Revision. Any Subordinates of the Reuse
Design Element will also be updated accordingly.

@returns
<ul>
<li>#ITK_ok on success.
<li>#CPD0CD_invalid_input_error if any member of @p reuse_tags is not a Reuse Design Element.
</ul>
*/
extern CPD0CD_API int CPD_baseline_and_update_item_realization(
    const unsigned int    n_reuses,      /**< (I) Number of Reuse Design Elements to update */
    const tag_t* reuse_tags,             /**< (I) n_reuses The Reuse Design Elements to update */
    const char*  baseline_process        /**< (I) Name of the workflow process to be used for baselining */
);
/**
Constructs a reuse design element create input.
The process to make a reuse element is:
<ol>
    <li>constructs create input
    <li>Add any other attributes to element
    <li>TCTYPE_create_object (input, reuse object)
</ol>

@returns
<ul>
<li>#ITK_ok on success.
<li>#PROP_invalid_object if the reuse element input is a NULLTAG.
</ul>
*/
extern CPD0CD_API int CPD0CD_construct_reuse_element_create_input (
    tag_t cd,                                   /**< (I) owning collaborative design */
    tag_t item_rev,                             /**< (I) existing item revision*/
    tag_t bv_type,                              /**< (I) The type of BOM view to use when configuring
                                                   structure below item revision (if NULL_TAG,
                                                   then the default view type will be used) */
    tag_t revision_rule,                        /**< (I) revision rule to use when configuring
                                                   structure below item revision (if NULL_TAG,
                                                   then default revision rule will be used) */
    const char *de_id,                          /**< (I) unique design element id to assign */
    tag_t de_type,                              /**< (I) Type of design element to create (if NULL_TAG, then Cpd0DesignElement will be used). */
    const char *de_name,                        /**< (I) The name for new design element */
    const double transform[CPD0CD_MATRIX_SIZE], /**< (I)transformation into collaborative design */
    const char *logical_designator,             /**< (I)attribute to label design element */
    tag_t *de_create_input                      /**< (O) tag of new design element create input */
);

/**
Constructs a shape design element input.
The process to make a shape element is:
<ol>
    <li>constructs create input
    <li>Add any other attributes to element
    <li>TCTYPE_create_object (input, shape object)
</ol>

@returns
<ul>
<li>#ITK_ok on success.
<li>#PROP_invalid_object if the shape element input is a NULLTAG.
</ul>
*/
extern CPD0CD_API int CPD0CD_construct_shape_element_create_input (
    tag_t cd,                       /**< (I) owning collaborative design */
    tag_t de_type,                  /**< (I) Type of design element to create */
    const char *de_id,              /**< (I) ID of new design element; if null or empty,
                                       a new ID will be automatically generated during creation */
    const char *de_name,            /**< (I) name for new design element */
    const double transform[16],     /**< (I) transformation into collaborative design */
    const char *logical_designator, /**< (I) logical designator for the design element (can be empty) */
    tag_t *de_create_input          /**< (O) tag of new design element create input */
);

/**
Constructs a promissory element input.
The process to make a promissory element is:
<ol>
    <li>constructs create input
    <li>Add any other attributes to element
    <li>TCTYPE_create_object (input, promissory object)
</ol>

@returns
<ul>
<li>#ITK_ok on success.
<li>#PROP_invalid_object if the promissory element input is a NULLTAG.
</ul>
*/
extern CPD0CD_API int CPD0CD_construct_promissory_element_create_input (
    tag_t cd,                        /**< (I) owning collaborative design */
    tag_t de_type,                   /**< (I) Type of design element to create */
    const char *de_id,               /**< (I) ID of new design element; if null or empty,
                                        a new ID will be automatically generated during creation */
    const char *de_name,             /**< (I) name for new design element */
    const char *logical_designator,  /**< (I) logical designator for the design element (can be empty) */
    tag_t *de_create_input           /**< (O) tag of new design element create input */
);

/**
@deprecated #CPD0CD_substitute_as_reuse_design_element deprecated in Teamcenter 11.6. Use #CPD0CD_substitute_as_reuse_with_configuration instead.

Converts a Promissory Design Element to a Reuse Design Element with a source object as the Item/Design Revision.
@returns
<ul>
<li>#ITK_ok on success.
<li>#CPD_invalid_input_tag if @p item_revision or @p design_element is invalid or #NULLTAG
<li>#CPD0CD_substitute3_not_supported if @p design_element is a Reuse Design Element instead of a Promissory one.
</ul>   
*/
TC_DEPRECATED("11.6","CPD0CD_substitute_as_reuse_design_element","CPD0CD_substitute_as_reuse_with_configuration")
extern CPD0CD_API int CPD0CD_substitute_as_reuse_design_element (
    const tag_t item_revision,             /**< (I)  Item Revision Tag of the source Item of the new Reuse Design Element */
    const tag_t design_element             /**< (I)  The Promissory Design Element to be converted */
);

/**
Converts a Promissory Design Element to a Reuse Design Element with a source object as the Item/Design Revision and the configuration context.
@returns
<ul>
<li>#ITK_ok on success.
<li>#CPD_invalid_input_tag if @p item_revision or @p design_element is invalid or #NULLTAG.
<li>#CPD_invalid_input_tag if @p configuration_context is invalid.
<li>#CPD0CD_substitute3_not_supported if @p design_element is a Reuse Design Element instead of a Promissory one.
</ul>
*/

extern CPD0CD_API int CPD0CD_substitute_as_reuse_with_configuration (
    const tag_t item_revision,             /**< (I)  Item Revision Tag of the source Item of the new Reuse Design Element */
    const tag_t design_element,            /**< (I)  The Design Element to be converted */
    const tag_t configuration_context      /**< (I)  The configuration context used to set the properties on the Design Item Instance of the Reuse */
);

/**
Converts a Reuse Design Element to a Promissory Design Element.
@returns
<ul>
<li>#ITK_ok on success.
<li>#CPD_invalid_input_tag_for_substitute_as_prom if @p design_element is invalid or #NULLTAG.
<li>#CPD0CD_substitute1_not_supported if @p design_element is other than Reuse.
</ul>
*/

extern CPD0CD_API int CPD0CD_substitute_as_promissory_design_element (
    const tag_t design_element             /**< (I)  The Reuse Design Element to be converted */
);

/**
Returns the list of all subordinates for a Design Element.
This routine will find the immediate children and all sub level children for the Design Element.

@returns
<ul>
<li>#ITK_ok on success.
<li>#CPD0CD_internal_error if the expected subordinates could not be found (invalid data condition).
<li>#CXPOM_invalid_tag if the DE tag is invalid.
</ul>
*/

extern CPD0CD_API int CPD0CD_ask_design_element_all_subordinates(
    tag_t design_element,            /**< (I) Tag of a design element, */
    int* sub_count,                  /**< (O) count of subordinate tags */
    tag_t **subordinates             /**< (OF) sub_count Tags of subordinate objects */
);

/**
Retrieves the list of Cpd0InfoInContext Attribute Groups corresponding to each of the Design Subset Content.
<br>These numbers map one to one with the objects returned in the parameter @p content_objs.
<br>These Attribute Groups wil contain the Find Number values.

@returns
<ul>
<li>#ITK_ok on success.
<li>#CPD0CD_internal_error if the expected subordinates could not be found (invalid data condition).
<li>#CXPOM_invalid_tag if the DSE tag is invalid.
</ul>
*/

extern CPD0CD_API int CPD_get_subset_find_numbers(
    tag_t dse_tag,                  /**< (I) Tag of a Design Subset Element */
    int* n_content_objs,            /**< (O) Number of subset content objects being returned  */
    tag_t** content_objs,             /**< (OF) n_content_objs Array of tags of the Design Subset Element content */
    tag_t** info_in_context_objs      /**< (OF) n_content_objs List of Cpd0InfoInContext Attribute Groups corresponding to each of the Design Subset Content */
);


/**
@deprecated #CPD0CD_create_model_preview_file deprecated in Teamcenter 11.5. Use #CPD0CD_create_model_preview_from_input instead.

Creates 4GD Model XML preview file for the source Item BVR Assembly (@p create_information (@p src_item_id)) based upon a predefined mapping (@p map_file).
<br/>The XML mapping file maps BOMLines attributes to 4GD attributes.

@returns
<ul>
<li>#ITK_ok on success.
<li>#CPD_4GPopulate_empty_input_item_id if (@p create_information (@p src_item_id)) is a 0-pointer or an empty string.
<li>#CPD_4GPopulate_invalid_input_itemid if (@p create_information (@p src_item_id)) points to a non-existent Item.
<li>#CPD_4GPopulate_invalid_input_modelname if  (@p create_information (@p target_model_name)) is a 0-pointer
    or an empty string.
<li>#CPD_4GPopulate_empty_input_mapfilename if @p map_file is a 0-pointer or an empty string.
<li>#CPD_4GPopulate_invalid_input_mapfilename if @p map_file points to a non-existent mapping file.
<li>#CPD_4GPopulate_mapfilename_parsing_error if @p map_file points to a existing mapping file
    containing invalid details as per "MappingXMLSchema.xsd".
<li>#CPD_4GPopulate_empty_input_previewfilename if @p preview_file_name is a 0-pointer or
    an empty string.
<li>#CPD_4GPopulate_invalid_initial_population_rev_rule if the "CPD_4GPopulate_RevisionRule" preference is configured
    with a revision rule that is not supported by the multiple revision support functionality.
<li>#CPD_4GPopulate_start_effectivity_incorrect_format if the mandatory "CPD_4GPopulate_StartingEffectivity"
    preference is configured with an incorrect format.
<li>#CPD_4GPopulate_rev_rule_not_found if the "CPD_4GPopulate_RevisionRule" preference is configured with a
    revision rule name for which actual Revision Rule object is not available.
<li>#CPD_4GPopulate_mandatory_pref_not_available if the mandatory "CPD_4GPopulate_RevisionRule" and
    "CPD_4GPopulate_StartingEffectivity" preferences are not available.
<li>#CPD0CD_reuse_de_exist_with_true_ia if a Reuse Design Element is already realized for
    the input source Installation Assembly Item Revision  @p create_information (@p src_item_id,  @p src_item_revision).
<li>#CPD0CD_reuse_de_exist_without_true_ia if a Reuse Design Element is already realized for
    the input source non-Installation Assembly Item Revision @p create_information (@p src_item_id, @p src_item_revision).
<li>#CPD0CD_invalid_effectivity_group_id if the Item ID value specified in the preference
    "CPD_4GPopulate_effectivity_group" does not correspond to an existing Effectivity Group Item Revision.
<li>#CPD_4GPopulate_dynamic_partition_not_supported if the Organization mapping table contains a Partition
    type name which is of dynamic Partition Type.
<li>#CPD_4GPopulate_invalid_output_directory_path if @p preview_file_name provided to generate model preview
    file does not exist.
<li>#CPD_4GPopulate_ignore_provided_mapping_file warning if the Collaborative Design @p create_information (@p target_model_name )
    has Mapping file attached with "IMAN_specification" relation.
<li>#CPD_4GPopulate_reset_variant_sync_warning warning if the is_sync_variant flag of input map_file @p map_file( @ is_sync_variant ) is true
    but the provided item of create_information @p create_information (@p src_item_id, @p src_item_revision) is not associated with any Configurator context.
<li>#CPD_4GPopulate_invalid_input_effectivity_date if the specified date (parameter @c date_effectivity of @p create_information) is in an invalid format.
<li>#CPD_4GPopulate_invalid_release_date if the specified date (parameter @c release_date of @p create_information) is in an invalid format.
</ul> 
*/
TC_DEPRECATED("11.5","CPD0CD_create_model_preview_file","CPD0CD_create_model_preview_from_input")
extern CPD0CD_API int CPD0CD_create_model_preview_file(
    const CPD_target_model_create_input_t* create_information, /**< (I) Source Item Revision and Target Model Information for create */
    const char* revision_rule,                                /**< (I) Revision Rule used to configure the input source Item BVR Assembly (@p create_infromation (@p  src_item_id)).
                                                                 <br/>If not provided, the latest working Revision Rule is used.*/
    const char* map_file,                                     /**< (I) Path of the Mapping XML file to define mapping between BVR types and 4GD types */
    const char* preview_file_name                             /**< (I) Path of the 4GD Mode Preview XML file name */
);

/**
Creates 4GD Model XML preview file for the source Item BVR Assembly (@p create_information (@p src_item_id)) based upon a predefined mapping (@p map_file).
<br/>The XML mapping file maps BOMLines attributes to 4GD attributes.

<table>
    <tr>
        <th>Valid Keys</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>map_file</td>
        <td>Path to the XML file that defines the mapping between Bom View Revision (BVR) types and 4GD types.</td>
    </tr>
    <tr>
        <td>preview_file_name</td>
        <td>Path to the 4GD model preview XML file.</td>
    </tr>
    <tr>
        <td>revision_rule</td>
        <td>Revision Rule name used to configure the input source Item BVR (which is the @p src_item_id in @p create_information).
If not provided, the latest working Revision Rule is used.</td>
    </tr>
    <tr>
        <td>override_folder</td>
        <td>Override folder name used to configure the input source Item BVR (which is the @p src_item_id in @p create_information) </td>
    </tr>
</table>

@returns
<ul>
<li>#ITK_ok on success.
<li>#CPD_invalid_key if @p key_array contains an invalid key.
<li>#CPD_duplicate_keys if @p key_array contains duplicate keys.
<li>#CPD_4GPopulate_empty_input_item_id if @p src_item_id in @p create_information is a null pointer or an empty string.
<li>#CPD_4GPopulate_invalid_input_itemid if @p src_item_id in @p create_information points to a non-existent Item.
<li>#CPD_4GPopulate_invalid_input_modelname if @p target_model_name in @p create_information is a null pointer
    or an empty string.
<li>#CPD_4GPopulate_empty_input_mapfilename if @p map_file is a null pointer or an empty string.
<li>#CPD_4GPopulate_invalid_input_mapfilename if @p map_file points to a non-existent mapping file.
<li>#CPD_4GPopulate_mapfilename_parsing_error if @p map_file points to a existing mapping file
    containing invalid details as per "MappingXMLSchema.xsd".
<li>#CPD_4GPopulate_empty_input_previewfilename if @p preview_file_name is a null pointer or an empty string.
<li>#CPD_4GPopulate_invalid_initial_population_rev_rule if the "CPD_4GPopulate_RevisionRule" preference is configured
    with a revision rule that is not supported by the multiple revision support functionality.
<li>#CPD_4GPopulate_start_effectivity_incorrect_format if the mandatory "CPD_4GPopulate_StartingEffectivity"
    preference is configured with an incorrect format.
<li>#CPD_4GPopulate_rev_rule_not_found if the "CPD_4GPopulate_RevisionRule" preference is configured with a
    revision rule name for which actual Revision Rule object is not available.
<li>#CPD_4GPopulate_mandatory_pref_not_available if the mandatory "CPD_4GPopulate_RevisionRule" and
    "CPD_4GPopulate_StartingEffectivity" preferences are not available.
<li>#CPD0CD_reuse_de_exist_with_true_ia if a Reuse Design Element is already realized for
    the input source Installation Assembly Item Revision specified by @p src_item_id and @p src_item_revision in @p create_information.
<li>#CPD0CD_reuse_de_exist_without_true_ia if a Reuse Design Element is already realized for
    the input source non-Installation Assembly Item Revision specified by @p src_item_id and @p src_item_revision in @p create_information.
<li>#CPD0CD_invalid_effectivity_group_id if the Item ID value specified in the preference
    "CPD_4GPopulate_effectivity_group" does not correspond to an existing Effectivity Group Item Revision.
<li>#CPD_4GPopulate_dynamic_partition_not_supported if the Organization mapping table contains a Partition
    type name which is of dynamic Partition Type.
<li>#CPD_4GPopulate_invalid_output_directory_path if @p preview_file_name provided to generate model preview
    file does not exist.
<li>#CPD_4GPopulate_ignore_provided_mapping_file warning if the Collaborative Design @p target_model_name in @p create_information
    has Mapping file attached with "IMAN_specification" relation.
<li>#CPD_4GPopulate_reset_variant_sync_warning warning if the @c is_sync_variant flag of input map_file @p map_file is true
    but the provided item of create_information @p src_item_id and @p src_item_revision in @p create_information is not associated with any Configurator context.
<li>#CPD_4GPopulate_invalid_input_effectivity_date if @p date_effectivity in @p create_information is in an invalid format.
<li>#CPD_4GPopulate_invalid_release_date if @p release_date in @p create_information is in an invalid format.
<li>#FL_duplicate_name if there are more than one folder found for the specified folder name @p override_folder
<li>#FL_not_found if @p override_folder does not exist.
<li>#RLZ0REALIZATION_override_folder_not_same if @p override_folder and the one specified in the Revision Rule @p revision_rule are not the same.
</ul>
*/
extern CPD0CD_API int CPD0CD_create_model_preview_from_input(
    const CPD_target_model_create_input_t* create_information, /**< (I) Source Item Revision and Target Model Information for create. */
    const int n_keys,                                          /**< (I) Number of keys. */
    const char** key_names,                                    /**< (I) n_keys Names of the keys. Values must be as mentioned in the table. */
    const char** key_values                                    /**< (I) n_keys Values associated to each provided key. */
);


/**
@deprecated #CPD0CD_create_or_update_model_using_preview deprecated in Teamcenter 11.6. Use #CPD0CD_create_or_update_or_snapshot_model_using_preview instead.

Creates or updates the full 4GD Model using XML preview file of source Item Assembly.

@returns
<ul>
<li>#ITK_ok on success.
<li>#CPD_4GPopulate_empty_input_previewfilename if @p preview_file_name is
    a 0-pointer or an empty string.
<li>#CPD_4GPopulate_invalid_input_previewfilename if @p preview_file_name points
    to a non-existent preview file.
<li>#CPD_4GPopulate_previewfile_parsing_error if @p preview_file_name points to a existing
    preview file containing invalid details as per "PreviewXMLSchema.xsd".
<li>#CPD0CD_invalid_effectivity_group_id if the Effectivity Group ID referenced in the preference
    "CPD_4GPopulate_effectivity_group" does not exist.
<li>#CPD_4GPopulate_unexpected_error if an unexpected error was encountered during
    the Populate 4G preview-based Item Realization.
<li>#CPD_4GPopulate_realization_error if an error was encountered during the Easy
    4G preview-based Item Realization.
<li>#CPD_4GPopulate_save_error if an error was encountered during save operation
    of the Populate 4G preview-based Item Realization.
<li>#CPD_4GPopulate_tagunload_error if an error was encountered during tag unload
    operation of the Populate 4G preview-based Item Realization.
<li>#CPD_4GPopulate_coll_design_does_not_exist_error if the Collaborative Design object pointed
    by @p model_object does not exist when using the update mode (@p is_update is @c true).
<li>#CPD_4GPopulate_partition_scheme_unavailable if the Partition Scheme type is unavailable for
    the Populate 4G preview-based Item Realization.
<li>#CPD_4GPopulate_bo_type_not_of_appmodel_type if the provided object type in @p preview_file_name
    is not a valid Application Model type
<li>#CPD_4GPopulate_item_does_not_have_configurator_context if the item of provided itemID in
    @p preview_file_name does not contain any associated Configurator Context.
<li>#CPD_4GPopulate_bo_type_does_not_exist if the provided Business Object type in
    @p preview_file_name does not exist.
<li>#CPD_4GPopulate_realization_message_for_errors warning if at least one assembly node in @p preview_file_name
    failed to realize into Reuse Design Elements.
</ul>   
*/
TC_DEPRECATED("11.6","CPD0CD_create_or_update_model_using_preview","CPD0CD_create_or_update_or_snapshot_model_using_preview")
extern CPD0CD_API int CPD0CD_create_or_update_model_using_preview(
    const char* preview_file_name,                       /**< (I) Full path to the 4GD Model Preview XML file.
                                                         <br/>It is also used in update mode in order to retrieve the model object. */
    const unsigned int batch_size,                       /**< (I) Indicates the number of objects that are created in one operation before being committed to the database and unloaded from memory.
                                                                  The system then processes a new batch of objects.
                                                         <br/>If the value is set to 0, the default value "1000" is used. */
    const logical is_update_of_design_elements_needed,   /**< (I) Flag to determine whether to update the existing desing elements are not. */
    tag_t* model_object                                  /**< (O) The created/updated Collaborative Design object. */
);

/**
Creates or updates or snapshot the full 4GD Model using XML preview file of source Item Assembly.

table>
    <tr>
        <th>Valid Keys</th>
        <th>Description</th>
    </tr>
    <tr>
        <td>preview_file_name</td>
        <td>Path to the XML file that defines the 4GD model objects which needs to be created</td>
    </tr>
    <tr>
        <td>update_of_design_changes</td>
        <td>Information to perform update realization on new reuse design component revisions. This should accept either true or false strings as value</td>
    </tr>
    <tr>
        <td>release_status</td>
        <td>Name of the release status object to snapshot 4G design components</td>
    </tr>
</table>

@returns
<ul>
<li>#ITK_ok on success.
<li>#CPD_4GPopulate_empty_input_previewfilename if @p preview_file_name is
    a 0-pointer or an empty string.
<li>#CPD_4GPopulate_invalid_input_previewfilename if @p preview_file_name points
    to a non-existent preview file.
<li>#CPD_4GPopulate_previewfile_parsing_error if @p preview_file_name points to a existing
    preview file containing invalid details as per "PreviewXMLSchema.xsd".
<li>#CPD0CD_invalid_effectivity_group_id if the Effectivity Group ID referenced in the preference
    "CPD_4GPopulate_effectivity_group" does not exist.
<li>#CPD_4GPopulate_unexpected_error if an unexpected error was encountered during
    the Populate 4G preview-based Item Realization.
<li>#CPD_4GPopulate_realization_error if an error was encountered during the Easy
    4G preview-based Item Realization.
<li>#CPD_4GPopulate_save_error if an error was encountered during save operation
    of the Populate 4G preview-based Item Realization.
<li>#CPD_4GPopulate_tagunload_error if an error was encountered during tag unload
    operation of the Populate 4G preview-based Item Realization.
<li>#CPD_4GPopulate_partition_scheme_unavailable if the Partition Scheme type is unavailable for
    the Populate 4G preview-based Item Realization.
<li>#CPD_4GPopulate_bo_type_not_of_appmodel_type if the provided object type in @p preview_file_name
    is not a valid Application Model type
<li>#CPD_4GPopulate_item_does_not_have_configurator_context if the item of provided itemID in
    @p preview_file_name does not contain any associated Configurator Context.
<li>#CPD_4GPopulate_bo_type_does_not_exist if the provided Business Object type in
    @p preview_file_name does not exist.
<li>#CPD_4GPopulate_realization_message_for_errors warning if at least one assembly node in @p preview_file_name
    failed to realize into Reuse Design Elements.
<li>#CPD_4GPopulate_realization_message_for_errors warning if at least one assembly node in @p preview_file_name
    failed to realize into Reuse Design Elements.
</ul>

*/

extern CPD0CD_API int CPD0CD_create_or_update_or_snapshot_model_using_preview(
    const int n_keys,                                          /**< (I) Number of keys. */
    const char** key_names,                                    /**< (I) n_keys Names of the keys. Values must be as mentioned in the table. */
    const char** key_values,                                   /**< (I) n_keys Values associated to each provided key. */
    tag_t* model_object                                        /**< (O) The created/updated Product Design object. */
);

/**
Checks if the input Items are Installation Assemblies (IA).
@note The items to check must be saved in the database before calling this ITK.

@returns
<ul>
<li>#ITK_ok on success.
<li>#CPD0CD_invalid_input_error if @p items is empty and @p n_items is not zero.
<li>#CPD0CD_invalid_item_property_in_preference if an invalid property value is provided in the preference "Cpd0InstallationAssemblyProperties".
<li>#CPD0CD_non_string_item_property_in_preference if a non-string property is provided in the preference "Cpd0InstallationAssemblyProperties".
</ul>
*/
extern CPD0CD_API int CPD0CD_is_installation_assembly(
    const unsigned int    n_items, /**< (I) Number of input items */
    const tag_t*          items,   /**< (I) n_items Items to check
                                   <br/>If any value of @p items is either #NULLTAG or not a valid Item, the corresponding @p is_ia will be false */
    logical**             is_ia    /**< (OF) n_items Indicates if the associated Item is Installation Assembly(IA). */
);


/**
Splits the indented Populate 4G Preview XML file into multiple flat structure XML files
which can be realized independently. The split XML file names will be returned for reference.
<br/>New independent files will be created in an already existing directory, and their name format is as follows:
@c {Collaborative_Design_Name_<sequence_no 1,2...>_DATETIMESTAMP}.

@returns
<ul>
<li>#ITK_ok on success.
<li>#CPD_4GPopulate_empty_input_previewfilename if @p preview_file_name is a 0-pointer or
    an empty string.
<li>#CPD_4GPopulate_invalid_input_previewfilename if @p preview_file_name is provided but
    preview file does not exist.
<li>#CPD_4GPopulate_previewfile_parsing_error if @p preview_file_name is provided but it does not
    contain valid details as per "PreviewXMLSchema.xsd".
<li>#CPD_4GPopulate_empty_input_split_directory if @p directory_path is a 0-pointer or
    an empty string.
<li>#CPD_4GPopulate_non_existing_input_split_directory if @p directory_path is provided but is
    a non existing directory.
<li>#CPD_4GPopulate_write_access_unavailable_on_split_directory if @p directory_path is an
    already existing directory without write access.
<li>#CPD_4GPopulate_internal_split_error if an error was encountered during the split
    Populate 4G preview-based Item Realization.
</ul>
*/
extern CPD0CD_API int CPD0CD_split_model_preview2(
    const char* preview_file_name,                  /**< (I) 4GD Model Preview XML file name */
    const char* directory_path,                     /**< (I) Directory path for storing the split XML files. <br/>The directory must exist. */
    const unsigned int number_of_batch_file,        /**< (I) Number of batch file to be created. */
    unsigned int* n_file_names,                     /**< (O) Number of split file names returned */
    char*** split_file_names                        /**< (OF) n_file_names names of the split XML files created.
                                                    <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only.*/
);


/**
Generates a pre-validation report of a Item-BVR Assembly using a mapping file between BVR and 4GD types.
<br/>This ITK traverses the entire BVR (BOM View Revision) structure and validates the data associated with the
organization nodes and the assembly nodes to generate an XML report.

@returns
<ul>
<li>#ITK_ok on success.
<li>#CPD_4GPopulate_empty_input_item_id if @c src_item_id in @p create_information is a 0-pointer or an empty string.
<li>#CPD_4GPopulate_invalid_input_itemid if @c src_item_id in @p create_information points to a non-existent Item.
<li>#CPD_4GPopulate_empty_input_mapfilename if @p map_file is a 0-pointer or an empty string.
<li>#CPD_4GPopulate_invalid_input_mapfilename if @p map_file points to a non-existent mapping file.
<li>#CPD_4GPopulate_mapfilename_parsing_error if @c mapping file in @p map_file points to an existing
    mapping file containing invalid details as per "MappingXMLSchema.xsd".
<li>#CPD_4GPopulate_empty_prevalidation_file_name if @p prevalidation_report_file_name is an empty string.
<li>#CPD_4GPopulate_invalid_output_directory_path if the output directory for @p prevalidation_report_file_name does not exist.
<li>#CPD_4GPopulate_invalid_input_effectivity_date if the specified date (@p create_information (@p date_effectivity) is an invalid format.
<li>#CPD_4GPopulate_invalid_release_date if the specified date (@p create_information (@p release_date) is an invalid format.
</ul>

*/
extern CPD0CD_API int CPD0CD_generate_pre_validation_report(
    const CPD_target_model_create_input_t* create_information,  /**< (I) Source Item Revision and Target Model Information for pre-validation */
    const char* revision_rule,                                  /**< (I) Revision Rule used to configure the input source Item BVR Assembly (@p create_infromation (@p  src_item_id)).
                                                                     <br/>If not provided, the latest working Revision Rule is used.*/
    const char* map_file,                                       /**< (I) Path of the Mapping XML file to define mapping between BVR types and 4GD types */
    const logical child_assm_validation,                        /**< (I) Flag to validate the child assembly structure.
                                                                     <br/> If it is true then only it will validate the child assemblies*/
    const char* prevalidation_report_file_name                  /**< (I) Path of the Pre-validation report file */
);

#ifdef __cplusplus
}
#endif

/** @} */

#include <cpd0cd/libcpd0cd_undef.h>
#endif
