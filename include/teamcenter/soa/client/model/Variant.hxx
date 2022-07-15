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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VARIANT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VARIANT_HXX

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
                class UnitOfMeasure;


class TCSOACLIENTMNGD_API Variant : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_name();
    const std::string& get_comment();
    Teamcenter::Soa::Common::AutoPtr<Item> get_parent_item();
    Teamcenter::Soa::Common::AutoPtr<UnitOfMeasure> get_fnd0uom();
    const std::string& get_extended_name();
    int get_fnd0comparison_mode();
    bool get_fnd0is_multi_select();
    bool get_fnd0is_discretionary();
    bool get_fnd0is_model_family();
    bool get_fnd0has_free_form_values();
    const Teamcenter::Soa::Client::StringVector& get_fnd0optionValues();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Variant")

   virtual ~Variant();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
