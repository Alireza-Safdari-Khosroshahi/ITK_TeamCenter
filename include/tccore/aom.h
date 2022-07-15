/*==============================================================================
  Copyright (c) 2003-2005 UGS Corporation
  Unpublished - All Rights Reserved
  ==============================================================================*/

/*  */

#ifndef AOM_H
#define AOM_H

#include <tc/tc_startup.h>

#include <tccore/workspaceobject.h>
#include <common/tc_deprecation_macros.h>

#include <tccore/libtccore_exports.h>

/**
    @file
*/

/**
   @defgroup AOM Application Object Module (AOM)
   @ingroup TC

   This module provides the implementation for load, unload, delete, and save for all persistent objects 
   that are identified through the POM tags.
     
   POM ITKs should not be used directly against the POM tags since the correspondence between the POM object
   and its C++ encapsulation can be broken (with unpredictable results). 

   @{
*/

#define AOM_archive_size_c     127
#define AOM_ixr_transactionid_size_c 1023
/** Define max VLA size as 4000-48(header) = 3952 */
#define AOM_max_VLA_size 3952

typedef struct AOM_export_info_entry_s
{
    tag_t      site;
    char       exporting_user[WSO_name_size_c+1];
    char       export_reason[WSO_desc_size_c+1];
    char       transaction_id[AOM_ixr_transactionid_size_c+1];
    date_t     last_export_date;
} AOM_export_info_entry_t;

typedef struct AOM_publication_info_entry_s
{
    tag_t      site;
    char       publishing_user[WSO_name_size_c+1];
    date_t     last_publication_date;
} AOM_publication_info_entry_t;

typedef enum AOM_sync_state_e
{
    AOM_SYNC_STATE_UP_TO_DATE                  = 1,
    AOM_SYNC_STATE_OUT_OF_DATE                 = 2,
    AOM_SYNC_STATE_REPLICA_HAS_LATER_DATE      = 3,
    AOM_SYNC_STATE_UNKNOWN                     = 4,
    AOM_SYNC_STATE_NOT_REPLICATED              = 5,
    AOM_SYNC_STATE_MASTER_DOES_NOT_EXIST       = 6,
    AOM_SYNC_STATE_UP_TO_DATE_PER_HUB          = 7,
    AOM_SYNC_STATE_UNKNOWN_OWNING_SITE         = 8,
    AOM_SYNC_STATE_REPLICA_HAS_BEEN_SUPERSEDED = 9,
    AOM_SYNC_STATE_NOT_A_REPLICA               = 10
} AOM_sync_state_t;

typedef enum AOM_sync_type_e
{
    OBJECT_SYNC         = 1,
    COMPONENT_SYNC      = 2,
    ASSEMBLY_SYNC       = 3
} AOM_sync_type_t;

