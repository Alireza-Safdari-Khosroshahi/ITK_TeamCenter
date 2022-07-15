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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_NAMEFIELD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_NAMEFIELD_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/BusinessRule.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class NameRule;


class TCSOACLIENTMNGD_API NameField : public Teamcenter::Soa::Client::Model::BusinessRule
{
public:
    const std::string& get_type_name();
    const std::string& get_property_name();
    int get_case();
    bool get_condition_override();
    Teamcenter::Soa::Common::AutoPtr<NameRule> get_rule_tag();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("NameField")

   virtual ~NameField();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
