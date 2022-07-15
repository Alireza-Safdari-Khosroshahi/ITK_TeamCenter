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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MDL0MODELELEMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MDL0MODELELEMENT_HXX

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
                class POM_object;


class TCSOAAPPMODELMODELMNGD_API Mdl0ModelElement : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_mdl0model_object();
    bool get_mdl0is_obsolete();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_specification();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mdl0AttachAttrGroup();
    const Teamcenter::Soa::Client::ModelObjectVector& get_mdl0pending_AttachAttrGroup();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mdl0ModelElement")

   virtual ~Mdl0ModelElement();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AppmodelMngd_undef.h>
#endif
