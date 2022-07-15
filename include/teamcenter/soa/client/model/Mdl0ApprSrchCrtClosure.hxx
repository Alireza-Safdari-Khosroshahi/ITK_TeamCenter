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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MDL0APPRSRCHCRTCLOSURE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MDL0APPRSRCHCRTCLOSURE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ApprSearchCriteria.hxx>

#include <teamcenter/soa/client/model/AppmodelMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ClosureRule;
                class ApprSearchCriteria;


class TCSOAAPPMODELMODELMNGD_API Mdl0ApprSrchCrtClosure : public Teamcenter::Soa::Client::Model::ApprSearchCriteria
{
public:
    Teamcenter::Soa::Common::AutoPtr<ClosureRule> get_mdl0closure_rule();
    Teamcenter::Soa::Common::AutoPtr<ApprSearchCriteria> get_mdl0search_criteria();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mdl0ApprSrchCrtClosure")

   virtual ~Mdl0ApprSrchCrtClosure();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AppmodelMngd_undef.h>
#endif
