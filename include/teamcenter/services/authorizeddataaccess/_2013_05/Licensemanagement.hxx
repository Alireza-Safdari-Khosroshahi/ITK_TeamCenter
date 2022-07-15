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

#ifndef TEAMCENTER_SERVICES_AUTHORIZEDDATAACCESS__2013_05_LICENSEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_AUTHORIZEDDATAACCESS__2013_05_LICENSEMANAGEMENT_HXX



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
            namespace _2013_05
            {
                class Licensemanagement;

class TCSOAAUTHORIZEDDATAACCESSSTRONGMNGD_API Licensemanagement
{
public:

    struct GetLicenseDetailsResponse;
    struct LicenseDetails;

    /**
     * LicenseDetailsResponse structure represents all the details of an ADA_License business
     * object in licDetails and operation status in serviceData.
     */
    struct GetLicenseDetailsResponse
    {
        /**
         * Structure containing the properties of the given ADA_License business objects.
         */
        std::vector< Teamcenter::Services::Authorizeddataaccess::_2013_05::Licensemanagement::LicenseDetails > licDetails;
        /**
         * ServiceDataContains partial errors encountered while fetching properties for ADA_License
         * business objects. The ADA_License business objects for which properties are fetched
         * successfully are added to the Plan list.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * LicenseDetails structure represents all the details of an ADA License object.
     */
    struct LicenseDetails
    {
        /**
         * The type of ADA License object. The type can be ITAR_License, Exclude_License, or
         * IP_License. The license type of existing licenses cannot be modified. An error will
         * be thrown if the value of licenseType does not match the type of the license being
         * modified.
         */
        std::string licenseType;
        /**
         * The unique ID of the license. This is string with a maximum of 128 bytes.
         */
        std::string licenseId;
        /**
         * The category property of an ADA license. This is an optional parameter of string
         * type 128 bytes in size. The value specified for licenseCategory parameter must match
         * one of the values in the LOV associated with Category property on the specifc ADA
         * license type.This is an optional parameter and may be left as a blank string (&quot;&quot;).
         */
        std::string licenseCategory;
        /**
         * The value for user citizenships property of an ADA license. This is an optional parameter.
         * The value specified for userCitizenships parameter is a two-letter country code.
         * If an invalid country code is entered, partial error code 10219 will be returned.
         */
        std::vector< std::string > userCitizenships;
        /**
         * The expiry date for the license, after which the license cannot be attached to WorkspaceObjects
         * and ceases to grant the access to users/groups listed on the license. The value specified
         * for expiryDate should be greater than or equal to current date, unless the value
         * is same as current value on an existing license. A NULL date specifies the lincense
         * will never expire.
         */
        Teamcenter::Soa::Common::DateTime expiryDate;
        /**
         * The freeze date for the license, after which the license cannot be attached to WorkspaceObjects.
         * The value specified for this parameter should be greater than the current date and
         * should be less than the value specified for expiryDate parameter, unless the value
         * is same as current value on an existing license. A NULL date specifies the license
         * is not locked.
         */
        Teamcenter::Soa::Common::DateTime lockDate;
        /**
         * A reason for the license to exist. This parameter can be a maxiumum of 128 bytes.
         * This is an optional parameter and may be left as a blank string (&quot;&quot;).
         */
        std::string licenseReason;
        /**
         * The qualifying Code of Federal Regulations (CFR) for ITAR licenses. This is not applicable
         * for IP and Exclude licenses. This parameter can be a maxiumum of 80 bytes. This is
         * an optional parameter and  may be left as a blank string (&quot;&quot;).
         */
        std::string qualifyingCfr;
        /**
         * The list of users associated with a license identified by licenseId. When the license
         * is attached to a classified WorkspaceObject, the users listed on the license will
         * get access to the WorkspaceObject, based on the access rules.
         */
        std::vector< std::string > users;
        /**
         * List of names of groups associated with the license identified by licenseId. For
         * sub-groups, the full names should be specified. When the license is attached to a
         * classified WorkspaceObject, the users from the groups/sub-groups listed on the license
         * will get access to the workspace object, based on the access rules. This parameter
         * takes an array of group name strings of upto 256 bytes in size.
         */
        std::vector< std::string > groups;
    };




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


protected:
    virtual ~Licensemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/authorizeddataaccess/AuthorizedDataAccess_undef.h>
#endif

