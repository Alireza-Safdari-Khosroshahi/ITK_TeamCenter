/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2009.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    MFG.h

    File description: ITK function

*/

#ifndef MFG_H
#define MFG_H


#include <mfg/libmfg_exports.h>
/**
    @defgroup MFG Manufacturing (MFG)
    This module defines the required ITK interface for MFG (manufacturing) related operations.
    @{
*/

/**
    The input object containing the relevant data for creating an object.
*/
typedef struct MFG_create_input_s {
    char* client_id;              /**< Unique identifier to relate the output with the input */
    tag_t target;                 /**< The target object to create a new object under it */
    tag_t create_input;           /**< A create input object containing the properties for the object to create */
} MFG_create_input_t;

/**
    The output containing the new objects resulting from the creation for the specified input.
*/
typedef struct MFG_create_output_s {
    char* client_id;              /**< Unique identifier to relate the output with the input */
    int count;                    /**< Number of created objects */
    tag_t* new_objects;           /**< Array of newly created objects */
} MFG_create_output_t;


#ifdef __cplusplus
    extern "C"{
#endif

extern MFG_API int MFG_disconnect_object(
    tag_t   object,         /**< (I) object*/
    tag_t   disconnectFrom  /**< (I) disconnectFrom*/
    );

extern MFG_API int MFG_create_flow(
    tag_t          pred,    /**< (I) predecessor*/
    tag_t          succ,    /**< (I) successor*/
    logical        implicit,/**< (I) implicit*/
    double         delay,   /**< (I) delay*/
    tag_t*         newFlow  /**< (O) tag to newly created flow*/
    );

extern MFG_API int MFG_remove_flow(
    tag_t          delFlow  /**< (I) tag to removed flow*/
    );

extern MFG_API int MFG_resolve_logical_assignments(
    tag_t    object,      /**< (I) object to resolve*/
    tag_t*  contexts,     /**< (I) context list*/
    int     nContexts,    /**< (I) number of contexts*/
    logical recursive     /**< (I) if true, resolve recursively*/
    );

extern MFG_API int MFG_get_resolved_nodes_from_LA(
    tag_t   parentLine,   /**< (I) parent line of nodes*/
    tag_t   laObj,        /**< (I) LA object to get nodes from*/
    int*    count,        /**< (O) number of resolved nodes*/
    tag_t** resolvedNodes /**< (O) resolved nodes*/
    );

extern MFG_API int MFG_edit_tool_requirement(
    tag_t trTag,            /**< (I) Tool Requirement object to edit*/
    const char *name,       /**< (I) TR Name*/
    const char *desc,       /**< (I) TR description*/
    const char *assignType, /**< (I) Assignment Type say METool*/
    tag_t searchCriteria   /**< (I) Search Criteria*/
    );

extern MFG_API int MFG_edit_logical_assignment(
    tag_t laTag,            /**< (I) LA object to edit*/
    const char *assignType, /**< (I) assignment type*/
    const char *usageAddr,  /**< (I) usage address*/
    const char *position    /**< (I) logical position*/
    );


    /**
    Lists the behaviors for each MFG class
    */   
    extern MFG_API int MFG_list_behaviors();

    /**
    Lists the properties for each MFG class
    */   
    extern MFG_API int MFG_list_properties();


    extern MFG_API int MFG_open_context(
        tag_t   object,                 /**< (I) object */
        logical openViews,              /**< (I) open OG windows */
        logical openAssociatedContexts, /**< (I) open associated contexts */
        int*    count,                  /**< (O) number of opened contexts */
        tag_t** openedContexts,         /**< (OF) count returned array of opened contexts tags */
        tag_t** structuerContexts,      /**< (OF) count returned array of structure contexts tags */
        tag_t*  cc                      /**< (O) the CC object */
        );

    /**
    Opens either the classic variant structure or the product configurator structure of a provided context (Subtype/Subclass of Item, Collaboration Context or Structure Context). 
    @note If the structure contains any configurator context, the structure is a product configurator structure. Otherwise it is classic structure. 
    @note Use #MFG_open_context to open the structure with or without Occurence Group view and its associated contexts.

    @returns 
    <ul> 
    <li>#ITK_ok on success. 
    <li>#BOM_invalid_tag if @p context is invalid.
    <li>#MFG_collaboration_context_mixed_variant_structure_failed_to_load if @p context is a Collaboration Context with mixed variant structures.
    <li>#MFG_classic_variant_structure_failed_to_load if @p is_product_configurator is @c true and @p context contains classic variant structures. 
    <li>#MFG_product_configurator_variant_structure_failed_to_load if @p is_product_configurator is @c false and @p context contains product configurator structures. 
    <li>#MFG_collaboration_context_classic_variant_structure_failed_to_load if @p is_product_configurator is @c true and @p context is a Collaboration Context with classic variant structures. 
    <li>#MFG_collaboration_context_product_configurator_variant_structure_failed_to_load if @p is_product_configurator is @c false and @p context is a Collaboration Context with product configurator variant structures.
    </ul> 

    */
    extern MFG_API int MFG_open_context_with_variant_check(
        const tag_t context,                       /**< (I) The context can be subtype/subclass of Item, Collaboration Context and Structure Contexts */
        const logical open_views,                  /**< (I) Set to @c true to open Occurence Group windows. */
        const logical open_associated_contexts,    /**< (I) Set to @c true to open associated contexts. */
        const logical is_product_configurator,     /**< (I) Set to @c true to load the product configurator structure. Otherwise, the classic structure is loaded. */
        int* n_opened_contexts,                    /**< (O) Number of opened contexts. */
        tag_t** opened_contexts,                   /**< (OF) n_opened_contexts The opened contexts. */
        tag_t** structure_contexts,                /**< (OF) n_opened_contexts The structure contexts.  */
        tag_t*  cc                                 /**< (O) The Collaboration Context object */
        );

    extern MFG_API int MFG_open_view(
        tag_t   context,                 /**< (I) context */
        tag_t   sc,                      /**< (I) StructureContext */
        tag_t   view,                    /**< (I) view */
        tag_t*  openedView               /**< (O) opened view */
        );

    extern MFG_API int MFG_close_context(
        tag_t   context                  /**< (I) context */
        );

    extern MFG_API int MFG_close_view(
        tag_t   view,                    /**< (I) view */
        tag_t   sc                       /**< (I) StructureContext */
        );

    extern MFG_API int MFG_set_ref_contexts(
        tag_t   context,                 /**< (I) context */
        int     num_addRefContexts,      /**< (I) number of add contexts */
        tag_t*  addRefContexts,          /**< (I) contexts list to add */
        int     num_removeRefContexts,   /**< (I) number of remove contexts */
        tag_t*  removeRefContexts,       /**< (I) contexts list to remove */
        logical removeExistingRef        /**< (I) if true remove all existing ref contexts */
        );

    extern MFG_API int MFG_get_ref_contexts(
        tag_t   context,                 /**< (I) context */
        int*    count_refContexts,       /**< (O) number of contexts */
        tag_t** refContexts              /**< (OF) contexts list */        
        );

    extern MFG_API int MFG_create_precedence_constraint(
        tag_t          pred,          /**< (I) predecessor*/
        tag_t          succ,          /**< (I) successor*/
        tag_t*         newConstraint  /**< (O) tag to newly created constraint*/
        );

    extern MFG_API int MFG_add_associated_context(
        tag_t    i_source_context,    /**< (I) source_context*/  
        tag_t    i_new_context_to_add /**< (I) new_context_to_add*/
        );

    extern MFG_API int MFG_is_context_associated(
        tag_t    i_source_context,    /**< (I) source_context*/  
        tag_t    i_context_to_check,  /**< (I) context_to_check*/
        logical* o_result             /**< (O) true if associated*/
        );

    /**
    Resolves the tool.
    */
    extern MFG_API int MFG_resolve_toolRequirement(
        tag_t ownerTag,             /**< (I) Process or operation tag*/
        tag_t trObjectTag,          /**< (I) Tool Requirement tag*/
        tag_t toolTag,              /**< (I) Tool tag*/
        const char* toolSource      /**< (I) Tool source*/
        );

    /**
    Finds tools matching the search criteria of Tool Requirement.
    */
    extern MFG_API int MFG_get_candidate_tools_for_tool_requirement(
        tag_t toolRequirementObject,   /**< (I) Tool Requirement tag*/
        tag_t ownerTag,                /**< (I) Process or operation tag*/
        const char* toolSource,        /**< (I) Source of tools*/
        int *nb_found_tools,           /**< (O) Number of found tools*/
        tag_t** found_tools            /**< (OF) nb_found_tools Candidate tools matching the search criteria of Tool Requirement*/
        );

    /**
    Get the Tool Requirements of the process or operation.
    */
    extern MFG_API int MFG_get_tool_requirements(
        tag_t ownerTag,              /**< (I) Process or operation tag*/
        const char* resolvedState,   /**< (I) Resolved state of the Tool Requirement. Values are "ALL", "RESOLVED" and "UNRESOLVED".*/
        int *nb_found_trs,           /**< (O) Number of found Tool Requirements*/
        tag_t** found_trs            /**< (OF) nb_found_trs Tool Requirements that are assigned to process or operation */
        );


    /**
    Create new objects in the BOM structure as specified in the input structure.
    <br/>The method receives create input object to create a new item and automatically adds this item to the target BOM line.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#MFG_invalid_target_type error if the target object type is invalid.
    </ul>
    */
    extern MFG_API int MFG_create_objects(
        int num_input,                     /**< (I) The number of inputs*/
        const MFG_create_input_t* input,   /**< (I) num_input The input for create*/
        int* num_output,                   /**< (O) The number of outputs*/
        MFG_create_output_t** output       /**< (OF) num_output The new objects created*/        
        );


/** @} */

#ifdef __cplusplus
}
#endif

#include <mfg/libmfg_undef.h>
#endif
