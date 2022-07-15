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

#ifndef TEAMCENTER_SERVICES_CORE__2011_06_RESERVATION_HXX
#define TEAMCENTER_SERVICES_CORE__2011_06_RESERVATION_HXX

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
            namespace _2011_06
            {
                class Reservation;

class TCSOACORESTRONGMNGD_API Reservation
{
public:

    struct OkToCheckoutResponse;

    /**
     * This structure contains the list and <code>ServiceData</code> objects. The list contains
     * verdict true or false for passed in object indicating if object can be checked out
     * or not. <code>ServiceData</code> contains error at index where it occurred for each
     * input object.
     */
    struct OkToCheckoutResponse
    {
        /**
         * A list indicating if the input business object can be checked out. "<i>true</i>"
         * indicates the object may be checked out. "<i>false</i>" indicates the object may
         * not be checked out.
         */
        std::vector< bool > verdict;
        /**
         * Contains the partial errors for any objects for which the <code>okToCheckout</code>
         * validation failed.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Reservation() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

