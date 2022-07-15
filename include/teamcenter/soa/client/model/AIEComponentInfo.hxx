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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_AIECOMPONENTINFO_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_AIECOMPONENTINFO_HXX

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
                class AIEDatasetInfo;
                class ItemRevision;
                class PSBOMViewRevision;


class TCSOACLIENTMNGD_API AIEComponentInfo : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_bl_tag();
    const std::string& get_bl_name();
    const std::string& get_viewtype_name();
    int get_num_ds();
    size_t count_ds_refs();
    Teamcenter::Soa::Common::AutoPtr<AIEDatasetInfo> get_ds_refs_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_ir_ref();
    Teamcenter::Soa::Common::AutoPtr<PSBOMViewRevision> get_bvr_ref();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AIEComponentInfo")

   virtual ~AIEComponentInfo();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
