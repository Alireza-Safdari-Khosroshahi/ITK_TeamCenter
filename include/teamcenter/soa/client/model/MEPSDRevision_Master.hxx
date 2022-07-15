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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEPSDREVISION_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEPSDREVISION_MASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/CmtpadtwpMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTPADTWPMODELMNGD_API MEPSDRevision_Master : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_program_id();
    const std::string& get_process_comment();
    double get_scheduled_time();
    double get_scheduled_cost();
    double get_allocated_time();
    double get_calculated_time();
    double get_sim_allocated_time();
    double get_sim_waiting_time();
    const std::string& get_sim_date();
    double get_target_cost();
    double get_target_time();
    const std::string& get_Process_engineer();
    const std::string& get_Process_number();
    const std::string& get_Product_name1();
    const std::string& get_Product_name2();
    const std::string& get_Product_name3();
    const std::string& get_Product_tool_num();
    const std::string& get_Progam_number1();
    const std::string& get_Progam_number2();
    const std::string& get_Progam_number3();
    const std::string& get_Program_number1();
    const std::string& get_Program_number2();
    const std::string& get_Program_number3();
    const std::string& get_Station_type();
    const std::string& get_process_notes();
    const std::string& get_eng_ref();
    const std::string& get_pe_engineer();
    const std::string& get_me_engineer();
    const std::string& get_me_group_leader();
    const std::string& get_assembly_position();
    const std::string& get_assembly_side();
    int get_work_height();
    double get_required_time_for_tryout();
    const std::string& get_restriction_description();
    double get_assembly_time_mpt();
    const std::string& get_PDT();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEPSDRevision_Master")

   virtual ~MEPSDRevision_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtpadtwpMngd_undef.h>
#endif
