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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRSEARCHCRITERIABOXZONE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRSEARCHCRITERIABOXZONE_HXX

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


class TCSOACLIENTMNGD_API ApprSearchCriteriaBoxZone : public Teamcenter::Soa::Client::Model::ApprSearchCriteria
{
public:
    const Teamcenter::Soa::Client::DoubleVector& get_coordinates();
    int get_operator();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprSearchCriteriaBoxZone")

   virtual ~ApprSearchCriteriaBoxZone();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
