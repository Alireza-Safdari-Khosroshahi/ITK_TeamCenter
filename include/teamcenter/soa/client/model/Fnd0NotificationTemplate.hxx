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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0NOTIFICATIONTEMPLATE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0NOTIFICATIONTEMPLATE_HXX

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


class TCSOACLIENTMNGD_API Fnd0NotificationTemplate : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_message();
    const std::string& get_subject();
    const Teamcenter::Soa::Client::StringVector& get_properties();
    bool get_message_modified();
    bool get_properties_modified();
    bool get_subject_modified();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0NotificationTemplate")

   virtual ~Fnd0NotificationTemplate();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
