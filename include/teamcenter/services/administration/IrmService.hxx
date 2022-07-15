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

#ifndef TEAMCENTER_SERVICES_ADMINISTRATION_IRMSERVICE_HXX
#define TEAMCENTER_SERVICES_ADMINISTRATION_IRMSERVICE_HXX

#include <teamcenter/services/administration/_2006_03/Irm.hxx>
#include <teamcenter/services/administration/_2008_03/Irm.hxx>
#include <teamcenter/services/administration/_2010_04/Irm.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/administration/Administration_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Administration
        {
            class IrmService;

/**
 * This service provides operations that are mainly used to accomplish Access Manager
 * related use cases.  Access Manager provides the functionality to configure site wide
 * access control on the Teamcenter business data. Artifacts like Access Manager Conditions,
 * Access Control Lists (ACLs), Access Control Entries (ACEs), Accessor Types and Access
 * Privileges are used to configure the data access control in Access Manager.  Accessor
 * Types and Privileges are also used to configure individual Object based access control.
 * Access Manager Rules can be configured to control access on any <b>POM_object</b>.
 * However Access Manager Rules are mostly applied for <b>POM_application_objects</b>
 * such as <b>Item</b>, <b>ItemRevision</b> and <b>Dataset</b> in real time. Following
 * are the use cases that are supported by the operations in this service.
 * <br>
 * <br>
 * <ul>
 * <li type="disc">Fetching Extra Protection details on a set of business objects for
 * the given accessors.
 * </li>
 * <li type="disc">Fetching effective ACL information on a set of business objects for
 * the given accessors.
 * </li>
 * <li type="disc">Fetching access privileges on a set of business objects for the given
 * accessors.
 * </li>
 * <li type="disc">Modifying the privileges or Access Control Entries (ACEs) on an object
 * ACL or a Named ACL.
 * </li>
 * <li type="disc">Getting the Named ACLs of different types. Teamcenter provides 3
 * types of named ACLs.</br>1-Rule based ACLs - Used in AM rule configuration.</br>2-Work
 * Flow ACLs - Used in Workflow tasks.</br>3-Project ACLs - Used to configure access
 * on Project objects.
 * </li>
 * <li type="disc">Getting list of Accessor Types.
 * </li>
 * <li type="disc">Getting the access privilege names including both internal and display
 * value.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaadministrationstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaadministrationtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAADMINISTRATIONSTRONGMNGD_API IrmService
    : public Teamcenter::Services::Administration::_2006_03::Irm,
             public Teamcenter::Services::Administration::_2008_03::Irm,
             public Teamcenter::Services::Administration::_2010_04::Irm
{
public:
    static IrmService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IrmService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/administration/Administration_undef.h>
#endif

