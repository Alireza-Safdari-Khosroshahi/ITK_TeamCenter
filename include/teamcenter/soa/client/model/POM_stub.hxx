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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_POM_STUB_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_POM_STUB_HXX

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
                class POM_data_manager;


class TCSOACLIENTMNGD_API POM_stub : public Teamcenter::Soa::Client::Model::POM_system_class
{
public:
    const std::string& get_object_uid();
    const std::string& get_object_class();
    const std::string& get_object_id();
    const std::string& get_object_name();
    const std::string& get_object_type();
    const std::string& get_object_desc();
    Teamcenter::Soa::Common::AutoPtr<POM_data_manager> get_definitive();
    int get_status_flag();
    int get_time_last_modified();
    int get_text_flag();
    const std::string& get_volume_guid();
    const std::string& get_relative_file_path();
    const std::string& get_owning_user_id();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("POM_stub")

   virtual ~POM_stub();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
