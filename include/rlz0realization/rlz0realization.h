/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    This header file declares all functions, data types and constants to be used by 4th Generation Designer.

*/

#ifndef RLZ0REALIZATION_RLZ0REALIZATION_H
#define RLZ0REALIZATION_RLZ0REALIZATION_H

#include <rlz0realization/librlz0realization_exports.h>

/**
    @defgroup RLZ0REALIZATION Realization

    This module provides an interface to 4GD model-to-model operations.
    Functions are provided to perform following operations:
    <ul>
    <li>Perform Realization updates from source to target application model
    <li>Perform Instantiation updates from source to target application model
    </ul>

    The prototypes for these functions are in rlz0realization.h.

    The APIs return codes are defined in Cpd0cd_errors.h and Rlz0realization_errors.h.

    @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/**
    Model-to-Model update realization operation

    This function performs realization updates from an application model (referred to as source model) 
    to another application model (referred to as target model).

    The elements to be included from the source to the target model can be either an explicit list of elements (@p include_source_elements) or results from a recipe (@p subset_def).

    @note The list @p include_source_elements refers to the model elements from source application model that need to be cloned to target model.
    <br/>The parameters @p append_list and @p remove_list refer to the model elements from the existing realization container that need to be considered during update realization.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#RLZ0REALIZATION_no_realization_container_provided_as_input if the supplied realization container object is NULLTAG.
    <li>#RLZ0REALIZATION_not_realization_container if the supplied realization container object is invalid.
    <li>#RLZ0REALIZATION_no_realization_object if the Realization object is not available for the supplied Realization container.
    <li>#RLZ0REALIZATION_not_realization_object if the object referred by the supplied Realization container is not a valid Realization object.
    <li>#RLZ0REALIZATION_no_source_model_provided_as_input if no valid Source Model is provided as input.
    <li>#RLZ0REALIZATION_no_config_context_provided_as_input if configuration context is not supplied.
    </ul>
*/
extern RLZ0REALIZATION_API int RLZ_update_model_to_model_realization(
    tag_t           realization_container,         /**< (I) Realization Container Tag (mandatory) */
    tag_t           source_model,                  /**< (I) Source application model. This argument is required when @p subset_def or @p include_source_elements is specified */
    tag_t           subset_def,                    /**< (I) Source subset definition tag (optional) */
    int             n_include_source_elements,     /**< (I) Number of objects to be included for update Realization (optional) */
    const tag_t*    include_source_elements,       /**< (I) n_include_source_elements Tags of objects to be included for update Realization (optional) */
    tag_t           config_context,                /**< (I) Source configuration context tag. Mandatory if @p include_source_elements is populated, else this is optional. */
    logical         sync_variant_expressions,      /**< (I) Flag to specify sync variant expressions from source to target objects. */
    logical         sync_effectivity_expressions,  /**< (I) Flag to specify sync effectivity expressions from source to target objects. */
    int             n_append_list,                 /**< (I) Number of objects to be appended to existing realization container during update Realization (optional) */
    const tag_t*    append_list,                   /**< (I) Tags of objects to be appended to existing realization container during update Realization (optional) */
    int             n_remove_list,                 /**< (I) Number of objects to be removed from realization container during update Realization (optional) */
    const tag_t*    remove_list,                   /**< (I) Tags of objects to be removed from realization container during update Realization (optional) */
    int*            n_added_objects,               /**< (O) Number of added objects during update Realization */
    tag_t**         added_objects,                 /**< (OF) n_added_objects Tags of added objects during update Realization */
    int*            n_updated_objects,             /**< (O) Number of updated objects during update Realization */
    tag_t**         updated_objects,               /**< (OF) n_updated_objects Tags of updated objects during update Realization */
    int*            n_failed_objects,              /**< (O) Number of failed objects during update Realization */
    tag_t**         failed_object_tags,            /**< (OF) n_failed_objects Tags of failed objects during update Realization */
    int**           failed_object_ifail_codes      /**< (OF) n_failed_objects Error codes of failed objects during update Realization */
);

/**
    Model-to-Model update instantiation operation

    This function performs instantiation updates from an application model (referred to as source model) 
    to another application model (referred to as target model).

    The elements to be included from the source to the target model can be either an explicit list of elements (@p include_source_elements) or results from a recipe (@p subset_def).

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CPD0CD_internal_error if the any of the supplied inputs is invalid or some internal error has occurred.
    </ul>
*/
extern RLZ0REALIZATION_API int RLZ_update_model_to_model_instantiation(
    tag_t           model_reuse_element,           /**< (I) Reuse Design Element Tag (mandatory) */
    tag_t           source_model,                  /**< (I) Source application model (mandatory) */
    tag_t           subset_def,                    /**< (I) Source subset definition tag (optional) */
    tag_t           config_context,                /**< (I) Source configuration context tag (mandatory) */
    int             n_include_source_elements,     /**< (I) Number of objects to be included during update Instantiation (optional) */
    const tag_t*    include_source_elements,       /**< (I) n_include_source_elements Tags of objects to be included during update Instantiation (optional) */
    int*            n_added_objects,               /**< (O) Number of added objects during update Instantiation */
    tag_t**         added_objects,                 /**< (OF) n_added_objects Tags of added objects during update Instantiation */
    int*            n_updated_objects,             /**< (O) Number of updated objects during update Instantiation */
    tag_t**         updated_objects                /**< (OF) n_updated_objects Tags of updated objects during update Instantiation */
);

#ifdef __cplusplus
}
#endif

/** @} */

#include <rlz0realization/librlz0realization_undef.h>
#endif 