#ifdef __cplusplus
extern "C"{
#endif

/**
   Initializes the AOM module. This module provides the implementation for load, unload, delete, and
   save for all applications that use POM tags as their means of identifying objects passed through the ITK interface.
*/
    extern TCCORE_API int AOM_init_module();

/**
   Shuts down the AOM module.
*/
    extern TCCORE_API int AOM_exit_module();

/**
   Loads an application object.
   This function loads the entire object as its actual class, if it is not already loaded.
   It is not entirely necessary to call this function since Teamcenter Engineering loads objects on demand;
   however, using this function is more efficient when loading several objects.
*/
    extern TCCORE_API int AOM_load(
        tag_t               obj     /**< (I) */
        );

/**
   Loads a set of application objects. This is more efficient than loading each object individually.
   
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#POM_invalid_tag if an object in @p objects is deleted.
   </ul>
*/
    extern TCCORE_API int AOM_load_instances(
        int                 n,              /**< (I) Number of objects to load. */
        tag_t*              objs,           /**< (I) Array of objects to load. */
        int*                n_loaded,       /**< (O) Number of objects that were successfully loaded. */
        tag_t**             objs_loaded     /**< (OF) n_loaded Array of objects that were successfully loaded. */
        );

/**
    Loads a set of application objects.
    <br/> This API will not return an error if @p n_objects is zero or if any object in @p objects is a #NULLTAG.

    @note Please use this API over #AOM_load_instances if already loaded instances needs to be returned along with the loaded instances.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_invalid_tag if an object in @p objects is deleted.
    </ul>
*/
    extern TCCORE_API int AOM_load_all_instances(
        int                 n_objects,          /**< (I) Number of objects to be loaded. */
        tag_t*              objects,            /**< (I) Array of objects to be loaded. */
        int*                n_objects_loaded,   /**< (O) Number of objects that were successfully loaded. */
        tag_t**             objects_loaded      /**< (OF) n_objects_loaded Array of objects that were successfully loaded.
                                                <br/>This array will also contain objects that were previously loaded from @p objects. */
        );

/**
   Reloads the in-memory representation of the object from the database.
   <br/>The tag does not change and any references to the object will still be valid.
   Any in-memory changes to the original object, since it was loaded, will be lost.
   If the object has been changed in the database since it was last loaded,
   those changes will now be present in memory:
   <ul>
   <li>If lock_flag is set to FALSE (0), a lock is not placed on the object.
   <br/>You can use this option to discard in memory edits that are no longer desired,
   or to update the in memory representation to reflect data base changes.
   <li>If lock_flag is set to TRUE (non 0), the object is reloaded as described above,
   and a write lock is obtained on the object.
   <br/>This is required if you wish to save a modified version of the object or delete it.
   </ul>

   #POM_modifiable can be called before #AOM_refresh if you want to avoid reloading an object
   that has already been loaded for modify. However, #AOM_refresh can frequently determine
   on its own whether a reload is actually necessary or not.

   A likely error would be that you are unable to obtain a write lock because somebody else already has it.
*/
    extern TCCORE_API int AOM_refresh(
        tag_t               obj,        /**< (I) */
        int                 lockFlag    /**< (I) */
        );

/**
   @deprecated #AOM_save deprecated in Teamcenter 11.2. Use #AOM_save_with_extensions or #AOM_save_without_extensions instead.

   Saves an application object to the database.

   <b>Restrictions:</b>
   Before calling save, the object must first be loaded or refreshed for modify.
*/
    TC_DEPRECATED( "11.2", "AOM_save", "AOM_save_with_extensions or AOM_save_without_extensions")
    extern TCCORE_API int AOM_save(
        tag_t               obj     /**< (I) */
        );

/**
   Saves the object and executes the PreCondition, PreAction and PostAction extensions if TC_save_msg is implemented on the type of the object;
   For example, this generic ITK will execute TC_save_msg on Item in the same way as ITEM_save_item does.

   <b>Restrictions:</b>
   Before calling save, the object must first be loaded or refreshed for modify.
*/
    extern TCCORE_API int AOM_save_with_extensions(
        tag_t               obj     /**< (I) */
        );

/**
   Saves the object and will not execute the PreCondition, PreAction and PostAction extensions even if TC_save_msg is implemented on the type of the object.

   <b>Restrictions:</b>
   <br/>Before calling save, the object must first be loaded or refreshed for modify.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#CXPOM_invalid_tag Invalid object tag provided.
   <li>#CXPOM_object_deleted The object tag provided already deleted.
   <li>#POM_inst_not_locked Object is not locked.
   <li>#POM_inst_in_use Object is already locked for modify.
   <li>#TCCORE_cannot_save_shadow_object The "Save" operation is not supported on the shadow object.
   <li>#TCCORE_cannot_save_transient_object The "Save" operation is not supported on the transient object.
   </ul>
*/
    extern TCCORE_API int AOM_save_without_extensions(
        tag_t               object  /**< (I) Tag of input object to save. */
        );

/**
   Removes an object from your local POM memory. You can reload the object later with the same tag if necessary.
*/
    extern TCCORE_API int AOM_unload(
        tag_t               obj     /**< (I) */
        );

/**
   Deletes an application object.
   Before deleting, the object must first be loaded or refreshed for modify.
   The object can be unloaded automatically if necessary.
*/
    extern TCCORE_API int AOM_delete(
        tag_t               obj     /**< (I) */
        );

/**
   #AOM_delete_from_parent is the same as #AOM_delete, but cuts it from parent first.
   Parent may be folder, Item or ItemRev.
*/
    extern TCCORE_API int AOM_delete_from_parent(
        tag_t               obj,        /**< (I) */
        tag_t               parent      /**< (I) */
        );

/**
   #AOM_describe_class is similar to POM_describe_class but will hide attributes for
   internal use only.
*/
    extern TCCORE_API int AOM_describe_class
    ( tag_t             class_id,          /**< (I) */
      int               n_names,           /**< (I) */
      char **           attr_names,        /**< (I) n_names */
      char **           application_name,  /**< (OF) */
      int *             descriptor,        /**< (O) */
      int *             n_attrs,           /**< (O) */
      tag_t **          attr_ids           /**< (OF) */
        );


    extern TCCORE_API int AOM_register_localized_attribute
    ( tag_t         class_id,           /**< (I) */
      tag_t         source_att,         /**< (I) */
      tag_t         target_att          /**< (I) */
        );


#ifdef __cplusplus
}
#endif

