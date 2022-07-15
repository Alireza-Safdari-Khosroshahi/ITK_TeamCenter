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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IMANRESERVATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IMANRESERVATION_HXX

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
                class WorkspaceObject;
                class Group;
                class User;
                class User;
                class POMImc;


class TCSOACLIENTMNGD_API ImanReservation : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_reason();
    const Teamcenter::Soa::Common::DateTime& get_date();
    const std::string& get_change_id();
    int get_reservation_state();
    int get_reservation_type();
    const std::string& get_export_dir_name();
    const Teamcenter::Soa::Client::StringVector& get_exported_fname_list();
    const Teamcenter::Soa::Client::StringVector& get_exported_time_stamp_list();
    const std::string& get_remote_user();
    const std::string& get_remote_group();
    Teamcenter::Soa::Common::AutoPtr<WorkspaceObject> get_object_restore_ptr();
    bool get_site_reserved();
    Teamcenter::Soa::Common::AutoPtr<Group> get_group_object();
    Teamcenter::Soa::Common::AutoPtr<User> get_user_object();
    size_t count_notification_list();
    Teamcenter::Soa::Common::AutoPtr<User> get_notification_list_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<POMImc> get_remote_site();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImanReservation")

   virtual ~ImanReservation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
