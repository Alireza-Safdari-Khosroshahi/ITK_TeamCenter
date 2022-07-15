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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_HRN_HARNESS_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_HRN_HARNESS_MASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/HrnMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAHRNMODELMNGD_API HRN_Harness_Master : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_part_type();
    const std::string& get_process_type();
    const std::string& get_process_value();
    const std::string& get_car_class_level2();
    const std::string& get_car_class_level3();
    const std::string& get_car_class_level4();
    const std::string& get_company_name();
    const std::string& get_model_year();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("HRN_Harness_Master")

   virtual ~HRN_Harness_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/HrnMngd_undef.h>
#endif
