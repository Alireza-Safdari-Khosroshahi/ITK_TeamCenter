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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ISPLANTATTRSTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ISPLANTATTRSTORAGE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/SpecmgrMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class UnitOfMeasure;
                class CPPlant;


class TCSOASPECMGRMODELMNGD_API ISPlantAttrStorage : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    double get_component_scrap();
    double get_lead_time_offset();
    double get_relevancy_to_costing();
    double get_bulk_material();
    const std::string& get_item_category();
    const std::string& get_issue_location();
    Teamcenter::Soa::Common::AutoPtr<UnitOfMeasure> get_issue_uom();
    Teamcenter::Soa::Common::AutoPtr<CPPlant> get_spm0plant();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ISPlantAttrStorage")

   virtual ~ISPlantAttrStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/SpecmgrMngd_undef.h>
#endif
