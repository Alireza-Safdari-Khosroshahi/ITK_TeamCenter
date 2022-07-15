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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PTN0PARTITIONREALIZATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PTN0PARTITIONREALIZATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Rlz0ModelRealization.hxx>

#include <teamcenter/soa/client/model/PartitionMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAPARTITIONMODELMNGD_API Ptn0PartitionRealization : public Teamcenter::Soa::Client::Model::Rlz0ModelRealization
{
public:
    bool get_ptn0sync_child_partitions();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Ptn0PartitionRealization")

   virtual ~Ptn0PartitionRealization();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PartitionMngd_undef.h>
#endif
