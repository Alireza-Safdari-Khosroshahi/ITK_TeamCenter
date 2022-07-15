/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2012.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Interface definition file for the Appmodel module.

    This file contains declaration of all the methods in this interface
*/

#ifndef MDL0MODEL_MDL0MODEL_H
#define MDL0MODEL_MDL0MODEL_H
#include <common/tc_deprecation_macros.h>
#include <mdl0model/libmdl0model_exports.h>

/**
    @defgroup MDL0MODEL Application Model
    @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/**
    @deprecated #MDL0MODEL_revise_object deprecated in Teamcenter 11.2. Use #TCTYPE_revise_objects instead.

    Revises a Conditional Element
    @return ITK_ok on success. Otherwise, it returns the error MDLOMODEL_object_has_no_status
*/
TC_DEPRECATED("11.2", "MDL0MODEL_revise_object", "TCTYPE_revise_objects" )
extern MDL0MODEL_API int MDL0MODEL_revise_object(
    tag_t          conditional_element_tag,      /**< (I) Conditional Element Tag which should be revised */
    tag_t          revise_input,                 /**< (I) Revise Input Descriptor of Conditional Element */
    int            n_deep_revise_data,           /**< (I) Number of Deep Copy Data objects */
    const tag_t*   deep_revise_data,             /**< (I) Deep Copy Data objects of the revise input */
    tag_t*         new_element_revision          /**< (O) Newly revised Conditional Element Tag */
);

/**
    @deprecated #MDL0MODEL_ask_deep_revise_data deprecated in Teamcenter 11.2. Use #TCTYPE_ask_deepcopydata instead.

    Returns the Deep Copy Data for the revise operation
    @return ITK_ok on success. Otherwise, it returns the error MDL0MODEL_object_deepcopy_data_cannot_be_retrieved   
*/
TC_DEPRECATED("11.2", "MDL0MODEL_ask_deep_revise_data", "TCTYPE_ask_deepcopydata" )
extern MDL0MODEL_API int MDL0MODEL_ask_deep_revise_data(
    tag_t           conditional_element_tag,       /**< (I) Conditional Element Tag which should be revised */
    int*            n_deep_revise_data,            /**< (O) Number of Deep Copy Data objects */
    tag_t**         deep_revise_data               /**< (OF) n_deep_revise_data Array containing the tags of the Deep Copy Data corresponding to the revise input */
);

/**
    @deprecated #MDL0MODEL_free_deep_revise_data deprecated in Teamcenter 11.2. Use #TCTYPE_free_deepcopydata instead.

    Deletes the associated Deep Copy Data objects and frees the allocated memory.
    This can be called using the information from the call to the "MDL0MODEL_ask_deep_revise_data" ITK

    @return ITK_ok, always  
*/
TC_DEPRECATED("11.2", "MDL0MODEL_free_deep_revise_data", "TCTYPE_free_deepcopydata" )
extern MDL0MODEL_API int MDL0MODEL_free_deep_revise_data(
    int            n_deep_revise_data,           /**< (I) Number of Deep Copy Data objects */
    tag_t*         deep_revise_data              /**< (I) Deep Copy Data objects of the revise input */
);

/**
    @deprecated #MDL0MODEL_promote_to_history deprecated in Teamcenter 11.2.3.
    <br/>Starting Teamcenter 11.2.3, the concept of "promote to history" no longer exists. New
    historical versions are now created automatically when a protected latest public version is
    modified. Pending removal, this function does nothing.

    Promotes the given instances, and any related objects, in POM history.

    If an instance is not revisable, the instance cannot be promoted. Instead
    its status list is checked for object stability.

    This function is transactional. In case of error, no instance is promoted and, where
    appropriate, "problem_instances" gives the objects that prevented the promote.

    All the input instances tags must be qualified by the same cparam, which must configure latest.

    Where unreleased non-revisable objects are encountered, and such objects can be baselined, then
    this function will look for existing up-to-date baselines of those objects and reference those
    in history. If no up-to-date baseline is found then a new one is created using the workflow
    process specified by argument @p baseline_release_procedure. If an unreleased non-revisable object
    is not baselineable (or if a baseline cannot be created because no @p baseline_release_procedure
    is supplied), then the attempt to promote will fail with error
    #MDL0MODEL_non_rev_promote_objects_not_released.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#MDL0MODEL_promote_tos_not_found if the application model's promote transfer option set cannot be found.
    <li>#MDL0MODEL_non_rev_promote_objects_not_released if any unreleased non-revisable objects are encountered.
    <li>#POM_promote_to_history_requires_public_latest_version if any of the input tags do not configure latest.
    <li>#POM_mixed_cparams if the input tags are configured by a mixture of cparams.
    </ul>
*/
TC_DEPRECATED_NO_REPLACEMENT( "11.2.3", "MDL0MODEL_promote_to_history" )
extern MDL0MODEL_API int MDL0MODEL_promote_to_history(
    int           n_instances,                 /**< (I) Number of instances to promote */
    const tag_t*  instances,                   /**< (I) n_instances Tags of instances to promote */
    const char*   baseline_release_procedure,  /**< (I) Name of the workflow process template to be used when baselining related objects */
    int*          n_problem_instances,         /**< (O) Number of problem instances preventing promotion */
    tag_t**       problem_instances            /**< (OF) n_failed_instances Tags of problem instances preventing promotion */
);

