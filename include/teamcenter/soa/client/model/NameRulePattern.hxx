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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_NAMERULEPATTERN_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_NAMERULEPATTERN_HXX

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
                class NameCounter;


class TCSOACLIENTMNGD_API NameRulePattern : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    bool get_autogen();
    const std::string& get_pattern();
    const std::string& get_pattern_desc();
    size_t count_counter_tags();
    Teamcenter::Soa::Common::AutoPtr<NameCounter> get_counter_tags_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("NameRulePattern")

   virtual ~NameRulePattern();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
