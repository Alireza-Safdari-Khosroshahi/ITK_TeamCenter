/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

  Auto-generated source from Teamcenter Data Model.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0WORKFLOWAUDIT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0WORKFLOWAUDIT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0AuditLog.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Fnd0WorkflowAudit : public Teamcenter::Soa::Client::Model::Fnd0AuditLog
{
public:
    int get_fnd0ActualDuration();
    const Teamcenter::Soa::Common::DateTime& get_fnd0EndDate();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0Signoff();
    const Teamcenter::Soa::Common::DateTime& get_fnd0StartDate();
    const std::string& get_process_templateDisp();
    const std::string& get_responsible_partyDisp();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0Object();
    const std::string& get_object_name();
    const std::string& get_object_type();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0Job();
    const std::string& get_job_name();
    const std::string& get_fnd0EventTypeName();
    const std::string& get_fnd0UserId();
    const std::string& get_fnd0GroupName();
    const std::string& get_fnd0RoleName();
    const Teamcenter::Soa::Common::DateTime& get_fnd0LoggedDate();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_process_template();
    const Teamcenter::Soa::Client::ModelObjectVector& get_epm_parentprocess();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_parent_task();
    const std::string& get_task_state();
    const std::string& get_task_result();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_responsible_party();
    const std::string& get_comments();
    const Teamcenter::Soa::Common::DateTime& get_due_date();
    bool get_late_flag();
    const std::string& get_fnd0SignoffDecision();
    const std::string& get_fnd0SignoffComments();
    const std::string& get_fnd0SignoffUserID();
    const std::string& get_fnd0SignoffGroupName();
    const std::string& get_fnd0SignoffRoleName();
    const std::string& get_fnd0ErrorMessage();
    int get_fnd0ErrorCode();
    const std::string& get_fnd0TargetAttachmentsSent();
    const std::string& get_fnd0EmailSubject();
    const std::string& get_fnd0DistributionList();
    const std::string& get_fnd0AssignedFrom();
    const std::string& get_fnd0ObjectDisplayName();
    const std::string& get_parent_taskDisp();
    const std::string& get_parent_processes();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0DepParentProcessTask();
    const std::string& get_fnd0SecondaryObjectType();
    const std::string& get_fnd0SecondaryObjectName();
    const std::string& get_fnd0SecondaryObjectID();
    const std::string& get_fnd0SecondaryObjectRevID();
    int get_fnd0SecondaryObjectSeqID();
    const std::string& get_fnd0SecondaryObjDispName();
    const std::string& get_fnd0SecondaryObjQualifier();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0SecondaryObject();
    int get_fnd0SequenceNumber();
    const std::string& get_fnd0ActualDurationDisplay();
    const std::string& get_fnd0Comments();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0WorkflowAudit")

   virtual ~Fnd0WorkflowAudit();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
