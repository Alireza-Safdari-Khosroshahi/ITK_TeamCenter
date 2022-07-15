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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CAE_AIF_FORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CAE_AIF_FORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API CAE_AIF_Form : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_solver_name();
    const std::string& get_analysis_type();
    const std::string& get_solution_type();
    const std::string& get_solution_step();
    const std::string& get_version_name();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_owner_form_obj();
    const std::string& get_project_id();
    const std::string& get_previous_version_id();
    const std::string& get_serial_number();
    const std::string& get_item_comment();
    const std::string& get_user_data_1();
    const std::string& get_user_data_2();
    const std::string& get_user_data_3();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CAE_AIF_Form")

   virtual ~CAE_AIF_Form();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
