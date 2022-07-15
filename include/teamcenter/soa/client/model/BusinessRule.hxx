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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_BUSINESSRULE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_BUSINESSRULE_HXX

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
                class BusinessRuleDescriptor;
                class Condition;


class TCSOACLIENTMNGD_API BusinessRule : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_object_desc();
    int get_secure_bits();
    Teamcenter::Soa::Common::AutoPtr<BusinessRuleDescriptor> get_rule_descriptor();
    Teamcenter::Soa::Common::AutoPtr<Condition> get_condition_reference();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("BusinessRule")

   virtual ~BusinessRule();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
