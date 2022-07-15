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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_AIEEXPORTNODE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_AIEEXPORTNODE_HXX

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
                class AIEComponentInfo;


class TCSOACLIENTMNGD_API AIEExportNode : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_export_comp();
    int get_export_children();
    int get_co_comp();
    int get_co_children();
    bool get_expanded();
    const std::string& get_owning_assy_ref();
    int get_num_children();
    const Teamcenter::Soa::Client::ModelObjectVector& get_child_refs();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_parent_ref();
    Teamcenter::Soa::Common::AutoPtr<AIEComponentInfo> get_comp_ref();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AIEExportNode")

   virtual ~AIEExportNode();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
