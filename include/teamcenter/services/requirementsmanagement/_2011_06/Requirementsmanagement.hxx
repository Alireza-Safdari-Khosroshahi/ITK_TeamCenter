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

#ifndef TEAMCENTER_SERVICES_REQUIREMENTSMANAGEMENT__2011_06_REQUIREMENTSMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_REQUIREMENTSMANAGEMENT__2011_06_REQUIREMENTSMANAGEMENT_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/requirementsmanagement/Requirementsmanagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Requirementsmanagement
        {
            namespace _2011_06
            {
                class Requirementsmanagement;

class TCSOAREQUIREMENTSMANAGEMENTSTRONGMNGD_API Requirementsmanagement
{
public:

    struct PublishColumnConfigInfo;

    /**
     * <code>PublishColumnConfigInfo</code> structure represents the parameters required
     * to publish the column configuration.
     */
    struct PublishColumnConfigInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The <b>Fnd0ColumnConfiguration</b> object, that stores all preferences that needs
         * to be created as site preferences.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  columnConfiguration;
    };




    /**
     * This operation publishes the Column Configuration that is <b>Mark as Publishable</b>
     * by the user. This operation will get the column configuration values from the specified
     * <b>Fnd0ColumnConfiguration</b> object and create the site preferences. After creating
     * the site preference it will set the "IsPublished" property to true present on the
     * specified <b>Fnd0ColumnConfiguration</b> object.  So by creating the site preference
     * these column configuration will be visible to all present users in the system. This
     * operation converts the user preferences to the site level preferences in Teamcenter
     * Context so that all users can use it. When user save the column configuration, applied
     * on the BOM structure then it will store all applied column configuration values as
     * user protection scope preferences. After that user can mark the same column configuration
     * as <b>Mark as Publishable</b> that means user want that column configuration to be
     * available to other users in the system. So <b>Administrator privileged user</b> can
     * publish the column configuration so it will be available to all other users in the
     * system. The user which originally saved the column configuration will see two preferences
     * with same name, one with protection scope user and other one with site protection
     * scope.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * You can publish the column configuration that is <b>Mark as Publishable</b> by the
     * user so that it will be visible to all other users and others users can apply the
     * publish column configuration on BOM structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param input
     *        A list of <code>PublishColumnConfigInfo</code> structures which hold the required
     *        information to publish the column configuration.
     *
     * @return
     *         ServiceData object is returned. The updated <b>Fnd0ColumnConfiguration</b> object
     *         is returned in the updated object list of ServiceData. Any failure will be returned
     *         with client id mapped to error message in the ServiceData list of partial errors.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData publishColumnConfiguration ( const std::vector< Teamcenter::Services::Requirementsmanagement::_2011_06::Requirementsmanagement::PublishColumnConfigInfo >& input ) = 0;


protected:
    virtual ~Requirementsmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/requirementsmanagement/Requirementsmanagement_undef.h>
#endif

