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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TMXFLOWC_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TMXFLOWC_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/model/CmtemserverMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTEMSERVERMODELMNGD_API TMXFlowC : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_TMXFlowPredecessor();
    const std::string& get_TMXFlowSuccessor();
    const std::string& get_TMXFlowDelay();
    const Teamcenter::Soa::Client::StringVector& get_TMXFlowParts();
    const std::string& get_TMXVariantSetID();
    const Teamcenter::Soa::Client::StringVector& get_TMXVariantSetExpression();
    const std::string& get_TMXFlowClassName();
    const std::string& get_TMXScopeFlowSubtype();
    const std::string& get_TMXFlowExtId();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TMXFlowC")

   virtual ~TMXFlowC();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtemserverMngd_undef.h>
#endif
