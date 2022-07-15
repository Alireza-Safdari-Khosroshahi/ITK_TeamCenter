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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING_MODELSERVICE_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING_MODELSERVICE_HXX

#include <teamcenter/services/manufacturing/_2009_10/Model.hxx>
#include <teamcenter/services/manufacturing/_2012_02/Model.hxx>



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
            class ModelService;

/**
 * Model
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

class TCSOAMANUFACTURINGSTRONGMNGD_API ModelService
    : public Teamcenter::Services::Manufacturing::_2009_10::Model,
             public Teamcenter::Services::Manufacturing::_2012_02::Model
{
public:
    static ModelService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * Gets the candidate tools against which Tool Requirement could be resolved. The candidate
     * tools are fetched based on the search criteria specified on the Tool Requirement.
     * The input parameter tool source specifies the source from where candidate tools are
     * supposed to be fetched.  The candidate tool can be fetched only in the Plant BOP.
     *
     * @param resolveObjects
     *        Input structure specifying Operation. Tool Requirement for which candidate tools
     *        are to be fetched. And tool source from where tools are to be fetched.
     *
     * @return
     *         Specifies the candidate tools that match the search criteria of the Tool requirement.
     *         Further resolveToolRequirement  could be used to resolve the TR with one of the candidate
     *         tools.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_02::Model::CandidateToolsForToolRequirement getCandidateToolsForToolRequirement ( const std::vector< Teamcenter::Services::Manufacturing::_2012_02::Model::ToolRequirementInput >& resolveObjects ) = 0;

    /**
     * Fetches the Tool Requirement for the given operation or process. Based on the status
     * of the Tool Requirement. either all. resolved or unresolved Tool Requirements are
     * returned. The respective options for the status are ALL. RESOLVED and UNRESOLVED.
     * Note that the Tool requirement assigned to child operation or process is not considered.
     *
     * @param parentObject
     *        Specifies the Operation of type Mfg0BvrOperation or Process of type Mfg0BvrProcess.
     *
     * @param toolRequirementStatus
     *        Specifies the status of the Tool requirement. The possible values are ALL & RESOLVED
     *        and UNRESOLVED. RESOLVED indicates that the Tool Requirement is resolved against
     *        the Tool. This option is relevant only for the Plant BOP where it is allowed to resolve
     *        the Tool Requirement.  UNRESOLVED indicates that the Tool Requirement is not resolved
     *        ALL includes both resolved and unresolved Tool Requirement.
     *
     * @return
     *         Specifies the Tool Requirements of type Mfg0BVRToolRequirement that are assigned
     *         to an Operation or Process
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_02::Model::ToolRequirementResponse getToolRequirements ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& parentObject,
        const std::vector< std::string >& toolRequirementStatus ) = 0;

    /**
     * Resolves the Tool Requirement with the provided tool. As a result the Tool is assigned
     * to the Tool Requirement and to the Operation for which Tool Requirement is defined.
     * This resolve operation  is allowed only in the Plant BOP.
     *
     * @param resolveObjects
     *        Specifies the data required for resolving the Tool requirement.
     *
     * @return
     *         Service data will hold partial errors & warnings and errors. if any.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData resolveToolRequirement ( const std::vector< Teamcenter::Services::Manufacturing::_2012_02::Model::ResolveDataInfo >& resolveObjects ) = 0;

    /**
     * Updates flows between the children of input object(s) based on Find number value.
     * Input objects should be an instance of BOM line. This service does not return any
     * resulting or affected objects. The client needs to update cache of affected objects
     * manually(children of the input object are affected ). If isSubHierarchies parameter
     * is true, flows are recursively updated for all children.
     *
     * @param input
     *        Should be a vector of BOM lines. This is a scope of update flow command.
     *
     * @param isSubHierarchies
     *        If isSubHierarchies parameter is true, flows are recursively updated for all children.
     *
     * @return
     *         Returns error message(s) if any generated during update flow execution. Please note
     *         service data will not return any resulting objects.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData updateFlows ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& input,
        bool isSubHierarchies ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ModelService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

