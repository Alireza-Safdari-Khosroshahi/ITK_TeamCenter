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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TC_WORKCONTEXT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TC_WORKCONTEXT_HXX

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
                class Role;
                class Project;
                class User;
                class Group;


class TCSOACLIENTMNGD_API TC_WorkContext : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_workcontext_name();
    const std::string& get_workcontext_desc();
    Teamcenter::Soa::Common::AutoPtr<Role> get_role();
    Teamcenter::Soa::Common::AutoPtr<Project> get_project();
    bool get_allow_subgroups();
    bool get_setting_modifiable();
    Teamcenter::Soa::Common::AutoPtr<User> get_user();
    Teamcenter::Soa::Common::AutoPtr<Group> get_group();
    const Teamcenter::Soa::Client::ModelObjectVector& get_loginuser_groupmembers();
    const std::string& get_object_desc();
    const std::string& get_object_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TC_WorkContext")

   virtual ~TC_WorkContext();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
