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
    @file mfgbvr.h
 
    This file contains the function prototypes for working with the class mfgbvr
    and specifically with the C ITK interface to this class.
 
*/

#ifndef MFGBVR_H
#define MFGBVR_H

#include <unidefs.h>
#include <mfgbvr/libmfgbvr_exports.h>

/**
    @defgroup MFGBVR Manufacturing BOM View Revision (BVR)
    This module defines the required ITK interface for MFG (manufacturing) related operations.
    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif

extern MFGBVR_API int MFG_create_object(
    const char*   type,      /**< (I) type name */
    tag_t         target,    /**< (I) target */
    tag_t         context,   /**< (I) context */
    const char*   name,      /**< (I) Name of the object */
    const char*   desc,      /**< (I) Description for new object */
    int*          count,     /**< (O) Number of created objects */
    tag_t**       newObjects /**< (OF) count Returned array of newly created objects tags */
    );

extern MFGBVR_API int MFG_create_EBOPContext(
    const char*   type,                 /**< (I) type name */
    const char*   name,                 /**< (I) Name of the object */
    const char*   desc,                 /**< (I) Description for new object */
    const char*   rootPartitionType,    /**< (I) root partition type name */
    const char*   rootPartitionName,    /**< (I) root partition name */
    const char*   rootPartitionDesc,    /**< (I) root partition description */
    int*          count,                /**< (O) Number of created objects */
    tag_t**       newObjects            /**< (OF) count Returned array of newly created objects tags */
    );

/** @} */

/**
@{
*/
extern MFGBVR_API int MFG_getLDRepresentation(
    tag_t line,                    /**< (I) */
    char** ld_concat               /**< (O) */
    );

extern MFGBVR_API int MFG_search_lines_in_context(
    tag_t top_line,                     /**< (I) The top line of the window  */
    const char* logical_pos,            /**< (I) The value of logical position */
    const char* usage_address,          /**< (I) The value of the usage address */
    int op,                             /**< (I) The operator */
    tag_t ** found_lines,               /**< (O) The lines that are found in the search  */
    int * size                          /**< (O) The number of the lines found in the search  */
    );


/** @} */

/**
@{
*/
extern MFGBVR_API int MFG_create_logical_assignment(
    tag_t         target,    /**< (I) target */
    tag_t         context,   /**< (I) context */
    const char*   name,      /**< (I) Name of the object */
    const char*   desc,      /**< (I) Description for new object */
    const char*   assignType,/**< (I) assignment type */
    const char*   usageAddr, /**< (I) usage address */
    const char*   position,  /**< (I) logical position */
    tag_t*        newObj     /**< (O) tag to newly created object */
    );

/** @} */


/**
@{
*/
extern MFGBVR_API int MFG_assign_part(
                                      tag_t         target,       /**< (I) target */
                                      tag_t         source,       /**< (I) source */
                                      const char*   relationName, /**< (I) Relation Name */
                                      const char*   relationType, /**< (I) Relation Type */
                                      tag_t*        newObj        /**< (O) tag to newly created object */
                                      );

/** @} */

/**
@{
*/
extern MFGBVR_API int MFG_allocate_object(
                                      tag_t         target,       /**< (I) target */
                                      tag_t         source,       /**< (I) source */
                                      tag_t*        newObj        /**< (O) tag to newly created object */
                                      );

/** @} */

/**
@{
*/
extern MFGBVR_API int MFG_connect_object(
    tag_t         target,       /**< (I) target */
    tag_t         source,       /**< (I) source */
    const char*   relationType, /**< (I) Relation Type */
    tag_t*        newObj        /**< (O) tag to newly created object */
    );

/** @} */

/**
@{
*/
extern MFGBVR_API int MFG_create_search_criteria_for_tool_requirement(tag_t        icsClass, /**< (I) */
                                                                      int          icsOptions, /**< (I) */
                                                                      int          noOfUncts, /**< (I) */
                                                                      const int   *uncts, /**< (I) */
                                                                      const char **unctValues, /**< (I) */
                                                                      tag_t       *searchCriteriaTag /**< (O) */
                                                                      );
