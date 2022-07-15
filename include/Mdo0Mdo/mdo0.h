/* 
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2014.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/
 
/**
    @file

    This file contains the function prototypes for working with the Mdo0 classes
    and specifically with the C ITK interface to these classes.

*/

#ifndef MDO0_H
#define MDO0_H

#include <unidefs.h>
#include <Mdo0Mdo/libmdo0mdo_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif
/**
    @defgroup MDO0 Multi-Disciplinary Object
    @ingroup MDO0MDO
    
    This module defines the required ITK interface for Multi-Disciplinary Object related operations.
    These functions allow you to create, update, or delete Multi-Disciplinary Objects and their relations.
    The ITK multi-disciplinary objects functions include:
    <ul>
    <li>Linking and unlinking design instances.
    <li>Finding linked design instances.
    <li>Creating and updating MDO associations.
    <li>Finding MDO associations.
    </ul>

    To use these functions, include mdo0.h.

    @{
*/
/**
    Links Design Instances and retrieves the link object.
    <br/>The operation is used to link two or more design instances from
    multi-discipline designs together through a common object Mdo0MDInstance.
    <br/>The operation can also update the design instance linkage by adding more
    design instances to the existing design instance linkage.
    <br/>Currently the Mdl0ModelElement is the supported object for design instance.
    <br/>If the linking is precise, the given design instance is used to link to the
    Mdo0Instance.
    If the linking is imprecise, the Mdl0ElementThread object of the
    Mdl0ModelElement is used for linking.
    <br/>Context information for the linking of design instances is optional.
    If the context information is provided while linking design instances,
    then the design instance linkage is valid only for that context.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#MDO_input_has_no_design_instances, if zero design instances are input.
    <li>#MDO_already_in_mdinstance_group, if the input design instances belong to multiple groups.
    </ul>
*/
extern MDO0MDO_API int MDO0_link_design_instances(
        int num_design_instances,       /**< (I) Number of Design Instances to be linked */
        const tag_t* design_instances,  /**< (I) num_design_instances Design Instances to be linked */
        const logical* is_di_precise,   /**< (I) num_design_instances Is corresponding Design Instance precise */
        tag_t context,                  /**< (I) Link context. Optional. */
        int* num_design_instance_links, /**< (O) Number of Design Instance Links created */
        tag_t** design_instance_links   /**< (OF) num_design_instance_links MDInstance linking design instances created */
        );

/**
    Unlinks Design Instances and retrieves the link object.
    <br/>The operation is used to unlink one or more design instances which are
    linked together through a common object Mdo0MDInstance.
    <br/>Currently the Mdl0ModelElement is the supported object for design instance.
    <br/>If the unlinking is precise, the given design instance is used to unlink
    from the Mdo0Instance.
    If the unlinking is imprecise, the Mdl0ElementThread object of the
    Mdl0ModelElement is used for unlinking.
    <br/>Context information for the unlinking of design instances is optional.
    If the context information is provided while unlinking design instances,
    then the Mdo0MDInstance object for the given context is identified and
    design instance is unlinked from the MdoMDInstance.
    If the last design instance from the MdoMDInstance is unlinked,
    the MdoMDInstance will also be deleted.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#MDO_input_has_no_design_instances, if zero design instances are input.
    <li>#MDO_no_mdinstances_found, if the design instances aren't linked.
    <li>#MDO_multiple_mdinstances_found, if input design instances are not linked with a common Mdo0MDInstance. 
    </ul>
*/
extern MDO0MDO_API int MDO0_unlink_design_instances(
        int num_design_instances,      /**< (I) Number of Design Instances to be unlinked */
        const tag_t* design_instances, /**< (I) num_design_instances Design Instances to be unlinked */
        const logical* is_di_precise,  /**< (I) num_design_instances Is corresponding Design Instance precise */
        tag_t context,                 /**< (I) Link context. Optional. */
        tag_t* design_instance_link    /**< (O) NULLTAG or Mdo0MDInstance with other linked design instances */
        );

