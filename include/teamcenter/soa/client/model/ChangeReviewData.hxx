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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CHANGEREVIEWDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CHANGEREVIEWDATA_HXX

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


class TCSOACLIENTMNGD_API ChangeReviewData : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_cm_reason();
    const std::string& get_cm_reason_desc();
    const std::string& get_cm_desc();
    const std::string& get_rev_state();
    const std::string& get_cm_sub_by();
    const std::string& get_cm_sub_on();
    const std::string& get_rev_charge();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ChangeReviewData")

   virtual ~ChangeReviewData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
