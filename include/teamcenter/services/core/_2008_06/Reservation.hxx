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

#ifndef TEAMCENTER_SERVICES_CORE__2008_06_RESERVATION_HXX
#define TEAMCENTER_SERVICES_CORE__2008_06_RESERVATION_HXX

#include <teamcenter/soa/client/model/User.hxx>
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
            namespace _2008_06
            {
                class Reservation;

class TCSOACORESTRONGMNGD_API Reservation
{
public:





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


protected:
    virtual ~Reservation() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

