/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2014.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software */


/**
    @defgroup BO BusinessObject (Metaframework)
    @ingroup TC

    Teamcenter has implemented ITK level functions that allow programmers
    to register and recover Teamcenter business objects. Those business objects
    are stored in a registry (cache) of recoverable business objects.

    The ITK functions for session recovery include:
    <ul>
    <li>A function to retrieve a business object so it can be recovered later.
    <li>A function to determine if a business object is recoverable.
    <li>A function to retrieve the tag of a recoverable business object.
    <li>A function to retrieve the UID of a recoverable business object.
    </ul>

    To use these functions, include session_recovery.h.
    @{
*/

#ifndef SESSION_RECOVERY_H
#define SESSION_RECOVERY_H

#include <unidefs.h>

#include <metaframework/libmetaframework_exports.h>

/**
A Reconstruct function pointer for recoverable business objects registered by BO_register_recoverable_business_object.
*/
typedef int(*ReconstructFn)(
    const char *  recipe,       /**< (I)  Recipe for reconstruction the recoverable business object */
    tag_t *       bus_obj_tag   /**< (I)  Recipe for reconstruction the recoverable business object */
    );

/**
A Get Recoverable key function pointer for recoverable business objects registered by BO_register_recoverable_business_object
*/
typedef char *(*RecoverableKeyFn)(
    const char *  recipe_uid  /**< (I)  UID of the recipe */
    );

