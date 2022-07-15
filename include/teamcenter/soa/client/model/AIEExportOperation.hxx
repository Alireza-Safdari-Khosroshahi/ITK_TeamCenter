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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_AIEEXPORTOPERATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_AIEEXPORTOPERATION_HXX

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
                class Dataset;
                class AIEPersistentConnection;
                class AIEExportAssembly;
                class VariantRule;
                class RevisionRule;


class TCSOACLIENTMNGD_API AIEExportOperation : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_conn_dir_name();
    int get_export_rule();
    const std::string& get_export_msg();
    const std::string& get_co_msg();
    const std::string& get_change_id();
    const std::string& get_reason();
    int get_num_assemblies();
    const std::string& get_tool_name();
    const std::string& get_logfile_name();
    int get_num_ds();
    size_t count_ds_refs();
    Teamcenter::Soa::Common::AutoPtr<Dataset> get_ds_refs_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<AIEPersistentConnection> get_conn_ref();
    size_t count_assembly_refs();
    Teamcenter::Soa::Common::AutoPtr<AIEExportAssembly> get_assembly_refs_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<VariantRule> get_variantrule_ref();
    Teamcenter::Soa::Common::AutoPtr<RevisionRule> get_revrule_ref();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AIEExportOperation")

   virtual ~AIEExportOperation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
