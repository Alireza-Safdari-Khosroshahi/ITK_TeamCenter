/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    ITK API for Collaboration Context
*/

/*  */

#ifndef COLLABCTX_H
#define COLLABCTX_H

#include <unidefs.h>

#include <collabctx/libcollabctx_exports.h>

/**
    @defgroup COLLABCTX Collaboration Context (CC)
    @{
*/

/**
    @name Collaboration Context related
    @{
*/
#define COLLABCTX_CCObject_class_name_c             "CCObject"
#define COLLABCTX_StructureContext_class_name_c     "StructureContext"
#define COLLABCTX_context_relation_name             "IMAN_CCContext"
#define COLLABCTX_structure_content_relation_name   "IMAN_StructureContent"
#define COLLABCTX_study_relation_name               "IMAN_CCStudy"
#define COLLABCTX_context_lov_name                  "Context Names"
#define COLLABCTX_ConfigurationContext_class_name_c "ConfigurationContext"
#define COLLABCTX_SCTypeData_class_name_c           "SCTypeData"
#define COLLABCTX_ref_context_relation_name         "IMAN_CCReferenceContext"
#define COLLABCTX_PrivateContext_class_name_c       "PrivateContext"
#define COLLABCTX_SCTypeData_relation_name          "IMAN_SCTypeData"
#define COLLABCTX_Mfg0CCStudy_relation_name         "Mfg0CCStudyRel"
#define COLLABCTX_StudyStructureContext_class_name  "Mfg0StudyStructureContext"
/** @} */

/**
    @name Type related
    @{
*/
#define COLLABCTX_ccobject_type_name_c              "CCObject"
#define COLLABCTX_me_ccobject_type_name_c           "MECollaborationContext"
#define COLLABCTX_product_structure_type_name_c     "MEProductContext"
#define COLLABCTX_factory_structure_type_name_c     "MEPlantContext"
#define COLLABCTX_process_structure_type_name_c     "MEProcessContext"
#define COLLABCTX_resource_structure_type_name_c    "MEResourceContext"
#define COLLABCTX_private_structure_type_name_c     "PrivateContext"
#define COLLABCTX_composition_structure_type_name_c "CompositionContext"
#define COLLABCTX_configuration_context_type_name_c "ConfigurationContext"
#define COLLABCTX_sctypedata_type_name_c            "SCTypeData"

/** @} */

/**
    @name Define macro for StructureContent relation subtype
    @{
*/
#define COLLABCTX_content_rel_any_stype             0
#define COLLABCTX_content_rel_background            ( 1 << 0 )
#define COLLABCTX_content_rel_target                ( 1 << 1 )
/** @} */

