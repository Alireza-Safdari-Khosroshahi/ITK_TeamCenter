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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MUGPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MUGPROXY_HXX

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


class TCSOACBAMODELMNGD_API MUGProxy : public Teamcenter::Soa::Client::Model::TcUsageProxy
{
public:
    bool get_is_modifiable();
    const std::string& get_object_desc();
    const std::string& get_object_name();
    const std::string& get_checked_out();
    const std::string& get_last_mod_date();
    const std::string& get_object_type();
    const std::string& get_owning_user();
    const std::string& get_owning_group();
    const std::string& get_relation();
    const std::string& get_release_status_list();
    const std::string& get_cba0SLOC_UMUG();
    const std::string& get_cba0MUG02_UMUG();
    const std::string& get_cba0RECORDSTATE_UMUG();
    const std::string& get_cba0MUGTUID_UMUG();
    const std::string& get_cba0LASTMODIFIEDUSER_UMUG();
    const std::string& get_cba0CREATIONUSER_UMUG();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UMUG();
    const std::string& get_cba0MUG01_UMUG();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UMUG();
    const std::string& get_cba0CONFIGLANGUAGE_UMUG();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MUGProxy")

   virtual ~MUGProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
