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

#ifndef TEAMCENTER_SERVICES_WORKFLOW__2010_09_WORKFLOW_HXX
#define TEAMCENTER_SERVICES_WORKFLOW__2010_09_WORKFLOW_HXX

#include <teamcenter/soa/client/model/EPMJob.hxx>
#include <teamcenter/soa/client/model/EPMTaskTemplate.hxx>


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
            namespace _2010_09
            {
                class Workflow;

class TCSOAWORKFLOWSTRONGMNGD_API Workflow
{
public:

    struct ApplyTemplateInput;
    struct ApplyTemplateOutput;
    struct ApplyTemplateResponse;

    /**
     * New versions of the workflow templates that needs to be applied including the corresponding
     * client ids.
     */
    struct ApplyTemplateInput
    {
        /**
         * client id
         */
        std::string clientId;
        /**
         * Process template to be applied
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMTaskTemplate>  processTemplate;
    };

    /**
     * Results from applying a template to its corresponding active processes.
     */
    struct ApplyTemplateOutput
    {
        /**
         * client id
         */
        std::string clientId;
        /**
         * Active processes that were updated successfully
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMJob>  > updatedProcesses;
        /**
         * Active processes that could not be updated
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::EPMJob>  > failedProcesses;
    };

    /**
     * Information about active processes that were updated with template changes
     */
    struct ApplyTemplateResponse
    {
        /**
         * List of processes that were updated and list of processes that failed.
         */
        std::vector< Teamcenter::Services::Workflow::_2010_09::Workflow::ApplyTemplateOutput > applyTemplateOutput;
        /**
         * Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Apply the specified templates to all active workflow processes that are based on
     * earlier versions of the templates.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param applyTemplateInput
     *        Templates to be applied to active processes
     *
     * @param processingMode
     *        Indicates if request needs to be processed asynchronously.  0 - Indicates synchronous
     *        processing. 1 - Indicates asynchronous processing.
     *
     * @return
     *         List of active processes that were updated successfully and list of failures
     *
     *
     * @exception ServiceException
     *           Teamcenter::Soa::Server::ServiceException:
     *           <br>
     */
    virtual Teamcenter::Services::Workflow::_2010_09::Workflow::ApplyTemplateResponse applyTemplateToProcesses ( const std::vector< Teamcenter::Services::Workflow::_2010_09::Workflow::ApplyTemplateInput >& applyTemplateInput,
        int processingMode ) = 0;


protected:
    virtual ~Workflow() {}
};
            }
        }
    }
}

#include <teamcenter/services/workflow/Workflow_undef.h>
#endif

