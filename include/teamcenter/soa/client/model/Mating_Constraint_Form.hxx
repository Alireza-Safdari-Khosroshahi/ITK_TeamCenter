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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MATING_CONSTRAINT_FORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MATING_CONSTRAINT_FORM_HXX

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


class TCSOACLIENTMNGD_API Mating_Constraint_Form : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_Name();
    const std::string& get_Description();
    const std::string& get_Type();
    const std::string& get_Parent_Part();
    const Teamcenter::Soa::Common::DateTime& get_Modified_Date();
    const std::string& get_Assembly_Context();
    const Teamcenter::Soa::Common::DateTime& get_Context_Time_Stamp();
    const std::string& get_Dimensional_Variable();
    const Teamcenter::Soa::Client::StringVector& get_Referenced_Entities();
    const Teamcenter::Soa::Common::DateTimeVector& get_Referenced_Time_Stamps();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mating_Constraint_Form")

   virtual ~Mating_Constraint_Form();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
