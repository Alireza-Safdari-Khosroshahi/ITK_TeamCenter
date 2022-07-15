/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef EPM_TASK_TEMPLATE_ITK_H
#define EPM_TASK_TEMPLATE_ITK_H

#include <tccore/workspaceobject.h>
#include <epm/epm.h>
#include <epm/libepm_exports.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
    @defgroup EPM_TASK_TEMPLATE_ITK Task Template
    @ingroup EPM
    @{
*/

/**
    EPMTaskTemplate Classifications
*/
typedef enum EPM_template_classification_e{
    PROCESS_TEMPLATE,
    TASK_TEMPLATE
} EPM_template_classification_t;

/**
    EPMTaskTemplate Process Stage
*/
typedef enum EPM_template_stage_e{
    OBSOLETE_STAGE,
    UNDER_CONSTRUCTION_STAGE,
    AVAILABLE_STAGE
} EPM_template_stage_t;

/**
    This ITK will return the number and the tags of all workflow process_templates,
    with the requested stage. Stage can have the following values:

    0 = all templates regardless of stage <br>
    1 = under construction <br>
    2 = ready for use <br>
    3 = obsolete

    A stage value = 2 is what is typically used to create process instances.
*/
extern EPM_API int EPM_ask_all_process_templates(
    int            template_stage,          /**< (I) */
    int*           process_template_count,  /**< (O) */
    tag_t**        process_templates        /**< (OF) process_template_count */
    );


/**
    This ITK will pass in a given process templates name, and
    return a tag to the matching process template object of that name.
*/
extern EPM_API int EPM_find_process_template(
    const char*    process_template_name,   /**< (I) */
    tag_t*         process_template         /**< (O) */
    );

/**
    This ITK will pass in a given process templates name or origin_uid, and
    return a tag to the matching process template object of that name or origin_uid.
    If no match is found NULLTAG is returned.
*/
extern EPM_API int EPM_find_process_template_by_name_or_origin_uid(
    const char*             search_string,  /**< (I) The task template's name or origin_uid */
    EPM_template_stage_t    stage,          /**< (I) The task template's stage */
    tag_t*                  template_tag    /**< (O) */
);

/**
    This ITK will pass in the process tag as argument,
    and find the process template tag that was used to create this process.
*/
extern EPM_API int EPM_ask_process_template(
    tag_t          process,             /**< (I) */
    tag_t*         process_template     /**< (O) */
    );



extern EPM_API int EPM_create_task_template2(
    const char                          *tt_name,                               /**< (I) */
    const char                          *tt_description,                        /**< (I) */
    tag_t                               parent_task_template,                   /**< (I) */
    const EPM_template_classification_t classification,                         /**< (I) */
    const tag_t                         obj_type,                               /**< (I) */
    tag_t*                              new_task_template                       /**< (O) */
    );

extern EPM_API int EPM_create_task_template_from_template(
    const char*    tt_name,                 /**< (I) New task template name. A NULL value is allowed */
    const char*    tt_description,          /**< (I) New task template description. A NULL value is allowed
                                                Template's description will be used if it is NULL */
    tag_t          parent_task_template,    /**< (I) The parent task template */
    tag_t          base_task_template,      /**< (I) Base task template */
    tag_t*         new_task_template        /**< (O) */
    );


extern EPM_API int EPM_create_process_template2(
    const char     *pt_name,                               /**< (I) */
    const char     *pt_description,                        /**< (I) */
    tag_t*         new_process_template                    /**< (O) */
    );


extern EPM_API int EPM_create_process_template_from_template2(
    const char     *pt_name,                                /**< (I) */
    const char     *pt_description,                         /**< (I) */
    tag_t          base_pt_tag,                             /**< (I) */
    tag_t*         new_process_template                     /**< (O) */
    );

extern EPM_API int EPM_delete_task_template(
    tag_t          task_template    /**< (I) */
    );

extern EPM_API int EPM_remove_task_template(
    tag_t          task_template    /**< (I) */
    );

extern EPM_API int EPM_ask_action_handlers(
    tag_t          task_template,               /**< (I) */
    EPM_action_t   action,                      /**< (I) */
    int*           no_of_action_handlers,       /**< (O) */
    tag_t**        action_handler_definitions   /**< (OF) no_of_action_handlers */
    );

extern EPM_API int EPM_add_action_handler(
    tag_t               task_template,      /**< (I) */
    const EPM_action_t  action,             /**< (I) */
    tag_t               action_handler      /**< (I) */
    );

extern EPM_API int EPM_add_rule(
    tag_t               task_template,      /**< (I) */
    const EPM_action_t  action,             /**< (I) */
    tag_t               rule                /**< (I) */
    );

extern EPM_API int EPM_remove_rule_handler(
    tag_t          task_template,       /**< (I) */
    tag_t          rule_definition,     /**< (I) */
    tag_t          rule_handler,        /**< (I) */
    logical        delete_handler       /**< (I) */
    );

extern EPM_API int EPM_remove_action_handler(
    tag_t          task_template,       /**< (I) */
    int            action,              /**< (I) */
    tag_t          action_handler,      /**< (I) */
    logical        delete_handler       /**< (I) */
    );

extern EPM_API int EPM_remove_rule(
    tag_t          task_template,       /**< (I) */
    tag_t          rule_definition      /**< (I) */
    );


/**
   Retrieves the handler named in the definition of the task.
   <br/>If a null action is provided, the first handler that matches the name is retrieved.
 */
extern EPM_API int EPM_find_handler2(
    tag_t               task_template,                      /**< (I) */
    EPM_handler_type_t  handler_type,                       /**< (I) Action / Rule */
    EPM_action_t        action,                             /**< (I) */
    const char          *handler_name,                      /**< (I) */
    tag_t*              handler                             /**< (O) */
    );

extern EPM_API int EPM_add_subtask_template(
    tag_t          parent_task_template,    /**< (I) */
    tag_t          task_template            /**< (I) */
    );

extern EPM_API int EPM_copy_task_template(
    tag_t          task_template,       /**< (I) */
    tag_t*         task_template_copy   /**< (O) */
    );

extern EPM_API int EPM_modify_task_template(
    tag_t          task_template,       /**< (I) */
    logical        visibility,          /**< (I) */
    tag_t*         task_template_copy   /**< (O) */
    );

extern EPM_API int EPM_modify_task_template2(
          tag_t   task_template,       /**< (I) */
          int modifyFlagsCount,        /**< (I) */
          const logical *modifyFlags,  /**< (I) */
          tag_t   *task_template_copy  /**< (O) */
        );

/**
    Creates an action handler associated with the given task template's action.
*/
extern EPM_API int EPM_create_action_handler2(
    tag_t          task_template,                               /**< (I) */
    EPM_action_t   action,                                      /**< (I) */
    const char     *action_handler_name,                        /**< (I) */
    int            action_handler_argument_count,               /**< (I) */
    const char**   action_handler_arguments,                    /**< (I) */
    tag_t*         action_handler                               /**< (O) */
    );

/**
    Removes and destroys the given handler
*/
extern EPM_API int EPM_delete_handler(
    tag_t          handler_definition   /**< (I) */
    );

/**
    Cuts the given handler from the action
*/
extern EPM_API int EPM_cut_handler(
    tag_t          handler_definition   /**< (I) */
    );


/**
   Creates a rule handler definition that is to be associated with an existing
   rule definition and is therefore not the only rule handler definition
   associated with this rule definition. 
   <br/>If the rule handler definition to be created is to act independently from
   any other rule handler, use #EPM_create_rule2 instead.
 */
extern EPM_API int EPM_create_rule_handler2(
    tag_t          rule,                                    /**< (I) */
    int            rule_quorum,                             /**< (I) */
    const char     *rule_handler_name,                      /**< (I) */
    int            rule_handler_argument_count,             /**< (I) */
    const char**   rule_handler_arguments,                  /**< (I) */
    logical        negated_flag,                            /**< (I) */
    logical        override_flag,                           /**< (I) */
    tag_t*         rule_handler                             /**< (O) */
    );

extern EPM_API int EPM_set_rule_quorum(
    tag_t          rule,    /**< (I) */
    int            quorum   /**< (I) */
    );


/*----------------------------------------------------------------------------*/
/**
   Creates a rule definition for the given task definition's action. A rule
   handler definition cannot be directly associated with a task's action,
   instead it is associated via a rule definition that in turn is associated
   with a task's action. A rule definition without at least one rule handler
   definition being associated does not make sense and is not allowed.
   <br/>Therefore details of the first rule handler to be created and associated
   with the rule are also required with this call, making it a convenient
   single call that handles the majority of use cases. In some cases more than
   one handler may be associated with a rule. In such a case addition handlers
   can be added to the rule using the #EPM_create_rule_handler2
   or #EPM_add_rule_handler APIs.
 */
extern EPM_API int EPM_create_rule2(
    tag_t               task_template,                          /**< (I) */
    const EPM_action_t  action,                                 /**< (I) */
    const char          *rule_handler_name,                     /**< (I) */
    int                 rule_handler_argument_count,            /**< (I) */
    const char**        rule_handler_arguments,                 /**< (I) */
    tag_t*              rule_handler,                           /**< (O) */
    tag_t*              rule                                    /**< (O) */
    );

extern EPM_API int EPM_ask_rule_handlers(
    tag_t          rule,            /**< (I) */
    int*           count,           /**< (O) */
    tag_t**        rule_handlers    /**< (OF) count */
    );

extern EPM_API int EPM_add_rule_handler(
    tag_t          rule,            /**< (I) */
    tag_t          rule_handler     /**< (I) */
    );

extern EPM_API int EPM_ask_rules(
    tag_t          task_template,   /**< (I) */
    EPM_action_t   action,          /**< (I) */
    int*           no_of_rules,     /**< (O) */
    tag_t**        rules            /**< (OF) no_of_rules */
    );

/**
   Finds an existing named process template and provides a tag to the
   process's task template. If process is not found the output parameter
   will be set to NULLTAG and function returns ITK_ok.
   <br/>@p pt_name should be the master value and not a localized value.
*/
extern EPM_API int EPM_find_template2(
    const char     *pt_name,                        /**< (I) */
    int            template_type,                   /**< (I) */
    tag_t*         process_task_template            /**< (O) */
    );

extern EPM_API int EPM_extent_template(
    int            stage,                   /**< (I)  #AVAILABLE_STAGE, #UNDER_CONSTRUCTION_STAGE, #OBSOLETE_STAGE */
    int            classification,          /**< (I)  #PROCESS_TEMPLATE or #TASK_TEMPLATE */
    int*           num,                     /**< (O)  Number of templates */
    tag_t**        process_task_templates   /**< (OF) num Template tags */
    );

extern EPM_API int EPM_extent_template_and_stage(
    int            classification,          /**< (I)  #PROCESS_TEMPLATE or #TASK_TEMPLATE */
    int*           num,                     /**< (O)  Number of templates */
    int**          task_template_stages,    /**< (OF) num Template stages */
    tag_t**        task_templates           /**< (OF) num Template tags */
    );


extern EPM_API int EPM_extent_locked_templates(
    int*           componentCount,  /**< (O) */
    tag_t**        componentTags    /**< (OF) componentCount */
    );

extern EPM_API int EPM_extent_modifiable_templates(
    int*           componentCount,  /**< (O) */
    tag_t**        componentTags    /**< (OF) componentCount */
    );

extern EPM_API int EPM_extent_handler_names_registered(
    const EPM_handler_type_t    handler_type,       /**< (I) Action / Rule */
    int*                        no_of_handlers,     /**< (O) */
    char***                     handler_names       /**< (OF) no_of_handlers */
    );

/**
    Provides a list of tags to the subtask templates for any task template.
*/
extern EPM_API int EPM_ask_subtask_templates(
    tag_t          parent_task_template,        /**< (I) */
    int*           no_of_subtask_templates,     /**< (O) */
    tag_t**        subtask_templates            /**< (OF) no_of_subtask_templates */
    );

/**
    Unlocks the modified and newly created process templates
*/
extern EPM_API int EPM_unlock_modified_templates(
    int            no_of_process_templates,     /**< (I) */
    tag_t*         process_templates            /**< (I) */
    );

/**
    Provides lists of the Signoff profiles
*/
extern EPM_API int EPM_ask_signoff_profiles(
    tag_t          task_template,           /**< (I) */
    int*           quorum,                  /**< (O) */
    int*           num_signoff_profiles,    /**< (O) */
    tag_t**        roles,                   /**< (OF) num_signoff_profiles */
    tag_t**        groups,                  /**< (OF) num_signoff_profiles */
    logical**      allow_sub_groups,        /**< (OF) num_signoff_profiles */
    int**          num_reviewers            /**< (OF) num_signoff_profiles */
    );

/**
    Creates a list of the Signoff profiles associated to a task template
*/
extern EPM_API int EPM_create_signoff_profiles(
    tag_t          task_template,           /**< (I) */
    int            quorum,                  /**< (I) */
    int            num_signoff_profiles,    /**< (I) */
    const tag_t*   roles,                   /**< (I) no_of_review_entries */
    const tag_t*   groups,                  /**< (I) no_of_review_entries */
    const logical* allow_sub_groups,        /**< (I) no_of_review_entries */
    const int*     num_reviewers,           /**< (I) no_of_review_entries */
    tag_t**        signoff_profiles         /**< (OF) */
    );

/**
    Provides an array of strings, where each string represents a single argument.
*/
extern EPM_API int EPM_ask_handler_arguments(
    tag_t          handler,         /**< (I) */
    int*           argument_count,  /**< (O) */
    char***        arguments        /**< (OF) argument_count */
    );

/**
    Sets the argument list for the handler.
*/
extern EPM_API int EPM_set_handler_arguments(
    tag_t          handler,         /**< (I) */
    int            argument_count,  /**< (I) */
    const char**   arguments        /**< (I) argument_count */
    );

/**
    Copies the given handler. The copy will not be associated with a
    rule object if its a rule handler or will not be associated with a task
    template's action if its an action handler.
*/
extern EPM_API int EPM_copy_handler(
    tag_t          handler,         /**< (I) */
    tag_t*         handler_copy     /**< (O) */
    );

/**
    Based on the action type and the input task template,
    this ITK returns a list of task template tags that the input task template is dependent on.

    If action = 'Start', then these are the tasks that must complete before the input task can start. <br>
    If action = 'Complete', then these are the tasks that should complete before the current task can complete.
 */
extern EPM_API int EPM_ask_predecessor_task_templates(
    tag_t          task_template,               /**< (I) */
    int            action,                      /**< (I) */
    int*           no_of_predecessors,          /**< (O) */
    tag_t**        predecessor_task_templates   /**< (OF) no_of_predecessors */
    );

/**
    Removes the dependencies for the input task template
*/
extern EPM_API int EPM_remove_predecessor_task_templates(
    tag_t          task_template,               /**< (I) */
    int            no_of_predecessors,          /**< (I) */
    const tag_t*   predecessor_task_templates,  /**< (I) no_of_predecessors */
    int            action                       /**< (I) */
    );

/**
    Adds dependencies for the input task template
*/
extern EPM_API int EPM_add_predecessor_task_templates(
    tag_t          task_template,               /**< (I) */
    int            no_of_predecessors,          /**< (I) */
    const tag_t*   predecessor_task_templates,  /**< (I) no_of_predecessors */
    int            action                       /**< (I) */
    );

extern EPM_API int EPM_task_template_ask_active_processes(
    tag_t          process_template,           /**< (I) */
    int*           process_count,              /**< (O) */
    tag_t**        process_list                /**< (OF)*/
    );

extern EPM_API int EPM_apply_template_to_active_process(
    tag_t process_template,                     /**< (I) */
    tag_t process                               /**< (I) */
    );

extern EPM_API int EPM_apply_template_to_active_processes(
    tag_t process_template,                     /**< (I) */
    int   processing_mode                       /**< (I) 0 - Indicates synchronous processing. 1 - Indicates asynchronous processing. */
    );

extern EPM_API int EPM_find_process_template_origin_uid(
    const char*    origin_uid,                  /**< (I) */
    int            stage,                       /**< (I)  #AVAILABLE_STAGE, #UNDER_CONSTRUCTION_STAGE, #OBSOLETE_STAGE */
    tag_t*         process_task_template        /**< (O) */
    );

/**
    Finds an existing named process template and provides a tag to the template.
    If the parameter @p template_name is empty, the template name to be used will be determined by the
    preference defined for the object tag ( &lt;TypeName&gt;_default_workflow_template ).
    If the parameter @p template_name is provided, the parameter @p object_tag is ignored and the process template matching the parameter @p template_name is searched.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#PF_NOTFOUND if the preference &lt;TypeName&gt;_default_workflow_template is not found
    <li>#EPM_template_not_found if the process template is not found
    </ul>
 */
extern EPM_API int EPM_find_process_template_by_name_or_object_type(
    const char*    template_name,       /**< (I) Template name */
    tag_t          object_tag,          /**< (I) Target object tag.
                                                 <br>If the template_name is not provided, the template name to be used
                                                 will be determined by the preference defined by the type of the input object
                                                 (preference &lt;TypeName&gt;_default_workflow_template).*/
    tag_t*         template_tag         /**< (O) Workflow template tag */
    );

/* This API returns a list of process templates based on given criteria.
 * based on current User Group and TargetObjects/ Object Types.
 * If there are multiple target objects/ object types, only the common assigned templates will
 * be returned.
 * If no targets/object types specified, it will return all the templates
 * assigned to the current user Group.
 * Underconstruction Templates are part of result only for users who are part of
 * DBA Group when include_under_construction = true.
 *
 * From Teamcenter 11.2 the template filter based on User Group and Object Types is used as a legacy template filter.
 * A new condition based template filter is introduced.
 * The preference WRKFLW_use_legacy_template_filter decides which template filter to use.
 * The new assigned template filter works on the target object input and filter condition associated with the respective template.
 * So the inputs object types and group will be invalid if you use the new filter.
 *
 * Arguments:
 *  include_under_construction (I) --- true = Under Construction + Available, false = Available Only
 *  assigned_templates (I) --- true = Assigned Templates, false = All Templates
 *  number_of_objects (I) --- The number of Target objects/ Object Types.
 *  target_objects (I) --- The Target Objects, for which types the assigned templates are returned, should be null if using object_types argument.
 *  object_types (I) --- The Object Types, for which types the assigned templates are returned, should be null if using target_objects argument.
 *  group (I) --- Group for which assigned templates are returned, should be null if you want to get results for session’s logged in group.
 *  count (O) --- The number of templates returned.
 *  process_templates (OF) --- The list of the templates.
 *
 * Similar to EPM_ask_workflow_templates, except that it does not check for User Exit implementation.
 */
extern EPM_API int EPM_ask_workflow_templates_base(
    logical        include_under_construction,  /**< (I) Show Under Construction Templates */
    logical        assigned_templates,          /**< (I) Show Assigned Templates */
    int            number_of_objects,           /**< (I) Number of object types or target objects */
    tag_t*        target_objects,               /**< (I) target objects */
    char**        object_types,                 /**< (I) object types */
    const char*        group,                   /**< (I) group */
    int*        count,                          /**< (O) output count */
    tag_t**     process_templates               /**< (OF) count output Templates */
);

/**
    This API returns a list of process templates based on given criteria.
  based on current User Group and TargetObjects/ Object Types.
  If there are multiple target objects/ object types, only the common assigned templates will
  be returned.
  If no targets/object types specified, it will return all the templates
  assigned to the current user Group.
  Underconstruction Templates are part of result only for users who are part of
  DBA Group when include_under_construction = true.

  From Teamcenter 11.2 the template filter based on User Group and Object Types is used as a legacy template filter.
  A new condition based template filter is introduced.
  The preference WRKFLW_use_legacy_template_filter decides which template filter to use.
  The new assigned template filter works on the target object input and filter condition associated with the respective template.
  So the inputs object types and group will be invalid if you use the new filter.
 
  Arguments:
   include_under_construction (I) --- true = Under Construction + Available, false = Available Only
   assigned_templates (I) --- true = Assigned Templates, false = All Templates
   number_of_objects (I) --- The number of Target objects/ Object Types.
   target_objects (I) --- The Target Objects, for which types the assigned templates are returned, should be null if using object_types argument.
   object_types (I) --- The Object Types, for which types the assigned templates are returned, should be null if using target_objects argument.
   group (I) --- Group for which assigned templates are returned, should be null if you want to get results for session’s logged in group.
   count (O) --- The number of templates returned.
   process_templates (OF) --- The list of the templates.

  This API results based on, Custom Template Filter implemented through User Exits
         if User Exit implemented - Calls only the user exit and skips the default functionality
         if User Exit not implemented - Calls the default functionality.
     Use EPM_ask_process_templates_base to get direct results from default behaviour only.
*/
extern EPM_API int EPM_ask_workflow_templates(
    logical        include_under_construction,    /**< (I) Show Under Construction Templates */
    logical        assigned_templates,            /**< (I) Show Assigned Templates */
    int            number_of_objects,             /**< (I) Number of object types or target objects */
    tag_t*        target_objects,                 /**< (I) target objects */
    char**        object_types,                   /**< (I) object types */
    const char*        group,                     /**< (I) group */
    int*        count,                            /**< (O) output count */
    tag_t**     process_templates                 /**< (OF) count output Templates */
    );

/**
    Provides a list of tags to all the sub task templates for any task template.
*/
extern EPM_API int EPM_ask_all_subtask_templates(
    tag_t          task_template,                  /**< (I) task to find its subtasks */
    int*           no_of_allsubtask_templates,     /**< (O) Total number of subtasks. */
    tag_t**        allsubtask_templates            /**< (OF) no_of_allsubtask_templates number of subtasks. */
    );

#ifdef __cplusplus
}
#endif

/** @} */

#include <epm/libepm_undef.h>
#endif
