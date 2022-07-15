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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ARCHITECTURE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ARCHITECTURE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Item.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class VariantExpressionBlock;


class TCSOACLIENTMNGD_API Architecture : public Teamcenter::Soa::Client::Model::Item
{
public:
    const std::string& get_generic_component_id();
    bool get_has_shared_nves();
    bool get_has_consistent_nves();
    bool get_is_partial_breakdown();
    bool get_has_hierarchical_variabilty();
    bool get_has_basedon_preexist_elemnt();
    Teamcenter::Soa::Common::AutoPtr<Architecture> get_instantiating_arch();
    Teamcenter::Soa::Common::AutoPtr<VariantExpressionBlock> get_var_exp_block();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Architecture")

   virtual ~Architecture();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
