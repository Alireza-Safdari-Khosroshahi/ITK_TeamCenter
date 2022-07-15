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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_POSITIONDESIGNATORPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_POSITIONDESIGNATORPROXY_HXX

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


class TCSOACBAMODELMNGD_API PositionDesignatorProxy : public Teamcenter::Soa::Client::Model::TcUsageProxy
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
    const std::string& get_cba0MASTERPDTUID_UPositionDesignator();
    const std::string& get_cba0USAGEADDRESS01_UMasterPositionDesignator();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UMasterPositionDesignator();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UMasterPositionDesignator();
    const std::string& get_cba0SLOC_UMasterPositionDesignator();
    const std::string& get_cba0CREATIONUSER_UMasterPositionDesignator();
    const std::string& get_cba0LASTMODIFIEDUSER_UMasterPositionDesignator();
    const std::string& get_cba0POSITIONDESIGNATORTUID_UPositionDesignator();
    const std::string& get_cba0SLOC_UPositionDesignator();
    const std::string& get_cba0SYSTEMGENERATED_UMasterPositionDesignator();
    const std::string& get_cba0DEFAULTLNG_UMasterPositionDesignator();
    const std::string& get_cba0RECORDSTATE_UPositionDesignator();
    const std::string& get_cba0MASTERPOSITIONDESIGNATORTUID_UMasterPositionDesignator();
    const std::string& get_cba0RECORDGROUPTUID_UPositionDesignator();
    const std::string& get_cba0DESCRIPTION_UMasterPositionDesignator();
    const std::string& get_cba0USAGEADDRESS02_UMasterPositionDesignator();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UPositionDesignator();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UPositionDesignator();
    const std::string& get_cba0RECORDGROUPITEMTUID_UPositionDesignator();
    const std::string& get_cba0RECORDSTATE_UMasterPositionDesignator();
    const std::string& get_cba0CREATIONUSER_UPositionDesignator();
    const std::string& get_cba0LASTMODIFIEDUSER_UPositionDesignator();
    const std::string& get_cba0DEFAULTSHORTDESCRIPTION_UMasterPositionDesignator();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PositionDesignatorProxy")

   virtual ~PositionDesignatorProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
