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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CM0GNREVIEWREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CM0GNREVIEWREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ChangeItemRevision.hxx>

#include <teamcenter/soa/client/model/CmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMMODELMNGD_API Cm0GnReviewRevision : public Teamcenter::Soa::Client::Model::ChangeItemRevision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_Cm0RaisesActionItems();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Cm0AuditsItem();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Cm0HasContract();
    const std::string& get_cm0isAuditsItemPresent();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cm0GnReviewRevision")

   virtual ~Cm0GnReviewRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmMngd_undef.h>
#endif
