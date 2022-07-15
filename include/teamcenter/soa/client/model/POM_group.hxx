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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_POM_GROUP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_POM_GROUP_HXX

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


class TCSOACLIENTMNGD_API POM_group : public Teamcenter::Soa::Client::Model::POM_system_class
{
public:
    const std::string& get_name();
    int get_privilege();
    Teamcenter::Soa::Common::AutoPtr<POM_group> get_parent();
    const Teamcenter::Soa::Common::DateTime& get_group_last_sync_date();
    int get_group_data_source();
    const std::string& get_display_name();
    const std::string& get_full_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("POM_group")

   virtual ~POM_group();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
