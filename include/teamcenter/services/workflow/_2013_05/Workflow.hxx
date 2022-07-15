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

#ifndef TEAMCENTER_SERVICES_WORKFLOW__2013_05_WORKFLOW_HXX
#define TEAMCENTER_SERVICES_WORKFLOW__2013_05_WORKFLOW_HXX

#include <teamcenter/soa/client/model/EPMTaskTemplate.hxx>
#include <teamcenter/soa/client/model/WorkspaceObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/workflow/Workflow_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Workflow
        {
            namespace _2013_05
            {
                class Workflow;

class TCSOAWORKFLOWSTRONGMNGD_API Workflow
{
public:

    struct GetWorkflowTemplatesInputInfo;
    struct GetWorkflowTemplatesOutput;
    struct GetWorkflowTemplatesResponse;

    /**
     * Structure to define input for workflow Templates
     */
    struct GetWorkflowTemplatesInputInfo
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * If set to true, the operation will return Under construction templates for administrative
         * users only.  Otherwise only available workflow templates are returned.
         */
        bool includeUnderConstruction;
        /**
         * If set to true, the operation will return assigned or filtered list of workflow templates
         * based on Target Objects and Object Types.
         */
        bool getFiltered;
        /**
         * List of target objects to be used for getting the filtered list of workflow templates.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  > targetObjects;
        /**
         * List of target object types to be used for getting the filtered list of workflow
         * templates. This argument is not required if targetObjects are specified.
         */
        std::vector< std::string > objectTypes;
        /**
         * User group to get the filtered list of  workflow templates.
         */
        std::string group;
    };

    /**
     * Structure to define output for workflow Templates
     */
    struct GetWorkflowTemplatesOutput
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * A list of output workflow Templates.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMTaskTemplate>  > workflowTemplates;
    };

    /**
     * Structure to define response for workflow Templates
     */
    struct GetWorkflowTemplatesResponse
    {
        /**
         * ServiceData contains any partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * Complete list of workflow Templates Output.
         */
        std::vector< Teamcenter::Services::Workflow::_2013_05::Workflow::GetWorkflowTemplatesOutput > templatesOutput;
    };




    /**
     * This operation gets the list of workflow templates based on input criteria. The criteria
     * includes the target objects for the workflow or the types of the target objects.
     * User can also specify if the under construction templates should to be returned and
     * if the filtered list of templates is required. The filtered list of templates are
     * returned based on the users group and the target objects. The filter rules can also
     * be customized using the user exits.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param input
     *        Structure to define input for workflow Templates.
     *
     * @return
     *         This operation returns the list of workflow templates based on the input criteria
     *         and ServiceData structure containing errors if any.
     *
     */
    virtual Teamcenter::Services::Workflow::_2013_05::Workflow::GetWorkflowTemplatesResponse getWorkflowTemplates ( const std::vector< Teamcenter::Services::Workflow::_2013_05::Workflow::GetWorkflowTemplatesInputInfo >& input ) = 0;


protected:
    virtual ~Workflow() {}
};
            }
        }
    }
}

#include <teamcenter/services/workflow/Workflow_undef.h>
#endif

