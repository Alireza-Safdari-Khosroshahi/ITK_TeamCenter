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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRSEARCHCRITERIAGROUP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRSEARCHCRITERIAGROUP_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ApprSearchCriteria.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ApprSearchCriteria;


class TCSOACLIENTMNGD_API ApprSearchCriteriaGroup : public Teamcenter::Soa::Client::Model::ApprSearchCriteria
{
public:
    int get_operator();
    size_t count_sub_criteria();
    Teamcenter::Soa::Common::AutoPtr<ApprSearchCriteria> get_sub_criteria_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprSearchCriteriaGroup")

   virtual ~ApprSearchCriteriaGroup();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
