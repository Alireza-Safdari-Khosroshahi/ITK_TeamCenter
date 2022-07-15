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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_STRUCTURECONTEXT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_STRUCTURECONTEXT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ConfigurationContext;


class TCSOACLIENTMNGD_API StructureContext : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<ConfigurationContext> get_configuration_context();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_closure_rule();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_self();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_3D_snap_shot();
    bool get_single_enditem_only();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_specification();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_top_line();
    const Teamcenter::Soa::Client::ModelObjectVector& get_contents();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_default_workcontext();
    bool get_is_composition();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_variant_rule();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_manifestation();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_revision_rule();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_reference();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_requirement();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ref_windows();
    const Teamcenter::Soa::Client::ModelObjectVector& get_activity_lines();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_StructureContent();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("StructureContext")

   virtual ~StructureContext();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
