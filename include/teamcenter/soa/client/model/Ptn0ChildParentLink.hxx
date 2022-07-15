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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PTN0CHILDPARENTLINK_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PTN0CHILDPARENTLINK_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Ptn0PartitionLink.hxx>

#include <teamcenter/soa/client/model/PartitionMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Ptn0Partition;


class TCSOAPARTITIONMODELMNGD_API Ptn0ChildParentLink : public Teamcenter::Soa::Client::Model::Ptn0PartitionLink
{
public:
    Teamcenter::Soa::Common::AutoPtr<Ptn0Partition> get_ptn0child_partition();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Ptn0ChildParentLink")

   virtual ~Ptn0ChildParentLink();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PartitionMngd_undef.h>
#endif
