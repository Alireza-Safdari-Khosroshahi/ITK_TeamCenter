/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

 /**
    @file

    ITK API for ME
*/

/*  */

#ifndef ME_H
#define ME_H

#include <fclasses/tc_basic.h>
#include <me/me_user_exits.h>
#include <me/libme_exports.h>



/**
    @defgroup ME Manufacturing Process Planner (ME)
    @{
*/

/**
    @name ME related
    @{
*/
#define ME_meprocess_class_name_c               "MEProcess"
#define ME_meop_class_name_c                    "MEOP"
#define ME_meprocess_rev_class_name_c           "MEProcessRevision"
#define ME_meop_rev_class_name_c                "MEOPRevision"
#define ME_activity_class_name_c                "MEActivity"
#define ME_meworkarea_class_name_c              "MEWorkarea"
#define ME_meworkarea_rev_class_name_c          "MEWorkareaRevision"
#define ME_meappearancepathnode_class_name_c    "MEAppearancePathNode"
#define ME_meappearancepathroot_class_name_c    "MEAppearancePathRoot"
#define ME_placeholder_item_id_c                "MEAppGroupPlaceholder"
#define ME_placeholder_item_id_c                "MEAppGroupPlaceholder"
#define ME_appearance_group_class_name_c        "AppearanceGroup"
#define ME_component_relation_class_name_c      "ComponentRelation"
/** @} */

/**
    @name Type related
    @{
*/
#define ME_mestation_type_name_c                "MEStation"
#define ME_mestation_rev_type_name_c            "MEStationRevision"
#define ME_meline_type_name_c                   "MELine"
#define ME_meline_rev_type_name_c               "MELineRevision"
#define ME_meplant_type_name_c                  "MEPlant"
#define ME_meplant_rev_type_name_c              "MEPlantRevision"
#define ME_medepartment_type_name_c             "MEDepartment"
#define ME_medepartment_rev_type_name_c         "MEDepartmentRevision"
#define ME_mesite_type_name_c                   "MESite"
#define ME_mesite_rev_type_name_c               "MESiteRevision"
#define ME_machining_type_name_c                "MENCMachining"
#define ME_machining_rev_type_name_c            "MENCMachining Revision"
#define ME_ncprogram_type_name_c                "MENCProgram"
#define ME_workpiece_type_name_c                "MEWorkpiece"
#define Usage_compareResultView_type_name_c     "UsageCompareResultView"
#define ME_appgrp_app_relation_type_name_c      "IMAN_MEComponent"
#define ME_meproductlocation_type_name_c        "MEProductLocation"
#define ME_meproductlocation_rev_type_name_c    "MEProductLocationRevision"
#define ME_medrill_type_name_c                  "MEDrill"
#define ME_medrill_rev_type_name_c              "MEDrillRevision"
#define ME_meedm_type_name_c                    "MEEDM"
#define ME_meedm_rev_type_name_c                "MEEDMRevision"
#define ME_memilling_type_name_c                "MEMilling"
#define ME_memilling_rev_type_name_c            "MEMilling Revision"
#define ME_memillturn_type_name_c               "MEMillTurn"
#define ME_memillturn_rev_type_name_c           "MEMillTurnRevision"
#define ME_meturning_type_name_c                "METurning"
#define ME_meturning_rev_type_name_c            "METurningRevision"
#define ME_mewedm_type_name_c                   "MEWEDM"
#define ME_mewedm_rev_type_name_c               "MEWEDM Revision"


#define ME_metrace_origin_type_name_c           "Mfg0METraceOriginRel"
#define ME_melogical_designator_type_name_c     "Mfg0MELogicalDesignatorRel"


/** @} */


/**
   @name base view ref window
   @{
*/
#define ME_base_view_ref_window_name_c          "viewBaseWindow"
/** @} */

/**
    @name activity description size
    @{
*/
#define ME_activity_desc_size_c                 240
/** @} */


/** 
    @name Flags to control action on a released Manufacturing BOM (MBOM) node while creating/updating from Engineering BOM (EBOM)
    @{
*/
/**
   Flag to indicate skipping of a non modifiable released Manufacturing BOM (MBOM) node during create/update from a Engineering BOM (EBOM)
*/
#define ME_SKIP_RELEASED_NODE                          1

/**
   Flag to indicate revising of a released Manufacturing BOM (MBOM) node during create/update from a Engineering BOM (EBOM)
*/
#define ME_REVISE_ON_RELEASE                           2

/**
   Flag to indicate only occurrence properties are to be updated on the released Manufacturing BOM (MBOM) node
*/
#define ME_UPDATE_PROP_ON_SELF_ON_RELEASE              3

/**
   Flag to indicate only occurrence properties are to be updated recursively on a released Manufacturing BOM (MBOM) node
*/
#define ME_UPDATE_PROP_ON_SELF_AND_BELOW_ON_RELEASE    4
/** @} */

#ifdef __cplusplus
extern "C"{
#endif
/**
   @name ME Setup Functions
   @{
*/
/**
   Initializes the ME module.
   <br/>This function must be called before using any other ME module functions.
   <br/>This function will be called by the standard ITK startup code.
   <br/>The ITK programmer can ignore this function.
   
   @note A second call is ignored.
*/
    extern ME_API int ME_init_module();


/**
   Initializes the MEBOM module.
   <br/>This function must be called before using any BOP related functions.
   <br/>This function will be called by the standard ITK startup code.
   <br/>The ITK programmer can ignore this function.
   
   @note A second call is ignored.
*/
    extern ME_API int MEBOM_init_module();
/** 
    @}
*/
    
/**
   @name ME Revisable Objects
   @{
*/
/**
   Creates a new process of a given type. It creates a Process, Process Revision and BV/BVR.
   
   <br/><b>Restrictions:</b>
   <br/>For a type other than null to be specified, that type must be defined by the site.
   <br/>If type is null, the default type is MEProcess. The name will be used as the revision's name.

    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
    extern ME_API int ME_create_process (
        const char*   id,       /**< (I) process identification number - system will assign automatically if empty*/
        const char*   revid,    /**< (I) revision id for the first rev - can be empty - automatically assigned*/
        const char*   type,     /**< (I) type name - can be empty - will take default type*/
        const char*   name,     /**< (I) Name of the process*/
        const char*   desc,     /**< (I) Description of process*/
        tag_t*        newProc   /**< (O) tag for newly created process*/
        );
    
/**
   Creates a new Process revision for a given Process. The revid can be empty.
   
   <br/><b>Restrictions:</b>
   <br/>The process for a given "id" needs to be created and saved before creating the revision for it.

   @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
    extern ME_API int ME_create_processrevision (
        const char*   id,           /**< (I) process identification number for which rev is created*/
        const char*   revid,        /**< (I) revision id - can be empty - automatically assigned to next available*/
        tag_t*        newProcRev    /**< (O) tag for newly created process revision*/
        );

/**
    Creates a new Operation of a given type. It creates a Operation and Operation Revision.
    
    <br/><b>Restrictions:</b>
    <br/>For a type other than null to be specified, that type must be defined by the site.
    <br/>If type is null, the default type is MEOP. The name will be used as the revision's name.
    
    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
    extern ME_API int ME_create_operation (
        const char*   id,           /**< (I) operation identification number - system will assign automatically if empty*/
        const char*   revid,        /**< (I) revision id for the first rev - can be empty - automatically assigned*/
        const char*   type,         /**< (I) type name - can be empty - will take default type*/
        const char*   name,         /**< (I) Name of the operation*/
        const char*   desc,         /**< (I) Description for new operation*/
        tag_t*        newProcOp     /**< (O) tag to newly created operation*/
        );

/**
   Creates a new Operation revision for a given Operation. The revid can be empty.
   
   <br/><b>Restrictions:</b>
   <br/>The Operation for a given "id" needs to be created and saved before creating the revision for it.

   @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
    extern ME_API int ME_create_operationrevision (
        const char*   id,           /**< (I) operation identification number for which rev is created*/
        const char*   revid,        /**< (I) revision id - can be empty - automatically assigned to next available*/
        tag_t*        newProcOpRev  /**< (O) tag for newly created operation revision*/
        );

/**
   Creates a new WorkArea of a given type. It creates a WorkArea, WorkArea Revision and BV/BVR.
   
   <br/><b>Restrictions:</b>
   <br/>For a type other than null to be specified, that type must be defined by the site.
   <br/>If type is null, the default type is MEWorkArea. The name will be used as the revision's name.

    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
    extern ME_API int ME_create_workarea (
        const char*   id,           /**< (I) workarea identification number - system will assign automatically if empty*/
        const char*   revid,        /**< (I) revision id for the first rev - can be empty - automatically assigned*/
        const char*   type,         /**< (I) type name - can be empty - will take default type*/
        const char*   name,         /**< (I) Name of the workarea*/
        const char*   desc,         /**< (I) Description of the workarea*/
        tag_t*        newWrkarea    /**< (O) tag for newly created workarea*/
        );

/**
   Creates a new WorkArea revision for a given WorkArea. The revid can be empty.

   <br/><b>Restrictions:</b>
   <br/>The WorkArea for a given "id" needs to be created and saved before creating the revision for it.

   @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
    extern ME_API int ME_create_workarearevision (
        const char*   id,               /**< (I) workarea identification number for which rev is created*/
        const char*   revid,            /**< (I) revision id - can be empty - automatically assigned to next available*/
        tag_t*        newWrkAreaRev     /**< (O) tag for newly created workarea revision*/
        );
/** @} */

/**
   @name ME Activity Creation and Management
   @{
*/
/**
   Creates a new Activity of a given type. The type can be empty. The default location for the activity in
   the Pert chart will be set to (0,0).
*/
    extern ME_API int ME_create_activity(
        const char*   name,     /**< (I) Name of the activity*/
        const char*   type,     /**< (I) Type of the activity - can be empty*/
        const char*   desc,     /**< (I) Description of the activity*/
        double        time,     /**< (I) Time take for activity*/
        tag_t*        newAct    /**< (O) Tag to newly created activity*/
        );
/**
   Creates a new Activity of a given type as above. It then takes the activities that are supplied by an
   array of activities called predList and sets them as predecessor for the newly created activity.
   
   <br/><b>Restrictions:</b>
   <br/>It will not allow adding itself as a predecessor. The predList needs to be an array of tags to activities.
   <br/>It will not allow adding same activity twice to its predecessors.
*/
    extern ME_API int ME_create_activity_with_list(
        const char*   name,         /**< (I) Name of the activity*/
        const char*   type,         /**< (I) Type of the activity - can be empty*/
        const char*   desc,         /**< (I) Description of the activity*/
        double        time,         /**< (I) Time take for activity*/
        int           numPred,      /**< (I) Number of predecessors*/
        const tag_t*  predList,     /**< (O) Array of tags to predecessor activities*/
        tag_t*        newAct        /**< (O) Tag to newly created activity*/
    );

/**
   Adds activity "pred" as a predecessor activity to an activity "succ".
   
   <br/><b>Restrictions:</b>
   <br/>It will not allow adding same activity twice. It will also not allow creation of cyclic relationships.
*/
    extern ME_API int ME_activity_add_predecessor(
        tag_t         successor,     /**< (I) Successor activity*/
        tag_t         predecessor    /**< (I) Predecessor activity*/
        );

/**
   Removes activity "pred" from predecessor activities of an activity "succ".
*/
    extern ME_API int ME_activity_remove_predecessor(
        tag_t         successor,     /**< (I) Successor activity*/
        tag_t         predecessor    /**< (I) Predecessor activity*/
        );

/**
   Lists predecessor activities for a given activity. The list can be empty if no predecessors are defined. 
*/
    extern ME_API int ME_activity_list_predecessors(
        tag_t         successor,         /**< (I) Activity whose predecessors are needed*/
        int*          n_predecessors,    /**< (O) Number of predecessors found*/
        tag_t**       predecessors       /**< (OF) n_predecessors Array of nPred predecessors*/
        );
    
/**
   Lists all leaf level activities for a given activity. Activities can contain other activities
   as its children creating a tree of activities. This API will start at the activity supplied
   and traverse to all leaf (activities without children) level and output all of them in listtags.
*/
    extern ME_API int ME_activity_list_activities(
        tag_t         activity,          /**< (I) Activity for which leaf level activities are needed*/
        int*          n_leaf_activities, /**< (I) Number of activities*/
        tag_t**       leaf_activites     /**< (I) n_leaf_activities List of tags to leaf level activities*/
        );

