/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Interface definition for the POM module.

    Contains:
    <ul>
    <li>definitions of all typedefs used in the interface, and some constants
        to be used with these types.
    <li>definitions of assorted limits (e.g. max. string length)
    <li>definitions of tokens
    <li>declarations of all the procedures in the interface
    </ul>
*/

/** @if DOX_IGNORE
    Error codes are in pom_errors.h, which is included by this file.

    Do not produce any #defines for macros other than constants in this file.
    The defines here are used in generating the 'filter_out_pom_tokens' mangler.

    pom.inc depends on basic.inc

    Function declarations

    (I)                indicates input argument
    (I)  argument-name indicates input array of length "argument-name"
    (O)                indicates output argument
    (OF)               indicates output argument which should be passed to POM_free after use
    (OF) argument-name indicates output argument array of length "argument-name"
                       which should be passed to POM_free after use
                       (note that "argument-name" should not contain whitespace;
                       neither should it contain the "*" even if it
                       is also a returned argument - this is so my simple-minded
                       test-bed parser works (Mark, November 1989)

    If you add a new function, please:

    - add a corresponding  "#define POM_F_<name> <something>" to pom_internal.h
    - add a case to cope with this in the function POM_name_of_function in pom_token_conversion.c

    17/8/90 ARMB  New 'case' done automatically by token_conversion.mangler
    generating pom_name_of_function.h
@endif */

/*  */

#ifndef POM_H
#define POM_H

/** @if DOX_IGNORE
    Force cc_check's dependency analysis to always assume
    pom.h is needed so it never warns to remove it.
@endif */
#ifdef __lint
    #pragma uginclude needed
#endif

#include <limits.h>

#include <unidefs.h>
#include <pom/pom/pom_typedefs.h>
#include <pom/enq/old_on_new.h>

#include <pom/pom/pom_mapping.h>
#include <pom/pom/pom_errors.h>
#include <pom/pom/pom_tokens.h>
#include <pom/pom/pom_macros.h>

#include <pom/pom/libpom_exports.h>

/**
    @defgroup POM Persistent Object Manager (POM)

    The Persistent Object Manager (POM) forms part of the Data Management architectural layer of the ITK.
    POM provides the interface between the object-oriented design methodology of the
    Teamcenter applications and the Relational Database Management System (RDBMS) upon which it is implemented.

    It is suggested that AOM be used by code using Teamcenter supplied classes
    (i.e., datasets, Items, etc.) and POM be used directly when dealing with your extensions to the schema.

    For example, a Form can use a POM class to store the data.
    Any searches or reports against the same must be done through POM since the AOM only loads
    classes known to the C++ encapsulation. This layer cannot be user extended at present.

    Also, the POM should not be used directly against AOM loaded classes since
    the correspondence between the POM object and its C++ encapsulation can be broken (with unpredictable results).

    @note POM ITK module does not support relations (typed or untyped) for tag data types.

    <b>The Initial Data Model</b>
    The following paragraphs describe the POM's initial data model.
    <br/>This consists of the "basic types" and the Core Objects and Attributes.

    Basic Types

    <table>
    <tr><td>Type   </td><td>Description                                                                          </td></tr>
    <tr><td>short  </td><td>Integer attribute (C two byte signed short). Access via POM int functions.           </td></tr>
    <tr><td>float  </td><td>Real attributes (C single precision floating point). Access via POM double functions.</td></tr>
    <tr><td>note   </td><td>Note attributes are used for long text fields (up to 1950 bytes).
                            These can be longer than regular strings, but involve storage overhead.
                            Access via POM string functions.                                                     </td></tr>
    <tr><td>int    </td><td>Integer attributes (C four byte signed integer). Access via POM int functions.       </td></tr>
    <tr><td>double </td><td>Real attributes (C double precision floating point). Access via POM double functions.</td></tr>
    <tr><td>char   </td><td>Char attributes (C single byte character). Access via POM char functions.            </td></tr>
    <tr><td>string </td><td>String attributes (C strings). Access via POM string functions.                      </td></tr>
    <tr><td>tag    </td><td>Tag attributes (tags are used as references to POM instances and classes).
                            Defined in unidefs.h. Access via POM tag functions.                                  </td></tr>
    <tr><td>logical</td><td>Logical attributes (true/false state). Defined in unidefs.h.
                            Access via POM logical functions.                                                    </td></tr>
    <tr><td>date   </td><td>Date attributes. Year (four digits), month (zero to eleven), day (one to thirty-one)
                            hour (zero to twenty three), minutes and seconds (both zero to fifty nine),
                            and must be later than minimum specified by POM_ask_earlier_date (currently 2nd Jan 1900).
                            Defined in unidefs.h. Access via POM date functions.                                 </td></tr>
    </table>

    Fixed and variable length arrays of these also exist.

    There are also the types:
    <ul>
    <li>class_id
    <li>attr_id
    <li>enquiry_id
    </ul>
    Attributes cannot hold values of these types; they are available purely at the level of the POM interface.

    <b>Core Classes</b>

    This topic shows the initial classes and their attribute definitions,
    in the syntax which would be used to define them in a textual definition file if they didn't already exist.

    <pre>
    database class POM_object

            superclass OM_tagged_object
            private POM
            uninstantiable

        attribute pid

            int
            attribute timestamp
            string []

    database class POM_system_class

        superclass POM_object
        private POM
        uninstantiable

    database class POM_application_object

            superclass POM_object
            private POM

        attribute owning_user

            untyped_reference
            public_read

        attribute owning_group

            untyped_reference
            public_read

        attribute acl_bits

            int

        attribute creation_date

            date
            public_read

        attribute last_mod_date

            date
            public_read

        attribute last_mod_user

            untyped_reference
            public_read

        attribute archive_date

            date
            NULL_valid
            initial_value
            public_read

        attribute archive_info

            string [127]

        attribute backup_date

            date
            NULL_valid
            initial_value
            public_read

    database class POM_group

            superclass POM_system_class
            private USER

        attribute name

            string [31]
            public_read
            NULL_valid
            unique

        attribute privilege

            int
            public_read
            NULL_valid

    database class POM_user

            superclass POM_system_class
            private USER

        attribute user_id

            string [31]
            public_read
            NULL_valid
            unique

        attribute password

            string [31]
            NULL_valid

        attribute user_name

            string [127]
            public_read
            NULL_valid

        attribute status

            int
            public_read
            NULL_valid

        attribute def_acl

            int
            NULL_valid

        attribute default_group

            ext_reference
            public_read
            NULL_valid

    database class POM_member

            superclass POM_system_class
            private USER

        attribute user

            typed_reference POM_user
            public_read
            NULL_valid

        attribute group

            typed_reference POM_group
            public_read
            NULL_valid

        attribute ga

            logical
            public_read
            NULL_valid
    </pre>
    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif

POMAPI date_t POM_null_date(void);

POMAPI date_t* POM_null_date_ptr(void);

#ifdef __cplusplus
    }
#endif

#define NULLTAG                         ((tag_t)0)
#define NULLCLASS                       ((tag_t)0)
#define NULLDATE                        (POM_null_date())

/**
    @name Some maxima
    @{
*/

/** Class and attribute name length same as OM */
#define POM_MAX_NAME_LENGTH             27

#define POM_MAX_ATTR_ARRAY_LENGTH       INT_MAX

/** Maximum length of a string attribute. (Oracle CHAR limit) */
#define POM_MAX_MAX_STRING_LENGTH       4000

/**
    Maximum length of an indexed string attribute. Limitation based
    on MSSQL support where maximum index key size is 900 bytes. This
    translates to 450 NVARCHAR characters.
*/
#define POM_MAX_INDEXED_STRING_LENGTH       450

/** Maximum length of a string attribute. (Oracle CHAR limit) */
#define POM_MAX_NOTE_LENGTH             4000

/**
    Attributes defined in a class.
    (Limited by columns in table, and columns in view, so actually
    long arrays and transient attributes shouldn't count towards these)
*/
#define POM_MAX_ATTRS_IN_CLASS          1000

/**
    Attributes defined in class and all its superclass.
    (Limited by columns in table, and columns in view, so actually
    long arrays and transient attributes shouldn't count towards these)
*/
#define POM_MAX_TOTAL_ATTRS_IN_CLASS    1000

/** Attributes in index limited by DB columns in index */
#define POM_MAX_ATTRS_IN_INDEX          16

/** Attributes in unique set limited by DB columns in index */
#define POM_MAX_IN_UNIQUE_SET           16

/**
    Predicates in 'where' clause
    (number of enquiries which can be combined)
    (Arrays count once per element in enquiry, plus once for join)
 */
#define POM_MAX_ATTRS_IN_ENQUIRY        50

/** Attributes in 'order by' clause */
#define POM_MAX_ATTRS_IN_ORDER          127

#define POM_MAX_ENQUIRIES               99999

/** Limited by length of 'in' clause */
#define POM_MAX_INSTANCES               100

/** Define license_level symbolic names */
/** PR6433704 - Moved from pom.h. To be deprecated soon after we
introduce set user license status API in sa module. */
#define POM_license_level_author        0
#define POM_license_level_consumer      1
#define POM_license_level_occasional    2
#define POM_license_level_viewer        3
#define POM_license_level_user          4
#define POM_license_level_admin         5
#define POM_license_level_max           5


/** Values to describe the type of a table.  <br>
    Pass as a parameter to POM_create_table and POM_generate_table_name functions. */ 
#define POM_TABLE_TYPE_NOT_SET 0    /** Not set to anything yet, undefined table type. */
#define POM_PERSISTENT_TABLE   1    /** Type designation for a persistent table. not supported yet*/
#define POM_TEMPORARY_TABLE    2    /** Type designation for a temporary table. */

/** Values to describe when to clear a temp table's rows, e.g., end of session or end of transaction. <br>
    Pass as a parameter to POM_create_table function when tableType == POM_TEMPORARY_TABLE. */
#define  POM_TT_CLEAR_ROWS_NOT_SET 0    /** Not set to anything yet. */
#define  POM_TT_CLEAR_ROWS_EOS     1    /** Clear rows at the end of session (EOS). */
#define  POM_TT_CLEAR_ROWS_EOT     2    /** Clear rows at the end of transaction (EOT). */


/** @} */

/**
    @name Valid input parameters for the #POM_set_user_license_status ITK
    @{
*/
#define POM_USER_STATUS_ACTIVE 0
#define POM_USER_STATUS_INACTIVE 1

/** @} */

/**
    Columns names made public via pom_tokens.inc (for generating sql).
*/

/** @if DOX_IGNORE
    Anything after the next line will be read by process_pif_file,
    please stick to the standard formatting to avoid indigestion
@endif */

/* END OF HEADER */

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @name Basic POM Functions
    @{
*/

/**
    Defines an index by:
    <ul>
    <li>taking an existing class
    <li>a number of attributes which are already associated with that class
    <li>adding that index definition to the class definition.
    </ul>

    <b>Restrictions:</b>

    A particular class cannot have two indexes of the same name, but two different classes can.
    Therefore, the name of an existing index is not always enough to specify it unambiguously.
    The addition of a class_id will remove this ambiguity.

    The is_unique flag is used to indicate whether or not the index allows
    duplicate values in the attributes that it covers.

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_define_index(
    const char*     index_name,     /**< (I) Name of index */
    tag_t           class_id,       /**< (I) ID of class for which to define index */
    int             n_attrs,        /**< (I) Number of attributes in index */
    const tag_t*    attr_ids,       /**< (I) n_attrs IDs of attributes in index */
    logical         is_unique       /**< (I) Whether or not to make the index unique */
    );

/**
    Removes an index definition from the class definition.

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_remove_index(
    const char*     index_name,     /**< (I) Name of index */
    tag_t           class_id        /**< (I) ID of class from which to remove index */
    );

/**
    Finds the superclass(es) for a specified class.
    It will only return the direct superclasses of the specified class -
    combined with single inheritance this implies that it will only return one class ID.

    Takes a class_id and returns an array of superclass_ids.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_superclasses_of_class(
    tag_t       class_id,           /**< (I) ID of class */
    int*        n_ids,              /**< (O) Number of superclasses */
    tag_t**     superclass_ids      /**< (OF) n_ids IDs of superclasses */
    );

/**
    Finds the subclass(es) for a specified class.
    It will only return the direct subclasses of the class.

    Takes a class_id and returns an array of subclass_ids.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_subclasses_of_class(
    tag_t       class_id,       /**< (I) ID of class */
    int*        n_ids,          /**< (O) Number of subclasses */
    tag_t**     subclass_ids    /**< (OF) n_ids IDs of subclasses */
    );

/**
    Finds out if one class is anywhere in the class structure below another class.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_is_descendant(
    tag_t       class_id,       /**< (I) ID of possible superclass */
    tag_t       sub_class_id,   /**< (I) ID of possible subclass */
    logical*    answer          /**< (O) Whether it is a subclass or not */
    );

/**
    Returns the ID of a class which is specified by its name.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_class_id_of_class(
    const char*     class_name,     /**< (I) Name of class */
    tag_t*          class_id        /**< (O) ID of class */
    );

/**
    Returns whether a class exists or not.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_does_class_exist(
    const char*     class_name,     /**< (I) */
    logical*        exists          /**< (O) */
    );

/**
    Returns the name of a class which is specified by its ID.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_name_of_class(
    tag_t  class_id,    /**< (I) ID of class */
    char** class_name   /**< (OF) Name of class */
    );

/**
    Returns part, or all, of the definition of a class.

    Allows the specification of the attribute-definitions to be returned.

    To specify all of the attributes in the definition of the class set:

    n_names = 0 <br>
    attr_names = NULL

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_describe_class(
    tag_t       class_id,           /**< (I) ID of class to describe */
    int         n_names,            /**< (I) Number of attributes of interest */
    char**      attr_names,         /**< (I) n_names Names of attributes of interest */
    char**      application_name,   /**< (OF) Name of application associated with class */
    int*        descriptor,         /**< (O) Sum of class tokens */
    int*        n_attrs,            /**< (O) Number of returned attributes */
    tag_t**     attr_ids            /**< (OF) n_attrs */
    );

/**
    Returns the definition of attributes for a specified class.

    For each attribute:
    <ul>
    <li>If its type is not "string," then the corresponding element of max_string_lengths is 0
    <li>If its type is not "typed reference,"
        then the corresponding element of referenced_classes is #NULLTAG
    </ul>
    Since this does not affect the stored data anywhere,
    it is possible for this function to "partially" succeed:
    when this occurs it can return a description for some of the attributes while complaining about others.

    For each attr_id:
    <ul>
    <li>If the attempt to describe it in this class is successful, then its name, type,
        length and descriptor are returned in the appropriate arrays, and 0 is returned in the attr_failures array
    <li>If the attempt to describe it fails, then the values in the name, type,
        length and descriptor arrays do not have any predictable value, and the failure code
        (e.g., for "attribute not defined for this class") is returned in the attr_failures array
    </ul>

    The failure code returned by itself is 0 unless NONE of the attributes can be described,
    in which case it is the value of attr_failures_[0].
    Therefore, if only one attribute is being described,
    the failure code is exactly the failure code applying to that one attribute.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_describe_attrs(
    tag_t           class_id,           /**< (I) ID of class in which to describe attributes */
    int             n_attrs,            /**< (I) Number of attributes to describe */
    const tag_t*    attr_ids,           /**< (I)  n_attrs ID of attributes to describe */
    char***         names,              /**< (OF) n_attrs Names of attribute */
    int**           types,              /**< (OF) n_attrs Types of attribute.  Choose one of the following: <br>
                                                 #POM_int, #POM_short, #POM_logical, #POM_float, <br>
                                                 #POM_double, #POM_char, #POM_string, #POM_date, <br>
                                                 #POM_typed_reference, #POM_untyped_reference, #POM_note, #POM_long_string */
    int**           max_string_lengths, /**< (OF) n_attrs Maximum allowable lengths of strings
                                                 (only if type is #POM_string, otherwise 0) */
    tag_t**         referenced_classes, /**< (OF) n_attrs IDs of classes referenced by attributes
                                                 (only if type is #POM_typed_reference, otherwise #NULLTAG) */
    int**           lengths,            /**< (OF) n_attrs Lengths of attribute - 1 for simple, \>1 for array */
    int**           descriptors,        /**< (OF) n_attrs Sum of the following tokens: <br>
                                                 #POM_null_is_valid, #POM_is_unique, #POM_has_lowerbound, <br>
                                                 #POM_has_upperbound, #POM_has_initial_value, #POM_is_classvariable, <br>
                                                 #POM_cannot_be_frozen, #POM_public, #POM_public_read, #POM_public_write */
    int**           attr_failures       /**< (OF) n_attrs Array, each element being 0 or
                                                 the code for the appropriate failure. */
    );

/**
    Returns the attributes for the specified index of the specified class.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_describe_index(
    const char*     index_name,     /**< (I) Name of index */
    tag_t           class_id,       /**< (I) ID in which to describe index */
    int*            n_attrs,        /**< (O) Number of attributes in index */
    tag_t**         attr_ids        /**< (OF) n_attrs IDs of attributes in index */
    );

/**
    Returns the indexes defined for the specified class.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_indexes_of_class(
    tag_t       class_id,       /**< (I) ID of class */
    int*        n_indexes,      /**< (O) Number of indexes in class */
    char***     index_names     /**< (OF) n_indexes Names of indexes in class */
    );

/**
    Returns the indexes defined for the specified attribute.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_indexes_of_attr(
    tag_t       class_id,       /**< (I) Class ID of the class in which the attribute appears */
    tag_t       attr_id,        /**< (I) Attribute ID of the attribute in question */
    int*        n_indexes,      /**< (O) Number of indexes in class */
    char***     index_names     /**< (OF) n_indexes Names of indexes in class */
    );

/** @} */

/**
    @name POM Functions for Instances
    @{
*/

/**
    Checks whether the given instance, loaded for read in the callers DS, requires a refresh or not.
    This function tests whether the DB representation of the instance is different to the loaded instances.
    For instances loaded for read this implies that some other session has modified the instance since it was loaded.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_refresh_required(
    tag_t       instance,   /**< (I) Tag of instance to test */
    logical*    verdict     /**< (O) True or false */
    );

/**
    Checks whether the given instance, newly created or loaded for modify in the callers DS,
    has been modified or not.
    This tests whether the DS representation of the instance has been altered since the instance was loaded.
    The result is always false for instances loaded for read as they cannot be altered.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_save_required(
    tag_t       instance,   /**< (I) Tag of instance to test */
    logical*    verdict     /**< (O) True or false */
    );

/**
    Checks whether the given instance is loaded in the callers DS for modify.
    Newly created instances are counted as modifiable.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modifiable(
    tag_t       instance,   /**< (I) Tag of instance to test */
    logical*    verdict     /**< (O) True or false */
    );

/**
    Returns the attr_id for the specified attribute in the specified class.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_attr_id_of_attr(
    const char*     attr_name,      /**< (I) Name of attribute */
    const char*     class_name,     /**< (I) Name of class */
    tag_t*          attr_id         /**< (O) Attribute identifier */
    );

/**
    Determines whether an attribute of the given name exists in the given class.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_attr_exists(
    const char*     attr_name,      /**< (I) Name of attribute */
    const char*     class_name,     /**< (I) Name of class */
    logical*        exists          /**< (O) True or false */
    );

/**
    Returns all the instances of the specified class.

    When the include_subclasses is TRUE, instances of subclasses
    (and subclasses of subclasses, etc.) are also returned.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_instances_of_class(
    tag_t       class_id,               /**< (I) ID of class */
    logical     include_subclasses,     /**< (I) Whether to include instances of subclasses too */
    int*        n_instances,            /**< (O) Number of instances */
    tag_t**     instance_tags           /**< (OF) n_instances Tags of instances */
    );

/**
    Finds out the class to which the instance belongs.

    This is the class in which the instance was instantiated,
    not necessarily the one in which it was loaded in this session
    (it is possible to load the instance as an instance of its own class or
    any superclass thereof - go to #POM_load_instances).

    The loaded class of an instance can be obtained by using #POM_loaded_class_of_instance.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_class_of_instance(
    tag_t  instance_tag,   /**< (I) */
    tag_t* class_id        /**< (O) */
    );

/**
    This is the class of the instance as it has been loaded in,
    not necessarily the one in which it was created
    (it is possible to load the instance as an instance of its own class,
    or any superclass thereof - go to #POM_load_instances).

    The DB class of an instance can be obtained using #POM_class_of_instance.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_loaded_class_of_instance(
    tag_t  instance_tag,   /**< (I) Tag of instance */
    tag_t* class_id        /**< (O) ID of class to which instance belongs */
    );

POMAPI int POM_negate_enquiry(
    tag_t  enquiry_id,      /**< (I) */
    tag_t* new_enquiry_id   /**< (O) */
    );

POMAPI int POM_scope_enquiry(
    tag_t  enquiry_id,  /**< (I) */
    tag_t  scope        /**< (I) */
    );

/**
    Selects the values of the specified attributes for the specified instances.
    Values for attributes that are not specified are empty.

    The instances are considered to be loaded (and can be refreshed to a fully loaded state later).
    See #POM_refresh_instances.

    This function loads the value for the specified instances into the DS, it does not return them.
    Use POM_ask_attr_\<type\>s to return the values.

    All the instances must contain all the specified attributes,
    though they do not need to be of the same class.
    If the instances are all of the same class, #NULLTAG can be specified as the class_to_load_as.
    If the instances are of different classes then a class ID must be specified.
    This class ID must be a class that contains all the attributes AND is a valid superclass
    for all the instances (the actual class of an instance is counted as a valid superclass).

    Tokens:

    #POM_order_ascending <br>
    #POM_order_descending

    When lock_type is set to #POM_delete_lock subsequent calls to
    POM_ask_attr_\<type\> functions on any of these instances will return
    #POM_inst_locked_for_delete and will not return the attribute value
    as long as the instance's lock type remains #POM_delete_lock.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_select_instances(
    int             n_instances,        /**< (I) Number of instances to select */
    const tag_t*    instance_tags,      /**< (I) n_instances Tags of instances to select */
    int             n_attrs,            /**< (I) Number of attributes to select */
    const tag_t*    attr_ids,           /**< (I) n_attrs IDs of attributes to select */
    tag_t           class_to_load_as,   /**< (I) Class ID the instances are to be selected as */
    int             lock_type           /**< (I) Indicates the type of lock required, can be either
                                                #POM_no_lock, #POM_read_lock, #POM_modify_lock, or #POM_delete_lock. */
    );

/**
    Executes the specified enquiry and, for the resulting instances,
    selects the values of the specified attributes,
    ordered according to the values of the specified order-attributes.
    Values for attributes that are not specified are empty.

    Each attribute can be ordered in ascending or descending order.
    The instances are ordered on the value of each attribute in turn,
    starting with the first attribute in the array.

    If the enquiry produces no instances, n_instances is 0, and instances is NULL.

    This function loads the value for the specified instances into the DS,
    it does not return them. Use POM_ask_attr_\<type\>s to return the values.

    If any instances cannot be selected, then none of them are.

    Tokens:

    #POM_order_ascending <br>
    #POM_order_descending

    When lock_type is set to #POM_delete_lock subsequent calls to
    POM_ask_attr_\<type\> functions on any of these instances will return
    #POM_inst_locked_for_delete and will not return the attribute value
    as long as the instance's lock type remains #POM_delete_lock.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_select_instances_by_enq(
    tag_t           enquiry_id,         /**< (I) ID of enquiry to execute to select instances */
    int             n_attrs,            /**< (I) Number of attributes to select */
    const tag_t*    attr_ids,           /**< (I) n_attrs IDs of attributes to select */
    tag_t           class_to_load_as,   /**< (I) Class ID the instances are to be selected as */
    int             lock_type,          /**< (I) Indicates the type of lock required, can be either
                                                #POM_no_lock, #POM_read_lock, #POM_modify_lock, or #POM_delete_lock. */
    int*            n_instances,        /**< (O) Number of instances to select */
    tag_t**         instances           /**< (OF) n_instances Tags of instances to select */
    );

/**
    Returns the instances and classes in the database which contain references to the specified instance.

    n_levels must be �1� � the function is defined to allow possibility of this being
    extended to multiple levels in a single request.

    The where_to_search argument allows the search domain to be specified as Data Search,
    Data Base, or Data Search and Data Base.

    Each returned instance or class has a corresponding entry in the _levels array
    saying how many levels away it was. At present this will always be �1�.

    If a class is found to be referencing an instance,
    then there will be a class variable (a typed or untyped reference) that contains the reference.
    Class variables are always updated in the DB,
    therefore the class_where_found return value will always be #POM_in_db_only.
    All the instances of that class are added to the list of instances.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_referencers_of_instance(
    tag_t       instance_tag,           /**< (I) Tag of instance */
    int         n_levels,               /**< (I) Number of levels to search */
    int         where_to_search,        /**< (I) Where to search <br>
                                                #POM_in_ds_only <br>
                                                #POM_in_db_only <br>
                                                #POM_in_ds_and_db */
    int*        n_instances,            /**< (O) Number of referencing instances */
    tag_t**     ref_instances,          /**< (OF) n_instances Tags of referencing instances */
    int**       instance_levels,        /**< (OF) n_instances Levels of referencing instances */
    int**       instance_where_found,   /**< (OF) n_instances Where the instance was found */
    int*        n_classes,              /**< (O) Number of referencing classes */
    tag_t**     ref_classes,            /**< (OF) n_classes Tags of referencing classes */
    int**       class_levels,           /**< (OF) n_classes Levels of referencing classes */
    int**       class_where_found       /**< (OF) n_classes Where the class was found (always DB) */
    );

/**
    Creates an instance of the specified class.
    Each attribute is set to the appropriate initial value if one exists,
    otherwise it is EMPTY and POM_set_attr_\<type\> must be used to set a value before trying to save the instance.

    To delete an instance that has not yet been saved, use #POM_unload_instances.

    It is possible that the class is only partially-defined,
    for example if an attribute has been defined to have a lower bound but that lower bound has not yet been set.
    In this casefails with "improperly defined class."

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_create_instance(
    tag_t  class_id,        /**< (I) ID of class to instantiate */
    tag_t* instance_tag     /**< (O) Tag of new instance */
    );

