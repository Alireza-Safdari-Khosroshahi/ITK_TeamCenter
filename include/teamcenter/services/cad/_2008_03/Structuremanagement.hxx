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

#ifndef TEAMCENTER_SERVICES_CAD__2008_03_STRUCTUREMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CAD__2008_03_STRUCTUREMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/cad/Cad_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Cad
        {
            namespace _2008_03
            {
                class Structuremanagement;

class TCSOACADSTRONGMNGD_API Structuremanagement
{
public:

    struct AskChildPathBOMLinesInfo;
    struct AskChildPathBOMLinesPath;
    struct AskChildPathBOMLinesResponse;

    /**
     * AskChildPathBOMLineMap
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > AskChildPathBOMLineMap;

    /**
     * A set of input information for a single product structure including the associated
     * child paths to be evaluated by this operation.
     */
    struct AskChildPathBOMLinesInfo
    {
        /**
         * Identifier used to relate partial errors associated with an instance of this information.
         */
        std::string clientId;
        /**
         * The BOM line parent of the first PS Occurrence Thread UID specified by each of the
         * paths.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  parentBomLine;
        /**
         * Indicates that the child paths are specified by "stable" rather than "real" PS Occurrence
         * Thread UIDs.
         */
        bool useAsStable;
        /**
         * One or more PS Occurrence Thread child paths.
         */
        std::vector< Teamcenter::Services::Cad::_2008_03::Structuremanagement::AskChildPathBOMLinesPath > childPaths;
    };

    /**
     * One or more PS Occurrence Threads defining an input child path within a given product
     * structure from a parent to a child.
     */
    struct AskChildPathBOMLinesPath
    {
        /**
         * Identifier used to relate partial errors associated with an instance of this information.
         */
        std::string clientId;
        /**
         * An ordered list of PS Occurrence Thread UIDs that specify a path from a parent Teamcenter::BOMLineImpl
         * through the product structure to the child.
         */
        std::vector< std::string > childPath;
    };

    /**
     * Defines the response from the askPSOccThreadChildBOMLines operation.
     */
    struct AskChildPathBOMLinesResponse
    {
        /**
         * A map of input PS Occurrence Thread UIDs to BOMLines.
         */
        AskChildPathBOMLineMap output;
        /**
         * The SOA framework object containing plain objects, and error information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Given one or more sets of product structure information containing child paths specified
     * by PS Occurrence Thread chains, this method returns the corresponding BOM Lines.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param input
     *        Specifies sets of product structure information each containing parent BOM line,
     *        based on a BOM Window opened by the client, and one or more child paths specified
     *        as an ordered set of PS Occurrence Thread UIDs. BOM configuration is managed by the
     *        BOM Window. Input client IDs must be unique for all input.
     *
     * @return
     *         map of input PS Occurrence Thread UIDs, specified as child paths in the input, to
     *         the corresponding BOMLines. BOMLine objects are returned as Service Data plain objects
     *         to inflate properties. Partial failures can result for each child path or product
     *         structure being evaluated and can be associated with the input by the input client
     *         ID.
     *
     */
    virtual Teamcenter::Services::Cad::_2008_03::Structuremanagement::AskChildPathBOMLinesResponse askChildPathBOMLines ( const std::vector< Teamcenter::Services::Cad::_2008_03::Structuremanagement::AskChildPathBOMLinesInfo >& input ) = 0;


protected:
    virtual ~Structuremanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/cad/Cad_undef.h>
#endif

