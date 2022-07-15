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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TC_PROJECT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TC_PROJECT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ProjectTeam;


class TCSOACLIENTMNGD_API TC_Project : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    bool get_is_active();
    const std::string& get_project_id();
    const std::string& get_project_name();
    const std::string& get_project_desc();
    Teamcenter::Soa::Common::AutoPtr<ProjectTeam> get_project_team();
    bool get_is_visible();
    bool get_use_program_security();
    const Teamcenter::Soa::Client::ModelObjectVector& get_project_data();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_am_tree();
    const std::string& get_object_desc();
    const std::string& get_object_name();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Program_Preferred_Items();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0LibraryForProject();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0OrganizationAuditLogs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TC_Project")

   virtual ~TC_Project();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
