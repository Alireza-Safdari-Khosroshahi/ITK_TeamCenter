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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MDL0CONDITIONALARTIFACT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MDL0CONDITIONALARTIFACT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mdl0ModelArtifact.hxx>

#include <teamcenter/soa/client/model/AppmodelMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAAPPMODELMODELMNGD_API Mdl0ConditionalArtifact : public Teamcenter::Soa::Client::Model::Mdl0ModelArtifact
{
public:
    const std::string& get_mdl0effectivity_formula();
    const std::string& get_mdl0effectivity_display();
    const std::string& get_mdl0allowed_eff_formula();
    const std::string& get_mdl0allowed_eff_display();
    const std::string& get_mdl0allowed_var_formula();
    const std::string& get_mdl0variant_formula();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mdl0ConditionalArtifact")

   virtual ~Mdl0ConditionalArtifact();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AppmodelMngd_undef.h>
#endif