/**
    Creates copies of a set of existing instances (which need not be loaded in the session) as follows:

    Application-maintained attribute values are copied

    System-maintained attribute values (such as "creation_date") are set appropriately
    The copy is created as an instance of the class in which the original instance was instantiated,
    even if the original instance is loaded as an instance of some superclass.
    Inconsistent attribute values (e.g., duplicate uniquely-valued ones)
    are only checked for when saving (i.e., in DB, not in DS).
    If any attributes for the relevant class are forced to be unique,
    then copying the values from the old instances into the new instances would clearly create unsaveable instances.
    Therefore these attributes are left EMPTY in the new instances,
    so that the application can readily recognize the instances as unsaveable.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_copy_instances(
    int             n_instances,    /**< (I) Number of instances to copy */
    const tag_t*    instance_tags,  /**< (I) n_instances Tags of instances to copy */
    tag_t**         new_instances   /**< (OF) n_instances Tags of new instances */
    );

/**
    Saves a set of instances to the database, optionally discarding the DS information.
    The set of instances to save may include instances to delete from the database.

    Instances being processed by POM_save_instances must be either newly created instances
    or have been locked by passing #POM_modify_lock or #POM_delete_lock in the lock_type
    input parameter to a function that loads or refreshes instances.  These include:
    <ul>
    <li>#POM_load_instances
    <li>#POM_load_instances_any_class
    <li>#POM_load_instances_by_enq
    <li>#POM_refresh_instances
    <li>#POM_refresh_instances_any_class
    <li>#POM_select_instances
    <li>#POM_select_instances_by_enq
    </ul>

    Returns #POM_ok on success or a POM error indicating the type of failure that occurred.
    @returns
    <ul>
    <li>#POM_ok on success
    <li>POM error indicating the type of failure that occurred.
    </ul>

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_save_instances(
    int             n_instances,        /**< (I) Number of instances to save */
    const tag_t*    instance_tags,      /**< (I) n_instances Tags of instances to save */
    logical         whether_to_unload   /**< (I) Whether to unload instances after saving (same for each instance) */
    );

/**
    Loads the specified set of instances from the database, creating DS copies of them.

    If lock_for_modify is true, the instances are locked for modification,
    and no other session can lock them for modification at the same time.
    Otherwise they are locked for read, and other sessions can lock them for read or for modification.
    Locks are obtained in class, instance_oid order

    When lock_type is set to #POM_delete_lock subsequent calls to
    POM_ask_attr_\<type\> functions on any of these instances will return
    #POM_inst_locked_for_delete and will not return the attribute value
    as long as the instance's lock type remains #POM_delete_lock.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_load_instances_any_class(
    int             n_instances,    /**< (I) Number of instances to load */
    const tag_t*    instances,      /**< (I) n_instances Tags of instances to load */
    int             lock_type       /**< (I) Indicates the type of lock required, can be either
                                            #POM_no_lock, #POM_read_lock, #POM_modify_lock, or #POM_delete_lock. */
    );

/**
    Loads the specified set of instances from the database, creating DS copies of them.
    The class_to_load_as argument is ignored (early versions allowed you to load just
    some superclass attributes).
    Note that all the instances must be of the same class.
    (You can use load_instances_any_class to load a mixture of classes)
    Note than none of the instances may be loaded already.
    (You can call POM_refresh_instances on loaded or unloaded instances)

    If the lock type is #POM_modify_lock, the instances are locked for modification,
    and no other session can lock them for modification or delete at the same time.
    If the lock type is #POM_delete_lock, the instances are locked for delete,
    and no other session can lock them for modification or delete or create a reference to them at the same time.
    A POM_read_lock permits other sessions to lock instances for read or for modification.
    A POM_no_lock writes nothing to the database and hence has no impact on other sessions.

    When lock_type is set to #POM_delete_lock subsequent calls to
    POM_ask_attr_\<type\> functions on any of these instances will return
    #POM_inst_locked_for_delete and will not return the attribute value
    as long as the instance's lock type remains #POM_delete_lock.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_load_instances(
    int             n_instances,        /**< (I) Number of instances to load */
    const tag_t*    instance_tags,      /**< (I) n_instances Tags of instances to load */
    tag_t           class_to_load_as,   /**< (I) ID of class to load instances as */
    int             lock_type           /**< (I) Indicates the type of lock required, can be either
                                                #POM_no_lock, #POM_read_lock, #POM_modify_lock, or #POM_delete_lock. */
    );

/**
    Load a list of instances in such a way that any failures due to access controls or
    due to the instance being already loaded are ignored.
    The list of instances that are loaded is returned.
    This contains both instances that were already loaded and the ones that managed to load.
    @note Passing in the same tag multiple times will cause this routine to error. The caller
    of this routine must ensure that all input tags are unique values.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_load_instances_possible(
    int             n_instances,        /**< (I) Number of instances to load */
    const tag_t*    instances,          /**< (I) n_instances Instances to be loaded */
    int*            n_ret_instances,    /**< (O) Number of instances now loaded */
    tag_t**         ret_instances       /**< (OF) n_ret_instances Instances that are now loaded */
    );

/**
    Executes the specified enquiry and loads the resulting set of instances from the database,
    creating DS copies of them.
    the class_to_load_as argument is ignored.
    If any instances cannot be loaded, then none of them are.

    When lock_type is set to #POM_delete_lock subsequent calls to
    POM_ask_attr_\<type\> functions on any of these instances will return
    #POM_inst_locked_for_delete and will not return the attribute value
    as long as the instance's lock type remains #POM_delete_lock.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_load_instances_by_enq(
    tag_t       enquiry_id,         /**< (I) ID of enquiry to execute to select instances */
    tag_t       class_to_load_as,   /**< (I) ID of class to load instances as */
    int         lock_type,          /**< (I) Indicates the type of lock required, can be either
                                            #POM_no_lock, #POM_read_lock, #POM_modify_lock, or #POM_delete_lock. */
    int*        n_instances,        /**< (O) Number of instances to load */
    tag_t**     instances           /**< (OF) n_instances Instances to be loaded */
    );

/** @} */

/**
    @name POM Functions for Users and Groups
    @{
*/

/**
    The argument verdict is set to true if the current user is logged in under a privileged group.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_is_user_sa(
    logical*    verdict     /**< (O) Logical result */
    );

/**
    Returns whether current user is group administrator of
    input group.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_is_user_ga(
    tag_t       group,      /**< (I) */
    logical*    verdict     /**< (O) */
    );

/** @} */

/**
    Refreshes the specified set of instances.

    For instances which are locked-for-modification this restores the attributes
    to the values they had when the instances were loaded.

    For read-only instances the values are re-read from the database if
    the instances have been modified by another POM session.
    If the instance was not originally loaded, it will be loaded
    (in this sense this function is superior to #POM_load_instances_any_class because
    it will deal with POM objects in any loaded state).
    The instances to be refreshed are each refreshed to their actual class -
    so if they were originally loaded as a superclass of their actual class,
    the missing attributes will be loaded.
    The instances specified do not have to be all of the same class.

    In addition the type of lock held on the instance can be altered.
    Instances that were originally read-locked can be locked for modification -
    if no other session is currently modifying the instance -
    and instances which are no longer going to be modified can
    have their locks "degraded" to read-only locks.
    Locks are obtained in class, instance_oid order

    When lock_type is set to #POM_delete_lock subsequent calls to
    POM_ask_attr_\<type\> functions on any of these instances will return
    #POM_inst_locked_for_delete and will not return the attribute value
    as long as the instance's lock type remains #POM_delete_lock.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_refresh_instances_any_class(
    int             n_instances,    /**< (I) Number of instances to refresh */
    const tag_t*    instances,      /**< (I) n_instances Tags of instances to refresh */
    int             lock_type       /**< (I) Indicates the type of lock required, can be either
                                            #POM_no_lock, #POM_read_lock, #POM_modify_lock, or #POM_delete_lock. */
    );

/**
    Refreshes the specified set of instances. For instances which are locked-for-modification,
    this restores the attributes to the values they had when the instances were loaded.
    For read-only instances the values are reread from the database if
    the instances have been modified by another POM session.

    The type of lock held on the instance can be altered.
    Instances that were originally read-locked can be locked for modification
    (if no other session is currently modifying the instance)
    and instances which are no longer going to be modified can have their locks "degraded" to read-only locks.
    Locks are obtained in class, instance_oid order

    The class_to_load_as argument is ignored (early versions allowed you to load just
    some superclass attributes).

    When lock_type is set to #POM_delete_lock subsequent calls to
    POM_ask_attr_\<type\> functions on any of these instances will return
    #POM_inst_locked_for_delete and will not return the attribute value
    as long as the instance's lock type remains #POM_delete_lock.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_refresh_instances(
    int             n_instances,        /**< (I) Number of instances to refresh */
    const tag_t*    instances,          /**< (I) n_instances Tags of instances to refresh */
    tag_t           class_to_load_as,   /**< (I) */
    int             lock_type           /**< (I) Indicates the type of lock required, can be either
                                                #POM_no_lock, #POM_read_lock, #POM_modify_lock, or #POM_delete_lock. */
    );

/**
    Unloads the specified instances from DS (i.e., discards the information about those instances.

    If an instance has not been saved, this has the effect of deleting the instance entirely.
    For this reason, if an instance has not been saved to the database and is referenced by another unsaved instance,
    then it can not be loaded or deleted.
    Either the reference to this object has to be changed (or set to NULL),
    or both the referencer and referencee must be unloaded simultaneously.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_unload_instances(
    int             n_instances,    /**< (I) Number of instances to unload */
    const tag_t*    instance_tags   /**< (I) n_instances Tags of instances to unload */
    );

/**
    Deletes the specified instances from the database.
    The instance must not be referenced or loaded by this, or any other POM session.
    Instances that have not been saved cannot be deleted,
    they can only be unloaded which will have the same effect as deleting.
    If a class is application protected the instance of that class can only be deleted by that application.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_delete_instances(
    int             n_instances,    /**< (I) */
    const tag_t*    instance_tags   /**< (I) n_instances */
    );

/**
    Executes the specified enquiry and deletes the resulting instances from the database.
    When the enquiry produces no instances, then n_instances is 0, and instances is NULL.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_delete_instances_by_enq(
    tag_t           enquiry_id,     /**< (I) ID of enquiry to execute to select instances */
    int*            n_instances,    /**< (O) Number of instances to delete */
    tag_t**         instances       /**< (OF) n_instances Tags of instances to delete */
    );

/**
    For the specified instances (which must all be in the same class),
    this function changes the specified attribute to NULL.

    <br> Supports rollback using markpoints: YES.
*/

POMAPI int POM_modify_null(
    int             n_instances,    /**< (I) Number of instances to modify */
    const tag_t*    instance_tags,  /**< (I) n_instances Tags of instances to modify */
    tag_t           attr_id         /**< (I) ID of attribute */
    );

/**
    For the specified instances,
    this function changes (all or some of) the specified array-valued attribute to NULL.

    The attribute must exist for all the instances,
    therefore there must be a class with that attribute,
    and the instances must be in that class or a subclass of it.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_nulls(
    int             n_instances,    /**< (I) Number of instances to modify */
    const tag_t*    instance_tags,  /**< (I) n_instances Tags of instances to modify */
    tag_t           attr_id,        /**< (I) ID of attribute */
    int             start,          /**< (I) Index of first element in array to set */
    int             n_values        /**< (I) Number of values to set */
    );

/**
    Executes the specified enquiry and for the resulting instances, changes the specified attribute to NULL.
    When the enquiry produces no instances, then n_instances is 0, and instances_tags is NULL.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_null_by_enq(
    tag_t           enquiry_id,     /**< (I) ID of enquiry to execute to select instances */
    tag_t           attr_id,        /**< (I) ID of attribute */
    int*            n_instances,    /**< (O) Number of instances to modify */
    tag_t**         instances       /**< (OF) n_instances Tags of instances to modify */
    );

/**
    Executes the specified enquiry and for the resulting instances,
    changes (all or some of) the specified array-valued attribute to NULL.

    When the enquiry produces no instances, then n_instances is 0,
    and instances_tags is NULL.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_nulls_by_enq(
    tag_t           enquiry_id,     /**< (I) ID of enquiry to execute to select */
    tag_t           attr_id,        /**< (I) ID of attribute */
    int             start,          /**< (I) Index of first element in array to set */
    int             n_values,       /**< (I) Number of values to set */
    int*            n_instances,    /**< (O) Number of instances to modify */
    tag_t**         instances       /**< (OF) n_instances Tags of instances to modify */
    );

/**
    Changes the specified attributes to NULL for the specified instances.
    The changes occur in the DS only. The attribute must exist for all the instances,
    therefore there must be a class with that attribute,
    and the instances must be in that class or a subclass of it.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_attr_null(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id         /**< (I) Attribute ID */
    );

/**
    Changes (all or some of) the specified array-valued attribute to NULL for the specified instances.
    The changes occur in the DS only.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_attr_nulls(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) Attribute ID */
    int             start,          /**< (I) Position in the VLA to start setting values */
    int             n_values        /**< (I) Number of values to be set */
    );

POMAPI int POM_insert_attr_nulls(
    int             n_instances,    /**< (I) */
    const tag_t*    instance_tags,  /**< (I) n_instances */
    tag_t           attr_id,        /**< (I) */
    int             start,          /**< (I) */
    int             n_values        /**< (I) */
    );

POMAPI int POM_append_attr_nulls(
    int             n_instances,    /**< (I) */
    const tag_t*    instance_tags,  /**< (I) n_instances */
    tag_t           attr_id,        /**< (I) */
    int             n_values        /**< (I) */
    );

/**
    Reverts the value of the attribute specified to that last saved to the database.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_revert_attr
  ( const tag_t    instance,          /**<  (I) */
    tag_t          attr_id            /**<  (I) */
    );

/**
    Sets the password for the specified user.checks that the old password is correct,
    except when a Teamcenter system administrator calls this function,
    in which case the old password can be NULL.

    @note When Teamcenter Security Services are installed and
    the TC_SSO_SERVICE environment variable is set in the  tc_profilevars file,
    passwords are managed by an external identity service provider rather than Teamcenter.
    In this case, the #POM_set_password function returns #POM_op_not_supported
    (the ability to change a password in Portal and ITK is disabled).

    @note This function operates on loaded instances only.

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_set_password(
    tag_t           user_tag,               /**< (I) Tag of user for whom to set password */
    const char*     old_password_string,    /**< (I) Old password */
    const char*     new_password_string     /**< (I) New password */
    );

/**
    Returns the owning user and group for the specified instance.
    This function returns attribute values for loaded instances only.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_owner(
    tag_t  instance_tag,    /**< (I) Tag of instance for which to ask owner */
    tag_t* user_tag,        /**< (O) Tag of owning user */
    tag_t* group_tag        /**< (O) Tag of owning group */
    );

/**
    Checks the password for the specified user.
    The given string is compared with the stored password and the argument answer indicates if they match.
    For security purposes, the password is stored in an encrypted form,
    and is never decrypted or returned through the interface.

    @note This function only operates for loaded user instances.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_check_password(
    tag_t           user_tag,           /**< (I) Tag of user for which to check password */
    const char*     password_string,    /**< (I) Possible password */
    logical*        answer              /**< (O) Whether password is correct */
    );

/**
    @name POM System Functions
    @{
*/

/**
    Places a "markpoint" (i.e., notes the state of the DS).
    Markpoints are places in a POM session that can be returned to within the current POM session.
    Certain POM calls (i.e., saving and removing classes)
    cannot be undone and will prevent markpoints placed earlier from being returned to.

    Information about whether a function supports rollback or not is provided in the documentation of
    each function.
    Functions which support rollback are subject to conditions noted in #POM_roll_to_markpoint.
    Other ITK modules should not be assumed to be markpoint safe unless specifically stated as such.

    @note Once #POM_place_markpoint has been called,
    POM is prepared to undo any changes made during that session to the point specified.
    It therefore has to store the state of everything it changes.
    This can require substantial amounts of system memory.

    @note #POM_forget_markpoint will free up system resources that were used for #POM_place_markpoint.
*/

POMAPI int POM_place_markpoint(
    int*        markpoint_number    /**< (O) Integer to identify markpoint */
    );

/**
    Attempts to undo all the POM commands that have been executed since the specified markpoint was placed.
    Note: rolls to just before the markpoint, so leaves the markpoint deleted.

    There are conditions where POM_roll_to_markpoint will not undo the POM commands executed since
    the specified markpoint was placed.  These include:
    <ul>
    <li>Data changed by another session.
    <li>The markpoint has expired.
    <li>POM calls that cannot be undone were called since #POM_place_markpoint.
        The #POM_place_markpoint description lists the functions that cannot be undone.
    <li>System problems such as loss of DB connection or a memory full condition.
    </ul>

    Descriptions of the changed data and markpoint expiration conditions follow.

    #POM_roll_to_markpoint can undo changes made since the corresponding #POM_place_markpoint call
    made within the same session.  If a second session finds and modifies the data made within these
    boundaries the first session cannot undo the changes made by the second session.  For example,
    if you, a user, create and save an object and someone else, another user, finds and references
    it, the rollback cannot succeed because the new object has been referenced.  Also, if you saved
    the object and its lock was released then someone else could change it further.  At this point
    you cannot rollback your change because that would require the other user to first undo their change.
    In general the reliability of the rollback can be improved if any creates are kept private as long
    as possible and any locks obtained after the markpoint was placed are retained until after the
    rollback/forget point. Where possible it is better to use a single #POM_save_instances call within
    the markpoint boundary function calls (#POM_place_markpoint and
    #POM_forget_markpoint/#POM_roll_to_markpoint).

    After a markpoint expires, a #POM_roll_to_markpoint call cannot undo changes made since the
    corresponding #POM_place_markpoint call.  A markpoint expires when #POM_forget_markpoint is called
    or the markpoint is removed from the system's revolving queue of markpoints.  The system maintains
    a revolving queue of markpoints.  (There are 200 places in the queue.)  As new markpoints
    are placed and the queue length reaches the maximum number of places then old markpoints are
    automatically expired.  This frees up memory, but the automatically expired markpoints
    cannot be used for rollbacks.  The typical usage is for smaller operations like item create and
    dataset save which require few markpoints.  Some operations may use a lot of system memory but
    only one place in the markpoint queue.  On the other hand, some other operations could use all
    the places in the markpoint queue.

*/
POMAPI int POM_roll_to_markpoint(
    int         markpoint_number,   /**< (I) Identifier of target markpoint */
    logical*    state_has_changed   /**< (O) Determines whether the rollback actually changed anything */
    );

/**
    Discards information associated with a markpoint.
    This frees up resources associated with the markpoint.
    This is the counterpart to #POM_roll_to_markpoint.
*/
POMAPI int POM_forget_markpoint(
    int         markpoint_number    /**< (I) Markpoint number as recorded from earlier call to #POM_place_markpoint */
    );

/**
    This function allows a tag value to be registered with the rollback mechanism so that, if a rollback
    occurs, the value is reset to its original value.
    Apart from rollback scenario, this function also resets the value on a #POM_exit_module call.

    @code
    static tag_t enq_created = null_tag;

    if (enq_created == null_tag)
    {
         // Create enquiry
         ...

         POM_cache_for_session( &enq_created );
         enq_created = 1;
    }

     //Make use of enquiry
    @endcode

    Lets assume the above code to create enquiry was called after a markpoint was created.
    If a rollback is called then object for the enquiry created will be thrown away (as it was created
    after markpoint was placed) and its tag will become invalid. #POM_cache_for_session can help detect
    this and recreate the enquiry.

    @see POM_place_markpoint
*/
POMAPI int POM_cache_for_session(
    tag_t* value    /**< (I) */
    );

/**
    This function causes the POM to record the name and password of the new application.
    This allows that application to call #POM_register_application -
    which compares the password given then to the one given here to authenticate the application.

    This function is restricted to Teamcenter system administrators only.

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_install_application(
    const char*     name,       /**< (I) Unique ID for application */
    const char*     password    /**< (I) Password for the application of the given name */
    );

/**
    Checks whether an application is installed or not.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_is_application_installed(
    const char*     application_name,       /**< (I) Unique ID for application  */
    const char*     application_password,   /**< (I) Password for the application of the given name */
    logical*        result                  /**< (O) returns true if input application is installed*/
    );

/**
    Registers the applications existence in the calling session.
    The password is compared to the encrypted password stored in the database to validate the application.
    Since this operation involves some database usage it is reasonably slow.
    For this reason it returns an application identifier and code word so that
    the application can identify itself quickly throughout the rest of the session.
    See #POM_identify_application.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_register_application(
    const char*     application_name,       /**< (I) Name of the application being registered */
    const char*     application_password,   /**< (I) Password used to authenticate the application */
    int*            application_id,         /**< (O) Session time identifier for the application */
    int*            application_code        /**< (O) Code used to authenticate the user of an application_id */
    );

/**
    Check if an application is already registered in a session.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_is_application_registered(
    const char*     application_name,       /**< (I) Unique ID for application */
    const char*     application_password,   /**< (I) Password for the application of the given name */
    logical*        result                  /**< (O) True if the application is currently registered */
    );

/**
    Sets the application-context in which subsequent POM calls occur.
    This function allows an application to identify itself to POM.
    POM will then allow the application to perform protected operations on
    classes with which the application is associated,
    and then to make itself anonymous again so that subsequently,
    POM will not allow those operations.

    The permission argument should be TRUE when the application wishes to identify itself,
    and FALSE for anonymity.
    For example, the Configuration Manager (CM) is the only application
    allowed to save objects of the class "cm_product."
    So the following sequence of calls succeeds:

    @code
        POM_identify_application (<cm-name>, true);
        POM_save_instances (1, &<tag-of-cm-product-instance>, unload_flag)
        (&n_fails, &fail_tags, &reasons);
        POM_identify_application (<cm-name>, false);
    @endcode

    However, if CM does not identify itself first,
    then the call to #POM_save_instances fails with "application has insufficient privilege."

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_identify_application(
    int         application_id,     /**< (I) Indicates which application is allowing/disallowing access to its instances */
    int         application_code,   /**< (I) Authenticates that application */
    logical     permission          /**< (I) Indicates whether access to its instances is allowed or not */
    );

/** checks if the input application is set currently.
    see #POM_identify_application for more information.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_is_application_identified(
    int         application_id,     /**< (I) Session time identifier for the application*/
    int         application_code,   /**< (I) code used to authenticate the user of an application_id */
    logical*    result              /**< (O) returns true, if input application-context is set.*/
    );

/**
    Returns the type of the specified attribute of the specified loaded instance.

    Ideally this is always the same type as that which #POM_describe_attrs returns.
    Therefore, this permits checking for consistency between the class definition and the instance information.
    If the reference is NULL, then is_it_null is returned as TRUE.
    This can or can not indicate an error, depending on whether the attribute is allowed to contain NULL or not.
    If the reference is EMPTY, then is_it_empty is returned as TRUE.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_check_reference(
    tag_t       instance_tag,           /**< (I) Tag of instance for which to check reference */
    tag_t       attr_id,                /**< (I) ID of attribute to check */
    tag_t*      class_id_of_reference,  /**< (O) ID of class to which attribute refers */
    logical*    is_it_null,             /**< (O) Whether attribute is NULL */
    logical*    is_it_empty             /**< (O) Whether attribute is empty */
    );

/**
    Sets a session-wide timeout value, used when the application tries to lock an instance
    for change by calling a POM function such as POM_modify_\<type\>.

    The timeout value is used to determine the period during which
    the POM function repeatedly tries to lock the instance.
    If the POM function is not successful in getting the lock at any time during this period,
    then it gives up, and returns the appropriate failure as described for the function,
    such as "instance already locked-for-change somewhere else."

    The timeout period can be specified as any positive value.
    Zero or any negative value means "do not wait, just try once."

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_timeout(
    double timeout_value    /**< (I) Value to which to set timeout (in seconds) */
    );

/**
    Returns the session-wide timeout value, as set by #POM_set_timeout.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_timeout(
    double*     timeout_value   /**< (O) Current value of timeout (in seconds) */
    );

/**
    Explains why the last POM function call failed.
    <ul>
    <li>The returned information includes:
    <li>The error code (in error_code)
    <li>Which argument caused to fail (in argument_number)
    <li>The name of the function that failed (in function_name)
    </ul>
    A description of what the failure code means (in explanation)

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_explain_last_error(
    int*   error_code,          /**< (O) Error code returned by last failing function */
    int*   argument_number,     /**< (O) Argument that caused failure,
                                        or zero if all arguments were successfully checked */
    char** function_name,       /**< (OF) Textual name of last failing function */
    char** explanation          /**< (OF) Text of error code */
    );

/** @} */

/**
    @name Miscellaneous POM Functions
    @{
*/

/**
    Converts the specified tag to a string representation,
    so that the tag can be passed as an argument to another process.

    @note The output of #POM_tag_to_string contains alphanumeric characters as well as
    the dollar sign (\$) and underscore (_).
    Therefore, if this string is to be parsed by a UNIX shell,
    you should enclose it in single quotes (') to ensure that it will be interpreted properly.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_tag_to_string(
    tag_t  tag,     /**< (I)  */
    char** string   /**< (OF) String representation of tag */
    );

/**
    Converts the specified string (a representation of a tag) to the corresponding tag.

    <br> Supports rollback using markpoints: YES.
    */
POMAPI int POM_string_to_tag(
    const char*     string,     /**< (I) String representation of tag */
    tag_t*          tag         /**< (O) */
    );

/**
    Registers the cpids for the list of uids passed in and returns a list of tags.
    The initial implementation of this function does not support passing in lwo classes.

    @note The cparam and cpids parameters are optional.  Also, a -1 can be passed in for
    all POM_Object classes, not lwo classes.

    <br> Supports rollback using markpoints: YES.

    @returns
    <ul>
    <li>#POM_ok on success
    <li>#POM_invalid_value if the parameters @p n_uids or @p uids are not valid values.
    <li>#POM_invalid_tag if @p uids passed in are not valid tags.
    <li>#POM_op_not_supported if @p cpids contains any cpids which are for lwo classes.
    </ul>
    */
POMAPI int POM_uids_to_tags(
    const int       n_uids,      /**< (I)  Number of uids to get tags for */
    const char**    uids,        /**< (I)  n_uids List of uids to get tags */
    const tag_t     cparam,      /**< (I) The cparam to get tags.-optional*/
    const int*      cpids,       /**< (I) The cpids for the uids-optional. */
    tag_t**         tags         /**< (OF) n_uids The tags for the uids passed in */
    );

/** @} */

/**
    Compares two class identifiers for equality.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_compare_class_ids(
    tag_t       class_id1,      /**< (I) Tag of class */
    tag_t       class_id2,      /**< (I) Tag of class */
    logical*    answer          /**< (O) Return true, if input class identifiers are equal */
    );

