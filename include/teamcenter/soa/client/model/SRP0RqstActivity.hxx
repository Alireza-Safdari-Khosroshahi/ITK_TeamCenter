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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SRP0RQSTACTIVITY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SRP0RQSTACTIVITY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/SRP0GnSrvRequest.hxx>

#include <teamcenter/soa/client/model/ServicerequestMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOASERVICEREQUESTMODELMNGD_API SRP0RqstActivity : public Teamcenter::Soa::Client::Model::SRP0GnSrvRequest
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_SRP0ActivityOffering();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SRP0RqstActivity")

   virtual ~SRP0RqstActivity();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServicerequestMngd_undef.h>
#endif
