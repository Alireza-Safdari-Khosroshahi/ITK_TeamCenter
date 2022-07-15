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

#ifndef TEAMCENTER_SERVICES_ADMINISTRATION__2008_03_IRM_HXX
#define TEAMCENTER_SERVICES_ADMINISTRATION__2008_03_IRM_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/administration/Administration_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Administration
        {
            namespace _2008_03
            {
                class Irm;

class TCSOAADMINISTRATIONSTRONGMNGD_API Irm
{
public:

    struct ActivateUserInput;
    struct DeactivateUserInput;
    struct LicenseStatus;
    struct LicenseStatusResponse;

    /**
     * This structure holds the <b>User</b> object to be activated and the license level
     * to be granted for the user.
     */
    struct ActivateUserInput
    {
        /**
         * The license level to be granted to the user.
         */
        int licenseLevel;
        /**
         * The user to be activated and granted the licnese level.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetUser;
    };

    /**
     * This structure holds the target user to be deactivated and new user and group to
     * take the ownership of objects owned by the target user.
     */
    struct DeactivateUserInput
    {
        /**
         * The user to be deactivated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetUser;
        /**
         * The new user to take ownership transferred from the deactivated user.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  newUser;
        /**
         * The new group to take ownership transferred from the deactivated user.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  newGroup;
    };

    /**
     * This structure  holds the number of licenses purchased and the number of licenses
     * used.
     */
    struct LicenseStatus
    {
        /**
         * The number of licenses purchased.
         */
        int numPurchasedLicenses;
        /**
         * The number of licenses used.
         */
        int numUsedLicenses;
    };

    /**
     * This structure  holds a list of license statuses for the each given user license
     * type.
     */
    struct LicenseStatusResponse
    {
        /**
         * List of LicenseStatus objects, one for each ActivateUserInput object.
         */
        std::vector< Teamcenter::Services::Administration::_2008_03::Irm::LicenseStatus > licStatus;
        /**
         * Object with all activated <b>User</b> objects in updated list and any errors that
         * occurred during activating users.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation can be used to activate user(s) based on the number of allowed active
     * author or consumer licenses. If not enough licenses are available, this operation
     * will return corresponding error code for the given license level.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Organization Management - It maps Organization Management services documentation
     * to BMIDE
     *
     * @param activateUser
     *        A list of ActivateUserInput objects with user and license level to set.
     *
     * @return
     *         This operation returns a LicenseStatusResponse object which contains a list of LicenseStatus
     *         objects one for the given license type. Each LicenseStatus object contains total
     *         available licenses (total licenses purchased) and total licenses in use for a given
     *         license type. User objects which are activated successfully are returned in the updated
     *         list of the ServiceData.Following errors occurred during  activation of the users
     *         will be returned in the error list of the ServiceData for different license levels:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">License Level&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Error
     *         Code and Message
     *         </li>
     *         <li type="disc">Author&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;515245 - The
     *         number of active Author users exceeds the number of purchased licenses.
     *         </li>
     *         <li type="disc">Consumer&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;515246 -
     *         The number of active Consumer users exceeds the number of purchased licenses.
     *         </li>
     *         <li type="disc">Occasional User&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;515254
     *         - The number of active Occasional Users exceeds the number of purchased licenses.
     *         </li>
     *         <li type="disc">Viewer&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;515255 - The
     *         number of active Viewer users exceeds the number of purchased licenses.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Administration::_2008_03::Irm::LicenseStatusResponse activateUsers ( const std::vector< Teamcenter::Services::Administration::_2008_03::Irm::ActivateUserInput >& activateUser ) = 0;

    /**
     * This operation deactivates given users and transfers ownership of the objects owned
     * by the users to be deactivated to new users if the new users are specified. The users
     * deactivated successfully are added in the updated object list of the service data.
     * If new users and groups are specified to take the ownership of the objects owned
     * by the deactivated users, then the new users and groups are added in the updated
     * object list as well after ownership is successfully transferred. This operation requires
     * system administration privilege.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Organization Management - It maps Organization Management services documentation
     * to BMIDE
     *
     * @param deactivateUser
     *        A list of users objects to be deactivated.
     *
     * @return
     *         This operation returns ServiceData object, and the deactivated  user objects are
     *         added to its updated object container. If the login user does not have system administration
     *         privilege, it will return error message  "The operation requires additional privileges
     *         (typically SA)" with error code <b>515002</b>.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deactivateUsers ( const std::vector< Teamcenter::Services::Administration::_2008_03::Irm::DeactivateUserInput >& deactivateUser ) = 0;


protected:
    virtual ~Irm() {}
};
            }
        }
    }
}

#include <teamcenter/services/administration/Administration_undef.h>
#endif

