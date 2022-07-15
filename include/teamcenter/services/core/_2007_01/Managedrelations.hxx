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

#ifndef TEAMCENTER_SERVICES_CORE__2007_01_MANAGEDRELATIONS_HXX
#define TEAMCENTER_SERVICES_CORE__2007_01_MANAGEDRELATIONS_HXX

#include <teamcenter/soa/client/model/TraceLink.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2007_01
            {
                class Managedrelations;

class TCSOACORESTRONGMNGD_API Managedrelations
{
public:

    struct ComplyingReport;
    struct CreateManagedRelationInput;
    struct DefiningReport;
    struct ManagedRelationResponse;
    struct ModifySources;
    struct ModifyTargets;
    struct ModifyManagedRelationInput;
    struct TraceabilityInfoInput;
    struct TraceabilityReportOutput;

    /**
     * Complying Report
     */
    struct ComplyingReport
    {
        /**
         * Tag of the Parent
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parent;
        /**
         * List of Children
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > children;
    };

    /**
     * This structure has all the information needed to create TraceLink managed relation.
     */
    struct CreateManagedRelationInput
    {
        /**
         * name
         */
        std::string name;
        /**
         * Type will decide what relation to be created
         */
        std::string type;
        /**
         * primaryTagList
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > primaryTagList;
        /**
         * secondaryTagList
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > secondaryTagList;
    };

    /**
     * Defining Report
     */
    struct DefiningReport
    {
        /**
         * Tag of the Parent
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parent;
        /**
         * List of Children
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > children;
    };

    /**
     * Managed Relation Response
     */
    struct ManagedRelationResponse
    {
        /**
         * List of Managed Relation Objects
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TraceLink>  > managedRelationObjects;
        /**
         * The successful Object ids, partial errors and failures
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Modify Sources
     */
    struct ModifySources
    {
        /**
         * List of Sources to Add
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > addSources;
        /**
         * List of Sources to Remove
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > removeSources;
    };

    /**
     * Modify Targets
     */
    struct ModifyTargets
    {
        /**
         * List of Targets to Add
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > addTargets;
        /**
         * List of Targets to Remove
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > removeTargets;
    };

    /**
     * Modify Managed Relation Input
     */
    struct ModifyManagedRelationInput
    {
        /**
         * Tag of the Relation
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  relationTag;
        /**
         * Modify Sources Input
         */
        Teamcenter::Services::Core::_2007_01::Managedrelations::ModifySources setSourcesInput;
        /**
         * Modify Targets Input
         */
        Teamcenter::Services::Core::_2007_01::Managedrelations::ModifyTargets setTargetsInput;
    };

    /**
     * Traceability Information Input
     */
    struct TraceabilityInfoInput
    {
        /**
         * Tag of the input
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  inputTag;
        /**
         * Report Type
         */
        std::string reportType;
        /**
         * Report Depth
         */
        int reportDepth;
    };

    /**
     * Traceability Report Output
     */
    struct TraceabilityReportOutput
    {
        /**
         * List of Defining Reports
         */
        std::vector< Teamcenter::Services::Core::_2007_01::Managedrelations::DefiningReport > definingTree;
        /**
         * List of Defining Reports (Indirect)
         */
        std::vector< Teamcenter::Services::Core::_2007_01::Managedrelations::DefiningReport > indirectDefiningTree;
        /**
         * List of Complying Reports
         */
        std::vector< Teamcenter::Services::Core::_2007_01::Managedrelations::ComplyingReport > complyingTree;
        /**
         * List of Complying Reports (Indirect)
         */
        std::vector< Teamcenter::Services::Core::_2007_01::Managedrelations::ComplyingReport > indirectComplyingTree;
        /**
         * The successful Object ids, partial errors and failures
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation will create new managed relation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param relationinfo
     *        input information required to create managed relation
     *
     * @return
     *         has any created relation and the service data.Failure will be returned with input
     *         index and error message in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Core::_2007_01::Managedrelations::ManagedRelationResponse createRelation ( const std::vector< Teamcenter::Services::Core::_2007_01::Managedrelations::CreateManagedRelationInput >& relationinfo ) = 0;

    /**
     * This operation will create traceability report for the selected TC object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param input
     *        information required to create report
     *
     * @return
     *         has traceability tree for the given TC object and the service data. Failure will
     *         be returned with input index and error message in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Core::_2007_01::Managedrelations::TraceabilityReportOutput getTraceReport ( const Teamcenter::Services::Core::_2007_01::Managedrelations::TraceabilityInfoInput&  input ) = 0;

    /**
     * This operation will Edit the managed relation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param newInput
     *        will have the modification info for given relation
     *
     * @return
     *         will loadthe modified relation along with service data. Failure will be returned
     *         with input index and error message in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Core::_2007_01::Managedrelations::ManagedRelationResponse modifyRelation ( const std::vector< Teamcenter::Services::Core::_2007_01::Managedrelations::ModifyManagedRelationInput >& newInput ) = 0;


protected:
    virtual ~Managedrelations() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

