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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IMANFILE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IMANFILE_HXX

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
                class ImanVolume;
                class ImanVolume;
                class HSM_Info;
                class VM_Info;


class TCSOACLIENTMNGD_API ImanFile : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_file_name();
    const std::string& get_sd_path_name();
    int get_translate();
    int get_text_flag();
    int get_machine_type();
    int get_status_flag();
    int get_time_last_modified();
    Teamcenter::Soa::Common::AutoPtr<ImanFile> get_released_version();
    const std::string& get_original_file_name();
    const std::string& get_relative_directory_path();
    bool get_store_and_forward_flag();
    Teamcenter::Soa::Common::AutoPtr<ImanVolume> get_volume_tag();
    Teamcenter::Soa::Common::AutoPtr<ImanVolume> get_destination_volume_tag();
    Teamcenter::Soa::Common::AutoPtr<HSM_Info> get_hsm_info();
    Teamcenter::Soa::Common::AutoPtr<VM_Info> get_vm_info();
    const std::string& get_file_size();
    const std::string& get_file_ext();
    const std::string& get_byte_size();
    const std::string& get_mime_type();
    const std::string& get_object_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImanFile")

   virtual ~ImanFile();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
