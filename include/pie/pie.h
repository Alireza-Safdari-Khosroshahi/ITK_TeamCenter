/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    PLMXML Import Export functions
*/

/*  */

#ifndef PIE_H
#define PIE_H

#include <tc/tc_startup.h>

#include <tccore/workspaceobject.h>
#include <pie/libpie_exports.h>

/**
    @defgroup PIE PLMXML Import/Export

    The ITK functions in this module deal with objects of the following type:

    <UL>
    <LI>TransferMode: The transfer mode object specifies the context of the export.
                    It has a context string, which specifies the intent of  the export and direction,
                    which specifies the direction of transfer.
                    Additionally, the object specifies the various Closure Rules,
                    Filter Rules and Property Sets that describe the mode of export through
                    reference to the specified  objects.
    <LI>ClosureRule: Rules for Traversal
    <LI>FilterRule: Filter rules for export or import
    <LI>PropertySet: Properties that are exported as user data
    <LI>Session: Holds all the data that is needed for processing export or import.
                It mainly controls the export/import process.
    </UL>
    @{
*/

#define PIE_name_size_c                 32
#define PIE_context_size_c              240
#define PIE_desc_size_c                 240
#define CLAUSE_DELIMITERS               ":."
#define PIE_COLON_DELIMITER             ":"
#define PIE_DOT_DELIMITER               "."
#define PIE_WILD_CARD_ASTERIX           "*"

#define CLAUSE_TYPE_STR                 "TYPE"
#define CLAUSE_CLASS_STR                "CLASS"
#define CLAUSE_PROPERTY_STR             "PROPERTY"
#define CLAUSE_ATTRIBUTE_STR            "ATTRIBUTE"
#define CLAUSE_RELATION_STR             "RELATION"
#define CLAUSE_RELATIONP2S_STR          "RELATIONP2S"
#define CLAUSE_RELATIONS2P_STR          "RELATIONS2P"
#define CLAUSE_REFBY_STR                "REFBY"
#define CLAUSE_OCCTYPE_STR              "OCCTYPE"
#define CLAUSE_CONTENT_STR              "CONTENT"
#define CLAUSE_FUNCTION_STR             "FUNCTION"

#define PROCESS_DIRECTIVE               "PROCESS"
#define NOPROCESS_TRAVERSE_DIRECTIVE    "TRAVERSE_NO_PROCESS"
#define PROCESS_AND_TRAVERSE_DIRECTIVE  "TRAVERSE_AND_PROCESS"

#define CLAUSE_PROPERTY_RULE_DO_STR     "DO"
#define CLAUSE_PROPERTY_RULE_SKIP_STR   "SKIP"
#define CLAUSE_PROPERTY_RULE_SKIP_GRM_STR "SKIP_GRM"

/** Rule String STUB_KEY for Property set */
#define CLAUSE_PROPERTY_RULE_STUB_KEY_STR "STUB_KEY"

/** Rule String CAND_KEY for Property set */
#define CLAUSE_PROPERTY_RULE_CAND_KEY_STR "CAND_KEY"

#define TRANSIENT_VOLUME_ROOTDIR        "Transient_Volume_RootDir"

/**
    Enum for formulating Closure, Filter and PropSet Clauses
*/
typedef enum PIE_type_e
{
    PIE_class = 0,
    PIE_type  = 1
} PIE_type_t;

/**
    Enum for type of relation (or reference) to traverse in closure rule
*/
typedef enum PIE_connection_type_e
{
    PIE_property             = 0,
    PIE_attribute            = 1,
    PIE_relation_primary     = 2,
    PIE_relation_secondary   = 3,
    PIE_referenced_by        = 4,
    PIE_all                  = 5,
    PIE_occurrence_type      = 6,
    PIE_content              = 7,    /**< for plmxml input traversals... */
    PIE_function             = 8
} PIE_connection_type_t;

/** @if DOX_IGNORE
    These e-nums are now synched with directives as bitmaps in pie_types.hxx
    Do not change them here without re-syncing - these are preserved for backward compatability only!
@endif */

/**
    Enum for rule type in closure rule
*/
typedef enum PIE_rule_type_e
{
    PIE_skip                  = 1,
    PIE_process               = 2,
    PIE_travers_no_process    = 4,
    PIE_travers_and_process   = 6,
    PIE_skip_grm              = 32
} PIE_rule_type_t;

/**
    Enum for rule type in a property set
*/
typedef enum PIE_prop_rule_type_e
{
    PIE_prop_do         = 0,    /**< Rule DO                          */
    PIE_prop_skip       = 1,    /**< Rule SKIP                        */
    PIE_prop_stub_key   = 2,    /**< Rule STUB_KEY                    */
    PIE_prop_cand_key   = 3     /**< Rule CAND_KEY                    */
} PIE_prop_rule_type_t;

/**
    Enum for translation direction
*/
typedef enum PIE_direction_e
{
    PIE_teamcenter2PLMXML  = 0,
    PIE_PLMXML2teamcenter  = 1,
    PIE_direction_both  = 2
} PIE_direction_t;

/**
    Enum for Schema Format Specification
*/
typedef enum PIE_schema_e
{
    PIE_ALL_schema  = 2,
    PIE_PLMXML_schema  = 0,
    PIE_TcXML_schema  = 1
} PIE_schema_t;

/**
    @note: The recommendation on enum for TcXML schema format is to use PIE_TcXML_schema. However, to support existing usages, the following defined symbol is required
*/
#define PIE_TcPLMXML_schema PIE_TcXML_schema

