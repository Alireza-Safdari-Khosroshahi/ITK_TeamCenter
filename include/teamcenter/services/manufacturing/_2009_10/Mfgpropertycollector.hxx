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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2009_10_MFGPROPERTYCOLLECTOR_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2009_10_MFGPROPERTYCOLLECTOR_HXX

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
                class Mfgpropertycollector;

class TCSOAMANUFACTURINGSTRONGMNGD_API Mfgpropertycollector
{
public:

    struct CollectPropertiesInputInfo;
    struct CollectPropertiesOutput;
    struct CollectPropertiesResponse;
    struct MFGNodePropertyValues;
    struct PropertyCollectorOutput;
    struct PropertyCollectorVisitorInfo;
    struct TraversalKeyInfo;
    struct TraversalRuleInfo;

    /**
     * This map holds the property name value pairs
     */
    typedef std::map< std::string, std::vector< std::string > > MFGPropertyNameValueMap;

    /**
     * This is a input structure containing rootNode, set of Traversal Rules and a set of
     * Traversal Visitor info.
     */
    struct CollectPropertiesInputInfo
    {
        /**
         * Client ID
         */
        std::string clientId;
        /**
         * The root node to traverse from.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  rootNode;
        /**
         * The traversal rules to be used while traversing BOP structure.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2009_10::Mfgpropertycollector::TraversalRuleInfo > traversalRuleList;
        /**
         * The collection of type of MfgNodes and properties to collect for the type.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2009_10::Mfgpropertycollector::PropertyCollectorVisitorInfo > propVisitorList;
    };

    /**
     * Structure containing client Id and PropertyCollectoroutput
     */
    struct CollectPropertiesOutput
    {
        /**
         * Client ID
         */
        std::string clientId;
        /**
         * vector of PropertyCollectorOutput
         */
        std::vector< Teamcenter::Services::Manufacturing::_2009_10::Mfgpropertycollector::PropertyCollectorOutput > output;
    };

    /**
     * Response structure containing service data
     */
    struct CollectPropertiesResponse
    {
        /**
         * The collection of MfgNode, property names and theit values.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2009_10::Mfgpropertycollector::CollectPropertiesOutput > outputList;
        /**
         * service data containing partial error data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The structure that holds MFGNode along with property names and their values.
     */
    struct MFGNodePropertyValues
    {
        /**
         * The MFGNode in BOP structure.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  node;
        /**
         * Map of Property Name Value Pair
         */
        MFGPropertyNameValueMap props;
    };

    /**
     * Output structure containing MfgNode, set of Properties that are evaluated for the
     * node and set of property values corresponding to the property names.
     */
    struct PropertyCollectorOutput
    {
        /**
         * Context Type of MfgNode
         */
        std::string contextType;
        /**
         * The vector of MFGNodePropertyValues.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2009_10::Mfgpropertycollector::MFGNodePropertyValues > nodeValueList;
    };

    /**
     * This structure contains list of properties to collect for the corresponding Traversal
     * Rule Key
     */
    struct PropertyCollectorVisitorInfo
    {
        /**
         * The collection of type of MfgNode and its corresponding MfgContext type.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2009_10::Mfgpropertycollector::TraversalKeyInfo > traversalVisitorsKeys;
        /**
         * The list of properties to be evaluated for the type of MfgNode specified in traversalRuleKey.
         */
        std::vector< std::string > propToCollectList;
    };

    /**
     * This is a structure of MFGNode types and MFGContext
     */
    struct TraversalKeyInfo
    {
        /**
         * set of MFGNode types
         */
        std::vector< std::string > types;
        /**
         * context of MFGNodes
         */
        std::string context;
    };

    /**
     * This structure contains TraversalRuleKeys and their corresponding relations properties.
     */
    struct TraversalRuleInfo
    {
        /**
         * The collection of type of MfgNode and its corresponding MfgContext type.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2009_10::Mfgpropertycollector::TraversalKeyInfo > traversalRuleKeys;
        /**
         * The list of properties to be used to traverse for current MfgNode to its sub nodes.
         */
        std::vector< std::string > targets;
    };




    /**
     * This function will call a Mfg function that takes the MfgNode, traversal rules and
     * property names to collect and return a list of property values of input properties
     * for every MfgNode in the BOP structure based on traversal rules.
     *
     * @param input
     *        MfgNode, traversal rules and property names to collect
     *
     * @return
     *         a list of property values of input properties for every MfgNode in the BOP structure
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Mfgpropertycollector::CollectPropertiesResponse collectProperties ( const std::vector< Teamcenter::Services::Manufacturing::_2009_10::Mfgpropertycollector::CollectPropertiesInputInfo >& input ) = 0;


protected:
    virtual ~Mfgpropertycollector() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

