/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/** @if DOX_IGNORE
    The naming convention is to prefix the eventtype name with a "__" to
    indicate that the eventtype is an standard (internal) Tc event type

    When a new eventtype is added in this file, it needs to be added to the list
    of standard eventtypes in /vobs/src/tc/main/install_event_types_itk_main.cxx
    so that the newly added eventtype gets created during the install.

    TC_WORKFLOW_SKIP_EVENT and TC_WORKFLOW_UNDO_EVENT are deprecated in V9.1,
    and will be obsolete in the future releases (perhaps starting from V11.0)
    Instead, the user should use TC_WORKFLOW_PROMOTE_EVENT in place of
    TC_WORKFLOW_SKIP_EVENT, use TC_WORKFLOW_DEMOTE_EVENT in place of
    TC_WORKFLOW_UNDO_EVENT.
@endif */

/*  */

#ifndef STANDARDTCEVENTTYPES_H
#define STANDARDTCEVENTTYPES_H

#include <sub_mgr/libsub_mgr_exports.h>

/**
    @defgroup STANDARD_TC_EVENT_TYPES Standard Event Types
    @ingroup SUBSCRIPTION
    @{
*/

#define TC_CREATE_EVENT                       "__Create"
#define TC_MODIFY_EVENT                       "__Modify"
#define TC_DELETE_EVENT                       "__Delete"
#define TC_CHECK_IN_EVENT                     "__Check_In"
#define TC_CHECK_OUT_EVENT                    "__Check_Out"
#define TC_CANCEL_CHECK_OUT_EVENT             "__Cancel_Check_Out"
#define TC_TRANSFER_CHECK_OUT_EVENT           "__Transfer_Check_Out"
#define TC_PROCESS_INITIATED_EVENT            "__Process_Initiated"
#define TC_WORKFLOW_ASSIGN_EVENT              "__Assign"
#define TC_WORKFLOW_START_EVENT               "__Start"
#define TC_WORKFLOW_END_EVENT                 "__End"
#define TC_WORKFLOW_COMPLETE_EVENT            "__Complete"
#define TC_WORKFLOW_SKIP_EVENT                "__Skip"
#define TC_WORKFLOW_SUSPEND_EVENT             "__Suspend"
#define TC_WORKFLOW_RESUME_EVENT              "__Resume"
#define TC_WORKFLOW_UNDO_EVENT                "__Undo"
#define TC_WORKFLOW_ABORT_EVENT               "__Abort"
#define TC_WORKFLOW_PERFORM_EVENT             "__Perform"
#define TC_WORKFLOW_APPROVE_EVENT             "__Approve"
#define TC_WORKFLOW_REJECT_EVENT              "__Reject"
#define TC_WORKFLOW_PROMOTE_EVENT             "__Promote"
#define TC_WORKFLOW_DEMOTE_EVENT              "__Demote"
#define TC_WORKFLOW_NOTIFY_EVENT              "__Notify"
#define TC_WORKFLOW_ASSIGN_APPROVER_EVENT     "__Assign_Approver"
#define TC_WORKFLOW_ADD_ATTACHMENT_EVENT      "__Add_Attachment"
#define TC_WORKFLOW_REMOVE_ATTACHMENT_EVENT   "__Remove_Attachment"
#define TC_WORKFLOW_STAND_IN_EVENT            "__Stand_In"
#define TC_WORKFLOW_APPLY_TEMPLATE_CHANGES_EVENT "__Update_Process"
#define TC_REPLICA_UPDATE_EVENT               "__Replica_Update"
#define TC_MODIFY_MASTER_COPY_EVENT           "__Modify_Master_Copy"
#define TC_INCLASS_EVENT                      "__Iman_inCLASS"
#define TC_OPEN_EVENT                         "__Open"
#define TC_SAVEAS_EVENT                       "__Save_As"
#define TC_IIR_REGISTER_FAIL_EVENT            "__Register_Failed"
#define TC_IIR_UNREGISTER_FAIL_EVENT          "__Unregister_Failed"
#define TC_IIR_PUBLISH_FAIL_EVENT             "__Publish_Failed"
#define TC_IIR_UNPUBLISH_FAIL_EVENT           "__Unpublish_Failed"
#define TC_ATTAINED_RELEASE_STATUS_EVENT      "__Attained_Release_Status"
#define TC_ATTACH_EVENT                       "__Attach"
#define TC_DETACH_EVENT                       "__Detach"
#define TC_PROXY_LINK_EVENT                   "__Proxy_Link"
#define TC_REMOTE_CHECK_IN_EVENT              "__Remote_Check_In"
#define TC_REMOTE_CHECK_OUT_EVENT             "__Remote_Check_Out"
#define TC_REMOTE_CANCEL_CHECK_OUT_EVENT      "__Remote_Cancel_Check_Out"
#define TC_REMOTE_TRANSFER_CHECK_OUT_EVENT    "__Remote_Transfer_Check_Out"
#define TC_NEW_IR_EVENT                       "__Item_Rev_Create"
#define TC_SITE_CHECK_IN_EVENT                "__Site_Check_In"
#define TC_SITE_CHECK_OUT_EVENT               "__Site_Check_Out"
#define TC_SITE_CANCEL_CHECK_OUT_EVENT        "__Site_Cancel_Check_Out"
#define TC_ASYNC_REQUEST_SUCCEEDED_EVENT      "__Async_Request_Succeeded"
#define TC_ASYNC_REQUEST_FAILED_EVENT         "__Async_Request_Failed"
#define TC_Email_Send_EVENT                   "__Email_Send"
#define TC_Email_Not_Send_EVENT               "__Email_Not_Send"
#define TC_WORKFLOW_FAIL_EVENT                "__Fail"
#define TC_WRITE_FILE_EVENT                   "__Write_File"
#define TC_READ_FILE_EVENT                    "__Read_File"
#define TC_REVISE_EVENT                       "__Revision_Create"