/**
   Unlocks an object for modification by another process.
*/
#define AOM_unlock(t)           (AOM_refresh(t,FALSE))

#ifdef __cplusplus
extern "C"{
#endif

/**
   Locks an object against modification by another process.
   This is similar to calling AOM_refresh(object, TRUE)
   except that this function does not reload the object if it already has a lock (as #AOM_refresh would).
*/
    extern TCCORE_API int AOM_lock(
        tag_t               obj     /**< (I) */
        );

    extern TCCORE_API int AOM_lock_for_delete(
        tag_t               obj     /**< (I) */
        );

/**
   Freezes an object so that all of its freezable attributes can no longer be modified.
*/
    extern TCCORE_API int AOM_freeze(
        tag_t               obj     /**< (I) */
        );

/**
   Unfreezes an object so that all of its freezable attributes can be unfrozen and modified.
*/
    extern TCCORE_API int AOM_unfreeze(
        tag_t               obj     /**< (I) */
        );

/**
   Inquires whether an object is frozen or not.
   If the object is frozen, then answer is set to TRUE, otherwise answer is set to FALSE.
*/
    extern TCCORE_API int AOM_ask_if_frozen(
        tag_t               obj,        /**< (I) */
        logical*            frozen      /**< (O) */
        );

/**
   Sets the user and group ownership for the object.

   @warning When you change ownership on a dataset then all versions of that dataset and all
   #AE_PART_OF named references will have their ownership changed as well.
*/
    extern TCCORE_API int AOM_set_ownership(
        tag_t               obj,    /**< (I) */
        tag_t               user,   /**< (I) */
        tag_t               group   /**< (I) */
        );

/**
   Retrieves the owning user for the object.
*/
    extern TCCORE_API int AOM_ask_owner(
        tag_t               obj,            /**< (I) */
        tag_t*              owning_user     /**< (O) */
        );

/**
   Retrieves the owning group for the object.
*/
    extern TCCORE_API int AOM_ask_group(
        tag_t               obj,            /**< (I) */
        tag_t*              owning_group    /**< (O) */
        );

/**
   Retrieves the last user to modify this object.
*/
    extern TCCORE_API int AOM_ask_last_modifier(
        tag_t               obj,        /**< (I) */
        tag_t*              a_user      /**< (O) */
        );

/**
   Retrieves the creation date of the object.
*/
    extern TCCORE_API int AOM_ask_creation_date(
        tag_t               obj,            /**< (I) */
        date_t*             creation_date   /**< (O) */
        );

/**
   Retrieves the date on which the object was last modified.
*/
    extern TCCORE_API int AOM_ask_modified_date(
        tag_t               obj,            /**< (I) */
        date_t*             modified_date   /**< (O) */
        );

/**
   Retrieves the date on which the object was last backed up.
*/
    extern TCCORE_API int AOM_ask_backup_date(
        tag_t               obj,            /**< (I) */
        date_t*             backup_date     /**< (O) */
        );


/**
   Retrieves a string containing information on archived data associated with this object.
*/
    extern TCCORE_API int AOM_ask_archive_info2(
        tag_t               obj,                                    /**< (I) */
        char                **archive_info                          /**< (OF) */
        );


/**
   Asks for the archive date of an object.
*/
    extern TCCORE_API int AOM_ask_archive_date2 (
        tag_t               object_tag,                         /**< (I) */
        char                **date_string                       /**< (OF) */
        );

/**
   Inquires whether an object is archived or not.
   If the object is archived, then answer is set to TRUE, otherwise answer is set to FALSE.
*/
    extern TCCORE_API int AOM_is_archived (
        tag_t               object_tag,     /**< (I) */
        logical*            answer          /**< (O) */
        );

/**
   Retrieves export information about the specified object.
   The export information is basically the data stored in a Teamcenter Engineering Export Record
   (one for each site the object was exported to), which consists of the following:
   <ul>
   <li>The tag of the site the object was exported to
   <li>The user ID of the user who performed the last export
   <li>The reason, if any, for exporting the object to the site
   <li>The date when the object was last exported to the site
   </ul>

   <b>Restrictions:</b>
   The specified object must be a workspace object.
   This function will return export information only if run at the site that owns the specified object.
   If run at a non-owning site, a successful status will be returned and a zero value returned for n_export_info.
*/
    extern TCCORE_API int AOM_get_export_info(
        tag_t                       object_tag,     /**< (I) Tag of the exported object. */
        int*                        n_export_info,  /**< (O) Number of sites the object was exported to. */
        AOM_export_info_entry_t**   export_info     /**< (OF) n_export_info Array of structures containing
                                                       the actual export information. */
        );

/**
   Retrieves publication information about the specified object.
   The publication information is basically the data stored in a Publication Audit Record
   (one for each site the object was published to), which consists of the following:
   <ul>
   <li>The tag of ODS site the object was published to
   <li>The user ID of the user who performed the last publication or re-publication
   <li>The date when the object was last published or republished to the site
   </ul>

   <b>Restrictions:</b>
   The specified object must be a workspace object.
   <br/>This function will return publication information only if run at the site that owns the specified object.
   <br/>If run at a non-owning site, a successful status will be returned and a zero value will returned for n_publish_info.
*/
    extern TCCORE_API int AOM_get_publication_info(
        tag_t                           object_tag,             /**< (I) Tag of the published object. */
        int*                            n_publication_info,     /**< (O) Number of ODS sites object was published to. */
        AOM_publication_info_entry_t**  publication_info        /**< (OF) n_publication_info Array of structures containing
                                                                   the actual publication information. */
        );

    extern TCCORE_API int AOM_ask_if_modifiable(
        tag_t               object_tag,     /**< (I) */
        logical*            verdict         /**< (O) */
        );

    /**
    Retrieves the name of @p obj.

    If the name for the business object is not defined, an empty name will be returned.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_invalid_tag if @p obj is an instance of Runtime Business Object.
    </ul>
    */
    extern TCCORE_API int AOM_ask_name(
        tag_t               obj,    /**< (I) The business object. */
        char**              name    /**< (OF) The name of the business object.*/
        );

/**
   Retrieves a flag that indicates if the type of a given object is or is a subtype of a given type tag.
   The answer is TRUE if the object type of the given object tag is type_tag or is a subtype of type_tag.
*/
    extern TCCORE_API int AOM_is_type_of(
        tag_t     object_tag,          /**< (I) Tag of an object. */
        tag_t     type_tag,            /**< (I) tag of a type object */
        logical * answer               /**< (O) A flag indicating if the object type of the given object (object_tag)
                                          is or is a subtype of the given type object (type_tag).
                                       */
        );

    extern TCCORE_API int AOM_check_sync_state(
        int                 n_replicas,     /**< (I)  Number of replica objects to check.     */
        tag_t*              replica_tags,   /**< (I)  Tags of replica objects to check.       */
        int**               owning_site_ids,/**< (OF) n_replicas Array of owning sites        */
        AOM_sync_state_t**  sync_state,     /**< (OF) n_replicas Array of sync state returns. */
        date_t**            master_lmd,     /**< (OF) n_replicas Array of master site last mod dates. */
        date_t**            replica_lmd,    /**< (OF) n_replicas Array of replica site last mod dates.  */
        int**               error_codes     /**< (OF) n_replicas Array of error codes.  */
        );

    extern TCCORE_API int AOM_ask_import_record(
        tag_t   object_tag,             /**< (I) Tag of an object. */
        tag_t *import_record            /**< (O)Tag of Import Record */
        );

    extern TCCORE_API int AOM_ask_import_record_associated_object(
        tag_t import_record,            /**< (I) Tag of an import record. */
        tag_t *obj_tag                  /**< (O) Tag of an object. */
        );

/**
   Changes the search mode of POM enquiries whenever searching text on localized attributes, in order to be able to use the current logged-in locale instead of the master locale.
   @note When applications are done with using the logged-in locale, the mode should be reverted to @c false.
   @returns #ITK_ok always.
*/
    extern TCCORE_API int AOM_set_query_rewrite_mode
    (
        logical mode        /**< (I) Mode for the search.
                            <ul>
                            <li>@c true: the search on localized attributes will be done using the current logged-in locale
                            <li>@c false: the search will be done on the master locale data.
                            </ul> */
        );

/**
   Retrieves the value of the mode set by #AOM_set_query_rewrite_mode ITK.
   @returns #ITK_ok always.
*/
    extern TCCORE_API int AOM_ask_query_rewrite_mode
    (
        logical *mode  /**< (O) logical to show if query rewrite has been enabled/disabled. */
        );

/**
   Instructs POM enquiry to search text on a localized attribute in all locales/translations other than the master locale.
   @returns #ITK_ok always.
 */
    extern TCCORE_API int AOM_set_query_locale_neutral
    (
        logical mode        /**< (I) Mode for the search.
                            <ul>
                            <li>@c true: the search will be done on the localized text.
                            <li>@c false: the search is done on the master locale.
                            </ul> */
        );

/**
   Retrieves the value of the mode set by #AOM_set_query_locale_neutral ITK
   @returns #ITK_ok always.
*/
    extern TCCORE_API int AOM_ask_query_locale_neutral
    (
        logical *mode /**< (O) logical to indicate whether this query is locale neutral and will search ALL locales */
        );

/**
   @deprecated #AOM_bulk_save_instances deprecated in Teamcenter 11.2. Use #AOM_bulk_save_instances_partial_errors instead
   for bulk save on update.
   <br/>Use #TCTYPE_bulk_create_objects_with_error_details instead for bulk create, which will also perform
   save and unlock for the created objects.

   Saves the input business objects in bulk through a single transaction.

   @note Objects to be saved must be loaded or refreshed for modify.
*/
TC_DEPRECATED("11.2", "AOM_bulk_save_instances", "AOM_bulk_save_instances_partial_errors")
extern TCCORE_API int AOM_bulk_save_instances(
    int             n_instances,    /**< (I) Number of instances to be saved in bulk. */
    const tag_t*    instances       /**< (I) n_instances Instances to be saved in bulk. */
);

/**
    Saves the input objects.

    If all input objects implement fnd0Save (and @c isSaveRefactoredAsSetBased
    returns @c true), then the save will be completed in a single transaction.
    Otherwise, each object will be saved individually.

    @note Objects to be saved must be loaded or refreshed for modify.

    @note If, while processing the input objects, additional objects are to be saved, deleted or unlocked, these
    additional objects must also support the set-based operation required (e.g. fnd0BulkDelete, fnd0Unlock) for
    all processing to be completed in a single transaction.

    @note Do not use with #TCTYPE_create_object or #TCTYPE_create_objects. For bulk create, use
    #TCTYPE_bulk_create_objects_with_error_details, which also performs save and unlock for the created objects.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ITK_internal_error if @p n_objects is zero or a negative number.
    <li>#ITK_internal_error if @p objects is NULL.
    </ul>
 */
extern TCCORE_API int AOM_bulk_save_instances_partial_errors(
    const int       n_objects,      /**< (I) Number of objects to be saved. */
    const tag_t*    objects,        /**< (I) n_objects Objects to be saved. */
    int**           error_codes,    /**< (OF) n_objects Error codes returned for each object:
                                    <ul>
                                    <li>#ITK_ok if the save completed for that object.
                                    <li>#CXPOM_invalid_tag Invalid object tag provided.
                                    <li>#POM_inst_not_locked Object is not locked.
                                    </ul> */
    char***         error_messages  /**< (OF) n_objects Error messages for errors returned.
                                    <br/>The memory for this packed array must be deallocated by calling #MEM_free on the container. */
);

/**
   @defgroup DIGITAL_SIGNATURE Digital Signature Feature

   Digital Signature feature enables user to manually review an object and set the object as being digitally signed.
   <br/>The digital signature captures the user�s name, timestamp, and requires PKI card authentication.
   <br/>This feature is supported for Business Objects that extend from POM_applciation_object or its sub classes.
   An object can have multiple digital signatures applied by users having the required Access Manager privileges.

   This module provides the implementation for the following use cases:
   <ul>
   <li>applying digital signature
   <li>void digital signatures on an object that is digitally signed
   <li>verify the state of digital signatures on a given object
   </ul>

   This module supports logging of audit events for Apply, Void, Verify and Delete actions.

   @{
*/

/**
   Performs the Apply Digital Signature operation on an object using an
   encrypted message (key).

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#AOM_ds_failed_apply_privilege if the user does not have DIGITAL_SIGN privilege on the  Workspace Object.
   <li>#AOM_ds_not_supported if the Digital Signature feature is not supported on the  Workspace Object.
   <li>#AOM_valid_ds_exists if the Workspace Object already contains a valid Digital Signature object.
   <li>#AOM_ds_invalid_input if invalid or insufficient inputs have been provided for the creation of a Digital Signature object.
   </ul>
*/
    extern TCCORE_API int AOM_apply_digital_signature(
        tag_t               object_tag,            /**< (I) The target object specified to apply the Digital Signature(DS).*/
        const char *        encrypt_string         /**< (I) The encrypted message (key) used to apply the Digital Signature. */
        );


/**
   Retrieves the total number of valid and void  Digital Signature (DS) objects and the Digital Signature states
   on the specified target objects.
   <br/>For a given target object, Digital Signature state is the combined state of all
   Digital Signatures on the target object.
   <br/>The Digital Signature States are None (1), Valid (2), InValid (4), Void (8) and Revoked (16).

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#CXPOM_invalid_tag if the specified object is NULL or incorrect.
   </ul>
*/
    extern TCCORE_API int AOM_verify_digital_signatures(
        int              n_target_objects,           /**< (I) Number of target objects to verify DS states.*/
        const tag_t*     target_objects,             /**< (I) n_target_objects Array of target objects specified.*/
        int**            num_valid_ds,               /**< (OF) n_target_objects Array of valid Digital Signature objects. */
        int**            num_void_ds,                /**< (OF) n_target_objects Array of void Digital Signature objects. */
        int**            num_total_ds,               /**< (OF) n_target_objects Array of all Digital Signature objects. */
        int**            digital_signature_states    /**< (OF) n_target_objects Array of Digital Signature objects states. */
        );



/**
   Voids the specified Digital Signatures on a given object.
   
   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#CXPOM_invalid_tag if the specified object is NULL or incorrect.
   <li>#AOM_ds_failed_void_privilege if the current user does not have VOID_DIGITAL_SIGN privilege on the specified object.
   <li>#AOM_ds_void_allowed_in_rootobj_context if the current user tries to void a Digital Signature on an object in a context different from its root object.
   </ul>
*/
    extern TCCORE_API int AOM_void_digital_signature(
        tag_t              target_object,          /**< (I) The object on which to void the Digital Signature objects.*/
        const char*        comment,                /**< (I) Comments attached to void operation.  */
        int                n_digital_signature,    /**< (I) Number of DS objects to be voided. */
        const tag_t*       digital_signatures      /**< (I) n_digital_signature Array of Digital Signatures to be voided.*/
        );


/** @} */ /*   */


/**
   @defgroup TABLE_PROPERTIES Table Properties Feature
   @ingroup AOM

   Table Properties provide the ability to manage an array of information/data in tabular manner.
   <ul>
   <li>A full table property consists of rows. The number of rows can vary per business object instance.
   <li>Each row consists of defined columns. Each column is defined as a property
   <li>A full table property is managed like other properties on the business object
   </ul>

   @{
*/

/**
   Retrieves the table row corresponding to the input row index.
   <br/>This function uses #PROP_ask_value_tag_at_msg for the table property.
   <br/>To customize the behavior of this function, register a method against this message name.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PROP_invalid_value if the input arguments are incorrect
   <li>#PROP_invalid_index if the @p row_index is not within the range.
   <li>#PROP_null_input_not_allowed if valid @p owning_object or @p table_property_name is not provided
   </ul>
*/
    extern TCCORE_API int AOM_ask_table_row(
        tag_t               owning_object,             /**< (I) Unique identifier (tag) of the owning object. */
        const char*         table_property_name,       /**< (I) Table property name. */
        int                 row_index,                 /**< (I) Specified row index to be retrieved from table rows. */
        tag_t*              table_row                  /**< (O) Table row object tag for the specified row index. */
        );


/**
   Retrieves the table rows for a given table property.
   <br/>This function uses PROP_ask_value_tags_msg. To customize the behavior of this function, register a method against this message.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PROP_invalid_value if the input arguments are incorrect
   <li>#PROP_null_input_not_allowed if valid @p owning_object or @p table_property_name is not provided
   </ul>
*/
    extern TCCORE_API int AOM_ask_table_rows(
        tag_t               owning_object,             /**< (I) Unique identifier (tag) of the owning object. */
        const char*         table_property_name,       /**< (I) Table property name. */
        int*                n_table_rows,              /**< (O) Number of table rows. */
        tag_t**             table_rows                 /**< (OF) n_table_rows Array of Table Row objects. */
        );


/**
   Retrieves the table rows for a specified range for a given table property.
   <br/>This function uses PROP_ask_value_tags_msg. To customize the behavior of this function, register a method against this message.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PROP_invalid_value if the input arguments are incorrect
   <li>#PROP_invalid_index if the @p row_index is not within the range.
   <li>#PROP_null_input_not_allowed if valid @p owning_object or @p table_property_name is not provided
   </ul>
*/
    extern TCCORE_API int AOM_ask_table_rows_range(
        tag_t               owning_object,              /**< (I) Unique identifier (tag) of the owning object. */
        const char*         table_property_name,        /**< (I) Table property name. */
        int                 start_row_index,            /**< (I) Specified start row index to retrieve the range of table rows. */
        int                 num_table_rows,             /**< (I) Number of table rows to retrieve. */
        tag_t**             table_rows                  /**< (OF) num_table_rows Array of Table Row objects. */
        );


/**
   Sets the table row object tags for the table property.
   <br/>The input list of objects are stored for the current property and existing objects that are not available in the input are deleted.
   <br/>Note that Table Row indices are consecutive like array indices.
   <br/>This function uses #PROP_set_value_tags_msg.
   <br/>To customize the behavior of this function, register a method against this message name.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PROP_invalid_value if the input list does not contain valid table rows
   <li>#PROP_invalid_input_object if valid @p owning_object or @p table_property_name is not provided
   <li>#PROP_invalid_table_prop_for_table_row if @p table_property_name does not correspond to a table property
   <li>#POM_inst_not_locked if the @p owning_object is not locked
   <li>#PROP_null_input_not_allowed if @p owning_object or @p table_property_name is not provided
   </ul>
*/
    extern TCCORE_API int AOM_set_table_rows(
        tag_t               owning_object,             /**< (I) Unique identifier (tag) of the owning object. */
        const char*         table_property_name,       /**< (I) Table property name. */
        int                 num_table_rows,            /**< (I) Number of table rows. */
        const tag_t*        table_row                  /**< (I) num_table_rows Array of Table Row objects. */
        );


/**
   Creates new table row objects from the specified index and re-indexes the remaining table row objects.
   <br/>If index is specified as 0 it creates the table row objects starting at the index 0 and re-indexes the remaining table row objects.
   <br/>If the specified index is equal to table rows length then it appends at the end.
   <br/>This function uses create operation to create the table row objects.
   <br/>To customize the behavior of this function, register a method against the create operation.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PROP_invalid_value if the input arguments are incorrect
   <li>#PROP_invalid_index if the @p row_index is not within the range.
   <li>#PROP_invalid_input_object if valid @p owning_object or @p table_property_name is not provided
   <li>#PROP_invalid_table_prop_for_table_row if @p table_property_name does not correspond to a table property
   <li>#POM_inst_not_locked if the @p owning_object is not locked
   <li>#PROP_null_input_not_allowed @p owning_object or @p table_property_name is not provided
   </ul>
*/
    extern TCCORE_API int AOM_insert_table_rows(
        tag_t               owning_object,              /**< (I) Unique identifier (tag) of the owning object. */
        const char*         table_property_name,        /**< (I) Table property name. */
        int                 insert_at_row_index,        /**< (I) Table row objects to be inserted from this row index. */
        int                 num_rows_to_insert,         /**< (I) The number of table row objects to be inserted. */
        tag_t**             table_rows                  /**< (OF) num_rows_to_insert Array of Table Row objects inserted. */
        );


/**
   Creates a new table row objects at the end of table. Note that Table Row indices are consecutive like array indices.

   <br/>This function uses  create operation to create the table row object.
   <br/>To customize the behavior of this function, register a method against the create operation.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PROP_invalid_value if the input arguments are incorrect
   <li>#PROP_invalid_input_object if valid @p owning_object or @p table_property_name is not provided
   <li>#PROP_invalid_table_prop_for_table_row if @p table_property_name does not correspond to a table property
   <li>#POM_inst_not_locked if the @p owning_object is not locked
   <li>#PROP_null_input_not_allowed @p owning_object or @p table_property_name is not provided
   </ul>
*/
    extern TCCORE_API int AOM_append_table_rows(
        tag_t               owning_object,             /**< (I) Unique identifier (tag) of the owning object .*/
        const char*         table_property_name,       /**< (I) Table property name. */
        int                 num_rows_to_append,        /**< (I) The number of table row objects to be appended. */
        int*                row_index,                 /**< (O) Index of the last table row object that was appended. */
        tag_t**             table_rows                 /**< (OF) num_rows_to_append Array of Table Row objects appended. */
        );


/**
   Deletes the table row objects starting at the specified index.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#PROP_invalid_value if the input arguments are incorrect
   <li>#PROP_invalid_input_object if valid @p owning_object or @p table_property_name is not provided
   <li>#PROP_invalid_index if the @p delete_from_row_index is not within the range.
   <li>#POM_inst_not_locked if the @p owning_object is not locked
   <li>#PROP_null_input_not_allowed @p owning_object or @p table_property_name is not provided
   </ul>
*/
    extern TCCORE_API int AOM_delete_table_rows(
        tag_t               owning_object,              /**< (I) Unique identifier (tag) of the owning object. */
        const char*         table_property_name,        /**< (I) Table property name. */
        int                 delete_from_row_index,      /**< (I) Table row objects to be deleted from this row index. */
        int                 num_rows_to_delete          /**< (I) The number of table row objects to be deleted. */
        );

/** @} */ /*   */

/**
   Refreshes the business objects in bulk through a single transaction.

   @note Object-specific errors are returned through the @p refresh_status parameter.

   @returns #ITK_ok always.
*/
    extern TCCORE_API int AOM_refresh_objects_in_bulk (
        int            n_object_tags,                  /**< (I) Number of objects to be refreshed. */
        const tag_t    *object_tags,                   /**< (I) n_object_tags Array of objects being refreshed */
        logical        lock_flag,                      /**< (I) The lock to apply to the refreshed objects: false (read only), true (read/write)  */
        int            **refresh_status                /**< (OF) n_object_tags Array of refresh statuses. <br/>The values are #ITK_ok on success, and any other error code on error. */
        );

/**
   Deletes an object and executes the PreCondition, PreAction and PostAction extensions if TC_delete_msg is implemented on the type of the object.
   <br/>For example, this generic ITK will execute TC_delete_msg on Item in the same way as ITEM_delete_item does.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#CXPOM_invalid_tag if the specified object is NULL or incorrect.
   <li>#ITEM_unable_to_delete when the object is an ItemRevision that cannot be deleted for any reason.
   <li>#AE_cannot_delete_dataset when the object is a Dataset that cannot be deleted for any reason.
   <li>Other error codes may be returned by the class method registered for object types other than ItemRevision and Dataset or customization.
   </ul>
*/
    extern TCCORE_API int AOM_delete_with_extensions(
        tag_t               object     /**< (I) The object to delete.*/
        );

/**
  Deletes the business objects in bulk through a single transaction.

  @returns
  <ul>
  <li>#ITK_ok on success.
  <li>#ITK_internal_error if @p n_instances is zero or a negative number.
  </ul>
*/
    extern TCCORE_API int AOM_bulk_delete_instances(
        const int       n_instances,    /**< (I) Number of objects to be deleted in bulk.*/
        const tag_t*    instances,      /**< (I) n_instances Instances to be deleted in bulk.*/
        int**           ifails          /**< (OF) n_instances Status codes for the deletion of each instance.
                                           <br/>Values are:
                                           <ul>
                                           <li>#ITK_ok if the instance was deleted.
                                           <li>#ITEM_unable_to_delete if the instance cannot be deleted for any reason.
                                           </ul> */
        );

    /**
    Refresh objects in bulk through a single transaction.
    <br/>If all input objects implement fnd0Refresh, then the refresh will be completed in a single transaction.
    Otherwise, each object will be refreshed individually.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ITK_internal_error if @p n_objects is zero or a negative number.
    </ul>
 */
    extern TCCORE_API int AOM_bulk_refresh_instances_partial_errors(
        const int       n_objects,      /**< (I) Number of objects to be refreshed. */
        const tag_t*    objects,        /**< (I) n_objects Objects to be refreshed. */
        int**           error_codes,    /**< (OF) n_objects Error codes returned for each object:
                                        <ul>
                                        <li>#ITK_ok if the save completed for that object.
                                        <li>#CXPOM_invalid_tag if null object tag is provided.
                                        <li>#POM_invalid_tag if an invalid object tag is provided.
                                        </ul> */
        char***         error_messages  /**< (OF) n_objects Error messages for errors returned.
                                        <br/>The memory for this packed array must be deallocated by calling #MEM_free on the container. */
    );


#ifdef __cplusplus
}
#endif

/** @} */ /*   */

#include <tccore/libtccore_undef.h>

#endif
