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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPBRANDASSETREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPBRANDASSETREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DocumentRevision.hxx>

#include <teamcenter/soa/client/model/BrndmgmtMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOABRNDMGMTMODELMNGD_API CPBrandAssetRevision : public Teamcenter::Soa::Client::Model::DocumentRevision
{
public:
    const std::string& get_brand_category();
    const std::string& get_asset_type();
    const std::string& get_internal_competitor();
    const std::string& get_usage();
    const std::string& get_classification();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_brand_equities();
    const Teamcenter::Soa::Client::ModelObjectVector& get_brm0CP_artworks();
    const Teamcenter::Soa::Client::ModelObjectVector& get_brm0CP_copy();
    const Teamcenter::Soa::Client::ModelObjectVector& get_brm0CP_copy_elements();
    const Teamcenter::Soa::Client::ModelObjectVector& get_brm0CP_graphic_elements();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPBrandAssetRevision")

   virtual ~CPBrandAssetRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/BrndmgmtMngd_undef.h>
#endif
