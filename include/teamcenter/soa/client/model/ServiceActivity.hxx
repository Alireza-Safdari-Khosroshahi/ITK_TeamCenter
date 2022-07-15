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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SERVICEACTIVITY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SERVICEACTIVITY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/TransactionActivity.hxx>

#include <teamcenter/soa/client/model/ServiceprocessingMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ActivityEntryValue;


class TCSOASERVICEPROCESSINGMODELMNGD_API ServiceActivity : public Teamcenter::Soa::Client::Model::TransactionActivity
{
public:
    const Teamcenter::Soa::Common::DateTime& get_needed_by_date();
    const std::string& get_activity_number();
    const std::string& get_authorized_by();
    bool get_is_preventative_maintenance();
    const std::string& get_category();
    const std::string& get_usage_path();
    size_t count_activity_entry_value();
    Teamcenter::Soa::Common::AutoPtr<ActivityEntryValue> get_activity_entry_value_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ServiceActivity")

   virtual ~ServiceActivity();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServiceprocessingMngd_undef.h>
#endif
