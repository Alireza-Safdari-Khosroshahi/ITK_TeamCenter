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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CORP_PROCESS_REVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CORP_PROCESS_REVISION_HXX

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


class TCSOAGMOMODELMNGD_API CORP_Process_Revision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const std::string& get_ec_approver_name();
    const std::string& get_ec_release_date();
    const std::string& get_ec_nums();
    const std::string& get_gm_area();
    const std::string& get_gm_discipline();
    const std::string& get_gm_station_operation();
    const std::string& get_gm_machine_equipment();
    const std::string& get_gm_drawing_number();
    const std::string& get_gm_project_program();
    const std::string& get_gm_model();
    const std::string& get_ir_approver_name();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date__MS1_();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date__MS2_();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date__MS3_();
    const std::string& get_Event();
    const std::string& get_gm_content_type();
    const std::string& get_gm_design_source();
    const std::string& get_gm_identifier();
    const std::string& get_gm_jobs_per_hour();
    const std::string& get_gm_major_area();
    const std::string& get_gm_plant();
    const std::string& get_gm_process_level();
    const std::string& get_gm_project_phase();
    const std::string& get_Milestone_1();
    const std::string& get_Milestone_2();
    const std::string& get_Milestone_3();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date__MS1_();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date__MS2_();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date__MS3_();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CORP_Process_Revision")

   virtual ~CORP_Process_Revision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
