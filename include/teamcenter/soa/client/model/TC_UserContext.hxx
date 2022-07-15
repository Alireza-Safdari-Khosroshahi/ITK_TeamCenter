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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TC_USERCONTEXT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TC_USERCONTEXT_HXX

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
                class Group;
                class User;
                class Project;


class TCSOACLIENTMNGD_API TC_UserContext : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_fnd0LocationCodePref();
    Teamcenter::Soa::Common::AutoPtr<Group> get_Fnd0current_organization();
    Teamcenter::Soa::Common::AutoPtr<User> get_user();
    Teamcenter::Soa::Common::AutoPtr<Project> get_current_project();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TC_UserContext")

   virtual ~TC_UserContext();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
