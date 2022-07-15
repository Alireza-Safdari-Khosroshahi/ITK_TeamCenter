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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CHECKLIST_TEMPLATE_FORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CHECKLIST_TEMPLATE_FORM_HXX

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


class TCSOACLIENTMNGD_API Checklist_Template_Form : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_eco_prepare();
    const std::string& get_cost_calc();
    const std::string& get_weight_calc();
    const std::string& get_eng_estimate();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Checklist_Template_Form")

   virtual ~Checklist_Template_Form();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
