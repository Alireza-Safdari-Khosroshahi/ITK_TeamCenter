/*==============================================================================
                Copyright (c) 2006 UGS
                Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Import Export functions
*/

#ifndef TIE_H
#define TIE_H

#include <pie/pie.h>
#include <tc/tc_startup.h>
#include <tccore/tctype.h>
#include <tccore/workspaceobject.h>
#include <tie/tie_errors.h>
#include <trv/trv.h>

#include <tie/libtie_exports.h>

/**
    @defgroup TIE TCPLMXML Import/Export

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
*/


/*

*/
typedef enum Object_status_in_map_e
{
/*

*/
    TIE_NOCOMMENT         = 0,
    TIE_NEW                  ,
    TIE_UPDATE               ,
    TIE_DELETE               ,
    TIE_FAILED               ,
    TIE_SKIPPED              ,
    TIE_REPLACED             ,
    TIE_STUBBED              ,
    TIE_OWNPASSED            ,
    TIE_OWNFAILED            ,
    TIE_DELETEFAILED         ,
    TIE_CHECKINFAILED        ,
    TIE_NOTOWNCHECKOUT       ,
    TIE_ROLLINGBACK          ,
    TIE_UNPROCESSED          ,
    TIE_INITIALIZED          ,
    TIE_NEWUNPROCESSED       ,
    TIE_PREPROCESSED         ,
    TIE_UPDATEUNPROCESSED    ,
    TIE_NEWTOBEPROCESSED     ,
    TIE_UPDATETOBEPROCESSED ,
    TIE_REPLACESTUBWITHNEW  ,
    TIE_UPDATEWITHSITECO    ,
    TIE_UPDATEWITHOWNERSHIPCHANGE ,
    TIE_OCCDELETE         ,
    TIE_GRMDELETE         ,
    TIE_ITEMREVDELETE     ,
    TIE_NAMEDREFDELETE    ,
    TIE_DUPLICATEGSID     ,
    TIE_OBJECTCREATEDASHELPER,
    TIE_COEOWNFAILED,
    PRIMARY_FAILED,
    TIE_NAMEDREFREPLACED,
    TIE_UNMANAGED_SKIP,
    TIE_UNMANAGED_NEW,
    TIE_UNMANAGED_UPDATE,
    TIE_UNMANAGED_UNKNOWN,
    TIE_REV_NEW_INSTANCE_TOBEPROCESSED,
    TIE_REV_NEW_TOBEPROCESSED,
    TIE_REV_UPDATE_TOBEPROCESSED,
    TIE_REV_NEW,
    TIE_REV_UPDATE
} Object_status_in_map_t;

/**
 * Scope_rules_import_mode_t enum details
 */
typedef enum Scope_rules_import_mode_e
{
    UNDEFINED_MODE = 0,
    IGNORE_MODE    = 1,      /**< Ignores already existing scope rules during import */
    OVERWRITE_MODE = 2,      /**< Overwrites already existing scope rules during import */
    APPEND_MODE = 3,         /**< Appends clauses to already existing closure rules during import */
    DELETE_CLAUSE_MODE = 4   /**< Deletes clauses from a closure rule */
} Scope_rules_import_mode_t;

/**
 * TIE_output_data structure details
 */
typedef struct TIE_output_data_s
{
    char *xmlFilePath;
    char *importexport_log_fmsticket;              /**< FMS Ticket of log file */
    char *failedobjects_fmsticket;                 /**< FMS Ticket of failed objects xml file used.
                                                   <br/>Used for importer only. For exporter this field is null. */
    int    nRootObjs;
    tag_t* rootObjs;
    int    nNewObjs;
    tag_t* newObjs;
    int    nUpdatedObjs;
    tag_t* updatedObjs;
    int    nDeletedObjsGSIdentities;
    char** deletedObjsGSIdentities;
}TIE_output_data_t;

typedef struct TIE_transfer_formula_s
{
    char *optionSetName;               /**< Name of optionset */
    char *optionSetUid;                /**< UID of optionset or null */
    int  n_options;                    /**< Number of options */
    TIE_option_value_t *optionOverrides; /**< Reference to the option overrides structure*/
    int  n_sessOptions;                /**< Number of session options */
    TIE_option_value_t *sessionOptions;  /**< Reference to the session options structure*/
    char *transferModeName;            /**< Name of Transfermode */
    char *transferModeUid;             /**< UID of Transfermode or null */
    char *logFileName;               /**< File name for log output or null */
    char *logFilePath;               /**< File path for log output or null */
    char   *xsltFMSTicket;             /**< FMS File ticket for xslt file    */
    char *reason;                      /**< Reason string */
} TIE_transfer_formula_t;

