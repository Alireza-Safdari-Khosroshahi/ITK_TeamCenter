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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MDL0APPLICATIONMODEL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MDL0APPLICATIONMODEL_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/model/AppmodelMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAAPPMODELMODELMNGD_API Mdl0ApplicationModel : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_mdl0model_id();
    const std::string& get_mdl0revision_id();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mdl0HasConfiguratorContext();
    bool get_mdl0allows_add_content();
    bool get_mdl0allows_remove_content();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_specification();
    const std::string& get_mdl0config_product_name();
    const std::string& get_mdl0config_prod_namespace();
    const std::string& get_mdl0var_conf_prod_namespace();
    const std::string& get_mdl0var_conf_prod_name();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_Rendering();
    const std::string& get_mdl0eff_configurator_URL();
    const std::string& get_mdl0tc_product_context();
    const std::string& get_mdl0tc_product_item();
    const std::string& get_mdl0var_configurator_URL();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mdl0ApplicationModel")

   virtual ~Mdl0ApplicationModel();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AppmodelMngd_undef.h>
#endif
