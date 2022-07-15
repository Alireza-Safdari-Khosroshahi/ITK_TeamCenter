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

#ifndef AUDITMGR_H
#define AUDITMGR_H

#include <qry/qry.h>
#include <tc/tc_startup.h>
#include <stdarg.h>
#include <ss/ss_const.h>
#include <sa/libsa_exports.h>

/**
    @defgroup AUDITMGR Audit Manager
    @ingroup SA
    @{
*/

#define AUDITDEF_class_name_c           "AuditDefinition"

#ifdef __cplusplus
    extern "C"{
#endif

/**
    This function initializes the auditmanager module
*/
extern SA_API int AUDITMGR__init_classes();

/**
    This function will be used for defining an object type and event type to be audited.
*/
extern SA_API int AUDITMGR_create_audit_definition (
    tag_t         objectType,               /**< (I) The tag of object type to be audited */
    tag_t         eventType,                /**< (I) The tag of event type to be audited */
    int           propCount,                /**< (I) The number of properties that a user wants to be audited.
                                                Beside the default info such as object name/id, user, event, and time,
                                                these are additional properties defined by the user. */
    char**        propertiesNames,          /**< (I) The list of properties to be audited */
    int           maxDaysKept,              /**< (I) The maximum number of days that audit logs to be kept on line.
                                                Once the defined time is expired, the audit log will be
                                                archived and purged from the storage. */
    tag_t         archiveMedia,             /**< (I) The tag of storage media to be used for archiving older audit logs.
                                                If none is defined, 
                                                the older audit logs will be purged from audit log storage. */
    tag_t         userDefinedLogHandler,    /**< (I) The tag of a handler for creating additional log data */
    tag_t*        auditDefTag               /**< (O) The tag of the created audit definition */
    );

/**
    This function is used to locate an audit definition.
*/
extern SA_API int AUDITMGR_find_audit_definition (
    tag_t         objectType,       /**< (I) The tag of object type defined in the audit definition */
    tag_t         eventType,        /**< (I) The tag of event type defined in the audit definition */
    int*          nFound,           /**< (O) The number of audit definitions found */
    tag_t**       auditDefTags      /**< (OF) nFound The tags of the found audit definitions */
    );

/**
    This function is used to get the storage type of an audit definition object.
*/
extern SA_API int AUDITMGR_get_storage_type (
    tag_t         auditDefTag,      /**< (I) Tag of the audit definition object */
    int*          storageType       /**< (O) Integer indicating the storage type. <br>
                                        0 or 1 means the audit records are stored in the database. <br>
                                        2 means the audit records are written to the external files. <br>
                                        0 is the default storage type value. <br>
                                        0 will be returned for all audit definition objects that were created prior to V8.0. */
    );

/**
    This function is used to set the storage type of an audit definition object.

    <b>Restrictions:</b>

    AUDITMGR_set_storage_type() should be called after creating an audit definition object by
    calling AUDITMGR_create_audit_definition().
    If you don’t call AUDITMGR_set_storage_type(),
    the default storage type 0 is assumed (i.e., stored in the database).
*/
extern SA_API int AUDITMGR_set_storage_type (
    tag_t         auditDefTag,      /**< (I) Tag of the audit definition object */
    int           storageType       /**< (I) Integer indicating the storage type. <br>
                                        1 means the audit records are stored in the database. <br>
                                        2 means the audit records are written to the external files. */
    );

extern SA_API int AUDITMGR_get_object_type (
    tag_t         auditDefTag,      /**< (I) */
    tag_t*        objectType        /**< (O) */
    );

extern SA_API int AUDITMGR_get_event_type (
    tag_t         auditDefTag,      /**< (I) */
    tag_t*        eventType         /**< (O) */
    );

extern SA_API int AUDITMGR_get_audit_properties (
    tag_t         auditDefTag,      /**< (I) */
    int*          propCount,        /**< (O) */
    char***       propertiesNames   /**< (OF) propCount */
    );

extern SA_API int AUDITMGR_get_max_days_kept (
    tag_t         auditDefTag,      /**< (I) */
    int*          daysCount         /**< (O) */
    );

extern SA_API int AUDITMGR_get_archive_media (
    tag_t         auditDefTag,      /**< (I) */
    tag_t*        archiveMedia      /**< (O) */
    );

extern SA_API int AUDITMGR_get_log_handler (
    tag_t         auditDefTag,      /**< (I) */
    tag_t*        logHandler        /**< (O) */
    );

extern SA_API int AUDITMGR_remove_audit_properties (
    tag_t         auditDefTag,      /**< (I) */
    int           propCount,        /**< (I) */
    char**        propsNames        /**< (I) */
    );

extern SA_API int AUDITMGR_add_audit_properties ( 
    tag_t         auditDefTag,      /**< (I) */
    int           propCount,        /**< (I) */
    char**        propertiesNames   /**< (I) */
    );

extern SA_API int AUDITMGR_set_max_days_kept (
    tag_t         auditDefTag,      /**< (I) */
    int           daysCount         /**< (I) */
    );

extern SA_API int AUDITMGR_set_archive_media (
    tag_t         auditDefTag,      /**< (I) */
    tag_t         archiveMedia      /**< (I) */
    );

extern SA_API int AUDITMGR_set_log_handler (
    tag_t         auditDefTag,      /**< (I) */
    tag_t         logHandler        /**< (I) */
    );

extern SA_API int AUDITMGR_get_auditable_types (
    int*          count,    /**< (O) */
    tag_t**       tags      /**< (OF) count */
    );

extern SA_API int AUDITMGR_get_auditable_type_names (
    int*          count,         /**< (O) */
    char***        typeNames      /**< (OF) count */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>

#endif
