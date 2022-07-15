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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ACTIVITYENTRYVALUE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ACTIVITYENTRYVALUE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/model/ServiceprocessingMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOASERVICEPROCESSINGMODELMNGD_API ActivityEntryValue : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    bool get_is_propagate();
    const Teamcenter::Soa::Common::DateTime& get_characteristic_date();
    double get_characteristic_value();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ActivityEntryValue")

   virtual ~ActivityEntryValue();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServiceprocessingMngd_undef.h>
#endif
