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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PSALTERNATESET_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PSALTERNATESET_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

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


class TCSOACLIENTMNGD_API PSAlternateSet : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_alt_items();
    const Teamcenter::Soa::Client::ModelObjectVector& get_alt_contexts();
    size_t count_alt_views();
    Teamcenter::Soa::Common::AutoPtr<PSBOMView> get_alt_views_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PSAlternateSet")

   virtual ~PSAlternateSet();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