/**
    Finds linked contexts.
    <br/>The operation is used to search for linked contexts for the given input design instances.
    <br/>Currently the Mdl0ModelElement is the supported object for design instance.
    <br/>If search is for precise design instance,
    using the given input design instance,
    the linked contexts are searched and returned.
    If search is for imprecise design instance,
    the Mdl0ElementThread object of the Mdl0ModelElement is used for search.
    <br/>If configuration detail are provided as part of input,
    for every linked design instance if any configuration is provided in input,
    the configuration is applied and if it is valid for this configuration,
    then the context is returned.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#MDO_missing_search_parameters, if zero design instances and no context are input.
    </ul>
*/
extern MDO0MDO_API int MDO0_find_linked_contexts(
        int num_design_instances,            /**< (I) Number of Design Instances */
        const tag_t* design_instances,       /**< (I) num_design_instances Design Instances */
        const logical* is_di_precise,        /**< (I) num_design_instances Is corresponding Design Instance precise */
        int num_app_models,                  /**< (I) Number of Mdl0ApplicationModels */
        const tag_t* app_models,             /**< (I) num_app_models Mdl0ApplicationModels */
        const tag_t* configuration_contexts, /**< (I) num_app_models Configuration contexts */
        int* num_contexts,                   /**< (O) Number of contexts found */
        tag_t** contexts                     /**< (OF) num_contexts Contexts found */
        );

/**
    Finds linked Design Instances.
    <br/>The operation is used to search for linked design instances for the given
    input design instances.
    <br/>Currently the Mdl0ModelElement is the supported object for design instance.
    <br/>If search is for precise design instance,
    using the given input design instance,
    the linked other design instances are searched and returned.
    If search is for imprecise design instance,
    the Mdl0ElementThread object of the Mdl0ModelElement is used for search.
    <br/>If the context information is provided along with design instances input
    while searching for design instances,
    then the Mdo0MDInstance object for the given design instance and context
    is identified and design instance of the MdoMDInstance are returned as
    linked design instances.
    <br/>If only context information is provided as input,
    all the MdoMDInstance for that context is identified and all the design
    instances of the MdoMDInstance is returned as linked design instances.
    <br/>If configuration detail are provided as part of input,
    for every linked design instance if any configuration is provided in input,
    the configuration is applied and if it is valid for this configuration,
    then the design instance is returned as linked design instances.
    Otherwise, the design instance is not returned as linked design instance
    for this input configuration.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#MDO_missing_search_parameters, if zero design instances and no context are input.
    </ul>
*/
extern MDO0MDO_API int MDO0_find_linked_design_instances(
        int num_design_instances,            /**< (I) Number of Design Instances */
        const tag_t* design_instances,       /**< (I) num_design_instances Design Instances */
        const logical* is_di_precise,        /**< (I) num_design_instances Is corresponding Design Instance precise */
        tag_t context,                       /**< (I) Link context or NULLTAG for all contexts */
        int num_app_models,                  /**< (I) Number of Mdl0ApplicationModels */
        const tag_t* app_models,             /**< (I) num_app_models Mdl0ApplicationModels */
        const tag_t* configuration_contexts, /**< (I) num_app_models Configuration contexts */
        int* num_linked_design_instances,    /**< (O) Number of design instances found */
        tag_t** linked_design_instances      /**< (OF) num_linked_design_instances Design instances found */
        );

/**
    Finds common MDO associations.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_not_found, if input tags are not design instances
    </ul>
*/
extern MDO0MDO_API int MDO0_find_mdo_associations(
        int num_design_instances,      /**< (I) Number of Design Instances */
        const tag_t* design_instances, /**< (I) num_design_instances Design Instances */
        int* num_mdo_assocs,           /**< (O) Number of MDO associations */
        tag_t** mdo_assocs             /**< (OF) num_mdo_assocs MDO associations */
        );

