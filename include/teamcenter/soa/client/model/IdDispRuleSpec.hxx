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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IDDISPRULESPEC_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IDDISPRULESPEC_HXX

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
                class IdDispRule;
                class IdContext;


class TCSOACLIENTMNGD_API IdDispRuleSpec : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_idcxt_order();
    Teamcenter::Soa::Common::AutoPtr<IdDispRule> get_iddisprule();
    Teamcenter::Soa::Common::AutoPtr<IdContext> get_idcontext();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IdDispRuleSpec")

   virtual ~IdDispRuleSpec();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
