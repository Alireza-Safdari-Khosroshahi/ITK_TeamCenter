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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TCCALENDAREVENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TCCALENDAREVENT_HXX

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
                class TCCalendar;
                class Range;


class TCSOACLIENTMNGD_API TCCalendarEvent : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<TCCalendar> get_tccalendar_tag();
    const Teamcenter::Soa::Common::DateTime& get_first_recur_start();
    const Teamcenter::Soa::Common::DateTime& get_first_recur_end();
    const Teamcenter::Soa::Common::DateTime& get_event_expiry_date();
    int get_event_type();
    int get_num_recurrences();
    int get_recur_interval();
    int get_recur_days_of_week();
    int get_recur_weeks_of_month();
    int get_recur_month();
    size_t count_event_range();
    Teamcenter::Soa::Common::AutoPtr<Range> get_event_range_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TCCalendarEvent")

   virtual ~TCCalendarEvent();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
