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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CM0ACTIONITEMREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CM0ACTIONITEMREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ProblemReportRevision.hxx>

#include <teamcenter/soa/client/model/CmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMMODELMNGD_API Cm0ActionItemRevision : public Teamcenter::Soa::Client::Model::ProblemReportRevision
{
public:
    const std::string& get_cm0Comments();
    const std::string& get_cm0OfficePriResp();
    const Teamcenter::Soa::Client::StringVector& get_cm0Zones();
    const Teamcenter::Soa::Client::ModelObjectVector& get_cm0RaisedByAudit();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cm0ActionItemRevision")

   virtual ~Cm0ActionItemRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmMngd_undef.h>
#endif
