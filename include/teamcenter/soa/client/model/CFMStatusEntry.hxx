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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CFMSTATUSENTRY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CFMSTATUSENTRY_HXX

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
                class TaskType;


class TCSOACLIENTMNGD_API CFMStatusEntry : public Teamcenter::Soa::Client::Model::CFMRuleEntry
{
public:
    int get_date_type();
    Teamcenter::Soa::Common::AutoPtr<TaskType> get_status_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CFMStatusEntry")

   virtual ~CFMStatusEntry();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
