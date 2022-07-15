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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PSOCCURRENCE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PSOCCURRENCE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class POM_object;
                class VariantExpressionBlock;
                class PSOccurrenceType;
                class PSOption;
                class PSBOMView;
                class PSBOMViewRevision;
                class UnitOfMeasure;
                class PSOccurrenceThread;
                class PSXform;
                class PSOccurrenceNotes;


class TCSOACLIENTMNGD_API PSOccurrence : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_child_item();
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_alternate_etc_ref();
    Teamcenter::Soa::Common::AutoPtr<VariantExpressionBlock> get_variant_condition();
    Teamcenter::Soa::Common::AutoPtr<PSOccurrenceType> get_occ_type();
    size_t count_used_options();
    Teamcenter::Soa::Common::AutoPtr<PSOption> get_used_options_at( size_t inx );
    const Teamcenter::Soa::Client::ModelObjectVector& get_effectivities();
    const std::string& get_seq_no();
    int get_occurrence_type();
    int get_order_no();
    int get_occ_flags();
    double get_qty_value();
    const Teamcenter::Soa::Client::IntVector& get_cd_indexes();
    const Teamcenter::Soa::Client::ModelObjectVector& get_cd_tags();
    double get_ext_transform_rot00();
    double get_ext_transform_rot10();
    double get_ext_transform_rot20();
    double get_ext_transform_per0();
    double get_ext_transform_rot01();
    double get_ext_transform_rot11();
    double get_ext_transform_rot21();
    double get_ext_transform_per1();
    double get_ext_transform_rot02();
    double get_ext_transform_rot12();
    double get_ext_transform_rot22();
    double get_ext_transform_per2();
    double get_ext_transform_tra0();
    double get_ext_transform_tra1();
    double get_ext_transform_tra2();
    double get_ext_transform_invscale();
    const Teamcenter::Soa::Client::ModelObjectVector& get_pred_list();
    const std::string& get_occurrence_name();
    Teamcenter::Soa::Common::AutoPtr<PSBOMView> get_child_bv();
    Teamcenter::Soa::Common::AutoPtr<PSBOMViewRevision> get_parent_bvr();
    Teamcenter::Soa::Common::AutoPtr<UnitOfMeasure> get_uom_tag();
    const std::string& get_ref_designator();
    Teamcenter::Soa::Common::AutoPtr<PSOccurrenceThread> get_occ_thread();
    Teamcenter::Soa::Common::AutoPtr<PSXform> get_xform();
    Teamcenter::Soa::Common::AutoPtr<PSOccurrenceNotes> get_notes_ref();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_MEAppearance();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_MEProductLocation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_ProductManual();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_MERequiredAppr();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_MEProductAppearance();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_MEWorkInstruction();
    const std::string& get_mvl_condition();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PSOccurrence")

   virtual ~PSOccurrence();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
