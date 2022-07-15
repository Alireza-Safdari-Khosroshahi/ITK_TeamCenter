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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EPMACTION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EPMACTION_HXX

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
                class EPMBusinessRule;
                class EPMHandler;


class TCSOACLIENTMNGD_API EPMAction : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_action_type();
    size_t count_rules();
    Teamcenter::Soa::Common::AutoPtr<EPMBusinessRule> get_rules_at( size_t inx );
    size_t count_action_handlers();
    Teamcenter::Soa::Common::AutoPtr<EPMHandler> get_action_handlers_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_tasktemplate();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EPMAction")

   virtual ~EPMAction();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
