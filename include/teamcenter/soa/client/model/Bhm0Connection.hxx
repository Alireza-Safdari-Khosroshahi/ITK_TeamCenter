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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_BHM0CONNECTION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_BHM0CONNECTION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/PSConnection.hxx>

#include <teamcenter/soa/client/model/BehaviormodelingMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOABEHAVIORMODELINGMODELMNGD_API Bhm0Connection : public Teamcenter::Soa::Client::Model::PSConnection
{
public:
    const std::string& get_bhm0Application();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Bhm0Connection")

   virtual ~Bhm0Connection();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/BehaviormodelingMngd_undef.h>
#endif
