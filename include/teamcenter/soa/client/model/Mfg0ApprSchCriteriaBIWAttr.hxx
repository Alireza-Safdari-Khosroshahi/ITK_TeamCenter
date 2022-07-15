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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0APPRSCHCRITERIABIWATTR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0APPRSCHCRITERIABIWATTR_HXX

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


class TCSOACLIENTMNGD_API Mfg0ApprSchCriteriaBIWAttr : public Teamcenter::Soa::Client::Model::ApprSearchCriteria
{
public:
    const std::string& get_Mfg0object_type();
    const std::string& get_Mfg0query_type();
    Teamcenter::Soa::Common::AutoPtr<ApprSearchCriteriaSlctState> get_Mfg0related_objects();
    const std::string& get_Mfg0match_type();
    bool get_Mfg0withHierarchy();
    bool get_Mfg0considerIPA();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Mfg0relContextItem();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0ApprSchCriteriaBIWAttr")

   virtual ~Mfg0ApprSchCriteriaBIWAttr();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