/**
    Compares two attribute ids for equality.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_compare_attr_ids(
    tag_t       attr_id1,   /**< (I) Tag of attribute identifier */
    tag_t       attr_id2,   /**< (I) Tag of attribute identifier */
    logical*    answer      /**< (O) Returns true if input attributes are equal */
    );

/**
    Compares two dates for equality.

    The result is returned in answer as

    0 if dates are equal <br>
    1 if date1 is later than date2 <br>
    -1 if date1 is earlier than date2

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_compare_dates(
    date_t date1,   /**< (I) First date */
    date_t date2,   /**< (I) Second date */
    int*   answer   /**< (O) 0, 1 or -1 as appropriate */
    );

/**
    Clears all values from the specified VLA setting its length to zero.

    @note VLAs are array attributes which can have a variable number of elements of their declared type.
    The data type of the VLA and class type (for typed references) or string length (for notes and strings)
    is declared when the attribute is defined.
    When an instance of a class with a VLA attribute is created that VLA attribute is initialized to zero length.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_clear_attr(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id         /**< (I) Attribute ID */
    );

/**
    Removes "number" elements from the specified VLA at the specified position.
    (The rest of the VLA effectively moves down to fill the gap, so the length is reduced by "number.")

    @note VLAs are attributes which can have a variable number of elements of their declared type.
    The data type of the VLA and class type (for typed references) or
    string length (for notes and strings) is declared when the attribute is defined.
    When an instance of a class, with a VLA attribute is created that VLA attribute is initialized to zero length.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_remove_from_attr(
    int             n_instances,    /**< (I) */
    const tag_t*    instances,      /**< (I) n_instances */
    tag_t           attr_id,        /**< (I) */
    int             position,       /**< (I) */
    int             number          /**< (I) */
    );

/**
    Find the current length of an attribute.
    This is most useful with VLAs, where the length of the attribute can change on a per instance basis.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_length_of_attr(
    tag_t  instance,    /**< (I) Tag identifier for instance */
    tag_t  attr_id,     /**< (I) ID for attribute */
    int*   length       /**< (O) Returned length */
    );

/**
    Extracts the part of the VLA VLA[start...start + number] and inserts it at VLA[newstart],
    that is, the "newstart"th position of the VLA after the extraction has taken place.

    For example, if the VLA is

    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

    Then start =5, number =3, newstart =10 produces

    1 2 3 4 5 9 10 11 12 13 6 7 8 14 15

    So that what was the fifth element is now the tenth.
    Remember that VLAs use "C" type indexing (from zero up) for arrays.

    If newstart is large enough that the reordering would leave a gap between
    the end of the current list and newstart, then fails.
    This happens if newstart + number \> "length."

    @note VLAs are attributes which can have a variable number of elements of their declared type.
    The data type of the VLA and class type (for typed references) or string length
    (for notes and strings) is declared when the attribute is defined.
    When an instance of a with a VLA attribute is created that VLA attribute is initialized to zero length.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_reorder_attr(
    int             n_instances,    /**< (I) Number of instances to reorder */
    const tag_t*    instances,      /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) ID of the VLA attribute */
    int             start,          /**< (I) Position in the VLA to move the values from */
    int             number,         /**< (I) Number of values to be moved */
    int             newstart        /**< (I) Destination for the values moved */
    );

/**
    Creates a database view over the selected attributes in the given class.

    The view is given the name supplied and the columns are aliased with the column names supplied.

    The view cannot include array attributes (either fixed length or VLA) or class variable attributes.

    <br> Supports rollback using markpoints: NO.
*/

POMAPI int POM_sql_view_of_class(
    tag_t           class_id,       /**< (I) ID of class */
    int             n_attrs,        /**< (I) Number of attributes to be covered by the view */
    const tag_t*    attr_ids,       /**< (I) n_attrs Array of attribute identifiers */
    char**          column_names,   /**< (I) n_attrs Array of names for each column of the view */
    const char*     view_name       /**< (I) Name of the view to be created */
    );

/**
    Drops the named view. This can be used to remove views created via #POM_sql_view_of_class.

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_sql_drop_view(
    const char*     view_name   /**< (I) */
    );

/**
    Tests that the view of the given name exists.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_sql_view_exists(
    const char*     view_name,      /**< (I) */
    logical*        answer          /**< (O) True if the given view does exist */
    );

/**
    Takes a class identifier and an attribute identifier and returns the
    textual names of the SQL database table and column within that table in which the attribute is stored.

    It is expected that this function will be used to directly access the values of
    the specified attribute for specific instances,
    or to produce a query over all values of this attribute in a given class.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_dbname_of_att(
    tag_t  class_id,    /**< (I) Class ID of the class in which the attribute appears */
    tag_t  attr_id,     /**< (I) Attribute ID of the attribute in question */
    char** table,       /**< (OF) Textual name of the database table */
    char** base         /**< (OF) Column name in the above table */
    );

/**
    Returns the array type of the attribute identified by class_id and attr_id.

    The return types cover:
    <ul>
    <li>non-array
    <li>small-array
    <li>large-array
    <li>variable-length-array
    </ul>

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_type_of_att(
    tag_t  class_id,    /**< (I) */
    tag_t  attr_id,     /**< (I) */
    int*   type         /**< (O) Array type of attribute */
    );

/**
    Internally, POM stores references to other POM objects as uids.
    Additionally, each row in the database table corresponding to a POM object
    is identified by the uid of the tag of the object.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_tag_to_uid(
    tag_t  tag,     /**< (I) */
    char** string   /**< (OF) UID is returned as a string */
    );

/**
    Converts the external class identifier into the internal integer representation for a class.

    This function is to be used with #POM_site_id and #POM_attr_to_apid so that the user is able to
    obtain the local site identifier and internal identifiers for classes and attributes.
    These are required so that the POM tables that have their entries specified by
    a combination of these identifiers can be accessed directly.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_class_to_cpid(
    tag_t  class_id,    /**< (I) ID of class */
    int*   cpid         /**< (O) Internal class identifier */
    );

/**
    Converts the external class/attribute identifiers into the internal integer attribute identifier.

    This function is to be used with #POM_site_id and #POM_class_to_cpid so that the user
    is able to obtain the local site identifier and internal identifiers for classes and attributes.
    These are required so that the POM tables that have their entries specified by a combination of
    these identifiers can be accessed properly.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_attr_to_apid(
    tag_t  class_id,    /**< (I) */
    tag_t  attr_id,     /**< (I) */
    int*   apid         /**< (O) */
    );

/**
    Returns the site ID of the local POM installation.
    This function is to be used with #POM_attr_to_apid and #POM_class_to_cpid so that the user is able
    to obtain the local site identifier and internal identifiers for classes and attributes.
    These are required so that the POM tables that have their entries specified by
    a combination of these identifiers can be accessed properly.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_site_id(
    int*   site     /**< (O) Local site ID */
    );

/**
    Enables or disables logins to POM (i.e., successful calls to #POM_start) from other processes.

    @note If the process that has disabled logins logs out (using #POM_stop), logins will be re-enabled.
    If the process that has disabled logins dies unexpectedly
    (without calling #POM_stop, further attempts to log in will be blocked unless
    the user is attempting to log in under a privileged group, when logins will be re-enabled.

    <b>Restrictions:</b>
    Only a Teamcenter system administrator can call this function.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_logins(
    logical     enable_logins   /**< (I) Whether to enable or disable logins */
    );

/**
    Finds out whether other processes are currently allowed to login to POM.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_logins(
    logical*    enable_logins   /**< (O) Whether logins are enabled or disabled */
    );

/**
    Logs in to POM. This must be the first call to POM - if any other POM function is called before this one,
    then that function will fail with "POM_start not yet called."

    The group_name can be a zero-length string, in which case the users default group will be selected,
    providing that the user is still a member of that group.
    If the default group cannot be selected, or had not been set, then the attempt to start POM will be blocked.

    @note This function is a composite of the following functions:

    @code
        POM_init_module();
        POM_login(user_name, password, group_name);
        POM_get_user(&dummy_name, &user_tag);
        POM_ask_top_class(&topmost_class_id);
        POM_get_version(&pom_version);
    @endcode

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_start(
    const char*     user_name,          /**< (I) Login name of the user */
    const char*     password,           /**< (I) Password */
    const char*     group_name,         /**< (I) Name of group */
    tag_t*          user_tag,           /**< (O) Tag of user */
    tag_t*          topmost_class_id,   /**< (O) ID of class POM_object */
    int*            pom_version         /**< (O) Integer to identify version of POM */
    );

/**
    Logs out of POM. If the argument ignore_unsaved_stuff is false,
    and there are unsaved instances in the DS, the attempt to log out fails.

    @note This function is a composite of the following functions:

    @code
        POM_logout(ignore_unsaved_stuff);
        POM_exit_module();
    @endcode

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_stop(
    logical     ignore_unsaved_stuff    /**< (I) Whether to log out even though there are unsaved changes in DS */
    );

/**
    Returns the ordering on the character set in use.
    This is useful knowledge when creating an enquiry which selects on a string-valued attribute,
    for example, by saying "all names greater than "W'" to return all names beginning with X, Y, or Z.

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_get_char_ordering(
    char** string   /**< (OF) String of characters in order */
    );

/**
    Sets the group to the named group, and returns the tag of the group.
    The group must be a valid group for the user.
    A side effect of using this function is that any privileges that may have been set by the user
    (e.g. #POM_bypass_access_check) will be cleared.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_group(
    const char*     group_name_string,  /**< (I) Name of group */
    tag_t*          group_tag           /**< (O) Tag of group */
    );

/**
    Switches the login group for the user.
    The current user must be member of the input group.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_group_by_tag(
    tag_t  group_tag    /**< (I) Tag of group */
    );

/**
    Get tag for a group object from its name.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_group_tag(
    const char*     group_name_string,  /**< (I) Name of group */
    tag_t*          group_tag           /**< (O) Tag of group */
    );

/**
    Returns the name of the logged-in user and the tag corresponding to the user instance.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_get_user(
    char** user_name_string,    /**< (OF) Name of user */
    tag_t* user_tag             /**< (O) Tag of user */
    );

/**
    Gets the user ID (the unique ID string for a user) for the currently logged in user.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_get_user_id(
    char** user_id_string   /**< (OF) Unique ID for the currently logged in user */
    );

/**
    Returns the tag of the current member.
    The member is a loaded form of the database link that gives the user authority to log into the chosen group.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_member(
    tag_t* member_tag   /**< (O) Tag of the member */
    );

/**
    Returns the name of the group (as handed to #POM_set_group or #POM_start),
    and the tag (as returned also by #POM_set_group). The name is from the specific group. To
    get a "hierarchical" group name, use #POM_ask_group_name.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_group(
    char** group_name_string,   /**< (OF) Name of group */
    tag_t* group_tag            /**< (O) Tag of the user whose default group is to be asked */
    );

/**
    Returns the tag of the current users default group.
    This is the group which the user will be logged into if
    the #POM_start call is given an empty string for the group.
    The default group can be #NULLTAG in which case the user has no default group.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_default_group(
    tag_t* group_tag    /**< (O) */
    );

/**
    Sets the current users default group.
    This is the group which the user will be logged into if the #POM_start call is given a #NULLTAG for the group.
    The change occurs in the DS only, therefore the instance of the current user must be loaded for modify before
    this function can be called. To make this change permanent,
    the instance must at some point be saved back to the database.

    If the group_tag is #NULLTAG then this corresponds to "no default group",
    and any following attempts to log into POM without specifying a group will fail.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_default_group(
    tag_t  group_tag    /**< (I) Tag of group */
    );

/**
    Returns the currently set default group for the specified user.
    The user object must be loaded at the time.
    Only system administrators can ask about the default group for users other than themselves.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_user_default_group(
    tag_t  user,        /**< (I) Tag of group */
    tag_t* group_tag    /**< (O) Tag of the user whose default group is to be asked */
    );

/**
    Sets the default group for the specified user to the group specified.
    The user object must be loaded for modify and must be saved again afterwards for this change to be made permanent.
    Only system administrators can set the default group for users other than themselves.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_user_default_group(
    tag_t  user,        /**< (I) Tag of the user whose default group is to be set */
    tag_t  group_tag    /**< (I) Tag of group */
    );

/**
    Sets the specified environmental information.

    Currently it can be used to:
    <ul>
    <li>Enable/disable rollback
    <li>Enable/disable in-DS attribute-value-checking
        (for e.g. duplication of unique attributes, or for checking against upper/lower bounds)
    <li>Enable/disable POM journaling
        (writing functions and arguments to the system log - for debugging and bug reporting)
    <li>Enable/disable argument checking
    <li>Enable/disable logging the SQL processed to the file
    <li>Enable/disable creation of tracebacks from the ERROR system
    <li>Disable/enable access manager checks (value is "false" for AM bypass is disabled - AM checks are enabled by default).  Requires Sys Admin privilege to change (intended for data migration utilities).
    <li>Disable/enable updating last modifying user and last modify dates when instances are saved (value is "true" for Attr bypass disabled (note: counter intuitive given AM bypass token). Requires Sys Admin privilege
        to change )intended for data migration utilities).
    <li>Setting pattern match characters for queries
        <ul>
        <li>the wildcard_one character will match any single character
        <li>the wildcard_any character will match a sequence of characters
        <li>the wildcard_escape charcter flags the following character as "not being special"
        <li>By default these are _ % and ~ so the string %Hello_world\% will match anything followed by Hello world%
            where the space between Hello and world can be any single character
        </ul>
    <li>Set the location of the directory where POM transmit files live (defaults to the POM_TRANSMIT_DIR environment variable)
    <li>Set the import mode (to one of POM_import_raise_error, POM_import_always_map, POM_import_default_to_map, POM_import_default_to_current or POM_import_default_as_apt)
    <li>Set the importing user and group (if importing in a mapping mode)
    <li>Enable/disable automatic unique constraint checking for private versions
    <li>Set POM as disabled (this can be used if we have lost a database connexion, or run out of memory) - in this mode most POM functions will simply return POM_api_disabled
    <li>Select the action to be taken if a database operation requires retrying
    </ul>

    <table>
    <tr><td>Token                      </td><td>Type   </td><td>POM Initial Value  </td><td>ITK Initial Value  </td></tr>
    <tr><td>#POM_rollback_switch*       </td><td>logical</td><td>false (OFF)      </td><td>false (OFF)      </td></tr>
    <tr><td>#POM_ds_checking_switch*    </td><td>logical</td><td>false (OFF)      </td><td>false (OFF)      </td></tr>
    <tr><td>#POM_error_traceback_switch*</td><td>logical</td><td>true (ON)      </td><td>true (ON)      </td></tr>
    <tr><td>#POM_log_sql_switch        </td><td>logical</td><td>OFF            </td><td>OFF            </td></tr>
    <tr><td>#POM_journaling_switch     </td><td>logical</td><td>true (ON)      </td><td>true (ON)      </td></tr>
    <tr><td>#POM_arg_checking_switch*   </td><td>logical</td><td>true (ON)      </td><td>true (ON)      </td></tr>
    <tr><td>#POM_timeout_strategy*      </td><td>int    </td><td>0 (don't retry)</td><td>0 (don't retry)</td></tr>
    <tr><td>#POM_timeout_interval*      </td><td>int    </td><td>0 (don't retry)</td><td>0 (don't retry)</td></tr>
    <tr><td>#POM_bypass_access_check   </td><td>logical</td><td>false (OFF)    </td><td>false (OFF)    </td></tr>
    <tr><td>#POM_bypass_attr_update    </td><td>logical</td><td>true (ON)      </td><td>true (ON)    </td></tr>
    <tr><td>#POM_wildcard_character_one*</td><td>int    </td><td>'_' 95, 0x5F   </td><td>'.' 46, 0x2E   </td></tr>
    <tr><td>#POM_wildcard_character_any*</td><td>int    </td><td>'%' 37, 0x25   </td><td>'*' 42, 0x2A   </td></tr>
    <tr><td>#POM_escape_character*      </td><td>int    </td><td>'~' 126, 0x7E  </td><td>'~' 126, 0x7E  </td></tr>
    <tr><td>#POM_transmit_directory*    </td><td>string </td><td>$POM_TRANSMIT_DIR </td><td>$POM_TRANSMIT_DIR </td></tr>
    <tr><td>#POM_import_mode*           </td><td>int    </td><td>POM_import_default_to_current </td><td>POM_import_default_to_current </td></tr>
    <tr><td>#POM_import_to_user*        </td><td>tag    </td><td>unset          </td><td>unset/nulltag  </td></tr>
    <tr><td>#POM_import_to_group*       </td><td>tag    </td><td>unset          </td><td>unset/nulltag  </td></tr>
    <tr><td>#POM_disable_api*           </td><td>logical</td><td>false (POM enabled) </td><td>false (POM enabled) </td></tr>
    <tr><td>#POM_enable_set_attr_callbacks*</td><td>logical</td><td>false (POM enabled) </td><td>false (POM enabled)- true</td></tr>
    <tr><td>#POM_check_private_uniqueness_switch*</td><td>logical</td><td>true (ON) </td><td>true (ON) </td></tr>
    </table>
    @note Some ITK initial values may be changed by the login process.
    @note Only for use with SPLM guidance.

    The #POM_timeout_strategy / #POM_timeout_interval pair of "switches" determine the action that
    POM takes whenever a database operation requires to be retired
    (due to a deadlock detected by the database server, etc.).
    The "strategies" available are:

    <table>
    <tr><td>0</td>                           <td>Do not retry but return with an error code.</td></tr>
    <tr><td>#POM_timeout_strategy_flat</td>  <td>On each retry, wait for #POM_timeout_interval seconds before retrying.</td></tr>
    <tr><td>#POM_timeout_strategy_linear</td><td>On each retry, wait for a linearly increasing period of time,
                                                starting from #POM_timeout_interval seconds.</td></tr>
    <tr><td>#POM_timeout_strategy_exp</td>   <td>Use an exponentially increasing delay between successive retries.</td></tr>
    </table>

    When the amount of time spent retrying the operation exceeds that specified by #POM_set_timeout,
    POM returns with an error code to indicate that the call failed.

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_set_env_info(
    int             what_to_set,            /**< (I) Token to indicate what to set. One of the other five parameters
                                                    is the value to set (the others are ignored) */
    logical         logical_value_to_set,   /**< (I) */
    int             int_value_to_set,       /**< (I) */
    double          double_value_to_set,    /**< (I) */
    tag_t           tag_value_to_set,       /**< (I) */
    const char*     string_value_to_set     /**< (I) */
    );

/**
    Returns the specified environmental information.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_env_info(
    int         what_to_ask_about,     /**< (I) Token to indicate what to ask about.
                                                One of the other five parameters is the current value,
                                                the others should be ignored. <br>
                                                Tokens: <br>
                                                #POM_rollback_switch <br>
                                                #POM_ds_checking_switch <br>
                                                #POM_log_sql_switch <br>
                                                #POM_error_traceback_switch */
    logical*    logical_current_value, /**< (O) */
    int*        int_current_value,     /**< (O) */
    double*     double_current_value,  /**< (O) */
    tag_t*      tag_current_value,     /**< (O) */
    char**      string_current_value   /**< (OF) */
    );

/**
    Returns a string describing the specified token.
    For example, for the token #POM_int, the returned string might be "integer."

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_describe_token(
    int    token,   /**< (I) Token to describe */
    char** string   /**< (OF) String describing token */
    );

/**
    Returns a string describing the specified error code.
    For example, for the error #POM_logins_are_disabled,
    the returned string would be POM_logins_are_disabled.

    The descriptions returned by #POM_describe_error are the same as
    those returned by #POM_explain_last_error,
    but #POM_describe_error can be called with any error code at any time.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_describe_error(
    int    error_code,  /**< (I) Error code to describe */
    char** string       /**< (OF) String describing error code */
    );

/**
    Frees the memory.
    Can be used to free memory allocated by POM ITKs.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_free(
    void*  space        /**< (I) */
    );

/**
    Returns the value of the lower-bound for an attribute which has been defined to have a lower-bound.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_lower_int(
    tag_t       class_id,       /**< (I) */
    tag_t       attr_id,        /**< (I) */
    int*        value,          /**< (O) */
    logical*    is_it_null,     /**< (O) */
    logical*    is_it_empty     /**< (O) */
    );

/**
    Returns the value of the upper-bound for an attribute which has been defined to have an upper-bound.

    Returns invalid attr_id if attribute initial value not set or attribute not defined for this class.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_upper_int(
    tag_t       class_id,       /**< (I) ID of class in which to describe attribute */
    tag_t       attr_id,        /**< (I) ID of attribute to describe */
    int*        value,          /**< (O) Attribute's initial value, lower bound, or upper bound (if it is set) */
    logical*    is_it_null,     /**< (O) Whether the initial value, lower bound or upper bound is NULL */
    logical*    is_it_empty     /**< (O) Whether the initial value, lower bound, or upper bound is empty */
    );

/**
    Returns the initial value for an attribute which has been defined to have an initial value.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_initial_int(
    tag_t       class_id,       /**< (I) */
    tag_t       attr_id,        /**< (I) */
    int*        value,          /**< (O) */
    logical*    is_it_null,     /**< (O) */
    logical*    is_it_empty     /**< (O) */
    );

/**
    For the specified instances (which must all be in the same class),
    this function changes the specified attribute to the specified value.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_int(
    int             n_instances,        /**< (I) Number of instances to modify */
    const tag_t*    instance_tags,      /**< (I) n_instances Tags of instances to modify */
    tag_t           attr_id,            /**< (I) ID of attribute */
    int             value               /**< (I) Value to which to set attribute */
    );

/**
    For the specified instances (which must all be in the same class), this function changes
    (all or some of) the specified array-valued attribute to the specified array of values.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_ints(
    int             n_instances,    /**< (I) Number of instances to modify */
    const tag_t*    instance_tags,  /**< (I) n_instances Tags of instances to modify */
    tag_t           attr_id,        /**< (I) ID of attribute */
    int             start,          /**< (I) Index of first element in array to set */
    int             n_values,       /**< (I) Number of values to set */
    const int*      values          /**< (I) n_values */
    );

/**
    Executes the specified enquiry and, for the resulting instances,
    this function changes the specified attribute to the specified value.
    When the enquiry produces no instances, then n_instances is 0, and "instances" is NULL.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_int_by_enq(
    tag_t       enquiry_id,     /**< (I) ID of enquiry to execute to select instances */
    tag_t       attr_id,        /**< (I) ID of attribute */
    int         value,          /**< (I) Value to which to set attribute */
    int*        n_instances,    /**< (O) Number of instances to modify */
    tag_t**     instances       /**< (OF) n_instances Tags of instances to modify */
    );

/**
    Executes the specified enquiry and, for the resulting instances,
    changes (all or some of) the specified array-valued attribute to the specified array of values.
    When the enquiry produces no instances, then n_instances is 0, and instances is NULL.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_ints_by_enq(
    tag_t       enquiry_id,     /**< (I) ID of enquiry to execute to select instances */
    tag_t       attr_id,        /**< (I) ID of attribute */
    int         start,          /**< (I) Index of first element in array to set */
    int         n_values,       /**< (I) Number of values to set */
    const int*  values,         /**< (I) n_values  */
    int*        n_instances,    /**< (O) Number of instances to modify */
    tag_t**     instances       /**< (OF) n_instances Tags of instances to modify */
    );

/**
    Changes the specified attribute to the specified value for each of the specified instances
    (which must all be in the same class). The changes occur in the DS only.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_attr_int(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of tags of these instances */
    tag_t           attr_id,        /**< (I) Attribute ID */
    int             value           /**< (I) */
    );

/**
    Changes (all or some of) the specified array-valued attribute to the specified array of values
    for each of the specified instances (which must all be in the same class).
    The changes occur in the DS only.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_attr_ints(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) Attribute ID */
    int             start,          /**< (I) Position in the VLA to start setting values */
    int             n_values,       /**< (I) Number of values to be set */
    const int*      values          /**< (I) n_values Array of n_values of the appropriate type */
    );

/**
    Returns the value of the specified attribute, for the specified instance.

    Returns attribute values for loaded instances only.

    POM_ask_attr_int will return the attribute's current value in the session for the given instance.
    Meanwhile, if the instance has been modified by another session, the value in the database can be different.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_int(
    tag_t       instance_tag,   /**< (I) Tag of instance for which to ask attribute value */
    tag_t       attr_id,        /**< (I) ID of array-valued attribute */
    int*        value,          /**< (O) Single value */
    logical*    is_it_null,     /**< (O) Single flag or array of flags to indicate which values are NULL */
    logical*    is_it_empty     /**< (O) Single flag or array of flags to indicate which values are empty */
    );

/**
    Returns n_values of values of the specified array-valued attribute,
    for the specified instance, starting from the position start.

    Returns attribute values for loaded instances only.

    POM_ask_attr_ints will return the attribute's current value in the session for the given instance.
    Meanwhile, if the instance has been modified by another session,
    the value in the database can be different.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_ints(
    tag_t       instance_tag,   /**< (I) Tag of instance for which to ask attribute value */
    tag_t       attr_id,        /**< (I) ID of array-valued attribute */
    int         start,          /**< (I) Position of the first array value to ask (for array returns only) */
    int         n_values,       /**< (I) Number of values in array (for array returns only) */
    int**       values,         /**< (OF) n_values Single value or array of (not NULL and not empty) attribute values */
    logical**   is_it_null,     /**< (OF) n_values Single flag or array of flags to indicate which values are NULL */
    logical**   is_it_empty     /**< (OF) n_values Single flag or array of flags to indicate which values are empty */
    );

/**
    Inserts the specified value into the specified VLA attribute at the specified position.

    The maximum value for start is the length of the VLA, at which point the insert becomes equivalent to an append.

    @note VLAs are attributes which can have a variable number of elements of their declared type.
    The data type of the VLA and class type (for typed references) or
    string length (for notes and strings) is declared when the attribute is defined.
    When an instance of a class with a VLA attribute is created, that VLA attribute is initialized to zero length.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_insert_attr_ints(
    int             n_instances,    /**< (I) */
    const tag_t*    instance_tags,  /**< (I) n_instances */
    tag_t           attr_id,        /**< (I) */
    int             start,          /**< (I) */
    int             n_values,       /**< (I) */
    const int*      values          /**< (I) n_values */
    );

