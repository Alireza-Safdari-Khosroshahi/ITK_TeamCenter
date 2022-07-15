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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SINGLEFILERECOVERY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SINGLEFILERECOVERY_HXX

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
                class SFRInfo;


class TCSOACLIENTMNGD_API SingleFileRecovery : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_object_name();
    int get_revision_number();
    const std::string& get_object_type();
    const std::string& get_object_owning_user();
    const std::string& get_object_owning_group();
    const Teamcenter::Soa::Common::DateTime& get_last_mod_date();
    const std::string& get_revision_anchor_uid();
    const std::string& get_primary_filename();
    const Teamcenter::Soa::Client::StringVector& get_object_form_types();
    const Teamcenter::Soa::Client::StringVector& get_volume_paths();
    const Teamcenter::Soa::Client::StringVector& get_ref_list();
    const Teamcenter::Soa::Client::StringVector& get_ref_names();
    Teamcenter::Soa::Common::AutoPtr<SFRInfo> get_sfr_info();
    const Teamcenter::Soa::Common::DateTime& get_sfr_info_backup_time_stamp();
    const std::string& get_sfr_info_backup_label();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SingleFileRecovery")

   virtual ~SingleFileRecovery();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
