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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_GROUP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_GROUP_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_group.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Role;
                class Discipline;
                class ImanVolume;
                class ImanVolume;


class TCSOACLIENTMNGD_API Group : public Teamcenter::Soa::Client::Model::POM_group
{
public:
    size_t count_list_of_role();
    Teamcenter::Soa::Common::AutoPtr<Role> get_list_of_role_at( size_t inx );
    size_t count_list_of_discipline();
    Teamcenter::Soa::Common::AutoPtr<Discipline> get_list_of_discipline_at( size_t inx );
    const std::string& get_description();
    Teamcenter::Soa::Common::AutoPtr<ImanVolume> get_volume();
    const std::string& get_security();
    const std::string& get_organization_name();
    const std::string& get_organization_id();
    const std::string& get_organization_type();
    const std::string& get_organization_legal_name();
    const std::string& get_organization_alternate_name();
    const std::string& get_organization_address();
    const std::string& get_organization_url();
    int get_operational_status();
    const std::string& get_nationality();
    Teamcenter::Soa::Common::AutoPtr<ImanVolume> get_local_volume();
    const std::string& get_object_name();
    const Teamcenter::Soa::Client::ModelObjectVector& get_roles();
    const std::string& get_object_full_name();
    const std::string& get_fnd0export_sites();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0OrganizationAuditLogs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Group")

   virtual ~Group();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
