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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IMPACTANALYSIS_FORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IMPACTANALYSIS_FORM_HXX

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


class TCSOACLIENTMNGD_API ImpactAnalysis_Form : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_cost_estimate();
    const std::string& get_weight_estimate();
    const std::string& get_models_affected();
    const std::string& get_estimated_duration();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImpactAnalysis_Form")

   virtual ~ImpactAnalysis_Form();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
