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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CORP_SIMULATION_REVISION_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CORP_SIMULATION_REVISION_MASTER_HXX

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


class TCSOAGMOMODELMNGD_API CORP_Simulation_Revision_Master : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_simulation_type();
    const std::string& get_identifier();
    const std::string& get_content_type();
    const Teamcenter::Soa::Client::StringVector& get_project_program();
    const Teamcenter::Soa::Client::StringVector& get_model();
    const std::string& get_simulation_engineer();
    const std::string& get_plant();
    const std::string& get_major_area();
    const Teamcenter::Soa::Client::StringVector& get_area();
    const Teamcenter::Soa::Client::StringVector& get_station_operation();
    const Teamcenter::Soa::Client::StringVector& get_associated_tool();
    const Teamcenter::Soa::Client::StringVector& get_associated_product();
    const std::string& get_product_system();
    const Teamcenter::Soa::Client::StringVector& get_product_subsystem();
    const std::string& get_jobs_per_hour();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CORP_Simulation_Revision_Master")

   virtual ~CORP_Simulation_Revision_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
