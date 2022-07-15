/*==============================================================================
                     Copyright (c) UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Header File for the ITK provided by the gdis module
*/

/*  */

#ifndef GDIS_H
#define GDIS_H

/*  */

#include <tccore/item.h>
#include <gdis/libgdis_exports.h>

/**
    @defgroup GDIS GDIS
    GDIS API provides a programming interface for the Oracle Tables that store the "measurement" data. It is assumed that the reader is familiar with the GDIS system and terminology. The API is also highly tailored for the other components of GDIS.
    @{
*/

/**
    Structure for providing the Event data during input.
*/
    
    typedef struct DPV_event_s
    {
        char* build_label; /**< Build Label aka Job Number */
        char* event_type; /**< Event type */
        char* event_datetime; /**< Event date time: dd-mon-yy HH24:MI:SS */
        char* vehicle_program; /**< Vehicle Program name */
        char* phase_name; /**< Phase name */
        char* plant_id; /**< Plant (MEPrPlant) Item Id */
        char* routine_id; /**< Routine (MEOP Type) Item Id */
        char* routine_rev; /**< Routine Revision */
        char* device_type; /**< Device Type */
        char* part_name; /**< Part Name */
        char* device; /**< Device Identifier (item id) of the Resource assigned */
        int shift_number; /**< Shift number */
        char* utc_time; /**< Time in UTC dd-mon-yy HH24:MI:SS */
        char* shift_day; /**< shift day time: dd-mon-yy HH24:MI:SS */
    } DPV_event_t, *DPV_event_p_t;

/**
    Structure for providing the Feature Actual data during input.
*/
    typedef struct DPV_ftr_actual_value_s
    {
        char* ftr_uid; /**< Feature UID */
        char* ftr_name; /**< Feature Name */
        char* ftratt_code; /**< Feature Attribute Code */
        double actual_value; /**< Actual Value of the Feature Attribute */
        struct DPV_ftr_actual_value_s* next; /**< Pointer to the next node in the linked list; set to NULL for the last node */
    } DPV_ftr_actual_value_t, *DPV_ftr_actual_value_p_t;

/**
    Structure for providing the Event Trace data during input.
    */
    typedef struct DPV_event_trace_value_s
    {
        char* trace_code; /**< Trace Code Name */
        char* event_trace_code_value; /**< Trace Code Value */
        struct DPV_event_trace_value_s* next; /**< Pointer to the next node in the linkded list; set to NULL for the last node */
    } DPV_event_trace_value_t, *DPV_event_trace_value_p_t;

/**
    Structure for providing the Event data during input.
    NOTE: For values of the type Date Time, the format expected is: dd-mon-yy HH24:MI:SS
*/
    typedef struct DPV_measurement_input_s
    {
        DPV_event_t event_row_values; /**< Values for to be inserted in a row of Event Table */
        DPV_ftr_actual_value_p_t feature_actuals; /**< Pointer to the Head of linked list - Insertions in Feature Actuals Table corresponding to the above event */
        DPV_event_trace_value_p_t event_trace_values; /**< Pointer to the Head of linked list - Insertions in Event Trace Table corresponding to the above event */
        logical trigger_report; /**< flag to tell whether or not to trigger reports for this event insertion */
        int ifail; /**< First error code of the insert transaction */
        struct DPV_measurement_input_s* next; /**< Pointer to the next node in the linkded list; set to NULL for the last node */
        char* event_sys_id; /**< Event Sys Id of the inserted row (OF) */
} DPV_measurement_input_t, *DPV_measurement_input_p_t;