/**
    Enum for spcifying scope of transferoptionset
*/
typedef enum PIE_transferoptionset_scope_e
{
    PIE_transferoptionset_private = 0,
    PIE_transferoptionset_public  = 1,
    PIE_transferoptionset_all  = 2
} PIE_transferoptionset_scope_t;

/**
    Enum for translation scope
*/
typedef enum PIE_scope_e
{
    PIE_TEAMCENTER   = 0,
    PIE_PLMXML  = 1
} PIE_scope_t;

typedef enum PIE_action_e
{
    PIE_PREACTION     = 0,
    PIE_DURINGACTION  = 1,
    PIE_POSTACTION    = 2
} PIE_action_t;

/**
    This enum is used to set the status of object that is in the object map.
*/
typedef enum PIE_object_status_in_map_e
{
    PIE_NOCOMMENT  = 0,           /**< This is used for initialization. */
    PIE_NEW,                      /**< This is used to specify that current object is newly created. */
    PIE_MOD,                      /**< This is used to specify that current object exists in DB and has 
                                       been modified in current import session. */
    PIE_PROC_NO_TRAV,             /**< This is used to specify that current object has been processed 
                                       but not traversed. */
    PIE_PROC_AGAIN,               /**< This is used to specify that even though this object is in
                                       the map, it was not processed fully. So process it again. */
    PIE_DS_REVISED,               /**< This is used to specify that the Dataset version from XML is the 
                                       latest comparing to the existing version in DB. */
    PIE_DS_ADD_TO_IC,             /**< Under some circumstances we must add a dataset to the IC if the existing 
                                       dataset has named references this is done for specific integrations. */
    PIE_DS_TO_VERSION,            /**< Add files to specific version. */
    PIE_BOMLine_editable,         /**< Checking whether BOM line is editable or not in JT export. */
    PIE_POMCLASS   = 1024,        /**< The processed object is POMClass, not object instance. */
    PIE_DEL        = 10,          /**< Mark for object deleted, like delta delete. */
    PIE_INCOMPLETE = 11           /**< The object is being processed.This is used for specify that the object 
                                       has been created but not fully processed */
} PIE_object_status_in_map_t;

/**
    This enum is used to set the scope of user exits
*/
typedef enum PIE_user_exits_type_e
{
    PIE_internal_user_exits  = 0,
    PIE_external_user_exits  = 1
}PIE_user_exits_type_t;


