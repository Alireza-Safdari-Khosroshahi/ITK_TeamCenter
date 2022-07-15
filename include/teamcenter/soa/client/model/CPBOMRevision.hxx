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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPBOMREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPBOMREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/SpecElementRevision.hxx>

#include <teamcenter/soa/client/model/SpecmgrMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class UOMWithConversion;
                class CPPropertyListFormat;


class TCSOASPECMGRMODELMNGD_API CPBOMRevision : public Teamcenter::Soa::Client::Model::SpecElementRevision
{
public:
    double get_base_quantity();
    double get_min_quantity();
    double get_max_quantity();
    bool get_cp_preferred();
    Teamcenter::Soa::Common::AutoPtr<UOMWithConversion> get_other_uom();
    Teamcenter::Soa::Common::AutoPtr<CPPropertyListFormat> get_property_list_format();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPBOMRevision")

   virtual ~CPBOMRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/SpecmgrMngd_undef.h>
#endif
