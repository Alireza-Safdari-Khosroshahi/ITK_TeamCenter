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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EDADERIVEDDATASETCONFIGDEF_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EDADERIVEDDATASETCONFIGDEF_HXX

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
                class ImanType;
                class DatasetType;


class TCSOAEDASERVERMODELMNGD_API EDADerivedDatasetConfigDef : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_name();
    const std::string& get_context();
    const std::string& get_prefix();
    const std::string& get_postfix();
    const std::string& get_parent_type();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_relation_type();
    Teamcenter::Soa::Common::AutoPtr<DatasetType> get_dataset_type();
    const std::string& get_callback_name();
    const std::string& get_reference_type();
    const std::string& get_path_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EDADerivedDatasetConfigDef")

   virtual ~EDADerivedDatasetConfigDef();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/EdaserverMngd_undef.h>
#endif
