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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SRP0SRVREQUESTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SRP0SRVREQUESTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/SRP0GnSrvRequestRevision.hxx>

#include <teamcenter/soa/client/model/ServicerequestMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOASERVICEREQUESTMODELMNGD_API SRP0SrvRequestRevision : public Teamcenter::Soa::Client::Model::SRP0GnSrvRequestRevision
{
public:
    const Teamcenter::Soa::Common::DateTime& get_SRP0InitiationDate();
    const std::string& get_SRP0Purpose();
    const Teamcenter::Soa::Client::ModelObjectVector& get_SRP0CustomerContact();
    const Teamcenter::Soa::Client::ModelObjectVector& get_SRP0Performs();
    const Teamcenter::Soa::Client::ModelObjectVector& get_srp0PhysicalElements();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_srp0CustContact();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_srp0CustLocation();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SRP0SrvRequestRevision")

   virtual ~SRP0SrvRequestRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServicerequestMngd_undef.h>
#endif
