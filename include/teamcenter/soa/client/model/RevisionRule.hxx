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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_REVISIONRULE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_REVISIONRULE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ItemRevision;
                class Item;
                class Intent;
                class CFMRuleEntry;


class TCSOACLIENTMNGD_API RevisionRule : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const Teamcenter::Soa::Common::DateTime& get_rule_date();
    int get_rule_unit();
    bool get_any_intent();
    bool get_nested_effectivity();
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_rule_end_item_rev();
    Teamcenter::Soa::Common::AutoPtr<Item> get_rule_end_item();
    size_t count_intent_list();
    Teamcenter::Soa::Common::AutoPtr<Intent> get_intent_list_at( size_t inx );
    size_t count_entry_list();
    Teamcenter::Soa::Common::AutoPtr<CFMRuleEntry> get_entry_list_at( size_t inx );
    bool get_suppressed();
    bool get_user_visible();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_configured_end_item_rev();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_modifier();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RevisionRule")

   virtual ~RevisionRule();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
