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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPEARANCECONFIGCONTEXT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPEARANCECONFIGCONTEXT_HXX

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
                class RevisionRule;


class TCSOACLIENTMNGD_API AppearanceConfigContext : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_config_mode();
    bool get_has_precise();
    Teamcenter::Soa::Common::AutoPtr<RevisionRule> get_revision_rule();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AppearanceConfigContext")

   virtual ~AppearanceConfigContext();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
