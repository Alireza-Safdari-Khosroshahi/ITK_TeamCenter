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

#ifndef TEAMCENTER_SERVICES_ADMINISTRATION__2007_06_AUTHORIZATION_HXX
#define TEAMCENTER_SERVICES_ADMINISTRATION__2007_06_AUTHORIZATION_HXX

#include <teamcenter/soa/client/model/Group.hxx>
#include <teamcenter/soa/client/model/User.hxx>


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
            namespace _2007_06
            {
                class Authorization;

class TCSOAADMINISTRATIONSTRONGMNGD_API Authorization
{
public:

    struct NameAuthorizationList;
    struct NameAuthorizationResponse;
    struct NameInfo;

    /**
     * This structure holds the accessibility information for the given user and group combinations
     * on the given applications or utilities.
     */
    struct NameAuthorizationList
    {
        /**
         * A list of NameAuthorizationResponse objects one for each of the given application
         * or utility.
         */
        std::vector< Teamcenter::Services::Administration::_2007_06::Authorization::NameAuthorizationResponse > output;
        /**
         * Object that holds the partial errors that occurred while getting the accessibility
         * on any of the given application or utility.
         */
        Teamcenter::Soa::Client::ServiceData partialErrors;
    };

    /**
     * This structure contains the name of the given application or utility, rule domain
     * name and the derived verdict that indicates whether the user and group combination
     * have accessibility on the application or utility or not.  True value for the verdict
     * indicates the user have authorization access on the application or the utility. False
     * value for the verdict indicates the user doesn't have authorization access on the
     * application or the utility.
     */
    struct NameAuthorizationResponse
    {
        /**
         * Name of the application or the utility.
         */
        std::string name;
        /**
         * Rule domain name.
         */
        std::string ruleDomain;
        /**
         * Derived verdict for the given user and group combination on the application or utility.
         */
        bool verdict;
    };

    /**
     * This structure contains the name of the application or utility and the rule domain
     * that indicates whether the name is that of an application or that of a utility.
     */
    struct NameInfo
    {
        /**
         * Name of an application or a utility whose accessibility for the given user need to
         * be determined.
         */
        std::string name;
        /**
         * The name of the rule domain. Valid rule domain  name is either Utility or Application.
         */
        std::string ruleDomain;
    };




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


protected:
    virtual ~Authorization() {}
};
            }
        }
    }
}

#include <teamcenter/services/administration/Administration_undef.h>
#endif

