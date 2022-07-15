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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MELOCATEOPREVISION_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MELOCATEOPREVISION_MASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/CmtemserverMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTEMSERVERMODELMNGD_API MELocateOpRevision_Master : public Teamcenter::Soa::Client::Model::Form
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


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MELocateOpRevision_Master")

   virtual ~MELocateOpRevision_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtemserverMngd_undef.h>
#endif
