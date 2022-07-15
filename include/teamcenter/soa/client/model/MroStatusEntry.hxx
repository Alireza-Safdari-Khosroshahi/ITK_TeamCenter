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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MROSTATUSENTRY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MROSTATUSENTRY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/MroRuleEntry.hxx>

#include <teamcenter/soa/client/model/AsmaintainedMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class TaskType;


class TCSOAASMAINTAINEDMODELMNGD_API MroStatusEntry : public Teamcenter::Soa::Client::Model::MroRuleEntry
{
public:
    Teamcenter::Soa::Common::AutoPtr<TaskType> get_statusType();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MroStatusEntry")

   virtual ~MroStatusEntry();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AsmaintainedMngd_undef.h>
#endif
