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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PTN0SUBSETDEFAULTS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PTN0SUBSETDEFAULTS_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mdl0SubsetDefaults.hxx>

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
                class ImanType;


class TCSOAPARTITIONMODELMNGD_API Ptn0SubsetDefaults : public Teamcenter::Soa::Client::Model::Mdl0SubsetDefaults
{
public:
    size_t count_ptn0partition_definitions();
    Teamcenter::Soa::Common::AutoPtr<Ptn0PartitionItemRevision> get_ptn0partition_definitions_at( size_t inx );
    size_t count_ptn0partition_scheme_types();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_ptn0partition_scheme_types_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_ptn0viewed_ptn_scheme_type();
    const Teamcenter::Soa::Client::StringVector& get_ptn0partition_ids();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ptn0tgt_partitions();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_ptn0viewed_partition_scheme();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Ptn0SubsetDefaults")

   virtual ~Ptn0SubsetDefaults();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PartitionMngd_undef.h>
#endif
