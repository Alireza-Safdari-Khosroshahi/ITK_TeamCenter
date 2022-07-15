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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IMANSUBSCRIPTION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IMANSUBSCRIPTION_HXX

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
                class ImanEventType;
                class ImanActionHandler;
                class Fnd0NotificationTemplate;


class TCSOACLIENTMNGD_API ImanSubscription : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_target();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_subscriber();
    Teamcenter::Soa::Common::AutoPtr<ImanEventType> get_event_type();
    const Teamcenter::Soa::Common::DateTime& get_execution_time();
    const Teamcenter::Soa::Common::DateTime& get_expiration_date();
    const Teamcenter::Soa::Client::StringVector& get_handler_parameters();
    const Teamcenter::Soa::Client::StringVector& get_attribute_names();
    const Teamcenter::Soa::Client::StringVector& get_attribute_values();
    const Teamcenter::Soa::Client::StringVector& get_math_operators();
    const Teamcenter::Soa::Client::StringVector& get_logic_operators();
    Teamcenter::Soa::Common::AutoPtr<ImanActionHandler> get_event_handler();
    Teamcenter::Soa::Common::AutoPtr<Fnd0NotificationTemplate> get_notification();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImanSubscription")

   virtual ~ImanSubscription();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