/**
    Adds the specified values to the end of the specified VLAs.

    VLAs are attributes which can have a variable number of elements of their declared type.
    The data type of the VLA and class type (for typed references) or string length (for notes and strings)
    is declared when the attribute is defined.
    When an instance with a VLA attribute is created, that VLA attribute is initialized to zero length.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_append_attr_ints(
    int             n_instances,    /**< (I) Number of instances to append the specified values to */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) ID of the VLA attribute */
    int             n_values,       /**< (I) Number of values to be appended */
    const int*      values          /**< (I) n_values Array of n_values of the appropriate type */
    );

/**
    Returns the value of the lower-bound for an attribute which has been defined to have a lower-bound.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_lower_double(
    tag_t       class_id,       /**< (I) */
    tag_t       attr_id,        /**< (I) */
    double*     value,          /**< (O) */
    logical*    is_it_null,     /**< (O) */
    logical*    is_it_empty     /**< (O) */
    );

/**
    Returns the value of the upper-bound for an attribute which has been defined to have an upper-bound.
    Returns invalid attr_id if attribute initial value not set or attribute not defined for this class.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_upper_double(
    tag_t       class_id,       /**< (I) ID of class in which to describe attribute */
    tag_t       attr_id,        /**< (I) ID of attribute to describe */
    double*     value,          /**< (O) Attribute's initial value, lower bound, or upper bound (if it is set) */
    logical*    is_it_null,     /**< (O) Whether the initial value, lower bound or upper bound is NULL */
    logical*    is_it_empty     /**< (O) Whether the initial value, lower bound, or upper bound is empty */
    );

/**
    Returns the initial value for an attribute which has been defined to have an initial value.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_initial_double(
    tag_t       class_id,       /**< (I) */
    tag_t       attr_id,        /**< (I) */
    double*     value,          /**< (O) */
    logical*    is_it_null,     /**< (O) */
    logical*    is_it_empty     /**< (O) */
    );

/**
    For the specified instances (which must all be in the same class),
    this function changes the specified attribute to the specified value.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_double(
    int             n_instances,    /**< (I) Number of instances to modify */
    const tag_t*    instance_tags,  /**< (I) n_instances Tags of instances to modify */
    tag_t           attr_id,        /**< (I) ID of attribute */
    double          value           /**< (I) Value to which to set attribute */
    );

/**
    For the specified instances (which must all be in the same class), this function changes
    (all or some of) the specified array-valued attribute to the specified array of values.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_doubles(
    int             n_instances,    /**< (I) Number of instances to modify */
    const tag_t*    instance_tags,  /**< (I) n_instances Tags of instances to modify */
    tag_t           attr_id,        /**< (I) ID of attribute */
    int             start,          /**< (I) Index of first element in array to set */
    int             n_values,       /**< (I) Number of values to set */
    const double*   values          /**< (I) n_values */
    );

/**
    Executes the specified enquiry and, for the resulting instances,
    this function changes the specified attribute to the specified value.
    When the enquiry produces no instances, then n_instances is 0, and "instances" is NULL.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_double_by_enq(
    tag_t       enquiry_id,     /**< (I) ID of enquiry to execute to select instances */
    tag_t       attr_id,        /**< (I) ID of attribute */
    double      value,          /**< (I) Value to which to set attribute */
    int*        n_instances,    /**< (O) Number of instances to modify */
    tag_t**     instances       /**< (OF) n_instances Tags of instances to modify */
    );

/**
    Executes the specified enquiry and, for the resulting instances,
    changes (all or some of) the specified array-valued attribute to the specified array of values.
    When the enquiry produces no instances, then n_instances is 0, and instances is NULL.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_doubles_by_enq(
    tag_t           enquiry_id,     /**< (I) ID of enquiry to execute to select instances */
    tag_t           attr_id,        /**< (I) ID of attribute */
    int             start,          /**< (I) Index of first element in array to set */
    int             n_values,       /**< (I) Number of values to set */
    const double*   values,         /**< (I) n_values  */
    int*            n_instances,    /**< (O) Number of instances to modify */
    tag_t**         instances       /**< (OF) n_instances  Tags of instances to modify */
    );

/**
    Changes the specified attribute to the specified value for each of the specified instances
    (which must all be in the same class). The changes occur in the DS only.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_attr_double(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) Attribute ID */
    double          value           /**< (I) */
    );

/**
    Changes (all or some of) the specified array-valued attribute to the specified array of values
    for each of the specified instances (which must all be in the same class).
    The changes occur in the DS only.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_attr_doubles(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) Attribute ID */
    int             start,          /**< (I) Position in the VLA to start setting values */
    int             n_values,       /**< (I) Number of values to be set */
    const double*   values          /**< (I) n_values Array of n_values of the appropriate type */
    );

/**
    Returns the value of the specified attribute, for the specified instance.

    Returns attribute values for loaded instances only.

    POM_ask_attr_double will return the attribute's current value in the session for the given instance.
    Meanwhile, if the instance has been modified by another session,
    the value in the database can be different.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_double(
    tag_t       instance_tag,   /**< (I) Tag of instance for which to ask attribute value */
    tag_t       attr_id,        /**< (I) ID of array-valued attribute */
    double*     value,          /**< (O) Single value */
    logical*    is_it_null,     /**< (O) Single flag or array of flags to indicate which values are NULL */
    logical*    is_it_empty     /**< (O) Single flag or array of flags to indicate which values are empty */
    );

/**
    Returns n_values of values of the specified array-valued attribute,
    for the specified instance, starting from the position start.

    Returns attribute values for loaded instances only.

    POM_ask_attr_doubles will return the attribute's current value in the session for the given instance.
    Meanwhile, if the instance has been modified by another session,
    the value in the database can be different.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_doubles(
    tag_t       instance_tag,   /**< (I) Tag of instance for which to ask attribute value */
    tag_t       attr_id,        /**< (I) ID of array-valued attribute */
    int         start,          /**< (I) Position of the first array value to ask (for array returns only) */
    int         n_values,       /**< (I) Number of values in array (for array returns only) */
    double**    values,         /**< (OF) n_values Single value or array of (not NULL and not empty) attribute values */
    logical**   is_it_null,     /**< (OF) n_values Single flag or array of flags to indicate which values are NULL */
    logical**   is_it_empty     /**< (OF) n_values Single flag or array of flags to indicate which values are empty */
    );

/**
    Inserts the specified value into the specified VLA attribute at the specified position.

    The maximum value for start is the length of the VLA, at which point the insert becomes equivalent to an append.

    @note VLAs are attributes which can have a variable number of elements of their declared type.
    The data type of the VLA and class type (for typed references) or
    string length (for notes and strings) is declared when the attribute is defined.
    When an instance of a class with a VLA attribute is created, that VLA attribute is initialized to zero length.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_insert_attr_doubles(
    int             n_instances,    /**< (I) */
    const tag_t*    instance_tags,  /**< (I) n_instances */
    tag_t           attr_id,        /**< (I) */
    int             start,          /**< (I) */
    int             n_values,       /**< (I) */
    const double*   values          /**< (I) n_values */
    );

/**
    Adds the specified values to the end of the specified VLAs.

    VLAs are attributes which can have a variable number of elements of their declared type.
    The data type of the VLA and class type (for typed references) or string length (for notes and strings)
    is declared when the attribute is defined.
    When an instance with a VLA attribute is created, that VLA attribute is initialized to zero length.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_append_attr_doubles(
    int             n_instances,    /**< (I) Number of instances to append the specified values to */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) ID of the VLA attribute */
    int             n_values,       /**< (I) Number of values to be appended */
    const double*   values          /**< (I) n_values Array of n_values of the appropriate type */
    );

/**
    Returns the value of the lower-bound for an attribute which has been defined to have a lower-bound.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_lower_char(
    tag_t       class_id,       /**< (I) */
    tag_t       attr_id,        /**< (I) */
    char*       value,          /**< (O) */
    logical*    is_it_null,     /**< (O) */
    logical*    is_it_empty     /**< (O) */
    );

/**
    Returns the value of the upper-bound for an attribute which has been defined to have an upper-bound.
    Returns invalid attr_id if attribute initial value not set or attribute not defined for this class.

    <br> Supports rollback using markpoints: YES.
*/

POMAPI int POM_ask_attr_upper_char(
    tag_t       class_id,       /**< (I) ID of class in which to describe attribute */
    tag_t       attr_id,        /**< (I) ID of attribute to describe */
    char*       value,          /**< (O) Attribute's initial value, lower bound, or upper bound (if it is set) */
    logical*    is_it_null,     /**< (O) Whether the initial value, lower bound or upper bound is NULL */
    logical*    is_it_empty     /**< (O) Whether the initial value, lower bound, or upper bound is empty */
    );

/**
    Returns the initial value for an attribute which has been defined to have an initial value.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_initial_char(
    tag_t       class_id,       /**< (I) */
    tag_t       attr_id,        /**< (I) */
    char*       value,          /**< (O) */
    logical*    is_it_null,     /**< (O) */
    logical*    is_it_empty     /**< (O) */
    );

/**
    For the specified instances (which must all be in the same class),
    this function changes the specified attribute to the specified value.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_char(
    int             n_instances,    /**< (I) Number of instances to modify */
    const tag_t*    instance_tags,  /**< (I) n_instances Tags of instances to modify */
    tag_t           attr_id,        /**< (I) ID of attribute */
    char            value           /**< (I) Value to which to set attribute */
    );

/**
    For the specified instances (which must all be in the same class), this function changes
    (all or some of) the specified array-valued attribute to the specified array of values.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_chars(
    int             n_instances,    /**< (I) Number of instances to modify */
    const tag_t*    instance_tags,  /**< (I) n_instances Tags of instances to modify */
    tag_t           attr_id,        /**< (I) ID of attribute */
    int             start,          /**< (I) Index of first element in array to set */
    int             n_values,       /**< (I) Number of values to set */
    const char*     values          /**< (I) n_values */
    );

/**
    Executes the specified enquiry and, for the resulting instances,
    this function changes the specified attribute to the specified value.
    When the enquiry produces no instances, then n_instances is 0, and "instances" is NULL.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_char_by_enq(
    tag_t       enquiry_id,     /**< (I) ID of enquiry to execute to select instances */
    tag_t       attr_id,        /**< (I) ID of attribute */
    char        value,          /**< (I) Value to which to set attribute */
    int*        n_instances,    /**< (O) Number of instances to modify */
    tag_t**     instances       /**< (OF) n_instances Tags of instances to modify */
    );

/**
    Executes the specified enquiry and, for the resulting instances,
    changes (all or some of) the specified array-valued attribute to the specified array of values.
    When the enquiry produces no instances, then n_instances is 0, and instances is NULL.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_chars_by_enq(
    tag_t           enquiry_id,     /**< (I) ID of enquiry to execute to select instances */
    tag_t           attr_id,        /**< (I) ID of attribute */
    int             start,          /**< (I) Index of first element in array to set */
    int             n_values,       /**< (I) Number of values to set */
    const char*     values,         /**< (I) n_values  */
    int*            n_instances,    /**< (O) Number of instances to modify */
    tag_t**         instances       /**< (OF) n_instances  Tags of instances to modify */
    );

/**
    Changes the specified attribute to the specified value for each of the specified instances
    (which must all be in the same class). The changes occur in the DS only.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_attr_char(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) Attribute ID */
    char            value           /**< (I) */
    );

/**
    Changes (all or some of) the specified array-valued attribute to the specified array of values
    for each of the specified instances (which must all be in the same class).
    The changes occur in the DS only.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_attr_chars(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) Attribute ID */
    int             start,          /**< (I) Position in the VLA to start setting values */
    int             n_values,       /**< (I) Number of values to be set */
    const char*     values          /**< (I) n_values Array of n_values of the appropriate type */
    );

/**
    Returns the value of the specified attribute, for the specified instance.

    Returns attribute values for loaded instances only.
    POM_ask_attr_char will return the attribute's current value for the given instance.
    Meanwhile, if the instance has been modified by another session,
    the value in the database can be different.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_char(
    tag_t       instance_tag,   /**< (I) Tag of instance for which to ask attribute value */
    tag_t       attr_id,        /**< (I) ID of array-valued attribute */
    char*       value,          /**< (O) Single value */
    logical*    is_it_null,     /**< (O) Single flag or array of flags to indicate which values are NULL */
    logical*    is_it_empty     /**< (O) Single flag or array of flags to indicate which values are empty */
    );

/**
    Returns n_values of values of the specified array-valued attribute,
    for the specified instance, starting from the position start.

    Returns attribute values for loaded instances only.

    POM_ask_attr_char will return the attribute's current value for the given instance.
    Meanwhile, if the instance has been modified by another session,
    the value in the database can be different.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_chars(
    tag_t       instance_tag,   /**< (I) Tag of instance for which to ask attribute value */
    tag_t       attr_id,        /**< (I) ID of array-valued attribute */
    int         start,          /**< (I) Position of the first array value to ask (for array returns only) */
    int         n_values,       /**< (I) Number of values in array (for array returns only) */
    char**      values,         /**< (OF) n_values Single value or array of (not NULL and not empty) attribute values */
    logical**   is_it_null,     /**< (OF) n_values Single flag or array of flags to indicate which values are NULL */
    logical**   is_it_empty     /**< (OF) n_values Single flag or array of flags to indicate which values are empty */
    );

/**
    Inserts the specified value into the specified VLA attribute at the specified position.

    The maximum value for start is the length of the VLA, at which point the insert becomes equivalent to an append.

    @note VLAs are attributes which can have a variable number of elements of their declared type.
    The data type of the VLA and class type (for typed references) or
    string length (for notes and strings) is declared when the attribute is defined.
    When an instance of a class with a VLA attribute is created, that VLA attribute is initialized to zero length.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_insert_attr_chars(
    int             n_instances,    /**< (I) */
    const tag_t*    instance_tags,  /**< (I) n_instances */
    tag_t           attr_id,        /**< (I) */
    int             start,          /**< (I) */
    int             n_values,       /**< (I) */
    const char*     values          /**< (I) n_values */
    );

/**
    Adds the specified values to the end of the specified VLAs.

    VLAs are attributes which can have a variable number of elements of their declared type.
    The data type of the VLA and class type (for typed references) or string length (for notes and strings)
    is declared when the attribute is defined.
    When an instance with a VLA attribute is created, that VLA attribute is initialized to zero length.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_append_attr_chars(
    int             n_instances,    /**< (I) Number of instances to append the specified values to */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) ID of the VLA attribute */
    int             n_values,       /**< (I) Number of values to be appended */
    const char*     values          /**< (I) n_values Array of n_values of the appropriate type */
    );

/**
    Returns the value of the lower-bound for an attribute which has been defined to have a lower-bound.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_lower_string(
    tag_t       class_id,       /**< (I) */
    tag_t       attr_id,        /**< (I) */
    char**      value,          /**< (OF) */
    logical*    is_it_null,     /**< (O) */
    logical*    is_it_empty     /**< (O) */
    );

/**
    Returns the value of the upper-bound for an attribute which has been defined to have an upper-bound.
    Returns invalid attr_id if attribute initial value not set or attribute not defined for this class.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_upper_string(
    tag_t       class_id,       /**< (I) ID of class in which to describe attribute */
    tag_t       attr_id,        /**< (I) ID of attribute to describe */
    char**      value,          /**< (OF) Attribute's initial value, lower bound, or upper bound (if it is set) */
    logical*    is_it_null,     /**< (O) Whether the initial value, lower bound or upper bound is NULL */
    logical*    is_it_empty     /**< (O) Whether the initial value, lower bound, or upper bound is empty */
    );

/**
    Returns the initial value for an attribute which has been defined to have an initial value.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_initial_string(
    tag_t       class_id,       /**< (I) */
    tag_t       attr_id,        /**< (I) */
    char**      value,          /**< (OF) */
    logical*    is_it_null,     /**< (O) */
    logical*    is_it_empty     /**< (O) */
    );

/**
    For the specified instances (which must all be in the same class),
    this function changes the specified attribute to the specified value.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_string(
    int             n_instances,    /**< (I) Number of instances to modify */
    const tag_t*    instance_tags,  /**< (I) n_instances Tags of instances to modify */
    tag_t           attr_id,        /**< (I) ID of attribute */
    const char*     value           /**< (I) Value to which to set attribute */
    );

/**
    For the specified instances (which must all be in the same class), this function changes
    (all or some of) the specified array-valued attribute to the specified array of values.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_strings(
    int             n_instances,    /**< (I) Number of instances to modify */
    const tag_t*    instance_tags,  /**< (I) n_instances Tags of instances to modify */
    tag_t           attr_id,        /**< (I) ID of attribute */
    int             start,          /**< (I) Index of first element in array to set */
    int             n_values,       /**< (I) Number of values to set */
    char**          values          /**< (I) n_values */
    );

/**
    Executes the specified enquiry and, for the resulting instances,
    this function changes the specified attribute to the specified value.
    When the enquiry produces no instances, then n_instances is 0, and "instances" is NULL.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_string_by_enq(
    tag_t           enquiry_id,     /**< (I) ID of enquiry to execute to select instances */
    tag_t           attr_id,        /**< (I) ID of attribute */
    const char*     value,          /**< (I) Value to which to set attribute */
    int*            n_instances,    /**< (O) Number of instances to modify */
    tag_t**         instances       /**< (OF) n_instances Tags of instances to modify */
    );

/**
    Executes the specified enquiry and, for the resulting instances,
    changes (all or some of) the specified array-valued attribute to the specified array of values.
    When the enquiry produces no instances, then n_instances is 0, and instances is NULL.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_strings_by_enq(
    tag_t       enquiry_id,     /**< (I) ID of enquiry to execute to select instances */
    tag_t       attr_id,        /**< (I) ID of attribute */
    int         start,          /**< (I) Index of first element in array to set */
    int         n_values,       /**< (I) Number of values to set */
    char**      values,         /**< (I) n_values  */
    int*        n_instances,    /**< (O) Number of instances to modify */
    tag_t**     instances       /**< (OF) n_instances  Tags of instances to modify */
    );

/**
    Changes the specified attribute to the specified value for each of the specified instances
    (which must all be in the same class). The changes occur in the DS only.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_attr_string(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) Attribute ID */
    const char*     value           /**< (I) */
    );

/**
    Changes (all or some of) the specified array-valued attribute to the specified array of values
    for each of the specified instances (which must all be in the same class).
    The changes occur in the DS only.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_attr_strings(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) Attribute ID */
    int             start,          /**< (I) Position in the VLA to start setting values */
    int             n_values,       /**< (I) Number of values to be set */
    char**          values          /**< (I) n_values Array of n_values of the appropriate type */
    );

/**
    POM_ask_attr_string will return the attribute's current value for the given instance.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_string(
    tag_t       instance_tag,   /**< (I) Tag of instance for which to ask attribute value */
    tag_t       attr_id,        /**< (I) ID of array-valued attribute */
    char**      value,          /**< (OF) Single value */
    logical*    is_it_null,     /**< (O) Single flag or array of flags to indicate which values are NULL */
    logical*    is_it_empty     /**< (O) Single flag or array of flags to indicate which values are empty */
    );

/**
    Returns values of the specified array-valued attribute,
    for the specified instance, starting from the position start.

    POM_ask_attr_strings will return the attribute's current value for the given instance.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_strings(
    tag_t       instance_tag,   /**< (I) Tag of instance for which to ask attribute value */
    tag_t       attr_id,        /**< (I) ID of array-valued attribute */
    int         start,          /**< (I) Position of the first array value to ask (for array returns only) */
    int         n_values,       /**< (I) Number of values in array (for array returns only) */
    char***     values,         /**< (OF) n_values Single value or array of (not NULL and not empty) attribute values */
    logical**   is_it_null,     /**< (OF) n_values Single flag or array of flags to indicate which values are NULL */
    logical**   is_it_empty     /**< (OF) n_values Single flag or array of flags to indicate which values are empty */
    );

/**
    Inserts the specified value into the specified VLA attribute at the specified position.

    The maximum value for start is the length of the VLA, at which point the insert becomes equivalent to an append.

    @note VLAs are attributes which can have a variable number of elements of their declared type.
    The data type of the VLA and class type (for typed references) or
    string length (for notes and strings) is declared when the attribute is defined.
    When an instance of a class with a VLA attribute is created, that VLA attribute is initialized to zero length.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_insert_attr_strings(
    int             n_instances,    /**< (I) */
    const tag_t*    instance_tags,  /**< (I) n_instances */
    tag_t           attr_id,        /**< (I) */
    int             start,          /**< (I) */
    int             n_values,       /**< (I) */
    char**          values          /**< (I) n_values */
    );

/**
    Adds the specified values to the end of the specified VLAs.

    VLAs are attributes which can have a variable number of elements of their declared type.
    The data type of the VLA and class type (for typed references) or string length (for notes and strings)
    is declared when the attribute is defined.
    When an instance with a VLA attribute is created, that VLA attribute is initialized to zero length.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_append_attr_strings(
    int             n_instances,    /**< (I) Number of instances to append the specified values to */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) ID of the VLA attribute */
    int             n_values,       /**< (I) Number of values to be appended */
    char**          values          /**< (I) n_values Array of n_values of the appropriate type */
    );

/**
    Returns the value of the lower-bound for an attribute which has been defined to have a lower-bound.
    @note These functions return the date in local time.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_lower_date(
    tag_t       class_id,       /**< (I) */
    tag_t       attr_id,        /**< (I) */
    date_t*     value,          /**< (O) */
    logical*    is_it_null,     /**< (O) */
    logical*    is_it_empty     /**< (O) */
    );

/**
    Returns the value of the lower-bound for an attribute which has been defined to have a lower-bound.
    @note This function returns date in UTC time.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_lower_utc_date(
    tag_t       class_id,       /**< (I) */
    tag_t       attr_id,        /**< (I) */
    date_t*     value,          /**< (O) */
    logical*    is_it_null,     /**< (O) */
    logical*    is_it_empty     /**< (O) */
    );

/**
    Returns the value of the upper-bound for an attribute which has been defined to have an upper-bound.
    Returns invalid attr_id if attribute initial value not set or attribute not defined for this class.
    @note These functions return the date in local time.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_upper_date(
    tag_t       class_id,       /**< (I) ID of class in which to describe attribute */
    tag_t       attr_id,        /**< (I) ID of attribute to describe */
    date_t*     value,          /**< (O) Attribute's initial value, lower bound, or upper bound (if it is set) */
    logical*    is_it_null,     /**< (O) Whether the initial value, lower bound or upper bound is NULL */
    logical*    is_it_empty     /**< (O) Whether the initial value, lower bound, or upper bound is empty */
    );

/**
    Returns the value of the upper-bound for an attribute which has been defined to have an upper-bound.
    @note These functions return the date in UTC time.
    Returns invalid attr_id if attribute initial value not set or attribute not defined for this class.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_upper_utc_date(
    tag_t       class_id,       /**< (I) */
    tag_t       attr_id,        /**< (I) */
    date_t*     value,          /**< (O) */
    logical*    is_it_null,     /**< (O) */
    logical*    is_it_empty     /**< (O) */
    );

/**
    Returns the initial value for an attribute which has been defined to have an initial value.
    @note These functions return the date in local time.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_initial_date(
    tag_t       class_id,       /**< (I) */
    tag_t       attr_id,        /**< (I) */
    date_t*     value,          /**< (O) */
    logical*    is_it_null,     /**< (O) */
    logical*    is_it_empty     /**< (O) */
    );

/**
    Returns the initial value for an attribute which has been defined to have an initial value.
    @note These functions return the date in UTC time.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_initial_utc_date(
    tag_t       class_id,       /**< (I) */
    tag_t       attr_id,        /**< (I) */
    date_t*     value,          /**< (O) */
    logical*    is_it_null,     /**< (O) */
    logical*    is_it_empty     /**< (O) */
    );

/**
    For the specified instances (which must all be in the same class),
    this function changes the specified attribute to the specified value.

    @note This function accepts the date in local time and must be later than minimum specified
    by POM_ask_earlier_date (currently 2nd Jan 1900).

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_date(
    int             n_instances,    /**< (I) Number of instances to modify */
    const tag_t*    instance_tags,  /**< (I) n_instances Tags of instances to modify */
    tag_t           attr_id,        /**< (I) ID of attribute */
    date_t          value           /**< (I) Value to which to set attribute */
    );

/**
    For the specified instances (which must all be in the same class), this function changes
    (all or some of) the specified array-valued attribute to the specified array of values.

    @note This function accepts the date in local time and must be later than minimum specified
    by POM_ask_earlier_date (currently 2nd Jan 1900).

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_dates(
    int             n_instances,    /**< (I) Number of instances to modify */
    const tag_t*    instance_tags,  /**< (I) n_instances Tags of instances to modify */
    tag_t           attr_id,        /**< (I) ID of attribute */
    int             start,          /**< (I) Index of first element in array to set */
    int             n_values,       /**< (I) Number of values to set */
    const date_t*   values          /**< (I) n_values */
    );

/**
    Executes the specified enquiry and, for the resulting instances,
    this function changes the specified attribute to the specified value.
    When the enquiry produces no instances, then n_instances is 0, and "instances" is NULL.

    @note This function accepts the date in local time and must be later than minimum specified
    by POM_ask_earlier_date (currently 2nd Jan 1900).

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_date_by_enq(
    tag_t       enquiry_id,     /**< (I) ID of enquiry to execute to select instances */
    tag_t       attr_id,        /**< (I) ID of attribute */
    date_t      value,          /**< (I) Value to which to set attribute */
    int*        n_instances,    /**< (O) Number of instances to modify */
    tag_t**     instances       /**< (OF) n_instances Tags of instances to modify */
    );

/**
    Executes the specified enquiry and, for the resulting instances,
    changes (all or some of) the specified array-valued attribute to the specified array of values.
    When the enquiry produces no instances, then n_instances is 0, and instances is NULL.

    @note This function accepts the date in local time and must be later than minimum specified
    by POM_ask_earlier_date (currently 2nd Jan 1900).

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_dates_by_enq(
    tag_t           enquiry_id,     /**< (I) ID of enquiry to execute to select instances */
    tag_t           attr_id,        /**< (I) ID of attribute */
    int             start,          /**< (I) Index of first element in array to set */
    int             n_values,       /**< (I) Number of values to set */
    const date_t*   values,         /**< (I) n_values  */
    int*            n_instances,    /**< (O) Number of instances to modify */
    tag_t**         instances       /**< (OF) n_instances  Tags of instances to modify */
    );

/**
    Changes the specified attribute to the specified value for each of the specified instances
    (which must all be in the same class). The changes occur in the DS only.

    @note This function accepts the date in local time and must be later than minimum specified
    by POM_ask_earlier_date (currently 2nd Jan 1900).

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_attr_date(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) Attribute ID */
    date_t          value           /**< (I) */
    );

