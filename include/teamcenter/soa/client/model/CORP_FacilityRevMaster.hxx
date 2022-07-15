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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CORP_FACILITYREVMASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CORP_FACILITYREVMASTER_HXX

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


class TCSOAGMOMODELMNGD_API CORP_FacilityRevMaster : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_facility_type();
    const std::string& get_identifier();
    const std::string& get_content_type();
    const std::string& get_facility_level();
    const Teamcenter::Soa::Client::StringVector& get_project_program();
    const std::string& get_design_source();
    const std::string& get_plant();
    const Teamcenter::Soa::Client::StringVector& get_building();
    const Teamcenter::Soa::Client::StringVector& get_floor();
    const Teamcenter::Soa::Client::StringVector& get_discipline();
    const std::string& get_project_phase();
    const Teamcenter::Soa::Client::StringVector& get_drawing_number();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CORP_FacilityRevMaster")

   virtual ~CORP_FacilityRevMaster();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
