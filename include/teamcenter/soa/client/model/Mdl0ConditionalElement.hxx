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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MDL0CONDITIONALELEMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MDL0CONDITIONALELEMENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mdl0ModelElement.hxx>

#include <teamcenter/soa/client/model/AppmodelMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Mdl0ElementThread;


class TCSOAAPPMODELMODELMNGD_API Mdl0ConditionalElement : public Teamcenter::Soa::Client::Model::Mdl0ModelElement
{
public:
    Teamcenter::Soa::Common::AutoPtr<Mdl0ElementThread> get_mdl0element_thread();
    const std::string& get_mdl0revision_id();
    const Teamcenter::Soa::Client::ModelObjectVector& get_mdl0sibling_revisions();
    const std::string& get_mdl0effectivity_formula();
    const std::string& get_mdl0effectivity_display();
    const std::string& get_mdl0allowed_eff_formula();
    const std::string& get_mdl0allowed_eff_display();
    bool get_mdl0is_revisable();
    const std::string& get_mdl0allowed_var_formula();
    const std::string& get_mdl0variant_formula();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mdl0ConditionalElement")

   virtual ~Mdl0ConditionalElement();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AppmodelMngd_undef.h>
#endif
