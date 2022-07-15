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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TIMESHEETENTRY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TIMESHEETENTRY_HXX

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
                class BillRate;
                class ScheduleTask;
                class User;


class TCSOACLIENTMNGD_API TimeSheetEntry : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const Teamcenter::Soa::Common::DateTime& get_date();
    int get_minutes();
    Teamcenter::Soa::Common::AutoPtr<BillRate> get_billrate_tag();
    const std::string& get_bill_code();
    const std::string& get_bill_sub_code();
    const std::string& get_bill_type();
    Teamcenter::Soa::Common::AutoPtr<ScheduleTask> get_scheduletask_tag();
    const std::string& get_time_category();
    Teamcenter::Soa::Common::AutoPtr<User> get_user_tag();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TimeSheetEntry")

   virtual ~TimeSheetEntry();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
