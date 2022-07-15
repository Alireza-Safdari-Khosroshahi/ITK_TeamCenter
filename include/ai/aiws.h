/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    ITK API for Application Interface Web Service

This file contains ITK functions related to Application Interface module.
*/

/*  */

#ifndef AIWS_H
#define AIWS_H

#include <unidefs.h>
#include <pie/pie.h>
#include <ai/appinterface.h>

#include <ai/libai_exports.h>

#ifdef __cplusplus
 extern "C"{
#endif

/**
    @defgroup AIWS Application Interface Web Service
    @ingroup PIE
    @{
*/

extern AI_API int AIWS_GetProjects(
    char*          xmlString,   /**< (I) */
    char**         xmlResStr    /**< (OF) */
    );

extern AI_API int AIWS_SetProjectInfo(
    char*          xmlString,   /**< (I) */
    char**         result       /**< (OF) */
    );

extern AI_API int AIWS_GetAllRequests(
    char*          xmlString,       /**< (I) */
    char**         xmlOutString     /**< (OF) */
    );

extern AI_API int AIWS_SetExchangeMessage(
    char*          xmlString,   /**< (I) */
    char**         result       /**< (OF) */
    );

extern AI_API int AIWS_StartExchange(
    char*          xmlString,   /**< (I) */
    char**         result       /**< (OF) */
    );

extern AI_API int AIWS_EndExchange(
    char*          xmlString,   /**< (I) */
    char**         result       /**< (OF) */
    );

extern AI_API int AIWS_CreatePublishRequest(
    char*          xmlString,       /**< (I) */
    char**         xmlResString     /**< (OF) */
    );

extern AI_API int AIWS_GetRequest(
    char*          xmlString,       /**< (I) */
    char**         xmlResString     /**< (OF) */
    );

extern AI_API int AIWS_GetNextApprovedRequest(
    char*          xmlString,       /**< (I) */
    char**         xmlResString     /**< (OF) */
    );

extern AI_API int AIWS_GetRequestStatus(
    char*          xmlString,       /**< (I) */
    char**         xmlResString     /**< (OF) */
    );

extern AI_API int AIWS_GetStructure(
    char*          xmlString,       /**< (I) */
    char**         xmlResString     /**< (OF) */
    );

extern AI_API int AIWS_GetStructureReadTicket(
    char*          xmlString,       /**< (I) */
    char**         xmlResString     /**< (OF) */
    );

extern AI_API int AIWS_PutStructure(
    char*          xmlString,   /**< (I) */
    char**         resString    /**< (OF) */
    );

extern AI_API int AIWS_GetStructureWriteTicket(
    char*          xmlString,   /**< (I) */
    char**         resString    /**< (OF) */
    );

extern AI_API int AIWS_GetAssociatedFiles(
    char*          xmlString,       /**< (I) */
    char**         xmlResString     /**< (OF) */
    );

extern AI_API int AIWS_GetReadFileTickets(
    char*          xmlString,       /**< (I) */
    char**         xmlResString     /**< (OF) */
    );

extern AI_API int AIWS_PutAssociatedFiles(
    char*          xmlString,   /**< (I) */
    char**         resStr       /**< (OF) */
    );

extern AI_API int AIWS_GetWriteFileTickets(
    char*          xmlString,   /**< (I) */
    char**         resStr       /**< (OF) */
    );

extern AI_API int AIWS_CommitFiles(
    char*          xmlString,   /**< (I) */
    char**         resStr       /**< (OF) */
    );

extern AI_API int AIWS_ProcessPublishRequest(
    char*          xmlString,   /**< (I) */
    char**         result       /**< (OF) */
    );

extern AI_API int AIWS_DeleteAIObject(
    char*          xmlString,   /**< (I) */
    char**         result       /**< (OF) */
    );

extern AI_API int AIWS_Invoke(
    char* xmlString,    /**< (I) */
    char** result       /**< (OF) */
    );

     extern AI_API int AIWS_CheckOut(const char* xmlString /* <I> */,char** result/* <OF> */);
     extern AI_API int AIWS_CheckIn(const char* xmlString /* <I> */,char** result/* <OF> */);
     extern AI_API int AIWS_GetNamedQueries(const char* xmlString /* <I> */,char** result/* <OF> */);
     extern AI_API int AIWS_GetQueryDescription(const char* xmlString /* <I> */,char** resString/* <OF> */);
     extern AI_API int AIWS_ExecuteQuery(const char* xmlString /* <I> */,char** resString/* <OF> */);
     extern AI_API int AIWS_GenerateSyncRequest(const char* xmlString /* <I> */,char** resString/* <OF> */);
     extern AI_API int AIWS_GetReservationInfo(const char* xmlString /* <I> */,char** resString/* <OF> */);
     extern AI_API int AIWS_CancelCheckOut(const char* xmlString /* <I> */,char** resString/* <OF> */);
     extern AI_API int AIWS_CreateProject(const char* xmlString /* <I> */,char** resString/* <OF> */);
     extern AI_API int AIWS_GetAppRefForItemId(const char* xmlString /* <I> */,char** resString/* <OF> */);
     extern AI_API int AIWS_GetObjectsForProjectType(const char* xmlString /* <I> */,char** resString/* <OF> */);
     extern AI_API int AIWS_GetPLMVersion(const char* xmlString /* <I> */,char** resString/* <OF> */);
     
/**
    @name API for TC Eng \<-\> TC Req.

    WOLF SOAP protocol itk functions.
    @{
*/

extern AI_API int AIWS_objectReferenced(
    char*          xmlString,   /**< (I) */
    char**         result       /**< (OF) */
    );

/**
    Creates the Exported Proxy Link record at the owning site for a proxy created at remote site.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AIWS_proxy_failed_exp_obj_record if Exported Proxy Link record could not be created for the given object at current site.
    </ul>
*/
extern AI_API int AIWS_mark_object_as_referenced(
    const char*    object_details,   /**< (I) String containing token value pairs for APPGUID,ORIGINALUID,LINKTYPE. 
                                              <br>E.g. APPGUID=ZZZZZZZZZZZZZ;ORIGINALUID=YYYYYYYYYYYYYY;LINKTYPE=ABC;
                                              <br>If the value of any of the tokens contains the separator character ';', then parsing will fail.
                                              <br>All tokens need to be specified.*/
    char**         error             /**< (OF) Contains error message, if any error encountered. */
    );

extern AI_API int AIWS_objectDeleted(
    char*          xmlString,   /**< (I) */
    char**         result       /**< (OF) */
    );

/**
    Marks any proxies for the object with a "stale" status, once the the owning site master object has been deleted.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AIWS_proxy_not_in_db if the Proxy Link record is not found for the given ojbect at current site or it cannot be marked as deleted.
    </ul>
*/
extern AI_API int AIWS_mark_object_as_deleted(
    const char*    object_details,   /**< (I) String containing token value pairs for APPGUID,ORIGINALUID. 
                                              <br>E.g. APPGUID=ZZZZZZZZZZZZZ;ORIGINALUID=YYYYYYYYYYYYYY;
                                              <br>If the value of any of the tokens contains the separator character ';', then parsing will fail.
                                              <br>All tokens need to be specified.*/
    char**         error             /**< (OF) Contains error message, if any error encountered. */
    );

extern AI_API int AIWS_objectNolongerReferenced(
    char*          xmlString,   /**< (I) */
    char**         result       /**< (OF) */
    );

/**
    Notifies master site to make sure that the exported proxy link is removed, once the proxied object is no longer referenced.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AIWS_proxy_exp_obj_not_in_db, if the Exported Proxy Link record is not found for the given ojbect at current site or it cannot be deleted.
    </ul>
*/
extern AI_API int AIWS_mark_object_as_no_longer_referenced(
    const char*    object_details,   /**< (I) String containing token value pairs for APPGUID,ORIGINALUID. 
                                              <br>E.g. ORIGINALUID=YYYYYYYYYYYYYY;APPGUID=ZZZZZZZZZZZZZ;
                                              <br>If the value of any of the tokens contains the separator character ';', then parsing will fail.
                                              <br>All tokens need to be specified.*/
    char**         error             /**< (OF) Contains error message, if any error encountered. */
    );

extern AI_API int AIWS_getRemoteProperties(
    char*          xmlString,   /**< (I) */
    char**         result       /**< (OF) */
    );

/**
    Sends the property values at master site for updating proxies, either by looking up at the request or from the exported proxy link.
    Also updates exported proxy link to indicate synchronization is complete.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AIWS_proxy_exp_obj_not_in_db, if the Exported Proxy Link record is not found for the given ojbect at current site.
    <li>#AIWS_proxy_no_keys_values, if there are any errors while getting the keys from Exported Proxy Link record of the object.
    <li>#AIWS_proxy_set_last_sync_date, if there are any errors while updating Exported Proxy Link record with the synchronization date.
    </ul>
*/
extern AI_API int AIWS_get_remote_properties_and_update_proxies(
    const char*    object_details,   /**< (I) String containing token value pairs for APPGUID,ORIGINALUID. 
                                              <br>E.g. APPGUID=ZZZZZZZZZZZZZ;ORIGINALUID=YYYYYYYYYYYYYY;
                                              <br>If the value of any of the tokens contains the separator character ';', then parsing will fail.
                                              <br>All tokens need to be specified.*/
    char**         properties        /**< (OF) Properties in form of key-value pairs and/or error messages, if any. Properties within this string start with the word 'PropKeys' and error messages start with word 'error'. If error is encountered before properties in the form of key-value paires are fetched, then the string will contain only errors. If properties in the form of key-value paires are fetched, then the string will start with the word 'PropKeys'. Then properties would be listed. Then error messages (starting with string 'error') will be displayed. */
    );

extern AI_API int AIWS_pushProperties(
    char*          xmlString,   /**< (I) */
    char**         result       /**< (OF) */
    );

/**
    Updates the property values at proxy site sent by the master site.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AIWS_proxy_not_in_db, if the proxy object is not found at current site.
    <li>#AIWS_proxy_update_properties, if there are any errors while updating the properties on the proxy object.
    </ul>
*/
extern AI_API int AIWS_update_properties_at_proxy_site(
    const char*    object_and_properties,   /**< (I) String containing token value pairs for APPGUID,ORIGINALUID,PROPKEYS,PROPVALUES. 
                                                     <br>E.g. APPGUID=ZZZZZZZZZZZZZ;ORIGINALUID=YYYYYYYYYYYYYY;PROPKEYS=ABC#XYZ#PQR;PROPVALUES=ABC#XYZ#PQR;
                                                     <br>If the value of any of the tokens contains the separator character ';', then parsing will fail.
                                                     <br>All tokens need to be specified.*/
    char**         error                    /**< (OF) Contains error message, if any error encountered. */
    );

extern AI_API int AIWS_getRemoteTraceReport(
    char*          xmlString,   /**< (I) */
    char**         result       /**< (OF) */
    );

/**
    Retrieves the trace report at the proxy site. Trace report lists all the items or item revisions
    that reference to this proxy link.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AIWS_proxy_not_in_db, if the proxy object is not found at current site.
    <li>#AIWS_proxy_get_trace_report, if there are any errors while getting the trace report.
    </ul>
*/
extern AI_API int AIWS_get_remote_trace_report(
    const char*    object_details,       /**< (I) String containing token value pairs for APPGUID,ORIGINALUID. 
                                                  <br>E.g. APPGUID=ZZZZZZZZZZZZZ;ORIGINALUID=YYYYYYYYYYYYYY;
                                                  <br>If the value of any of the tokens contains the separator character ';', then parsing will fail.
                                                  <br>All tokens need to be specified.*/
    char**         trace_report          /**< (OF) Trace report and errors encountered (if any). Trace report part comes first and starts with string 'html'. Errors are put in the end and they strt with string 'error'. */
    );

extern AI_API int AIWS_pushPropertiesToMaster(
    char*     xmlString,  /**< (I) */
    char**     result      /**< (OF) */
    );
/**
    Updates the property values at master site sent by the remote site.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AIWS_proxy_set_properties_to_master, if there are any errors setting properties on master object.
    </ul>
*/
extern AI_API int AIWS_update_properties_at_master_site(
    const char*    object_and_properties,   /**< (I) String containing token value pairs for APPGUID,MASTERUID,ARRAYSIZE,NAME,KEY,VALUE.  
                                                     <br>E.g. APPGUID=ZZZZZZZZZZZZZ;MASTERUID=YYYYYYYYYYYYYY;ARRAYSIZE=111;NAME=XYZ;KEY=PQR;VALUE=ABC;
                                                     <br>If the value of any of the tokens contains the separator character ';', then parsing will fail.
                                                     <br>All tokens need to be specified.*/
    char**         error                    /**< (OF) Contains error message, if any error encountered. */
    );

extern AI_API int AIWS_wkfCreateProcess(
    char*     xmlString, /**< (I) */
    char**     result     /**< (OF) */
    );

/**
    Performs following tasks:
          1. Creating a process
          2. Creating a proxy to the TcPrj obj that triggered the process creation.
          3. Notifying TcPrj that their task is referenced (objectReferenced).
          4. Creating a relation between the process' task and the new proxy.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AIWS_proxy_failed_creating_process, if there are any errors creating the workflow process from Teamcenter Project.
    <li>#AIWS_proxy_exoprt_new_process, if there are any errors creating exported proxy link for this workflow process.
    <li>#AIWS_proxy_no_process_template, if there is no process template found for given name.
    </ul>
*/
extern AI_API int AIWS_wkf_create_process(
    const char*    object_and_process_details,   /**< (I) String containing token value pairs for APPGUID,PRJTASKUID,TASKNAME,TEMPLATENAME,PROCESSNAME,PROCESSOWNER,DEADLINE,CONTAINER and RELATIONTYPE.  
           <br>E.g.APPGUID=ZZZZZZZZZZZZZ;PRJTASKUID=YYYYYYYYYYYYYY;TASKNAME=ABC;TEMPLATENAME=XYZ;PROCESSNAME=PQR;PROCESSOWNER=LMN;DEADLINE=BCD;CONTAINER=CDE;RELATIONTYPE=DEF;
           <br>If the value of any of the tokens contains the separator character ';', then parsing will fail.
           <br>All tokens need to be specified.*/
    char**         process_uid                   /**< (OF) Process UID of created process and error messages (if any). UID is displayed before the error messages. String 'TheUid' preceds the UID and string 'error' precedes the error messages. */
    );

extern AI_API int AIWS_wkfGetTemplates(
    char*     xmlString, /**< (I) */
    char**     result     /**< (OF) */
    );

/**
    Retrieves all process templates at current site.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AIWS_proxy_no_templates, if there are any errors getting all process templates.
    </ul>
*/
extern AI_API int AIWS_wkf_get_templates(
    const char*    application_guid,   /**< (I) String containing token value pair for APPGUID. 
                                                <br>E.g. APPGUID=ZZZZZZZZZZZZZ;
                                                <br>If the value of any of the tokens contains the separator character ';', then parsing will fail.
                                                <br>All tokens need to be specified.*/
    char**         templates           /**< (OF) Template names and error messages (if any). Template names are displayed before the error messages. String 'TemplateNames' preceds the template names and string 'error' precedes the error messages. */
    );

extern AI_API int AIWS_getRemoteInbox(
    char*     xmlString, /**< (I) */
    char**     result     /**< (OF) */
    );

/**
    Retrieves the ID of the User Inbox and number of tasks in the user inbox at current site.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AIWS_proxy_no_user_in_db, if there are any errors getting either the inbox uid or the number of tasks in the inbox.
    </ul>
*/
extern AI_API int AIWS_get_remote_inbox_details(
    const char*    application_guid_and_user_name,   /**< (I) String containing token value pairs for APPGUID,USERNAME. 
                                                              <br>E.g. APPGUID=ZZZZZZZZZZZZZ;USERNAME=ABC;
                                                              <br>If the value of any of the tokens contains the separator character ';', then parsing will fail.
                                                              <br>All tokens need to be specified.*/
    char**         remote_inbox_details              /**< (OF) UserInbox uid & number of tasks in the user inbox at current site and error messages (if any). Inbox details are displayed before the error messages. String 'RemoteInbox' preceds inbox details and string 'error' precedes the error messages. */
    );

extern AI_API int AIWS_tcGetWSOClasses(
    char*     xmlString, /**< (I) */
    char**     result     /**< (OF) */
    );

/**
    Retrieves list of classes in the preference "TC_external_wkf_class_list" at current site.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AIWS_proxy_get_class_names, if there are any errors getting the names for all proxiable Workspace Object Classes.
    </ul>
*/
extern AI_API int AIWS_tc_get_wso_classes(
    const char*    dummy_string,        /**< (I) This is a placeholder empty string, which is needed to comply with the protocol that the parameters for the AIWS ITKs are of same type. */
    char**         class_names          /**< (OF) Class names and error messages (if any). Class names are displayed before the error messages. String 'ClassNames' preceds class names and string 'error' precedes the error messages.*/
    );

extern AI_API int AIWS_tcGetWSOTypes(
    char*     xmlString, /**< (I) */
    char**     result     /**< (OF) */
    );

/**
    Retrieves list of all the types for the given class at current site.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AIWS_proxy_get_class_relation_types, if there are any errors getting the relation types.
    </ul>
*/
extern AI_API int AIWS_tc_get_wso_types(
    const char*    class_name,         /**< (I) String containing token value pair for CLASSNAME.  
                                                <br>E.g. CLASSNAME=ABC;
                                                <br>If the value of any of the tokens contains the separator character ';', then parsing will fail.
                                                <br>All tokens need to be specified.*/
    char**         type_names          /**< (OF) Type names and error messages (if any). Type names are displayed before the error messages. String 'TypeNames' preceds type names and string 'error' precedes the error messages. */
    );

extern AI_API int AIWS_tcGetWSOClassRelationTypes(
    char*     xmlString, /**< (I) */
    char**     result     /**< (OF) */
    );

/**
    Retrieves list of all the default relation types for the given class at current site.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AIWS_proxy_get_latest_revision, if there are any errors getting the latest revision.
    </ul>
*/
extern AI_API int AIWS_tc_get_wso_class_relation_types(
    const char*    class_name,             /**< (I) String containing token value pair for CLASSNAME. 
                                                    <br>E.g. CLASSNAME=ABC;
                                                    <br>If the value of any of the tokens contains the separator character ';', then parsing will fail.
                                                    <br>All tokens need to be specified.*/
    char**         relation_names          /**< (OF) Relation names and error messages (if any). Relation names are displayed before the error messages. String 'RelationNames' preceds relation names and string 'error' precedes the error messages. */
    );

extern AI_API int AIWS_tcGetLatestRev(
    char*     xmlString, /**< (I) */
    char**     result     /**< (OF) */
    );

/**
    Retrieves uid of the latest revision for the given item at current site.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AIWS_proxy_get_latest_revision, if there are any errors getting the latest revision.
    </ul>
*/
extern AI_API int AIWS_tc_get_uid_of_latest_revision(
    const char*    object_details,          /**< (I) String containing token value pair for WSOINSTANCE. 
                                                     <br>E.g. WSOINSTANCE=ZZZZZZZZZZZZZ;
                                                     <br>If the value of any of the tokens contains the separator character ';', then parsing will fail.
                                                     <br>All tokens need to be specified.*/
    char**         latest_revision          /**< (OF) UID of latest revision and error messages (if any). UID is displayed before the error messages. String 'LatestRevSec' preceds UID and string 'error' precedes the error messages.*/
    );

extern AI_API int AIWS_tcReviseItem(
    char*     xmlString, /**< (I) */
    char**     result     /**< (OF) */
    );

/**
    Revises the given item and retrieves uid of the latest revision.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AIWS_proxy_revise_item, if there are any errors revising the latest revision.
    </ul>
*/
extern AI_API int AIWS_tc_revise_item(
    const char*    object_details,           /**< (I) String containing token value pair for WSOINSTANCE. 
                                                      <br>E.g. WSOINSTANCE=ZZZZZZZZZZZZZ;
                                                      <br>If the value of any of the tokens contains the separator character ';', then parsing will fail.
                                                      <br>All tokens need to be specified.*/
    char**         latest_revision           /**< (OF) UID of the latest revision of the object and error messages (if any). UID is displayed before the error messages. String 'RevisedItemSec' preceds UID and string 'error' precedes the error messages.*/
    );

extern AI_API int AIWS_tcCreateWSOInstance(
    char*     xmlString, /**< (I) */
    char**     result     /**< (OF) */
    );

/**
    Creates the Workspace Object at current site.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AIWS_proxy_create_wso_instance, if there are any errors while creating the Workspace Object.
    <li>#AIWS_proxy_get_proxy_uid, if there are any errors while converting tag to uid.
    </ul>
*/
extern AI_API int AIWS_tc_create_wso_instance(
    const char*    object_details,               /**< (I) String containing token value pairs for WSOTYPE,NAME,OWNER,DESCRIPTION,CONTAINER,RELATIONTYPE. 
                                                          <br>E.g. WSOTYPE=ABC;NAME=ABC;OWNER=ABC;DESCRIPTION=ABC;CONTAINER=ABC;RELATIONTYPE=ABC;
                                                          <br>If the value of any of the tokens contains the separator character ';', then parsing will fail.
                                                          <br>All tokens need to be specified.*/
    char**         workspace_object_uid          /**< (OF) UID of the newly created workspace object and error messages (if any). UID is displayed before the error messages. String 'WSOInstanceSec' preceds UID and string 'error' precedes the error messages. */
    );

extern AI_API int AIWS_destroyProcessLink(
    char*     xmlString, /**< (I) */
    char**     result     /**< (OF) */
    );

/**
    Deletes the proxy attachment for the given workflow task at current site.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#AIWS_proxy_destroy_process_link, if there are any errors deleting the attachment.
    </ul>
*/
extern AI_API int AIWS_destroy_process_link(
    const char*    workflow_task_details,   /**< (I) String containing token value pairs for APPGUID,MASTERUID. 
                                                     <br>E.g. APPGUID=ZZZZZZZZZZZZZ;MASTERUID=YYYYYYYYYYYYYY;
                                                     <br>If the value of any of the tokens contains the separator character ';', then parsing will fail.
                                                     <br>All tokens need to be specified.*/
    char**         error                    /**< (OF) Contains error message, if any error encountered. */
    );

extern AI_API int AIWS_register_auth_fn();

extern AI_API int AIWS_decrypt(
    const char*    user,
    const char*    mangledpw
    );

/** @} */

/** @} */

#ifdef __cplusplus
}
#endif

#include <ai/libai_undef.h>

#endif