/** @} */

/**
@{
*/
extern MFGBVR_API int MFG_create_tool_requirement(tag_t target, /**< (I) Operation/process */
                                                  tag_t context, /**< (I) Mostly null */
                                                  const char *name, /**< (I) TR Name */
                                                  const char *desc, /**< (I) TR description */
                                                  const char *assignType, /**< (I) Assignment Type say METool */
                                                  tag_t searchCriteria, /**< (I) Could be NULL */
                                                  tag_t *newObj /**< (O) TR Object */
                                                  );



/** @} */

/**
Copies relationship data for scope flows from old revision to new revision.
 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#MFGBVR_internal_error if an invalid item revision is provided.
    <li>Possibly other errors
    </ul>
*/
extern MFGBVR_API int MFG_copy_data_for_scope_flows(
    tag_t old_revision, /**< (I) Old Revision tag on which the scope flow relationship exists */
    tag_t new_revision  /**< (I) New Revision tag in which the scope flow relationship data needs to be copied */
    );

/**
Exports objects to Briefcase in off line mode.
<br/>If the exported object is a Collaboration Context (CC) then
     <ul>
    <li> An Appearance Path Node (APN) is also created for the identified BOMLine objects in the CC. The BOMLine objects are identified based on the preference MERuleForBriefcaseExport.
    <li> If there is a session option "opt_exp_partial_bom_input" then product structure is exported partially based on the consumptions in BOP.
    <li> If the value of session option "autoOTCR" is true then recursive ownership transfer is done on objects marked for ownership transfer.
    </ul>
<br/>
 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#GMS_zero_target_sites  if @p n_sites is 0.
    <li>#GMS_invalid_target_site if any site in @p sites is invalid (NULLTAG).
    <li>#GMS_nothing_to_process if any object in @p objects is invalid (NULLTAG).
    <li>#MFGBVR_partial_export_not_allowed if there are any exceptions while finding occurrence thread chain for partial export.
    </ul>
*/
extern MFGBVR_API int MFG_export_objects_to_briefcase(
    const char *    reason,                 /**< (I) Reason for the export. This can be a null pointer.*/
    int             n_objects,              /**< (I) Number of objects to be exported.*/
    const tag_t *   objects,                /**< (I) n_objects Objects to be exported.*/
    int             n_sites,                /**< (I) Number of sites to which objects are to be exported.*/
    const tag_t *   sites,                  /**< (I) n_sites Sites to which objects are to be exported.*/
    tag_t           option_set,             /**< (I) The object of type "TransferOptionSet".*/
    int             n_options,              /**< (I) Number of transfer options whose values need to different than in "TransferOptionSet".*/
    const char **   option_names,           /**< (I) n_options Options whose values need to different than in "TransferOptionSet".
                                            <br/>Some of the valid values are:
                                            <ul>
                                            <li>opt_do_struct       (true/false)</li>
                                            <li>opt_rev_select      (latestRevisionOnly/allReleasedRevisionsOnly/ etc)</li>
                                            <li>opt_entire_bom      (true/false)</li>
                                            </ul>
                                            <br/>For the extensive list, please refer to the documentation of the PLM XML Export Import administration tool. */
    const char **   option_values,          /**< (I) n_options Overridden Values.*/
    int             n_session_options,      /**< (I) Number of session options*/
    const char **   session_option_names,   /**< (I) n_session_options Session options.
                                            <br/>Some of the valid values are:
                                            <ul>
                                            <li>modified_objects_only   (True/False)</li>
                                            <li>continue_on_error       (True/False)</li>
                                            <li>dry_run                 (True/False)</li>
                                            <li>offline                 (True/False)</li>
                                            <li>transfer_site_ownership (True/False)</li>
                                            </ul>
                                            <br/>For the extensive list, please refer to the documentation of the PLM XML Export Import administration tool. */
    const char **   session_option_values,  /**< (I) n_session_options Values of session options.*/
    tag_t *         briefcase_dataset,      /**< (O) Tag of the dataset representing exported briefcase.*/
    char **         briefcase_file_name,    /**< (OF) File name of the exported briefcase.*/
    int  *          n_export_log_files,     /**< (O) Number of log files.*/
    char ***        export_log_files        /**< (OF) n_export_log_files Log files. <br/>The array is not packed, which means that the memory is to be deallocated calling #MEM_free on all of the members individually and on the container also. */
);

