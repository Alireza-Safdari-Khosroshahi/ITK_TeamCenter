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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IRVALIDATIONDATAS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IRVALIDATIONDATAS_HXX

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


class TCSOAGMOMODELMNGD_API IRValidationDataS : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_validation_name();
    const std::string& get_validation_desc();
    const std::string& get_validation_appl();
    const std::string& get_validation_utility_name();
    const std::string& get_validation_utility_shell();
    const Teamcenter::Soa::Client::StringVector& get_types_to_validate();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IRValidationDataS")

   virtual ~IRValidationDataS();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