/* Security Audit Logs */
#define TC_ASSIGN_DATA_TO_PROJECT             "Fnd0Assign_Data_To_Project"
#define TC_REMOVE_DATA_FROM_PROJECT           "Fnd0Remove_Data_From_Project"
#define TC_ASSIGN_USER_TO_PROJECT             "Fnd0Assign_User_To_Project"
#define TC_REMOVE_USER_FROM_PROJECT           "Fnd0Remove_User_From_Project"
#define TC_SET_TEAM_ADMIN                     "Fnd0Set_Team_Admin"
#define TC_UNSET_TEAM_ADMIN                   "Fnd0Unset_Team_Admin"
#define TC_SET_PROJECT_ADMIN                  "Fnd0Set_Project_Admin"
#define TC_UNSET_PROJECT_ADMIN                "Fnd0Unset_Project_Admin"
#define TC_SET_PRIVLEGED_USER                 "Fnd0Set_Privileged_User"
#define TC_UNSET_PRIVLEGED_USER               "Fnd0Unset_Privileged_User"
#define TC_SET_DEFAULT_PROJECT                "Fnd0Set_Default_Project"
#define TC_ASSIGN_GROUP_TO_PROJECT            "Fnd0Assign_Group_To_Project"
#define TC_REMOVE_GROUP_FROM_PROJECT          "Fnd0Remove_Group_From_Project"
#define TC_SPONSORED_USER_LOGIN               "Fnd0Sponsored_Login"

/* Schedule Notifications */
#define TC_SCHEDULE_ADD_TASK_EVENT                               "__Add_Task"
#define TC_SCHEDULE_DELETE_TASK_EVENT                            "__Delete_Task"
#define TC_SCHEDULE_NEAR_DUE_EVENT                               "__Near_Due"
#define TC_SCHEDULE_OVERDUE_EVENT                                "__Overdue"
#define TC_SCHEDULE_START_DATE_CHANGE_EVENT                      "__Start_Date_Change"
#define TC_SCHEDULE_FINISH_DATE_CHANGE_EVENT                     "__Finish_Date_Change"
#define TC_SCHEDULE_STATUS_CHANGE_EVENT                          "__Status_Change"
#define TC_SCHEDULE_STATUS_CHANGE_TO_NOT_STARTED_EVENT           "__Status_ChangeTo_NotStarted"
#define TC_SCHEDULE_STATUS_CHANGE_TO_IN_PROGRESS_EVENT           "__Status_ChangeTo_InProgress"
#define TC_SCHEDULE_STATUS_CHANGE_TO_NEEDS_ATTENTION_EVENT       "__Status_ChangeTo_NeedsAttentn"
#define TC_SCHEDULE_STATUS_CHANGE_TO_COMPLETE_EVENT              "__Status_ChangeTo_Complete"
#define TC_SCHEDULE_STATUS_CHANGE_TO_ABANDONED_EVENT             "__Status_ChangeTo_Abandoned"
#define TC_SCHEDULE_STATUS_CHANGE_TO_LATE_EVENT                  "__Status_ChangeTo_Late"
#define TC_SCHEDULE_PRIORITY_CHANGE_EVENT                        "__Priority_Change"
#define TC_SCHEDULE_PRIORITY_CHANGE_TO_LOWEST_EVENT              "__Priority_ChangeTo_Lowest"
#define TC_SCHEDULE_PRIORITY_CHANGE_TO_LOW_EVENT                 "__Priority_ChangeTo_Low"
#define TC_SCHEDULE_PRIORITY_CHANGE_TO_MEDIUM_LOW_EVENT          "__Priority_ChangeTo_MediumLow"
#define TC_SCHEDULE_PRIORITY_CHANGE_TO_MEDIUM_EVENT              "__Priority_ChangeTo_Medium"
#define TC_SCHEDULE_PRIORITY_CHANGE_TO_HIGH_EVENT                "__Priority_ChangeTo_High"
#define TC_SCHEDULE_PRIORITY_CHANGE_TO_VERY_HIGH_EVENT           "__Priority_ChangeTo_VeryHigh"
#define TC_SCHEDULE_PRIORITY_CHANGE_TO_HIGHEST_EVENT             "__Priority_ChangeTo_Highest"

