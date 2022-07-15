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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0CLIENTSESSIONINFO_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0CLIENTSESSIONINFO_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Fnd0ClientSessionInfo : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_fnd0user_id();
    const std::string& get_fnd0current_ip();
    const std::string& get_fnd0last_ip();
    const Teamcenter::Soa::Common::DateTime& get_fnd0last_start_time();
    const Teamcenter::Soa::Common::DateTime& get_fnd0current_start_time();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0ClientSessionInfo")

   virtual ~Fnd0ClientSessionInfo();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
