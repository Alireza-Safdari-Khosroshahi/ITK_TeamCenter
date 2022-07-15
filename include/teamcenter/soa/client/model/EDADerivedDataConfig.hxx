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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EDADERIVEDDATACONFIG_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EDADERIVEDDATACONFIG_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/EdaserverMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class EDADerivedItemConfigDef;
                class EDADerivedDatasetConfigDef;


class TCSOAEDASERVERMODELMNGD_API EDADerivedDataConfig : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_name();
    size_t count_derived_item_defs();
    Teamcenter::Soa::Common::AutoPtr<EDADerivedItemConfigDef> get_derived_item_defs_at( size_t inx );
    size_t count_derived_dataset_defs();
    Teamcenter::Soa::Common::AutoPtr<EDADerivedDatasetConfigDef> get_derived_dataset_defs_at( size_t inx );
    const std::string& get_description();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EDADerivedDataConfig")

   virtual ~EDADerivedDataConfig();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/EdaserverMngd_undef.h>
#endif
