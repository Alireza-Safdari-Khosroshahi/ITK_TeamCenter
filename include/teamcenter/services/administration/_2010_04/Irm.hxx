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

#ifndef TEAMCENTER_SERVICES_ADMINISTRATION__2010_04_IRM_HXX
#define TEAMCENTER_SERVICES_ADMINISTRATION__2010_04_IRM_HXX

#include <teamcenter/soa/client/model/User.hxx>
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
            namespace _2010_04
            {
                class Irm;

class TCSOAADMINISTRATIONSTRONGMNGD_API Irm
{
public:

    struct AccessorTypesResponse;
    struct DisplayNameInfo;
    struct ACLInfo;
    struct ACLInfoResponse;
    struct ACLInfos;
    struct ExtraProtectionInfo;
    struct ExtraProtectionInfoReport;
    struct ExtraProtectionInfoResponse;
    struct PrivNamesInfoResponse;

    /**
     * This structure contains the internal names and corresponding display values for all
     * the Accessor Types in Teamcenter.
     */
    struct AccessorTypesResponse
    {
        /**
         * List of DisplayNameInfo objects containing the internal name and corresponding display
         * name for each of the Accessor Types in Teamcenter.
         */
        std::vector< Teamcenter::Services::Administration::_2010_04::Irm::DisplayNameInfo > accessorTypeNameInfos;
        /**
         * Object that holds any partial errors that occur while getting the display names of
         * the Accessor Types in Teamcenter.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * DisplayNameInfo structure holds the internal name and corresponding display name
     * of objects like privilege, named ACL, Accessor type and Accessor Id.
     */
    struct DisplayNameInfo
    {
        /**
         * String representing the internal name of an access privilege or a named ACL or an
         * accessor type or an accessor.
         */
        std::string internalName;
        /**
         * String representing the display name of an access privilege or a named ACL or an
         * accessor type or an accessor.
         */
        std::string displayName;
    };

    /**
     * Structure to hold the ACE information for a single row in the effective ACL table
     * like granted privileges, revoked privileges, Accessor Type name, Accessor Id and
     * the ACL name. This structure holds both internal names and corresponding display
     * values for the names of Accessor Type, Named ACL, Privilege and Accessor ID that
     * constitutes a single ACE.
     */
    struct ACLInfo
    {
        /**
         * A list of objects containing the internal and display names of the access privileges
         * that are granted to the user on a given business object.
         */
        std::vector< Teamcenter::Services::Administration::_2010_04::Irm::DisplayNameInfo > grantedPrivsInfo;
        /**
         * A list of  objects containing the internal and display names of the access privileges
         * that are revoked to the user on a given business object.
         */
        std::vector< Teamcenter::Services::Administration::_2010_04::Irm::DisplayNameInfo > revokedPrivsInfo;
        /**
         * Object containing the internal and display names of the accessor type in the ACE
         * that is applicable to the given business object and to the user.
         */
        Teamcenter::Services::Administration::_2010_04::Irm::DisplayNameInfo accessorTypeNameInfo;
        /**
         * Object containing the internal and display names of the accessor id in the ACE that
         * is applicable to the given business object and to the user.
         */
        Teamcenter::Services::Administration::_2010_04::Irm::DisplayNameInfo accessorIdInfo;
        /**
         * Object containing the internal and display names of the ACL in the ACE that is applicable
         * to the given business object and to the user.
         */
        Teamcenter::Services::Administration::_2010_04::Irm::DisplayNameInfo aclNameInfo;
    };

    /**
     * This structure holds the list of effective ACL reports for each of the given business
     * objects.  Each effective ACL report contains the business object and corresponding
     * effective ACL information.
     */
    struct ACLInfoResponse
    {
        /**
         * List of derived Effective ACL reports for each of the given business objects.
         */
        std::vector< Teamcenter::Services::Administration::_2010_04::Irm::ACLInfos > aclInfosList;
        /**
         * Object that holds the partial errors that occurred while deriving the effective ACL
         * information for any of the given business objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure holds the business object and corresponding effective ACL information
     * derived through access rule evaluation.  Each effective ACL contains a list of ACE
     * objects. Each ACE object is a single row in the effective ACL table that contains
     * information like granted privileges, revoked privileges, Accessor Type name, Accessor
     * Id and the ACL name.
     */
    struct ACLInfos
    {
        /**
         * The business object for which effective ACL was derived.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  workSpaceObject;
        /**
         * List of ACE objects returned from the server that make up the effective ACL for the
         * business object.
         */
        std::vector< Teamcenter::Services::Administration::_2010_04::Irm::ACLInfo > aclInfos;
    };

    /**
     * This structure contains the derived extra protection information corresponding to
     * a single access privilege on a given business object for the given user.
     */
    struct ExtraProtectionInfo
    {
        /**
         * Object that holds the internal name and display name of the access privilege.
         */
        Teamcenter::Services::Administration::_2010_04::Irm::DisplayNameInfo privilegeNameInfo;
        /**
         * The verdict for the privilege for the user on the object.
         */
        bool verdict;
        /**
         * A list of access rules evaluated to arrive at the verdict for the privilege.
         */
        std::vector< std::string > rules;
        /**
         * A list of access rule arrangements involved in arriving at the verdict. Arrangements
         * means the order in which the rules are evaluated.
         */
        std::vector< std::string > ruleEvaluation;
        /**
         * Object that holds the internal and display names of the named ACL. For object ACLs
         * the internal name is "OBJECT".
         */
        Teamcenter::Services::Administration::_2010_04::Irm::DisplayNameInfo aclNameInfo;
        /**
         * Object that holds the internal and display names of the accessor type name corresponding
         * to the ACE that involved in arriving at the privilege verdict.
         */
        Teamcenter::Services::Administration::_2010_04::Irm::DisplayNameInfo accessorTypeNameInfo;
        /**
         * Object that holds the internal and display names of the accessor Id  corresponding
         * to the ACE that involved in arriving at the privilege verdict.
         */
        Teamcenter::Services::Administration::_2010_04::Irm::DisplayNameInfo accessorIdInfo;
    };

    /**
     * This structure holds the business object and corresponding derived extra protection
     * information for all the access privileges for the given user.
     */
    struct ExtraProtectionInfoReport
    {
        /**
         * <b>POM_object</b> on which extra protection information is derived for the given
         * user.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  workSpaceObject;
        /**
         * The derived extra protection information corresponding to the single business object.
         */
        std::vector< Teamcenter::Services::Administration::_2010_04::Irm::ExtraProtectionInfo > extraProtectionInfos;
    };

    /**
     * This structure contains list of extra protection reports one for of each of the given
     * business objects for the given user.
     */
    struct ExtraProtectionInfoResponse
    {
        /**
         * List of extra protection report objects one for each of the given business objects.
         */
        std::vector< Teamcenter::Services::Administration::_2010_04::Irm::ExtraProtectionInfoReport > extraProtectionReports;
        /**
         * Object that holds the partial errors occurred while deriving extra protection  information
         * of any of the given business objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure holds the internal and display names of all the Teamcenter access
     * privileges.
     */
    struct PrivNamesInfoResponse
    {
        /**
         * A list of DisplayNameInfo objects that holds internal name and display names of each
         * Teamcenter privilege objects.
         */
        std::vector< Teamcenter::Services::Administration::_2010_04::Irm::DisplayNameInfo > privNameInfos;
        /**
         * Object that holds any of the partial errors that occurred while getting the display
         * names of the privileges in Teamcenter. But in fact this operation will not result
         * in any errors as it is returning the names of existing privileges. Scope for any
         * errors is very less.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation can be used to get the names of all the Accessor Types in Teamcenter.
     * Accessor Types are used to configure access privileges for different accessors in
     * Access Control List (ACL) table in Access Manager Application. Examples for the Accessor
     * Types are "World", "User", "Group", and "Role in Group".  For more information on
     * the Accessor Types please refer to the Access Manager guide in Teamcenter documentation.
     * The returned names from this operation will include both internal names and corresponding
     * client locale specific localized display names of the Accessor Types.  The display
     * names of the Accessor Types are used for displaying in the User Interface.  Whereas,
     * the internal names of the Accessor Types are used for internal processing of the
     * rule tree evaluation.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * In general wherever the Accessor Type names need to be displayed this operation can
     * be used. At present following use cases in Teamcenter Rich Application Client (RAC)
     * calls this operation.
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Display the Accessor Type names in Extra Protection information dialog.
     * </li>
     * <li type="disc">Display the Accessor Type names in Effective ACL dialog.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Entitlement - It Maps IRM SOA services to BMIDE.
     *
     * @return
     *         This operation returns the AccessorTypesResponse object that holds a list of  DisplayNameInfo
     *         objects for each of the Accessor Types in Teamcenter and the ServiceData. DisplayNameInfo
     *         holds the internal name of an Accessor Type and corresponding display name.  Partial
     *         error <b>525130</b> that indicates the given accessor type is invalid, will be returned
     *         by this operation if a given accessor type cannot be found.
     *
     */
    virtual Teamcenter::Services::Administration::_2010_04::Irm::AccessorTypesResponse getAccessorTypes (  ) = 0;

    /**
     * This operation can be used to get the effective Access Control List (ACL) information
     * for a list of business objects.  Effective ACL information displays the Access Control
     * Entries (ACEs) that are applicable to the business object with respect to the user
     * for whom access privileges are being evaluated on the object. Applicable ACEs are
     * picked up from the ACLs that are configured against the Access Manager Rules which
     * are evaluated to true for the given business object based on details like the object's
     * type, object's class, object attributes, object status and project to which it is
     * assigned.  By looking at the effective ACL table end user will be able to understand
     * what privileges or granted, what privileges are denied for the user on the object
     * and, what ACL and Accessor Type are involved in either granting or denying a particular
     * access privilege. For more information on ACLs, ACEs, effective ACLs please refer
     * to the Access Manager guide in Teamcenter.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * ACL list dialog in Teamcenter Rich Application Client (RAC) calls this operation
     * to get the effective ACL information.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Entitlement - It Maps IRM SOA services to BMIDE.
     *
     * @param objects
     *        List of business objects for which effective ACLs need to be derived.  The business
     *        object can be any <b>POM_object</b> like <b>Item</b>, <b>ItemRevision</b> and <b>Dataset</b>.
     *
     * @return
     *         This operation returns list of effective ACL information objects for each of the
     *         given business objects. Partial errors that occur while deriving effective ACL for
     *         any of the given business objects will be returned in service data. An error will
     *         occur in situations like, if the given object cannot be loaded and if the given object
     *         tag is invalid. Following is the error code and message.
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">525071- The tag passed is not a valid tag
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Administration::_2010_04::Irm::ACLInfoResponse getEffectiveACLInfo2 ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects ) = 0;

    /**
     * This operation can be used to get the additional access protection information for
     * a given user on a set of business objects.  Additional protection information can
     * be used to understand what Named ACL, what Accessor and what AM rule path are involved
     * in arriving at the verdict for an access privilege on a given object for the given
     * user. This helps the user to understand why a particular privilege on the given object
     * is granted or denied for the given user.  At present this information is displayed
     * only in RAC client in the "Extra Protection Information" dialog.  This operation
     * supports localization of privilege names, ACL names and Accessor type names.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * "Extra Protection Information" dialog in Teamcenter Rich Application Client (RAC)
     * calls this operation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Entitlement - It Maps IRM SOA services to BMIDE.
     *
     * @param user
     *        Teamcenter user object for whom extra protection information on the given business
     *        objects need to be derived.
     *
     * @param objects
     *        List of business objects on which Extra protection information need to be derived
     *        for the given user. The business objects can be any <b>POM_objects</b> like <b>Item</b>,
     *        <b>ItemRevision</b> and <b>Dataset</b>.
     *
     * @return
     *         This operation returns ExtraProtectionInfoResponse object that contains a list of
     *         extra protection reports one for each of the given business objects and the ServiceData.
     *         Each extra protection report contains the business object and corresponding extra
     *         protection information. Partial errors that occur while deriving extra protection
     *         information of any given business objects will be returned in error stack in ServiceData.
     *         Following is the possible error and error message.
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">525071- The tag passed is not a valid tag
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Administration::_2010_04::Irm::ExtraProtectionInfoResponse getExtraProtectionInfo2 ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  user,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects ) = 0;

    /**
     * This operation can be used to get the internal names and corresponding display values
     * of all the access privileges in Teamcenter.  The display names of the privileges
     * are used to display the privilege names in the User Interface in client specific
     * locale.  Whereas, the internal privilege names are used for internal processing of
     * the rule tree evaluation. Below is the list of access privileges in Teamcenter release
     * 10.0. For functional information on each of these privileges please refer to the
     * Access Manager guide in Teamcenter documentation.
     * <br>
     * <br>
     * ADD_CONTENT
     * <br>
     * ASSIGN_TO_PROJECT
     * <br>
     * Administer_ADA_Licenses
     * <br>
     * BATCH_PRINT
     * <br>
     * CHANGE
     * <br>
     * CHANGE_OWNER
     * <br>
     * CICO
     * <br>
     * COPY
     * <br>
     * DELETE
     * <br>
     * DEMOTE
     * <br>
     * DIGITAL_SIGN
     * <br>
     * EXPORT
     * <br>
     * IMPORT
     * <br>
     * IP_ADMIN
     * <br>
     * IP_Classifier
     * <br>
     * ITAR_ADMIN
     * <br>
     * ITAR_Classifier
     * <br>
     * MARKUP
     * <br>
     * PROMOTE
     * <br>
     * PUBLISH
     * <br>
     * READ
     * <br>
     * REMOTE_CICO
     * <br>
     * REMOVE_CONTENT
     * <br>
     * REMOVE_FROM_PROJECT
     * <br>
     * SUBSCRIBE
     * <br>
     * TRANSFER_IN
     * <br>
     * TRANSFER_OUT
     * <br>
     * TRANSLATION
     * <br>
     * UNMANAGE
     * <br>
     * WRITE
     * <br>
     * WRITE_ICOS
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation can be used in general wherever the privilege names need to be displayed.
     * At present following use cases in Teamcenter Rich Application Client (RAC) calls
     * this operation.
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Display the privilege names in Access dialog.
     * </li>
     * <li type="disc">Display the privilege names in Extra Protection information dialog.
     * </li>
     * <li type="disc">Display the privilege names in effective Access Control List (ACL)
     * dialog.
     * </li>
     * <li type="disc">Display the privilege tool tips in Named ACL panel.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Entitlement - It Maps IRM SOA services to BMIDE.
     *
     * @return
     *         This operation returns the internal names and corresponding display names of all
     *         the access privileges in Teamcenter in the form of a list.
     *
     */
    virtual Teamcenter::Services::Administration::_2010_04::Irm::PrivNamesInfoResponse getPrivilegeNames (  ) = 0;


protected:
    virtual ~Irm() {}
};
            }
        }
    }
}

#include <teamcenter/services/administration/Administration_undef.h>
#endif

