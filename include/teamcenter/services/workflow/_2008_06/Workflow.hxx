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

#ifndef TEAMCENTER_SERVICES_WORKFLOW__2008_06_WORKFLOW_HXX
#define TEAMCENTER_SERVICES_WORKFLOW__2008_06_WORKFLOW_HXX

#include <teamcenter/soa/client/model/EPMAssignmentList.hxx>
#include <teamcenter/soa/client/model/EPMJob.hxx>
#include <teamcenter/soa/client/model/EPMSignoffProfile.hxx>
#include <teamcenter/soa/client/model/EPMTask.hxx>
#include <teamcenter/soa/client/model/EPMTaskTemplate.hxx>
#include <teamcenter/soa/client/model/Group.hxx>
#include <teamcenter/soa/client/model/ResourcePool.hxx>
#include <teamcenter/soa/client/model/Role.hxx>
#include <teamcenter/soa/client/model/Signoff.hxx>
#include <teamcenter/soa/client/model/WorkspaceObject.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/workflow/Workflow_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Workflow
        {
            namespace _2008_06
            {
                class Workflow;

class TCSOAWORKFLOWSTRONGMNGD_API Workflow
{
public:

    struct AssignmentLists;
    struct AttachmentInfo;
    struct AuditFile;
    struct ChangeStateInputInfo;
    struct ChangeStateOutput;
    struct ContextData;
    struct CreateSignoffInfo;
    struct CreateSignoffs;
    struct DefinitionInfo;
    struct GetResourcePoolOutput;
    struct GroupRoleRef;
    struct InstanceInfo;
    struct ProcessTemplates;
    struct RemoveSignoffsInfo;
    struct ResourcePoolInfo;
    struct Resources;
    struct Tasks;
    struct Templates;

    /**
     * AllOrAssigned
     */
    enum AllOrAssigned{ SOA_EPM_All,
                 SOA_EPM_Assigned
                 };

    /**
     * OriginType
     */
    enum OriginType{ SOA_EPM_ORIGIN_UNDEFINED,
                 SOA_EPM_SIGNOFF_ORIGIN_PROFILE,
                 SOA_EPM_SIGNOFF_ORIGIN_ADDRESSLIST
                 };

    /**
     * SignoffAction
     */
    enum SignoffAction{ SOA_EPM_ACTION_UNDEFINED,
                 SOA_EPM_Review,
                 SOA_EPM_Acknowledge,
                 SOA_EPM_Notify
                 };

    /**
     * SoaEPMAction
     */
    enum SoaEPMAction{ SOA_EPM_assign_action,
                 SOA_EPM_start_action,
                 SOA_EPM_complete_action,
                 SOA_EPM_skip_action,
                 SOA_EPM_suspend_action,
                 SOA_EPM_resume_action,
                 SOA_EPM_undo_action,
                 SOA_EPM_abort_action,
                 SOA_EPM_perform_action,
                 SOA_EPM_add_attachment_action,
                 SOA_EPM_remove_attachment_action,
                 SOA_EPM_approve_action,
                 SOA_EPM_reject_action,
                 SOA_EPM_promote_action,
                 SOA_EPM_demote_action,
                 SOA_EPM_refuse_action,
                 SOA_EPM_assign_approver_action,
                 SOA_EPM_notify_action,
                 SOA_EPM_no_action,
                 SOA_EPM_fail_action
                 };

    /**
     * SoaEPMSupportingValues
     */
    enum SoaEPMSupportingValues{ SOA_EPM_no_decision,
                 SOA_EPM_approve,
                 SOA_EPM_reject,
                 SOA_EPM_unset,
                 SOA_EPM_completed,
                 SOA_EPM_unable_to_complete,
                 SOA_EPM_true,
                 SOA_EPM_false,
                 SOA_EPM_no_error
                 };

    /**
     * stateType
     */
    enum stateType{ open_notrunning,
                 open_notrunning_suspended,
                 open_running,
                 closed_completed,
                 closed_abnormalcompleted,
                 closed_abnormalcompleted_terminated,
                 closed_abnormalcompleted_aborted,
                 open_notrunning_pending,
                 open_running_started,
                 open_running_failed
                 };

    /**
     * Process Assignment Lists
     */
    struct AssignmentLists
    {
        /**
         * assignedLists
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMAssignmentList>  > assignedLists;
        /**
         * ownedLists
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMAssignmentList>  > ownedLists;
        /**
         * groupLists
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMAssignmentList>  > groupLists;
        /**
         * otherLists
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMAssignmentList>  > otherLists;
        /**
         * Service data - returns index of the input vector if call on that fails
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure containing list of attachments and the attachment types
     */
    struct AttachmentInfo
    {
        /**
         * attachment
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > attachment;
        /**
         * attachmentType
         */
        std::vector< int > attachmentType;
    };

    /**
     * Audit files
     */
    struct AuditFile
    {
        /**
         * auditFiles
         */
        std::vector< std::string > auditFiles;
        /**
         * serviceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input to changeState operation
     */
    struct ChangeStateInputInfo
    {
        /**
         * state
         */
        stateType state;
        /**
         * remoteProcessID
         */
        std::string remoteProcessID;
    };

    /**
     * ChangeState operation output
     */
    struct ChangeStateOutput
    {
        /**
         * state
         */
        stateType state;
        /**
         * remoteProcessID
         */
        std::string remoteProcessID;
        /**
         * parentProcessID
         */
        std::string parentProcessID;
        /**
         * serviceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Context-specific data required to create a process or a sub process at a local or
     * a remote site.  Except the process template, the rest of the elements in the context
     * data is optional. The optional elements        that are currently supported are attachmentCount,attachments,attachmentTypes
     * and processAssignmentList.  The rest of the optional elements are defined to support
     * future workflow enhancements.
     */
    struct ContextData
    {
        /**
         * Name of the process template.  must be a valid, existing process template
         */
        std::string processTemplate;
        /**
         * Login id of the process owner. supported in future
         */
        std::string processOwner;
        /**
         * Count of attachment objects consisting of including both target        and reference
         * attachments. If count is less than 1, no attachments are added
         */
        int attachmentCount;
        /**
         * List of atachments representing either target or reference objects that will be added
         * at process creation time. List may consist of target attachments or reference attachments
         * or a mixture of both. If NULL, no attachments are added
         */
        std::vector< std::string > attachments;
        /**
         * Identifies the types of attachments listed in attachment.  Valid types include EPM_target_attachment
         * (target attachment) and EPM_reference_attachment (reference attachment). There is
         * a one-to-one correspondence between the attachment types on this list and the list
         * of attachments.
         */
        std::vector< int > attachmentTypes;
        /**
         * A date in the form of yyyy-mm-dd hh-mm-ss GMT that will be applied as a due date
         * for the processes. If GMT is not specified then the time will be interpreted as based
         * on the local time zone of the server. If NULL or invalid date, no due date is applied.
         * supported in future
         */
        Teamcenter::Soa::Common::DateTime deadlineDate;
        /**
         * Identifies the object to which the processes should be attached using the relation_type
         * specified. supported in future
         */
        std::string container;
        /**
         * The name of the relation. If NULL, the default relation type for the container object
         * will be used. supported in future
         */
        std::string relationType;
        /**
         * Name of the process assignment list
         */
        std::string processAssignmentList;
        /**
         * A list of comma-separated user login IDs that will be used to satisfy signoff profiles
         * for each individual task. Any users that do not match a signoff profile within a
         * task will be added as an adhoc user. supported in future
         */
        std::vector< std::string > processResources;
        /**
         * The path to the dependency task. This will be used to determine the dependency tasks
         * in the processes that need to be returned in response.   The full path to the task
         * in the template needs to be specified, e.g.       CMII Change Notice: Change Admin
         * II (CN). supported in future
         */
        std::string dependencyTask;
        /**
         * The flag to indicate if the observer needs to be notified about events that occur
         * on the processes and the dependency tasks in the processes. supported in future
         */
        bool subscribeToEvents;
        /**
         * Number of events to subscribe to
         */
        int subscriptionEventCount;
        /**
         * List of events for which subscription objects will be created so that the observer
         * is notified when these events occur on the process and /or process dependency task.
         * supported in future
         */
        std::vector< std::string > subscriptionEventList;
        /**
         * URI of the observer in the remote application. supported in future
         */
        std::string remoteParent;
        /**
         * The Application ID of the application in which the observer resides. supported in
         * future
         */
        std::string remoteParentAppguid;
        /**
         * The URL to the observer. supported in future
         */
        std::string remoteParentUrl;
    };

    /**
     * Structure containing information to add adhoc signoff or add signoff based on a profile
     */
    struct CreateSignoffInfo
    {
        /**
         * signoffMember
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  signoffMember;
        /**
         * origin
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  origin;
        /**
         * signoffAction
         */
        SignoffAction signoffAction;
        /**
         * originType
         */
        OriginType originType;
    };

    /**
     * Structure containing information to add adhoc signoff or add signoff based on a profile
     */
    struct CreateSignoffs
    {
        /**
         * task
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMTask>  task;
        /**
         * signoffInfo
         */
        std::vector< Teamcenter::Services::Workflow::_2008_06::Workflow::CreateSignoffInfo > signoffInfo;
    };

    /**
     * Structure containing process template information
     */
    struct DefinitionInfo
    {
        /**
         * unique identifier of the process template
         */
        std::string definitionkey;
        /**
         * name of the process template
         */
        std::string name;
        /**
         * description of the process template
         */
        std::string description;
        /**
         * version of the process template
         */
        std::string version;
        /**
         * status of the process template. The values are 0 -obsolete,1 - under construction,
         * 2- ready for use
         */
        int status;
    };

    /**
     * Structure containing the Resource Pool matching the GroupRoleRef and the ServiceData
     */
    struct GetResourcePoolOutput
    {
        /**
         * resourcePoolInfo
         */
        std::vector< Teamcenter::Services::Workflow::_2008_06::Workflow::ResourcePoolInfo > resourcePoolInfo;
        /**
         * serviceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure containing the group and role info
     */
    struct GroupRoleRef
    {
        /**
         * groupTag
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Group>  groupTag;
        /**
         * roleTag
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Role>  roleTag;
        /**
         * allowSubGroup
         */
        int allowSubGroup;
        /**
         * isAllMembers
         */
        int isAllMembers;
    };

    /**
     * Structure containing information related to the new process
     */
    struct InstanceInfo
    {
        /**
         * instanceKey. supported in future
         */
        std::string instanceKey;
        /**
         * newProcessDepTask. supported in future
         */
        std::string newProcessDepTask;
        /**
         * newProcessUrl. supported in future
         */
        std::string newProcessUrl;
        /**
         * newProcessDepTaskUrl. supported in future
         */
        std::string newProcessDepTaskUrl;
        /**
         * serviceData containing the created process and errors if any
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Process templates
     */
    struct ProcessTemplates
    {
        /**
         * vector of DefinitionInfo objects
         */
        std::vector< Teamcenter::Services::Workflow::_2008_06::Workflow::DefinitionInfo > output;
        /**
         * Service data contains any partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure containing signoffs to be removed
     */
    struct RemoveSignoffsInfo
    {
        /**
         * task
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMTask>  task;
        /**
         * removeSignoffObjs
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Signoff>  > removeSignoffObjs;
    };

    /**
     * Structure containing resource pool , group and role info
     */
    struct ResourcePoolInfo
    {
        /**
         * groupRoleRef
         */
        Teamcenter::Services::Workflow::_2008_06::Workflow::GroupRoleRef groupRoleRef;
        /**
         * resourcePoolTag
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ResourcePool>  resourcePoolTag;
    };

    /**
     * Structure containing the task template and the resources to be applied to the template
     */
    struct Resources
    {
        /**
         * taskTemplate
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMTaskTemplate>  taskTemplate;
        /**
         * templateResources
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > templateResources;
        /**
         * profiles
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMSignoffProfile>  > profiles;
        /**
         * actions
         */
        std::vector< int > actions;
        /**
         * revQuorum
         */
        int revQuorum;
        /**
         * ackQuorum
         */
        int ackQuorum;
    };

    /**
     * Structure containing all the tasks in a process
     */
    struct Tasks
    {
        /**
         * allTasks
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMTask>  > allTasks;
        /**
         * Service data contains any partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * structure containing workflow templates
     */
    struct Templates
    {
        /**
         * workflowTemplates
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMTaskTemplate>  > workflowTemplates;
        /**
         * Service data contains any partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Workflow() {}
};
            }
        }
    }
}

#include <teamcenter/services/workflow/Workflow_undef.h>
#endif

