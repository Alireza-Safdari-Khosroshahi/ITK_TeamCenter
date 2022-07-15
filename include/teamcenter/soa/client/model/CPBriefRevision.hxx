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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPBRIEFREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPBRIEFREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/RequirementSpec_Revision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API CPBriefRevision : public Teamcenter::Soa::Client::Model::RequirementSpec_Revision
{
public:
    const Teamcenter::Soa::Common::DateTime& get_initiative_target_date();
    const std::string& get_target_market();
    const std::string& get_product_category();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPBriefRevision")

   virtual ~CPBriefRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
