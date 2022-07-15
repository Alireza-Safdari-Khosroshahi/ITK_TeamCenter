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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MDL0VARIATIONINMODEL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MDL0VARIATIONINMODEL_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/AppmodelMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Mdl0ApplicationModel;


class TCSOAAPPMODELMODELMNGD_API Mdl0VariationInModel : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_mdl0name();
    const std::string& get_mdl0description();
    const std::string& get_mdl0product_name();
    const std::string& get_mdl0product_namespace();
    const std::string& get_mdl0configurator_URL();
    Teamcenter::Soa::Common::AutoPtr<Mdl0ApplicationModel> get_mdl0model();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mdl0VariationInModel")

   virtual ~Mdl0VariationInModel();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AppmodelMngd_undef.h>
#endif
