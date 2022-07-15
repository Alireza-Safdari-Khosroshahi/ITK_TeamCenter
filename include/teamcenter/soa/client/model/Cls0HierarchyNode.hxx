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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CLS0HIERARCHYNODE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CLS0HIERARCHYNODE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Ptn0Partition.hxx>

#include <teamcenter/soa/client/model/ClassificationMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Cls0HierarchyView;


class TCSOACLASSIFICATIONMODELMNGD_API Cls0HierarchyNode : public Teamcenter::Soa::Client::Model::Ptn0Partition
{
public:
    Teamcenter::Soa::Common::AutoPtr<Cls0HierarchyView> get_cls0hierarchy_view();
    int get_cls0level_sort_index();
    bool get_cls0is_leaf_node();
    const Teamcenter::Soa::Client::StringVector& get_cls0ancestors();
    bool get_cls0is_abstract();
    bool get_cls0multiple_classification();
    bool get_cls0filter_by_read_access();
    bool get_cls0is_assembly();
    int get_cls0instance_count();
    int get_cls0child_count();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cls0HierarchyNode")

   virtual ~Cls0HierarchyNode();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ClassificationMngd_undef.h>
#endif
