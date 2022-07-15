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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CORP_PART_REVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CORP_PART_REVISION_HXX

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


class TCSOAGMOMODELMNGD_API CORP_Part_Revision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const std::string& get_ec_approver_name();
    const std::string& get_ec_release_date();
    const std::string& get_ec_nums();
    const std::string& get_ir_approver_name();
    const Teamcenter::Soa::Client::StringVector& get_change_desc();
    const std::string& get_dls();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date__MS1_();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date__MS2_();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date__MS3_();
    const std::string& get_Event();
    const std::string& get_gauge();
    const std::string& get_gm_p_addreq();
    const std::string& get_gm_p_addreq2();
    const std::string& get_gm_p_addreq3();
    const std::string& get_gm_p_addreq4();
    const std::string& get_gm_p_appear();
    const std::string& get_gm_p_appear2();
    const std::string& get_gm_p_appear3();
    const std::string& get_gm_p_appear4();
    const std::string& get_gm_p_appeng();
    const std::string& get_gm_p_fin();
    const std::string& get_gm_p_fin2();
    const std::string& get_gm_p_fin3();
    const std::string& get_gm_p_fin4();
    const std::string& get_gm_p_mat();
    const std::string& get_gm_p_mat2();
    const std::string& get_gm_p_mat3();
    const std::string& get_gm_p_mat4();
    const std::string& get_gm_p_mateng();
    const std::string& get_gm_p_pcoat();
    const std::string& get_gm_p_pcoat2();
    const std::string& get_gm_p_pcoat3();
    const std::string& get_gm_p_pcoat4();
    const std::string& get_gm_p_pcperf();
    const std::string& get_gm_p_pcperf2();
    const std::string& get_gm_p_pcperf3();
    const std::string& get_gm_p_pcperf4();
    const std::string& get_gm_p_perf();
    const std::string& get_gm_p_perf2();
    const std::string& get_gm_p_perf3();
    const std::string& get_gm_p_perf4();
    const std::string& get_gm_p_pnteng();
    const std::string& get_gm_p_svc();
    const std::string& get_gm_p_svc2();
    const std::string& get_mass();
    const std::string& get_material();
    const std::string& get_Milestone_1();
    const std::string& get_Milestone_2();
    const std::string& get_Milestone_3();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date__MS1_();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date__MS2_();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date__MS3_();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CORP_Part_Revision")

   virtual ~CORP_Part_Revision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
