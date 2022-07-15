/*
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2009.
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
*/
/**
    @file

    This header file declares all data types and constants to be used by the RDV
    (Repeatable Digital Validation) Application.
*/

/*  */

#ifndef TEAMCENTER_RDV_RDV_H
#define TEAMCENTER_RDV_RDV_H

#include <property/prop.h>
#include <ps/ps.h>
#include <tccore/item.h>

#include <rdv/librdv_exports.h>

/**
    @defgroup RDV Repeatable Digital Validation (RDV)

    This module provides an interface to common RDV functions, such as creating and manipulating RDV contexts,
    searching for instances within an RDV context, and interpreting search results. 
    These functions correspond to the functionality provided in the DesignContext application in
    Teamcenter Engineering and the View In Context functionality in Web Access.

    The prototypes for these functions are in rdv.h.

    RDV API return codes are defined in rdv_errors.h.

    The RDV module maintains a state that defines the currently active RDV context.
    Applications may use the RDV API to control the RDV context being active by
    obtaining and setting contexts as appropriate. 

    Many RDV functions are sensitive to Teamcenter Engineering preferences defined in \$TC_DATA/.iman_env or
    the corresponding user, group, or role preferences.
    Please refer to the documentation provided in \$TC_DATA/.iman_env for more detail.
    Preference values are automatically read upon calling the first RDV API call.
    If the preferences are changed during the Teamcenter Engineering session,
    the application may enforce a re-evaluation.

    <b>Common Return Values</b>

    <table>
    <tr><td>#BOM_invalid_tag                      </td><td>Input BOM window is a #NULLTAG</td></tr>
    <tr><td>#ITK_internal_error                   </td><td>Error in the Search Engine API layer.
                                                           Additional information may be found in the syslog file.</td></tr>
    <tr><td>#ITK_no_acs_license                   </td><td>No RDV license available.</td></tr>
    <tr><td>#RDV_cannot_add_null_tag              </td><td>Cannot add NULLTAGs to RDV contexts.</td></tr>
    <tr><td>#RDV_cannot_find_object               </td><td>Can't find object.</td></tr>
    <tr><td>#RDV_cannot_initialize_search_criteria</td><td>Can't instantiate Class.</td></tr>
    <tr><td>#RDV_cannot_retrieve_attr             </td><td>Can't retrieve attribute from object.</td></tr>
    <tr><td>#RDV_context_not_searchable           </td><td>An RDV search was requested in a non-searchable context.</td></tr>
    <tr><td>#RDV_illegal_parameter                </td><td>Conflicting input parameters:
                                                           <UL>
                                                           <LI>bom_window and product_item_rev<br>
                                                               The Product ItemRevision does not match the BOM window top line
                                                           <LI>bom_window and revision_rule<br>
                                                               The RevisionRule does not match the BOM window's revision rule
                                                           <LI>bom_window and variant_rule<BR>
                                                               The VariantRule does not match the BOM window's variant rule</td></tr>
    <tr><td>#RDV_invalid_composite_prop_name      </td><td>The evaluation of a Composite Property failed that is defined in
                                                           one of the following preferences:
                                                           <UL>
                                                           <LI>PortalDesignContextECObject.WorkPartProperties<br>
                                                               defining properties to add WorkParts affected by a change object 
                                                           <LI>PortalDesignContextProcess.WorkPartProperties<BR>
                                                               defining properties to add WorkParts affected by a process object
                                                           </UL>
                                                           Either a syntax error was detected or
                                                           a regular property name was invalid.
                                                           Additional information may be found in the syslog file.</td></tr>
    <tr><td>#RDV_invalid_composite_prop_type      </td><td>The evaluation of a Composite Property failed that is defined in 
                                                           one of the following preferences:
                                                           <UL>
                                                           <LI>PortalDesignContextECObject.WorkPartProperties<BR>
                                                               defining properties to add WorkParts affected by a change object
                                                           <LI>PortalDesignContextProcess.WorkPartProperties defining<BR>
                                                               properties to add WorkParts affected by a process object
                                                           </UL>
                                                           The Composite Property contains regular property, which is neither an 
                                                           [un]typed_relation nor an [un]typed_reference. Additional information
                                                           may be found in the syslog file.</td></tr>
    <tr><td>#RDV_invalid_context                  </td><td>An invalid RDV context was specified.
                                                           The context was not obtained by calling
                                                           #RDV_context_ask_context.</td></tr>
    <tr><td>#RDV_invalid_installation             </td><td>RDV is either not installed or
                                                           the installation is invalid or incomplete</td></tr>
    <tr><td>#RDV_maximum_exceeded                 </td><td>The maximum number of objects to add was exceeded.
                                                           The maximum is set with the 
                                                           PortalDesignContextMaxMatchingObjects preference.</td></tr>
    <tr><td>#RDV_object_not_found                 </td><td>The object was not fond in the current RDV context</td></tr>
    </table>

    @{
*/

#define TCTEMPDIR     "TC_TMP_DIR"
#define TCROOT        "TC_ROOT"

#define PATHSTR         "PATH"
#define EXE_EXT         ".exe"

#ifdef WNT
   #define PATH_SEP     "\\"
   #define PATHTERM     ";"
#else
   #define PATH_SEP     "/"
   #define PATHTERM     ":"
#endif

typedef int (*RDV_is_ia_function_t)(
    tag_t     bom_line,
    logical*  is_IA
    );

typedef void* RDV_search_engine_t;

typedef void* RDV_search_engine_id_t;

typedef void* RDV_context_t;

typedef int RDV_object_type_token;

