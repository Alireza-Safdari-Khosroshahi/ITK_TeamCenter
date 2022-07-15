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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SCHEDULEMEMBER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SCHEDULEMEMBER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class POM_object;
                class Schedule;
                class CostValue;


class TCSOACLIENTMNGD_API ScheduleMember : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_resource_tag();
    int get_member_priv();
    Teamcenter::Soa::Common::AutoPtr<Schedule> get_schedule_as_member();
    Teamcenter::Soa::Common::AutoPtr<CostValue> get_costvalue_form_tag();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0ScheduleAuditLogs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ScheduleMember")

   virtual ~ScheduleMember();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
