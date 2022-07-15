/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SERVICES_WORKFLOW_WORKFLOWSERVICE_HXX
#define TEAMCENTER_SERVICES_WORKFLOW_WORKFLOWSERVICE_HXX

#include <teamcenter/services/workflow/_2007_06/Workflow.hxx>
#include <teamcenter/services/workflow/_2008_06/Workflow.hxx>
#include <teamcenter/services/workflow/_2010_09/Workflow.hxx>
#include <teamcenter/services/workflow/_2013_05/Workflow.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/workflow/Workflow_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Workflow
        {
            class WorkflowService;

/**
 * Contains Workflow Services
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaworkflowstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaworkflowtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAWORKFLOWSTRONGMNGD_API WorkflowService
    : public Teamcenter::Services::Workflow::_2007_06::Workflow,
             public Teamcenter::Services::Workflow::_2008_06::Workflow,
             public Teamcenter::Services::Workflow::_2010_09::Workflow,
             public Teamcenter::Services::Workflow::_2013_05::Workflow
{
public:
    static WorkflowService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Manages the release status status of an object  The permitted operations are Append,
     * Delete, Rename and Replace Currently Append and Delete are supported With the delete
     * operation if an empty string is passed in instead of the status name all statuses
     * will be cleared for that set of workspace objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param input
     *        A vector of ReleaseStatusInput structures that control operations performed on the
     *        objects
     *
     * @return
     *         Failure will be with error messages in the ServiceData.
     *
     *
     * @exception ServiceException
     *           Teamcenter::Soa::Server::ServiceException:
     *           <br>
     */
    virtual Teamcenter::Services::Workflow::_2007_06::Workflow::SetReleaseStatusResponse setReleaseStatus ( const std::vector< Teamcenter::Services::Workflow::_2007_06::Workflow::ReleaseStatusInput >& input ) = 0;

    /**
     * addAttachments - Add attachments to a task.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param task
     *        task to add attachments to.
     *
     * @param attachments
     *        structure containing the list of attachments and the attachment types. The attachments
     *        can be target_objects, reference_objects,release status etc The attachment types
     *        can be EPM_target_attachment, EPM_reference_attachment, EPM_release_status_attachment
     *        and EPM_signoff_attachment
     *
     * @return
     *         containing the updated task.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData addAttachments ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMTask>  task,
        const Teamcenter::Services::Workflow::_2008_06::Workflow::AttachmentInfo&  attachments ) = 0;

    /**
     * addSignoffs : Add signoffs on a task.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param signoffs
     *        vector of CreateSignoffs - structure containing the task tag and vector of CreateSignoffInfo
     *        Description: CreateSignoffInfo structure contains information to add adhoc signoff
     *        or add signoff based on a profile Case of Adhoc signoff:this is used for the case
     *        of adhoc signoff : Provide signoffMember can be group member(user), resource pool
     *        or address list(complete address list) tags : In this profile /subset of addresslist
     *        will be empty. So there is no need to provide origin and origintype. Can pass a null
     *        and 0 respectively. : Provide the signoffAction. Case of profile :this is used when
     *        a signoff member is being added to satisfy a signoff profile : Provide the signoff
     *        member : Provide the origin which will be the signoff profile object associated with
     *        the signoff member : Provide the originType as SOA_EPM_SIGNOFF_ORIGIN_PROFILE Case
     *        of subset of address list : this is used when only a particular member of an addresslist
     *        needs to be added as a signoff. : Provide the signoff member : Provide the origin
     *        which will be the address list object associated with the signoff member : Provide
     *        the originType as SOA_EPM_SIGNOFF_ORIGIN_ADDRESSLIST
     *
     * @return
     *         serviceData.
     *
     *
     * @exception ServiceException
     *           Teamcenter::Soa::Server::ServiceException:
     *           <br>
     */
    virtual Teamcenter::Soa::Client::ServiceData addSignoffs ( const std::vector< Teamcenter::Services::Workflow::_2008_06::Workflow::CreateSignoffs >& signoffs ) = 0;

    /**
     * Assign a process assignment list to a process. Description: If the assignment list
     * is given, it will use it to apply the assignment list to the process.  If the assignment
     * is not given, it will loop through the Resources structure and create the list of
     * task templates and list of resources, profiles and other information to apply the
     * resources to the process. Thus at a given time either assignmentList and resources
     * both cannot be null. either one of them can be null
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param process
     *        the process to which the process assignment list has to be assigned.
     *
     * @param assignmentList
     *        assignment list to be applied to the process
     *
     * @param resources
     *        list of structures containing resource info (for eg. Task template, Group member
     *        or resource pool, signoff profiles, quorum etc).
     *
     * @return
     *         - Service data contains any partial errors.
     *
     *
     * @exception ServiceException
     *           Teamcenter::Soa::Server::ServiceException:
     *           <br>
     */
    virtual Teamcenter::Soa::Client::ServiceData assignAllTasks ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMJob>  process,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMAssignmentList>  assignmentList,
        const std::vector< Teamcenter::Services::Workflow::_2008_06::Workflow::Resources >& resources ) = 0;

    /**
     * changeState - Change the state of a process or a task at a remote site.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param stateInput
     *        ChangeStateInputInfo
     *
     * @return
     *         the structure consisting of the changed state of the process or sub process or a
     *         task at the remote site, the unique ID of the remote process or task whose state
     *         was changed, the uniqueID of the process or task who initiated the state change and
     *         the serviceData containing the URI of the modified remote process or task.
     *
     */
    virtual Teamcenter::Services::Workflow::_2008_06::Workflow::ChangeStateOutput changeState ( const Teamcenter::Services::Workflow::_2008_06::Workflow::ChangeStateInputInfo&  stateInput ) = 0;

    /**
     * CreateInstance - Creates a process/sub process at a local or a remote site.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param startImmediately
     *        Boolean value to say whether the instance that is created should be
     *        immediately started, or whether it should be put
     *        into an initial state                                              for later starting
     *        by use of the "start" operation.  If this tag is
     *        missing, the default value is true.
     *
     * @param observerKey
     *        URI of the observer that initiated the process or sub process at a remote
     *        site.  The observer is to be notified of events impacting
     *        the execution of this                                        process instance such
     *        as state changes, and most notably the completion of
     *        the instance.  If not specified, the observer will not receive completed
     *        notification from the sub process.
     *
     * @param name
     *        Name of the remote process or sub process instance.  This argument is optional
     *
     * @param subject
     *        A shorter description of the purpose of the remote process or sub process.   This
     *        argument is optional.
     *
     * @param description
     *        A longer description of the purpose of the remote process or sub process. This
     *        argument is optional.
     *
     * @param contextData
     *        Context-specific data required to create a process or sub process at a local or a
     *        remote site in Teamcenter.
     *
     * @return
     *         InstanceInfo structure containing the URI of the new process or sub process that
     *         has been created at the remote site ServiceData -  contains the URI of the newly
     *         created process or sub process at the remote site.
     *
     */
    virtual Teamcenter::Services::Workflow::_2008_06::Workflow::InstanceInfo createInstance ( bool startImmediately,
        const std::string&  observerKey,
        const std::string&  name,
        const std::string&  subject,
        const std::string&  description,
        const Teamcenter::Services::Workflow::_2008_06::Workflow::ContextData&  contextData ) = 0;

    /**
     * Delegate a signoff to a different groupmember or a resourcepool.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param delegatee
     *        The group memebr or a resource pool tag to be delegated to.
     *
     * @param signoff
     *        signoff object.
     *
     * @return
     *         serviceData.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData delegateSignoff ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  delegatee,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Signoff>  signoff ) = 0;

    /**
     * Gets all the tasks in a process.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param process
     *        workflow process object
     *
     * @param state
     *        TODO
     *
     * @return
     *         Tasks
     *
     */
    virtual Teamcenter::Services::Workflow::_2008_06::Workflow::Tasks getAllTasks ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMJob>  process,
        int state ) = 0;

    /**
     * Gets the process assignment list given the process assignment list names.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param names
     *        A set of process assignment list names
     *
     * @return
     *         AssignmentList - with list of process assignment lists and ServiceData
     *
     *
     * @exception ServiceException
     *           Teamcenter::Soa::Server::ServiceException:
     *           <br>
     */
    virtual Teamcenter::Services::Workflow::_2008_06::Workflow::AssignmentLists getAssignmentLists ( const std::vector< std::string >& names ) = 0;

    /**
     * getResourcePool - Returns regular or all member ResourcePools corresponding to the
     * list of GroupRoleRef (group and role).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param groupRoleRef
     *        list of GroupRoleRef  structure containing info about the Resource Pool being asked
     *        for
     *
     * @return
     *         list of ResourcePoolInfo - structure containing the Resource Pool matching the GroupRoleRef
     *         and the Service Data
     *
     */
    virtual Teamcenter::Services::Workflow::_2008_06::Workflow::GetResourcePoolOutput getResourcePool ( const std::vector< Teamcenter::Services::Workflow::_2008_06::Workflow::GroupRoleRef >& groupRoleRef ) = 0;

    /**
     * Get the list of workflow templates given the list of target workspace objects and
     * the All or Assigned criteria.  Description This SOA will return all the ready to
     * use and under construction templates if the allorAssined criteria is SOA_EPM_ALL.
     * If the allOrAssignedCriteria is set to SOA_EPM_Assigned, this SOA will get the group
     * information and the configured filtering criteria from the session and using the
     * list of target objects, return the filtered list of workflow templates.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param targets
     *        list of target objects to get the workflow templates for
     *
     * @param allOrAssignedCriteria
     *        criteria to get all the templates or assigned templates.
     *
     * @return
     *         Templates
     *
     * @deprecated
     *         As of Teamcenter 10.1, use the getWorkflowTemplates operation from the _2013_05 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10.1, use the getWorkflowTemplates operation from the _2013_05 namespace."))
#endif
    virtual Teamcenter::Services::Workflow::_2008_06::Workflow::Templates getWorkflowTemplates ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  >& targets,
        const AllOrAssigned&  allOrAssignedCriteria ) = 0;

    /**
     * Gets a list of process templates based on the criteria passed.  Description if name
     * and status are specified, all the templates matching the name and the status are
     * returned. If only name is specified, only the available templates matching the name
     * will be returned If only status is specified, all the templates with the specified
     * status is returned. If both are not specified, all the available templates will be
     * returned for a non-Dba
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param name
     *        name of the template to retrieve. This argument is optional.  Provide the value null
     *        to make it optional.
     *
     * @param templatestatus
     *        TODO
     *
     * @return
     *         ProcessTemplates
     *
     */
    virtual Teamcenter::Services::Workflow::_2008_06::Workflow::ProcessTemplates listDefinitions ( const std::string*  name,
        int templatestatus ) = 0;

    /**
     * Performs workflow actions on a task. The actions that can be performed using this
     * operation are : assign, start, complete, skip, suspend, resume, undo, perform, approve,
     * reject, promote and demote. Note: Special case This operation can be used to set
     * only comments without changing the decision for perform signoff task. To do that,
     * use the 'EPM_no_action' as input for action argument and use the current decision
     * for the supportingValue argument.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param task
     *        The task
     *
     * @param action
     *        the action to be performed on the task required. The possible values for action are
     *        defined in enum SoaEPMAction.  They are SOA_EPM_assign_action, SOA_EPM_start_action,
     *        SOA_EPM_complete_action,  SOA_EPM_skip_action, SOA_EPM_suspend_action,  SOA_EPM_resume_action,
     *        SOA_EPM_undo_action, SOA_EPM_abort_action, SOA_EPM_perform_action,
     *        SOA_EPM_add_attachment_action, SOA_EPM_remove_attachment_action, SOA_EPM_approve_action,
     *        SOA_EPM_reject_action, SOA_EPM_promote_action, SOA_EPM_demote_action, SOA_EPM_refuse_action,
     *        SOA_EPM_assign_approver_action, SOA_EPM_notify_action and SOA_EPM_no_action
     *
     * @param comments
     *        user comments. This argument is optional.  Provide the value null to make it optional.
     *
     * @param password
     *        password for secure signoff action required for secure signoff.        This argument
     *        is optional.  Provide the value null to make it optional(non secure).
     *
     * @param supportingValue
     *        this argument can be used to send in decision value or result.  If the task is perform
     *        signoff task, provide the decision using this argument.  The possible values for
     *        decision are SOA_EPM_no_decision, SOA_EPM_approve, SOA_EPM_reject.  For all the other
     *        tasks, provide the result value using this argument.  Following are the result values
     *        applicable for different tasks..   SOA_EPM_unset - Do,Review,Route,Ack,EPMTask,Cond(Auto/Manual),SST
     *        and Validate  SOA_EPM_completed - Do,EPMTask and SST  SOA_EPM_unable_to_complete
     *        -Do,EPMTtask,Cond (Manual)  SOA_EPM_true -Cond (Auto/Manual)  SOA_EPM_false -Cond
     *        (Auto/Manual)  SOA_EPM_no_error - Validate
     *
     * @param supportingObject
     *        If the action is assign, provide a user tag or a resource pool tag to assign the
     *        task to. If the task is perform signoff task, provide the signoff tag to set the
     *        decision on.
     *
     * @return
     *         Service data - returns index of the input vector if call on that fails
     *
     *
     * @exception ServiceException
     *           Teamcenter::Soa::Server::ServiceException:
     *           <br>
     */
    virtual Teamcenter::Soa::Client::ServiceData performAction ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMTask>  task,
        const SoaEPMAction&  action,
        const std::string*  comments,
        const std::string*  password,
        const SoaEPMSupportingValues&  supportingValue,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  supportingObject ) = 0;

    /**
     * removeAttachments - Remove attachments to a task.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param task
     *        task to remove attachments from.
     *
     * @param attachments
     *        the list of attachments to remove The attachments can be target_objects, reference_objects,release
     *        status etc
     *
     * @return
     *         containing the updated task.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData removeAttachments ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMTask>  task,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& attachments ) = 0;

    /**
     * addSignoffs - Add/remove and update signoffs on a task.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param signoffs
     *        list of Signoffs - structure containing the select signoff task tag, groupmembers
     *        or
     *
     * @return
     *         serviceData.
     *
     *
     * @exception ServiceException
     *           Teamcenter::Soa::Server::ServiceException:
     *           <br>
     */
    virtual Teamcenter::Soa::Client::ServiceData removeSignoffs ( const std::vector< Teamcenter::Services::Workflow::_2008_06::Workflow::RemoveSignoffsInfo >& signoffs ) = 0;

    /**
     * viewAuditFile - get audit information on the selected object when stored in a file.
     * By default, audit info is stored in a file in teamcenter.  This operation cannot
     * be used to get audit info when audit manager is turned on.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param auditedObject
     *        the object to get audit info on. E.g. workspace object in process or
     *        process itself..
     *
     * @param isSignoffReport
     *        Boolean to indicate if the request is for a audit file or a signoff report. true
     *        for a signoff report, false for a audit file
     *
     * @return
     *         structure containing the audit file and the service data.
     *
     */
    virtual Teamcenter::Services::Workflow::_2008_06::Workflow::AuditFile viewAuditFile ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  auditedObject,
        bool isSignoffReport ) = 0;

    /**
     * Apply the specified templates to all active workflow processes that are based on
     * earlier versions of the templates.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param applyTemplateInput
     *        Templates to be applied to active processes
     *
     * @param processingMode
     *        Indicates if request needs to be processed asynchronously.  0 - Indicates synchronous
     *        processing. 1 - Indicates asynchronous processing.
     *
     * @return
     *         List of active processes that were updated successfully and list of failures
     *
     *
     * @exception ServiceException
     *           Teamcenter::Soa::Server::ServiceException:
     *           <br>
     */
    virtual Teamcenter::Services::Workflow::_2010_09::Workflow::ApplyTemplateResponse applyTemplateToProcesses ( const std::vector< Teamcenter::Services::Workflow::_2010_09::Workflow::ApplyTemplateInput >& applyTemplateInput,
        int processingMode ) = 0;

    /**
     * This operation gets the list of workflow templates based on input criteria. The criteria
     * includes the target objects for the workflow or the types of the target objects.
     * User can also specify if the under construction templates should to be returned and
     * if the filtered list of templates is required. The filtered list of templates are
     * returned based on the users group and the target objects. The filter rules can also
     * be customized using the user exits.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param input
     *        Structure to define input for workflow Templates.
     *
     * @return
     *         This operation returns the list of workflow templates based on the input criteria
     *         and ServiceData structure containing errors if any.
     *
     */
    virtual Teamcenter::Services::Workflow::_2013_05::Workflow::GetWorkflowTemplatesResponse getWorkflowTemplates ( const std::vector< Teamcenter::Services::Workflow::_2013_05::Workflow::GetWorkflowTemplatesInputInfo >& input ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("WorkflowService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/workflow/Workflow_undef.h>
#endif

