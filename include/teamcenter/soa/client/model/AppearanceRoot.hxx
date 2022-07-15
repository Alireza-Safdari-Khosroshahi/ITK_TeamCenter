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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPEARANCEROOT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPEARANCEROOT_HXX

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
                class AppearanceConfigContext;
                class AppearanceTrackedItemInfo;
                class ApprUpdChangePkg;


class TCSOACLIENTMNGD_API AppearanceRoot : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<AppearanceConfigContext> get_config_context();
    Teamcenter::Soa::Common::AutoPtr<AppearanceTrackedItemInfo> get_tracked_item_info();
    bool get_has_spatial_data();
    bool get_is_for_pre_release();
    int get_corruption_status();
    const Teamcenter::Soa::Common::DateTime& get_ok_date();
    bool get_is_active();
    bool get_is_available();
    const Teamcenter::Soa::Common::DateTime& get_last_fix_date();
    const Teamcenter::Soa::Common::DateTime& get_last_check_date();
    Teamcenter::Soa::Common::AutoPtr<ApprUpdChangePkg> get_last_aucp();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_owning_group();
    const std::string& get_object_desc();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_owning_user();
    const std::string& get_object_id();
    const std::string& get_object_name();
    const std::string& get_description();
    const std::string& get_pubr_object_id();
    bool get_is_published();
    const Teamcenter::Soa::Common::DateTime& get_creation_date();
    const std::string& get_object_type();
    int get_num_appearances();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AppearanceRoot")

   virtual ~AppearanceRoot();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
