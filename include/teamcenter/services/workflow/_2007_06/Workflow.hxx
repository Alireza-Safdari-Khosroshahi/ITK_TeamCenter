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

#ifndef TEAMCENTER_SERVICES_WORKFLOW__2007_06_WORKFLOW_HXX
#define TEAMCENTER_SERVICES_WORKFLOW__2007_06_WORKFLOW_HXX

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
            namespace _2007_06
            {
                class Workflow;

class TCSOAWORKFLOWSTRONGMNGD_API Workflow
{
public:

    struct ReleaseStatusInput;
    struct ReleaseStatusOption;
    struct SetReleaseStatusResponse;

    /**
     * releaseStatusOperation
     */
    enum releaseStatusOperation{ Append,
                 Delete,
                 Rename,
                 Replace
                 };

    /**
     * ReleaseStatus input
     */
    struct ReleaseStatusInput
    {
        /**
         * Operations to perform ( Currently only Append is supported )
         */
        std::vector< Teamcenter::Services::Workflow::_2007_06::Workflow::ReleaseStatusOption > operations;
        /**
         * Objects to modify
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  > objects;
    };

    /**
     * ReleaseStatus option
     */
    struct ReleaseStatusOption
    {
        /**
         * Name of release type to instantiate and assign
         */
        std::string newReleaseStatusTypeName;
        /**
         * Operation to perform
         */
        releaseStatusOperation operation;
        /**
         * Name of old release type to delete or replace
         */
        std::string existingreleaseStatusTypeName;
    };

    /**
     * service data
     */
    struct SetReleaseStatusResponse
    {
        /**
         * serviceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Manages the release status status of an object  The permitted operations are Append,
     * Delete, Rename and Replace Currently Append and Delete are supported With the delete
     * operation if an empty string is passed in instead of the status name all statuses
     * will be cleared for that set of workspace objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Workflow - Component for Workflow elements
     *
     * @param input
     *        A vector of ReleaseStatusInput structures that control operations performed on the
     *        objects
     *
     * @return
     *         Failure will be with error messages in the ServiceData.
     *
     *
     * @exception ServiceException
     *           Teamcenter::Soa::Server::ServiceException:
     *           <br>
     */
    virtual Teamcenter::Services::Workflow::_2007_06::Workflow::SetReleaseStatusResponse setReleaseStatus ( const std::vector< Teamcenter::Services::Workflow::_2007_06::Workflow::ReleaseStatusInput >& input ) = 0;


protected:
    virtual ~Workflow() {}
};
            }
        }
    }
}

#include <teamcenter/services/workflow/Workflow_undef.h>
#endif

