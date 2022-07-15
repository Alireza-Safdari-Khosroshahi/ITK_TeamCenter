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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CDM0EVENTSTABLE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CDM0EVENTSTABLE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/TableProperties.hxx>

#include <teamcenter/soa/client/model/Cdm0contractmanagementMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACDM0CONTRACTMANAGEMENTMODELMNGD_API Cdm0EventsTable : public Teamcenter::Soa::Client::Model::TableProperties
{
public:
    const Teamcenter::Soa::Common::DateTime& get_cdm0EndDate();
    const std::string& get_cdm0EventName();
    int get_cdm0OffSet();
    const std::string& get_cdm0Recurrence();
    const Teamcenter::Soa::Common::DateTime& get_cdm0StartDate();
    const Teamcenter::Soa::Common::DateTime& get_cdm0RecurrenceEndDate();
    const std::string& get_cdm0RelativeTo();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cdm0EventsTable")

   virtual ~Cdm0EventsTable();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/Cdm0contractmanagementMngd_undef.h>
#endif
