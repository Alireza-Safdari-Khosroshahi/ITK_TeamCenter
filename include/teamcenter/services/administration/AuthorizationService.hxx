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

#ifndef TEAMCENTER_SERVICES_ADMINISTRATION_AUTHORIZATIONSERVICE_HXX
#define TEAMCENTER_SERVICES_ADMINISTRATION_AUTHORIZATIONSERVICE_HXX

#include <teamcenter/services/administration/_2007_06/Authorization.hxx>
#include <teamcenter/services/administration/_2008_12/Authorization.hxx>



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
            class AuthorizationService;

/**
 * This service provides operations that are mainly used to accomplish authorization
 * functionality related use cases.  Authorization functionality in Teamcenter enables
 * administrators to configure rules that allow non system administration group members
 * to access administration applications in authoring mode or run system administration
 * utilities. Authorization rules can be configured on applications or utilities for
 * individual groups or role-in-group accessors.  Users that belong to these configured
 * groups or role-in-group accessors can then open an admin application in authoring
 * mode or run an admin utility through command line. This service provides operations
 * to accomplish following use cases.
 * <br>
 * <br>
 * <ul>
 * <li type="disc">Getting authorization rules for a set of accessors (Group and Role
 * in the Group).
 * </li>
 * <li type="disc">Setting authorization rules for a set of accessors (Group and Role
 * in the Group).
 * </li>
 * <li type="disc">Checking authorization for given user, group and role combination
 * on given set of applications and utilities.
 * </li>
 * <li type="disc">Checking authorization for given user and group combination on given
 * set of applications and utilities.
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

class TCSOAADMINISTRATIONSTRONGMNGD_API AuthorizationService
    : public Teamcenter::Services::Administration::_2007_06::Authorization,
             public Teamcenter::Services::Administration::_2008_12::Authorization
{
public:
    static AuthorizationService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation can be used to get authorization access on the given applications
     * and utilities for the given user and group combination. Rule domain specifies accessibility
     * need to be checked on an application or on a utility. Valid values for the domain
     * are "utility" and "application".  If some other string is specified as rule domain
     * this operation will return error code <b>290006</b>.  However accessibility check
     * for correct domain names will continue. Following are the valid application names
     * and utility names for this operation. For more information on authorization rules
     * please refer to Authorization guide in Teamcenter documentation.
     * <br>
     * <br>
     * <b>List of application IDs:</b>
     * <br>
     * Organization
     * <br>
     * Business_Modeler_IDE
     * <br>
     * Access_Manager
     * <br>
     * Archive_Restore
     * <br>
     * Setup_Wizard
     * <br>
     * Workflow_Designer
     * <br>
     * PLMXML_Import_Export
     * <br>
     * Project
     * <br>
     * Subscription_Monitor
     * <br>
     * Classification_Admin
     * <br>
     * Report_Designer
     * <br>
     * Application_Configuration
     * <br>
     * EIntegrator_Admin
     * <br>
     * Audit_Manager
     * <br>
     * Authorization
     * <br>
     * Schema_Editor
     * <br>
     * Appearance_Configuration
     * <br>
     * ADA License
     * <br>
     * <br>
     * <b>List of utility IDs:</b>
     * <br>
     * data_share
     * <br>
     * export_recovery
     * <br>
     * database_verify
     * <br>
     * update_project_data
     * <br>
     * find_processes
     * <br>
     * data_sync
     * <br>
     * dsa_util
     * <br>
     * import_export_business_rules
     * <br>
     * purge_invalid_subscriptions
     * <br>
     * create_change_types
     * <br>
     * fsc_admin
     * <br>
     * ada_util
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * To check user's accessibility
     * <br>
     * <br>
     * <ul>
     * <li type="disc">While opening an admin application.
     * </li>
     * <li type="disc">While running an admin utility.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Authorization - This component consists of the Client and Enterprise Tier code and
     * constructs that support Authorization functionality including such things as the
     * Rich Client Authorization Application plus SOA, ITK and Preferences.
     *
     * @param user
     *        User object whose access on the given applications or utilities need to be determined.
     *
     * @param group
     *        The <b>Group</b> to which the user belongs to.
     *
     * @param inputNames
     *        A list of NameInfo objects.
     *
     * @return
     *         This operation returns NameAuthorizationList structure. This structure contains a
     *         list of  NameAuthorizationResponse structures one for each of the given application
     *         or utility and ServiceData.  Partial error <b>290006</b> that indicates invalid rule
     *         domain value is given for the authorization rule will be returned by this operation
     *         if an invalid value is specified for the rule domain.
     *
     * @deprecated
     *         As of tc2007.1.5, use the checkAuthorizationAccess operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007.1.5, use the checkAuthorizationAccess operation."))
#endif
    virtual Teamcenter::Services::Administration::_2007_06::Authorization::NameAuthorizationList checkAuthorization ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  user,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Group>  group,
        const std::vector< Teamcenter::Services::Administration::_2007_06::Authorization::NameInfo >& inputNames ) = 0;

    /**
     * This operation can be used to get authorization access on the given applications
     * and utilities for the given user, group and role combination. Rule domain specifies
     * accessibility need to be checked on an application or on a utility. Valid values
     * for the domain are "utility" and "application".  If some other string is specified
     * as rule domain this operation will return error code <b>290006</b>.  However accessibility
     * check for correct domain names will continue. Following are the valid application
     * names and utility names for this operation. For more information on authorization
     * rules please refer to Authorization guide in Teamcenter documentation.
     * <br>
     * <br>
     * <b>List of application IDs:</b>
     * <br>
     * Organization
     * <br>
     * Business_Modeler_IDE
     * <br>
     * Access_Manager
     * <br>
     * Archive_Restore
     * <br>
     * Setup_Wizard
     * <br>
     * Workflow_Designer
     * <br>
     * PLMXML_Import_Export
     * <br>
     * Project
     * <br>
     * Subscription_Monitor
     * <br>
     * Classification_Admin
     * <br>
     * Report_Designer
     * <br>
     * Application_Configuration
     * <br>
     * EIntegrator_Admin
     * <br>
     * Audit_Manager
     * <br>
     * Authorization
     * <br>
     * Schema_Editor
     * <br>
     * Appearance_Configuration
     * <br>
     * ADA License
     * <br>
     * <br>
     * <b>List of utility IDs:</b>
     * <br>
     * data_share
     * <br>
     * export_recovery
     * <br>
     * database_verify
     * <br>
     * update_project_data
     * <br>
     * find_processes
     * <br>
     * data_sync
     * <br>
     * dsa_util
     * <br>
     * import_export_business_rules
     * <br>
     * purge_invalid_subscriptions
     * <br>
     * create_change_types
     * <br>
     * fsc_admin
     * <br>
     * ada_util
     * <br>
     * attribute_export
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * To check user's accessibility.
     * <br>
     * <br>
     * <ul>
     * <li type="disc">While opening an admin application.
     * </li>
     * <li type="disc">While running an admin utility
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Authorization - This component consists of the Client and Enterprise Tier code and
     * constructs that support Authorization functionality including such things as the
     * Rich Client Authorization Application plus SOA, ITK and Preferences.
     *
     * @param user
     *        User object whose access on the given applications or utilities need to be determined.
     *
     * @param group
     *        The <b>Group</b> to which the user belongs to.
     *
     * @param role
     *        <b>Role</b> in group to which the user belongs to.
     *
     * @param inputNames
     *        A list of NameInfo objects.
     *
     * @return
     *         This operation returns NameAuthorizationList structure. This structure contains a
     *         list of  NameAuthorizationResponse structures one for each of the given application
     *         or utility and ServiceData. Partial error <b>290006</b> that indicates invalid rule
     *         domain value is given for the authorization rule will be returned by this operation
     *         if an invalid value is specified for the rule domain.
     *
     */
    virtual Teamcenter::Services::Administration::_2007_06::Authorization::NameAuthorizationList checkAuthorizationAccess ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  user,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Group>  group,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Role>  role,
        const std::vector< Teamcenter::Services::Administration::_2007_06::Authorization::NameInfo >& inputNames ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AuthorizationService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/administration/Administration_undef.h>
#endif

