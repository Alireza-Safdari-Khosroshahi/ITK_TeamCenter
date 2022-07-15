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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2012_02_CONSTRAINTS_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2012_02_CONSTRAINTS_HXX

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
            namespace _2012_02
            {
                class Constraints;

class TCSOAMANUFACTURINGSTRONGMNGD_API Constraints
{
public:

    struct AdjacentObjectInfo;
    struct GetPrecedenceConstraintPathsInputs;
    struct GetPrecedenceConstraintPathsResponse;
    struct GetPrecedenceConstraintPathsResult;
    struct GetPrecedenceConstraintsIn;
    struct GetPrecedenceConstraintsResponse;
    struct PrecedenceConstraintPath;
    struct PrecedenceConstraintPathComponent;
    struct ValidateConstraintConsistencyError;
    struct ValidateConstraintConsistencyInputs;
    struct ValidateConstraintConsistencyResponse;
    struct ValidateConstraintConsistencyResult;
    struct ValidateProcessAreaAssignmentsError;
    struct ValidateProcessAreaAssignmentsInputs;
    struct ValidateProcessAreaAssignmentsResponse;
    struct ValidateProcessAreaAssignmentsResult;

    /**
     * The map containing a BusinessObject as key and its list of adjacent objects (predecessor/successor)
     * as the value
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , std::vector< AdjacentObjectInfo > > AdjacentObjectsMap;

    /**
     * The structure representing an adjacent object (either the predecessor or the successor)
     * along with the constraint object
     */
    struct AdjacentObjectInfo
    {
        /**
         * The constraint object (Mfg0BvrPrecedenceConstraint)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  constraintObject;
        /**
         * The preceding or succeeding object (Mfg0BvrProcess / Mfg0BvrOperation)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  adjacentObject;
    };

    /**
     * Input structure for the getPrecedenceConstraintPaths operation.
     */
    struct GetPrecedenceConstraintPathsInputs
    {
        /**
         * The process/operation line at the start of the precedence chain. This member can
         * hold BOs of type Mfg0BvrProcess and Mfg0BvrOperation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  startNode;
        /**
         * The operation/process line at the end of the precedence chain This member can hold
         * BOs of type Mfg0BvrProcess and Mfg0BvrOperation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  endNode;
    };

    /**
     * Response structure for the getPrecedenceConstraintPaths operation.
     */
    struct GetPrecedenceConstraintPathsResponse
    {
        /**
         * A list of result structures that contain the paths for each start and end node pair
         * specfied in the input structures.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_02::Constraints::GetPrecedenceConstraintPathsResult > results;
        /**
         * The ServiceData object for the matching GetPrecedenceConstraintPathsInputs structure.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The result structure for the getPrecedenceConstraintPaths operation.
     */
    struct GetPrecedenceConstraintPathsResult
    {
        /**
         * The list of paths that connect the respective start and end node.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_02::Constraints::PrecedenceConstraintPath > paths;
    };

    /**
     * The input structure for the getPrecedenceConstraints service operation
     */
    struct GetPrecedenceConstraintsIn
    {
        /**
         * The integer indicating the number of predecessor levels to be processed in the precedence
         * chain
         */
        int predecessorLevel;
        /**
         * The integer indicating the number of successor levels to be processed in the precedence
         * chain
         */
        int successorLevel;
        /**
         * The input object (Mfg0BvrProcess / Mfg0BvrOperation)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  inputObject;
    };

    /**
     * The response structure of the getPrecedenceConstraints service operation. Contains
     * the predecessor and successor maps.
     */
    struct GetPrecedenceConstraintsResponse
    {
        /**
         * The map of objects to their predecessors
         */
        AdjacentObjectsMap predecessorMap;
        /**
         * The map of objects to their successors
         */
        AdjacentObjectsMap successorMap;
        /**
         * The ServiceData structure
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Defines a specific path for the GetPrecedenceConstraintPaths API
     */
    struct PrecedenceConstraintPath
    {
        /**
         * A list of structures that hold the nodes and constraints that make up the path to
         * the end node.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_02::Constraints::PrecedenceConstraintPathComponent > components;
        /**
         * The end node itself. The Business Object  is of type Mfg0BvrProcess or Mfg0BvrOperation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  endNode;
    };

    /**
     * A component of a constraint path for structure PrecedenceConstraintPath
     */
    struct PrecedenceConstraintPathComponent
    {
        /**
         * A node which is part of the path (type Mfg0BvrProcess or Mfg0BvrOperation).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  predecessor;
        /**
         * The constraint that connects the node of this component structure to the next, or,
         * in case this is the last component in the path, to the end node. Note that the predecessor
         * of the constraint is different from the predecessor member in case the constraint
         * is inherited.The same applies to the successor of the constraint: it does not necessarily
         * have to be the successor in the path. This member is of type Mfg0BvrPrecedenceConstraint.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  constraint;
        /**
         * Indicates whether the constraint is directly connected to the predecessor and successor
         * nodes in the path or whether it has been inherited from a parent node:
         */
        bool constraintIsInherited;
    };

    /**
     * Describes a problem detected by the validateConstraintConsistency operation.
     */
    struct ValidateConstraintConsistencyError
    {
        /**
         * The type of the constraint that is violated. This is the ImanType of the runtime
         * constraint object, for example Mfg0BvrPrecedenceConstraint for precedence constraints.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  constraintType;
        /**
         * A localized message explaining the detected inconsistency.
         */
        std::string message;
        /**
         * The list of operations/processes that participate in the constraints that are inconsistent.
         * The list contains business objects of type Mfg0BvrOperation and Mfg0BvrProcess.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objects;
        /**
         * The constraint objects which are inconsistent.These objects are of type Mfg0BvrConstraint.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > constraints;
    };

    /**
     * Input structure for the validateConstraintConsistency operation.
     */
    struct ValidateConstraintConsistencyInputs
    {
        /**
         * The constraint types to check. Each entry in this vector is of type ImanType; it
         * corresponds to the type of the runtime object for the constraint (e.g. Mfg0BvrPrecedenceConstraint
         * for precedence constraints or Mfg0BvrPrecedenceConstraint for group constraints;
         * customer defined derived types are accepted as well). If the vector is empty, all
         * constraints are checked.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > constraintTypes;
        /**
         * The list of BOMLines from the BOP window that define the root nodes of the sub structures
         * to check.  The objects must be of type Mfg0BvrProcess or Mfg0BvrOperation. All lines
         * must be associated with the same window.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > rootNodes;
    };

    /**
     * Response structure of the validateConstraintConsistencyResponse operation.
     */
    struct ValidateConstraintConsistencyResponse
    {
        /**
         * The list of result structures that holds one entry for each input structure.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_02::Constraints::ValidateConstraintConsistencyResult > results;
        /**
         * The ServiceData object for this request.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Result structure for the validateConstraintConsistency operation.
     */
    struct ValidateConstraintConsistencyResult
    {
        /**
         * The  list of validation errors, if any.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_02::Constraints::ValidateConstraintConsistencyError > errors;
    };

    /**
     * A structure that contains information about an problem detected in the ValidateProcessAreaAssignments
     * operation. In the case of a precedence constraint violation, the objectsOfContextOfConstraint
     * vector will contain the predecessor and the sucessor operation or process whose order
     * is conflicting with the order of the process areas they are assigned to, if a Product
     * BOP is given. The objectsOfContextToValidate member will contain their respective
     * counterparts in the Plant BOP, and processAreas will contain the associated process
     * areas. In case of a precedence constraint violations the constraints vector will
     * be empty, since the constraints themselves are meaningless without the intermittent
     * operations/processes. In order to obtain the paths of processes/operations and constraints
     * that define the precedence of the start and end node, the GetPrecedenceConstraintPathsAPI
     * may be used. Currently one possible type of error may arise when precedence constraints
     * are violated. The format of the error message is similar to the following: <Node
     * A> is assigned to <Process Area X> while its successor <Node B> is assigned to <Process
     * Area Y>  which is a predecessor of  <Process Area X>.
     */
    struct ValidateProcessAreaAssignmentsError
    {
        /**
         * The type of the constraint that is violated. Corresponds to the ImanType of the constraint
         * object. See also the constraintTypes member of struct ValidateProcessAreaAssignmentsInputs.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  constraintType;
        /**
         * A localized message explaining the validation error.
         */
        std::string message;
        /**
         * The list of operations and/or processes that violate the constraints. These objects
         * belong to the contexts passed via the contextOfConstraints parameter i.e. the Product
         * BOPs. The vector will be empty if the contextOfConstraints vector is empty. The list
         * contains business objects of type Mfg0BvrOperation and Mfg0BvrProcess.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objectsOfContextOfConstraint;
        /**
         * The list of assigned nodes from the contextToValidate parameter. In case only a single
         * Product BOP exists, the vector will hold the same number of objects as the objectsOfContextOfConstraint
         * member. The business objects are of type Mfg0BvrOperation and Mfg0BvrProcess.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objectsOfContextToValidate;
        /**
         * The list of process areas associated with the Product BOP objects. The objects are
         * of type Mfg0BvrProcessArea and belong to the context passed in contextToValidate.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > processAreas;
        /**
         * The constraint objects which are violated. These objects are of type Mfg0BvrConstraint.
         * Note that depending on the type of violation the constraints list may be empty. This
         * is the case for example for precedence constraints.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > constraints;
    };

    /**
     * Input structure for the validateProcessAreaAssignments operation.
     */
    struct ValidateProcessAreaAssignmentsInputs
    {
        /**
         * The constraint types to check. Each entry in this vector is of type ImanType; it
         * corresponds to the type of the runtime object for the constraint (e.g. Mfg0BvrPrecedenceConstraint
         * for precedence constraints or Mfg0BvrGroupConstraint for group constraints). The
         * types vector may also contain customized types derived from the base constraint types.
         * If the vector is empty, all constraints are checked.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > constraintTypes;
        /**
         * The context of the process area structure. This is the top line of the window that
         * holds the Plant BOP structure (the object is of type Mfg0BvrPlantBOP).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  contextToValidate;
        /**
         * A list of contexts that describes the processes and operations whose assignments
         * are to be validated. If empty it is assumed that the context of the process area
         * structure is to be used. Currently only one single is accepted that represents the
         * topline of the Product BOP structure (this object must be of type Mfg0BvrProductBOP).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > contextOfConstraints;
        /**
         * The list of BOMLines from the Plant BOP window that define the substructure whose
         * allocations are examined If the list is empty, the whole Plant BOP loaded into the
         * Plant BOP window will be checked. The Business Objects are of type Mfg0BvrProcessArea.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > rootProcessAreas;
        /**
         * The maximum number of errors to return. Can be set to 0 in order not to impose any
         * limit. Otherwise the value must be greater than 0.
         */
        int maxErrors;
    };

    /**
     * Response structure for the validateProcessAreaAssignments operation.
     */
    struct ValidateProcessAreaAssignmentsResponse
    {
        /**
         * The list of result structures that holds one entry for each input structure.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_02::Constraints::ValidateProcessAreaAssignmentsResult > results;
        /**
         * The ServiceData object for this request.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Result structure for the validateProcessAreaAssignments operation.
     */
    struct ValidateProcessAreaAssignmentsResult
    {
        /**
         * The  list of validation errors, if any.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_02::Constraints::ValidateProcessAreaAssignmentsError > errors;
    };




    /**
     * Returns all operations/processes in the precedence chain starting from the given
     * start operation/process up to the end operation/process, i.e., all operations/processes
     * succeeding the start operation/process and preceding the end operation/process.
     *
     * @param inputData
     *        The input data contains the list of start and end operation or process lines.
     *
     * @return
     *         A structure holding a vector of constraint paths for each input structure.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_02::Constraints::GetPrecedenceConstraintPathsResponse getPrecedenceConstraintPaths ( const std::vector< Teamcenter::Services::Manufacturing::_2012_02::Constraints::GetPrecedenceConstraintPathsInputs >& inputData ) = 0;

    /**
     * Fetches all precedence constraints defined on the given input objects - traverses
     * 'm' levels in the predecessor chain and 'n' levels in the successor chain.
     *
     * @param inputData
     *        The list of input objects (Mfg0BvrProcess / Mfg0BvrOperation) whose precedence constraints
     *        are to be fetched along with the number of levels to be traversed in the predecessor
     *        and successor chains.
     *
     * @return
     *         Returns a map of predecessors and successors for each object
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Manufacturing::_2012_02::Constraints::GetPrecedenceConstraintsResponse getPrecedenceConstraints ( const std::vector< Teamcenter::Services::Manufacturing::_2012_02::Constraints::GetPrecedenceConstraintsIn >& inputData ) = 0;

    /**
     * This SOA invokes the consistency check service. It checks whether the constraints
     * defined in the product BOP or a sub structure thereof are consistent.
     *
     * @param inputData
     *        A vector of ValidateConstraintConsistencyInputs structures that defines one or multiple
     *        substructures to check.
     *
     * @return
     *         A set of error descriptions for each input structure.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_02::Constraints::ValidateConstraintConsistencyResponse validateConstraintConsistency ( const std::vector< Teamcenter::Services::Manufacturing::_2012_02::Constraints::ValidateConstraintConsistencyInputs >& inputData ) = 0;

    /**
     * This SOA invokes the constraint validation service. It checks whether the assignments
     * of operations or processes of a Product BOP to process areas in a Plant BOP are consistent
     * with the constraint definitions.
     *
     * @param inputData
     *        A vector of ValidateProcessAreaAssignmentsInputs structures that define the the Plant
     *        and Product BOPs and the set of nodes to validate in the Plant BOP.
     *
     * @return
     *         A structure that contains a list of errors for each input structure.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_02::Constraints::ValidateProcessAreaAssignmentsResponse validateProcessAreaAssignments ( const std::vector< Teamcenter::Services::Manufacturing::_2012_02::Constraints::ValidateProcessAreaAssignmentsInputs >& inputData ) = 0;


protected:
    virtual ~Constraints() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

