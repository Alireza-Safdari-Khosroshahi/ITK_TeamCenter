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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_AIEEXPORTASSEMBLY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_AIEEXPORTASSEMBLY_HXX

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
                class AIEExportNode;
                class AIEExportNode;
                class DatasetType;


class TCSOACLIENTMNGD_API AIEExportAssembly : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_bw_ref();
    bool get_co_root();
    int get_num_dstypes();
    const std::string& get_primary_filespec();
    const std::string& get_primary_path();
    Teamcenter::Soa::Common::AutoPtr<Dataset> get_root_ds_ref();
    Teamcenter::Soa::Common::AutoPtr<AIEExportNode> get_toplevel_ref();
    size_t count_node_refs();
    Teamcenter::Soa::Common::AutoPtr<AIEExportNode> get_node_refs_at( size_t inx );
    size_t count_dstype_refs();
    Teamcenter::Soa::Common::AutoPtr<DatasetType> get_dstype_refs_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AIEExportAssembly")

   virtual ~AIEExportAssembly();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
