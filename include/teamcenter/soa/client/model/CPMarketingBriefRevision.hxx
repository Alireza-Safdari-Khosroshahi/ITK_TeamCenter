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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPMARKETINGBRIEFREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPMARKETINGBRIEFREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/CPBriefRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API CPMarketingBriefRevision : public Teamcenter::Soa::Client::Model::CPBriefRevision
{
public:
    const std::string& get_competition();
    const std::string& get_region();
    const std::string& get_currency();
    double get_target_cost();
    const std::string& get_primary_contact_person();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_Has_ThemeBoard();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPMarketingBriefRevision")

   virtual ~CPMarketingBriefRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