#define TC_SCHEDULETASK_USER_ASSIGNED_EVENT                      "__User_Assigned"
#define TC_SCHEDULETASK_NEAR_DUE_EVENT                           "__Near_Due"
#define TC_SCHEDULETASK_OVERDUE_EVENT                            "__Overdue"
#define TC_SCHEDULETASK_START_DATE_CHANGE_EVENT                  "__Start_Date_Change"
#define TC_SCHEDULETASK_FINISH_DATE_CHANGE_EVENT                 "__Finish_Date_Change"
#define TC_SCHEDULETASK_STATUS_CHANGE_EVENT                      "__Status_Change"
#define TC_SCHEDULETASK_STATUS_CHANGE_TO_NOT_STARTED_EVENT       "__Status_ChangeTo_NotStarted"
#define TC_SCHEDULETASK_STATUS_CHANGE_TO_IN_PGROGRESS_EVENT      "__Status_ChangeTo_InProgress"
#define TC_SCHEDULETASK_STATUS_CHANGE_TO_NEEDS_ATTENTION_EVENT   "__Status_ChangeTo_NeedsAttentn"
#define TC_SCHEDULETASK_STATUS_CHANGE_TO_COMPLETE_EVENT          "__Status_ChangeTo_Complete"
#define TC_SCHEDULETASK_STATUS_CHANGE_TO_ABANDONED_EVENT         "__Status_ChangeTo_Abandoned"
#define TC_SCHEDULETASK_STATUS_CHANGE_TO_LATE_EVENT              "__Status_ChangeTo_Late"
#define TC_SCHEDULETASK_PRIORITY_CHANGE_EVENT                    "__Priority_Change"
#define TC_SCHEDULETASK_PRIORITY_CHANGE_TO_LOWEST_EVENT          "__Priority_ChangeTo_Lowest"
#define TC_SCHEDULETASK_PRIORITY_CHANGE_TO_LOW_EVENT             "__Priority_ChangeTo_Low"
#define TC_SCHEDULETASK_PRIORITY_CHANGE_TO_MEDIUM_LOW_EVENT      "__Priority_ChangeTo_MediumLow"
#define TC_SCHEDULETASK_PRIORITY_CHANGE_TO_MEDIUM_EVENT          "__Priority_ChangeTo_Medium"
#define TC_SCHEDULETASK_PRIORITY_CHANGE_TO_HIGH_EVENT            "__Priority_ChangeTo_High"
#define TC_SCHEDULETASK_PRIORITY_CHANGE_TO_VERY_HIGH_EVENT       "__Priority_ChangeTo_VeryHigh"
#define TC_SCHEDULETASK_PRIORITY_CHANGE_TO_HIGHEST_EVENT         "__Priority_ChangeTo_Highest"
#define TC_SCHEDULETASK_WORK_ESTIMATE_CHANGE_EVENT               "__Work_Estimate_Change"
#define TC_SCHEDULETASK_WORK_COMPLETE_CHANGE_EVENT               "__Work_Complete_Change"
#define TC_SCHEDULETASK_WORK_READY_EVENT                         "__Work_Ready"
#define TC_SCHEDULETASK_DELETED_EVENT                            "__Deleted"