/**
    Structure for providing the Log information
    NOTE: For values of the type Date Time, the format expected is: dd-mon-yy HH24:MI:SS
*/
    typedef struct DPV_log_s
    {
        char* event_time; /**< Event time  */
        char* upload_time; /**< Upload time */
        char* plant_id; /**<plant id */
        char* device_id; /**< device id */
        char* jsn; /**< job sequence number */
        char* script_id; /**< script id */
        char* script_rev; /**< script rev */
        char* routine_id; /**< Routine id */
        char* routine_name; /**< Routine name */
        char* file_name; /**< file name */
        char* url_to_device; /**< Url to device */
        char* feature_name; /**< Feature name */
        char* attribute_id; /**< Attribute id */
        int error_code; /**< Error code */
        char* error_message; /**< Error messagae */
        int ifail; /**< Error Code of the insert transaction */
        struct DPV_log_s* next; /**< Pointer to next node in linked list */
    } DPV_log_t, *DPV_log_p_t;

    /**
        Structure for providing the Feature spec limits information
    */
    typedef struct DPV_limits_s
    {
        char* ftr_uid; /**< UID of the Feature */
        char* ftratt_code; /**< Feature Attribute Code */
        double LSL; /**< LSL of the Feature Attribute */
        double USL; /**< USL of the Feature Attribute */
        struct DPV_limits_s* next;  /**< Pointer to the next node in the linked list */
} DPV_limits_t, *DPV_limits_p_t;

    /**
        Structure for providing the spec set and Reject Limits
        NOTE: For values of the type Date Time, the format expected is: dd-mon-yy HH24:MI:SS
    */
    typedef struct DPV_pf_limit_s
    {
        char* plant_id; /**< Item Id of the Plant */
        char* routine_id; /**< Item Id of the Routine */
        char* routine_rev; /**< Revision of the Routine */
        char* device_type; /**< Type of the Device */
        char* creation_time; /**< Time of creation of the record */
        int error_code; /**< Error code of the first insert failure among the DPV_limit_s structures */
        DPV_limits_p_t ftratt_limits;  /**< The linked list of the limits being inserted */
        struct DPV_pf_limit_s* next;  /**< Pointer to the next node in the linked list */
    } DPV_pf_limit_t, *DPV_pf_limit_p_t;

/**
    An enum to hold the range filter given during the search
*/
typedef enum{
    LAST_N_JOBS,     /**< Most recent X Jobs */
    LAST_N_HRS,      /**< Events executed in the recent X hours */
    LAST_N_MIN,      /**< Events executed in the recent X minutes */
    DATETIME_RANGE, /**< Events executed in the Date Time range given */
    JSN_RANGE,       /**< Events having the Build Label in the given Job Range and executed during the given date time range */
    JSN              /**< Event having the Build Label given and executed during the given date time range */
} DPV_range_filter_given_t;

/**
    A structure to hold the search criteria to be used for fetching feature actuals data from measurement tables. The Routine id and the revision is used for fetching the engineering data. Routine revision is not considered for the measurement data, though
*/
typedef struct DPV_search_criteria_s{
    char* plant_id;         /**< Plant Item Id */
    char* vehicle_program;  /**< Vehicle Program Name */
    char* part_name;        /**< Part Name */
    char* routine_id;       /**< Routine Item Id */
    char* routine_rev;      /**< Revision of Routine */
    char* device;          /**< Device Item Id */
    char* phase_name;      /**< Phase Name */
    char* event_type;      /**< Event Type */
    int shift_number;       /**< Shift number */
    DPV_range_filter_given_t filter_given; /**< Filter being passed */
} DPV_search_criteria_t;

/**
    A structure to give date range of interest – one of the range filters; also used in when a Job or Job Range is filter criteria
    Date time fomat expected is: MM-DD-YYYY HH24:MI:SS
*/
typedef struct{
    char* from_date_time; /**< From Date MM-DD-YYYY HH24:MI:SS */
    char* to_date_time; /**< To Date MM-DD-YYYY HH24:MI:SS */
} DPV_date_time_range_t;

/**
    A structure to give the job range of interest – one of the range filters; job range is associated with a date time too
*/
typedef struct {
    char* from_job; /**< From Job Number */
    char* to_job; /**< To Job Number */
    DPV_date_time_range_t date_time_range; /**< Date Time Range */
} DPV_job_range_t;

/**
    A structure to give the job of interest – one of the range filters; job is associated with a date time too
*/
typedef struct {
    char* job; /**< JSN */
    DPV_date_time_range_t date_time_range; /**< Date Time Range */
} DPV_job_t;