#ifdef __cplusplus
    extern "C"{
#endif
/**
    @name Collaboration Context Setup Function
    @{
*/

/**
    Initializes the Collaboration Context module.
    This function must be called before using any other Collaboration Context module functions.
    This function will be called by the standard ITK startup code.
    The ITK programmer can ignore this function.
    @note A second call is ignored.
*/
extern COLLABCTX_API int COLLABCTX_init_module();
/** @} */

/**
    @name Collaboration Context creation Functions
    @{
*/

/**
    Creates the CCObject instance.
*/
extern COLLABCTX_API int COLLABCTX_create_ccobject(
    const char*          type,         /**< (I) Type name - can be empty - will take default type*/
    const char*          name,         /**< (I) Name of the CCObject*/
    const char*          desc,         /**< (I) Description of the CCObject*/
    tag_t*               cc            /**< (O) Tag of CCObject instance */
    );

/**
    Creates the StructureContext instance.
*/
extern COLLABCTX_API int COLLABCTX_create_structure_context(
    const char*          type,       /**< (I) Type name - can be empty - will take default type*/
    const char*          name,       /**< (I) Name of the StructureContext*/
    const char*          desc,       /**< (I) Description of the StructureContext*/
    tag_t*               context     /**< (O) Tag of StructureContext instance */
    );

/**
    Creates ConfigurationContext instance.
*/
extern COLLABCTX_API int COLLABCTX_create_configuration_context(
    const char*          type,       /**< (I) Type name - can be empty - will take default type*/
    const char*          name,       /**< (I) Name of the ConfigurationContext*/
    const char*          desc,       /**< (I) Description of the ConfigurationContext*/
    tag_t*               rule        /**< (O) Tag of ConfigurationContext instance*/
    );

/**
    Creates ConfigurationContext instance based on reference
*/
extern COLLABCTX_API int COLLABCTX_create_config_context_based_on_ref(
    const char*         type,       /**< (I) Type name - can be empty - will take default type*/
    const char*         name,       /**< (I) Name of the ConfigurationContext*/
    const char*         desc,       /**< (I) Description of the ConfigurationContext*/
    tag_t*              ref_obj_tag,/**< (I) Tag of reference object*/
    tag_t*              context     /**< (O) Tag of ConfigurationContext instance*/
    );

/** @} */

/**
    @name Functions for CCObject
    @{
*/

/**
    Adds StructureContext to CC.
*/
extern COLLABCTX_API int COLLABCTX_add_structure_context(
    tag_t                cc,           /**< (I) The CCObject */
    tag_t                context       /**< (I) The StructureContext to be added */
    );

/**
    Removes StructureContext from CC.
*/
extern COLLABCTX_API int COLLABCTX_remove_structure_context(
    tag_t                cc,       /**< (I) The CCObject */
    tag_t                context   /**< (I) The StructureContext to be removed */
    );

/**
    Retrieves all StructureContext.
*/
extern COLLABCTX_API int COLLABCTX_ask_structure_contexts(
    tag_t                cc,         /**< (I) The CCObject */
    int*                 number,     /**< (O) Number of StructureContexts */
    tag_t**              contexts    /**< (OF) The StructureContexts tag list */
    );

/**
    Retrieves the working StructureContext (also called Study).
    @note There will be only one working context
*/
extern COLLABCTX_API int COLLABCTX_ask_working_context(
    tag_t                cc,       /**< (I) The CCObject */
    tag_t*               context   /**< (O) Tag of the Working StructureContext */
    );

/**
    Sets the working StructureContext
*/
extern COLLABCTX_API int COLLABCTX_set_working_context(
    tag_t                cc,       /**< (I) The CCObject */
    tag_t                context   /**< (I) The StructureContext to be set */
    );

/**
    Retrieves the ConfigurationContext used by this CCObject.
*/
extern COLLABCTX_API int COLLABCTX_ccobj_ask_config_context(
    tag_t                cc,           /**< (I) The CCObject */
    tag_t*               config        /**< (O) Tag of the ConfigurationContext */
    );

/**
    Sets ConfigurationContext to the CCObject.
*/
extern COLLABCTX_API int COLLABCTX_ccobj_set_config_context(
    tag_t                cc,           /**< (I) The CCObject */
    tag_t                config        /**< (I) The ConfigurationContext  to be set*/
    );
/** @} */

/**
    @name Functions for StructureContext
    @{
*/

/**
    Retrieves the ConfigurationContext used by this StructureContext.
*/
extern COLLABCTX_API int COLLABCTX_context_ask_config_context(
    tag_t                context,      /**< (I) The StructureContext */
    tag_t*               config        /**< (O) Tag of the ConfigurationContext */
    );

/**
    Sets ConfigurationContext to the StructureContext.
*/
extern COLLABCTX_API int COLLABCTX_context_set_config_context(
    tag_t                context,       /**< (I) The StructureContext */
    tag_t                config         /**< (I) The ConfigurationContext to be set*/
    );

/**
    Adds component to StructureContext.
    @note The component can be Item/ItemRevision/AppearanceGroup.
*/
extern COLLABCTX_API int COLLABCTX_context_add_content(
    tag_t                context,      /**< (I) The StructureContext */
    tag_t                comp,         /**< (I) The component to be added*/
    int                  subType       /**< (I) Subtype such as #COLLABCTX_content_rel_background */
    );

/**
    Removes component from StructureContext.
    @note The component can be Item/ItemRevision/AppearanceGroup.
*/
extern COLLABCTX_API int COLLABCTX_context_remove_content(
    tag_t                context,      /**< (I) The StructureContext */
    tag_t                comp          /**< (I) The component to be removed*/
    );

/**
    Retrieves all the components used by this StructureContext.
*/
extern COLLABCTX_API int COLLABCTX_context_ask_contents(
    tag_t                context,    /**< (I) StructureContext */
    int*                 number,     /**< (O) Number of contexts */
    tag_t**              contents,   /**< (OF) number Contexts list */
    int                  subType     /**< (I) SubType of the content relation such as background/target, etc. */
    );

/**
    Determines whether StructureContext is a composition.
*/
extern COLLABCTX_API int COLLABCTX_context_is_composition(
    tag_t                context,       /**< (I) The StructureContext */
    logical*             isComp         /**< (O) Whether or not it is a composition */
    );

/**
    Determines whether StructureContext only allow an End Item.
*/
extern COLLABCTX_API int COLLABCTX_context_single_end_item(
    tag_t                context,       /**< (I) The StructureContext */
    logical*             isSingle       /**< (O) Whether or not it allows only single End Item */
    );
/** @} */

/**
    @name Functions for ConfigurationContext
    @{
*/

/**
    Sets ClosureRule to ConfigurationContext. It will be saved as well.
*/
extern COLLABCTX_API int COLLABCTX_configuration_set_closurerule(
    tag_t                context,      /**< (I) The ConfigurationContext */
    tag_t                rule          /**< (I) The closure rule to be set*/
    );

/**
    Temporarily changes ClosureRule to ConfigurationContext.
    @note It will not be saved
*/
extern COLLABCTX_API int COLLABCTX_configuration_chg_closurerule(
    tag_t                context,      /**< (I) The ConfigurationContext */
    tag_t                rule          /**< (I) The new Closure rule*/
    );

/**
    Retrieves the ClosureRule stored in ConfigurationContext.
*/
extern COLLABCTX_API int COLLABCTX_configuration_ask_closurerule(
    tag_t                context,      /**< (I) The ConfigurationContext */
    tag_t*               rule          /**< (O) Tag of the Closure rule */
    );

/**
    Sets RevisionRule to ConfigurationContext. If Rule is a run time revision rule, we will:
    <ol>
    <li>if context already has private rule, replace the entries of the private rule
    <li>otherwise, clone the input rule and save it as private rule to the context.
    </ol>
*/
extern COLLABCTX_API int COLLABCTX_configuration_set_revisionrule(
    tag_t                context,      /**< (I) The ConfigurationContext */
    tag_t                rule          /**< (I) The Revision rule to be set */
    );

/**
    Temporarily changes RevisionRule to ConfigurationContext.
    @note It will not be saved
*/
extern COLLABCTX_API int COLLABCTX_configuration_chg_revisionrule(
    tag_t                context,      /**< (I) The ConfigurationContext */
    tag_t                rule          /**< (I) The new Revision rule */
    );

/**
    Retrieves the RevisionRule.
*/
extern COLLABCTX_API int COLLABCTX_configuration_ask_revisionrule(
    tag_t                context,      /**< (I) The ConfigurationContext */
    tag_t*               rule          /**< (O) Tag of the revision rule */
    );

/**
    Sets AssemblyArragement in ConfigurationContext.
*/
extern COLLABCTX_API int COLLABCTX_configuration_set_arrangement(
    tag_t                context,      /**< (I) The ConfigurationContext */
    tag_t                arrangement   /**< (I) The AssemblyArrangement to be set */
    );

/**
    Temporarily changes AssemblyArragement in ConfigurationContext.
    @note It will not be saved
*/
extern COLLABCTX_API int COLLABCTX_configuration_chg_arrangement(
    tag_t                context,      /**< (I) The ConfigurationContext */
    tag_t                arrangement   /**< (I) The new AssemblyArrangement */
    );

/**
    Retrieves  the AssemblyArrangement in ConfigurationContext.
*/
extern COLLABCTX_API int COLLABCTX_configuration_ask_arrangement(
    tag_t                context,      /**< (I) The ConfigurationContext */
    tag_t*               arrangement   /**< (O) Tag of the AssemblyArrangement */
    );

/** @} */

/**
    @name Functions for SC Type Data
    @{
*/

/**
    Determines whether structure context type is composition
*/
extern COLLABCTX_API int COLLABCTX_sctype_ask_is_composition(
    tag_t                scType,     /**< (I) The Structurecontext type*/
    logical*             is_comp     /**< (O) Whether or not it is a composition */
    );

/**
    Determines whether structure context type allows only one end item
*/
extern COLLABCTX_API int COLLABCTX_sctype_ask_single_end_item(
    tag_t                scType,      /**< (I) The Structurecontext type */
    logical*             is_single    /**< (O) Whether or not it allows only single End Item */
    );

/** @} */

/**
    @name Functions for copying objects
    @{
*/

/**
    Copies the CCObject and its relations
*/
extern COLLABCTX_API int COLLABCTX_copy_ccobject(
    tag_t                baseCC,  /**< (I) The CC to copy */
    const char*          name,    /**< (I) Name for new object if different */
    const char*          desc,    /**< (I) Description for new object if different */
    tag_t*               newCC    /**< (O) Tag of new object */
    );

/**
    Copies the StructureContext and its relations
*/
extern COLLABCTX_API int COLLABCTX_copy_structure_context(
    tag_t                baseSC,  /**< (I) The StructureContext to copy */
    const char*          name,    /**< (I) Name for new object if different */
    const char*          desc,    /**< (I) Description for new object if different */
    tag_t*               newSC    /**< (O) Tag of new object */
    );

/**
    Copies the ConfigurationContext and its relations
*/
extern COLLABCTX_API int COLLABCTX_copy_configuration_context(
    tag_t                baseConfig,    /**< (I) The ConfigurationContext to copy */
    const char*          name,          /**< (I) Name for new object if different */
    const char*          desc,          /**< (I) Description for new object if different */
    tag_t*               newConfig      /**< (O) Tag of new object */
    );

/** @} */

/**
    @name Accountability check functions
    @{
*/

/**
    Performs an accountability check 
*/
extern COLLABCTX_API int COLLABCTX_acctability_check(
    tag_t* srcLines,            /**< (I) List of lines from source window. Structures rooted by each of them will be checked. */
    int srcLineCount,           /**< (I) Number of source lines. */
    tag_t* tarLines,            /**< (I) List of lines from target widnow. Checked will be done over the structures under these lines only. */
    int tarLineCount,           /**< (I) Number of target lines. */
    int options,                /**< (I) Options of accountability check. Expected to be any combination of the following:
                                    add 1 - For source lines with "stop" marks, if to check their children.
                                    add 2 - If to check source lines at the lowest level only, as opposed to at all levels.
                                    add 4 - If to search all contextes in target, as opposed to the current active context.
                                    add 8 - If to search by absolute occurrence ID's only, as opposed to strictly by absolute
                                            occurrence objects.
                                    add 16 - If to compare a pre-define list of additional properties during the check.
                                    add 32 - If to search for target lines connected via PublishLink
                                */
    tag_t assyCtxtLineTag,      /**< (I) The possible source context line (in case the check is done when in-context mode is on)*/
    tag_t bomCtxtLineTag,       /**< (I) The possible target context line  (in case the check is done when in-context mode is on)*/
    int* srcRetCount,           /**< (O) Number of source lines checked. */
    tag_t** srcRetTags,         /**< (OF) List of source lines checked. If not interested in this output, let *srcRetCount = -1 before calling. */
    int* matRetCount,           /**< (O) Number of matched target lines */
    tag_t** matRetTags          /**< (OF) List of matched target lines. If not interested in this output, let *matRetCount = -1 before calling.*/
    );

/**
    Performs accountability check on source (e.g. EBOM) and target (e.g. MBOM) BOM structures and generates reports.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ME_invalid_input_arguments if @p n_source_scopes or @p n_target_scopes is 0.
    <li>#ME_invalid_input_arguments if any element in @p source_scopes or @p target_scopes is #NULLTAG or an invalid tag.
    <li>#ME_invalid_input_arguments if not all elements in @p source_scopes are from the same BOM window.
    <li>#ME_invalid_input_arguments if not all elements in @p target_scopes are from the same BOM window.
    <li>#ME_invalid_input_arguments if all elements in @p source_scopes and @p target_scopes are from the same BOM window.
    <li>#ME_invalid_input_arguments if @p favorite_dataset is #NULLTAG and @p favorite_xml_file_path is NULL.
    <li>#ME_invalid_input_arguments if @p favorite_dataset is not NULLTAG but is invalid.
    <li>#ME_invalid_input_arguments if @p favorite_xml_file_path is not NULL but is an invalid path.
    <li>Any errors returned from accountability check engine or ACFavorite.
    </ul>
*/
extern COLLABCTX_API int COLLABCTX_accountability_check(
    const unsigned int n_source_scopes,          /**< (I) The number of source scope lines.*/    
    const tag_t* source_scopes,                  /**< (I) n_source_scopes The source scope lines.*/                    
    const unsigned int n_target_scopes,          /**< (I) The number of target scope lines.*/    
    const tag_t* target_scopes,                  /**< (I) n_target_scopes The target scope lines.*/
    const tag_t favorite_dataset,                /**< (I) Accountability check favorite dataset that contains user inputs.*/
    const char* favorite_xml_file_path,          /**< (I) Absolute path to a favorite XML file on a local disk. If both @p favorite_dataset and @p favorite_xml_file_path are given, 
                                                        use only the @p favorite_xml_file_path.*/
    const char* report_name,                     /**< (I) The name of the generated excel report. If specified, it will overwrite the value for the tag @c reportName in the favorite's XML.*/    
    const char* occurrence_group_name,           /**< (I) The name of the generated occurrence group. If specified, it will overwrite the value for the tag @c resultName in the favorite's XML.*/  
    const logical create_og_on_target,           /**< (I) Specifies whether to create occurrence group on the target BOM structure.*/
    unsigned int* n_equivalence_sets,            /**< (O) The number of equivalence sets found by accountability check.*/    
    tag_t*** source_equivalents,                 /**< (OF) n_equivalence_sets All source equivalent lines found by accountability check. The first dimension of the list represents all the equivalent sets 
                                                        for source lines, and the size of it is specified by @p n_equivalence_sets. The second dimension of the list represents 
                                                        the source lines of a single equivalent set. This list is terminated by a NULLTAG.
                                                        <br/>The memory is deallocated by calling #MEM_free on each dimension container.
                                                 */
    tag_t*** target_equivalents,                 /**< (OF) n_equivalence_sets All target equivalent lines found by accountability check. The first dimension of the list represents all the equivalent sets 
                                                        for target lines, and the size of it is specified by @p n_equivalence_sets. The second dimension of the list represents 
                                                        the target lines of a single equivalent set. This list is terminated by a NULLTAG.
                                                        <br/>The memory is deallocated by calling #MEM_free on each dimension container.
                                                 */ 
    unsigned int** check_results,                /**< (OF) n_equivalence_sets The list of accountability check results for all equivalent sets.                                                        
                                                        <br/>Each value in the list represents an accountability check result that can be one of the following: 
                                                        <ul>
                                                        <li>0 for full match</li> 
                                                        <li>1 for multiple match</li> 
                                                        <li>2 for partial match</li> 
                                                        <li>3 for multiple partial match/li> 
                                                        <li>4 for missing in target</li> 
                                                        <li>5 for effectivity mismatch</li> 
                                                        <li>6 for partial & effectivity mismatch</li> 
                                                        </ul>                                                                      
                                                 */ 
    unsigned int* n_missing_in_sources,          /**< (O) The number of target lines that are missing in the source structure.*/
    tag_t** missing_in_sources,                  /**< (OF) n_missing_in_sources The list of target lines that are missing in the source structure.*/
    char** report_path,                          /**< (OF) The path to the generated Excel report. <br/>This value is a NULL pointer if the value for the tag @c reportName or @c reportMode in the XML file 
                                                        (through @p favorite_dataset or @p favorite_xml_file_path) is not set to trigger a report generation.*/
    tag_t* source_occurrence_group,              /**< (O) The occurrence group generated on the source structure. <br/>This value is a #NULLTAG if the value for the tag @c resultName or @c reportMode in the XML file 
                                                        (through @p favorite_dataset or @p favorite_xml_file_path) is not set to trigger an occurrence group generation.*/
    tag_t* target_occurrence_group               /**< (O) The occurrence group generated on the target structure. <br/>This value is a #NULLTAG if the value for the tag @c resultName or @c reportMode in the XML file 
                                                        (through @p favorite_dataset or @p favorite_xml_file_path) is not set to trigger an occurrence group generation.*/

    );
    
/**
    After a run of accountability check each line assigned with a color property
    This method resets this property in all the lines
*/
extern COLLABCTX_API int COLLABCTX_clear_acctability_check(
    tag_t* windows,     /**< (I) List of windows on which to clear check results. */
    int num_win         /**< (I) Number of windows in the list. */
    );

/**
    Finds aligned occurrences whose data mismatches
*/
extern COLLABCTX_API int  COLLABCTX_alignment_check(
    tag_t       source_line,                     /**< (I) The scope line to start the alignment check */
    tag_t       target_line,                     /**< (I) The scope line of the target BOM to start alignment check */
    int         *count,                          /**< (O) The number of mismatched pairs */
    tag_t       **source_lines,                  /**< (OF) count Tags of source lines of the mismatches */
    tag_t       **target_lines,                  /**< (OF) count Tags of target lines of the mismatches */
    int         **n_mismatched_properties,       /**< (OF) count Number of the mismatching properties of each mismatched pair (value ranges from 1 to n_properties) */
    int         **mismatched_properties,         /**< (OF) count Indices of mismatched properties */
    int         *n_properties,                   /**< (O)  The number of properties used */
    char        ***properties                    /**< (OF) n_properties Properties used for the check */
    );

/**
    Syncs alignment data
*/
extern COLLABCTX_API int  COLLABCTX_sync_aligned_occurrences(
    tag_t       source_line,                     /**< (I) The source line of the alignment to sync data */
    tag_t       target_line                     /**< (I) The target line of the alignment to sync data */
    );

/**
    Returns the variant rules applied on the associated Configuration Context (CC) object.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#COLLABCTX_invalid_ccobject if the CC object is invalid.
    </ul>
*/
extern COLLABCTX_API int COLLABCTX_configuration_ask_variant_rules(
    tag_t                context,            /**< (I) The Configuration Context object*/
    int*                 num_variant_rules,  /**< (O) Number of variant rules */
    tag_t**              variant_rules       /**< (OF) num_variant_rules List of variant rules */
    );

/**
    Sets variant rules to the Configuration Context (CC) object. If there are no variant rules, the CC object is created 
    without variant rules.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#COLLABCTX_invalid_ccobject if the CC object is invalid.
    <li>#POM_invalid_tag if any of the variant rule is invalid.
    </ul>
   
*/
extern COLLABCTX_API int COLLABCTX_configuration_set_variant_rules(
    tag_t               context,            /**< (I) The Configuration Context object*/
    int                 num_variant_rules,  /**< (I) Number of variant rules*/
    tag_t*              variant_rules       /**< (I) The variant rules to be set*/    
    );

/**
    Temporarily changes the current variant rules with the new rules in the Configuration Context (CC) object.
    The new rules will not be saved. If there are no variant rules, the CC object is created 
    without variant rules.


    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#COLLABCTX_invalid_ccobject if the CC object is invalid.
    <li>#POM_invalid_tag if any of the variant rule is invalid.
    </ul>
   
*/
extern COLLABCTX_API int COLLABCTX_configuration_change_variant_rules(
    tag_t               context,            /**< (I) The Configuration Context object*/
    int                 num_variant_rules,  /**< (I) Number of variant rules*/
    tag_t*              variant_rules       /**< (I) The variant rules to be set*/
    
    );

/**
    Checks whether the given Configuration Context (CC) is present in the database. If it is not, it saves the CC with the name "_PRIVATE_PURGEABLE_CC_". 

    <br/>This ITK is a temporary solution to mark adhoc temporary Configuration Context objects that stateless clients (e.g Active Workspace) might have created. Once marked the objects will be easily identifiable by the mentioned utility in order to be purged. 
    <br/>This ITK should not be used for any other purposes. 

    @attention Adhoc CC objects saved in this manner into the DB can be searched using the name "_PRIVATE_PURGEABLE_CC_", and then purged. 
    <br/>Use the utility 'purge_adhoc_configuration_contexts' in order to achieve that. 

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#COLLABCTX_invalid_ccobject if the @p context is invalid.
    </ul>
*/
extern COLLABCTX_API int COLLABCTX_save_adhoc_configuration_context(
    tag_t               context             /**< (I) The Configuration Context. */
    );

/**
    Creates and retrieves BOM Windows for the given list of Structure Context objects.
    <br/>@note For Each Structure Context object, a BOM Window and a return code will be in @p bom_windows and @p return_codes .
    <br/>In case of a failure BOM Window in @p bom_window will be #NULLTAG and respective error code will be in @p return_codes.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#COLLABCTX_invalid_structure_context if @p structure_contexts contains an invalid object.
    <li>#COLLABCTX_partial_error_for_bom_window_create_for_structure_context if there is an error during the BOM Window creation.
    </ul>
*/
extern COLLABCTX_API int COLLABCTX_create_bomwindows_for_scos(
    const int            n_structure_contexts,     /**< (I) Number of Structure Contexts */
    const tag_t*         structure_contexts,       /**< (I) n_structure_contexts The list of Structure Contexts*/
    tag_t**              bom_windows,              /**< (OF) n_structure_contexts The list of the respective BOM Windows. It can contain #NULLTAG in case of an error.*/
    int**                return_codes              /**< (OF) n_structure_contexts The list of return codes for every structure context object in the input. */
    );

/** @} */

/** @} */

#ifdef __cplusplus
}
#endif

#include <collabctx/libcollabctx_undef.h>

#endif
