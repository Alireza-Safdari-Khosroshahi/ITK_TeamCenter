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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EFFECTIVITY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EFFECTIVITY_HXX

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
                class Item;
                class ItemRevision;


class TCSOACLIENTMNGD_API Effectivity : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const Teamcenter::Soa::Client::IntVector& get_effectivity_units();
    const Teamcenter::Soa::Common::DateTimeVector& get_effectivity_dates();
    bool get_effectivity_protection();
    const std::string& get_effectivity_id();
    Teamcenter::Soa::Common::AutoPtr<Item> get_end_item();
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_end_item_rev();
    int get_range_type();
    const std::string& get_date_range_text();
    int get_unit_open_ended_status();
    const std::string& get_unit_range_text();
    int get_date_open_ended_status();
    const std::string& get_range_text();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Effectivity")

   virtual ~Effectivity();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
