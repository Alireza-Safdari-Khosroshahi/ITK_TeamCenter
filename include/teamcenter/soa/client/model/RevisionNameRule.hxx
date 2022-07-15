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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_REVISIONNAMERULE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_REVISIONNAMERULE_HXX

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


class TCSOACLIENTMNGD_API RevisionNameRule : public Teamcenter::Soa::Client::Model::BusinessRule
{
public:
    const std::string& get_rule_name();
    bool get_exclude_skip_letters();
    int get_init_rev_type();
    const std::string& get_init_rev_start();
    const std::string& get_init_rev_desc();
    int get_sec_rev_type();
    const std::string& get_sec_rev_start();
    const std::string& get_sec_rev_desc();
    int get_suppl_rev_format();
    const std::string& get_suppl_rev_desc();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RevisionNameRule")

   virtual ~RevisionNameRule();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
