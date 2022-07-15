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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_POM_APPLICATION_OBJECT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_POM_APPLICATION_OBJECT_HXX

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
                class POM_system_class;
                class POM_system_class;
                class POM_system_class;


class TCSOACLIENTMNGD_API POM_application_object : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_archive_info();
    int get_acl_bits();
    const Teamcenter::Soa::Common::DateTime& get_creation_date();
    const Teamcenter::Soa::Common::DateTime& get_archive_date();
    const Teamcenter::Soa::Common::DateTime& get_last_mod_date();
    const Teamcenter::Soa::Common::DateTime& get_backup_date();
    Teamcenter::Soa::Common::AutoPtr<POM_system_class> get_owning_group();
    Teamcenter::Soa::Common::AutoPtr<POM_system_class> get_last_mod_user();
    Teamcenter::Soa::Common::AutoPtr<POM_system_class> get_owning_user();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("POM_application_object")

   virtual ~POM_application_object();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
