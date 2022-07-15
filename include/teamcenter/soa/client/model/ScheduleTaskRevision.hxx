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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SCHEDULETASKREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SCHEDULETASKREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ScheduleTask;
                class User;


class TCSOACLIENTMNGD_API ScheduleTaskRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    int get_priority();
    int get_fixed_type();
    bool get_auto_complete();
    int get_task_type();
    int get_constraint();
    size_t count_child_task_taglist();
    Teamcenter::Soa::Common::AutoPtr<ScheduleTask> get_child_task_taglist_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_privileged_user();
    Teamcenter::Soa::Common::AutoPtr<User> get_fnd0workflow_owner();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_TaskExecution_Form_RType();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_TaskScheduling_Form_RType();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_TaskCost_Form_RType();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ResourceAssignment();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ScheduleTaskRevision")

   virtual ~ScheduleTaskRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
