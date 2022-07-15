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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CFMOVERRIDEENTRY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CFMOVERRIDEENTRY_HXX

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
                class Folder;


class TCSOACLIENTMNGD_API CFMOverrideEntry : public Teamcenter::Soa::Client::Model::CFMRuleEntry
{
public:
    Teamcenter::Soa::Common::AutoPtr<Folder> get_folder();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CFMOverrideEntry")

   virtual ~CFMOverrideEntry();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