/**
    Changes the specified attribute to the specified value for each of the specified instances
    (which must all be in the same class). The changes occur in the DS only.

    @note This function accepts the date in UTC time and must be later than minimum specified
    by POM_ask_earlier_date (currently 2nd Jan 1900).
*/
POMAPI int POM_set_attr_utc_date(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) Attribute ID */
    date_t          value           /**< (I) */
    );

/**
    Changes (all or some of) the specified array-valued attribute to the specified array of values
    for each of the specified instances (which must all be in the same class).
    The changes occur in the DS only.

    @note This function accepts the date in local time and must be later than minimum specified
    by POM_ask_earlier_date (currently 2nd Jan 1900).

    @see POM_set_attr_utc_dates

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_attr_dates(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) Attribute ID */
    int             start,          /**< (I) Position in the VLA to start setting values */
    int             n_values,       /**< (I) Number of values to be set */
    const date_t*   values          /**< (I) n_values Array of n_values of the appropriate type */
    );

/**
    Changes (all or some of) the specified array-valued attribute to the specified array of values
    for each of the specified instances (which must all be in the same class).
    The changes occur in the DS only.

    @note This function accepts the date in UTC time and must be later than minimum specified
    by POM_ask_earlier_date (currently 2nd Jan 1900).

    @see POM_set_attr_dates

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_attr_utc_dates(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) Attribute ID */
    int             start,          /**< (I) Position in the VLA to start setting values */
    int             n_values,       /**< (I) Number of values to be set */
    const date_t*   values          /**< (I) n_values Array of n_values of the appropriate type */
    );

/**
    Returns the value of the specified attribute, for the specified instance.

    Returns attribute values for loaded instances only.

    POM_ask_attr_date will return the attribute's current value in the session for the given instance.
    Meanwhile, if the instance has been modified by another session,
    the value in the database can be different.

    @note This function returns date in local time.
    @see POM_ask_attr_utc_date

   <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_date(
    tag_t       instance_tag,   /**< (I) Tag of instance for which to ask attribute value */
    tag_t       attr_id,        /**< (I) ID of array-valued attribute */
    date_t*     value,          /**< (O) Single value */
    logical*    is_it_null,     /**< (O) Single flag or array of flags to indicate which values are NULL */
    logical*    is_it_empty     /**< (O) Single flag or array of flags to indicate which values are empty */
    );

/**
    Returns the value of the specified attribute, for the specified instance.

    Returns attribute values for loaded instances only.

    POM_ask_attr_utc_date will return the attribute's current value in the session for the given instance.
    Meanwhile, if the instance has been modified by another session,
    the value in the database can be different.

   @note This function returns date in UTC time.
   @see POM_ask_attr_date

   <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_utc_date(
    tag_t       instance_tag,   /**< (I) */
    tag_t       attr_id,        /**< (I) */
    date_t*     value,          /**< (O) */
    logical*    is_it_null,     /**< (O) */
    logical*    is_it_empty     /**< (O) */
    );

/**
    Returns n_values of values of the specified array-valued attribute,
    for the specified instance, starting from the position start.

    Returns attribute values for loaded instances only.

    POM_ask_attr_dates will return the attribute's current value in the session for the given instance.
    Meanwhile, if the instance has been modified by another session,
    the value in the database can be different.

   @note This function returns date in local time.
   @see POM_ask_attr_utc_dates

   <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_dates(
    tag_t       instance_tag,   /**< (I) Tag of instance for which to ask attribute value */
    tag_t       attr_id,        /**< (I) ID of array-valued attribute */
    int         start,          /**< (I) Position of the first array value to ask (for array returns only) */
    int         n_values,       /**< (I) Number of values in array (for array returns only) */
    date_t**    values,         /**< (OF) n_values Single value or array of (not NULL and not empty) attribute values */
    logical**   is_it_null,     /**< (OF) n_values Single flag or array of flags to indicate which values are NULL */
    logical**   is_it_empty     /**< (OF) n_values Single flag or array of flags to indicate which values are empty */
    );

/**
    Returns n_values of values of the specified array-valued attribute,
    for the specified instance, starting from the position start.

    Returns attribute values for loaded instances only.

    POM_ask_attr_dates will return the attribute's current value in the session for the given instance.
    Meanwhile, if the instance has been modified by another session,
    the value in the database can be different.

   @note This function returns date in UTC time.
   @see POM_ask_attr_dates

   <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_utc_dates(
    tag_t       instance_tag,   /**< (I) */
    tag_t       attr_id,        /**< (I) */
    int         start,          /**< (I) */
    int         n_values,       /**< (I) */
    date_t**    values,         /**< (OF) n_values  */
    logical**   is_it_null,     /**< (OF) n_values  */
    logical**   is_it_empty     /**< (OF) n_values  */
    );

/**
    Inserts the specified value into the specified VLA attribute at the specified position.

    The maximum value for start is the length of the VLA, at which point the insert becomes equivalent to an append.

    @note VLAs are attributes which can have a variable number of elements of their declared type.
    The data type of the VLA and class type (for typed references) or
    string length (for notes and strings) is declared when the attribute is defined.
    When an instance of a class with a VLA attribute is created, that VLA attribute is initialized to zero length.

    @note This function accepts the date in local time and must be later than minimum specified
    by POM_ask_earlier_date (currently 2nd Jan 1900).

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_insert_attr_dates(
    int             n_instances,    /**< (I) */
    const tag_t*    instance_tags,  /**< (I) n_instances */
    tag_t           attr_id,        /**< (I) */
    int             start,          /**< (I) */
    int             n_values,       /**< (I) */
    const date_t*   values          /**< (I) n_values */
    );

/**
    Adds the specified values to the end of the specified VLAs.

    VLAs are attributes which can have a variable number of elements of their declared type.
    The data type of the VLA and class type (for typed references) or string length (for notes and strings)
    is declared when the attribute is defined.
    When an instance with a VLA attribute is created, that VLA attribute is initialized to zero length.

    @note This function accepts the date in local time and must be later than minimum specified
    by POM_ask_earlier_date (currently 2nd Jan 1900).

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_append_attr_dates(
    int             n_instances,    /**< (I) Number of instances to append the specified values to */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) ID of the VLA attribute */
    int             n_values,       /**< (I) Number of values to be appended */
    const date_t*   values          /**< (I) n_values Array of n_values of the appropriate type */
    );

/**
    Returns the initial value for an attribute which has been defined to have an initial value.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_initial_logical(
    tag_t       class_id,       /**< (I) */
    tag_t       attr_id,        /**< (I) */
    logical*    value,          /**< (O) */
    logical*    is_it_null,     /**< (O) */
    logical*    is_it_empty     /**< (O) */
    );

/**
    For the specified instances (which must all be in the same class),
    this function changes the specified attribute to the specified value.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_logical(
    int             n_instances,    /**< (I) Number of instances to modify */
    const tag_t*    instance_tags,  /**< (I) n_instances Tags of instances to modify */
    tag_t           attr_id,        /**< (I) ID of attribute */
    logical         value           /**< (I) Value to which to set attribute */
    );

/**
    For the specified instances (which must all be in the same class), this function changes
    (all or some of) the specified array-valued attribute to the specified array of values.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_logicals(
    int             n_instances,    /**< (I) Number of instances to modify */
    const tag_t*    instance_tags,  /**< (I) n_instances Tags of instances to modify */
    tag_t           attr_id,        /**< (I) ID of attribute */
    int             start,          /**< (I) Index of first element in array to set */
    int             n_values,       /**< (I) Number of values to set */
    const logical*  values          /**< (I) n_values */
    );

/**
    Executes the specified enquiry and, for the resulting instances,
    this function changes the specified attribute to the specified value.
    When the enquiry produces no instances, then n_instances is 0, and "instances" is NULL.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_logical_by_enq(
    tag_t       enquiry_id,     /**< (I) ID of enquiry to execute to select instances */
    tag_t       attr_id,        /**< (I) ID of attribute */
    logical     value,          /**< (I) Value to which to set attribute */
    int*        n_instances,    /**< (O) Number of instances to modify */
    tag_t**     instances       /**< (OF) n_instances Tags of instances to modify */
    );

/**
    Executes the specified enquiry and, for the resulting instances,
    changes (all or some of) the specified array-valued attribute to the specified array of values.
    When the enquiry produces no instances, then n_instances is 0, and instances is NULL.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_logicals_by_enq(
    tag_t           enquiry_id,     /**< (I) ID of enquiry to execute to select instances */
    tag_t           attr_id,        /**< (I) ID of attribute */
    int             start,          /**< (I) Index of first element in array to set */
    int             n_values,       /**< (I) Number of values to set */
    const logical*  values,         /**< (I) n_values  */
    int*            n_instances,    /**< (O) Number of instances to modify */
    tag_t**         instances       /**< (OF) n_instances  Tags of instances to modify */
    );

/**
    Changes the specified attribute to the specified value for each of the specified instances
    (which must all be in the same class). The changes occur in the DS only.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_attr_logical(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) Attribute ID */
    logical         value           /**< (I) */
    );

/**
    Changes (all or some of) the specified array-valued attribute to the specified array of values
    for each of the specified instances (which must all be in the same class).
    The changes occur in the DS only.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_attr_logicals(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) Attribute ID */
    int             start,          /**< (I) Position in the VLA to start setting values */
    int             n_values,       /**< (I) Number of values to be set */
    const logical*  values          /**< (I) n_values Array of n_values of the appropriate type */
    );

/**
    Returns the value of the specified attribute, for the specified instance.

    Returns attribute values for loaded instances only.

    POM_ask_attr_logical will return the attribute's current value in the session for the given instance.
    Meanwhile, if the instance has been modified by another session,
    the value in the database can be different.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_logical(
    tag_t       instance_tag,   /**< (I) Tag of instance for which to ask attribute value */
    tag_t       attr_id,        /**< (I) ID of array-valued attribute */
    logical*    value,          /**< (O) Single value */
    logical*    is_it_null,     /**< (O) Single flag or array of flags to indicate which values are NULL */
    logical*    is_it_empty     /**< (O) Single flag or array of flags to indicate which values are empty */
    );

/**
    Returns n_values of values of the specified array-valued attribute,
    for the specified instance, starting from the position start.

    Returns attribute values for loaded instances only.

    POM_ask_attr_logicals will return the attribute's current value in the session for the given instance.
    Meanwhile, if the instance has been modified by another session,
    the value in the database can be different.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_logicals(
    tag_t       instance_tag,   /**< (I) Tag of instance for which to ask attribute value */
    tag_t       attr_id,        /**< (I) ID of array-valued attribute */
    int         start,          /**< (I) Position of the first array value to ask (for array returns only) */
    int         n_values,       /**< (I) Number of values in array (for array returns only) */
    logical**   values,         /**< (OF) n_values Single value or array of (not NULL and not empty) attribute values */
    logical**   is_it_null,     /**< (OF) n_values Single flag or array of flags to indicate which values are NULL */
    logical**   is_it_empty     /**< (OF) n_values Single flag or array of flags to indicate which values are empty */
    );

/**
    Inserts the specified value into the specified VLA attribute at the specified position.

    The maximum value for start is the length of the VLA, at which point the insert becomes equivalent to an append.

    @note VLAs are attributes which can have a variable number of elements of their declared type.
    The data type of the VLA and class type (for typed references) or
    string length (for notes and strings) is declared when the attribute is defined.
    When an instance of a class with a VLA attribute is created, that VLA attribute is initialized to zero length.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_insert_attr_logicals(
    int             n_instances,    /**< (I) */
    const tag_t*    instance_tags,  /**< (I) n_instances */
    tag_t           attr_id,        /**< (I) */
    int             start,          /**< (I) */
    int             n_values,       /**< (I) */
    const logical*  values          /**< (I) n_values */
    );

/**
    Adds the specified values to the end of the specified VLAs.

    VLAs are attributes which can have a variable number of elements of their declared type.
    The data type of the VLA and class type (for typed references) or string length (for notes and strings)
    is declared when the attribute is defined.
    When an instance with a VLA attribute is created, that VLA attribute is initialized to zero length.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_append_attr_logicals(
    int             n_instances,    /**< (I) Number of instances to append the specified values to */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) ID of the VLA attribute */
    int             n_values,       /**< (I) Number of values to be appended */
    const logical*  values          /**< (I) n_values Array of n_values of the appropriate type */
    );

/**
    For the specified instances (which must all be in the same class),
    this function changes the specified attribute to the specified value.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_tag(
    int             n_instances,    /**< (I) Number of instances to modify */
    const tag_t*    instance_tags,  /**< (I) n_instances Tags of instances to modify */
    tag_t           attr_id,        /**< (I) ID of attribute */
    tag_t           value           /**< (I) Value to which to set attribute */
    );

/**
    For the specified instances (which must all be in the same class), this function changes
    (all or some of) the specified array-valued attribute to the specified array of values.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_tags(
    int             n_instances,    /**< (I) Number of instances to modify */
    const tag_t*    instance_tags,  /**< (I) n_instances Tags of instances to modify */
    tag_t           attr_id,        /**< (I) ID of attribute */
    int             start,          /**< (I) Index of first element in array to set */
    int             n_values,       /**< (I) Number of values to set */
    const tag_t*    values          /**< (I) n_values */
    );

/**
    Executes the specified enquiry and, for the resulting instances,
    this function changes the specified attribute to the specified value.
    When the enquiry produces no instances, then n_instances is 0, and "instances" is NULL.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_tag_by_enq(
    tag_t       enquiry_id,     /**< (I) ID of enquiry to execute to select instances */
    tag_t       attr_id,        /**< (I) ID of attribute */
    tag_t       value,          /**< (I) Value to which to set attribute */
    int*        n_instances,    /**< (O) Number of instances to modify */
    tag_t**     instances       /**< (OF) n_instances Tags of instances to modify */
    );

/**
    Executes the specified enquiry and, for the resulting instances,
    changes (all or some of) the specified array-valued attribute to the specified array of values.
    When the enquiry produces no instances, then n_instances is 0, and instances is NULL.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_modify_tags_by_enq(
    tag_t           enquiry_id,     /**< (I) ID of enquiry to execute to select instances */
    tag_t           attr_id,        /**< (I) ID of attribute */
    int             start,          /**< (I) Index of first element in array to set */
    int             n_values,       /**< (I) Number of values to set */
    const tag_t*    values,         /**< (I) n_values  */
    int*            n_instances,    /**< (O) Number of instances to modify */
    tag_t**         instances       /**< (OF) n_instances  Tags of instances to modify */
    );

/**
    Changes the specified attribute to the specified value for each of the specified instances
    (which must all be in the same class). The changes occur in the DS only.

    No attribute of attr_id in instance_tags may be set to an instance value that is locked with #POM_delete_lock.

    Returns #POM_ok on success or a POM error indicating the type of failure that occurred.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_attr_tag(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) Attribute ID */
    tag_t           value           /**< (I) value to set in attribute with attr_id in each element of instance_tags. */
    );

/**
    Changes (all or some of) the specified array-valued attribute to the specified array of values
    for each of the specified instances (which must all be in the same class).
    The changes occur in the DS only.

    No attribute of attr_id in instance_tags may be set to values that include instances that are locked with #POM_delete_lock.

    Returns #POM_ok on success or a POM error indicating the type of failure that occurred.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_attr_tags(
    int             n_instances,    /**< (I) Number of instances to set */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) Attribute ID */
    int             start,          /**< (I) Position in the VLA to start setting values */
    int             n_values,       /**< (I) Number of values to be set */
    const tag_t*    values          /**< (I) n_values array of instances to set in attribute with attr_id in each element of instance_tags. */
    );

/**
    Returns the value of the specified attribute, for the specified instance.

    Returns attribute values for loaded instances only.

    POM_ask_attr_tag will return the attribute's current value in the session for the given instance.
    Meanwhile, if the instance has been modified by another session,
    the value in the database can be different.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_tag(
    tag_t       instance_tag,   /**< (I) Tag of instance for which to ask attribute value */
    tag_t       attr_id,        /**< (I) ID of array-valued attribute */
    tag_t*      value,          /**< (O) Single value */
    logical*    is_it_null,     /**< (O) Single flag or array of flags to indicate which values are NULL */
    logical*    is_it_empty     /**< (O) Single flag or array of flags to indicate which values are empty */
    );

/**
    Returns n_values of values of the specified array-valued attribute,
    for the specified instance, starting from the position start.

    Returns attribute values for loaded instances only.

    POM_ask_attr_tags will return the attribute's current value in the session for the given instance.

    The value returned is the value the attribute had when the instance was loaded.
    Meanwhile, if the instance has been modified by another session,
    the value in the database can be different.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_attr_tags(
    tag_t       instance_tag,   /**< (I) Tag of instance for which to ask attribute value */
    tag_t       attr_id,        /**< (I) ID of array-valued attribute */
    int         start,          /**< (I) Position of the first array value to ask (for array returns only) */
    int         n_values,       /**< (I) Number of values in array (for array returns only) */
    tag_t**     values,         /**< (OF) n_values Single value or array of (not NULL and not empty) attribute values */
    logical**   is_it_null,     /**< (OF) n_values Single flag or array of flags to indicate which values are NULL */
    logical**   is_it_empty     /**< (OF) n_values Single flag or array of flags to indicate which values are empty */
    );

/**
    Inserts the specified value into the specified VLA attribute at the specified position.

    The maximum value for start is the length of the VLA, at which point the insert becomes equivalent to an append.

    @note VLAs are attributes which can have a variable number of elements of their declared type.
    The data type of the VLA and class type (for typed references) or
    string length (for notes and strings) is declared when the attribute is defined.
    When an instance of a class with a VLA attribute is created, that VLA attribute is initialized to zero length.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_insert_attr_tags(
    int             n_instances,    /**< (I) */
    const tag_t*    instance_tags,  /**< (I) n_instances */
    tag_t           attr_id,        /**< (I) */
    int             start,          /**< (I) */
    int             n_values,       /**< (I) */
    const tag_t*    values          /**< (I) n_values */
    );

/**
    Adds the specified values to the end of the specified VLAs.

    VLAs are attributes which can have a variable number of elements of their declared type.
    The data type of the VLA and class type (for typed references) or string length (for notes and strings)
    is declared when the attribute is defined.
    When an instance with a VLA attribute is created, that VLA attribute is initialized to zero length.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_append_attr_tags(
    int             n_instances,    /**< (I) Number of instances to append the specified values to */
    const tag_t*    instance_tags,  /**< (I) n_instances Array of n_instances tags of these instances */
    tag_t           attr_id,        /**< (I) ID of the VLA attribute */
    int             n_values,       /**< (I) Number of values to be appended */
    const tag_t*    values          /**< (I) n_values Array of n_values of the appropriate type */
    );

/**
    Freezes an instance so that all of its freezable attributes can no longer be modified.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_freeze(
    tag_t  instance_to_freeze   /**< (I) */
    );

/**
    Unfreezes an instance so that all of its freezable attributes can be unfrozen and modified.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_unfreeze(
    tag_t  instance_to_unfreeze     /**< (I) */
    );

/**
    Checks whether the given instance is frozen

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_is_frozen(
    tag_t       instance,   /**< (I) Tag of instance to test */
    logical*    verdict     /**< (O) True or false */
    );

/**
    Getter function for the object_properties bit flags on POM_object.

    Tokens:
    #POM_object_mask_frozen
    #POM_object_mask_has_ixr
    #POM_object_mask_is_locked

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_get_object_property
  ( tag_t      instance,   /**< (I) Tag of instance to test */
    int        bit_to_get, /**< (I) The object property flag to test for */
    logical   *verdict     /**< (O) True or false */
  );

/**
    Setter function for the object_properties bit flags on POM_object

    Tokens:
    #POM_object_mask_frozen
    #POM_object_mask_has_ixr
    #POM_object_mask_is_locked

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_object_property
  ( tag_t      instance,   /**< (I) Tag of instance to test */
    int        bit_to_set, /**< (I) The object property flag to set */
    logical    value       /**< (I) True or false */
  );

/**
    Checks whether the given instance is loaded in the callers DS or not.
    Newly created instances are counted as loaded as they are already present in DS.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_is_loaded(
    tag_t       instance,   /**< (I) Tag of instance to test */
    logical*    verdict     /**< (O) True or false */
    );

/**
    Creates an instance of the class POM_user and sets to the values specified the:
    <ul>
    <li>user_id (forced to lower case)
    <li>user_name
    <li>password
    </ul>
    The tag of the user created is returned in new_user.
    The user must be a Teamcenter system administrator to create a user.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_new_user(
    const char*     user_id,    /**< (I) Login name for the user */
    const char*     user_name,  /**< (I) Full name for the user */
    const char*     password,   /**< (I) User's password */
    tag_t*          new_user    /**< (O) Tag of the new user */
    );

/**
    Takes a tag of an instance of the class POM_user, or a subclass of same,
    and sets to the values specified the:
    <ul>
    <li>user_id (forced to lower case)
    <li>user_name
    <li>password
    </ul>
    The user must be a Teamcenter system administrator to "init" a user.

    This function allows the caller to create a user which has
    extra attributes they have defined in a subclass of POM_user.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_init_user(
    tag_t           new_user,   /**< (I) Tag of the new user */
    const char*     user_id,    /**< (I) Login name for the user */
    const char*     user_name,  /**< (I) Full name for the user */
    const char*     password    /**< (I) User's password */
    );

/**
    Sets the license_level and status of the user identified by a_user.
    The caller must be a Teamcenter system administrator.
    The status is not interpreted by POM and is provided for the caller to classify users.
    The number of purchased and used licenses for the specified license_level is returned.

    @returns
    <ul>
    <li>#POM_ok on success
    <li>#POM_invalid_value if the parameters @p new_status or @p license_level are not valid values.
    <li>#POM_invalid_tag if @p a_user is invalid.
    </ul>
*/
POMAPI int POM_set_user_license_status(
    tag_t  a_user,       /**< (I) Tag of an existing user */
    int    new_status,   /**< (I) Status to grant to the user. <br/>Valid values are:
                         <ul><li>#POM_USER_STATUS_ACTIVE</li><li>#POM_USER_STATUS_INACTIVE</li></ul> */
    int    license_level,/**< (I) License level to grant to the user. <br/>Valid values are:
                         <ul><li>#POM_license_level_author</li><li>#POM_license_level_consumer</li><li>#POM_license_level_occasional</li>
                         <li>#POM_license_level_viewer</li><li>#POM_license_level_user</li></ul>*/
    int    *purchased,   /**< (O) Number of purchased licenses */
    int    *used         /**< (O) Number of used licenses */
    );

/**
    Sets the license_level and status of the user identified by a_user based on license
    bundle to be assigned to the user. The caller must be a Teamcenter system administrator.
    The status is not interpreted by POM and is provided for the caller to classify users.
    The number of purchased and used licenses for the specified license_level is returned.
*/
POMAPI int POM_set_user_license_status2(
    tag_t          a_user,        /**< (I) Tag of an existing user */
    int            new_status,    /**< (I) Status to grant to the user */
    int            license_level, /**< (I) License level to grant to the user */
    const char     *license_bundle,/**< (I) License bundle to assign to the user */
    int            *purchased,    /**< (O) Number of purchased licenses */
    int            *used          /**< (O) Number of used licenses */
    );

/**
Sets the license level and status of the user based on a license
bundle and the license server to be assigned to the user.
<br>The caller must be a Teamcenter system administrator.
<br>The status is not interpreted by POM and is provided for the
caller to classify users.
<br>The number of purchased and used licenses for the specified
license level is also retrieved.

@returns
<ul>
<li>#POM_ok on success
<li>#POM_invalid_value if new_status or license_level is not an integer
</ul>
*/
POMAPI int POM_set_user_license_status_with_server(
    tag_t          a_user,           /**< (I) Tag of an existing user */
    int            new_status,       /**< (I) Status to grant to the user */
    int            license_level,    /**< (I) License level to grant to the user */
    const char     *license_bundle,  /**< (I) License bundle to assign to the user */
    const char     *license_server,  /**< (I) License Server to assign to the user */
    int            *purchased,       /**< (O) Number of purchased licenses */
    int            *used             /**< (O) Number of used licenses */
    );

/**
    Takes the tag of a user object and deletes it from the database.
    It will only attempt to delete the specified user if
    the current user is a Teamcenter system administrator,
    and will only be able to delete it if it is not referenced from any other POM object
    (i.e., this implies that there must be no member objects linking this user to any groups).
    When a user logs into POM, the appropriate user object is locked so that it cannot be deleted.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_delete_user(
    tag_t  a_user   /**< (I) Tag of the user to delete */
    );

/**
    Creates a new group (an instance of the class "POM_group").

    @note The name is forced to lower case before being set.

    <b>Restrictions:</b>

    You must be logged in as a System Administrator to use this function.

    <b>Return values:</b>
    #POM_invalid_string - Invalid name null or exceeds #POM_MAX_NOTE_LENGTH <br>
    #POM_invalid_value - Invalid privilege - must be 0 or 1.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_new_group(
    const char*     name,       /**< (I) The new group's name */
    int             privilege,  /**< (I) The new group's SA privilege (1 if it is an SA group, 0 if not) */
    tag_t*          new_group   /**< (O) The new group */
    );

/**
    Initializes a group.

    <b>Restrictions:</b>
    <ul>
    <li>You must be logged in as a system administrator to use this function.
    <li>The name is forced to lower case before being set.
    </ul>

    <b>Return values:</b>
    #POM_invalid_string - Invalid name - null or exceeds #POM_MAX_NOTE_LENGTH <br>
    #POM_invalid_value - Invalid privilege - must be 0 or 1.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_init_group(
    tag_t           new_group,  /**< (I) The group to initialize */
    const char*     name,       /**< (I) The group's new name */
    int             privilege   /**< (I) The group's new SA privilege (1 if it is an SA group, 0 if not) */
    );

/**
    Takes the tag of a group object and deletes it from the database.
    It will only attempt to delete the group if the current user is a Teamcenter system administrator,
    and will only be able to delete it if it is not referenced from any other POM object -
    (i.e., this implies that there must be no users linked to this group by member objects.

    When a user logs into POM, the appropriate group object is locked so that it cannot be deleted.
    Additionally, this lock is updated whenever the user changes group.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_delete_group(
    tag_t  a_group  /**< (I) Tag of the group to delete */
    );

