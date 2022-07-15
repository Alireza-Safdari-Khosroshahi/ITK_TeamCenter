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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2010_09_CORE_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2010_09_CORE_HXX

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
                class Core;

class TCSOAMANUFACTURINGSTRONGMNGD_API Core
{
public:

    struct FindNodeInContextInputInfo;
    struct FindNodeInContextResponse;
    struct FoundNodesInfo;
    struct GetAffectedPropertiesArg;
    struct NodeInfo;

    /**
     * Input struct for the find node in context service
     */
    struct FindNodeInContextInputInfo
    {
        /**
         * Client ID
         */
        std::string clientID;
        /**
         * The topline that defines the search scope.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  context;
        /**
         * The nodes to search.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > nodes;
        /**
         * If true all abs occs with the same Id will be search for, if no exact apn is matched.
         */
        bool byIdOnly;
        /**
         * If true then all contexts will be searched otherwise only the current context will
         * be searched if no current context specified at the time then the context of the topline
         * is used.
         */
        bool allContexts;
        /**
         * A more specific scope to searh in.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  inContextLine;
    };

    /**
     * The Response struct.
     */
    struct FindNodeInContextResponse
    {
        /**
         * Infornation retrieves for each input struct that we looked for.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2010_09::Core::FoundNodesInfo > resultInfo;
        /**
         * Service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * A struct that hold all the results on a single search parallel to the one input struct.
     */
    struct FoundNodesInfo
    {
        /**
         * Client ID
         */
        std::string clientID;
        /**
         * In each search we look into a vector of nodes to search.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2010_09::Core::NodeInfo > resultNodes;
    };

    /**
     * This structure provides the input parameters for the getAffectedProperties operation.
     * It describes the property changes applied to a process or operation structure for
     * which the affected runtime properties are inquired.
     */
    struct GetAffectedPropertiesArg
    {
        /**
         * he root node of the process or operation structure that is inspected.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  rootNode;
        /**
         * The list of process or operation nodes that have been changed.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > changedNodes;
        /**
         * The name of the properties that have been changed.
         */
        std::vector< std::string > changedProperties;
    };

    /**
     * The struct that holds the result for each node in the input.
     */
    struct NodeInfo
    {
        /**
         * The found nodes we find.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > foundNodes;
        /**
         * The original input node.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  originalNode;
    };




    /**
     * Finding parallel line in a given window of a given line.
     *
     * @param input
     *        Input struct.
     *
     * @return
     *         The found lines.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2010_09::Core::FindNodeInContextResponse findNodeInContext ( const std::vector< Teamcenter::Services::Manufacturing::_2010_09::Core::FindNodeInContextInputInfo >& input ) = 0;

    /**
     * Returns the runtime properties of dependent nodes which are affected when the duration
     * of one or more nodes has been changed in a process or operation structure.
     *
     * @param arguments
     *        A list of GetAffectedPropertiesChanges structures that describe the changes that
     *        have been made to a process or operation structure.
     *
     * @param requestedProperties
     *        The names of the properties that are to be retrieved. In the first version only the
     *        properties that are processed by the Gantt application are accepted (Mfg0calc_duration,
     *        Mfg0calc_start_time, Mfg0calc_dur_start_time).
     *
     * @return
     *         A ServiceData structure that contains the computed property values in the DataObject
     *         member. The structure also informs about errors that occurred during the course of
     *         the operation.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData getAffectedProperties ( const std::vector< Teamcenter::Services::Manufacturing::_2010_09::Core::GetAffectedPropertiesArg >& arguments,
        const std::vector< std::string >& requestedProperties ) = 0;


protected:
    virtual ~Core() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

