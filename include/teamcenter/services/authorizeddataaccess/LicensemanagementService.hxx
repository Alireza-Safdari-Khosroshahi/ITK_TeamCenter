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

#ifndef TEAMCENTER_SERVICES_AUTHORIZEDDATAACCESS_LICENSEMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_AUTHORIZEDDATAACCESS_LICENSEMANAGEMENTSERVICE_HXX

#include <teamcenter/services/authorizeddataaccess/_2007_06/Licensemanagement.hxx>
#include <teamcenter/services/authorizeddataaccess/_2009_10/Licensemanagement.hxx>
#include <teamcenter/services/authorizeddataaccess/_2012_09/Licensemanagement.hxx>
#include <teamcenter/services/authorizeddataaccess/_2013_05/Licensemanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/authorizeddataaccess/AuthorizedDataAccess_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Authorizeddataaccess
        {
            class LicensemanagementService;

/**
 * The <code>LicenseManagement</code> service provides operations to manage the Authorized
 * Data Access (ADA) licenses. ADA licenses provide a mechanism to grant time bound
 * access for specified users and groups to classified data. The data can be any <b>WorkspaceObject</b>
 * such as an <b>Item</b>,  <b>ItemRevision</b>,  <b>Dataset</b>, etc. Teamcenter provides
 * three types of licenses based on the type of control needed: ITAR (International
 * Traffic in Arms Regulation),  license for export controlled data,  IP (Intellectual
 * Property) license for proprietary data and Exclude license for revoking access to
 * named users and groups.
 * <br>
 * The operations in this service allow creation, modification and deletion of all three
 * types of ADA licenses. This service also provides operations to query for all ADA
 * licenses, to get details of a specific license, to attach licenses to a <b>WorkspaceObject</b>
 * and to detach them.
 * <br>
 * <br>
 * The LicenseManagement service can be used for supporting following usecases:
 * <br>
 * <br>
 * <ul>
 * <li type="disc">Create an ADA_License business object of type ITAR/IP/Exclude
 * </li>
 * <li type="disc">Modify an ADA_License business object to set/modify lock date, license
 * expiry, users, groups, reason, and in accordance with information
 * </li>
 * <li type="disc">Search for all ADA_License business objects the user has READ access
 * to
 * </li>
 * <li type="disc">Get details of a specific ADA_License business object
 * </li>
 * <li type="disc">Attach ADA_License Business Objects to classified WorkspaceObject
 * business objects to grant access for users and/or groups listed on the licenses
 * </li>
 * <li type="disc">Detach ADA_License business objects from WorkspaceObject business
 * objects
 * </li>
 * <li type="disc">Delete ADA_License business objects the user has access to
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaauthorizeddataaccessstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaauthorizeddataaccesstypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAAUTHORIZEDDATAACCESSSTRONGMNGD_API LicensemanagementService
    : public Teamcenter::Services::Authorizeddataaccess::_2007_06::Licensemanagement,
             public Teamcenter::Services::Authorizeddataaccess::_2009_10::Licensemanagement,
             public Teamcenter::Services::Authorizeddataaccess::_2012_09::Licensemanagement,
             public Teamcenter::Services::Authorizeddataaccess::_2013_05::Licensemanagement
{
public:
    static LicensemanagementService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * This operation gets the properties of anfor each ADA_License business object for
     * each given specified in LicenseIds licenseIds parameter. The properties of the ADA_License
     * business objects are supplied viareturned in LicenseDetails structures as part of
     * LicenseDetailsResponse. The LicenseDetails contains information for properties such
     * as license type, license ID, category, expiry date, lock date, reason, in accordance
     * with, and associated users and groups, for a given license. If a the user does not
     * have the sufficientREAD privilege to the any license,  if the a license ID does not
     * exist or if there is any unexpected error of while getting property information,
     * the errors are returned in the  ServiceData of LicenseDetailsResponse.
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
     *         A list of LicenseDetails structures, one for each found ADA_License business object,
     *         and a ServiceData element as part of LicenseDetailsResponse. The properties of given
     *         ADA_License business objects are returned via LicenseDetails of LicenseDetailsResponse.
     *         If a the user does not have the sufficient READ privilege to the any license,  if
     *         the a license ID does not exist or if there is any unexpected error of while getting
     *         property information, the errors is are returned in ServiceData of LicenseDetailsResponse.
     *
     */
    virtual Teamcenter::Services::Authorizeddataaccess::_2012_09::Licensemanagement::GetLicenseDetailsResponse getLicenseDetails3 ( const std::vector< std::string >& licenseIds ) = 0;

    /**
     * This operation creates or modifies an ADA_License business object for each LicenseDetails
     * supplied. The LicenseDetails contains information for properties such as license
     * type, license ID, category, expiry date, lock date, reason, in accordance with, and
     * associated users and groups, for a given license. If a specified license ID already
     * exists, the rest of the property values are updated on that license. However, if
     * the license ID does not exist, then a new license of the specified type and ID will
     * be created, and the rest of the properties are set on the created license. The user
     * performing the operation will need the privilege specified in the ADA_license_administration_privilege
     * site preference to create/modify an ADA License. If a user does not have the necessary
     * privilege or if there is a validation error, the operation would fail and the error
     * is returned in the ServiceData.
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
     *         The created/updated ADA_License business objects are returned via ServiceData in
     *         Created/Updated lists. If the user does not have sufficient privilege to create/modify
     *         license objects, or if the input parameters are invalid, the errors are returned
     *         in ServiceData.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setLicenseDetails ( const std::vector< Teamcenter::Services::Authorizeddataaccess::_2012_09::Licensemanagement::LicenseDetails >& licenseInfo ) = 0;

    /**
     * This operation creates or modifies an ADA_License business object for each LicenseDetails
     * supplied. The LicenseDetails contains information for properties such as license
     * type, license ID, category, citizenship, expiry date, lock date, reason, in accordance
     * with, and associated users and groups, for a given license. If a specified license
     * ID already exists, the rest of the property values are updated on that license. However,
     * if the license ID does not exist, then a new license of the specified type and ID
     * will be created, and the rest of the properties are set on the created license. The
     * user performing the operation will need the privilege specified in the ADA_license_administration_privilege
     * site preference to create/modify an ADA License. If a user does not have the necessary
     * privilege or if there is a validation error, the operation would fail and the error
     * is returned in the ServiceData.
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
     *         The created/updated ADA_License business objects are returned via ServiceData in
     *         Created/Updated lists. If the user does not have sufficient privilege to create/modify
     *         license objects, or if the input parameters are invalid, the errors are returned
     *         in ServiceData.  If an attempt to change the type of an existing license is made,
     *         partial error 10197 is returned.  If an invalid user citizenship is entered, partial
     *         error 10219 is returned.  If the create or update failed for any other reason, partial
     *         error 10221 is returned.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData createOrUpdateLicense ( const std::vector< Teamcenter::Services::Authorizeddataaccess::_2013_05::Licensemanagement::LicenseDetails >& licenseInfo ) = 0;

    /**
     * This operation gets the properties of  each ADA_License business object for each
     * of the licenseIds parameter. The properties of the ADA_License business objects are
     * returned in LicenseDetails structures as part of LicenseDetailsResponse. The LicenseDetails
     * contains information for properties such as license type, license ID, category, citizenship,
     * expiry date, lock date, reason, in accordance with, and associated users and groups,
     * for a given license. If a the user does not have the sufficient READ privilege to
     * the license,  if the a license ID does not exist or if there is any unexpected error
     * of while getting property information, the errors are returned in the ServiceData
     * of LicenseDetailsResponse.
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
     *         A list of LicenseDetails structures, one for each found ADA_License business object,
     *         and a ServiceData element as part of LicenseDetailsResponse. The properties of given
     *         ADA_License business objects are returned via LicenseDetails of LicenseDetailsResponse.
     *         If a the user does not have the sufficient READ privilege to the any license,  if
     *         the a license ID does not exist or if there is any unexpected error of while getting
     *         property information, the errors is are returned in ServiceData of LicenseDetailsResponse.
     *         If the license cannot be found based on the licenseID given, partial error 10212
     *         is returned.  If the retrieve failed on any of the calls partial error 10220 is returned.
     *
     */
    virtual Teamcenter::Services::Authorizeddataaccess::_2013_05::Licensemanagement::GetLicenseDetailsResponse getLicenseDetails4 ( const std::vector< std::string >& licenseIds ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("LicensemanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/authorizeddataaccess/AuthorizedDataAccess_undef.h>
#endif

