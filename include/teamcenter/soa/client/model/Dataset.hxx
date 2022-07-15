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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DATASET_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DATASET_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class DatasetType;
                class RevisionAnchor;
                class Tool;
                class Tool;


class TCSOACLIENTMNGD_API Dataset : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_ref_list();
    const Teamcenter::Soa::Client::StringVector& get_ref_names();
    const Teamcenter::Soa::Client::IntVector& get_ref_types();
    const std::string& get_format_used();
    const std::string& get_user_class();
    bool get_system_managed();
    const std::string& get_local_path();
    const std::string& get_markup_acl();
    bool get_markup_official();
    const std::string& get_markup_status();
    const Teamcenter::Soa::Client::StringVector& get_fnd0InstanceAttrExMappings();
    bool get_fnd0IsSignable();
    Teamcenter::Soa::Common::AutoPtr<DatasetType> get_dataset_type();
    Teamcenter::Soa::Common::AutoPtr<RevisionAnchor> get_rev_chain_anchor();
    Teamcenter::Soa::Common::AutoPtr<Tool> get_tool_used();
    Teamcenter::Soa::Common::AutoPtr<Tool> get_markup_create_tool();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_external_object_link();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_Rendering();
    const std::string& get_pubr_object_id();
    const std::string& get_rev();
    int get_keep_limit_prop();
    int get_highest_rev_prop();
    const Teamcenter::Soa::Client::ModelObjectVector& get_revisions_prop();
    const std::string& get_rev_prop();
    const std::string& get_id_prop();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0FileAccessAuditLogs();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DgtSignatureByUserRelation();
    bool get_fnd0IsCheckOutForSign();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Dataset")

   virtual ~Dataset();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