/**
    Creates an instance of the class POM_member, and sets to the specified values the:
    <ul>
    <li>user
    <li>group
    <li>"ga" status
    </ul>
    The tag of the member created is returned in the argument new_member.
    To create a member instance,
    the calling user must be either a Teamcenter system administrator or
    the group administrator of the group in which the member will reside.
    The as_ga flag allows a member to be deemed a group administrator of the group.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_new_member(
    tag_t       user,           /**< (I) User to be made a member of the group given */
    tag_t       group,          /**< (I) Group to grant the user membership of */
    logical     as_ga,          /**< (I) Whether to grant group administrator privilege to the member */
    tag_t*      new_member      /**< (O) Tag of the new member */
    );

/**
    Takes a tag of an instance of the class POM_member,
    or a subclass of same, and sets to the specified values the:
    <ul>
    <li>Reference to a group
    <li>Reference to a user
    <li>Status of that user in that group
    </ul>
    The user must be a Teamcenter system administrator
    (or the group administrator of the specified group) to "init" a member.
    No instance of a subclass of the class POM_member can be saved until
    it has been initialized by this function (since it will contain empty attributes).
    This ensures that no unprivileged user can create member objects.

    This function allows the caller to create a member which has
    extra attributes they have defined in a subclass of POM_member.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_init_member(
    tag_t       new_member,     /**< (I) Tag of the new member */
    tag_t       user,           /**< (I) User to be made a member of the group given */
    tag_t       group,          /**< (I) Group to grant the user membership of */
    logical     as_ga           /**< (I) Whether to grant group administrator privilege to the member */
    );

/**
    Takes the tag of a member object and deletes it from the database.
    From this point on, the user specified will be unable to log in to the listed group.
    If that user is currently logged in, this will not prevent him from setting his current group
    (the deletion will only take effect after he has logged out).

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_delete_member(
    tag_t  a_member     /**< (I) Tag of the member object to delete */
    );

/**
    This function takes a class ID and an array of attributes
    (which must be attributes of the specified class)
    and an array of #POM_order_ascending / #POM_order_descending tokens
    (which must be the same size as the array of attributes).
    It also takes an array of loaded POM instances,
    all of which must be instances of the class specified (or subclasses thereof).
    It returns an ordered array of POM objects.

    Attributes which are NULL are taken to be equal to other NULL values.
    NULL values are ordered after non-NULL values when ordering in ascending order,
    and vice-versa (i.e., NULL values are logically greater than all non-NULL values).

    @note The instances must be loaded and currently,
    only one attribute can be specified for the ordering.
    None of the attributes being ordered can be empty, or array attributes.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_order_instances(
    tag_t           class_id,           /**< (I) Class ID containing the attributes */
    int             n_instances,        /**< (I) Number of instances to sort */
    const tag_t*    instances,          /**< (I) n_instances Array of instances to sort */
    int             n_attrs,            /**< (I) Number of attributes to compare */
    const tag_t*    attr_ids,           /**< (I) n_attrs Array of attributes */
    const int*      up_or_down_tokens,  /**< (I) n_attrs #POM_order_ascending / #POM_order_descending tokens */
    tag_t**         ordered_instances   /**< (OF) n_instances Returned array of instances */
    );

/**
    Used to determine POM's version number.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_get_version(
    int*   version      /**< (O) POM version number */
    );

/**
    Used to check whether POM is running (i.e., whether a user is logged in).

    <br>Returns
    <ul>
    <li> POM_not_yet_started (and logged_in false) if POM_init_module has not been called
    <li> POM_ok and logged_in false if POM is initialised, but no user is logged in
    <li> POM_ok and logged_in true if POM is initialised and a user is logged in
    </ul>

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_is_running(
    logical*    logged_in  /**< (O) True or false */
    );

/**
    This function is used to determine whether there are any
    POM instances that have been modified and not yet saved.
    This includes all newly created instances.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_any_unsaved_info(
    logical*    answer  /**< (O) True or false */
    );

/**
    Returns the tag of the topmost class in the POM class hierarchy.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_top_class(
    tag_t* class_id     /**< (O) ID of class */
    );

/**
    Validates the given tag. For a tag to be valid it must correspond to an instance of a POM class.
    @note Tags of the classes and attributes themselves are not considered to be valid.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_is_tag_valid(
    tag_t       tag,        /**< (I) Tag to validate */
    logical*    answer      /**< (O) Returns true if tag is valid */
    );

/**
    Logs the named user into POM, which must have been already initialized.

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_login(
    const char*     user_name,      /**< (I) */
    const char*     password,       /**< (I) */
    const char*     group_name      /**< (I) */
    );

/**
    Logs the sponsored user into POM, which must have been already initialized.
    <br/>The @p sponsored_user_name is the user that will be logged in, and actions will run as that user.
    <br/>The @p user_name and @p password are used to authenticate the sponsoring user.
    <br/>The @p sponsored_user_name and @p sponsored_group_name are used to authenticate the sponsored user.
    <br> Supports rollback using markpoints: NO.

    @returns
    <ul>
    <li>#POM_ok on success.
    <li>#POM_user_and_group_invalid if the user is not in the provided group.
    <li>#POM_invalid_account_values if the user it not a valid user.
    <li>#POM_AUDIT_bad_password_login if the password for the user is not valid.
    <li>#POM_already_running if the user is already logged in.
    <li>#POM_invalid_name if the group provided is not valid.
    <li>#POM_op_not_supported if attempting an SSO login without SSO being enabled.
    <li>#POM_tcsso_error if there is an error in the TCSSO login attempt.
    <li>Possibly other errors.
    </ul>
*/
POMAPI int POM_login_sponsored(
    const char*     user_name,              /**< (I) Sponsoring user */
    const char*     password,               /**< (I) Sponsoring users password */
    const char*     sponsored_user_name,    /**< (I) Sponsored user */
    const char*     sponsored_group_name    /**< (I) Group of the sponsored user */
    );

/**
    Logs in to POM using the current operating system user name as the Teamcenter user ID.
    No password authentication is performed within Teamcenter.

    For a call to this function to be successful,
    there must be a Teamcenter user with an identical user ID to
    the operating system user name of the caller of this function.
    Also, that user must have a default group set (and be a valid member of that group).

    @note POM must be in an initialized state prior to calling this function. See #POM_init_module.

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_auto_login( void );

/**
    Logs the user out from POM. If ignore_unsaved_stuff is false,
    the POM will return an error and not log out if there are unsaved instances.
    If ignore_unsaved_stuff is true, the POM will logout.

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_logout(
    logical     ignore_unsaved_stuff    /**< (I) Whether to log out even though there are unsaved changes in DS */
    );

/**
    Initializes the POM module, establishes contact with the underlying RDBMS,
    and loads the schema file containing the class definitions.

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_init_module( void );

/**
    Shuts down the POM module.

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_exit_module( void );

/**
    Returns an array containing all the members of the specified group.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_list_group_members(
    tag_t       a_group,    /**< (I) */
    int*        n_members,  /**< (O) */
    tag_t**     members     /**< (OF) n_members */
    );

/**
    Determines whether the specified instance has ever been saved to the database.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_is_newly_created(
    tag_t       instance,   /**< (I) Tag of instance to test */
    logical*    answer      /**< (O) True or false */
    );

/**
    Returns the date that the instance was archived. The instance must be loaded.
    The date returned by this function will be in local time.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_archive_date(
    tag_t       instance,       /**< (I) */
    date_t*     archive_date    /**< (O) */
    );

/**
    Sets the date specifying when the instance was archived.
    The instance must be loaded for modify, and must be saved afterwards to permanently record the date.
    An Teamcenter system administrator can set this value on any object.
    An ordinary user must be the owning user of the object to use this function.

    @note This function accepts the date in local time and must be later than minimum specified
    by POM_ask_earlier_date (currently 2nd Jan 1900).

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_archive_date(
    tag_t  instance,        /**< (I) */
    date_t archive_date     /**< (I) */
    );

/**
    Sets the archive date attribute to NULL for a POM application object instance.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_archive_date_null(
    tag_t  instance     /**< (I) Instance in which to set the archive date to NULL */
    );

/**
    Returns the archive information string associated with the instance.
    The instance must be loaded.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_archive_info(
    tag_t  instance,        /**< (I) */
    char** archive_info     /**< (OF) */
    );

/**
    Sets the archive information string associated with the instance.
    The instance must be loaded for modify,
    and must be saved afterwards to permanently record the information.
    An Teamcenter system administrator can set this value on any object.
    An ordinary user must be the owning user of the object to use this function.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_archive_info(
    tag_t           instance,       /**< (I) */
    const char*     archive_info    /**< (I) */
    );

/**
    Sets the archive info attribute to NULL for a POM application object instance.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_archive_info_null(
    tag_t  instance     /**< (I) Instance in which to set the archive date to NULL */
    );

/**
    Retrieves a token indicating the state of the @p instance.
    <br> Supports rollback using markpoints: YES.

    @returns
    <ul>
    <li>#POM_ok on success
    <li>#POM_invalid_tag if @p instance is invalid tag or #NULLTAG
    </ul>
*/
POMAPI int POM_ask_instance_state(
    tag_t  instance,              /**< (I) Tag of the instance whose state is being enquired */
    int*   state_token            /**< (O) Token indicating current state of the instance <br>
                                        #POM_inst_is_not_loaded <br>
                                        #POM_inst_is_loaded <br>
                                        #POM_inst_is_loaded_for_modify <br>
                                        #POM_inst_is_new <br>
                                        #POM_inst_is_modified <br>
                                        #POM_inst_is_selected <br>
                                        #POM_inst_is_selected_modified */
    );


/**
    Retrieves an array of tokens indicating the state of each input instance.
    <br> Supports rollback using markpoints: YES.

    @returns
    <ul>
    <li>#POM_ok on success
    <li>#POM_invalid_tag if any of the @p instances is invalid tag or #NULLTAG
    </ul>
*/
POMAPI int POM_ask_instances_states(
    int          n_instances,             /**< (I) Number of instances. */
    const tag_t* instances,               /**< (I) n_instances Instances whose state is being enquired */
    int**        state_tokens             /**< (OF) n_instances Token indicating current state of each input instance <br>
                                                #POM_inst_is_not_loaded <br>
                                                #POM_inst_is_loaded <br>
                                                #POM_inst_is_loaded_for_modify <br>
                                                #POM_inst_is_new <br>
                                                #POM_inst_is_modified <br>
                                                #POM_inst_is_selected <br>
                                                #POM_inst_is_selected_modified */
    );

/**
    Converts original_date to converted date according to the conversion token specified.
    Appropriate tokens are:

    #POM_gmt_to_local <br>
    #POM_local_to_gmt

    @note This function accepts the date in local time and must be later than minimum specified
    by POM_ask_earlier_date (currently 2nd Jan 1900).

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_convert_date(
    int         conversion,         /**< (I) */
    date_t      original_date,      /**< (I) */
    date_t*     converted_date      /**< (O) */
    );

/**
    Gets the name for the given, loaded, user.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_user_name(
    tag_t   user,   /**< (I) Tag ID of a user instance */
    char**  name    /**< (OF) Returned memory containing the name of the user */
    );

/**
    Sets the name for the given, modifiable, user.
    The caller must be either a Teamcenter system administrator or
    be setting the name for the currently logged in user.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_user_name(
    tag_t           user,   /**< (I) Tag ID of a user instance */
    const char*     name    /**< (I) New name for the user */
    );

/**
    Gets the unique ID for the given, loaded, user.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_user_id(
    tag_t  user,    /**< (I) Tag ID of a user instance */
    char** id       /**< (OF) Returned memory containing the ID of the user */
    );

/**
    Sets the unique ID for the given, modifiable, user.
    The caller must be a Teamcenter system administrator.
    Note that it will not allow to change unique ID of those users who are already logged in.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_user_id(
    tag_t           user,   /**< (I) Tag ID of a user instance */
    const char*     id      /**< (I) New ID for the user */
    );

/**
    Sets the number of retries that should be attempted if
    an attempt to obtain a modify lock is blocked by another user.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_retry_count(
    int    count    /**< (I) Number of retries that should be attempted */
    );

/**
    Returns the number of retries that should be attempted if
    an attempt to obtain a modify lock is blocked by another user.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_retry_count(
    int    *count    /**< (O) Number of retries that should be attempted */
    );

/**
    Sets the time used as the basis for the retry interval.
    The actual length of time waited between retries will depend upon the timeout strategy.
    See #POM_set_env_info( #POM_timeout_strategy ).
    This function is equivalent to using #POM_set_env_info( #POM_timeout_interval ).

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_retry_interval(
    int    retry_interval   /**< (I) Base time in seconds to wait between retries */
    );

/**
    Returns an ordered list of all the values that the specified attribute takes for database instances
    (with duplicate values removed from this list).

    For example, if the class_id is "User" and the attr_id is "user_name,"
    this function returns a list of all the user names in the database.

    <br> Supports rollback using markpoints: YES.
*/

POMAPI int POM_ask_domain_of_logical(
    tag_t       class_id,   /**< (I) Tag of the class */
    tag_t       attr_id,    /**< (I) Tag of the attribute for which the domain is to be found */
    int*        n_values,   /**< (O) Number of unique values found for this attribute */
    logical**   values      /**< (OF) n_values Array of values */
    );

/**
    Returns an ordered list of all the values that the specified attribute takes for database instances
    (with duplicate values removed from this list).

    For example, if the class_id is "User" and the attr_id is "user_name,"
    this function returns a list of all the user names in the database.

    <br> Supports rollback using markpoints: YES.
*/

POMAPI int POM_ask_domain_of_char(
    tag_t       class_id,   /**< (I) Tag of the class */
    tag_t       attr_id,    /**< (I) Tag of the attribute for which the domain is to be found */
    int*        n_values,   /**< (O) Number of unique values found for this attribute */
    char**      values      /**< (OF) n_values Array of values */
    );

/**
    Returns an ordered list of all the values that the specified attribute takes for database instances
    (with duplicate values removed from this list).

    For example, if the class_id is "User" and the attr_id is "user_name,"
    this function returns a list of all the user names in the database.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_domain_of_int(
    tag_t  class_id,    /**< (I) Tag of the class */
    tag_t  attr_id,     /**< (I) Tag of the attribute for which the domain is to be found */
    int*   n_values,    /**< (O) Number of unique values found for this attribute */
    int**  values       /**< (OF) n_values Array of values */
    );

/**
    Returns an ordered list of all the values that the specified attribute takes for database instances
    (with duplicate values removed from this list).

    For example, if the class_id is "User" and the attr_id is "user_name,"
    this function returns a list of all the user names in the database.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_domain_of_double(
    tag_t       class_id,   /**< (I) Tag of the class */
    tag_t       attr_id,    /**< (I) Tag of the attribute for which the domain is to be found */
    int*        n_values,   /**< (O) Number of unique values found for this attribute */
    double**    values      /**< (OF) n_values Array of values */
    );

/**
    Returns an ordered list of all the values that the specified attribute takes for database instances
    (with duplicate values removed from this list).

    For example, if the class_id is "User" and the attr_id is "user_name,"
    this function returns a list of all the user names in the database.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_domain_of_date(
    tag_t       class_id,   /**< (I) Tag of the class */
    tag_t       attr_id,    /**< (I) Tag of the attribute for which the domain is to be found */
    int*        n_values,   /**< (O) Number of unique values found for this attribute */
    date_t**    values      /**< (OF) n_values Array of values */
    );

/**
    Returns an ordered list of all the values that the specified attribute takes for database instances
    (with duplicate values removed from this list).

    For example, if the class_id is "User" and the attr_id is "user_name,"
    this function returns a list of all the user names in the database.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_domain_of_string(
    tag_t       class_id,   /**< (I) Tag of the class */
    tag_t       attr_id,    /**< (I) Tag of the attribute for which the domain is to be found */
    int*        n_values,   /**< (O) Number of unique values found for this attribute */
    char***     values      /**< (OF) n_values Array of values */
    );

/**
    Returns an ordered list of all the values that the specified attribute takes for database instances
    (with duplicate values removed from this list).

    For example, if the class_id is "User" and the attr_id is "user_name,"
    this function returns a list of all the user names in the database.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_domain_of_tag(
    tag_t       class_id,   /**< (I) Tag of the class */
    tag_t       attr_id,    /**< (I) Tag of the attribute for which the domain is to be found */
    int*        n_values,   /**< (O) Number of unique values found for this attribute */
    tag_t**     values      /**< (OF) n_values Array of values */
    );

/**
    Sets the name of the supplied group to the given name.
    The user must either be a Teamcenter system administrator or
    the group administrator for the given group. Also refer to #SA_set_group_name2.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_group_name(
    tag_t           group,      /**< (I) Tag of group */
    const char*     name        /**< (I) Name to be given to the supplied group */
    );

/**
    Sets the privilege attribute of the supplied group to be the specified value (0 or 1).
    When set to "1" any user logging into the specified group will have system administrator privileges.
    When set to "0" any user logging into the specified group will only have the rights of an "ordinary" user.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_group_privilege(
    tag_t  group,       /**< (I) Tag of group */
    int    privilege    /**< (I) Privilege (value) attribute of the supplied group */
    );

/**
    Sets the user attribute of the specified member instance to be the supplied user tag.

    Both the member and the user must be loaded. The current user (the person logged in)
    must either be a Teamcenter system administrator or
    the group administrator of the given group.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_member_user(
    tag_t  member,  /**< (I) Tag of member */
    tag_t  user     /**< (I) Tag of user */
    );

/**
    Sets the group attribute of the specified member instance to be the supplied group tag.

    Both the member and the user must be loaded. The current user (the person logged in)
    must either be a Teamcenter system administrator or
    the group administrator of the group referenced from the member
    as well as the group administrator of the specified group.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_member_group(
    tag_t  member,  /**< (I) Tag of member */
    tag_t  group    /**< (I) Tag of group */
    );

/**
    Sets the group administrator attribute for the supplied group to be the specified value.

    The member must be loaded.
    The current user must either be a Teamcenter system administrator or
    the group administrator for the given group.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_member_is_ga(
    tag_t       member,     /**< (I) Tag of member */
    logical     is_ga       /**< (I) Value for the ga attribute */
    );

/**
    Returns the node type and name for the DB server.

    @note This is not necessarily the node upon which the RDBMS server processes are located.
    The information is recorded when the Teamcenter system is installed.
    Node types recognized are defined in pom_tokens.h.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_server_info(
    int*   node_type,   /**< (O) ID for one of the node types supported (see pom_tokens.h) */
    char** node_name    /**< (OF) Name of the node from which the DB was installed */
    );

/**
    Finds the index of the first occurrence of the given value in an attribute.
    @note If the given value is not found returns values_index = -1.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_index_of_logical(
    tag_t       instance_tag,   /**< (I) Tag of instance */
    tag_t       attr_id,        /**< (I) Attribute ID */
    logical     value,          /**< (I) Value to search for in the given attribute for
                                        the given instance of the type appropriate for the attribute */
    int*        values_index    /**< (O) Index into attribute at which the given value or NULL value was found */
    );

/**
    Finds the index of the first occurrence of the given value in an attribute.
    @note If the given value is not found returns values_index = -1.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_index_of_char(
    tag_t  instance_tag,    /**< (I) Tag of instance */
    tag_t  attr_id,         /**< (I) Attribute ID */
    char   value,           /**< (I) Value to search for in the given attribute for
                                    the given instance of the type appropriate for the attribute */
    int*   values_index     /**< (O) Index into attribute at which the given value or NULL value was found */
    );

/**
    Finds the index of the first occurrence of the given value in an attribute.
    @note If the given value is not found returns values_index = -1.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_index_of_int(
    tag_t  instance_tag,    /**< (I) Tag of instance */
    tag_t  attr_id,         /**< (I) Attribute ID */
    int    value,           /**< (I) Value to search for in the given attribute for
                                    the given instance of the type appropriate for the attribute */
    int*   values_index     /**< (O) Index into attribute at which the given value or NULL value was found */
    );

/**
    Finds the index of the first occurrence of the given value in an attribute.
    @note If the given value is not found returns values_index = -1.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_index_of_double(
    tag_t  instance_tag,    /**< (I) Tag of instance */
    tag_t  attr_id,         /**< (I) Attribute ID */
    double value,           /**< (I) Value to search for in the given attribute for
                                    the given instance of the type appropriate for the attribute */
    int*   values_index     /**< (O) Index into attribute at which the given value or NULL value was found */
    );

/**
    Finds the index of the first occurrence of the given value in an attribute.
    @note If the given value is not found returns values_index = -1.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_index_of_date(
    tag_t  instance_tag,    /**< (I) Tag of instance */
    tag_t  attr_id,         /**< (I) Attribute ID */
    date_t value,           /**< (I) Value to search for in the given attribute for
                                    the given instance of the type appropriate for the attribute */
    int*   values_index     /**< (O) Index into attribute at which the given value or NULL value was found */
    );

/**
    Finds the index of the first occurrence of the given value in an attribute.
    @note If the given value is not found returns values_index = -1.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_index_of_string(
    tag_t           instance_tag,   /**< (I) Tag of instance */
    tag_t           attr_id,        /**< (I) Attribute ID */
    const char*     value,          /**< (I) Value to search for in the given attribute for
                                            the given instance of the type appropriate for the attribute */
    int*            values_index    /**< (O) Index into attribute at which the given value or NULL value was found */
    );

/**
    Finds the index of the first occurrence of the given value in an attribute.
    @note If the given value is not found returns values_index = -1.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_index_of_tag(
    tag_t  instance_tag,    /**< (I) Tag of instance */
    tag_t  attr_id,         /**< (I) Attribute ID */
    tag_t  value,           /**< (I) Value to search for in the given attribute for
                                    the given instance of the type appropriate for the attribute */
    int*   values_index     /**< (O) Index into attribute at which the given value or NULL value was found */
    );

/**
    Finds the index of the first occurrence of a NULL in an attribute.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_index_of_null(
    tag_t  instance_tag,    /**< (I) Tag of instance */
    tag_t  attr_id,         /**< (I) Attribute ID */
    int*   values_index     /**< (O) Index into attribute at which the given value or NULL value was found */
    );

/**
    Finds the current lock type (#POM_no_lock, #POM_read_lock, #POM_modify_lock, or #POM_delete_lock).

    @note This API examines only the current session's locks and returns the lock type for any lock currently held.
    This API does not examine locks held by other sessions.

    @returns
    <ul>
    <li>#POM_ok on success
    <li>#POM_inst_not_loaded if @p instance is not loaded.
    <li>#POM_inst_newly_created if @p instance is newly created.
    </ul>

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_instance_lock(
    tag_t  instance,    /**< (I) Tag of the instance */
    int*   lock_token   /**< (O) Lock type held on the instance, by the current session (see pom_tokens.h) */
    );

/**
    Finds the current lock type (#POM_no_lock, #POM_read_lock, #POM_modify_lock, or #POM_delete_lock)
    for each instance passed.

@returns
    <ul>
    <li>#POM_ok on success
    <li>#POM_inst_not_loaded if an instance is not loaded
    <li>#POM_inst_newly_created if the instance is newly created (and therefore not locked)
    </ul>

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_instances_locks(
    int     n_instances,        /**< (I) Number of instances. */
    const   tag_t* instances,   /**< (I) n_instances Instances to find lock tokens for. */
    int   **lock_token          /**< (OF) n_instances Lock type held on each instance (see pom_tokens.h) */
    );

/**
    Returns the tag of the IMC object for the given site..

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_lookup_imc(
    int    site_id,     /**< (I) */
    tag_t* imc          /**< (O) */
    );

/**
    Indicates whether or not this object is a local cache.
    An object is counted as a cache if its master copy resides at a different IMC.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_is_cached(
    tag_t       instance,   /**< (I) Tag of the object */
    logical*    is_cached   /**< (O) Indication of whether or not the object is cached */
    );

/**
    Get owning site for an object.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_location_of_instance(
    tag_t  instance,    /**< (I) Tag of object */
    tag_t* location     /**< (O) Tag of owning site */
    );

/**
    Sets the owning site of an object.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_instance_location(
    tag_t  instance,    /**< (I) Tag of object */
    tag_t  location     /**< (I) Tag of owning site */
    );

/**
    Regenerates the schema files based on information in the database.
        Typically schema file needs to be updated after schema changes are made in the database.

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_regen_schema_file(
    const char*     initial_user,       /**< (I) Name of user */
    const char*     initial_password,   /**< (I) Password of user */
    const char*     initial_group       /**< (I) Group of user */
    );

/**
    Create a file in POM cache.
    Objects can be added to this file and then #POM_write_file can be used to write the file to disk.
    @note the input parameter application and version is for the caller to store auxiallary information.
    The application input parameters isnt related to any POM application.

    @see POM_file_add_instance

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_create_file(
    const char*     application,    /**< (I) Name of application */
    int             version,        /**< (I) Version of application */
    tag_t*          file            /**< (O) Tag of file created */
    );

/**
    A file written using #POM_write_file can be read back into POM cache using this API.
    @see #POM_file_view_instance #POM_file_recover_instance #POM_unload_file

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_read_file(
    const char*     pathname,       /**< (I) */
    char**          application,    /**< (OF) */
    int*            version,        /**< (O) */
    tag_t*          file            /**< (O) */
    );

/**
    Write the input POM file to the supplied disk location.

    The OS projection flags to be supplied during writing file can be three and four-digit octal numbers representing modes.
    With three-digit octal notation, each numeral represents a different component of the permission set: user class, group class, and "others" class respectively.
    For example, "-rwxr-xr-x" would be represented as 755 in three-digit octal.
    For more information about modes visit http://en.wikipedia.org/wiki/File_system_permissions#Octal_notation

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_write_file(
    tag_t           file,           /**< (I) Tag of file */
    const char*     pathname,       /**< (I) Full path name of the file */
    int             os_protection   /**< (I) Three or four digit octal numbers representing modes. */
    );

/**
    Unloads a file from POM cache.
    @see POM_read_file

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_unload_file(
    tag_t  file     /**< (I) */
    );

/**
    Sets the destination site for file.

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_file_set_destination(
    tag_t  file,            /**< (I) */
    tag_t  destination      /**< (I) */
    );

/**
    Gets the destination site for the file.

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_file_ask_destination(
    tag_t  file,            /**< (I) */
    tag_t* destination      /**< (O) */
    );

/**
    Adds an object to a POM file.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_add_instance(
    tag_t  file,        /**< (I) Tag of file */
    tag_t  instance     /**< (I) Tag of object */
    );

/**
    Add an unsaved instance to a POM file.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_add_unsaved_instance(
    tag_t  file,        /**< (I) Tag of file */
    tag_t  instance     /**< (I) Tag of an unsaved object */
    );