/** New events for ScheduleTask audit */
#define TC_SCHMGT_WF_LAUNCH                                      "__WF_Launch"
#define TC_SCHMGT_WF_CHANGED                                     "__WF_Changed"
#define TC_SCHMGT_TASK_SCH_CHANGE                                "__Task_SchedulingData_Changed"
#define TC_SCHMGT_TASK_EXEC_CHANGE                               "__Task_ExecutionData_Changed"
#define TC_SCHMGT_TASK_STATUS_CHANGE                             "__TaskStatus_Changed"

/** Dependnecy */
#define TC_SCHMGT_TASK_DEPENDENCY_CREATE                         "__TaskDependency_Create"
#define TC_SCHMGT_TASK_DEPENDENCY_MODIFY                         "__TaskDependency_Modify"
#define TC_SCHMGT_TASK_DEPENDENCY_DELETE                         "__TaskDependency_Delete"

/** Resource Assignment */
#define TC_SCHMGT_RESOURCEASSIGNMENT_CREATE                      "__ResourceAssignment_Create"
#define TC_SCHMGT_RESOURCEASSIGNMENT_MODIFY                      "__ResourceAssignment_Modify"
#define TC_SCHMGT_RESOURCEASSIGNMENT_DELETE                      "__ResourceAssignment_Delete"

/** Common events for schedule and task */
#define TC_SCHMGT_STATE_CHANGE                                   "__State_Change"
#define TC_SCHMGT_STATE_NOT_STARTED                              "__State_ChangeTo_NotStarted"
#define TC_SCHMGT_STATE_IN_PROGRESS                              "__State_ChangeTo_InProgress"
#define TC_SCHMGT_STATE_COMPLETE                                 "__State_ChangeTo_Complete"
#define TC_SCHMGT_STATE_CLOSED                                   "__State_ChangeTo_Closed"
#define TC_SCHMGT_STATE_ABORT                                    "__State_ChangeTo_Abort"

/** New events for Schedule audit */
#define TC_SCHMGT_SCH_STATUS_CHANGE                              "__SchStatus_Changed"
#define TC_SCHMGT_SCH_BASELINE                                   "__Sch_Baseline_Created"

/** Qualification */
#define TC_SCHMGT_ASSIGN_QUALIFICATION                           "Fnd0Assign_Qualification"
#define TC_SCHMGT_REMOVE_QUALIFICATION                           "Fnd0Remove_Qualification"
#define TC_SCHMGT_MODIFY_QUALIFICATION_LEVEL                     "Fnd0Modify_Qualification_Level"

/** Events related to ADA Licenses */
#define TC_LOCK_LICENSE_EVENT                                    "__Lock"
#define TC_UNLOCK_LICENSE_EVENT                                  "__Unlock"
#define TC_LICENSE_LOCK_DATE_MODIFIED_EVENT                      "__Lock_Date_Modified"
#define TC_EXPIRE_LICENSE_EVENT                                  "__Expire"
#define TC_LICENSE_EXPIRE_DATE_MODIFIED_EVENT                    "__Expiry_Date_Modified"
#define TC_ADD_USERS_GROUPS_TO_LICENSE_EVENT                     "__Add_Users_Groups"
#define TC_REMOVE_USERS_GROUPS_FROM_LICENSE_EVENT                "__Remove_Users_Groups"
#define TC_ATTACH_LICENSE_EVENT                                  "__Attach_License"
#define TC_DETACH_LICENSE_EVENT                                  "__Detach_License"
#define TC_EDIT_AUTH_PARAGRAPH_EVENT                             "__Edit_Auth_Paragraph"

/* Events related to the Structure Manager application */
#define TC_COMPONENT_ADD_EVENT                                   "__Component_Add"
#define TC_COMPONENT_REMOVE_EVENT                                "__Component_Remove"

/** Events related to Digital Signature

     This event indicates that a digital signature has been applied.
     <br><br>
     Auditing and Subscription events can be posted using the postEvent method.
*/
#define TC_DIGITAL_SIGNATURE_APPLY_EVENT                         "Fnd0Apply_Digital_Signature"

/**
     This event indicates that a digital signature object has been deleted.
     <br><br>
     Auditing and Subscription events can be posted using the postEvent method.
*/
#define TC_DIGITAL_SIGNATURE_DELETE_EVENT                        "Fnd0Delete_Digital_Signature"

/**
     This event indicates a PKI smart card authentication.
     <br><br>
     Auditing and Subscription events can be posted using the postEvent method.
*/
#define TC_PKI_AUTHENTICATION_EVENT                              "Fnd0PKI_Authentication"

