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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CORP_BUILD_REVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CORP_BUILD_REVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API CORP_Build_Revision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date__MS1_();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date__MS2_();
    const Teamcenter::Soa::Common::DateTime& get_Estimated_Completion_Date__MS3_();
    const std::string& get_Event();
    const Teamcenter::Soa::Common::DateTime& get_first_trmt_dte();
    const std::string& get_Milestone_1();
    const std::string& get_Milestone_2();
    const std::string& get_Milestone_3();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date__MS1_();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date__MS2_();
    const Teamcenter::Soa::Common::DateTime& get_Required_Completion_Date__MS3_();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CORP_Build_Revision")

   virtual ~CORP_Build_Revision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
