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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ITEMREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ITEMREVISION_HXX

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
                class Item;
                class Anchor;
                class PSBOMViewRevision;
                class PSOption;
                class PSOption;
                class VariantExpressionBlock;
                class GDEbvr;


class TCSOACLIENTMNGD_API ItemRevision : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_item_revision_id();
    Teamcenter::Soa::Common::AutoPtr<Form> get_item_master_tag();
    bool get_has_variant_module();
    Teamcenter::Soa::Common::AutoPtr<Item> get_items_tag();
    int get_sequence_id();
    int get_sequence_limit();
    Teamcenter::Soa::Common::AutoPtr<Anchor> get_sequence_anchor();
    const std::string& get_fnd0CurrentLocationCode();
    size_t count_structure_revisions();
    Teamcenter::Soa::Common::AutoPtr<PSBOMViewRevision> get_structure_revisions_at( size_t inx );
    size_t count_declared_options();
    Teamcenter::Soa::Common::AutoPtr<PSOption> get_declared_options_at( size_t inx );
    size_t count_used_options();
    Teamcenter::Soa::Common::AutoPtr<PSOption> get_used_options_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<VariantExpressionBlock> get_variant_expression_block();
    size_t count_gde_bvr_list();
    Teamcenter::Soa::Common::AutoPtr<GDEbvr> get_gde_bvr_list_at( size_t inx );
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_UG_promotion();
    const Teamcenter::Soa::Client::ModelObjectVector& get_representation_for();
    const Teamcenter::Soa::Client::ModelObjectVector& get_interpart_links();
    const std::string& get_current_revision_id();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_UG_wave_geometry();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_MEMfgModel();
    const Teamcenter::Soa::Client::ModelObjectVector& get_interpart_equations();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_UG_wave_part_link();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_UG_altrep();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_3D_snap_shot();
    const Teamcenter::Soa::Client::ModelObjectVector& get_mating_constraints();
    const Teamcenter::Soa::Client::ModelObjectVector& get_allowable_participant_types();
    const Teamcenter::Soa::Client::ModelObjectVector& get_assignable_participant_types();
    const Teamcenter::Soa::Client::ModelObjectVector& get_participants();
    const Teamcenter::Soa::Client::ModelObjectVector& get_epm_proposed_reviewers();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_epm_proposed_responsible_party();
    const std::string& get_mvl_text();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_specification();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0ExportContent();
    const Teamcenter::Soa::Client::ModelObjectVector& get_EC_solution_item_rel();
    const Teamcenter::Soa::Client::ModelObjectVector& get_EC_addressed_by_rel();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_id_dispdefault();
    const std::string& get_item_id();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Generic_Architecture();
    const std::string& get_effectivity_text();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_external_object_link();
    bool get_has_module();
    const Teamcenter::Soa::Client::ModelObjectVector& get_altid_list();
    const Teamcenter::Soa::Client::ModelObjectVector& get_EC_problem_item_rel();
    const Teamcenter::Soa::Client::ModelObjectVector& get_EC_reference_item_rel();
    bool get_has_variants();
    const std::string& get_intent_text();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_UG_wave_position();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_CAE_Defining();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_classification();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_Rendering();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_master_form_rev();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_UG_expression();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_UG_scenario();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TCEng_rdv_plmxml_configured();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_Motion();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_aliasid();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_CAE_Source();
    const Teamcenter::Soa::Client::ModelObjectVector& get_geometric_interfaces();
    bool get_is_vi();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_manifestation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_ProductManual();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_Simulation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_CAE_Target();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_WorkContext_Relation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_reference();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_CAE_Results();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Validation();
    const std::string& get_gc_updated_from_object_string();
    const Teamcenter::Soa::Client::ModelObjectVector& get_EC_affected_item_rel();
    const Teamcenter::Soa::Client::ModelObjectVector& get_EC_snapshot_rel();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_UG_udf();
    const Teamcenter::Soa::Client::ModelObjectVector& get_parametric_interfaces();
    const std::string& get_current_id();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TCEng_rdv_plmxml_unconfigured();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_requirement();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_snapshot();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_MEWorkInstruction();
    const std::string& get_current_id_context();
    const std::string& get_current_id_type();
    const std::string& get_current_id_uid();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_CAE_Criteria();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_CAE_Include();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_CAE_Param();
    const Teamcenter::Soa::Client::ModelObjectVector& get_BOM_Rollup();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Attaches();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Thumbnail_Source();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_sst_record();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ContactInCompany();
    const Teamcenter::Soa::Client::ModelObjectVector& get_LocationInCompany();
    const Teamcenter::Soa::Client::ModelObjectVector& get_HasParticipant();
    bool get_is_IRDC();
    const Teamcenter::Soa::Client::StringVector& get_fms_tickets();
    const Teamcenter::Soa::Client::ModelObjectVector& get_VisItemRevCreatedSnapshot2D();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0ListsCustomNotes();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0ListsParamReqments();
    const Teamcenter::Soa::Client::ModelObjectVector& get_revision_list();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0StructureAuditLogs();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ps_children();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ps_parents();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0StruObjAttrOverride();
    const Teamcenter::Soa::Client::ModelObjectVector& get_VisSession();
    const Teamcenter::Soa::Client::ModelObjectVector& get_VisMarkup();
    const Teamcenter::Soa::Client::ModelObjectVector& get_SimplifiedRendering();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0SpatialRendering();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0derived_default_rules();
    const std::string& get_fnd0IRDCUsed();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0fixed_default_rules();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0option_groups();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0option_values();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0TC_valdata_result();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0constraint_rules();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CAEAnalysis();
    const Teamcenter::Soa::Client::ModelObjectVector& get_MEProcess();
    const Teamcenter::Soa::Client::ModelObjectVector& get_MESetup();
    const Teamcenter::Soa::Client::ModelObjectVector& get_view();
    double get_fnd0rollupAccuracy();
    double get_fnd0rollupCoMx();
    double get_fnd0rollupCoMy();
    double get_fnd0rollupCoMz();
    double get_fnd0rollupMass();
    double get_fnd0rollupMoIxx();
    double get_fnd0rollupMoIyy();
    double get_fnd0rollupMoIzz();
    double get_fnd0rollupPoIxy();
    double get_fnd0rollupPoIxz();
    double get_fnd0rollupPoIyz();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ItemRevision")

   virtual ~ItemRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
