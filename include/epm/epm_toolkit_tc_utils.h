/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Contains utility functions for the EPM and CR action handlers
    which are exported from libtc on NT.
*/

/*  */

#ifndef EPM_TOOLKIT_TC_UTILS_H
#define EPM_TOOLKIT_TC_UTILS_H

#include <user_exits/epm_toolkit_utils.h>
#include <epm/libepm_exports.h>

/**
    @defgroup EPM_TOOLKIT_TC_UTILS Toolkit
    @ingroup EPM
    @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
    Sets up the parser for EPM handler arguments.
    <br> It currently uses the parser from Generic shell.
    <br>The function is to be used in order to populate a name/value pair map in a static variable which 
    is then later used for keyword substitution when the function #EPM_substitute_keyword is called.
    <br>If writing a handler which argument values can contain keywords such as
    TARGET, REFERENCE, SIGNOFF, RELEASE_STATUS, ROOTTASK, 
    the call to #EPM_setup_parser must be followed by a call to #EPM_substitute_keyword.

    @code
        extern int EPM_create_form( EPM_action_message_t msg )
        {
            number_of_args = TC_number_of_arguments(msg.arguments);
            rcode = EPM_ask_job( msg.task, &job_tag );

            if ( rcode == ITK_ok )
            {
                rcode = EPM_setup_parser( msg.task );
            }
            for ( i=0; i < number_of_args && rcode == ITK_ok; i++ )
            {
                rcode = ITK_ask_argument_named_value( TC_next_argument( msg.arguments ),
                                              &flag, &value
                                              );
                if ( rcode == ITK_ok )
                {
                    rcode = EPM_substitute_keyword( value, &normal_value );
                }
                if ( rcode == ITK_ok )
                { 
                    if ( strcmp("type", flag ) == 0 )
                    {  
                        strcpy( form_type, normal_value );
                    }
                    else if ( strcmp( "name", flag ) == 0 )
                    {
                        strcpy( form_name, normal_value );
                    }
                    else
                    {
                        rcode = ITK_invalid_flag;
                    }
                }
            }
            return rcode;
        }
    @endcode

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#ITK_internal_error if Handler keyword ROOTTASK has been changed to ROOT or if addition of keyward is not OK
    <li>#ITK_internal_error if initiation of parsing fails
    </ul> 
*/
extern EPM_API int EPM_setup_parser(
    tag_t          task           /**< (I) The Task tag */ 
    );

/**
    Substitutes the keywords for value and return the
    resulting string in normal_val.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_substitute_keyword(
    const char*    value,            /**< (I) The command line argument named value. */
    char**         normal_val        /**< (OF) The substituted keywords for value. */
    );

/**
    Substitutes keywords from objects accessible from the task. The keywords are.
    $PROCESSOWNER               - Teamcenter::UserImpl ID of job owner 
    $PROCESSGROUP               - Teamcenter::GroupImpl ID of job owner 

    $TARGETOWNER                - Teamcenter::UserImpl ID of owner of first target 
    $TARGETGROUP                - Teamcenter::GroupImpl ID of owner of first target 

    $TARGETOWNER[(Class)|Type]  - Teamcenter::UserImpl ID of owner of first target of 
                                  class Class or type Type.
    $TARGETGROUP[(Class)|Type]  - Teamcenter::GroupImpl ID of owner of first target of 
                                  class Class or type Type.

    The fields are processed as if they could all exist in the argument string.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_substitute_task_keyword(
    tag_t          task,         /**< (I) The task tag. */
    const char*    value,        /**< (I) The command line argument named value. */
    char**         normal_val    /**< (OF) The substituted keywords for value. */
    );

/**
    Breaks down an IMAN argument list structure into 2 string arrays containing
    the argument names and values.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_args_process_args(
    tag_t                 task,         /**< (I) Arg structure from handler */
    TC_argument_list_t*   args,         /**< (I) Number of arguments */
    int*                  arg_count,    /**< (O) Number of arguments */
    char***               arg_names,    /**< (OF) arg_count Array of argument names */
    char***               arg_values    /**< (OF) arg_count Array of argument values */
    );

/**
    Adds all the user names of reviewers of this task to the address list.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_add_undecided_reviewers_as_recipients(
    tag_t           task,       /**< (I) The task tag. */
    counted_list_t* recipient   /**< (OF) The list of recipients. */
    );

/**
    Adds the user_name to the recipient list.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_add_to_list(
    counted_list_t* arg,              /**< (I) The list of recipients. */
    char*           user_name         /**< (I) User name to be added to the list of recipients. */
    );