#ifdef __cplusplus
    extern "C"{
#endif

/**
   Retrieves the transfer modes.
*/
extern PIE_API int PIE_find_transfer_mode2(
    const char     *transfer_mode_name, /**< (I) Name of transfer mode */
    const char     *context_string,     /**< (I) Context string */
    int*           n_transfer_mode,     /**< (O) Number of transfer modes */
    tag_t**        transfer_mode        /**< (OF) n_transfer_mode The transfer modes. */
    );

extern PIE_API int PIE_extent_transfer_modes(
    int*           n_transfer_modes,    /**< (O) Number of transfer Modes */
    tag_t**        transfer_modes       /**< (OF) n_transfer_modes Transfer Mode Tags */
    );


/**

  */
extern PIE_API int PIE_create_transfer_mode_instance2(
    const char     *transfer_mode_name,                     /**< (I) Name of Transfer Mode */
    const char     *transfer_mode_description,              /**< (I) Description of Transfer Mode */
    const char     *context_string,                         /**< (I) Input variable indicating the context string */
    tag_t*         transfer_mode                            /**< (O) Output Transfer Mode tag */
    );


extern PIE_API int PIE_transfer_mode_get_context_string2(
    tag_t          transfer_mode,                           /**< (I) The Transfer Mode */
    char           **context_string                         /**< (OF) The associated context */
    );


extern PIE_API int PIE_transfer_mode_set_context_string2(
    tag_t          transfer_mode,                           /**< (I) Input Transfer Mode tag */
    const char     *context_string                          /**< (I) Input variable specifying the context string */
    );

extern PIE_API int PIE_transfer_mode_set_xslt(
    tag_t          transfer_mode,   /**< (I) Transfer Mode */
    int            n_files,         /**< (I) Number of XSLT Files */
    tag_t*         xslt_files       /**< (I) n_files XSLT File Tags */
    );

extern PIE_API int PIE_transfer_mode_remove_xslt(
    tag_t          transfer_mode,   /**< (I) */
    tag_t          xslt_file        /**< (I) */
    );

extern PIE_API int PIE_transfer_mode_get_xslt(
    tag_t          transfer_mode,   /**< (I) Input Transfer Mode Tag */
    int*           n_files,         /**< (O) Number of xslt files */
    tag_t**        xslt_files       /**< (OF) n_files Array of xslt files */
    );

extern PIE_API int PIE_transfer_mode_get_direction(
    tag_t            transfer_mode, /**< (I) Input Transfer Mode Tag */
    PIE_direction_t* direction      /**< (O) Output variable indicating the Direction of transfer (export or import) */
    );

extern PIE_API int PIE_transfer_mode_set_direction(
    tag_t           transfer_mode,  /**< (I) Input Transfer Mode Tag */
    PIE_direction_t direction       /**< (I) Input variable indicating the Direction of Transfer (import or export) */
    );

extern PIE_API int PIE_transfer_mode_get_schema_format(
    tag_t            transfer_mode, /**< (I) Input Transfer Mode Tag */
    PIE_schema_t* schema_format     /**< (O) Output variable indicating the Schema format of transfer (PLMXML or TCXML) */
    );

extern PIE_API int PIE_transfer_mode_set_schema_format(
    tag_t           transfer_mode,  /**< (I) Input Transfer Mode Tag */
    PIE_schema_t schema_format      /**< (I) Input variable indicating the Schema format of Transfer (PLMXML or TCXML) */
    );

extern PIE_API int PIE_transfer_mode_get_incremental(
    tag_t          transfer_mode,   /**< (I) Input Transfer Mode Tag */
    logical*       incremental      /**< (O) Output variable indicating whether the transfer is incremental */
    );

extern PIE_API int PIE_transfer_mode_set_incremental(
    tag_t          transfer_mode,   /**< (I) Input Transfer Mode Tag */
    logical        incremental      /**< (I) Output variable indicating whether the transfer is incremental */
    );

extern PIE_API int PIE_transfer_mode_get_multisite(
  tag_t       transfer_mode,                              /* <I> */
  logical    *multisite                                   /* <O> */
  );

extern PIE_API int PIE_transfer_mode_set_multisite(
  tag_t       transfer_mode,                              /* <I> */
  logical     multisite                                   /* <I> */
  );

extern PIE_API int PIE_transfer_mode_get_closures(
    tag_t          transfer_mode,   /**< (I) Transfer Mode */
    tag_t*         closure          /**< (O) The Closure Rule associated with the transfer mode */
    );

extern PIE_API int PIE_transfer_mode_set_closures(
    tag_t          transfer_mode,   /**< (I) Transfer Mode */
    tag_t          closure          /**< (I) The Closure Rule to be associated with the transfer mode */
    );

extern PIE_API int PIE_transfer_mode_get_filters(
    tag_t          transfer_mode,   /**< (I) Transfer Mode */
    tag_t*         filter           /**< (O) The Filter to be associated with the transfer mode */
    );

extern PIE_API int PIE_transfer_mode_set_filters(
    tag_t          transfer_mode,   /**< (I) Transfer Mode */
    tag_t          filter           /**< (I) The Filter to be associated with the transfer mode */
    );

extern PIE_API int PIE_transfer_mode_load_defaults(
    tag_t          transfer_mode    /**< (I) */
    );

extern PIE_API int PIE_transfer_mode_get_prop_set(
    tag_t          transfer_mode,   /**< (I) Transfer Mode */
    tag_t*         prop_set         /**< (O) The PropertySet associated with the transfer mode */
    );

extern PIE_API int PIE_transfer_mode_set_prop_set(
    tag_t          transfer_mode,   /**< (I) Input Transfer Mode tag */
    tag_t          prop_set         /**< (I) The PropertySet to be associated with the transfer mode */
    );

extern PIE_API int PIE_transfer_mode_get_config_objs(
    tag_t          transfer_mode,   /**< (I) Transfer Mode */
    int*           n_config_objs,   /**< (O) Number of config objects */
    tag_t**        config_objs      /**< (OF) n_config_objs Config Objects */
    );

extern PIE_API int PIE_transfer_mode_set_config_objs(
    tag_t          transfer_mode,   /**< (I) Input Transfer Mode tag */
    int            n_config_objs,   /**< (I) Number of Config Objects */
    tag_t*         config_objs      /**< (I) Config Objects */
    );

extern PIE_API int PIE_transfer_mode_get_action_list(
    tag_t          transfer_mode,       /**< (I) Input Transfer Mode tag */
    int*           n_action_list_objs,  /**< (O) Number of Action Lists */
    tag_t**        action_list_objs     /**< (OF) n_action_list_objs Action List Objects */
    );

extern PIE_API int PIE_transfer_mode_set_action_list(
    tag_t          transfer_mode,       /**< (I) Input Transfer Mode tag */
    int            n_action_list_objs,  /**< (I) Number of Action Lists */
    tag_t*         action_list_objs     /**< (I) n_action_list_objs Action List Objects */
    );


/**

*/
extern PIE_API int PIE_create_closure_rules2(
    const char     *name,                       /**< (I) Closure Rule Name */
    const char     *desc,                       /**< (I) Closure Rule Description */
    PIE_scope_t    scope,                       /**< (I) Scope of Closure Rule */
    tag_t*         closure_tag                  /**< (O) Closure Rule tag */
    );

extern PIE_API int PIE_closure_add_rule_clause(
    tag_t                 closure_tag,      /**< (I) Closure Rule Tag */
    PIE_type_t            p_class_or_type,  /**< (I) Whether the primary object is specified through Type or Class */
    const char*           p_name,           /**< (I) Class or Type name of the primary object */
    PIE_connection_type_t c_type,           /**< (I) The type of connectivity between Primary and Secondary Objects */
    const char*           c_name,           /**< (I) Name of the connectivity/relation  between Primary and Secondary Objects */
    const char*           prop_name,        /**< (I) Represents the attribute/property name, when the relation is ATTRIBUTE/PROPERTY */
    PIE_type_t            s_class_or_type,  /**< (I) Whether the secondary object is specified through Type or Class */
    const char*           s_name,           /**< (I) The name of the class or type of the secondary object */
    PIE_rule_type_t       rule_type         /**< (I) The Directive specification */
    );

extern PIE_API int PIE_closure_set_rule_clause(
    tag_t                 closure_tag,      /**< (I) Closure Rule tag */
    int                   index,            /**< (I) Index of the clause */
    PIE_type_t            p_class_or_type,  /**< (I) Whether the primary object is specified through Type or Class */
    const char*           p_name,           /**< (I) Class or Type name of the primary object */
    PIE_connection_type_t c_type,           /**< (I) The type of connectivity between Primary and Secondary Objects */
    const char*           c_name,           /**< (I) Name of the connectivity/relation  between Primary and Secondary Objects */
    const char*           prop_name,        /**< (I) Represents the attribute/property name, when the relation is ATTRIBUTE/PROPERTY */
    PIE_type_t            s_class_or_type,  /**< (I) Whether the secondary object is specified through Type or Class */
    const char*           s_name,           /**< (I) The name of the class or type of the secondary object */
    PIE_rule_type_t       rule_type         /**< (I) The Directive specification */
    );


/**

 */
extern PIE_API int PIE_describe_closure_rule2(
    tag_t          closure_tag,                 /**< (I) Closure Rule tag */
    char           **name,                      /**< (OF) Closure Rule Name */
    char           **desc,                      /**< (OF) Closure Rule Description */
    PIE_scope_t*   scope,                       /**< (O) Scope of Closure rule */
    int*           n_clauses                    /**< (O) Number of clauses */
    );

extern PIE_API int PIE_closure_get_rule_clause(
    tag_t                  closure_tag,     /**< (I) Closure Rule tag */
    int                    index,           /**< (I) Index of the clause */
    PIE_type_t*            p_class_or_type, /**< (O) Whether the primary object is specified through Type or Class */
    char**                 p_name,          /**< (OF) Class or Type name of the primary object */
    PIE_connection_type_t* c_type,          /**< (O) The type of connectivity between Primary and Secondary Objects */
    char**                 c_name,          /**< (OF) Name of the connectivity/relation between Primary and Secondary Objects */
    char**                 prop_name,       /**< (OF) Represents the attribute/property name, when the relation is ATTRIBUTE/PROPERTY */
    PIE_type_t*            s_class_or_type, /**< (O) Whether the secondary object is specified through Type or Class */
    char**                 s_name,          /**< (OF) The name of the class or type of the secondary object */
    PIE_rule_type_t*       rule_type        /**< (O) The Directive specification */
    );



/**

*/
extern PIE_API int PIE_find_closure_rules2(
    const char     *name,                       /**< (I) Closure Rule name */
    PIE_scope_t    scope,                       /**< (I) Scope */
    int*           n_closure_tags,              /**< (O) Number of tags */
    tag_t**        closure_tags                 /**< (OF) n_closure_tags Closure Rule tags */
    );


/**

*/
extern PIE_API int PIE_create_filter2(
    const char     *name,                       /**< (I) Filter Name */
    const char     *desc,                       /**< (I) Description of the Filter */
    PIE_scope_t    scope,                       /**< (I) Scope */
    tag_t*         filter                       /**< (O) Filter tag */
    );



extern PIE_API int PIE_find_filter2(
    const char     *name,                       /**< (I) Filter name */
    PIE_scope_t    scope,                       /**< (I) Scope */
    int*           n_filter_tags,               /**< (O) Number of filter tags */
    tag_t**        filter_tags                  /**< (OF) n_filter_tags Filter tags */
    );

/**

*/
extern PIE_API int PIE_describe_filter2(
    tag_t          filter_tag,                  /**< (I) Filter tag */
    char           **name,                      /**< (OF) Name of Filter */
    char           **desc,                      /**< (OF) Description of the Filter */
    PIE_scope_t*   scope,                       /**< (O) Scope */
    int*           n_clauses                    /**< (O) Number of clauses */
    );

extern PIE_API int PIE_filter_add_clause(
    tag_t          filter,          /**< (I) Filter tag */
    PIE_type_t     type_or_class,   /**< (I) Whether Type or Class is used to specify the object */
    const char*    p_name,          /**< (I) Type or Class Name of the object */
    const char*    filter_name      /**< (I) Name of filter to be applied */
    );

extern PIE_API int PIE_filter_get_clause(
    tag_t          filter,          /**< (I) Filter tag */
    int            index,           /**< (I) Index of the clause */
    PIE_type_t*    type_or_class,   /**< (O) Whether a Type or Class of the Object is specified */
    char**         p_name,          /**< (OF) Type or Class Name of the Object */
    char**         filter_name      /**< (OF) Name of the filter */
    );

/**
    @name Action Rule Calls
    @{
*/


/**

*/
extern PIE_API int PIE_create_action2(
    const char     *name,                       /**< (I) */
    const char     *desc,                       /**< (I) */
    PIE_scope_t    scope,                       /**< (I) */
    PIE_action_t   type,                        /**< (I) */
    const char*    actionName,                  /**< (I) */
    tag_t*         action                       /**< (O) */
    );


extern PIE_API int PIE_find_action2(
    const char     *name,                       /**< (I) */
    PIE_scope_t    scope,                       /**< (I) */
    int*           n_action_tags,               /**< (O) */
    tag_t**        action_tags                  /**< (OF) n_action_tags */
    );

/**

*/
extern PIE_API int PIE_describe_action2(
    tag_t          action_tag,                  /**< (I) */
    char           **name,                      /**< (OF) */
    char           **desc,                      /**< (OF) */
    PIE_scope_t*   scope,                       /**< (O) */
    PIE_action_t*  type,                        /**< (O) */
    char**         actionName                   /**< (OF) */
    );

extern PIE_API int PIE_action_set_func_name(
    tag_t          action,      /**< (I) */
    const char*    func_name    /**< (I) */
    );

extern PIE_API int PIE_action_get_func_name(
    tag_t          action,      /**< (I) */
    char**         func_name    /**< (OF) */
    );

/** @} */

/**
    @name Property Set Calls
    @{
*/

/**

*/
extern PIE_API int PIE_create_prop_set2(
    const char     *name,                       /**< (I) Name of Property Set */
    const char     *desc,                       /**< (I) Description of the Property set */
    PIE_scope_t    scope,                       /**< (I) Scope */
    tag_t*         prop_set                     /**< (O) Property Set tag */
    );


/**

*/
extern PIE_API int PIE_find_prop_set2(
    const char     *name,                       /**< (I) Name of the property set */
    PIE_scope_t    scope,                       /**< (I) Scope */
    int*           n_propset_tags,              /**< (O) Number of property sets */
    tag_t**        propset_tags                 /**< (OF) n_propset_tags Property Set tags */
    );

extern PIE_API int PIE_prop_add_clause(
    tag_t                 prop_set,         /**< (I) Property Set tag */
    PIE_type_t            type_or_class,    /**< (I) Whether Type or Class of Property set is specified */
    const char*           p_name,           /**< (I) Type or class name of the property set */
    PIE_connection_type_t prop_or_attr,     /**< (I) The connection type ?property or attribute */
    const char*           a_name,           /**< (I) Name of the property or attribute */
    PIE_prop_rule_type_t  rule_type         /**< (I) The directive specification */
    );


/**

*/
extern PIE_API int PIE_describe_prop_set2(
    tag_t          prop_set,                    /**< (I) Property set tag */
    char           **name,                      /**< (OF) Name of Property Set */
    char           **desc,                      /**< (OF) Description of the property set */
    PIE_scope_t*   scope,                       /**< (O) Scope */
    int*           n_clauses                    /**< (O) Number of clauses */
    );

extern PIE_API int PIE_prop_get_clause(
    tag_t                  prop_set,        /**< (I) Property Set tag */
    int                    index,           /**< (I) Index of the clause */
    PIE_type_t*            type_or_class,   /**< (O) Whether Type or Class is used to specify the object */
    char**                 p_name,          /**< (OF) Type or Class name of the object */
    PIE_connection_type_t* prop_or_attr,    /**< (O) The connectivity type - property or attribute */
    char**                 a_name,          /**< (OF) The property or attribute name */
    PIE_prop_rule_type_t*  rule_type        /**< (O) The directive specification */
    );

/** @} */

/**
    @name Option Set Related APIs
    @{
*/

/**
    Finds the TransferOptionSet based on the given name.
    @returns
    <ul>
    <li>#ITK_ok on success        
    <li>Error code for any failure raised during data query from db 
    </ul>
*/
extern PIE_API int PIE_find_transfer_option_set(
    const char     *transfer_option_set_name,                     /**< (I) Name of transfer option set */
    int*           num_transfer_option_set_tags,                  /**< (O) Number of transfer option sets */
    tag_t**        transfer_option_set_tags                       /**< (OF) num_transfer_option_set_tags Array of transfer option sets */
    );


/**  The following api is used by online and offline (briefcase) transfers and here is the usage of the parameters
 *   ispush and isexoport for various cases
 *
 *   case 1: remote export    - on-line  --- ispush = true   isexport = true  exporting option set for local site
 *   case 2: remote import    - on-line  --- ispush = false  isexport = true  exporting option set for remote site
 *   case 3: briefcase export - off-line --- ispush = true   isexport = true  exporting option set for local site
 *   case 4: briefcase import - off-line --- ispush = na     isexport = false importing option set for briefcase import
 */
extern PIE_API int PIE_get_available_transfer_option_sets(
    tag_t    user,            /**< (I) User Tag */
    tag_t    group,           /**< (I) Group Tag */
    tag_t    role,            /**< (I) Role Tag */
    int      n_sites,         /**< (I) Number of Sites */
    tag_t *   sites,          /**< (I) Site Tags */
    logical  is_push,         /**< (I) Is it a Push case or Pull */
    logical  is_export,       /**< (I) Is it a Export Option Set */
    int *    n_optionsets,    /**< (O) Number of Option Set Objects */
    tag_t **  option_set_objs /**< (OF) n_optionsets List of OptionSet objects */
    );


/**

*/
extern PIE_API int PIE_describe_option_set2(
    tag_t     option_set_tag,                           /**< (I) Option Set Tag */
    char   **option_set_name,                           /**< (OF) Option Set Name */
    char   **option_set_description,                    /**< (OF) Option Set Description */
    tag_t*   transfermode,                              /**< (O) Transfermode Tag */
    char   **transfermode_name,                         /**< (OF) Transfermode Name */
    tag_t*   site,                                      /**< (O) Site Tag */
    int*     n_options,                                 /**< (O) Number of Options */
    char***  option_names,                              /**< (OF) n_options Option Names */
    char***  option_display_names,                      /**< (OF) n_options Option Display Names */
    char***  option_values,                             /**< (OF) n_options Option Initial Values */
    char***  option_descriptions,                       /**< (OF) n_options Option Descriptions */
    char***  option_group_names,                        /**< (OF) n_options Option Group Names */
    logical** option_read_only_flags                    /**< (OF) n_options Option Read only flags */
    );

/** @} */

/**
    @name PIE Session calls
    @{
*/

extern PIE_API int PIE_create_session(
    tag_t*         session      /**< (O) The session tag */
    );

extern PIE_API int PIE_create_session_for_ai(
    tag_t          request,     /**< (I) */
    tag_t*         session      /**< (O) */
    );

extern PIE_API int PIE_session_set_file(
    tag_t          session,     /**< (I) Session tag */
    const char*    file_name    /**< (I) File name */
    );

extern PIE_API int PIE_session_ask_file(
    tag_t          session,     /**< (I) */
    const char**   file_name    /**< (O) File name in buffer that should be SM_free'd*/
    );

extern PIE_API int PIE_session_set_log_file(
    tag_t          session,     /**< (I) Session tag */
    const char*    file_name    /**< (I) File name */
    );

extern PIE_API int PIE_session_ask_transfer_mode(
  tag_t            session,         /**< (I) */
  tag_t*           transfer_mode    /**< (O) */
  );

extern PIE_API int PIE_session_set_transfer_mode(
    tag_t          session,         /**< (I) Session tag */
    tag_t          transfer_mode    /**< (I) Transfer mode associated with the session */
    );

extern PIE_API int PIE_session_set_revision_rule(
    tag_t          session,         /**< (I) */
    tag_t          revision_rule    /**< (I) */
    );

extern PIE_API int PIE_session_export_objects(
    tag_t          session,     /**< (I) Session tag */
    int            n_objs,      /**< (I) Number of objects to be exported */
    tag_t*         obj_list     /**< (I) n_objs List of objects to be exported */
    );

extern PIE_API int PIE_session_get_target_pathname(
    tag_t          session,     /**< (I) */
    char**         pathname     /**< (OF) */
    );

extern PIE_API int PIE_session_set_target_pathname(
    tag_t          session,     /**< (I) */
    char*          pathname     /**< (I) */
    );

extern PIE_API int PIE_session_get_incremental_change(
    tag_t     session,                  /* <I> */
    tag_t     *incremental_change       /* <O> */
  );

extern PIE_API int PIE_session_set_incremental_change(
    tag_t     session,                  /* <I> */
    tag_t     incremental_change        /* <I> */
  );

extern PIE_API int PIE_session_set_edit_targets(
    tag_t          session,                 /**< (I) Session tag */
    int            num_tags,                /**< (I) Number of objects to be edited */
    tag_t*         tags_allowed_to_edit     /**< (I) n_objs List of objects to be edited */
  );

/**
    Sets the Incremental Changes (IC) which are to be assumed as unmodified and hence explicitly excluded from the current IC based delta export.
    An error CXPOM_invalid_tag (7007) will be returned if the session tag is invalid.
    In all other cases, the function will return ITK_ok.
*/
extern PIE_API int PIE_session_set_ic_exclusion_list(
    tag_t          session,                 /**< (I) Session tag */
    int            num_tags,                /**< (I) Number of Incremental Changes to be excluded */
    tag_t*         ic_tags_to_exclude       /**< (I) List of Incremental Changes to be excluded */
  );

/**
   Gets the list of taget objects to be processed in the session. 
*/
extern PIE_API int PIE_session_get_target_objects(
  tag_t     session,       /**< (I) Session tag */
  int      *n_objs,        /**< (O) Number of of target objects */
  tag_t   **obj_list       /**< (OF) n_objs List of target objects */
  );

/**
    Do not import the files during a dry_run
*/
extern PIE_API int PIE_session_import_objects(
    tag_t          session,     /**< (I) Session tag */
    logical        dry_run,     /**< (I) Whether only a dry run should be carried out */
    int*           n_objs,      /**< (O) Number of objects imported */
    tag_t**        obj_list     /**< (OF) n_objs List of objects exported */
    );

extern PIE_API int PIE_session_get_rule_types(
    tag_t          session,     /**< (I) */
    int*           n_types,     /**< (O) */
    char***        typeNames    /**< (OF) n_types */
    );

/**
   Get the errors occured during export of objects from session. This method gives you no. of objects
   failed to export, their tag and error code due to which failure happened.
*/
extern PIE_API int PIE_session_get_errors(
    tag_t          session,         /**< (I) Session tag */
    int*           n_errors,        /**< (O) Number of errors */
    tag_t**        error_objs,      /**< (OF) n_errors List of error objects */
    int**          error_codes      /**< (OF) n_errors List of error codes */
    );
/**
   Get the errors occured during import of objects from session. This method gives you no. of PLMXML objects
   failed to import, their PLMXML ids and error code due to which failure happened.
*/
extern PIE_API int PIE_session_get_import_errors(
    tag_t          session,         /**< (I) Session tag */
    int*           n_errors,        /**< (O) Number of errors */
    char***         error_ids,      /**< (OF) n_errors List of error element ids in PLMXML file */
    int**          error_codes      /**< (OF) n_errors List of error codes */
    );

extern PIE_API int PIE_delete_session(
    tag_t          session      /**< (I) Session tag */
    );

extern PIE_API int PIE_session_add_info(
    tag_t          session,     /**< (I) Session tag */
    int            n_strings,   /**< (I) Number of strings */
    char**         titles,      /**< (I) n_strings List of titles */
    char**         values       /**< (I) n_values List of values */
    );

extern PIE_API int PIE_session_ask_info(
    tag_t          session,     /**< (I) Session tag */
    int*           n_strings,   /**< (O) Number of strings */
    char***        titles,      /**< (OF) n_strings List of titles */
    char***        values       /**< (OF) n_strings List of values */
    );

extern PIE_API int PIE_session_get_user_xslt_file(
    tag_t          session,         /**< (I) Session tag */
    char**         user_xslt_fname  /**< (OF) User XSLT file name */
    );

extern PIE_API int PIE_session_set_user_xslt_file(
    tag_t          session,         /**< (I) Session tag */
    const char*    user_xslt_fname  /**< (I) The User XSLT file name */
    );

/**
    Get the export locales from the session.
    The locales returned would follow the standard Java locale naming convention: 2letterlanguage_2LETTRAREA (eg: en_US).
*/
extern PIE_API int PIE_session_get_export_locales(
    tag_t          session,            /**< (I) Unique identifier(tag) of the export session. */
    int            *exportlocaleCount, /**< (O) Number of languages set in the export session. */
    char           ***exportLocales    /**< (OF)List of languages to be exported with. */
    );

/**
    Set the export locales to the session.
    The exported file contains the translations in the locales set to the session.
    The Site Master Language translation will always be included.
    The locales should follow the standard Java locale naming convention: 2letterlanguage_2LETTRAREA (eg: en_US).
*/
extern PIE_API int PIE_session_set_export_locales(
    tag_t          session,            /**< (I) Unique identifier(tag) of the export session. */
    const int      exportlocaleCount,  /**< (I) Number of languages set in the export session. */
    char           **exportLocales     /**< (I) List of languages to be exported with. */
    );

/**
    Get the PLM XML document of the session.
*/
extern PIE_API int PIE_session_get_plmxml_document(
    tag_t          session,            /**< (I) Unique identifier(tag) of the session. */
    void           **plmxmlDoc         /**< (O) The PLM XML document in the current session. */
    );

/**
    Update the processed object in ObjectMap. This can be used for both export and import
    To add the Teamcenter object and the corresponding PLM XML object in the processed object list
*/
extern PIE_API int PIE_session_update_processed_object(
    tag_t          session,            /**< (I) Unique identifier(tag) of the session. */
    tag_t          obj,                /**< (I) Tag of Teamcenter object. */
    void           *plmxmlObj,         /**< (I) PLM XML object. */
    int            failCode            /**< (I) Any failure during the processing of the object. */
    );

/**
    Given a Teamcenter object, get the corresponding PLM XML object exported,and failure code during the processing of the object if any.
*/
extern PIE_API int PIE_session_get_processed_plmxml_object(
    tag_t          session,            /**< (I) Unique identifier(tag) of the session. */
    tag_t          obj,                /**< (I) Tag of Teamcenter object. */
    void           **plmxmlObj,        /**< (O) PLM XML object. */
    int            *failCode           /**< (O) Any failure during the processing of the object. */
    );

/**
    Given a PLM XML object, get the corresponding Teamcenter object imported,and failure code during the processing of the object if any.
*/
extern PIE_API int PIE_session_get_processed_tc_object(
    tag_t          session,            /**< (I) Unique identifier(tag) of the session. */
    void           *plmxmlObj,         /**< (I) PLM XML object. */
    tag_t          *obj,               /**< (O) Tag of Teamcenter object. */
    int            *failCode           /**< (O) Any failure during the processing of the object. */
    );

/** @} */

/**
    @name PIE Delta Calls
    @{
*/

extern PIE_API int PIE_create_delta_info(
    tag_t*         delta_info   /**< (O) */
    );

extern PIE_API int PIE_create_bom_delta_info(
    tag_t*         piebomdeltainfo      /**< (O) */
    );

extern PIE_API int PIE_add_delta_objects(
    tag_t          delta_info,  /**< (I) */
    int            n_objs,      /**< (I) */
    tag_t*         objs         /**< (I) */
    );

extern PIE_API int PIE_get_delta_adds(
    tag_t          delta_info,      /**< (I) */
    int*           n_objs,          /**< (O) */
    tag_t**        added_objs       /**< (OF) n_objs */
    );

extern PIE_API int PIE_get_delta_deletes(
    tag_t          delta_info,      /**< (I) */
    int*           n_objs,          /**< (O) */
    tag_t**        deleted_objs     /**< (OF) n_objs */
    );

extern PIE_API int PIE_get_delta_modifications(
    tag_t          delta_info,      /**< (I) */
    int*           n_objs,          /**< (O) */
    tag_t**        modified_objs    /**< (OF) n_objs */
    );

extern PIE_API int PIE_create_delta_session(
    tag_t          old_xml_file,    /**< (I) */
    char*          targetPathName,  /**< (I) */
    tag_t*         session          /**< (O) */
    );

extern PIE_API int PIE_merge_delta_to_base(
    tag_t          session,         /**< (I) */
    tag_t*         merged_xml_file  /**< (O) */
    );

/** @} */

/** For AutoTest */
extern PIE_API int PIE__compare_set_visitor(
    tag_t          diff_set,
    int            depth,
    void*          user_data
    );

/** For AppUid */
extern PIE_API int PIE_find_object_by_appref(
    char *appuid,  /**< (I) */
    char *appl,    /**< (I) */
    char *site,    /**< (I) */
    char *ver,     /**< (I) */
    int *count,    /**< (O) */
    tag_t **found    /**< (OF) n_objs */
    );


/** @if DOX_IGNORE
extern PIE_API int PIE_delta_session_export_objects();
@endif */

/*
 * External User exits import/export methods support
 */
/**
    Structure for user to define an import/export method
*/
typedef int (* PIE_user_method_func_t)( void *);
typedef struct PIEUserMethodList_s
{
    const char             *contextStr;   /* Context String */
    const char             *name;         /* Class or type name */
    PIE_user_method_func_t  func;         /* User method */
} PIEUserMethodList_t;


extern PIE_API int PIE_register_user_methods(
    void* listUserMethods,    /**< (I) Array of methods. It is a list of PIEUserMethodList_t. Each method is defined in a PIEUserMethodList_t. */
    int n_methods             /**< (I) Number of methods */
    );

/**
    External User schema map support
 */
typedef struct
{
    char                 *teamcenterObject;     /* Class name of Teamcenter object */
    char                 *plmxml_class;    /* Class name of plmxml object */
    char                 *teamcenterProperty;   /* Property name of Teamcenter object */
    char                 *plmxmlAttribute; /* Attribute name of plmxml object */
    logical              addToParent;      /* Flag to add to parent */
} PIEUserSchemaMap;


extern PIE_API int PIE_register_user_schema(
    void* listUserSchemas,      /**< (I) Array of schema mappings. It is a list of PIEUserSchemaMap. Each map is defined in a PIEUserSchemaMap. */
    int n_schemas               /**< (I) Number of schema mappings */
    );

/**
    External User action rule support
 */
typedef int (* PIE_user_action_func_t)( tag_t );

extern PIE_API int PIE_register_user_action (
  char*                      handleName,    /**< (I) Action name */
  PIE_user_action_func_t     user_m         /**< (I) Action method */
  );


/**
    External User filter rule support
 */
typedef PIE_rule_type_t (* PIE_user_filter_func_t)( void *);

extern PIE_API int PIE_register_user_filter (
  char*          filterRuleName,    /**< (I) Filter name */
  PIE_user_filter_func_t user_m     /**< (I) Filter method */
  );

/**
    @name Extract vaules from PIE_message_t*
    @{
*/

/**
   Returns the currently processed object class name from PIE_message_t*. 
   Mainly used by external user import/export methods.
*/
extern PIE_API int PIE_get_class_from_callpath(
  void         *userPath,         /**< (I) Information of currently processed object */
  char        **calledClass       /**< (OF) Class name of currently processed object */
  );

/**
   Returns the currently processed object type name from PIE_message_t*. 
   Mainly used by external user import/export methods.
*/
extern PIE_API int PIE_get_type_from_callpath(
  void         *userPath,         /**< (I) Information of currently processed object */
  char        **calledType        /**< (OF) Type name of currently processed object */
  );

/**
   Returns the currently processed object tag from PIE_message_t*. 
   Mainly used by external user import/export methods.
*/
extern PIE_API int PIE_get_obj_from_callpath(
  void         *userPath,         /**< (I) Information of currently processed object */
  tag_t        *objTag            /**< (O) Object tag of currently processed object */
  );

/**
   Returns the currently processing plmxml object pointer from PIE_message_t*. 
   Mainly used by external user import/export methods.
*/
extern PIE_API int PIE_get_plmxmlobj_from_callpath(
  void         *userPath,         /**< (I) Information of currently processing object */
  void         **plmxmlobj        /**< (O) plmxml object pointer of currently processing object */
  );

/**
   Returns the previous processed object information PIE_message_t*. 
   Mainly used by external user import/export methods.
*/
extern PIE_API int PIE_get_prior_callpath(
  void         *userPath,         /**< (I) Information of currently processed object */
  void        **prev_userPath     /**< (O) Information of previous processed object */
  );

/**
   Returns the processed object information PIE_message_t* based on the given object class name. 
   Mainly used by external user import/export methods. 
*/
extern PIE_API int PIE_find_callpath_by_class(
   void         *userPath,     /**< (I) Information of currently processed object */
   char         *className,    /**< (I) Class name to be searched for */
   void        **calledPath    /**< (O) Information of processed object matches with the given class name */
  );

/**
   Returns the processed object information PIE_message_t* based on the given object type name. 
   Mainly used by external user import/export methods.
*/
extern PIE_API int PIE_find_callpath_by_type(
   void         *userPath,     /**< (I) Information of currently processed object */
   char         *typeName,     /**< (I) Type name to be searched for */
   void        **calledPath    /**< (O) Information of processed object matches with the given type name */
  );

/**
   Returns the TransferMode tag being used by the current processing. 
   Mainly used by external user import/export methods.
*/
extern PIE_API int PIE_get_transfermode(
  void         *userPath,     /**< (I) Information of currently processed object */
  tag_t        *transMode     /**< (O) Transfer mode used by this process */
  );

/**
   Returns the PIESession tag being used by the current processing. 
   Mainly used by external user import/export methods.
*/
extern PIE_API int PIE_get_session(
  void         *userPath,     /**< (I) Information of currently processed object */
  tag_t        *session       /**< (O) Session  */
  );

/**
   Returns the relation type between previous processed object and current processed object. 
   Mainly used by external user import/export methods.
*/
extern PIE_API int PIE_get_relation_type(
  void         *userPath,     /**< (I) Information of currently processed object */
  char        **relType       /**< (OF) Relation type between previous object and current object */
  );

/**
   Returns the relation name between previous processed object and current processed object. 
   Mainly used by external user import/export methods.
*/
extern PIE_API int PIE_get_relation_name(
  void         *userPath,     /**< (I) Information of currently processed object */
  char        **relName       /**< (OF) Relation name between previous object and current object*/
  );
/** @} */

extern PIE_API int PIE_create_working_dir(
    char        **dirName       /**< (OF) Temp Directory Name */
  );

extern PIE_API int PIE_ensure_file_readable(
    char        *path       /**< (I) File Name */
  );

extern PIE_API int PIE_send_socket_message(
    const char *message,    /**< (I) Message string to be sent to the socket */
    char *host_n_port,      /**< (I) Host and port to which the message is sent. Should be of the format host:port*/
    int *response           /**< (O) Response from the host. */
  );

/**
   Retrieves the application reference (appRef) path and the version of the specified object.
   
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#PIE_dm_name_not_IM if the @p object parameter is not a valid POM object
   </ul>
*/
extern PIE_API int PIE_get_application_reference_label(
    tag_t                object,          /**< (I) The object for which the label is requested. */
    char**               label,           /**< (OF) The label representing the object application reference (appRef) path. */
    char**               version          /**< (OF) The version of the object. */
    );

/**
   Sets pie session option in plmxml export for given name and value.
   <br/>It will add a new PIE session option as "name:value" pair.
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CXPOM_invalid_tag if @p session is not valid Session.
   <li>#PIE_invalid_input_session_option if @p option_name or @p option_value is null.
   </ul>
*/
extern PIE_API int PIE_session_set_session_option(
    const tag_t        session,         /**< (I) Unique identifier of the session. */
    const char*        option_name,     /**< (I) Session option name */
    const char*        option_value     /**< (I) Session option value */
    );
#ifdef __cplusplus
}
#endif

/** @} */

#include <pie/libpie_undef.h>

#endif

