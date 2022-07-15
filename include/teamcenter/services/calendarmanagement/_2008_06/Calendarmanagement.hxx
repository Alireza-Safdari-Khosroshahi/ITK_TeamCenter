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

#ifndef TEAMCENTER_SERVICES_CALENDARMANAGEMENT__2008_06_CALENDARMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CALENDARMANAGEMENT__2008_06_CALENDARMANAGEMENT_HXX

#include <teamcenter/services/calendarmanagement/_2007_06/Calendarmanagement.hxx>
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
            namespace _2008_06
            {
                class Calendarmanagement;

class TCSOACALENDARMANAGEMENTSTRONGMNGD_API Calendarmanagement
{
public:

    struct CalendarData;
    struct CalendarContainer;
    struct CalendarUpdate;

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
         * The type of calendar (1-System Calendar, 2-Schedule Calendar, 3-User Calendar, 4-ScheduleMember
         * Calendar)
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
        /**
         * The timezone id (as specified in the Olson database eg, 'America/New_York' for US
         * Eastern time)
         */
        std::string timeZone;
    };

    /**
     * A container to hold the Calendar Events related to CalendarData
     */
    struct CalendarContainer
    {
        /**
         * The Calendar information
         */
        Teamcenter::Services::Calendarmanagement::_2008_06::Calendarmanagement::CalendarData tccalendarAttributes;
        /**
         * The event information
         */
        std::vector< Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::CalendarEventData > newEvents;
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
        Teamcenter::Services::Calendarmanagement::_2008_06::Calendarmanagement::CalendarData calendarAttributes;
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
     * This operation creates a list of calendars based on the users request to the application
     * interface.
     * <br>
     * <b> User, Resource, Schedule, Base Calendars</b> can be created .
     * <br>
     * The information needed to create <b>Calendar</b> are specified in the <code>CalendarContainer</code>
     * structure. It returns <code>CreateCalendarResponses</code>   which contains the response
     * data from the create request .Errors will be returned in the list of partial errors
     * in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calendar Management - Application in Teamcenter to manage calendars in project schedules
     *
     * @param newTCCalendars
     *        A vector of <code>CalendarContainer</code> structures that holds the various attributes
     *        for
     *        <br>
     *        the calendar to be created. This includes any new calendar events.
     *        <br>
     *        <br>
     *        <br>
     *
     * @return
     *         This operation returns the response data from the create request.
     *         <br>
     *         The <code>CreateCalendarResponse</code> object containing a list of <code>CreateCalendarResponse</code>
     *         objects , one for each successfully created  <b>Calendar</b>, and a <code>ServiceData</code>
     *         element. The newly created <b>Calendars</b> are added to the created list of the
     *         <code>ServiceData</code>. If the user does not have write permission to the calendar
     *         container object, the calendar container object will be attached to the partial error.
     *         <br>
     *         <br>
     *         Following are some possible errors returned:
     *         <br>
     *         <ul>
     *         <li type="disc">148 -<b> TCCalendar</b> already exists
     *         </li>
     *         <li type="disc">150 - Only a dba can create calendar for another user
     *         </li>
     *         <li type="disc">153 - Only a dba can create base calendar
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement::CreateCalendarResponse createCalendars ( const std::vector< Teamcenter::Services::Calendarmanagement::_2008_06::Calendarmanagement::CalendarContainer >& newTCCalendars ) = 0;

    /**
     * This operation updates the list of specified calendars and their events based on
     * the users request to the application interface. This includes creating, modifying
     * and deleting events associated with list of specified calendars. The information
     * needed to update calendars is specified in the <code>CalendarUpdate</code> structure.
     * It returns service data which contains the response data from the update request.
     * Errors will be returned in the list of partial errors in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calendar Management - Application in Teamcenter to manage calendars in project schedules
     *
     * @param tccalendarUpdates
     *        Contains a vector of <code>CalendarUpdate</code> structures. The <code>CalendarUpdate</code>
     *        contains
     *        <br>
     *        the calendar to be updated and the <code>CalendarData</code> structure that holds
     *        its new attribute values. It also includes vectors that specify the following event
     *        modifications for each calendar:
     *        <br>
     *        1. <b>UID</b> of the calendar to modify
     *        <br>
     *        2. <code>CalendarData</code> containing calendar attributes to be updated
     *        <br>
     *        3. Vector of <code>CalendarEventData</code> containing data for creating new events
     *        <br>
     *        4. Vector of events to be deleted
     *        <br>
     *        5. Vector of events to be updated
     *        <br>
     *
     * @return
     *         This operation returns the response data from the update request. It contains the
     *         calendar and calendar event objects, service data. If the input parameters are invalid
     *         or if sufficient conditions are not met for performing the <code>updateCalendars</code>
     *         operation,errors are returned.
     *         <br>
     *         Following are some possible errors returned:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">148 - <b>TCCalendar</b> already exists
     *         </li>
     *         <li type="disc">151 - Only a <b>dba</b> can update calendar for another user
     *         </li>
     *         <li type="disc">154 - Only a <b>dba</b> can update base calendar
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData updateCalendars ( const std::vector< Teamcenter::Services::Calendarmanagement::_2008_06::Calendarmanagement::CalendarUpdate >& tccalendarUpdates ) = 0;


protected:
    virtual ~Calendarmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/calendarmanagement/CalendarManagement_undef.h>
#endif

