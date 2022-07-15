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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2012_02_MODEL_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2012_02_MODEL_HXX

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
                class Model;

class TCSOAMANUFACTURINGSTRONGMNGD_API Model
{
public:

    struct CandidateTool;
    struct CandidateToolsForToolRequirement;
    struct ResolveDataInfo;
    struct Tool;
    struct ToolRequirementInput;
    struct ToolRequirementResponse;
    struct ToolRequirementResult;

    /**
     * Specifies the candidate tools for the Operation or Process where Tool Requirement
     * is assigned.
     */
    struct CandidateTool
    {
        /**
         * Specifies the Operation of type Mfg0BvrOperation or Process of type Mfg0BvrProcess
         * where Tool Requirement is assigned.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parentObject;
        /**
         * Specifies the candidate tools matching the search criteria of the Tool Requirement.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_02::Model::Tool > tools;
    };

    /**
     * Specifies the candidate tools for the Tool Requirement
     */
    struct CandidateToolsForToolRequirement
    {
        /**
         * Structure with member as Operation or Process and the candidate tools.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_02::Model::CandidateTool > candidateTools;
        /**
         * Service data will hold warnings and errors. if any.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input structure specifying the Operation or Process. the Tool Requirement that is
     * to be resolved. the Tool with which Tool requirement resolve against and the tool
     * source from where tool is to be picked.
     */
    struct ResolveDataInfo
    {
        /**
         * Specifies the Operation of type Mfg0BvrOperation or Process of type Mfg0BvrProcess
         * under which Tool requirement is assigned.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parent;
        /**
         * Specifies the Tool Requirement of type Mfg0BVRToolRequirement that is to be resolved.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  trObject;
        /**
         * Tool of type Mfg0BvrResource that matches the search criteria of the Tool Requirement
         * and against which it is going to be resolved.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  toolObject;
        /**
         * Specifies the source from where the tool is to be fetched. The possible values are
         * LIBRARY & WORKAREA and ALL which specify that the tool is to be fetched respectively
         * from only library only workarea or workarea and library. Note that in the case of
         * ALL the preference is given to the workarea over the library.
         */
        std::string toolSource;
    };

    /**
     * Specifies the candidate tools with members as the Tool Requirement and the tools
     * that match the search criteria of Tool Requirement.
     */
    struct Tool
    {
        /**
         * Specifies the Tool Requirement of type Mfg0BVRToolRequirement.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  trObject;
        /**
         * Specifies the candidate tools of type Mfg0BvrResource matching the search criteria
         * of the Tool Requirement.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > toolObjects;
    };

    /**
     * Input structure specifying the Operation or Process. the Tool Requirement for which
     * candidate tools are to be fetched and the tool source from where tools are to be
     * fetched.
     */
    struct ToolRequirementInput
    {
        /**
         * Specifies the Operation of type Mfg0BvrOperation or Process of type Mfg0BvrProcess
         * under which Tool requirement is assigned.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parent;
        /**
         * Specifies the Tool Requirement of type Mfg0BVRToolRequirement for which candidate
         * tools are to be fetched.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  trObject;
        /**
         * Specifies the source from where the tools are to be fetched.  The possible values
         * are Library & WorkArea and All. Which specify that the tools are to be fetched respectively
         * from library and workarea. Only library and only workarea.
         */
        std::string toolSource;
    };

    /**
     * Specifies the Tool Requirements that are assigned to an Operation or Process.
     */
    struct ToolRequirementResponse
    {
        /**
         * Specifies the Tool Requirements.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_02::Model::ToolRequirementResult > toolRequirements;
        /**
         * Service data will hold warnings and errors. if any.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Specifies the Tool Requirements that are assigned to an Operation or Process.
     */
    struct ToolRequirementResult
    {
        /**
         * Specifies the Operation of type Mfg0BvrOperation or Process of type Mfg0BvrProcess
         * to which Tool requirement is assigned.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parentObject;
        /**
         * Specifies the Tool Requirement of type Mfg0BVRToolRequirement that are assigned to
         * the Operation or Process.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > toolRequirements;
    };




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


protected:
    virtual ~Model() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

