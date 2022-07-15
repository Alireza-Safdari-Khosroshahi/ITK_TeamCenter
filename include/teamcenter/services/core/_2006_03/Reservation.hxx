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

#ifndef TEAMCENTER_SERVICES_CORE__2006_03_RESERVATION_HXX
#define TEAMCENTER_SERVICES_CORE__2006_03_RESERVATION_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2006_03
            {
                class Reservation;

class TCSOACORESTRONGMNGD_API Reservation
{
public:

    struct GetReservationHistoryResponse;
    struct ReservationHistory;
    struct ReservationHistoryEvent;

    /**
     * GetReservationHistoryResponse
     */
    struct GetReservationHistoryResponse
    {
        /**
         * Reservation history.
         */
        std::vector< Teamcenter::Services::Core::_2006_03::Reservation::ReservationHistory > histories;
        /**
         * Objects which are queried successfully are added to the ServiceData plain list.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Reservation history.
     */
    struct ReservationHistory
    {
        /**
         * Object of reservation history.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * Sequence of history events, earliest first.
         */
        std::vector< Teamcenter::Services::Core::_2006_03::Reservation::ReservationHistoryEvent > events;
    };

    /**
     * Single event in reservation history.
     */
    struct ReservationHistoryEvent
    {
        /**
         * Date and time of event.
         */
        std::string dateTime;
        /**
         * User name.
         */
        std::string user;
        /**
         * Event type.  "<i>Check-Out</i>"/"<i>Check-In</i>"/"<i>Cancel Check-Out</i>".
         */
        std::string activity;
        /**
         * change id as provided during <code>checkout</code> operation.
         */
        std::string changeId;
        /**
         * User comment
         */
        std::string comment;
    };




    /**
     * This operation cancels a check-out for a set of previously checked-out business objects.
     * The objects will be restored to the pre-check-out state. Only one user can perform
     * a cancel check-out transaction on the object if the user has enough privilege on
     * the object.  This action may be applied to remote checked out objects, and will cancel
     * the check-out and records the cancel check-out transaction event. Cancel checkout
     * is not supported for some of the business objects for e.g. - <b>Item</b>, <b>BOMView</b>,<b>BOMViewRevision</b>,
     * <b>Schedule</b>.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * checkout
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Reservation - A reservation is created by a user by checking out the master copy
     * at the owning site.  A reservation prevents other users from checking out the master
     * copy; and from transferring site ownership by effectively placing a lock on the master.
     *
     * @param objects
     *        A list of objects to be canceled for previously check-out.
     *
     * @return
     *         The canceled checked out business objects are returned in the updated list. Any failures
     *         are returned as partial errors with the index of the input object included in the
     *         partial error.
     *         <br>
     *         The following errors may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">26012:&nbsp;&nbsp;&nbsp;&nbsp;The passed in buisess object is NULL.
     *         </li>
     *         <li type="disc">32015: The business object is not checked out.
     *         </li>
     *         <li type="disc">32027:&nbsp;&nbsp;&nbsp;&nbsp;The user does not have sufficient privilege
     *         to perform the option.
     *         </li>
     *         <li type="disc">32061: The cancel checkout action is not supported for the business
     *         object type.
     *         </li>
     *         <li type="disc">32095: The business object is checked out to a different site.
     *         </li>
     *         <li type="disc">51024:&nbsp;&nbsp;&nbsp;&nbsp;The business object is not valid.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData cancelCheckout ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects ) = 0;

    /**
     * This operation checks-in a set of previously checked-out business objects. This operation
     * takes care of all complex business logic involved to check-in passed in business
     * objects.  Each input object is verified that it is locally owned, site owned, and
     * not transferred to another user after the checkout was performed. This operation
     * validates precondition defined per type in COTS object and site customization and
     * performs basic check-in. <b>Dataset</b>, <b>ItemRevision</b> and many other business
     * object types have their own business logic for check-in. This operation calls underlying
     * <code>checkin</code> method of those individual objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Reservation - A reservation is created by a user by checking out the master copy
     * at the owning site.  A reservation prevents other users from checking out the master
     * copy; and from transferring site ownership by effectively placing a lock on the master.
     *
     * @param objects
     *        Set of previously checked-out valid business objects. (e.g. <b>Dataset</b>, <b>Item</b>,
     *        <b>ItemRevision</b> )
     *
     * @return
     *         Objects which check in successfully are returned in the updated list. Any errors
     *         that occur while processing a input business object will be returned as a partial
     *         error. The index of the input business object is included in the partial error. The
     *         following errors may be returned:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">26012:&nbsp;&nbsp;&nbsp;&nbsp;Passed in business object is NULL,
     *         or is invalid.
     *         </li>
     *         <li type="disc">32015:&nbsp;&nbsp;&nbsp;&nbsp;The business object is not checked
     *         out.
     *         </li>
     *         <li type="disc">32205: A system exception while performing a remote check in for
     *         a given object.
     *         </li>
     *         <li type="disc">32095: The object is checked out to the site but not locally checked
     *         out. This is a precondition before performing the check in operation. The passed
     *         in object is not checked out to the local site.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData checkin ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects ) = 0;

    /**
     * This operation checks  out a set of business objects with given comment and change
     * identifier. Only one user can perform a check-out transaction on the object. The
     * user must have sufficient  privilege on the object or the check out will fail. This
     * operation allows for remote check-out and records the check-out transaction event.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Reservation - A reservation is created by a user by checking out the master copy
     * at the owning site.  A reservation prevents other users from checking out the master
     * copy; and from transferring site ownership by effectively placing a lock on the master.
     *
     * @param objects
     *        A list of business objects to be checked out.
     *
     * @param comment
     *        A comment describing the reason for the check-out.  An empty string is allowed.
     *
     * @param changeId
     *        A string value to identify the change.  Empty string allowed.
     *
     * @return
     *         The checked out business objects are returned in the updated list. Any failures are
     *         returned as partial errors with the index of  the input object included in the partial
     *         error. The following errors may be returned:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">26012:   The passed in business object is NULL.
     *         </li>
     *         <li type="disc">515024: The passed in business object is not valid.
     *         </li>
     *         <li type="disc">32053:&nbsp;&nbsp;&nbsp;&nbsp;The check out operation is not supported
     *         for the given business object.
     *         </li>
     *         <li type="disc">32027:&nbsp;&nbsp;&nbsp;&nbsp;The user does not have sufficient privilege
     *         to perform the check out.
     *         </li>
     *         <li type="disc">32051:&nbsp;&nbsp;&nbsp;&nbsp;The selected business object is archived
     *         and therefore cannot be checked out.
     *         </li>
     *         <li type="disc">32009:&nbsp;&nbsp;&nbsp;&nbsp;The selected business object is already
     *         checked out by another user or different session.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData checkout ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects,
        const std::string&  comment,
        const std::string&  changeId ) = 0;

    /**
     * This operation gets the reservation history for a set of business objects, such as
     * <b>Dataset</b>, <b>Item</b>, <b>ItemRevision</b> and many other business object types.
     * An object which has never been checked out will have a valid reservation history
     * with an empty sequence of events.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Reservation - A reservation is created by a user by checking out the master copy
     * at the owning site.  A reservation prevents other users from checking out the master
     * copy; and from transferring site ownership by effectively placing a lock on the master.
     *
     * @param objects
     *        A list of business objects to query for reservation history.
     *
     * @return
     *         The list of reservation history for each of the input objects. The objects which
     *         are queried successfully are added to the <code>ServiceData</code> plain list.
     *         <br>
     *         If there is no valid history or exception is raised for this operation then <code>ServiceData</code>
     *         contains passed in object at index where errors have occurred. The following errors
     *         may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">26012:   The passed in business object is NULL.
     *         </li>
     *         <li type="disc">515024: The passed in business object is not valid.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2006_03::Reservation::GetReservationHistoryResponse getReservationHistory ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects ) = 0;


protected:
    virtual ~Reservation() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

