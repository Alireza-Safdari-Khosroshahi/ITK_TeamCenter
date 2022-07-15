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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PROXYLINKENG_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PROXYLINKENG_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ProxyLink.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API ProxyLinkEng : public Teamcenter::Soa::Client::Model::ProxyLink
{
public:
    const std::string& get_obj_id();
    const std::string& get_obj_type();
    const std::string& get_owner_name();
    const std::string& get_owning_group();
    const Teamcenter::Soa::Common::DateTime& get_create_date();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ProxyLinkEng")

   virtual ~ProxyLinkEng();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
