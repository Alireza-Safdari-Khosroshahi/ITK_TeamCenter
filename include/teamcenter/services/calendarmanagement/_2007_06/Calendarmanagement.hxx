/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SERVICES_CALENDARMANAGEMENT__2007_06_CALENDARMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CALENDARMANAGEMENT__2007_06_CALENDARMANAGEMENT_HXX

#include <teamcenter/soa/client/model/Schedule.hxx>
#include <teamcenter/soa/client/model/TCCalendar.hxx>
#include <teamcenter/soa/client/model/TCCalendarEvent.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/calendarmanagement/CalendarManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Calendarmanagement
        {
            namespace _2007_06
            {
                class Calendarmanagement;

class TCSOACALENDARMANAGEMENTSTRONGMNGD_API Calendarmanagement
{
public:

    struct CalendarData;
    struct CalendarContainer;
    struct CalendarEventData;
    struct CalendarResponse;
    struct CalendarUpdate;
    struct CreateCalendarResponse;
    struct ModifyCalendarEvent;
    struct RangeData;

    /**
     * The information necessary to create a single TCCalendar including daily default ranges.
     */
    struct CalendarData
    {
        /**
         * The name of the calendar
         */
        std::string name;
        /**
         * The description of the calendar
         */
        std::string description;
        /**
         * The schedule this calendar relates to (or null)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Schedule>  schedule;
        /**
         * The resource this calendar relates to (or null)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  source;
        /**
         * The parent BASE calendar (or null)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCCalendar>  baseCalendar;
        /**
         * The type of calendar
         */
        int type;
        /**
         * The ranges for Sunday
         */
        std::vector< Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::RangeData > sunRanges;
        /**
         * The ranges for Monday
         */
        std::vector< Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::RangeData > monRanges;
        /**
         * The ranges for Tuesday
         */
        std::vector< Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::RangeData > tueRanges;
        /**
         * The ranges for Wednesday
         */
        std::vector< Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::RangeData > wedRanges;
        /**
         * The ranges for Thursday
         */
        std::vector< Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::RangeData > thuRanges;
        /**
         * The ranges for Friday
         */
        std::vector< Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::RangeData > friRanges;
        /**
         * The ranges for Saturday
         */
        std::vector< Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::RangeData > satRanges;
    };

    /**
     * A container to hold the Calendar Events related to CalendarData
     */
    struct CalendarContainer
    {
        /**
         * The Calendar information
         */
        Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::CalendarData tccalendarAttributes;
        /**
         * The event information
         */
        std::vector< Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::CalendarEventData > newEvents;
    };

    /**
     * The information for a single CalendarEvent.
     */
    struct CalendarEventData
    {
        /**
         * The date of the event
         */
        Teamcenter::Soa::Common::DateTime firstRecurStart;
        /**
         * Placeholder for recurring end date. (not currently used)
         */
        Teamcenter::Soa::Common::DateTime firstRecurEnd;
        /**
         * Placeholder for recurring event expiration. (not currently used)
         */
        Teamcenter::Soa::Common::DateTime eventExpiryDate;
        /**
         * The time ranges for the event
         */
        std::vector< Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::RangeData > eventRanges;
        /**
         * Placeholder for event type. (not currently used)
         */
        int eventType;
        /**
         * Placeholder number of recurrences. (not currently used)
         */
        int numRecurrences;
        /**
         * Placeholder for the recurring interval. (not currently used)
         */
        int recurInterval;
        /**
         * Placeholder for mask of days. (not currently used)
         */
        int recurDaysOfWeek;
        /**
         * Placeholder for mask of weeks. (not currently used)
         */
        int recurWeeksOfMonth;
        /**
         * Placeholder for mask of months. (not currently used)
         */
        int recurMonth;
    };

    /**
     * The response containing a created calendars and the events.
     */
    struct CalendarResponse
    {
        /**
         * The calendar
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCCalendar>  calendar;
        /**
         * The events related to that calendar.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCCalendarEvent>  > calendarEvent;
    };

    /**
     * The information necessary to modify a calendar.
     */
    struct CalendarUpdate
    {
        /**
         * The calendar to modify
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCCalendar>  calendar;
        /**
         * The basic calendar data to modify
         */
        Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::CalendarData calendarAttributes;
        /**
         * New calendar events to add
         */
        std::vector< Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::CalendarEventData > eventsToAdd;
        /**
         * Existing calendar events to delete
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCCalendarEvent>  > eventsToDelete;
        /**
         * Calendar events to update.
         */
        std::vector< Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::ModifyCalendarEvent > eventsToUpdate;
    };

    /**
     * The container with ALL the CalendarResponse and the service data.
     */
    struct CreateCalendarResponse
    {
        /**
         * The service data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * The calendars and events
         */
        std::vector< Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::CalendarResponse > calendarResponse;
    };

    /**
     * The information necessary to modify a calendar event.
     */
    struct ModifyCalendarEvent
    {
        /**
         * The event to modify
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCCalendarEvent>  event;
        /**
         * The new event data
         */
        Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::CalendarEventData eventAttributes;
    };

    /**
     * A single time range.  The startRange and endRange represent minutes since midnight.
     * There is a special range (startRange=480 and endRange=480) which represents a non-working
     * range.
     */
    struct RangeData
    {
        /**
         * The starting offset.
         */
        int startRange;
        /**
         * The ending offset.
         */
        int endRange;
    };




    /**
     * Creates new calendars based on the provided input parameters.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calendar Management - Application in Teamcenter to manage calendars in project schedules
     *
     * @param newTCCalendars
     *        A vector of CalendarContainer structures that holds the various attributes for the
     *        calendar to be created. This includes any new calendar events.
     *
     * @return
     *         Contains the calendar and calendar event objects. It also contains serviceData that
     *         has the error stack if partial or all operations fail.
     *
     * @deprecated
     *         As of Teamcenter 8.2, use the createCalendars operation from the _2010_04 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.2, use the createCalendars operation from the _2010_04 namespace."))
#endif
    virtual Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::CreateCalendarResponse createCalendars ( const std::vector< Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::CalendarContainer >& newTCCalendars ) = 0;

    /**
     * Updates the specified calendars and their events. This includes creating, modifying
     * and deleting events associated with specified calendars
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calendar Management - Application in Teamcenter to manage calendars in project schedules
     *
     * @param tccalendarUpdates
     *        Contains a vector of CalendarUpdate structures. The CalendarUpdate contains the calendar
     *        to be updated and the CalendarData structure that holds its new attribute values.
     *        It also includes vectors that specify the following event modifications for each
     *        calendar: 1. UID of the calendar to modify 2. CalendarData containing calendar attributes
     *        to be updated 3. Vector of CalendarEventData containing data for creating new events
     *        4. Vector of events to be deleted 5. Vector of events to be updated
     *
     * @return
     *         Contains the calendar and calendar event objects ServiceData also includes the error
     *         stack if partial or all operations fail.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData updateCalendars ( const std::vector< Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::CalendarUpdate >& tccalendarUpdates ) = 0;


protected:
    virtual ~Calendarmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/calendarmanagement/CalendarManagement_undef.h>
#endif

