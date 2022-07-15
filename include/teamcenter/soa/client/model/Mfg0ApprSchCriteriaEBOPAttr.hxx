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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0APPRSCHCRITERIAEBOPATTR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0APPRSCHCRITERIAEBOPATTR_HXX

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


class TCSOACLIENTMNGD_API Mfg0ApprSchCriteriaEBOPAttr : public Teamcenter::Soa::Client::Model::ApprSearchCriteria
{
public:
    const std::string& get_Mfg0type_name();
    const Teamcenter::Soa::Client::StringVector& get_Mfg0logicaldesign_attrs();
    const Teamcenter::Soa::Client::StringVector& get_Mfg0logicaldesign_values();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0ApprSchCriteriaEBOPAttr")

   virtual ~Mfg0ApprSchCriteriaEBOPAttr();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
