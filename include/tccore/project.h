/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef PROJECT_H
#define PROJECT_H

#include <unidefs.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup PROJ Project
    @{
*/

#define PROJ_id_size_c        64
#define PROJ_name_size_c      32
#define PROJ_desc_size_c     240
#define PROJECTTEAM_AUTHOR_ROLE "Project Author"

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Creates a new Project with the given ID, name and description.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#PROJECT_unique_id_required if no Project exists with @p project_id.
    <li>#PROJECT_invalid_name  if the @p name is empty or contain blank spaces.
    <li>#POM_string_too_long if any of the @p project_id, @p name or @p description arguments is too long (respectively more than #PROJ_id_size_c, #PROJ_name_size_c and #PROJ_desc_size_c).
    </ul>
*/
extern TCCORE_API int PROJ_create_project(
    const char*         project_id,  /**< (I) The identification string (ID) of the Project*/
    const char*         name,        /**< (I) Name of the Project that is to be created*/
    const char*         description, /**< (I) Description of the Project that is to be created*/
    tag_t*              project      /**< (O) The new Project*/
    );

/**
    Retrieves all the Projects assigned to the provided user,
    including inactive Projects (if the @p include_inactive flag is set to true).
    @note If the user is #NULLTAG, all the Projects defined in the database are returned.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_wrong_class if the @p user is not a user object.
    </ul>
*/
extern TCCORE_API int PROJ_find_user_project(
    tag_t   user,            /**< (I)  User of the Project*/
    logical include_inactive,/**< (I)  Includes inactive Projects*/
    int*    count,           /**< (O)  Number of Projects found*/
    tag_t** projects         /**< (OF) count The projects */
    );

/**
    Determines if the given user has any projects

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_invalid_value if the given tags fails to form POM query
    <li>#CXPOM_wrong_class if the @p user is not a user object.
    <li>Possibly other errors
    </ul>
 */
extern TCCORE_API int PROJ_user_has_project(
    tag_t               user,                       /**< (I)  Tag of the given user */
    logical             active_projects_only,       /**< (I)  If set to true, check only the active projects */
    logical*            has_project                 /**< (O)  If the user has any projects */
    );

/**
    Finds the Project with given Project identifier string.
    
    @returns #ITK_ok always
*/
extern TCCORE_API int PROJ_find(
    const char*         project_id,  /**< (I) The ID of the Project to find.
                                       <br/>It is case sensitive.
                                       <br/>Wildcards are not supported (to use wildcard or other searching capabilities, please use saved query "Projects...").  */
    tag_t*              project      /**< (O) The matching Project. <br/>It will be #NULLTAG if no matching Project can be found.
 */
    );

/**
    Assigns objects to specified projects.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#PROJECT_not_member_general if the logged-in user is not a member of one of the project.
    <li>#POM_invalid_tag if any of the projects does not exist in the database.
    <li>#PROJECT_user_is_not_privileged if the logged-in user cannot assign objects to these projects.
    <li>#PROJECT_internal_error if the object assignment has failed for other reasons.
    <li>#POM_insufficient_privilege if the logged-in user is not a privileged member.
    <li>#PROJECT_not_active if any project in @p projects is not active
    <li>#PROGRAM_not_active if any program in @p programs is not active
    </ul>
*/
extern TCCORE_API int PROJ_assign_objects(
    int                 project_count,  /**< (I) Number of the Project*/
    tag_t*              projects,       /**< (I) Projects to be assigned*/
    int                 object_count,   /**< (I) Number of the objects*/
    tag_t*              objects         /**< (I) Objects  to assign for Projects*/
    );

/**
    Removes objects from the specified projects.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_tag if any of the projects or/and objects does not exist in the database.
    <li>#POM_insufficient_privilege if the logged-in user is not a privileged member.
    </ul>
*/
extern TCCORE_API int PROJ_remove_objects(
    int                 project_count,  /**< (I) Number of the Project*/
    tag_t*              projects,       /**< (I) Projects to be removed*/
    int                 object_count,   /**< (I) Number of the objects*/
    tag_t*              objects         /**< (I) object_count Objects to remove from Projects*/
    );


/**
    Checks if a given user is a regular Project member (non-privileged member) of a given Project.
    @returns
    <ul>
    <li>#ITK_ok on success, or if #NULLTAG is provided for both parameters (in which case @p answer is false).
    <li>#POM_invalid_tag if any of @p project or @p user is invalid.
    </ul>
*/
extern TCCORE_API int PROJ_is_user_a_member(
    tag_t project,     /**< (I) The Project  */
    tag_t user,        /**< (I) The user  */
    logical *answer    /**< (O) Indicates if the user is a member of the Project */
    );

/**
    Checks if a given user is a privileged Project member of a given Project.
    @returns
    <ul>
    <li>#ITK_ok on success, or if #NULLTAG is provided for both parameters (in which case @p answer is false).
    <li>#POM_invalid_tag if any of @p project or @p user is invalid.
    </ul>
*/
extern TCCORE_API int PROJ_is_user_a_privileged_member(
    tag_t   project,    /**< (I) The Project */
    tag_t   user,       /**< (I) the User */
    logical *answer     /**< (O) Indicates if the User is a privileged member
                                 (a Project author, a Project administrator, or a Project team administrator)
                                  of the given Project */
    );

/**
   Adds users as a regular Project member (non-privileged member).
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#POM_invalid_tag  if @p project is invalid.
   <li>#POM_insufficient_privilege if the logged-in user is not a privileged member.
   </ul>
*/
extern TCCORE_API int PROJ_add_members(
    tag_t  project,                     /**<(I) The Project to which the users are to be added */
    int    user_count,                  /**<(I) Number of members to be added */
    tag_t* users_groups_groupmembers    /**<(I) user_count List of Users/Groups/GroupMembers that are to be added as members of the given Project */
    );

/**
   Removes members from a Project.
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#POM_invalid_tag if @p project is invalid.
   <li>#POM_insufficient_privilege if the logged-in user is not a privileged member.
   </ul>
*/
extern TCCORE_API int PROJ_remove_members(
    tag_t   project,                     /**< (I) A Project tag that the given users will be removed */
    int     user_count,                  /**< (I) Number of members to be removed */
    tag_t*  users_groups_groupmembers    /**< (I) user_count List of Users/Groups/GroupMembers that are to be added as members of the given Project */
    );
/**
    Sets the users as Project authors (privileged users that can add/remove objects to/from a Project).
    <br/>Ensure that a user to be added as a Project Author is already a Project member.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_tag if any of @p project or @p user is invalid.
    <li>#POM_insufficient_privilege if the logged-in user is not a privileged member.
    </ul>
*/
extern TCCORE_API int PROJ_add_author_members(
    tag_t   project,        /**< (I) A Project tag that the given users will be removed */
    int     author_count,   /**< (I) Number of authors to add */
    tag_t*  authors         /**< (I) author_count List of authors on the project */
    );

/**
    Revokes the Project author (privileged users that can add/remove objects to/from a Project) status of the users from a Project.
    <br/> The project membership of the users are not removed.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_tag if the @p project or @p user is invalid.
    <li>#CXPOM_invalid_tag if the @p project is nulltag.
    <li>#POM_insufficient_privilege if the logged-in user is not a privileged member.
    </ul>
*/
extern TCCORE_API int PROJ_remove_author_members(
    tag_t  project,       /**< (I) A Project tag that the given users will be added as members */
    int    author_count,  /**< (I) Number of authors to add */
    tag_t* authors        /**< (I) author_count List of authors on the Project */
    );

/**
    Retrieves the Project author users (privileged users that can add/remove objects from a Project).
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_tag  if the @p Project is invalid.
    </ul>
*/
extern TCCORE_API int PROJ_ask_author_members(
    tag_t    project,      /**< (I)  The Project */
    int *    author_count, /**< (O)  Number of authors */
    tag_t ** authors       /**< (OF) author_count List of authors on the Project */
    );

/**
    Sets users as Project team administrators (users that can manage the project team but not the project meta data).
    <br/>Ensure that a user to be added as a Project team administrator is already a Project member.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_wrong_class if any of @p project is not a valid Project
    <li>#POM_invalid_value if any member of @p team_admins is not a valid User
    <li>#CXPOM_invalid_tag if the @p project is #NULLTAG.
    <li>#PROJECT_user_is_not_privileged if the logged-in user is not a project team administrator or project administrator
    </ul>
*/
extern TCCORE_API int PROJ_add_team_admin(
    const tag_t   project,            /**< (I) The Project for which the users will be added to the project team administrators */
    const int     n_team_admins,      /**< (I) Number of team administrators to add */
    const tag_t*  team_admins         /**< (I) n_team_admins List of team administrators to add to the project */
    );

/**
    Revokes Project team administrator status of the users from a Project.
    <br/> The project membership of the users are not removed.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_wrong_class if any of @p project is not a valid Project
    <li>#CXPOM_invalid_tag if the @p project is #NULLTAG.
    <li>#PROJECT_user_is_not_privileged if the logged-in user is not a project team administrator or project administrator
    </ul>
*/
extern TCCORE_API int PROJ_remove_team_admin(
    const tag_t  project,          /**< (I) The Project for which the users will be removed from the project team administrators */
    const int    n_team_admins,    /**< (I) Number of team administrators to remove */
    const tag_t* team_admins       /**< (I) n_team_admins List of team administrators to remove from the Project */
    );

/**
    Retrieves the Project team administrators (users that can manage the project team but not the project meta data).
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_wrong_class if any of @p project is not a valid Project
    <li>#CXPOM_invalid_tag if the @p project is #NULLTAG.
    </ul>
*/
extern TCCORE_API int PROJ_ask_team_admins(
    const tag_t project,          /**< (I)  The Project */
    int *       n_team_admins,    /**< (O)  Number of team administrators */
    tag_t **    team_admins       /**< (OF) n_team_admins List of team administrators on the Project */
    );

/**
    Assigns a team to the given Project.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if @p project is invalid.
    <li>#CXPOM_wrong_class if @p project is a valid object, but not a project.
    <li>#PROJECT_invalid_object if any of the values of @p project_administrator or @p privileged_users is not a user object.
    <li>#PROJECT_user_is_not_privileged if the logged-in user does not have administrative privileges on the @p project.
    <li>#PROJECT_no_project_team_members if @p member_count is less than or equal to zero.
    </ul>
*/
extern TCCORE_API int PROJ_assign_team(
    tag_t    project,                       /**< (I) The Project*/
    int      member_count,                  /**< (I) Number of the Project members*/
    tag_t*   members,                       /**< (I) member_count Members to add. <br/>This can be Users, Group Members and Group objects. If any other object type is provided, it will be discarded. */
    tag_t    project_administrator,         /**< (I) The user that will be a Project administrator. It can be #NULLTAG. */
    int      privileged_user_count,         /**< (I) Number of privileged users. <br/>If a zero or negative number is provided, no privileged users will be assigned to the project. */
    tag_t*   privileged_users               /**< (I) privileged_user_count The list of privileged users */
    );

/**
     Assigns team members to the given Project. This API supports multiple project team administrators.
     @returns
     <ul>
     <li>#ITK_ok on success.
     <li>#CXPOM_invalid_tag if a @p project, @p members, @p administrators, or @p privileged_users tag is invalid.
     <li>#PROJECT_invalid_admin_or_priv_member_tag if an @p administrators or @p privileged_users tag is a valid object, but not a user.
     <li>#PROJECT_user_is_not_privileged if the logged-in user does not have administrative privileges on the @p project.
     <li>#PROJECT_no_project_team_members if @p member_count is less than or equal to zero.
     <li>#PROJECT_no_project_team_administrators if @p administrator_count is less than or equal to zero.
     <li>#PROJECT_invalid_member_tag if any of the @p members is not a Group or GroupMember tag.
     </ul>
 */
extern TCCORE_API int PROJ_assign_team_members(
    tag_t project,                     /**< (I) The Project*/
    int member_count,                  /**< (I) Number of the Project members*/
    tag_t* members,                    /**< (I) member_count Members to add. <br/>This can be Group Members and Group objects. If any other object type is provided, it will be discarded. */
    int administrator_count,           /**< (I) Number of Project administrators*/
    tag_t* administrators,             /**< (I) administrator_count The list of Project team administrators*/
    int privileged_user_count,         /**< (I) Number of privileged users. <br/>If a zero or negative number is provided, no privileged users will be assigned to the project. */
    tag_t* privileged_users            /**< (I) privileged_user_count The list of privileged users*/
    );

/**
    Retrieves the team of the given Project, including information about members, administrators and privileged users.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the @p project is invalid.
    <li>#POM_insufficient_privilege if the logged-in user is not a privileged member.
    </ul>
 */
extern TCCORE_API int PROJ_ask_team(
        tag_t project,                /**< (I)  The Project */
        int* member_count,            /**< (O)  Number of project members found */
        tag_t** members,              /**< (OF) member_count The list of Project members */
        int* administrator_count,     /**< (O)  Number of Project admins */
        tag_t** administrator_tags,   /**< (OF) administrator_count The list of Project team administrators */
        int* privileged_user_count,   /**< (O)  Number of privileged users */
        tag_t** privileged_user_tags  /**< (OF) privileged_user_count The list of privileged users */
    );

/**
    Creates a new Project based on an existing Project.
    <br>The members, team administrators, administrator and privileged users are copied from the source project.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the @p source_project is invalid.
    <li>#PROJECT_unique_id_required if no @p project exists with the ID.
    <li>#POM_string_too_long if any of the @p project_id, @p name or @p description arguments is too long (respectively more than #PROJ_id_size_c, #PROJ_name_size_c and #PROJ_desc_size_c).
    <li>#POM_insufficient_privilege if the logged-in user is not a privileged member.
    </ul>
*/
extern TCCORE_API int PROJ_copy_project(
        tag_t source_project,                 /**< (I) The Project to be copied from */
        const char * project_id,              /**< (I) The identification string (ID) of the new Project */
        const char * project_name,            /**< (I) Name of the new Project */
        const char * project_description,     /**< (I) Description of the new Project*/
        logical active,                       /**< (I) Defines if the Project is active */
        logical visible,                      /**< (I) If it is visible*/
        logical use_program_security,         /**< (I) If it uses program level security*/
        tag_t * project                       /**< (O) The newly created project */
    );

/**
    Activates or de-activates a Project.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the @p project is invalid.
    <li>#POM_insufficient_privilege if the logged-in user is not a privileged member.
    </ul>
*/
extern TCCORE_API int PROJ_activate_project(
    tag_t               project,    /**< (I) The Project to activate */
    logical             activate    /**< (I) If the Project is activate */
    );

 /**
     Retrieves the activation status of a Project.
     @returns
     <ul>
     <li>#ITK_ok on success
     <li>#CXPOM_invalid_tag  if the @p project is invalid.
     </ul>
*/
extern TCCORE_API int PROJ_is_project_active(
    tag_t               project,    /**< (I) The Project to activate */
    logical*            active      /**< (O) The activation status */
    );

/**
    Retrieves identification string (ID) for a specified Project.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the @p project is invalid.
    </ul>
*/
extern TCCORE_API int PROJ_ask_id2(
    tag_t               project,                /**< (I)  The Project to identify*/
    char                **id                    /**< (OF) The Project identification string*/
    );


/**
    Retrieves the name of the specified Project.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if the @p project is invalid.
    </ul>
*/
extern TCCORE_API int PROJ_ask_name2(
    tag_t               project,                    /**< (I)  The Project */
    char                **name                      /**< (OF) The Project name string*/
    );

/**
    Retrieves the objects assigned to a Project.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#SA_group_name_already_used if the @p project_id already exists.
    </ul>
*/
extern TCCORE_API int PROJ_ask_assigned_objects(
    const char* project_id,                         /**< (I)  The identification string (ID) of the Project*/
    int*        object_count,                       /**< (O)  Number of assigned objects */
    tag_t**     objects                             /**< (OF) object_count The assigned objects */
    );


/*
    Initializes a Project object.
    <br/>It is not saved to the database until an explicit call to #AOM_save occurs.
    <br/>An id, name and description must be specified.
    <br/>You normally use this function with a subclass of Project.
    For example, using a specialized class of Project:
    <ol>
    <li>Call #POM_create_instance to create the object in memory.
    <li>Use #PROJ_initialize to initialize the attributes which were
    inherited from Project.
    <li>Use additional POM calls to initialize the attributes comprising
    your specialization of Project.
    </ol>

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#SA_group_name_already_used if the @p project already exists.
    <li>#POM_string_too_long if any of the @p project_id, @p name or @p description arguments is too long (respectively more than #PROJ_id_size_c, #PROJ_name_size_c and #PROJ_desc_size_c).
    <li>#POM_insufficient_privilege if the logged-in user is not a privileged member.
    </ul>
*/
extern TCCORE_API int PROJ_initialize2(
    tag_t project,                            /**< (I) The Project */
    const char *id,                           /**< (I) The Project identification string (ID) of the Project */
    const char *name,                         /**< (I) Name of the Project that is to be created*/
    const char *description                   /**< (I) Description of the Project*/
    );

/**
  Creates a new Project with the given ID, name, description and use_program_level_security option.
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SA_group_name_already_used if the @p project_id already exists.
   <li>#POM_string_too_long if any of the @p project_id, @p name or @p description arguments is too long (respectively more than #PROJ_id_size_c, #PROJ_name_size_c and #PROJ_desc_size_c).
   <li>#POM_insufficient_privilege if the logged-in user is not a privileged member.
   </ul>
*/
extern TCCORE_API int PROJ_create_project_with_options(
    const char*         project_id,                     /**< (I) The identification string (ID) of the Project */
    const char*         name,                           /**< (I) Name of the Project */
    const char*         description,                    /**< (I) Description of the Project */
    const logical       use_program_level_security,     /**< (I) When set to true, a Programs are created instead of a Project */
    tag_t*              project                         /**< (O) The new Project*/
    );

/**
   Changes program level security of a Project.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_tag if the @p project is invalid.
    <li>#POM_insufficient_privilege if the logged-in user is not a privileged member.
    </ul>

*/
extern TCCORE_API int PROJ_edit_project_options(
    tag_t               project,                      /**< (I) The Project */
    const logical       use_program_level_security    /**< (I) When set to true, a Programs are created instead of a Project */
    );

/**
    Sets a project as default Project for a list of Project members.
   <br/>If the logged-in user has a User Context, it updates the Project within the User Context.
   Otherwise, it creates a new User Context and sets the current project.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if any of the @p project and members are invalid.
    </ul>
*/
extern TCCORE_API int PROJ__set_default_project(
    int member_count,      /**< (I) Number of Project members*/
    tag_t *members,        /**< (I) A list of tags of Project members to be set as default*/
    tag_t project          /**< (I) The Project tag*/
    );

/**
  Retrieves all the Projects assigned to the given user.
  @note If the user is #NULLTAG, all the projects defined in the database are retrieved:
  <ul>
  <li>including active projects only if the @p active_projects_only flag is set to true.
  <li>including privileged Projects only if @p privileged_projects_only flag is set to true.
  <li>including programs Projects only if @p programs_only flag is set to true.
  <li>if the given user is #NULLTAG, all the Projects defined in DB are retrieved.
  </ul>
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#CXPOM_wrong_class if the @p user is not a user object.
    </ul>
*/
extern TCCORE_API int PROJ_find_user_projects
(
    tag_t               user,                       /**< (I)  Tag of the given user */
    logical             active_projects_only,       /**< (I)  If set to true, it includes active projects only */
    logical             privileged_projects_only,    /**<(I)  If set to true, it includes privileged Projects only privileged only */
    logical             programs_only,              /**< (I)  If set to true, it includes programs Projects only */
    int*                n_projects,                 /**< (O)  Number of Projects */
    tag_t**             projects                    /**< (OF) n_projects Projects found for this user */
);

/**
    Determines if the users are in any of the given projects.

    <br/>The determination is done regardless of the active project and role.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_invalid_value if the given tags fails to form POM query
    <li>#PROJECT_internal_error if the number of the inputs exceeds INT_MAX
    <li>Possibly other errors
    </ul>
 */
extern TCCORE_API int PROJ_check_users_in_projects(
    const unsigned int      n_users,                /**< (I)  The number of the given users */
    const tag_t *           users,                  /**< (I)  n_users The users */
    const unsigned int      n_projects,             /**< (I)  The number of projects */
    const tag_t*            projects,               /**< (I)  n_projects The projects to check membership */
    logical **              verdicts                /**< (OF) n_users The verdicts for each user */
    );

/**
   Finds all the objects in a Project according to a criteria.
   <br/>The object and client application responsible for the loading of the objects are also retrieved by this function.
   <br/>Wildcard characters are supported in filter_values (* matches 0 or more and ? matches single character)
   <br/><br/>This ITK offers good performances for Projects containing large amount of data.
   @returns #ITK_ok always.
   @note No object is returned if @p project_id is invalid or if @p filter_criteria, @p filter_name, @p filter_values do not match any objects.
*/
extern TCCORE_API int PROJ_find_objects_in_projects
(
      const char *  project_id,               /**< (I)  The Project ID */
      int           filter_criteria,          /**< (I)  Additional criteria count */
      const char ** filter_names,             /**< (I)  Criteria names. <br/>Valid values are "Name" and "Type". */
      const char ** filter_values,            /**< (I)  Criteria values */
      int *         number_objects,           /**< (O)  Number of objects found */
      tag_t **      objects                   /**< (OF) number_objects Objects in the Project */
);

/**
  Creates a new Project with the given ID, name, description, parent project and use_program_level_security option.
   @note @p peer_project_id is for future use. The value given in this arguments will be ignored.

   <b>Restrictions:</b>
   <br/>The logged-in user must be administrator of parent project.
   <br/>The parent project must have program security enabled.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#SA_group_name_already_used if the @p project_id already exists.
   <li>#POM_string_too_long if any of the @p project_id, @p name or @p description arguments is too long
       (respectively more than #PROJ_id_size_c, #PROJ_name_size_c and #PROJ_desc_size_c characters).
   <li>#POM_insufficient_privilege if the logged-in user is not a privileged member.
   <li>#PROJECT_fail_to_find_project if the project with @p parent_project_id is not found.
   <li>#PROJECT_user_not_administrator if the logged-in user is not an administrator of the parent project.
   <li>#PROJECT_team_inheritance_not_allowed if the project is not being created under a parent.
   </ul>
*/
extern TCCORE_API int PROJ_create_project_with_parent(
    const char*         project_id,                     /**< (I) The project ID of the project to create */
    const char*         parent_project_id,              /**< (I) The project ID of the parent project */
    const char*         peer_project_id,                /**< (I) The project ID of the peer project */
    const char*         name,                           /**< (I) Name of the Project */
    const char*         description,                    /**< (I) Description of the Project */
    const logical       use_program_security,           /**< (I) When set to true, a Program is created instead of a
                                                                 Project */
    const unsigned int  allow_team_inheritance,         /**< (I) Valid values are:
                                                                <ul>
                                                                <li>0: The parent Program members are ignored.
                                                                <li>Otherwise: The Project team is copied from the parent Program.
                                                                </ul>  */
    tag_t*              project                         /**< (O) The new Project*/
    );

/**
  Retrieves the ordered list (starting from immediate to the top level parent) of parent Projects for a given project.
  <br/>If @p all_parents is true, it retrieves all the parents recursively. Otherwise, only immediate parent will be returned.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#POM_invalid_tag if the @p project is invalid.
   </ul>
*/
extern TCCORE_API int PROJ_ask_parent_projects(
    const tag_t         project,                  /**< (I) Tag of the Project */
    const logical       all_parents,              /**< (I) If @c true, retrieves all the parents recursively. Otherwise, only the immediate parent is retrieved. */
    int*                n_parents,                /**< (O) Number of parent Projects. */
    tag_t**             projects                  /**< (O) n_parents List of parent Projects. */
    );

typedef enum PROJ_validate_condition_type_e
{
    PROJ_priv_members_only = 0,
    PROJ_priv_member_or_reg_member_with_access,
    PROJ_reg_member_with_access,
    PROJ_priv_member_and_with_access,
    PROJ_no_member_with_access
} PROJ_validate_condition_type_t;

/** @} */

#ifdef __cplusplus
}
#endif

#include <tccore/libtccore_undef.h>

#endif