/**
   Adds a tool that is used by the activity.
*/
    extern ME_API int ME_activity_add_tool(
        tag_t         acttag,       /**< (I) Activity for which tool needs to be added*/
        const char*   toolName      /**< (I) Tool name*/
    );

/**
    Adds a tool that is used by the activity and defined by resLine
*/
    extern ME_API int ME_activity_add_reference_tool(
        tag_t acttag,             /**< (I) Activity to which reference tool needs to be added*/
        const char *toolName,     /**< (I) Name of the tool*/
        tag_t resLineTag,         /**< (I) Tag to resouce bom line */
        tag_t opLineTag           /**< (I) Tag to activity's parent operation bom line*/
        );

/**
   Removes a tool that is used by the activity.
*/
    extern ME_API int ME_activity_remove_tool(
        tag_t         acttag,       /**< (I) Activity for which tool needs to be removed*/
        const char*   toolName      /**< (I) Name of the tool*/
        );

/**
   Lists all tools used by the activity.
*/
    extern ME_API int ME_activity_ask_toollist(
        tag_t         acttag,       /**< (I) Activity for which list of tools is needed*/
        int*          nTool,        /**< (O) Number of tools used by activity*/
        char***       toolList      /**< (OF) Array of tool names used by this activity */
        );
    
/**
    Lists successor activities for a given activity. The list can be empty.
*/
    extern ME_API int ME_activity_list_successors(
        tag_t         predTag,      /**< (I) Input activity*/
        int*          nSucc,        /**< (O) Number of successors*/
        tag_t**       succTags      /**< (OF) Array of successor activities to input activity */
        );

/**
   Lists immediate child activities of a given parent activity.
*/
    extern ME_API int ME_activity_list_activity_children(
        tag_t         activityTag,      /**< (I) Input activity*/
        int*          nChild,           /**< (O) Number of immediate children found*/
        tag_t**       actChildTags      /**< (OF) Array of immediate children for input */
        );
    
/**
   Lists child activities below given activity including all level below it and its immediate
   children. 
*/
    extern ME_API int ME_activity_list_all_children(
        tag_t         activityTag,      /**< (I) Input activity*/
        int*          nChild,           /**< (O) Number of child activities below input activity*/
        tag_t**       actChildTags      /**< (OF) Array of child activities below input activity*/
    );

/**
   Iinserts the child tags to parent tag.
   <br/>If the child tag is an activity, the system will make a new copy and insert to the parentTag.
   <br/>If the child tag is not not an activity, then the system will insert the input tag only
*/
    extern ME_API int ME_activity_insert_tags(
        tag_t         parentTag,    /**< (I) Input activity*/
        int           nChild,       /**< (O) Number of children to be inserted*/
        const tag_t*  childTags     /**< (OF) Array of children to be inserted*/
        );

/**
   Asks the long description of an activity.
*/
    extern ME_API int ME_activity_ask_description2(
        tag_t activityTag,                           /**< (I) Input activity*/
        char **actDesc                               /**< (OF) Description of the object */
        );
    

/**
    Sets the long description of an activity.
*/
    extern ME_API int ME_activity_set_description2(
        tag_t activityTag,                                         /**< (I) Input activity*/
        const char *new_description                                /**< (I) Description of activity*/
        );


/**
   Retrieves the time analysis results for the sub-tree activities
*/
    extern ME_API int ME_Time_Analysis_Rollup(
        tag_t node,                                                    /**< (I) */
        int *nValues,                                                /**< (O) */
        double ** timeAnalysisValues,                                /**< (O) */
        double * tWork,                                                /**< (O) */
        double * tDuration                                            /**< (O) */
        );

/**
   Retrieves the time analysis results for the sub-tree activities
*/
    extern ME_API int ME_Calculate_Allocated_Time(
        tag_t node,                                               /**< (I) */
        const char * calculatedBy,                                    /**< (I) */
        double * allocated_time                                     /**< (O) */
        );
/**
   @}
*/

/**
    @name Template Cloning
    @{
*/
/**
    Performs a clone operation on the specified workspace object
*/
    extern ME_API int ME_copy_recursively(
        tag_t         wso_to_copy,              /**< (I) Tag of the workspace object to clone*/
        tag_t         configuring_bom_window,   /**< (I) BOM window tag to determine which revision to clone*/
        const char*   copy_rules_key,           /**< (I) Rule key from the preferences which controls cloning operation */
        const char*   name,                     /**< (I) Name of the newly cloned workspace object*/
        const char*   description,              /**< (I) Description of newly created object*/
        tag_t*        new_wso                   /**< (O) Tag of a newly created workspace object*/
        );

/**
   Clones a MEProcess or MEOperation revision recursively from input revision ID
*/
    extern ME_API int ME_create_process_from_template (
        const char* id,               /**< (I) Optional - ID of a newly created process*/
        const char* revision_id,      /**< (I) Optional - revision id of a newly created process*/
        const char* name,             /**< (I) Name of a newly created process*/
        const char* description,      /**< (I) Optional - description of a newly created process*/
        tag_t  template_process,      /**< (I) Tag of the process revision to be cloned*/
        tag_t revision_rule,          /**< (I) Tag of a revision rule used for cloning*/
        tag_t bop_window,             /**< (I) Tag of a bopwindow tag to determine which revision to clone*/
        const char * clone_rule_key,  /**< (I) Rule key from the preferences which controls cloning operation*/
        tag_t* new_process            /**< (O) Tag of newly cloned process revision*/
    );

/**
    Clones a Plant revision recursively from input revision id
 */
    extern ME_API int ME_create_plant_from_template (
        const char* id,                /**< (I) Optional - ID of a newly created plant*/
        const char* revision_id,       /**< (I) Optional - revision id of a newly created plant*/
        const char* name,              /**< (I) Name of a newly created plant*/
        const char* description,       /**< (I) Optional - description of a newly created plant*/
        tag_t template_plant_revision, /**< (I) Tag of the plant revision to be cloned*/
        tag_t revision_rule,           /**< (I) Tag of a revision rule used for cloning*/
        tag_t working_window,          /**< (I) Tag of a bomwindow tag to determine which revision to clone*/
        const char * clone_rule_key,   /**< (I) Rule key from the preferences which controls cloning operation*/
        tag_t* new_plant               /**< (O) Tag of newly cloned plant revision*/
        );

/**
   Clones a Product revision recursively from input revision id
*/
    extern ME_API int ME_create_product_from_template (
        const char* id,                    /**< (I) Optional - ID of a newly created product*/
        const char* revision_id,           /**< (I) Optional - revision id of a newly created product*/
        const char* name,                  /**< (I) Name of a newly created product*/
        const char* description,           /**< (I) Optional - description of a newly created product*/
        tag_t  template_product_revision,  /**< (I) Tag of the product revision to be cloned*/
        tag_t revision_rule,               /**< (I) Tag of a revision rule used for cloning*/
        tag_t working_window,              /**< (I) Tag of a bomwindow tag to determine which revision to clone*/
        const char * clone_rule_key,       /**< (I) Rule key from the preferences which controls cloning operation*/
        tag_t* new_product                 /**< (O) Tag of newly cloned product revision*/
        );
/** @} */

/**
    @name Attachments Related
    @{
*/
/**
    Creates assembly window for browsing appearance group tree.
    <br/>The source bomwindow is the window consisting of a bom with appearance group's base view.
*/
    extern ME_API int ME_create_assembly_window(
        tag_t         revision_rule,         /**< (I) Revision Rule for the window */
        tag_t         source_bom_window,     /**< (I) Source BOM Window*/
        tag_t*        assembly_window        /**< (O) Tag to assembly window*/
        );
    
/**
   Creates an attachment window. 
   <br/>The source BOM Window is the window for which attachments will be viewed.
*/
    extern ME_API int ME_create_attachment_window(
        tag_t         revision_rule,         /**< (I) Revision Rule for the window */
        tag_t         source_bom_window,     /**< (I) Source BOM Window */
        tag_t*        attachment_window      /**< (O) Attachment Window */
    );

/**
    Creates root line for an attachment window or assembly window
    <br/>Assembly window expects appearance group
    <br/>Attachment window expects bomline or workspace object
    <br/>Attachment window can also take activity as input to traverse activity tree.
*/
    extern ME_API int ME_window_create_root_line(
        tag_t         window,          /**< (I) Input assembly or attachment window*/
        tag_t         root,            /**< (I) Root as defined above*/
        tag_t*        root_line        /**< (O) Tag to root MECFGLine class*/
    );

/**
    Sets the effectivity on a window
*/
    extern ME_API int ME_window_set_effectivity(
        tag_t         window,       /**< (I) Input window*/
        date_t        date,         /**< (I) Date effectivity*/
        int           unit_no,      /**< (I) Unit_no for effectivity*/
        tag_t         end_item      /**< (I) End item for which unit_no is applied*/
    );

/**
   Shows incremental changes
*/
    extern ME_API int ME_window_show_incremental_changes(
        tag_t         window    /**< (I) Input attchemnt or assembly window*/
        );
    
/**
   Hides incremental changes
*/
    extern ME_API int ME_window_hide_incremental_changes(
        tag_t         window    /**< (I) Input attchemnt or assembly window*/
        );
    
/**
   Lists all immediate children of a given line - will need to free up child_lines
*/
    extern ME_API int ME_line_ask_child_lines(
        tag_t         line,         /**< (I) MECfgLine parent line for which children are needed */
        int*          n_children,   /**< (O) Number of children*/
        tag_t**       child_lines   /**< (OF) n_children Array of children */
    );

/**
   Lists all descendant children of given line - will need to free up desc_lines.
*/
    extern ME_API int ME_line_ask_descendant_lines(
        tag_t         line,               /**< (I) MECfgLine parent line for which children are needed */
        int*          n_descendants,      /**< (O) Number of descendants */
        tag_t**       descendant_lines    /**< (OF) n_descendants Array of descendants */
    );

/**
   Checks to see if passed-in tag is a valid key for this window.
   <br/>If it is, loads it in the appropriate place in the hierarchy
*/
    extern ME_API int ME_window_place_object(
        tag_t         window,   /**< (I) Input window*/
        tag_t         key,      /**< (O) Key object*/
        tag_t*        line      /**< (O) MECfgLine for the key */
        );

/**
   Checks to see if passed-in tag is a valid key for this window.
   <br/>If it is, load it in all the appropriate places in the hierarchy
*/
    extern ME_API int ME_window_place_all_instances(
        tag_t         window,   /**< (I) Input window*/
        tag_t         key,      /**< (I) Key object*/
        int*          n_lines,  /**< (O) Number of lines found with the key*/
        tag_t**       lines     /**< (OF) n_lines Array of MECfgLines*/
    );

/**
   Loads all lines with the AbsOcc ID into an Assembly Window
*/
    extern ME_API int ME_window_place_instances_with_absoccid(
        tag_t         assembly_window,   /**< (I) Input assembly window*/
        const char*   id,                /**< (I) AbsOcc ID*/
        int*          n_lines,           /**< (O) Number of lines found*/
        tag_t**       lines              /**< (OF) n_lines Array of found MECfgLines*/
    );

/**
   Closes the assembly or attachment window
*/
    extern ME_API int ME_window_close(
        tag_t         window    /**< (I) Input assembly or attachment window*/
        );

/**
   Updates assembly window for variants - variants are applicable only to assembly window
*/
    extern ME_API int ME_window_configure_variants(
        tag_t         window   /**< (I) Input assembly window*/
        );

/**
   Updates assembly window for variants - applicable only for assembly window
*/
    extern ME_API int ME_window_show_variants(
        tag_t         window   /**< (I) Input assembly window*/
        );
    
/**
    Updates assembly window for variants - applicable only for assembly window
*/
    extern ME_API int ME_window_hide_variants(
        tag_t         window   /**< (I) Input assembly window*/
        );

/**
   Adds actitivy object to parent line with relation type relation_type with predecessor handling
*/
    extern ME_API int ME_line_add_Activity_with_predecessor(
        tag_t         line,           /**< (I) Parent Line - any MECfgLine*/
        tag_t         object,         /**< (I) Object that needs to be added*/
        const char*   relation_type,  /**< (I) Relationship type - needed only for attachments*/
        tag_t*        child           /**< (O) MECfgLine for the newly added object*/
    );

