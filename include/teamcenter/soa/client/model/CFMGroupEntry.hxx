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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CFMGROUPENTRY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CFMGROUPENTRY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/CFMRuleEntry.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class CFMRuleEntry;


class TCSOACLIENTMNGD_API CFMGroupEntry : public Teamcenter::Soa::Client::Model::CFMRuleEntry
{
public:
    size_t count_sub_entries();
    Teamcenter::Soa::Common::AutoPtr<CFMRuleEntry> get_sub_entries_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CFMGroupEntry")

   virtual ~CFMGroupEntry();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
