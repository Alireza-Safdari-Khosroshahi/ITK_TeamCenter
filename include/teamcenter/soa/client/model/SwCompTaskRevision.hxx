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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SWCOMPTASKREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SWCOMPTASKREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ScheduleTaskRevision.hxx>

#include <teamcenter/soa/client/model/ScdtMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOASCDTMODELMNGD_API SwCompTaskRevision : public Teamcenter::Soa::Client::Model::ScheduleTaskRevision
{
public:
    const std::string& get_integration_branch();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SwCompTaskRevision")

   virtual ~SwCompTaskRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ScdtMngd_undef.h>
#endif
