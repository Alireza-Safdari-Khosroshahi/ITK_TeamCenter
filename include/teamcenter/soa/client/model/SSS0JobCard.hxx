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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SSS0JOBCARD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SSS0JOBCARD_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/SSS0JobActivity.hxx>

#include <teamcenter/soa/client/model/ServiceschedulingMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class StructureContext;


class TCSOASERVICESCHEDULINGMODELMNGD_API SSS0JobCard : public Teamcenter::Soa::Client::Model::SSS0JobActivity
{
public:
    bool get_sss0isRebase();
    const Teamcenter::Soa::Client::ModelObjectVector& get_sss0ImpactedPart();
    Teamcenter::Soa::Common::AutoPtr<StructureContext> get_sss0upgradedConfiguration();
    const Teamcenter::Soa::Client::ModelObjectVector& get_sss0WorkForAsset();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SSS0JobCard")

   virtual ~SSS0JobCard();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServiceschedulingMngd_undef.h>
#endif
