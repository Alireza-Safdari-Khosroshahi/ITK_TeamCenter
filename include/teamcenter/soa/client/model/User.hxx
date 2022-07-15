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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_USER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_USER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_user.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ImanVolume;
                class Folder;
                class Folder;
                class Folder;
                class Person;
                class ImanVolume;
                class ResourcePool;
                class POMImc;
                class POMImc;


class TCSOACLIENTMNGD_API User : public Teamcenter::Soa::Client::Model::POM_user
{
public:
    Teamcenter::Soa::Common::AutoPtr<ImanVolume> get_volume();
    Teamcenter::Soa::Common::AutoPtr<Folder> get_mailbox();
    Teamcenter::Soa::Common::AutoPtr<Folder> get_home_folder();
    Teamcenter::Soa::Common::AutoPtr<Folder> get_newstuff_folder();
    Teamcenter::Soa::Common::AutoPtr<Person> get_person();
    const std::string& get_os_username();
    const std::string& get_ip_clearance();
    const std::string& get_geography();
    const std::string& get_nationality();
    const std::string& get_gov_clearance();
    const Teamcenter::Soa::Common::DateTime& get_ttc_date();
    Teamcenter::Soa::Common::AutoPtr<ImanVolume> get_local_volume();
    size_t count_fnd0ResourcePoolList();
    Teamcenter::Soa::Common::AutoPtr<ResourcePool> get_fnd0ResourcePoolList_at( size_t inx );
    const Teamcenter::Soa::Client::StringVector& get_fnd0citizenships();
    Teamcenter::Soa::Common::AutoPtr<POMImc> get_fnd0home_site();
    size_t count_fnd0remote_sites_deny_login();
    Teamcenter::Soa::Common::AutoPtr<POMImc> get_fnd0remote_sites_deny_login_at( size_t inx );
    const Teamcenter::Soa::Client::ModelObjectVector& get_subscribed_resourcepools();
    const Teamcenter::Soa::Client::ModelObjectVector& get_subscribed_remote_inboxes();
    const Teamcenter::Soa::Client::ModelObjectVector& get_surrogate_list();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_login_group();
    const Teamcenter::Soa::Client::ModelObjectVector& get_work_contexts();
    const std::string& get_userid();
    const Teamcenter::Soa::Client::ModelObjectVector& get_available_sites();
    const Teamcenter::Soa::Client::ModelObjectVector& get_remote_inboxes();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_userinbox();
    const Teamcenter::Soa::Client::ModelObjectVector& get_assignable_projects();
    const Teamcenter::Soa::Client::ModelObjectVector& get_priviledged_projects();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_inbox_delegate();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_TCCalendar_Rel_Type();
    bool get_is_member_of_dba();
    const Teamcenter::Soa::Client::ModelObjectVector& get_unsubscribed_remote_inboxes();
    const Teamcenter::Soa::Client::ModelObjectVector& get_my_home_folder();
    const Teamcenter::Soa::Client::ModelObjectVector& get_default_work_contexts();
    const Teamcenter::Soa::Client::ModelObjectVector& get_user_projects();
    const Teamcenter::Soa::Client::ModelObjectVector& get_subscribed_inboxes();
    bool get_is_valid_surrogate();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_taskinbox();
    bool get_is_out_of_office();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_CostValue_Relation();
    int get_fnd0usage_days();
    double get_fnd0used_hours();
    int get_fnd0grace_days();
    double get_fnd0grace_hours();
    const std::string& get_fnd0export_sites();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0OrganizationAuditLogs();
    const std::string& get_fnd0license_server();
    const Teamcenter::Soa::Client::StringVector& get_fnd0license_bundles();
    const std::string& get_fnd0vis_service_level();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("User")

   virtual ~User();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
