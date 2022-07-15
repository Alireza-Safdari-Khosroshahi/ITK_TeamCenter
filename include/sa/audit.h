/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all data types and constants to be used by
    clients of the Event Manager.
*/

/*  */

#ifndef AUDIT_H
#define AUDIT_H

#include <qry/qry.h>
#include <tc/tc_startup.h>
#include <tccore/workspaceobject.h>
#include <tccore/item.h>
#include <stdarg.h>
#include <ss/ss_const.h>
#include <sa/tccalendar.h>

#include <sa/libsa_exports.h>

/**
    @defgroup AUDIT Audit
    @ingroup SA
    @{
*/

#define  AUDIT_equal                   0
#define  AUDIT_not_equal               1
#define  AUDIT_less_than               2
#define  AUDIT_less_than_or_equal      3
#define  AUDIT_greater_than            4
#define  AUDIT_greater_than_or_equal   5
#define  AUDIT_like                    6
#define  AUDIT_in                      7


/**
    The following are the field names to be used in constructing the search clause:
    <ol>
    <li>objectTag
    <li>eventTypeTag
    <li>id
    <li>name
    <li>rev
    <li>userId
    <li>beforeDate
    <li>afterDate
    <li>eventTypeName
    <li>eventTypeName
    </ol>
*/
typedef struct AUDIT_log_query_s {
    tag_t      objectTag;
    int        objectOperator;
    tag_t      eventTypeTag;
    int        eventTypeOperator;
    char*      id;
    int        idOperator;
    char*      name;
    int        nameOperator;
    char*      rev;
    int        revOperator;
    char*      puid;
    int        puidOperator;
    char*      userId;
    int        userIdOperator;
    date_t*    beforeDate;
    int        beforeDateOperator;
    date_t*    afterDate;
    int        afterDateOperator;
    char*      eventTypeName;
    int        eventTypeNameOperator;
    char*      groupName;
    int        groupNameOperator;
    tag_t      groupTag;
    int        groupTagOperator;
    char*      objSeqNumber;
    int        objSeqNumberOperator;
    char*      objTypeName;
    int        objTypeNameOperator;
    tag_t      secObjectTag;
    int        secObjectTagOperator;
    char*      secObjId;
    int        secObjIdOperator;
    char*      secObjName;
    int        secObjNameOperator;
    char*      secObjRev;
    int        secObjRevOperator;
    char*      secObjTypeName;
    int        secObjTypeNameOperator;
    char*      secObjSeqNumber;
    int        secObjSeqNumberOperator;
    char*      errorCode;
    int        errorCodeOperator;
    char*      errorMsg;
    int        errorMsgOperator;
    char*      projectName;
    char*      projectId;
    char*      projectUid;
    int        projectUidOperator;
} AUDIT_log_query_t;

typedef struct AUDIT_record_s {
    char       objTagStr[15];
    char       objName[TCCALENDAR_name_size_c + 1];
    char       id[ITEM_id_size_c + 1];
    char       revName[33];
    int        objSeqNumber;
    char       objTypeName[33];
    char       eventTypeTagStr[15];
    char       eventTypeName[33];
    char       auditDefTagStr[15];
    char       userId[33];
    char       groupTagStr[15];
    char       groupName[257];
    char       secObjTagStr[15];
    char       secObjName[TCCALENDAR_name_size_c + 1];
    char       secObjId[ITEM_id_size_c + 1];
    char       secObjRevName[33];
    int        secObjSeqNumber;
    char       secObjTypeName[33];
    char*      dateStr;
    int        errorCode;
    char       errorMsg[257];
    int        storageType;
    int        propCount;
    char**     propNames;
    char**     propValues;
    char**     propOldValues;
} AUDIT_record_t;

