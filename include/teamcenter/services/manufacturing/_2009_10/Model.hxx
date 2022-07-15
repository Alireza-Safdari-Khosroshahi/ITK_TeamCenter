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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2009_10_MODEL_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2009_10_MODEL_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/manufacturing/Manufacturing_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Manufacturing
        {
            namespace _2009_10
            {
                class Model;

class TCSOAMANUFACTURINGSTRONGMNGD_API Model
{
public:

    struct CalculateCriticalPathResponse;
    struct CalculateCriticalPathResult;
    struct FlowInput;
    struct FlowResponse;
    struct GetResolvedNodesFromLAResponse;
    struct LogicalAssignmentAttribute;
    struct LogicalAssignmentData;
    struct LogicalAssignmentResolvedNodes;
    struct ResolveData;
    struct ResolvedNodesInput;
    struct ResolvedNodesOutput;

    /**
     * The response structure for the calculateCriticalPath operation.
     */
    struct CalculateCriticalPathResponse
    {
        /**
         * A list of CalculateCriticalPathResult structures for each path returned.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2009_10::Model::CalculateCriticalPathResult > results;
        /**
         * This is a common data strucuture used to return sets of Teamcenter Data Model object
         * from a service request. This also holds services exceptions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * A structure that represents a path returned by the computeCriticalPath operation
     */
    struct CalculateCriticalPathResult
    {
        /**
         * The root object for which this path was computed
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * A list of components that make up the path. This includes the connecting flows.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > components;
        /**
         * The total duration of the path.
         */
        double duration;
    };

    /**
     * FlowInput
     */
    struct FlowInput
    {
        /**
         * The successor object of the flow object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  successor;
        /**
         * The predecessor object of the flow.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  predecessor;
        /**
         * The delay time for the successor.
         */
        double delay;
    };

    /**
     * FlowResponse
     */
    struct FlowResponse
    {
        /**
         * A vector of the new succesfully created flow objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > flowsResult;
        /**
         * serviceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response for getResolvedNodesFromLA SOA
     */
    struct GetResolvedNodesFromLAResponse
    {
        /**
         * All the resolved nodes of all objects
         */
        std::vector< Teamcenter::Services::Manufacturing::_2009_10::Model::ResolvedNodesOutput > outResolvedNodes;
        /**
         * Service data object
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Attribute representation
     */
    struct LogicalAssignmentAttribute
    {
        /**
         * Attribute name
         */
        std::string name;
        /**
         * Attribute value
         */
        std::string value;
    };

    /**
     * Parameters for editing Logical Assignment object
     */
    struct LogicalAssignmentData
    {
        /**
         * Logical Assignment object to edit
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  laObj;
        /**
         * Attributes to set to the object
         */
        std::vector< Teamcenter::Services::Manufacturing::_2009_10::Model::LogicalAssignmentAttribute > laAttributes;
    };

    /**
     * Holds resolved nodes of each LA
     */
    struct LogicalAssignmentResolvedNodes
    {
        /**
         * LA object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  laObj;
        /**
         * Resolved nodes of LA object
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > resolvedNodes;
    };

    /**
     * Data for object to resolve
     */
    struct ResolveData
    {
        /**
         * object to resolve
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * what type of LAs to resolve (class name)
         */
        std::string laResolveType;
        /**
         * if this flag is true, resolve all LAs of the above type of this object, all operations
         * and processes under this object, all operations and processes under child processes
         * and so on
         */
        bool recursive;
    };

    /**
     * Input for getResolvedNodesFromLA SOA
     */
    struct ResolvedNodesInput
    {
        /**
         * parent operation/process
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parentObject;
        /**
         * vector of LA objects of this op/proc, for which we want resolved nodes
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > laObjects;
    };

    /**
     * Holds resolved nodes of the whole parent object
     */
    struct ResolvedNodesOutput
    {
        /**
         * Parent object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parentObject;
        /**
         * Resolved nodes of all LA objects
         */
        std::vector< Teamcenter::Services::Manufacturing::_2009_10::Model::LogicalAssignmentResolvedNodes > laResolvedNodes;
    };




    /**
     * Calculate the critical paths for MFGBVRProcess, MFGBVROperation or MFGBVRActivity
     * and their corresponding APS objects. A critical path is the sequence of processes,
     * operations or activities that determine the minimum duration of the root object.
     * Thereby only those MFG objects will be considered that are either direct sub elements
     * or implementers of the root object.
     *
     * @param roots
     *        The list of MFG BVR or APS root objects the critical path is to be calculated for.
     *
     * @return
     *         For each object in the roots vector the list of critical paths. There maybe more
     *         than one per object if multiple paths of the same length exist.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Model::CalculateCriticalPathResponse calculateCriticalPath ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& roots ) = 0;

    /**
     * Create a new mfgFlow object between two mfg objects i.e process or operation
     *
     * @param input
     *        a vector of  FlowInput structures.
     *
     * @return
     *         Flow Response a vector of all the new created flow objects
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Model::FlowResponse createFlow ( const std::vector< Teamcenter::Services::Manufacturing::_2009_10::Model::FlowInput >& input ) = 0;

    /**
     * This service enables editing the values of Logical Assignment objects.
     *
     * @param laEditVec
     *        Vector of objects to edit.
     *
     * @return
     *         Service Data object that contains errors
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData editLogicalAssignments ( const std::vector< Teamcenter::Services::Manufacturing::_2009_10::Model::LogicalAssignmentData >& laEditVec ) = 0;

    /**
     * This service returns the resolved nodes for each of the received Logical Assignment
     * objects.
     *
     * @param inputObjects
     *        Input objects for which to return resolved nodes.
     *
     * @return
     *         Response object
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Model::GetResolvedNodesFromLAResponse getResolvedNodesFromLA ( const std::vector< Teamcenter::Services::Manufacturing::_2009_10::Model::ResolvedNodesInput >& inputObjects ) = 0;

    /**
     * Removing existing Flow objects.
     *
     * @param input
     *        a vector of  Flows to remove.
     *
     * @return
     *         Service Data object
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData removeFlow ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& input ) = 0;

    /**
     * This service will resolve and re-resolve logical assignments to concrete assignments
     * against the product structure.
     *
     * @param laVec
     *        Vector of Logical Assignment objects to resolve
     *
     * @param resolveObjects
     *        Vector of objects to resolve for each object the service will resolve all its Logical
     *        Assignments
     *
     * @param externalSources
     *        Vector of loaded product structures on which to run the resolve mechanism
     *
     * @return
     *         Service Data object that contains errors and a list of Logical Assignment objects
     *         that were actually updated.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData resolveLogicalAssignments ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& laVec,
        const std::vector< Teamcenter::Services::Manufacturing::_2009_10::Model::ResolveData >& resolveObjects,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& externalSources ) = 0;


protected:
    virtual ~Model() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

