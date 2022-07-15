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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPSPECIFICATIONREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPSPECIFICATIONREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Specification_Revision.hxx>

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
                class CPManufacturer;
                class CPPlant;
                class UOMWithConversion;
                class CPKeyword;
                class CPSpecType;


class TCSOASPECMGRMODELMNGD_API CPSpecificationRevision : public Teamcenter::Soa::Client::Model::Specification_Revision
{
public:
    const std::string& get_authoring_system();
    Teamcenter::Soa::Common::AutoPtr<UnitOfMeasure> get_base_uom();
    size_t count_manufacturers();
    Teamcenter::Soa::Common::AutoPtr<CPManufacturer> get_manufacturers_at( size_t inx );
    size_t count_plants();
    Teamcenter::Soa::Common::AutoPtr<CPPlant> get_plants_at( size_t inx );
    size_t count_other_uom();
    Teamcenter::Soa::Common::AutoPtr<UOMWithConversion> get_other_uom_at( size_t inx );
    size_t count_keywords();
    Teamcenter::Soa::Common::AutoPtr<CPKeyword> get_keywords_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<CPSpecType> get_spec_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPSpecificationRevision")

   virtual ~CPSpecificationRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/SpecmgrMngd_undef.h>
#endif