/**
   Adds object to parent line with relation type relation_type
*/
    extern ME_API int ME_line_add(
        tag_t         line,          /**< (I) Parent Line - any MECfgLine*/
        tag_t         object,        /**< (I) Object that needs to be added*/
        const char*   relation_type, /**< (I) Relationship type - needed only for attachments*/
        tag_t*        child          /**< (O) MECfgLine for the newly added object*/
        );

/**
    Removes child line from parent line
*/
    extern ME_API int ME_line_remove(
        tag_t         parent,   /**< (I) Parent Line - any MECfgLine*/
        tag_t         child     /**< (I) MECfgLine for the child that needs to be removed*/
    );

/**
   Deletes a child attachment line from a parent attachment line.
   <br/>It also deletes underlying workspace object, which the line is representing.

   <br/><b>Restrictions:</b>
   <br/>This call is valid only for children of attachment line.
*/
    extern ME_API int ME_attachment_line_delete(
        tag_t         parent,   /**< (I) Attachment line whose child needs to be deleted */
        tag_t         child     /**< (I) Attachment line which needs to be deleted */
        );
    
/**
   Makes a copy of the workspace object that the line is representing,
   and groups the changes related to a workspace object together.
   
   <br/><b>Restrictions:</b>
   <br/>Make sure you are in incremental change context.
*/
    extern ME_API int ME_attachment_line_change(
        tag_t         line,     /**< (I) Attachment line which needs to be changed */
        tag_t*        new_wso    /**< (O) Tag of the new workspace object */
        );
    
/**
   Moves child line from original parent to new parent line
*/
    extern ME_API int ME_line_reparent(
        tag_t         child,        /**< (I) MECfgLine for the child that needs to be moved */
        tag_t         new_parent    /**< (I) MECfgLine for the new parent under which child will move */
        );
    
/**
   Removes incremental changes from the child MECfgLine line
*/
    extern ME_API int ME_line_remove_incremental_changes(
        tag_t line,                   /**< (I) MECfgLine for the line with incremental change */
        int n_changes,                /**< (I) Number of changes to be removed from the input line */
        tag_t *ices                   /**< (I) n_changes Array of changes to be removed */
    );

/**
   Removes a resource line from an activity.
   
   <br/><b>Restrictions:</b>
   <br/>If the line is not a resource line in the activty nothing is done.
   <br/>The input should be a valid bomline tag
   <br/>It will return an error if this is not a valid line or if i can't remove the resource line or if i can't lock the activity.
*/
    extern ME_API int ME_activity_remove_res_line(
        tag_t         activity,      /**< (I) Tag of an activity*/
        tag_t         ressource      /**< (I) Tag of the resource bomline we like to remove*/
    );

/**
   Hides assigned items in the process window (items that are configured out in the source)
*/
    extern ME_API int ME_window_hide_assigned_occurrences(
        tag_t bop_window                 /**< (I) Tag of a BOPWindow */
        );
    
/**
   Shows assigned items in the process window (items that are configured out in the source)
*/
    extern ME_API int ME_window_show_assigned_occurrences(
        tag_t bop_window                 /**< (I) Tag of a BOPWindow*/
        );
/** @} */

/**
    @name BOP/BOS Window Related
    @{
*/
/**
    Creates BOP window for Process or Compositions
*/
    extern ME_API int ME_create_bop_window(
        tag_t*        window    /**< (O) newly created BOP window*/
        );

/**
    Adds reference window to BOPWindow - reference windows are needed for configuring items that are
    consumed or referenced in a compostion loaded in a BOP window. The reference window contains
    BOM from which components were assigned to composition or process (e.g. product is reference for
    a process loaded in a BOPWindow).
*/
    extern ME_API int ME_bop_window_add_ref_window(
        tag_t bop_window,               /**< (I) input bopwindow */
        tag_t ref_window,               /**< (I) reference window with referenced bom*/
        char *window_type               /**< (I) window type*/
    );
    
/**
   Adds an occurrence type as a controlling type to a bopwindow. The occType added here will be used by
   BOPWindow in configuring the parent operations out.

   @note The Occurrence Type should be one of the types defined in the Admin->types under occTypes. It is Caps sensitive.
   
   Usage -
   ME_bopwindow_add_control_occtype(bp_tag, "MEConsumed") -  will add MEConsumed as a
   controlling occ for this BOPWindow. Therefore operations with consumed items
   will be configured out if the consumed item is configured out from its respective
   product definition.
   
   @note There is no default controlling occ defined for a bopwindow. It is upto the
   client to decide which one should be used and it should be defined using
   following API.
   
   @note The rich client uses a preference under "controllingOccsForProcessConfiguration"
   and it should be used to be consistent with MSE behavior or CC behavior for a
   CC consisting of a process/product/plant.
   
   @note You can define more than one occTypes as controlling types or you can have a
   bop_window that may not have any controlling occurrence_type.
   
   <br/><b>Restrictions:</b>
   <br/>It will return an error if a type that is not defined in the database is used as second parameter.

   @warning Do not add same type more than once. E.g.If you add MEConsumed twice, you will need to remove it twice.
*/
    extern ME_API int ME_bopwindow_add_control_occtype(
        tag_t bop_window,                  /**< (I) Tag of a bopwindow*/
        char *occurrence_type              /**< (I) Occurrence Type*/
        );

/**
   Removes an occurrence type as a controlling type from a bopwindow.

   @note Occurrence Type as defined in the Admin->types under occTypes. It is Caps sensitive.

   Usage -
   ME_bopwindow_remove_control_occtype(bp_tag, "MEConsumed") -  will remove MEConsumed from a
   bopwindow as a controlling occ. Therefore operations with consumed items
   will not be configured out if the consumed item is configured out from its respective
   product definition.
   
   <br/><b>Restrictions:</b>
   <br/>It will return an error if a type that is not defined in the database is used as second parameter.
*/
    extern ME_API int ME_bopwindow_remove_control_occtype(
        tag_t bop_window,                  /**< (I) Teh BOP Window */
        char *occurrence_type              /**< (I) Occurrence Type*/
        );

/**
   Takes a BOMWindow tag (Product Window) and finds out the array of
   BOPWindow's tags (Process Windows), which have a reference to this BOMWindow.
*/
    extern ME_API int ME_bom_window_has_ref_bop_window(
        tag_t bom_window,                  /**< (I) The BOM Window */
        int* n_referenced_windows,         /**< (O) Number of referenced BOP Windows */
        tag_t ** referenced_bop_windows    /**< (OF) n_referenced_windows Tags of all the BOPWindows reference to the BOMWindow */  
    );

/**
   Closes BOP Window
*/
    extern ME_API int ME_close_bop_window(
        tag_t         window    /**< (I) The BOP Window */
        );
    
/**
   Creates BOS window -- not used anymore
*/
    extern ME_API int ME_create_bos_window(
        tag_t         rev_rule,     /**< (I) */
        tag_t*        window        /**< (O) */
        );

/**
    Sets source for the window - not used anymore
*/
    extern ME_API int ME_set_bos_window_source(
        tag_t         window,       /**< (I) */
        tag_t         src_line,     /**< (I) */
        tag_t*        top_line      /**< (O) */
        );

/**
   Closes the window - not used anymore
*/
    extern ME_API int ME_close_bos_window(
        tag_t         window    /**< (I) */
        );

/**
    Processes BOM balancing (persistent-mode accountability check)
*/
    extern ME_API int ME_process_balancing(
        tag_t         srcWin,           /**< (I) The source window (e.g., product or workarea) */
        tag_t*        srcLines,         /**< (I) BOM Lines from the source window, whose sub-structures balancing will be performed.
                                           If empty, then top line of the source window assumed. */
        int           num_srcLines,     /**< (I) Size of above array */
        tag_t         tarWin,           /**< (I) The target window (BOM window) to perform balancing against */
        tag_t*        tarLines,         /**< (I) Specified BOM lines from the target window, whose sub-structures balancing will be performed against.
                                           If empty, then top line of the target window assumed. */
        int           num_tarLines,     /**< (I) Size of above array */
        char*         resultName,       /**< (I) Name of the result view (occurrence group) */
        char*         resultDesc,       /**< (I) Description of the result view (occurrence group) */
        int           options,          /**< (I) Options of accountability check. Expected to be any combination of the following:
                                           add 1 - For source lines with "stop" marks, if to check their children.
                                           add 2 - If to check source lines at the lowest level only, as opposed to at all levels.
                                           add 4 - If to search all contextes in target, as opposed to the current active context.
                                           add 8 - If to search by absolute occurrence ID's only, as opposed to strictly by absolute
                                           occurrence objects.
                                           add 16 - If to compare a pre-define list of additional properties during the check.
                                           add 32 - If to compare occurrences linked via PublishLink
                                        */
        tag_t assyCtxtLineTag,          /**< (I) The possible source context line (in case the check is done when in-context mode is on)*/
        tag_t bomCtxtLineTag,           /**< (I) The possible target context line  (in case the check is done when in-context mode is on)*/
        tag_t*        resultView        /**< (O) The view (an occurrence group) containing result in its sub-groups */
        );
    
/**
   Takes a line tag and its window tag and finds out the corresponding line
   in last compare window.
*/
    extern ME_API int ME_get_source_or_target_line(
        tag_t lineTag,                  /**< (I) The line tag*/
        tag_t winTag,                   /**< (I) The window tag*/
        logical *isTarget,              /**< (O) True is the corresponding line is found*/
        tag_t *outLineTag               /**< (O) The corresponding line tag*/
        );
/** @} */

/**
   @name TCM XML Related - may have been replaced by PLMXML!!!
   @{
*/
    extern ME_API int TCMXML_export_plmxml(
        tag_t*        selectedComps,    /**< (I) */
        int           nComps,           /**< (I) */
        const char*   applicationKey,   /**< (I) */
        const char*   fileName          /**< (I) */
        );
    
    extern ME_API int TCMXML_import_plmxml(
        const char*   filePath,         /**< (I) */
        const char*   applicationType,  /**< (I) */
        tag_t         icComponent,      /**< (I) */
        tag_t*        endItem,          /**< (O) */
        int*          viewsCount,       /**< (O) */
        tag_t**       views,            /**< (O) */
        int*          errorStatus       /**< (O) */
        );
/** @} */

/**
   @name ME NX Object Related
   @{
*/
/**
   Creates a MENX object.

   <br/><b>Restrictions:</b>
   <br/>It will return an error if unable to save new MENX object
*/
    extern ME_API int ME_create_nx_object(
        const char*   name,             /**< (I) Name of MENX object */
        const char*   desc,             /**< (I) Description of MENX object */
        const char*   type,             /**< (I) Type of MENX object, such as MILL, DRILL, ... */
        const char*   subType,          /**< (I) Sub type MENX object, such as 5 Parameters, 7 Parameters, ... */
        int           n_int,            /**< (I) Count of integer parameters of MENX object */
        int*          intList,          /**< (I) An array of integer paraemters of MENX object */
        int           n_double,         /**< (I) Count of double parameters of MENX object */
        double*       doubleList,       /**< (I) An array of double parameters of MENX object */
        int           n_string,         /**< (I) Count of string parameters of MENX object */
        char**        stringList,       /**< (I) An array of string parameters of MENX object*/
        char**        intKeyList,       /**< (I) An array of strings that hold integer key values of MENX object */
        char**        doubleKeyList,    /**< (I) An array of strings that hold double key values of MENX object */
        char**        stringKeyList,    /**< (I) An array of strings that hold string key values of MENX object */
        tag_t*        newObjTag         /**< (O) Tag of the new MENX object */
        );

/**
   Reads a MENX object and return all parameters of the MENX object
   
   <br/><b>Restrictions:</b>
   <br/>It will return an error if unable to find the MENX object
*/
    extern ME_API int ME_nx_object_read_data(
        tag_t         theTag,           /**< (I) Input MENX object tag*/
        char**        resource_desc,    /**< (O) Returned a string, description of MENX object*/
        int*          numIntAtts,       /**< (O) Returned int, count of integer parameters of MENX object*/
        int**         intAtts,          /**< (OF) Returned an array of integer paraemters of MENX object */
        int*          numDoubleAtts,    /**< (O) Returned int, count of double parameters of MENX object*/
        double**      doubleAtts,       /**< (OF) Returned an array of double parameters of MENX object */
        int*          numStringAtts,    /**< (O) Returned int, count of string parameters of MENX object*/
        char***       stringAttrs,      /**< (OF) Returned an array of string parameters of MENX object */
        char***       intKeyIds,        /**< (OF) Returned an array of strings that hold integer key values of MENX object */
        char***       doubleKeyIds,     /**< (OF) Returned an array of strings that hold double key values of MENX object */
        char***       stringKeyIds      /**< (OF) Returned an array of strings that hold string key values of MENX object */
        );

