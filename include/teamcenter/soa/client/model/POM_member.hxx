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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_POM_MEMBER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_POM_MEMBER_HXX

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
                class POM_user;
                class POM_group;


class TCSOACLIENTMNGD_API POM_member : public Teamcenter::Soa::Client::Model::POM_system_class
{
public:
    bool get_ga();
    const Teamcenter::Soa::Common::DateTime& get_membership_last_sync_date();
    int get_membership_data_source();
    Teamcenter::Soa::Common::AutoPtr<POM_user> get_user();
    Teamcenter::Soa::Common::AutoPtr<POM_group> get_group();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("POM_member")

   virtual ~POM_member();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
