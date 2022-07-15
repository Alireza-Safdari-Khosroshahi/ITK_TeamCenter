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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_NAMEFIELDS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_NAMEFIELDS_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class NameRules;


class TCSOACLIENTMNGD_API NameFields : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_type_name();
    const std::string& get_property_name();
    int get_case();
    Teamcenter::Soa::Common::AutoPtr<NameRules> get_rule_tag();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("NameFields")

   virtual ~NameFields();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
