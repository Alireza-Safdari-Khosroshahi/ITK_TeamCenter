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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ASMAINTAINEDREVISIONRULE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ASMAINTAINEDREVISIONRULE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/MroRevisionRule.hxx>

#include <teamcenter/soa/client/model/AsmaintainedMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAASMAINTAINEDMODELMNGD_API AsMaintainedRevisionRule : public Teamcenter::Soa::Client::Model::MroRevisionRule
{
public:
    const Teamcenter::Soa::Common::DateTime& get_ruleDate();
    const Teamcenter::Soa::Client::ModelObjectVector& get_entryList();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AsMaintainedRevisionRule")

   virtual ~AsMaintainedRevisionRule();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AsmaintainedMngd_undef.h>
#endif