#ifdef __cplusplus
        extern "C"{
#endif


/**
    This function is used to create an audit log for an event.
*/
extern SA_API int AUDIT_log_event (
    tag_t         targetObject,     /**< (I) */
    tag_t         objectType,       /**< (I) */
    tag_t         eventType,        /**< (I) */
    const char*   objectId,         /**< (I) */
    const char*   objectName,       /**< (I) */
    const char*   rev               /**< (I) */
    );
    
/**
    This function is used to create an audit log for an events type including __Email_Send, __Email_Not_Send.
*/
extern SA_API int AUDIT_log_event2 (
    tag_t         targetObject,     /**< (I) */
    tag_t         objectType,       /**< (I) */
    tag_t         eventType,        /**< (I) */
    tag_t         subEventType,     /**< (I) - optional, this is only used for auditing notification email history.
                                            In that case, eventType will be __Email_Send or __Email_Not_send, and subEventType
                                            field stores the subscribed event name which triggers the notification email send event. */
    const char*   objectId,         /**< (I) */
    const char*   objectName,       /**< (I) */
    const char*   rev               /**< (I) */
    );

/**
    This function is used to create an audit log for an events type including __Email_Send, __Email_Not_Send.
    This supports specifying secondary object, optional parameters to be recorded, along with any error code
    and error message. All these fields are optional.
*/
extern SA_API int AUDIT_log_event3 (
    tag_t         targetObject,     /**< (I) */
    tag_t         objectType,       /**< (I) */
    tag_t         eventType,        /**< (I) */
    tag_t         subEventType,     /**< (I) - optional, this is only used for auditing notification email history.
                                            In that case, eventType will be __Email_Send or __Email_Not_send, and subEventType
                                            field stores the subscribed event name which triggers the notification email send event. */
    const char*   objectId,         /**< (I) */
    const char*   objectName,       /**< (I) */
    const char*   rev,              /**< (I) */
    int           objectSeq,        /**< (I) */
    tag_t         secondaryObject,  /**< (I) - optional. Secondary object involved with the event */
    int           paramCount,       /**< (I) - optional. Count of optional parameters to be recorded */
    const char**  paramNames,       /**< (I) - optional. Optional parameters to be recorded in audit log */
    const char**  paramValues,      /**< (I) - optional. Optional parameter values to be recorded in audit log */
    int           errorCode,        /**< (I) - optional. Error code in case of a failure event */
    const char*   errorMsg          /**< (I) - optional. Error message in case of a failure event */
    );

extern SA_API int AUDIT_log_event4 (
    tag_t         targetObject,                /**< (I) */
    tag_t         objectType,                /**< (I) */
    tag_t         eventType,                /**< (I) */
    tag_t         subEventType,                /**< (I) - optional, this is only used for auditing notification email history.
                                            In that case, eventType will be __Email_Send or __Email_Not_send, and subEventType
                                            field stores the subscribed event name which triggers the notification email send event. */
    const char*   objectId,                    /**< (I) */
    const char*   objectName,                /**< (I) */
    const char*   rev,                        /**< (I) */
    int           objectSeq,                /**< (I) */
    int           secondaryObjectTagCount,    /**< (I) */
    tag_t*        secondaryObjectTags,        /**< (I) */
    const char**  secondaryObjectQualifiers,/**< (I) */
    int           paramCount,                /**< (I) - optional. Count of optional parameters to be recorded */
    const char**  paramNames,                /**< (I) - optional. Optional parameters to be recorded in audit log */
    const char**  paramValues,                /**< (I) - optional. Optional parameter values to be recorded in audit log */
    int           errorCode,                /**< (I) - optional. Error code in case of a failure event */
    const char*   errorMsg                    /**< (I) - optional. Error message in case of a failure event */
    );


/**
    This function is used to find audit logs with a specified search conditions.
*/
extern SA_API int AUDIT_get_records (
    AUDIT_log_query_t       logQuery,           /**< (I) The search conditions such as user,
                                                    object name/id, event type, and date. */
    int                     nConditions,        /**< (I) The number of search conditions for user defined properties */
    char**                  conditionValues,    /**< (I) nConditions The search conditions for user defined properties */
    int*                    resColCount,        /**< (O) The number of result columns */
    char***                 resColNames,        /**< (OF) resColCount The list of column names */
    QRY_user_query_row_t**  resRows             /**< (OF) */
    );

/** 
      Finds audit logs with the specified search conditions. 
      @returns 
      <ul> 
      <li>#ITK_ok on success.
      <li>#AUDITMGR_NO_TABLE if the AUDITLOG table does not exist.
      <li>Possibly other errors.
      </ul> 
*/
extern SA_API int AUDIT_get_records_with_specified_col (
    AUDIT_log_query_t       log_query,          /**< (I) The search conditions such as user,
                                                    object name/id, event type, and date. */
    int                     condition_count,    /**< (I) The number of search conditions for user defined properties */
    char**                  condition_values,   /**< (I) The search conditions for user defined properties */
    int                     n_columns,          /**< (I) The number of the columns(stored in the col_names) */
    char**                  col_names,          /**< (I) The names of the columns for the result (stored in the rows) */
    QRY_user_query_row_t**  rows                /**< (OF) n_columns The resulting rows. <br/>The memory will need to be relinquished using the #USER_query_free_rows ITK. */
    );

/** 
      Finds audit logs with the specified search conditions. 
      @returns 
      <ul> 
      <li>#ITK_ok on success.
      <li>#AUDITMGR_NO_TABLE if the AUDITLOG table does not exist.
      <li>Possibly other errors.
      </ul> 
*/
extern SA_API int AUDIT_get_records_with_specified_col2 (
    AUDIT_log_query_t       log_query,               /**< (I) The search conditions such as user,
                                                        object name/id, event type, and date. */
    int                     condition_count,        /**< (I) The number of search conditions for user defined properties */
    char**                  condition_prop_names,   /**< (I) The search condition property names for user defined properties */
    char**                  condition_values,       /**< (I) The search conditions for user defined properties */
    int                     n_columns,              /**< (I) The number of the columns(stored in the col_names) */
    char**                  col_names,              /**< (I) The names of the columns for the result (stored in the rows) */
    QRY_user_query_row_t**  rows                    /**< (OF) n_columns The resulting rows. <br/>The memory will need to be relinquished using the #USER_query_free_rows ITK. */
    );

extern SA_API int AUDIT_delete_specified_records (
    int           logCount,     /**< (I) */
    char**        logUidis      /**< (I) logCount */
    );

/**
    This function is used to delete audit records.
*/
extern SA_API int AUDIT_delete_records (
    AUDIT_log_query_t   logQuery    /**< (I) The criteria of audit records to be deleted */
    );

/**
    This function is used to create an audit log for an existing audit log data.
    This function should be used mainly for migrating the older audit log into the new format.
*/
extern SA_API int AUDIT_insert_record (
    AUDIT_record_t  logInfo     /**< (I) The audit log record to be stored in the audit log storage */
    );

extern SA_API void  AUDIT_initialize_log_query (
    AUDIT_log_query_t*  logQuery    /**< (O) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>

#endif
