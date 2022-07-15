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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CONDITION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CONDITION_HXX

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
                class ConditionParameter;


class TCSOACLIENTMNGD_API Condition : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_condition_name();
    const std::string& get_condition_desc();
    size_t count_parameters();
    Teamcenter::Soa::Common::AutoPtr<ConditionParameter> get_parameters_at( size_t inx );
    const std::string& get_expression();
    bool get_secure_flag();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Condition")

   virtual ~Condition();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
