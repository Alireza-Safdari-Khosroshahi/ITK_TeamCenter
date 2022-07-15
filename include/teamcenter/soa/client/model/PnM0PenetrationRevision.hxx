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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PNM0PENETRATIONREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PNM0PENETRATIONREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/IssueReportRevision.hxx>

#include <teamcenter/soa/client/model/PenetrationmgmtMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAPENETRATIONMGMTMODELMNGD_API PnM0PenetrationRevision : public Teamcenter::Soa::Client::Model::IssueReportRevision
{
public:
    const std::string& get_pnm0Hole_cut_status();
    const std::string& get_pnm0Hole_cut_type();
    const std::string& get_pnm0Penetration_type();
    const std::string& get_pnm0Hole_cut_direction();
    const std::string& get_pnm0Hole_cut_face_handle();
    const std::string& get_pnm0Hole_cut_feature_handle();
    const std::string& get_pnm0Compensation_type();
    const std::string& get_pnm0Cut_across_erection_brk();
    const std::string& get_pnm0Spill_coaming_required();
    const std::string& get_pnm0Structural_mfg_status();
    const std::string& get_pnm0Routing_segment_handle();
    const Teamcenter::Soa::Client::ModelObjectVector& get_PnM0CompensationPart();
    const Teamcenter::Soa::Client::ModelObjectVector& get_PnM0HangerPart();
    const Teamcenter::Soa::Client::ModelObjectVector& get_PnM0HoleCutObject();
    const Teamcenter::Soa::Client::ModelObjectVector& get_PnM0PenetratedParts();
    const Teamcenter::Soa::Client::ModelObjectVector& get_PnM0PenetratingParts();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PnM0PenetrationRevision")

   virtual ~PnM0PenetrationRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PenetrationmgmtMngd_undef.h>
#endif
