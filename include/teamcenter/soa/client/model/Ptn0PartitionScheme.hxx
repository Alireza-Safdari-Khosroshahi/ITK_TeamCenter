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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PTN0PARTITIONSCHEME_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PTN0PARTITIONSCHEME_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mdl0ModelElement.hxx>

#include <teamcenter/soa/client/model/PartitionMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ImanType;


class TCSOAPARTITIONMODELMNGD_API Ptn0PartitionScheme : public Teamcenter::Soa::Client::Model::Mdl0ModelElement
{
public:
    size_t count_ptn0supported_partn_types();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_ptn0supported_partn_types_at( size_t inx );
    bool get_ptn0is_realized();
    bool get_ptn0allows_add_content();
    bool get_ptn0allows_remove_content();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Ptn0PartitionScheme")

   virtual ~Ptn0PartitionScheme();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PartitionMngd_undef.h>
#endif