/**
    Finds associated MDO artifacts.
    <br/>The operation is used to search for MDThread and compatible design artifacts for
    the given input design instances.
    <br/>Currently the Mdl0ModelElement is the supported object for design instance.
    <br/>The underlying object for the Mdl0ModelElement is used for searching for MDThread.
    <br/>If more than one design instance is given as input,
    all the design instance's underlying object will be identified and collected.
    Then all the MDThread objects containing this set of design artifacts will be returned.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_not_found, if input tags are not design instances
    </ul>
*/
extern MDO0MDO_API int MDO0_find_mdo_artifacts(
        int num_design_instances,      /**< (I) Number of Design Instances */
        const tag_t* design_instances, /**< (I) num_design_instances Design Instances */
        tag_t mdo_assoc,               /**< (I) MDO association */
        int* num_mdo_artifacts,        /**< (O) Number of MDO artifacts found */
        tag_t** mdo_artifacts          /**< (OF) num_mdo_artifacts  MDO artifacts found */
        );

/**
    Creates an MDO association with these artifacts.
    <br/>The operation is to create a brand new MDThread object based on the MDThread properties
    and set of design artifacts.

    @returns
    <ul>
    <li>#ITK_ok on success
    </ul>
*/
extern MDO0MDO_API int MDO0_create_mdo_association(
        char* mdo_name,             /**< (I) Name of MDO */
        int num_mdo_artifacts,      /**< (I) Number of MDO artifacts */
        const tag_t* mdo_artifacts, /**< (I) num_mdo_artifacts  MDO artifacts */
        tag_t* mdo                  /**< (O) New or updated MDO */
        );

/**
    Updates an MDO association with these artifacts.
    <br/>The operation is to update an existing MDThread object by associating additional
    required design artifacts to it or remove existing design artfiacts association from it.

    @returns
    <ul>
    <li>#ITK_ok on success
    </ul>
*/
extern MDO0MDO_API int MDO0_update_mdo_association(
        tag_t mdo,                  /**< (I) Existing MDO to update */
        int num_add_artifacts,      /**< (I) Number of design artifacts being added */
        const tag_t* add_artifacts, /**< (I) num_add_artifacts Design artifacts being added */
        int num_rem_artifacts,      /**< (I) Number of design artifacts being removed */
        const tag_t* rem_artifacts  /**< (I) num_rem_artifacts Design artifacts being removed */
        );

/**
    Deletes MDO notifications.  The flag indicates whether all notifications are deleted or only those meeting
    the input criteria, the created before date, the action that triggered the MDO notification, or
    the mdo0TriggeringComponent for which the notification is created.
    <br/>The created before date must use the localized format defined in the key "DefaultDateFormat" specified in the file timelocal_locale.xml.
    <br/>The English default format is "%d-%b-%Y %H:%M".
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PROP_not_a_date if the value for the parameter @p before_date is incorrect.
    </ul>
*/
extern MDO0MDO_API int MDO0_cleanup_mdo_notifications(
        logical delete_all,                /**< (I) Flag to indicate that all MDO notifications are to be deleted.
                                                    <br/>If true, other inputs will be ignored.
                                                    <br/>If false, other inputs will be processed. */
        const char* before_date,           /**< (I) The date (in the format explained above) before which the MDO notifications are to be removed. */
        int n_triggering_comp,             /**< (I) The number of triggering components */
        const tag_t* triggering_comp_tags, /**< (I) n_triggering_comp Tags of the triggering components */
        const char* triggering_action,     /**< (I) The action that triggered MDO Notification */
        int* n_failed_objects,             /**< (O)  The number of deletion failed notification objects */
        tag_t** failed_object_tags,        /**< (OF) n_failed_objects Failed notification objects */
        int**  error_codes                 /**< (OF) n_failed_objects Error codes for failed notification objects */
        );

/** @} */

#ifdef __cplusplus
}
#endif

#include <Mdo0Mdo/libmdo0mdo_undef.h>
#endif