/**
   Modifies the parameters a MENX object.
   
   <br/><b>Restrictions:</b>
   <br/>It will return an error if fail to find or checkout MENX object
*/
    extern ME_API int ME_nx_object_modify_data(
        tag_t         nxObjTag,         /**< (I) Input MENX object tag*/
        const char*   desc,             /**< (I) String, description of MENX object*/
        int           n_int,            /**< (I) Int, count of integer parameters of MENX object*/
        int*          intList,          /**< (I) An array of integer paraemters of MENX object*/
        int           n_double,         /**< (I) Int, count of double parameters of MENX object*/
        double*       doubleList,       /**< (I) An array of double parameters of MENX object*/
        int           n_string,         /**< (I) Int, count of string parameters of MENX object*/
        char**        stringList,       /**< (I) An array of string parameters of MENX object*/
        char**        intKeyList,       /**< (I) An array of strings that hold integer key values of MENX object*/
        char**        doubleKeyList,    /**< (I) An array of strings that hold double key values of MENX object*/
        char**        stringKeyList     /**< (I) An array of strings that hold string key values of MENX object*/
        );

/**
   Creates a MENX object type in database.

   <br/><b>Restrictions:</b>
   <br/>It will return an error if fail to create the type
*/
    extern ME_API int MENXOBJECT_type_create(
        const char*   meobj_class_name,         /**< (I) String, the class name of MENC object*/
        const char*   meobj_type_name,          /**< (I) String, the type name of MENC object*/
        const char*   def_class_name,           /**< (I) String, name of the Storage class to be associated with the type*/
        int           cardinality,              /**< (I) Number of occurrences MENX Object of this type can have*/
        int           numOfViewAllowableTypes,  /**< (I) Number of allowed view types for this type*/
        tag_t*        allowableViewTypes,       /**< (I) An array of view types tags*/
        tag_t*        meobj_type_tag            /**< (O) Returned MENX object type tag*/
        );

/**
   Deletes a MENX object type in database.

   <br/><b>Restrictions:</b>
   <br/>It will return an error if fail to delete the type
*/
    extern ME_API int MENXOBJECT_type_delete(
        tag_t         meobj_type_tag    /**< (I) Type tag of MENX object to be deleted*/
        );
/** @} */

/**
   @name IPA - InProcess Assembly Tree Related
   @{
*/
/**
   Generates an IPA tree.
   
   <br/><b>Restrictions:</b>
   <br/>It will return an error if this is not a valid window, or other internal errors during creation
*/
    extern ME_API int ME_genrateIPATree(
        tag_t bopWindow,                    /**< (I) Tag of the process structure window we want to create an IPA for*/
        char *ipaName,                      /**< (I) String of the IPA name(top occ group) */
        char *occGrpType,                   /**< (I) String, type of IPA occ. groups*/
        int count_selectedProcessTypes,     /**< (I) Int ,count of the process types that an IPA will create for them*/
        char **selectedProcessTypes,        /**< (I) An array of strings, that hold the different process types names*/
        int count_selectedConsumptionOcc,   /**< (I) Int, count of the consumption types that will be added to the occ. grp */
        char **selectedConsumptionOcc,      /**< (I) An array of stringsm that hold the different consumption types names*/
        char *attachmentName,               /**< (I) String, the name of the log file*/
        logical isLogFileNeeded,            /**< (I) Bool, if to create a statistic log file*/
        int count_ToReceivers,              /**< (I) Int ,the count of the email TO recipients*/
        char **ToReceivers,                 /**< (I) An array of strings, the addresses of the email TO recipients*/
        int count_CCReceivers,              /**< (I) Int ,the count of the email CC recipients*/
        char **CCReceivers,                 /**< (I) An array of strings, the addresses of the email CC recipients*/
        char *MailSubject,                  /**< (I) String the subject of the email*/
        char *MailMessage,                  /**< (I) String the message of the email*/
        tag_t EffectivityEndItem,           /**< (I) Tag the effectivity end item*/
        tag_t EffectivityEndRev,            /**< (I) Tag the effectivity end item revision*/
        char *EffUnitRange,                 /**< (I) String ,the effectivity unit range represented as text */
        char *EffDateRange,                 /**< (I) String  the effectivity date represented as text */
        tag_t *prdctWinAPR                  /**< (O) Returend APR tag of the top occ. grp*/
        );

/**
   Updates the IPA tree

   <br/><b>Restrictions:</b>
   <br/>It will return an error if this is not a valid window, or other internal errors during update
*/
    extern ME_API int ME_updateIPATree(
        tag_t bop_window     /**< (I) Tag of the window where the configured process structure contains the IPA tree we want to update*/
        );

/**
   Updates the IPA tree starting from a specific line

   <br/><b>Restrictions:</b>
   <br/>It will return an error if this is not a valid line, or other internal errors during update
*/
    extern ME_API int ME_localupdateIPATree(
        tag_t bop_line    /**< (I) Tag of the window where the configured process structure contains the IPA tree we want to update */
        );

/**
   Deletes the IPA tree

   <br/><b>Restrictions:</b>
   <br/>It will return an error if this is not a valid window, or other internal errors during deletion
*/
    extern ME_API int ME_cleanIPATree(
        tag_t bop_window,                     /**< (I) Tag of the window where the configured process structure contains the IPA tree we want to delete*/
        tag_t *product_window_apr             /**< (O) Returns null if there is not open BOMWindow for the consumed products.
                                                 <br/>Otherwise it return the APR of the consumed product BOMWindow*/
    );

/**
   Checks if an IPA tree exists for the BOPWindow config rule
   
   <br/><b>Restrictions:</b>
   <br/>It will return an error if this is not a valid window, or other internal errors during the IPA check
*/
    extern ME_API int ME_isIPAExists(
        tag_t bop_Window,                    /**< (I) Tag of the window where we check if configured process structure contains an IPA tree*/
        logical *is_needed                   /**< (O) The return value showing if the IPA tree exists*/
    );

/**
   Runs over each process in the vector get its IPA
   the return the search scope under it.
*/
    extern ME_API int ME_generateSearchScope(
        tag_t* processes,                    /**< (I) The processes */
        int processes_size,                  /**< (I) Processes size */
        tag_t** bom_lines,                   /**< (O) The search scope */
        int* bomlines_size                   /**< (O) Search scope size */
    );
    
/**
   Generates a sub structure of the given IPA
   with only the bomlines from the search result list
   will save in as a permanent structure under the given name
   and will be consumed under the given process
*/
    extern ME_API int ME_saveSearchResult(
        tag_t process,                      /**< (I) The process */ 
        tag_t* search_result_list,          /**< (I) Search result list */
        int search_result_size,             /**< (I) Search result size */
        char* name,                         /**< (I) The name of the name structure */
        tag_t* filtered_ipa,                /**< (O) The new structure */
        tag_t* filtered_ipa_root,           /**< (O) The collection of all filteredIPA structures */
        tag_t** rejected_list,              /**< (O) The bomline that didn't get in the new structure */
        int* rejected_list_size             /**< (O) The size of rejected_list */
        );
    
/**
   Retrieves a filtered IPA of a given process.
   <br/>It will return NULL if not found or not exist
   <br/>the filteredIPA of a process is defined as the direct parent of
   <br/>the AppGroupBOPLine child (of the process) with "MEFilteredIPA" occ type
*/
    extern ME_API int ME_getFilteredIPA(
        tag_t process_line,                 /**< (I) The process */ 
        tag_t* filter_ipa                   /**< (O) The filtered IPA */ 
        );
    
/**
   Deletes a filtered IPA structure under a given processes
*/
    extern ME_API int ME_deleteFilteredIPA(
        tag_t* process_lines,               /**< (I) The processes */ 
        int noOfLines                       /**< (I) Number of processes */ 
        );
/**
   @}
*/   
   
/**
   @name Find Checked outs in structure
@{
*/
/**
   Retrieves all the checked-out items for the given structures.
*/
    extern ME_API int ME_find_checked_outs_in_structure(
        tag_t *lines,             /**< (I) n_lines Array of tags, the search scope */
        int n_lines,              /**< (I) Size of the array */            
        int *n_items,             /**< (O) Number of the checked-out items */            
        tag_t **check_out_items   /**< (O) n_items Array of all the checked-out items */                        
        );

/*
  Checks out items for the given structures recursively
*/
    extern ME_API int ME_checkout_for_PS(
        tag_t target_line,       /**< (I) */
        logical co_process,      /**< (I) */
        logical is_recursive,    /**< (I) */
        char *change_id_char,    /**< (I) */
        char *comment_char       /**< (I) */
        );

/*
  Checks in items for the given structures recursively
*/
    extern ME_API int ME_checkin_for_PS(
        tag_t target_line       /**< (I) */
        );
/** 
@}
*/
        
        
/**
   @name Find Connected MFGs with part(bomline) in product structure
   @{
*/
/**
   Retrieves all the connected MFGs with part (BOMLine) in product structure.
*/
    extern ME_API int ME_get_connected_mfgs_from_part(
        tag_t part,                    /**< (I) Part (BOM Line) */
        int*  number_manufacturings,   /**< (O) Number of MFGs found */
        tag_t** manufacturings         /**< (OF) number_manufacturings Array of MFGs */
        );
    
/**
   Retrieves all the MFGs connected to parts in the product structure
*/
    extern ME_API int ME_get_connected_mfgs_from_parts(
        tag_t* parts,              /**< (I) Parts (BOM Lines)*/
        int number_parts,          /**< (I) Count of Parts */
        tag_t** manufacturings,    /**< (OF) number_manufacturings Array of MFGs */
        int* number_manufacturings /**< (O)  Number of MFGs connected */
        );
  
/**
    Retrieves all the corresponding BOM Lines in a search scope structure that match the source node.

@returns
<ul>
<li>#ITK_ok on success.
<li>#BOM_invalid_tag if @p source_node is invalid or #NULLTAG.
<li>#BOM_invalid_tag if @p search_scope is invalid.
<li>#BOM_invalid_tag if @p source_node is invalid.
<li>#CXPOM_invalid_tag if @p specific_scope_within_structure is invalid.
</ul>
*/
    extern ME_API int ME_find_node_in_context(
        tag_t search_scope,                          /**< (I) The context (top line) in which the @p source_node will be searched in.
                                                          <br/>If it is #NULLTAG, all others input parameters are ignored and @p source_node is retrieved.*/
        tag_t source_node,                           /**< (I) The node to search within @p search_scope.*/
        logical by_id_only,                          /**< (I) If @c true, ID in context value of @p source_node is used to find nodes in @p search_scope with matching ID in context. 
                                                          <br/>If @c false,for Bill Of Process (BOP) to Bill Of Material (BOM) the linked Appearance Path Nodes (APN) will be used.*/ 
        logical all_contexts,                        /**< (I) If @c true, @p source_node will be searched in @p search_scope.
                                                          <br/>If @c false, the search scope is restricted to look for corresponding BOMLines in @p specific_scope_within_structure.
                                                          <br/>If @p specific_scope_within_structure is #NULLTAG, the context of the top line is used. */
        tag_t specific_scope_within_structure,       /**< (I) The current scope within the top line context in which the search is to be performed.
                                                          <br/>If it is #NULLTAG, @p source_node will be searched in @p search_scope.*/
        tag_t** found_lines,                         /**< (OF) n_found_lines The found lines. */ 
        int* n_found_lines                           /**< (O) The number of found lines. */ 
        );

/**
    Finds related nodes in a given context for a given node with the relation information,
    returns all the lines found and their number.
*/
    extern ME_API int ME_find_node_in_context_by_relation(
        tag_t context,               /**< (I) The context to search in  */
        tag_t node,                  /**< (I) The node to search  */
        logical by_id_only,          /**< (I) */
        logical all_Contexts,        /**< (I) */
        tag_t in_context_line,       /**< (I) */
        const char* relation_name,   /**< (I) The relation name */
        int relation_direction,      /**< (I) The relation direction */
        int relation_Depth,          /**< (I) The relation depth */
        tag_t** found_lines,         /**< (OF) found_lines_size The lines that are found  */
        int* found_lines_size        /**< (O) The number of the lines found in the search  */
        );

