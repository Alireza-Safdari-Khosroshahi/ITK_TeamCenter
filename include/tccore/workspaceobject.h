/* Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright $2014.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    Header file for all of the data structures used in WSO search, find and get info,
    plus the prototypes for the ITK.
*/

/*  */

#ifndef WORKSPACEOBJECT_H
#define WORKSPACEOBJECT_H

#include <tc/tc_startup.h>
#include <common/tc_deprecation_macros.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup WSO Workspace Object (WSO)

    This module implements the methods of the abstract class called WorkspaceObject from which several other classes descend.
    The methods of these classes are presented as the functional interface described in this reference section.

    The system employs an object-oriented design and these functions implement the methods found at the top of the hierarchy.
    The hierarchy starts with POM objects at the top. This means all descendant objects may use POM functions.

    Each of these modules introduces a specialized interface to the objects.
    Therefore, the super class interface (e.g., POM) may no longer be applicable and/or allowed.

    @note To use these functions, include workspaceobject.h.

    <b>Data Structure Descriptions</b>

    These constants specify the size of variables returned in the get_info entries.
    Do not write more than this number of bytes into the buffers.

    #WSO_name_size_c <br>
    #WSO_desc_size_c <br>
    #WSO_date_size_c <br>
    #WSO_revision_size_c

    <b>Search Criteria</b>

    The following structure allows you to specify a query:

    #WSO_search_criteria_t

    <b>Basic Information</b>

    The following structure contains basic information about a workspace object:

    #WSO_description_t

    The values in square brackets indicate the amount of memory allocated for
    the storage of the value of the corresponding attribute.
    For those that can be changed care must be taken not to overwrite the limits.

    Dates are returned as: yyyy-mm-dd hh:mm:ss

    <b>Common Return Values</b>

    <table>
        <tr><td>#CXPOM_invalid_tag</td>
            <td>Function specified a tag that is either no longer existent or is not a tag_t.</td>
        </tr>
        <tr><td>#CXPOM_wrong_class</td>
            <td>Tag supplied is not a valid WorkspaceObject.</td>
        </tr>
        <tr><td>#WSO_wr_invalid_depth</td>
            <td>Invalid depth (zero or negative).</td>
        </tr>
        <tr><td>#WSOM_invalid_eff</td>
            <td>Effectivity tag being queried does not exist.</td>
        </tr>
        <tr><td>#WSOM_bad_effectivity_text_format</td>
            <td>This error is returned when difficulty is encountered parsing a string into a set of start-end range values.
                The problem might be one or more of the following:
                <UL>
                    <LI>Incorrect format for date effectivities.
                    <LI>Text representation of 'to' not being equal to corresponding internationalized values.
                    <LI>Text representations of 'open-ended' and 'stock-out' not being equal to internationalized values.
                </UL>
                Go to #WSOM_eff_set_date_range or #WSOM_eff_set_unit_range for additional information.</td>
        </tr>
        <tr><td>#WSOM_range_overlap</td>
            <td>A correctly formatted discontinuous range must contain values that are in ascending order,
                otherwise this error will result. Go to #WSOM_eff_set_date_range or #WSOM_eff_set_unit_range  for additional information.</td>
        </tr>
        <tr><td>#WSOM_cannot_edit_protected</td>
            <td>A protected effectivity cannot be edited. To make the effectivity editable, it must first be unlocked.
                This can only be done by a user with the correct permissions.</td>
        </tr>
        <tr><td>#WSOM_no_mixed_range_types</td>
            <td>The range text contains both date and unit values;
                effectivities can have either a date range or a unit range, but not both.</td>
        </tr>
        <tr><td>#WSOM_closed_status_open_range</td>
            <td>A range being set with an array has an odd number of values,
                suggesting an open-ended range, but the #WSOM_open_ended_status_t parameter is set to #EFFECTIVITY_closed.</td>
        </tr>
        <tr><td>#WSOM_open_status_closed_range</td>
            <td>A range being set with an array has an even number of values, suggesting a closed range,
                but the #WSOM_open_ended_status_t parameter is set to #EFFECTIVITY_open_ended or #EFFECTIVITY_stock_out.</td>
        </tr>
        <tr><td>#WSOM_cant_save_eff_with_no_rs</td>
            <td>An effectivity must be attached to a release status before it can be saved.
                This error results if an ITK program is still working with an effectivity
                that has been removed from its release status.</td>
        </tr>
        <tr><td>#WSOM_init_module #WSOM_exit_module</td>
            <td>WSOM_init/exit_module are the standard wrappers round any module;
                they are called by Teamcenter startup / TC_stop so the normal ITK programmer can ignore them.
                Repeated calls to #WSOM_init_module are harmless.</td>
        </tr>
        <tr><td>#WSOM_extent</td>
            <td>#WSOM_extent returns all the workspace objects in the database
                (an unlikely event for any real site - but potentially useful on a test database).</td>
        </tr>
        <tr><td>#WSOM_cannot_destroy_eff</td>
            <td>An attempt is being made to destroy an effectivity attached to a release status.
                This should be done by removing the effectivity from the release status.</td>
        </tr>
    </table>

    @{
*/

#define WSO_name_size_c             128
#define TC_LEGACY_ID_NAME_SIZE      32

/** POM's current max string length. */
#define WSO_desc_size_c             240

#define WSO_date_size_c             21
#define WSO_object_type_size_c      32
#define WSO_revision_size_c         15
#define WSO_release_status_size_c   128

#define WSO_ip_class_size_c         128
#define WSO_gov_class_size_c        128

/**
    Used to indicate that a where referenced search should proceed
    until no more references are found.
    Note there is currently no published ITK for where referenced.
*/
#define WSO_where_ref_any_depth     -1

/** @if DOX_IGNORE
    These entries are here since tasktypes have disappeared.
    These should also be expunged.
@endif */
#define RLM_tasktype_name_size_c    32
#define RLM_tasktype_desc_size_c    32
#define RLM_followup_action_size_c  32

/** @if DOX_IGNORE
    (MSF) 3-June-1993 20 attributes now
@endif */

#define Describe_object_name        0x1
#define Describe_object_type        0x2
#define Describe_owner              0x4
#define Describe_application        0x8
#define Describe_date_created       0x10
#define Describe_date_modified      0x20
#define Describe_date_released      0x40
#define Describe_released_for       0x80
#define Describe_id_string          0x100
#define Describe_revision_number    0x200
#define Describe_revision_limit     0x400
#define Describe_owning_group       0x800
#define Describe_last_mod_user      0x1000
#define Describe_archive_date       0x2000
#define Describe_backup_date        0x4000
#define Describe_description        0x8000
#define Describe_is_frozen          0x10000
#define Describe_is_reserved        0x20000
#define Describe_revision_id        0x40000
#define Describe_owning_site        0x80000

/**
    The structure defined below is for use primarily by FolderLand.
    It retieves all the required information from the WorkspaceObject and
    therefore does not need a virtual function or the particular subclass
    of the instance to be loaded. It is used with the "describe" function.

    If object type is ItemVersionFolder, the id attribute will be mapped to
    "id_string" field and the name attribute will be mapped to "object_name"
    field. For some other object types, the name attribute will be mapped to
    "id_string" field and the "object_name" field will be null.
*/
typedef struct WSO_description_s {
    char       object_name[WSO_name_size_c + 1];
    char       object_type[WSO_name_size_c + 1];

    char       owners_name[WSO_name_size_c + 1];
    char       application[WSO_name_size_c + 1];

    char       date_created[WSO_date_size_c + 1];
    char       date_modified[WSO_date_size_c + 1];
    char       date_released[WSO_date_size_c + 1];
    char       released_for[WSO_release_status_size_c + 1];

    char       id_string[WSO_name_size_c + 19];
    int        revision_number;                                 /**< Dataset stuff */
    int        revision_limit;                                  /**< Dataset stuff */

    char       owning_group_name[WSO_name_size_c+1];
    char       last_modifying_user_name[WSO_name_size_c+1];
    char       archive_date[WSO_date_size_c+1];
    char       backup_date[WSO_date_size_c+1];
    char       description[WSO_desc_size_c+1];
    int        is_frozen;
    int        is_reserved;
    char       revision_id[WSO_name_size_c+1];                  /**< Item revision */
    char       owning_site_name[WSO_name_size_c+1];
} WSO_description_t, *WSO_description_p_t;

/**
    This structure allows you to specify a query:
*/
typedef struct WSO_search_criteria_s{
    char       class_name[WSO_name_size_c+1];       /**< Default value will be "Folder".
                                                        The value must be for a sub-class of WorkspaceObject. */
    char       pom_class_name[WSO_name_size_c+1];
    char       name[WSO_name_size_c+1];             /**< This is the applicable attribute name */
    char       desc[WSO_desc_size_c+1];             /**< This is reserved for future use and not currently used */
    int        revision;                            /**< This is reserved for future use and not currently used */
    tag_t      owner;
    tag_t      group;
    date_t     createdBefore;
    date_t     modifiedBefore;
    date_t     releasedBefore;
    date_t     createdAfter;
    date_t     modifiedAfter;
    date_t     releasedAfter;
    int        scope;                               /**< This is either #WSO_search_HOR or #WSO_search_Vault */
} WSO_search_criteria_t, *WSO_search_criteria_p_t;

#define WSO_search_HOR              0
#define WSO_search_Vault            1

/**
    The get/set_info mechanism uses the data structure described below.
    A client should use the appropriate get_info call.
    In the ITK this would be a function named WSOM_get_info(WSO_descriptor_p_t *d)
    in C++ an instance of the class is used to access the member function get_info.

    The client may change some values that are not protected.
    If this is done the client should set the m_flag of the corresponding #WSO_get_info_entry_t.

    The client must be sure not to overwrite the buffer provided for the value.
    The size of the buffer is provided in the entry.

    When values are changed the client should call the appropriate set_info function.
    i.e. #WSOM_set_info for C ITK and instance set_info for C++

    Use of the get_info function will result in memory being allocated.
    Please call the appropriate free_info function to free the memory.
    Do not use any other means to free this memory.

    #WSOM_get_info - allocate memory and return data.<br>
    #WSOM_set_info - change the values of appropriate attributes<br>
    #WSOM_free_info - free memory allocated by #WSOM_get_info
*/
typedef struct WSO_get_info_entry_s {
    char       name[WSO_name_size_c + 1];   /**< Applicable attribute name */
    int        size;                        /**< Length of the value string. Be sure not to overwrite it. */
    char*      value;                       /**< Buffer containing the value of this attribute. */
    char       desc[32];                    /**< Description of the attribute value. e.g "bytes" */
    int        p_flag;                      /**< If this value is set (i.e. p_flag != 0),
                                                 then the value of the attribute cannot be changed using set_info. */
    int        m_flag;                      /**< If the value is changed then this flag should be set to 1 */
    void*      client_data;                 /**< #WSOM_get_info uses it for form entry id.
                                                 It is up the client to decide what use if any there is for it. */
    int        entry_number;                /**< Do not modify */
    int        number_of_entries;           /**< Do not modify */
} WSO_get_info_entry_t, *WSO_get_info_entry_p_t;

/**
    The owner and group may be changed by changing the tags or by changing the name and
    letting the internal functions determine the tag. The choice is up to the client.
    Changing tags if you have them, is a faster means of changing ownership.

    In either case the request can still fail if access is denied.
    When a request fails the entry's m_flag is set to -1.

    The change of m_flag to -1 is in addition to all other standard error reporting mechanisms not a replacement of them.
*/
typedef struct WSO_descriptor_s {
    int                   m_flag;       /**< Set if you change the owner/group tag */
    tag_t                 owner;        /**< May also be changed by changing the name in the appropriate entry. */
    tag_t                 group;        /**< May also be changed by changing the name in the appropriate entry. */
    int                   n_entries;    /**< Do not modify. */
    WSO_get_info_entry_t* entries;      /**< Array size is: n_entries */
} WSO_descriptor_t, *WSO_descriptor_p_t;


/**
    Effectivity open ended status
*/
typedef enum WSOM_open_ended_status_e {
    EFFECTIVITY_closed       = 0,
    EFFECTIVITY_open_ended   = 1,
    EFFECTIVITY_stock_out    = 2
} WSOM_open_ended_status_t;

/**
    Effectivity range types

    Effectivity ranges are either dates or units and this is enforced in the code.
    However, legacy data upgraded to the new model may contain both dates and units.
*/
typedef enum WSOM_range_type_e {
    EFFECTIVITY_range_not_defined           = 0,
    EFFECTIVITY_range_unit                  = 1,
    EFFECTIVITY_range_date                  = 2,
    EFFECTIVITY_range_legacy_unit_and_date  = 3
} WSOM_range_type_t;

/** Structure for #BOM_line_ask_unit_occurrence_effectivity */
typedef struct WSOM_effectivity_info_s {
    tag_t enditem;                              /**< Tag of the enditem object  */
    int unitCount;                              /**< Number of Units in @p units */
    int* units;                                 /**< Units */
    int dateCount;                              /**< Number of Dates in @p dates */
    date_t* dates;                              /**< Dates */
    WSOM_open_ended_status_t openEndedStatus;   /**< Effectivity open ended status */
} WSOM_effectivity_info_t;

#ifdef __cplusplus
extern "C"{
#endif

extern TCCORE_API int WSOM_init_module();

extern TCCORE_API int WSOM_exit_module();

/**
    Lists all instances of WorkspaceObject
    (well actually subclasses thereof, WorkspaceObject is an abstract class) in the database.
*/
extern TCCORE_API int WSOM_extent(
    int*                n_instances,    /**< (O) */
    tag_t**             instances       /**< (OF) n_instances */
    );


/**
   Initializes the WorkspaceObject attributes of an object.
   <br/>It would normally be called for an object that is an instance of a subclass of WorkspaceObject.
*/
extern TCCORE_API int WSOM_initialize2(
    tag_t               wso,                          /**< (I) */
    const char          *name,                            /**< (I) */
    const char          *description                      /**< (I) */
    );


/**
    Assigns a new name to a WorkspaceObject.

    @warning When a dataset named reference is being modified and #WSOM_set_name2 is used within one dataset save,
    #WSOM_set_name2 should be called before the modification to the named references.
    Otherwise, the original named references might be lost.
*/
extern TCCORE_API int WSOM_set_name2(
    tag_t               wso,                      /**< (I)  */
    const char          *new_name                       /**< (I)  */
    );


/**
    Retrieves the name of the input WorkspaceObject.
*/
extern TCCORE_API int WSOM_ask_name2(
    tag_t               wso,                      /**< (I) Tag of the object */
    char                **name                        /**< (OF) Name of the object */
    );

/**
    Retrieves the ID string of the specified Item or Item Revision.
    <br/>This string is the same as displayed in the Workspace ID column.
    <br/>If the tag passed to this routine is a WorkspaceObject other than an Item or Item Revision,
    an empty string is returned.
*/
extern TCCORE_API int WSOM_ask_id_string(
    tag_t               wso,  /**< (I) Tag of the object */
    char**              id       /**< (OF) ID string of the object */
    );

/**
    Retrieves the object ID of the specified WorkspaceObject.
    <br/>The string is the object ID as it appears in the Object column of the Workspace display.
*/
extern TCCORE_API int WSOM_ask_object_id_string(
    tag_t               wso,  /**< (I) Tag of the object */
    char**              object_id   /**< (OF) Object ID of the object */
    );


/**
    Sets the description for a WorkspaceObject.

    @warning When a dataset named reference is being modified and #WSOM_set_description2 is used within one dataset save,
    the #WSOM_set_description2 function should be called before the modification to the named references.
    Otherwise, the original named references might be lost.
*/
extern TCCORE_API int WSOM_set_description2(
    tag_t               wso,                              /**< (I) */
    const char          *new_description                        /**< (I) */
    );

/**
    Retrieves the description of the specified WorkspaceObject.
*/
extern TCCORE_API int WSOM_ask_description2(
    tag_t               wso,                          /**< (I) Tag of the object */
    char                **description                     /**< (OF) Description of the object */
    );


/**
    Sets the object type for a specified Workspaceobject.
    You can use this for setting the type of a Folder that you use for
    some special purpose so that you can differentiate it from other Folders
    in the workspace or so you can key on it in some ITK program algorithm.

    @note Do not change the object type of special Teamcenter instances,
    like Target Folders, because certain Teamcenter algorithms may key on their object type.

    @note The object_type field cannot be switched to a new Business Object that has different
    storage class from the original Business Object.

    @note Since certain Teamcenter algorithms depend upon
    the object type of an object being correct, a restriction has been added to
    the system that requires a TcType to exist for all objects for which you attempt to
    set the object type. Thus, if you create a new class in the system, and try to set its type,
    you must create a new TcType to correspond to the class before attempting to call
    #WSOM_set_object_type2 on that object.

*/
extern TCCORE_API int WSOM_set_object_type2(
    tag_t               wso,                            /**< (I) */
    const char          *object_type                        /**< (I) */
    );



/**
    Assigns a new IP Classification property value to a Workspace Object.
    
    <br/>This value must match one of values specified in the IP_level_list_ordering preference.
    This preference defines a list of Intellectual Property (IP) classification values and clearance levels 
    that are assigned to data objects and users for IP access evaluation. 
    The order in which they appear in the list determines their restrictiveness.
    The first row is the lowest classification, and the last row is the highest. 
    Access Manager compares these values to determine user access rights to the object. 
    IP_level_list_ordering is for use with classification functionality.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_invalid_tag if the provided Workspace Object is invalid
    </ul>
    */
extern TCCORE_API int WSOM_set_ip_classification2(
    tag_t        wso,                          /**< (I) Tag of the Workspace Object */
    const char   *classification                         /**< (I) IP Classification value to be assigned to the Workspace Object */
        );


/**
    Retrieves the IP Classification property value associated with specified Workspace Object.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_invalid_tag if the provided Workspace Object is invalid
    </ul>
*/
extern TCCORE_API int WSOM_ask_ip_classification2(
    tag_t       wso,                               /**< (I) Tag of the Workspace Object */
    char        **classification                       /**< (OF) The IP Classification value assigned to Workspace Object */
    );

/**
    Determines if the IP Classification attribute set or not on specified Workspace Object.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_invalid_tag if the provided Workspace Object is invalid
    </ul>
*/
extern TCCORE_API int WSOM_has_ip_classification(
    tag_t       wso,                               /**< (I) Tag of the Workspace Object */
    logical*    has_ip_classification                     /**< (O) True if the specified Workspace Object has IP Classification set on it, otherwise, False */
    );


/**
    Assigns a Government Classification property value to a Workspace Object.
    
    <br/>Access to classified data is determined by an evaluation of the user's clearance level and 
    the classification level that is applied to the object.
    The Government Classification property specifies the classification level of an individual object and 
    can be viewed and modified in the same manner as other object properties.
    Users must have ITAR Admin or ITAR Classifier privileges to classify objects.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_invalid_tag if the provided Workspace Object is invalid
    </ul>
*/
extern TCCORE_API int WSOM_set_gov_classification2(
    tag_t        wso,                                  /**< (I) Tag of the Workspace Object */
    const char   *classification                            /**< (I) Government Classification value to be assigned to the Workspace Object */
        );


/**
    Retrieves the Government Classification property value associated with specified Workspace Object.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_invalid_tag if the provided Workspace Object is invalid
    </ul>
*/
extern TCCORE_API int WSOM_ask_gov_classification2(
    tag_t       wso,                                  /**< (I) Tag of the Workspace Object */
    char        **classification                           /**< (OF) Government Classification value assigned to Workspace Object */
    );

/**
    Determines if the Government Classification attribute set or not on specified Workspace Object.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_invalid_tag if the provided Workspace Object is invalid
    </ul>
*/
extern TCCORE_API int WSOM_has_gov_classification(
    tag_t       wso,                               /**< (I) Tag of the Workspace Object */
    logical*    has_gov_classification                    /**< (O) True if the specified Workspace Object has Government Classification set on it, otherwise, False */
    );

/**
    Retrieves whether the object is IP logged or not based on preference called TC_session_clearance.
    
    <br/>If the preference has a value is set to either 'log' or 'block', it will check the value of ip_classification attribute
    for the given object.
    <br/>If the given Workspace object's IP classification value is set, then it will return TRUE.
    <br/>Otherwise, it will return FALSE even if the object is classified, the preference needs to be set in order to get a TRUE verdict.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_invalid_tag if the provided Workspace Object is invalid
    </ul>
*/
extern TCCORE_API int WSOM_ask_ip_logged(
    tag_t       wso,                               /**< (I) Tag of the Workspace Object */
    logical*    logged                                  /**< (O) True if Workspace Object is IP logged, otherwise, False */
    );

/**
    Determines whether the user has UNMANAGE access privilege on Workspace Object or not.
    
    <br/>It works with preference TC_session_clearance value block or log.
    Allowing data out of the managed environment creates a security vulnerability,
    but there may be times you want to grant a user permission to use NX menus that involve exporting data out of the environment.
    The Unmanage privilege in Access Manager allows you to grant users the ability to access these features.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_invalid_tag if the provided Workspace Object is invalid
    </ul>
 */
extern TCCORE_API int WSOM_ask_user_can_unmanage(
    tag_t       wso,                               /**< (I) */
    logical*    can_unmanage                            /**< (O) */
    );

/**
    Retrieves the number of licenses and list of licenses associated with the input Workspace Object.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#POM_invalid_tag if the provided Workspace Object is invalid
    </ul>
*/
extern TCCORE_API int WSOM_ask_licenses(
    tag_t               wso,            /**< (I) Tag of the Workspace Object */
    int*                n_licenses,       /**< (O) Number of licenses associated with the input object */
    tag_t**             licenses            /**< (OF) n_licenses Licenses associated with the input object */
    );


/**
    Retrieves an array of tags of WorkspaceObjects, regardless of subclass, that have a particular name.

    @returns
    <ul>
    <li>#ITK_ok if no error occurs during the query.
    This does not mean that hits will be greater than 0.
    That must be a separate check.
    <li>Possibly other errors.
    </ul>
*/
extern TCCORE_API int WSOM_find2(
    const char          *name,                      /**< (I) */
    int*                hits,                       /**< (O) */
    tag_t**             list                        /**< (OF) hits */
    );

/**
    Initializes a search criteria structure.
    <br/>This would be used in preparation for doing another search.
*/
extern TCCORE_API int WSOM_clear_search_criteria(
    WSO_search_criteria_t* criteria     /**< (I) */
    );

/**
    Retrieves an array of POMObject or subclasses of POMObject tags that match the previously specified search criteria.
    Use #MEM_free to free the space used by the tag list.

    This function allocates memory sufficient to return a list of all matching POMObject object tags.
    The client is expected to free the memory using #MEM_free.

    Fill out the #WSO_search_criteria_t structure as necessary.
    Use #NULLTAG to ignore owners as necessary and minimum/maximum dates for the *Before and *After date specifiers.
    Therefore, you will set before dates to maximumDate and the after dates to minimumDate so that
    all dates are valid or simply #NULLDATE so dates are not used as a search criteria.

    The following list describes the effect of setting various values in the structure #WSO_search_criteria_t.

    <table>
    <tr><td>class_name</td><td>If set, must be set to the name of an object type as displayed in the workspace.</td></tr>
    <tr><td>name</td>      <td>Can contain wild card characters.
                            The percent sign and underscore are the only valid wild card characters, where:

                            \% Represents any set of characters in the substring. <br>
                            _ (Underscore) Represents any single character in the substring. <br>
                            If wild card characters are used then select 1 ("%" for multi-char replacement, use "_" for single char replacement.) <br>
                            for Tc preference "TC_pattern_match_style". </td></tr>
    <tr><td>owner</td>     <td>If set, means only select objects belonging to the owner you specify.</td></tr>
    <tr><td>group</td>     <td>If set, means only select objects belonging to the group you specify.</td></tr>
    <tr><td>dates</td>     <td>You must select objects created/modified/released_before first,
                            then specify dates after.</td></tr>
    <tr><td>scope</td>     <td>#WSO_search_HOR searches the entire database.
                            #WSO_search_Vault searches for objects that have at least one status of approval.
    </table>

    @code
    {
        int error_code;
        int number_found;
        tag_t* list_of_wsos;

        WSO_search_criteria_t criteria;
        WSOM_clear_search_criteria(&criteria);
        strcpy(criteria.name,"My Friend's Current Design");

        error_code = WSOM_search(criteria, &number_found,&list_of_wsos);

        MEM_free(list_of_wsos);
    }
    @endcode

    <b>Restrictions:</b>

    Do not forget to free the returned list as illustrated.

    See #AE_find_dataset2, #AE_find_tool2, and #WSOM_clear_search_criteria
*/
extern TCCORE_API int WSOM_search(
    WSO_search_criteria_t criteria,     /**< (I) */
    int*                  hits,         /**< (O) */
    tag_t**               list          /**< (OF) hits */
    );

/**
    Fills out the specified structure with the appropriate pieces of data.
    
    @note Do not use #MEM_free to free the memory allocated to info. Use #WSOM_free_info.

    @code
    {
        tag_t wso;
        WSO_descriptor_t info;
        int stat;

        stat = WSOM_get_info(wso, &info);

        stat = WSOM_free_info (wso, info);
    }
    @endcode
*/
extern TCCORE_API int WSOM_get_info(
    tag_t               wso,  /**< (I) */
    WSO_descriptor_t*   info        /**< (O) */
    );

/**
    Uses a #WSO_descriptor_t as input to actually change the values of
    the associated attributes of the workspace object.
*/
extern TCCORE_API int WSOM_set_info(
    tag_t               wso,  /**< (I) */
    WSO_descriptor_t*   info        /**< (I) */
    );

/**
    Frees up all of the memory allocated by #WSOM_get_info.
*/
extern TCCORE_API int WSOM_free_info(
    tag_t               wso,  /**< (I) */
    WSO_descriptor_t*   info        /**< (I) */
    );

/**
    Retrieves a structure containing basic information about a workspace object.
    This is a convenience function,
    as all of this information can also be obtained using other POM, AOM and WSOM functions.

    @note All of the values, except the revision number, are returned as strings.
*/
extern TCCORE_API int WSOM_describe(
    tag_t               wso,      /**< (I) */
    WSO_description_t*  description     /**< (O) */
    );

/**
    @deprecated #WSOM_copy deprecated in Teamcenter 12.4. Use #TCTYPE_bulk_saveas_objects2 instead.

    Creates a copy of the input WorkspaceObject.

    @note No Deep Copy is performed. To copy the whole object (including its related objects), #TCTYPE_saveas_object should be used.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#NULLTAG on error
    </ul>
*/
TC_DEPRECATED( "12.4", "WSOM_copy", "TCTYPE_bulk_saveas_objects2" )
extern TCCORE_API int WSOM_copy(
    tag_t               wso,        /**< (I) The Wokspace Object to copy */
    const char*         new_name,   /**< (I) The name of the copied object. A NULL pointer can be provided, in which case explain_what_happens_t
                                    <br/> Some subclasses may enforce unique names among instances of their class.
                                    <br/> In that case a new unique name is required or an error is returned.*/
    tag_t*              copied_wso  /**< (O) The copied Workspace Object */
    );

/**
    Revision numbers are normally controlled automatically by Teamcenter.
    If this routine is used improperly,
    you may end up with an inconsistent or confusing set of revision numbers.
    #WSOM_set_revision sets the revision number for a workspace object.
    Revision number should be greater than 0.
*/
extern TCCORE_API int WSOM_set_revision(
    tag_t               wso,  /**< (I) */
    int                 rev_number  /**< (I) */
    );

/**
    Retrieves the revision number of the WorkspaceObject.
*/
extern TCCORE_API int WSOM_ask_revision(
    tag_t               wso,  /**< (I) Tag of the object */
    int*                rev_number  /**< (O) Revision of the object */
    );

/**
    Allows to alter the version limit of a dataset.
    <br/>Normally, version limit is only applicable to datasets.
    <br/>However, this attribute can be made editable for other workspace objects via Properties ITK.
*/
extern TCCORE_API int WSOM_set_revision_limit(
    tag_t               wso,  /**< (I) */
    int                 rev_limit   /**< (I) */
    );

/**
    Retrieves the revision limit for the input object.
*/
extern TCCORE_API int WSOM_ask_revision_limit(
    tag_t               wso,  /**< (I) Tag of the object */
    int*                rev_limit   /**< (O) Revision limit of the object */
    );


/**
    Retrieves the object type of the specified WorkspaceObject.
*/
extern TCCORE_API int WSOM_ask_object_type2(
    tag_t               wso,                      /**< (I) */
    char                **object_type                   /**< (OF) */
    );

/**
    Retrieves the original object on which the input WorkspaceObject was based (i.e., copied from).
    If no based-on information is stored for this WorkspaceObject then #NULLTAG is specified .

    Based-on information is only stored for subclasses of Dataset, Item and Item Revision.

    When either the original or the derived object is deleted, the based-on information that links them is lost.

    Based-on information is not stored for objects created in Teamcenter versions prior to 3.4.
*/
extern TCCORE_API int WSOM_ask_based_on(
    tag_t               wso,            /**< (I) Tag of the workspace object */
    tag_t*              based_on_wso    /**< (O) Tag of the object that the input object is based-on.
                                             #NULLTAG if no based on information. */
    );

/**
    Lists of all the WorkspaceObjects derived from the specified input Workspace Object
    (i.e., all those objects that have the input Workspace Object as their based-on object).

    Based-on information is only stored for subclasses of Dataset, Item, and Item Revision.

    When either the original or the derived object is deleted, the based-on information that links them is lost.

    Based-on information is not stored for objects created in Teamcenter versions prior to 3.4.
*/
extern TCCORE_API int WSOM_list_derived_wsos(
    tag_t               wso,            /**< (I) Tag of the workspace object */
    int*                n_derived,      /**< (O) Number of objects derived from the input object */
    tag_t**             derived_wsos    /**< (OF) n_derived Array of the tags of the objects derived from the input object */
    );


/**
    @deprecated #WSOM_where_referenced deprecated in Teamcenter 11.3. Use #WSOM_where_referenced2 instead.

    Finds all WorkspaceObjects that reference the specified WorkspaceObject.
    <br/>If the specified number of levels > 1, then all WorkspaceObjects that reference the referencers are found,
    and so on, building up a reference tree of the specified number of levels.

    The user is responsible to free each string returned in the array individually
    before freeing up the the array itself. Use #MEM_free to free up the memory.

    The figure below shows a reference tree structure to illustrate the result of a
    where-referenced search on My_Dataset (using a depth of #WSO_where_ref_any_depth).

    @note The result returned from #WSOM_where_referenced is impacted by the value of the preference "Where_Ref_Avoid_Duplicate_Expansion".
    <br/>When this preference is set to true, the default value, duplicate nodes will be shown only once in the output tree.
    <br/>To make duplicate nodes visible in all paths, change the value to false.

    Calling a where-referenced function on My_Dataset in the above example will return the following arrays:

    <table>
    <tr><td>index</td><td>level</td><td>referencer</td> <td>relation</td></tr>
    <tr><td>0</td>    <td>1</td>    <td>4545</td>       <td>"Reference"</td></tr>
    <tr><td>1</td>    <td>2</td>    <td>3476/A-view</td><td>"Occurrence"</td></tr>
    <tr><td>2</td>    <td>3</td>    <td>3476/A</td>     <td>""</td></tr>
    <tr><td>3</td>    <td>4</td>    <td>3476</td>       <td>""</td></tr>
    <tr><td>4</td>    <td>5</td>    <td>My_Folder</td>  <td>""</td></tr>
    <tr><td>5</td>    <td>5</td>    <td>2355/B-view</td><td>"Occurrence"</td></tr>
    <tr><td>6</td>    <td>6</td>    <td>2355/B</td>     <td>""</td></tr>
    <tr><td>7</td>    <td>7</td>    <td>2355</td>       <td>""</td></tr>
    <tr><td>8</td>    <td>8</td>    <td>My_Folder</td>  <td>""</td></tr>
    <tr><td>9</td>    <td>2</td>    <td>Newstuff</td>   <td>""</td></tr>
    </table>

    @note Since the folder My_Folder contains both Item 3476 and Item 2355,
    My_Folder appears twice to indicate the different paths through the tree.
*/
TC_DEPRECATED( "11.3", "WSOM_where_referenced", "WSOM_where_referenced2" )
extern TCCORE_API int WSOM_where_referenced(
    tag_t               wso,            /**< (I) Tag of the WorkspaceObject whose referencers are sought */
    int                 n_depth,        /**< (I) Depth of search. #WSO_where_ref_any_depth means report all referencers
                                             up to WorkspaceObjects that are not referenced at all. */
    int*                n_referencers,  /**< (O) The total number of referencers found */
    int**               levels,         /**< (OF) n_referencers Array containing the level of each referencer found,
                                             starting from 1 for a direct reference to the specified WorkspaceObject */
    tag_t**             referencers,    /**< (OF) n_referencers Array of tags of the referencers found */
    char***             relations       /**< (OF) n_referencers Array of strings describing the relations between
                                             the referencers and the referenced.
                                             <br/>This array is not packed, which means that both the elements and the container need to be freed through a call to #MEM_free.   */
    );


/**
    Finds all WorkspaceObjects that reference the specified WorkspaceObject.
    If the specified number of levels > 1, then all WorkspaceObjects that reference the referencers are found,
    and so on, building up a reference tree of the specified number of levels.

    The figure below shows a reference tree structure to illustrate the result of a
    where-referenced search on My_Dataset (using a depth of #WSO_where_ref_any_depth).

    @note The result returned from #WSOM_where_referenced2 is impacted by the value of the preference "Where_Ref_Avoid_Duplicate_Expansion".
    <br/>When this preference is set to true, the default value, duplicate nodes will be shown only once in the output tree.
    <br/>To make duplicate nodes visible in all paths, change the value to false.

    Calling a where-referenced function on My_Dataset in the above example will return the following arrays:

    <table>
    <tr><td>index</td><td>level</td><td>referencer</td> <td>relation</td></tr>
    <tr><td>0</td>    <td>1</td>    <td>4545</td>       <td>"Reference"</td></tr>
    <tr><td>1</td>    <td>2</td>    <td>3476/A-view</td><td>"Occurrence"</td></tr>
    <tr><td>2</td>    <td>3</td>    <td>3476/A</td>     <td>""</td></tr>
    <tr><td>3</td>    <td>4</td>    <td>3476</td>       <td>""</td></tr>
    <tr><td>4</td>    <td>5</td>    <td>My_Folder</td>  <td>""</td></tr>
    <tr><td>5</td>    <td>5</td>    <td>2355/B-view</td><td>"Occurrence"</td></tr>
    <tr><td>6</td>    <td>6</td>    <td>2355/B</td>     <td>""</td></tr>
    <tr><td>7</td>    <td>7</td>    <td>2355</td>       <td>""</td></tr>
    <tr><td>8</td>    <td>8</td>    <td>My_Folder</td>  <td>""</td></tr>
    <tr><td>9</td>    <td>2</td>    <td>Newstuff</td>   <td>""</td></tr>
    </table>

    @note Since the folder My_Folder contains both Item 3476 and Item 2355,
    My_Folder appears twice to indicate the different paths through the tree.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag          if @p wso is #NULLTAG.
    <li>#CXPOM_wrong_class          if @p wso is not a tag of a WorkspaceObject.
    <li>#WSO_wr_invalid_depth       if @p n_depth is 0 or less than -1.
    <li>Possibly other errors.
    </ul>
*/
extern TCCORE_API int WSOM_where_referenced2(
    const tag_t         wso,            /**< (I) Tag of the WorkspaceObject whose referencers are sought */
    const int           n_depth,        /**< (I) Depth of search. #WSO_where_ref_any_depth means report all referencers
                                             up to WorkspaceObjects that are not referenced at all. */
    int*                n_referencers,  /**< (O) The total number of referencers found */
    int**               levels,         /**< (OF) n_referencers Array containing the level of each referencer found,
                                             starting from 1 for a direct reference to the specified WorkspaceObject */
    tag_t**             referencers,    /**< (OF) n_referencers Array of tags of the referencers found */
    char***             relations       /**< (OF) n_referencers Array of strings describing the relations between
                                             the referencers and the referenced.
                                             <br/>This array is packed, which means that only the container needs to be freed through a call to #MEM_free.   */
    );


/**
    @name Release Status ITK
    @{
*/

/**
    Lists release statuses attached to a workspace object.
*/
extern TCCORE_API int WSOM_ask_release_status_list(
    tag_t               workspace_object,   /**< (I) Workspace object tag */
    int*                n_statuses,       /**< (O) Number of release statuses attached to the workspace object */
    tag_t**             statuses         /**< (OF) n_statuses The release statuses attached to the workspace object */
    );

/**
    Retrieves the release date of a given release status.
*/
extern TCCORE_API int WSOM_status_ask_date_released(
    tag_t               release_status,     /**< (I) Release status tag */
    date_t*             release_date        /**< (O) Release date */
    );

/** @} */

/**
    @name Effectivity ITK

    All functions that add/edit/remove effectivity automatically lock the release status and
    effectivities. After such calls, the changes remain loaded in session until committed to the
    database by calling AOM_save( release_status ). There is never a need to save individual
    effectivity instances; they will be automatically saved when you save the owning release status.
    @{
*/

/**
    Creates an effectivity qualified against an end item.
    The release status is locked by this call;
    call #AOM_save to commit the changes to the database.
*/
extern TCCORE_API int WSOM_effectivity_create(
    tag_t               release_status,     /**< (I) Tag of the release status to which the effectivity will be attached */
    tag_t               end_item,           /**< (I) Tag of the end item against which the effecitivity is to be qualified */
    tag_t*              effectivity         /**< (O) Tag of the newly created effectivity */
    );

/**
    Creates an empty effectivity.
    The release status is locked by this call;
    call #AOM_save to commit the changes to the database.
*/
extern TCCORE_API int WSOM_effectivity_create_empty(
    tag_t               release_status,     /**< (I) Tag of the release status to which the effectivity will be attached */
    tag_t*              effectivity         /**< (O) Tag of the newly created effectivity */
    );

/**
    Creates an effectivity with the date range specified by a text string.
*/
extern TCCORE_API int WSOM_eff_create_with_date_text(
    tag_t               release_status,     /**< (I) */
    tag_t               end_item,           /**< (I) */
    const char*         range_text,         /**< (I) */
    tag_t*              effectivity         /**< (O) */
    );

/**
    Creates an effectivity with the unit range specified by a text string.
*/
extern TCCORE_API int WSOM_eff_create_with_unit_text(
    tag_t               release_status,     /**< (I) */
    tag_t               end_item,           /**< (I) */
    const char*         range_text,         /**< (I) */
    tag_t*              effectivity         /**< (O) */
    );

/**
    Creates an effectivity with effectivity group.
*/
extern TCCORE_API int WSOM_effectivity_create_with_effectivitygroup(
    tag_t               effectivitygroup_rev,           /**< (I) */
    tag_t               end_item,                       /**< (I) */
    const char*         unit_text,                      /**< (I) */
    tag_t*              effectivity                     /**< (O) */
    );


/**
    Creates an effectivity qualified against an end item.
    Also sets the effectivity range to the units in the array supplied.
    The release status is locked by this call; call #AOM_save to commit the changes to the database.
*/
extern TCCORE_API int WSOM_effectivity_create_with_units(
    tag_t                    release_status,            /**< (I) Tag of the release status to which the effectivity will be attached */
    tag_t                    end_item,                  /**< (I) Tag of the end item against which the effectivity is to be qualified */
    int                      n_units,                   /**< (I) Number of units in the array */
    int*                     start_end_values,          /**< (I) n_units Unit start, end values.
                                                           <br/>Go to #WSOM_eff_set_units for additional information. */
    WSOM_open_ended_status_t open_ended_or_stock_out,   /**< (I) One of the constants either #EFFECTIVITY_open_ended,
                                                           #EFFECTIVITY_stock_out or #EFFECTIVITY_closed */
    tag_t*                   effectivity                /**< (O) Tag of the newly created effectivity */
    );

/**
    Creates an effectivity qualified against an end item.
    <br/>Also sets the effectivity range to the units in the array supplied.
    The release status is locked by this call; call #AOM_save to commit the changes to the database.
*/
extern TCCORE_API int WSOM_effectivity_create_with_dates(
    tag_t                    release_status,            /**< (I) Tag of the release status to which the effectivity will be attached */
    tag_t                    end_item,                  /**< (I) Tag of the end item against which the effectivity is to be qualified */
    int                      n_dates,                   /**< (I) Number of dates in the array */
    date_t*                  start_end_values,          /**< (I) n_dates Date start, end values.
                                                             Go to #WSOM_eff_set_dates for additional information. */
    WSOM_open_ended_status_t open_ended_or_stock_out,   /**< (I) One of the constants either #EFFECTIVITY_open_ended,
                                                             #EFFECTIVITY_stock_out or #EFFECTIVITY_closed */
    tag_t*                   effectivity                /**< (O) Tag of the newly created effectivity */
    );

/**
    Gives all the effectivities attached to a given release status.

    In 'V7 effectivity mode' a status can have multiple effectivities,
    each one qualified by a different end item.
*/
extern TCCORE_API int WSOM_status_ask_effectivities(
    tag_t               release_status,     /**< (I) Tag of the release status being queried */
    int*                n_effectivities,    /**< (O) Number of effectivities attached to the release status */
    tag_t**             effectivities       /**< (OF) n_effectivities Tags of all the effectivities attached to the release status */
    );

/**
    Removes an effectivity from a release status.
    <br/>The release status is locked by this call:
    use #AOM_save to commit the changes to the database.
*/
extern TCCORE_API int WSOM_status_remove_effectivity(
    tag_t               release_status,     /**< (I) Tag of the release status */
    tag_t               effectivity         /**< (I) Tag of the effectivity to be removed */
    );

/**
    Removes all effectivities from the release status.
    <br/>The release status is locked by this call: use #AOM_save to commit the changes to the database.
*/
extern TCCORE_API int WSOM_status_clear_effectivities(
    tag_t               release_status      /**< (I) Tag of the release status to be cleared of effectivities */
    );



/**
    Parses the range_text string and sets the effectivity range to the values extracted.
    <br/>If @p append is @c true, the range values are added to the existing unit range.
    Otherwise, the range is replaced with the values specified.
*/
extern TCCORE_API int WSOM_eff_set_unit_range(
    tag_t               release_status,     /**< (I) */
    tag_t               effectivity,        /**< (I) */
    const char*         range_text,         /**< (I) */
    logical             append              /**< (I) */
    );

/**
    Gives a text representation of the unit range values of a given effectivity.
    <br/>Formatting takes place according to the restrictions of #WSOM_eff_set_date_range and
    #WSOM_eff_set_unit_range as appropriate.
*/
extern TCCORE_API int WSOM_eff_ask_unit_range(
    tag_t               release_status,     /**< (I) Tag of the release status to which the effectivity belongs */
    tag_t               effectivity,        /**< (I) Tag of the effectivity being queried */
    char**              range_text          /**< (OF) Text representation of the unit range values */
    );


/**
    Parses the range_text string and sets the effectivity range to the values extracted.
    <br/>If @p append is @c true, the range values are added to the existing date range.
    Otherwise, the range is replaced with the values specified.
*/
extern TCCORE_API int WSOM_eff_set_date_range(
    tag_t               release_status,     /**< (I) */
    tag_t               effectivity,        /**< (I) */
    const char*         range_text,         /**< (I) */
    logical             append              /**< (I) */
    );

/**
    Gives a text representation of the date range values of a given effectivity.
    <br/>Formatting takes place according to the restrictions of #WSOM_eff_set_date_range and #WSOM_eff_set_unit_range.
*/
extern TCCORE_API int WSOM_eff_ask_date_range(
    tag_t               release_status,     /**< (I) Tag of the release status to which the effectivity belongs */
    tag_t               effectivity,        /**< (I) Tag of the effectivity being queried */
    char**              range_text          /**< (OF) Text representation of the date range values */
    );


/**
    Gives a text representation of both the unit and date range values of a given effectivity concatenated together.
    <br/>Formatting takes place according to the restrictions of #WSOM_eff_set_date_range and #WSOM_eff_set_unit_range.
*/
extern TCCORE_API int WSOM_eff_ask_range(
    tag_t               release_status,     /**< (I) Tag of the release status to which the effectivity belongs */
    tag_t               effectivity,        /**< (I) Tag of the effectivity being queried */
    char**              range_text          /**< (OF) Text representation of the date range values */
    );


/**
   Sets the unit range for a given effectivity.
   
   <br/>The release status is locked by this call; call #AOM_save to commit the changes to the database.

    <b>Restrictions:</b>
    <OL>
    <LI>Values should be in ascending order.
    <LI>The value of open_ended_or_stock_out should be either #EFFECTIVITY_open_ended,
        #EFFECTIVITY_stock_out or #EFFECTIVITY_closed.
        If the value is #EFFECTIVITY_closed, then n_units has to be even, otherwise n_units has to be odd.
    <LI>Unit ranges must be qualified against an end item, i.e., they cannot have #NULLTAG end item.
    </OL>
*/
extern TCCORE_API int  WSOM_eff_set_units(
    tag_t                    release_status,            /**< (I) Tag of the release status to which the effectivity belongs */
    tag_t                    effectivity,               /**< (I) Tag of the effectivity */
    int                      n_units,                   /**< (I) The size of the array or start-end values */
    int*                     start_end_values,          /**< (I) n_units The start-end values of the discontinuous range.
                                                               For example, consider a discontinuous range consisting of
                                                               continuous ranges r1, r2, ..., rn where rx has start and end values,
                                                               rx.start and rx.end.
                                                               The array of start_end_vals for this discontinuous range will
                                                               be constructed as { r1.start, r1.end, r2.start, r2.end, ...,
                                                               rn.start, rn.end }. The last value, rn.end should be omitted if
                                                               the discontinuous range is open ended. */
    WSOM_open_ended_status_t open_ended_or_stock_out,   /**< (I) One of the following constants: #EFFECTIVITY_open_ended,
                                                               #EFFECTIVITY_stock_out or #EFFECTIVITY_closed. */
    logical                  append                     /**< (I) If set to true, the values in the array will be added to
                                                               the unit range, otherwise they will replace them. */
    );


/**
   Sets the date range for a given effectivity.
   <br/>The release status is locked by this call: use #AOM_save to commit the changes to the database.

   <b>Restrictions:</b> See #WSOM_eff_set_units for additional information.
*/
extern TCCORE_API int  WSOM_eff_set_dates(
    tag_t                    release_status,            /**< (I) Tag of the release status to which the effectivity belongs */
    tag_t                    effectivity,               /**< (I) Tag of the effectivity */
    int                      n_dates,                   /**< (I) The size of the array or start-end values */
    date_t*                  start_end_values,          /**< (I) n_dates The start-end values of the discontinuous range.
                                                               For example, consider a discontinuous range consisting of
                                                               continuous ranges r1, r2, ..., rn where rx has start and
                                                               end values, rx.start and rx.end.
                                                               The array of start_end_vals for this discontinuous range will
                                                               be constructed as { r1.start, r1.end, r2.start, r2.end, ...,
                                                               rn.start, rn.end }. The last value, rn.end should be omitted if
                                                               the discontinuous range is open ended. */
    WSOM_open_ended_status_t open_ended_or_stock_out,   /**< (I) One of the following constants: #EFFECTIVITY_open_ended,
                                                               #EFFECTIVITY_stock_out or #EFFECTIVITY_closed. */
    logical                  append                     /**< (I) If set to true, the values in the array will be added to
                                                               the date range, otherwise they will replace them */
    );


/**
    Converts the unit range into an array of start-end values.
    <br/>If size of the array is odd, the unit range is open-ended.
*/
extern TCCORE_API int  WSOM_eff_ask_units(
    tag_t                     release_status,           /**< (I) Tag of the release status to which the effectivity belongs */
    tag_t                     effectivity,              /**< (I) Tag of the effectivity being queried */
    int*                      n_units,                  /**< (O) The size of the array or start-end values */
    int**                     start_end_values,         /**< (OF) n_units The start-end values */
    WSOM_open_ended_status_t* open_ended_or_stock_out   /**< (O) One of the following constants: #EFFECTIVITY_open_ended,
                                                                 #EFFECTIVITY_stock_out or #EFFECTIVITY_closed. */
    );


/**
    Converts the date range into an array of start-end values.
    <br/>If size of the array is odd, the date range is open-ended.
*/
extern TCCORE_API int  WSOM_eff_ask_dates(
    tag_t                     release_status,           /**< (I) Tag of the release status to which the effectivity belongs */
    tag_t                     effectivity,              /**< (I) Tag of the effectivity being queried */
    int*                      n_dates,                  /**< (O) The size of the array or start-end values */
    date_t**                  start_end_values,         /**< (OF) n_dates The start-end values */
    WSOM_open_ended_status_t* open_ended_or_stock_out   /**< (O) One of the following constants: #EFFECTIVITY_open_ended,
                                                                 #EFFECTIVITY_stock_out or #EFFECTIVITY_closed. */
    );

/**
    Converts both effectivity ranges into arrays of start-end values.
    <br/>Although as indicated in the comments for #WSOM_eff_set_date_range and #WSOM_eff_set_unit_range,
    only one range type is permitted per effectivity,
    legacy data does not have this restriction.
    This method will extract both ranges for such data.
    This method may also be of use if it is unknown what range type a particular effectivity is,
    although in this respect, the function #WSOM_eff_ask_range_type may be of some use.
*/
extern TCCORE_API int  WSOM_eff_ask_ranges(
    tag_t                     release_status,           /**< (I) Tag of the release status to which the effectivity belongs */
    tag_t                     effectivity,              /**< (I) Tag of the effectivity being queried */
    int*                      n_units,                  /**< (O) The size of the array or start-end values */
    int*                      n_dates,                  /**< (O) */
    int**                     units,                    /**< (OF) n_units The array of start-end values */
    date_t**                  dates,                    /**< (OF) n_dates */
    WSOM_open_ended_status_t* unit_open_ended_status,   /**< (O) One of the following constants: #EFFECTIVITY_open_ended,
                                                                 #EFFECTIVITY_stock_out or #EFFECTIVITY_closed. */
    WSOM_open_ended_status_t* date_open_ended_status    /**< (O) */
    );


/**
    Identifies whether an effectivity contains no ranges, unit ranges, date ranges, or both in the case of legacy data.
*/
extern TCCORE_API int WSOM_eff_ask_range_type(
    tag_t               release_status,     /**< (I) Tag of the release status to which the effectivity belongs */
    tag_t               effectivity,        /**< (I) Tag of the effectivity being queried */
    WSOM_range_type_t*  range_type          /**< (O) One of the following constants: #EFFECTIVITY_range_not_defined,
                                                     #EFFECTIVITY_range_unit, #EFFECTIVITY_range_date or
                                                     #EFFECTIVITY_range_legacy_unit_and_date. */
    );


/**
    Clears any existing effectivity ranges from this effectivity object.
    <br/>Required if you want to change from unit to date ranges or vice versa.
*/
extern TCCORE_API int WSOM_eff_clear_ranges(
    tag_t               release_status,     /**< (I) */
    tag_t               effectivity         /**< (I) */
    );


/**
    Sets the end item revision against which a given effectivity is qualified.
    <br/>The release status is locked by this call: use #AOM_save to commit the changes to the database.

    <b>Restrictions:</b>
    Setting or clearing the end item revision also changes the end item to match.
    An effectivity containing unit ranges cannot have a #NULLTAG end item.
*/
extern TCCORE_API int WSOM_eff_set_end_item_rev(
    tag_t               release_status,     /**< (I) Tag of the release status to which the effectivity belongs */
    tag_t               effectivity,        /**< (I) Tag of the effectivity being qualified with an end item */
    tag_t               end_item_rev        /**< (I) Tag of the end item revision */
    );


/**
    Sets the end item against which a given effectivity is qualified.
    <br/>The release status is locked by this call: use #AOM_save to commit the changes to the database.

    <b>Restrictions:</b>
    An effectivity containing unit ranges cannot have a #NULLTAG end item.
*/
extern TCCORE_API int WSOM_eff_set_end_item(
    tag_t               release_status,     /**< (I) Tag of the release status to which the effectivity belongs */
    tag_t               effectivity,        /**< (I) Tag of the effectivity being qualified with an end item */
    tag_t               end_item            /**< (I) Tag of the end item */
    );


/**
    Retrieves the end item revision against which a given effectivity is qualified.
*/
extern TCCORE_API int WSOM_eff_ask_end_item_rev(
    tag_t               release_status,     /**< (I) Tag of the release status to which the effectivity belongs */
    tag_t               effectivity,        /**< (I) Tag of the effectivity */
    tag_t*              end_item_rev        /**< (O) Tag of the end item revision */
    );

/**
    Retrieves the end item against which a given effectivity is qualified.
*/
extern TCCORE_API int WSOM_eff_ask_end_item(
    tag_t               release_status,     /**< (I) Tag of the release status to which the effectivity belongs */
    tag_t               effectivity,        /**< (I) Tag of the effectivity */
    tag_t*              end_item            /**< (O) Tag of the end item */
    );


/**
    Sets the protection on a given effectivity.
    <br/>A protected effectivity is one that cannot be edited.
    The release status is locked by this call; call #AOM_save to commit the changes to the database.
*/
extern TCCORE_API int WSOM_eff_set_protection(
    tag_t               release_status,     /**< (I) Tag of the release status to which the effectivity belongs */
    tag_t               effectivity,        /**< (I) Tag of the effectivity being locked or unlocked */
    logical             protection          /**< (I) True if the effectivity is to be protected to prevent editing, otherwise, false. */
    );


/**
    Retrieves the protection set on a given effectivity. A protected effectivity is one that cannot be edited.
*/
extern TCCORE_API int WSOM_eff_ask_is_protected(
    tag_t               release_status,     /**< (I) Tag of the release status to which the effectivity belongs */
    tag_t               effectivity,        /**< (I) Tag of the effectivity being queried */
    logical*            is_protected        /**< (O) True if the effectivity is being protected to prevent editing, otherwise, false. */
    );


/**
    Identifies whether or not the database is in v7 effectivity mode.
    <br/>If not in v7 mode, the new effectivity functionality will not be available.
    However, in a Multi-Site Collaboration environment,
    all sites must be in v7 effectivity mode to safely exchange effectivity data.
    See change_effectivity_mode utility for more information.
*/


extern TCCORE_API int WSOM_ask_effectivity_mode(
    logical*            is_v7   /**< (O) True if the database is in v7 effectivity mode, otherwise false. */
    );

/**
    Retrieves the EAD (Export Authorization Document) paragraphs attached to a workspace object.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Various errors if parameter cannot be retrieved
    </ul>
*/
extern TCCORE_API int WSOM_ask_ead_paragraph (
    tag_t wso,                      /**< (I) Workspace Object */
    int*  num,                      /**< (O) Number of EAD paragraphs returned */
    char *** paragraph              /**< (OF) num An unpacked array of EAD paragraphs. <br/>The memory is freed by calling #MEM_free on each element and on the container. */
    );

/**
    Generates a new unique revision ID
    <br>If a naming rule is attached to the property fnd0RevisonId of the Workspace Object instance, it is used to generate new ID.
    <br>Otherwise, a default legacy ID generator (similar to Item_Revison_Id) is used.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#NR_no_autogen if a naming rule without counter is attached and the system is not able to generate the id which matches naming rule pattern
    </ul>
*/
extern TCCORE_API int WSOM_generate_new_revision_id(
    tag_t wso_revision,  /**< (I) The tag of the Workspace Object for which a new revision ID is required to be generated. */
    tag_t object_type,       /**< (I) The type of the object. */
    char **id                /**< (OF) The generated ID */
    );

/**
    Generates a new unique thread ID
    <br>If a naming rule is attached to the property fnd0ThreadId of the Fnd0WSOThread Object, it is used to generate new ID.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#NR_no_autogen if a naming rule without counter is attached and the system is not able to generate the id which matches naming rule pattern
    </ul>
*/
extern TCCORE_API int WSOM_generate_new_thread_id(
    tag_t object_type, /**< (I) the type of the object. */
    char **id          /**< (OF) The generated ID */
    );

/** @} */

/**
   Assigns TC_Project value to @p owning_project attribute of @p wso
   <br/>@p owning_project attribute is propagated to other objects based on the propagation rules.
   @note #PROJ_assign_objects or different API(s) will need to be invoked to assign the project_list value.
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#CXPOM_invalid_tag if @p wso is #NULLTAG.
   <li>Possibly other errors
   </ul>
*/
extern TCCORE_API int WSOM_assign_to_owning_project (
    tag_t wso,                /**< (I) The Workspace Object */
    tag_t owning_project      /**< (I) The owning project for assignment */
    );

#ifdef __cplusplus
}
#endif

/** @} */

#include <tccore/libtccore_undef.h>

#endif