/** 
Exports objects to Briefcase. If the exported object is a Collaboration Context (CC), an Appearance Path Node (APN) is also created for the identified BOMLine objects in the CC.
<br/>The BOMLine objects are identified based on the preference MERuleForBriefcaseExport.
@returns
<ul>
    <li>#ITK_ok on success.
    <li>#GMS_zero_target_sites  if @p n_sites is 0.
    <li>#GMS_invalid_target_site if any site in @p sites is invalid (NULLTAG).
    <li>#GMS_nothing_to_process if any object in @p objects is invalid (NULLTAG).
</ul>
*/
extern MFGBVR_API int MFG_request_remote_export(
    int             n_objects,              /**< (I) Number of objects to be exported.*/
    const tag_t*    objects,                /**< (I) n_objects Objects to be exported. */
    int             n_sites,                /**< (I) Number of sites to which objects are to be exported.*/
    const tag_t*    sites,                  /**< (I) n_sites Sites to which objects are to be exported. */
    const char*     reason,                 /**< (I) Reason for the export. This can be a null pointer.*/
    tag_t           option_set,             /**< (I) The object of type "TransferOptionSet".*/
    int             n_options,              /**< (I) Number of transfer options whose values need to different than in "TransferOptionSet".*/
    const char**    option_names,           /**< (I) n_options Options whose values need to different than in "TransferOptionSet".
                                            <br/>Some of the values are:
                                            <ul>
                                            <li>opt_do_struct       (true/false)</li>
                                            <li>opt_rev_select      (latestRevisionOnly/allReleasedRevisionsOnly/ etc)</li>
                                            <li>opt_entire_bom      (true/false)</li>
                                            </ul>
                                            <br/>For the extensive list, please refer to the documentation of the PLM XML Export Import administration tool. */
    const char**    option_values,          /**< (I) n_options Overridden Values. */
    int             n_session_options,      /**< (I) Number of session options.*/
    const char**    session_option_names,   /**< (I) n_session_options Session options.
                                            <br/>Some of the values are:
                                            <ul>
                                            <li>modified_objects_only   (True/False)</li>
                                            <li>continue_on_error       (True/False)</li>
                                            <li>dry_run                 (True/False)</li>
                                            <li>offline                 (True/False)</li>
                                            <li>transfer_site_ownership (True/False)</li>
                                            </ul>
                                            <br/>For the extensive list, please refer to the documentation of the PLM XML Export Import administration tool. */
    const char**    session_option_values,  /**< (I) n_session_options Values of session options. */
    int             priority,               /**< (I) Can assume value either -2 or -1*/
    logical         email_notification,     /**< (I) Should sent email or not.*/
    int             n_email_addrs,          /**< (I) Number of email recipients.*/
    char**          email_addrs,            /**< (I) n_email_addrs Email addresses.*/
    int*            n_msg_ids,              /**< (O) Number of messages.*/
    char***         msg_ids                 /**< (OF) n_msg_ids Messages. <br/>The array is not packed, which means that the memory is to be deallocated calling #MEM_free on all of the members individually and on the container also.*/
);

/**
   Structure for recipe resolved lines
*/
typedef MFGBVR_API struct MFG_resolved_lines_s
{
    tag_t mbom_scope;                       /**< Manufacturing BOM scope below which the following lines are resolved. */
    unsigned int n_recipe_resolved;         /**< Number of lines resolved using the recipes defined on or below mbom_scope */
    tag_t* recipe_resolved_lines;           /**< n_recipe_resolved bomline tags of resolved recipes */
    unsigned int n_manually_assigned;       /**< Number of manually assigned lines.*/
    tag_t* manually_assigned_lines;         /**< n_manually_assigned bomline tags that are assigned manually.*/
} MFG_resolved_lines_t;


