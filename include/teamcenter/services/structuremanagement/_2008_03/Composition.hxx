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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2008_03_COMPOSITION_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2008_03_COMPOSITION_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/structuremanagement/StructureManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Structuremanagement
        {
            namespace _2008_03
            {
                class Composition;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Composition
{
public:

    struct AssignChildLineOccTypes;
    struct AssignChildLinesOutput;
    struct AssignChildLinesParameter;
    struct AssignChildLinesResponse;

    /**
     * This structure defines child lines to be assigned with its occurrence type and client
     * id.
     */
    struct AssignChildLineOccTypes
    {
        /**
         * lineToAssign
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  lineToAssign;
        /**
         * occurrence type for new assigned line. it can be empty.
         */
        std::string occType;
    };

    /**
     * Holds the response from assignChildLines
     */
    struct AssignChildLinesOutput
    {
        /**
         * new BOMLines created as a result of assign operation under newParentLine
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > newLines;
        /**
         * a subset new bomlines that do have incoming flows.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > linesWithoutPreds;
    };

    /**
     * This structure provides a set of input values for assignLines operation.
     */
    struct AssignChildLinesParameter
    {
        /**
         * new parent line under which the bomlines need to be assigned
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  newParentLine;
        /**
         * Array of AssignChildLineOccType
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2008_03::Composition::AssignChildLineOccTypes > linesToAssign;
        /**
         * should predecessor relationship be copied over from old parent?
         */
        bool copyPreds;
        /**
         * occurrence type to be used for newly assigned lines.
         */
        bool copyOccTypeFromSource;
    };

    /**
     * Holds the response from assignChildLines
     */
    struct AssignChildLinesResponse
    {
        /**
         * array of AssignChildLinesOutput
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2008_03::Composition::AssignChildLinesOutput > assignOutput;
        /**
         * Exceptions from internal processing returned as PartialErrors
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Assign lines from one or more parent to a new parent line.
     *
     * @param input
     *        BomLines to be assigned from one or more parent  to new parent line
     *
     * @return
     *         including newLines, lines without predecessors and exceptions.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2008_03::Composition::AssignChildLinesResponse assignChildLines ( const std::vector< Teamcenter::Services::Structuremanagement::_2008_03::Composition::AssignChildLinesParameter >& input ) = 0;


protected:
    virtual ~Composition() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

