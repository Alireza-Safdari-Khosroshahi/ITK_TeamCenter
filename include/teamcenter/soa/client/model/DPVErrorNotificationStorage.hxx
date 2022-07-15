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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DPVERRORNOTIFICATIONSTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DPVERRORNOTIFICATIONSTORAGE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/DpvMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOADPVMODELMNGD_API DPVErrorNotificationStorage : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_notification_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DPVErrorNotificationStorage")

   virtual ~DPVErrorNotificationStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/DpvMngd_undef.h>
#endif
