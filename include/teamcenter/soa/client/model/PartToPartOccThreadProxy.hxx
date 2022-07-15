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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PARTTOPARTOCCTHREADPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PARTTOPARTOCCTHREADPROXY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/TcUsageProxy.hxx>

#include <teamcenter/soa/client/model/CbaMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACBAMODELMNGD_API PartToPartOccThreadProxy : public Teamcenter::Soa::Client::Model::TcUsageProxy
{
public:
    const std::string& get_last_mod_date();
    const std::string& get_relation();
    const std::string& get_owning_group();
    const std::string& get_object_desc();
    bool get_is_modifiable();
    const std::string& get_checked_out();
    const std::string& get_object_type();
    const std::string& get_owning_user();
    const std::string& get_release_status_list();
    const std::string& get_object_name();
    const std::string& get_cba0P2POCCTHREADTUID_UP2POccThread();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UP2POccThread();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UP2POccThread();
    const std::string& get_cba0SLOC_UP2POccThread();
    const std::string& get_cba0LASTMODIFIEDUSER_UP2POccThread();
    const std::string& get_cba0CREATIONUSER_UP2POccThread();
    const std::string& get_cba0THREADTUID_UP2POccThread();
    const std::string& get_cba0THREADDESCRIPTION_UP2POccThread();
    const std::string& get_cba0RECORDSTATE_UP2POccThread();
    const std::string& get_cba0RECORDGROUPTUID_UP2POccThread();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PartToPartOccThreadProxy")

   virtual ~PartToPartOccThreadProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
