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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_OBJECTMAPPING_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_OBJECTMAPPING_HXX

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
                class ExternalAttribute;
                class ExternalDataSource;
                class MappedProperty;
                class MappedProperty;


class TCSOACLIENTMNGD_API ObjectMapping : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    bool get_persistent();
    bool get_related_to_item();
    bool get_update_on_save();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_itemtype();
    const Teamcenter::Soa::Client::StringVector& get_query_stmt();
    const std::string& get_store_procedure();
    size_t count_mapped_keys();
    Teamcenter::Soa::Common::AutoPtr<ExternalAttribute> get_mapped_keys_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<ExternalDataSource> get_data_source();
    size_t count_mapped_item_props();
    Teamcenter::Soa::Common::AutoPtr<MappedProperty> get_mapped_item_props_at( size_t inx );
    size_t count_mapped_props();
    Teamcenter::Soa::Common::AutoPtr<MappedProperty> get_mapped_props_at( size_t inx );
    const std::string& get_eintformtype();
    const std::string& get_query_name();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_exatt_item_desc();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_exatt_item_rev();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_exatt_item_name();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_exatt_item();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ObjectMapping")

   virtual ~ObjectMapping();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
