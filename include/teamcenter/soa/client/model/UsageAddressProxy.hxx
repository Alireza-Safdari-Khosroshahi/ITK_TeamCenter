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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_USAGEADDRESSPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_USAGEADDRESSPROXY_HXX

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


class TCSOACBAMODELMNGD_API UsageAddressProxy : public Teamcenter::Soa::Client::Model::TcUsageProxy
{
public:
    bool get_is_modifiable();
    const std::string& get_object_desc();
    const std::string& get_object_name();
    const std::string& get_checked_out();
    const std::string& get_last_mod_date();
    const std::string& get_object_type();
    const std::string& get_owning_group();
    const std::string& get_owning_user();
    const std::string& get_relation();
    const std::string& get_release_status_list();
    int get_cba0FUTURE_NUM_4_UUsageAddress();
    const std::string& get_cba0NOMATHREQUIREDINDICATOR_UUsageAddress();
    const std::string& get_cba0USAGEADDRESSTUID_UUsageAddress();
    const std::string& get_cba0USAGEADDRESSFAMILYTUID_UUsageAddress();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UUsageAddress();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UUsageAddress();
    const std::string& get_cba0USAGEADDRESS01_UUsageAddress();
    const std::string& get_cba0SLOC_UUsageAddress();
    const std::string& get_cba0USAGEADDRESS02_UUsageAddress();
    const std::string& get_cba0LASTMODIFIEDUSER_UUsageAddress();
    const std::string& get_cba0CREATIONUSER_UUsageAddress();
    const std::string& get_cba0FUTURE_TXT_1_UUsageAddress();
    const std::string& get_cba0USAGEADDRESS03_UUsageAddress();
    const std::string& get_cba0FUTURE_TXT_2_UUsageAddress();
    const std::string& get_cba0DEFAULTDESCRIPTION_UUsageAddress();
    const std::string& get_cba0USAGEADDRESS04_UUsageAddress();
    const std::string& get_cba0RECORDSTATE_UUsageAddress();
    const std::string& get_cba0FUTURE_TXT_3_UUsageAddress();
    const std::string& get_cba0DEFAULTLNG_UUsageAddress();
    const std::string& get_cba0USAGEADDRESS05_UUsageAddress();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("UsageAddressProxy")

   virtual ~UsageAddressProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