/**
    Finds instances which must be frozen before the given instances can be promoted.

    An instance needs to be frozen if:
    <ul>
    <li>it is not a revisable object.
    <li>it is not released.
    </ul>

    Both the given instances, and any related instances are tested.

    The list of release statuses that freeze an object can be customized. See Mdl0NotFrozenByStatusList.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#MDL0MODEL_internal_error in case of failure.
    </ul>
*/
extern MDL0MODEL_API int MDL0MODEL_find_instances_to_freeze(
    int             n_instances,            /**< (I) Number of promotion candidates */
    const tag_t*    instances,              /**< (I) n_instances Tags of promotion candidates */
    int*            n_instances_to_freeze,  /**< (O) Number of instances to freeze */
    tag_t**         instances_to_freeze     /**< (OF) n_failed_instances Tags of instances to freeze */
);

/**
    Model elements clone operation

    This function performs clone (deep copy) of model elements from an application model (referred to as source model)
    to another application model (referred to as target model).

    The elements to be included from the source to the target model can be either an explicit list of elements (@p include_source_elements) or results from a recipe (@p subset_def).

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#MDL0MODEL_invalid_input if the source application model or target application model is NULLTAG or unsupported type.
    <li>#MDL0MODEL_no_config_context_provided if configuration context is not supplied.
    <li>#MDL0MODEL_no_objects_found_to_perform_the_operation if no object is found for clone operation, because either the supplied input objects are invalid or the supplied subset definition is empty.
    <li>#MDL0MODEL_clone_internal_error if any internal error occurred during clone operation.
    </ul>
*/
extern MDL0MODEL_API int MDL_clone_model_elements(
    tag_t           target_model,                  /**< (I) Target application model (mandatory). */
    tag_t           source_model,                  /**< (I) Source application model (mandatory). */
    tag_t           subset_def,                    /**< (I) Source subset definition tag (optional) */
    tag_t           config_context,                /**< (I) Source configuration context tag (mandatory if @p include_source_elements is supplied). */
    int             n_include_source_elements,     /**< (I) Number of objects to be included for clone operation (optional) */
    const tag_t*    include_source_elements,       /**< (I) n_include_source_elements Tags of objects to be included for clone operation (optional) */
    logical         sync_variant_expressions,      /**< (I) Flag to specify sync variant expressions from source to target objects.*/
    logical         sync_effectivity_expressions,  /**< (I) Flag to specify sync effectivity expressions from source to target objects. */
    logical         checkout_on_create,            /**< (I) Flag to specify check-out on create for target objects (optional). */
    int*            n_cloned_objects,              /**< (O) Number of objects created in target model after clone operation */
    tag_t**         cloned_objects,                /**< (OF) n_cloned_objects Tags of newly created target model elements after clone operation */
    int*            n_failed_objects,              /**< (O) Number of source objects failed during clone operation */
    tag_t**         failed_object_tags,            /**< (OF) n_failed_objects Tags of source objects failed during clone operation */
    int**           failed_object_ifail_codes      /**< (OF) n_failed_objects Error codes of source objects failed during clone operation */
    );
    
/**
   Retrieves configured related objects by traversing copy-stable relations.
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#POM_invalid_tag if the input tag is invalid.
   <li>#MDL0MODEL_internal_error if size mismatch occurs in output parallel vectors.
   </ul>
*/
    extern MDL0MODEL_API int MDL0MODEL_query_related_objects(
        int             n_source_objects,               /**< (I) Number of source objects */
        const tag_t*    source_objects,                 /**< (I) n_source_objects Array containing the tags of the source objects */
        tag_t           configuration_context,          /**< (I) Configuration context */
        const char*     relation_type_name,             /**< (I) Relation name for the relationship between input source objects and output related objects. If not specified, then all relations will be considered */
        const char*     other_side_object_type_name,    /**< (I) The type of related objects to be queried for the given relation. If not specified, all related objects for the given relation name are queried */
        const char*     attribute_name,                 /**< (I) Attribute name of the relation to be filtered */
        int             attribute_type,                 /**< (I) Attribute type of the relation to be filtered */
        const char*     attribute_value,                /**< (I) Attribute value of the relation to be filtered */
        logical         query_primaries,                /**< (I) A boolean flag to set the direction of navigation across the relation while fetching the related objects */
        logical         return_relations,               /**< (I) Flag to specify if the relation objects should be returned in response */
        int*            n_related_objects,              /**< (O) Count of related objects */
        tag_t**         related_objects,                /**< (OF) n_related_objects Array containing the tags of the related objects */
        tag_t**         ret_source_objects,             /**< (OF) n_related_objects Array containing the tags of the input source objects */
        tag_t**         relation_objects                /**< (OF) n_related_objects Array containing the tags of the relation objects when return_relations is set TRUE else Array containing 0 objects */
        );
    
