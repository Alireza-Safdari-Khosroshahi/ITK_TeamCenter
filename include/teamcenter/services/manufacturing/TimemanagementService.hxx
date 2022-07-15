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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING_TIMEMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING_TIMEMANAGEMENTSERVICE_HXX

#include <teamcenter/services/manufacturing/_2008_06/Timemanagement.hxx>
#include <teamcenter/services/manufacturing/_2010_09/Timemanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/manufacturing/Manufacturing_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Manufacturing
        {
            class TimemanagementService;

/**
 * Contains TimeManagement Services
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoamanufacturingstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoamanufacturingtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAMANUFACTURINGSTRONGMNGD_API TimemanagementService
    : public Teamcenter::Services::Manufacturing::_2008_06::Timemanagement,
             public Teamcenter::Services::Manufacturing::_2010_09::Timemanagement
{
public:
    static TimemanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Calculates the allocated time for each requested bop line.
     *
     * @param object
     *        TODO
     *
     * @return
     *         structure containing the results of the allocated time calculation.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2008_06::Timemanagement::AllocatedTimeResponse allocatedTimeRollUp ( const Teamcenter::Services::Manufacturing::_2008_06::Timemanagement::AllocatedTime&  object ) = 0;

    /**
     * Calculates the total time for each activity category under a requested bop line.
     * An additional calculation is all the run time propertie related to the bop line time
     * calculations such as total time and duration time.
     *
     * @param inputs
     *        a Time Analysis Input structure, required
     *
     * @return
     *         structure containing the results of the time analysis calculation.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2008_06::Timemanagement::TimeAnalysisRollupResponse timeAnalysisRollup ( const Teamcenter::Services::Manufacturing::_2008_06::Timemanagement::TimeAnalysisInputs&  inputs ) = 0;

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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TimemanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

