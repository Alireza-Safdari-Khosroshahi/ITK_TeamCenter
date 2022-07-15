/*==============================================================================
                Copyright (c) 2003-2005,2008 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the interface to Teamcenter types.
    These are similar to the EXPRESS notion of defined data type.
*/

/*  */

#ifndef TCTYPE_H
#define TCTYPE_H

#include <property/prop.h>
#include <tccore/tctype_msg.h>
#include <user_exits/user_exits.h>
#include <common/tc_deprecation_macros.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup TCTYPE Teamcenter Types
    @ingroup TC

    A type represents some object in the user's business environment.
    <br/>Some examples are: Part, Equipment, Employee.
    <br/>In Teamcenter, a type is implemented by a class.
    <br/>Some common Teamcenter classes are: Item, Form, and Person.
    <br/>This section describes the ITK interface for types.

    <br/>A type can have properties and methods which define it and dictate its behavior.
    <br/>Go to Properties and Methods for additional information.

    <br/>By default, a type implemented by a class will have a property for each class attribute.
    <br/>Any of those properties can be removed from the type and additional properties can be added to the type.
    <br/>Those additional properties can be:
    <table>
    <tr><td>run-time</td><td>Value is derived at run-time.       </td></tr>
    <tr><td>relation</td><td>Implemented by an TcRelation.     </td></tr>
    <tr><td>compound</td><td>Uses a property from another object.</td></tr>
    </table>
    @{
*/

#define TC_set_id_msg                 "IMAN_set_id"
#define TC_set_name_msg               "IMAN_set_name"
#define TC_set_description_msg        "IMAN_set_description"
#define TC_set_type_msg               "IMAN_set_type"
#define TC_set_type_directly_msg      "IMAN_set_type_directly"

/** @if DOX_IGNORE
    (brk) 20-feb-1994
    The following are manifest constants for storage size in bytes of various
    small strings that can be returned by this module.
    NOTE they should be well correlated with WSO_name_size_c and POM_MAX_NAME_LENGTH
@endif */

#define TCTYPE_name_size_c            32
#define TCTYPE_class_name_size_c      27

/** @if DOX_IGNORE
    The following macros are added for update list use
@endif */

/**
    This is used to enable client server update list.
*/
#define TCTYPE_DISABLE_UPDATE_LIST    0
#define TCTYPE_ENABLE_UPDATE_LIST     1
#define TCTYPE_SUSPEND_UPDATE_LIST    2
#define TCTYPE_RESUME_UPDATE_LIST     3

/**
    This is used to indicate all loaded properties needs to be processed.
*/
#define TCTYPE_UPDATE_ALL_PROPS       "_update_all_"

typedef enum TCTYPE_display_e {
    TCTYPE_DISPLAYABLE=0,          /**< Type is displayable. */
    TCTYPE_HIDDEN_AT_SYSTEM_LEVEL, /**< Type is hidden at System level */
    TCTYPE_HIDDEN_AT_SITE_LEVEL,   /**< Type is hidden at Site level */
    TCTYPE_HIDDEN_AT_PARENT_LEVEL, /**< Type is hidden at Parent level */
    TCTYPE_HIDDEN_AT_CURRENT_LEVEL /**< Type is hidden at Current level */
} TCTYPE_display_t;

/**
    Defines the business objects category that could be on a type.
    <br>This enumeration can be used by #TCTYPE_extent_by_category.
    <br>If category is TCTYPE_Persistent, it returns all the business object types of persistent.
    <br>If category is TCTYPE_Runtime, it returns all the business object types of runtime.
    <br>If category is TCTYPE_OperationInput, it returns all the business object types of operation input.
    <br>If category is TCTYPE_Dynamic, it returns all the business object types of dynamic types.
    <br>If the category is #TCTYPE_All or #TCTYPE_Root, it returns all the business object types of runtime, persistent and dynamic types.
*/
typedef enum TCTYPE_category_e {
    TCTYPE_Persistent,               /**< Indicates persistent business objects */
    TCTYPE_Runtime,                  /**< Indicates runtime business objects */
    TCTYPE_OperationInput,           /**< Indicates operation input business objects */
    TCTYPE_Root,                     /**< Indicates root object  */
    TCTYPE_Dynamic,                  /**< Indicates programmatically created business object */
    TCTYPE_All                       /**< Indicates all business objects */
} TCTYPE_category_t;


typedef struct TCTYPE_availablerel_s
{
    char* actualName;  /**< Actual name */
    char* displayName; /**< Display name */
}  TCTYPE_availablerel_t;

/**
    Provides a container to hold an array of attached deep copy data objects for an object to be operated on.
    <br/>It is further contained in the #TCTYPE_bulk_copy_input_t object when copying or revising an object in Teamcenter using the set-based ITKs, #TCTYPE_bulk_saveas_objects or #TCTYPE_bulk_revise_objects.
*/
typedef  struct  TCTYPE_deepcopydata_s
{
    int                         n_deepcopydata_attached_objects;    /**< (I) Number of attached deep copy data objects. */
    tag_t*                      deepcopydata_attached_objects;      /**< (I) n_deepcopydata_attached_objects The array of attached deep copy data objects. */
}       TCTYPE_deepcopydata_t;

/**
    Provides a container to hold the object to operate on, its operation descriptor and the corresponding #TCTYPE_deepcopydata_t object.
    <br/>It is put to use when copying or revising an object in Teamcenter using the set-based ITKs, #TCTYPE_bulk_saveas_objects or #TCTYPE_bulk_revise_objects.
*/
typedef  struct  TCTYPE_bulk_copy_input_s
{
    tag_t                       source_object;                      /**< (I) The object to operate on. */
    tag_t                       operation_descriptor;               /**< (I) The descriptor object carrying information to perform an operation on @p source_object. */
    TCTYPE_deepcopydata_t*      attached_deepcopydata;              /**< (I) The deep copy data for @p source_object. */
}       TCTYPE_bulk_copy_input_t;

/**
    This is used to indicate the context for secondary object creation when a primary object is created.
*/
typedef enum TCTYPE_compounding_ctxt_e
{
    TCTYPE_compounding_ctxt_unknown,  /**< Context for secondary object is unknown */
    TCTYPE_compounding_ctxt_relation, /**< The secondary object is a relation object.
                                         <br>This is useful in cases where properties on relation need to be
                                         configured for generic creation. */
    TCTYPE_compounding_ctxt_secondary /**< The secondary object is a Business Object that is not a relation,
                                         e.g Item Master is the secondary object created when an Item is
                                         created. */
} TCTYPE_compounding_ctxt_t;

/**
    Defines the supported operation input types. These types correspond to the OperationInput types
    defined in BMIDE and can be used as input of MetaModel operations.
*/
typedef enum TCTYPE_operation_input_e
{
    TCTYPE_OPERATIONINPUT_CREATE = 0, /**< Create operation input type */
    TCTYPE_OPERATIONINPUT_REVISE = 1, /**< Revise operation input type */
    TCTYPE_OPERATIONINPUT_SAVEAS = 2, /**< SaveAs operation input type */
    TCTYPE_OPERATIONINPUT_ANY    = 3  /**< Generic operation input type */
} TCTYPE_operation_input_t;

/**
    The options listed by the enum lets the user understand the context during a deferred save operation,
    especially when implementing PostAction extensions that have been manually moved.
*/
typedef enum TCTYPE_save_operation_context_e
{
    TCTYPE_save_on_create,            /**< Save operation in the context of Create */
    TCTYPE_save_on_saveas,            /**< Save operation in the context of SaveAs */
    TCTYPE_save_on_revise,            /**< Save operation in the context of Revise */
    TCTYPE_save_on_update,            /**< Save operation in the context of Update */
    TCTYPE_unknown_operation_context, /**< Save operation in the context of Unknown */
    TCTYPE_save_on_clone              /**< Save operation in the context of Clone */
}   TCTYPE_save_operation_context_t;

#ifdef __cplusplus
extern "C"{
#endif

/**
    Initializes the TCTYPE module.
    This function can be called in #ITK_user_main before using any other TCTYPE module functions.
    Currently, it is called during Teamcenter startup and
    before installing types in the install_types utility.
*/
extern TCCORE_API int TCTYPE_init_module();

extern TCCORE_API int TCTYPE_exit_module();

/**
    Refreshes a type that has been created.
*/
extern TCCORE_API int TCTYPE_refresh(
    tag_t               type,           /**< (I) The type to refresh */
    logical             lock_or_not     /**< (I) Indicates whether to lock the type. True is yes. */
    );


/**
    Retrieves a type's internal name.
*/
extern TCCORE_API int TCTYPE_ask_name2(
    tag_t               type,                             /**< (I) The type */
    char                **type_name                       /**< (OF) The name of the type */
    );


 /**
   Retrieves the type tag from the provided type name.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#TYPE_unknown_type if @p type_name is not found.
   <li>#TYPE_invalid_type_name if @p type_name is NULL or empty.
   </ul>
*/
extern TCCORE_API int TCTYPE_ask_type(
    const char*               type_name,               /**< (I) The name of the type */
    tag_t*                    type                     /**< (O) The found type */
    );


/**
    Asks a type for its display name.
*/
extern TCCORE_API int TCTYPE_ask_display_name(
    tag_t               type,                             /**< (I) The type */
    char**              display_type_name                 /**< (OF) The display name of the type */
    );


/**
    Asks the type for the name of the class that implements it.
*/
extern TCCORE_API int TCTYPE_ask_class_name2(
    tag_t               type,                                     /**< (I) The type */
    char                **type_class                              /**< (OF) The name of the class */
    );

/**
    Asks an object for its type.
*/
extern TCCORE_API int TCTYPE_ask_object_type(
    tag_t               object,    /**< (I) The tag of the object */
    tag_t*              type       /**< (O) The tag of the type */
    );

/**
    Retrieves the types of an array of objects without loading them.

    @returns  #ITK_ok always
    @note If any of the input @p objects is invalid or #NULLTAG, the corresponding entry in @p types will be #NULLTAG.
*/
extern TCCORE_API int TCTYPE_ask_object_types(
    int                 number_of_objects,      /**< (I) The number of objects in the input array*/
    const tag_t*        objects,                /**< (I) The tags of the objects */
    tag_t**             types                   /**< (OF) number_of_objects Object types */
    );

/**
    Asks an object for its type.
    but honoring stubs as well
*/
extern TCCORE_API int TCTYPE_ask_object_type_with_stubs(
    tag_t               object,     /**< (I) The object */
    tag_t*              type        /**< (O) The type */
    );


/**
    Finds the type that has the type_name and class_name provided.

    @returns #ITK_ok always, even if the type is not found.

    @note The caller needs to check the value returned in the parameter @p type_tag.
*/
extern TCCORE_API int TCTYPE_find_type(
    const char*         type_name,      /**< (I) The name of the type */
    const char*         class_name,     /**< (I) The name of the class.  A null or a wrong name is allowed.
                                           <br/>In that case, if a non-zero length type name is specified TCTYPE_find_type
                                           will search for the type tag for the given type name. */
    tag_t*              type            /**< (O) The tag of the found type (#NULLTAG if not found) */
    );

/**
    Finds types implemented by the given class.
*/
extern TCCORE_API int TCTYPE_find_types_for_class(
    const char*         class_name,         /**< (I) The name of the type */
    int*                number_of_types,    /**< (O) The number of types found */
    tag_t**             types               /**< (OF) number_of_types The found types (NULL if none found) */
    );

/**
    Finds the types implemented by the given class that are displayable to the login user in the object creation dialog.
    If the value of include_subclasses is TRUE,
    then the function finds the displayable types implemented by the subclasses of the given class also.
*/
extern TCCORE_API int TCTYPE_find_displayable_types_for_class(
    const char*         class_name,             /**< (I) Name of the class */
    logical             include_subclasses,     /**< (I) TRUE: Find displayable types implemented by
                                                         the given class and its subclasses <br>
                                                         FALSE: Find displayable types implemented by
                                                         the given class only. */
    int*                number_of_types,        /**< (O) The number of types found */
    tag_t**             types                   /**< (OF) number_of_types The found types */
    );

/**
    Finds the types implemented by the given class that are displayable to the login user in the object creation dialog.
    If the value of include_subclasses is TRUE,
    then the function finds the displayable types implemented by the subclasses of the given class also.
    In addition we get the real and display type names for the displayable types for the connection locale.
*/
extern TCCORE_API int TCTYPE_UIF_find_displayable_types_for_class(
    const char*         class_name,             /**< (I) Name of the class */
    logical             include_subclasses,     /**< (I) TRUE: Find displayable types implemented by
                                                         the given class and its subclasses <br>
                                                         FALSE: Find displayable types implemented by
                                                         the given class only. */
    int*                number_of_types,        /**< (O) The number of types found */
    tag_t**             types,                  /**< (OF) number_of_types The found types */
    char***             type_names,             /**< (OF) number_of_types The type names */
    char***             display_type_names      /**< (OF) number_of_types The type display names */
    );

/**
    Finds the types implemented by the given class that are displayable to
    the given accessor in the object creation dialog.
    If the value of include_subclasses is TRUE,
    then the function finds the displayable types implemented by the subclasses of the given class also.
*/
extern TCCORE_API int TCTYPE_find_displayable_types_for_class_and_accessor(
    const char*         class_name,             /**< (I) Name of the class */
    tag_t               accessor_tag,           /**< (I) Tag of the accessor (Group, Role-in-Group) */
    logical             include_subclasses,     /**< (I) TRUE: Find displayable types, for the given accessor,
                                                         implemented by the given class and its subclasses <br>
                                                         FALSE: Find displayable types, for the given accessor,
                                                         implemented by the given class only. */
    int*                number_of_types,        /**< (O) The number of types found */
    tag_t**             types                   /**< (OF) number_of_types The found types */
    );

/**
    Finds the types implemented by the given class that are not displayable to
    the given accessor in the object creation dialog.
    If the value of include_subclasses is TRUE,
    then the function finds the non-displayable types (hidden types)
    implemented by the subclasses of the given class also.
*/
extern TCCORE_API int TCTYPE_find_hidden_types_for_class_and_accessor(
    const char*          class_name,            /**< (I) Name of the class */
    tag_t                accessor_tag,          /**< (I) Tag of the accessor ( Group, Role-in-Group ) */
    logical              include_subclasses,    /**< (I) TRUE: Find non-displayable types, for the given accessor,
                                                     implemented by the given class and its subclasses <br>
                                                     FALSE: Find non-displayable types, for the given accessor,
                                                     implemented by the given class only. */
    int*                 number_of_types,       /**< (O) The number of types found */
    tag_t**              types,                 /**< (OF) number_of_types The found types */
    TCTYPE_display_t**   details                /**< (OF) number_of_types Tells if the type is non-displayable
                                                     because of system-level rule or site-wide rule or
                                                     parent-level rule or the rules defined at the given accessor level. */
    );

extern TCCORE_API int TCTYPE_find_alltypes_for_class(
    const char*         class_name,         /**< (I) */
    int*                number_of_types,    /**< (O) */
    tag_t**             types               /**< (OF) number_of_types */
    );

/**
    Finds all types in the database.
*/
extern TCCORE_API logical TCTYPE_is_extent_already_called();

/**
   @note To ensure that all types are loaded and @p types is not needed, call #TCTYPE_is_extent_already_called
   first to see if #TCTYPE_extent is already called. Call #TCTYPE_extent only if is has not been called
*/
extern TCCORE_API int TCTYPE_extent(
    int*                number_of_types,    /**< (O) The number of types found */
    tag_t**             types               /**< (OF) number_of_types The found types (NULL if none found) */
    );


/**
    Asks a type for a list of the property descriptors that define it.
    If there is an error, num is set to 0 and pd_tags is set to NULL.
*/
extern TCCORE_API int TCTYPE_list_properties(
    tag_t               type,                  /**< (I) The type */
    int*                n_properties,          /**< (O) The number of property descriptors returned */
    tag_t**             property_descriptors   /**< (OF) n_properties The tags of the property descriptors that define the type */
    );

/**
    Asks a type for its property descriptor that has the value of the parameter @p property_name as its name.
*/
extern TCCORE_API int TCTYPE_ask_property_by_name(
    tag_t               type,                     /**< (I) The type */
    const char*         property_name,            /**< (I) The name of the property */
    tag_t*              property_descriptor       /**< (O) The tag of the property descriptor */
    );

/**
    Returns verdict = true if the input property exists on the input type.
    It does not return PROP_not_found if the property is not found on the input type.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#TYPE_no_find_type if @p type is invalid.
    <li>#TYPE_unknown_type if the specified type does not exist.
    <li>#PROP_not_found if @p property_name is NULL or empty string.
    </ul>
*/
extern TCCORE_API int TCTYPE_property_exists(
    tag_t               type,           /**< (I) The type */
    const char*         property_name,  /**< (I) The name of the property */
    logical*            verdict         /**< (O) Does the property exist */
    );

/**
    Retrieves the property based on the specified type and the display name of the property for that type.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#PROP_not_found if the property with the specified name could not be found.
    </ul>
*/
extern TCCORE_API int TCTYPE_ask_property_by_display_name(
    tag_t               type,                     /**< (I) The type */
    const char*         display_name,             /**< (I) Display name of the property */
    tag_t*              property_descriptor       /**< (O) The property */
    );



/**
    Lists all types of GRM relation which can have primary objects of this type.
    <br>This is used to populate the Revision Information dialog box.
    The Revision Information dialog box displays all GRM relation types for
    a particular Item or Item Revision.
    You can then show or hide these in Workspace.
    <br>This list is built up by finding all \<rel_type_name\>_relation_primary preferences that
    specify this type as a valid primary.
*/
extern TCCORE_API int TCTYPE_list_primary_rtypes(
    tag_t               primary_type,           /**< (I) Tag of the object type */
    int*                number_relation_types,  /**< (O) Number of relation types */
    tag_t**             relation_types          /**< (OF) number_relation_types Array of relation type tags */
    );


/** @if DOX_IGNORE
    (Jon Kao) 4/24
@endif */
/**
   Retrieves the list of displayable properties on a given type.
*/
extern TCCORE_API int TCTYPE_list_displayable_properties(
    tag_t               type,                  /**< (I) The tag of the type on which displayable properties are requested. */
    int*                number_of_properties,  /**< (O) The number of displayable properties*/
    tag_t**             property_descriptors   /**< (OF) number_of_properties Property Descriptor tags for the
                                                  displayable properties */
    );

/**
   Retrieves the list of available relations on a given type.
*/
extern TCCORE_API int TCTYPE_ask_available_relations(
    tag_t                     type,                   /**< (I) The type on which available relations are requested. */
    int*                      number_of_relations,    /**< (O) The number of available relations */
    TCTYPE_availablerel_t**   available_relations     /**< (OF) number_of_relations The array of available relations */
    );


/**
   Retrieves the display names and actual names of the available relations on a given type.
*/
extern TCCORE_API int TCTYPE_ask_available_relation_names(
    tag_t                     type,                   /**< (I) The type on which available relations are requested. */
    int*                      number_of_relations,    /**< (O) The number of available relations */
    char***                   relation_display_names, /**< (OF) number_of_relations The display names of available relations */
    char***                   relation_actual_names   /**< (OF) number_of_relations The actual names of available relations */
    );

/**
   Retrieves the parent type tag of a given type.
*/
extern TCCORE_API int TCTYPE_ask_parent_type(
    tag_t type,             /**< (I) The type */
    tag_t *parent_type      /**< (O) The parent type of the given type */
    );

/**
   Determines if a given type is the same as or a subtype of the input parent type.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TYPE_no_find_type if the given type is #NULLTAG
   <li>#TYPE_unknown_type if any of the given types does not exist.
   </ul>
*/
extern TCCORE_API int TCTYPE_is_type_of (
    tag_t     type,         /**< (I) The tag for the type to compare */
    tag_t     parent_type,  /**< (I) The tag for a parent type to check if @p type is its subtype */
    logical * answer        /**< (O) Indicates if the @p type is the same as or subtype of the @p parent_type */
    );

/**
   Determines if a provided type (through argument @p type) is a sub-type of another one (parameter @p parent_type_name).
   <br>The value of the parameter @p answer will also be true if the two types are identical.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TYPE_unknown_type if the specified type does not exist.
   </ul>
*/
extern TCCORE_API int TCTYPE_is_type_of_as_str(
    tag_t                    type,                   /**< (I) The type */
    const char*              parent_type_name,       /**< (I) Parent type name */
    logical*                 answer                  /**< (O) Flag indicating whether @p type is of the same type as parent_type_name or one of its sub-types */
    );

/**
   Retrieves a list of subtypes of a given type.
   @note The parameter @p for_same_class_only is used to scope what the returned list of subtypes will include.
   <ul>
   <li>If the value is "true", the returned list of subtypes will include only subtypes that are created for the same
   class as for the given type.
   <li>If the value is "false" and the given type is a primary type, the returned list of subtypes will include subtypes
   for the same class as well as all types for each subclass of the class of the given type.
   </ul>
*/
extern TCCORE_API int TCTYPE_ask_subtypes(
    tag_t    type,                   /**< (I) A type */
    logical  for_same_class_only,    /**< (I) Indicates whether the scope of the search is limited to types for the same class */
    int *    n_subtypes,             /**< (O) Number of subtypes found */
    tag_t ** subtypes                /**< (OF) n_subtypes The found types */
    );

/**
   Retrieves a list of subtypes for the given type.
   <br>The given exclusion list is used to exclude the subtype names from the output.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>#CXPOM_invalid_tag if @p type is invalid.
   <li>#TYPE_unknown_type if the specified type does not exist.
   </ul>
*/
extern TCCORE_API int TCTYPE_ask_subtypes_with_exclusions(
    tag_t             type,                       /**< (I) A type */
    logical           for_same_class_only,        /**< (I) Flag indicating whether the scope of the search is limited to types of the same class */
    int               number_exclusion_bo_names,  /**< (I) Number of the Business Object names to be excluded from output */
    const char**      exclusion_bo_names,         /**< (I) Array of names for the Business Objects to be excluded from output */
    int *             number_of_subtypes,         /**< (O) Number of found types */
    tag_t **          subtypes                    /**< (OF) number_of_subtypes Array of tags for the found subtypes  */
    );

/**
   Retrieves the list of immediate child types of a given type.
   @note The parameter @p for_same_class_only is used to scope what the returned list of subtypes will include.
   <ul>
   <li>If the value is "true", the returned list of child subtypes will include only child subtypes
   that are created for the same class as for the given type.  The returned subtypes will be the
   subtypes that are one-level down in the type hierarchy from the given type.
   <li>If the value is "false" and the given type is a primary type, the returned list of subtypes
   will include the immediate subtypes for the same class as well as all primary types for the
   immediate subclasses of the class of the given type.
   </ul>
*/
extern TCCORE_API int TCTYPE_ask_child_types(
    tag_t    type,                  /**< (I) The type */
    logical  for_same_class_only,   /**< (I) Flag indicating whether the scope of the search is limited to types for the same class */
    int *    number_of_child_types, /**< (O) The number of found child types */
    tag_t ** child_types            /**< (OF) number_of_child_types The list of found child types */
    );

/**
   Retrieves the list of child types of a given type.
   <br>Each of the returned child types is also a primary type.
 */
extern TCCORE_API int TCTYPE_ask_child_primary_types (
    tag_t    type,                  /**< (I) The type */
    int *    number_of_child_types, /**< (O) The number of found child types */
    tag_t ** child_types            /**< (OF) number_of_child_types The list of found child types */
    );

/**
   Loads all delay types/classes
 */
extern TCCORE_API int TCTYPE_load_all_delayed_types() ;

/**
   Retrieves the CreateInput Type object tag for the input Business Object.
 */
extern TCCORE_API int TCTYPE_ask_create_descriptor(
    tag_t type_tag,             /**< (I) The tag of the Business Object type */
    tag_t* creation_descriptor  /**< (O) The tag of the associated CreateInput object */
);


/**
   Retrieves the SaveAsInput Type object tag for the input Business Object.
 */
extern TCCORE_API int TCTYPE_ask_saveas_descriptor(
    tag_t type_tag,             /**< (I) The tag of the Business Object type */
    tag_t* save_as_descriptor   /**< (O) The tag of the associated SaveAs object */
 );

/**
   @deprecated #TCTYPE_ask_target_deepcopydata deprecated in Teamcenter 11.2.2. Use #TCTYPE_ask_deepcopydata instead.
   <br/>Use #TCTYPE_ask_deepcopydata with the value #TCTYPE_OPERATIONINPUT_SAVEAS for the parameter "operation_input".

   Retrieves the DeepCopyData tag for the input Business Object.
*/
TC_DEPRECATED( "11.2.2", "TCTYPE_ask_target_deepcopydata", "TCTYPE_ask_deepcopydata" )
extern TCCORE_API int TCTYPE_ask_target_deepcopydata(
    tag_t   object_tag,               /**< (I) The object tag*/
    int  *  number_attached_objects,  /**< (O) The number of attached objects*/
    tag_t** deep_copy_data_tags       /**< (OF) number_attached_objects Tags for the Deep Copy Data*/
);


/**
    Constructs #TCTYPE_bulk_copy_input_t objects corresponding to input list of source objects to be operated on.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ITK_internal_error if @p n_source_objects is zero or a negative number.
    <li>#ITK_internal_error if @p source_objects is NULL.
    <li>#TYPE_no_find_type if any member of @p source_objects is a #NULLTAG.
    <li>#METAFRAMEWORK_invalid_BusinessObject if any member of @p source_objects cannot undergo the operation @p operation_type.
    <li>#ITK_internal_error if @p operation_type is invalid.
    <li>Possibly other errors.
    </ul>
*/
extern TCCORE_API int TCTYPE_construct_bulk_copy_inputs(
    const int                           n_source_objects,       /**< (I) Number of source objects. */
    const tag_t*                        source_objects,         /**< (I) n_source_objects The array of source objects. */
    const TCTYPE_operation_input_t      operation_type,         /**< (I) The operation type. Only #TCTYPE_OPERATIONINPUT_REVISE and #TCTYPE_OPERATIONINPUT_SAVEAS are valid. */
    TCTYPE_bulk_copy_input_t**          bulk_copy_inputs        /**< (OF) n_source_objects The array of #TCTYPE_bulk_copy_input_t objects.
    <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only. */
);

/**
    Constructs #TCTYPE_bulk_copy_input_t objects corresponding to input list of source objects to be operated on.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ITK_internal_error if @p n_source_objects is zero or a negative number.
    <li>#ITK_internal_error if @p source_objects is NULL.
    <li>#TYPE_no_find_type if any member of @p source_objects is a #NULLTAG.
    <li>#METAFRAMEWORK_invalid_BusinessObject if any member of @p source_objects cannot undergo the operation @p operation_type.
    <li>#ITK_internal_error if @p operation_type is invalid.
    <li>Possibly other errors.
    </ul>
*/
extern TCCORE_API int TCTYPE_construct_bulk_operation_inputs(
    const int                           n_source_objects,       /**< (I) Number of source objects. */
    const tag_t*                        source_objects,         /**< (I) n_source_objects The array of source objects. */
    const TCTYPE_operation_input_t      operation_type,         /**< (I) The operation type. Only #TCTYPE_OPERATIONINPUT_REVISE and #TCTYPE_OPERATIONINPUT_SAVEAS are valid. */
    TCTYPE_bulk_copy_input_t**          bulk_copy_inputs        /**< (OF) n_source_objects The array of #TCTYPE_bulk_copy_input_t objects. */
);


/**
    Deletes the operation descriptor and deep copy data objects held by #TCTYPE_bulk_copy_input_t objects.
    <br/>Ensure this is called only after performing the set-based "saveAs" or "revise" operation.
    <br/>Ensure this is followed immediately by a call to #MEM_free on the array of #TCTYPE_bulk_copy_input_t objects since the objects pointed to have just been deleted by this ITK.

    @code
    int ifail = ITK_ok;

    try
    {
        ResultCheck  rStat;
        ....
        const int  n_source_objects = 3;
        ....                                                                        //  create a valid tag_t*, source_objects to hold 3 valid objects to revise.
        TCTYPE_bulk_copy_input_t*  pBulkCopyInput = 0;
        rStat = TCTYPE_construct_bulk_copy_inputs( n_source_objects,
                                                   source_objects,
                                                   TCTYPE_OPERATIONINPUT_REVISE,
                                                   & pBulkCopyInput );              //  retrieve 3 valid TCTYPE_bulk_copy_input_t objects for set-based revise operation.
        ....
        tag_t*  revised_objects = 0;
        rStat = TCTYPE_bulk_revise_objects( n_source_objects, pBulkCopyInput,
                                            & revised_objects );                    //  perform the set-based revise operation using TCTYPE_bulk_copy_input_t
        ....                                                                        //  objects held by pBulkCopyInput.
        ....
        rStat = TCTYPE_delete_operation_input_objects( n_source_objects,
                                                       pBulkCopyInput );            //  this call will delete the operation descriptor and
                                                                                    //  deep copy data objects held by pBulkCopyInput.

        MEM_free( pBulkCopyInput );                                                 //  MEM_free will deallocate memory blocks held by pBulkCopyInput.
        pBulkCopyInput = 0;
        ....
    }
    catch( const IFail& ex )
    {
        ifail = ex.ifail();
    }

    return  ifail;
    @endcode

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ITK_internal_error if @p n_bulk_copy_inputs is zero or a negative number.
    <li>#ITK_internal_error if @p bulk_copy_inputs is NULL.
    </ul>
*/
extern TCCORE_API int TCTYPE_delete_operation_input_objects(
    const int                           n_bulk_copy_inputs,                     /**< (I) Number of #TCTYPE_bulk_copy_input_t objects. */
    const TCTYPE_bulk_copy_input_t*     bulk_copy_inputs                        /**< (I) n_bulk_copy_inputs The array of #TCTYPE_bulk_copy_input_t objects. */
);


/**
    Deletes the operation descriptor and deep copy data objects held by #TCTYPE_bulk_copy_input_t objects.
    <br/>Ensure this is called only after performing the set-based "saveAs" or "revise" operation.

    @code
        int ifail = ITK_ok;

        try
        {
            ResultCheck  rStat;
            ....
            int  n_source_objects = 3;
            ....                                                                        //  create a valid tag_t*, source_objects to hold 3 valid objects to revise.
            TCTYPE_bulk_copy_input_t*  pBulkCopyInput = 0;
            rStat = TCTYPE_construct_bulk_operation_inputs( n_source_objects,
                                                            source_objects,
                                                            TCTYPE_OPERATIONINPUT_REVISE,
                                                            & pBulkCopyInput );              //  retrieve 3 valid TCTYPE_bulk_copy_input_t objects for set-based revise operation.
            ....
            tag_t*  revised_objects = 0;
            rStat = TCTYPE_bulk_revise_objects2( n_source_objects, pBulkCopyInput,
                                                 & revised_objects );                    //  perform the set-based revise operation using TCTYPE_bulk_copy_input_t
            ....                                                                         //  objects held by pBulkCopyInput.
            ....
            rStat = TCTYPE_delete_bulk_operation_inputs( &n_source_objects,
                                                         &pBulkCopyInput );            //  this call will delete the operation descriptor, deep copy data objects held by pBulkCopyInput
                                                                                      //  and pBulkCopyInput itself

            pBulkCopyInput = 0;
        ....
        }
        catch( const IFail& ex )
        {
        ifail = ex.ifail();
        }

        return  ifail;
    @endcode

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ITK_internal_error if @p n_bulk_copy_inputs is zero or a negative number.
    <li>#ITK_internal_error if @p bulk_copy_inputs is NULL.
    </ul>
*/
extern TCCORE_API int TCTYPE_delete_bulk_operation_inputs(
    int*                           n_bulk_copy_inputs,                           /**< (OF) Number of #TCTYPE_bulk_copy_input_t objects. */
    TCTYPE_bulk_copy_input_t**     bulk_copy_inputs                              /**< (OF) n_bulk_copy_inputs The array of #TCTYPE_bulk_copy_input_t objects. */
);



/**
    Copies the source objects in bulk using set-based implementation.
    <br/>If any of the source objects being copied does not have set-based implementation for the Types involved as a part of processing its deep copy data for the SaveAs operation, the set-based processing is aborted and all the source objects are copied using object-based implementation.
    <br/>In this case, ensure that every input #TCTYPE_bulk_copy_input_t object is relevant to the operation type, #TCTYPE_OPERATIONINPUT_SAVEAS.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ITK_internal_error if @p n_bulk_copy_inputs is zero or a negative number.
    <li>#ITK_internal_error if @p bulk_copy_inputs is NULL.
    <li>Possibly other errors.
    </ul>
*/
extern TCCORE_API int TCTYPE_bulk_saveas_objects(
    const int                           n_bulk_copy_inputs,                     /**< (I) Number of #TCTYPE_bulk_copy_input_t objects. */
    const TCTYPE_bulk_copy_input_t*     bulk_copy_inputs,                       /**< (I) n_bulk_copy_inputs The array of #TCTYPE_bulk_copy_input_t objects. */
    tag_t**                             copied_objects                          /**< (OF) n_bulk_copy_inputs The copied objects. */
);

/**
    Copies the source objects in bulk using set-based implementation with partial failure handling.
    <br/>If any of the source objects being copied does not have set-based implementation for the Types involved as a part of processing its deep copy data for the SaveAs operation, the set-based processing is aborted and all the source objects are copied using object-based implementation.
    <br/>In this case, ensure that every input #TCTYPE_bulk_copy_input_t object is relevant to the operation type, #TCTYPE_OPERATIONINPUT_SAVEAS.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ITK_internal_error if @p n_bulk_copy_inputs is zero or a negative number.
    <li>#ITK_internal_error if @p bulk_copy_inputs is NULL.
    <li>Possibly other errors.
    </ul>
*/
extern TCCORE_API int TCTYPE_bulk_saveas_objects2(
    const int                           n_bulk_copy_inputs,                     /**< (I) Number of #TCTYPE_bulk_copy_input_t objects. */
    const TCTYPE_bulk_copy_input_t*     bulk_copy_inputs,                       /**< (I) n_bulk_copy_inputs The array of #TCTYPE_bulk_copy_input_t objects. */
    tag_t**                             copied_objects,                         /**< (OF) n_bulk_copy_inputs The copied objects. */
    int**                               ifails,                                 /**< (OF) n_bulk_copy_inputs The statuses for each copied object.               
                                                                                <br / >It will be #ITK_ok on success. */
    char***                             error_messages                          /**< (OF) n_bulk_copy_inputs Error messages for errors that might have occurred during the saveas of each object. 
                                                                                error_messages is packed and should be freed via MEM_free  */
);


/**
    Revises the source objects in bulk using set-based implementation.
    <br/>If any of the source objects being revised does not have set-based implementation for the Types involved as a part of processing its deep copy data for the Revise operation, the set-based processing is aborted and all the source objects are revised using object-based implementation.
    <br/>In this case, ensure that every input #TCTYPE_bulk_copy_input_t object is relevant to the operation type, #TCTYPE_OPERATIONINPUT_REVISE.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ITK_internal_error if @p n_bulk_copy_inputs is zero or a negative number.
    <li>#ITK_internal_error if @p bulk_copy_inputs is NULL.
    <li>#METAFRAMEWORK_invalid_BusinessObject if the object is not revisable.
    <li>Possibly other errors.
    </ul>
*/
extern TCCORE_API int TCTYPE_bulk_revise_objects(
    const int                           n_bulk_copy_inputs,                     /**< (I) Number of #TCTYPE_bulk_copy_input_t objects. */
    const TCTYPE_bulk_copy_input_t*     bulk_copy_inputs,                       /**< (I) n_bulk_copy_inputs The array of #TCTYPE_bulk_copy_input_t objects. */
    tag_t**                             revised_objects                         /**< (OF) n_bulk_copy_inputs The revised objects. */
);

/**
Copies the source objects in bulk using set-based implementation with partial failure handling.
<br/>If any of the source objects being copied does not have set-based implementation for the Types involved as a part of processing its deep copy data for the SaveAs operation, the set-based processing is aborted and all the source objects are copied using object-based implementation.
<br/>In this case, ensure that every input #TCTYPE_bulk_copy_input_t object is relevant to the operation type, #TCTYPE_OPERATIONINPUT_SAVEAS.

@returns
<ul>
<li>#ITK_ok on success.
<li>#ITK_internal_error if @p n_bulk_copy_inputs is zero or a negative number.
<li>#ITK_internal_error if @p bulk_copy_inputs is NULL.
<li>Possibly other errors.
</ul>
*/
extern TCCORE_API int TCTYPE_bulk_revise_objects2(
    const int                           n_bulk_copy_inputs,                     /**< (I) Number of #TCTYPE_bulk_copy_input_t objects. */
    const TCTYPE_bulk_copy_input_t*     bulk_copy_inputs,                       /**< (I) n_bulk_copy_inputs The array of #TCTYPE_bulk_copy_input_t objects. */
    tag_t**                             revised_objects,                        /**< (OF) n_bulk_copy_inputs The revised objects. */
    int**                               ifails,                                 /**< (OF) n_bulk_copy_inputs The statuses for each copied object.
                                                                                <br / >It will be #ITK_ok on success. */
    char***                             error_messages                          /**< (OF) n_bulk_copy_inputs Error messages for errors that might have occurred during the revise of each object.
                                                                                error_messages is packed and should be freed via MEM_free  */
);

/**
    @deprecated #TCTYPE_bulk_create_objects deprecated in Teamcenter 13.1. Use #TCTYPE_bulk_create_objects_with_error_details instead.
    
    Creates objects in bulk using set-based implementation.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ITK_internal_error if @p n_objects is zero or a negative number.
    <li>#ITK_internal_error if @p create_inputs is NULL.
    <li>Possibly other errors.
    </ul>
*/
TC_DEPRECATED( "13.1", "TCTYPE_bulk_create_objects", "TCTYPE_bulk_create_objects_with_error_details")
extern TCCORE_API int TCTYPE_bulk_create_objects(
    const int        n_objects,             /**< (I) Number of CreateInput objects. */
    const tag_t*     create_inputs,         /**< (I) n_objects The array of CreateInput objects. */
    tag_t**          objects                /**< (OF) n_objects The created objects. */
);

/**
    Retrieves all the visible property descriptors and compound object data for the input CreateInput object type.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#TYPE_no_find_type if the system is unable to find the corresponding ImanType object.
    <li>Potentially other errors.
    </ul>
*/
extern TCCORE_API int TCTYPE_ask_create_prop_descriptors(
    tag_t     create_descriptor_tag,               /**< (I)  The tag for the create descriptor */
    int*      number_property_descriptors,         /**< (O)  Number of property descriptor tags */
    tag_t**   property_descriptor_tags,            /**< (OF) number_property_descriptors Array of tags for the property descriptors */
    int*      number_secondary_prop_names,         /**< (O)  Number of secondary object property names */
    char***   secondary_prop_names,                /**< (OF) number_secondary_prop_names Array of secondary object property names
                                                       <br>This string array is packed, which means that only the container
                                                       needs to be deallocated through a call to #MEM_free. */
    tag_t**   secondary_bo_type_tags,              /**< (OF) number_secondary_prop_names Array of type tags for the secondary objects */
    logical** is_required,                         /**< (OF) number_secondary_prop_names Array of logical values indicating the corresponding secondary object is required or not */
    logical** is_array,                            /**< (OF) number_secondary_prop_names Array of logical values indicating the corresponding secondary object is array or not */
    int**     compounding_ctxts,                   /**< (OF) number_secondary_prop_names Array of contexts for secondary objects creation */
    tag_t**   secondary_create_descriptor_tags     /**< (OF) number_secondary_prop_names Array of tags for secondary objects' create descriptors */
);


/**
    Retrieves all the visible property descriptors for the input SaveAsInput object type.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#TYPE_no_find_type if the system is unable to find the corresponding ImanType object.
    <li>Potentially other errors.
    </ul>
*/
extern TCCORE_API int TCTYPE_ask_saveas_prop_descriptors(
    tag_t   saveas_descriptor_tag,           /**< (I) The tag for the saveas descriptor */
    int*    number_prop_descriptor_tags,     /**< (O) Number of property descriptor tags */
    tag_t** prop_decriptor_tags              /**< (OF) number_prop_descriptor_tags Array of tags for the property descriptors */
);


/**
   Constructs a CreateInput object for the input Business Object.
   <br>Use this CreateInput object to hold input data for the creation of an object.
 */
extern TCCORE_API int TCTYPE_construct_create_input(
    tag_t  type,            /**< (I) The type of the Business Object*/
    tag_t* create_input     /**< (O) The CreateInput object*/
);

/**
   Constructs a SaveAsInput object for the input Business Object.
   <br>Use this SaveAsInput object to hold input data for the creation of an object.
 */
extern TCCORE_API int TCTYPE_construct_saveasinput(
    tag_t  type,            /**< (I) The type of the Business Object*/
    tag_t* save_as_input    /**< (O) The SaveAsInput object*/
);

/**
   Constructs a SaveAsInput object for the input Business Object.
   <br>Use this SaveAsInput object to hold input data for the creation of an object.
 */
extern TCCORE_API int TCTYPE_construct_operationinput(
    tag_t                    target_object_type,   /**< (I) */
    TCTYPE_operation_input_t operation_input,      /**< (I) */
    tag_t*                   target_save_as_input  /**< (O) */
);

/**
   Deletes the Deep Copy Data objects.

   @returns #ITK_ok always
 */
extern TCCORE_API int TCTYPE_free_deepcopydata(
    int    number_deep_copy_data,   /**< (I) */
    tag_t* deep_copy_data          /**< (I) */
);

/**
    Performs a SaveAs operation on the specified object according to the SaveAs
    data in the SaveAsInput objects and deep copies the attached objects based
    upon the DeepCopyData provided. DeepCopyData for an object may be null if no
    Deep Copy Rule is defined for its type.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ITEM_create_id_gen_failed if the system is unable to generate a valid item ID.
    <li>#METAFRAMEWORK_businessObj_creation_fail if the system is unable to create the object.
    <li>Possibly other errors.
    </ul>

    @note An exception will be thrown if invalid tags are provided in the parameters @p target_object_tag or @p save_as_input_tag.
*/
extern TCCORE_API int TCTYPE_saveas_object(
    tag_t  target_object,               /**< (I) The tag of the target object (objects being saved) */
    tag_t  save_as_input,               /**< (I) The tag of the SaveAsInput for the target object, containing user input */
    int    number_of_attached_objects,  /**< (I) The number of objects attached to the target object */
    tag_t* deep_copy_data,              /**< (I) Array of DeepCopyData tags for the attached objects  */
    tag_t* target_copy                  /**< (O) The tag of the copy of the top-level object saved */
);

/**
   Retrieves the ReviseInput Type object tag for the input type.
 */
extern TCCORE_API int TCTYPE_ask_revise_descriptor(
    tag_t  object_type,        /**< (I) The type */
    tag_t* revise_descriptor   /**< (O) The revise descriptor */
);

/**
   Retrieves the DeepCopyData tag(s) for the input object, a top-level object undergoing
   the operation type specified by opvar, such as SaveAs or Revise.
*/
extern TCCORE_API int TCTYPE_ask_deepcopydata(
    tag_t                    object,                     /**< (I) The tag of the top-level object being revised or saved */
    TCTYPE_operation_input_t operation_input,            /**< (I) The operation type */
    int *                    number_of_attached_objects, /**< (O) The number of objects related to the top-level object through a relation or reference property */
    tag_t**                  deep_copy_data              /**< (OF) number_of_attached_objects Array of the DeepCopyData tags  */
);

/**
   Revises the specified input objects according to the revise data in the
   ReviseInput objects and deep copies the attached objects based on the
   DeepCopyData provided.

   @returns #ITK_ok always

   @note It is necessary to check the returned array returned in the parameter @p ifails to determine the
   error status of a particular object.
   <br>Possible values for the array in the parameter @p ifails are:
   <ul>
   <li>#ITK_ok on success.
   <li>#TCCORE_revise_not_supported if the target object is not configured to allow the revise operation.
   <li>#ITEM_duplicate_rev if a revision with a requested revision id already exists.
   <li>Possibly other errors.
   </ul>
*/
extern TCCORE_API int TCTYPE_revise_objects(
    int     number_target_objects,  /**< (I) The number of objects to be revised */
    tag_t*  target_object,          /**< (I) number_target_objects Array of target objects (objects being revised) */
    tag_t*  revise_input,           /**< (I) number_target_objects Array of ReviseInput tags for the target objects, containing user input */
    int*    number_attached_objs,   /**< (I) number_target_objects Array of ints in which the value of nth element in num_attached_objs is the number of the objects attached to nth element in target_object_tags */
    tag_t*  deep_copy_data,         /**< (I) Array of DeepCopyData tags for the attached objects */
    tag_t** target_copy,            /**< (OF) number_target_objects Array of tags of the revised objects */
    int**   ifails                  /**< (OF) number_target_objects Array of ifail errors for the top-level target objects */
);

/**
   Creates an object according to the creation data in the CreateInput object.

   @note Do not save the created object using #AOM_bulk_save_instances_partial_errors.
   Use #AOM_save_with_extensions or #AOM_save_without_extensions instead.

 */
extern TCCORE_API int TCTYPE_create_object(
    tag_t create_input,  /**< (I) The tag of the CreateInput descriptor */
    tag_t* bo            /**< (O) The tag of the created Business Object*/
);

/**
   Creates objects of the given quantity for the specified types, according to the creation data in the CreateInput objects.
   <br/>The supported types are Item, ItemRevision, Dataset and Form
   <br/>If any error is detected, no objects will be created.

   @note Do not save the created objects using #AOM_bulk_save_instances_partial_errors.
   Use #AOM_save_with_extensions, #AOM_save_without_extensions or #AOM_bulk_save_instances instead.

   @note The references to the created compound objects are cleared

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TCCORE_bulk_create_not_supported if the type of the object to create is not Item, ItemRevision, Dataset or Form
   <li>#ITK_internal_error if the CreateInput object is invalid
   <li>Possibly other errors
   </ul>
 */
extern TCCORE_API int TCTYPE_create_objects(
    int n_bulks,            /**< (I) Number of CreateInput objects*/
    int* quantities,        /**< (I) n_bulks Array of number of objects to create for each CreateInput object */
    tag_t* create_inputs,   /**< (I) n_bulks Array of CreateInput objects */
    int* n_objects,         /**< (O) Number of created objects */
    tag_t** objects         /**< (OF) n_objects Array of created objects */
);

/**
   Creates single objects of the specified types, according to the creation data in the CreateInput objects.
   <br/>The supported types are Item, ItemRevision, Dataset and Form
   <br/>If any error is detected, no objects will be created.
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TCCORE_bulk_create_not_supported if the type of the object to create is not Item, ItemRevision, Dataset or Form
   <li>Possibly other errors
   </ul>
 */
extern TCCORE_API int TCTYPE_create_single_objects(
    int n_bulks,            /**< (I) Number of CreateInput objects*/
    const tag_t* create_inputs,   /**< (I) Array of CreateInput objects */
    int* n_objects,         /**< (O) Number of objects created */
    tag_t** objects         /**< (OF) n_objects Array of objects created */
);

/**
   Sets the display values for a property on a CreateInput descriptor.
 */
extern TCCORE_API int TCTYPE_set_create_display_value(
    tag_t  create_input,                /**< (I) The CreateInput descriptor */
    char*  property_name,               /**< (I) The property name*/
    int    number_of_display_values,    /**< (I) The number of the secondary Business Objects to set display value on*/
    const  char** display_values        /**< (I) Array of the display values.
                                           <br>Each display value is assigned to a secondary Business Object under the parameter @p property_name.
                                           <br>The parameter @p number_of_display_values is normally equal to 1.
                                           <br>The parameter @p number_of_display_values can be greater than 1 only if the property is a VLA and multiple secondary Business Objects need to be created */
);

/**
    @deprecated #TCTYPE_set_OperationInput_DisplayValue deprecated in Teamcenter 10.1.4. Use #AOM_set_value_string, and #AOM_set_value_strings instead.
    <br/>Use type-safe AOM set ITK APIs such as #AOM_set_value_string, and #AOM_set_value_strings,
    or use C++ set APIs such as setString and setStringArray, based on the value-type of the property.

    Sets display value(s) for a property on OperationInput type object. Only single array of char* for @p display_values is
    supported (char *display_values[1]). For single-valued properties, pointer to the display value is expected as input,
    while pointer to a string with comma-separated display values is expected as input for array-type properties.
*/
TC_DEPRECATED( "10.1.4", "TCTYPE_set_OperationInput_DisplayValue", "AOM_set_value_string" )
extern TCCORE_API int TCTYPE_set_OperationInput_DisplayValue(
    tag_t  operation_input,            /**< (I)  The OperationInput type object */
    char*  property_name,              /**< (I)  Name of the property */
    const  char** display_values       /**< (I)  Pointer to the display value(s) to set for the @p property_name property */

);

/**
    Retrieves the display value for a property on OperationInput

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#PROP_not_found if the property is not found.
    <li>#PROP_invalid_value_type if the specified property is invalid.
    </ul>
*/
extern TCCORE_API int TCTYPE_get_OperationInput_DisplayValues(
    tag_t     operation_input,           /**< (I)  The Operation Input Object */
    char*     property_name,             /**< (I)  Name of the Property on the Input Object */
    int*      number_of_display_values,  /**< (O)  The number of display values found */
    char***   display_values,            /**< (OF) number_of_display_values Array of display values for the property.
                                            <br>This string array is packed and please use #MEM_free after its use. */
    logical** is_null                    /**< (O)   number_of_display_values Array of logicals: "true" if the display value is null */
);

/**
    Finds the types for the Business Object that are displayable to the logged-in user in the object creation dialog.
*/
extern TCCORE_API int TCTYPE_find_displayable_business_objects(
    const char*   bo_name,                   /**< (I)  Name of the Business Object */
    int           number_exclusion_bo_names, /**< (I)  number of the Business Object names to be excluded */
    const char**  exclusion_bo_names,        /**< (I)  Array of the Business Object names to be excluded */
    int*          number_displayable_types,  /**< (O)  Number of the displayable types */
    tag_t**       displayable_types          /**< (OF) number_displayable_types Array of the displayable type tags */
);

/**
    Finds the types for the Business Object that are displayable to the login user in the object creation dialog.
    <br>In addition we get the real and display type names for the displayable types for the connection locale.
*/
extern TCCORE_API int TCTYPE_UIF_find_displayable_business_objects(
    const char*    bo_name,                   /**< (I)  Name of the Business Object */
    int            number_exclusion_bo_names, /**< (I)  Number of the Business Object names to be excluded */
    const char**   exclusion_bo_names,        /**< (I)  Array of the Business Object names to be excluded */
    int*           number_displayable_types,  /**< (O)  Number of the displayable types */
    tag_t**        displayable_types,         /**< (OF) number_displayable_types Array of the displayable type tags */
    char***        type_names,                /**< (OF) number_displayable_types Array of type internal names */
    char***        display_type_names         /**< (OF) number_displayable_types Array of type display names */
);

/**
    Finds the types for the Business Object that are displayable to the login user in object creation dialogs and
    configured in BMIDE to be displayed by generic create dialogs.
    <br>This function behaves similarly to #TCTYPE_UIF_find_displayable_business_objects, except that it also excludes
    types on which the Fnd0EnableUsageOfDialog constant value on the CreateInput is false.
    <br>It also retrieves the internal and display type names for the displayable types. The display names are in
    the server locale.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#TYPE_unknown_type if the Business Object name provided is not that of a known type.
    </ul>
*/
extern TCCORE_API int TCTYPE_UIF_find_generically_creatable_business_objects(
    const char*   bo_name,                    /**< (I)  Internal name of the Business Object */
    int           number_exclusion_bo_names,  /**< (I)  Number of the Business Object names to be excluded from the returned types */
    const char**  exclusion_bo_names,         /**< (I)  Array of the Business Object names to be excluded from the returned types */
    int*          number_displayable_types,   /**< (O)  Number of the displayable types */
    tag_t**       displayable_types,          /**< (OF) number_displayable_types Array of the displayable type tags*/
    char***       type_names,                 /**< (OF) number_displayable_types Array of type internal names */
    char***       display_type_names          /**< (OF) number_displayable_types Array of type display names */
);

/**
    Retrieves the relevant name rule patterns for the properties of a given type.
*/
extern TCCORE_API int TCTYPE_ask_name_rule_patterns(
    const char*   bo_name,                 /**< (I)  Name of the BusinessObject */
    int*          number_property_names,   /**< (O)  Number of properties having name rule patterns. This can be NULL */
    char***       property_names,          /**< (OF) number_property_names Names of properties having name rule patterns. This can be NULL */
    int**         pattern_count,           /**< (OF) number_property_names Array of pattern count for each of the above properties. This can be NULL */
    int*          number_of_patterns,      /**< (O)  Total number of patterns for all the above properties. This can be NULL */
    char***       patterns                 /**< (OF) number_of_patterns All the patterns for all the above properties. This can be NULL */
);

/**
    Retrieves the context during a deferred save operation
*/
extern TCCORE_API int TCTYPE_ask_save_operation_context(
    TCTYPE_save_operation_context_t*    save_operation_context /**< (O) The context during a deferred save operation. */
);


/**
   Retrieves business object types for the specified type category.
   <br>If the category is #TCTYPE_All or #TCTYPE_Root, it returns all the business object types of runtime, persistent and dynamic types.

   @returns
   <ul>
   <li>#ITK_ok on success.
   <li>Possibly other POM errors coming from query executions to retrieve business objects from the database.
   </ul>
*/
extern TCCORE_API int TCTYPE_extent_by_category(
    TCTYPE_category_t       type_category,          /**< (I) The type category */
    int*                    number_of_types,        /**< (O) The number of types found */
    tag_t**                 types                   /**< (OF) number_of_types The found types (NULL if none found) */
);


/**
   @defgroup TCTYPE_MODIFIED_TAG_LISTS Lists of tags for objects that have been modified (changed or deleted)
   @ingroup TCTYPE
   When objects are being modified on the server, it is important that the information be passed on the client(s)
   for the same modifications to be replicated there.
   <br/>The Service Oriented Architecture (SOA) layer takes care of passing the information to the clients.
   It must, however, be first captured through the ITKs in this group.
   <br/><br/>Two lists are managed: the changed objects and the deleted objects.
   @{
*/
    /**
       Adds the specified object (and potentially its properties) to the list of objects that have changed.
       <br/>If the parameter @p properties is a null pointer, all the loaded properties of the object are treated as changed.

       @returns #ITK_ok always
    */
    extern TCCORE_API int TCTYPE_add_to_changed_tag_list(
        tag_t object,           /**< (I) The tag of the object to be added to the list of changed objects. */
        const char* properties  /**< (I) A string separated list of modified properties for this object. */
        );

    /**
       Adds the specified object to the list of objects that have been deleted.

       @returns #ITK_ok always
    */
    extern TCCORE_API int TCTYPE_add_to_deleted_tag_list(
        tag_t object           /**< (I) The tag of the object to be added to the list of deleted objects. */
        );


    /**
       Retrieves the objects that belong to the changed list and those that belong to the deleted list.

       @returns #ITK_ok always
    */
    extern TCCORE_API int TCTYPE_get_modified_tag_list(
        logical clear_lists,         /**< (I)  Indicates if the lists will be reset after this call.
                                        <br/>Valid values are false (do not reset the lists) and true. */
        int*    num_objects,         /**< (O)  The total number of changed and deleted objects. */
        tag_t** tags,                /**< (OF) num_objects The list of tags for the objects. */
        int**   deleted_or_modified, /**< (OF) num_objects Indicates what kind of update that has occurred
                                        on the object: 0 = deleted, 1 = changed. */
        char*** properties           /**< (OF) num_objects Array of property lists (string with property names separated by a comma)
                                        indicating the update that has occurred on the object.
                                        <br/>An empty string denotes an unidentified change (possibly all the properties)
                                        <br/>A value "name_property1,name_property2" denotes changes done to the properties
                                        "name_property1" and "name_property2".
                                        <br/>The array is packed, which means that the memory is deallocated by simply calling #MEM_free
                                        on the container (not its elements). */
        );

    /**
       Removes the specified object from the list of objects that have been updated/changed.

       @returns #ITK_ok always
    */
    extern TCCORE_API int TCTYPE_remove_from_modified_tag_list(
        tag_t object           /**< (I) The tag of the object to be removed from the list of updated/changed objects. */
        );

    /**
        Retrieves the descriptions of specified types.
        @returns
        <ul>
        <li>#ITK_ok always.
        </ul>
    */
    extern TCCORE_API int TCTYPE_ask_type_descriptions(
        const unsigned int n_types,         /**< (I) Number of types for which descriptions are to be retrieved.                                                             */
        const tag_t* types,                 /**< (I) n_types Tags of the types for which descriptions are to be retrieved.                                                   */
        char*** type_descriptions           /**< (OF) n_types The type descriptions. An empty string will be returned if the description for the type could not be retrieved.
                                               <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only.        */
        );

    /**
        Retrieves if the @p type is abstract or not.
        @returns
        <ul>
        <li>#ITK_ok on success
        <li>#TYPE_unknown_type if the @p type is #NULLTAG or invalid
        </ul>
    */
    extern TCCORE_API int TCTYPE_ask_is_abstract( 
        tag_t type,                 /**< (I) The type */
        logical* isAbstract         /**< (O) Indicates if the @p type is abstract or not. */
        );

    /**
    Creates, saves and unlocks objects in bulk using set-based implementation with partial error handling.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ITK_internal_error if @p n_objects is zero or a negative number.
    <li>#ITK_internal_error if @p create_inputs is NULL.
    <li>Possibly other errors.
    </ul>
    */
    extern TCCORE_API int TCTYPE_bulk_create_objects_with_error_details(
        const int        n_objects,             /**< (I) Number of CreateInput objects. */
        const tag_t*     create_inputs,         /**< (I) n_objects The array of CreateInput objects. */
        tag_t**          objects,               /**< (OF) n_objects The created objects. */
        int**            statuses,              /**< (OF) n_objects The statuses for the creation of each Item.
                                                <br/>It will be #ITK_ok on success. */
        char***          error_messages         /**< (OF) n_objects Error messages for errors that might have occurred during the creation of each Item.
                                                <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container.*/
    );

/**
   @}
*/

/**
   Determines if @p type is the same as or a subtype of Fnd0LogicalObject type.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TYPE_unknown_type if @p type is #NULLTAG or does not exist
   </ul>
*/
extern TCCORE_API int TCTYPE_is_logical_type (
    tag_t     type,         /**< (I) The Logical Object Type tag. */
    logical   *answer       /**< (O) Indicates if the @p type is the same as or a subtype of Fnd0LogicalObject type */
    );

/**
   Determines if @p type is the subtype of Fnd0LogicalObject type.

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TYPE_unknown_type if @p type is #NULLTAG or does not exist
   </ul>
*/
extern TCCORE_API int TCTYPE_is_logical_subtype (
    tag_t     type,         /**< (I) The Logical Object Type tag. */
    logical   *answer       /**< (O) Indicates if the @p type is the subtype of Fnd0LogicalObject type */
    );


#ifdef __cplusplus
}
#endif

/** @} */

#include <tccore/libtccore_undef.h>

#endif