/** @} */
    
/**
    Sets the BOM Line property specified by the preference "MEIdGenerationPropertySetting" with the values of the contituent properties on that BOM Line.
   <br>The specified Closure Rule must follow a pattern similar to any of the Accountability Closure Rules defined in the PLMXML admin application.
   * @returns
   *   <ul>
   *   <li>#ITK_ok on success.
   *   <li>#ME_invalid_input_data if any of the first 3 parameters are not specified as described below.
   *   <li>#MFG_invalid_closure_rule if an invalid closure_rule is specified.
   *   <li>#ME_missing_preference if an invalid preference is specified.
   *   <li>#ME_missing_types_in_preference if the preference has invalid entries.
   *   </ul>
   */
    extern ME_API int ME_set_bomline_prop_based_on(
        tag_t item_tag,           /**< (I) item representing the root of the structure. If specified will ignore scTag. If not specified scTag must be specified.  */
        tag_t revrule_tag,        /**< (I) revision rule for the structure. Must be supplied if itemTag is not NULLTAG.  */
        tag_t sc_tag,             /**< (I) The Structure Context representing the structure in which to set the bomline property.  */
        const char* closure_rule, /**< (I) optional closureRule name used to traverse the structure for selecting the lines to set properties. If null will traverse entire structure. */
        const char* scope_id_in_context,  /**< (I) optional id in context top level string used to find the scope below which expansion is done. If neither scope parameters are specified or are invalid, top line of the BOM window is used as scope. */
        const char* scope_id,     /**< (I) optional itemId to be used as scope below which expansion is done. Only used if scopeIdInContext is not specified. If neither scope parameters are specified or are invalid, top line of the BOM window is used as scope. */
        const char* preference,  /**< (I) optional preference name if "MEIdGenerationPropertySetting" is not suitable. */
        logical force_update,    /**< (I) If prior value is set for the property, override it if this flag is true. Should be specified as false if original not empty ids are to be maintained. */
        const char* dry_run_file  /**< (I) Fully qualified filename to write the bomline details on which id will be set. Can be null.  */
        );
    
/**
   Structure for Saved Query Expression for Structure Search
*/
    typedef ME_API struct ME_saved_query_expression_s{
        int     num_entries;                    /**< Number of Entries For Saved Query Filter */
        char**  entries;                        /**< Saved Query Entries to populate Saved Query Filter */
        char**  values;                         /**< Saved Query Values to populate Saved Query Filter */
        tag_t   saved_qry_tag;                  /**< Saved Query Tag used in Saved Query Filter */
    } ME_saved_query_expression_t ;
    
/** 
    Structure for Occurrence Search Expression for Structure Search
*/
    typedef ME_API struct ME_occurrence_note_expression_s{
        int num_note_type;                          /**< Number of Note Type for Occurrence Filter */
        char** note_type_str;                       /**< Note Type String for Occurrence Filter */
        char** occ_qry_opr;                         /**< Occurrence Query Operator used for Occurrence Filter.
                                                       <br/>Possible values are EQ, NE, LT, GT, LE, GE, LIKE, NOT_LIKE,
                                                       NULL, NOT NULL for equal, not equal, less than, greater than,
                                                       less than equal to, greater than equal to, like, not like,
                                                       null, not null respectively.*/
        char** occurrence_values;                   /**< Occurrence Search Values for Occurrence Filter */
    } ME_occurrence_note_expression_t;
    
/** 
    Structure for Search Expression for Structure Search. Currently only saved query expression and occurrence
    note is implemented. The structure will be enhanced in future to accommodate other general search criteria as well.
*/
    typedef ME_API struct ME_search_expression_set_s {
        int num_saved_query_expressions;                        /**< Number of Saved Query Expressions */
        ME_saved_query_expression_t* saved_query_expressions;   /**< Saved Query Expressions */
        int num_occ_note_expressions;                           /* < Number of Occurrence Note Expressions */
        ME_occurrence_note_expression_t* occ_note_expressions;  /**< Occurrence Note Expressions */
    } ME_search_expression_set_t;
    
/** 
    Structure for MFG Search criteria for Structure Search. Will be implemented in future for support of manufacturing
    features related queries as well as logical designator search.
*/
    typedef ME_API struct ME_mfg_search_criteria_s {
        tag_t dummy;                    /**< Dummy member added to struct to avoid C compile error:
                                           <br/>C2016 - C requires that a struct or union has at least one member */
    } ME_mfg_search_criteria_t;
    
/**
   Performs the structure search on the structure specified by the scope expression
   and the criteria specified by the different search expressions and provides the result BOMLines.
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#ME_invalid_input_data if scope for search is not correct.
   </ul>
*/
    extern ME_API int ME_execute_structure_search(
        int     num_scope_tags,                             /**< (I) Number of scope BOMLine tags */
        const tag_t*  scope_tags,                           /**< (I) Scope BOMLine tags */
        const ME_search_expression_set_t* search_expression,/**< (I) Search Expression containing parameters for general search */
        const ME_mfg_search_criteria_t* mfg_search_criteria,/**< (I) Manufacturing Search Criteria. Pass it as a null pointer for the moment. */
        int*   num_bom_lines,                               /**< (O) Number of result BOMLine array size */
        tag_t** bom_lines                                   /**< (OF) num_bom_lines Array of BOMLines found by the performed search*/
        );
    
/**
   Retrieves the Occurrence Group views for a given base view window.
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>Other BOM errors.
   </ul>
*/
    extern ME_API int ME_get_occurrence_group_views(
        tag_t base_view_window,   /**< (I) The base view window */
        int* n_views,              /**< (O) The number of Occurrence Group views*/
        tag_t** og_views           /**< (OF) n_views The Occurrence Group views*/
        );

/**
   Retrieves the base view for a given Occurrence Group view window.
   @returns
   <ul>
   <li> #ITK_ok on success.
   <li> Other BOM errors.
   </ul>
*/
    extern ME_API int ME_get_base_view(
        tag_t og_view,    /**< (I) The og view window */
        tag_t* base_view  /**< (O) The base view window */
        );
    
/**
   Creates a Manufacturing BOM (MBOM) from Engineering BOM(EBOM) based on user customizations for new MBOM item types.
   <br/>Relies on the user_exit functions: USER_create_or_ref_item and USER_sync_item to be implemented to support custom behavior.
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#ME_invalid_input_data if an invalid item is provided for @p ebom_root.
   <li>#CFM_invalid_name if an invalid rule is provided for @p rev_rule.
   <li>Possibly other errors
   </ul>
*/
    extern ME_API int ME_create_mbom_from_ebom(
        tag_t ebom_root,         /**< (I) Can be item/revision/StructureContext.*/
        const char* rev_rule,    /**< (I) Name of revision rule. Unused if ebomRoot is StructureContext.*/
        tag_t mbom_rev_rule,     /**< (I) Tag of revision rule or structure context (with configuration context having the revision rule) to be used for the mbom structure.*/
        int depth,               /**< (I) If supplied - create the mbom structure only upto the depth specified here. pass -1 if not used.*/
        int action_on_release,   /**< (I) Perform action. Valid values are:
                                    <ul>
                                    <li>#ME_SKIP_RELEASED_NODE if a mbom node is released and not modifiable skip it.
                                    <li>#ME_REVISE_ON_RELEASE if a mbom node is released, revise it and modify it.
                                    <li>#ME_UPDATE_PROP_ON_SELF_ON_RELEASE if a mbom node is released, update occurrence props on self only.
                                    <li>#ME_UPDATE_PROP_ON_SELF_AND_BELOW_ON_RELEASE if a mbom node is released, update properties only on self and recursively on children.
                                    </ul> */
        const char* opaque_data, /**< (I) Pass through data for any extensions registered from caller.*/
        const char* log_file,    /**< (I) Filename to write additional logs.*/
        tag_t* mbom_root         /**< (O) New MBOM root tag. */
        );
    
/**
   Updates a Manufacturing BOM (MBOM) sub-assembly/node from a Engineering BOM (EBOM) node based on user customizations for new MBOM item types.
   <br/>Relies on the user_exit functions #USER_create_or_ref_item and USER_sync_item to be implemented to support custom behavior.
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#ME_invalid_input_data if an invalid item is provided for @p ebom_root.
   <li>#CFM_invalid_name if an invalid rule is provided for @p rev_rule.
   <li>Possibly other errors
   </ul>
*/
    extern ME_API int ME_update_mbom_from_ebom(
        tag_t ebom_root,               /**< (I) Can be item/revision/StructureContext.*/
        const char* rev_rule,          /**< (I) Name of revision rule. Unused if ebomRoot is StructureContext.*/
        tag_t ebom_scope_object,       /**< (I) Item representing the ebom (sub)node to be updated or created in mbom structure.*/
        const char* ebom_idic,         /**< (I) Id in context of top level for ebom scope line. Will be used instead of ebomScopeObject are specified.*/
        tag_t mbom_root,               /**< (I) Item/revision/StructureContext representing the root of mbom structure.*/
        tag_t mbom_rev_rule,           /**< (I) Tag of revision rule for mbom structure. Unused if mbomRoot is StructureContext.*/
        int depth,                     /**< (I) How many levels to go below scopeobject to create/update.*/
        int action_on_release,         /**< (I) Perform action. Valid values are:
                                          <ul>
                                          <li>#ME_SKIP_RELEASED_NODE if a mbom node is released and not modifiable skip it.
                                          <li>#ME_REVISE_ON_RELEASE if a mbom node is released, revise it and modify it.
                                          <li>#ME_UPDATE_PROP_ON_SELF_ON_RELEASE if a mbom node is released, update occurrence props on self only.
                                          <li>#ME_UPDATE_PROP_ON_SELF_AND_BELOW_ON_RELEASE if a mbom node is released, update properties only on self and recursively on children.
                                          </ul> */
        const char* user_data,         /**< (I) Pass through data for any extensions registered from caller.*/
        const char* log_file,          /**< (I) Filename to write additional logs.*/
        tag_t* mbom_node               /**< (O) MBOM node created/updated corresponding to the EBOM scope object.*/
        );
    
/**
   Creates new lines by duplicating source objects and pasting them to the target line.
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#ME_invalid_copy_action_rules if @p copy_rule_key is invalid.
   <li>#ITK_parameter_invalid_value if @p target_line or any value in @p src_objects is not a valid tag.
   <li>Possibly other errors.
   </ul>
*/
    extern ME_API int ME_paste_duplicate_structure(
        const int num_src_objects,            /**< (I) Number of source objects to duplicate.*/
        const tag_t* src_objects,             /**< (I) The source objects to duplicate.*/
        const tag_t target_line,              /**< (I) The target line for connecting newly created lines.*/      
        const char* copy_rules_key,           /**< (I) Name of the rule to be used for copy. */
        int* num_new_child_lines,             /**< (O) Number of newly created lines under the target line.*/
        tag_t** new_child_lines               /**< (OF) num_new_child_lines Newly created lines under the target line.*/
    );
/**
Retrieves adjusted Studies and Study Structure Contexts of a Collaborative Context (CC) that contains a specific scope or one of its children. 
@returns
   <ul>
   <li>#ITK_ok on success.
   <li>#ME_invalid_input_data if @p collaboration_context or @p scope is invalid.
   </ul>
*/
extern ME_API int ME_get_studies_in_cc_by_scope(
    const tag_t collaboration_context,    /**< (I) Collaboration Context (CC) */
    const tag_t scope,                    /**< (I) The scope line in the BOP/Plant, or one of its children (not including a consumed product).
                                          <br/>It can be a Zone, Line, Process, Operation, Work Area, Resource, etc. */
    unsigned int* n_studies,              /**<(O) The number of adjusted Studies.*/ 
    tag_t** studies,                      /**<(OF) n_studies The studies that contain @p scope line or its children.*/
    tag_t** study_structure_contexts      /**<(OF) n_studies The Structure Contexts that matches to @p studies.*/
    );