typedef struct ownershipChange_s
{
    int    destinationSiteId;     /**< Destination site */
    int    gsidCnt;               /**< Number of object Gsid Strings */
    char** gsidStrs;              /**< Object Gsid strings */
} ownershipChange_t;

typedef struct stubInfo_s
{
    int    masterSiteId;          /**< Master site */
    int    gsidCnt;               /**< Number of object Gsid Strings */
    char** gsidStrs;              /**< Object Gsid strings */
} stubInfo_t;

typedef struct locale_data_s
{
    tag_t  obj;             /**< tc object */
    int    nProps;          /**< number of locale contents */
    char** propNames;       /**< L10N attribute names */
    char** propValues;      /**< L10N attribute values */
} locale_data_t;

typedef struct TIEGSIdentityInput_s
{
    char* system;
    char*  label;
    char*  subLabel;
    char*  className;
    char*  split_token;
    char*  context;
    char*  object_uid;
    char*  factor_id;
    logical atomic;
} TIEGSIdentityInput_t;

/**
    Enum for TIE export status
*/
typedef enum TIE_export_status_e
{
    EXPORT_SUCCESS,
    EXPORT_SUCCESS_STUB,
    EXPORT_PENDING,
    EXPORT_PENDING_STUB,
    EXPORT_PENDING_TRANSFER_OWNER,
    EXPORT_FAIL,
    EXPORT_REPLICA_DELETED,
    EXPORT_CONVERT_TO_STUB,
    EXPORT_SITE_CHECKIN,
    EXPORT_PENDING_SITE_CHECKIN_DELETE,
    EXPORT_MAX_STATUS
} TIE_export_status_t;

#define TIE_serialize_msg       "TIE_serialize"
#define TIE_deserialize_msg     "TIE_deserialize"

/**
    Function message for custom traversal method
*/
#define TIE_customTraversal_msg "TIE_customTraversal"

