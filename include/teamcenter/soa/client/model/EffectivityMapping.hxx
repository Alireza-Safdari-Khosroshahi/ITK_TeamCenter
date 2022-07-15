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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EFFECTIVITYMAPPING_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EFFECTIVITYMAPPING_HXX

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
                class ItemRevision;
                class Effectivity;


class TCSOACLIENTMNGD_API EffectivityMapping : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_sub_unit();
    const Teamcenter::Soa::Common::DateTime& get_sub_date();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_sub_end_item();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_sub_end_itemrev();
    int get_priority();
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_owning_itemrev();
    Teamcenter::Soa::Common::AutoPtr<Effectivity> get_effectivity();
    bool get_latest_released_subdate();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EffectivityMapping")

   virtual ~EffectivityMapping();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