/**
   Retrieves configured impacted welds for input design elements.
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#POM_invalid_tag if the input tag is invalid.
   <li>#MDL0MODEL_internal_error if size mismatch occurs in output parallel vectors.
   </ul>
*/
    extern MDL0MODEL_API int MDL0MODEL_get_impacted_welds(
        int             n_design_element_objects,       /**< (I) Number of Design Element objects */
        const tag_t*    design_element_objects,         /**< (I) n_design_element_objects Array containing the tags of the Design Element objects */
        tag_t           configuration_context,          /**< (I) Configuration context */
        int*            n_impacted_welds,               /**< (O) Count of impacted weld objects */
        tag_t**         impacted_welds,                 /**< (OF) n_impacted_welds Array containing the tags of the impacted weld objects */
        tag_t**         ret_design_element_objects      /**< (OF) n_impacted_welds Array containing the tags of the input Design Element objects */
        );
    
/**
    Retrieves the configured elements related to a primary object through a specific relation type.
    <br/>Major configuration contexts are extracted from the cparam of the input parimary. 
    If no configuration context is found in the cparam, it will look for one on the viewing context stack.
    <br/>If parameter @p primary is invalid, it would return nothing back.
    <br/>If the parameter @p relation_type is NULLTAG, it would match any relation types. 
    <br/>The returned set includes:
    <ul> 
    <li>Elements configured by directly related secondary threads.
    <li>Elements configured by the thread of the related secondary object.
    <li>Non configurable related secondaries.
    </ul>
    
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_tag if the parameter @p primary is invalid
    <li>#TYPE_unknown_type if the parameter @p relation_type is invalid.
    </ul>
*/
    extern MDL0MODEL_API int MDL0MODEL_configure_secondary_elements(
        tag_t primary,          /**< (I) Primary object */
        tag_t relation_type,    /**< (I) Relation type */
        int* n_secondaries,     /**< (O) Number of secondary objects found */
        tag_t** secondaries     /**< (OF) n_secondaries Array of secondary objects */
        );

/**
    Retrieves the configured priamry elements related to a secondary element through a specific relation type.
    <br/>Major configuration contexts are extracted from the cparam of the input secondary. 
    If no configuration context is found in the cparam, it will look for one on the viewing context stack.
    <br/>If the parameter @p relation_type is NULLTAG, it would match any relation types. 
    <br/>The returned set includes:
    <ul> 
    <li>Elements configured by directly related primary threads.
    <li>Elements configured by the thread of the related primary object.
    <li>Non configurable related primaries.
    </ul>
    
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_tag if the parameter @p secondary is invalid
    <li>#TYPE_unknown_type if the parameter @p relation_type is invalid. 
    </ul>
*/
    extern MDL0MODEL_API int MDL0MODEL_configure_primary_elements(
        tag_t secondary,      /**< (I) Given secondary element */
        tag_t relation_type,  /**< (I) Relation type */
        int* n_primaries,     /**< (O) Number of primary objects found */
        tag_t** primaries     /**< (OF) n_primaries Array of primary objects */
        );

/**
    Retrieves the view modes for a list of configured objects.
    <br/>The view modes may be used in the client to determine which menu items are displayed for the
    various modes. New values may be added as needed in the following releases. 
    <br/>Clients that work with multiple server versions and parse these values should handle new unexpected ones.
    <br/>View modes should not be persisted.

    @note For precise tags, invalid tags, tags configured with staging space cparam or tags configured with historical cparam having no extra data with key BSLN
          the string returned in view mode is UNKNOWN.

    @returns
    <ul>
    <li>#ITK_ok always
    </ul>
*/
    extern MDL0MODEL_API int MDL0MODEL_ask_view_modes(
        int n_instances,            /**< (I) Number of configured tags */
        const tag_t* instances,     /**< (I) n_instances The configured objects */
        char*** view_modes          /**< (OF) n_instances The view modes for each configured @p instances.
                                          <br/>The retrieved values are one of the following:
                                          <ul>
                                          <li>LATEST
                                          <li>ALL_CHANGE
                                          <li>CHANGE
                                          <li>MARKUP
                                          <li>OPEN_BASELINE
                                          <li>CLOSED_BASELINE
                                          <li>SNAPSHOT
                                          <li>UNKNOWN
                                          </ul>
                                          <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
        );

#ifdef __cplusplus
}
#endif

/**
    @}
*/
#include <mdl0model/libmdl0model_undef.h>
#endif