#ifdef __cplusplus
    extern "C"{
#endif


/**
    Exports a list of objects
*/
extern TIE_API int TIE_export_objects(
    const char *tcGSMessageId,      /**< (I) Unique id for transaction */
    int n_objects,                  /**< (I) Number of objects to export */
    tag_t* objects,                 /**< (I) n_objects Objects to export */
    int n_siteTags,                 /**< (I) Number of sites to export to */
    tag_t* targetSiteTags,          /**< (I) n_siteTags Tags of target sites */
    logical synchronize,            /**< (I) Synchronize objects */
    TIE_transfer_formula_t opts,    /**< (I) Structure of options */
    TIE_output_data_t* output_data  /**< (I) Output data structure*/
    );

/**
    Traverse a list of objects
*/
extern TIE_API int TIE_traverse_objects(
    const char *tcGSMessageId,      /**< (I) Unique id for transaction */
    int n_objects,                  /**< (I) Number of objects to export */
    tag_t* objects,                 /**< (I) n_objects Objects to export */
    int n_siteTags,                 /**< (I) Number of sites to export to */
    tag_t* targetSiteTags,          /**< (I) n_siteTags Tags of target sites */
    logical synchronize,            /**< (I) Synchronize objects */
    TIE_transfer_formula_t opts,    /**< (I) Structure of options */
    TIE_output_data_t* output_data  /**< (I) Output data structure*/
    );

/**
    Confirm export and failure of objects
*/
extern TIE_API int TIE_confirm_export(
    tag_t targetSiteTag,          /**< (I) Tag of target site */
    const char *tcGSMessageId,    /**< (I) Unique id for transaction */
    int n_failed_objects,         /**< (I) Number of objects that failed to export */
    tag_t* failed_objects,        /**< (I) n_failed_objects Objects that failed to export */
    logical commit,               /**< (I) commit export or roll back on failure */
    int *n_ownership,             /**< (O) Number of ownership changes */
    ownershipChange_t** ownership,/**< (OF) n_ownership Ownership change list */
    int *n_stubs,                 /**< (O) Number of stubs */
    stubInfo_t** stubs            /**< (OF) n_stubs Stub replication list */
    );

/**
   Imports TCXML file into Teamcenter.
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TIE_invalid_optionset_for_hl_import The transfer option set is for low level briefcase import only and cannot be used for high level TCXML file.
   <li>#TIE_invalid_input_file Invalid The input TCXML file is invalid.
   </ul>
*/
extern TIE_API int TIE_import_objects(
    const char *transaction_id,    /**< (I) Unique id for transaction or NULL */
    tag_t master_site,             /**< (I) Master site or NULL */
    TIE_transfer_formula_t opts,   /**< (I) Structure of options */
    char* input_xml_file,          /**< (I) fms ticket for input xml file*/
    TIE_output_data_t* output_data /**< (OF) Logfile and failedobjects file */
    );

/**
    Extract information from TIE_Message_t
*/
extern TIE_API int TIE_get_object_from_mesg(
    void* tieGenMesg,              /**< (I) TIE_message_t */
    tag_t* objectTag               /**< (O) object tag */
    );

/**
    Generate a number of pre-constructed Teamcenter UIDs.
*/
extern TIE_API int TIE_get_preconstructed_uids(
        int numRequestedUids,       /**< (I) Number of UIDs to construct */
        int* numConstructedUids,    /**< (O) Number of UIDs constructed */
        char*** constructedUids     /**< (OF) numConstructedUids UIDs constructed */
);

/**
    Takes a hash key as input and generates a valid Teamcenter UID based on it.
*/
extern TIE_API int TIE_get_hashed_uid(
        int ownSiteId,          /**< (I) Site Id of Legacy system/ */
        const char* hashKey,    /**< (I) Hash Key */
        char** hashedUID        /**< (OF) Valid Teamcenter UID for given hash key */
);

/**
    Creates GSIdentities in bulk.
*/
extern TIE_API int TIE_create_gsidentities(
        int numInput,                   /**< (I) Number of GSIdentityInputs */
        TIEGSIdentityInput_t* input,    /**< (I) Array of Structures containing GSID info */
        int* numGSIDTags,               /**< (O) Number of created GSIdentity Tags */
        tag_t** gsidTags                /**< (OF) numGSIDTags Number of  GSIdentity Tags created */
);

/** @} */

/**
    External User action rule support
 */
typedef int (* TIE_user_action_func_t)( tag_t );

extern TIE_API int TIE_register_user_action (
  char*                      handleName,    /**< (I) Action name */
  TIE_user_action_func_t     user_m         /**< (I) Action method */
  );


/**
    External User filter rule support
 */
typedef PIE_rule_type_t (* TIE_user_filter_func_t)( void *);

extern TIE_API int TIE_register_user_filter (
  char*          filterRuleName,    /**< (I) Filter name */
  TIE_user_filter_func_t user_m     /**< (I) Filter method */
  );

extern TIE_API int TIE_get_L10N_properties (
  tag_t          sessTag,                  /**< (I) Session */
  int            nObjs,                    /**< (I) number of objects */
  tag_t*         objTags,                  /**< (I) Array of objects */
  locale_data_t  **L10NProps               /**< (O) Array of Locale data */
  );

/**
    Confirms low level import and failure of objects
    @note Starting tc10.1.4, ACCT_TABLE was upgraded with app_id. This method is only for site consolidation usage. 
    <br/>The method takes ":SITECON_SYNC" as @p app_id when updating ACCT_TABLE.
*/
extern TIE_API int TIE_lowlevel_confirm_import_with_file(
    const char       *tcGSMessageId,         /**< (I) Unique id for transaction or NULL */
    int               nSucessIslands,        /**< (I) Number of objects that exported successfully */
    char            **sucessIslands,         /**< (I) nSucessObjects Objects that exported Successfully */
    int               nFailureIslands,       /**< (I) Number of objects that failed to export */
    char            **failureIslands,        /**< (I) nFailureObjects Objects that failed to export */
    TIE_output_data_t* output_data           /**< (I) Output data structure*/
    );

/**
    Performs high level ownership transfer (flip-the-switch)
*/
extern TIE_API int TIE_flip_ownership(
    const char *tcGSMessageId,       /**< (I) Unique id for transaction or NULL */
    int n_siteTags,                  /**< (I) Number of sites to export to */
    tag_t* targetSiteTags,           /**< (I) n_siteTags Tags of target sites */
    TIE_output_data_t* output_data,  /**< (I) Output data structure*/
    logical isFlipDryRun             /**< (I) Dryrun mode option*/
    );

/**
   Exports data in the PLMXML format according to specified options.
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TIE_error_occurred if the export operation has failed for any other reason (invalid parameter, traversal failure, invalid output location, etc.).
   </ul>
*/
extern TIE_API int TIE_export_to_plmxml(
    int n_objects,                  /**< (I)  Number of objects to export */
    tag_t* objects,                 /**< (I)  n_objects Objects to export */
    TIE_transfer_formula_t* opts,   /**< (I)  Structure of options */
    TIE_output_data_t* output_data  /**< (OF) Output data structure*/
    );

/**
   Imports data in the PLMXML format according to specified options.
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#TIE_error_occurred if the import operation has failed for any other reason (invalid input file, invalid parameter, import failure etc.).
   </ul>
*/
extern TIE_API int TIE_import_from_plmxml(
    const char *appId,              /**< (I) Application id for import */
    const char * fileName,          /**< (I) File Name for import */
    TIE_transfer_formula_t* opts,   /**< (I) Structure of options */
    TIE_output_data_t* output_data  /**< (I) Output data structure*/
    );
    
#ifdef __cplusplus
}
#endif

#include <tie/libtie_undef.h>

#endif