/**
Retrieves the Studies and Study Structure Contexts of a Collaborative Context (CC) that are impacted by a specific object.
<br/>All studies that include the selected scope object itself or one of its parents in BOP or Plant are retrieved.
@returns
   <ul>
   <li>#ITK_ok on success.
   <li>#ME_invalid_input_data if @p collaboration_context or @p scope is invalid.
   </ul>
*/
extern ME_API int ME_get_studies_in_cc_impacted_by_scope(
    const tag_t collaboration_context,    /**< (I) Collaboration Context (CC) */
    const tag_t scope,                    /**< (I) The scope line in the BOP/Plant, or one of its parents.
                                          <br/>It can be a Zone, Line, Process, Operation, Work Area, Resource, etc. */
    unsigned int* n_studies,              /**< (O) The number of adjusted Studies.*/ 
    tag_t** studies,                      /**< (OF) n_studies The studies that contain @p scope line or its parents.*/
    tag_t** study_structure_contexts      /**< (OF) n_studies The Structure Contexts that matches to @p studies.*/
    );

/**
Retrieves all the Studies and Study Structure Contexts of a Collaborative Context (CC).
@returns
   <ul>
   <li>#ITK_ok on success.
   <li>#ME_invalid_input_data if @p collaboration_context is invalid.
   </ul>
*/
extern ME_API int ME_get_all_studies_in_cc(
    const tag_t collaboration_context,    /**< (I) Collaboration Context (CC) */
    unsigned int* n_studies,              /**< (O) The number of adjusted Studies.*/
    tag_t** studies,                      /**< (OF) n_studies The studies of @p collaboration_context*/
    tag_t** study_structure_contexts      /**< (OF) n_studies The Structure Contexts that matches to @p studies*/
    ); 


/**
Assigns a number of child BOM lines to a new parent line.

@note This function is more efficient than calling #BOM_line_assign_child_line multple times if more than one line
is to be assigned to a common parent.

The function attempts to assign as many lines as possible.  If it fails for a specific source line it will return
an error code and the associated error message in the @p ifails and @p ifail_messages arrays, at the index that
corresponds to the line's position in the @p source_lines array.  The function will then continue with assigning
the remaining source lines.

The error codes that are returned in the ifails array are #CXPOM_invalid_tag if the source line's tag is invalid or
#PS_not_found if the related entry in the @p occurrence_types parameter is invalid or the code of another runtime error.

 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if @p parent_bom_line is invalid.
    <li>#ITK_parameter_invalid_value if @p num_source_lines is invalid (< 0) or @p occurrence_types is null even though @p copy_occ_types_from_source is @c false.
    <li>Possibly other errors.
    </ul>
*/
extern ME_API int ME_assign_child_lines(
    tag_t parent_bom_line,                /**< (I) The parent BOM line that will hold the newly created BOM lines.*/ 
    int num_source_lines,                 /**< (I) Number of source lines to assign.*/ 
    const tag_t* source_lines,            /**< (I) num_source_lines The source lines to assign.*/ 
    logical copy_occ_types_from_source,   /**< (I) Set to @c true to use the same occurrence types as the source lines. Otherwise the values passed in @p occurrence_types are used. */
    const char** occurrence_types,        /**< (I) num_source_lines An optional array that holds the occurrence type for each assignment.  <br/>The array is mandatory if @p copy_occ_types_from_source is set to @c false. Otherwise, use a null pointer. */
    tag_t** new_lines,                    /**< (OF) num_source_lines Lines created under the parent line. <br/>If the assignment of a particular source line failed, the corresponding entry will hold the #NULL_TAG value.*/
    int** ifails,                         /**< (OF) num_source_lines List of error codes that indicate whether the assignment of each source line failed.  <br/>#ITK_ok at a given index indicates that the corresponding source line in @p source_lines was properly assigned. */
    char*** ifail_messages                /**< (OF) num_source_lines List of error messages that correspond to the error code returned in the @p ifails parameter. <br/>The array may contain empty strings if the error message is not defined, or if the corresponding error code is #ITK_ok. */
    );

/**
 Finds candidate design lines based on a search criterion.
 <br/>The search is carried out by in-context ID and absolute transformation. If multiple matches are found, the match will be furthered by properties as defined in the preference "MEDesignToBomFindDesignsSearchCriteriaProperties".  If the input Part lines or Design lines are not the appropiate types the search returns no matching results.

 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ME_partline_results_do_not_match if the number of Part lines mapped internally does not match @p n_part_lines.
    </ul>
*/
extern ME_API int ME_search_for_design_candidates(
    const unsigned int  n_part_lines,                /**< (I) The number of Part lines.*/
    const tag_t * part_lines,                        /**< (I) n_part_lines Part lines to search for candidate Design lines.*/
    const unsigned int n_contexts,                   /**< (I) The number of Design contexts.*/
    const tag_t * design_contexts,                   /**< (I) n_contexts The Design line contexts. If more than one is specified, their common parent is used.*/
    ME_part_design_match_t ** matching_design_lines  /**< (OF) n_part_lines The matching candidate Design lines.
                                                     <br/>The array is packed, which means that the memory is to be deallocated using #MEM_free on the container only. */  
    );

/**
Finds the future revisions that can become effective after the revision specified by the input BOMLine.  
<br/>The Revision Rule associated with the input BOMLine is used as the current configuration.  
<br/>The Revision Rule must contain at least one 'Has Status' clause and an effectivity has to be specified.
<br/>The current configuration is advanced to see if a different revision will be configured in the future.
<br/>Any future revisions configured in after the current configuration are collected and returned with the configuration information.

 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if @p current_line is invalid.
    <li>#CFM_cant_find_rev_rule if no Revision Rule associated with @p current_line.
    <li>#ME_REVRULE_INVALID_NO_HASSTATUS if the Revision Rule associated with @p current_line contains no 'Has Status' clause. 
    <li>#ME_REVRULE_INVALID_NO_EFFECTIVITY if the Revision Rule associated with @p current_line has no effectivity clause. 
    <li>#ME_REVRULE_INVALID_NO_ENDITEM if the Revision Rule associated with @p current_line has no end item clause. 
    <li>#ME_CANNOT_CREATE_TRANSIENT_REVRULE if a transient Revision Rule cannot be created. 
    </ul>
*/
extern ME_API int ME_find_future_effective_revs(
    const tag_t current_line,           /**< (I) The current line to find future effective revisions.*/
    int* n_changes,                     /**< (O) The number of changes.*/
    tag_t** configured_revisions,       /**< (OF) n_changes Future effective revisions found.*/ 
    tag_t** configuring_statuses,       /**< (OF) n_changes Status that found future effective revision.*/
    tag_t** configuring_effectivities,  /**< (OF) n_changes Effectivities that found future effective revision.*/
    date_t** effective_dates,           /**< (OF) n_changes The effective date (for data Effectivity only).*/ 
    int** effective_units,              /**< (OF) n_changes The effective unit (for unit Effectivity only).*/
    char*** how_configured              /**< (OF) n_changes The how configured string for future effective revision.
                                        <br/>The array is packed, which means that the memory is to be deallocated using #MEM_free on the container only. */
    );

/**
    Determines for each object/variant rule combination whether the objects are configured-in 
    for a specified variant rule. 

    <br/>Thereby it takes into account all aspects of an object that determine its visibility,
    such as the variant conditions of the object itself and of all its parent objects, 
    as well as the conditions of any assigned object and that of its respective parent objects. 
    <br/>The results will depend on the configuration state for IC, revision rule, effectivity,
    etc. of the implied windows, including the reference windows.
   <br/>If a provided variant rule is not matched by the variant configuration
   of any involved window, a warning message will be returned in @p warnings, in order
    to indicate that the visibility check regarding the specific variant rule cannot be reliably 
    performed because the configuration of the window contradicts the variant rule.

    <br/>This operation currently does not support modular variants. Only saved variant rules
    (business object VariantRule) for the classic variant model are accepted or,
    alternatively,  product variants (type <b>Mfg0BvrProductVariant</b>) which are linked
    to <b>VariantRule</b> objects.

@returns
  <ul>
    <li>#ITK_ok on success.
    <li>#ME_missing_variant_rule if the @p variant_rules parameter holds the tag of a product variant which is not associated with a variant rule.
    <li>#ME_internal_error if some input parameter contains an invalid value. In this case please consult the syslog for details.
  </ul>
*/
extern ME_API int ME_match_objects_against_variant_rules(
    const unsigned int n_objects,   /**< (I) Number of objects to check.*/ 
    const tag_t* objects,       /**< (I) n_objects The objects to check.*/ 
    const unsigned int n_variant_rules,      /**< (I) Number of Variant Rules.*/ 
    const tag_t* variant_rules, /**< (I) n_variant_rules Variant rules or product variants to check the objects against.*/ 
    tag_t*** visibiliy_matrix,  /**< (OF) n_objects A matrix that holds for each object passed in the objects parameter the list of matching variant rules.
                                     The returned memory consists of a packed array of tag_t arrays where each sub array is terminated by a #NULLTAG. */
    int* n_warnings,          /**< (O) Number of messages returned in the warnings vector. */
    char*** warnings            /**< (OF) n_warnings The localized warning messages that describe the inconsistencies in the configuration of the involved windows.  <br/>The warnings are associated to the symbols #ME_config_svr_mismatch, #ME_config_pv_mismatch, #ME_config_svrs_mismatch, #ME_config_pvs_mismatch and #ME_config_svrs_pvs__mismatch. Check their documentation to see the format of the warning messages.  <br/>The array is packed, which means that only the container needs to be deallocated using #MEM_free. */
    );

/**
   Finds equivalent lines based on the top level ID In Context (IDIC) and aligns the equivalent MBOM Lines to EBOM Lines, 
   when provided a ColloborationContext object encompassing an Engineering Bill of Material (BOM), Manufacturing BOM and a Bill of Process.
   @note The EBOM and MBOM roots must be linked by IMAN_METarget relation prior to calling this API.

    <br/>It optionally stamps IDIC on MBOM Lines prior to aligning with the EBOM Line. If an IDIC exists on the MBOM Line, it can be overridden if @p force_update is specified.
    <br/>@p mbom_closure_rule can be used to control which MBOM Lines are stamped with IDIC, and @p mbom_scope_item_id can be further 
    used to scope the MBOM Lines below which the stamping occurs.
    <br/>If only a single pair has to be aligned, @p ebom_line and @p mbom_line can be provided instead of @p collaboration_context.
    <br/>If @p collaboration_context is provided, caller is responsible for closing all the windows created. BOM world apis can be used before and after to find the newly created windows.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_data         if @p collaboration_context is invalid and one or both of @p ebom_line and @p mbom_line are invalid.
    <li>#MFG_invalid_closure_rule if @p mbom_closure_rule is invalid.
    <li>#BOM_invalid_data         if @p mbom_scope_item_id does not result in finding a MBOM Line.
    <li>#PF_NOTFOUND              if @p preference does not exist.    
    </ul>
*/
extern ME_API int ME_align_mbom_to_ebom(
    const tag_t collaboration_context,    /**< (I) Collaboration Context (CC) representing the ebom, mbom and optionally bop structure. */
    const tag_t ebom_line,                /**< (I) The EBOM line in case single line alignment is needed. <br/>It is ignored if @p collaboration_context is provided. */
    const tag_t mbom_line,                /**< (I) The MBOM line in case single line alignment is needed. <br/>It is ignored if @p collaboration_context is provided. */
    const logical stamp_ids,              /**< (I) Indicates to stamp IDs on MBOM lines prior to alignment. */
    const logical force_update,           /**< (I) Forces to update a pre-existing IDIC value on MBOM lines. */
    const char* mbom_closure_rule,        /**< (I) Closure rule to filter MBOM lines considered for stamping. This is only relevant if @p collaboration_context is provided. <br/>Pass @c NULL if unused.*/
    const char* mbom_scope_item_id,       /**< (I) The item ID to be used to start the MBOM traversal. This is only relevant if @p collaboration_context is provided. Pass @c NULL if unused. If invalid, topline will be used.*/
    const char* preference_name,          /**< (I) The name of the preference to override the value of the MEIDGenerationPropertySetting preference. Pass @c NULL if unused.*/
    int *n_missing,                       /**< (OF) Number of MBOM lines not found in EBOM. The syslog file will have the error details.*/
    tag_t** missing_ebom_lines,           /**< (OF) n_missing MBOM lines not found in EBOM. */
    int *n_multiple_match,                /**< (OF) Number of MBOM lines that were multiple matched in EBOM. The syslog file will have the error details.*/
    tag_t** multiple_matched_mbom_lines,  /**< (OF) n_multiple_match MBOM lines that were multiple matched in EBOM.*/
    int *n_aligned,                       /**< (OF) Number of MBOM lines that were aligned.*/
    tag_t** aligned_mbom_lines            /**< (OF) n_aligned MBOM lines that were matched to EBOM lines.*/
    );

