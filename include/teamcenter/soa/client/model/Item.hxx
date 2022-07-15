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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ITEM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ITEM_HXX

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
                class Form;
                class CFM_configuration_object;
                class UnitOfMeasure;


class TCSOACLIENTMNGD_API Item : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_item_id();
    const Teamcenter::Soa::Client::ModelObjectVector& get_bom_view_tags();
    Teamcenter::Soa::Common::AutoPtr<Form> get_item_master_tag();
    const std::string& get_fnd0OriginalLocationCode();
    bool get_is_configuration_item();
    bool get_has_variant_module();
    bool get_is_vi();
    const Teamcenter::Soa::Client::ModelObjectVector& get_global_alt_list();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_preferred_global_alt();
    bool get_fnd0is_monolithic();
    Teamcenter::Soa::Common::AutoPtr<CFM_configuration_object> get_configuration_object_tag();
    Teamcenter::Soa::Common::AutoPtr<UnitOfMeasure> get_uom_tag();
    const Teamcenter::Soa::Client::ModelObjectVector& get_more_revisions();
    const Teamcenter::Soa::Client::ModelObjectVector& get_revision_list();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_master_form();
    const Teamcenter::Soa::Client::ModelObjectVector& get_EC_addressed_by_rel();
    const Teamcenter::Soa::Client::ModelObjectVector& get_EC_solution_item_rel();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_id_dispdefault();
    const std::string& get_generic_component_object_string();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Generic_Architecture();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_MEView();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_external_object_link();
    const Teamcenter::Soa::Client::ModelObjectVector& get_altid_list();
    bool get_has_module();
    bool get_has_global_alternates();
    const Teamcenter::Soa::Client::ModelObjectVector& get_EC_reference_item_rel();
    const Teamcenter::Soa::Client::ModelObjectVector& get_EC_problem_item_rel();
    bool get_has_variants();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_CAE_Defining();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_classification();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_vi_sos();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_Rendering();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_aliasid();
    bool get_is_linked_to_generic_component();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_CAE_Source();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_manifestation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_ic_intent();
    const Teamcenter::Soa::Client::ModelObjectVector& get_displayable_revisions();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_CAE_Target();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_WorkContext_Relation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_reference();
    bool get_is_variant_item();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_CAE_Results();
    const Teamcenter::Soa::Client::ModelObjectVector& get_EC_snapshot_rel();
    const Teamcenter::Soa::Client::ModelObjectVector& get_EC_affected_item_rel();
    const std::string& get_current_id();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_AuditLog();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_requirement();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_CAE_Criteria();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_CAE_Include();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_CAE_Param();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_sst_record();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ContactInCompany();
    const Teamcenter::Soa::Client::ModelObjectVector& get_LocationInCompany();
    const Teamcenter::Soa::Client::ModelObjectVector& get_VisItemRevCreatedSnapshot2D();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0ListsCustomNotes();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0ListsParamReqments();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0StruObjAttrOverride();
    const std::string& get_current_id_context();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0StructureAuditLogs();
    const std::string& get_fnd0VariantNamespace();
    const std::string& get_fnd0PartIdentifier();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Item")

   virtual ~Item();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
