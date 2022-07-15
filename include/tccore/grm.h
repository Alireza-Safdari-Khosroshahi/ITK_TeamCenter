/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all data types and constants to be used by clients of the GRM module
*/

/*  */

#ifndef GRM_H
#define GRM_H

#include <tccore/grm_errors.h>
#include <fclasses/tc_basic.h>
#include <stdarg.h>
#include <common/tc_deprecation_macros.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup GRM Generic Relationship Manager (GRM)

    The GRM module supports the concept of explicit relationships.
    A dataset can be directly and explicitly related to an Item Revision with,
    as an example, a specification relationship.
    With GRM, you can define and enforce specific rules pertaining to relationships,
    as well as separate the maintenance of relationships from the data itself.

    <b>Common Return Values</b>

    <table>
    <tr><td>Return Value                 </td><td>Description                                                 </td></tr>
    <tr><td>#CXPOM_invalid_tag           </td><td>Invalid tag supplied.                                       </td></tr>
    <tr><td>#GRM_duplicate_relation_type </td><td>The type you propose to create already exists in the system.</td></tr>
    <tr><td>#GRM_internal_error          </td><td>The GRM module has detected an internal inconsistency and
                                                  therefore should not be used.                               </td></tr>
    <tr><td>#GRM_invalid_primary_object  </td><td>Specified tag for the primary_object is not valid.          </td></tr>
    <tr><td>#GRM_invalid_relation_type   </td><td>Specified tag for relation_type is not valid.               </td></tr>
    <tr><td>#GRM_invalid_secondary_object</td><td>Specified tag for the secondary_object is not valid.        </td></tr>
    <tr><td>#GRM_invalid_user_data       </td><td>Specified tag for user_data is not valid.                   </td></tr>
    <tr><td>#GRM_not_initialized         </td><td>The GRM module was not initialized.                         </td></tr>
    <tr><td>#GRM_relation_already_exists </td><td>The relation being saved already exists.                    </td></tr>
    <tr><td>#GRM_relation_does_not_exist </td><td>Relation does not exist.                                    </td></tr>
    <tr><td>#GRM_undefined_relation_type </td><td>The type you propose to delete does not exist.              </td></tr>
    </table>

    <b>Returned Tag Structure</b>

    Several GRM list functions return a list of tag quadruplets defined by the structure #GRM_relation_t.
    The tag structure includes the tags of the primary_object, secondary_object, relation_type, and the user_data.
    The tag of a specific element of the structure can be referenced as follows:

    <table>
    <tr><td>structure_name.primary      </td><td>To reference the primary object.  </td></tr>
    <tr><td>structure_name.secondary    </td><td>To reference the secondary object.</td></tr>
    <tr><td>structure_name.relation_type</td><td>To reference the relation type.   </td></tr>
    <tr><td>structure_name.user_data    </td><td>To reference the user data.       </td></tr>
    </table>

    <b>Constraint Handler Registration and Execution</b>

    User-written constraint handlers should be registered in the USER_register_handlers user exit.
    This user exit is called during initialization for both interactive and ITK modes.
    This ensures that constraint handling is enforced in a consistent manner.

    If constraint handlers are also registered in your ITK program (as well as in USER_register_handlers),
    then both sets of constraint handlers are called in the order they were registered.
    Since USER_register_handlers is called before your main ITK program,
    any handler you register in your ITK program is executed after
    the handlers registered using USER_register_handlers.

    Additionally, it is possible that an internal Teamcenter handler is
    also registered for a give relation type and action combination.
    Such a handler is normally registered by a Teamcenter module or
    application to enforce certain rules before the user exit USER_register_handlers is called.
    Internal handlers are always executed before any user-written handler.

    <b>Multi-Level Handlers</b>

    Several levels of constraint handlers can exist for a particular relation type and action combination.
    There are internal handlers which a Teamcenter developer may have registered.
    For example, a new module in Teamcenter (i.e., MYITEM)
    may register a set of internal handlers for creating a relation of type reference to
    ensure that the primary object is either an item or an item revision.

    The System Administrator of an installation could also register handlers using the
    user exit USER_register_handlers to enforce the rule that the user must be
    the owner of the item or item revision to allow the creation of such a relation.
    Additionally, an ITK program can register another set of handlers to enforce the rule that
    the secondary object cannot be another item or item revision.

    For multi-level handlers, the order of execution is as follows:
    <ol>
    <li>internal pre-condition handler
    <li>user exit pre-condition handler
    <li>ITK program pre-condition handler
    <li>internal pre-action handler
    <li>user exit pre-action handler
    <li>ITK program pre-action handler
    <li>base action (the main operation performed by Teamcenter)
    <li>internal post-action handler
    <li>user exit post-action handler
    <li>ITK program post-action handler
    </ol>
    If a handler that executes first returns an error condition,
    then the other registered handlers will not execute.
    For example, if the internal pre-condition handler returns an error,
    none of the other handlers will execute; this includes the base action.

    @{
*/

#define GRM_class_name_c               "ImanRelation"
#define GRM_relationtype_name_size_c   32

typedef struct GRM_relation_s
{
    tag_t the_relation;
    tag_t primary;
    tag_t secondary;
    tag_t relation_type;
    tag_t user_data;
} GRM_relation_t, *GRM_relation_p_t;

/**
    Provides a list of Primary/Secondary objects and Generic Relationship Management (GRM) Relations to search for.
*/
typedef struct GRM_list_relation_input_s
{
    int     object_count;           /**< Number of primary/secondary objects to search for.*/
    tag_t*  objects;                /**< object_count The list of such objects.*/
    int     relation_type_count;    /**< Number of relation types to search for.*/
    tag_t*  relation_types;         /**< relation_type_count List of relation types.*/
} GRM_list_relation_input_t, *GRM_list_relation_input_p_t;


#ifdef __cplusplus
 extern "C"{
#endif

/**
    Creates a relation of the specified type.

    <b>Restrictions:</b>

    The primary_object, secondary_object, and relation_type must all be valid tags.
    The user_data can be a #NULLTAG but if it is not a #NULLTAG, then it must be a valid tag.
    The user_data can be the tag of any valid POM object that the user wants to access through the GRM relation.
    To create the relation in the database, #GRM_save_relation must be called after this function.
    It is highly recommended that #GRM_find_relation be called first to determine if
    the relation already exists before calling this function; otherwise,
    the attempt to create a duplicate relation will be detected only during #GRM_save_relation.
*/
extern TCCORE_API int GRM_create_relation(
    tag_t               primary_object,     /**< (I) Direction-setting object in the relation;
                                                it is usually the independent object in the relation. */
    tag_t               secondary_object,   /**< (I) This object is usually the dependent object in the relationship */
    tag_t               relation_type,      /**< (I) This is a tag of the specified relationship type */
    tag_t               user_data,          /**< (I) This is a tag that identifies some user data; must be set to #NULLTAG if not used. */
    tag_t*              relation            /**< (O) Tag of new relation, if successfully created. */
    );

/**
    Saves a relation.
    Before calling save, the object must first be loaded or refreshed for modify.
*/
extern TCCORE_API int GRM_save_relation(
    tag_t               relation    /**< (I) Tag of relation to be saved */
    );

/**
    Deletes a relation.
*/
extern TCCORE_API int GRM_delete_relation(
    tag_t               relation    /**< (I) Tag of relation to be deleted */
    );

/**
    Looks for a relation and returns its tag if it exists.

    <b>Restrictions:</b>

    None of the input parameters can be a #NULLTAG and all should be valid tags.
*/
extern TCCORE_API int GRM_find_relation(
    tag_t               primary_object,     /**< (I) Direction-setting object in the relation;
                                                it is usually the independent object in the relation. */
    tag_t               secondary_object,   /**< (I) This object is usually the dependent object in the relationship */
    tag_t               relation_type,      /**< (I) This is a tag of the specified relationship type; this cannot be a #NULLTAG. */
    tag_t*              relation            /**< (O) Tag of the relation, if found. */
    );

/**
    Returns a list and count of all relations which satisfy the search criteria as defined by the input parameters.
    Each input tag can be a #NULLTAG, which effectively acts as a wildcard identifier;
    for example, if the relation type is a #NULLTAG, then it means match all relation types.
    If all the input are #NULLTAG, then all relations in the system will be returned.
*/
extern TCCORE_API int GRM_list_relations(
    tag_t               primary_object,     /**< (I) Tag of primary object to be searched for */
    tag_t               secondary_object,   /**< (I) Tag of secondary object to be searched for */
    tag_t               relation_type,      /**< (I) Tag of relation type to be searched for */
    tag_t               user_data,          /**< (I) Tag of user data to be searched for */
    int*                count,              /**< (O) Number of objects found */
    tag_t**             relation_list       /**< (OF) count List of tags of all relations that match the search */
    );

/**
    Returns a list and count of all secondary objects with a specified relation type to the specified primary object.
*/
extern TCCORE_API int GRM_list_secondary_objects(
    tag_t               primary_object,     /**< (I) Tag of primary object to search for */
    tag_t               relation_type,      /**< (I) Tag of relation type to search for; #NULLTAG means all relation types. */
    int*                count,              /**< (O) Number of objects found */
    GRM_relation_t**    secondary_list      /**< (OF) count List of tag quadruplet
                                                 (primary, secondary, relation_type, user_data)
                                                 as defined by the structure #GRM_relation_t. */
    );

/**
    Retrieves in bulk the list of all secondary objects with a specified relation types to the specified primary objects.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#GRM_not_initialized if the Generic Relationship Management (GRM) module is not initialized.
    <li>#GRM_invalid_set_of_arguments if any of the input arguments are invalid.
    </ul>
*/
extern TCCORE_API int GRM_list_secondary_objects_in_bulk(
    int                                 input_count,    /**< (I) Number of structures to use for the search */
    const GRM_list_relation_input_t*    inputs,         /**< (I) input_count List of search structures, which contain the primary objects and GRM relations  */
    int*                                count,          /**< (O) Number of objects found  */
    GRM_relation_t**                    secondary_list  /**< (OF) count List of #GRM_relation_t structures
                                                        {which contains a tag quadruplet: primary, secondary, relation_type, user_data). */
    );

/**
    Returns a list and count of all secondary objects with a
    specified relation type to the specified primary object.
    Differs from #GRM_list_secondary_objects in that it returns only the objects themselves,
    and <b>does not load the relations</b>.
    This means it is likely to be more efficient than #GRM_list_secondary_objects.
*/
extern TCCORE_API int GRM_list_secondary_objects_only(
    tag_t               primary_object,     /**< (I) Tag of primary object to search for */
    tag_t               relation_type,      /**< (I) Tag of relation type to search for;
                                                 #NULLTAG means all relation types. */
    int*                count,              /**< (O) Number of objects found */
    tag_t**             secondary_objects   /**< (OF) count Array of secondary objects found */
    );

/**
    Returns a list and count of all primary objects with a specified relation type to the specified secondary_object.
*/
extern TCCORE_API int GRM_list_primary_objects(
    tag_t               secondary_object,   /**< (I) Tag of secondary object to search for */
    tag_t               relation_type,      /**< (I) Tag of relation type to search for; #NULLTAG means all relation types. */
    int*                count,              /**< (O) Number objects found */
    GRM_relation_t**    primary_list        /**< (OF) count List of tag quadruplet
                                                 {primary_object, secondary_object, relation_type, user_data}
                                                 as defined by the structure #GRM_relation_t. */
    );

/**
    Retrieves in bulk the list of all primary objects with a specified relation types to the specified secondary objects.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#GRM_not_initialized if the Generic Relationship Management (GRM) module is not initialized.
    <li>#GRM_invalid_set_of_arguments if any of the input arguments are invalid.
    </ul>
*/
extern TCCORE_API int GRM_list_primary_objects_in_bulk(
    int                                 input_count,    /**< (I) Number of structures to use for the search */
    const GRM_list_relation_input_t*    inputs,         /**< (I) input_count List of search structures, which contain the secondary objects and GRM relations  */
    int*                                count,          /**< (O) Number of objects found */
    GRM_relation_t**                    primary_list    /**< (OF) count List of #GRM_relation_t structures
                                                        {which contains a tag quadruplet: primary, secondary, relation_type, user_data). */
    );

/**
    Returns a list and count of all primary objects with a
    specified relation type to the specified secondary object.
    Differs from #GRM_list_primary_objects in that it returns only the objects themselves,
    and <b>does not load the relations</b>.
    This means it is likely to be more efficient than #GRM_list_primary_objects.
*/
extern TCCORE_API int GRM_list_primary_objects_only(
    tag_t               secondary_object,   /**< (I) Tag of secondary object to search for */
    tag_t               relation_type,      /**< (I) Tag of relation type to search for;
                                                 #NULLTAG means all relation types. */
    int*                count,              /**< (O) Number of objects found */
    tag_t**             primary_objects    /**< (OF) count Array of primary objects found */
    );

/**
    Retrieves the list and count of all objects of the specified primary object type with a
    specified relation type to the specified secondary object.
    <br>This function differs from #GRM_list_primary_objects_only in that it returns only objects of the specified type,
    and <b>does not load the relations</b>. A NULL relation_type means all relatoin types. If the secondary_object
    is NULL or invalid, the function will return nothing.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#TYPE_unknown_type if the specified primary object type does not exist.
    </ul>
*/
extern TCCORE_API int GRM_list_primary_objects_with_primary_object_type_only(
    tag_t               secondary_object,   /**< (I) Tag of secondary object used for the search */
    tag_t               relation_type,      /**< (I) Tag of relation type used for the search. Provide #NULLTAG in order to look for all relation types */
    const char*         primary_type_name,  /**< (I) Name of primary object type used for the search */
    int*                count,              /**< (O) Number of found objects */
    tag_t**             primary_objects     /**< (OF) count Array of found primary objects  */
    );

/**
    Retrieves the list of all objects (both primary and secondary) that are related to the specified object.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#GRM_not_initialized if the Generic Relationship Management (GRM) module is not initialized.
    <li>#GRM_internal_error if the input object is #NULLTAG or an invalid tag.
    </ul>
*/
extern TCCORE_API int GRM_list_all_related_objects(
    tag_t               object,                 /**< (I) The object for which related objects must be retrieved */
    int*                count,                  /**< (O) Number of objects found */
    GRM_relation_t**    related_object_list     /**< (OF) count List of tag quadruplet
                                                    {primary, secondary, relation_type, user_data}
                                                    as defined by the structure #GRM_relation_t. */
    );

/**
    Retrieves the list of all objects (both primary and secondary) that are related to the specified object.
    <br/>It differs from #GRM_list_all_related_objects in that it returns only the objects themselves,
    and <b>does not load the relations</b>.
    <br/>This means it is likely to be more efficient than #GRM_list_all_related_objects.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#GRM_not_initialized if the Generic Relationship Management (GRM) module is not initialized.
    <li>#GRM_internal_error if the input object is #NULLTAG or an invalid tag.
    </ul>
*/
extern TCCORE_API int GRM_list_all_related_objects_only(
    tag_t               object,             /**< (I) The object for which related objects must be retrieved */
    int*                count,              /**< (O) Number of objects found */
    tag_t**             related_objects     /**< (OF) count Array of related_object found */
    );

/**
    Returns the primary object tag of the specified relation.
*/
extern TCCORE_API int GRM_ask_primary(
    tag_t               relation,       /**< (I) Tag of the relation */
    tag_t*              primary_object  /**< (O) Tag of the primary object in the specified relation */
    );

/**
    Returns the secondary object tag of the specified relation.
*/
extern TCCORE_API int GRM_ask_secondary(
    tag_t               relation,           /**< (I) Tag of the relation */
    tag_t*              secondary_object    /**< (O) Tag of the secondary object in the specified relation */
    );

/**
    Returns the relation type of the specified relation.
*/
extern TCCORE_API int GRM_ask_relation_type(
    tag_t               relation,       /**< (I) Tag of the relation */
    tag_t*              relation_type   /**< (O) Tag of the relation type in the specified relation */
    );

/**
    Returns the tag of the user data of the specified relation.
*/
extern TCCORE_API int GRM_ask_user_data(
    tag_t               relation,   /**< (I) Tag of the relation */
    tag_t*              user_data   /**< (O) Tag of the user data the specified relation */
    );

/**
    Sets the value of the relation's user data to that of the specified new_user_data.

    <b>Restrictions:</b>

    The tag supplied in new_user_data can be a #NULLTAG.
    However, if it is not a #NULLTAG, then it must be a valid POM tag.

    The relation must be locked before this function is called and then later unlocked.

    For the new value to be reflected in the database, #AOM_save must be called.
*/
extern TCCORE_API int GRM_set_user_data(
    tag_t               relation,       /**< (I) Tag of the relation */
    tag_t               new_user_data   /**< (I) Tag of the new user data */
    );

/**
    Returns the tags of all relation types in the system.
*/
extern TCCORE_API int GRM_list_relation_types(
    int*                count,              /**< (O) Count of relation types in system */
    tag_t**             relation_type_list  /**< (OF) count Tag list of relation types in system */
    );

/**
Retrieves the relation type for the given relation type name.
@note This API does not return an error if the relation type is not found, for this case @p relation_type would be a #NULLTAG

@returns
<ul>
<li>#ITK_ok always
</ul>
*/
extern TCCORE_API int GRM_find_relation_type(
    const char*         relation_type_name,     /**< (I) Name of relation type to find. */
    tag_t*              relation_type           /**< (O) Tag of relation type.
                                                <br\>This will be a #NULLTAG if no relation type is found for @p relation_type_name. */
    );

/**
    @deprecated #GRM_create_relation_type deprecated in Teamcenter 12.4.
    <br/>A relation type should be created in BMIDE.
    
    Creates a new relation type in the system.
*/
TC_DEPRECATED_NO_REPLACEMENT( "12.4", "GRM_create_relation_type")
extern TCCORE_API int GRM_create_relation_type(
    const char*         relation_type_name,     /**< (I) Name of relation type */
    tag_t*              relation_type           /**< (O) Tag of created relation type */
    );

/**
    Deletes a relation type from the system.
*/
extern TCCORE_API int GRM_delete_relation_type(
    tag_t               relation_type   /**< (I) Tag of relation type to be deleted */
    );

/** @} */

/**
    Creates a relation of the specified type and Copy Stable ID.

    <b>Restrictions:</b>

    The primary_object, secondary_object, and relation_type must all be valid tags.
    <br/>If the Copy Stable ID is NULL, a Copy Stable Id will be generated by the system.
    <br/>The user_data can be a #NULLTAG but if it is not a #NULLTAG, then it must be a valid tag.
    <br/>The user_data can be the tag of any valid POM object that the user wants to access through the GRM relation.
    <br/>To create the relation in the database, #GRM_save_relation must be called after this function.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#TYPE_unknown_type if the Relation type name is invalid.
    <li>#GRM_relation_already_exists if the Relation already exists between the primary and secondary.
    <li>#GRM_duplicate_copy_stable_relation if a Relation already exists for the primary with the copy stable id.
    </ul>
*/
extern TCCORE_API int GRM_create_copy_stable_relation(
    tag_t               primary_object,     /**< (I) Tag of primary object on the relation.        */
    tag_t               secondary_object,   /**< (I) Tag of secondary object on the relation.      */
    const char *        relation_type,      /**< (I) Name of the relation type.                    */
    tag_t               user_data,          /**< (I) Tag of the user data attached to the relation.*/
    const char *        copy_stable_id,     /**< (I) String Copy Stable Identifier                 */
    tag_t*              relation            /**< (O) Tag of the new relation.                     */
    );

/**
    Returns a list and count of all relations which satisfy the search criteria as defined by the input parameters.

    <b>Restrictions:</b>
    When a value is not supplied for an input paramenter it acts as a wildcard;
    <br/>for example, if the relation type is  #NULLTAG, all relation types will be returned.
    <br/>A value must be supplied for at least one of the input parameters.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#GRM_invalid_set_of_arguments if at least one of the input paramaters is not supplied.
    </ul>
*/
extern TCCORE_API int GRM_find_copy_stable_relations(
    tag_t               primary_object,     /**< (I) Tag of primary object on the relation.        */
    tag_t               secondary_object,   /**< (I) Tag of secondary object on the relation.      */
    const char*         copy_stable_id,     /**< (I) String Copy Stable Identifier                 */
    tag_t               relation_type,      /**< (I) Name of the relation type.                    */
    tag_t               user_data,          /**< (I) Tag of the user data attached to the relation.*/
    int*                count,              /**< (O) Number of relations matching the criteria.    */
    tag_t**             relation_list       /**< (OF) Tags of the relations matching the criteria  */
    );

#ifdef __cplusplus
}
#endif

#include <tccore/libtccore_undef.h>

#endif
