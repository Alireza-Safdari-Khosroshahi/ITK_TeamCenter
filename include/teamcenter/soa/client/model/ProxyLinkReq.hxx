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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PROXYLINKREQ_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PROXYLINKREQ_HXX

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


class TCSOACLIENTMNGD_API ProxyLinkReq : public Teamcenter::Soa::Client::Model::ProxyLink
{
public:
    const std::string& get_obj_id_num();
    const std::string& get_obj_id_num_list();
    const std::string& get_last_mod_user();
    const Teamcenter::Soa::Common::DateTime& get_last_mod_date();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ProxyLinkReq")

   virtual ~ProxyLinkReq();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
