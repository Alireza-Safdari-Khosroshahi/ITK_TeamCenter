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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MDL0MODELARTIFACT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MDL0MODELARTIFACT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

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


class TCSOAAPPMODELMODELMNGD_API Mdl0ModelArtifact : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_mdl0model_object();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mdl0ModelArtifact")

   virtual ~Mdl0ModelArtifact();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AppmodelMngd_undef.h>
#endif
