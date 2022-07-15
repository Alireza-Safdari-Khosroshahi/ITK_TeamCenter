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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EPMSIGNOFFPROFILE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EPMSIGNOFFPROFILE_HXX

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
                class Role;
                class Group;


class TCSOACLIENTMNGD_API EPMSignoffProfile : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    bool get_allow_subgroups();
    int get_number_of_signoffs();
    int get_signoff_quorum();
    Teamcenter::Soa::Common::AutoPtr<Role> get_role();
    Teamcenter::Soa::Common::AutoPtr<Group> get_group();
    const std::string& get_role_name();
    const std::string& get_group_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EPMSignoffProfile")

   virtual ~EPMSignoffProfile();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
