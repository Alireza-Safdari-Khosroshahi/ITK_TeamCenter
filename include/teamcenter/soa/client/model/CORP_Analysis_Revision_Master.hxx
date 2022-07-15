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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CORP_ANALYSIS_REVISION_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CORP_ANALYSIS_REVISION_MASTER_HXX

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


class TCSOAGMOMODELMNGD_API CORP_Analysis_Revision_Master : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_analysis_type();
    const std::string& get_vehicle_program();
    const std::string& get_vehicle_line();
    const std::string& get_model_year();
    const std::string& get_model_desc();
    const std::string& get_upc();
    const std::string& get_prelim_data();
    const std::string& get_vehicle_partition();
    const Teamcenter::Soa::Client::StringVector& get_analysis_details();
    const std::string& get_release_level();
    const std::string& get_additional_info1();
    const std::string& get_additional_info2();
    const std::string& get_additional_info3();
    const std::string& get_additional_info4();
    const std::string& get_additional_info5();
    const std::string& get_CAE_Procedure_name();
    const std::string& get_CAE_Procedure_ID();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_owner_form_obj();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CORP_Analysis_Revision_Master")

   virtual ~CORP_Analysis_Revision_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
