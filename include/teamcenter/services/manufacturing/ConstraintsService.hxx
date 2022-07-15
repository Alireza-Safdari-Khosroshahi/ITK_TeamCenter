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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING_CONSTRAINTSSERVICE_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING_CONSTRAINTSSERVICE_HXX

#include <teamcenter/services/manufacturing/_2012_02/Constraints.hxx>



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
            class ConstraintsService;

/**
 * Contains service methods to fetch/validate constraints
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

class TCSOAMANUFACTURINGSTRONGMNGD_API ConstraintsService
    : public Teamcenter::Services::Manufacturing::_2012_02::Constraints
{
public:
    static ConstraintsService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ConstraintsService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

