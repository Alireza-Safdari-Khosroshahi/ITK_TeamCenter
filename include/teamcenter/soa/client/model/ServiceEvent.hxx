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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SERVICEEVENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SERVICEEVENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ServicePerformed.hxx>

#include <teamcenter/soa/client/model/ServiceeventmanagementMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOASERVICEEVENTMANAGEMENTMODELMNGD_API ServiceEvent : public Teamcenter::Soa::Client::Model::ServicePerformed
{
public:
    const std::string& get_work_location();
    const std::string& get_job_cards();
    const std::string& get_signed_off_by();
    const std::string& get_zones();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ServiceEvent")

   virtual ~ServiceEvent();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServiceeventmanagementMngd_undef.h>
#endif
