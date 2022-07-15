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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRSEARCHCRITERIAMAPATTR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRSEARCHCRITERIAMAPATTR_HXX

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


class TCSOACLIENTMNGD_API ApprSearchCriteriaMapAttr : public Teamcenter::Soa::Client::Model::ApprSearchCriteria
{
public:
    const std::string& get_name();
    const std::string& get_value();
    int get_operator();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprSearchCriteriaMapAttr")

   virtual ~ApprSearchCriteriaMapAttr();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
