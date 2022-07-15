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

#ifndef TEAMCENTER_SERVICES_CALENDARMANAGEMENT_CALENDARMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_CALENDARMANAGEMENT_CALENDARMANAGEMENTSERVICE_HXX

#include <teamcenter/services/calendarmanagement/_2007_01/Calendarmanagement.hxx>
#include <teamcenter/services/calendarmanagement/_2007_06/Calendarmanagement.hxx>
#include <teamcenter/services/calendarmanagement/_2008_06/Calendarmanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/calendarmanagement/CalendarManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Calendarmanagement
        {
            class CalendarmanagementService;

/**
 * The <code>CalendarManagement</code> service provides standard operations to satisfy
 * primarily the typical needs of a user dealing with calendar management.  It also
 * enables the user to perform various operations to manage specific calendars and customize
 * them with specified calendar data and calendar events.
 * <br>
 * The <code>CalendarManagement</code> service can be used for supporting following
 * use-cases:
 * <br>
 * <ul>
 * <li type="disc">Creating new calendars
 * </li>
 * <li type="disc">Updating calendars
 * </li>
 * <li type="disc">Getting calendars
 * </li>
 * <li type="disc">Deleting calendars
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoacalendarmanagementstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoacalendarmanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACALENDARMANAGEMENTSTRONGMNGD_API CalendarmanagementService
    : public Teamcenter::Services::Calendarmanagement::_2007_01::Calendarmanagement,
             public Teamcenter::Services::Calendarmanagement::_2007_06::Calendarmanagement,
             public Teamcenter::Services::Calendarmanagement::_2008_06::Calendarmanagement
{
public:
    static CalendarmanagementService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CalendarmanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/calendarmanagement/CalendarManagement_undef.h>
#endif

