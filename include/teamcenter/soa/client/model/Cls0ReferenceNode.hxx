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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CLS0REFERENCENODE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CLS0REFERENCENODE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Cls0HierarchyNode.hxx>

#include <teamcenter/soa/client/model/ClassificationMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Cls0HierarchyNode;


class TCSOACLASSIFICATIONMODELMNGD_API Cls0ReferenceNode : public Teamcenter::Soa::Client::Model::Cls0HierarchyNode
{
public:
    Teamcenter::Soa::Common::AutoPtr<Cls0HierarchyNode> get_cls0master_node();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cls0ReferenceNode")

   virtual ~Cls0ReferenceNode();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ClassificationMngd_undef.h>
#endif
