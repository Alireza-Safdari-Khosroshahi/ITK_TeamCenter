/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all the functions to be used
    by clients of the Role class which is part of the System
    Administration module of Teamcenter Engineering.

    <b>Restrictions:</b>

    This include file should not generally be used by anyone.
    Normally sa.h or role.hxx should be included instead.
*/

/*  */

#ifndef ROLE_H
#define ROLE_H

#include <sa/sa.h>
#include <unidefs.h>

#include <sa/libsa_exports.h>

/**
    @defgroup ROLE Role
    @ingroup SA
    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Allocates an array of tags, and stores in the array all roles in the database. 
    The client is responsible for deallocating the array of role_tags.
    Use #MEM_free to free the memory pointed to by role_tags.
*/
extern SA_API int SA_extent_role(
    int*          num_of_roles,     /**< (O) Stores the size of the array */
    tag_t**       role_tags         /**< (OF) num_of_roles Points to the array of tags */
    );


/**
    Initializes a Role object. It is not saved to the database until an explicit call to #AOM_save occurs.
    This function is normally used with a subclass of Role. 
    For example, if you defined a class special Role, 
    you would first call #POM_create_instance to create the object in memory.
    Then you would use this function to initialize the attributes which were inherited from Role.
    Finally, you would use additional POM calls to initialize the attributes comprising your specialization of Role.
*/
extern SA_API int SA_initialize_role2(
    tag_t         role_tag,                     /**< (I) */
    const char    *rolename                     /**< (I) */
    );


/**
    Creates a Role object. 
    It is not saved to the database until an explicit call to #AOM_save occurs.
    A role name must be specified.
*/
extern SA_API int SA_create_role2(
    const char    *rolename,                    /**< (I) */
    tag_t*        role_tag                      /**< (O) */
    );


/**
    Sets name attribute of the role.
*/
extern SA_API int SA_set_role_name2(
    tag_t         role_tag,                     /**< (I) */
    const char    *rolename                     /**< (I) */
    );


/**
    Sets name attribute of the role.
*/
extern SA_API int SA_set_role_description2(
    tag_t         role_tag,                                 /**< (I) */
    const char    *description                              /**< (I) */
    );


/**
    Finds a role with the specified name. The role name is unique in the database.
    If an error occurs, then a non-zero integer returns.
    If no role exists with the specified name,
    then a zero returns on the stack and a #NULLTAG returns for the role tag.
*/
extern SA_API int SA_find_role2(
    const char    *rolename,                    /**< (I) */
    tag_t*        role_tag                      /**< (O) */
    );


/**
    Returns the value of the name attribute for this role.
*/
extern SA_API int SA_ask_role_name2(
    tag_t         role_tag,                     /**< (I) */
    char          **rolename                    /**< (OF) */
    );


/**
    Returns the value of the description attribute for this role.
*/
extern SA_API int SA_ask_role_description2(
    tag_t         role_tag,                                 /**< (I) */
    char          **description                             /**< (OF) */
    );

/**
    Returns the role current tag of the logged in user. 
*/
extern SA_API int SA_ask_current_role(
    tag_t*        current_role_tag      /**< (O) */
    );
/**
    Returns the list of mapped attributes for a role.
*/
extern SA_API int SA_get_mapped_role_attr_list(    
    int*     numberOfAttributes,   /**< (O) */ 
    char***  list                  /**< (OF) numberOfAttributes */);


/**
    Sets the data source for the role
*/
extern SA_API int SA_set_role_last_sync_date(
    const tag_t    role,                          /**< (I) */
    date_t         syncDate                       /**< (I) */
    );
/**
    Returns the role last sync date.
*/
extern SA_API int SA_get_role_last_sync_date(
    const tag_t    role,                          /**< (I) */
    date_t        *syncDate                       /**< (O) */
    );
/**
    Sets the data source for the role
*/
extern SA_API int SA_set_role_data_source(
    const tag_t    role,                          /**< (I) */
    int            dataSource                     /**< (I) */
    );
/**
    Returns the role data source.
*/
extern SA_API int SA_get_role_data_source(
    const tag_t    role,                                /**< (I) */
    int           *dataSource                           /**< (O) */
    );


/**
 */
extern SA_API int SA_ask_role_name_by_localized_role_name2(
    const char *localizedRoleName,              /**< (I) */
    char **roleName                             /**< (OF) */
);

/** @} */

#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>

#endif
