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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_NAMERULES_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_NAMERULES_HXX

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
                class NameCounters;


class TCSOACLIENTMNGD_API NameRules : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_rule_name();
    const Teamcenter::Soa::Client::StringVector& get_pattern();
    bool get_autogen();
    size_t count_counter_tags();
    Teamcenter::Soa::Common::AutoPtr<NameCounters> get_counter_tags_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("NameRules")

   virtual ~NameRules();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
