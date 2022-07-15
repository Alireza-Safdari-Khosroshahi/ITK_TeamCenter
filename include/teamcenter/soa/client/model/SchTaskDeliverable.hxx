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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SCHTASKDELIVERABLE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SCHTASKDELIVERABLE_HXX

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
                class SchDeliverable;


class TCSOACLIENTMNGD_API SchTaskDeliverable : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    int get_submit_type();
    Teamcenter::Soa::Common::AutoPtr<SchDeliverable> get_schedule_deliverable();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_schedule_task();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0ScheduleAuditLogs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SchTaskDeliverable")

   virtual ~SchTaskDeliverable();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