/**
    An union to hold the range filter for search
*/
typedef union{
    int last_x_jobs;    /**< Most recent X Jobs */
    int last_x_hrs;     /**< Events executed in the recent X hours */
    int last_x_min;     /**< Events executed in the recent X minutes */
    DPV_date_time_range_t date_time_range; /**< Events executed in the Date Time range given */
    DPV_job_range_t job_range; /**< Events having the Build Label in the given Job Range and executed during the given date time range */
    DPV_job_t job;    /**< Event having the Build Label given and executed during the given date time range */
} DPV_range_filter_t;

typedef struct DPV_precal_routine_only_s{
    char* date; /**< Date */
    double percentage_on_target; /**< Value of the Percentage On Target Feature Attributes */
    struct DPV_precal_routine_only_s* next; /**< Pointer to next node in the linked list */
} DPV_precal_routine_only_t, *DPV_precal_routine_only_p_t;

typedef struct DPV_db_info_s {
    char* db_name; /**< Database Name */
    char* db_type; /**< Database Type -- oracle or MSSQL */
    char* server_name; /**< Hosting server of the Database */
} DPV_db_info_t, *DPV_db_info_p_t;

/**
    A structure to give date range of interest – one of the range filters; also used in when a Job or Job Range is filter criteria
    Date time fomat expected is: MM-DD-YYYY HH24:MI:SS
*/
typedef struct{
    char* from_date_time; /**< From Date MM-DD-YYYY HH24:MI:SS */
    char* to_date_time; /**< To Date MM-DD-YYYY HH24:MI:SS */
} GDIS_date_time_range_t;

typedef struct GDIS_precal_routine_only_s{
    char* date; /**< Date */
    double percentage_on_target; /**< Value of the Percentage On Target Feature Attributes */
    struct GDIS_precal_routine_only_s* next; /**< Pointer to next node in the linked list */
} GDIS_precal_routine_only_t, *GDIS_precal_routine_only_p_t;

/** Structures for the DPV_get_mapped_ftr_data ITK */
typedef struct DPV_routine_set_s{
    char* routine_id1;
    char* routine_rev1;
    char* routine_id2;
    char* routine_rev2;
} DPV_routine_set_t, *DPV_routine_set_p_t;


typedef struct DPV_mapped_ftr_data_s{
    char* ftr_occ_uid1;                 /**< occurrence uid is under the Routine 1 */
    char* ftr_occ_uid2;                 /**< occurrence uid is under the Routine 2 */
    int ftr_att_count;                  /**< count of mapped feature attributes returned */
    char** ftr_att_code;                /**< list of feature att codes that are common */
    struct DPV_mapped_ftr_data_s* next; /**< pointer to next structure. NULL if it is the last */
} DPV_mapped_ftr_data_t, *DPV_mapped_ftr_data_p_t;


