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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRSEARCHCRITERIAPROXIMITY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRSEARCHCRITERIAPROXIMITY_HXX

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
                class ApprSearchCriteriaSlctState;
                class ApprSearchCriteriaSlctState;


class TCSOACLIENTMNGD_API ApprSearchCriteriaProximity : public Teamcenter::Soa::Client::Model::ApprSearchCriteria
{
public:
    double get_distance();
    Teamcenter::Soa::Common::AutoPtr<ApprSearchCriteriaSlctState> get_target_appearance();
    Teamcenter::Soa::Common::AutoPtr<ApprSearchCriteriaSlctState> get_background_appearance();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprSearchCriteriaProximity")

   virtual ~ApprSearchCriteriaProximity();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
