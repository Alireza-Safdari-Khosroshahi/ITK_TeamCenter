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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CLS0MASTERNODE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CLS0MASTERNODE_HXX

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


class TCSOACLASSIFICATIONMODELMNGD_API Cls0MasterNode : public Teamcenter::Soa::Client::Model::Cls0HierarchyNode
{
public:
    const std::string& get_cls0class_type_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cls0MasterNode")

   virtual ~Cls0MasterNode();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ClassificationMngd_undef.h>
#endif
