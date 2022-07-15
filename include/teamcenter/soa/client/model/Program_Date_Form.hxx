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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PROGRAM_DATE_FORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PROGRAM_DATE_FORM_HXX

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


class TCSOAGMOMODELMNGD_API Program_Date_Form : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_event();
    const Teamcenter::Soa::Common::DateTime& get_ecd();
    const Teamcenter::Soa::Common::DateTime& get_pcd();
    const std::string& get_milestone_1();
    const Teamcenter::Soa::Common::DateTime& get_ecd_milestone_1();
    const Teamcenter::Soa::Common::DateTime& get_pcd_milestone_1();
    const std::string& get_milestone_2();
    const Teamcenter::Soa::Common::DateTime& get_ecd_milestone_2();
    const Teamcenter::Soa::Common::DateTime& get_pcd_milestone_2();
    const std::string& get_milestone_3();
    const Teamcenter::Soa::Common::DateTime& get_ecd_milestone_3();
    const Teamcenter::Soa::Common::DateTime& get_pcd_milestone_3();
    const std::string& get_acd_milestone_1();
    const std::string& get_acd_milestone_2();
    const std::string& get_acd_milestone_3();
    const std::string& get_acd();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Program_Date_Form")

   virtual ~Program_Date_Form();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