/**
    Get the email address for TC user.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_get_user_email_addr(
    tag_t          user_tag,        /**< (I) The user tag. */
    char**         user_email       /**< (OF) Email of an user. */
    );

/**
    Get person's email address from person tag.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_get_person_email_addr(
    const char *   person_name,     /**< (I) The person name.  */
    char**         user_email       /**< (OF) The person email. */
    );

/** @if DOX_IGNORE
    Lee 25July03, changed name from EPM__get_resource_pool to EPM_parse_resource_pool

    @returns #ITK_ok or error code.
@endif */
extern EPM_API int EPM_parse_resource_pool(
    const char*    buf,           /**< (I) The argument which can in the following format:
                                     <ol><li>GroupName::RoleName</li><li>RoleName</li><li>GroupName::</li></ol> */
    tag_t*         rp             /**< (O) The ResourcePool object tag. */
    );


/**
    Parses the input arguments for group, role and allow-subgroups flag.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_parse_reviewer_type(
    char*          argument,            /**< (I) Input argument to be parsed. */
    char**         groupName,           /**< (OF) The group name  */
    logical*       allowSubGroups,      /**< (O) The flag indicates that subgrouping is allowed or not. */
    char**         roleName             /**< (OF) The role name. */
    );

/**
    Creates workspace object for the following inputs.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_create_wsobject (
  const char* wso_type,          /**< (I) The WorkSpace Object type. */
  const char* name,              /**< (I) Name of the object. */
  char*       owner,             /**< (I) Owner name. */
  char*       description,       /**< (I) Description. */
  char*       container_uid,     /**< (I) Uid of the container. */
  char*       relation_name,     /**< (I) The relation. */
  int         attribute_count,   /**< (I) The count of attributes. */
  char**      attribute_names,   /**< (I) Attribute's names. */
  char**      attribute_types,   /**< (I) Attribute's types. */
  char**      attribute_values,  /**< (I) Attribute's values. */
  tag_t*      new_wso            /**< (I) Tag of new workspace object.*/
  );

/**
    Creates a container relation of a workspace object 

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_create_container_relation(
    tag_t       wso,                        /**< (I) The workspace object. */
    tag_t       container,                  /**< (I) The container. */
    char*       relation_name,              /**< (I) The relation name. */
    tag_t       wso_owner,                  /**< (I) The WorkSpace Object owner tag. */
    logical     addto_owner_newstuff        /**< (I) Flag to indicate that object to add in newstuff folder. */
  );

/**
    Finds the users_tags that reference the person and
    set the user_tag to the first one found. Note that there could be multiple
    users referencing the person but only the first one will be returned.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_find_user_from_person( 
    const char *person,  /**< (I) The person name. */ 
    tag_t *user_tag      /**< (O) The user tag. */
    );

/**
    Retrieves the users using group members

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_get_users_for_group_members( 
    int   gm_count,       /**< (I) The count of group members. */
    tag_t *gm_tags,       /**< (I) The group member tags. */
    int   *users_count,   /**< (O) The count of users retrieved from group members. */ 
    tag_t ** list_users   /**< (OF) users_count The list of user tags. */
    );

/**
    Updates the last modified date of the instance argument provided.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM__update_last_modified_date( 
    tag_t instance,                 /**< (I) The tag of an object of which last modified date is to be changed. */ 
    date_t *modification_date       /**< (I) The modification date of an object.*/
  );

/**
    Retrieves the secondary objects for BVR object.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_get_bvr_attachments( 
    tag_t bvr_tag,                        /**< (I) The tag of BVR object */ 
    tag_t relation_type,                  /**< (I) The relation type. */
    int* sec_count,                       /**< (O) The returned count of secondary objects. */
    tag_t** sec_objs                      /**< (OF) sec_count Tags of all returned secondary objects. */
  );

/**
    Retrieves the default group member for the user 

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_get_default_group_member_for_user( tag_t  user_tag ,   /**< (I) The user tag. */
                                                          tag_t* group_member /**< (O) The tag of group member. */
                                                        );

/**
    Takes an alias list name, the alias list may contain 
    AliasList names, TC user names, OS user names and Email IDs.
    <br/>This function will create a list of group members given an alias list.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_process_aliaslist_get_members( 
    tag_t alist,                   /**< (I) Alias list name. */
    counted_tag_list_t * gm_list,  /**< (OF) List of group members. */
    counted_tag_list_t * rp_list   /**< (OF) List of resource pool tags. */
    );

