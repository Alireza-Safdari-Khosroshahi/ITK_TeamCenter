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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CHANGENOTICEREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CHANGENOTICEREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/GnChangeNoticeRevision.hxx>

#include <teamcenter/soa/client/model/CmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMMODELMNGD_API ChangeNoticeRevision : public Teamcenter::Soa::Client::Model::GnChangeNoticeRevision
{
public:
    const Teamcenter::Soa::Client::StringVector& get_Cm0impact_types();
    const std::string& get_CMImplPriority();
    const std::string& get_CMIsCustApprovalRequired();
    const std::string& get_CMStatusOfCustApproval();
    const Teamcenter::Soa::Common::DateTime& get_CMDateOfCustApproval();
    const std::string& get_CMSpecialInstruction();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMImpactedItems();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMImplement();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMProblemItems();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMReferenceItems();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMSolutionItems();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMWorkBreakdown();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ChangeNoticeRevision")

   virtual ~ChangeNoticeRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmMngd_undef.h>
#endif
