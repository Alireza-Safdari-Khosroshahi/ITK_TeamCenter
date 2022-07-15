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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_RLZ0ITEMREALIZATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_RLZ0ITEMREALIZATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Rlz0Realization.hxx>

#include <teamcenter/soa/client/model/RealizationMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ItemRevision;
                class VariantRule;
                class StoredOptionSet;


class TCSOAREALIZATIONMODELMNGD_API Rlz0ItemRealization : public Teamcenter::Soa::Client::Model::Rlz0Realization
{
public:
    const std::string& get_rlz0bom_view();
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_rlz0product();
    Teamcenter::Soa::Common::AutoPtr<VariantRule> get_rlz0variant_rule();
    Teamcenter::Soa::Common::AutoPtr<StoredOptionSet> get_rlz0sos();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_rlz0sourceInput();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Rlz0ItemRealization")

   virtual ~Rlz0ItemRealization();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/RealizationMngd_undef.h>
#endif
