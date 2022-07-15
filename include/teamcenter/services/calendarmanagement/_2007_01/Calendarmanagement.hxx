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

#ifndef TEAMCENTER_SERVICES_CALENDARMANAGEMENT__2007_01_CALENDARMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CALENDARMANAGEMENT__2007_01_CALENDARMANAGEMENT_HXX

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
            namespace _2007_01
            {
                class Calendarmanagement;

class TCSOACALENDARMANAGEMENTSTRONGMNGD_API Calendarmanagement
{
public:

    struct GetTCCalendarData;
    struct TCCalendarData;
    struct NewTCCalendar;
    struct TCCalendarContainer;
    struct TCCalendarEventData;
    struct TCCalendarModification;
    struct TCCalendarResponse;
    struct TCCalendarUpdate;

    /**
     * ActionString
     */
    enum ActionString{ MergeSchedule,
                 ResetSchedule
                 };

    /**
     * The query information for calendars
     */
    struct GetTCCalendarData
    {
        /**
         * The type of TCCalendar (1-System Calendar, 2-Schedule Calendar, 3-User Calendar,
         * 4-ScheduleMember Calendar)
         */
        int type;
        /**
         * The related schedule
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  schedule;
        /**
         * The related resource
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  resource;
    };

    /**
     * Data for a calendar
     */
    struct TCCalendarData
    {
        /**
         * Name of the tccalendar
         */
        std::string name;
        /**
         * Description of the tccalendar
         */
        std::string description;
        /**
         * Null indicates no schedule
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  schedule;
        /**
         * TCCalendar source(schedule/resource)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  source;
        /**
         * Type of tccalendar
         */
        int type;
        /**
         * Default minutes for Sunday
         */
        int minsSun;
        /**
         * Default minutes for Monday
         */
        int minsMon;
        /**
         * Default minutes for Tuesday
         */
        int minsTue;
        /**
         * Default minutes for Wednesday
         */
        int minsWed;
        /**
         * Default minutes for Thursday
         */
        int minsThu;
        /**
         * Default minutes for Friday
         */
        int minsFri;
        /**
         * Default minutes for Saturday
         */
        int minsSat;
    };

    /**
     * Holder for new tccalendar and its events
     */
    struct NewTCCalendar
    {
        /**
         * The calendar data
         */
        Teamcenter::Services::Calendarmanagement::_2007_01::Calendarmanagement::TCCalendarData tccalendarAttributes;
        /**
         * The calendar events.
         */
        std::vector< Teamcenter::Services::Calendarmanagement::_2007_01::Calendarmanagement::TCCalendarEventData > newEvents;
    };

    /**
     * Holder for TCCalendar and its events
     */
    struct TCCalendarContainer
    {
        /**
         * The TCCalendar
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCCalendar>  tccalendar;
        /**
         * The TCCalendarEvents for the TCCalendar.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCCalendarEvent>  > events;
    };

    /**
     * Data for a calendar event.
     */
    struct TCCalendarEventData
    {
        /**
         * The date on which event occurs
         */
        Teamcenter::Soa::Common::DateTime eventDate;
        /**
         * The duration of the event in minutes
         */
        int eventMin;
    };

    /**
     * Modification structure
     */
    struct TCCalendarModification
    {
        /**
         * TCCalendar to modify
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCCalendar>  scheduleTCCalendar;
        /**
         * enumerated action
         */
        ActionString action;
    };

    /**
     * Standard response for most tccalendar calls
     */
    struct TCCalendarResponse
    {
        /**
         * The calendar containers
         */
        std::vector< Teamcenter::Services::Calendarmanagement::_2007_01::Calendarmanagement::TCCalendarContainer > tccalendars;
        /**
         * The service data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * A calendar update
     */
    struct TCCalendarUpdate
    {
        /**
         * The calendar being updated
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCCalendar>  tccalendar;
        /**
         * The updated attributes
         */
        Teamcenter::Services::Calendarmanagement::_2007_01::Calendarmanagement::TCCalendarData updatedAttributes;
        /**
         * Events to delete
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCCalendarEvent>  > eventsToDelete;
        /**
         * Events to update
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCCalendarEvent>  > eventsToUpdate;
        /**
         * Corresponding updates for the EventsToUpdate
         */
        std::vector< Teamcenter::Services::Calendarmanagement::_2007_01::Calendarmanagement::TCCalendarEventData > eventAttributes;
        /**
         * Events to create
         */
        std::vector< Teamcenter::Services::Calendarmanagement::_2007_01::Calendarmanagement::TCCalendarEventData > newEvents;
    };




    /**
     * Creates new calendars based on the input parameters.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calendar Management - Application in Teamcenter to manage calendars in project schedules
     *
     * @param newTCCalendars
     *        A vector of NewCalendar structures that holds the various attributes for the calendar
     *        to be created. This includes any new calendar events.
     *
     * @return
     *         A structure that contains a CalendarContainer structure for each calendar which in
     *         turn contains the newly created calendar and all its inherited calendar events. ServiceData
     *         includes the error stack if partial or all operations fail.
     *
     * @deprecated
     *         As of tc2007.1, use the createCalendars operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007.1, use the createCalendars operation."))
#endif
    virtual Teamcenter::Services::Calendarmanagement::_2007_01::Calendarmanagement::TCCalendarResponse createTCCalendars ( const std::vector< Teamcenter::Services::Calendarmanagement::_2007_01::Calendarmanagement::NewTCCalendar >& newTCCalendars ) = 0;

    /**
     * This operation deletes the specified calendars and their calendar events based on
     * the user's request to the application interface. Multiple calendars and its their
     * events can be deleted   through this operation. Existing schedule, resource , and
     * base calendars can be deleted through this operation..
     * <br>
     * The information needed to delete a <b>TCCalendar</b>  object is specified in the
     * <b>TCCalendar</b> structure. It returns  <code>ServiceData</code>  , which is  a
     * common data structure used to return sets of Teamcenter data model objects from a
     * service request. This structure holds lists of data model objects that were 'created',
     * 'deleted', 'updated' or 'plain' in the database with this service request. 'Plain'
     * objects are simply objects that the service is returning where no changes have been
     * made to the database object, i.e. e.g., <code>GetHomeFolder</code> returns a list
     * of objects that are contained in the user's home folder. Errors will be returned
     * in the list of partial errors in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calendar Management - Application in Teamcenter to manage calendars in project schedules
     *
     * @param tccalendarsToDelete
     *        A collection of  <b>TCCalendar</b> structures . Each <b>TCCalendar</b> structure
     *        holds information about the <b>TCCalendar</b> necessary for deletion . Deletes  a
     *        list of specified calendars mentioned in the input. The input parameter is mandatory.
     *        <br>
     *
     * @return
     *         <code>Teamcenter::Soa::Server::ServiceData</code>
     *         <br>
     *         <br>
     *         A list that contains the <code>UIDs</code> of the deleted calendars and its the deleted
     *         calendar events associated with the deleted calendars.  The <code>ServiceData</code>
     *         also includes the error stack if partial or all operations. If the input parameters
     *         are invalid or if sufficient conditions are not met for performing the <code>deleteTCCalendars</code>
     *         operation, errors are returned.
     *         <br>
     *         Following are some possible errors returned:
     *         <br>
     *         <ul>
     *         <li type="disc"> 152 - Only a <b>dba</b> can delete calendar for another user
     *         </li>
     *         <li type="disc"> 155 - Base calendar should not be deleted
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteTCCalendars ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCCalendar>  >& tccalendarsToDelete ) = 0;

    /**
     * This operation gets the list of  calendars based on the user's request to the application
     * interface. Multiple calendars can be obtained through this operation.
     * <br>
     * The information needed to get <b>TCCalendar</b>  objects is specified in the <code>GetTCCalendarData</code>
     * structure. It returns <code>TCCalendarResponse</code> which contains response data
     * from the <code>getcalendar</code> request. Errors will be returned in the list of
     * partial errors in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calendar Management - Application in Teamcenter to manage calendars in project schedules
     *
     * @param getTCCalendars
     *        A vector of <code>GetCalendarData</code> structures that define the required calendars
     *        <br>
     *        with the following parameters:
     *        <br>
     *        1. Type of calendar
     *        <br>
     *        2. Associated schedule if any
     *        <br>
     *        3. Associated resource if any
     *        <br>
     *        The type of parameter is mandatory
     *        <br>
     *
     * @return
     *         A structure that contains the required calendars and their respective events within
     *         <code>CalendarContainer</code> objects. The <code>ServiceData</code> object includes
     *         the error stack if partial or all operations fail.
     *         <br>
     *         <br>
     *         Following are some errors returned :
     *         <br>
     *         <ul>
     *         <li type="disc">147 - Invalid parameter is passed for <b>TCCalendar</b>
     *         </li>
     *         <li type="disc">175 - The base calendar %1$ does not exist.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Calendarmanagement::_2007_01::Calendarmanagement::TCCalendarResponse getTCCalendars ( const std::vector< Teamcenter::Services::Calendarmanagement::_2007_01::Calendarmanagement::GetTCCalendarData >& getTCCalendars ) = 0;

    /**
     * Modifies the specified schedule calendars based on the action string. Reset: Reset
     * the schedule calendar to the base calendar Merge: Merge the schedule calendar with
     * the base calendar
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calendar Management - Application in Teamcenter to manage calendars in project schedules
     *
     * @param modifications
     *        Contains a vector of Schedule Calendars to modify
     *
     * @return
     *         A structure that contains the modified schedule calendars within CalendarContainer
     *         objects. ServiceData includes the error stack if partial or all operations fail.
     *
     * @deprecated
     *         As of Teamcenter 8.2, use the updateCalendars opeation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.2, use the updateCalendars opeation."))
#endif
    virtual Teamcenter::Services::Calendarmanagement::_2007_01::Calendarmanagement::TCCalendarResponse modifyTCCalendars ( const std::vector< Teamcenter::Services::Calendarmanagement::_2007_01::Calendarmanagement::TCCalendarModification >& modifications ) = 0;

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
     *        calendar: 1. Vector of events to be deleted 2. Vector of events to be updated 3.
     *        Vector containing CalendarEventData that specifies new attribute values for the event
     *        4. Vector of CalendarEventData containing data for creating new events
     *
     * @return
     *         A structure that contains the updated calendars within CalendarContainer objects.
     *         The ServiceData object will contain uids of the created, modified and deleted calendar
     *         events. ServiceData also includes the error stack if partial or all operations fail.
     *
     * @deprecated
     *         As of tc2007.1, use the updateCalendars operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007.1, use the updateCalendars operation."))
#endif
    virtual Teamcenter::Services::Calendarmanagement::_2007_01::Calendarmanagement::TCCalendarResponse updateTCCalendars ( const std::vector< Teamcenter::Services::Calendarmanagement::_2007_01::Calendarmanagement::TCCalendarUpdate >& tccalendarUpdates ) = 0;


protected:
    virtual ~Calendarmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/calendarmanagement/CalendarManagement_undef.h>
#endif

