/*HEAD ICS2 HHH CLASSIFICATION */
/*==============================================================================
               Copyright (c) 2003-2005 UGS Corporation
               Unpublished - All Rights Reserved
==============================================================================*/

/**
   @file
   
   Published ITK functions to create/modify in-CLASS Objects
*/

/*  */

#ifndef ICS2_H_INCLUDED
#define ICS2_H_INCLUDED

#include <common/tc_deprecation_macros.h>

/**
   @ingroup ICS

   <b>Common return values:</b>
   #ICS_err_attribute_does_not_exist <br>
   #ICS_err_attribute_not_unique <br>
   #ICS_err_cannot_create_files <br>
   #ICS_err_class_does_not_exist <br>
   #ICS_err_could_not_open_file <br>
   #ICS_err_file_already_exists <br>
   #ICS_err_invalid_value <br>
   #ICS_err_invalid_property <br>
   #ICS_err_invalid_reference_type <br>
   #ICS_err_parent_is_not_shared
   @{
*/

/**
   This value can be used as a value for theOptions parameter in ICS_ico_search().
   In case a class id is passed in as a search criteria,
   this option will restrict the search to the specified class only.
   The default behavior will searach in all classes below the given one as well.
*/
#define ICS_SEARCH_THIS_CLASS_ONLY     ( 1 << 0 )

/**
   This option allows to specify that strings will be searched case insensitive.
   Case sensitive is the default.
*/
#define ICS_SEARCH_CASE_INSENSITIVE    ( 1 << 1 )

/**
   This value can be used as a value for theOptions parameter in ICS_ico_search().
   This option specifies that the search result is sorted by the object id.
   The default behaviour is, that the search result is sorted by attributes, if
   attributes are given. If no attributes are given, the search result is sorted
   by the object id by default.
*/
#define ICS_SEARCH_ORDER_BY_ID           ( 1 << 2 )

/**
   This value can be used as a value for theOptions parameter in ICS_ico_search().
   This option specifies that the search result will contain metric and non-metric instances.
   By default only metric or non-metric will be found depending on the active unit system.
*/
#define ICS_SEARCH_IN_BOTH_UNIT_SYSTEMS  ( 1 << 3 )

/**
   This value can be used as a value for theOptions parameter in ICS_ico_search().
   This option specifies that the search result will contain only instances of the other unit system than the active one.
*/
#define ICS_SEARCH_IN_OTHER_UNIT_SYSTEM  ( 1 << 4 )



#define ICS_ICO_IGNORE_WRITE_PROTECTION_ERRORS  ( 1 << 0 )

#define ICS_MAX_CLASS_ATTR_SIZE  10

#define ICS_DBL_STR_SIZE 64


/**
   Defines valid values which can be used for theClassFlags parameter of #ICS_class_create
*/

typedef enum ICS_class_flags_s {
    CLASS_flag_englishUnitBase  = (1 << 0),
    CLASS_flag_isGroup          = (1 << 1),
    CLASS_flag_unit_system_both = (1 << 2),
    CLASS_flag_isStorrageClass  = (1 << 4),
    CLASS_flag_isAssembly       = (1 << 5)
} ICS_class_flags_e;

typedef enum ICS_class_properties_s {
    CLASS_prop_id      = -600,  /**< G */
    CLASS_prop_parents = -603,  /**< G */
    CLASS_prop_name    = -607   /**< GS */
} ICS_class_properties_e;


typedef int(* ICS_auto_compute_function_t)( tag_t, int );

typedef struct ICS_auto_compute_attr_s
{
    int auto_compute_attr_id;                           /**< Attribute id of the attribute to be auto computed */
    ICS_auto_compute_function_t auto_compute_function;  /**< Pointer to the function which computes the value or property of this attribute */
    int num_attr_deps;                                  /**< Number of other attributes from this class used for auto computation */
    int attr_deps[ICS_MAX_CLASS_ATTR_SIZE];             /**< Attribute ids of dependent attributes */
}ICS_auto_compute_attr_t;


/**
   Defines the structure to hold configured KeyLOV description for a specific class attribute.
*/
typedef struct ICS_keylov_descriptor_s
{
    int      attribute_id;        /**< Class Attribute ID */
    char*    keylov_id;           /**< Keylov ID */
    char*    keylov_name;         /**< Keylov Name */
    tag_t    keylov_tag;          /**< Keylov tag */
    char*    owning_site;         /**< Keylov owning site */
    int      num_shared_sites;    /**< number of shared sites */
    char**   shared_sites;        /**< Keylov owning site */
    int      flags;               /**< Keylov flags */
    int      value_count;         /**< number of values */
    char**   keys;                /**< keys */
    char**   values;              /**< values */
    logical* deprecation_status;  /**< deprecation status */
    char*    selected_key;        /**< selected key */
}ICS_keylov_descriptor_t, *ICS_keylov_descriptor_p_t;


/**
   Defines the list of available auto compute modes
*/
typedef enum ICS_auto_compute_mode_s {
    AUTOCOMPUTE_MODE_load = 0,      /**< manipulate attribute properties based on the input values and the custom logic in place
                                       This mode will not manipulate any attribute values as this is used during loading,
                                       and the values are already available in the database */
    AUTOCOMPUTE_MODE_create = 1,    /**< perform all the operations in the custom logic to manipulate attribute values as well as properties
                                       based on the default values */
    AUTOCOMPUTE_MODE_edit = 2       /**< perform all the operations in the custom logic to manipulate attribute values as well as properties
                                       based on the updated values */
} ICS_auto_compute_mode_e;


/**
   Defines the list of possible values for the unit system
*/
typedef enum ICS_unit_system_s {
    UNIT_SYSTEM_unspecified = -1,
    UNIT_SYSTEM_metric      = 0,
    UNIT_SYSTEM_english     = 1
} ICS_unit_system_e;

/**
   Defines valid values for the flags property of the class attributes
*/
typedef enum ICS_class_attr_flags_s {
    CLASS_ATTR_vla           = (1 << 0),
    CLASS_ATTR_external_vla  = (1 << 1),
    CLASS_ATTR_mandatory     = (1 << 2),
    CLASS_ATTR_protected     = (1 << 3),
    CLASS_ATTR_unique        = (1 << 4),
    CLASS_ATTR_propagated    = (1 << 5),
    CLASS_ATTR_localValue    = (1 << 6),
    CLASS_ATTR_reference     = (1 << 7),
    CLASS_ATTR_auto_computed = (1 << 15),
    CLASS_ATTR_hidden        = (1 << 20),
    CLASS_ATTR_localizable   = (1 << 22),
    CLASS_ATTR_use_as_facet  = (1 << 30)
    /*  */

} ICS_class_attr_flags_e;

/**
   Defines the list of available view types
*/
typedef enum ICS_view_type_s {
    VIEW_type_subclass = 0,     /**< Leagacy type view where instances are stored in */
    VIEW_type_defaultView = 1,  /**< Default view with fixed Name "defaultView" will be created automatically
                                   if it does not exist */
    VIEW_type_user = 2,
    VIEW_type_group = 3,
    VIEW_type_role = 4,          /**< Currently not supported */
    VIEW_type_project = 5,
    VIEW_type_table = 6,
    VIEW_type_indexing = 7,
    VIEW_type_template_view = 100,
    VIEW_type_mapping_internal      = 200,
    VIEW_type_mapping_user          = 201,
    VIEW_type_nxlib_search_criteria = 202,
    VIEW_type_nxlib_search_result   = 203,
    VIEW_type_nxlib_retrieve        = 204
} ICS_view_type_e;

/**
   Defines the list of availabe types for #ICS_ask_children
*/
typedef enum ICS_child_type_s {
    ICS_CHILD_type_group             = (1 << 0),
    ICS_CHILD_type_class             = (1 << 1),
    ICS_CHILD_type_view              = (1 << 2), /**< All type of views including subclasses */
    ICS_CHILD_type_view_no_subclass  = (1 << 3), /**< Real views only */
    ICS_CHILD_type_subclass          = (1 << 4), /**< Subclasses only */
    ICS_CHILD_type_template_view     = (1 << 5), /**< Template views only */
    ICS_CHILD_type_all      = ICS_CHILD_type_group | ICS_CHILD_type_class | ICS_CHILD_type_view
} ICS_child_type_e;

/**
   ICS_class_share_type_e defines the list of availabe types for ICS_class_share_incl_children
*/
typedef enum ICS_class_share_type_s {
    ICS_CLASS_SHARE_child_classes = (1 << 1),
    ICS_CLASS_SHARE_default_views  = (1 << 2),
    ICS_CLASS_SHARE_specific_views = (1 << 3), /**< user, group, and role views (specified in the preference ICS_share_viewtypes) */
    ICS_CLASS_SHARE_subclasses      = (1 << 4), /**< subclasses only */
    ICS_CLASS_SHARE_views         = ( ICS_CLASS_SHARE_default_views | ICS_CLASS_SHARE_specific_views | ICS_CLASS_SHARE_subclasses ),
    ICS_CLASS_SHARE_all           = ( ICS_CLASS_SHARE_child_classes | ICS_CLASS_SHARE_views )
} ICS_class_share_type_e;

/**
   Defines the options for the ITK function ICS_class_list_children2.
*/
typedef enum ICS_list_children_options_s {
    ICS_CHILDREN_NO_COUNT       = 0       , /**< */
    ICS_CHILDREN_INSTANCE_COUNT = (1 << 0), /**< Get the instance count for each child*/
    ICS_CHILDREN_CHILD_COUNT    = (1 << 1), /**< Get the children count for each child*/
    ICS_CHILDREN_VIEW_COUNT     = (1 << 2), /**< Get the view count*/
    ICS_CHILDREN_INCLUDE_HIDDEN_INSTANCES = (1 << 4), /**< Include hidden instances on instance count*/
    ICS_CHILDREN_ALL_COUNT      = ICS_CHILDREN_INSTANCE_COUNT | ICS_CHILDREN_CHILD_COUNT | ICS_CHILDREN_VIEW_COUNT
} ICS_list_children_options_e;

/**
   Specifies that a Classification class attribute uses the Reference Attribute definition that
   is set in the Classification dictionary.
*/
#define ICS_REFATTR_INHERITED         1

/**
   Specifies that a Classification class attribute uses the Reference Attribute definition that
   is set locally in the Classification class.
*/
#define ICS_REFATTR_CLASS_LOCAL       2

/**
   Reference Attribute type "classified object" (property or attribute of the classified object)
*/
#define ICS_REFATTR_CLASSIFIED_OBJECT 1
/**
   Reference Attribute type "master form" (property or attribute of the master form of the
   classified object).
*/
#define ICS_REFATTR_MASTERFORM        2
/**
   Reference Attribute type "related object" (property or attribute of an object that is related
   to the classified object).
*/
#define ICS_REFATTR_RELATED_OBJECT    3

/**
   Reference Attribute type "ico" (attribute of a different ico).
*/
#define ICS_REFATTR_ICO               4

/**
   The Reference Attribute value is read from the classified item OR (if the classified object
   is an item revision) from the item of the classified item revision
*/
#define ICS_REFATTR_ITEM_ATTR         1
/**
   The Reference Attribute specifies a TC property (not a POM attribute)
*/
#define ICS_REFATTR_PROPERTY          ( 1 << 1 )

/**
   Internal use only.
*/
#define ICS_SUBCLASSES_TO_STORAGE_CLASSES ( 1 )

/**
   Copy the class even if it has unreadable children.
*/
#define ICS_IGNORE_UNREADABLE_CHILDREN    ( 1 << 1 )

/**
   Copy the class including its inherited attributes.
*/
#define ICS_COPY_INHERITED_ATTRIBUTES     ( 1 << 2 )

/**
   Don't actually copy the class / migrate the subclasses, only do the initial checks.
*/
#define ICS_DRY_RUN                       ( 1 << 3 )

/**
   Copy the class only, not the hierarchy.
*/
#define ICS_COPY_THIS_CLASS_ONLY          ( 1 << 4 )

#define ICS_SHARED_IS_ERROR               ( 1 << 5 )

/**
   Add attributes from new parent class to copy of view
*/
#define ICS_ADD_ATTRBIUTES_FROM_PARENT    ( 1 << 6 )


#define ICS_DEFAULT_VIEW "defaultView"

/**
   Don't stop moving part family templates if source attributes are mapped that do not exist in the target.
*/
#define ICS_IGNORE_MAPPING_ERRORS         ( 1 )

/**
   if this option is passed to the function ICS_class_add_attributes() the function will try to remove
   the atrribute from any descendant and update the instances accordingly
*/
/*  NOTE: The value of this definition must be in sync of the corresponding definition in sml_defines.h */
#define ICS_ADD_ATTRIBUTE_MOVE_UP ( 1 << 0 )

#define ICS_CLASS_USE_VIEW_IMAGE ( 1 << 0 )

#include <ics/libics_exports.h>