/**
    Retrieves the first valid target for the given task and participant type.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_get_first_valid_target (
    tag_t task,                            /**< (I) The task tag. */ 
    tag_t participantType,                 /**< (I) The tag of participant type. */ 
    tag_t* target                          /**< (O) Tag of first valid target. */
    
);

/**
    Parses the input argument which can be in the
    following format:
    <ol>
    <li>GroupName::RoleName</li>
    <li>RoleName</li>
    <li>GroupName::.</li>
    </ol>

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_parse_reviewers(
    const char *argument,       /**< (I) The argument which can be in the above formats specified. */
    char ** group_name,         /**< (OF) The group name. */
    logical * allow_subgroups,  /**< (O) The flag indicates that subgrouping is allowed or not. */
    char ** role_name,          /**< (OF) The role name. */
    logical * all_members       /**< (O) The flag for allMembers. */
    );
    
/**
    Retrieves the current job associated with given object.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_get_current_job(
    tag_t  object,     /**< (I) The object tag. */
    tag_t* job,        /**< (O) The current job tag. */
    tag_t* job_type    /**< (O) The current job type tag. */
    );

/**
    Retrieves the Project Team associated with a group member.
    <br/>If the group member is not part of any Project Team, 
    the returned Project Team tag will be a NULLTAG.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_ask_groupmember_projectteam ( 
    tag_t group_member,           /**< (I) Group Member tag. */
    tag_t * the_project_team      /**< (O) The Project Team tag.*/
    );

/**
    Retrieves the User for all group member objects and 
    tries to match it with the parameter @p user. If a match is found that group member tag will
    be stored in parameter @p list_tags

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_get_groupmembers_from_projectteam ( 
    tag_t   user ,                 /**< (I) The user tag.*/
    tag_t   project_team ,         /**< (I) The ProjectTeam tag. */
    int *   list_count,            /**< (O) The count of all groupmembers which are matched with the given user tag. */
    tag_t** list_tags              /**< (OF) list_count The list of tags of all group members. */ 
    );

/**
    Gives the difference between given 2 dates in minutes

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_get_differenceInDates(
    date_t first_date,               /**< (I) Start date of the task.  */
    date_t second_date,              /**< (I) End date of the task. */
    int *difference_in_minutes       /**< (O) Date difference in minutes*/
    );

/**
    Checks for errors and warnings on the error stack.
    This function returns true if there are errors or warnings on error stack otherwise returns false.
*/
extern EPM_API logical EPM_entriesOnErrorStack();


/**
    Creates a mailing list using user tags from counted_tag_list_t

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_get_mailing_list(
    int                n_users,            /**< (I) Number of users. */
    tag_t              *tag_list,          /**< (I) The list of user tags. */
    counted_list_t     *recipients         /**< (OF) The list of recipients. */
    );

/**
    Removes duplicate tags from the list.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_remove_duplicate_tags(
    int                *n_users,           /**< (O) Number of users. */
    tag_t              **tag_list          /**< (OF) n_users The list of user tags with removed duplicate ones.*/
    );

/**
    Copies the strings from in_str_list to out_str_list and 
    removes the duplicate strings from out_str_list.

    @returns #ITK_ok or error code.
*/
extern EPM_API int EPM_remove_duplicate_strings(
    int                in_count,                 /**< (I) Number of users. */
    char               **in_str_list,            /**< (I) The list of user strings. */
    int                *out_count,               /**< (O) The final count of users after removing duplicate ones. */
    char               ***out_str_list           /**< (OF) The final list of user strings after removing duplicate ones. */
    );


/**
    Retrieves all objects attached to the root task of the parent process of the given task.

    
    @param[in]  task_tag The task tag
    @param[out] count Number of attachments
    @param[out] attachments count The attachments
    @param[out] attachment_types count The types of attachments.<br/>Only deallocate the container using #MEM_free. Do not deallocate its elements (const char pointers).

    @returns 
    <ul>
    <li>#ITK_ok on success
    <li>Possibly some error codes. 
    </ul>
*/
extern EPM_API int EPM_ask_root_task_attachments(
    tag_t task_tag,
    int *count,
    tag_t **attachments,
    const char ***attachment_types
    );

/**
    Retrieves the most recently logged audit record for a signoff (Approve/Reject) event.
    
    @returns The tag of audit_record, or NULLTAG if no audit record is found.
*/
extern tag_t findLastSignoffAuditRecord(
    tag_t task_tag,                 /**< (I) the task tag */
    tag_t signoff_tag,              /**< (I) the signoff objec tag */
    CR_signoff_decision_t decision  /**< (I) signoff decision */
    );

#ifdef __cplusplus
}
#endif

/** @} */

#include <epm/libepm_undef.h>
#endif

