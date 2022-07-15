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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ABSOCCDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ABSOCCDATA_HXX

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
                class AbsOccurrence;
                class AbsOccurrence;
                class AbsOccDataQualifier;
                class NoteType;
                class PSBOMView;
                class PSOccurrenceType;
                class UnitOfMeasure;
                class VariantExpressionBlock;
                class VariantExpressionBlock;
                class GeneralDesignElement;


class TCSOACLIENTMNGD_API AbsOccData : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<AbsOccurrence> get_abs_occ();
    Teamcenter::Soa::Common::AutoPtr<AbsOccurrence> get_parent_absocc();
    Teamcenter::Soa::Common::AutoPtr<AbsOccDataQualifier> get_data_qualifier();
    double get_xt_transform_rot00();
    double get_xt_transform_rot10();
    double get_xt_transform_rot20();
    double get_xt_transform_per0();
    double get_xt_transform_rot01();
    double get_xt_transform_rot11();
    double get_xt_transform_rot21();
    double get_xt_transform_per1();
    double get_xt_transform_rot02();
    double get_xt_transform_rot12();
    double get_xt_transform_rot22();
    double get_xt_transform_per2();
    double get_xt_transform_tra0();
    double get_xt_transform_tra1();
    double get_xt_transform_tra2();
    double get_xt_transform_invscale();
    const std::string& get_notetext();
    int get_occflags();
    double get_qtyvalue();
    const std::string& get_seqno();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_childitem();
    const std::string& get_occname();
    int get_instancenumber();
    int get_flagvalue();
    int get_flagmask();
    const std::string& get_archtype();
    const std::string& get_archelemid();
    const std::string& get_logicalpos();
    const Teamcenter::Soa::Client::StringVector& get_usgpartidlist();
    const Teamcenter::Soa::Client::StringVector& get_usgprodlist();
    int get_datamask();
    const std::string& get_ref_designator();
    int get_source();
    Teamcenter::Soa::Common::AutoPtr<NoteType> get_notetype();
    Teamcenter::Soa::Common::AutoPtr<PSBOMView> get_childbv();
    Teamcenter::Soa::Common::AutoPtr<PSOccurrenceType> get_occtype();
    Teamcenter::Soa::Common::AutoPtr<UnitOfMeasure> get_uom_tag();
    Teamcenter::Soa::Common::AutoPtr<VariantExpressionBlock> get_variantcondition();
    Teamcenter::Soa::Common::AutoPtr<VariantExpressionBlock> get_ucc_vc();
    Teamcenter::Soa::Common::AutoPtr<GeneralDesignElement> get_gdeobject();
    const std::string& get_absocc_rootline_str();
    const std::string& get_absocc_attr_name();
    const std::string& get_absocc_attr_value();
    const std::string& get_object_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AbsOccData")

   virtual ~AbsOccData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