/**
    Finds equivalent lines based on the top level ID In Context (IDIC) between the consumed lines in a Bill of Process (BOP) 
    and a Manufacturing Bill of Product (MBOM) and creates links between each pair. 

    <br/>The typical usage is that the BOP has been aligned with a full Manufacturing BOM (MBOM), and now it has to be aligned
    with a mini MBOM which has the same IDIC as the full MBOM.

    <br/>Since retrieving the aligned BOP Lines has a performance impact, the retrieval of that information can be avoided by calling the API in the following fashion:
    @code
    try
    {    
    ResultStatus rStat = ME_link_consumed_line_to_bom(    mbom_line, bop_line, false, 0, 0, false, 0, 0 );
    [...]
    }
    [...]
    @endcode

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_data if @p mbom_line or @p bop_line is invalid.
    <li>#MFG_invalid_closure_rule if @p mbom_closure_rule or @p bop_closure_rule is invalid.
    <li>Possibly other errors.
    </ul>
*/
extern ME_API int ME_link_consumed_line_to_bom(
    const tag_t mbom_line,                               /**< (I) The MBOM structure root line. */
    const tag_t bop_line,                                /**< (I) The BOP structure root line.*/
    const logical single_alignment,                      /**< (I) If true, only align the non root lines @p mbom_line and @ bop_line. If false the bom_line and bop_line are traversed. */
    const char* mbom_closure_rule,                       /**< (I) Closure rule to filter MBOM lines considered for linking.<br/>Use @c NULL if unused.*/
    const char* bop_closure_rule,                        /**< (I) Closure rule to filter BOP lines considered for linking.<br/>Use @c NULL if unused.*/
    const logical randomly_align_equal_bop_and_bom_lines,/**< (I) If the number of MBOM lines considered for linking by IDIC is more than 1 
                                                                  and matches the number of BOP lines, setting to @c true will randomly link pairs.*/
    int *n_aligned,                                      /**< (O) Number of BOP lines that were aligned.*/
    tag_t** aligned_bop_lines                            /**< (OF) n_aligned BOP lines that were aligned to the MBOM lines.*/
    );

/** 
    Structure representing application neutral identifier. 
*/
    typedef ME_API struct ME_application_ref_s{
        char* application;      /**< The application where these fields can be resolved. For example - it is Teamcenter for TC. */
        char* label;            /**< The identifier for the object. */
        char* version;          /**< The optional version string. */
    } ME_application_ref_t;

/**
Finds lines associated with input ApplicationRef objects.
<br/> The @p bom_window or @p configuring_object are used to setup the current configuration. One is required.
<br/> The @p application_refs specify the list of ApplicationRefs for which to find the associated object.
<br/> The @p revision_rule and @p variant_rule can be used in conjunction with @p configuring_object to provide RevisionRule and VariantRule configuration information.

 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CFM_cant_find_rev_rule if @p revision_rule is specified but no RevisionRule is found. 
    <li>#ME_missing_variant_rule if the @p variant_rule is specified but no VariantRule is found.
    <li>#ME_feature_failed_invalid_or_missing If @p bom_window and @p configuring_object are both not specified.
    <li>#ME_feature_failed_invalid_or_missing If @p application_refs is not specified.
    <li>#BOM_invalid_tag if @p bom_window is specified and is not a valid BOMWindow.
    <li>#BOM_invalid_tag if @p configuring_object is specified and is not a valid object as specified below.
    </ul>
*/
extern ME_API int ME_get_objects_from_application_refs(
    const tag_t bom_window,                         /**< (I) BOMWindow representing the window from which target application was launched. Must be initialized to NULL by client if unused.*/
    const tag_t revision_rule,                      /**< (I) Optional Can be used to specify the Revision Rule. Not used if @p bom_window is specified.*/
    const tag_t variant_rule,                       /**< (I) Optional Can be used to specify the Variant Rule. Not used if @p bom_window is specified.*/
    const tag_t configuring_object,                 /**< (I) The object to use for configuration. Can be one of the following:
                                                       <br/> CollaborationContext
                                                       <br/> StructureContext 
                                                       <br/> Item 
                                                       <br/> ItemRevision 
                                                       <br/> BOMView 
                                                       <br/> BOMViewRevision 
                                                       <br/> Must be initialized to NULL if unused.
                                                    */
    const int n_application_refs,                   /**< (I) The number of ApplicationRefs.*/           
    const ME_application_ref_t* application_refs,   /**< (I) n_application_refs ApplicationRefs.*/ 
    const tag_t og_bv_scope,                        /**< (I) The BOMView (BV) scope object to use for input ApplicationRefs that are OccurrenceGroup (OG) related.  
                                                       <br/>OG related lines will be searched for within this scope.
                                                       <br/>Set to #NULLTAG if this is not to be used.*/
    int* n_windows,                                 /**< (O) n_window windows.*/
    tag_t** windows,                                /**< (OF) n_windows The windows created by this operation.*/ 
    tag_t** found_objects                           /**< (OF) n_found_objects The object found for an associated ApplicationRef. If no object is found for a specific ApplicationRef NULL is returned for that entry.*/
    );

/**
 Links the roots of the structure for use with a Design Part Alignment.
 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_class if either @p design_root_line or @p part_root_line is a invalid BOM Line tag.
    <li>Possibly other errors.
    </ul>
*/
extern ME_API int ME_link_design_bom_roots(
    const tag_t design_root_line,              /**< (I) The Root design BOM Line.*/
    const tag_t part_root_line                 /**< (I) The Root part BOM Line.*/
    );

/**
 Aligns a Design line and a Part line. 
 <br/>The alignment type will be updated, if it already exists.
 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_class if either of @p design_line and @p part_line are invalid.
    <li>Possibly other errors.
    </ul>
*/
extern ME_API int ME_align_design_bom(
    const tag_t design_line,             /**< (I) The design BOMLine. It cannot be NULLTAG.*/
    const tag_t part_line,               /**< (I) The part BOMLine. It cannot be NULLTAG.*/
    unsigned int align_mode              /**< (I) Perform action. Valid values are:
                                          <ul>
                                          <li>#ME_DESIGN_BOM_REV to just align the design revision and part revision.<br/>This is the default value if an invalid value is specified.
                                          <li>#ME_DESIGN_BOM_DESIGN to instantiate the design line below the part line on align.
                                          <li>#ME_DESIGN_BOM_UNLINK to disconnect the design revision from part revision across all connected design and part lines.
                                          </ul> */
    );

/** 
    Cloning structure information. 
*/
    typedef ME_API struct ME_cloning_structs_info_s{ 
        char* name;              /**< The name of new structure to be created as a cloned structure in Alternative.
                                <br/> It cannot be blank nor NULL. */
        char* description;       /**< The description of new structure to be created as a cloned structure in Alternative.
                                <br/> If description is not to be specified, it should be initialized as "".
                                <br/> It cannot be NULL. */
        char* id;                /**< ID of new structure to be created as a cloned structure in Alternative.
                                <br/> It cannot be blank nor NULL. */
        char* revision_id;       /**< The revision ID of new structure to be created as a cloned structure in Alternative.
                                <br/> It cannot be blank nor NULL. */
        int n_scopes;            /**< Number of BOMLine objects to be cloned in Alternative. It cannot be zero*/
        tag_t* scopes;           /**< n_scopes The list of BOMLine objects to be cloned in Alternative.
                                <br/> It can be either root BOMLine or multiple BOMLine objects within the same structure.
                                <br/> It cannot have NULLTAG as a value.*/
        char* cloning_rule;      /**< The rule used for cloning. The value varies based on the structure type which is getting cloned. 
                                <br/> For example, the acceptable value for Mfg0MEPlantBOP is "ProjectPlantBOPTemplate.
                                <br/> It cannot be blank nor NULL. */
        int n_parameters;        /**< Number of additional parameters. User can choose not to send any additional parameter, in such case it should be initialised to 0. */
        char** parameter_names;  /**< n_parameters The additional parameters names. 
                                <br/> Currently supported additional parameters are:<ul>
                                <li>IsLeadPlantCreationEnabled (values @c true / @c false).
                                <li>AlternativeBeingCloned  (values @c true / @c false).
                                </ul> */
        char** parameter_values;      /**< n_parameters The values for the additional parameters. */
    } ME_cloning_structs_info_t;

/** 
    The Effectivity information for setting on a list of cloned BOMLine objects. 
*/
    typedef ME_API struct ME_rel_effectivity_info_s{ 
        tag_t end_item;            /**< Effectivity end Item. It cannot be NULL if @p unit_range is specified. */
        tag_t end_item_revision;   /**< Effectivity end ItemRevision. Cannot be NULL if unitRangeText is specified. */
        char* unit_range;          /**< Effectivity unit range, for example "5-10". Multiple range can also be provided, for example "3,5-10,20-50". This range belongs to the end .
                                  <br/> Item which is part of the structrue on which the unit effectivity is applied
                                  <br/> Valid unit ranges are:
                                  <ul>
                                  <li>"StartUnit"
                                  <li>"StartUnit-EndUnit", where @c StartUnit <= @c EndUnit.
                                  <li>"StartUnit-SO", where  @c SO (Stock Out) means that the effectivity will be applicable until the stock-out condition.
                                  <li>"StartUnit-UP", where @c UP means anything above the start unit.
                                  <li>"StartUnit1 - EndUnit1, StartUnit2 - EndUnit2" (e.g. "10 - 12, 15, 16 - UP"), where @c StartUnit2 > @c EndUnit1.
                                  </ul>
                                  <br/> - All units are positive integers
                                  <br/>
                                  <br/> For example, the effectivity can be 3 - 5 where 3 is start unit and 5 is end unit.
                                  <br/> It can also be 3 - UP where 3 is start unit and "UP" means anything above the start unit.
                                  <br/> "UP" and "SO" indicates open ended effectivity.
                                  <br/> "SO" is stock out means effectivity will be applicable till the stock out condition.
                                  <br/> If unit_range is not to be specified, it should be initialized as "". */
        int n_date_ranges;         /**< Number of Date ranges.*/
        date_t* date_ranges;       /**< n_date_ranges The list of effectivity date range.
                                  <br/> For instance, opened date range could be specified as "05 Jan - UP" and closed date range as "01 Jan - 03 Apr".
                                  <br/> The list may have any number of opened and closed date range.
                                  <br/> For example, If you select multiple dates such as start date "19th May 2015" and End date "22nd May 2015" ,
                                  <br/> start date "19th June 2015" and end date "22nd June 2015",
                                  <br/> the @p data_ranges have 4 values as below : 2015-02-19, 2015-05-22, 2015-06-19,2015-06-22.
                                  <br/> It can be NULL and @p n_date_ranges should be initialised to 0. */
        int open_ended_status;     /**< Effectivity open-ended status.
                                  <br/> Valid values are:
                                  <ul>
                                  <li>0 : for closed unit range effectivity or date effectivity.
                                  <li>1 : for opened unit range effectivity or date effectivity (UP).
                                  <li>2 : for opened unit range effectivity or date effectivity stock out (SO).
                                  </ul>
                                  For example, if you select an open-ended effectivity such as start date "19th May 2015" and end date "UP",
                                  @p date_ranges list contains 2015-05-19 with "open_ended_status" value as "1". */
    }ME_rel_effectivity_info_t;

