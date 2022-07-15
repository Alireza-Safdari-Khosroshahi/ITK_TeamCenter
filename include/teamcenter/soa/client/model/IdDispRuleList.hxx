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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IDDISPRULELIST_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IDDISPRULELIST_HXX

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
                class IdDispRule;
                class IdDispRule;
                class User;


class TCSOACLIENTMNGD_API IdDispRuleList : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<IdDispRule> get_idlist_current();
    size_t count_idlist_rules();
    Teamcenter::Soa::Common::AutoPtr<IdDispRule> get_idlist_rules_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<User> get_idlist_owner();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IdDispRuleList")

   virtual ~IdDispRuleList();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