#ifdef __cplusplus
    extern "C"{
#endif


/**
    Retrieves the tag associated with the uid of a recoverable object. The @p uid must be formatted
    for server usage only, e.g. a version output by #BO_get_recoverable_object_uid.
    
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_op_not_supported if the @p uid is null.
    <li>#POM_component_id_not_found if there is no recipe for the @p uid.
    <li>#ITK_internal_error if other errors occur. Check the Teamcenter system log for more information.
    </ul>
*/
extern METAFRAMEWORK_API int BO_get_recoverable_object_tag(
    const char *  uid,            /**< (I) UID of object to recover */
    logical       persist_recipe, /**< (I) Indicates if the recipe should be persisted to the db */
    tag_t *       tag             /**< (O) Tag of recoverable object */
);

/**
    Finds a recoverable object tag in the runtime cache. The @p uid must be formatted
    for server usage only, e.g. a version output by #BO_get_recoverable_object_uid.

    <br/>If no tag can be found using the @p uid, no object is created. If the object
    needs to be created, use #BO_get_recoverable_object_tag. 

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_op_not_supported if the @p uid value is null.
    <li>#POM_component_id_not_found if there is no recipe for the @p uid.
    <li>#ITK_internal_error if other errors occur.  Check the Teamcenter system log for more information.
    </ul>
*/
extern METAFRAMEWORK_API int BO_lookup_recoverable_object_tag(
    const char *  uid,                /**< (I) UID of object to recover */
    logical       persist_recipe,     /**< (I) Indicates if the recipe should be persisted to the db */
    tag_t *       tag                 /**< (O) Tag of recoverable object */
);

/**
    Retrieves the uid associated with a recoverable object. This uid is suitable for usage on
    the server only and will be formatted for session recovery if the object is session recoverable.

    <br/>If a uid that is valid for round trips between the server and client is required, please use 
    #BO_get_recoverable_object_uid_stateless.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#TYPE_unknown_type if @p bus_obj_tag is of an unknown type.
    <li>#ITK_internal_error if an internal error has occurred.  Check the Teamcenter system log for more information.
    </ul>
*/
extern  METAFRAMEWORK_API int BO_get_recoverable_object_uid(
    tag_t         bus_obj_tag,     /**< (I) The tag of a Teamcenter business object */
    logical       persist_recipe,  /**< (I) Indicates if the recipe should be persisted to the database */
    char**        uid              /**< (OF) The UID for the input Teamcenter business object */
);

/**
    Retrieves the tag associated with the UID of a recoverable object. The input @p uid
    must be formatted for server and client usage, e.g. a version output by
    #BO_get_recoverable_object_uid_stateless.

    <br/>An empty @p uid will not cause an error and will output a #NULLTAG.
    
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#ITK_internal_error if the @p uid is null or other internal errors occurred. Check the Teamcenter system log for more information.
    <li>#METAFRAMEWORK_smartuid_unsupported_version if the @p uid provided is not properly formatted.
    </ul>
*/
extern METAFRAMEWORK_API int BO_get_recoverable_object_tag_stateless(
    const char *  uid,    /**< (I) UID of object to recover */
    tag_t *       tag     /**< (O) The recoverable object */
);

/**
    Retrieves the uid associated with a business object that is suitable for round trips between the
    server and a stateful client. If the object is session recoverable, the uid is valid for round trips 
    between the server and both stateful or stateless clients.

    <br/>A NULLTAG input will not cause any error and will produce an ouput UID that is an empty string.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#TYPE_unknown_type if @p business_object is of an unknown type.
    <li>#ITK_internal_error if other errors occur. Check the Teamcenter system log for more information.
    </ul>
*/
extern  METAFRAMEWORK_API int BO_get_recoverable_object_uid_stateless(
    const tag_t   business_object, /**< (I) A Teamcenter business object */
    char **       uid              /**< (OF) The UID for the input Teamcenter business object */
);

/**
    Retrieves the uid associated with a recoverable object. This uid is suitable for usage on
    the server only and should be formatted as session-recoverable UID by the caller.
    This uid will always be cached in the object.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#TYPE_unknown_type if @p bus_obj_tag is of an unknown type.
    <li>#ITK_internal_error if an internal error has occurred.  Check the Teamcenter system log for more information.
    </ul>
*/
extern  METAFRAMEWORK_API int BO_get_recoverable_object_uid_cached(
    tag_t         bus_obj_tag,     /**< (I) The tag of a Teamcenter business object */
    logical       persist_recipe,  /**< (I) Indicates if the recipe should be persisted to the database */
    char**        uid              /**< (OF) The UID for the input Teamcenter business object */
);

/**
    Checks whether the business object is recoverable and whether or not the recipe is persisted to the database.
    
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ITK_internal_error if an internal error has occurred. Check the Teamcenter system log for more information.
    </ul>
*/
extern METAFRAMEWORK_API int BO_is_recoverable(
    tag_t         obj_tag,        /**< (I) The tag of the Teamcenter object */
    logical *     is_recoverable, /**< (O) True if the object is recoverable.  False if it is not. */
    logical *     persist_recipe  /**< (O) Indicates whether the recipe should be persisted to the DB */
);


/**
    Registers a business object class for recovery.
    
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#METAFRAMEWORK_invalid_BusinessObject if the input name is not a valid Business Object name
    </ul>
*/
extern METAFRAMEWORK_API int BO_register_recoverable_business_object(
    const char *      name,        /**< (I)  Name to Register */
    ReconstructFn     fn,          /**< (I)  Funtion pointer to the function used to recover the Teamcenter BusinessObject */
    RecoverableKeyFn  key_function /**< (I) Function pointer to the recoverable Key function. */
);


/**
    Removes an entry corresponding to @p uid if present in the cache of recoverable business objects.
    The @p uid may be formatted for server usage (e.g. a version output by #BO_get_recoverable_object_uid
    or #BO_get_recoverable_object_uid_cached) or for round-trip usage (e.g. a version output by
    #BO_get_recoverable_object_uid_stateless).
    
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ITK_internal_error if other errors occur. Check the Teamcenter system log for more information.
    </ul>
*/
extern METAFRAMEWORK_API int BO_remove_recoverable_business_object(
    const char*   uid    /**< (I) UID of business object to be removed. */
);

/** @} */

#ifdef __cplusplus
}
#endif

#include <metaframework/libmetaframework_undef.h>
#endif