/**
     This event indicates that a digital sign is verified on the target object.
     <br><br>
     Auditing and Subscription events can be posted using the postEvent method.
*/
#define TC_DIGITAL_SIGNATURE_VERIFY_EVENT                        "Fnd0Verify_Digital_Signature"

/**
     This event indicates that a digital signature is voided on the target object.
     <br><br>
     Auditing and Subscription events can be posted using the postEvent method.
*/
#define TC_DIGITAL_SIGNATURE_VOID_EVENT                          "Fnd0Void_Digital_Signature"

/**
     This event indicates that a Replace operation has been performed on the BVR model.
     <br><br>
     Auditing and Subscription events can be posted using the postEvent method.
*/
#define TC_OCCURRENCE_REPLACE_EVENT                              "Fnd0Occurrence_Replace"

/**
     This event indicates that a release status has been applied to a BVR model.
     <br><br>
     Auditing and Subscription events can be posted using the postEvent method.
*/
#define TC_APPLY_RELEASE_STATUS_EVENT                            "Fnd0Apply_Release_Status"

/** @} */

/**
    @defgroup STANDARD_TC_EVENT_REFERENCE_DATA_KEYS Common reference data keys used when posting events
    @ingroup SUBSCRIPTION
    @{
*/

/**
     This key is used when specifying the original underlying object UID as part of the reference
     data on the event.  This is typically used during a replace event.  Reference data is specified
     as name and value pairs passed to the event when the postEvent method is called.
     <br><br>
     It is the responsibility of the Action Handler to retrieve the reference value using this
     reference data key.
*/
#define TC_ORIGINAL_UNDERLYING_OBJECT_REF_KEY                    "OriginalUnderlyingObject"

/**
     This key is used when specifying an underlying object UID as part of the reference
     data on the event.  This is typically used during a replace event.  Reference data is specified
     as name and value pairs passed to the event when the postEvent method is called.
     <br><br>
     It is the responsibility of the Action Handler to retrieve the reference value using this
     reference data key.
*/
#define TC_UNDERLYING_OBJECT_REF_KEY                             "UnderlyingObject"

/** Special internal event for tracking notification list changes on subscriptions */
#define TC_NEW_SUBSCRIPTION_RECIPIENTS_EVENT                     "Fnd0New_Subscription_Recipients"

/** Special internal trigger event for completion of Print */
#define TC_PRINT_COMPLETE_EVENT                                  "Fnd0Print_Complete"

/** Special internal trigger event for completion of Document Management various tasks */
#define TC_DOCMGT_RENDER_COMPLETE_EVENT                          "Fnd0DocMgt_Render_Complete"
#define TC_DOCMGT_UPDATEDOCPROP_COMPLETE_EVENT                   "Fnd0DocMgt_UpdDocProp_Complete"
#define TC_DOCMGT_BATCHPRINT_COMPLETE_EVENT                      "Fnd0DocMgt_BatchPrint_Complete"
#define TC_DOCMGT_RENDERONDEMAND_SUCCESS_EVENT                   "Fnd0DocMgt_RenderOnDemandSuccess"
#define TC_DOCMGT_RENDERONDEMAND_FAILURE_EVENT                   "Fnd0DocMgt_RenderOnDemandFailure"
#define TC_DOCMGT_PDF_SIGN_FAILURE_EVENT                         "Fnd0DocMgt_PDFSignFailure"
#define TC_DOCMGT_PDF_SIGN_SUCCESS_EVENT                         "Fnd0DocMgt_PDFSignSuccess"

/** Special internal trigger event for completion of the comparison of rich text contents of Workspace objects */
#define TC_CONTENT_COMPARE_COMPLETE_EVENT                        "Fnd0Content_Compare_Complete"

/** Special internal trigger event for completion of the export of Workspace objects to Excel */
#define TC_EXPORT_COMPLETE_EVENT                                  "Fnd0Export_Complete"

/** Special internal trigger event for completion of Generate Report */
#define TC_GENERATE_REPORT_COMPLETE_EVENT                        "Fnd0GenerateReport_Complete"

/** Special internal trigger event for error completion of Workflow Async */
#define TC_GENERATE_WORKFLOW_ASYNC_EVENT                        "Fnd0Workflow_Error"

/** Special internal trigger event for completion of Multisite Async */
#define TC_GENERATE_MULTISITE_ASYNC_EVENT                        "Fnd0MultiSite_Complete"
/** @} */

#include <sub_mgr/libsub_mgr_undef.h>
#endif