/**
    Verifies the instance in the file.
    Any issues are reported as error.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_view_instance(
    tag_t  file,        /**< (I) */
    tag_t  instance     /**< (I) */
    );

/**
    Updates the database with the object in the file.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_recover_instance(
    tag_t  file,        /**< (I) Tag of file */
    tag_t  instance     /**< (I) Tag of object from file to be updated in database */
    );

/**
    Returns the number of objects in a POM file.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_ask_contents(
    tag_t       file,           /**< (I) Tag of file */
    int*        n_instances,    /**< (O) Count of instances */
    tag_t**     instances       /**< (OF) n_instances  Array of tag of objects */
    );

/**
    Returns if the inputs instance is included in the file.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_is_included(
    tag_t       file,           /**< (I) */
    tag_t       instance,       /**< (I) */
    logical*    is_included     /**< (O) */
    );

/**
    Returns true if the object has been already recovered from the file.
    @see #POM_file_recover_instance

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_is_recovered(
    tag_t       file,           /**< (I) Tag of file */
    tag_t       instance,       /**< (I) Tag of object */
    logical*    is_recovered    /**< (O) returns true if object is already recovered */
    );

/**
    Adds to a list of selected instances in a file.
    USe #POM_file_ask_selected to know the selected instances.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_select_instance(
    tag_t  file,        /**< (I) Tag of file */
    tag_t  instance     /**< (I) Tag of object */
    );

/**
    Returns an array of selected instances.
    Specific instances can be selected using #POM_file_select_instance API.
    When a file is unloaded, the selected instances are cleared.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_ask_selected(
    tag_t       file,           /**< (I) Tag of file */
    int*        n_instances,    /**< (O) Count of selected instances */
    tag_t**     instances       /**< (OF) n_instances Selected instances */
    );

/**
    For a POM file a destination site can be set using #POM_file_set_destination.
    After the destination site is set, this API helps setting the owning site of the
    input object in the file to be the destination site.

    @see #POM_file_set_destination

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_transfer_instance(
    tag_t  file,        /**< (I) Tag of file */
    tag_t  instance     /**< (I) Tag of object */
    );

/**
    Set additional information about instances in a file.
    @see POM_file_ask_data

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_set_data(
    tag_t  file,        /**< (I) Tag of file */
    tag_t  class_id,    /**< (I) Tag of class */
    tag_t  instance,    /**< (I) Tag of object in the file */
    int    n_values,    /**< (I) Count of values */
    char** values       /**< (I) n_values Array of string values */
    );

/**
    Get additional information set for an instance in a file.
    @see POM_file_set_data

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_ask_data(
    tag_t       file,       /**< (I) Tag of file */
    tag_t       class_id,   /**< (I) Tag of class */
    tag_t       instance,   /**< (I) Tag of object */
    int*        n_values,   /**< (O) Count of values */
    char***     values      /**< (OF) n_values Array for string values */
    );

/**
    Replaces an object in a POM file.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_replace_tag(
    tag_t  file,                /**< (I) Tag of file */
    tag_t  original_tag,        /**< (I) Tag of object in the file to be replaced */
    tag_t  replacement_tag      /**< (I) Tag of the replacement object */
    );

/**
    Typically when an object is recovered from a POM file, its internal unique identifer is used to find the object in database.
    In some scenarios the application may want to use some other attributes to find the object.
    This API enables setting attributes as candidate keys which can be used to find the object in database during recovery.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_set_candidate_key(
    tag_t           pom_file,       /**< (I) Tag of file */
    tag_t           instance,       /**< (I) Tag of object */
    int             n_attributes,   /**< (I) Count of attributes */
    const tag_t*    attributes      /**< (I) n_attributes Array of tag of attributes */
    );

/**
    Returns the string values candidate keys set in the POM file.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_ask_candidate_keys(
    tag_t       pom_file,           /**< (I) Tag of file */
    int*        n_key_strings,      /**< (O) Count of candidate strings  */
    char***     key_strings         /**< (OF) n_key_strings */
    );

/**
    A POM file refers to a file which contains information about the schema for the file.
    This file is referred as the transmit file.
    This APIs helps getting path of transmit file from a POM file.

    @see POM_write_transmit_file

    <br> Supports rollback using markpoints: YES.
*/

POMAPI int POM_file_ask_xmit_file(
    const char*     pathname,   /**< (I) Full path of file wrttien via POM */
    char**          xmitname    /**< (OF) Full path of the transmit file */
    );

/**
    Writes the transmit file.
    The file is written to the path set in the environment variable #POM_transmit_directory .
    @see #POM_set_env_info

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_write_transmit_file( void );

/**
    This API helps adding some additional information about stubs in the file.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_set_stub_data(
    int                 n_entries,  /**< (I) Count of entries */
    tag_t*              tags,       /**< (I) n_entries Array of tags of stubs */
    char**              names,      /**< (I) n_entries Array of attribute names*/
    char**              values      /**< (I) n_entries Array of values of the attributes */
    );

/**
    Performs a copy that will copy attribute settings from one instance to another instance of the same class.
    This avoids the need to read each attribute and set the corresponding attribute in the target instance.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_copy_over(
    tag_t  source,      /**< (I) Instance to copy from */
    tag_t  target       /**< (I) Instance to copy the values into */
    );

/**
    Allocates a new tag value.

    <br> Supports rollback using markpoints: NO.
*/

POMAPI int POM_allocate_tag(
    tag_t* new_tag      /**< (O) Value of tag allocated */
    );

/**
    Finds the generic accessor instance that represents the combination of the instances supplied in instances.
    For example, "role in group" is represented by a pair of tags of a role and a group.
    If this combination already exists then the tag of that instance is returned in accessor.
    Otherwise, an instance is created.
    The instances must be of different class as the order of storage is based upon a sort by class.
    This allows efficient querying and non-duplication when presented with the same set of tags in different orders.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_find_accessor(
    int             n_instances,    /**< (I) Number of tags represented in accessor */
    const tag_t*    instances,      /**< (I) n_instances Tags of the accessor */
    tag_t*          accessor        /**< (O) Accessor instance */
    );

/**
    Returns the tag associated with a POM accessor;
    refreshes the accessor instance (therefore it need not be loaded for this call).

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_accessor_instances(
    tag_t       accessor,       /**< (I) Accessor instance */
    int*        n_instances,    /**< (O) Number of tags represented in accessor */
    tag_t**     instances       /**< (OF) n_instances Tags of the accessor */
    );

/**
    Deletes the POM accessor of the given tag.

    @note AM does not reference the POM instances via a POM attribute,
    so there is not referential integrity associated with this instance.
    Naturally any ACL referring to a deleted instance in POM will not be
    usable for obtaining access to the ACL'd instance.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_delete_accessor(
    tag_t  accessor     /**< (I) Accessor instance */
    );

/**
    Sets the creation date in a POM application object.
    This is intended to be used in upgrade programs that wish to retain audit info.
    This is only callable by a Teamcenter system administrator.
    If the creation date has not been set at the point that it is saved, then it will be automatically set.

    Note on use with versionable instances:
    In general it only makes sense to call POM_set_creation_date on an unsaved first version, but
    in theory (e.g., if you wanted to correct a previously incorrect value) you could set the
    creation date on an existing instance, in which case it would follow the usual rules and hence
    only update latest, leaving historical versions with the previous value.

    This function accepts the date in local time and must be later than minimum specified
    by POM_ask_earlier_date (currently 2nd Jan 1900).

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_creation_date(
    tag_t  instance,        /**< (I) Instance in which to set the creation date */
    date_t creation_date    /**< (I) New date to be set in instance */
    );

/**
Sets the creation date using the GMT instead of the local time (as #POM_set_creation_date does).

<br> Supports rollback using markpoints: YES.

@returns
<ul>
<li>#POM_ok on success
<li>#POM_insufficient_privilege if a non-privileged user tries to reset a creation date
</ul>
*/
POMAPI int POM_set_creation_utc_date(
    tag_t  instance,        /**< (I) Instance in which to set the creation date */
    date_t creation_date    /**< (I) New date to be set in instance */
    );

/**
    Sets the modification date in a POM application object.
    This is intended to be used in upgrade programs that wish to retain audit info.
    This is only callable by a Teamcenter system administrator.

    @note By default, the POM will automatically update the modification date
    (and last modifying user) so upgrade programs that set these fields themselves should use
    #POM_set_env_info to set #POM_bypass_attr_update in order to avoid the automatic update.
    Note that this flag must be set to FALSE to avoid the last modification date being
    updated when you save the instance.

    This function accepts the date in local time and must be later than minimum specified
    by POM_ask_earlier_date (currently 2nd Jan 1900).

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_modification_date(
    tag_t  instance,            /**< (I) Instance in which to set the last-mod-date */
    date_t modification_date    /**< (I) New date to be set in instance */
    );

/**
Sets the modification date using the GMT instead of the local time (as #POM_set_modification_date does).

<br> Supports rollback using markpoints: YES.

@returns
<ul>
<li>#POM_ok on success
<li>#POM_insufficient_privilege if a non-privileged user tries to set a modification date
</ul>
*/
POMAPI int POM_set_modification_utc_date(
    tag_t  instance,            /**< (I) Instance in which to set the last-mod-date */
    date_t modification_date    /**< (I) New date to be set in instance */
    );

/**
    Sets the last modifying user in a POM application object.
    This is intended to be used in upgrade programs that wish to retain audit info.
    This is only callable by a Teamcenter system administrator.

    @note By default the POM will automatically update the last modifying user
    (and modification date) so upgrade programs that set these fields themselves should use
    #POM_set_env_info to set #POM_bypass_attr_update to avoid the automatic update.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_modification_user(
    tag_t  instance,              /**< (I) Instance in which to set the archive date/info or
                                        set the archive date/info to null or to modify */
    tag_t  modification_user      /**< (I) New user to be set in instance */
    );

/**
    Tests that an instance is a valid instance.
    <br/>This is useful when using #POM_no_lock on loaded data,
    since "no lock" implies no referential integrity
    other sessions can delete data that is loaded via #POM_no_lock.
    <br/>Note that a stub "exists" so you can reference a non-local object,
    but when you load one you will get a POM_inst_not_local error.
    <br/>Verdict will be true for the following cases:
    <ul>
    <li>Newly created but not yet saved instance. No Database trip will be incurred.</li>
    <li>Loaded instance locked with POM_modify_lock or POM_read_lock. No Database trip will be incurred.</li>
    <li>Instance is online (i.e there is a record in POM_object). This will incur a database trip.</li>
    <li>There is a stub record for this object. This will incur a database trip.</li>
    </ul>
    <br/>Verdict will be false if none of the above is true or the tag is configured to a logically deleted versionable instance.
    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_instance_exists(
    tag_t       instance_tag,   /**< (I) Tag of the instance */
    logical*    verdict         /**< (O) True if the instance does exist in the DB */
    );

/**
    Finds the user ID, login date, and node for the user who has a modify lock on the given instance.
    This can be used to give detailed error reports in the event of an attempt to
    modify an instance failing due to #POM_inst_in_use. This function is limited to modify locks,
    as they are exclusive, and does not report any users holding read or "no" locks.

    The information reported is obtained from a class POM_session which is populated upon login
    with information regarding the users: ID, process ID (internal field), login date, and node name.
    This class is not application protected,
    and can be queried or read by the user to determine who is logged into the system.

    The process ID field is private, however, and should not be used.
    Its internal purpose is to find the locks for a given session,
    but its format is unpublished and should not be depended upon, as it may change without notice.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_who_locked_instance(
    tag_t       inst,           /**< (I) Tag of instance to test */
    char**      user_name,      /**< (OF) User found to be locking instance */
    date_t*     login_date,     /**< (O) Date that user logged in */
    char**      node_name       /**< (OF) Node at which that user is logged in */
    );

/**
    Bulk access equivalent of POM_who_locked_instance
    Returned names and date arrays will have NULL entries for non-locked instances

    Returns #POM_ok on success or a POM error indicating the type of failure that occurred.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_who_locked_instances(
    int         n_instances,    /**< (I) count of instance to test */
    tag_t       *insts,         /**< (I) n_instances  Tags of instance to test */
    logical   **is_modify_locked, /**< (OF) n_instances  true if the corresponding instance is locked, false otherwise */
    char***     user_names,       /**< (OF) n_instances   Users found to be locking instance */
    date_t**    login_dates,      /**< (OF) n_instances   Dates that user logged in */
    char***     node_names        /**< (OF) n_instances   Nodes at which that user is logged in */
    );

/**
    When you lock something for modify you expect to be able to save it later.
    However there are a few cases when you might lose your lock.  Attempting to save your object
    after losing the lock will give you an error, but you might want to find out ahead of time.
    Reasons you might lose your lock are:-
        POM_lost_lock_session_gone
            The database is shut down and restarted (without you connected) and then someone else wants your
            lock, so they assume your process had crashed and gone away, so claim your lock.
        POM_lost_lock_session_gone
            Someone runs clearlocks in the same circumstances.
        POM_lost_lock_session_killed
            Someone runs clearlocks assert dead and asserts your session to be dead.
        POM_lost_lock_stolen
            Someone with SA privilege asserts his right to steal your lock.
        POM_lost_lock_dont_know
            The lock has gone, but the auditing tables have not been installed
    This function will return POM_ok even if it finds some locks missing.

    <br> Supports rollback using markpoints: YES.
*/

POMAPI int POM_look_for_lost_locks(
    int *       n_lost,         /**< (O) Number of my locks that are now missing */
    tag_t **    lost,           /**< (OF) n_lost Objects that have lost their locks */
    int **      why,            /**< (OF) n_lost Reasons the locks were lost */
    char ***    who             /**< (OF) n_lost Strings to describe the session that stole the lock */
    );

/**
    Updates the backup date attribute in the given instance.
    This attribute cannot be directly updated via #POM_set_attr_date due to application protection.
    This function allows the update, but only for system administrators.

    <b>Restrictions:</b>

    You must be a Teamcenter system administrator to use this function
    (since you are updating audit trail information).

    @note This function accepts the date in local time and must be later than minimum specified
    by POM_ask_earlier_date (currently 2nd Jan 1900).

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_backup_date(
    tag_t  instance,    /**< (I) */
    date_t backup_date  /**< (I) */
    );

/**
    Get current session.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_session(
    tag_t* session  /**< (O) Tag of current session */
    );

/**
    Returns the token value for input token name.
    For example, when the input name "POM_is_unique" is supplied,
    this function will provide the token #POM_is_unique.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_string_to_token(
    const char*     string,     /**< (I) */
    int*            token       /**< (O) */
    );

/**

    This API provides information about any schema changes related to the instances
    in the file.

    Apart from names of classes which are different, information about whether the class has been
    removed (#POM_conv_class_removed) or changed (#POM_conv_class_changed).

    @see #POM_file_ask_conv_attr_info

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_ask_conv_class_info(
    tag_t       file,       /**< (I) Tag of file */
    int*        count,      /**< (O) Count of classes*/
    char***     classes,    /**< (OF) count Array of classes */
    int**       states      /**< (OF) count Array of class state. Valid values are #POM_conv_class_changed or #POM_conv_class_removed */
    );

/**
    This API provides information about schema changes related to the instances
    in the file.

    #POM_file_ask_conv_class_info returns information about classes that are different.
    This API returns some more information about particular classes and which attributes
    are new (#POM_conv_attr_new) or removed (#POM_conv_attr_removed).

    @see #POM_file_ask_conv_class_info

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_file_ask_conv_attr_info(
    tag_t           file,           /**< (I) Tag of file */
    const char*     class_name,     /**< (I) Name of class */
    int*            count,          /**< (O) Count of attributes */
    char***         attrs,          /**< (OF) count Array of attribute names */
    int**           states          /**< (OF) count Array of attribute states. Valid values are #POM_conv_attr_new or #POM_conv_attr_removed. */
    );

/**
    Sets the owning user of an object.

    <br> Supports rollback using markpoints: YES.
*/

POMAPI int POM_set_owning_user(
    tag_t  instance,    /**< (I) Tag of object */
    tag_t  user         /**< (I) Tag of user */
    );

/**
    Sets the owning group of an object.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_owning_group(
    tag_t  instance,    /**< (I) Tag of object */
    tag_t  group        /**< (I) Tag of group */
    );

/**
    Returns the valid groups for the user.

    if Access manager mode is set to #AM_MODE_ALL_GROUPS then all the groups
    where the user is an active member are returned. Otherwise the current group is returned.

    @see #AM_set_mode

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_authenticated_groups(
    int*        n_groups,   /**< (O) */
    tag_t**     groups      /**< (OF) */
    );

/**
    Given an array of strings, this API copies them into a  contiguous memory block.
    The output array of packed strings can be accessed similar to input array of unpacked strings.
    The packed representation can be freed with a single #MEM_free call.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_pack_strings(
    int         n_strings,          /**< (I) Count of strings */
    char**      strings,            /**< (I) n_string Array of unpacked strings */
    char***     packed_strings      /**< (OF) Packed string array */
    );

/**
    Returns the accessor information for users.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_users_accessors(
    int         n_user_accs,    /**< (I) Count of users */
    tag_t*      user_accs,      /**< (I) n_user_accs Array of tag of users */
    int*        n_accessors,    /**< (O) Count of accessors */
    tag_t**     accessors       /**< (OF) n_accessors Array of tag of accessors */
    );

/**
    Sets the owning user and group on a list of objects.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_owners(
    int    n_instances,     /**< (I) Count of objects */
    tag_t* instances,       /**< (I) n_instances Array of tag of objects */
    tag_t  owning_user,     /**< (I) Tag of user */
    tag_t  owning_group     /**< (I) Tag of group */
    );

/**
    Verifies if the input error code is the last error encountered in POM.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_acknowledge_error(
    int    error_code   /**< (I) POM error code */
    );

/**
    Find all groups satisfying the input pattern in the sub-tree rooted at
  input root group.

  The pattern may be:
      null or "", meaning "any group"
      simple, e.g. "a" or "a", meaning "any group of this name"
      compound e.g. "a.b.c" or "a..c", meaning "any group of this full name"
          (relative to the root_group) (with the special case of "a." meaning
          "any root group of this name").
  The root group may be null_tag, meaning "look in the whole group tree".

  <br> Supports rollback using markpoints: YES.
 */

POMAPI int POM_find_h_groups(
    const char*     group_pattern,  /**< (I) Group search pattern. */
    tag_t           root_group,     /**< (I) Tag of root group */
    int*            n_groups,       /**< (O) Count of groups returned */
    tag_t**         groups          /**< (OF) n_groups Array of tag of groups */
    );

/**
    Returns if a group is a sub-group of the input group.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_is_sub_group(
    tag_t       group,      /**< (I) Tag of parent group */
    tag_t       sub_group,  /**< (I) Tag of sub-group */
    logical*    answer      /**< (O) */
    );

/**
    Creates a new group and add it as a sub-group in the input parent group.

    <b>Restrictions:</b>
    You must be logged in as a System Administrator to use this function.

    <br> Supports rollback using markpoints: YES.
*/

POMAPI int POM_new_h_group(
    const char*     name,           /**< (I) Name of group */
    int             privilege,      /**< (I) Group Privilege (1 for system admin group else 0 ) */
    tag_t           parent_group,   /**< (I) Tag of parent group */
    tag_t*          new_group       /**< (O) Tag of created group */
    );

/**
    Initializes a group object.

    <b>Restrictions:</b>
    You must be logged in as a System Administrator to use this function.

    <br> Supports rollback using markpoints: YES.
*/

POMAPI int POM_init_h_group(
    tag_t           group,          /**< (I) Tag of group */
    const char*     name,           /**< (I) Name of group */
    int             privilege,      /**< (I) Group Privilege (1 for system admin group else 0 ) */
    tag_t           parent_group    /**< (I) Tag of parent group */
    );

/**
    Sets the parent group for a group.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_set_group_parent(
    tag_t  group,   /**< (I) Tag of group */
    tag_t  parent   /**< (I) Tag of parent group */
    );

/**
    Returns the name of a group. Name is a full hierarchical group to the group tag given.
    The format of the name is �<group-name>.<super-group>.<root-group-name>� with as many �super-group�
    names as the hierarchy involves between the given tag and the root (where parent group is null_tag).

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_ask_group_name(
    tag_t  group,   /**< (I) Tag of group */
    char** name     /**< (OF) Name of group */
    );


/**
    Load all instances of input class.
    Note: This should only be used when you are loading instances of a class that have small population.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_load_class_extent
  (
    const char *                aclass,                /**< (I) Name of class */
    int *                       n_instances,           /**< (O) count of objects */
    tag_t **                    instances,             /**< (OF) n_instances Array of tag of objects */
    int                         lock_type              /**< (I) Only POM_no_lock lock_type is supported by this function. */
    );

/**
    Create a functional index.

    <br> Supports rollback using markpoints: NO.
*/
POMAPI int POM_define_func_index
  ( const char *                index_name,            /**< (I) Name of functional index */
    tag_t                       class_id,              /**< (I) Tag of class*/
    int                         n_attrs,               /**< (I) Count of attribute identifiers */
    const tag_t *               attr_ids,              /**< (I) n_attrs Array of tag of attribute identifiers */
    logical                     is_unique,             /**< (I) Flag whether index stores unique values */
    const char *                expr                   /**< (I) Function to apply on the attributes. For example, #POM_index_func_upper or #POM_index_func_substr */
  );

/**
    Returns information about a index created for a class.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_describe_class_index
  ( const char *                index_name,            /**< (I) Name of index */
    tag_t                       class_id,              /**< (I) Tag of class */
    int *                       n_attrs,               /**< (O) Count of attribute identifiers */
    tag_t **                    attr_ids,              /**< (OF) n_attrs Array of tag of attribute identifiers */
    int **                      pos,                   /**< (OF) */
    char ***                    expr                   /**< (OF) */
  );

/**
    Load instances via a query.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_load_instances_possible_by_enquiry
  ( const char *                enq_id,                /**< (I) Name of the enquiry */
    const char *                class_name,            /**< (I) Name of the class */
    int *                       n_instances,           /**< (O) Count of loaded objects */
    tag_t **                    instances,             /**< (OF) n_instances Array of tag of loaded objects */
    int *                       n_failures,            /**< (O) Count of objects that satisy the query but couldnt be loaded */
    tag_t **                    failed_instances       /**< (OF) n_failures Array of tag of objects that satisfy the query but couldnt be loaded */
  );

/**
   Retrieves the earliest valid date in POM for the local time zone.

    <br/> Supports rollback using markpoints: YES.

    @returns
    <ul>
    <li>#POM_ok on success
    <li>#POM_invalid_value if @p value is a null pointer.
    </ul>
*/
POMAPI int POM_get_earliest_date
  ( date_t *                    value                  /**< (O) Earliest date value in the local time zone */
  );

/**
    Retrieves the earliest valid date in POM in UTC.

    <br/> Supports rollback using markpoints: YES.

    @returns
    <ul>
    <li>#POM_ok on success
    <li>#POM_invalid_value if @p value is a null pointer.
    </ul>
*/
POMAPI int POM_get_earliest_utc_date
  ( date_t *                    value                  /**< (O) Earliest date value in UTC */
  );

/**
    Retrieves true if the specified local time-zone date @p value
    is possibly an earliest date value otherwise returns false.
    <br/> For historical reasons the POM_ask_earliest_date()
    value might possibly have been stored in the database in a
    range of date-time values between 1900 01 01 00:00:00 UTC
    and 1900 01 03 00:00:00 UTC, not including the end points.
    Output value is true if the specified date
    is between these two date-time values otherwise it
    is false.

    <br/> Supports rollback using markpoints: YES.

    @returns
    <ul>
    <li>#POM_ok always
    </ul>

*/
POMAPI int POM_is_possible_earliest_date
  ( const date_t    *value,        /**< (I) Local time-zone date to be checked for possible earliest date */
    logical         *result        /**< (O) True if @p value is an earliest date value, otherwise false  */
  );

/**
    Retrieves true if the specified UTC date @p value
    is possibly an earliest date value otherwise returns false.
    <br/> For historical reasons the POM_ask_earliest_date()
    value might possibly have been stored in the database in a
    range of date-time values between 1900 01 01 00:00:00 UTC
    and 1900 01 03 00:00:00 UTC, not including the end points.
    Output value is true if the specified date
    is between these two date-time values otherwise it
    is false.

    <br/> Supports rollback using markpoints: YES.

    @returns
    <ul>
    <li>#POM_ok always
    </ul>

*/
POMAPI int POM_is_possible_earliest_utc_date
  ( const date_t    *value,        /**< (I) UTC date to be checked for possible earliest date */
    logical         *result        /**< (O) True if @p value is an earliest date value, otherwise false  */
  );

/**
    Retrieves the latest (maximum) valid date in POM for the local time zone.

    <br/> Supports rollback using markpoints: YES.

    @returns
    <ul>
    <li>#POM_ok on success
    <li>#POM_invalid_value if @p value is a null pointer.
    </ul>
*/
POMAPI int POM_get_latest_date
  ( date_t *                    value                  /**< (O) Latest date value for the local time zone */
  );

/**
    Retrieves the latest (maximum) valid date in POM in UTC.

    <br/> Supports rollback using markpoints: YES.

    @returns
    <ul>
    <li>#POM_ok on success
    <li>#POM_invalid_value if @p value is a null pointer.
    </ul>
*/
POMAPI int POM_get_latest_utc_date
  ( date_t *                    value                  /**< (O) Latest date value in UTC */
  );

/**
    Gives a count of the number of active sessions currently connected to the database
    For each session gives some text that describes the session.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_list_connected_sessions(
    int *count,         /**< (O) */
    char ***descriptors /**< (OF) */
    );

/**
    (Does not need a prior POM_init call)
    Attempts to connect to the database and returns state:
    <ul>
    <li>0 - database is present and appears to be installed
    <li>1 - can connect to the database, but it appears not to have POM tables installed
    <li>2 - can't connect to the database
    </ul>

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_is_database_there(
    int *state         /**< (O) */
    );

/**
    Replaces the attribute value for ALL instances of a class.
    This function is not supported on a class storing versionable data except when the attribute name is "object_type".
    This is to support the case of changing the name of a TC type.

    <b>Restrictions:</b>
    You must be logged in as a System Administrator to use this function.

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_replace_string_value
  ( const char *                class_name,           /**< (I) Name of class */
    const char *                attr_name,            /**< (I) Name of attribute */
    const char *                old_str_value,        /**< (I) Old value of attribute */
    const char *                new_str_value,        /**< (I) New value of attribute */
    logical                     match_exact_value     /**< (I) Whether old value should match exactly or not */
  );

