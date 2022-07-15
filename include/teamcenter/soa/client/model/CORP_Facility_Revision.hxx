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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CORP_FACILITY_REVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CORP_FACILITY_REVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API CORP_Facility_Revision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const std::string& get_ec_approver_name();
    const std::string& get_ec_release_date();
    const std::string& get_ec_nums();
    const std::string& get_gm_discipline();
    const std::string& get_gm_floor();
    const std::string& get_gm_drawing_number();
    const std::string& get_gm_building();
    const std::string& get_gm_project_program();
    const std::string& get_ir_approver_name();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date__MS1_();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date__MS2_();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date__MS3_();
    const std::string& get_Event();
    const std::string& get_gm_content_type();
    const std::string& get_gm_design_source();
    const std::string& get_gm_facility_level();
    const std::string& get_gm_identifier();
    const std::string& get_gm_plant();
    const std::string& get_gm_project_phase();
    const std::string& get_ITDC_WAP1_APPROVAL_NO();
    const std::string& get_ITDC_WAP1_APPROVAL_TYPE();
    const std::string& get_ITDC_WAP1_BLDG();
    const std::string& get_ITDC_WAP1_CLASSIFICATION();
    const std::string& get_ITDC_WAP1_CO_DWG_NO();
    const std::string& get_ITDC_WAP1_CO_ORDER_NO();
    const std::string& get_ITDC_WAP1_COLUMN_LINE();
    const std::string& get_ITDC_WAP1_COMMENT();
    const std::string& get_ITDC_WAP1_COMPANY();
    const Teamcenter::Soa::Common::DateTime& get_ITDC_WAP1_CREATE_DATE();
    const std::string& get_ITDC_WAP1_DWG_FMT();
    const std::string& get_ITDC_WAP1_INV_NO();
    const std::string& get_ITDC_WAP1_LEVEL();
    const std::string& get_ITDC_WAP1_MF_Storage();
    const std::string& get_ITDC_WAP1_MF_YEAR();
    const std::string& get_ITDC_WAP1_PLANT();
    const std::string& get_ITDC_WAP1_REMARK();
    const std::string& get_Milestone_1();
    const std::string& get_Milestone_2();
    const std::string& get_Milestone_3();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date__MS1_();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date__MS2_();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date__MS3_();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CORP_Facility_Revision")

   virtual ~CORP_Facility_Revision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
