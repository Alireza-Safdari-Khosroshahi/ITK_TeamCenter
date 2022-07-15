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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SCMVERSIONOBJECT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SCMVERSIONOBJECT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/model/ScmccMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class SCMConfigContext;
                class SCMServer;


class TCSOASCMCCMODELMNGD_API SCMVersionObject : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_scm_element();
    const std::string& get_scm_checkout_view();
    Teamcenter::Soa::Common::AutoPtr<SCMConfigContext> get_scm_config_context();
    const Teamcenter::Soa::Client::StringVector& get_scm_element_paths();
    const std::string& get_scm_config_rule();
    const std::string& get_scm_config_type();
    Teamcenter::Soa::Common::AutoPtr<SCMServer> get_scm_server();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SCMVersionObject")

   virtual ~SCMVersionObject();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ScmccMngd_undef.h>
#endif
