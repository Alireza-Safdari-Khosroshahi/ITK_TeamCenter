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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEPADREVISION_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEPADREVISION_MASTER_HXX

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


class TCSOACMTPADTWPMODELMNGD_API MEPADRevision_Master : public Teamcenter::Soa::Client::Model::Form
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
    const std::string& get_prd_dev_team();
    const std::string& get_bk_year();
    const std::string& get_bk();
    const std::string& get_pad_upc();
    const std::string& get_ecl();
    const std::string& get_erg_eval();
    const std::string& get_bestfitvpps();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEPADRevision_Master")

   virtual ~MEPADRevision_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtpadtwpMngd_undef.h>
#endif
