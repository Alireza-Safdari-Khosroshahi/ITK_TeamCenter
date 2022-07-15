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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_BUSINESS_CASE_FORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_BUSINESS_CASE_FORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API Business_Case_Form : public Teamcenter::Soa::Client::Model::Form
{
public:
    double get_est_engg_expense();
    double get_act_engg_expense();
    const std::string& get_engg_expense_comment();
    double get_est_tool_cost();
    double get_act_tool_cost();
    const std::string& get_tool_cost_comment();
    double get_est_vendor_cost();
    double get_act_vendor_cost();
    const std::string& get_vendor_cost_comment();
    double get_est_oper_cost();
    double get_act_oper_cost();
    const std::string& get_oper_cost_comment();
    double get_est_prod_cost();
    double get_act_prod_cost();
    const std::string& get_prod_cost_comment();
    double get_est_rework_cost();
    double get_act_rework_cost();
    const std::string& get_rework_cost_comment();
    double get_est_warranty_cost();
    double get_act_warranty_cost();
    const std::string& get_warranty_cost_comment();
    double get_est_change_life();
    double get_act_change_life();
    const std::string& get_change_life_comment();
    double get_est_volume_change();
    double get_act_volume_change();
    const std::string& get_volume_change_comment();
    double get_est_warranty();
    double get_act_warranty();
    const std::string& get_warranty_comment();
    double get_est_vehicle_mass();
    double get_act_vehicle_mass();
    const std::string& get_vehicle_mass_comment();
    const Teamcenter::Soa::Common::DateTime& get_est_validation_date();
    const Teamcenter::Soa::Common::DateTime& get_act_validation_date();
    const std::string& get_validation_date_comment();
    const Teamcenter::Soa::Common::DateTime& get_est_ppap_date();
    const Teamcenter::Soa::Common::DateTime& get_act_ppap_date();
    const std::string& get_ppap_date_comment();
    bool get_trial_run_reqd();
    const Teamcenter::Soa::Common::DateTime& get_est_trial_run_date();
    const Teamcenter::Soa::Common::DateTime& get_act_trial_run_date();
    const std::string& get_trial_run_date_comment();
    const Teamcenter::Soa::Common::DateTime& get_est_prod_rel_date();
    const std::string& get_prod_rel_date_comment();
    const Teamcenter::Soa::Common::DateTime& get_est_review_date();
    const Teamcenter::Soa::Common::DateTime& get_act_review_date();
    const std::string& get_review_date_comment();
    const std::string& get_currency();
    const std::string& get_currency_comments();
    double get_total_invest_est1();
    double get_total_invest_est2();
    const std::string& get_total_invest_comments();
    double get_machinery_est1();
    double get_machinery_est2();
    const std::string& get_machinery_comments();
    double get_engg_base_exp_est1();
    double get_engg_base_exp_est2();
    const std::string& get_engg_base_exp_comments();
    double get_engg_int_exp_est1();
    double get_engg_int_exp_est2();
    const std::string& get_engg_int_exp_comments();
    double get_manuf_engg_exp_est1();
    double get_manuf_engg_exp_est2();
    const std::string& get_manuf_engg_exp_comments();
    double get_plant_engg_exp_est1();
    double get_plant_engg_exp_est2();
    const std::string& get_plant_engg_exp_comments();
    double get_startup_exp_est1();
    double get_startup_exp_est2();
    const std::string& get_startup_exp_comments();
    double get_plant_rework_est1();
    double get_plant_rework_est2();
    const std::string& get_plant_rework_comments();
    double get_supp_rework_est1();
    double get_supp_rework_est2();
    const std::string& get_supp_rework_comments();
    double get_cancellation_est1();
    double get_cancellation_est2();
    const std::string& get_cancellation_comments();
    double get_manpower_est1();
    double get_manpower_est2();
    const std::string& get_manpower_comments();
    double get_plant_scrap_est1();
    double get_plant_scrap_est2();
    const std::string& get_plant_scrap_comments();
    double get_supp_scrap_est1();
    double get_supp_scrap_est2();
    const std::string& get_supp_scrap_comments();
    const std::string& get_change_inside_comments();
    const std::string& get_risk_involved_comments();
    const Teamcenter::Soa::Client::DoubleVector& get_warranty_est1();
    const Teamcenter::Soa::Client::DoubleVector& get_warranty_est2();
    const Teamcenter::Soa::Client::StringVector& get_warranty_iptv_comments();
    const Teamcenter::Soa::Client::DoubleVector& get_mass_per_vehicle_est1();
    const Teamcenter::Soa::Client::DoubleVector& get_mass_per_vehicle_est2();
    const Teamcenter::Soa::Client::StringVector& get_mass_per_vehicle_comments();
    const std::string& get_change_driver_comments();
    double get_tooling_impact_est1();
    double get_tooling_impact_est2();
    const std::string& get_tooling_impact_comments();
    double get_material_impact_est1();
    double get_material_impact_est2();
    const std::string& get_material_impact_comments();
    const std::string& get_cust_approval_comments();
    bool get_cust_approval_reqd();
    const Teamcenter::Soa::Common::DateTime& get_prod_rel_date_est2();
    bool get_ptr_reversible();
    const std::string& get_ptr_reversible_plan();
    int get_manuf_lead_weeks_est1();
    int get_manuf_lead_weeks_est2();
    const std::string& get_manuf_lead_weeks_comments();
    int get_tooling_lead_weeks_est1();
    int get_tooling_lead_weeks_est2();
    const std::string& get_tooling_lead_weeks_comments();
    const std::string& get_tgt_impl_date_comments();
    const std::string& get_change_inside();
    const std::string& get_risk_involved();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Business_Case_Form")

   virtual ~Business_Case_Form();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
