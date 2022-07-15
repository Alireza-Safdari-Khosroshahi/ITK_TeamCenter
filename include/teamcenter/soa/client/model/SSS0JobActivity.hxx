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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SSS0JOBACTIVITY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SSS0JOBACTIVITY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0GnWOTask.hxx>

#include <teamcenter/soa/client/model/ServiceschedulingMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class PartMovement;


class TCSOASERVICESCHEDULINGMODELMNGD_API SSS0JobActivity : public Teamcenter::Soa::Client::Model::Fnd0GnWOTask
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_sss0CorrectedDiscrepancy();
    const Teamcenter::Soa::Client::ModelObjectVector& get_sss0Utilization();
    bool get_sss0configUpdated();
    const Teamcenter::Soa::Client::ModelObjectVector& get_sss0DiscrepancyDiscovered();
    const std::string& get_sss0longDescription();
    size_t count_sss0PartsMoved();
    Teamcenter::Soa::Common::AutoPtr<PartMovement> get_sss0PartsMoved_at( size_t inx );
    const Teamcenter::Soa::Client::ModelObjectVector& get_sss0RequestsPart();
    const Teamcenter::Soa::Client::ModelObjectVector& get_sss0ResultingInformation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_sss0SpecifiesCharToCapture();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SSS0JobActivity")

   virtual ~SSS0JobActivity();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServiceschedulingMngd_undef.h>
#endif