#ifdef __cplusplus
extern "C"{
#endif

    /**
       @name Class related Functions

       <b>Common return values:</b>

       #ICS_err_attribute_does_not_exist <br>
       #ICS_err_cannot_create_files <br>
       #ICS_err_class_does_not_exist <br>
       #ICS_err_could_not_open_file <br>
       #ICS_err_file_already_exists <br>
       #ICS_err_invalid_property <br>
       #ICS_err_invalid_reference_type <br>
       #ICS_err_invalid_value <br>
       #ICS_err_parent_is_not_shared <br>
       @{
    */

    /**
       Checks whether a class with the given classId exists in the database

       <b>Return values:</b>

       true  : class exists <br>
       false : a class with this id does not exist
    */
    extern ICS_API logical ICS_class_exists(
        const char*        theClassId     /**< (I) The unique id of an existing class */
        );

    /**
       Creates a new class as child of the given parent. The class is immediately created in the database.
    */
    extern ICS_API int ICS_class_create(
        const char*    theClassId,     /**< (I) The unique id of the new class */
        const char*    theParentId,    /**< (I) The unique id of the existing parent this should belong to */
        const char*    theName,        /**< (I) The display name of the new class */
        int            theClassFlags,  /**< (I) Flags to configure the class */
        int            theAttrCount,   /**< (I) The number of attributes to add to the class valid range is 0 to 100 */
        int*           theAttrIds      /**< (I) The attribute id's to be added to the class.
                                          The attributes must exist in the dictionary. */
        );

    /**
       Creates a new class as child of the given parent. A new id for this class will be generated and returned.
    */
    extern ICS_API int ICS_class_create_unique( const char* theParentId,    /**< (I) the unique id of the existing parent this should belong to */
                                                const char* theName,        /**< (I) the 'display' Name of the new class */
                                                int         theClassFlags,  /**< (I) Flags to configure the class */
                                                int         theAttrCount,   /**< (I) the number of attributes to add to the class valid range is 0 to 100*/
                                                int        *theAttrIds,     /**< (I) the attribute id's to be added to the class. The Attributes must exist in the dictionary. */
                                                char*      *theNewClassId   /**< (OF) the new generated unique id of the new class */
        );

    /**
       Permanently removes the class from the database

       @note Classes can only be removed if the are not referenced by child classes, views, or instances
    */
    extern ICS_API int ICS_class_remove(
        const char*    theClassId   /**< (I) The unique id of an existing class */
        );

    /**
       Saves unsaved modifications to the database.
       All functions that require a call to this function are explicitly marked.
    */
    extern ICS_API int ICS_class_save(
        const char*    theClassId   /**< (I) The unique id of the class */
        );

    /**
       Reloads the class definition from the database.
       All changes made be any function call that requires the use of ICS_class_save() will be lost.
    */
    extern ICS_API int ICS_class_refresh(
        const char*    theClassId   /**< (I) The unique id of the class */
        );

    /**
       This has the same functionality as ICS_class_refresh()
    */
    extern ICS_API int ICS_class_cancel(
        const char*    theClassId   /**< (I) The unique id of the class */
        );

    /**
       Sets the given property value for the specified property

       @note This function requires a subsequent call to ICS_class_save() to commit the changes to the database
    */
    extern ICS_API int ICS_class_set_property(
        const char*    theClassId,          /**< (I) The unique id of an existing class */
        const char*    thePropertyName,     /**< (I) The id of the property to set. Possible values are: <br>
                                               PARENT, NAME, SHORT_NAME, FLAGS <br>
                                               UNITSYSTEM, ABSTRACT, ISASSEMBLY <br>
                                               MULTIINST, USER1, USER2 */
        const char*    thePropertyValue     /**< (I) The value for the property */
        );

    /**
       Returns the value for the specified property of an existing class
    */
    extern ICS_API int ICS_class_ask_property(
        const char*    theClassId,          /**< (I) The unique id of an existing class */
        const char*    thePropertyName,     /**< (I) The id of the property to set. Possible values: <br>
                                               CID, ISAGROUP, NUM_SHARED_SITES, ATTR_COUNT <br>
                                               also see ICS_class_set_property() */
        char**         thePropertyValue     /**< (OF) The value for the property needs to be freed using #MEM_free */
        );

    /**
       Adds the given shared site.

       @note This function requires a subsequent call to ICS_class_save()
       to commit the changes to the database
    */
    extern ICS_API int ICS_class_add_shared_site(
        const char*    theClassId,              /**< (I) The unique id of an existing class */
        const char*    theSharedSite,           /**< (I) The name of the shared site */
        logical        approveShareOfParents    /**< (I) A class can only be shared,
                                                   if its parents are shared. <br>
                                                   false: if the parents are not shared
                                                   theSharedSite will not be added <br>
                                                   true:  if the parents are not shared
                                                   theSharedSite will be added to the
                                                   specified class and its parents */
        );

    /**
       Returns the count and the values of the shared sites
    */
    extern ICS_API int ICS_class_ask_shared_sites(
        const char*    theClassId,      /**< (I) The unique id of an existing class */
        int*           theSiteCount,    /**< (O) The number of shared sites */
        char***        theSharedSites   /**< (OF) theSiteCount The shared sides.
                                           Need to be freed using #MEM_free */
        );

    /**
       Set the alias names for the class. Any previously existing alis names will be overwitten.
       This function can be used to remove all alias names by setting theCount = 0

       @note This function requires a subsequent call to ICS_class_save()
       to commit the changes to the database
    */
    extern ICS_API int ICS_class_set_alias_names(
        const char*  theClassId,   /**< (I) The unique id of an existing class */
        int          theCount,     /**< (I) The number of alias names to set   */
        const char** theLanguages, /**< (I) The optional language identifiers of the alias names. Need to be at least an empty string (not NULL)  */
        const char** theAliasNames /**< (I) The alias names  */
        );

    /**
       Add a new alias name to existing list of alias names

       @note This function requires a subsequent call to ICS_class_save()
       to commit the changes to the database
    */
    extern ICS_API int ICS_class_add_alias_name(
        const char* theClassId,   /**< (I) The unique id of an existing class */
        const char* theLanguage,  /**< (I) The number of alias names to set   */
        const char* theAliasName  /**< (I) The alias name */
        );


    /**
       returns all alias names of the class.

    */
    extern ICS_API int ICS_class_ask_alias_names(
        const char*  theClassId,     /**< (I) The unique id of an existing class */
        int          *theCount,      /**< (OF) The number of alias names to set   */
        char**       *theLanguages,  /**< (OF) The optional language identifiers of the alias names. Might be "" */
        char**       *theAliasNames  /**< (OF) The alias names */
        );

    /**
       Imports a document for this class. An existing image will be overwritten.
       A document can be the class image or icon or any other type of document.
    */
    extern ICS_API int ICS_class_import_document(
        const char*    theClassId,          /**< (I) The unique id of an existing class */
        const char*    theDocumentType,     /**< (I) Possible values are: <br>
                                               Image <br>
                                               Icon */
        const char*    theFileName          /**< (I) The name of the file to be imported */
        );

    /**
       Exports all documents of the given type attached to this class
    */
    extern ICS_API int ICS_class_export_document(
        const char*    theClassId,              /**< (I) The unique id of an existing class */
        const char*    theDocumentType,         /**< (I) For possible values see ICS_class_import_document() */
        const char*    theOutputDirectory,      /**< (I) The directory name to put the files into */
        logical        overwriteExistingFiles,  /**< (I) */
        int*           theFileCount,            /**< (O) The number of files exported */
        char***        theFileNames             /**< (OF) theFileCount the names of the files put into theOutputDirectory */
        );

    extern ICS_API int ICS_class_ask_document_fileId(
        const char*    theClassId,          /**< (I) The unique id of an existing class */
        const char*    theDocumentType,     /**< (I) For possible values see ICS_class_import_document() */
        char**         theFileId            /**< (OF) */
        );

    /**
       Returns the types and tags of all documents according to the dataset of the given class

       All parameters ecept for theClassId accept NULL pointer to indicate that this parameter should not be returned
    */
    extern ICS_API int ICS_class_ask_documents(
        const char*    theClassId,          /**< (I) The unique id of an existing class */
        int*           theDocumentCount,    /**< (O) The number of named references */
        char***        theDocumentTypes,    /**< (OF) theDocumentCount The reference names of the documents */
        tag_t**        theDocumentTags      /**< (OF) theDocumentCount The tags of the documents */
        );

    /**
       Remove all images assigned to this class
    */
    extern ICS_API int ICS_class_remove_document(
        const char*    theClassId,          /**< (I) The unique id of an existing class */
        const char*    theDocumentType      /**< (I) For possible values see ICS_class_import_document() */
        );

    /**
       Adds the given attributes to an existing class <br>
       Note: this function returns SML_ERR_NO_INSTANCE_FOUND if the class does not exist
    */
    extern ICS_API int ICS_class_add_attributes(
        const char*    theClassId,      /**< (I) The unique id of an existing class */
        int            theAttrCount,    /**< (I) The number of attributes to add to the class valid range is 0 to 100 */
        int*           theAttrIds       /**< (I) The attribute id's to be added to the class.
                                           The Attributes must exist in the dictionary. */
        );

    /**
       Extends  ICS_class_add_attributes by adding theOptions paramter.
    */
    extern ICS_API int ICS_class_add_attributes2( const char *theClassId,     /**< (I) The unique id of an existing class. */
                                                  int         theAttrCount,   /**< (I) The number of attributes to add to the class valid range is 0 to 100 */
                                                  int        *theAttrIds,     /**< (I) The attribute id's to be added to the class.
                                                                                 The Attributes must exist in the dictionary. */
                                                  int         theOptions      /**< (I) Possible values are:
                                                                                 ICS_ADD_ATTRIBUTE_MOVE_UP: Will remove the attribute to add in any descendant
                                                                                 and update the ICOs accordingly.
                                                                                 This will only work for local classes/hierarchies */
        );

    /**
       Returns all attributes of the given class
    */
    extern ICS_API int ICS_class_ask_attributes(
        const char*    theClassId,          /**< (I) The unique id of an existing class */
        int*           theAttributeCount,   /**< (O) The attribute count */
        tag_t**        theAttributeTags,    /**< (O) The tags of attributes */
        int**          theAttributeIds      /**< (OF) theAttributeCount */
        );

    /**
       Remove the given attributes from the class.

       @note Attributes can only be removed under certain restrictions.
    */
    extern ICS_API int ICS_class_remove_attributes(
        const char*    theClassId,      /**< (I) The unique id of an existing class */
        int            theAttrCount,    /**< (I) The number of attributes to remove from the class */
        int*           theAttrIds       /**< (I) The attribute IDs to be removed from the class */
        );

    /**
       Sets the property value for the property in the specified attribute of the class

       @note This function requires a subsequent call to ICS_class_save() to commit the changes to the database
       @note If you want to set the ATTRIBUTEID please use the following ITK functions:<br>
       ICS_class_remove_attributes() and ICS_class_add_attributes()

    */
    extern ICS_API int ICS_class_set_attr_property(
        const char*    theClassId,          /**< (I) The unique id of an existing class */
        int            theAttributeId,      /**< (I) The id of the attribute to set the property in. */
        const char*    thePropertyName,     /**< (I) The id of the property to set
                                               Possible values are: <br>
                                               ANNOTATION, MIN, MAX, FLAGS, <br>
                                               MANDATORY, PROTECTED, UNIQUE, PROPAGATED, <br>
                                               ARRAY_SIZE, ARRAY, EXTERNAL_ARRAY, REFERENCE, <br>
                                               LOCAL_VALUE, USER1, USER2 */
        const char*    thePropertyValue     /**< (I) The value for the property */
        );

    /**
       Asks for the value of the property in the specified attribute of the class
    */
    extern ICS_API int ICS_class_ask_attr_property(
        const char*    theClassId,          /**< (I) The unique id of an existing class */
        int            theAttributeId,      /**< (I) The id of the attribute to set the property in */
        const char*    thePropertyName,     /**< (I) The id of the property to ask.
                                               For possible values see ICS_class_set_attr_property()
                                               and additionally SMINDEX, DBINDEX, CID, _NAME, _FORMAT, LOCAL_USER1, LOCAL_USER2 */
        char**         thePropertyValue     /**< (OF) The value for the property. Needs to be freed using #MEM_free. */
        );


    /*===+++========================================================================
    **  ICS_class_search returns information about the classes found by evaluating theQuery
    **
    **                                3     attribute name
    **            theSortOption  : specifies the attribute to be used for sorting the result
    **                             Supported values are:
    **                               -600  class id (default if 0 or any invalid value is specified )
    **                               -607  class name
    **                               -608  class short name
    **                               -612  user data 1
    **                               -613  user data 2
    **
    **            theCount       : the number of classes matching theQuery
    **
    **           NOTE: The input to all following values can be NULL to indicate
    **                 that the output should not be returned.
    **
    **            theTags            : the tags of the found classes
    **            theTypes           : the types of the classes
    **                                   Posible values are: Group, Class, StorrageClass
    **            theCIDs            : the unique class ids
    **            theName            : the class names
    **            theInstancesCounts : the number of instances stored in each class (including subclass instances)
    **            theChildCounts     : the number of  children (of type Group,Class or StorrageClass) each class has
    **            theViewCounts      : the number of views for each class
    **            theSubClassCounts  : the number of SML-SubClasses for each class
    **
    **
    ** Return value :
    **                ITK_OK
    **                Error discovered
    **
    */
    extern ICS_API int ICS_class_search( const char*   theQuery,           /**< (I)  Expression of type attributeId operator value
                                                                              Supported values for attributeId are: <br>
                                                                              -600  class id <br>
                                                                              -607  class name <br>
                                                                              -601  class type <br>
                                                                              -608  short name <br>
                                                                              -602  group id <br>
                                                                              -612  user data 1 <br>
                                                                              -613  user data 2 <br>
                                                                              8     attribute id <br>
                                                                              3     attribute name    */
                                         int           theSortOption,      /**< (I) Attribute Id to sort by*/
                                         int          *theCount,           /**< (O) Number classes found */
                                         tag_t       **theTags,            /**< (OF) Tgas of the classes found */
                                         char*       **theTypes,           /**< (OF) theCount Types of the classe */
                                         char*       **theCIDs,            /**< (OF) theCount Ids of the classe */
                                         char*       **theNames,           /**< (OF) theCount Names of the classes */
                                         int         **theInstancesCounts, /**< (OF) Number of instances stored in the class and any child class */
                                         int         **theChildCounts,     /**< (OF) Number of children of the class */
                                         int         **theViewCounts,      /**< (OF) Number of views of the class */
                                         int         **theSubClassCounts   /**< (OF) Number of subclasses of the class */
        );

    /**
       Retrieves the tag and the id of the parent of the given class  <br>

       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#SML_ERR_NO_INSTANCE_FOUND if the class ID does not exist
       </ul>
    */
    extern  ICS_API int ICS_class_ask_parent(
        const char*     theClassId,     /**< (I) The unique id of an existing class */
        tag_t*          theParentTag,   /**< (O) The tag of the Parent */
        char**          theParentId     /**< (OF) The Parent's Id */
        );

    /**
       Retrieves the parents for the specified class of an existing class <br>

       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#SML_ERR_NO_INSTANCE_FOUND if the class ID does not exist
       </ul>
    */
    extern ICS_API int ICS_class_ask_parents(
        const char*    theClassId,      /**< (I) The unique id of an existing class */
        logical        includeGroups,   /**< (I) False : only parents of type class (where the given class inherits from) are returned <br>
                                           True  : the groups up to and including SAM are returned as well */
        int*           theParentCount,  /**< (O) The number of classes returned */
        tag_t**        theParentTags,   /**< (OF) theParentCount The list of unique id's of the parents <br>
                                           null if theParentCount == 0 <br>
                                           Needs to be freed using #MEM_free */
        char***        theParentIds     /**< (OF) theParentCount The list of unique id's of the parents <br>
                                           null if theParentCount == 0 <br>
                                           Needs to be freed using #MEM_free */
        );

    /**
       Retrieves the children for the specified class of an existing class
    */
    extern ICS_API int ICS_class_ask_children(
        const char*    theClassId,          /**< (I) The unique id of an existing class */
        int            theChildTypeFilter,  /**< (I) The following values from #ICS_child_type_e: <br>
                                               #ICS_CHILD_type_class <br>
                                               #ICS_CHILD_type_view */
        int*           theChildCount,       /**< (O) The number of classes returned */
        char***        theChildren          /**< (OF) theChildCount The list of unique id's of the childern <br>
                                               null if theChildCount == 0. Needs to be freed using #MEM_free */
        );

    /**
       Retrieves the children for the specified class of an existing class

       The following parameters accept NULL pointer to indicate that this parameter should not be returned:

       theChildCount, theChildernTags, theChildrenIds, theChildrenTypes

       @note The legacy objects SMLClass and SMLSubClass are treated as class and storageClass
    */
    extern ICS_API int ICS_class_list_children(
        const char*    theClassId,          /**< (I) The unique id of an existing class */
        int            theChildTypeFilter,  /**< (I) The following values from #ICS_child_type_e: <br>
                                               #ICS_CHILD_type_class <br>
                                               #ICS_CHILD_type_view */
        int            theSortOption,       /**< (I) */
        int*           theChildCount,       /**< (O) The number of classes returned */
        tag_t**        theChildrenTags,     /**< (OF) theChildCount The POM tags of the children */
        char***        theChildrenIds,      /**< (OF) theChildCount The unique id's of the childern */
        char***        theChildrenTypes,    /**< (OF) theChildCount The types of the children <br>
                                               Group <br>
                                               Class <br>
                                               StorrageClass <br>
                                               View */
        char***        theChildrenNames,    /**< (OF) The (display) names of the children */
        int**          theInstanceCounts,   /**< (OF) The number of instances stored in the class and all its descendents */
        int**          theChildrenCounts,   /**< (OF) The number of child classes for each child */
        int**          theViewCounts        /**< (OF) The number of view for each child */
        );

    /**
       Provides the same values as #ICS_class_list_children
       with the exception that:
       <ul>
       <li>Instead of childrenTags childrenUid will be transfered.
       <li>This method will be used until the web itk binding functionality
       for arrays of tags is fixed.
       </ul>
    */
    extern ICS_API int ICS_WEB_class_list_children( const char *theClassId,       /**< (I)>  */
                                                    int         theChildTypeFilter,   /**< (I)  */
                                                    int         theSortOption,        /**< (I)  */
                                                    int         *theChildCount,       /**< (O)  */
                                                    char*       **theChildrenUid,     /**< (OF) theChildCount */
                                                    char*       **theChildrenIds,     /**< (OF) theChildCount */
                                                    char*       **theChildrenTypes,   /**< (OF) theChildCount */
                                                    char*       **theChildrenNames,   /**< (OF) theChildCount */
                                                    int         **theInstanceCounts,  /**< (OF) theChildCount */
                                                    int         **theChildrenCounts,  /**< (OF) theChildCount */
                                                    int         **theViewCounts       /**< (OF) theChildCount */
        );


    /**
       Retrieves the children for the specified class of an existing class

       The following parameters accept NULL pointer to indicate that this parameter should not be returned:

       theChildCount, theChildernTags, theChildrenIds, theChildrenTypes

       @note The legacy objects SMLClass and SMLSubClass are treated as class and storageClass
    */
    extern ICS_API int ICS_class_list_children2(
        const char*    theClassId,          /**< (I) The unique id of an existing class */
        int            theChildTypeFilter,  /**< (I) The following values from #ICS_child_type_e: <br>
                                               #ICS_CHILD_type_class <br>
                                               #ICS_CHILD_type_view */
        int            theSortOption,       /**< (I) */
        int            theOptions,          /**< (I) The options for the children search: <br>
                                               #0
                                               #ICS_CHILDREN_INSTANCE_COUNT
                                               #ICS_CHILDREN_CHILD_COUNT
                                               #ICS_CHILDREN_VIEW_COUNT
                                               #ICS_CHILDREN_ALL_COUNT
                                               #ICS_CHILDREN_INCLUDE_HIDDEN_INSTANCES */
        int*           theChildCount,       /**< (O)  The number of classes returned */
        tag_t**        theChildrenTags,     /**< (OF) theChildCount The POM tags of the children */
        char***        theChildrenIds,      /**< (OF) theChildCount The unique id's of the childern */
        char***        theChildrenTypes,    /**< (OF) theChildCount The types of the children <br>
                                               Group <br>
                                               Class <br>
                                               StorrageClass <br>
                                               View */
        char***        theChildrenNames,    /**< (OF) theChildCount The (display) names of the children */
        int**          theInstanceCounts,   /**< (OF) theChildCount The number of instances stored in the class and all its descendents */
        int**          theChildrenCounts,   /**< (OF) theChildCount The number of child classes for each child */
        int**          theViewCounts,       /**< (OF) theChildCount The number of view for each child */
        char***        theIconImageTickets, /**< (OF) theChildCount The icon image ticket for each child */
        char***        theClassImageTickets /**< (OF) theChildCount The class image ticket for each child */
        );


    /**
       Retrieves the most important information about a class

       @note If theClassId has the format xxx::yyy it is treated as a legacy SMLSubClass
    */
    extern ICS_API int ICS_class_describe(
        const char*    theClassId,          /**< (I) The unique id of an existing class */
        char**         theParent,           /**< (OF) The id of the parent class or group */
        int*           theType,             /**< (O) Group, Class, StorageClass */
        char**         theName,             /**< (OF) The display name for the class */
        char**         theShortName,        /**< (OF) An optional short version of theName */
        char**         theDescription,      /**< (OF) A user oriented description of the class */
        char**         theUserData1,        /**< (OF) Customer specific values not used by UGS */
        char**         theUserData2,        /**< (OF) Customer specific values not used by UGS */
        int*           theOptions,          /**< (O) Bit encoded values from #ICS_class_flags_e */
        int*           theInstanceCount,    /**< (O) The number of instances stored in this class or any of its children */
        int*           theChildrenCount,    /**< (O) The number of children of this class */
        int*           theViewCount         /**< (O) The number of views defined for this class */
        );

    /**
       @note The Attributes returned by this function are filtered through
       the view defined for the user of this call
    */
    extern ICS_API int ICS_class_describe_attributes(
        const char*    theClassId,          /**< (I) The unique id of an existing class */
        int*           theCount,            /**< (O) The number of attributes of this class */
        int**          theIds,              /**< (OF) theCount The attribute id */
        char***        theNames,            /**< (OF) theCount The display name */
        char***        theShortNames,       /**< (OF) theCount The short version of the display name */
        char***        theAnnotations,      /**< (OF) theCount The annotation */
        int**          theArraySize,        /**< (OF) theCount 1 for non vla attributes, > 1 for vla attribute */
        int**          theFormat,           /**< (OF) theCount The internal format definition.
                                               Use ICS_describe_format() to get details. */
        char***        theUnit,             /**< (OF) theCount */
        char***        theMinValues,        /**< (OF) theCount Minimum allowed value ( valid for integer and float attributes) */
        char***        theMaxValues,        /**< (OF) theCount Maximum allowed value ( valid for integer and float attributes) */
        char***        theDefaultValues,    /**< (OF) theCount Default value for new Instances */
        char***        theDescriptions,     /**< (OF) theCount The attribute description from the dictionary */
        int**          theOptions           /**< (OF) theCount Bit encoded values from #ICS_class_attr_flags_e */
        );




    /**
       Retrieves the definition of a view given the view tag.

       <b>Restrictions:</b>
       This function can only be used with views.
    */
    extern ICS_API int ICS_view_describe_view (
        tag_t          view,                /**< (I) Tag of the view */
        int*           nAttributes,         /**< (O) Number of attributes defined for the given view */
        int**          uncts,               /**< (OF) nAttributes UNCT's of the attributes */
        int**          formats,             /**< (OF) nAttributes Attributes formats */
        int**          nonMetricFormats,    /**< (OF) nAttributes Attributes Non Metric formats */
        char***        attributeIds,        /**< (OF) nAttributes Attribute Ids */
        char***        attributeNames,      /**< (OF) nAttributes Attribute names */
        char***        shortNames,          /**< (OF) nAttributes Short names for the attributes */
        char***        units,               /**< (OF) nAttributes Units for the attributes (NULL if no unit is defined for the attribute) */
        char***        configBefore,        /**< (OF) nAttributes  */
        char***        configField,         /**< (OF) nAttributes  */
        char***        configAfter,         /**< (OF) nAttributes  */
        int**          flags,               /**< (OF) nAttributes  */
        char***        metricMin,           /**< (OF) nAttributes Metric Minimum values for the attributes */
        char***        metricMax,           /**< (OF) nAttributes Metric Maximum values for the attributes */
        char***        nonMetricMin,        /**< (OF) nAttributes Non Metric Minimum values for the attributes */
        char***        nonMetricMax,        /**< (OF) nAttributes Non Metric Maximum values for the attributes */
        char***        metricDefaultValue,  /**< (OF) nAttributes Metric Default values for the attributes */
        char***        nonMetricDefaultValue/**< (OF) nAttributes Non Metric Default values for the attributes */
        );

    /**
       @deprecated #ICS_class_ask_icos deprecated in Teamcenter 11.2.2. Use #ICS_ico_search instead.

       Retrieves all instances (ICOs) of the given class
       The following parameters accept NULL pointer to indicate that this parameter should not be returned:
       theICOTags, theICOUIDs, theICOIds, theClassId, theWSOTag
    */
    TC_DEPRECATED("11.2.2","ICS_class_ask_icos","ICS_ico_search")
    extern ICS_API int ICS_class_ask_icos(
        const char*    theClassId,              /**< (I) The unique id of an existing class */
        logical        includeFromChildren,     /**< (I) */
        int*           theCount,                /**< (O) The number of ICO tags returned */
        tag_t**        theICOTags,              /**< (OF) theCount The list of ICOs of the given class */
        char***        theICOUIDs,              /**< (OF) theCount */
        char***        theICOIds,               /**< (OF) theCount The IDs of the ICOs */
        char***        theClassIds,             /**< (OF) theCount The class ids of the ICOs */
        tag_t**        theWSOTags,              /**< (OF) theCount The tags of the objects the ICOs are classifying */
        char***        theWSOUIDs               /**< (OF) theCount */
        );

    /**
       @deprecated #ICS_class_search_icos deprecated in Teamcenter 11.2.2. Use #ICS_ico_search instead.
    */
    TC_DEPRECATED("11.2.2","ICS_class_search_icos","ICS_ico_search")
    extern ICS_API int ICS_class_search_icos(
        const char*    theClassId,          /**< (I) */
        logical        searchInChildren,    /**< (I) */
        int            theExpressionCount,  /**< (I) */
        int*           theAttrIds,          /**< (I) */
        char**         theAttrExpressions,  /**< (I) */
        int*           theCount,            /**< (O) */
        tag_t**        theICOTags,          /**< (OF) theCount */
        char***        theICOUIDs,          /**< (OF) theCount */
        char***        theICOIds,           /**< (OF) theCount */
        char***        theClassIds,         /**< (OF) theCount */
        tag_t**        theWSOTags,          /**< (OF) theCount */
        char***        theWSOUIDs           /**< (OF) theCount */
        );

    /**
       Determines whether theClassId is a descendant of theAncestor.
       <br/>This will cover classes and parents.

       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#SML_ERR_NO_INSTANCE_FOUND if the class does not exist
       </ul>
    */
    extern ICS_API int ICS_class_is_descendant(
        const char*    theClassId,      /**< (I) */
        const char*    theAncestor,     /**< (I) */
        logical*       theVerdict       /**< (O) */
        );

    /**
       If theClassTag is a valid class, returns the id of the class
    */
    extern ICS_API int ICS_class_ask_id(
        tag_t          theClassTag,     /**< (I) The tag of the Class */
        char**         theClassId       /**< (OF) The Id of the Class */
        );

    /**
       Retrieves the class IDs of a list of classes.

       @note Any invalid entry in @p theClasses will be represented by an empty string in the output array @p theClassIds.

       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#SML_ERR_INVALID_VALUE if @p theCount is 0 or if all the members of @p theClasses are invalid.
       </ul>
    */
    extern ICS_API int ICS_class_ask_ids(
        unsigned int     theCount,       /**< (I) Number of classes */
        const tag_t*     theClasses,     /**< (I) theCount Classes */
        char*           **theClassIds    /**< (OF) theCount IDs corresponding to the given classes.
                                            <br/>The array is packed, which means that the memory is deallocated by calling #MEM_free on the container only. */
        );

    /**
       If theClassId is a valid class, returns the POM tag of the class <br>

       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#SML_ERR_NO_INSTANCE_FOUND if the class does not exist
       </ul>
    */
    extern ICS_API int ICS_class_ask_tag(
        const char*    theClassId,      /**< (I) The Id of the Class */
        tag_t*         theClassTag      /**< (O) The tag of the Class */
        );

    /**
       Call this function to define an attribute ? given by the ID of the Classification class and its
       attribute ID - as reference attribute.

       @note Use 0 as theReferenceState to define the attribute to be a normal attribute (non reference
       attribute).

       @note This function requires a subsequent call to #ICS_class_save to commit the changes to the database.

    */
    int ICS_API ICS_class_set_attr_as_reference(
        const char *theClassId,               /**< (I) Class ID of the Classification class where you want to
                                                 define the reference attribute. <br>
                                                 The parameter must specify an existing class ID. */
        int        theAttributeID,            /**< (I) Attribute ID of the attribute that you want to define as
                                                 reference attribute. <br>
                                                 The parameter must specify the attribute ID of an
                                                 attribute that is used in Classification class
                                                 theClassId. */
        int        theReferenceState,         /**< (I)  0 - non reference attribute <br>
                                                 #ICS_REFATTR_INHERITED - the Reference Attribute definition
                                                 from the Classification dictionary will be used <br>
                                                 #ICS_REFATTR_CLASS_LOCAL - set a Reference Attribute
                                                 definition for the attribute locally in this class
                                                 (only in this case the following parameters are used) */
        int        theReferenceAttributeType, /**< (I) One of the following values:
                                                 <ul>
                                                 <li> #ICS_REFATTR_CLASSIFIED_OBJECT - a property or attribute of the
                                                 classified object
                                                 <li> #ICS_REFATTR_MASTERFORM - a property or attribute of the
                                                 Masterform of the classified item or item revision
                                                 <li> #ICS_REFATTR_RELATED_OBJECT - a property or attribute of an
                                                 object that is related (via an IMAN Relation) to the
                                                 classified object
                                                 <li> #ICS_REFATTR_ICO - an attribute of a different ICO
                                                 </ul> */
        int        theFlags,                  /**< (I) Set to 0 or any combination of: <br>
                                                 #ICS_REFATTR_PROPERTY: set this flag if you want to define an
                                                 IMAN property - do not set it if you want to define a POM
                                                 Attribute <br>
                                                 #ICS_REFATTR_ITEM_ATTR: set this flag if you want to define a
                                                 reference attribute of an item. This means that if the
                                                 classified object is an item revision the reference
                                                 attribute value will be read from the item (or its
                                                 masterform / an object that is related to the item) of
                                                 the classified item revision. */
        const char *theClassName,             /**< (I) Depending on theReferenceAttributeType specify the
                                                 following value:
                                                 <ul>
                                                 <li> #ICS_REFATTR_CLASSIFIED_OBJECT: Classification class where the
                                                 referenced ICO is stored (the parameter must not be
                                                 NULL).
                                                 <li> #ICS_REFATTR_MASTERFORM: IMAN Type of the classified object /
                                                 its item if #ICS_REFATTR_ITEM_ATTR is set in the flags (the
                                                 parameter may be NULL to specify that different IMAN
                                                 Types are allowed)
                                                 <li> #ICS_REFATTR_CLASSIFIED_OBJECT: POM Class / IMAN Type of the
                                                 classified object / its item if ICS_ITEM_ATTR is set
                                                 in the flags (the parameter may be NULL to specify that
                                                 different IMAN Types are allowed)
                                                 <li> #ICS_REFATTR_RELATED_OBJECT: POM Class / IMAN Type of the
                                                 related object (the parameter must not be NULL)
                                                 </ul>
                                                 (The second alternatives are valid if #ICS_REFATTR_PROPERTY is
                                                 specified in theFlags) */
        const char *theAttrName,              /**< (I) This parameter must not be NULL. <br>
                                                 Depending on theReferenceAttributeType specify the following
                                                 value:
                                                 <ul>
                                                 <li> #ICS_REFATTR_CLASSIFIED_OBJECT: name of the POM Attribute /
                                                 IMAN Property where the value of the reference
                                                 attribute will be read from
                                                 <li> #ICS_REFATTR_MASTERFORM: name of the POM Attribute / IMAN
                                                 Property where the value of the reference attribute
                                                 will be read from (the POM Attribute / IMAN Property is
                                                 found in the Masterform of the classified object / its
                                                 item)
                                                 <li> #ICS_REFATTR_CLASSIFIED_OBJECT: Attribute ID of the attribute
                                                 that will be displayed as "key attribute" of the
                                                 referenced ICO
                                                 <li> #ICS_REFATTR_RELATED_OBJECT: name of the POM Attribute / IMAN
                                                 Property where the value of the reference attribute
                                                 will be read from (this POM Attribute / IMAN Property
                                                 is found in the related object)
                                                 </ul>
                                                 (The second alternatives are valid if #ICS_REFATTR_PROPERTY is
                                                 specified in theFlags) */
        const char *theRelationName         /**< (I) If theReferenceAttributeType is #ICS_REFATTR_RELATED_OBJECT: name of
                                               the IMAN Relation with which the related object is attached
                                               to the classified object (may be NULL to specify that any
                                               relation is possible). <br>
                                               For all other Reference Attribute types this parameter is
                                               not used. */
        );

    /**
       Call this function to ask the reference attribute properties of an attribute in a certain
       Classification class (given by the Class ID and the attribute ID).
    */

    int ICS_API ICS_class_ask_attr_reference_props(
        const char **theClassId,               /**< (I) Class ID of the Classification class in which the
                                                  attribute is used. */
        int        theAttributeID,             /**< (I) Attribute ID of the Classification class attribute from
                                                  which you want to read the reference attribute definition.
                                                  The parameter must specify an attribute ID of an
                                                  attribute that is used in Classification class theClassId. */
        int        *theReferenceAttributeState,/**< (O) 0 - non reference attribute <br>
                                                  #ICS_REFATTR_INHERITED - the Reference Attribute
                                                  definition is taken from the Classification
                                                  dictionary (in this case the subsequent parameters are
                                                  set to the values defined in the Classification
                                                  dictionary) <br>
                                                  #ICS_REFATTR_CLASS_LOCAL - the Reference Attribute
                                                  definition is specified locally in the Classification
                                                  class */
        int        *theReferenceAttributeType, /**< (O) One of the following values:
                                                  <ul>
                                                  <li> #ICS_REFATTR_CLASSIFIED_OBJECT - a property or attribute of
                                                  the classified object
                                                  <li> #ICS_REFATTR_MASTERFORM - a property or attribute of the
                                                  Masterform of the classified item or item revision
                                                  <li> #ICS_REFATTR_RELATED_OBJECT - a property or attribute of an
                                                  object that is related (via an IMAN Relation) to the
                                                  classified object
                                                  <li> #ICS_REFATTR_ICO - an attribute of a different ICO
                                                  </ul> */
        int        *theFlags,                  /**< (O) 0 or any combination of: <br>
                                                  #ICS_REFATTR_PROPERTY: this flag is set if an IMAN property is
                                                  defined - if it is not set then a POM attribute is
                                                  defined <br>
                                                  #ICS_REFATTR_ITEM_ATTR: this flag is set if a reference attribute
                                                  of an item is defined. This means that if the classified
                                                  object is an item revision the reference attribute value
                                                  will be read from the item (or its masterform / an object
                                                  that is related to the item) of the classified item
                                                  revision.*/
        char       **theClassName,             /**< (OF) Depending on theReferenceAttributeType this parameter
                                                  specifies one the following values:
                                                  <ul>
                                                  <li> #ICS_REFATTR_CLASSIFIED_OBJECT: Classification class where
                                                  the referenced ICO is stored.
                                                  <li> #ICS_REFATTR_MASTERFORM: IMAN Type of the classified object
                                                  / its item if #ICS_REFATTR_ITEM_ATTR is set in the flags
                                                  (the parameter may be NULL to specify that
                                                  different IMAN Types are allowed)
                                                  <li> #ICS_REFATTR_CLASSIFIED_OBJECT: POM Class / IMAN Type of
                                                  the classified object / its item if #ICS_REFATTR_ITEM_ATTR
                                                  is set in the flags (the parameter may be NULL to
                                                  specify that different IMAN Types are allowed)
                                                  <li> #ICS_REFATTR_RELATED_OBJECT: POM Class / IMAN Type of the
                                                  related object
                                                  </ul>
                                                  (The second alternatives are valid if #ICS_REFATTR_PROPERTY is
                                                  set in theFlags) */
        char       **theAttrName,              /**< (OF) Depending on theReferenceAttributeType this parameter
                                                  specifies the following value:
                                                  <ul>
                                                  <li> #ICS_REFATTR_CLASSIFIED_OBJECT: name of the POM Attribute
                                                  / IMAN Property where the value of the reference
                                                  attribute will be read from
                                                  <li> #ICS_REFATTR_MASTERFORM: name of the POM Attribute / IMAN
                                                  Property where the value of the reference attribute
                                                  will be read from (the POM Attribute / IMAN
                                                  Property is found in the Masterform of the
                                                  classified object / its item)
                                                  <li> #ICS_REFATTR_CLASSIFIED_OBJECT: Attribute ID of the
                                                  attribute that will be displayed as "key attribute"
                                                  of the referenced ICO
                                                  <li> #ICS_REFATTR_RELATED_OBJECT: name of the POM Attribute /
                                                  IMAN Property where the value of the reference
                                                  attribute will be read from (this POM Attribute /
                                                  IMAN Property is found in the related object)
                                                  </ul>
                                                  (The second alternatives are valid if #ICS_REFATTR_PROPERTY is
                                                  set in theFlags) */
        char       **theRelationName           /**< (OF) If theReferenceAttributeType is #ICS_REFATTR_RELATED_OBJECT:
                                                  name of the IMAN Relation with which the related object
                                                  is attached to the classified object (may be NULL to
                                                  specify that any relation is possible). <br>
                                                  For all other Reference Attribute types this parameter
                                                  is set to NULL. */
        );

    /**
       The following function copies theClass to a new Classification class with theNewCid ID and theNewParent
       parent; afterwards the descendants whose IDs are contained within theOldIDs are copied under the new Class
       with the IDs specified in theNewIDs.
     
       The function fails if one of the following error conditions is met:
       <ul>
       <li>theNewParent is a descendant of theClass
       <li>theOldIDs contains IDs of Classes/Views that either aren't descendants of theClass or their immediate
         parent is not in theOldIDs
       <li>theNewIDs contains IDs that are not unique.
       <li>theClass has unreadable descendants (this check is only executed if ICS_IGNORE_UNREADABLE_CHILDREN
         is not specified in theOptions)
       <li>theNewParent is not writable
       </ul>

       Moreover a warning is logged if
       <ul>
       <li>theClass is shared (the shared sites are not copied!)
       <li>theClass or one of its descendants to copy has part family templates attached (part family templates
         can only be attached to ONE Classification class - and they are not moved to the copies)
       </ul>

       If these checks succeed and theClass itself is successfully copied, then further errors during the
       subsequent copy operation are logged to the syslog file but do not lead to a rollback.
     */
    extern ICS_API int ICS_class_copy(
        const char *theClass,         /**< (I) The ID of the Classification class to be copied */
        const char *theNewCidIn,      /**< (I) The ID of the Classification class that is created as a copy of theClass */
        const char *theNewParent,     /**< (I) The ID of the Classification class under which the copy of theClass is created */
        int        theOptions,        /**< (I) options - valid values are:
                                         <ul>
                                         <li> #ICS_COPY_THIS_CLASS_ONLY - only copy theClass (no descendants are copied.
                                         If this option is not specified and theChildCount is 0,
                                         then all descendants of theClass are copied under the new
                                         Class and the IDs for the copies are automatically generated.
                                         <li> #ICS_IGNORE_UNREADABLE_CHILDREN - no error if theClass has unreadable descendants
                                         <li> #ICS_COPY_INHERITED_ATTRIBUTES - the copy of theClass will contain all attributes
                                         of theClass (local and inherited attributes). If this option
                                         is not specified, then only the local attributes of theClass
                                         are copied to the new Class.
                                         <li> #ICS_DRY_RUN - only executes the checks but does not actually copy any objects
                                         </ul> */
        int        theChildCountIn,   /**< (I) Count of the descendants of theClass that shall be copied together with theClass. */
        const char **theOldIDsIn,     /**< (I) IDs of the descendants to copy. theOldIDs must containthe IDs as
                                         CID (for Classification classes) or CID::SID (for Classification views).*/
        const char **theNewIDsIn,     /**< (I) IDs of the copies. theNewIDs must contain the IDs of the objects to be created as
                                         NEW_CID (for Classification classes) or NEW_SID (for Classification Views).*/
        char       **theNewCidOut,    /**< (OF) The ID of the Classification class that is created as a copy of theClass. */
        int        *theChildCountOut, /**< (O) Count of the descendants that were successfully copied. */
        char       ***theOldIDsOut,   /**< (OF) theChildCountOut IDs of the descendants the ware successfully copied. theOldIDsOut contain the IDs as
                                         CID (for Classification classes) or CID::SID (for Classification views).*/
        char       ***theNewIDsOut    /**< (OF) theChildCountOut IDs of the copies. theNewIDs contain the IDs of the objects that were created as
                                         NEW_CID (for Classification classes) or NEW_SID (for Classification Views).*/
        );

    /**
       The following function moves theClassToMove under theNewParent.
       The operation will be done the following way:
       <ul>
       <li>The id of the class will be changed to theClassToMove
       <li>The class will be copied to a new class with id theClassToMove and under theNewParent.
       <li>The part family templates that are attached to and the ICOs that are stored in the class are moved to the copy.
       </ul>
       When this is done the class children and views (in other words: all descendants of the class) will be processed in
       the same way. If something goes wrong there will not be a rollback. Moreover the operation will continue even if an
       error occured. As many objects as possible will be moved.
       After the objects have been renamed and copied the old objects will be deleted.
       The function will fail completely if:
       <ul>
       <li>theNewParent is a descendant of theClassToMove
       <li>theClassToMove has unreadable children
       <li>theClassToMove is not writable
       <li>theNewParent is not locally owned
       <li>theNewParent is a class but theClassToMove is a group
       <li>theClassToMove is shared
       </ul>
     */
    int ICS_API ICS_class_move( const char*  theClassToMove,    /**< (I) The ID of the Classification class to be moved */
                                const char*  theNewParent,      /**< (I) The ID of the Classification class under which the theClassToMove is moved */
                                int         *theFailedCount,    /**< (O) The number of objects that could not be moved (in case of classes only the top level object is counted)*/
                                char**      *theFailedObjects   /**< (OF) theFailedCount The IDs of the objects that could not be moved*/
        );


    extern ICS_API int ICS_class_move_partfamily_templates( const char *theSourceClassId, const char *theTargetClassId, int theOptions );

    /**
       The following function shares theClass to theSites and afterwards shares the following objects:
       <ol>
       <li>class children (and their children and so on) if theOptions contains ICS_CLASS_SHARE_child_classes
       <li>subclasses (also the subclasses of class children if ICS_CLASS_SHARE_child_classes is specified )
       if ICS_CLASS_SHARE_subclass is specified i theOptions
       <li>default views (also the default views of class children if ICS_CLASS_SHARE_child_classes is specified ) if
       ICS_CLASS_SHARE_default_view is specified in theOptions
       <li>user, role and group views (also these types of views of class children if ICS_CLASS_SHARE_child_classes is specified ) if
       ICS_CLASS_SHARE_specific_view is specified in theOptions (the preference ICS_share_viewtypes is evaluated to find out
       which of these types will be shared)
       </ol>
       It is no error to specify sites to which theClass is already shared (this enables you share the
       children of theClass although theClass itself is already shared).
       The function fails if theClass's parent is not shared to at least one of theSites and shareParentsToo is false.
       If theClass is successfully shared then no error is returned (but logged in the syslog file) if sharing any of
       the children fails.
    */
    extern ICS_API int ICS_class_share_incl_children( const char *theClass,      /**< (I) the class to be shared */
                                                      int        theSiteCount,   /**< (I) the count of the sites to which the class
                                                                                    (and possibly children) will be shared */
                                                      const char **theSites,     /**< (I) the names of the sites to which the class
                                                                                    (and possibly children) will be shared */
                                                      int        theOptions,     /**< (I) specifies which of the children of theClass
                                                                                    will be shared (see above). */
                                                      logical    shareParentsToo /**< (I) If true then the parents of theClass will
                                                                                    be shared to theSites, too. */
        );

    /**
       Retrieves the dependency configuration settings of the attributes for the given class.

       @returns
       <ul>
       <li>#ITK_ok on success
       <li>POM enquiry related error otherwise.
       </ul>
    */
    extern ICS_API int ICS_class_ask_attr_dep_config(
        tag_t class_tag,                   /**< (I) The tag of the class*/
        int   *attr_count,                 /**< (O) The number of class attributes containing dependency settings */
        int   **attr_ids,                  /**< (OF) attr_count The class attribute IDs */
        char* **dependency_attributes,     /**< (OF) attr_count The dependency attribute values. The output string array is SM-packed,
                                              hence should be freed by calling #MEM_free on the container only. */
        char* **dependency_configurations  /**< (OF) attr_count The dependency configuration values. The output string array is SM-packed,
                                              hence should be freed by calling #MEM_free on the container only. */
        );

    /**
       Retrieves the dependency configuration settings of the attributes for the given class.
       If the value for @p class_id is invalid, no error is returned.

       @returns
       <ul>
       <li>#ITK_ok on success
       <li>POM enquiry related error otherwise.
       </ul>
    */
    extern ICS_API int ICS_class_ask_attr_dep_config_by_id(
        const char* class_id,              /**< (I) The ID of the class*/
        int   *attr_count,                 /**< (O) The number of class attributes containing dependency settings */
        int   **attr_ids,                  /**< (OF) attr_count The class attribute IDs */
        char* **dependency_attributes,     /**< (OF) attr_count The dependency attribute values */
        char* **dependency_configurations  /**< (OF) attr_count The dependency configuration values */
        );


    /** @} */

    /**
       @name View/Subclass related Functions

       <b>Common return values:</b>

       #ICS_err_attribute_does_not_exist <br>
       #ICS_err_cannot_create_files <br>
       #ICS_err_class_does_not_exist <br>
       #ICS_err_could_not_open_file <br>
       #ICS_err_file_already_exists <br>
       #ICS_err_invalid_property <br>
       #ICS_err_invalid_reference_type <br>
       #ICS_err_invalid_value <br>
       #ICS_err_parent_is_not_shared <br>
       #ICS_err_view_does_not_exist
       @{
    */

    /**
       Checks whether a class with the given classId exists in the database

       <b>Return values:</b>

       true  : view exists <br>
       false : a view with this id does not exist
    */
    extern ICS_API logical ICS_view_exists(
        const char*        theClassId,      /**< (I) The unique id of a class */
        const char*        theViewId        /**< (I) The unique id of a view */
        );

    /**
       Creates a view for the specified class
    */
    extern ICS_API int ICS_view_create(
        const char*     theClassId,     /**< (I) The unique id of an existing class the view should belong to */
        const char*     theViewId,      /**< (I) The ID of the view which needs to be unique within
                                           the scope of the class the view belongs to */
        ICS_view_type_e theViewType,    /**< (I) Defines how the view is used: <br>
                                           #VIEW_type_subclass - legacy type can only be added to
                                           abstract classes with no further class children <br>
                                           #VIEW_type_defaultView - optionaly,
                                           will be autogenerated if needed and does not exist <br>
                                           The id is fixed: "defaultView" <br>
                                           #VIEW_type_user, #VIEW_type_group, #VIEW_type_role <br>
                                           For these views, theViewId needs to be set to the user, group or role Id. */
        const char*     theName,        /**< (I) The view name is optional except for #VIEW_type_subclass */
        int             theAttrCount,   /**< (I) The number of Attributes added to the view */
        int*            theAttrIds      /**< (I) The Attributes added to the view (need to exist in the class) */
        );

    /**
       Permanently removes the view from the database

       @note Views of type #VIEW_type_subclass can only be removed if no instances are stored in it
    */
    extern ICS_API int ICS_view_remove(
        const char*    theClassId,  /**< (I) Id of the class the view to remove is assigned to */
        const char*    theViewId    /**< (I) Id of the view */
        );

    /**
       Saves unsaved modifications to the database.
       All functions that require a call to this function are explicitly marked.
    */
    extern ICS_API int ICS_view_save(
        const char*    theClassId,  /**< (I) The unique id of the class */
        const char*    theViewId    /**< (I) The unique id of a view in the specified class */
        );

    /**
       Reloads the view definition from the database. All changes made by any function call
       that requires the use of ICS_view_save() will be lost.
    */
    extern ICS_API int ICS_view_refresh(
        const char*    theClassId,  /**< (I) The unique id of the class */
        const char*    theViewId    /**< (I) The unique id of a view in the specified class */
        );

    /**
       Has the same functionality as ICS_view_refresh()
    */
    extern ICS_API int ICS_view_cancel(
        const char*    theClassId,  /**< (I) The unique id of the class */
        const char*    theViewId    /**< (I) The unique id of a view in the specified class */
        );

    /**
       Sets the given property value for the specifed property

       @note This function requires a subsequent call to ICS_view_save()
       to commit the changes to the database
    */
    extern ICS_API int ICS_view_set_property(
        const char*    theClassId,          /**< (I) The unique id of an existing class */
        const char*    theViewId,           /**< (I) The unique id of a view in the specified class */
        const char*    thePropertyName,     /**< (I) The id of the property to set. Possible values are: <br>
                                               SID, TYPE, TYPENAME, NAME, SHORT_NAME, USER1, USER2, FLAGS */
        const char*    thePropertyValue     /**< (I) The value for the property */
        );

    /**
       Returns the value for the specifed property of an existing view.
    */
    extern ICS_API int ICS_view_ask_property(
        const char*    theClassId,          /**< (I) The unique id of an existing class */
        const char*    theViewId,           /**< (I) The unique id of a view in the specified class */
        const char*    thePropertyName,     /**< (I) The name of the property to set.
                                               Possible values: see ICS_class_set_property()
                                               and additionally CID, NUM_SHARED_SITES */
        char**         thePropertyValue     /**< (OF) The value for the property.
                                               Needs to be freed using SM_free */
        );

    /**
       Adds the given shared site

       @note This function requires a subsequent call to ICS_view_save()
       to commit the changes to the database
    */
    extern ICS_API int ICS_view_add_shared_site(
        const char*    theClassId,              /**< (I) The unique id of an existing class */
        const char*    theViewId,               /**< (I) The unique id of a view in the specified class */
        const char*    theSharedSite,           /**< (I) The name of the shared site */
        logical        approveShareOfParents    /**< (I) A view can only be shared, if its parents are shared. <br>
                                                   false: if the parents are not shared
                                                   theSharedSite will not be added <br>
                                                   true:  if the parents are not shared
                                                   theSharedSite will be added to the
                                                   specified class and its parents */
        );

    /**
       Returns the count and the values of the shared sites
    */
    extern ICS_API int ICS_view_ask_shared_sites(
        const char*    theClassId,      /**< (I) The unique id of an existing class */
        const char*    theViewId,       /**< (I) The unique id of a view in the specified class */
        int*           theSiteCount,    /**< (O) The number of shared sites */
        char***        theSharedSites   /**< (OF) theSiteCount The shared sides.
                                           Need to be freed using #MEM_free */
        );

    extern ICS_API int ICS_view_add_attributes(
        const char*    theClassId,      /**< (I) The unique Id of the class */
        const char*    theViewId,       /**< (I) The View Id */
        int            theAttrCount,    /**< (I) The attribute count */
        int*           theAttrIds       /**< (I) The attributes to be added */
        );

    extern ICS_API int ICS_view_remove_attributes(
        const char*    theClassId,      /**< (I) The unique Id of the class */
        const char*    theViewId,       /**< (I) The View Id */
        int            theAttrCount,    /**< (I) The attribute count */
        int*           theAttrIds       /**< (I) The attributes to be removed */
        );

    /**
       Sets the property value for the property in the specified attribute of the view

       @note This function requires a subsequent call to ICS_view_save()
       to commit the changes to the database
    */
    extern ICS_API int ICS_view_set_attr_property(
        const char*    theClassId,          /**< (I) The unique id of an existing class */
        const char*    theViewId,           /**< (I) The unique id of a view in the specified class */
        int            theAttributeId,      /**< (I) The id of the attribute to set the property in */
        const char*    thePropertyName,     /**< (I) The id of the property to set. Possible values are: <br>
                                               MIN, MAX, FLAGS, FLAGS1, FLAGS2,
                                               TEXT, TEXT1, TEXT2, USER1, USER2 */
        const char*    thePropertyValue     /**< (I) The value for the property */
        );

    /**
       Asks for the value of the property in the specified attribute of the view
    */
    extern ICS_API int ICS_view_ask_attr_property(
        const char*      theClassId,        /**< (I) The unique id of an existing class */
        const char*      theViewId,         /**< (I) The unique id of a view in the specified class */
        int              theAttributeId,    /**< (I) The id of the attribute to set the property in */
        const char*      thePropertyName,   /**< (I) The id of the property to ask. Possible values:
                                               see ICS_view_set_attr_property() and additionally
                                               UNCT, LINDEX, SMINDEX, MANDATORY, PROTECTED */
        char**           thePropertyValue   /**< (OF) The value for the property.
                                               Needs to be freed using #MEM_free */
        );


    /**
       Returns all attributes of the given view
    */
    extern ICS_API int ICS_view_ask_attributes(
        const char*    theClassId,          /**< (I) The unique id of the class */
        const char*    theViewId,           /**< (I) The View Id */
        int*           theAttributeCount,   /**< (O) The attribute count */
        int**          theAttributeIds      /**< (OF) theAttributeCount the attribute Ids */
        );

    /*********************************************************************************
     **
     */
    typedef struct ICS_view_attribute_descriptor_s
    {
        int          id;
        char*        name;
        char*        shortName;
        int          format;
        char*        unit;
        char*        defautValue;
        char*        minValue;
        char*        maxValue;
        char*        preConfigOptions;
        char*        configOptions;
        char*        postConfigOptions;
        int          flags;
        char*        userData1;
        char*        userData2;
    }ICS_view_attribute_descriptor_t, *ICS_view_attribute_descriptor_p_t;


    /*********************************************************************************
     **
     */
    typedef struct ICS_view_descriptor_s
    {
        char*    classId;
        char*    viewId;
        char*    unitSystem;
        int      type;
        char*    name;
        int      options;
        char*    userData1;
        char*    userData2;

        int      attributeCount;
        ICS_view_attribute_descriptor_p_t  attributes;

    } ICS_view_descriptor_t, *ICS_view_descriptor_p_t;

    /**
       Returns the most important information about a view and its attributes

       theUnitSystem: Possible values are "", "metric" and "non-metric"
       If "non-metric" is specified for a class that supports both unit systems the non-metric values are returned.
       Otherwise the metric values are returned.
       If the class is either metric or non-metric theUnitSystem is ignored.

       theUserMode: if true the display names of the units will be returned.

    */
    extern ICS_API int ICS_view_describe(
        const char*    theClassId,            /**< (I) The unique id of the class */
        const char*    theViewId,             /**< (I) The View Id */
        const char*    theUnitSystem,         /**< (I) Values can be "", "metric" and "non-metric" <br>
                                                 If "non-metric" is specified for a class that supports both unit systems the non-metric values are returned.<br>
                                                 Otherwise the metric values are returned.<br>
                                                 If the class is either metric or non-metric theUnitSystem is ignored.*/
        logical        theUserMode,           /**< (I) If true, the display names of the units will be returned*/
        ICS_view_descriptor_p_t   *theViewDescriptor      /**< (OF) The View Descriptor */
        );


    /**
       Free up the memory for the given descriptor.
    */
    extern ICS_API void ICS_view_descriptor_free(
        ICS_view_descriptor_p_t theViewDescriptor /**< (I) The View Descriptor */
        );



    /**
       If theViewTag is a valid view, returns the id of the view
       in the following form: cid::sid
    */
    extern ICS_API int ICS_view_ask_id(
        tag_t          theViewTag,      /**< (I) The tag of the View */
        char**         theViewId        /**< (OF) The Id of the View */
        );


    /**
       If theViewId (cid::sid) is a valid view, returns the POM tag of the view
    */
    extern ICS_API int ICS_view_ask_tag(
        const char*    theViewId,   /**< (I) The Id of the View */
        tag_t*         theViewTag   /**< (O) The tag of the View */
        );

    /**
       Returns the types and tags of all documents according to the dataset of the given view

       The following parameters accept NULL pointer to indicate that this parameter should not be returned:

       theDocumentCount, theDocumentTypes, theDocumentTags
    */
    extern ICS_API int ICS_view_ask_documents(
        const char*    theViewId,           /**< (I) The unique id of an existing view */
        int*           theDocumentCount,    /**< (O) The number of named references */
        char***        theDocumentTypes,    /**< (OF) theDocumentCount The reference names of the documents */
        tag_t**        theDocumentTags      /**< (OF) theDocumentCount The tags of the documents */
        );

    /**
       Import a document for this view. An existing image will be overwritten.
       A document can be the view image or icon or any other type of document
    */
    extern ICS_API int ICS_view_import_document(
        const char*    theViewId,           /**< (I) The unique id of an existing view */
        const char*    theDocumentType,     /**< (I) Possible values are: <br>
                                               Image <br>
                                               Icon */
        const char*    theFileName          /**< (I) The name of the file to be imported */
        );

    /**
       Exports all documents of the given type attached to this class
    */
    extern ICS_API int ICS_view_export_document(
        const char*    theViewId,               /**< (I) The unique id of an existing view */
        const char*    theDocumentType,         /**< (I) For possible values see ICS_view_import_document() */
        const char*    theOutputDirectory,      /**< (I) The directory name to put the files into */
        logical        overwriteExistingFiles,  /**< (I) */
        int*           theFileCount,            /**< (O) The number of files exported */
        char***        theFileNames             /**< (OF) theFileCount The names of the files put into theOutputDirectory */
        );

    /**
       Removes all images assigned to this view
    */
    extern ICS_API int ICS_view_remove_document(
        const char*    theViewId,       /**< (I) The unique id of an existing view */
        const char*    theDocumentType  /**< (I) For possible values see ICS_view_import_document() */
        );

    /**
       Search for views using specified query.

       The input to all output parameter except theCount can be NULL to indicate
       that the output should not be returned.
    */
    extern ICS_API int ICS_view_search( const char* theQuery,            /**< (I) the query: (unct) (op) (value), e.g. "-600 = classid" *
                                                                            Supported values for unct are:
                                                                            <ul><li> -600  class id
                                                                            <li> -607  view name
                                                                            <li> -608  short name
                                                                            <li> -612  user data 1
                                                                            <li> -613  user data 2
                                                                            <li> 8     attribute id
                                                                            <li> 3     attribute name  </ul>  */
                                        int         theSortAttrId,       /**< (I) specifies the attribute to be used for sorting the result */
                                        int         theOptions,          /**< (I) options, currently not supported */
                                        int         *theCount,           /**< (O) the number of views matching theQuery */
                                        tag_t       **theTags,           /**< (OF) theCount the tags of the found views */
                                        char*       **theTypes,          /**< (OF) theCount the types of the views. <br>
                                                                            possible values are "subclass", "default",
                                                                            "user", "group", "role", "graphics_mapping" */
                                        char*       **theClassIds,       /**< (OF) theCount the class ids */
                                        char*       **theViewIds,        /**< (OF) theCount the view ids */
                                        char*       **theNames,          /**< (OF) theCount the names of the views */
                                        int         **theInstanceCounts  /**< (OF) theCount the number of instances */
        );

/**
 **  Copy a view to another parent class.
 */
    extern ICS_API int ICS_view_copy(
        const char      *theClass,     /**< (I) The ID of the Classification class of the view to be copied */
        const char      *theView,      /**< (I) The ID of the Classification view to be copied */
        const char      *theNewParent, /**< (I) The ID of the Classification class under which the copy of theView is created */
        const char      *theNewId,     /**< (I) The ID of the Classification view that is created as a copy of theView. */
        ICS_view_type_e theNewType,    /**< (I) Defines how the created view is used: <br>
                                          #VIEW_type_subclass - legacy type can only be added to
                                          abstract classes with no further class children <br>
                                          #VIEW_type_defaultView - optionaly,
                                          will be autogenerated if needed and does not exist <br>
                                          The id is fixed: "defaultView" <br>
                                          #VIEW_type_user, #VIEW_type_group, #VIEW_type_role <br>
                                          For these views, theViewId needs to be set to the user, group or role Id. */
        int             theOptions     /**< (I) options - valid values are:
                                          <ul>
                                          <li> #ICS_ADD_ATTRBIUTES_FROM_PARENT - all attributes of theNewParent will be
                                          added to the copy of the view
                                          <li> #ICS_DRY_RUN - only executes the checks but does not copy the view
                                          </ul> */
        );

    /** @} */

    /**
       @name Classification Object (ICO) related Functions

       <b>Common Return Values:</b>

       #ICS_invalid_ico - The provided ICO tag is invalid
       @{
    */

    /**
       Create a new ICO
    */
    extern ICS_API int ICS_ico_create(
        const char*    theICOId,                /**< (I) The id of the ICO. Will be ignored i theClassifiedObjectTag is != NULLTAG */
        tag_t          theClassifiedObjectTag,  /**< (I) The WSO to classify with the new ICO*/
        const char*    theClassId,              /**< (I) The id of the class the ICo should be stored in*/
        int            theAttributeCount,       /**< (I) The number of attribute id/values given*/
        int*           theAttributeId,          /**< (I) The attribute ids*/
        const char**   theAttributeValues,      /**< (I) The values for the listed Attributes */
        tag_t*         theICOTag                 /**< (O)  The Tag of the created ICO */
        );

    extern ICS_API int ICS_ico_create2(
        const char*    theICOId,                /**< (I) The id of the ICO. Will be ignored i theClassifiedObjectTag is != NULLTAG */
        tag_t          theClassifiedObjectTag,  /**< (I) The WSO to classify with the new ICO*/
        const char*    theClassId,              /**< (I) The id of the class the ICo should be stored in*/
        int            theAttributeCount,       /**< (I) The number of attribute id/values given*/
        int*           theAttributeId,          /**< (I) The attribute ids*/
        int*           theAttributeValCounts,   /**< (I) The attribute value count */
        const char***  theAttributeValues,      /**< (I) The values for the listed Attributes */
        tag_t*         theICOTag                 /**< (O)  The Tag of the created ICO */
        );

    /**
       Remove the ICO identified by theICOTag from the database
    */
    extern ICS_API int ICS_ico_remove( tag_t theICOTag  /* (I) The tag of the ICO to be removed */
        );

    /**
       @deprecated #ICS_ico_find deprecated in Teamcenter 11.2.2. Use #ICS_ico_search instead.

       Find the ICO identified by its id and/or classified object tag
       e.g. <br>
       1. find ICO with a given ID  ( ignore WSO tag ) <br>
       ICS_ico_find( id, wsoTag, 0, &count, &icoTags ); <br>

       2. Find ICO for given WSO tag ( ignoring id ) <br>
       ICS_ico_find( "", wsoTag, 1, &count, &icoTags ); <br>

       3. Find ICO with given id where WSO is null tag <br>
       ICS_ico_find( id, NULLTAG, 1, &count, &icoTags );
    */
    TC_DEPRECATED("11.2.2","ICS_ico_find","ICS_ico_search")
    extern ICS_API int ICS_ico_find(
        const char*    theICOId,                /**< (I) The id of the ICO */
        tag_t          theClassifiedObjectTag,  /**< (I) The classified WSO */
        int            theOptions,              /**< (I) 0 or 1. If 0, then ICO will be searched only using theICOId. The value of theClassifiedObjectTag will be ignored, even if specified.<br>
                                                   If 1, the ICOs will be searched using theICOId and theClassifiedObjectTag both */
        int*           theCount,                /**< (O) No of ICOs found */
        tag_t**        theICOTags               /**< (OF) theCount Tags of ICOs found */
        );

    /**
       Executes the POM enquiry resulting from the theAttrIds and theAttrExpr.
       theOptions affects the search, the following values can be used: #ICS_SEARCH_THIS_CLASS_ONLY,
       #ICS_SEARCH_CASE_INSENSITIVE, #ICS_SEARCH_ORDER_BY_ID and/or ICS_SEARCH_IN_BOTH_UNIT_SYSTEMS.

       The out parameters accept NULL pointer to indicate that this parameter should not be returned.
       If not specified by theOptions, the out parameters are sorted by the values for the given
       search attributes. If no search attributes are gives, then they are sorted by theICOIds.

       @note For more compilcated queries use the ICS_enquiry_ functions (ics_enquiry.h)
    */
    extern ICS_API int ICS_ico_search(
        int            theExprCount,    /**< (I) The number of attributss */
        int*           theAttrIds,      /**< (I) Array of attributes to search for. 
                                        Supported values for internal Attribute ID are:
                                        <ul>
                                        <li>@c  #ICS_UNCT_INSTANCE_WSO_TYPE - Workspace Object Type
                                        <li>@c  #ICS_UNCT_INSTANCE_ID - Classification Object (ICO) ID
                                        <li>@c  #ICS_UNCT_CID - Class CID
                                        <li>@c  #ICS_UNCT_INSTANCE_SID_PUID - View UID
                                        <li>@c  #ICS_UNCT_INSTANCE_CID_PUID - Class UID
                                        <li>@c  #ICS_UNCT_INSTANCE_ICO_TYPE - Classification Object (ICO) Type
                                        <li>@c  #ICS_UNCT_INSTANCE_REVISION_RULE - Revision Rule. This should be used in combination with class ID.<br/>
                                         For example: ICS_ico_search( 2, { -600, -726 }, { "ClassID", "Latest Working" }, theOptions, theCount, theICOTags, theICOUIDs, theICOIds, theClassIds, theWSOTags, theWSOUIDs )
                                        <li>@c  #ICS_UNCT_INSTANCE_READ_ACCESS - Read Access. This should be used in combination with class ID.<br/>
                                         For example: ICS_ico_search( 2, { -600, -727 }, { "ClassID", "" }, theOptions, theCount, theICOTags, theICOUIDs, theICOIds, theClassIds, theWSOTags, theWSOUIDs )
                                         </ul>
                                         @note You cannot use an attribute search without a class ID.<br/>                                         
                                         Usage:ICS_ico_search( 2, { -600, attributeID }, { "ClassID", "attributValue" }, theOptions, theCount, theICOTags, theICOUIDs, theICOIds, theClassIds, theWSOTags, theWSOUIDs )
                                       */
        char**         theAttrExpr,     /**< (I)  A search string for each attribute in theAttrIds */
        int            theOptions,      /**< (I) The enquiry options: <br>
                                           #ICS_SEARCH_THIS_CLASS_ONLY to limit search results to
                                           the class with the unique ID, theClassId. <br>
                                           #ICS_SEARCH_CASE_INSENSITIVE to search without case sensitivity. <br>
                                           #ICS_SEARCH_ORDER_BY_ID to sort the result by object ids. <br>
                                           #ICS_SEARCH_IN_BOTH_UNIT_SYSTEMS to search in both unit systems. If this option is used then you need to specify the active unitsystem
                                           -630 = 0/1 (metric/non-metric) as theAttrIds & theAttrExpr. This determines in which unit system the returned attribute values are displayed*/
        int*           theCount,        /**< (O) The number of found ICOs. */
        tag_t**        theICOTags,      /**< (OF) The tags of the found ICOs. */
        char***        theICOUIDs,      /**< (OF) The UIDs of the found ICOs. */
        char***        theICOIds,       /**< (OF) The IDs of the found ICOs. */
        char***        theClassIds,     /**< (OF) The Class IDs of the found ICOs. */
        tag_t**        theWSOTags,      /**< (OF) The workspace object tags of the found ICOs. */
        char***        theWSOUIDs       /**< (OF) The workspace object UIDs of the found ICOs. */
        );

    /**
       Executes the POM enquiry resulting from the theAttrIds and theAttrExpr.
       theOptions affects the search, the following values can be used: #ICS_SEARCH_THIS_CLASS_ONLY,
       #ICS_SEARCH_CASE_INSENSITIVE and/or #ICS_SEARCH_ORDER_BY_ID.

       The out parameters accept NULL pointer to indicate that this parameter should not be returned.
       If not specified by theOptions, the out parameters are sorted by the values for the given
       search attributes. If no search attributes are gives, then they are sorted by theICOIds.

       @note For more compilcated queries use the ICS_enquiry_ functions (ics_enquiry.h)
    */

    extern ICS_API int ICS_ico_search_count(
        int         theExprCount,    /**< (I) The number of attributss */
        int         *theAttrIds,     /**< (I) theExprCount Array of attributes to search for */
        char*       *theAttrExpr,    /**< (I) theExprCount A search string for each attribute in theAttrIds */
        int         theOptions,      /**< (I) The enquiry options: <br>
                                        #ICS_SEARCH_THIS_CLASS_ONLY to limit search results to
                                        the class with the unique ID, theClassId. <br>
                                        #ICS_SEARCH_CASE_INSENSITIVE to search without case sensitivity. <br>
                                        #ICS_SEARCH_ORDER_BY_ID to sort the result by object ids. */
        int         *theCount        /**< (O) The number of found ICOs. */
        );


    /**
       Returns the tag of the worksoace object the ICO classifies
    */
    extern ICS_API int ICS_ico_ask_classified_object(
        tag_t          theICOTag,           /**< (I) The Tag of the ICO */
        tag_t*         theClassifiedObject  /**< (OF) The Classified WSO */
        );

    /**
       Returns the class id of the class the ICO is stored in

       If the ICO is stored in a (legacy) sml-subclass theClassId has the following format:

       classid::subclassid
    */
    extern ICS_API int ICS_ico_ask_class(
        tag_t          theICOTag,   /**< (I) The Tag of the ICO */
        char**         theClassId   /**< (OF) The Id of the Class */
        );

    /**
       Returns the tag of the class the ICO is stored in
    */
    extern ICS_API int ICS_ico_ask_class_tag(
        tag_t          theICOTag,   /**< (I) The Tag of the ICO */
        tag_t*         theClassTag  /**< (O) The tag of the Class */
        );

    /**
       Returns the values of the given attributes
    */
    extern ICS_API int ICS_ico_ask_named_attributes(
        tag_t          theICOTag,               /**< (I) The Tag of the ICO */
        int            theAttributeCount,       /**< (I) The attribute count */
        int*           theAttributeIds,         /**< (I) The attributes */
        int**          theAttributeValCounts,   /**< (OF) theAttributeCount The count of attribute values */
        char****       theAttributeValues       /**< (OF) theAttributeCount The attribute values */
        );

    /**
       Sets all attributes of the given ICO
    */
    extern ICS_API int ICS_ico_set_attributes(
        tag_t          theICOTag,               /**< (I) The Tag of the ICO */
        int            theAttributeCount,       /**< (I) The attribute count */
        int*           theAttributeIds,         /**< (I) The attributes */
        int*           theAttributeValCounts,   /**< (I) The count of attribute values */
        const char***  theAttributeValues       /**< (I) The attribute values */
        );

    /**
       Returns all attributes of the given ICO

       @note Only those attributes are retuned which are accessible through the user specific view.
    */
    extern ICS_API int ICS_ico_ask_attributes(
        tag_t          theICOTag,               /**< (I) The Tag of the ICO */
        int*           theAttributeCount,       /**< (O) The attribute count */
        int**          theAttributeIds,         /**< (OF) theAttributeCount The attribute Ids */
        int**          theAttributeValCounts,   /**< (OF) theAttributeCount The count of Attribute values */
        char****       theAttributeValues       /**< (OF) theAttributeCount The attribute values */
        );

    /**
       Returns all attributes with their optimized units ans values of the given ICO
       For the attributes that are numeric and optimization flag is turned "on" , optimized units ans values are returned
       For other attributes, storage units ans values are returned
       @note Only those attributes are retuned which are accessible through the user specific view.
    */
    extern ICS_API int ICS_ico_ask_attributes_optimized(
        tag_t            theICOTag,                   /**< (I) The Tag of the ICO */
        int             *theAttributeCount,           /**< (O) The attribute count */
        int*            *theAttributeIds,             /**< (OF) theAttributeCount The attribute Ids */
        char**            *theAttributeNames,              /**< (OF) theAttributeCount The attribute names */
        int*            *theAttributeValCounts,       /**< (OF) theAttributeCount The attribute value count */
        char***         *theAttributeOptimizedValues,  /**< (OF) theAttributeCount The attribute values */
        char***         *theAttributeOptimizedUnits    /**< (OF) theAttributeCount The attribute units */
        );

    /**
       Returns all attributes of the given ICO without using a view
    */
    extern ICS_API int ICS_ico_ask_all_attributes(
        tag_t          theICOTag,               /**< (I) The Tag of the ICO */
        int*           theAttributeCount,       /**< (O) The attribute count */
        int**          theAttributeIds,         /**< (OF) theAttributeCount The attribute Ids */
        int**          theAttributeValCounts,   /**< (OF) theAttributeCount The attribute value count */
        char****       theAttributeValues       /**< (OF) theAttributeCount The attribute values */
        );

    /**
       Appropriately frees the memory allocated for the parameters theAttributeIds, theAttributeValCounts, theAttributeValues.
       This function is convenient to free memory from the variables returned by functions like #ICS_ico_ask_all_attributes.
       This function returns:
       <ul>
       <li>#ITK_ok
       </ul>
    */
    extern ICS_API int ICS_ico_free_attributes(
        int            theAttributeCount,       /**< (I) The attribute count */
        int*           theAttributeIds,         /**< (I) The attributes*/
        int*           theAttributeValCounts,   /**< (I) The attribute value count */
        char***        theAttributeValues       /**< (I) The attribute values */
        );


    /**
       Search the distinct list of values in the given context for theAttributeId
       The function will search for all ICOs using the given criteria (theAttrIds/theAttrExpr)
    */
    extern ICS_API int ICS_ico_find_values(
        int         theExprCount,        /**< (I) The count of expressions */
        int         *theAttrIds,         /**< (I) The attribute Ids */
        char*       *theAttrExpr,        /**< (I) Array of expressions */
        int         theOptions,          /**< (I) Placeholder for future use */
        int         theAttributeId,      /**< (I) The attribute Id for which the values are being returned */
        int         *theCount,           /**< (O) the value count */
        char*       **theValues,         /**< (OF) theCount The values */
        int         **theValueCounts     /**< (OF) theCount The count of values */
        );

    /**
       Search the distinct list of values in the given context for theAttributeId
       The function will search for all ICOs using the given criteria (theAttrIds/theAttrExpr)
       In addition to ICS_ico_find_values() this function returns a display value
    */
    extern ICS_API int ICS_ico_find_values2(
        int         theExprCount,        /**< (I) The count of expressions */
        int         *theAttrIds,         /**< (I) The attribute Ids */
        char*       *theAttrExpr,        /**< (I) Array of expressions*/
        int         theOptions,          /**< (I) */
        int         theAttributeId,      /**< (I) */
        int         *theCount,           /**< (O) The value count */
        char*       **theValues,         /**< (OF) theCount The values */
        int         **theValueCounts,    /**< (OF) theCount The value count */
        char*       **theDisplayValues   /**< (OF) theCount The display values */
        );

    /**
       moves ICO to the given new class
    */
    extern ICS_API int ICS_ico_move( int         theCount,                  /**< (I) The count */
                                     const tag_t *theICOTags,               /**< (I) The tags of the ICO */
                                     const char  *theNewClass,              /**< (I) The destination class */
                                     int         *theErrorCount,            /**< (O) The count of errors*/
                                     tag_t       **theUnsuccessfulICOTags,  /**< (OF) theErrorCount The tags of ICOs failed to move */
                                     int         **theErrorCodes,           /**< (OF) theErrorCount The error codes */
                                     char        ***theErrorMessages        /**< (OF) theErrorCount The error messages */
        );


    /*===+++======================================================================== */

    /**
       Checks if the provided Classification Object (ICO) classifies an item.
       If yes, it modifies the internal data structures such that after completion
       the ICO will classify the item's latest revision instead of the item itself.

       <b>Return values:</b>

       #ITK_ok - The ICO does not classify an item,
       or it was successfully reassigned to the item's latest revision
    */
    extern ICS_API int ICS_ico_reassign_to_rev( tag_t theICOTag /**< (I) The tag of the ICO to be reassociated */
        );


    /**
       Map the source ICO identified by theSourceICOTag to the new target item and
       ICO identified by theTargetItemID.  The target ICO will be created in the
       Classification class having theTargetClassID.
    */
    extern ICS_API int ICS_ico_map( tag_t   theSourceICOTag,          /**< (I) The tag of the ICO to be mapped  */
                                    char *  theTargetItemID,          /**< (I) The ID of the new target item    */
                                    char *  theTargetItemName,        /**< (I) The new target item's name       */
                                    char *  theTargetItemTypeName,    /**< (I) The name of the target item type */
                                    char *  theTargetItemRevID,       /**< (I) The ID of the new item Revision  */
                                    char *  theTargetItemDescription, /**< (I) The new target item's decription */
                                    char *  theTargetClassID,         /**< (I) The ID of the class to map to    */
                                    int     theOptions,               /**< (I) Options to the mapping process   */
                                    tag_t * theNewICOTag              /**< (O) The new target ICO               */
        );

    /**
       @deprecated #ICS_class_ask_mapping_sources deprecated in Teamcenter 12.2.
       <br/>Internal Classification Objects (ICO) are now mapped based on ICO IDs. Hence retrieving mapping sources functionality will not be based on class ID.
        
       Determine the source classes that have been mapped to the given target class.
    */
    TC_DEPRECATED_NO_REPLACEMENT("12.2","ICS_class_ask_mapping_sources")
    extern ICS_API int ICS_class_ask_mapping_sources( char   * theTargetClassID,    /**< (I)  ID of a class to map ICOs to    */
                                                      int      theMappingViewType,  /**< (I)  Type of mappings to return      */
                                                      int    * theSourceClassCount, /**< (O)  Count of mapping source classes */
                                                      char *** theSourceClassIDs,   /**< (OF) theSourceClassCount The Ids of source class */
                                                      char *** theSourceClassNames  /**< (OF) theSourceClassCount The names of source Class */
        );

    /**
       Determine the target classes that the given source class has been mapped to.
    */
    extern ICS_API int ICS_class_ask_mapping_targets( char   * theSourceClassID,    /**< (I)  ID of the class to map ICOs from */
                                                      int      theMappingViewType,  /**< (I)  Type of mappings to return       */
                                                      int    * theTargetClassCount, /**< (O)  Count of mapping target classes  */
                                                      char *** theTargetClassIDs,   /**< (OF) theTargetClassCount The Ids of target class */
                                                      char *** theTargetClassNames  /**< (OF) theTargetClassCount The names of target Class */
        );

    /**
       Define a mapping between the given source and target class,
       as well as the attribute mappings to the target class? attributes.
    */
    extern ICS_API int ICS_class_create_mapping( char  * theSourceClassID,    /**< (I) ID of class to map ICOs from */
                                                 char  * theTargetClassID,    /**< (I) ID of class to map ICOs to   */
                                                 int     theMappingViewType,  /**< (I)  Mapping view type to create */
                                                 int     theAttributeCount,   /**< (I) Count of mapped attributes   */
                                                 int   * theAttributeIds,     /**< (I) theAttributeCount The attribute Ids */
                                                 char ** theAttributeMappings /**< (I) theAttributeCount The attribute mappings */
        );

    /**
       If a mapping exists between the given source and target class, return the
       target class? attributes as well as their corresponding attribute mappings.
    */
    extern ICS_API int ICS_class_describe_mapping( char   * theSourceClassID,    /**< (I)  ID of class to map ICOs from */
                                                   char   * theTargetClassID,    /**< (I)  ID of class to map ICOs to   */
                                                   int      theMappingViewType,  /**< (I)  Requested mapping view type  */
                                                   int    * theAttributeCount,   /**< (O)  Count of mapped attributes   */
                                                   int   ** theAttributeIds,     /**< (OF) theAttributeCount The attribute Ids */
                                                   char *** theAttributeMappings /**< (OF) theAttributeCount The attribute mappings */
        );

    /**
       Delete the mapping between the given source and target class, if one exists.
    */
    extern ICS_API int ICS_class_delete_mapping( char * theSourceClassID,  /**< (I) ID of the mapping?s source class */
                                                 char * theTargetClassID,  /**< (I) ID of the mapping?s target class */
                                                 int    theMappingViewType /**< (I) Type of mapping view to delete   */
        );

    /**
       Creates a new Item in inClass.
       The function is called by inClass Server before the save action of an ICO.
       The Classification Server provides the necessary Data as input (arrays) parameter for the call.
       These are the Classification Class ID and the attributes from the Dialog appearing
       when pressing the Save Button if the ICS_create_wso_on_save is set to "yes".
       The first thing to be done by the interface is to generate the attributes defined by the mapping preferences.
       Then it must check the validity and existence of the attributes according to the preferences.
       If all checks are done and don't result in a roll back, the workspace object (Item/Item Revision) will be created.
       Once the WSO is created the relevant Seed Data will be copied and related to the WSO according to the Seed Part.
    */
    extern ICS_API int ICS_ico_create_wso(
        const char*   theClassId,     /**< (I) The unique Id of the Class */
        int           theAttrCount,   /**< (I) The count of the attributes */
        int*          theAttrIds,     /**< (I) The attribute Ids */
        char**        theAttrValues,  /**< (I) The attribute values */
        int           theOptions,     /**< (I) Placeholder for future use */
        tag_t         *theWSO         /**< (O) Tag of the WSO */
        );

    /**
       Returns the tag of the ICOs whare the given ICO is used
    */
    extern ICS_API int ICS_ico_where_used(
        const char* theICOId,          /**< (I) The id of the ICO to find where used            */
        int         *theCount,         /**< (O) The number of references found                  */
        tag_t*      *theTagsWhereUsed  /**< (OF) theCount The list of ICO where the ICO is used */
        );
    /** @} */

    /**
       @name Attribute Dictionary related functions

       <b>Common return values:</b>

       #ICS_err_attribute_does_not_exist <br>
       #ICS_err_attribute_not_unique <br>
       #ICS_err_invalid_parameter <br>
       #ICS_err_invalid_property <br>
       #ICS_err_invalid_value <br>
       #ICS_err_missing_parameter <br>
       #ICS_err_object_referenced <br>
       #ICS_err_property_readonly <br>
       #ICS_invalid_attribute_id
       @{
    */

    /**
       Creates a new attribute with the given name and format.
    */
    extern ICS_API int ICS_attribute_create(
        int            theAttrId,       /**< (I) Unique identifier of the attribute. A value between -999 to 999 is not possible. */
        const char*    theAttrName,     /**< (I) Optional name of the attribute */
        int            theAttrFormat    /**< (I) The format of the attribute. For additional information about the
                                           attribute format definition refer #ICS_describe_format.
                                        */
        );

    /**
       ICS_attribute_creates a new unique attribute with the given name and format.
    */
    extern ICS_API int ICS_attribute_create_unique( const char* theAttrName,    /**< (I) The Attribute Name */
                                                    int         theAttrFormat,  /**< (I) The Format (!= 0) for the attribute */
                                                    int        *theAttrId       /**< (O) the newly created unique attribute id (>= 1000) */
        );

    /**
       Removes the attribute identified by theAttrId permanently from the database
    */
    extern ICS_API int ICS_attribute_remove(
        int            theAttrId    /**< (I) The unique identifier of the attribute */
        );

    /**
       Sets the value for the specified property of an existing attribute
    */
    extern ICS_API int ICS_attribute_set_property(
        int            theAttrId,           /**< (I) The unique identifier of the attribute */
        const char*    thePropertyName,     /**< (I) The specified property. Possible values are: <br>
                                               NAME <br>
                                               SHORT_NAME <br>
                                               REFERENCE <br>
                                               UNIT1 <br>
                                               UNIT2 <br>
                                               FLAGS <br>
                                               USER1 <br>
                                               USER2 <br>
                                               DEFAULT_VALUE <br>
                                               DEFAULT_VALUE2 <br>
                                               DESCRIPTION */
        const char*    thePropertyValue     /**< (I) The value for the specified property */
        );

    /**
       Returns the value for the specified property of an existing attribute
    */
    extern ICS_API int ICS_attribute_ask_property(
        int            theAttrId,           /**< (I) The unique identifier of the attribute */
        const char*    thePropertyName,     /**< (I) The specified property.
                                               For possible values see #ICS_attribute_set_property and additionally:  <br>
                                               ID <br>
                                               FORMAT1 <br>
                                               FORMAT2 <br>
                                               COMMENT */
        char**         thePropertyValue     /**< (OF) The value of the given property */
        );

    /**
       Returns the count and the values of the shared sites
    */
    extern ICS_API int ICS_attribute_ask_shared_sites(
        int            theAttrId,       /**< (I) The unique identifier of the attribute */
        int*           theSiteCount,    /**< (O) The number of shared sites */
        char***        theSharedSites   /**< (OF) theSiteCount The shared sites.
                                           Need to be freed using #MEM_free */
        );

    /**
       Returns all classes where this attribute is used
    */
    extern ICS_API int ICS_attribute_ask_references(
        int            theAttrId,       /**< (I) The unique identifier of the attribute */
        int*           theRefCount,     /**< (O) The number of classes where this attribute is used */
        char***        theRefs          /**< (OF) theRefCount The classes where this attribute is used */
        );

    /**
       Returns the tag for the given Attribute Id
    */
    extern ICS_API int ICS_attribute_ask_tag(
        int            theAttrId,   /**< (I) The Attribute Id */
        tag_t*         theTag       /**< (O) The Tag */
        );

    /**
       Returns the Attribute Id for the given tag
    */
    extern ICS_API int ICS_attribute_ask_id(
        tag_t          theTag,      /**< (I) The Tag */
        int*           theAttrId    /**< (O) The Attribute Id */
        );

    /**
       Call this function to define an attribute - given by its attribute ID in the Classification dictionary
       - as reference attribute. <br>
       Returns ITK_ok or different kinds of errors, for example trying to set a Reference Attribute type that
       does not exist.

       @note Use 0 as theReferenceAttributeType to define the attribute to be a "normal" attribute (non
       reference attribute).

    */
    int ICS_API ICS_attribute_set_as_reference(
        int        theAttributeID,            /**< (I) Attribute ID of the attribute that you want to define as
                                                 reference attribute. The parameter must specify an
                                                 existing attribute ID. */
        int        theReferenceAttributeType, /**< (I) One of the following values: <br>
                                                 0 - non reference attribute (in this case the subsequent
                                                 parameters are not used) <br>
                                                 #ICS_REFATTR_CLASSIFIED_OBJECT - a property or attribute of the
                                                 classified object <br>
                                                 #ICS_REFATTR_MASTERFORM - a property or attribute of the
                                                 Masterform of the classified item or item revision <br>
                                                 #ICS_REFATTR_RELATED_OBJECT - a property or attribute of an object
                                                 that is related (via an IMAN Relation) to the classified
                                                 object <br>
                                                 #ICS_REFATTR_ICO - an attribute of a different ICO */
        int        theFlags,                  /**< (I) Set to 0 or any combination of: <br>
                                                 #ICS_REFATTR_PROPERTY: set this flag if you want to define an IMAN
                                                 property - do not set it if you want to define a POM
                                                 Attribute <br>
                                                 #ICS_REFATTR_ITEM_ATTR: set this flag if you want to define a
                                                 reference attribute of an item. This means that if the
                                                 classified object is an item revision the reference
                                                 attribute value will be read from the item (or its
                                                 masterform / an object that is related to the item) of the
                                                 classified item revision. */
        const char *theClassName,             /**< (I) Depending on theReferenceAttributeType specify the
                                                 following value:
                                                 <ul>
                                                 <li> #ICS_REFATTR_CLASSIFIED_OBJECT: Classification class where
                                                 the referenced ICO is stored (parameter must not be
                                                 NULL).
                                                 <li> #ICS_REFATTR_MASTERFORM: IMAN Type of the classified object /
                                                 its item if #ICS_REFATTR_ITEM_ATTR is set in the flags (the
                                                 parameter may be NULL to specify that different IMAN
                                                 Types are allowed)
                                                 <li> #ICS_REFATTR_CLASSIFIED_OBJECT: POM Class / IMAN Type of the
                                                 classified object (its item if #ICS_REFATTR_ITEM_ATTR is set
                                                 in the flags) <br>
                                                 (the parameter may be NULL to specify that different
                                                 IMAN Types are allowed)
                                                 <li> #ICS_REFATTR_RELATED_OBJECT: POM Class / IMAN Type of the
                                                 related object (the parameter must not be NULL)
                                                 </ul>
                                                 (The second alternatives are valid if #ICS_REFATTR_PROPERTY is
                                                 specified in parameter theFlags) */
        const char *theAttrName,              /**< (I) This parameter must not be NULL. <br>
                                                 Depending on theReferenceAttributeType specify the
                                                 following value:
                                                 <ul>
                                                 <li> #ICS_REFATTR_CLASSIFIED_OBJECT: name of the POM Attribute /
                                                 IMAN Property where the value of the reference
                                                 attribute will be read from
                                                 <li> #ICS_REFATTR_MASTERFORM: name of the POM Attribute / IMAN
                                                 Property where the value of the reference attribute
                                                 will be read from (the POM Attribute / IMAN Property
                                                 is found in the Masterform of the classified object /
                                                 its item)
                                                 <li> #ICS_REFATTR_CLASSIFIED_OBJECT: Attribute ID of the attribute
                                                 that will be displayed as "key attribute" of the
                                                 referenced ICO
                                                 <li> #ICS_REFATTR_RELATED_OBJECT: name of the POM Attribute / IMAN
                                                 Property where the value of the reference attribute
                                                 will be read from (this POM Attribute / IMAN Property
                                                 is found in the related object)
                                                 </ul>
                                                 (The second alternatives are valid if ICS_PROPERTY is
                                                 specified in theFlags) */
        const char *theRelationName           /**< (I) If theReferenceAttributeType is #ICS_REFATTR_RELATED_OBJECT then
                                                 this parameter specifies the name of the IMAN Relation
                                                 with which the related object is attached to the classified object (may be
                                                 NULL to specify that any relation is possible). <br>
                                                 For all other Reference Attribute types this parameter is
                                                 not used. */
        );
    /**
       Call this function to ask the reference attribute properties of an attribute given by its attribute ID
       in the Classification dictionary. <br>
       Returns ICS_invalid_attribute_id if no attribute with the given attribute ID exists.
    */
    int ICS_API ICS_attribute_ask_reference_props(
        int   theAttributeID,              /**< (I) Attribute ID of the attribute from which you want to read the
                                              reference attribute definition. The parameter must specify an
                                              existing attribute ID. */
        int   *theReferenceAttributeType,  /**< (O) One of the following values:
                                              <ul>
                                              <li> 0 - normal attribute
                                              <li> #ICS_REFATTR_CLASSIFIED_OBJECT - a property or attribute of the
                                              classified object
                                              <li> #ICS_REFATTR_MASTERFORM - a property or attribute of the
                                              Masterform of the classified item or item revision
                                              <li> #ICS_REFATTR_RELATED_OBJECT - a property or attribute of an
                                              object that is related (via an IMAN Relation) to the
                                              classified object
                                              <li> #ICS_REFATTR_ICO - an attribute of a different ICO
                                              </ul> */
        int   *theFlags,                   /**< (O) 0 or a combination of: <br>
                                              #ICS_REFATTR_PROPERTY: this flag is set if an IMAN property is
                                              defined - if it is not set then a POM attribute is defined <br>
                                              #ICS_REFATTR_ITEM_ATTR: this flag is set if a reference attribute of
                                              an item is defined. This means that if the classified object
                                              is an item revision the reference attribute value will be
                                              read from the item (or its masterform / an object that is
                                              related to the item) of the classified item revision. */
        char  **theClassName,              /**< (OF) Depending on theReferenceAttributeType this parameter
                                              specifies one the following values:
                                              <ul>
                                              <li> #ICS_REFATTR_CLASSIFIED_OBJECT: Classification class where the
                                              referenced ICO is stored.
                                              <li> #ICS_REFATTR_MASTERFORM: IMAN Type of the classified object /
                                              its item if #ICS_REFATTR_ITEM_ATTR is set in the flags (the
                                              parameter may be NULL to specify that different IMAN
                                              Types are allowed)
                                              <li> #ICS_REFATTR_CLASSIFIED_OBJECT: POM Class / IMAN Type of the
                                              classified object / its item if ICS_ITEM_ATTR is set in
                                              the flags (the parameter may be NULL to specify that
                                              different IMAN Types are allowed)
                                              <li> #ICS_REFATTR_RELATED_OBJECT: POM Class / IMAN Type of the
                                              related object
                                              </ul>
                                              (The second alternatives are valid if #ICS_REFATTR_PROPERTY is set
                                              in theFlags) */
        char  **theAttrName,               /**< (OF) Depending on theReferenceAttributeType this parameter
                                              specifies the following value:
                                              <ul>
                                              <li> #ICS_REFATTR_CLASSIFIED_OBJECT: name of the POM Attribute /
                                              IMAN Property where the value of the reference
                                              attribute will be read from
                                              <li> #ICS_REFATTR_MASTERFORM: name of the POM Attribute / IMAN
                                              Property where the value of the reference attribute
                                              will be read from (the POM Attribute / IMAN Property is
                                              found in the Masterform of the classified object / its
                                              item)
                                              <li> #ICS_REFATTR_CLASSIFIED_OBJECT: Attribute ID of the attribute
                                              that will be displayed as "key attribute" of the
                                              referenced ICO
                                              <li> #ICS_REFATTR_RELATED_OBJECT: name of the POM Attribute / IMAN
                                              Property where the value of the reference attribute
                                              will be read from (this POM Attribute / IMAN Property
                                              is found in the related object)
                                              </ul>
                                              (The second alternatives are valid if #ICS_REFATTR_PROPERTY is set
                                              in theFlags) */
        char  **theRelationName            /**< (OF) If theReferenceAttributeType is #ICS_REFATTR_RELATED_OBJECT: name of
                                              the IMAN Relation with which the related object is attached
                                              to the classified object (may be NULL to specify that any
                                              relation is possible). <br>
                                              For all other Reference Attribute types this parameter is
                                              set to NULL. */
        );

    /**
       This function returns all dictionary attributes that match the
       given search criteria values. <br>
       The input to all output parameter except theCount can be NULL to indicate
       that the output should not be returned.
    */
    extern ICS_API int ICS_attribute_search( const char* theQuery,         /**< (I) the query: (unct) (op) (value), e.g. "-401 = attributename".
                                                                              Supported values for unct are:
                                                                              <ul><li> -400    Attribute ID
                                                                              <li> -401    Name
                                                                              <li> -402    Short Name
                                                                              <li> -403    Default Annotation
                                                                              <li> -404    Format 1
                                                                              <li> -405    Unit 1
                                                                              <li> -406    Format 2
                                                                              <li> -407    Unit 2             </ul> */
                                             int         theSortAttrID,    /**< (I) specifies the ID to be used for sorting the result,
                                                                              Possible value is one of the supported values for unct in theQuery */
                                             int         theOptions,       /**< (I) search options, supported is #ICS_SEARCH_CASE_INSENSITIVE to search without case sensitivity,
                                                                              when searching for IDs -401, -402, -403, -405 and -407 */
                                             int         *theCount,        /**< (O) Number of attributes found */
                                             tag_t       **theTags,        /**< (OF) theCount Tags of the attributes found */
                                             int         **theIDs,         /**< (OF) theCount Ids of the attributes */
                                             char*       **theNames        /**< (OF) theCount Names of the attributes */
        );


    /**
       This function convert the attribute value from one unit to another unit.
    */
    extern ICS_API int ICS_attribute_convert_attribute_values( const char* theInputUnit,             /**< (I) The input unit */
                                                               const char* theInputValue,            /**< (I) The input value */
                                                               const char* theOutputUnit,            /**< (I) The output unit */
                                                               int         theOutputAttributeFormat, /**< (I) The attribute format */
                                                               char**      theOutputValue            /**< (OF)The output value */
        );

    /** @} */

    /**
       @name KeyLOV functions

       <b>Common return values:</b>

       #ICS_err_invalid_keylov_id <br>
       #ICS_err_kelov_does_not_exist <br>
       #ICS_err_keylov_key_not_unique <br>
       #ICS_err_keylov_key_unknown <br>
       #ICS_err_object_referenced
       @{
    */

    /**
       Creates a new KeyLOV with the given parameters
    */
    extern ICS_API int ICS_keylov_create(
        const char*    theKeyLOVId,     /**< (I) Unique identifier of the KeyLOV
                                           @note Even if theKeyLOVId is of type char*,
                                           only id's representing a negative integer can be used
                                           as definition from an attribute. */
        const char*    theKeyLOVName,   /**< (I) Optional name of the KeyLOV */
        int            theOptions,      /**< (I) Not used in V8.1.1 and below */
        int            theCount,        /**< (I) The count of the entries ( key + value ) */
        char**         theKeys,         /**< (I) Required list of keys
                                           The keys will be stored in the ICO */
        char**         theValues        /**< (I) Optional corresponding list of values. The Values are only used for display.
                                           @note If a list of values are passed in,
                                           it must contain one value for each key which might be "" but not NULL */
        );

    /**
       Creates a new KeyLOV with a unique id and with the given parameters
       For the description of the parameter please refer ICS_keylov_create()
    */
    extern ICS_API int ICS_keylov_create_unique(
        const char *theKeyLOVName,   /**< (I) Key LOV Name */
        int        theOptions,       /**< (I) The flags */
        int        theCount,         /**< (I) The count */
        char       **theKeys,        /**< (I) The Keys for the Key LOV */
        char       **theValues,      /**< (I) The Values for the Key LOV */
        char*      *theNewId         /**< (OF) The Unique Id of the Key LOV created */
        );

    /**
       Removes the KeyLOV definition identified by theKeyLOVId permanently from the database
    */
    extern ICS_API int ICS_keylov_remove(
        const char*    theKeyLOVId      /**< (I) The unique identifier of the KeyLOV */
        );

    /**
       Adds keys and values to a KeyLOV
    */
    extern ICS_API int ICS_keylov_insert_entries(
        const char*    theKeyLOVId,     /**< (I) The unique identifier of the KeyLOV */
        const char*    theInsertKey,    /**< (I) In front of this existing key the following keys are inserted.
                                           If theInsertKey = NULL or "" then the inserted keys are added
                                           at the end of the existing keys. */
        int            theCount,        /**< (I) The number of keys to be added to the KeyLOV */
        char**         theKeys,         /**< (I) The KeyLOV keys to be added to the KeyLOV */
        char**         theValues        /**< (I) The values for the added keys */
        );

    /**
       Removes keys and values from a KeyLOV
    */
    extern ICS_API int ICS_keylov_remove_entries(
        const char*    theKeyLOVId,     /**< (I) The unique identifier of the KeyLOV */
        int            theCount,        /**< (I) The number of keys to be removed */
        char**         theKeys          /**< (I) The keys to be removed */
        );
        

        /**
                                             
       Sets the hide key option for the KeyLOV identified by theKeyLOVId
       To enable the setting set theOptions to 1. To disable the setting set it to 0.

       Return value: ICS_err_kelov_does_not_exist if the KeyLOV does not exist
    */
    extern ICS_API int ICS_keylov_set_options(
        const char*    theKeyLOVId,     /**< (I) The Key LOV Id*/
        int            theOptions       /**< (I) */
        );

    /**
       Sets the value for the specified property of an existing key LOV.

       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#SML_ERR_NO_INSTANCE_FOUND if the key LOV does not exist.
       <li>#ICS_err_invalid_property if the property does not exist.
       </ul>
    */
    extern ICS_API int ICS_keylov_set_property(
        const char*    theKeyLOVId,         /**< (I) The Key LOV ID */
        const char*    thePropertyName,     /**< (I) The specified property. Valid values are:
                                               <ul>
                                               <li>NAME: any value is allowed and taken as the name of the key LOV.
                                               <li>HIDEKEYS: any value other than "true" and "1" for @p thePropertyValue will result in not setting the HIDEKEYS flag.
                                               </ul> */
        const char*    thePropertyValue     /**< (I) The value for the specified property. */
        );

    /**
       Retrieves the value for the specified property of an existing key LOV.

       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#SML_ERR_NO_INSTANCE_FOUND if the key LOV does not exist.
       <li>#ICS_err_invalid_property if the property does not exist.
       </ul>
    */
    extern ICS_API int ICS_keylov_ask_property(
        const char*    theKeyLOVId,         /**< (I) The Key LOV ID */
        const char*    thePropertyName,     /**< (I) The specified property. Valid values are "NAME", "HIDEKEYS" and "ID". */
        char**         thePropertyValue     /**< (OF) The value of the given property */
        );


    /**
    Overwrites all existing values of the KeyLOV with the provided ones. 

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#ICS_err_kelov_does_not_exist if the KeyLOV does not exist
    <li>#SML_ERR_KEY_NOT_UNIQUE if @p theKeys contains a 0 pointer or empty string
    </ul>
    */
    extern ICS_API int ICS_keylov_set_entries( 
        const char*          theKeyLOVId,     /**< (I) The unique identifier of the KeyLOV */
        const unsigned int   theCount,        /**< (I) The number of keys to be added to the KeyLOV */
        const char         **theKeys,         /**< (I) theCount The KeyLOV keys to be set into the KeyLOV */
        const char         **theValues,       /**< (I) theCount The values for the keys to be set
                                              @note If an entry in @p theValues is a 0 pointer, the value will be set to an empty string*/
        const logical       *theDeprecateStatus /**< (I) theCount The deprecation status corresponding to KeyLOV keys. 
                                                @note If no entry is to be deprecated, use a 0 pointer.*/
                                             );


    /**
       Returns the count and the values of the shared sites
    */
    extern ICS_API int ICS_keylov_ask_shared_sites(
        const char*    theKeyLOVId,     /**< (I) The unique identifier of the KeyLOV */
        int*           theSiteCount,    /**< (O) The number of shared sites */
        char***        theSharedSites   /**< (OF) theSiteCount The shared sites.
                                           Need to be freed using #MEM_free */
        );

    /**
       Returns all attributes Ids which use the KeyLOV identified by theKeyLOVId
    */
    extern ICS_API int ICS_keylov_ask_references(
        const char*    theKeyLOVId,     /**< (I) The unique identifier of the KeyLOV */
        int*           theRefCount,     /**< (O) The number of references */
        int**          theRefs          /**< (OF) theRefCount The references */
        );

    /**
       Returns the POM tag for the given KeyLOV Id
    */
    extern ICS_API int ICS_keylov_ask_tag(
        const char*    theKeyLOVId,     /**< (I) The unique Id of the Key LOV */
        tag_t*         theTag           /**< (O) The POM Tag */
        );

    /**
       Returns the KeyLOV Id for the given POM tag
    */
    extern ICS_API int ICS_keylov_ask_id(
        tag_t          theTag,          /**< (I) The POM Tag */
        char**         theKeyLOVId      /**< (OF) The unique Id of the Key LOV*/
        );

    /**
       This function returns all keylovs that match the
       given search criteria values. <br>
       The input to all output parameter except theCount can be NULL to indicate
       that the output should not be returned.
    */
    extern ICS_API int ICS_keylov_search( const char* theQuery,     /**< (I) the query: (unct) (op) (value), e.g. "-430 = keylovid" *
                                                                       Supported values for unct are:
                                                                       <ul><li> -430    Keylov ID
                                                                       <li>     -431    Keylov Name     </ul> */
                                          int         theSortAttrID,    /**< (I) specifies the unct to be used for sorting the result,
                                                                           Possible value is one of the supported values for unct in theQuery */
                                          int         theOptions,       /**< (I) search options, supported is #ICS_SEARCH_CASE_INSENSITIVE to search without case sensitivity */
                                          int         *theCount,        /**< (O) Number of keylovs found */
                                          tag_t       **theTags,        /**< (OF) theCount Tags of the keylovs found */
                                          char*       **theIDs,         /**< (OF) theCount Ids of the keylovs */
                                          char*       **theNames        /**< (OF) theCount Names of the keylovs */
        );


    /**
       Deprecates/Un-deprecates the specified Key LOV entries for the given LOV Keys.
    */
    extern ICS_API int ICS_keylov_deprecate_entries( const char  *key_lov_id ,     /* <(I)> The unique identifier of the Key LOV */
                                                     int         n_lov_value_keys, /* <(I)> Number of Keys of the LOV values */
                                                     char        **lov_value_keys, /* <(I)> n_lov_value_keys Array of LOV value Keys */
                                                     logical     *deprecate_status /* <(I)> n_lov_value_keys Array of Logical values true/false, indicates
                                                                                      Deprecate/Un-deprecate status corresponds Key LOV
                                                                                      value in the lov_value_keys array*/
        );

    /**
       Returns all values of the Key LOV for the specified Key LOV ID.
    */
    extern ICS_API int ICS_keylov_get_keylov( const char*  key_lov_id,            /* <I>  The unique identifier of the Key LOV */
                                              char         **key_lov_name,        /* <OF> The name of Key LOV */
                                              int          *options,              /* <O>  The options for the Key LOV */
                                              int          *n_lov_entries,        /* <O>  Number of Key LOV values */
                                              char         ***lov_keys,           /* <OF> n_lov_entries Array of LOV Keys  */
                                              char         ***lov_values,         /* <OF> n_lov_entries Array of LOV values */
                                              logical      **deprecated_staus,    /* <OF>  n_lov_entries Array of Deprecated status of each Key LOV value */
                                              char         **owning_site,         /* <OF> The owning site*/
                                              int          *n_shared_sites,       /* <O>  The number of shared sites*/
                                              char         ***shared_sites        /* <OF> n_shared_sites Array of shared sites */
        );


    /**
       Returns the deprecated status of given LOV Key.
    */
    extern ICS_API  int ICS_keylov_is_entry_deprecated( const char  *key_lov_id,    /**< (I) The unique identifier of the KeyLov*/
                                                        const char  *lov_value_key, /**< (I)KeyLOV Value*/
                                                        logical     *deprecate      /**<O>Deprecated status of the entry*/
        );


    /**
       Returns true if the ICO attribute is localizable
    */
    extern ICS_API int ICS_ico_property_isLocalizable(
        tag_t       theICOTag,            /**< (I) The ICO Tag */
        const int   theAttributeId,   /**< (I) The Attribute id*/
        logical     *isLocalizable    /**< (O) is Localizable*/
        );

    /**
       Returns the list of localizable ICO attributes
    */
    extern ICS_API int ICS_ico_ask_localizable_properties(
        tag_t     theICOTag,          /**< (I) The ICO Tag */
        int       *theAttributeCount, /**< (O) The Attribute count*/
        int       **theAttributeIds   /**< (OF) theAttributeCount The Localizable Attribute Ids*/
        );

    /**
       Sets one or more values on a string property.
    */
    extern ICS_API int ICS_ico_set_localized_value_strings( tag_t       theICOTag,                 /**< (I) The ICO Tag*/
                                                            int          noAttributes,              /**< (I) The Attribute count */
                                                            int*         theAttributeIds,           /**< (I) List of attribute Id */
                                                            const char*  locale,                    /**< (I) locale for which the value need to set*/
                                                            int*         theAttributeValCount,      /**< (I) Array of number of values*/
                                                            char***      theAttributeValues,        /**< (I) List of value array */
                                                            char**       localization_statuses,     /**< (I) Array of localisation */
                                                            logical      isMaster                   /**< (I) Flag to Indicate wether the locale is master*/
        );

    /**
       Asks one or more values of a string property. The property can be single-valued or multi-valued (i.e., array or list).
    */
    extern ICS_API int ICS_ico_ask_localized_value_strings(
        tag_t       theICOTag,              /**< (I) The ICO Tag */
        const int   theAttributeId,         /**< (I) Attribute Id of the ICO */
        const char* locale,                 /**< (I) The locale of the property value */
        int*        theAttributeValCount,   /**< (O) Number of values returned. */
        char***     theAttributeValues,     /**< (OF) theAttributeValCount The num values of the property. This must be a list or array of constant chars. */
        char**      localization_statuses,  /**< (OF) theAttributeValCount The list of localization statuses each applicable to the corresponding property value in the values array. */
        logical*    isMaster                /**< (O) specifies if the locale specified as input is the master locale for each property value in the values array. */
        );
    /**
       Returns true if theTag is of the asked type
    */
    extern ICS_API logical ICS_is_keylov(
        tag_t              theTag   /**< (I) */
        );

    /**
       Returns true if theTag is of the asked type
    */
    extern ICS_API logical ICS_is_attribute(
        tag_t              theTag   /**< (I) */
        );

    /**
       Returns true if theTag is of the asked type
    */
    extern ICS_API logical ICS_is_class(
        tag_t              theTag   /**< (I) */
        );

    /**
       Returns true if theTag is of the asked type
    */
    extern ICS_API logical ICS_is_view(
        tag_t              theTag   /**< (I) */
        );

    /**
       Returns true if theTag is of the asked type
    */
    extern ICS_API logical ICS_is_subclass(
        tag_t              theTag   /**< (I) */
        );

    /**
       Returns true if theTag is of the asked type
    */
    extern ICS_API logical ICS_is_ico(
        tag_t              theTag   /**< (I) */
        );

    /**
       Imports the content of the given sml file
    */
    extern ICS_API int ICS_sml_import(
        char *file,        /**< (I) absolute pathname of file to import from */
        char *importMode   /**< (I) import mode: Use "1" to insert and "2" to update. */
        );


    /**
       Auto-compute attribute values for classification object (ICO) based on custom program registered with BMF_ICS_exec_custom_attribute_logic operation in BMIDE
    */
    extern ICS_API int ICS_ico_auto_compute(
        const char      *theICOid,                      /**< (I) ICO id                                                         */
        const char      *theClassId,                    /**< (I) Class id                                                       */
        const char      *theViewId,                     /**< (I) View id                                                        */
        const int       theUnitSystem,                  /**< (I) Unit System of the ICO                                         */
        tag_t           theWsoTag,                      /**< (I) Workspace object tag that is being classified                  */
        const int       theMode,                        /**< (I) AutoCompute operation mode                                     */
        const int       theAttributeCount,              /**< (I) The number of attributes                                       */
        const int       *theAttributeIds,               /**< (I) Array of attribute ids                                         */
        const int       *theAttrValueCounts,            /**< (I) Array of attribute value count                                 */
        const char      ***theAttributeValues,          /**< (I) Array of attribute values                                      */
        const int       *theAttributeLengths,           /**< (I) Array of attribute array sizes                                 */
        const char      **theAttributeUnits,            /**< (I) Array of attribute units                                       */
        const int       *theAttributeFlags,             /**< (I) Array of attribute flags                                       */
        const logical   *theModifiedFlag,               /**< (I) Array of flags specifying the updated attributes               */
        int             *theAutoComputedCount,          /**< (O) The number of auto computed attributes                         */
        int             **theAutoComputedIds,           /**< (OF) theAutoComputedCount Array of auto computed attribute ids                          */
        int             **theAutoComputedValueCounts,   /**< (OF) theAutoComputedCount Array of attribute value count                                */
        char            ****theAutoComputedValues,      /**< (OF) theAutoComputedCount Array of auto computed attribute values                       */
        int             **theAutoComputedLengths,       /**< (OF) theAutoComputedCount Array of attribute array sizes                                */
        char            ***theAutoComputedUnits,        /**< (OF) theAutoComputedCount Array of auto computed attribute units                        */
        int             **theAutoComputedFlags          /**< (OF) theAutoComputedCount Array of auto computed attribute flags                        */
        );


    /**
       This API is to be used for writing the custom program to be registered with BMF_ICS_exec_custom_attribute_logic operation in BMIDE.
       Register the attribute dependencies for auto-computed attributes.
    */
    extern ICS_API int ICS_auto_compute_register_attrs(
        const char   *class_id,                             /**< (I) Class Id                       */
        const char   *view_id,                              /**< (I) View Id                        */
        const int     size,                                 /**< (I) No of Attributes               */
        ICS_auto_compute_attr_t *auto_compute_attrs,        /**< (I) Array of attribute structures  */
        logical  toOverride                                 /**< (I) Flag to indicate  overiding of the parent class registration*/
        );

    /**
       This API is to be used for writing the custom program to be registered with BMF_ICS_exec_custom_attribute_logic operation in BMIDE.
       Set the auto computed attribute values. This API to be used with attributes with an array of values.
    */
    extern ICS_API int ICS_auto_compute_set_attr_values(
        const  int     theAttributeId,         /**< (I) Attribute Id               */
        const  int     theAttrValueCount,      /**< (I) Attribute Value Count      */
        const  char    **theAttributeValues,   /**< (I) Attribute Value Array      */
        const  char    *theUnit                /**< (I) Attribute Unit System      */
        );
    /**
       This API is to be used for writing the custom program to be registered with BMF_ICS_exec_custom_attribute_logic operation in BMIDE.
       Set the auto computed attribute value
    */
    extern ICS_API int ICS_auto_compute_set_attr_value(
        const  int     theAttributeId,         /**< (I) Attribute Id               */
        const  char    *theAttributeValue,     /**< (I) Attribute Value            */
        const  char    *theUnit                /**< (I) Attribute Unit System      */
        );
    /**
       This API is to be used for writing the custom program to be registered with BMF_ICS_exec_custom_attribute_logic operation in BMIDE.
       Set the auto computed attribute property
    */

    extern ICS_API int ICS_auto_compute_set_attr_prop(
        const  int     theAttributeId,         /**< (I) Attribute Id       */
        const  int     thePropType,            /**< (I) Property Type      */
        const  logical theValue                /**< (I) Property Value     */
        );
    /**
       This API is to be used for writing the custom program to be registered with BMF_ICS_exec_custom_attribute_logic operation in BMIDE.
       The method is used for retreiving the values of the attribute. This API is to be used with attributes with an array of values.
    */
    extern ICS_API int ICS_auto_compute_get_attr_values(
        const   int attributeId,    /**< (I) attribute id                        */
        int         *valueCount,    /**< (O) Attribute Value count               */
        char        ***value,       /**<(OF) valueCount array of values for the attribute   */
        int         *format,        /**< (O) The attribute format                */
        char        **unit          /**<(OF) valueCount value of the unit                   */
        );
    /**
       This API is to be used for writing the custom program to be registered with BMF_ICS_exec_custom_attribute_logic operation in BMIDE.
       The method is used for retreiving the value of the attribute
    */
    extern ICS_API int ICS_auto_compute_get_attr_value(
        const   int attributeId,    /**< (I) attribute id                */
        char        **value,        /**<(OF) value of the attribute id   */
        int         *format,        /**< (O) The attribute format        */
        char        **unit          /**<(OF) value of the unit           */
        );


    /**
       This API is to be used for writing the custom program to be registered with BMF_ICS_exec_custom_attribute_logic operation in BMIDE.
       The method is used for retreiving the property value of the attribute id
    */
    extern ICS_API  int ICS_auto_compute_get_attr_prop(
        const  int  theAttributeId,    /**< (I) attribute id                          */
        int         thePropType,       /**< (I) property type of the attribute        */
        logical     *theValue          /**< (O) true/false for the specified property */
        );
    /**
       This API is used for checking the privialge of the Inclass object like Class,Subclass,Class Attributes,View Attributes
       based on the ACL information configured in the classification Admin
    */
    extern ICS_API  int ICS_check_privilege(
        tag_t theInstanceTag,/**< (I) Instance Tag */
        const char *thePrivilegeName,/**< (I) The name of the privilage to be checked*/
        logical *isGrantedExt /**< (O) true/false for the specified privilage */
        );

    /**
       Removes the class and its hierarchy with the given parameters
    */
    extern ICS_API int ICS_class_remove_hierarchy (
        const char  *theClassId,                /**< (I)    class id                                    */
        logical     theRecurseOption,           /**< (I)    theRecurseOption for child elements         */
        logical     theViewsOption,             /**< (I)    Option to remove views                      */
        logical     theIcosOption,              /**< (I)    Option to remove Icos                       */
        logical     theWSOOption,               /**< (I)    Option to remove WSO                        */
        logical     theChildrenOnlyOption,      /**< (I)    Option to remove the ChildrenOnly           */
        logical     theIgnoreOption,            /**< (I)    theIgnoreOption                             */
        logical     thePurgeAttrs,              /**< (I)    thePurgeAttrs                               */
        logical     thePurgeKeyLOV,             /**< (I)    thePurgeKeyLOV                              */
        int         *theFailedObjectsCount,     /**< (O)    the number of failed objects count          */
        char*       *theFailedObjects           /**< (OF)   theFailedObjectsCount the failed class id's */
        );
    /*===========================================================================
    **  ICS_class_search_libraries returns the information about the libraries found by searchStrings
    **
    **            theCount       : the number of classes matching theQuery
    **
    **           NOTE: The input to all following values can be NULL to indicate
    **                 that the output should not be returned.
    **
    **            theTags            : the tags of the found classes
    **            theTypes           : the types of the classes
    **                                   Posible values are: Group, Class, StorrageClass
    **            theCIDs            : the unique class ids
    **            theparentCIDs      : the unique class ids of parent
    **            theNames           : the class names
    **            theInstancesCounts : the number of instances stored in each class (including subclass instances)
    **            theChildCounts     : the number of  children (of type Group,Class or StorrageClass) each class has
    **            theLibraries       : the library value for found libraries
    **
    ** Return value :
    **                ITK_OK
    **                Error discovered
    **
    */

    /**
       Returns the information about the libraries found by theSearchStrings
    */

    extern ICS_API int ICS_class_search_libraries(
        int          theNumSearchStrings,    /**<  (I) Number of search strings                                    */
        const char*  *theSearchStrings,      /**<  (I) Array of search strings                                     */
        int          *theCount,              /**<  (O) Number of classes found                                     */
        tag_t        **theTags,              /**< (OF) theCount Tags of the classes found                           */
        char*        **theTypes,             /**< (OF) theCount Types of the classes                                */
        char*        **theCIDs,              /**< (OF) theCount Ids of the classes                                  */
        char*        **theParentCIDs,        /**< (OF) theCount Parent ids of the classes                           */
        char*        **theNames,             /**< (OF) theCount Names of the classes                                */
        int          **theInstancesCounts,   /**< (OF) Number of instances stored in the class and any child class  */
        int          **theChildCounts,       /**< (OF) Number of children of the classes                            */
        char*        **theLibraries          /**< (OF) theCount library values for classes                          */
        );

    /*===========================================================================
    **  ICS_class_ask_parentinfo returns the information about all the parents found by theChildCIDs
    **
    **            theParentCount     : the number of classes matching theChildCIDs
    **
    **           NOTE: The input to all following values can be NULL to indicate
    **                 that the output should not be returned.
    **
    **            theparentTags      : the tags of the found parent classes
    **            theparentTypes     : the types of the parent classes
    **                                   Posible values are: Group, Class, StorrageClass
    **            theparentCIDs      : the unique class ids of parents
    **            theNames           : the class names of parents
    **            theInstancesCounts : the number of instances stored in each parent class (including subclass instances)
    **            theChildCounts     : the number of  children (of type Group,Class or StorrageClass) each parent class has
    **
    ** Return value :
    **                ITK_OK
    **                Error discovered
    **
    */

    /**
       Returns the information about all the parents found by theChildCIDs
    */
    extern ICS_API int ICS_class_ask_parentinfo( int          theNumCIDs,             /**<  (I) Number of the child classes                                 */
                                                 const char*  *theChildCIDs,          /**<  (I) Array of child class IDs                                    */
                                                 int          *theParentCount,        /**<  (O) The number of parents found                                 */
                                                 tag_t        **theParentTags,        /**< (OF) theParentCount Tags of the parents found                    */
                                                 char*        **theParentTypes,       /**< (OF) theParentCount Types of the parent classes
                                                                                         Posible values are: Group, Class, StorageClass             */
                                                 char*        **theParentCIDs,        /**< (OF) theParentCount Class IDs of the Parent classes             */
                                                 char*        **theNames,             /**< (OF) theParentCount Names of the parent classes                  */
                                                 int          **theInstancesCounts,   /**< (OF) Number of instances stored in the class and any child class */
                                                 int          **theChildCounts        /**< (OF) Number of children of the classes                           */
        );


/**
   Retrieves the information about dependent attributes in the given class when the selected attribute value has changed.
   <br/>Values are returned for all given UI attributes that have changed in the parameters @p selected_attr / @p selected_value.

   <br/>The @p class_id parameter must be a valid class ID and not NULL <br>
   All other input values can be set as follows:
   <table>
   <tr><td>USE CASE                    </td><td>  selected_attr   </td><td> selected_value   </td><td> ui_attr_count  </td><td> ui_attr_ids  </td><td> ui_attr_values  </td></tr>
   <tr><td>User has selected a value   </td><td>  valid attr ID   </td><td> valid value      </td><td> UI attr count  </td><td> UI attr IDs  </td><td> UI attr values  </td></tr>
   <tr><td>User has deselected a value </td><td>  valid attr ID   </td><td> "" or NULL       </td><td> UI attr count  </td><td> UI attr IDs  </td><td> UI attr values  </td></tr>
   <tr><td>Initial view                </td><td>  0               </td><td> 0                </td><td> UI attr count  </td><td> UI attr IDs  </td><td> NULL or empty UI attr values </td></tr>
   <tr><td>Edit Mode                   </td><td>  0               </td><td> 0                </td><td> UI attr count  </td><td> UI attr IDs  </td><td> ICO values (currently displayed in the view) </td></tr>
   </table>

   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#SML_ERR_NO_INSTANCE_FOUND if the class does not exist.
   <li>#SML_ERR_ATTR_NOT_IN_CLASS if the selected attribute is not in the class
   </ul>
*/
    extern ICS_API int ICS_class_attr_ask_dep_keylovs(
        const char*  class_id,                       /**< (I)  Class ID, must not be NULL */
        int          selected_attr,                  /**< (I)  The selected attribute */
        const char*  selected_value,                 /**< (I)  The selected value */
        int          ui_attr_count,                  /**< (I)  Number of attributes in the UI */
        const int*   ui_attr_ids,                    /**< (I)  UI attribute IDs */
        const char** ui_attr_values,                 /**< (I)  UI attribute values */
        int         *changed_attr_count,             /**< (O)  Number of changed keylovs */
        ICS_keylov_descriptor_p_t **changed_keylovs  /**< (OF) changed_attr_count The changed Keylovs */
        );



    /**
       Retrieves the information about the 'common' attributes for the input classes.
       <br/>The attributes searched and returned must:
       <ul>
       <li>belong to the 'Search Index View'</li>
       <li>have 'Used as facet' flag set.</li>
       </ul>

       @returns #ITK_ok always.
       <br/>In case of invalid inputs, no results will be returned (attribute count equals to 0).
    */
    extern ICS_API int ICS_ask_common_attributes_used_as_facets2(
        int             class_ids_count,                    /**<  (I) The Class ID count.                                                                            */
        const char      **class_ids,                        /**<  (I) The Class IDs for which the attributes are to be found.                                        */
        int             *attribute_count,                   /**<  (O) The count of the matching attributes found.                                                    */
        int             **attribute_ids,                    /**< (OF) attribute_count The IDs of the matching attributes.                                            */
        int             **attribute_metric_formats,         /**< (OF) attribute_count The metric format values of the attributes.
                                                               <br> The attribute format defines the type of value that
                                                               can be stored for the attribute.
                                                               <br> For additional information about the attribute format
                                                               definition, refer #ICS_describe_format.                                              */
        int             **attribute_non_metric_formats,     /**< (OF) The non-metric format values of the attributes.                                                */
        char            ***attribute_names,                 /**< (OF) attribute_count The attribute names.The output string array is SM-packed,
                                                               hence should be freed by calling #MEM_free on the container only.                           */
        char            ***attribute_metric_units,           /**< (OF) attribute_count The metric unit value for attributes.The output string array is SM-packed,
                                                                hence should be freed by calling #MEM_free on the container only.                           */
        char            ***attribute_non_metric_units       /**< (OF) attribute_count The non metric unit value for attributes.The output string array is SM-packed,
                                                               hence should be freed by calling #MEM_free on the container only.                           */
        );

    /**
        Retrieves the information about the "indexable" attributes in the system.
        <br/>The attributes searched and returned must:
        <ul>
        <li>belong to the 'Search Index View'</li>
        </ul>
        
        @returns
        <ul>
        <li>#ITK_ok on success
        <li>POM enquiry related error otherwise.
        </ul>
    */
    extern ICS_API int ICS_ask_indexable_attributes(
        int             *attribute_count,                   /**<  (O) The count of the matching attributes found.                                   */
        int             **attribute_ids,                    /**< (OF) attribute_count The IDs of the matching attributes.                           */
        int             **attribute_metric_formats,         /**< (OF) attribute_count The metric format values of the attributes.
                                                               <br> The attribute format defines the type of value that
                                                               can be stored for the attribute.
                                                               <br> For additional information about the attribute format
                                                               definition, refer #ICS_describe_format.                             */
        int             **attribute_non_metric_formats,     /**< (OF) The non-metric format values of the attributes.                               */
        char            ***attribute_names,                 /**< (OF) attribute_count The attribute names.The output string array is packed,
                                                               hence should be freed by calling #MEM_free on the container only.          */
        char            ***attribute_metric_units,          /**< (OF) attribute_count The metric unit value for attributes.The output string array is packed,
                                                               hence should be freed by calling #MEM_free on the container only.          */
        char            ***attribute_non_metric_units       /**< (OF) attribute_count The non metric unit value for attributes.The output string array is packed,
                                                               hence should be freed by calling #MEM_free on the container only.          */
        );

    /**
       Retrieves the dependent classified workspace object.
       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#SML_ERR_MISSING_PARAMETER in case of invalid input.
       </ul>
    */
    extern ICS_API int ICS_ask_dependent_classified_WSO(
        const tag_t theWSOTag,                   /**< (I) The WorkspaceObject tag */
        tag_t      *theDependentClassifiedWSO    /**< (O) The dependent WorkspaceObject tag */
        );

/** @} */

#ifdef __cplusplus
}
#endif
/** @} */

#include <ics/libics_undef.h>

#endif