/**
Resolves recipes defined on given MBOM to perform auto assignment from the source EBOM which is linked to MBOM.
@returns
<ul>
    <li>#ITK_ok on success.
    <li>#SOAMANUFACTURING_invalid_scope if @p n_ebom_scopes = 0 or any object in @p ebom_scopes is #NULLTAG
    <li>#ME_mbom_ebom_roots_not_linked, if EBOM and MBOM root are not linked
</ul>
*/
extern MFGBVR_API int MFG_resolve_assignment_recipe(
    unsigned int n_mbom_scopes,         /**< (I) Number of Manufacturing BOM (MBOM) scope lines on or below which the recipe should be resolved. */
    const tag_t* mbom_scopes,           /**< (I) n_mbom_scopes Manufacturing BOM scope lines. All the scope lines should be from the same structure */
    unsigned int n_ebom_scopes,         /**< (I) Number of Engineering BOM (EBOM) scope lines. Currently only one EBOM scope is supported */
    const tag_t* ebom_scopes,           /**< (I) n_ebom_scopes EBOM scope lines */
    unsigned int n_recipe_objs,         /**< (I) Number of Recipe objects that are a subset of recipes defined on or below MBOM scope line. */
    const tag_t* recipe_objs,           /**< (I) n_recipe_objs Recipe objects to be resolved. if @p n_recipe_objs is 0, the @p mbom_scopes are used to get the recipe objects. */
    logical re_resolve,                 /**< (I) If @c true resolve the recipes, otherwise return the previously resolved lines. */
    logical remove_previously_resolved, /**< (I) If @c true, any previously resolved lines are removed. */
    logical recursive,                  /**< (I) If @c true, recursively resolves under the given recipe anchor. */
    logical generate_log,               /**< (I) If @c true, generates a log file with details of the resolved lines for given recipe under a parent line. */
    unsigned int* n_scope_resolved,     /**< (O) Number of MBOM scopes for which recipes are resolved.*/
    MFG_resolved_lines_t** resolved,    /**< (OF) n_scope_resolved Structures containing the MBOM scope objects and assigned lines below these scopes.<br/>The array is not packed, which means that the memory is to be deallocated calling #MEM_free on all of the members individually and on the container also.*/
    char** log_file_path                /**< (OF) Absolute path of the log file containing details of the resolved lines for each recipe on or below the MBOM scopes.*/
);

/**
    Creates the associated twin structure of a Plant BOP (Bill Of Process) or a BOE (Bill Of Equipment) structure.

    <br/>If the operation is invoked on top line of the Plant BOP structure, it creates associated BOE structure as a twin.
    <br/>If the operation is invoked on top line of the BOE structure, it creates associated Plant BOP structure as a twin.

    @note The preference @c MEBOPToBOEObjectTypeMap specifies the XML dataset name which defines object type mappings and
    their attribute mappings between BOE and Plant BOP structures.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#MFGBVR_invalid_create_twin_input if @p source_object is neither a valid Plant BOP nor BOE structure.
    <li>#MFGBVR_associated_plantbop_already_exist if The associated Plant Bill Of Process structure already exist for the given input Bill of Equipment line.
    <li>#MFGBVR_associated_plant_already_exist if The associated Bill Of Equipment structure already exist for the given input Plant Bill of Process line.
    <li>#MFGBVR_create_boe_no_mapping_available if object type and their attribute mappings are missing in the XML dataset name referenced by the preference @c MEBOPToBOEObjectTypeMap.
    <<li>#MFGBVR_BOPToBOE_no_dataset if no valid XML dataset name is specified by the @c MEBOPToBOEObjectTypeMap preference.
    <li>#MFGBVR_target_structure_created_with_errors if any other issue.
    </ul>
*/
extern MFGBVR_API int MFGBVR_create_associated_twin(
    tag_t source_object,                               /**< (I) The top line of a Plant BOP or BOE structure. */
    tag_t* twin_structure                              /**< (O) The top line of the associated twin structure. */
);