#ifdef __cplusplus
extern "C"{
#endif


/**
    Saved Query Expression
*/
typedef struct
{
    tag_t saved_qry;            /**< The saved query used in saved query filter expression */
    unsigned int n_entries;     /**< The number of entries for saved query filter expression */
    char** entries;             /**< n_entries The entries for saved query filter expression */
    char** values;              /**< n_entries The values for saved query filter expression */
} RDV_saved_query_expression_t;

/**
    ItemRevision Expression. This can be used to search BOMLines in a structure using ItemRevisions.
*/
typedef struct
{
    unsigned int n_item_revisions;  /**< The number of ItemRevisions in the list filter expression. */
    tag_t* item_revisions;          /**< n_item_revisions ItemRevisions in the list filter expression. */
} RDV_item_revision_expression_t;

/**
    Translate Scope Search Expression
*/
typedef struct
{
    unsigned int n_occ_types;   /**< The number of occurrence types used in scope filter */
    char** ignore_occ_types;    /**< n_occ_types The occurrence types used as an attribute for scope filter */
} RDV_translate_scope_search_expression_t;

/**
    Translate Scope Search Expression with scope
*/
typedef struct
{
    int n_occ_types;            /**< The number of occurrence types used in scope filter */
    char** ignore_occ_types;    /**< n_occ_types The occurrence types used as an attribute for scope filter */
    int n_scoped_lines;         /**< The number of scoped BOMLines used in scope filter */
    tag_t *scoped_line;         /**< n_scoped_lines The scoped BOMLines used in scope filter */
} RDV_translate_scope_search_expression_with_scope_t;

/**
    Proximity Search Expression
*/
typedef struct
{
    double distance;                    /**< The proximity distance */
    unsigned int n_occ_thread_chain;    /**< The number of occurrence threads used for getting configured BOM lines for proximity search */
    char** occ_thread_chain;            /**< n_occ_thread_chain The occurrence threads used for getting configured BOMLines for proximity search */
} RDV_proximity_search_expression_t;

/**
    Occurrence Search Expression
*/
typedef struct
{
    unsigned int n_note_type;           /**< The number of note types for the occurrence filter */
    char** note_types;                  /**< n_note_type The note type strings for the occurrence filter */
    char** occ_qry_opr;                 /**< n_note_type The occurrence query operator used for the occurrence filter */
    char** occ_values;                  /**< n_note_type The occurrence search values for the occurrence filter */
} RDV_occurrence_search_expression_t;

/**
    Form Attribute Search Expression
*/
typedef struct
{
    unsigned int n_form_attr;       /**< The number of form attributes for the form attribute filter */
    char** is_item_form_flag;       /**< n_form_attr The logical variables in string form for the item form used in the form attribute filter */
    char** relation_type_names;     /**< n_form_attr The relation type names defined for the form attribute filter */
    char** form_type_names;         /**< n_form_attr The form types defined for the form attribute filter */
    char** form_attr_name;          /**< n_form_attr The names of the form attribute used for the form attribute filter */
    char** form_qry_opr;            /**< n_form_attr The query operators used in the form attribute filter */
    char** form_bool_val;           /**< n_form_attr The logical values for the form attribute filter */
    char** form_int_val;            /**< n_form_attr The integer values for the form attribute filter */
    char** form_double_val;         /**< n_form_attr The double values for the form attribute filter */
    char** form_string_val;         /**< n_form_attr The string values for the form attribute filter */
    char** form_date_val;           /**< n_form_attr The date values for the form attribute filter */
    char** form_uid_val;            /**< n_form_attr The uid values for the form attribute filter */
} RDV_form_attribute_search_expression_t;

/**
    InClass Attribute Search Expression
*/
typedef struct
{
    unsigned int n_class_attr;      /**< The number of inclass attributes for the InClass attribute filter */
    char** class_names;             /**< n_class_attr The class names used in the InClass attribute filter */
    int* class_attr_ids;            /**< n_class_attr The attribute ids used in the InClass attribute filter */
    char** class_attr_values;       /**< n_class_attr The attribute values used in the InClass attribute filter */
} RDV_inclass_attribute_search_expression_t;

/**
    Search by Size Expression
*/
typedef struct
{
    logical larger_than;            /**< The larger than logical variable used to populate search by size object */
    double diagonal_length;         /**< The diagonal length to populate search by size object */
} RDV_search_bysize_expression_t;

/**
    Box Zone Search Expression
*/
typedef struct
{
    unsigned int n_box_zone_instances;  /**< The number of box zone instances */
    tag_t* box_zones;                   /**< n_box_zone_instances The box zones defined for the given box zone search filter */
    char** boxzone_comp;                /**< n_box_zone_instances The box zone comparators to decide co-ordinates for a box are inside, outside or intersects */
} RDV_boxzone_search_expression_t;

/**
    The call will cause all preferences to be reinitialized as part of the next RDV ITK call.
    This call should be used after changing RDV preferences to activate the new settings.

    For example Web applications in RDV use this call to reset the currently active RDV context each time 
    a new HTML frame containing RDV action icons is loaded,
    e.g. for folders, envelopes, ItemRevisions, or Workflow Processes.
    This causes all preferences to refresh upon invoking the next RDV / Web function.
    Changes to user preference settings, e.g. the requested proximity search distance,
    will therefore be immediately effective in the next RDV / Web function
*/
extern RDV_API int RDV_init();

/**
    Sets the method being used to check if a BOMline is an Installation Assembly BOMline.
    There are 3 standard methods provided. 
    These methods can be configured using the PortalDesignContextIsInstallationAssemblyMethod preference:
    <UL>
    <LI>transformsComponents. Returns the 1st BOMLine that has at least one occurrence below it not
                              using the identity transformation matrix.
    <LI>isPrecise. Returns the 1st BOMLine representing an ItemRevisoin with a precise BOMViewRevision.
    <LI>hasIRType. Returns the 1st BOMLine representing an ItemRevision of the type specified in 
                   the preference PortalDesignContextIsInstallationAssemblyMethod.hasIRType.Type
    </UL>
*/
extern RDV_API int RDV_set_ia_method(
    RDV_is_ia_function_t    method_name    /**< (I) A pointer to the functions that is to be used to identify Installation Assemblies */
    );

/**
    Checks if a BOMLine is an Installation Assembly BOMLine by checking the transformation matrix for each component.
    It returns true if at least one occurrence below this BOMLine has a transformation matrix different than the identity matrix. 
*/
extern RDV_API int RDV_is_ia_by_transform(
    tag_t          bom_line,    /**< (I) The BOMLine that will be checked */
    logical*       is_ia        /**< (O) The verdict being returned */
    );

/**
    Checks if a BOMLine is an Installation Assembly BOMLine by checking for a precise BOMViewRevision. 
*/
extern RDV_API int RDV_is_ia_by_preciseness(
    tag_t          bom_line,    /**< (I) The BOMLine that will be checked */
    logical*       is_ia        /**< (O) The verdict being returned */
    );

/**
    Checks if a BOMLine is an Installation Assembly BOMLine by checking ItemRevision type against
    the value defined in the PortalDesignContextIsInstallationAssemblyMethod.hasIRType.Type preference. 
*/
extern RDV_API int RDV_is_ia_by_ir_type(
    tag_t          bom_line,    /**< (I) The BOMLine that will be checked */
    logical*       is_ia        /**< (O) The verdict being returned */
    );

/**
    Checks if a BOMLine is an Installation Assembly by checking the value of the property 
    on it defined by the preference PortalDesignContextIsInstallationAssemblyMethod.has_bomline_prop.name 
    against the value definaed by the preference 
    PortalDesignContextIsInstallationAssemblyMethod.has_bomline_prop.value
*/
extern RDV_API int RDV_is_ia_by_bomline_prop(
    tag_t          bom_line,    /**< (I) The BOMLine that will be checked */
    logical*       is_ia        /**< (O) The verdict being returned */
    );

/**
    Finds the parent Installation Assembly BOMLine among all parent BOMLines.
    <br/>The chain of BOMLines leading from the input BOMLine to the root of the tree is traversed
    according to the setting of the preference PortalDesignContextFindInstallationTreeWalkIncrement
    where -1 means down and 1 means up. For each BOMLinein this chain the currently active 
    #RDV_is_ia_function_t function is called. The function will return the 1st BOMLine for which the 
    #RDV_is_ia_function_t function returns TRUE. If no parent BOMLine matched the criteria,
    a #NULLTAG is returned.
*/
extern RDV_API int RDV_ask_installation_assembly(
    tag_t          bom_line,        /**< (I) The BOMLine to search the Installation Assembly for */
    tag_t*         ia_bom_line      /**< (O) The Installation Assembly BOMLine for the input bom_line */
    );

/**
    Processes Teamcenter Engineering objects to add them to the RDV context.
    <br/>Depending on the preference values for:
    <UL>
    <LI>PortalDesignContextECObject.TYPE
    <LI>PortalDesignContextECObject.WorkPartProperties
    <LI>PortalDesignContextECObject.WorkPartRelationships
    <LI>PortalDesignContextExcludedWorkPart.Types
    <LI>PortalDesignContextProductItemProperties
    <LI>PortalDesignContextProcess.WorkPartProperties
    <LI>PortalDesignContextProcess.WorkPartOrChangeAttachmentTypes
    </UL>
    Additional objects may be automatically added along with the input object.
*/
extern RDV_API int RDV_context_add_object(
    tag_t          obj,                 /**< (I) The object that is to be added to the currently active RDV context */
    int*           n_added_objects,     /**< (O) The number of objects that were added to the currently active
                                            RDV context as a result of this call */
    tag_t**        added_objects        /**< (OF) n_added_objects The objects that were added to the currently
                                            active RDV context as a result of this call */
    );


/**
    Releases memory allocated to the currently active context.
    <br/>The context is set to NULL as a result to this call.
    It is safe to call this on NULL contexts. 

    As an example, Web applications in RDV use this call to reset the currently active RDV context
    each time a new HTML frame containing RDV action icons is loaded,
    e.g. for folders, envelopes, ItemRevisions, or Workflow Processes.
    This releases any resources, e.g. memory, allocated to a potentially existing RDV context

    <b>Restrictions:</b>

    You should not call this function if there are references to the current context held outside the RDV ITK module.
    Calling #RDV_context_clear will invalidate these references. Use RDV_context_set_context(NULL) instead.
*/
extern RDV_API int RDV_context_clear();

/**
    Retrieves a reference to the RDV search engine of the currently active RDV context. 

    <b>Restrictions: </b>
    You should either specify the parameters product_item_rev, revision_rule,
    and variant_rule, or the bom_window parameter. 
    If you specify both sets of parameters, the call will not complete successfully if the
    input parameters are conflicting (e.g. product_item_rev does not correspond to the provided bom_window).
    You may use #NULLTAG for parameters you don't want to set.
*/
extern RDV_API int RDV_find_search_engine(
    tag_t                product_item_rev,  /**< (I) The ItemRevision of the product for which a search engine is to be instantiated */
    tag_t                revision_rule,     /**< (I) The revision rule for which the requested search engine should be valid,
                                                    if NULL, the default revision rule will be assumed */
    tag_t                variant_rule,      /**< (I) The variant rule for which the requested search engine should be valid.
                                                    May be NULL. */
    tag_t                bom_window,        /**< (I) The BOM window for which a search engine is to be instantiated */
    RDV_search_engine_t* search_engine      /**< (OF) A reference to the requested search engine */
    );

/**
    Retrieves a reference to the RDV search engine ID. 
    <br/>This ID can be used as input to Search Engine API calls, e.g. QPL API
*/
extern RDV_API int RDV_search_engine_ask_id(
    RDV_search_engine_t     search_engine,  /**< (I) */
    RDV_search_engine_id_t* id              /**< (O) The identifier of the currently active search engine */
    );

/**
    Provides a convenient interface to perform a default search on the currently active context.
    <br/>This call will search for all WorkPart instances and their near-by component instances
    within the distance provided in the preference WebDesignContextDefaultSearchDistance.

    This call is based on lower level APIs to the search engine.
    It provides an abstraction layer hiding the implementation of the search engine,
    e.g. UG based QPL versus JT based QPL search engines, or PSE appearance search engines. 

    This call provides a detailed output in terms of various types of bomlines.
    BOMLines may basically be target or background BOMLines.
    It is further drilled down by this call into bomlines,
    which were found but could not be configured because of the revision rule,
    variant rule or effectivity settings.

    <b>Restrictions: </b>
    The call will fail, if the currently active RDV context is not proximity searchable.
    See also #RDV_context_is_proximity_searchable.
*/
extern RDV_API int RDV_context_default_prox_search(
    int*           n_target_bom_lines,                      /**< (O) */
    tag_t**        target_bom_lines,                        /**< (OF) n_target_bom_lines */
    int*           n_unconfigured_target_bom_lines,         /**< (O) */
    tag_t**        unconfigured_target_bom_lines,           /**< (OF) n_unconfigured_target_bom_lines */
    int*           n_unconfigurable_target_bom_lines,       /**< (O) */
    tag_t**        unconfigurable_target_bom_lines,         /**< (OF) n_unconfigurable_target_bom_lines */
    int*           n_background_bom_lines,                  /**< (O) */
    tag_t**        background_bom_lines,                    /**< (OF) n_background_bom_lines */
    int*           n_unconfigured_background_bom_lines,     /**< (O) */
    tag_t**        unconfigured_background_bom_lines,       /**< (OF) n_unconfigured_background_bom_lines */
    int*           n_unconfigurable_background_bom_lines,   /**< (O) */
    tag_t**        unconfigurable_background_bom_lines      /**< (OF) n_unconfigurable_background_bom_lines */
    );

/**
    Executes a search using the specified search engine.
*/
extern RDV_API int RDV_execute_search(
    RDV_search_engine_id_t  engine_id,          /**< (I) The ID of the search engine to use for this call.
                                                    A search engine can be instantiated by calling #RDV_find_search_engine.
                                                    If the currently active context is searchable (use #RDV_context_is_searchable)
                                                    the search engine can also be obtained by calling #RDV_context_ask_search_engine. 
                                                    The search engine ID is available through #RDV_search_engine_ask_id. */
    tag_t                   search_criteria,    /**< (I) The tag of the search criteria object. 
                                                    Usually this is a tag to a criteria group object. */
    int*                    n_results,          /**< (O) The number of search criteria matches */
    char***                 results             /**< (OF) n_results Search criteria matches. These matches can be
                                                    converted to BOM lines using #RDV_map_search_results_to_bom. */
    );

/**
    Finds out whether the currently active RDV context allows to search by proximity.
    <br/>For example Web applications in RDV use this call to determine whether or not to add a new action icon
    for DesignContext searches when a new HTML frame containing RDV action icons is loaded, 
    e.g. for folders, envelopes, ItemRevisions, or Workflow Processes. 
    <br/><br/>The following criteria will control whether or not a context is searchable:
    <UL>
    <LI>The context must at least contain one WorkPart. 
    <LI>The context must contain a Product ItemRevision
    <LI>If no RevisionRule is set, the default RevisionRule applies
    <LI>It must be possible to instantiate a search engine for the Product ItemRevision, RevisionRule, and VariantRule combination
    </UL>
*/
extern RDV_API int RDV_context_is_proximity_searchable(
    logical*       is_searchable    /**< (O) True if the currently active context is proximity searchable */
    );

/**
    Determines whether the currently active RDV context is searchable. 
    <br/>The following criteria will control whether or not a context is searchable:
    <UL>
    <LI>If the preference PortalDesignContextAllowNoWorkParts is set to 0, the context must at least contain one WorkPart. 
    <LI>The context must contain a Product ItemRevision
    <LI>If no RevisionRule is set, the default RevisionRule applies
    <LI>It must be possible to instantiate a search engine for the Product ItemRevision, RevisionRule, and VariantRule combination 
    </UL>
*/
extern RDV_API int RDV_context_is_searchable(
    logical*       is_searchable    /**< (O) True if the currently active context is searchable */
    );

/**
    Converts RDV search engine matches into BOM lines. 
    <br/>Converting search engine matches to configured BOM windows involves loading and 
    expanding the BOM tree as needed for the mapped results.

    RDV search engine matches are returned by calls to #RDV_execute_search.

    The call returns BOM lines in 3 different arrays. 

    The 1st array returns BOM lines corresponding to search results that were successfully mapped to the BOM window.

    The 2nd array returns BOM lines that were successfully mapped but are not valid for
    the configuration setting of the current BOM window with respect to effective date
    (Occurrence Effectivity) and/or variant option settings.
    This could be a result of searching for near-by components of the left hand drive steering column which
    might return the right hand drive glove box.
    Provided that a left hand drive variant rule is in effect the right hand drive glove box will be returned
    in the 2nd array in this case.

    The 3rd array returns BOM lines, which encountered error conditions during the process of being mapped to the BOMWindow.
    This could be the result of failing to configure a revision of the corresponding component Item or
    one of its parent Items if the structure was changed since the last update to the search index.
    Another reason could be that a component was removed from the structure since the search index was last updated.
    For each search result failing to map to the BOM window the closest successfully mapped parent is returned.
    This could mean that some parents are returned multiple times. 
    The following condition will always be met:

    n_search_results = n_bom_lines + n_unconfigured_bom_lines + n_unconfigurable_bom_lines
*/
extern RDV_API int RDV_map_search_results_to_bom(
    tag_t          bom_window,                  /**< (I) The BOM window to which the results are to be mapped.
                                                        If a #NULLTAG is passed, it will default to the search engine
                                                        BOMWindow as obtained by a call to #RDV_context_ask_bom_window. */
    int            n_stringsToMatch,            /**< (I) Number of search results to convert */
    const char**   stringsToMatch,              /**< (I) Search results to convert */
    int*           n_bomlines,                  /**< (O) Number of converted bom lines */
    tag_t**        bom_lines,                   /**< (OF) n_bomlines Converted bom lines */
    int*           n_unconfigured_matches,      /**< (O) BOM lines corresponding to search results, 
                                                        which don?t configure for the current effective date or variant rule. */
    tag_t**        unconfigured_matches,        /**< (OF) n_unconfigured_matches BOM lines corresponding to search results,
                                                        which don?t configure for the current effective date or variant rule. */
    int*           n_unconfigurable_bom_lines,  /**< (O) Number of search results corresponding to BOM lines for which
                                                        no revision configures or for which other errors were encountered. */
    tag_t**        unconfigurable_bom_lines     /**< (OF) n_unconfigurable_bom_lines BOM lines corresponding to 
                                                        search results for which no revision configures or for which
                                                        other errors were encountered. The BOM line on which the error
                                                        was encountered is given. This may be the BOM line that corresponds
                                                        to the search result or a parent BOM line thereof */
    );

extern RDV_API int RDV_get_unconf_bom_lines_indexes(
    int            n_bom_lines,                 /**< (I) */
    tag_t*         bom_lines,                   /**< (I) n_bom_lines */
    logical        shows_unconfigured_by_date,  /**< (I) */
    logical        shows_unconfigured_variants, /**< (I) */
    int*           n_indexes,                   /**< (O) */
    int**          indexes                      /**< (OF) n_indexes */
    );

/**
    Retrieves a reference to the currently active RDV context. 

    When building applications using this API you may use this call to obtain a reference to
    the currently active context in order swap it back in at a later time using #RDV_context_set_context.
    It is recommended to place a call to #RDV_context_set_context with a NULL object in order to avoid
    overwriting the obtained external reference to the RDV context by subsequent calls.

    A typical sequence of calls allowing for building a second context while maintaining
    a valid reference to the first context is shown below:

    @code
        ifail = RDV_context_ask_context( &context_1 );
        ifail = RDV_context_set_context( NULL );
        
        ifail = RDV_context_ask_context( &context_2 );
        ifail = RDV_context_set_context( context_1 );
    @endcode
*/
extern RDV_API int RDV_context_ask_context(
    RDV_context_t* rdv_context_object   /**< (O) Returns a reference to the currently active RDV context */
    );

/**
    Sets the currently active RDV context, replacing potentially existing context. 

    When building applications using this API you may use this call to swap in a previously created context.
    Calling #RDV_context_set_context with a NULL object will prevent external references to
    RDV contexts to be overwritten by subsequent calls

    At typical sequence of calls allowing for building a second context while maintaining 
    a valid reference to the first context is shown below:

    @code
        ifail = RDV_context_ask_context( &context_1 );
        ifail = RDV_context_set_context( NULL );
        
        ifail = RDV_context_ask_context( &context_2 );
        ifail = RDV_context_set_context( context_1 );
    @endcode

    <b>Restrictions: </b>

    The parameter rdv_context_object may by NULL.
    Otherwise it must have been obtained by an earlier call to #RDV_context_ask_context.
*/
extern RDV_API int RDV_context_set_context(
    RDV_context_t  rdv_context_object   /**< (I) The RDV context to set */
    );

/**
    Retrieves a reference to the BOM window used by the RDV search engine.
    If no BOM window exists yet, the BOM window will be created if the context is searchable.
*/
extern RDV_API int RDV_context_ask_bom_window(
    tag_t*         bom_window   /**< (O) The BOM window used by the RDV search engine */
    );

/**
    Sets the BOM window, which is to be used by the RDV search engine.
*/
extern RDV_API int RDV_context_set_bom_window(
    tag_t          bom_window   /**< (I) The BOM window to be used by the RDV search engine */
    );

/**
    Sets the RDV context objects, bypassing the additional logic in #RDV_context_add_object. 
*/
extern RDV_API int RDV_context_set_objects(
    int            n_objects,   /**< (I) The number of input objects */
    tag_t*         objects      /**< (O) n_objects The input object array may contain Items and ItemRevisions for
                                        WorkParts and Product Items, Workflow processes, Engineering Changes, 
                                        VariantRules and/or RevisionRules, Structure Context objects and
                                        Configuration Context objects. */
    );

/**
    Removes the object from the current RDV context. 
*/
extern RDV_API int RDV_context_remove_object(
    tag_t          object   /**< (I) The object to remove */
    );

/**
    Retrieves the list of objects in the current RDV context.
    <br/>The following type tokens are available to request only a subset of objects:
    <ul>
    <li>#RDV_object_type_all
    <li>#RDV_object_type_product_itemrev
    <li>#RDV_object_type_work_part_item
    <li>#RDV_object_type_eng_change
    <li>#RDV_object_type_workflow_process
    <li>#RDV_object_type_revision_rule
    <li>#RDV_object_type_variant_rule
    <li>#RDV_object_type_structurecontext
    <li>#RDV_object_type_configcontext
    </ul>
*/
extern RDV_API int RDV_context_ask_objects(
    RDV_object_type_token   type_token,     /**< (I) A token that specifies the object type of objects to return.
                                                Several tokens may be combined, 
                                                e.g. #RDV_object_type_product_itemrev | #RDV_object_type_work_part_item */
    int*                    n_objects,      /**< (O) The number of output objects */
    tag_t**                 objects         /**< (O) n_objects The output object array may contain WorkParts Items,
                                                Product ItemRevisions, Workflow processes, Engineering Changes,
                                                VariantRules, RevisionRules, Structure Context objects, and/or
                                                Configuration Context objects, depending on the provided type_token. */
    );

/**
    Retrieves a reference to the search engine of the current RDV context.
*/
extern RDV_API int RDV_context_ask_search_engine(
    RDV_search_engine_t*    search_engine   /**< (O) A reference to the currently active search engine */
    );

/**
    Retrieves the list of variant options that are variable for the provided list of BOM lines.
    <br/>The required variant rule tag may be obtained from #BOM_window_ask_variant_rules.
    All options in this rule that are not explicitly set by the user will be unset when the call returns.
    <br/>Use #BOM_variant_rule_delete to dispose of this variant rule once it will no longer be used.
*/
extern RDV_API int RDV_ask_variable_variant_options(
    int            n_bom_lines,         /**< (I) The number of input bom lines for which the set of
                                                variable variant options is to be returned */
    tag_t*         bom_lines,           /**< (I) n_bom_lines The input bom lines for which the set of variable variant options
                                                is to be returned */
    tag_t          variant_rule,        /**< (I) The variant rule to work with. This tag may be obtained from 
                                                #BOM_window_ask_variant_rules. All options not explicitly set by the
                                                user in this variant rule will be unset when the call returns. 
                                                <br/>Use #BOM_variant_rule_delete to dispose of this variant rule when
                                                it will not be used any longer. */
    int*           n_variant_options,   /**< (O) The number of output variant options */
    tag_t**        variant_options      /**< (OF) n_variant_options The output variant options */
    );

/**
    Retrieves the list of variant rules covering all valid variant overlays.
    The list is a complete list of variant rules for which at least one input BOMLine configures.
    Calls to this function may take a considerable amount of time. 
    The following preference may be used in order to limit the processing time:
    <UL>
    <LI>PortalDesignContextSetVariantRulesMaxTargetAppearances<BR>
        If the number of input bom lines given in n_bom_lines exceeds this limit, 
        the array being returned will be NULL.
    <LI>PortalDesignContextSetVariantRulesMaxVariantRules <BR>
        If the number of variant options relevant to the input bom line array bom_lines exceeds this limit,
        the array being returned will be NULL.
    </UL>
*/
extern RDV_API int RDV_ask_overlay_variant_rules(
    int            n_bom_lines,         /**< (I) The number of input bom lines for which the set of
                                            variant rules is to be returned */
    tag_t*         bom_lines,           /**< (I) n_bom_lines The input bom lines for which the set of variant rules is to be returned */
    int*           n_variant_rules,     /**< (O) The number of output variant rules */
    tag_t**        variant_rules        /**< (OF) n_variant_rules The output variant rules */
    );

extern RDV_API int RDV_export_config_nx_assembly(
    int            target_count,         /**< (I) */
    tag_t*         target_list,          /**< (I) target_count */
    int            background_count,     /**< (I) */
    tag_t*         background_list,      /**< (I) background_count */
    logical        checkout_targets,     /**< (I) */
    char*          naming_format,        /**< (I) */
    char**         zip_file_name,        /**< (OF) */ 
    char**         log_file_name         /**< (OF) */ 
    );

extern RDV_API int RDV_export_config_nx_structure(
    int            target_count,         /**< (I) */
    tag_t*         target_lines,         /**< (I) target_count */
    int            background_count,     /**< (I) */
    tag_t*         background_lines,     /**< (I) background_count */
    logical        checkout_targets,     /**< (I) */
    char*          naming_format,        /**< (I) */
    char**         zip_file_ticket,      /**< (OF) */ 
    char**         log_file_ticket       /**< (OF) */ 
    );

extern RDV_API int RDV_get_checkfilename_for_web(
    char**         check_file_name    /**< (OF) */
    );

/**
    Retrieves the BOM Lines that match the search criteria present in a context object.

    The mode parameter can take one of the following values:
    <ul>
    <li>#RDV_return_old_search_results - The structure context will be returned according to the state it was saved
    <li>#RDV_reevaluate_search_criteria - The structure context will be returned as a result of reevaluating the search criteria
    <li>#RDV_reevaluate_search_criteria
    </ul>
    The structure context will be returned as a result of reevaluating the search criteria.
    Newly added component instances will be considered when reevaluating the search criteria
*/
extern RDV_API int RDV_structurecontext_evaluate(
    tag_t          sco_tag,                             /**< (I) The structure context object */
    int            mode,                                /**< (I) One of the following: <br>
                                                            #RDV_return_old_search_results <br>
                                                            #RDV_reevaluate_search_criteria <br>
                                                            #RDV_reevaluate_search_criteria <br> */
    tag_t          bom_window,                          /**< (I) */
    int*           n_target_bom_lines,                  /**< (O) Number of target bom lines */
    tag_t**        target_bom_lines,                    /**< (OF) n_target_bom_lines Target bom lines */
    int*           n_unconfigured_target_bomlines,      /**< (O) Number of target BOM lines, which don?t configure for the 
                                                            current effective date or variant rule. */
    tag_t**        unconfigured_target_bomlines,        /**< (OF) n_unconfigured_target_bomlines Target BOM lines corresponding to
                                                            search results, which don?t configure for the 
                                                            current effective date or variant rule. */
    int*           n_unconfigurable_target_bom_lines,   /**< (O) Number of target BOM lines for which no revision configures or
                                                            for which other errors were encountered. */
    tag_t**        unconfigurable_target_bom_lines,     /**< (OF) n_unconfigurable_target_bom_lines Target BOM lines for which
                                                            no revision configures or for which other errors were encountered.
                                                            The BOM line on which the error was encountered is given.
                                                            This may be the actual background BOM line or a parent. */
    int*           n_bg_bom_lines,                      /**< (O) Number of background bom lines */
    tag_t**        bg_bom_lines,                        /**< (OF) n_bg_bom_lines Background bom lines */
    int*           n_unconfigured_bg_bomlines,          /**< (O) Number of background BOM lines, which don?t configure for
                                                            the current effective date or variant rule. */
    tag_t**        unconfigured_bg_bomlines,            /**< (OF) n_unconfigured_bg_bomlines Background BOM lines corresponding to
                                                            search results, which don?t configure for the current
                                                            effective date or variant rule. */
    int*           n_unconfigurable_bg_bom_lines,       /**< (O) Number of background BOM lines for which no revision configures or
                                                            for which other errors were encountered */
    tag_t**        unconfigurable_bg_bom_lines          /**< (OF) n_unconfigurable_bg_bom_lines Background BOM lines for which
                                                            no revision configures or for which other errors were encountered.
                                                            The BOM line on which the error was encountered is given.
                                                            This may be the actual background BOM line or a parent. */
    );

extern RDV_API int RDV_ask_search_engine_bv_type(
    tag_t*         bom_view_type    /**< (O) */
    );

extern RDV_API int RDV_add_design_to_ia(
    tag_t      component,                     /**< (I) */
    tag_t      ia_revision,                   /**< (I) */
    int        prod_rev_count,                /**< (I) */
    tag_t*     prod_rev_tags,                 /**< (I) */
    tag_t      arch_element_apn,              /**< (I) */
    int        a_count,                       /**< (I) */
    tag_t*     a_nves,                        /**< (I) */
    int        b_count,                       /**< (I) */
    tag_t*     b_nves,                        /**< (I) */
    int        n_requested_occurrences,       /**< (I) */
    int        n_lous,                        /**< (I) */  
    tag_t*     lous,                          /**< (I) */      
    tag_t**   apns_of_requested_occurrences   /**< (OF) */
    );

extern RDV_API int RDV_replace_design_in_product( 
    tag_t   component,                        /**< (I) */
    logical is_update,                        /**< (I) */
    int     bom_line_count,                   /**< (I) */
    tag_t*  bom_line_tags,                    /**< (I) */
    int     product_revision_count,           /**< (I) */
    tag_t*  product_revision_tags,            /**< (I) product_revision_count */
    tag_t   arch_apn_tag,                     /**< (I) */
    int     a_count,                          /**< (I) */
    tag_t*  a_nves,                           /**< (I) */
    int     b_count,                          /**< (I) */
    tag_t*  b_nves,                           /**< (I) */
    int     n_lou,                            /**< (I) */
    tag_t*  lous                              /**< (I) */
    );

extern RDV_API int RDV_update_occurrences_with_vc_in_product(
    int     bom_line_count,         /**< (I) */
    tag_t*  bom_lines,              /**< (I) bom_line_count */
    int     product_revision_count, /**< (I) */
    tag_t*  product_revision_tags,  /**< (I) product_revision_count */
    tag_t   arch_element_apn,       /**< (I) */
    int     a_count,                /**< (I) */
    tag_t  *a_nves,                 /**< (I) a_count */
    int     b_count,                /**< (I) */
    tag_t*  b_nves,                 /**< (I) b_count */
    int     n_lous,                 /**< (I) */
    tag_t*  lous                    /**< (I) n_lous */
    );


extern RDV_API int RDV_replace_ind_design_in_product(
    tag_t   component,          /**< (I) */
    tag_t   bomLine,            /**< (I) */
    int     prodRev_count,      /**< (I) */
    tag_t  *prodRev_tags,       /**< (I) */
    tag_t   arch_element_apn,   /**< (I) */
    int     a_count,            /**< (I) */
    tag_t  *a_nves,             /**< (I) */
    int     b_count,            /**< (I) */
    tag_t  *b_nves,             /**< (I) */
    int     n_lous,             /**< (I) */
    tag_t   *lous               /**< (I) */       
    );

extern RDV_API int RDV_replace_part_in_product(
    tag_t   component,                                    /**< (I) */
    tag_t   bomLine,                                      /**< (I) */
    tag_t   archApn_tag,                                  /**< (I) */
    int     a_count,                                      /**< (I) */
    tag_t  *a_nves,                                       /**< (I) */
    logical splitAndClone,                                /**< (I) */
    logical carrySubstitutes                              /**< (I) */
    );


extern RDV_API int RDV_replace_part_solution_in_product(
    tag_t   component,                                    /**< (I) */
    tag_t   bomLine,                                      /**< (I) */
    tag_t   abeAPN,                                       /**< (I) */
    int     n_authNVEs,                                   /**< (I) */
    tag_t  *authNVEs,                                     /**< (I) */
    logical splitAndClone,                                /**< (I) */
    logical carrySubstitutes,                             /**< (I) */
    int     quantity,                                     /**< (I) */
    int     n_noteTexts,                                  /**< (I) */ 
    char  **noteTypes,                                    /**< (I) */
    char  **noteTexts                                     /**< (I) */      
    );


extern RDV_API int RDV_remove_designs_from_ia(
    tag_t    productItem,                                 /**< (I) */
    int      n_comps_to_be_cut,                           /**< (I) */
    tag_t   *comps_to_be_cut                              /**< (I) */
    );


extern RDV_API int RDV_generate_PLMXML_file(
    int            numberOfBOMLines,    /**< (I) */
    int            numOfSelectedBL,     /**< (I) */
    tag_t*         bomLineTags,         /**< (I) numberOfBOMLines */
    tag_t*         selectedBLTags,      /**< (I) numOfSelectedBL */
    tag_t          bomWindow,           /**< (I) */
    char**         genFileName          /**< (OF) */
    );

extern RDV_API int RDV_getTempFileName(
    char*          prefix,          /**< (I) */
    char**         tempFileName     /**< (OF) */
    );

extern RDV_API void RDV_generate_tempfilename(
    char*           prefix,     /**< (I) */
    char**          fileName    /**< (OF) */
    );

/**
    Retrieves the type of a Search Criteria object.
*/
extern RDV_API int RDV_srch_crt_get_type(
    tag_t          scObjTag,    /**< (I) The tag of the search criteria instance */
    char**         type         /**< (OF) The type of the search criteria instance */
    );

/**
    Creates a Search Criteria Grouping object.
    <br/>It takes the tags of Search Criteria objects and attaches them to the Search Criteria Grouping object.
    The operator joining the individual search criteria is also taken and stored inside the Search Criteria Grouping object.
*/
extern RDV_API int RDV_grp_srch_crt_create(
    tag_t          typeTag,                 /**< (I) The object type tag for the search criteria object. 
                                                The type tag can be obtained by calling #TCTYPE_find_type,
                                                e.g. #TCTYPE_find_type( "ApprSearchCriteriaGroup",
                                                "ApprSearchCriteriaGroup", &my_type_tag ) */
    int            noOfSearchCriterias,     /**< (I) The number of search criteria that are to be grouped together */
    const tag_t*   search_criterias,        /**< (I) noOfSearchCriterias The search criteria that are to be grouped together */
    int            op,                      /**< (I) The logical operator with which the search criteria that are
                                                to be grouped together. Can be one of the following POM tokens: <br>
                                                #POM_and <br>
                                                #POM_or */
    tag_t*         scGrpObjTag              /**< (O) The resulting search criteria object.
                                                The object will not be persistently saved until you call #AOM_save. */
    );

/**
    Retrieves the Search Criteria objects from the Search Criteria Grouping object.
    <br/>This also retrieves the number of Search Criteria objects being referenced by the Grouping object and
    the operator used to combine them.
*/
extern RDV_API int RDV_grp_srch_crt_get_attrs(
    tag_t          scGrpObjTag,         /**< (I) The search criteria object */
    int*           op,                  /**< (O) The logical operator with which sub- criteria are grouped together.
                                                Can be one of the following POM tokens: <br> 
                                                #POM_and <br>
                                                #POM_or */
    int*           noOfSubCriteria,     /**< (O) The number of sub-criteria objects */
    tag_t**        subCriteria          /**< (OF) noOfSubCriteria Sub-criteria objects in this criteria grouping */
    );

/**
    Creates a Search Criteria Attribute object. 
    <br/>It takes the object type, attribute name, value and the operator and returns the tag of the
    resulting Attribute Filter Search Criteria object.
*/
extern RDV_API int RDV_attr_srch_crt_create(
    tag_t          typeTag,         /**< (I) The object type tag for the search criteria object.
                                        The type tag can be obtained by calling #TCTYPE_find_type, e.g. 
                                        #TCTYPE_find_type( "ApprSearchCriteriaAttribute",
                                        "ApprSearchCriteriaAttribute", &my_type_tag ) */
    const char*    name,            /**< (I) The name of the attribute to search by */
    const char*    value,           /**< (I) The required value */
    int            op,              /**< (I) The comparator. Can be a combination of one or more of:<br>
                                        #POM_not <br>
                                        #POM_is_equal_to <br>
                                        #POM_is_greater_than <br>
                                        #POM_is_less_than <br>
                                        #POM_is_null <br>
                                        #POM_is_like */
    tag_t*         scAttrObjTag     /**< (O) The resulting search criteria object.
                                        The object will not be persistently saved until you call #AOM_save. */
    );

/**
    Retrieves the name, value and operator from a Search Criteria Attribute Filter object.
*/
extern RDV_API int RDV_attr_srch_crt_get_attrs(
    tag_t          scAttrObjTag,    /**< (I) The attribute search criteria object */
    char**         name,            /**< (OF) The name of the attribute to search by */
    int*           op,              /**< (O) The comparator. Can be a combination of one or more of: <br> 
                                        #POM_not <br>
                                        #POM_is_equal_to <br>
                                        #POM_is_greater_than <br>
                                        #POM_is_less_than <br>
                                        #POM_is_null <br>
                                        #POM_is_like */
    char**         value            /**< (OF) The value this criterion requires */
    );

/**
    Creates a Search Criteria Mapped Attribute object.
    <br/>It takes the criteria object type, mapped attribute name and value
    (e.g. for a occurrence note), and the comparator.
    It retrieves the tag of the resulting Mapped Attribute Search Criteria object.
*/
extern RDV_API int RDV_mapattr_srch_crt_create(
    tag_t          typeTag,             /**< (I) The object type tag for the search criteria object.
                                            The type tag can be obtained by calling #TCTYPE_find_type, e.g. 
                                            #TCTYPE_find_type( "ApprSearchCriteriaMapAttr", 
                                            "ApprSearchCriteriaMapAttr", &my_type_tag ) */
    const char*    name,                /**< (I) The name of the attribute to search by */
    const char*    value,               /**< (I) The value this criterion requires */
    int            op,                  /**< (I) The comparator. Can be a combination of one or more of <br>
                                            #POM_not <br>
                                            #POM_is_equal_to <br>
                                            #POM_is_greater_than <br>
                                            #POM_is_less_than <br>
                                            #POM_is_null <br>
                                            #POM_is_like */
    tag_t*         scMappAttrObjTag     /**< (O) The resulting search criteria object. 
                                            The object will not be persistently saved until you call #AOM_save. */
    );

/**
    Retrieves the name, value and operator from a Search Criteria Mapped Attribute object.
*/
extern RDV_API int RDV_mapattr_srch_crt_get_attrs(
    tag_t          scMapAttrObjTag,     /**< (I) The mapped attribute search criteria object */
    char**         name,                /**< (OF) The name of the mapped attribute */
    int*           op,                  /**< (O) The comparator. Can be a combination of one or more of: <br>
                                                #POM_not <br>
                                                #POM_is_equal_to <br>
                                                #POM_is_greater_than <br>
                                                #POM_is_less_than <br>
                                                #POM_is_null <br>
                                                #POM_is_like */
    char**         value                /**< (OF) The required value for the mapped attribute */
    );

/**
    Creates a Search Criteria Form Attribute object.
    It takes the criteria object type, relation type, parent type, form type logical operator,
    property name, property type, comparator and value.
    
    It returns the tag of the resulting Form Attribute Search Criteria object.
**/
extern RDV_API int RDV_formattr_srch_crt_create(
    const char*     relationtype,       /**< (I) Type of Relation e.g "Reference" */
    int             parentType,         /**< (I) 1 if Item, 0 if Item Revision*/
    const char*     formType,           /**< (I) Form type */
    const char*     logicalOpr,         /**< (I) Logical operator, e.g "AND", "OR" */
    const char*     propertyName,       /**< (I) Name of the property*/
    const char*     mathOpr,            /**< (I) The comparator */
    const char*     propType,           /**< (I) Type of property, e.g. "StringType", "DateType"*/
    int             sizeOfValues,       /**< (I) Length of Array of strings*/
    const char**    value,                 /**< (I) sizeOfValues Array of strings*/
    tag_t*          scFormAttrObjTag    /**< (O) The resulting search criteria object. 
                                                 The object will not be persistently saved until you call #AOM_save. */
    );

/**
    Retrieves the relation type, parent type, form type logical operator,
    property name, property type, comparator and value from a Search Criteria Form Attribute object.
**/
extern RDV_API int RDV_formattr_srch_crt_get_attrs( 
    tag_t   scFormAttrObjTag,   /**< (I)  The form attribute search criteria object */
    char**  relationtype,       /**< (OF) Type of Relation e.g "Reference" */
    int*    parentType,         /**< (O)  1 if Item, 0 if Item Revision*/
    char**  formType,           /**< (OF) Form type */
    char**  logicalOpr,         /**< (OF) Logical operator, e.g "AND", "OR" */
    char**  propertyName,       /**< (OF) Name of the property*/
    char**  mathOpr,            /**< (OF) The comparator */
    char**  propType,           /**< (OF) Type of property, e.g. "StringType", "DateType"*/
    int*    sizeOfValues,       /**< (O)  Length of Array of strings*/
    char*** values              /**< (0F) sizeOfValues Array of strings*/
    );                                  

/**
    Creates a Search Criteria Named Zone object. 
    It takes the criteria object type, the name of the zone, and the comparator.
    It returns the tag of the resulting named zone search criteria object
*/
extern RDV_API int RDV_namedzone_srch_crt_create(
    tag_t          typeTag,             /**< (I) The object type tag for the search criteria object.
                                            The type tag can be obtained by calling #TCTYPE_find_type, e.g. 
                                            #TCTYPE_find_type( "ApprSearchCriteriaNamedZone", 
                                            "ApprSearchCriteriaNamedZone", &my_type_tag ) */
    const char*    name,                /**< (I) The name of the zone */
    int            op,                  /**< (I) The comparator. Can be either <br> 
                                            #RDV_above <br>
                                            #RDV_below <br>
                                            #RDV_intersects <br>
                                            #RDV_within <br>
                                            #RDV_outside <br>
                                            #RDV_interferes */
    tag_t*         scNamedZoneObjTag    /**< (O) The resulting search criteria object. 
                                            The object will not be persistently saved until you call #AOM_save. */
    );

/**
    Retrieves the name and operator from a Search Criteria Named Zone object.
*/
extern RDV_API int RDV_namedzone_srch_crt_get_attrs(
    tag_t          scNamedZoneObjTag,   /**< (I) The search criteria object */
    char**         name,                /**< (OF) The name of the zone */
    int*           comparator           /**< (O) The comparator. Can be either: <br>
                                                #RDV_above <br>
                                                #RDV_below <br>
                                                #RDV_intersects <br>
                                                #RDV_within <br>
                                                #RDV_outside <br>
                                                #RDV_interferes */
    );

/**    
    Creates a search criteria Box Zone object (type ApprSearchCriteriaBoxZone) with coordinates of the box and the comparator value.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#RDV_cannot_instantiate_class if the criteria cannot be created.
    </ul>
*/
extern RDV_API int RDV_boxzone_srch_crt_create(
    tag_t          type,                /**< (I) The object type tag for the search criteria object.
                                            <br/>The type can be obtained by invoking #TCTYPE_find_type
                                            e.g. TCTYPE_find_type( "ApprSearchCriteriaBoxZone", "ApprSearchCriteriaBoxZone", &my_type_tag ) */
    int            n_coordinates,       /**< (I) Expected to be 12 */
    const double*  coordinates,         /**< (I) n_coordinates (x,y,z) coordinates of a corner of the box and 3 vectors for the box edges. 
                                            Each of the vectors is expected in the form of (x,y,z) */
    int            comparator,          /**< (I) The comparator. Can be either of the following values defined in tctrushape.h: #TCTRUSHAPE_inside_box, #TCTRUSHAPE_outside_box, #TCTRUSHAPE_interferes_with_box */
    tag_t*         sch_box_zone_object   /**< (O) The resulting search criteria object. 
                                            <br/>The object will not be persistently saved until you call #AOM_save. */
    );

/**    
    Retrieves the coordinates and comparator from a Search Criteria Box Zone object.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#RDV_cannot_find_object if @p sch_box_zone_object is not a valid ApprSearchCriteriaBoxZone
    <li>#RDV_cannot_retrieve_attr if coordinates or ZoneComparator attribute cannot be retrieved
    </ul>
*/
extern RDV_API int RDV_boxzone_srch_crt_get_attrs(
    tag_t          sch_box_zone_object,  /**< (I) The search criteria object */
    int*           n_coordinates,       /**< (O) Expected to be 12 */
    double**       coordinates,         /**< (OF) n_coordinates (x,y,z) coordinates of a corner of the box and 3
                                                vectors for the box edges. Each of the vectors is expected in the form of (x,y,z) */
    int*           comparator           /**< (O) The comparator. Can be either of the following values defined in tctrushape.h: #TCTRUSHAPE_inside_box, #TCTRUSHAPE_outside_box, #TCTRUSHAPE_interferes_with_box */
    );

/**      
    Creates a search criteria Box Zone object with tags of boxes and the comparator value.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#RDV_cannot_initialize_search_criteria if required search criteria is not specified
    <li>#RDV_cannot_instantiate_class if ApprSearchCriteriaBoxZone cannot be instantiated
    </ul>
*/
extern RDV_API int RDV_boxzone_srch_crt_create_with_boxzones(
    tag_t          type,                /**< (I) The object type tag for the search criteria object.
                                            The type tag can be obtained by calling #TCTYPE_find_type, e.g. 
                                            #TCTYPE_find_type( "ApprSearchCriteriaBoxZone", "ApprSearchCriteriaBoxZone", &my_type_tag ) */
    int            n_box_zones,         /**< (I) Number of Box Zones */
    const tag_t*   box_zones,            /**< (I) n_box_zones List of Box Zone objects */
    logical        is_external_reference,          /**< (I) Boolean flag to indicate whether Box Zone objects are external referenced or not.
                                            In case of workset or subset, the Box Zone objects stored on form shall be external reference. 
                                            For other cases, the Box Zone objects stored on form shall be typed reference. */
    int            comparator,          /**< (I) The comparator. Can be either of the following values defined in tctrushape.h: #TCTRUSHAPE_inside_box, #TCTRUSHAPE_outside_box, #TCTRUSHAPE_interferes_with_box */
    tag_t*         sch_box_zone_object   /**< (O) The resulting search criteria object. 
                                            The object will not be persistently saved until you call #AOM_save. */
    );

/**    
    Retrieves the array of Box Zone objects and comparator from a Search Criteria Box Zone object.

    @returns 
    <ul>
    <li>#ITK_ok on success
    <li>#RDV_cannot_find_object if @p sch_box_zone_object is not a valid ApprSearchCriteriaBoxZone
    <li>#RDV_cannot_retrieve_attr if either attributes @c box_zones or @c comparator cannot be retrieved
    </ul>
*/
extern RDV_API int RDV_boxzone_srch_crt_get_boxzones_attrs(
    tag_t          sch_box_zone_object,  /**< (I)  The search criteria object */
    int*           n_box_zones,          /**< (O)  Number of Box Zones */
    tag_t**        box_zones,            /**< (OF) n_box_zones The Box Zone objects that constitute the search criteria */
    int*           comparator           /**< (O)  The comparator. Can be either of the following values defined in tctrushape.h: #TCTRUSHAPE_inside_box, #TCTRUSHAPE_outside_box, #TCTRUSHAPE_interferes_with_box */
    );
    
/**    
    Creates a search criteria Plane Zone object with coordinates of the Plane Zone and the comparator value.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#RDV_cannot_instantiate_class if ApprSearchCriteriaPlaneZone cannot be instantiated
    </ul>
*/
extern RDV_API int RDV_planezone_srch_crt_create(
    tag_t          type,                /**< (I) The object type tag for the search criteria object.
                                            The type tag can be obtained by calling #TCTYPE_find_type, e.g. 
                                            #TCTYPE_find_type( "ApprSearchCriteriaPlaneZone",
                                            "ApprSearchCriteriaPlaneZone", &my_type_tag ) */
    int            n_coordinates,       /**< (I) Expected to be 6 */
    const double*  coordinates,         /**< (I) n_coordinates x,y,z coordinates of a point, and 3 coordinates for the normal vector */
    int            comparator,          /**< (I) The comparator. Can be either of the following values defined in tctrushape.h: #TCTRUSHAPE_above_plane, #TCTRUSHAPE_below_plane, #TCTRUSHAPE_interferes_with_plane  */
    tag_t*         sch_planezone_object /**< (O) The resulting search criteria object. This object will not be persistently saved until you call #AOM_save. */
    );

/**    
    Retrieves the coordinates of Plane Zone and comparator from a Search Criteria Plane Zone object.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#RDV_cannot_find_object if @p sch_planezone_object is not a valid ApprSearchCriteriaPlaneZone
    <li>#RDV_cannot_retrieve_attr if coordinates or ZoneComparator attribute cannot be retrieved
    </ul>
*/
extern RDV_API int RDV_planezone_srch_crt_get_attrs(
    tag_t          sch_planezone_object, /**< (I) The search criteria object */
    int*           n_coordinates,        /**< (O) Expected to be 6 */
    double**       coordinates,          /**< (OF) n_coordinates x,y,z coordinates of a point,
                                             and 3 coordinates for the normal vector */
    int*           comparator            /**< (O) The comparator. Can be either of the following values defined in tctrushape.h: #TCTRUSHAPE_above_plane, #TCTRUSHAPE_below_plane, #TCTRUSHAPE_interferes_with_plane  */
    );

/**    
    Creates a search criteria Plane Zone object with list of planes and the comparator value.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#RDV_cannot_initialize_search_criteria if required search criteria is not specified
    <li>#RDV_cannot_instantiate_class if ApprSearchCriteriaPlaneZone cannot be instantiated
    </ul>
*/
extern RDV_API int RDV_planezone_srch_crt_create_with_planezones(
    tag_t          type,                  /**< (I) The object type tag for the search criteria object.
                                            The type tag can be obtained by calling #TCTYPE_find_type, e.g. 
                                            #TCTYPE_find_type( "ApprSearchCriteriaPlaneZone",
                                            "ApprSearchCriteriaPlaneZone", &my_type_tag ) */
    int            n_plane_zones,         /**< (I) Number of PlaneZone tags */
    const tag_t*   plane_zones,           /**< (I) n_plane_zones List of Plane Zone objects */
    logical        is_external_reference, /**< (I) Indicates whether the Box Zone objects are external referenced.
                                            <br/>In case of workset or subset, the Box Zone objects stored on Form will be an external reference. 
                                            <br/>For all other cases, the Box Zone objects stored on Form will be a typed reference. */    
    int            comparator,            /**< (I) The comparator. Can be either of the following values defined in tctrushape.h: #TCTRUSHAPE_above_plane, #TCTRUSHAPE_below_plane, #TCTRUSHAPE_interferes_with_plane  */
    tag_t*         sch_planezone_object   /**< (O) The resulting search criteria object. 
                                            <br/>The object will not be persistently saved until you call #AOM_save. */
    );

/**    
    Retrieves the array of Plane Zone tags and comparator from a Search Criteria Plane Zone object.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#RDV_cannot_find_object if @p sch_planezone_object is not a valid ApprSearchCriteriaPlaneZone
    <li>#RDV_cannot_retrieve_attr if either attributes @c plane_zones or @c comparator cannot be retrieved
    </ul>
*/
extern RDV_API int RDV_planezone_srch_crt_get_planezones_attrs(
    tag_t          sch_planezone_object, /**< (I)  The search criteria object */
    int*           n_plane_zones,        /**< (O)  Number of PlaneZone tags */         
    tag_t**        plane_zones,           /**< (OF) n_plane_zones The Plane Zone objects that constitute the search criteria */
    int*           comparator            /**< (O) The comparator. Can be either of the following values defined in tctrushape.h: #TCTRUSHAPE_above_plane, #TCTRUSHAPE_below_plane, #TCTRUSHAPE_interferes_with_plane  */
    );
    
/**
    Creates a Search Criteria Proximity object.
    It takes in tags of search criteria appearance objects that correspond to
    the selection states of the target and background appearances.
    It also takes in the proximity distance.
*/
extern RDV_API int RDV_prox_srch_crt_create(
    tag_t          typeTag,             /**< (I) The object type tag for the search criteria object.
                                            The type tag can be obtained by calling #TCTYPE_find_type, e.g. 
                                            #TCTYPE_find_type( "ApprSearchCriteriaProximity",
                                            "ApprSearchCriteriaProximity", &my_type_tag ) */
    double         distance,            /**< (I) Search distance in units according to the top level assembly */
    tag_t          targetAppearance,    /**< (I) The "ApprSearchCriteriaSlctState" object storing selected and
                                            non-selected target appearances */
    tag_t          bgAppearance,        /**< (I) The "ApprSearchCriteriaSlctState" object storing selected and 
                                            non-selected background appearances */
    tag_t*         scProximityObjTag    /**< (O) The search criteria object. This object will not be persistently saved until #AOM_save is invoked. */
    );

/**
    Retrieves the distance and search criteria appearance tags,
    which represent the selection states of target and background appearances
    at the time of saving the Structure Context object.
*/
extern RDV_API int RDV_prox_srch_crt_get_attrs(
    tag_t          scProximityObjTag,   /**< (I) The search criteria object */
    double*        distance,            /**< (O) The search distance */
    tag_t*         targetAppearance,    /**< (O) The "ApprSearchCriteriaSlctState" object storing selected and 
                                            non-selected target appearances */
    tag_t*         bgAppearance         /**< (O) The "ApprSearchCriteriaSlctState" object storing selected and 
                                            non-selected background appearances */
    );

/**
    Creates a Search Criteria Saved Query object.
    It takes in the entries and values of the Saved Query along with the Saved Query name and
    returns the tag of the resulting Saved Query Search Criteria object.
*/
extern RDV_API int RDV_savedqry_srch_crt_create(
    tag_t          typeTag,         /**< (I) The object type tag for the search criteria object.
                                        The type tag can be obtained by calling #TCTYPE_find_type, e.g. 
                                        #TCTYPE_find_type( "ApprSearchCriteriaSavedQry", 
                                        "ApprSearchCriteriaSavedQry", &my_type_tag ) */
    const char*    queryName,       /**< (I) The name of the saved query */
    int            noOfInstances,   /**< (I) The number of user entries for the saved query */
    const char**   entries,         /**< (I) noOfInstances The list of user entries for the saved query */
    const char**   values,          /**< (I) noOfInstances The required values for the saved query */
    tag_t*         scSQObjTag       /**< (O) The resulting search criteria object. 
                                        The object will not be persistently saved until you call #AOM_save. */
    );

/**
    Retrieves the Saved Query name and
    the user entries and values from a Saved Query Search Criteria object.
*/
extern RDV_API int RDV_savedqry_srch_crt_get_attrs(
    tag_t          scSQObjTag,      /**< (I) The search criteria object */
    char**         sqName,          /**< (OF) The name of the saved query */
    int*           noOfEntries,     /**< (O) The number of user entries for the saved query */
    char***        entries,         /**< (OF) noOfEntries The list of user entries for the saved query */
    char***        values           /**< (OF) noOfEntries The required values for the saved query */
    );

/**
    Creates a Search Criteria Classification object.
    It takes in the IcsClass, icsOprions and unct information and stores them
    inside the Search Criteria Classification object.
*/
extern RDV_API int RDV_inclass_srch_crt_create(
    tag_t          typeTag,             /**< (I) The object type tag for the search criteria object.
                                            The type tag can be obtained by calling #TCTYPE_find_type, e.g. 
                                            #TCTYPE_find_type( "ApprSearchCriteriaInClass", 
                                            "ApprSearchCriteriaInClass", &my_type_tag ) */
    tag_t          icsClass,            /**< (I) Classification class name */
    int            icsOptions,          /**< (I) Classification options */
    int            noOfUncts,           /**< (I) Number of Classification attribute IDs */
    const int*     uncts,               /**< (I) noOfUncts List of Classification attribute IDs */
    const char**   unctValues,          /**< (I) noOfUncts List of Classification attribute values (incl. comparator). */
    tag_t*         scInClassObjTag      /**< (O) The resulting search criteria object. 
                                            The object will not be persistently saved until you call #AOM_save. */
    );

/**
    Retrieves attribute information from Search Criteria Classification Filter object.
*/
extern RDV_API int RDV_inclass_srch_crt_get_attrs(
    tag_t          scInClassObjTag,     /**< (I) The search criteria object */
    tag_t*         icsClass,            /**< (O) Classification class name */
    int*           icsOptions,          /**< (O) Classification options */
    int*           noOfUncts,           /**< (O) Number of Classification attribute IDs */
    int**          uncts,               /**< (OF) noOfUncts List of Classification attribute IDs */
    char***        unctValues           /**< (OF) noOfUncts List of Classification attribute values (incl. comparator) */
    );

/**
    Creates a Search Criteria Appearance object.
    It takes tag arrays of selected and unselected appearances.
    It returns the tag of search criteria appearance object tag created.
*/
extern RDV_API int RDV_appr_srch_crt_create(
    tag_t          typeTag,                       /**< (I) The object type tag for the search criteria object.
                                                      The type tag can be obtained by calling #TCTYPE_find_type, e.g. 
                                                      #TCTYPE_find_type( "ApprSearchCriteriaSlctState", "ApprSearchCriteriaSlctState", &my_type_tag ) */
    int            noOfSelectedApnsOrBOMLines,    /**< (I) Number of selected appearances */
    const tag_t*   selectedApnsOrBOMLines,        /**< (I) noOfSelectedBOMlines Selected appearances */
    int            noOfUnSelectedApnsOrBOMLines,  /**< (I) Number of unselected appearances */
    const tag_t*   unSelectedApnsOrBOMLines,      /**< (I) noOfUnselectedBOMLines Unselected appearances */
    tag_t*         scAppearancesObjTag            /**< (O) The resulting search criteria object. 
                                                      The object will not be persistently saved until you call #AOM_save. */
    );

/**
    Retrieves the selected and unselected appearances at the time of saving this object.
    This is used by DesignContext Application to replay a filter.
*/
extern RDV_API int RDV_appr_srch_crt_get_attrs(
    tag_t          scAppearancesObjTag,     /**< (I) The search criteria object */
    int*           noOfSelectedBOMlines,    /**< (O) Number of selected appearances */
    tag_t**        selectedBOMLines,        /**< (OF) noOfSelectedBOMlines Selected appearances */
    int*           noOfUnselectedBOMlines,  /**< (O) Number of unselected appearances */
    tag_t**        unselectedBOMLines       /**< (OF) noOfUnselectedBOMlines Unselected appearances */
    );

/**
    Retrieves the BOMLines for an array of appearance pathnode UID's
    <br/>This method takes APN UID in the format ""xysadretw7rtye""   instead of 
    "xysadretw7rtye"
*/
extern RDV_API int RDV_getbomlinesfromapprpathnodeUIDs(
    char**         appr_path_node_uid,  /**< (I) Input ApprPathNodes */ 
    int            localapprUIDLength,  /**< (I) Number of input ApprPathNodes*/ 
    tag_t          bomWindow,           /**< (I) Input BOMWindow */ 
    tag_t**        bomlines,            /**< (OF) Output array containing BOMLines */ 
    int*           bomlineCount         /**< (O) Count of output BOMLines */ 
    );

/**
   Retrieves the bomlines for an array of absolute occurrence Ids.
*/
extern RDV_API int RDV_getbomlinesfromAbsoluteOccUIDs(
    char **absolute_occurrence_uids,        /**< (I) Array of Abs Occ UIDs */ 
    int num_of_absolute_occurrence_uids,    /**< (I) Length of array of abs occ uids */ 
    tag_t bomWindow,                        /**< (I) input BOMWindow */ 
    tag_t **bomlines,                       /**< (OF) Output array containing BOMLines */ 
    int *bomlineCount                       /**< (O) Count of output BOMLines */ 
    );

/**
    Parses the inputFile and returns the values of a
    particular column where column name is also input
*/ 
extern RDV_API int RDV_parseFile(
    char*          inputFile,           /**< (I) */
    char*          input,               /**< (I) */
    char***        inputValueArray,     /**< (OF) length */
    int*           length               /**< (O) */
    );

/**
    Parses the input file and returns the FileHeader as tokens.
*/  
extern RDV_API int RDV_parseFileHeader(
    char*          inputFile,   /**< (I) */
    char***        sub_tokens,  /**< (O) */
    int*           length       /**< (O) */
    );

/**
    Retrieves the Preference Values provided the Preference name
    is the input
*/  
extern RDV_API int RDV_get_site_pref_values(
    const char*    pref_name,           /**< (I) */
    int*           num_pref_values,     /**< (O) */
    char***        pref_values          /**< (OF) num_pref_values */
    );

/**
    Tokenises the String based on the delimeter supplied.This method
    parses the string character by character basis
*/ 
extern RDV_API void RDV_string_tokenizer (
    char*           string,             /**< (I) */
    char            delimit,            /**< (I) */
    int*            count,              /**< (O) */
    char***         t                   /**< (OF) count*/
    );

/**
    Parses a specific file and converts the complete file
    into a single array
*/
extern RDV_API int RDV_getIssues(
    char*          resultsFile,     /**< (I) */
    char***        issuesArray,     /**< (OF) issuesArrayLen */
    int*           issuesArrayLen   /**< (O) */
    );

/**
    Converts a string operator into an integer
    operator to be used by Trushape module.
*/
extern RDV_API int RDV_retrieve_trushape_operator_for_app_search(
    char*          op              /**< (I) */
    );

/**
    Creates a Named Variant Expression based on code(unique name), description,
    constituent variant Expressions, operator and comment.
*/
extern RDV_API int RDV_named_variant_expr_create(
    const char*    code,        /**< (I) */
    const char*    desc,        /**< (I) */
    tag_t          var1,        /**< (I) */
    tag_t          var2,        /**< (I) */
    int            op,          /**< (I) */
    const char*    comment,     /**< (I) */
    tag_t*         newNVETag    /**< (O) */
    );
extern RDV_API int RDV_create_nve_from_formula
    ( const char*   code,               /**< (I) */  
      const char*   desc,               /**< (I) */
      const char*   productName,        /**< (I) */
      const char*   productNamespace,   /**< (I) */
      const char*   formula,            /**< (I) */
      int           op,                 /**< (I) */
      const char*   comment,            /**< (I) */
      tag_t*        newNVETag           /**< (O) */
    );

/**
    Retrieves the constituent attributes from a Named Variant Expression Object.
*/
extern RDV_API int RDV_named_variant_expr_get_attrs(
    tag_t          nveObjTag,       /**< (I) */
    char**         code,            /**< (OF) */
    char**         desc,            /**< (OF) */
    int*           fp,              /**< (O) */
    tag_t*         var1,            /**< (O) */
    tag_t*         var2,            /**< (O) */
    int*           op,              /**< (O) */
    char**         comment,         /**< (OF) */
    int*           no_of_literals,  /**< (O) */
    tag_t**        literals         /**< (OF) no_of_literals */
    );


extern RDV_API int RDV_get_valid_overlay_bom_lines(
    const logical show_unconfigured_variant, /**< (I) */
    const logical show_unconfigured_by_date, /**< (I) */
    const int      n_variant_rules,          /**< (I) */
    const tag_t  * variant_rules,            /**< (I) */
    int    * n_backgrnd_bomlines,            /**< (I/O) */
    tag_t  * backgrnd_bomlines,              /**< (I/O) */
    int    * n_unconfigured_bom_lines,       /**< (O) */
    tag_t ** unconfigured_bom_lines          /**< (OF) */
    );    


/**
    Adds a part to a Generic Object Element's structure.
*/
extern RDV_API int RDV_add_part_to_product(
    tag_t         component,              /**< (I) */
    tag_t         genericObjectBOMLine,   /**< (I) */
    int           prodRev_count,          /**< (I) */
    tag_t*        prodRev_tags,           /**< (I) prodRev_count */
    tag_t         goApn_tag,              /**< (I) */
    int           a_count,                /**< (I) */
    tag_t*        a_nves,                 /**< (I) a_count */
    int           quantity,               /**< (I) */
    tag_t*        occurrence              /**< (O) */
    );

/**
    Adds a part along with the part data.
*/
extern RDV_API int RDV_add_part_solution_to_product(
    tag_t         component,              /**< (I) */
    tag_t         genericObjectBOMLine,   /**< (I) */
    int           prodRev_count,          /**< (I) */
    tag_t*        prodRev_tags,           /**< (I) prodRev_count */
    tag_t         goApn_tag,              /**< (I) */
    int           a_count,                /**< (I) */
    tag_t*        a_nves,                 /**< (I) a_count */
    int           quantity,               /**< (I) */
    int           n_note_text,            /**< (I) */
    char**        note_text,              /**< (I) */
    char**        note_types,             /**< (I) */
    tag_t*        occurrence              /**< (O) */
    );


extern RDV_API int RDV_execute_workparts_query(
    char    *item_id,                                   /**< (I) */
    int     *n_instances,                               /**< (O) */
    tag_t   **instances                                 /**< (OF) n_instances */
    );

extern RDV_API int RDV_execute_processes_query(
    char     *object_name,                               /**< (I) */
    int      *n_instances,                               /**< (O) */
    tag_t    **instances                                 /**< (OF) n_instances */     
    );

extern RDV_API int RDV_execute_eng_change_query(
    char     *item_id,                                   /**< (I) */
    char     *item_revision_id,                          /**< (I) */
    int      *n_instances,                               /**< (O) */
    tag_t    **instances                                 /**< (OF) n_instances */     
    );


/**
    Copies a BOM Line and uses the following input preferences to determine how the copy should be performed:
    <ul>
    <li>whether substitutes should be carried forward
    <li>whether the new line should be added as a substitute of the original
    <li>whether transformation information should be carried forward
    </ul>

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#RDV_cannot_find_object if the object is not found.
    <li>#RDV_illegal_parameter if the supplied input parameters are invalid.
    </ul>
*/
extern RDV_API int RDV_bomline_copy(
    tag_t        parent_line,           /**< (I) Tag of the parent bomline to be copied */
    tag_t        child_line,            /**< (I) Tag of the child bomline to be copied */
    logical      carry_substitutes,     /**< (I) Flag to specify whether substitutes should be carried forward */
    logical      as_substitute,         /**< (I) Flag to specify whether the new line should be added as a substitute of the original */
    logical      copy_xform,            /**< (I) Flag to specify whether transformation information should be carried forward */
    const char*  occ_type,              /**< (I) Specifies the occurrence type */
    tag_t*       new_line               /**< (O) Tag of the newly created bomline */
    );
     
extern RDV_API int RDV_bomline_replace_with_substitutes(
    tag_t *  bomLine,                        /**< (I/O) */
    tag_t *  item,                           /**< (I) */
    tag_t *  itemRevision                    /**< (I) */
    );
    
extern RDV_API int RDV_bomline_substitute_with_alternates(
    tag_t *  bomLine,                        /**< (I/O) */
    tag_t *  item,                           /**< (I) */
    tag_t *  itemRevision                    /**< (I) */
    );

extern RDV_API int RDV_add_with_touchpoint(
    tag_t   parentTag,                        /**< (I) */
    tag_t   componentTag,                     /**< (I) */
    logical processParents,                   /**< (I) */
    logical processChildren                   /**< (I) */
    );

extern RDV_API int RDV_get_bomline_prop_chain( 
    tag_t          bomLine,                 /**< (I) */
    char          *bomLineProp,             /**< (I) */
    logical        is_string_prop,          /**< (I) */
    logical        is_reference_prop,       /**< (I) */
    int           *noOfProps,               /**< (O) */
    char        ***props,                   /**< (OF) noOfProps */
    int           *noOfBomLines,            /**< (O) */
    tag_t        **bomLines                 /**< (OF) noOfProps */
    );

extern RDV_API int RDV_check_user_privilege(
   tag_t   obj_tag,                  /**< (I) */
   tag_t   user_tag                  /**< (I) */
    );

extern RDV_API int RDV_is_installation_assembly(
    tag_t  bomLine,        /**< (I) */
    logical *is_ia         /**< (O) */
    );


/**
   Creates a variant expression block.
   <ul>
   <li>In a non-MFK (Multifield key) environment, the parameter "item_info" contains the Item ID.
   <li>In an MFK environment, the parameter "item_info" contains the key of any item which uniquely identifies the Item.
   <br>The key is a delimited string which contains name/value pairs of Item attributes separated by the ',' character, usually of the form attr1=value1,attr2=value2.... etc, where attr1, attr2 are property internal names (e.g. "item_id=GMC00723,object_name=topitem,object_type=Item").
   <br>To include a delimiter character ( e.g. ',' '=') in a name or value, the character should be escaped with the '\' character. E.g.:
   <ul>
   <li>if the item ID contains an equals sign (123=456), the key string would be: "item_id=123\=456,object_type=Document".
   <li>if the item ID contains an comma (123,456), the keys tring would be: "item_id=123\,456,object_type=Document".
   <li>if the item ID contains a backslash (123\\456), the keystring would be: "item_id=123\\456,object_type=Document".
   </ul>
   </ul>

   @returns
   <ul>
   <li>#ITK_ok on success.</li>
   <li>#ITEM_multiple_items_returned, if multiple items are found with the value provided for the "item_info" parameter.</li>
   <li>#BOM_no_variant_name, if input parameter option_name is null.</li>
   <li>#BOM_invalid_tag, Invalid tag received by BOM Module.</li>
   </ul>
*/ 
extern RDV_API int RDV_set_option_values(
     char*   item_info,                    /**< (I) Item key (in MFK enviroment) or Item ID */
     char*   option_name,                  /**< (I) Name of Option */
     char*   option_value,                 /**< (I) Value of Option */
     tag_t   *var_exp_block                /**< (O) tag of Variant Expression Block */
    );

extern RDV_API int RDV_create_base_options( 
     tag_t        product,                    /**< (I) */ 
     const char  *option_name,                /**< (I) */ 
     const char  *option_value,               /**< (I) */ 
     tag_t       *opt_tag,                    /**< (O) */ 
     tag_t       *opt_rev                     /**< (O) */ 
    );


/**
   Produces a one-to-one string representation that is not dependent on any environment settings
  This string won't be human readable. Use BOM_variant_expression_as_text if you want that
  we want to avoid calling BOM_variant_expression_as_text( ve, as_text ) ) for three reasons:
  <ul>
  <li>it sets strange parenthesis
  <li>the as text representation may be internationalized (e..g the operator string)
  <li>PSE may have turned off the ItemID prefix preference "PSE_show_option_item_prefix"
  </ul>
 */
extern RDV_API int RDV_variant_expression_as_text(
    tag_t   ve,                     /**< (I) */
    char ** as_text                 /**< (O) */
    );

extern RDV_API int RDV_ask_variant_xo_table_data(
    int           n_ves,               /**< (I) */
    const tag_t * ves,                 /**< (I) n_ves */
    int *         n_column_headers,    /**< (O) */
    tag_t **      column_header_exprs, /**< (OF) n_column_headers */
    char  ***     column_header_strs,  /**< (OF) n_column_headers as string */
    int *         n_ves_2_save,        /**< (O) */
    tag_t **      ves_2_save,          /**< (OF) n_ves_2_save */
    int *         n_rows,              /**< (O) */
    int *         n_columns,           /**< (O) */
    int *         n_table_chars,       /**< (O) */
    char **       table_chars          /**< (OF) n_table_chars */
    );

extern RDV_API int ARCH_update_option_declaration(
    tag_t option_rev          /**< (I) */
    );

/**
    Generates a configured plmxml file from the unconfigured plmxml file, 
    applying the saved variant rule. This function is called from Adhoc DC thin client.
    <br/>This ITK should not be used in MFK supported environment as it might return error, 
    ITEM_multiple_items_returned, if multiple items are found with same ID.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#ITEM_item_not_found, if an invalid Item ID string is passed.
    <li>#ITEM_multiple_items_returned, if multiple items are found with same ID in MFK environment.
    <li>#RDV_cannot_create_file, if the transient volume directory is not defined or does not exist.
    <li>Possibly other errors.
    </ul>
*/
extern RDV_API int RDV_config_plmxml(
    tag_t  dataset_tag,          /**< (I) Tag of the dataset */
    char   *item_id,             /**< (I) Item (Product) ID, passed as string */
    char   *rev,                 /**< (I) Revision of the Item (Product) selected */
    char   *svr,                 /**< (I) Saved Variant Rule (SVR) as IMAN_specification.
                                          NULL or string "NULL" should be passed if SVR is not used */
    char   *entity_handle,       /**< (I) The UG occurrence entity handles entered as a single string, separated using the comma character (,).
                                          If empty string ("") is passed, this ITK will create empty pruned PLM file */
    int     nb_of_targets,       /**< (I) Number of target entity handles. This parameter is not used */
    char   *target_lines,        /**< (I) Target entity handles entered as a single string, separated using the comma character (,).
                                          NULL or empty string ("") should be passed if target lines are not used for search */
    logical voo_flag,            /**< (I) Valid Overlays Only (VOO) flag. Valid values for this flag:
                                          TRUE: Valid Overlays will be applied while configuring the structure 
                                          FALSE: Valid Overlays will not be applied while configuring the structure */
    char  **plmxml_config_file,  /**< (OF) Name of the configured pruned PLM file */
    char  **file_location        /**< (OF) Location of pruned PLM file */
 );

/**
    Generates a configured plmxml file from the unconfigured plmxml file, 
    applying the saved variant rule. This function is called from Adhoc DC thin client.
    <br/>This ITK is needed for MFK environment where Item ID might not be unique. In this 
    case item UID is used to retrieve the item revision tag and this is passed as input.
    of the item is required to be passed.
    
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#RDV_illegal_parameter, if entity_handle parameter is NULL.
    <li>#POM_invalid_tag, if an invalid tag or NULLTAG is passed in Dataset tag or Item (Product) revision tag.
    <li>#RDV_cannot_create_file, if the transient volume directory is not defined or does not exist.
    <li>Possibly other errors.
    </ul>
*/
extern RDV_API int RDV_config_plmxml_mfk(
    tag_t  dataset_tag,          /**< (I) Tag of the dataset */
    tag_t  product_revision_tag, /**< (I) Tag of the Item (Product) revision */
    char   *svr,                 /**< (I) Saved Variant Rule (SVR) as IMAN_specification.
                                          NULL or string "NULL" should be passed if SVR is not used */
    char   *entity_handle,       /**< (I) The UG occurrence entity handles entered as a single string, separated using the comma character (,).
                                          If empty string ("") is passed, this ITK will create empty pruned PLM file */
    char   *target_lines,        /**< (I) Target entity handles entered as a single string, separated using the comma character (,).
                                          NULL or empty string ("") should be passed if target lines are not used for search */
    logical voo_flag,            /**< (I) Valid Overlays Only (VOO) flag. Valid values for this flag:
                                          TRUE: Valid Overlays will be applied while configuring the structure
                                          FALSE: Valid Overlays will not be applied while configuring the structure */
    char  **plmxml_config_file,  /**< (OF) Name of the configured pruned PLM file */
    char  **file_location        /**< (OF) Location of pruned PLM file */
 );

extern RDV_API int Web_rdv_get_rev_rule(
    char  *fileBuff,      /**< (I) */
    char **revRulename    /**< (OF) */
    );

extern RDV_API int RDV_getRevision_fromDataset(
    tag_t dataset_tag,          /**< (I) */
    char **revisionRule         /**< (OF) file_location */
    );


extern RDV_API int WEB_RDV_getQPLBuilds(
    char   **QPLBuildsBuffer,    /**< (OF) qpl_buffer */
    char   **productIds          /**< (OF) product_id */
    );

extern RDV_API int WEB_RDV_decodeGetQPLScheme(
    char  *QPLItemID,                 /**< (I) */
    int   *errorCodeStatus,           /**< (O) */
    int   *nMessages,                 /**< (O) */
    char **messageString,             /**< (OF) nMessages */
    int   *nProximityInfo,            /**< (O) */
    char **proximityInfoString,       /**< (OF) nProximityInfo */
    int   *nAttributes,               /**< (O) */
    char **attributesString,          /**< (OF) nAttributes */
    int   *nZones,                    /**< (O) */
    char **zonesString                /**< (OF) nZones */
    );

extern RDV_API int WEB_RDV_executeQPLFilter (
    char   *qplBuildID,              /**< (I) */
    char   *distance,                /**< (I) */
    char   *booleanOperator,         /**< (I) */
    int     attCount,                /**< (I) */
    char  **attNames,                /**< (I) */
    char  **attOps,                  /**< (I) */
    char  **attValues,               /**< (I) */
    int     zoneAttrCount,           /**< (I) */
    char  **zoneAttrNames,           /**< (I) */
    char  **zoneAttrOps,             /**< (I) */
    int     occCount,                /**< (I) */
    char  **occTags,                 /**< (I) */
    int    *occEntityHandleCount,    /**< (O) */
    char  **occEntityHandle          /**< (OF) occEntityHandle */
    );

extern RDV_API int WEB_RDV_getExecuteQPLFilterCount (
    char   *qplBuildID,              /**< (I) */
    char   *distance,                /**< (I) */
    char   *booleanOperator,         /**< (I) */
    int     attCount,                /**< (I) */
    char  **attNames,                /**< (I) */
    char  **attOps,                  /**< (I) */
    char  **attValues,               /**< (I) */
    int     zoneAttrCount,           /**< (I) */
    char  **zoneAttrNames,           /**< (I) */
    char  **zoneAttrOps,             /**< (I) */
    int     occCount,                /**< (I) */
    char  **occTags,                 /**< (I) */
    int    *occEntityHandleCount,    /**< (O) */
    char  **occEntityHandle          /**< (OF) occEntityHandle */
    );


extern RDV_API int RDV_get_Occurences_id(
  tag_t  datasetTag,          /**< (I) */
  char  *entity_handle,       /**< (I) */
  char **retChar              /**< (OF) occurrences */
  );
  
extern RDV_API int RDV_get_rev_rule(
    char  *fileBuff,       /**< (I) */
    char **revRulename     /**< (OF) revrule */
);

extern RDV_API int RDV_generate_variant_map(
  tag_t datasetTag,         /**< (I) */
  char **revisionRule,      /**< (O) */
  char **productId          /**< (O) */
  );

extern RDV_API int RDV_generate_pruned_plmxml(
      tag_t     datasetTag,     /**< (I) */
      tag_t     prodRevTag,     /**< (I) */
      tag_t     window,         /**< (I) */
      tag_t     svrTag,         /**< (I) */
      char     *entityHandles,  /**< (I) */
      int       noOfTargetLines,/**< (I) */
      tag_t    *targetLines,    /**< (I) noOfTargetLines */      
      logical   vooFlag,        /**< (I) */
      char     **pruneFilePath  /**< (OF) filepath */
     );
extern RDV_API int RDV_clearHashTable();

extern RDV_API char *RDV_escape_xml_tag_value(
    const char *value                       /**< (I) */
    );

extern RDV_API int RDV_remove_parts_related_to_abe(
    tag_t     apn_tag,     /**<  (I) */
    tag_t     topline      /**<  (I) */
    );

extern RDV_API int RDV_is_part_shared(
    tag_t     apn_tag,      /**<  (I) */
    logical   *is_shared,   /**<  (O) */
    int       *no_of_refs   /**<  (O) */
    );

extern RDV_API int RDV_get_arch_meapnchild_components(
     tag_t topLevelItem,                   /**< (I) */
     tag_t meApn,                          /**< (I) */
     tag_t bomWindowTag,                   /**< (I) */
     int *noOfChildComponents,             /**< (O) */
     char ***componentsGcid,               /**< (OF) noOfChildComponents */
     char ***componentsName,               /**< (OF) noOfChildComponents */ 
     tag_t **childMeapns                   /**< (OF) noOfChildComponents */
);

extern RDV_API int RDV_get_apn_for_top_arch_and_bomwindow(
     char *gcId,                         /**< (I) */
     tag_t topArchTag,                   /**< (I) */
     tag_t bomWindowTag,                 /**< (I) */
     int *noOfMeapns,                    /**< (O) */
     tag_t **meApns,                     /**< (OF) */
     char ***genCompId,                  /**< (OF) */
     char ***compDesc                    /**< (OF) */    
);

extern RDV_API int RDV_find_imprecise_abe(
     char *gcId,                          /**< (I) */
     tag_t topArchTag,                    /**< (I) */
     tag_t bomWindowTag,                  /**< (I) */
     int *noOfMeapns,                     /**< (O) */
     tag_t **meApns,                      /**< (OF) */ 
     char ***genCompId,                   /**< (OF) */
     char ***compDesc                     /**< (OF) */
);

extern RDV_API int RDV_find_precise_abe(
     char *gcId,                          /**< (I) */
     tag_t topArchTag,                    /**< (I) */
     tag_t bomWindowTag,                  /**< (I) */
     int *noOfMeapns,                     /**< (O) */
     tag_t **meApns,                      /**< (OF) */ 
     char ***genCompId,                   /**< (OF) */
     char ***compDesc                     /**< (OF) */
);

extern RDV_API int RDV_get_arch_bomline_comps(
     tag_t topLevelItem,                 /**< (I) */
     tag_t meApn,                        /**< (I) */
     tag_t bomWindowTag,                 /**< (I) */
     int *noOfChildComponents,           /**< (O) */
     tag_t **childMeapns,                /**< (OF) */
     tag_t **bomLines                    /**< (OF) */
);
extern RDV_API int RDV_config_plmxml_with_svr(
    tag_t dataset_tag,         /**< (I) */
    tag_t toprev,              /**< (I) */
    char *directoryName,       /**< (I) */
    int  *svrCount,            /**< (I) */
    char **svr                 /**< (I) */
    );
extern RDV_API int RDV_config_plmxml_with_svr_with_log(
    tag_t datasetTag,          /**< (I) */
    tag_t toprev,              /**< (I) */
    char *directory,           /**< (I) */
    int  *svrCount,            /**< (I) */
    char **svr,                /**< (I) */
    char *logFileImport        /**< (I) */
    );
extern RDV_API int RDV_config_plmxml_with_import(
    tag_t dataset_tag,              /**< (I) */
    tag_t revid_tag,                /**< (I) */
    char *directoryName,            /**< (I) */
    int  *svrCount,                 /**< (I) */
    char **svr,                     /**< (I) */
    char *importUtility,            /**< (I) */
    char *importUtilityParameter,   /**< (I) */
    char *logFileImport             /**< (I) */
    );
extern RDV_API int RDV_get_precise_abe_child_apns(
    tag_t topLevelItem,             /**< (I) */
    tag_t meApn,                    /**< (I) */
    tag_t bomWindowTag,             /**< (I) */
    int *noOfChildComponents,       /**< (O) */
    char ***componentsGcid,         /**< (OF) noOfChildComponents */ 
    char ***componentsName,         /**< (OF) noOfChildComponents */  
    tag_t **childMeapns             /**< (OF) noOfChildComponents */
    );
extern RDV_API int RDV_get_imprecise_abe_child_apns(
    tag_t topLevelItem,             /**< (I) */ 
    tag_t meApn,                    /**< (I) */
    tag_t bomWindowTag,             /**< (I) */
    int *noOfChildComponents,       /**< (O) */ 
    char ***componentsGcid,         /**< (OF) noOfChildComponents */
    char ***componentsName,         /**< (OF) noOfChildComponents */
    tag_t **childMeapns             /**< (OF) noOfChildComponents */ 
    );


extern RDV_API int RDV_vissco_ask_contents(
    tag_t visSCOTag,
    const char* relationName,
    int subType,
    int * numOFObjects, 
    tag_t ** objects
    );

extern RDV_API int RDV_vissco_remove_content(
    tag_t visSCOTag,
    tag_t comp
    );

extern RDV_API int RDV_clone_part_solution_bomline_for_revise(
    tag_t    bomLine,      /**<  (I) > **/
    tag_t    apn_tag,      /**<  (I) > **/
    tag_t    abe_apn,      /**<  (I) > **/
    tag_t    appgrp,      /**<  (O) > **/
    tag_t   *newLine      /**<  (O) > **/
    );

/**
    Executes search for the input search configuration parameters and retrieves the found BOM Lines, their properties and installation assembly.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_line_has_no_ir if @p product is #NULLTAG.
    <li>#CXPOM_invalid_tag if @p revision_rule is #NULLTAG.
    <li>#BOM_invalid_tag if @p product is not a valid Product Item Revision or @p revision_rule is not a valid Revision Rule.
    <li>#POM_invalid_tag if @p saved_variant_rule is not a valid Saved Variant Rule or any of the @p box_zones is not a valid box zone.
    <li>#QSEARCH_internal_error if @p saved_qry is not #NULLTAG but does not contain a valid Saved Query or <br> if any of the @p form_attr_name is not a valid Form Attribute Name or <br> if any of the @p class_names is is not a valid Class Name.
    <li>#QRY_invalid_list_of_user_entries if any of the @p entries is not a valid entry name for Saved Query.
    <li>#POM_invalid_string if any of the @p occ_thread_chain is not a valid Occurrence Thread Chain.
    <li>#TYPE_unknown_type if any of the @p form_type_names is not valid Form Type.
    </ul>
*/
extern RDV_API int WEB_RDV_execute_cacheless_search(
    tag_t           product,                            /**< (I) The product item revision tag */
    tag_t           revision_rule,                      /**< (I) The revision rule to configure the BOM Window. */
    int             n_variant_opts,                     /**< (I) The number of variant options */
    tag_t*          variant_options,                    /**< (I) n_variant_opts The variant options to configure the BOM Window. */
    int*            variant_option_values,              /**< (I) n_variant_opts The variant option values to configure the BOM Window. */
    tag_t           saved_variant_rule,                 /**< (I) The saved variant rule to configure the BOM Window. */
    int             n_entries,                          /**< (I) The number of entries for saved query filter expression */
    char**          entries,                            /**< (I) n_entries The values for saved query filter expression */
    char**          values,                             /**< (I) n_entries The values for saved query filter expression */
    tag_t           saved_qry,                          /**< (I) The saved query used in saved query filter expression */
    int             n_occ_types,                        /**< (I) The number of occurrence types used in scope filter */
    char**          ignore_occ_types,                   /**< (I) n_occ_types The occurrence types used as an attribute for scope filter */
    double          distance,                           /**< (I) The proximity distance */
    int             n_occ_thread_chain,                 /**< (I) The number of occurrence threads used for getting configured BOM lines for proximity search */
    const char**    occ_thread_chain,                   /**< (I) n_occ_thread_chain The occurrence threads used for getting configured BOMLines for proximity search */
    logical         voo_enabled,                        /**< (I) The flag for checking variant condition */
    logical         true_shape_enabled,                 /**< (I) The flag enables true shape filtering on the search results */
    int             n_note_type,                        /**< (I) The number of note types for the occurrence filter */
    char**          note_types,                         /**< (I) n_note_type The note type strings for the occurrence filter */
    char**          occ_qry_opr,                        /**< (I) n_note_type The occurrence query operator used for the occurrence filter */
    char**          occ_values,                         /**< (I) n_note_type The occurrence search values for the occurrence filter */
    int             n_form_attr,                        /**< (I) The number of form attributes for the form attribute filter */
    char**          is_item_form_flag,                  /**< (I) n_form_attr The logical variables in string form for the item form used in the form attribute filter */
    char**          relation_type_names,                /**< (I) n_form_attr The relation type names defined for the form attribute filter */
    char**          form_type_names,                    /**< (I) n_form_attr The form types defined for the form attribute filter */
    char**          form_attr_name,                     /**< (I) n_form_attr The names of the form attribute used for the form attribute filter */
    char**          form_qry_opr,                       /**< (I) n_form_attr The query operators used in the form attribute filter */
    char**          form_bool_val,                      /**< (I) n_form_attr The logical values for the form attribute filter */
    char**          form_int_val,                       /**< (I) n_form_attr The integer values for the form attribute filter */
    char**          form_double_val,                    /**< (I) n_form_attr The double values for the form attribute filter */
    char**          form_string_val,                    /**< (I) n_form_attr The string values for the form attribute filter */
    char**          form_date_val,                      /**< (I) n_form_attr The date values for the form attribute filter */
    char**          form_uid_val,                       /**< (I) n_form_attr The uid values for the form attribute filter */
    int             n_class_attr,                       /**< (I) The number of inclass attributes for the InClass attribute filter */
    char**          class_names,                        /**< (I) n_class_attr The class names used in the InClass attribute filter */
    int*            class_attr_ids,                     /**< (I) n_class_attr The attribute ids used in the InClass attribute filter */
    char**          class_attr_values,                  /**< (I) n_class_attr The attribute values used in the InClass attribute filter */
    logical         larger_than,                        /**< (I) The larger than logical variable used to populate search by size object */
    double          diagonal_length,                    /**< (I) The diagonal length to populate search by size object */
    int             n_box_zone_instances,               /**< (I) The number of box zone instances */
    tag_t*          box_zones,                          /**< (I) n_box_zone_instances The box zones defined for the given box zone search filter */
    char**          boxzone_comp,                       /**< (I) n_box_zone_instances The box zone comparators to decide co-ordinates for a box are inside, outside or intersects */
    int*            n_found_bomlines,                   /**< (O) The number of found BOM Lines for the search on the provided configured BOM Lines */
    char***         bom_line_prop,                      /**< (OF) n_found_bomlines The properties of configured BOM Lines */
    char***         ia_assembly,                        /**< (OF) n_found_bomlines The name of Installation Assembly for configured BOM Lines */
    int *           n_unconfigured_bom_lines,           /**< (O) The number of unconfigured BOM Lines */
    char***         unconfig_bom_line_prop,             /**< (OF) n_unconfigured_bom_lines The properties of unconfigured BOM Lines */
    char***         unconfig_ia_assembly                /**< (OF) n_unconfigured_bom_lines The name of Installation Assembly for unconfigured BOM Lines */
);

extern RDV_API int WEB_RDV_create_VISSC(
    tag_t item_rev_tag,                      /**< (I)*/
    tag_t revision_rule,                     /**< (I)*/
    int     no_variant_opts,                 /**< (I)*/
    tag_t*  variant_option_tags,             /**< (I)*/
    int*    variant_option_values,           /**< (I)*/
    tag_t   saved_variant_rule_tag,          /**< (I)*/
    int occurrence_count,                    /**< (I)*/
    const char** occurrence_string_array,    /**< (I)*/
    char* client_id,                         /**< (I)*/
    tag_t* vscobj                            /**< (O)*/
    );

extern RDV_API int extract_psoccchain_from_bomlineprops( 
    int position,                 /**< (I)*/ 
    char** bomline_props,         /**< (I)*/ 
    char** OccChain               /**< (OF)*/
    );

extern RDV_API int WEB_RDV_get_sco_info(
    tag_t    sco_tag,                       /**< (I) */
    int      sco_evaluate_mode,             /**< (I) */
    tag_t*   sco_rev_rule,                  /**< (O) */
    tag_t*   sco_variant_rule,              /**< (O) */
    tag_t*   sco_prod_rev,                  /**< (O) */
    int*     work_parts_size,               /**< (O) */
    char***  work_parts_uids,               /**< (OF) work_parts_size */
    double*  sco_prox_dist,                 /**< (O) */
    int*     sco_zones_size,                /**< (O) */
    char***  sco_zones_comp,                /**< (OF)  sco_zones_size */
    char***  sco_zones_uids,                /**< (OF)  sco_zones_size */
    int*     svd_qry_entries_size,          /**< (O) */
    char***  qry_entries,                   /**< (OF)  svd_qry_entries_size */
    char***  qry_values,                    /**< (OF)  svd_qry_entries_size */
    tag_t*   sco_svd_qry_tag,               /**< (O) */
    int*     occ_attr_size,                 /**< (O) */
    char***  sco_occ_attr_name,             /**< (OF)  occ_attr_size */
    char***  sco_occ_oper,                  /**< (OF)  occ_attr_size */
    char***  sco_occ_attr_value,            /**< (OF)  occ_attr_size */
    int*     no_form_attr,                  /**< (O) */
    char***  sco_is_item_form_flag,         /**< (OF)  no_form_attr */
    char***  sco_relation_type_names,       /**< (OF)  no_form_attr */
    char***  sco_form_logical_opr,          /**< (OF)  no_form_attr */
    char***  sco_form_type_names,           /**< (OF)  no_form_attr */
    char***  sco_form_attr_name,            /**< (OF)  no_form_attr */
    char***  sco_form_qry_opr,              /**< (OF)  no_form_attr */
    char***  sco_form_string_val,           /**< (OF)  no_form_attr */
    logical* sco_true_shape_enabled,        /**< (O) */
    logical* sco_voo_enabled,               /**< (O) */
    logical* sco_append_parts,              /**< (O) */
    int*     sco_target_lines_size,         /**< (O) */
    char***  sco_target_lines_occ_chain,    /**< (OF)  sco_target_lines_size */
    char***  target_lines_ia,               /**< (OF)  sco_target_lines_size */
    int*     sco_selected_target_lines_size,     /**< (O) */
    char***  sco_selected_target_lines_props,    /**< (OF)  sco_selected_target_lines_size */    
    int*     sco_backgrnd_lines_size,       /**< (O) */
    char***  sco_backgrnd_lines_occ_chain,  /**< (OF)  sco_backgrnd_lines_size */
    char***  backgrnd_lines_ia,              /**< (OF)  sco_backgrnd_lines_size */
    int*     sco_selected_backgrnd_lines_size,   /**< (O) */
    char***  sco_selected_backgrnd_lines_props   /**< (OF)  sco_selected_backgrnd_lines_size */
);

extern RDV_API int WEB_RDV_create_scg(
    tag_t   product_rev_tag,                 /**< (I)*/
    tag_t   revision_rule,                   /**< (I)*/
    int     no_variant_opts,                 /**< (I)*/
    tag_t*  variant_option_tags,             /**< (I)*/
    int*    variant_option_values,           /**< (I)*/
    tag_t   saved_variant_rule_tag,          /**< (I)*/
    int     no_workparts,                    /**< (I)*/
    tag_t*  workpart_tags,                   /**< (I)*/
    int     no_entries,                      /**< (I)*/
    const char**  entries,                   /**< (I)*/
    const char**  values,                    /**< (I)*/
    tag_t   saved_qry_tag,                   /**< (I)*/
    double  distance,                        /**< (I)*/
    int     sel_tgt_occ_chain_size,          /**< (I)*/
    const char** sel_tgt_occ_thread_chain,   /**< (I)*/
    int     unsel_tgt_occ_chain_size,        /**< (I)*/
    const char** unsel_tgt_occ_thread_chain, /**< (I)*/
    int     sel_bk_occ_chain_size,           /**< (I)*/
    const char** sel_bk_occ_thread_chain,    /**< (I)*/
    int     unsel_bk_occ_chain_size,         /**< (I)*/
    const char** unsel_bk_occ_thread_chain,  /**< (I)*/
    logical voo_enabled,                     /**< (I)*/
    logical true_shape_enabled,              /**< (I)*/
    int no_note_type,                        /**< (I)*/
    char** note_type_str,                    /**< (I)*/
    char** occ_qry_opr,                      /**< (I)*/
    char** occ_values,                       /**< (I)*/
    int no_form_attr,                        /**< (I)*/
    char** is_item_form_flag,                /**< (I)*/
    char** relation_type_names,              /**< (I)*/
    char** form_type_names,                  /**< (I)*/
    char** form_logical_opr,                 /**< (I)*/
    char** form_attr_name,                   /**< (I)*/
    char** form_qry_opr,                     /**< (I)*/
    char** form_string_val,                  /**< (I)*/
    int box_zone_instances,                  /**< (I)*/
    tag_t* box_zone_tags,                    /**< (I)*/
    char** boxzone_comp,                     /**< (I)*/
    tag_t* sc_filter_grp_tag                 /**< (O)*/
);

extern RDV_API int WEB_RDV_create_sco(
    char*   sco_type,                        /**< (I)*/
    char*   sco_name,                        /**< (I)*/
    char*   sco_desc,                        /**< (I)*/
    tag_t   product_rev_tag,                 /**< (I)*/
    tag_t   revision_rule,                   /**< (I)*/
    int     no_variant_opts,                 /**< (I)*/
    tag_t*  variant_option_tags,             /**< (I)*/
    int*    variant_option_values,           /**< (I)*/
    tag_t   saved_variant_rule_tag,          /**< (I)*/
    int     no_workparts,                    /**< (I)*/
    tag_t*  workpart_tags,                   /**< (I)*/
    tag_t tgt_saved_qry_tag,                 /**< (I)*/
    int no_tgt_crt,                          /**< (I)*/
    const char** tgt_entires_crt,            /**< (I)*/
    const char** tgt_values_crt,             /**< (I)*/
    int     sel_tgt_occ_chain_size,          /**< (I)*/
    const char** sel_tgt_occ_thread_chain,   /**< (I)*/
    int     unsel_tgt_occ_chain_size,        /**< (I)*/
    const char** unsel_tgt_occ_thread_chain, /**< (I)*/
    int     sel_bk_occ_chain_size,           /**< (I)*/
    const char** sel_bk_occ_thread_chain,    /**< (I)*/
    int     unsel_bk_occ_chain_size,         /**< (I)*/
    const char** unsel_bk_occ_thread_chain,  /**< (I)*/
    int     tgt_occ_chain_size,              /**< (I)*/
    const char** tgt_occ_thread_chain,       /**< (I)*/
    int     bk_occ_chain_size,               /**< (I)*/
    const char** bk_occ_thread_chain,        /**< (I)*/
    int no_sc_filter_grp_tags,               /**< (I)*/
    tag_t* sc_filter_grp_tags,               /**< (I)*/
    tag_t* sco_tag                           /**< (O)*/
);

extern RDV_API int RDV_vis_strct_cntxt_obj_remove_sco_contents(
    tag_t   structureContextObjectTag      /**< (I)*/
);

/**
    Creates a search cursor for the input search configuration parameters and retrieves a limited number of the found BOM Lines.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_line_has_no_ir if @p product is #NULLTAG.
    <li>#CXPOM_invalid_tag if @p revision_rule is #NULLTAG.
    <li>#BOM_invalid_tag if @p product is not a valid Product Item Revision or @p revision_rule is not a valid Revision Rule.
    <li>#POM_invalid_tag if @p saved_variant_rule is not a valid Saved Variant Rule or box_zones from @p box_zone_search_expr is not a valid box zone.
    <li>#QSEARCH_internal_error if @p saved_query_expr is not a null pointer but does not contain a valid Saved Query or <br> if form attribute name is passed in @p form_attr_search_expr is not a valid Form Attribute Name or <br> if an class name is passed in @p inclass_attr_search_expr is not a valid Class Name.
    <li>#QRY_invalid_list_of_user_entries if any of the entry name passed in @p saved_query_expr is not a valid entry name for Saved Query.
    <li>#POM_invalid_string if any of the occurrence thread chain passed in @p proximity_expr is not a valid Occurrence Thread Chain.
    <li>#TYPE_unknown_type if any of the form type name passed in @p form_attr_search_expr is not valid Form Type.
    </ul>
*/
extern RDV_API int RDV_start_cacheless_search(
    const tag_t                                     product,                    /**< (I) The product item revision tag */
    const tag_t                                     revision_rule,              /**< (I) The revision rule to configure the BOM Window. */
    const unsigned int                              n_variant_opts,             /**< (I) The number of variant options */
    const tag_t*                                    variant_options,            /**< (I) n_variant_opts The variant options to configure the BOM Window. */
    const int*                                      variant_option_values,      /**< (I) n_variant_opts The variant option values to configure the BOM Window. */
    const tag_t                                     saved_variant_rule,         /**< (I) The saved variant rule to configure the BOM Window. */
    const logical                                   voo_enabled,                /**< (I) The flag for checking variant condition */
    const logical                                   true_shape_enabled,         /**< (I) The flag enables true shape filtering on the search results */
    const int                                       page_size,                  /**< (I) The number of results to retrieve */
    const RDV_saved_query_expression_t*             saved_query_expr,           /**< (I) The saved query search expression */
    const RDV_translate_scope_search_expression_t*  translate_scope_expr,       /**< (I) The translate scope search expression */
    const RDV_proximity_search_expression_t*        proximity_expr,             /**< (I) The proximity search expression */
    const RDV_occurrence_search_expression_t*       occurrence_search_expr,     /**< (I) The occurrence search expression */
    const RDV_form_attribute_search_expression_t*   form_attr_search_expr,      /**< (I) The form attribute search expression */
    const RDV_inclass_attribute_search_expression_t* inclass_attr_search_expr,  /**< (I) The in class attribute search expression */
    const RDV_search_bysize_expression_t*           search_by_size_expr,        /**< (I) The search by size expression */
    const RDV_boxzone_search_expression_t*          box_zone_search_expr,       /**< (I) The box zone search expression */
    tag_t*                                          search_window,              /**< (O) The BOM window created for the search configured using input parameters */
    unsigned int*                                   n_config_bom_lines,         /**< (O) The number of configured BOM Lines */
    tag_t**                                         config_bom_lines,           /**< (OF) n_config_bom_lines The configured BOM Lines */
    unsigned int*                                   n_unconfigured_bom_lines,   /**< (O) The number of unconfigured BOM Lines */
    tag_t**                                         unconfigured_bom_lines,     /**< (OF) n_unconfigured_bom_lines The unconfigured BOM lines */
    unsigned int*                                   n_unconfigurable_bom_lines, /**< (O) The number of unconfigurable BOM lines */
    tag_t**                                         unconfigurable_bom_lines,   /**< (OF) n_unconfigurable_bom_lines unconfigurable BOM lines */
    tag_t*                                          search_cursor,              /**< (O) The search cursor for the search configured using input parameters */
    unsigned int*                                   n_found_bomlines,           /**< (O) The number of found BOM Lines for the search on the provided configured BOM Lines */
    tag_t**                                         found_bomlines,             /**< (OF) n_found_bomlines The BOM Lines found for the search on the provided configured BOM Lines */
    logical*                                        search_done                 /**< (O) Indicates if all the found BOM Lines are returned. <br> If @p search_done is false then next list of found BOM Lines can be retrieved using #RDV_next_cacheless_search */ 
);

/**
    Creates a search cursor for the input search configuration parameters and retrieves a limited number of the found BOM Lines.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_line_has_no_ir if @p product is #NULLTAG.
    <li>#CXPOM_invalid_tag if @p revision_rule is #NULLTAG.
    <li>#BOM_invalid_tag if @p product is not a valid Product Item Revision or @p revision_rule is not a valid Revision Rule.
    <li>#POM_invalid_tag if @p variant_options is not a valid variant options tag
    <li>#BOM_invalid_variant_value if @p variant_option_values is not a valid variant value
    <li>#POM_invalid_tag if @p saved_variant_rule is not a valid Saved Variant Rule or box_zones from @p box_zone_search_expr is not a valid box zone.
    <li>#QSEARCH_internal_error if @p saved_query_expr is not a null pointer but does not contain a valid Saved Query or <br> if form attribute name is passed in @p form_attr_search_expr is not a valid Form Attribute Name or <br> if an class name is passed in @p inclass_attr_search_expr is not a valid Class Name.
    <li>#QRY_invalid_list_of_user_entries if any of the entry name in @p saved_query_expr is not a valid entry name for Saved Query.
    <li>#POM_invalid_string if any of the occurrence thread chain in @p proximity_expr is not a valid Occurrence Thread Chain.
    <li>#TYPE_unknown_type if any of the form type name in @p form_attr_search_expr is not valid Form Type.
    <li>#POM_invalid_value if any ItemRevision in @p item_revision_expr is invalid.
    </ul>

    @code
        ifail = SPC_RDV_start_cacheless_search_with_scope( product, revision_rule, n_variant_opts, variant_options, variant_option_values, saved_variant_rule,
                      voo_enabled, true_shape_enabled, page_size, chunk_size, saved_query_expr, translate_scope_expr, proximity_expr, occurrence_search_expr, form_attr_search_expr,
                      inclass_attr_search_expr, search_by_size_expr, box_zone_search_expr, item_revision_expr, &search_window, &n_config_bom_lines, &config_bom_lines, &n_unconfigured_bom_lines, &unconfigured_bom_lines, &n_unconfigurable_bom_lines, &unconfigurable_bom_lines, search_cursor, n_found_bomlines, found_bomlines, search_done );

        if( !search_done )
        {
            ifail = SPC_RDV_next_cacheless_search( search_cursor, page_size, n_config_bom_lines, config_bom_lines, n_found_bomlines, found_bomlines, search_done );
        }
    @endcode
*/
extern RDV_API int RDV_start_cacheless_search_with_scope(
    const tag_t                                                product,                    /**< (I) The product item revision tag */
    const tag_t                                                revision_rule,              /**< (I) The revision rule to configure BOM Window */
    const int                                                  n_variant_opts,             /**< (I) The number of variant options */
    const tag_t*                                               variant_options,            /**< (I) n_variant_opts The variant options to configure BOM Window */
    const int*                                                 variant_option_values,      /**< (I) n_variant_opts The variant option values to configure BOM Window */
    const tag_t                                                saved_variant_rule,         /**< (I) The saved variant rule to configure BOM Window */
    const logical                                              voo_enabled,                /**< (I) The flag for checking variant condition */
    const logical                                              true_shape_enabled,         /**< (I) The flag enables true shape filtering on the search results */
    const int                                                  page_size,                  /**< (I) The number of results to retrieve */
    const int                                                  chunk_size,                 /**< (I) The number of Items to process */
    const RDV_saved_query_expression_t*                        saved_query_expr,           /**< (I) The saved query search expression */
    const RDV_translate_scope_search_expression_with_scope_t*  translate_scope_expr,       /**< (I) The translate scope search expression */
    const RDV_proximity_search_expression_t*                   proximity_expr,             /**< (I) The proximity search expression */
    const RDV_occurrence_search_expression_t*                  occurrence_search_expr,     /**< (I) The occurrence search expression */
    const RDV_form_attribute_search_expression_t*              form_attr_search_expr,      /**< (I) The form attribute search expression */
    const RDV_inclass_attribute_search_expression_t*           inclass_attr_search_expr,   /**< (I) The "in class" attribute search expression */
    const RDV_search_bysize_expression_t*                      search_by_size_expr,        /**< (I) The search by size expression */
    const RDV_boxzone_search_expression_t*                     box_zone_search_expr,       /**< (I) The box zone search expression */
    const RDV_item_revision_expression_t*                      item_revision_expr,         /**< (I) The ItemRevision search expression */
    tag_t*                                                     search_window,              /**< (O) The BOM Window created for the search configured using input parameters */
    int*                                                       n_config_bom_lines,         /**< (O) The number of configured BOM Lines */
    tag_t**                                                    config_bom_lines,           /**< (OF) n_config_bom_lines The configured BOM Lines */
    int*                                                       n_unconfigured_bom_lines,   /**< (O) The number of unconfigured BOM Lines */
    tag_t**                                                    unconfigured_bom_lines,     /**< (OF) n_unconfigured_bom_lines The unconfigured BOM Lines */
    int*                                                       n_unconfigurable_bom_lines, /**< (O) The number of unconfigurable BOM Lines */
    tag_t**                                                    unconfigurable_bom_lines,   /**< (OF) n_unconfigurable_bom_lines The unconfigurable BOM Lines */
    tag_t*                                                     search_cursor,              /**< (O) The search cursor for the search configured using input parameters */
    int*                                                       n_found_bomlines,           /**< (O) The number of found BOM Lines for the search on the provided configured BOM Lines */
    tag_t**                                                    found_bomlines,             /**< (OF) n_found_bomlines The BOM Lines found for the search on the provided configured BOM Lines */
    logical*                                                   search_done                 /**< (O) Indicates if all the found BOM Lines are returned. <br/> If @p search_done is @c false, the next list of found BOM Lines can be retrieved using #RDV_next_cacheless_search. */
);

/**
    Retrieves the next list of found BOM Lines, using the Search Cursor created by #RDV_start_cacheless_search.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if @p search_cursor is #NULLTAG or if @p search_cursor not a valid Search Cursor or if any of the BOM Line from @p config_bom_lines is not a valid BOM Line.
    </ul>
 */
extern RDV_API int RDV_next_cacheless_search(
    const tag_t         search_cursor,                  /**< (I) The search cursor */
    const int           page_size,                      /**< (I) The number of results to retrieve */
    const unsigned int  n_config_bom_lines,             /**< (I) The number of configured BOM Lines */
    const tag_t*        config_bom_lines,               /**< (I) n_configured_bom_lines The configured BOM Lines */
    unsigned int*       n_found_bomlines,               /**< (O) The number of found BOM Lines for the search on the provided configured BOM Lines */
    tag_t**             found_bomlines,                 /**< (OF) n_found_bomlines The BOM Lines found for the search on the provided configured BOM Lines */
    logical*            search_done                     /**< (O) Indicates if all the found BOM Lines are returned. <br> If search_done is false then next set of BOM Lines can be retrieved using #RDV_next_cacheless_search */ 
);

/**
    Closes and destroys Search Cursor and a Search Window.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CXPOM_invalid_tag if @p search_cursor is not a valid Search Cursor.
    </ul>
 */
extern RDV_API int RDV_stop_cacheless_search(
    const tag_t         search_cursor,                  /**< (I) The search cursor to be cleared */
    const tag_t         search_window                   /**< (I) The search window to be closed */
    );

/**
    Saves the recipe by creating a filter recipe object given @p JSON_expression.
    The @p owning_object is the tag value of the "fnd0OwningObject" property on the filter recipe

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#RDV_invalid_json if the input @p json_expression is invalid
    <li>#RDV_invalid_input if the saved query name or folder name is invalid
    <li>#RDV_cannot_create_recipe if the @p owning_object is NULLTAG or an unexpected internal error occurs
    </ul>
*/
extern RDV_API int RDV_save_recipe
(
    const char*   json_expression,      /**< (I) The JSON expression string */
    tag_t         owning_object,        /**< (I) The tag of the object that owns the recipe */
    tag_t*        filter_recipe         /**< (O) The created filter recipe tag */
);

/**
    Creates a JSON expression string for given @p filter_recipe
    and @p bom_window

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#RDV_invalid_recipe if @p filter_recipe input is invalid
    <li>#RDV_cannot_read_recipe if there is an unexpected internal error
    </ul>
*/
extern RDV_API int RDV_read_recipe
(
    tag_t  filter_recipe,       /**< (I) The existing filter recipe object */
    tag_t  bom_window,          /**< (I) The BOM Window that is the current scope */
    char** json_expression      /**< (OF) The created JSON expression string */
);

/**
    Creates a complete JSON expression string for given 
    global filters and @p json_recipe

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#RDV_invalid_recipe if @p json_recipe is invalid
    <li>#RDV_cannot_create_recipe if @p bom_window is NULLTAG or there is an unexpected internal error
    </ul>
*/
extern RDV_API int RDV_add_filter_options_to_recipe
(    
    const char* json_recipe,            /**< (I) The existing filter recipe object */
    tag_t bom_window,                    /**< (I) The bom window that is the context of the search */
    int num_scope_bom_lines,            /**< (I) The number of scope bomlines */
    tag_t* scope_bom_lines,                /**< (I) The tags of the scope bomlines */
    int num_ignore_occ_types,            /**< (I) The number of ignored occurence types */
    tag_t* ignore_occ_types,            /**< (I) The tags of the ignored occurence types */
    logical is_lwb,                        /**< (I) The flag to return light weight bomlines */
    logical do_true_shape,                /**< (I) The flag to do true shape filtering */
    logical return_in_scope,            /**< (I) The flag to return in scope bomlines */
    logical execute_voo_filters,        /**< (I) The flag to execute voo filters */
    logical remote_search,                /**< (I) The flag to enable remote search */
    const char* remote_site_id,            /**< (I) The remote site id if remote search enabled */
    char** recipe_with_filter_options   /**< (OF) completed json recipe with global scope and filters */
);


/** @} */

#ifdef __cplusplus
}
#endif

#include <rdv/librdv_undef.h>

#endif

