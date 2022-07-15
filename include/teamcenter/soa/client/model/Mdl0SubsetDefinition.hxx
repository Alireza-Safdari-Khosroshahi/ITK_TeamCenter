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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MDL0SUBSETDEFINITION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MDL0SUBSETDEFINITION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0RecipeContainer.hxx>

#include <teamcenter/soa/client/model/AppmodelMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class POM_object;


class TCSOAAPPMODELMODELMNGD_API Mdl0SubsetDefinition : public Teamcenter::Soa::Client::Model::Fnd0RecipeContainer
{
public:
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_mdl0model_object();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mdl0AttachAttrGroup();
    const Teamcenter::Soa::Client::ModelObjectVector& get_mdl0pending_AttachAttrGroup();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mdl0SubsetDefinition")

   virtual ~Mdl0SubsetDefinition();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AppmodelMngd_undef.h>
#endif
