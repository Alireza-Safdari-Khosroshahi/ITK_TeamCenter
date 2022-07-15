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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SSS0JOBTASKREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SSS0JOBTASKREVISION_HXX

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


class TCSOASERVICESCHEDULINGMODELMNGD_API SSS0JobTaskRevision : public Teamcenter::Soa::Client::Model::SSS0JobActivityRevision
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_sss0impactedPhysicalPart();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_sss0workForAsset();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SSS0JobTaskRevision")

   virtual ~SSS0JobTaskRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServiceschedulingMngd_undef.h>
#endif
