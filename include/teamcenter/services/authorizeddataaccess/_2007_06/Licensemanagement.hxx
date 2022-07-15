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

#ifndef TEAMCENTER_SERVICES_AUTHORIZEDDATAACCESS__2007_06_LICENSEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_AUTHORIZEDDATAACCESS__2007_06_LICENSEMANAGEMENT_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/authorizeddataaccess/AuthorizedDataAccess_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Authorizeddataaccess
        {
            namespace _2007_06
            {
                class Licensemanagement;

class TCSOAAUTHORIZEDDATAACCESSSTRONGMNGD_API Licensemanagement
{
public:

    struct GetLicenseDetailsResponse;
    struct LicenseDetails;
    struct LicenseIdAndType;
    struct LicenseIdsAndTypesResponse;
    struct LicenseInput;
    struct LicenseTypeAndStatusFilter;

    /**
     * <code>GetLicenseDetailsResponse</code> represents the details of<b> </b><b>ADA_License</b>
     * business objects.
     */
    struct GetLicenseDetailsResponse
    {
        /**
         * Structures containing the properties of <b>ADA_License</b> business objects.
         */
        std::vector< Teamcenter::Services::Authorizeddataaccess::_2007_06::Licensemanagement::LicenseDetails > licDetails;
        /**
         * Contains partial errors encountered while fetching properties for <b>ADA_License</b>
         * business objects. The <b>ADA_License</b> business objects for which properties are
         * fetched successfully are added to the Plain list.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>LicenseDetails</code> structure represents all the details of an ADA License
     * object.
     */
    struct LicenseDetails
    {
        /**
         * The type of ADA License object. The type can be <i>ITAR_License</i>, <i>Exclude_License</i>,
         * or <i>IP_License</i>.
         */
        std::string licenseType;
        /**
         * The unique ID of the license. This is string with a maximum of 128 bytes.
         */
        std::string licenseId;
        /**
         * The expiry date for the license, after which the license cannot be attached to <b>WorkspaceObject</b>
         * business objects and ceases to grant the access to users/groups listed on the license.
         * A NULL date specifies the license will never expire.
         */
        Teamcenter::Soa::Common::DateTime expiryDate;
        /**
         * A reason for the license to exist. This parameter can be a maximum of 128 bytes.
         * This is an optional parameter and may have value as a blank string.
         */
        std::string licenseReason;
        /**
         * The list of users associated with a license identified by <code>licenseId</code>.
         * When the license is attached to a classified <b>WorkspaceObject</b>, the users listed
         * on the license will get access to the <b>WorkspaceObject</b>, based on the access
         * rules.
         */
        std::vector< std::string > users;
        /**
         * List of names of groups associated with the license identified by <code>licenseId</code>.
         * For subgroups, the full names should be specified. When the license is attached to
         * a classified <b>WorkspaceObject</b>, the users from the groups/subgroups listed on
         * the license will get access to the workspace object, based on the access rules. This
         * parameter represents an array of group name strings of upto 256 bytes in size.
         */
        std::vector< std::string > groups;
    };

    /**
     * <code>LicenseIdAndType</code> structure Represents license Type and license ID of
     * an ADA License object.
     */
    struct LicenseIdAndType
    {
        /**
         * The type of a license object.  This is string with a maximum of 32 bytes.
         */
        std::string licenseType;
        /**
         * The unique ID of the license object. This is string with a maximum of 128 bytes.
         */
        std::string licenseId;
    };

    /**
     * <code>LicenseIdsAndTypesResponse</code> Represents the license IDs and types of <b>ADA_License</b>
     * business objects.
     */
    struct LicenseIdsAndTypesResponse
    {
        /**
         * Structures containing the license Type and license ID of fetched <b>ADA_License </b>business
         * objects
         */
        std::vector< Teamcenter::Services::Authorizeddataaccess::_2007_06::Licensemanagement::LicenseIdAndType > licIdType;
        /**
         * Contains partial errors encountered while fetching <b>ADA_License</b> business objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>LicenseInput</code> represents a list of license IDs of ADA licenses and the
     * associated <b>WorkspaceObject</b> business objects.
     */
    struct LicenseInput
    {
        /**
         * List of license IDs of ADA licenses. These are strings of each with a maximum of
         * 128 bytes size.
         */
        std::vector< std::string > selectedLicenses;
        /**
         * List of <b>WorkspaceObject</b> business objects associated with the <code>selectedLicenses</code>.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objects;
    };

    /**
     * <code>LicenseTypeAndStatusFilter</code> structure Represents type and status of ADA
     * License objects.
     */
    struct LicenseTypeAndStatusFilter
    {
        /**
         * The type of ADA License objects. The type can be specified as <i>ITAR_License</i>,
         * <i>ExcludeE_License</i>, <i>IP_License</i>, or, ALL. The value of ALL indicates that
         * licenses of all types need to be fetched.
         */
        std::string licType;
        /**
         * The status of ADA License objects. The value should be set to <code>ALL</code> for
         * returning all licenses. Any other value for <code>licStatus</code> returns only unlocked
         * and unexpired licenses.
         */
        std::string licStatus;
    };




    /**
     * This operation attaches ADA Licenses to <b>WorkspaceObject</b> business objects such
     * as <b>Item</b>, <b>ItemRevision</b>, <b>Dataset</b>, etc. as specified in each <code>LicenseInput</code>.
     * <code>LicenseInput</code> provides details on the licenses to be attached, and the
     * <b>WorkspaceObject</b> business objects to attach the licenses to. Users performing
     * this operation will need <b>IP_ADMIN</b> privilege to both the workspace objects
     * and the licenses being attached, if the licenses are of type <b>IP</b> or <b>Exclude</b>,
     * while <b>ITAR_ADMIN</b><b> </b>privilege is needed to both the workspace objects
     * and the licenses being attached if the licenses are of <b>ITAR</b> license type.
     * If the user does not have necessary privilege to attach any licenses, or if there
     * is any other error while attaching licenses, the errors are returned as partial errors
     * in <code>ServiceData</code>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * You can attach <b>ADA_License</b><b> </b>business objects to classified <b>WorkspaceObject</b>
     * business objects to grant access for users and/or groups listed on the licenses.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Authorized Data Access - Authorized Data Access (ADA) is a security solution that
     * complements Access Manager rules to control access to sensitive data through the
     * use of data classification, user clearance, and time bound authorizing documents
     * (ADA Licenses).
     *
     * @param attachLicense
     *        Structures containing information of licenses to attach, and the workspace objects
     *        to attach to.
     *
     * @return
     *         The <b>WorkspaceObject</b> business objects to which the licenses are successfully
     *         attached, are added to Updated list of <code>ServiceData</code>. If the user does
     *         not have necessary privilege to attach any license, or if there are any other errors
     *         while attaching the licenses, the errors are returned as partial errors in <code>ServiceData</code>.
     *         Following are some possible errors returned in <code>ServiceData</code>:
     *         <br>
     *         <ul>
     *         <li type="disc">10163&nbsp;&nbsp;&nbsp;&nbsp;You need IP Admin privilege to attach
     *         license
     *         </li>
     *         <li type="disc">10170&nbsp;&nbsp;&nbsp;&nbsp;You need ITAR Admin privilege to attach
     *         license
     *         </li>
     *         <li type="disc">10194&nbsp;&nbsp;&nbsp;&nbsp;License cannot be attached because it
     *         has expired
     *         </li>
     *         <li type="disc">10196&nbsp;&nbsp;&nbsp;&nbsp;The privilege specified in ADA_license_administration_privilege
     *         site preference is invalid.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData attachLicenses ( const std::vector< Teamcenter::Services::Authorizeddataaccess::_2007_06::Licensemanagement::LicenseInput >& attachLicense ) = 0;

    /**
     * This operation deletes all <b>ADA_License</b><b> </b>business objects specified in
     * <code>licenseIds</code> parameter. Users performing this operation will need privilege
     * specified in <b>ADA_license_administration_privilege</b> site preference to delete
     * the licenses. If the user does not have necessary privilege to delete the licenses,
     * or if any license is attached to workspace objects, or, if there is any other error
     * while deleting the licenses, the errors are returned as partial errors in <code>ServiceData</code>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * You can delete <b>ADA_License</b> business objects of type <b>ITAR</b>/<b>IP</b>/<b>Exclude</b>
     * by providing license IDs for the licenses.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Authorized Data Access - Authorized Data Access (ADA) is a security solution that
     * complements Access Manager rules to control access to sensitive data through the
     * use of data classification, user clearance, and time bound authorizing documents
     * (ADA Licenses).
     *
     * @param licenseIds
     *        License IDs of the ADA licenses to delete.
     *
     * @return
     *         The <b>ADA_License</b> business objects that have been successfully deleted are added
     *         to Deleted list of <code>ServiceData</code>. If the user does not have necessary
     *         privilege to delete the licenses, or, if any license is attached to workspace objects,
     *         or, if there are any other errors while deleting the licenses, the errors are returned
     *         as partial errors in <code>ServiceData</code>. Following are some possible errors
     *         returned in <code>ServiceData</code>:
     *         <br>
     *         <ul>
     *         <li type="disc">10190&nbsp;&nbsp;&nbsp;&nbsp;User does not have necessary privilege
     *         to delete the license
     *         </li>
     *         <li type="disc">51008&nbsp;&nbsp;&nbsp;&nbsp;The license object being tried for delete
     *         is attached to workspace objects
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteLicense ( const std::vector< std::string >& licenseIds ) = 0;

    /**
     * This operation gets the properties for each <b>ADA_License</b> business object specified
     * in <code>licenseIds</code> and returns them in <code>LicenseDetails</code> structures
     * as part of <code>GetLicenseDetailsResponse</code>. The <code>LicenseDetails</code>
     * contains information for properties such as license type, license ID,  expiry date,
     * reason, and associated users and groups, for a given license. If there is no matching
     * license for a given license ID, <code>LicenseDetails</code> structure for that license
     * will contain <code>Not_found</code> as the value for license ID, while the rest of
     * the parameters will contain NULL values. However, if the user does not have READ
     * privilege to any license or if there is any unexpected error while getting property
     * information, the errors are returned in the <code>ServiceData</code> of <code>GetLicenseDetailsResponse</code>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <br>
     * Use Case 1:<b> Get properties of an ADA License</b>
     * <br>
     * You can get properties of an <b>ADA_License</b> business object of type ITAR/IP/Exclude
     * using <code>getLicenseDetails</code> operation by providing license ID for the license.
     * <br>
     * <br>
     * Use Case 2: <b>Check the existence of an ADA License</b>
     * <br>
     * You can check if an <b>ADA_License</b> businesses object with given license ID exists
     * using <code>getLicenseDetails</code> operation.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Authorized Data Access - Authorized Data Access (ADA) is a security solution that
     * complements Access Manager rules to control access to sensitive data through the
     * use of data classification, user clearance, and time bound authorizing documents
     * (ADA Licenses).
     *
     * @param licenseIds
     *        License IDs of the licenses to get properties for.
     *
     * @return
     *         A list of <code>LicenseDetails</code> structures, one for each <b>ADA_License</b><i>
     *         </i>business object, and a ServiceData element as part of <code>GetLicenseDetailsResponse</code>.
     *         If the user does not have the READ privilege to any license or if there is any unexpected
     *         error while getting property information, the errors are returned in <code>ServiceData</code>
     *         of <code>GetLicenseDetailsResponse</code>. Following are some possible errors returned
     *         in <code>ServiceData</code>:
     *         <br>
     *         <ul>
     *         <li type="disc">10190&nbsp;&nbsp;&nbsp;&nbsp;User does not have necessary privilege
     *         to get properties of license
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Authorizeddataaccess::_2007_06::Licensemanagement::GetLicenseDetailsResponse getLicenseDetails ( const std::vector< std::string >& licenseIds ) = 0;

    /**
     * This operation gets all the <b>ADA_License</b> business objects based on license
     * type and license status specified in <code>licenseFilterInput</code> parameter. Licenses
     * of a specific type can be queried for by specifying the license type as <code>ITAR_License</code>,<code>
     * IP_License</code> or <code>Exclude_License</code>. A value of  <code>ALL</code> for
     * the license type returns all types of ADA licenses. If the license status specified
     * is <code>ALL</code>, all ADA licenses are returned, else only unlocked and unexpired
     * licenses are returned. For the <b>ADA_License</b> business objects found, details
     * like license IDs and license types are returned in <code>LicenseIdAndType</code>
     * structures as part of <code>LicenseIdsAndTypesResponse</code>. If there is any unexpected
     * error while getting licenses, the errors are returned in the <code>serviceData</code>
     * of <code>LicenseIdsAndTypesResponse</code>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: <b>Get </b><b>ADA</b><b> Licenses based on type and status</b>
     * <br>
     * You can get <b>ADA_License</b> business objects using <code>getLicenseIdsAndTypes</code>
     * operation based on specified license type and license status.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Authorized Data Access - Authorized Data Access (ADA) is a security solution that
     * complements Access Manager rules to control access to sensitive data through the
     * use of data classification, user clearance, and time bound authorizing documents
     * (ADA Licenses).
     *
     * @param licenseFilterInput
     *        Specifies the  type and  status of ADA licenses to get.
     *
     * @return
     *         A list of <code>LicenseIdAndType</code> structures, one for each <b>ADA_License</b>
     *         business object found, and a ServiceData element as part of <code>LicenseIdsAndTypesResponse</code>.
     *         If there are any unexpected errors while getting the licenses, the errors are returned
     *         in <code>serviceData</code> of <code>LicenseIdsAndTypesResponse</code>.
     *
     */
    virtual Teamcenter::Services::Authorizeddataaccess::_2007_06::Licensemanagement::LicenseIdsAndTypesResponse getLicenseIdsAndTypes ( const std::vector< Teamcenter::Services::Authorizeddataaccess::_2007_06::Licensemanagement::LicenseTypeAndStatusFilter >& licenseFilterInput ) = 0;

    /**
     * This operation removes/detaches ADA Licenses from <b>WorkspaceObject</b> business
     * objects such as <b>Item</b>, <b>ItemRevision</b>, <b>Dataset</b>, etc. as specified
     * in each <i>LicenseInput</i>. <i>LicenseInput</i> provides details of the licenses
     * to be removed, and the <b>WorkspaceObject</b> business objects to remove the licenses
     * from. Users performing this operation will need <b>IP_ADMIN</b> privilege to both
     * the workspace objects and the licenses being removed, if the licenses are of type
     * <b>IP</b> or <b>Exclude</b>, while the privilege specified in <b>ADA_license_administration_privilege</b>
     * site preference is needed to both the workspace objects and the licenses being removed
     * if the licenses are of <b>ITAR</b> license type. If the user does not have necessary
     * privilege to remove any licenses, or if there is any other error while removing licenses,
     * the errors are returned as partial errors in <i>ServiceData</i>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use case:
     * <br>
     * You can remove <b>ADA_License</b> business objects from classified <b>WorkspaceObject</b>
     * business objects to revoke access for users and/or groups listed on the licenses.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Authorized Data Access - Authorized Data Access (ADA) is a security solution that
     * complements Access Manager rules to control access to sensitive data through the
     * use of data classification, user clearance, and time bound authorizing documents
     * (ADA Licenses).
     *
     * @param removeLicense
     *        Structures containing information of licenses to remove, and workspace objects from
     *        which to remove.
     *
     * @return
     *         The <b>WorkspaceObject</b> business objects from which the licenses are successfully
     *         removed, are added to Updated list of <i>ServiceData</i>. If the user does not have
     *         necessary privilege to remove any licenses, or if there are any other errors while
     *         removing the licenses, the errors are returned as partial errors in <i>ServiceData</i>.
     *         Following are some possible errors returned in <i>ServiceData</i>:
     *         <br>
     *         <ul>
     *         <li type="disc">10164&nbsp;&nbsp;&nbsp;&nbsp;You need IP Admin privilege to detach
     *         license
     *         </li>
     *         <li type="disc">10195&nbsp;&nbsp;&nbsp;&nbsp;You do not have necessary privilege
     *         to detach license
     *         </li>
     *         <li type="disc">10196&nbsp;&nbsp;&nbsp;&nbsp;The privilege specified in ADA_license_administration_privilege
     *         site preference is invalid
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData removeLicenses ( const std::vector< Teamcenter::Services::Authorizeddataaccess::_2007_06::Licensemanagement::LicenseInput >& removeLicense ) = 0;

    /**
     * This operation creates or modifies an <b>ADA_License</b> business object for each
     * <code>LicenseDetails</code> supplied. The <code>LicenseDetails</code> contains information
     * for properties such as license type, license ID, expiry date, reason, and associated
     * users and groups, for a given license. If a specified license ID already exists,
     * the rest of the property values are updated on that license. However, if the license
     * ID does not exist, then a new license of the specified type and ID will be created,
     * and the rest of the properties are set on the created license. The user performing
     * the operation will need the privilege specified in the<b> </b><b>ADA_license_administration_privileg</b>e
     * site preference to create/modify an ADA License. If a user does not have the necessary
     * privilege or if there is a validation error, the operation would fail and the error
     * is returned in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use Case 1: Create an ADA license</b>
     * <br>
     * You can create a new ADA license of type ITAR/IP/Exclude using <code>setLicenseDetails</code>
     * operation by providing a unique license ID for the license using <code>LicenseDetails</code>
     * structure.
     * <br>
     * <br>
     * <b>Use Case 2: Modify an ADA License</b>
     * <br>
     * The following types of modifications can be done on existing ADA licenses using <code>setLicenseDetails</code>
     * operation. Other than the license ID and license type, all other parameters of the
     * ADA licenses can be modified using this operation.
     * <br>
     * <ul>
     * <li type="disc">Set an expiry date on a license
     * </li>
     * <li type="disc">Add new users and/or groups to a license
     * </li>
     * <li type="disc">Remove users and/or groups from a license
     * </li>
     * <li type="disc">Set reason for a license
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Authorized Data Access - Authorized Data Access (ADA) is a security solution that
     * complements Access Manager rules to control access to sensitive data through the
     * use of data classification, user clearance, and time bound authorizing documents
     * (ADA Licenses).
     *
     * @param licenseInfo
     *        Structures containing the details of the licenses to be created/modified.
     *
     * @return
     *         The created/updated<b> </b><b>ADA_License</b> business objects are returned via <code>ServiceData</code>
     *         in Created/Updated lists. If the user does not have sufficient privilege to create/modify
     *         license objects, or if the input parameters are invalid, the errors are returned
     *         in <code>ServiceData</code>.
     *         <br>
     *         Following are some possible errors returned in <code>ServiceData</code>:
     *         <br>
     *         <ul>
     *         <li type="disc">10188&nbsp;&nbsp;&nbsp;&nbsp;The expiry date is in the past
     *         </li>
     *         <li type="disc">10189&nbsp;&nbsp;&nbsp;&nbsp;Users and/or groups are being added
     *         to a locked license
     *         </li>
     *         <li type="disc">10190&nbsp;&nbsp;&nbsp;&nbsp;User does not have necessary privilege
     *         to create/modify license
     *         </li>
     *         <li type="disc">10191&nbsp;&nbsp;&nbsp;&nbsp;Group name size is more than 256 bytes
     *         </li>
     *         <li type="disc">10192&nbsp;&nbsp;&nbsp;&nbsp;Subgroup names are being set though
     *         subgroup support is not enabled
     *         </li>
     *         <li type="disc">10197&nbsp;&nbsp;&nbsp;&nbsp;License type of an existing license
     *         is being modified
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setLicenseDetails ( const std::vector< Teamcenter::Services::Authorizeddataaccess::_2007_06::Licensemanagement::LicenseDetails >& licenseInfo ) = 0;


protected:
    virtual ~Licensemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/authorizeddataaccess/AuthorizedDataAccess_undef.h>
#endif

