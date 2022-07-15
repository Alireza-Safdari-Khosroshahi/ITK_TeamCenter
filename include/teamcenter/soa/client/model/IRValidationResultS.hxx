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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IRVALIDATIONRESULTS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IRVALIDATIONRESULTS_HXX

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
                class IRValidationDataS;


class TCSOAGMOMODELMNGD_API IRValidationResultS : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    bool get_validation_result();
    int get_validation_status();
    const Teamcenter::Soa::Common::DateTime& get_validation_date();
    const std::string& get_validation_target();
    const std::string& get_validating_user();
    const std::string& get_validation_notes();
    Teamcenter::Soa::Common::AutoPtr<IRValidationDataS> get_validation_data();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IRValidationResultS")

   virtual ~IRValidationResultS();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
