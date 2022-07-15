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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CORP_PROCESSREVMASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CORP_PROCESSREVMASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API CORP_ProcessRevMaster : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_process_type();
    const std::string& get_identifier();
    const std::string& get_content_type();
    const std::string& get_process_level();
    const Teamcenter::Soa::Client::StringVector& get_project_program();
    const Teamcenter::Soa::Client::StringVector& get_model();
    const std::string& get_design_source();
    const std::string& get_plant();
    const std::string& get_major_area();
    const Teamcenter::Soa::Client::StringVector& get_area();
    const Teamcenter::Soa::Client::StringVector& get_station_operation();
    const Teamcenter::Soa::Client::StringVector& get_discipline();
    const std::string& get_project_phase();
    const Teamcenter::Soa::Client::StringVector& get_drawing_number();
    const Teamcenter::Soa::Client::StringVector& get_machine_equipment();
    const std::string& get_jobs_per_hour();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CORP_ProcessRevMaster")

   virtual ~CORP_ProcessRevMaster();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
