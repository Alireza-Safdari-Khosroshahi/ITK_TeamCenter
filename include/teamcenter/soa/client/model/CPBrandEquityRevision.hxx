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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPBRANDEQUITYREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPBRANDEQUITYREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/model/BrndmgmtMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOABRNDMGMTMODELMNGD_API CPBrandEquityRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const std::string& get_channel();
    const std::string& get_scope();
    const std::string& get_target_market();
    const std::string& get_value_proposition();
    const std::string& get_internal_competitor();
    const std::string& get_company();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_theme_boards();
    const std::string& get_brand_category();
    const std::string& get_brand_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPBrandEquityRevision")

   virtual ~CPBrandEquityRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/BrndmgmtMngd_undef.h>
#endif
