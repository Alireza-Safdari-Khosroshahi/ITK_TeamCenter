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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PTN0APPRSRCHPARTITION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PTN0APPRSRCHPARTITION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ApprSearchCriteria.hxx>

#include <teamcenter/soa/client/model/PartitionMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ApprSearchCriteria;
                class ApprSearchCriteria;


class TCSOAPARTITIONMODELMNGD_API Ptn0ApprSrchPartition : public Teamcenter::Soa::Client::Model::ApprSearchCriteria
{
public:
    Teamcenter::Soa::Common::AutoPtr<ApprSearchCriteria> get_ptn0partition_obj_criteria();
    Teamcenter::Soa::Common::AutoPtr<ApprSearchCriteria> get_ptn0partition_rev_criteria();
    bool get_ptn0include_children();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Ptn0ApprSrchPartition")

   virtual ~Ptn0ApprSrchPartition();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PartitionMngd_undef.h>
#endif
