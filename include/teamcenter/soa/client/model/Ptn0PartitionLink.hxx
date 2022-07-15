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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PTN0PARTITIONLINK_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PTN0PARTITIONLINK_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mdl0ConditionalArtifact.hxx>

#include <teamcenter/soa/client/model/PartitionMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Ptn0PartitionItemRevision;
                class ImanType;


class TCSOAPARTITIONMODELMNGD_API Ptn0PartitionLink : public Teamcenter::Soa::Client::Model::Mdl0ConditionalArtifact
{
public:
    Teamcenter::Soa::Common::AutoPtr<Ptn0PartitionItemRevision> get_ptn0partition_definition();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_ptn0partition_scheme_type();
    const std::string& get_ptn0partition_id();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Ptn0PartitionLink")

   virtual ~Ptn0PartitionLink();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PartitionMngd_undef.h>
#endif
