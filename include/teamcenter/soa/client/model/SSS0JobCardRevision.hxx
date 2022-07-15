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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SSS0JOBCARDREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SSS0JOBCARDREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/SSS0JobActivityRevision.hxx>

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


class TCSOASERVICESCHEDULINGMODELMNGD_API SSS0JobCardRevision : public Teamcenter::Soa::Client::Model::SSS0JobActivityRevision
{
public:
    Teamcenter::Soa::Common::AutoPtr<StructureContext> get_sss0upgradedConfiguration();
    const Teamcenter::Soa::Client::ModelObjectVector& get_SSS0WorkForAsset();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_sss0JobCardAsset();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMHasImpactedItem();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_sss0JobCardImpPart();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SSS0JobCardRevision")

   virtual ~SSS0JobCardRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServiceschedulingMngd_undef.h>
#endif
