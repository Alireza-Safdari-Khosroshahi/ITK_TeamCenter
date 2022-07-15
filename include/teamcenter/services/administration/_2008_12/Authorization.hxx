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

#ifndef TEAMCENTER_SERVICES_ADMINISTRATION__2008_12_AUTHORIZATION_HXX
#define TEAMCENTER_SERVICES_ADMINISTRATION__2008_12_AUTHORIZATION_HXX

#include <teamcenter/services/administration/_2007_06/Authorization.hxx>
#include <teamcenter/soa/client/model/Group.hxx>
#include <teamcenter/soa/client/model/Role.hxx>
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
            namespace _2008_12
            {
                class Authorization;

class TCSOAADMINISTRATIONSTRONGMNGD_API Authorization
{
public:





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


protected:
    virtual ~Authorization() {}
};
            }
        }
    }
}

#include <teamcenter/services/administration/Administration_undef.h>
#endif

