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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PTN0PARTITION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PTN0PARTITION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mdl0ConditionalElement.hxx>

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
                class ApprSearchCriteria;
                class ImanType;


class TCSOAPARTITIONMODELMNGD_API Ptn0Partition : public Teamcenter::Soa::Client::Model::Mdl0ConditionalElement
{
public:
    Teamcenter::Soa::Common::AutoPtr<Ptn0PartitionItemRevision> get_ptn0source_object();
    const Teamcenter::Soa::Client::StringVector& get_ptn0reference_designators();
    Teamcenter::Soa::Common::AutoPtr<ApprSearchCriteria> get_ptn0partition_recipe();
    const std::string& get_ptn0partition_id();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_ptn0partition_scheme_type();
    bool get_ptn0allows_add_content();
    bool get_ptn0allows_remove_content();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_Rendering();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_ptn0source_partition();
    const std::string& get_ptn0source_object_id();
    const std::string& get_ptn0source_object_name();
    const std::string& get_ptn0source_object_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Ptn0Partition")

   virtual ~Ptn0Partition();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PartitionMngd_undef.h>
#endif
