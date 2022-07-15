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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0APPRSCHCRITERIAFORMATTR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0APPRSCHCRITERIAFORMATTR_HXX

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


class TCSOACLIENTMNGD_API Fnd0ApprSchCriteriaFormAttr : public Teamcenter::Soa::Client::Model::ApprSearchCriteria
{
public:
    bool get_fnd0parent_type();
    const std::string& get_fnd0logical_opr();
    const std::string& get_fnd0prop_name();
    const std::string& get_fnd0math_opr();
    const Teamcenter::Soa::Client::StringVector& get_fnd0value();
    const std::string& get_fnd0form_type();
    const std::string& get_fnd0relation_type();
    const std::string& get_fnd0prop_type();
    const std::string& get_fnd0object_string();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0ApprSchCriteriaFormAttr")

   virtual ~Fnd0ApprSchCriteriaFormAttr();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