/**
    Sets the wild card characters using the input pattern.
    <br>It registers the preference driven wildcards so POM login matches group name using them
    instead of POM�s default.

    <br>Valid values for the input pattern are:
    <ul>
    <li>1: the wild card character '_'
    <li>2: the wild card character '.'
    <li>3: the wild card character '?'
    </ul>

    @returns
    <ul>
    <li>#POM_ok if the input pattern match style is valid and the operation has succeeded.
    <li>#POM_invalid_value if the input pattern match style is invalid.
    </ul>

    <br> Supports rollback using markpoints: YES.
*/
POMAPI int POM_preinit_pattern_match (
    int pattern /**< (I) Input pattern match style */
    );
    
/**
    Gets database information including name, version, and banner.
    @returns
    <ul>
    <li>#POM_ok on success
    <li>Any other errors resulting from Database query
    </ul>
*/
POMAPI int POM_ask_database_info (
    char ** database_name,      /**< (OF) The database type ("Oracle", "SQL Server", etc). */
    char ** database_version,   /**< (OF) The version number ("12.1", "2017", etc). */
    char ** database_banner    /**< (OF) The complete banner information of the database ("Oracle Database 11g Enterprise Edition Release 11.2.0.3.0 - 64bit Production"). */
    );


/**
    Locks the given list of tags for reference to prevent them from been deleted.

    @returns
    <ul>
    <li>#POM_ok on success
    <li>Any other errors resulting from Database query
    </ul>
*/

POMAPI int POM_lock_instances_for_reference (
    unsigned int n_ref_instances,             /**< (I) Number of instances to lock */
    const tag_t * ref_instances,              /**< (I) n_ref_instances Tags of instances to lock */
    unsigned int * n_failed_ref_instances,    /**< (O) Number of instances that failed to lock */
    tag_t ** failed_ref_instances             /**< (OF) n_failed_ref_instances tags that failed to lock */
    );


/**
    Removes the reference lock created on the given list of tags.

    @returns
    <ul>
    <li>#POM_ok on success
    <li>Any other errors resulting from Database query
    </ul>
*/
POMAPI int POM_unlock_reference_instances (
    unsigned int n_ref_instances,  /**< (I) Number of instances to unlock */
    const tag_t * ref_instances    /**< (I) n_ref_instances tags of instances to be unlocked */

    );
    
/**
    @name POM Temporary Table Functions
           
    The POM temporary table interface contains functions for managing and populating temporary tables in 
    Teamcenter.

    <b>Why use a temporary table?</b>

    A temporary tables is used to hold data in a database table for a short time during which it
    can be queried by itself or along with data from other persistent tables in the database. 
    
    Temporary tables are typically used for these reasons:
    <ul>
    <li>Include data in the database for use in queries that is not typically in the database and 
        that doesn't need to be persisted beyond the length a database client session.
    <li>Overcome size limitations in SQL statements.  Sometimes temp tables are used in SELECT statements
        in WHERE IN clauses to avoid maximums on the number of items allowed in a WHERE IN list.  
        Sometimes temp tables are used to avoid limitations on database bind variables.
    <li>Improve performance by avoiding extra DB trips.  This is often a motivation for using temp tables
        in SELECTS within WHERE IN lists or to overcome bind variable limitations.  If
        putting data in a temp table and using it in a WHERE IN list means that the application will 
        execute many fewer SQL statements, then using the temp table may be worthwhile.
    </ul>

    However, there are downsides to using temp tables.  If you are thinking of using a temp table to
    improve performance, you should ask if it really will improve performance.  There is overhead 
    involved in creating a temp table, populating it with data, and disposing of its data, and it is 
    important to be aware of that overhead.  An important question might be, "Will 1 SELECT statment 
    that requires creating a temp table from other data in the database really run faster than multiple 
    SELECT statements or another type of SELECT statment that does not use a temp table?"

    Before deciding to use a temp table consider these alternatives for avoiding the temp table creation, 
    population, and disposal overhead:
    <ul>
    <li>Derived tables.
    <li>Common table expressions (CTEs).
    <li>Subquery factoring (WITH clause).
    <li>Multiple select statements.
    </ul>

    A temp table can be beneficial in a query when the temp table is used to collect data from various
    different sources, for example multiple different tables in the database.  If your data is coming 
    directly from a query, consider using a CTE (common table expression) or a derived table so you can 
    avoid the temp table overhead.


    <b>How to use this interface</b>
    
    The basic tasks in temp table use are
    <ul>
    <li>Create a temp table.
    <li>Populate a temp table.
    <li>Use the temp table.
    <li>Clear its contents.
    </ul>

    You can create a temp table with the #POM_create_table function.  You pass it an application prefix name, 
    a temp table name, definition information about the columns to go in the temp table, and a clear_rows parameter
    that says whether you want the temp table to remain populated until the end of the current transaction or until
    the end of the session with the database.  #POM_create_table returns an actual database table name that you will pass
    to other POM table API functions.  #POM_create_table automatically registers a temp table it creates with Teamcenter
    Enquiry.

    Once the temp table is created you will want to populate it with data.  You can use the table insert functions
    to populate the temp table.
    <ul>
    <li>#Call POM_prepare_table_insert to get ready to insert data.  Pass it an actual table name returned from #POM_create_table 
        and #POM_prepare_table_insert returns an insert handle name.
    <li>Call POM_set_table_insert_<type>_column_vals() to set a column of data on the insert handle.  You pass it an 
        insert handle name and the data that you want to insert into the column.  Call 
        POM_set_table_insert_<type>_column_vals() for each column in the temp table that you want to populate.
    <li>#Call POM_exec_table_insert after all the column data is set in the insert handle to insert the
        data into the temp table the database.
    </ul>

    Once a temp table is populated you can use the temp table in Teamcenter Enquiry.  Since the temp table was registered 
    with Enquiry you can use the temp table's actual table name as a class name in POM Enquiry function calls.

        Note:  Regarding POM_untyped_references, temp tables, and POM Enquiry
        A POM_untyped_reference is a tag.  When you call #POM_set_table_insert_untyped_reference_column_vals to insert
        POM_untyped_references into a temp table you will pass it an array of tag_t.  Puids will be stored in the temp
        table corresponding to those tags.  When POM Enquiry is used to query the temp table, enquiry will check to see 
        that the puid value is a valid reference (unless the "+ no_cpid_lookup" hint is used) and covert the puid value
        to a tag.  The caller wishing to avoid this tag and puid processing should store puid values as character strings 
        instead of using #POM_untyped_reference.
    
    Depending on how a temp table was created, its contents will be cleared at the end of the client database session
    (#POM_logout) or at the end of the current transaction.  If you want to clear a temp table's contents explicitly 
    before either of those times call #POM_clear_table.  You might want to do this if you know you are done with the 
    data and/or you want to repopulate the same temp table with other data.

    Other table API functions
    <ul>
    <li>#POM_generate_table_name generates an actual table name from the table application prefix, the 
        table name, and database vendor specific syntax used in temp table names.
    <li>#POM_get_table_defn_info gets information used to define a table.  This function can be used by applications as
        a debugging aid.
    </ul>

    For more details about these functions see the function descriptions in this file.

    @{
*/

/**
    Generates a name for a table.
    <br/>The caller supplies an application prefix name and a root table name.
    <br/>The application prefix will be prepended to the root table name and this name will be modified
    with db vendor specific additions as needed and returned in the actual_table_name parameter.
    <br/>The purpose of the application prefix is to help prevent table name collisions by providing
    an application namespace that segregates the names of temp tables.  
    <br/>Then each application area can be careful about making sure that its temp table names are unique without worrying
    about the temp table names used by other application areas. 
    <br/>Recommends use template name e.g. Fnd0 for foundation.

    Currently only supports generation of temporary table names.

    @returns 
    <ul> 
    <li>#POM_ok on success 
    <li>Any another POM error on failure 
    </ul>
*/
POMAPI int POM_generate_table_name(
    int                 table_type,         /**< (I)  Type of table.  The only value supported now is #POM_TEMPORARY_TABLE. */
    const char         *application_prefix, /**< (I)  An application prefix name, must be 3 or 4 chars long. */
    const char         *root_table_name,    /**< (I)  The root name of the table that the caller wants to create. <br/>
                                             Should be <= 26 characters long. */
    char              **actual_table_name   /**< (OF) The table name actually created. <br/>
                                             The caller should keep the actual_table_name so it can be passed to other functions
                                             and free it after its last use. <br/>
                                             For temporary tables this name may contain some pre-pended characters for particular db vender <br/> 
                                             followed by the application prefix followed by the root_table_name. <br/> */
);

/**
   Creates a table.  
   <br/>Currently only supports creation of temporary tables.
   @returns 
   <ul> 
   <li>#POM_ok on success 
   <li>Any another POM error on failure 
   </ul>
*/
POMAPI int POM_create_table(
    int                 table_type,         /**< (I) Type of table.  The only value supported now is #POM_TEMPORARY_TABLE. */ 
    const char         *application_prefix, /**< (I) An application prefix name, must be 3 or 4 chars long. */
    const char         *root_table_name,    /**< (I) The root name of the table that the caller wants to create. */
    int                 n_columns,          /**< (I) Number of columns in the table. */
    const char        **column_names,       /**< (I) n_columns Array of column names. */
    const int          *column_types,       /**< (I) n_columns Array of column types. <br/>Valid values are:
                                                <ul>
                                                <li>#POM_date, 
                                                <li>#POM_double, 
                                                <li>#POM_int, 
                                                <li>#POM_logical, 
                                                <li>#POM_string, 
                                                <li>#POM_untyped_reference.
                                                </ul> */
    const int          *column_widths,      /**< (I) n_columns Array of column widths.  <br/> 
                                               Elements corresponding to columns that are varchar columns must be set to the column width. 
                                               Widths for other column types will be determined from the column types. */
    int                   clear_rows,       /**< (I) When to delete rows in the temp table, e.g., at end of transaction (#POM_TT_CLEAR_ROWS_EOT) <br/>
                                               or end of session (#POM_TT_CLEAR_ROWS_EOS). */
    char              **actual_table_name   /**< (OF) Actual table name of the table just created.  <br/>
                                               Keep this value to pass to other POM temporary table functions expecting an actual table name. <br/>
                                               Free actual_table_name after you're done with it. */
);

/**
    Clears a table of its contents.

    Currently only supports clearing temporary tables.

    For a temporary table, clears the temp table of the current session's contents.
    It does not clear the contents belonging to other sessions. 
    For temporary tables does not return or raise an error for the condition where the current 
    session has no data in the temp table.

    @returns 
    <ul> 
    <li>#POM_ok on success 
    <li>Any another POM error on failure 
    </ul>
    
*/
POMAPI int POM_clear_table(
    const char *actual_table_name /**< (I) Name of the table the caller wants to clear. <br/>
                                     Pass in the database table name of the table.
                                     This can be a table name output by #POM_create_table or #POM_generate_table_name. */
);

/**
    Prepares to insert data into a table and allocate an insert handle associated with 
    an insert handle name. 
    <br/>This function currently only supports inserts into temporary tables. 

    <br/>The caller will call #POM_prepare_table_insert to obtain a table insert handle name. 
    <br/>The insert handle name is passed to other table insert functions. 
    <br/>The caller will call POM_set_table_insert_<type>_column_vals() to associate values with the insert handle 
    to be inserted later. The insert handle holds onto the data in memory to be inserted into the table. 
    <br/>Finally, the caller calls #POM_exec_table_insert to insert the values associated with the 
    insert handle into the table in the database. 

    @returns 
    <ul> 
    <li>#POM_ok on success 
    <li>Any another POM error on failure 
    </ul> 

*/
POMAPI int POM_prepare_table_insert(
    const char *actual_table_name,    /**< (I) An actual table name output by #POM_create_table or <br/>
                                         #POM_generate_table_name. <br/>
                                         Currently only temporary tables are supported. */
    const char *insert_name,          /**< (I) A name for your insert to the actual table name. */
    char      **insert_handle_name    /**< (OF) The name of an insert handle that will hold table data to be inserted later.  <br/>
                                         The caller should keep the insert handle name to pass to other POM temporary table insert <br/>
                                         functions and free it after its last use. */
);

/**
    Sets a column of character string data (#POM_string) to insert into a table in a table insert handle.
    <br/>It is the caller's responsibility, especially important for a multi-column table, to make sure that 
    all the column values "line up" with the other column values that belong in their row. 
    @returns 
    <ul> 
    <li>#POM_ok on success 
    <li>Any another POM error on failure 
    </ul>
*/
POMAPI int POM_set_table_insert_string_column_vals(
    const char     *insert_handle_name,   /**< (I) A table insert handle name output by #POM_prepare_table_insert. */
    const char     *column_name,          /**< (I) The name of the column for this data. <br/>
                                             column_name must match the name of a column in the <br/>
                                             table associated with insert_handle_name <br/>
                                             in the call to #POM_prepare_table_insert. <br/>
                                             column_name must refer to a #POM_string column. */
    int             n_values,             /**< (I) The number of values to put into the table insert handle. */
    const char    **column_values,        /**< (I) n_values Array of values to put on the table insert handle. */
    const logical  *null_values           /**< (I) n_values Array of logicals showing which of column_values are null. <br/>
                                             null_values[i] == true shows that column_values[i] is null. <br/>
                                             null_values[i] == false shows that column_values[i] is not null. <br/>
                                             Pass NULL for null_values to indicate that all of the <br/>
                                             values in column_values are non-null. */
);

/**
    Sets a column of integer data (#POM_int) to insert into a table in a table insert handle.
    <br/>It is the caller's responsibility, especially important for a multi-column table, to make sure that 
    all the column values "line up" with the other column values that belong in their row. 
    @returns 
    <ul> 
    <li>#POM_ok on success 
    <li>Any another POM error on failure 
    </ul>
*/
POMAPI int POM_set_table_insert_int_column_vals(
    const char     *insert_handle_name,   /**< (I) A table insert handle name output by #POM_prepare_table_insert. */
    const char     *column_name,          /**< (I) The name of the column for this data. <br/>
                                             column_name must match the name of a column in the <br/>
                                             table associated with insert_handle_name <br/>
                                             in the call to #POM_prepare_table_insert. <br/>
                                             column_name must refer to a #POM_int column. */
    int             n_values,             /**< (I) The number of values to put into the table insert handle. */
    const int      *column_values,        /**< (I) n_values array of values to put on the table insert handle. */
    const logical  *null_values           /**< (I) n_values array of logicals showing which of column_values are null. <br/>
                                             null_values[i] == true shows that column_values[i] is null. <br/>
                                             null_values[i] == false shows that column_values[i] is not null. <br/>
                                             Pass NULL for null_valuess to indicate that all of the <br/>
                                             values in column_values are non-null. */
);

/**
    Sets a column of logical data (#POM_logical) to insert into a table in a table insert handle.
    <br/>It is the caller's responsibility, especially important for a multi-column table, to make sure that 
    all the column values "line up" with the other column values that belong in their row. 
    @returns 
    <ul> 
    <li>#POM_ok on success 
    <li>Any another POM error on failure 
    </ul>
*/
POMAPI int POM_set_table_insert_logical_column_vals(
    const char     *insert_handle_name,   /**< (I) A table insert handle name output by #POM_prepare_table_insert. */
    const char     *column_name,          /**< (I) The name of the column for this data. <br/>
                                             column_name must match the name of a column in the <br/>
                                             table associated with insert_handle_name <br/>
                                             in the call to #POM_prepare_table_insert. <br/>
                                             column_name must refer to a #POM_logical column. */
    int             n_values,             /**< (I) The number of values to put into the table insert handle. */
    const logical  *column_values,        /**< (I) n_values array of values to put on the table insert handle. */
    const logical  *null_values           /**< (I) n_values array of logicals showing which of column_values are null. <br/>
                                             null_values[i] == true shows that column_values[i] is null. <br/>
                                             null_values[i] == false shows that column_values[i] is not null. <br/>
                                             Pass NULL for nullVals to indicate that all of the <br/>
                                             values in column_values are non-null. */
);

/**
    Sets a column of double data (#POM_double) to insert into a table in a table insert handle.
    <br/>It is the caller's responsibility, especially important for a multi-column table, to make sure that 
    all the column values "line up" with the other column values that belong in their row. 
    @returns 
    <ul> 
    <li>#POM_ok on success 
    <li>Any another POM error on failure 
    </ul>
*/
POMAPI int POM_set_table_insert_double_column_vals(
    const char     *insert_handle_name,    /**< (I) A table insert handle name output by #POM_prepare_table_insert. */
    const char     *column_name,           /**< (I) The name of the column for this data. <br/>
                                             column_name must match the name of a column in the <br/>
                                             table associated with insert_handle_name <br/>
                                             in the call to #POM_prepare_table_insert. <br/>
                                             column_name must refer to a #POM_double column. */
    int             n_values,              /**< (I) The number of values to put into the table insert handle. */
    const double   *column_values,         /**< (I) n_values array of values to put on the table insert handle. */
    const logical  *null_values            /**< (I) n_values array of logicals showing which of column_values are null. <br/>
                                             null_values[i] == true shows that column_values[i] is null. <br/>
                                             null_values[i] == false shows that column_values[i] is not null. <br/>
                                             Pass NULL for null_values to indicate that all of the <br/>
                                             values in column_values are non-null. */
);

/**
    Sets a column of date data (#POM_date) to insert into a table in a table insert handle.
    <br/>It is the caller's responsibility, especially important for a multi-column table, to make sure that 
    all the column values "line up" with the other column values that belong in their row. 
    @returns 
    <ul> 
    <li>#POM_ok on success 
    <li>Any another POM error on failure 
    </ul>
*/
POMAPI int POM_set_table_insert_date_column_vals(
    const char     *insert_handle_name,    /**< (I) A table insert handle name output by #POM_prepare_table_insert. */
    const char     *column_name,           /**< (I) The name of the column for this data. <br/>
                                             column_name must match the name of a column in the <br/>
                                             table associated with insert_handle_name <br/>
                                             in the call to #POM_prepare_table_insert. <br/>
                                             column_name must refer to a #POM_date column. */
    int             n_values,              /**< (I) The number of values to put into the table insert handle. */
    const date_t   *column_values,         /**< (I) n_values array of values to put on the table insert handle. */
    const logical  *null_values            /**< (I) n_values array of logicals showing which of column_values are null. <br/>
                                             null_values[i] == true shows that column_values[i] is null. <br/>
                                             null_values[i] == false shows that column_values[i] is not null. <br/>
                                             Pass NULL for null_values to indicate that all of the <br/>
                                             values in column_values are non-null. */
);

/**
    Sets a column of untyped reference data (POM_untyped_references, tags) to insert into a table in a table insert handle.
    <br/>It is the caller's responsibility, especially important for a multi-column table, to make sure that 
    all the column values "line up" with the other column values that belong in their row. 
    <br/>This function will convert the input tags to uids.  The uids will be stored in the temp table.
    @returns 
    <ul> 
    <li>#POM_ok on success 
    <li>Any another POM error on failure 
    </ul>

    Sees the note earlier in this file "Note:  Regarding POM_untyped_references, temp tables, and POM Enquiry"
    for important information about how POM_untyped_references, temp tables, and POM Enquiry work together.
*/
POMAPI int POM_set_table_insert_untyped_reference_column_vals(
    const char     *insert_handle_name,     /**< (I) A table insert handle name output by #POM_prepare_table_insert. */
    const char     *column_name,            /**< (I) The name of the column for this data. <br/>
                                                 column_name must match the name of a column in the <br/>
                                                 table associated with insert_handle_name <br/>
                                                 in the call to #POM_prepare_table_insert. <br/>
                                                 column_name must refer to a #POM_untyped_reference column. */
    int             n_values,               /**< (I) The number of values to put into the table insert handle. */
    const tag_t    *column_values,          /**< (I) n_values array of values to put on the table insert handle. */
    const logical  *null_values             /**< (I) n_values array of logicals showing which of column_values are null. <br/>
                                                 null_values[i] == true shows that column_values[i] is null. <br/>
                                                 null_values[i] == false shows that column_values[i] is not null. <br/>
                                                 Pass NULL for null_values to indicate that all of the <br/>
                                                 values in column_values are non-null. */
);

/**
    Executes the insert for a table insert handle -- inserts all the data in the table insert
    handle into its table.
    <br/>Frees the table insert handle when it is done with the insert, but does not free the insert_handle_name.  
    <br/>The caller should free the insert_handle_name after its last use.
    <br/>This function currently only supports inserts into temporary tables.
    @returns 
    <ul> 
    <li>#POM_ok on success 
    <li>Any another POM error on failure 
    </ul>
*/
POMAPI int POM_exec_table_insert(
    const char     *insert_handle_name    /**< (I) A table insert handle name output by #POM_prepare_table_insert. */
);

/**
    Removes and frees the insert for a table insert handle 
    <br/>This function currently only supports insert handle into temporary tables.
    @returns 
    <ul> 
    <li>#POM_ok on success 
    <li>Any another POM error on failure 
    </ul>
*/
POMAPI int POM_remove_table_insert_handle(
    const char     *insert_handle_name    /**< (I) A table insert handle name output by #POM_prepare_table_insert. */
);

/**
    Gets information used to define a table.  Furnished as a debugging aid to applications.
    <br/>This function currently only supports getting table definition info for a temporary table being used in the current session.
    @returns 
    <ul> 
    <li>#POM_ok on success 
    <li>Any another POM error on failure 
    </ul>
*/
POMAPI int POM_get_table_defn_info(
    const char                    *actual_table_name,      /**< (I) An actual table name output by #POM_create_table or <br/>
                                                             #POM_generate_table_name. <br/>
                                                             Currently must be the actual_table_name of a temporary table in use <br/>
                                                             in this session. */
    char                          **application_prefix,    /**< (OF) An application prefix for the table name. */
    char                          **root_table_name,       /**< (OF) The root name of the table. */
    int                            *n_columns,             /**< (O) The number of columns in the table. */
    char                         ***column_names,          /**< (OF) n_columns Unpacked array of column names for the columns in the table. <br/>
                                                             Because the array is unpacked, the caller must free each element before freeing the colNames. */
    int                           **column_types,          /**< (OF) n_columns Array of column type numbers for the columns in the table. <br/>
                                                              */
    char                         ***column_type_names,     /**< (OF) n_columns Unpacked array of column type names for column_types. <br/>                       
                                                             Because the array is unpacked, the caller must free each element before freeing column_type_names. */
    int                           **column_widths,         /**< (OF) n_columns Array of column widths for the columns.  <br/>
                                                             Note that the column widths that matter are those for character string  <br/>
                                                             columns.  Widths used in the database are otherwise type dependent. */
    int                            *clear_rows             /**< (O) When to delete rows in the temp table, one of #POM_TT_CLEAR_ROWS_NOT_SET, <br/>
                                                             #POM_TT_CLEAR_ROWS_EOS, or #POM_TT_CLEAR_ROWS_EOT defined */
);

/**
    Adds a table name to the list of tables that will get dropped at the end of a Tc session.
    <br/>This function currently only supports adding the name of a table to the drop session drop table list for a temporary table being used in the current session.
    @returns 
    <ul> 
    <li>#POM_ok on success 
    <li>Any another POM error on failure 
    </ul>
*/
POMAPI int POM_add_table_name_to_session_drop_table_list(
    int         table_type,           /**< (I) Type of table.  The only value supported now is #POM_TEMPORARY_TABLE. */
    const char *actual_table_name     /**< (I) An actual table name output by #POM_create_table or #POM_generate_table_name. */
);

/**
   Checks if a table exists in the database.
   @returns 
    <ul> 
    <li>#POM_ok on success 
    <li>Any another POM error on failure 
    </ul>
*/
POMAPI int POM_does_table_exist(
    const char *actual_table_name  /**< (I) The database table name of the table to check.   <br/>  
                                      For a temporary table pass the actual_table_name returned from #POM_create_table or #POM_generate_table_name. */
);  

/**
   Drops a temporary table, putting transaction boundaries around it if they do not already exist.
   @returns 
    <ul> 
    <li>#POM_ok on success 
    <li>Any another POM error on failure 
    </ul>
*/
POMAPI int POM_drop_temp_table_with_trans_checking(
    const char *actual_table_name  /**< (I) The database table name of the table to check. <br/>   
                                      For a temporary table pass the actual_table_name returned from #POM_create_table or #POM_generate_table_name. */
);    

/**
    Output (is_active) value is true if there is transparent upgrade activity on the system.
    Some Teamcenter functionality might be restricted during the transparent upgrade process.
    @returns
    <ul>
    <li>#POM_ok on success
    <li>Any another POM error on failure
    </ul>
*/
POMAPI int POM_is_transparent_upgrade_active(
    logical* is_active                  /**< (O) True = tranparent upgrade is active */
);

/**
Determines if each input tag is a valid POM-tag.
<br\>There are three optional sets of return data.
<ul>
<li>valid One flag for each input tag, true = valid POM-tag or null-tag / false = invalid POM-tag
<li>valid_tags List of unique valid POM-tags (not including null-tag) 
<li>invalid_tags List of unique invalid POM-tags (not including null-tag)
</ul>

@note Tags of deleted POM Objects are valid POM-tags.

@returns
<ul>
<li>#POM_ok on success
<li>POM error indicating the type of failure that occurred.
</ul>

<br\> Supports rollback using markpoints: YES.
*/
POMAPI int POM_valid_pom_tags(
    int             n_tags,            /**< (I)  Number of tags to validate */
    const tag_t*    tags,              /**< (I)  n_tags tags to validate */
    logical**       valid,             /**< (OF) n_tags flags, one for each input tag, true = valid or null-tag / false = not valid (NULL is acceptable) */
    int*            n_valid_tags,      /**< (O)  Number of unique non-null valid POM-tags (NULL is acceptable) */
    tag_t**         valid_tags,        /**< (OF) List of non-null valid POM-tags, containing n_valid_tags tags (NULL is acceptable) */
    int*            n_invalid_tags,    /**< (O)  Number of unique non-null invalid POM-tags (NULL is acceptable) */
    tag_t**         invalid_tags       /**< (OF) List of non-null invalid POM-tags, containing n_invalid_tags tags (NULL is acceptable) */
);

/** @} */ 
    
/** @} */

#ifdef __cplusplus
}
#endif
#include <pom/pom/libpom_undef.h>

#endif /* POM_H */
