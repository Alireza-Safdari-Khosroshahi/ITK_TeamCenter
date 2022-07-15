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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SCHDELIVERABLE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SCHDELIVERABLE_HXX

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
                class WorkspaceObject;


class TCSOACLIENTMNGD_API SchDeliverable : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<WorkspaceObject> get_deliverable_inst();
    const std::string& get_deliverable_name();
    const std::string& get_deliverable_type();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_schedule();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0ScheduleAuditLogs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SchDeliverable")

   virtual ~SchDeliverable();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
