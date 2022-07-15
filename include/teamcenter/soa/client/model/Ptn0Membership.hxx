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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PTN0MEMBERSHIP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PTN0MEMBERSHIP_HXX

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
                class POM_object;


class TCSOAPARTITIONMODELMNGD_API Ptn0Membership : public Teamcenter::Soa::Client::Model::Ptn0PartitionLink
{
public:
    const std::string& get_ptn0reference_designator();
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_ptn0partition_member();
    bool get_ptn0is_partition_owned();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Ptn0Membership")

   virtual ~Ptn0Membership();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PartitionMngd_undef.h>
#endif