/**
 Creates a Alternative with the given input structures that are to be cloned and/or referred to. 
 <br/>It also establishes a relation between the input MECollaborationContext (CC) object and newly created Alternative.
 <br/>Alternative is a CC object itself. The term is used for mix production.
 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ME_cloning_error_clone if in any of the input @p name is empty or @p cloning_structures, @c name, @c id, @c revision_id are empty, or @c n_scopes is 0.
    <li>#COLLABCTX_invalid_ccobject if @p cc is invalid CCObject.
    <li>Possibly other errors.
    </ul>
*/
extern ME_API int ME_create_alternative( 
    const char* name,                                      /**< (I) Name of the new Alternative.
                                                              <br/> It cannot be blank nor NULL. */
    const char* description,                               /**< (I) Description for the new Alternative.
                                                              <br/> It can be NULL.*/
    const char* release_status,                            /**< (I) The release status to be associated with the line(s) in the cloned structure, if the lines do not 
                                                                    have any release status in the original structure.
                                                              <br/> It is configurable, but in this version the only acceptable value is "PlanningSyncState".
                                                              <br/> if release_status is not to be specified, it should be initialized as "".*/
    const tag_t cc,                                        /**< (I) The MECollaborationContext from which Alternative is to be created. It cannot be NULLTAG. If NULL*/
    const unsigned int n_cloning_structures,               /**< (I) The Number of structures to be cloned.*/
    const ME_cloning_structs_info_t* cloning_Structures,   /**< (I) n_cloning_structures A list of cloning structures which contains the BOMLine objects to be cloned in the Alternative.
                                                              <br/> The structure contains additional cloning information as well.*/
    const ME_rel_effectivity_info_t* effectivity_information,/**< (I) The information required to set effectivity for a list of cloned BOMLine objects.*/
    const unsigned int n_referred_structures,              /**< (I) Number of BOMLine objects from the original CC that are going to be referred in the Alternative.*/
    const tag_t* referred_structures,                      /**< (I) n_referred_structures List List of BOMLine objects from the original CC that are going to be referred in the Alternative.*/
    tag_t* alternative                                     /**< (O) The created Alternative object.*/
    );

/**
 Finds all the alternatives created for the given input objects.
  <br/>For example, if an alternative is created for the scope of a line, it will be retrieved if the input is that line only and not for any other object.
 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ME_invalid_line_tag if in any of the input @p objects is NULLTAG.
    <li>Possibly other errors.
    </ul>
*/
extern ME_API int ME_find_alternatives(
    int n_objects,                                /**< (I) Number of objects for which to find alternatives.*/
    const tag_t* objects,                         /**< (I) n_objects Objects for which to find alternatives. */
    int* n_alternatives,                          /**< (O) Number of found alternatives. */
    tag_t** alternatives                          /**< (OF) n_alternatives Found alternatives. */
    );

/**
 Creates ID in context strings at all subassembly levels below the given design and part lines pair.
 <br/>If the subassemblies are used for independent design/ebom alignment, linkSubAssemblies must be set to true.
 @note The input design and part assembly line and their relevant children should already be aligned at a higher with respect to ID in context ( Top Level )

 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_data if either @p design_assembly_line or @p part_assembly_line is #NULLTAG.
    <li>#COLLABCTX_invalid_closure_rule if @p closure_rule_name is not NULL and is not found.
    <li>Possibly other errors.
    </ul>
*/
extern ME_API int ME_recursively_align_id_in_context_in_nested_design_contexts(     
    const tag_t design_assembly_line,                                        /**< (I) The rootline of the design structure below which the ID in context strings have to be aligned  */
    const tag_t part_assembly_line,                                          /**< (I) The rootline of the part structure below which the ID in context strings have to be aligned.*/
    const logical link_sub_assemblies,                                       /**< (I) If true, link the @p part_asssembly_line and @p design_assmembly_line. If false,  the nested assembly pairs are not linked with design/ebom relation. */
    const char* closure_rule_name                                            /**< (I) If not NULL, must be valid closure rule name to traverse the Design structure. If NULL, Defaults to "DesignToBomAll"*/
    );

/**
    Updates the Dynamic In-Process Assembly tree (DIPA).

    <br/>If the operation is invoked on top line of the process structure, it updates all the DIPA (Mfg0BvrDynamicIPA) nodes under all the sub-processes.
    <br/>If the operation is invoked on one or more specific DIPA (Mfg0BvrDynamicIPA) nodes, it updates only the DIPA (Mfg0BvrDynamicIPA) nodes provided as input.
    <br/>If the operation is invoked on one or more processes in the process structure, it updates DIPA (Mfg0BvrDynamicIPA) nodes for input processes and each of its sub-process.  

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if any member of @p source_nodes is invalid or #NULLTAG. 
    <li>#ITK_parameter_invalid_value if @p n_source_nodes is zero or less than zero.
    <li>#MFG_show_dynamic_ipa_nothing_to_clean if no Dynamic In-Process Assembly tree can be found under any member of @p source_nodes.
    </ul>

    @note The log file is generated only in case of warning during the update of some source node DIPA. Note that the API will return #ITK_ok in this event.
*/
extern ME_API int ME_update_dynamic_ipa_tree(
    const int    n_source_nodes,                             /**< (I) The count of source_nodes.*/
    const tag_t* source_nodes,                               /**< (I) n_source_nodes The root line of structure (BOP/EBOP/STUDY ) or any node (process/processstation/processline/processarea) which contains the Dynamic IPA tree. */
    char**       log_file_name,                              /**< (OF) The name of the log file. <br/>This parameter is populated only in case of warnings.*/
    char**       log_file_ticket                             /**< (OF) The file ticket of the log file.*/
    );
   
/**
    Sets the product scope on process line.
    <br/>It sets the scope selected from product structure to selected process line.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ME_process_not_in_cc if @p process_line is invalid or #NULLTAG.
    </ul>
*/
   
extern ME_API int ME_set_scopes_for_process(
    const tag_t process_line,      /**< (I) Input process line to set scope */
    const int n_scope_lines,           /**< (I) number of BOMLines of product structure to set the scope on process line.  */
    tag_t* scope_lines_from_product    /**< (I)List of BOMLines of product structure to set the scope on process line.  */
    );
    
/**
    Removes the product scope from process line.  
    <br/>It removes all the scopes from selected process line.
    
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ME_process_not_in_cc if @p process_line is invalid or NULLTAG.
    </ul>
*/
    
extern ME_API int ME_remove_scopes_for_process(
    const tag_t process_line,           /**< (I) Input process line to remove scopes from */  
    tag_t** scope_lines_from_product     /**< (OF) List of BOMLines of product structure removed from scope on process line.  */
    ); 
    
/**
    gives the product scopes from process line. 
    <br/>It gives all the product scopes set on input process line.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ME_process_not_in_cc if @p process_line is invalid or NULLTAG.
    </ul>
*/
    
extern ME_API int ME_get_product_scopes_for_process(
    const tag_t process_line,      /**< (I) Input process line to get scopes */                     
    tag_t** product_scopes         /**< (OF) List of BOMLines of product structure set as scope on process line.  */
    );

/**
    Gives the product scopes from process line.
    <br/>It gives all the product scopes set on input process line.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ME_process_not_in_cc if @p process_line is invalid.
    </ul>
*/
extern ME_API int ME_get_product_scopes_for_process2(
    const tag_t process_line,    /**< (I) Input process line to get scopes. */
    int* n_product_scopes,       /**< (OF) Number of product scopes. */
    tag_t** product_scopes       /**< (OF) List of product structure BOMLines which are set as scope on process line. */
);

/**
    Removes the input product scopes from process line.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ME_structures_not_in_cc if any of the @p product_scopes and @p process_line are not part of same Collaboration Context.
    <li>#ME_set_scope_invalid_object_type if @p process_line is invalid.
    </ul>
*/
extern ME_API int ME_remove_scopes_for_process2(
    const tag_t process_line,    /**< (I) Input process line to remove scopes from */
    const int n_product_scopes,  /**< (I) Number of product scopes. */
    tag_t* product_scopes        /**< (I) List of product structure BOMLine scopes to be removed from process line. */
);

/**
    Contains the mapping of the product scope to the list of process lines.
*/
typedef struct ME_product_scope_to_process_lines_map_s
{
    tag_t product_scope;    /**< The product scope. */
    int n_process_lines;    /**< Number of process lines. */
    tag_t* process_lines;   /**< List of process lines which are associated with product scope. */
}  ME_product_scope_to_process_lines_map_t;

/**
    Gives the product scope to process lines map.
    <br/>It gives list of process lines for each of input product scope in the context of input context process line(BOP topline).
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ME_invalid_context_process_line if @p context_process_line is invalid.
    <li>#ME_invalid_product_scope if any of the @p product_scopes is invalid.
    <li>#ME_product_scope_not_in_same_cc if any of the @p product_scopes and @p context_process_line are not part of same Collaboration Context.
    </ul>
*/
extern ME_API int ME_get_process_lines_for_product_scopes(
    const tag_t context_process_line,                                                /**< (I) The context process line(BOP topline) in which the�process lines�will be searched in for each of the input product scope. */
    const int n_product_scopes,                                                      /**< (I) Number of product scopes. */
    tag_t* product_scopes,                                                           /**< (I) List of product scopes for which process lines will be searched. */
    ME_product_scope_to_process_lines_map_t** product_scope_to_process_lines_map     /**< (OF) Output data map which contains the mapping of product scope to list of process lines. */
);
 
/**
    gives all the welds associated with given process stations.  
    <br/>It gives all assigned as well as unassigned weld for given process stations in input.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ME_product_scope_not_set if product scope is not already set.
    </ul>
*/
 
extern ME_API int ME_get_all_welds_connected_to_dipa(
    const tag_t* process_stations,        /**< (I) Input process stations to find assigned & unassigned welds */
    const int n_station,                  /**< (I) Number of input process stations */ 
    tag_t** unassigned_welds,             /**< (OF) List of welds from product scope, not assigned to input process station */
    tag_t** assigned_welds                /**< (OF) List of welds from product scope, assigned to input process station */
    );    
    
/**
 *  The validation test result returned by #ME_execute_mfg_validation_test_suites. 
 */
typedef ME_API struct ME_validation_test_result_s
{
    char * validation_test_suite_name;   /**< The name of the validation test suite */
    char * validation_test_name ;        /**< The name of the Validation Test within the Validation Test Suite that was executed or skipped. */ 
    int validation_test_result;          /**< Validation Test result : Pass=0, Fail=1 or Not Applicable=2 */ 
    int message_type;                    /**< The status message type Info=0,Warning=1 or Error=2 */ 
    char * status_message;               /**< The contents of the status message */
} ME_validation_test_result_t;

/**
    Executes the manufacturing validation test suites registered by @p client_identifier.
    <br/>If preference @c MfgValidationTestFramework_<ValidationTestSuiteTypeName>_ClosureRule exist the manufacturing validation test framework will apply the closure rule to each input object before calling the corresponding validation test suites.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ME_mfg_validation_test_framework_cannot_find_client if @p client_identifier is not found in preference MfgValidationTestFramework_Clients.
    <li>#ME_mfg_validation_test_framework_no_validation_test_types if the preference @c MfgValidationTestFramework_Client_<client_identifier>_ValidationTestTypes is empty or missing.
    <li>#ME_mfg_validation_test_framework_no_validation_tests_registered_for_type if no validation test suites are registered for the type.
    </ul>

*/
extern ME_API int ME_execute_mfg_validation_test_suites(
    const char *  client_identifier,                     /**< (I)  The client_identifier must match an entry in preference MfgValidationTestFramework_Clients. */
    const int     n_input_objects,                       /**< (I)  The number of input objects. */
    const tag_t * input_objects,                         /**< (I)  n_input_objects The input objects to pass to the manufacturing test framework. */
    const int     n_validation_test_names,               /**< (I)  The number of validation test names. */
    const char ** validation_test_names,                 /**< (I)  n_validation_test_names The validation tests to execute.  <br/>Until further notice, this argument is unused and all tests are executed.  */
    const int     n_additional_info,                     /**< (O)  The number of additional info. */
    const char ** additional_info,                       /**< (OF) n_additional_info The additional info.  <br/>Until further notice, this argument is unused.  */   
    int *         n_tested_objects,                      /**< (O)  The number of tested objects. */
    tag_t **      tested_objects,                        /**< (OF) n_tested_objects The objects that were tested. */  
    int *         n_validation_results,                  /**< (O)  The number of validation results is equal to (n_tested_objects * n_validation_test_names). */
    ME_validation_test_result_t *** validation_results   /**< (OF) Two-dimensional array for the validation test results. The first dimension is @p n_tested_objects, and the second is @p n_validation_test_names.
                                                         <br/>The array is packed, which means that the memory needs to be deallocated by calling #MEM_free on the container only. */
);

    
#ifdef __cplusplus
}
#endif

#include <me/libme_undef.h>
/** @} */
#endif