/**
    Synchronizes the associated twin lines of a Plant BOP (Bill Of Process) or a BOE (Bill Of Equipment) lines.

    <br/>Determines the associated target structure with source lines, and creates the missing elements in target structure and the type of the element to be created is identified by mappings defined in the XML dataset name referenced by the preference @c MEBOPToBOEObjectTypeMap.
    <br/>Updates the properties in target structure and the properties to be updated are identified by mappings defined in the XML dataset name referenced by the preference @c MEBOPToBOEObjectTypeMap.

    @note The preference @c MEBOPToBOEObjectTypeMap specifies the XML dataset name which defines object type mappings and
    their attribute mappings between BOE and Plant BOP structures.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#MFGBVR_invalid_sync_twin_input if the @p source_object is neither a valid Plant BOP nor BOE structure.
    <li>#MFGBVR_associated_plantbop_does_not_exist if the @p source_objects is not linked with the associated Plant BOP object.
    <li>#MFGBVR_associated_plant_does_not_exist if the @p source_objects is not linked with the associated BOE object.
    <li>#MFGBVR_sync_object_types_not_compatible if the @p source_object type is not compatible with the the associated Plant BOP or BOE object.
    <li>#MFGBVR_sync_failed_for_input_objects if multiple issues found during synchronization.
    </ul>
*/
extern MFGBVR_API int MFGBVR_sync_twin_lines_from_source(
    unsigned int n_objects,                              /**< (I) The number of objects to be synchronized. */
    const tag_t* source_objects,                         /**< (I) n_objects The source lines of either Plant BOP or BOE structure. */
    logical is_remove_obsolete_twin,                     /**< (I) If the @c true, the associated lines which do not have relations of type @c Mfg0MELinkedBOERel will be removed from the associated structure. */ 
    unsigned int *n_twin_relations,                      /**< (O) The Number of twin relations that were created during synchronize.*/
    tag_t** twin_relations                               /**< (OF) n_twin_relations The twin relations that were created during synchronize.*/
);

/**
    Synchronizes the twin lines of a Plant BOP (Bill Of Process) or a BOE (Bill Of Equipment) lines.

    <br/>Creates the missing elements in source structure and the type of the element to be created is identified by mappings defined in the XML dataset name referenced by the preference @c MEBOPToBOEObjectTypeMap.
    <br/>Updates the properties in source structure and the properties to be updated are identified by mappings defined in the XML dataset name referenced by the preference @c MEBOPToBOEObjectTypeMap.

    @note The preference @c MEBOPToBOEObjectTypeMap specifies the XML dataset name which defines object type mappings and
    their attribute mappings between BOE and Plant BOP structures.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#MFGBVR_invalid_sync_twin_input if the @p source_object or @p target_object is neither a valid Plant BOP nor BOE structure.
    <li>#MFGBVR_sync_input_objects_not_linked if the @p source_object type and @p target object type are not linked.
    <li>#MFGBVR_sync_object_types_not_compatible if the @p source_object type is not compatible with the the associated Plant BOP or BOE object.
    <li>#MFGBVR_sync_failed_for_input_objects if multiple issues found during synchronization.
    </ul>
*/

extern MFGBVR_API int MFGBVR_sync_twin_lines(
    unsigned int n_objects,                              /**< (I) The number of objects to be synchronized. */
    tag_t* source_objects,                               /**< (I) n_objects The source lines of either Plant BOP or BOE structure. */
    tag_t* target_objects,                               /**< (I) n_objects The target lines of either BOE or Plant BOP structure. If the @p source_objects are Plant BOP lines then @p target_object should be BOE lines and vice versa.*/
    logical is_remove_obsolete_twin,                     /**< (I) If the @c true, the @p source_lines which do not have relation @c Mfg0MELinkedBOERel will be removed from the target structure.*/
    unsigned int *n_twin_relations,                      /**< (O) The Number of twin relations that were created during synchronize.*/
    tag_t** twin_relations                               /**< (OF) n_twin_relations The twin relations that were created during synchronize.*/
);

#ifdef __cplusplus
}
#endif

#include <mfgbvr/libmfgbvr_undef.h>
#endif
