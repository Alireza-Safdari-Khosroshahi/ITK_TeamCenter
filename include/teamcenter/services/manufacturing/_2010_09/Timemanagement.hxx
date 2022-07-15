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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2010_09_TIMEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2010_09_TIMEMANAGEMENT_HXX

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
            namespace _2010_09
            {
                class Timemanagement;

class TCSOAMANUFACTURINGSTRONGMNGD_API Timemanagement
{
public:

    struct CalculateCriticalPathResponseEx;
    struct CalculateCriticalPathResultEx;
    struct GetActivityTimesResponse;
    struct GetActivityTimesResult;

    /**
     * A map that contains activity time values for different activity categories.
     */
    typedef std::map< std::string, double > ActivityTimePerCategoryMap;

    /**
     * The response structure for the calculateCriticalPathEx operation. If it is not possible
     * to compute the critical path for a specific root object, no entry will be added
     * to the results vector. Instead the serviceData member will contain an description
     * of the failure cause.
     */
    struct CalculateCriticalPathResponseEx
    {
        /**
         * A list of CalculateCriticalPathResultEx structures for each path returned.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2010_09::Timemanagement::CalculateCriticalPathResultEx > results;
        /**
         * Contains a list of error descriptions if the path computation has failed.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * A structure that represents a path returned by the computeCriticalPathEx operation.
     */
    struct CalculateCriticalPathResultEx
    {
        /**
         * the root object for which this path was computed
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * A list of components that make up the path. This includes also the connecting flows.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > components;
        /**
         * The total length of the path.
         */
        double duration;
    };

    /**
     * The response structure of the getActivityTimes operation.
     */
    struct GetActivityTimesResponse
    {
        /**
         * A vector of GetActivityTimesResult structures that holds for each root node the list
         * of activity times indexed by category.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2010_09::Timemanagement::GetActivityTimesResult > results;
        /**
         * This is a common data structure that is used to return Teamcenter model data from
         * a service request. This member also holds service exceptions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * A structure that contains for a specific root node passed to the getActivityTimes
     * operation the map of accumulated activity times per category.
     */
    struct GetActivityTimesResult
    {
        /**
         * The root of the process or operation tree for which the activity times have been
         * calculated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  rootNode;
        /**
         * Contains the computed activity time for each category.
         */
        ActivityTimePerCategoryMap timePerCategoryMap;
    };




    /**
     * This operation computes the critical paths for processes or operations. The critical
     * path is the sequence of processes or operations that determine the minimum duration
     * of a specific object.  If the processLeafNodes flag is set, the algorithm will traverse
     * down the structure until it finds all leaf nodes that make up the path. Otherwise
     * only the direct children will be taken into account.
     *
     * @param roots
     *        The list of MFG process or operation objects the critical path is to be calculated
     *        for.
     *
     * @param processLeafNodes
     *        A flag that determines whether to compute the path from the leave nodes of the process/operation
     *        structure or from the direct children of a root object.
     *
     * @return
     *         For each object in the 'roots' vector the list of critical paths. There may be more
     *         than one per object if multiple paths of the same length exist.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2010_09::Timemanagement::CalculateCriticalPathResponseEx calculateCriticalPathEx ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& roots,
        bool processLeafNodes ) = 0;

    /**
     * Traverses a set of process or operation trees and computes the effective accumulated
     * times of all leaf activities, ignoring any flows between processes, operations or
     * activities.  For each activity category that is encountered, a distinct value is
     * returned.
     *
     * @param rootNodes
     *        The root nodes of the tree structures for which the activity times are to be computed.
     *
     * @return
     *         The list of activity times indexed by category for each root node in a GetActivityTimesResponse
     *         structure.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2010_09::Timemanagement::GetActivityTimesResponse getActivityTimes ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& rootNodes ) = 0;

    /**
     * Updates the allocated time property recursively for all nodes of a list of process
     * or operation trees.
     *
     * @param rootNodes
     *        Defines the root nodes of the trees to be updated.
     *
     * @param propagateZeroValues
     *        If this parameter is false, the allocated time of a specific node is only overwritten
     *        if more detailed information is available at a lower level.  This means that if a
     *        given node is not further detailed by any sub node, or if all of the computed times
     *        of the sub nodes are 0, the allocated time property of the parent will remain unchanged.
     *
     * @param stopLevel
     *        If this parameter is greater than 0, the update will stop that number of levels below
     *        the root node. This means that the root node itself will be excluded from the update
     *        if the value is 1; if it is 2, all child nodes with exception of the root's direct
     *        children will be updated and so forth.
     *
     * @param precedence
     *        The precedence vector defines how the allocated time of a leaf node is to be determined.
     *        Each entry must consist of one of the values 'estimated_time', 'simulated_time',
     *        'allocated_time' or 'analysis'.  In the case of 'estimated_time' or 'simulated_time'
     *        the value is retrieved from the respective property of the TimeAnalysis form.  In
     *        case of 'allocated_time' the previous value of the property will be reused.  The
     *        value 'analysis' specifies that the allocated time of an operation is to be recursively
     *        computed from its activity structure; for processes the result will always be 0.
     *        In case the evaluation of the first entry of the 'precedence' vector leads to a 0
     *        value, the algorithm will proceed with the next entry until the end of the vector
     *        is reached. If no suitable value is found, the resulting value will be 0.
     *
     * @return
     *         The ServiceData structure containing error information for this service request.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData populateAllocatedTimeProperties ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& rootNodes,
        bool propagateZeroValues,
        int stopLevel,
        const std::vector< std::string >& precedence ) = 0;

    /**
     * Recomputes the cached values of the runtime properties related to TimeManagement
     * for one or more process or operation trees. This will affect the properties of all
     * nodes of the tree structures defined by the rootNodes parameter.
     *
     * @param rootNodes
     *        The root nodes of the tree structures for which the runtime properties are to be
     *        calculated.
     *
     * @param fieldNames
     *        The names of the calculated fields to recompute. Currently the following fieldnames
     *        are accepted: Mfg0calc_duration, Mfg0calc_start_time, Mfg0calc_dur_start_time, bl_me_work_time
     *        and bl_me_duration. If the fieldName vector is empty, all of the properties will
     *        be updated.
     *
     * @return
     *         A ServiceData structure that contains the computed property values in the DataObject
     *         member. The structure also informs about errors that occurred during the course of
     *         the operation.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData updateTimeManagementProperties ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& rootNodes,
        const std::vector< std::string >& fieldNames ) = 0;


protected:
    virtual ~Timemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

