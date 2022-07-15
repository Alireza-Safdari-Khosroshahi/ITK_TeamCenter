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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_RESOURCEPOOL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_RESOURCEPOOL_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_system_class.hxx>

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


class TCSOACLIENTMNGD_API ResourcePool : public Teamcenter::Soa::Client::Model::POM_system_class
{
public:
    Teamcenter::Soa::Common::AutoPtr<Role> get_role();
    bool get_all_members();
    Teamcenter::Soa::Common::AutoPtr<Group> get_group();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ResourcePool")

   virtual ~ResourcePool();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
