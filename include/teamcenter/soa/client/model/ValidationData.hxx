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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VALIDATIONDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VALIDATIONDATA_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ClosureRule;
                class Dataset;
                class ValidationParams;


class TCSOACLIENTMNGD_API ValidationData : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_validation_name();
    const std::string& get_validation_description();
    const std::string& get_validation_application();
    bool get_validation_can_group();
    const std::string& get_validation_utility_name();
    const std::string& get_validation_utility_command();
    const Teamcenter::Soa::Client::StringVector& get_validation_arguments();
    Teamcenter::Soa::Common::AutoPtr<ClosureRule> get_validation_closure_rule();
    Teamcenter::Soa::Common::AutoPtr<Dataset> get_validation_ext_rule();
    const std::string& get_validation_category();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_validation_requirement();
    bool get_override_reason_mandatory();
    bool get_keep_overridden_result();
    Teamcenter::Soa::Common::AutoPtr<ValidationParams> get_validation_parameters();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Validation();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ValidationData")

   virtual ~ValidationData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
