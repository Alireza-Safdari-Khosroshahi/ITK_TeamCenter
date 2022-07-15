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

#ifndef TEAMCENTER_SERVICES_ADMINISTRATION__2006_03_IRM_HXX
#define TEAMCENTER_SERVICES_ADMINISTRATION__2006_03_IRM_HXX

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
            namespace _2006_03
            {
                class Irm;

class TCSOAADMINISTRATIONSTRONGMNGD_API Irm
{
public:

    struct ACLInfo;
    struct ACLInfos;
    struct CheckAccessorPrivilegesResponse;
    struct GetACLInfoResponse;
    struct GetProtectionReportResponse;
    struct Privilege;
    struct PrivilegeReport;
    struct PrivilegeSettingInput;
    struct Protection;
    struct ProtectionReport;

    /**
     * Structure to hold the ACE information for a single row in the effective ACL table
     * like granted privileges, revoked privileges, Accessor Type name, Accessor Id and
     * the ACL name.
     */
    struct ACLInfo
    {
        /**
         * Names access privilege that are granted to the user on a given object.
         */
        std::vector< std::string > grantedNames;
        /**
         * Names access privilege that are revoked to the user on a given object.
         */
        std::vector< std::string > revokedNames;
        /**
         * The name of the accessor type in the ACE that is applicable to the given business
         * object and to the user.
         */
        std::string accessorType;
        /**
         * The name of the accessor id in the ACE that is applicable to the given business object
         * and to the user.
         */
        std::string accessorId;
        /**
         * The name of the name of the ACL in the ACE that is applicable to the given business
         * object and to the user.  Name for the object ACL is "ORBJECT".
         */
        std::string namedACL;
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
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * List of ACE objects returned from the server that make up the effective ACL for the
         * business object.
         */
        std::vector< Teamcenter::Services::Administration::_2006_03::Irm::ACLInfo > aclInfos;
    };

    /**
     * A list of privilegeReport objects for each of the given business objects and each
     * given privilege. Each PrivilegeReport object contains the business object and verdicts
     * for all the given privileges.
     */
    struct CheckAccessorPrivilegesResponse
    {
        /**
         * A list of PrivilegeReport objects one for each of the given business object.
         */
        std::vector< Teamcenter::Services::Administration::_2006_03::Irm::PrivilegeReport > privilegeReports;
        /**
         * Object that holds the partial errors that resulted while determining the privileges
         * on a business object through access rules evaluation.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure holds the list of effective ACL reports for each of the given business
     * objects.  Each effective ACL report contains the business object and corresponding
     * effective ACL information.
     */
    struct GetACLInfoResponse
    {
        /**
         * List of derived Effective ACL reports for each of the given business objects.
         */
        std::vector< Teamcenter::Services::Administration::_2006_03::Irm::ACLInfos > aclInfoList;
        /**
         * Object that holds the partial errors that occurred while getting the effective ACL
         * information for any of the given business objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains list of extra protection reports one for of each of the given
     * business objects for the given user.
     */
    struct GetProtectionReportResponse
    {
        /**
         * List of extra protection report objects one for each of the given business objects.
         */
        std::vector< Teamcenter::Services::Administration::_2006_03::Irm::ProtectionReport > protectionReports;
        /**
         * Object that holds the partial errors occurred while deriving extra protection  information
         * of any of the given business objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure holds the name of the given privilege and its verdict that indicates
     * if the privilege is granted or denied.
     */
    struct Privilege
    {
        /**
         * The name of the access privilege.
         */
        std::string privilegeName;
        /**
         * Value true means the privilege is granted and false means the privilege is denied.
         */
        bool verdict;
    };

    /**
     * This structure holds the business object for which access privileges are successfully
     * evaluated and corresponding privileges information. Privilege information includes
     * the privilege name and corresponding verdict for each of the given privileges.
     */
    struct PrivilegeReport
    {
        /**
         * Business object on which access privileges are evaluated successfully  for the given
         * groupMember.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * A list of evaluated access privileges and corresponding verdicts for the given groupMember
         * on the business object.
         */
        std::vector< Teamcenter::Services::Administration::_2006_03::Irm::Privilege > privilegeInfos;
    };

    /**
     * This structure holds the object on which access privileges need to be modified and
     * the sets of granted, denied and unset privileges for the given accessor type.
     */
    struct PrivilegeSettingInput
    {
        /**
         * POM_application_object or a named ACL.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * A list of access privilege names that need to be granted.
         */
        std::vector< std::string > grant;
        /**
         * A list of access privilege names that need to be denied.
         */
        std::vector< std::string > revoke;
        /**
         * A list of access privilege names that need to be unset.
         */
        std::vector< std::string > unset;
    };

    /**
     * This structure contains the derived extra protection information corresponding to
     * a single access privilege on a given business object for the given user.
     */
    struct Protection
    {
        /**
         * The name of the access privilege.
         */
        std::string privilege;
        /**
         * True or false. True means the privilege is granted and false means the privilege
         * is denied.
         */
        bool verdict;
        /**
         * A list of access rules evalued to arrive at the verdict for the privilege.
         */
        std::vector< std::string > rules;
        /**
         * A list of access rule arrangements involved in arriving at the verdict.
         */
        std::vector< std::string > ruleEvaluation;
        /**
         * The name of the named ACL that is used to determine the verdict for this privilege.
         * For object ACLs the name is "OBJECT".
         */
        std::string acl;
        /**
         * The accessor type name corresponding to the ACE that involved in arriving at the
         * privilege verdict.
         */
        std::string accessorType;
        /**
         * The name of the accessor that is used in the ACE that is used to determine the privilege.
         */
        std::string accessorId;
    };

    /**
     * This structure holds the business object and corresponding derived extra protection
     * information for all the access privileges for the given user.
     */
    struct ProtectionReport
    {
        /**
         * <b>POM_object</b> on which extra protection information is derived for the given
         * user.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * The derived extra protection information corresponding to the single business object.
         */
        std::vector< Teamcenter::Services::Administration::_2006_03::Irm::Protection > protections;
    };




    /**
     * This operation gets the verdicts for the given access privileges for the given <b>GroupMember</b>
     * on the given set of business objects.  This operation finds the accessors for the
     * combination of given groupMember's user, role and group and then uses the list of
     * found accessors to determine the verdicts for the given access privileges for the
     * given <b>GroupMember</b> on the given business objects. The business objects can
     * be any<b> </b><b>POM_object</b>.  Privilege Names must be internal names of the Access
     * Manager<b> </b><b>AM_Privilege</b> objects.  If a privilege object with any of the
     * given names does not exist in the system then this operation will return the error
     * <b>525101</b>.  However, evaluation of the valid privilege names will continue. Following
     * are the list of valid privilege names. For functional description about these privileges
     * please refer to the Access Manager guide in Teamcenter documentation.
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
     * <b>Teamcenter Component:</b>
     * <br>
     * Entitlement - It Maps IRM SOA services to BMIDE.
     *
     * @param groupMember
     *        The <b>GroupMember</b> whose access privileges on the given business objects need
     *        to be determined.
     *
     * @param objects
     *        The list of business objects on which access privileges are being evaluated for the
     *        given groupMember. The business object can be any <b>POM_object</b>.
     *
     * @param privilegeNames
     *        This is a list of valid Access Manager   privilege names whose verdicts for the given
     *        groupMember on the given business objects need to be determined. The privilege names
     *        must be the internal names.
     *
     * @return
     *         This operation returns a list of privilege reports for each requested business object
     *         and each requested privilege. Each of the requested business objects is returned
     *         on the plain list of the <b>ServiceData</b>. A partial error <b>525101</b> is returned
     *         for invalid privilege name, while the remaining privileges are evaluated.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Administration::_2006_03::Irm::CheckAccessorPrivilegesResponse checkAccessorsPrivileges ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  groupMember,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects,
        const std::vector< std::string >& privilegeNames ) = 0;

    /**
     * This operation can be used to get the effective Access Control List (ACL) information.
     * Effective ACL information displays the Access Control Entries (ACEs) that are applicable
     * to the business object with respect to the user for whom access privileges are being
     * evaluated on the object. Applicable ACEs are picked up from the ACLs that are configured
     * against the Access Manager Rules which are evaluated to true for the given object
     * based on the object's type, class, attributes, status and project to which it is
     * assigned to etc.  By looking at the effective ACL table end user will be able to
     * understand what privileges or granted, what privileges are denied for the user on
     * the object and, what ACL and Accessor Type are involved in either granting or denying
     * a particular access privilege. This operation can be used to get all the information
     * required to render the effective ACL table. Limitation with this operation is it
     * does not support localization. Hence all the strings returned by this or internal
     * values. For more information on ACLs, ACEs, effective ACLs please refer to the Access
     * Manager guide in Teamcenter.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * ACL list dialog in Teamcenter Rich Application Client (RAC) used to call this operation
     * to get the effective ACL information before it was replaced with the new operation
     * getEffectiveACLInfo2 that supports localization of ACL names, Accessor type names
     * and privilege names.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Entitlement - It Maps IRM SOA services to BMIDE.
     *
     * @param objects
     *        List of business objects for which effective ACLs need to be derived. The business
     *        object can be any <b>POM_object</b> like <b>Item</b>, <b>ItemRevision</b> and <b>Dataset.</b>
     *
     * @return
     *         This operation returns list of effective ACL information objects for each of the
     *         given business objects. Partial errors that occur while deriving effective ACL for
     *         any of the given business objects will be returned in service data. An error will
     *         occur in situations like, if the given object cannot be loaded and if the given object
     *         tag is invalid.
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">525071- The tag passed is not a valid tag
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Administration::_2006_03::Irm::GetACLInfoResponse getEffectiveACLInfo ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects ) = 0;

    /**
     * This operation can be used to get the additional access protection information for
     * a given user on a set of business objects.  Additional protection information can
     * be used to understand what Named ACL, what Accessor and what AM rule path are involved
     * in arriving at the verdict for an access privilege on a given object for the given
     * user. This helps the user to understand why a particular privilege on the given object
     * is granted or denied for the given user.  This operation does not support localization.
     * Hence all the strings returned by this operation are internal values.  This operation
     * is replaced by a new operation getExtraProtectionInfo2 that supports localization.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Extra Protection Information dialog in Teamcenter Rich Application Client (RAC) used
     * to call this operation before it was replaced with the new operation getExtraProtectionInfo2
     * that supports localization.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Entitlement - It Maps IRM SOA services to BMIDE.
     *
     * @param user
     *        List of business objects on which Extra protection information need to be derived
     *        for the given user. The business objects can be any <b>POM_objects</b> like <b>Item</b>,
     *        <b>ItemRevision</b> and <b>Dataset</b>.
     *
     * @param objects
     *        Teamcenter user object for whom extra protection information on the given business
     *        objects need to be derived.
     *
     * @return
     *         This operation returns GetProtectionReportResponse object that contains a list of
     *         extra protection reports one for each of the given business objects and the ServiceData.
     *         Each extra protection report contains the business object and corresponding extra
     *         protection information. Partial errors that occur while deriving extra protection
     *         information of any given business objects will be returned in error stack in ServiceData.
     *         Following are the list of possible errors and corresponding messages.
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">525071- The tag passed is not a valid tag
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Administration::_2006_03::Irm::GetProtectionReportResponse getExtraProtectionInfo ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  user,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects ) = 0;

    /**
     * This operation removes the specified accessors from the given objects. Objects in
     * the given list can be either <b>AM_ACL</b> (named Access Control List) objects or<b>
     * POM_application_object</b>. If the object is a named ACL then the Access Control
     * Entry (ACE)  from the named ACL is removed.  If the object is a<b> POM_application_object</b>
     * then object ACL entry with the specified accessor type and accessor id is removed.
     * Objects on which given accessor is removed successfully are returned in the updated
     * list of the ServiceData.  Objects on which accessor removal resulted in an error
     * are returned in the list of failures in the ServiceData.  Invalid accessor type and
     * accessor ID will result in error code <b>525120</b>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Modifying a Named ACL or removing an object ACL from Teamcenter Rich Application
     * Client (RAC) calls this operation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Entitlement - It Maps IRM SOA services to BMIDE.
     *
     * @param objects
     *        List of named ACLs or <b>POM_objects</b> from which the access control entry with
     *        specified accessor type and accessor id need to be removed.
     *
     * @param accessorType
     *        Name of the accessor type in the ACE that need to be removed.
     *
     * @param accessorId
     *        Name of the accessor ID in the ACE that need to be removed.  Accessor ID is basically
     *        argument value to the accessor type. Not all accessor types have argument value.
     *        Hence, accessor id can be null.
     *
     * @return
     *         This operation returns ServiceData. Objects for which accessor removal was successful
     *         are returned in the updated objects list of the serviceData. Whereas objects for
     *         which accessor removal resulted in an error are added to the error stack.  Invalid
     *         accessor type and accessor ID will result in error <b>525120</b>.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData removeAccessor ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects,
        const std::string&  accessorType,
        const std::string&  accessorId ) = 0;

    /**
     * This operation can be used to grant or deny a set of privileges to the specified
     * accessor type and accessor id on the given object.  Either a named Access Control
     * List (ACL) or a <b>POM_application_object</b> can be submitted as input to this operation.
     * If the object is a <b>POM_application_object</b> then an object ACL will be added
     * on the object. If the object is a named ACL then an ACE entry is either modified
     * or added to the named ACL. For invalid Accessor type and Accessor Id this operation
     * will return the error <b>525101</b>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <ul>
     * <li type="disc">Updating named ACL objects by either modifying existing ACE entries
     * or by adding new ACE entries for the specified accessor.
     * </li>
     * <li type="disc">Adding new object ACLs on a <b>POM_application_object</b> for the
     * specified accesor.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Entitlement - It Maps IRM SOA services to BMIDE.
     *
     * @param privilegeSettings
     *        A list of PrivilegeSettingInput objects one for each of the given objects on which
     *        privileges need to be modified.
     *
     * @param accessorType
     *        The name of the accessor type for which privileges need to be modified.
     *
     * @param accessorId
     *        The argument value to the accessor type. Not all accessor types take argument value.
     *        Hence, accessor id can be null.
     *
     * @return
     *         This operation returns ServiceData object.  Objects on which updating the access
     *         privileges was successful are returned in updated list of ServiceData. Objects on
     *         which access privileges update was not successful are returned in error list in the
     *         <b>ServiceData</b>.  Below are the list of possible error codes and messages.
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">525101 - No instances were found with the given name
     *         </li>
     *         <li type="disc">525071 - The tag passed is not a valid tag
     *         </li>
     *         <li type="disc">525120 - The given accessor was not found in the given ACL
     *         </li>
     *         <li type="disc">525060 - Duplicate entry : the ACL can contain only one entry for
     *         each accessor
     *         </li>
     *         <li type="disc">525050 - You do not have change rights for this ACL
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData setPrivileges ( const std::vector< Teamcenter::Services::Administration::_2006_03::Irm::PrivilegeSettingInput >& privilegeSettings,
        const std::string&  accessorType,
        const std::string&  accessorId ) = 0;


protected:
    virtual ~Irm() {}
};
            }
        }
    }
}

#include <teamcenter/services/administration/Administration_undef.h>
#endif

