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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CFMWORKINGENTRY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CFMWORKINGENTRY_HXX

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
                class Group;
                class User;


class TCSOACLIENTMNGD_API CFMWorkingEntry : public Teamcenter::Soa::Client::Model::CFMRuleEntry
{
public:
    bool get_current_user();
    bool get_current_group();
    Teamcenter::Soa::Common::AutoPtr<Group> get_group_tag();
    Teamcenter::Soa::Common::AutoPtr<User> get_user_tag();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CFMWorkingEntry")

   virtual ~CFMWorkingEntry();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
