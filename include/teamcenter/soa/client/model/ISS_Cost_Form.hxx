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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ISS_COST_FORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ISS_COST_FORM_HXX

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
                class PwtMakeCostKey;


class TCSOAGMOMODELMNGD_API ISS_Cost_Form : public Teamcenter::Soa::Client::Model::Form
{
public:
    const Teamcenter::Soa::Client::StringVector& get_lead_time();
    size_t count_cost_key_list();
    Teamcenter::Soa::Common::AutoPtr<PwtMakeCostKey> get_cost_key_list_at( size_t inx );
    const std::string& get_final_ar_num();
    const std::string& get_temp_ar_num();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ISS_Cost_Form")

   virtual ~ISS_Cost_Form();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
