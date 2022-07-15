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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FE_MODEL_VERIFICATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FE_MODEL_VERIFICATION_HXX

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


class TCSOAGMOMODELMNGD_API FE_MODEL_VERIFICATION : public Teamcenter::Soa::Client::Model::Form
{
public:
    const Teamcenter::Soa::Client::StringVector& get_data_values();
    const std::string& get_new_file_name();
    const std::string& get_new_file_location();
    const std::string& get_modeler_signature();
    const Teamcenter::Soa::Common::DateTime& get_completion_date();
    const std::string& get_requester_signature();
    const Teamcenter::Soa::Common::DateTime& get_requester_date();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("FE_MODEL_VERIFICATION")

   virtual ~FE_MODEL_VERIFICATION();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
