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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IMANACTION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IMANACTION_HXX

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
                class ImanActionHandler;
                class User;


class TCSOACLIENTMNGD_API ImanAction : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_eventtype_id();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_subscription_target();
    const std::string& get_objectstr_of_target();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_subscriber();
    const Teamcenter::Soa::Client::StringVector& get_handler_parameters();
    const Teamcenter::Soa::Common::DateTime& get_execution_time();
    const std::string& get_target_object_type_name();
    const std::string& get_node_name();
    const Teamcenter::Soa::Common::DateTime& get_event_time();
    int get_retries_togo();
    int get_event_state();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_modified_obj();
    const Teamcenter::Soa::Client::StringVector& get_attribute_names();
    const Teamcenter::Soa::Client::StringVector& get_attribute_values();
    Teamcenter::Soa::Common::AutoPtr<ImanActionHandler> get_action_handler();
    Teamcenter::Soa::Common::AutoPtr<User> get_event_initiator();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImanAction")

   virtual ~ImanAction();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
