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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SSS0SVCWORKORDERREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SSS0SVCWORKORDERREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Cm0GnWorkOrderRevision.hxx>

#include <teamcenter/soa/client/model/ServiceschedulingMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOASERVICESCHEDULINGMODELMNGD_API SSS0SvcWorkOrderRevision : public Teamcenter::Soa::Client::Model::Cm0GnWorkOrderRevision
{
public:
    int get_sss0actualElapsedTime();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_sss0WkOrdSchedule();
    const Teamcenter::Soa::Client::ModelObjectVector& get_SSS0WkOrderCustomerContact();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Sam0WorkPerformedAt();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_sss0WkOrdPhysLoc();
    const Teamcenter::Soa::Client::ModelObjectVector& get_SSS0WorkForAsset();
    const Teamcenter::Soa::Client::ModelObjectVector& get_sss0WkOrdAsset();
    const Teamcenter::Soa::Client::ModelObjectVector& get_sss0WkOrdCustContact();
    const Teamcenter::Soa::Client::ModelObjectVector& get_sss0WkOrdLocInCompany();
    const Teamcenter::Soa::Client::ModelObjectVector& get_SSS0RequestsPart();
    const Teamcenter::Soa::Client::ModelObjectVector& get_SSS0DiscrepancyDiscovered();
    const Teamcenter::Soa::Client::ModelObjectVector& get_sss0CorrectedDiscrepancy();
    const Teamcenter::Soa::Client::ModelObjectVector& get_sss0ChildTasks();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SSS0SvcWorkOrderRevision")

   virtual ~SSS0SvcWorkOrderRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServiceschedulingMngd_undef.h>
#endif