#ifdef __cplusplus
extern "C"
{
#endif


    /**
        This function is used for inserting the data into Event, Feature Actual and Event Trace tables simultaneously. It makes insertions in bulk.
    */
    extern GDIS_API int DPV_insert(
        DPV_measurement_input_p_t measurement_input, /**< (I) Pointer to the Head of the linked list giving the data to be inserted NOTE: GDIS_measurement_input_p_t-event_sys_id is OF */
        int* ai_token, /**< (I) A token that helps Factory Link to identify the availablity of new AI objects for download */
        int* common_ai_token /**< (I) A common token that helps Factory Link to identify the availablity of new AI objects for download */
        );

    /**
        This function is used for making a single row insert in the Event table.
    */
    extern GDIS_API int DPV_insert_event(
        DPV_event_t event_row_values,   /**< (I) Values of the row to be inserted in the Event Table */
        char** event_sys_id   /**< (OF) Event sys id of the insertion made */
        );

    /**
        This function is used for making a set of insertions in the Feature Actual Values table for a given event_sys_id.
    */
    extern GDIS_API int DPV_insert_feature_actuals(
        DPV_ftr_actual_value_p_t feature_actuals, /**< (I) Head of the linked list - Insertion to be made in Feature Actuals table for a given event sys id  */
        char* plant_id , /**< (I) Plant id of the Event to find the DBname and link information */
        char* event_sys_id /**< (I) Event sys id of the Event that measured these feature actual values */
        );
    /**
        This function is used for making a set of insertions in the Feature Actual Values table for a given event_sys_id.
        Here routine_id variable is used for to call call_trigger_service function.
        If routine id is having blank value meaning it is non triggered split routine.
        If routine id is having non blank value meaning it is triggered split routine and we can call call_trigger_service function.

        Here isTrigger value used in the follwoing two cases
        isTrigger value is TRUE then we are considering it all the split data got inserted.
        in another case to call the call_trigger_serivice function based on routine id value.
    */
    extern GDIS_API int DPV_insert_feature_actuals_new(
        DPV_ftr_actual_value_p_t feature_actuals, /**< (I) Head of the linked list - Insertion to be made in Feature Actuals table for a given event sys id  */
        char* plant_id , /**< (I) Plant id of the Event to find the DBname and link information */
        char* event_sys_id, /**< (I) Event sys id of the Event that measured these feature actual values */
        char* routine_id, /**< (I) Routine Id of the Event that measured these feature actual values */
        logical isTrigger /**< (I)This is trigger_reports property value for the routine*/
        );

    /**
        This function is used for making a set of insertions in the Event Trace table for a given event_sys_id.
    */
    extern GDIS_API int DPV_insert_event_trace_values(
        DPV_event_trace_value_p_t event_trace_values, /**< (I) Head of the linked list - Insertion to be made in Event Trace table for a given event sys id  */
        char* plant_id, /**< (I) Plant id of the Event to find the DBname and link information */
        char* event_sys_id /**< (I) Event sys id of the Event that measured these feature actual values */
        );

    /**
        This function is used for making a set of insertions in the Log table 
    */
    extern GDIS_API int DPV_insert_log(
        DPV_log_p_t  log_input, /**< (I) Linked list of Log information */
        int* ai_token, /**< (I) A token that helps Factory Link to identify the availablity of new AI objects for download */
        int* common_ai_token /**< (I) A common token that helps Factory Link to identify the availablity of new AI objects for download */
        );

    /**
        This function is used for making a set of insertions in the Spec set limit table 
    */
    extern GDIS_API int DPV_insert_pf_spec_limit(
        DPV_pf_limit_p_t spec_limit_input /**< (I) Linked list of spec set limits */
        );

    /**
        This function is used for making a set of insertions in the Reject set limit table 
    */
    extern GDIS_API int DPV_insert_pf_reject_limit(
        DPV_pf_limit_p_t reject_limit_input /**< (I) Linked list of Reject set limits */
        );

    /**
        This function is used for updation of measmt event values 
    */
    extern GDIS_API int DPV_update_event_col(
    char* plant_id, /**< (I) Plant Id of the Event to find the DBname and link information */
    char* event_sys_id, /**< (I) Event Sys Id of the Event whose event type is to be updated */
    char* column_name,  /**< (I) Name of the column to be updated */
    char* new_value    /**< (I) New value of the Column for the given Event Sys Id */
    );

/**
     This function is used for making a query to get Plants.
*/
extern GDIS_API int DPV_get_plants(
    int* num_results,          /**< (O) Number of Vehicle Programs found */
    char*** plant_ids   /**< (OF) List of Vehicle Prgrams found */
    );

/**
    This function is used for making a query to get Vehicle Programs for a given Plant (MEPrPlant) Item Id
*/
extern GDIS_API int DPV_get_vehicle_programs(
    char* plant_id,            /**< (I) Item Id of the Plant */
    int* num_results,          /**< (O) Number of Vehicle Programs found */
    char*** vehicle_programs   /**< (OF) List of Vehicle Prgrams found */
    );

/**
    This function is used for making a query to get Device Types for a given Plant (MEPrPlant) Item Id and Vehicle Program
*/
extern GDIS_API int DPV_get_device_types(
    char* plant_id,         /**< (I) Item Id of the Plant */
    char* vehicle_program,  /**< (I) Vehicle Program name */
    int* num_results,       /**< (O) Number of Device Types found */
    char*** device_types    /**< (OF) List of the Device Types found */
    );

/**
    This function is used for making a query to get Device Types for a given Plant (MEPrPlant) Item Id, Vehicle Program and Device Type
*/
extern GDIS_API int DPV_get_parts(
    char* plant_id,         /**< (I) Item Id of the Plant */
    char* vehicle_program,  /**< (I) Vehicle Program name */
    char* device_type,      /**< (I) Device Type name */
    int* num_results,      /**< (O) Number of Parts found */
    char*** part_names     /**< (OF) List of the Part Names found */
    );

/**
    This function is used for making a query to get Item Ids of Routines (MEOP) for a given Plant Item Id, Vehicle Program, Device Type and Part Name
*/
extern GDIS_API int DPV_get_routines(
    char* plant_id,        /**< (I) Item Id of the Plant */
    char* vehicle_program, /**< (I) Vehicle Program Name */
    char* device_type,     /**< (I) Device Type Name */
    char* part_name,       /**< (I) Part Name */
    int* num_results,      /**< (O) Number of Routines found */
    char*** routine_ids    /**< (OF) List of Item Ids of the Routines found */
    );

/**
    This function is used for making a query to get Device Identifiers for a given Plant Item Id, Vehicle Program, Device Type, Part and Routine (MEOP) Item Id 
*/
extern GDIS_API int DPV_get_devices(
    char* plant_id,        /**< (I) Item Id of the Plant */
    char* vehicle_program, /**< (I) Vehicle Program Name */
    char* device_type,     /**< (I) Device Type Name */
    char* part_name,       /**< (I) Part Name */
    char* routine_id,      /**< (I) Routine Item Id */
    int* num_results,      /**< (O) Number of Devices found */
    char*** devices        /**< (OF) List of the Device Identifiers found */
    );

/**
    This function is used for making a query to get Phase Names for a given Plant Item Id, Vehicle Program, Device Type, Part and Routine (MEOP) Item Id
*/
extern GDIS_API int DPV_get_phases(
    char* plant_id,        /**< (I) Item Id of the Plant */
    char* vehicle_program, /**< (I) Vehicle Program Name */
    char* device_type,     /**< (I) Device Type Name */
    char* part_name,       /**< (I) Part Name */
    char* routine_id,      /**< (I) Routine Item Id */
    int* num_results,      /**< (O) Number of Phases found */
    char*** phase_names    /**< (OF) List of names of the Phases found */
    );

/**
    This function is used for making a query to get Event Types for a given Plant Item Id, Vehicle Program, Device Type, Part and Routine (MEOP) Item Id
*/
extern GDIS_API int DPV_get_event_types(
    char* plant_id,        /**< (I) Item Id of the Plant */
    char* vehicle_program, /**< (I) Vehicle Program Name */
    char* device_type,     /**< (I) Device Type Name */
    char* part_name,       /**< (I) Part Name */
    char* routine_id,      /**< (I) Routine Item Id */
    int* num_results,      /**< (O) Number of results */
    char*** event_types    /**< (OF) List of Event Types found */
    );

/**
    This function is used for getting the raw data for a given Search Criteria. The raw data is written to a text file and a read ticket is given as output
*/
extern GDIS_API int DPV_get_raw_data_for_routine(
    DPV_search_criteria_t search_criteria, /**< (I) Search Criteria for fetching measurement data of a Routine */
    DPV_range_filter_t range_filter,        /**< (I) Range Filter used to control the number of events to be fetched from the measurement data */
    char** raw_data_read_ticket             /**< (OF) A read ticket for the Raw Data */
    );

/**
    This function is used for getting the precalculated data for a given Search Criteria.
*/
extern GDIS_API int DPV_get_prec_on_target_for_routine(
    char* plant_id,                          /**< (I) Plant Id */
    char* routine_id,                        /**< (I) Routine Item Id */
    char* routine_rev,                       /**< (I) Routine Revision */
    DPV_date_time_range_t date_range,       /**< (I) Date range in which percentage on target */
    char* spec_set_code,                     /**< (I) Spec set code of interest */
    DPV_precal_routine_only_p_t *routine_cal/**< (OF) Precalculated data  */
    );

/**
    This function is used for getting the precalculated data for a given Search Criteria.
*/
extern GDIS_API int GDIS_get_prec_on_target_for_routine(
    char* routine_id,                        /**< (I) Routine Item Id */
    char* routine_rev,                       /**< (I) Routine Revision */
    GDIS_date_time_range_t date_range,       /**< (I) Date range in which percentage on target */
    char* spec_set_code,                     /**< (I) Spec set code of interest */
    GDIS_precal_routine_only_p_t* routine_cal/**< (OF) Precalculated data */
    );


/**
    This function is used for creating a cluster.
*/
extern GDIS_API int DPV_create_cluster(
    char* routine_id,          /**< (I) Routine Item Id */
    char* routine_rev,         /**< (I) Routine Revision */
    char* cluster_name,        /**< (I) Name of the cluster to be created */
    char* cluster_desc,        /**< (I) Description of the cluster to be created */
    int num_ftratt,            /**< (I) Number of feature attributes */
    char** ftr_uid_list,       /**< (I) Array of UIDs of features, whose feature attributes have to be added to the cluster */
    char** ftratt_code_list,   /**< (I) Array of ftratt_codes of the feature attributes to be added to the cluster */
    char** cluster_uid         /**< (OF) UID of the cluster created */
    );

/**
    This function is used to modify a cluster, i.e. either to add feature-attributes to a cluster or to remove feature-atributes from a cluster.
*/
extern GDIS_API int DPV_modify_cluster(
    char* routine_id,         /**< (I) Routine Item Id */
    char* routine_rev,        /**< (I) Routine Revision */
    char* cluster_uid,        /**< (I) UID of the cluster to be modified */
    int num_ftratt,           /**< (I) Number of feature attributes */
    char** ftr_uid_list,      /**< (I) Array of UIDs of features, whose feature attributes would replace the existing list */
    char** ftratt_code_list   /**< (I) Array of ftratt_codes of the feature attributes which would replace the existing list in Cluster */
    );

/**
    This function is used to get the feature-attributes of a cluster.
*/
extern GDIS_API int DPV_cluster_get_ftratt(
    char* routine_id,         /**< (I) Routine Item Id */
    char* routine_rev,        /**< (I) Routine Revision */
    char* cluster_uid,        /**< (I) UID of the cluster, whose feature attributes are to be fetched */
    int* count_ftratt,        /**< (O) Number of feature attributes found */
    char*** ftr_uid_list,     /**< (OF) Array of UIDs of features */
    char*** ftratt_code_list  /**< (OF) Array of feature-attribute codes */
    );

/**
    This function is used to delete a cluster.
*/
extern GDIS_API int DPV_delete_cluster(
    char* cluster_uid       /**< (I) UID of the Cluster */
    );
/**
    This function is used to check if a given cluster exists.
*/
extern GDIS_API int DPV_is_engg_obj_available(
    char* engg_obj_uid,       /**< (I) UID of the Engineering Object */
    logical* answer          /**< (O) returns true if the cluster is available or false if otherwise */
    );

/**
    This function is used to create a cluster-group.
*/
extern GDIS_API int DPV_create_cluster_group(
    char* cluster_group_name,  /**< (I) Name of the cluster-group to be created */
    char* cluster_group_desc,  /**< (I) Description of the cluster-group to be creted. optional */
    int num_clusters,          /**< (I) Number of feature attributes */
    char** cluster_uid_list,   /**< (I) Array of UIDs of clusters to be inserted in the cluster-group */
    char** cluster_group_uid   /**< (OF) UID of the cluster-group created */
    );


/**
    This function is used to add a cluster to a cluster-group.
*/
extern GDIS_API int DPV_add_cluster_to_cluster_group(
    char* cluster_group_uid,  /**< (I) UID of the cluster-group */
    char* cluster_uid         /**< (I) UID of the cluster */
    );

/**
    This function is used to remove a cluster from a cluster-group.
*/
extern GDIS_API int DPV_del_cluster_frm_cluster_grp(
    char* cluster_group_uid,  /**< (I) UID of the cluster-group */
    char* cluster_uid         /**< (I) UID of the cluster */
    );

/**
    This function is used to obtain the clusters of a cluster-group.
*/
extern GDIS_API int DPV_cluster_group_get_clusters(
    char* cluster_group_uid,  /**< (I) UID of the cluster-group */
    int* count_clusters,      /**< (O) Number of clusters found */
    char*** cluster_uid_list  /**< (OF) Array off UIDs of clusters found */
    );

/**
    This function is used to create cluster on routine
*/
extern GDIS_API int DPV_create_cluster_on_routine (
    char* routine_id,    /**< (I) routineId */
    char* routine_rev,   /**< (I) routineRev */
    char* cluster_name,  /**< (I) cluster name that you are going to create */
    char* cluster_desc,  /**< (I) cluster description */
    int ftr_id_cnt,      /**< (I) Number of ftrs that you are sending.*/
    char** ftr_id,       /**< (I) Array of ftr_ids */
    char** ftr_name,     /**< (I) Array of ftr_names */
    char** ftratt_code,  /**< (I) Array of ftratt_codes */
    char** cluster_id,   /**< (OF) Cluster Id */
    char** cluster_rev   /**< (OF) Cluster Rev */
    );
/**
    This function is used to edit the cluster
*/
extern GDIS_API int DPV_edit_cluster(
    char* cluster_id,      /**< (I) Cluster Id which you are going to edit */
    char* cluster_rev,     /**< (I) Revision of above given cluster id */
    int ftr_id_cnt,        /**< (I) Number of ftrs that you are sending */
    char** ftr_id,         /**< (I) Array of ftr_ids */
    char** ftr_name,       /**< (I) Array of ftr_names */
    char** ftratt_code     /**< (I) Array of ftratt_codes */
    );
/**
    This function is used to get the contents from the given cluster
*/
extern GDIS_API int DPV_get_cluster_content(
    char* cluster_id,      /**< (I) Cluster Id which you are interested to get the content */
    char* cluster_rev,     /**< (I) Revision of above given cluster id */
    int* ret_count,        /**< (O) Number of ftrs that you are getting */
    char*** ftr_id,        /**< (OF) Array of ftr_ids */
    char*** ftr_name,      /**< (OF) Array of ftr_names */
    char*** ftratt_code    /**< (OF) Array of ftratt_codes */
    );
/**
    This function is used to remove the cluster from the routine.
*/
extern GDIS_API int DPV_rem_cluster_on_routine(
    char* routine_id,    /**< (I) Routine Id which your interested cluster having relation */
    char* routine_rev,   /**< (I) Revision of above given routine id */
    char* cluster_id,    /**< (I) Cluster Id which you are interested to remove */
    char* cluster_rev    /**< (I) Revision of above given cluster id */
    );
/**
    This function is used to know whether the given cluster is exist or not
*/
extern GDIS_API int DPV_does_cluster_exist(
    char* cluster_id,    /**< (I) Cluster Id in which you are interested */
    char* cluster_rev,   /**< (I) Revision of above given cluster id */
    logical* answer      /**< (O) It's a logica value.(true if exist,false if does't */
    );
/**
    This function is used to remove cluster rev.
    First it will remove the relations and references and then it deletes the cluster it self.
*/
extern GDIS_API int DPV_del_cluster_rev(
    char* cluster_id,    /**< (I) Cluster Id in which you are interested to delete */
    char* cluster_rev    /**< (I) Revision of above given cluster id */
    );
/**
    This function is used to create a cluster-group.
*/
extern GDIS_API int DPV_create_clustergroup(
    char* cluster_group_name,     /**< (I) Cluster Group name */
    char* cluster_group_desc,     /**< (I) Cluster Group description */
    int num_clusters,             /**< (I) Number of clusters that you are going add under cluster group */
    char** cluster_id,            /**< (I) Array of cluster ids */
    char** cluster_rev,           /**< (I) Array of cluster revisions */
    char** cluster_group_id,      /**< (O) Cluster Group Id */
    char** cluster_group_rev      /**< (O) Revision of above given cluster group id */
    );
/**
    This function is used to add clusters to a cluster group.
*/
extern GDIS_API int DPV_add_cluster_to_clustergroup(
    char* cluster_group_id,     /**< (I) Cluster Group Id */
    char* cluster_group_rev,    /**< (I) Cluster Group Revision */
    char* cluster_id,           /**< (I) Cluster Id in which you are interested to add */
    char* cluster_rev           /**< (I) Revision of above given cluster id.*/
    );
/**
    This function is used to remove the cluster from the cluster group.
*/
extern GDIS_API int DPV_rem_cluster_frm_cluster_grp(
    char* cluster_group_id,     /**< (I) Cluster Group Id */
    char* cluster_group_rev,    /**< (I) Cluster Group Revision */
    char* cluster_id,           /**< (I) Cluster Id in which you are interested to remove */
    char* cluster_rev           /**< (I) Revision of above given cluster id*/
    );
/**
    This function is used to get cluster from the cluster group
*/
extern GDIS_API int DPV_get_clusters_of_clustergroup (
    char* cluster_group_id,     /**< (I) Cluster Group Id */
    char* cluster_group_rev,    /**< (I) Cluster Group Revision */
    int* ret_count,             /**< (O) Count of clusters that will return */
    char*** cluster_id,         /**< (OF) Array of cluster ids */
    char*** cluster_rev         /**< (OF) Array of cluster Revisions */
    );
/**
    This function is used to obtain the mapped feature attributes for a given pair of routines
*/
extern GDIS_API int DPV_get_mapped_ftr_data (
    DPV_routine_set_t routine_set,             /**< (I) R1 & R2 */
    DPV_mapped_ftr_data_p_t* mapped_ftr_data   /**< (OF) Linked List of DPV_mapped_ftr_data_s structures */
    );

/**
    This function is used to obtain the mapped feature attributes for a given pair of routines based on PortingMap sheet 
*/
extern GDIS_API int DPV_get_mapped_ftr_portdata (
    DPV_routine_set_t routine_set,             /**< (I) R1 & R2 */
    DPV_mapped_ftr_data_p_t* mapped_ftr_data   /**< (OF) Linked List of DPV_mapped_ftr_data_s structures */
    );

/**
    This function is used to obtain the database information for a given plant id
*/
extern GDIS_API int DPV_get_dbinfo_for_plant (
    char* plant_id,    /**< (I) The plant id whose data is of interest */
    DPV_db_info_p_t* db_info   /**< (OF) Structure with details of the measurement database */
);

/**
    This function is used for getting the token to return to factory link.
*/
extern GDIS_API int DPV_update_ai_token ( );

/**
    This function is used for getting the token to return to factory link.
*/
extern GDIS_API int DPV_get_ai_token(
     int* ai_token /**< (O) current value stored in the cell */
);


/**
    This function is used to import the feature data for a given routine
*/
extern GDIS_API int DPV_import_feature_data (
    tag_t routine_revision, /**< (I) The tag of the routine revision */
    char* read_ticket,    /**< (I) The read ticket of the XML file */
    char* ds_name,        /**< (I) Name of the dataset */
    char* ds_description  /**< (I) Description of the dataset */
);

/**
    This function is used for getting the token to return to factory link.
*/
extern GDIS_API int DPV_update_common_ai_token ( );

/**
    This function is used for getting the token to return to factory link.
*/
extern GDIS_API int DPV_get_common_ai_token(
     int* common_ai_token /**< (O) current value stored in the cell */
);

/**
    This function is used to create the relationship between routine revision to xlsb dataset.
*/
extern GDIS_API int DPV_relation_bw_Ruleset_RoutineRev (
    tag_t xlsbDatasetTag, /**< (I) The tag of the xlsb dataset */
    tag_t routineRevTag /**< (I) The tag of the routine revision */
);

/**
    This function is used to get the xlsb dataset corresponding to a dpv excel dataset.
*/
extern GDIS_API int getCustomXLSBForXLSX(
    tag_t dpvExcelDsTag, /**< (I) The tag of the xlsb dataset */
    tag_t *xlsbDsTag /**< (O) The tag of the routine revision */
);

/**
    This function is used for to call the trigger service.
*/
extern GDIS_API int call_trigger_service(
    char **routines, /**< (I) Array of routines*/
    int count        /**< (I) Routines count*/
    );

#ifdef __cplusplus
}
#endif

/** @} end of GDIS */

#include <gdis/libgdis_undef.h>

#endif
