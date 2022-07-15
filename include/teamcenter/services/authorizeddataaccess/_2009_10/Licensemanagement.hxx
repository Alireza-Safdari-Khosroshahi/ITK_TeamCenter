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

#ifndef TEAMCENTER_SERVICES_AUTHORIZEDDATAACCESS__2009_10_LICENSEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_AUTHORIZEDDATAACCESS__2009_10_LICENSEMANAGEMENT_HXX

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
            namespace _2009_10
            {
                class Licensemanagement;

class TCSOAAUTHORIZEDDATAACCESSSTRONGMNGD_API Licensemanagement
{
public:

    struct GetLicenseDetailsResponse;
    struct LicenseDetails;
    struct LicenseInput;

    /**
     * <code>GetLicenseDetailsResponse</code> represents the details of<b> </b><b>ADA_License</b>
     * business objects.
     */
    struct GetLicenseDetailsResponse
    {
        /**
         * Structures containing the properties of <b>ADA_License</b> business objects.
         */
        std::vector< Teamcenter::Services::Authorizeddataaccess::_2009_10::Licensemanagement::LicenseDetails > licDetails;
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
         * The type of ADA License object. The type can be <i>ITAR_License</i>,<i> Exclude_License</i>,
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
         * The freeze date for the license, after which the license cannot be attached to <b>WorkspaceObject</b>
         * business objects. A NULL date specifies the license is not locked.
         */
        Teamcenter::Soa::Common::DateTime lockDate;
        /**
         * A reason for the license to exist. This parameter can be a maximum of 128 bytes.
         * This is an optional parameter and may have value as a blank string
         */
        std::string licenseReason;
        /**
         * The qualifying Code of Federal Regulations (CFR) for ITAR licenses. This is not applicable
         * for IP and Exclude licenses. This parameter can be a maxiumum of 80 bytes. This is
         * an optional parameter and  may have value as a blank string.
         */
        std::string qualifyingCfr;
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
     * <code>LicenseInput</code> represents a list of license IDs of ADA licenses, associated
     * <b>WorkspaceObject</b> business objects, and applicable authorizing paragraph information
     * (valid for <b>ITAR</b> licenses only).
     */
    struct LicenseInput
    {
        /**
         * List of license IDs of ADA licenses. These are strings with a maximum of 128 bytes
         * size.
         */
        std::vector< std::string > selectedLicenses;
        /**
         * List of <b>WorkspaceObject</b> business objects associated with the <code>selectedLicenses</code>.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objects;
        /**
         * List of authorizing paragraphs for the licenses being attached to <b>WorkspaceObject</b>
         * business objects. These are strings with a maximum of 80 bytes size. The size of
         * <code>eadParagraph</code> vector should match the size of the <code>selectedLicenses</code>
         * (each entry in <code>eadParagraph</code> maps to corresponding entry in <code>selectedLicenses</code>).
         * If a paragraph entry is not applicable for a specific license (paragraph entries
         * are applicable only for licenses of <b>ITAR</b> type), then that entry can be left
         * blank. System will ignore any paragraph entry if it is not applicable for a license
         * to be attached. This is an optional parameter
         */
        std::vector< std::string > eadParagraph;
    };




    /**
     * This operation attaches <b>ADA</b>_<b>License</b> business objects to <b>WorkspaceObject</b>
     * business objects such as <b>Item</b>, <b>ItemRevision</b>, <b>Dataset</b>, etc. as
     * specified in each <code>LicenseInput</code>. Optionally, this operation can set/update
     * authorizing paragraph information for the <b>ITAR</b> licenses being attached. Users
     * performing this operation will need <b>IP_ADMIN</b> privilege to both the workspace
     * objects and the licenses being attached, if the licenses are of type <b>IP</b> or
     * <b>Exclude</b>, while <b>ITAR_ADMIN</b><b> </b>privilege is needed to both the workspace
     * objects and the licenses being attached, if the licenses are of <b>ITAR</b> license
     * type. If the user does not have necessary privilege to attach any licenses, or if
     * there is any other error while attaching licenses, the errors are returned as partial
     * errors in <code>ServiceData</code>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use case 1: <b>Attach </b><b>ADA</b><b> licenses to </b><b>WorkspaceObject</b><b>
     * business objects</b>
     * <br>
     * You can attach <b>ADA_License</b> business objects of <b>ITAR</b>/<b>IP</b>/<b>Exclude</b>
     * type to classified <b>WorkspaceObject</b> business objects using <code>attachLicenses</code>
     * operation to grant access for users and/or groups listed on the licenses. Optionally,
     * authorizing paragraph information can be specified for the <b>ITAR</b> licenses being
     * attached through <code>LicenseInput</code> structure.
     * <br>
     * <br>
     * Use Case 2: <b>Modify authorizing paragraph for an attached </b><b>ITAR</b><b> license</b>
     * <br>
     * You can modify the authorizing paragraph information associated with an <b>ITAR</b>
     * license already attached to a <b>WorkspaceObject</b> business object by passing in
     * the license ID of the <b>ITAR</b> license, the <b>WorkspaceObject</b> business object
     * and the modified authorizing paragraph information in <code>LicenseInput</code> structure
     * using <code>attachLicenses</code> operation.
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
     * @param attachLicense
     *        Structures containing information on licenses to attach, workspace objects to attach
     *        to, and associated authorizing paragraph information (applicable for <b>ITAR</b>
     *        licenses).
     *
     * @return
     *         The <b>WorkspaceObject</b> business objects to which the licenses are successfully
     *         attached, are added to Updated list of <code>ServiceData</code>. If the user does
     *         not have necessary privilege to attach any licenses, or if there are any other errors
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
     *         <li type="disc">10193&nbsp;&nbsp;&nbsp;&nbsp;The Authorizing Paragraph information
     *         cannot be set
     *         </li>
     *         <li type="disc">10194&nbsp;&nbsp;&nbsp;&nbsp;License cannot be attached because it
     *         is locked or it has expired
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData attachLicenses ( const std::vector< Teamcenter::Services::Authorizeddataaccess::_2009_10::Licensemanagement::LicenseInput >& attachLicense ) = 0;

    /**
     * This operation gets the properties for each <b>ADA_License</b> business object specified
     * in <code>licenseIds</code> and returns them in <code>LicenseDetails</code> structures
     * as part of <code>GetLicenseDetailsResponse</code>. The <code>LicenseDetails</code>
     * contains information for properties such as license type, license ID, expiry date,
     * lock date, reason, in accordance with, and associated users and groups, for a given
     * license. If there is no matching license for a given license ID, LicenseDetails structure
     * for that license will contain <code>Not_found</code> as the value for license ID,
     * while the rest of the parameters will contain NULL values. However, if the user does
     * not have READ privilege to any license or if there is any unexpected error while
     * getting property information, the errors are returned in the <code>ServiceData</code>
     * of <code>GetLicenseDetailsResponse</code>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: <b>Get properties of an ADA License</b>
     * <br>
     * You can get properties of an <b>ADA_License</b> business object of type ITAR/IP/Exclude
     * using <code>getLicenseDetails2</code> operation by providing license ID for the license.
     * <br>
     * <br>
     * Use Case 2: <b>Check the existence of an ADA License</b>
     * <br>
     * You can check if an <b>ADA_License</b> businesses object with given license ID exists
     * using <code>getLicenseDetails2</code> operation.
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
     *         A list of <code>LicenseDetails</code> structures, one for each <b>ADA_License</b>
     *         business object, and a ServiceData element as part of <code>GetLicenseDetailsResponse</code>.
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
    virtual Teamcenter::Services::Authorizeddataaccess::_2009_10::Licensemanagement::GetLicenseDetailsResponse getLicenseDetails2 ( const std::vector< std::string >& licenseIds ) = 0;

    /**
     * This operation creates or modifies an <b>ADA_License</b> business object for each
     * <code>LicenseDetails</code> supplied. The <code>LicenseDetails</code> contains information
     * for properties such as license type, license ID, expiry date, lock date, reason,
     * in accordance with, and associated users and groups, for a given license. If a specified
     * license ID already exists, the rest of the property values are updated on that license.
     * However, if the license ID does not exist, then a new license of the specified type
     * and ID will be created, and the rest of the properties are set on the created license.
     * The user performing the operation will need the privilege specified in the <b>ADA_license_administration_privilege</b>
     * site preference to create/modify an ADA License. If a user does not have the necessary
     * privilege or if there is a validation error, the operation would fail and the error
     * is returned in the <code>ServiceData</code>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use Case </b><b>1</b><b>: Create an </b><b>ADA</b><b> license</b>
     * <br>
     * You can create a new ADA license of type ITAR/IP/Exclude using <code>setLicenseDetails</code>
     * operation by providing a unique license ID for the license using <code>LicenseDetails</code>
     * structure.
     * <br>
     * <b>
     * <br>
     * Use Case </b><b>2</b><b>: Modify an </b><b>ADA</b><b> License</b>
     * <br>
     * The following types of modifications can be done on existing ADA licenses using <code>setLicenseDetails</code>
     * operation. Other than the license ID and license type, all other parameters of the
     * ADA licenses can be modified using this operation.
     * <br>
     * <ul>
     * <li type="disc">Set an expiry or lock date on a license
     * </li>
     * <li type="disc">Unlock licenses by specifying a NULL date or a future date for lockDate
     * parameter
     * </li>
     * <li type="disc">Add new users and/or groups to a license
     * </li>
     * <li type="disc">Remove users and/or groups from a license
     * </li>
     * <li type="disc">Specify value for qualifying code of federal regulations for ITAR
     * licenses
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
     *         The created/updated <b>ADA_License</b> business objects are returned via <code>ServiceData</code>
     *         in Created/Updated lists. If the user does not have sufficient privilege to create/modify
     *         license objects, or if the input parameters are invalid, the errors are returned
     *         in <code>ServiceData</code>. Following are some possible errors returned in <code>ServiceData</code>:
     *         <br>
     *         <ul>
     *         <li type="disc">10184&nbsp;&nbsp;&nbsp;&nbsp;Lock date is being set on expired licenses
     *         </li>
     *         <li type="disc">10185&nbsp;&nbsp;&nbsp;&nbsp;Lock date is either in the past or beyond
     *         expiry date
     *         </li>
     *         <li type="disc">10186&nbsp;&nbsp;&nbsp;&nbsp;Value for In accordance with is being
     *         set on non ITAR licenses
     *         </li>
     *         <li type="disc">10187&nbsp;&nbsp;&nbsp;&nbsp;Value for In accordance with is more
     *         than 80 bytes in size
     *         </li>
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
    virtual Teamcenter::Soa::Client::ServiceData setLicenseDetails ( const std::vector< Teamcenter::Services::Authorizeddataaccess::_2009_10::Licensemanagement::LicenseDetails >& licenseInfo ) = 0;


protected:
    virtual ~Licensemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/authorizeddataaccess/AuthorizedDataAccess_undef.h>
#endif

