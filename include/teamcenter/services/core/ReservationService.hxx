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

#ifndef TEAMCENTER_SERVICES_CORE_RESERVATIONSERVICE_HXX
#define TEAMCENTER_SERVICES_CORE_RESERVATIONSERVICE_HXX

#include <teamcenter/services/core/_2006_03/Reservation.hxx>
#include <teamcenter/services/core/_2008_06/Reservation.hxx>
#include <teamcenter/services/core/_2011_06/Reservation.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            class ReservationService;

/**
 * This service exposes operations related to reservations in Teamcenter. The reservation
 * concept is used to gain exclusive rights to Teamcenter business objects so that multiple
 * users don't modify the same object accidently. There are underlying complex rules
 * for reservation governing each object based on type of objects. Many business objects
 * (e.g. <b>Dataset</b> and <b>ItemRevision</b>) have their own set of validations and
 * internal implementation on how reservation works. Broadly user can perform <code>checkout</code>
 * operation which gives exclusive modification right to given business object; <code>checkin</code>
 * operation that makes sure that checked out business object status is saved and exclusive
 * right on that object is withdrawn so as other user can do checkout on this object;
 * <code>cancelCheckout</code> operation that is applicable to certain business objects
 * only<code>; getReservationHistory</code> operation provides history for a given business
 * objects on how reservation operations were applied for a given business object.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoacorestrongmngd.dll
 * </li>
 * <li type="disc">libtcsoacoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACORESTRONGMNGD_API ReservationService
    : public Teamcenter::Services::Core::_2006_03::Reservation,
             public Teamcenter::Services::Core::_2008_06::Reservation,
             public Teamcenter::Services::Core::_2011_06::Reservation
{
public:
    static ReservationService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * This operation transfers the previously checked-out business objects to the user
     * given from input. This operation takes care of all complex business logic involved
     * in transfer checked-out based on passed in objects. Each input object is verified
     * that it is valid for transferring its checkout.
     * <br>
     * This operation validates precondition defined per type in COTS object and site customization
     * before performing transfer checked-out objects to the target user. <b>Dataset</b>,
     * <b>ItemRevision</b> and many other business object types have their own business
     * logic for transfer check-out. This operation calls underlying transfer checkout method
     * of those individual objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Reservation - A reservation is created by a user by checking out the master copy
     * at the owning site.  A reservation prevents other users from checking out the master
     * copy; and from transferring site ownership by effectively placing a lock on the master.
     *
     * @param objects
     *        A list of the previously checked-out Teamcenter objects (e.g. <b>Dataset</b>, <b>Item</b>,
     *        <b>ItemRevision</b> ) to transfer the checkout.
     *
     * @param userId
     *        The Teamcenter user id to who checked-out has to be transferred to.
     *
     * @return
     *         The objects that are transferred checked-out successfully are added to the <code>ServiceData</code>
     *         updated list. <code>ServiceData</code> also contains any partial error. The index
     *         of the input business object is included in the partial error. Some of the possible
     *         error situations are explained here with valid error codes:
     *         <br>
     *         <ul>
     *         <li type="disc">32015:&nbsp;&nbsp;&nbsp;&nbsp;The object is not checked out, so this
     *         is not a valid candidate for check-in.
     *         </li>
     *         <li type="disc">32056:&nbsp;&nbsp;&nbsp;&nbsp;The object is already checked-out by
     *         the target user. Transfer of check-out must be to a different user.
     *         </li>
     *         <li type="disc">32080:&nbsp;&nbsp;&nbsp;&nbsp;The object is checked-out to a remote
     *         site. The operation must be performed at the remote site.
     *         </li>
     *         <li type="disc">9175: This action can not be performed when the <b>Dataset</b> is
     *         referenced to more than one <b>ItemRevision</b> object with the <code>attach</code>
     *         relation
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData transferCheckout ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  userId ) = 0;

    /**
     * This operation determines whether or not the input objects may be checked out given
     * the type of object, access rules, and current checkout state of the object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Reservation - A reservation is created by a user by checking out the master copy
     * at the owning site.  A reservation prevents other users from checking out the master
     * copy; and from transferring site ownership by effectively placing a lock on the master.
     *
     * @param objects
     *        The list of objects which should be validated for Checkout.
     *
     * @return
     *         This operation returns a verdict true or false for each passed in object in output
     *         structure <code>OkToCheckoutResponse</code>. This structure contains list and <code>ServiceData</code>.
     *         The list contains the verdict and <code>ServiceData</code> contains error at index
     *         where it occurred.
     *         <br>
     *         The possible partial error 32053 is returned if the object's type is not supported
     *         by the check out facility.
     *
     */
    virtual Teamcenter::Services::Core::_2011_06::Reservation::OkToCheckoutResponse okToCheckout ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ReservationService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/core/Core_undef.h>
#endif

