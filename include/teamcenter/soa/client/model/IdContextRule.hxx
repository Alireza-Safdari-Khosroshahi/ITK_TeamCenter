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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IDCONTEXTRULE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IDCONTEXTRULE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/BusinessRule.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ImanType;
                class ImanType;
                class IdContext;


class TCSOACLIENTMNGD_API IdContextRule : public Teamcenter::Soa::Client::Model::BusinessRule
{
public:
    const std::string& get_idcxt_rule();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_idfbl_type();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_idfr_type();
    Teamcenter::Soa::Common::AutoPtr<IdContext> get_idcontext();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IdContextRule")

   virtual ~IdContextRule();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
