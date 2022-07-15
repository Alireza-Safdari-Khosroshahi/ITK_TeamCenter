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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPEARANCE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPEARANCE_HXX

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
                class AppearanceRoot;
                class ItemRevision;
                class Item;
                class PSBOMView;
                class PSOccurrenceThread;


class TCSOACLIENTMNGD_API Appearance : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Appearance> get_parent();
    Teamcenter::Soa::Common::AutoPtr<AppearanceRoot> get_appearance_root();
    const Teamcenter::Soa::Common::DateTime& get_creation_date();
    double get_ext_transform_rot00();
    double get_ext_transform_rot10();
    double get_ext_transform_rot20();
    double get_ext_transform_per0();
    double get_ext_transform_rot01();
    double get_ext_transform_rot11();
    double get_ext_transform_rot21();
    double get_ext_transform_per1();
    double get_ext_transform_rot02();
    double get_ext_transform_rot12();
    double get_ext_transform_rot22();
    double get_ext_transform_per2();
    double get_ext_transform_tra0();
    double get_ext_transform_tra1();
    double get_ext_transform_tra2();
    double get_ext_transform_invscale();
    const Teamcenter::Soa::Common::DateTime& get_validity_date_in();
    const Teamcenter::Soa::Common::DateTime& get_validity_date_out();
    int get_validity_unit_in();
    int get_validity_unit_out();
    bool get_is_precise();
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_component_item_rev();
    Teamcenter::Soa::Common::AutoPtr<Item> get_component_item();
    Teamcenter::Soa::Common::AutoPtr<PSBOMView> get_component_bom_view();
    Teamcenter::Soa::Common::AutoPtr<PSOccurrenceThread> get_occ_thread();
    const Teamcenter::Soa::Client::StringVector& get_mapped_attrs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Appearance")

   virtual ~Appearance();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
