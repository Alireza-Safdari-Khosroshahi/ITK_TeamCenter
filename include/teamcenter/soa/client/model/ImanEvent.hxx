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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IMANEVENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IMANEVENT_HXX

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
                class ImanType;
                class ImanEventType;
                class User;


class TCSOACLIENTMNGD_API ImanEvent : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_target_obj();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_target_object_type();
    const std::string& get_objectstr_of_target();
    const Teamcenter::Soa::Common::DateTime& get_event_time();
    int get_event_state();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_modified_obj();
    const Teamcenter::Soa::Client::StringVector& get_attribute_names();
    const Teamcenter::Soa::Client::StringVector& get_attribute_values();
    const Teamcenter::Soa::Client::StringVector& get_reference_data_names();
    const Teamcenter::Soa::Client::StringVector& get_reference_data_values();
    Teamcenter::Soa::Common::AutoPtr<ImanEventType> get_event_type();
    Teamcenter::Soa::Common::AutoPtr<User> get_event_initiator();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImanEvent")

   virtual ~ImanEvent();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
