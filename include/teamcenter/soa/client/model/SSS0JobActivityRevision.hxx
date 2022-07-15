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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SSS0JOBACTIVITYREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SSS0JOBACTIVITYREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0GnWOTaskRevision.hxx>

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


class TCSOASERVICESCHEDULINGMODELMNGD_API SSS0JobActivityRevision : public Teamcenter::Soa::Client::Model::Fnd0GnWOTaskRevision
{
public:
    bool get_sss0configUpdated();
    const std::string& get_sss0longDescription();
    size_t count_sss0partsMoved();
    Teamcenter::Soa::Common::AutoPtr<PartMovement> get_sss0partsMoved_at( size_t inx );
    int get_sss0actualElapsedTime();
    const Teamcenter::Soa::Client::ModelObjectVector& get_SSS0RequestsPart();
    const Teamcenter::Soa::Client::ModelObjectVector& get_SSS0SpecifiesCharToCapture();
    const Teamcenter::Soa::Client::ModelObjectVector& get_SSS0DiscrepancyDiscovered();
    const Teamcenter::Soa::Client::ModelObjectVector& get_SSS0ResultingInformation();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SSS0JobActivityRevision")

   virtual ~SSS0JobActivityRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServiceschedulingMngd_undef.h>
#endif
