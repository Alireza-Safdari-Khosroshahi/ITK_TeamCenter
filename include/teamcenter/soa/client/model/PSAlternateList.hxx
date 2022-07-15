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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PSALTERNATELIST_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PSALTERNATELIST_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class PSBOMView;


class TCSOACLIENTMNGD_API PSAlternateList : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_alt_items();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_preferred_item();
    size_t count_alt_views();
    Teamcenter::Soa::Common::AutoPtr<PSBOMView> get_alt_views_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PSAlternateList")

   virtual ~PSAlternateList();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
