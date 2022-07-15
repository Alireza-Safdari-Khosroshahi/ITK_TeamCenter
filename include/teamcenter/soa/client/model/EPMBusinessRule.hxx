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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EPMBUSINESSRULE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EPMBUSINESSRULE_HXX

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
                class EPMBRHandler;


class TCSOACLIENTMNGD_API EPMBusinessRule : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_rule_quorum();
    size_t count_rule_handlers();
    Teamcenter::Soa::Common::AutoPtr<EPMBRHandler> get_rule_handlers_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_next_rule();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_parent_tasktemplate();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_action();
    int get_quorum();
    const std::string& get_object_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EPMBusinessRule")

   virtual ~EPMBusinessRule();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
