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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MRODATEENTRY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MRODATEENTRY_HXX

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


class TCSOAASMAINTAINEDMODELMNGD_API MroDateEntry : public Teamcenter::Soa::Client::Model::MroRuleEntry
{
public:
    bool get_today();
    const Teamcenter::Soa::Common::DateTime& get_effectiveDate();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MroDateEntry")

   virtual ~MroDateEntry();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AsmaintainedMngd_undef.h>
#endif
