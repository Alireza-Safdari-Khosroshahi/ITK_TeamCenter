/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the interface to iddisp data manipulation. For other
    related interfaces please review the related topics in the users guide and
    review the appropriate header files.
*/

/*  */

#ifndef IDDISP_H
#define IDDISP_H

#include <tc/tc_startup.h>
#include <common/emh_const.h>
#include <tccore/iddisp_errors.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup IDDISP IdDispRule

    Since an item or item revision can have more than one id, 
    the user should be able to configure which id and rev id gets displayed.

    Users can manage their own display rules:

    <ul>
    <li>Users can designate one of the rules as the current display rule.
    <li>Users can share the rules with other users. 
        This allows a site and a group to define some standard set of rules while still allowing
        a user to create additional display rules.
    <li>If an identifiable object has designated an identifier as a default display identifier then it
        provides the default display of the identifiable object.
        If no default display identifier exists, the initial id is considered the default display of the identifiable object.
        Users have the option to end a display rule by using a default display of the identifiable object. 
    </ul>

    Use AOM functionality to refresh, save, and delete IdDispRule objects.
    Use #MEM_free to release allocated storage.

    @{
*/

/**
    @name IDDISPRULE class name and property name constants
    @{
*/
#define IDDISPRULE_class_name_c          "IdDispRule"
#define IDDISPRULE_name                  "iddisp_name"
#define IDDISPRULE_disp_name             "iddisp_disp_name"
#define IDDISPRULE_owner                 "owning_user"
#define IDDISPRULE_usedefault            "use_default"
#define IDDISPRULE_idcontexts            "idcontext_list"
/** @} */

/**
    @name Messages unique to IDDISPRULE
    @{
*/
#define IDDISPRULE_create_msg            "IDDISPRULE_create"
/** @} */

#ifdef __cplusplus
    extern "C"{
#endif

/**
    The type is provided for future extension. 
    Generally, this should be "IdDispRule" or null to mean "IdDispRule".
    This call creates a new iddisprule object in memory of the given type,
    but does not save it in the database. 
*/
extern TCCORE_API int IDDISP_create (
    const char*         iddisp_type,        /**< (I) Type of iddisprule instance to be created or null */
    tag_t*              new_iddisprule_tag  /**< (O) Tag of new iddisprule object */
    );

/**
    Returns the name attribute for the given identifier display rule. 
*/
extern TCCORE_API int IDDISP_ask_name (
    tag_t               iddisprule_tag,     /**< (I) Tag of existing iddisprule */
    char**              name                /**< (OF) Name attribute value for the given identifier display rule */
    );

/**
    Returns TRUE if the given identifier display rule specifies to use a default when the contents of the rule is not matched. 
*/
extern TCCORE_API int IDDISP_ask_usedefault (
    tag_t               iddisprule_tag,     /**< (I) Tag of existing iddisprule */
    logical*            use_default         /**< (O) Indicates if the given identifier display rule is the default rule */
    );

/**
    Returns all the idcontext objects for the given identifier display rule.
*/
extern TCCORE_API int IDDISP_ask_idcontexts (
    tag_t               iddisprule_tag,     /**< (I) Tag of existing iddisprule */
    int*                num_idcontexts,     /**< (O) Number of idcontext objects */
    tag_t**             idcontext_tags      /**< (OF) num_idcontexts An array of tags to idcontext objects */
    );

/**
    Returns the current identifier display rule.
*/
extern TCCORE_API int IDDISP_ask_current (
    tag_t*              iddisprule_tag      /**< (O) Tag of current iddisprule.  Could be a null tag. */
    );

/**
    Sets the name attribute for the given identifier display rule. 
    The name must be case-insensitively unique for the owner of the rule.
*/
extern TCCORE_API int IDDISP_set_name (
    tag_t               iddisprule_tag,     /**< (I) Tag of existing iddisprule */
    const char*         name                /**< (I) Name attribute value for the given identifier display rule */
    );

/**
    Sets the given identifier display rule use default.  
    TRUE specifies to use a default when the contents of the rule are not matched. 
*/
extern TCCORE_API int IDDISP_set_usedefault (
    tag_t               iddisprule_tag,     /**< (I) Tag of existing iddisprule */
    logical             use_default         /**< (I) Indicates if the given identifier display rule is the default rule */
    );

/**
    Sets all the idcontext objects for the given identifier display rule.
*/
extern TCCORE_API int IDDISP_set_idcontexts (
    tag_t               iddisprule_tag,     /**< (I) Tag of existing iddisprule */
    int                 num_idcontexts,     /**< (I) Number of idcontext objects */
    tag_t*              idcontext_tags      /**< (I) An array of tags to idcontext objects */
    );

/**
    Sets the given identifier display rule as the current rule. Can be #NULLTAG.  
    If not, the rule must be already in the user’s list.
*/
extern TCCORE_API int IDDISP_set_current (
    tag_t               iddisprule_tag      /**< (I) Tag of current iddisprule or #NULLTAG */
    );

/**
    Returns all identifier display rules in the given user’s rule list. 
*/
extern TCCORE_API int IDDISP_my_rules (
    int*                num_rules,          /**< (O) Number of identifier display rules */
    tag_t**             iddisprule_tags     /**< (OF) num_rules An array of tags to identifier display rule objects */
    );

/**
    Returns all identifier display rules in the given user’s rule list. 
*/
extern TCCORE_API int IDDISP_list_rules (
    tag_t               user_tag,           /**< (I) Tag of requested user */
    int*                num_rules,          /**< (O) Number of identifier display rules for the given user */
    tag_t**             iddisprule_tags     /**< (OF) num_rules An array of tags to identifier display rule objects */
    );

/**
    Adds given identifier display rules to the user’s rule list. 
*/
extern TCCORE_API int IDDISP_add (
    int                 num_rules,          /**< (I) Number of identifier display rules */
    tag_t*              iddisprule_tags     /**< (I) An array of tags to identifier display rule objects */
    );

/**
    Removes given identifier display rules from the user’s rule list. 
    If one of the rule being removed is also the current rule of the user, it cannot be removed. 
    If the rule being removed is not shared by anyone else, it will be deleted.
    If someone shares it, it will not be allowed to remove the rule. 
    However, one can transfer the ownership of the rule to someone who is sharing the rule
    and then remove it from his or her list.
*/
extern TCCORE_API int IDDISP_remove (
    int                 num_rules,          /**< (I) Number of identifier display rules */
    tag_t*              iddisprule_tags     /**< (I) An array of tags to identifier display rule objects */
    );

/**
    Returns the identifier display rule object for the given rule name and owner.
*/
extern TCCORE_API int IDDISP_find_rule (
    const char*         name,               /**< (I) Name of identifier display rule or null */
    tag_t               owner_tag,          /**< (I) Tag of owner for the given rule name */
    tag_t*              iddisprule_tag      /**< (O) Tag of iddisprule object */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tccore/libtccore_undef.h>

#endif
