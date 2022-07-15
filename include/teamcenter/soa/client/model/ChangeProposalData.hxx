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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CHANGEPROPOSALDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CHANGEPROPOSALDATA_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API ChangeProposalData : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_cm_reason();
    const std::string& get_cm_reason_desc();
    const std::string& get_cm_desc();
    const std::string& get_cp_name();
    const std::string& get_cp_state();
    const std::string& get_cm_sub_by();
    const std::string& get_cm_sub_on();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ChangeProposalData")

   virtual ~ChangeProposalData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
