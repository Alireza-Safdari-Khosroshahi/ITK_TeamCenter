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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2013_05_CORE_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2013_05_CORE_HXX

#include <teamcenter/services/manufacturing/_2010_09/Core.hxx>
#include <teamcenter/soa/client/model/RuntimeBusinessObject.hxx>
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
            namespace _2013_05
            {
                class Core;

class TCSOAMANUFACTURINGSTRONGMNGD_API Core
{
public:

    struct FindNodeInContextInputInfo;
    struct MatchObjectsAgainstVariantRulesArg;
    struct MatchObjectsAgainstVariantRulesResponse;
    struct MatchObjectsAgainstVariantRulesResult;

    /**
     * A map that collects for a set of runtime objects a list of variant rules or, alternatively,
     * product variants. This type maps a <code>RuntimeBusinessObject</code> to a list of
     * <code>BusinessObject</code>s.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RuntimeBusinessObject> , std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > VariantRuleMap;

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
        /**
         * A list of relation types, currently only FND_TraceLink relation is supported.
         */
        std::vector< std::string > relationTypes;
        /**
         * The relation direction to search. The value includes 1(primary), 2(secondary) and
         * 0(primary and secondary). It is only valid if the relation types are given.
         */
        int relationDirection;
        /**
         * The depth to search, -1 to search all levels and any other positive integer value
         * to search up to that level. It is only valid if the relation types are given.
         */
        int relationDepth;
    };

    /**
     * This structure provides input parameters for the <i>matchObjectsAgainstVariantRules</i>
     * operation.
     */
    struct MatchObjectsAgainstVariantRulesArg
    {
        /**
         * The objects whose variant definition is to be checked against the set of variant
         * rules or product variants. Currently only BOMLines are accepted.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RuntimeBusinessObject>  > objects;
        /**
         * The variant rules or product variants which are to be applied consecutively to each
         * object. The objects must be of type <code>VariantRule</code> or <code>Mfg0BvrProductVariant</code>,
         * respectively.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > variantRules;
    };

    /**
     * The response structure for the <i>matchObjectsAgainstVariantRules</i> operation.
     */
    struct MatchObjectsAgainstVariantRulesResponse
    {
        /**
         * The ServiceData object for this request.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * A list of result structures; each entry corresponds to an entry in the <i>MatchObjectsAgainstVariantRulesArg</i>
         * vector passed to the <i>matchObjectsAgainstVariantRules</i> operation.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2013_05::Core::MatchObjectsAgainstVariantRulesResult > results;
    };

    /**
     * A set of data collected by the <i>matchObjectsAgainstVariantRules</i> operation for
     * a specific <i>MatchObjectsAgainstVariantRulesArg</i> structure.
     */
    struct MatchObjectsAgainstVariantRulesResult
    {
        /**
         * A map that holds for each of the runtime objects supplied in the <i>MatchObjectsAgainstVariantRulesArg</i>
         * structure the matching variant rules or product variants.
         */
        VariantRuleMap matrix;
        /**
         * A list of localized warning messages that describe inconsistencies in the configuration
         * of the involved windows, if the variant configuration of a window does not satisfy
         * the configuration of a supplied variant rule or product variant. The warnings are
         * of the form "The window configuration for structure "&lt;top line title&gt;"" is
         * missing the following variant rule/product variant(s): &lt;rule-name&gt;, ...".
         */
        std::vector< std::string > warnings;
    };




    /**
     * Getting the related objects of the selected object from the target contexts according
     * to the input information.
     *
     * @param input
     *        Input struct
     *
     * @return
     *         The related objects of the input nodes are added to the response.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2010_09::Core::FindNodeInContextResponse findNodeInContext ( const std::vector< Teamcenter::Services::Manufacturing::_2013_05::Core::FindNodeInContextInputInfo >& input ) = 0;

    /**
     * This operation takes a list of pairs of runtime object and variant rule lists and
     * determines for each object/variant rule combination of each pair whether the object
     * is configured-in for the specified variant rule. Thereby it takes all aspects of
     * an object into account that determine the visibility of the object, such as the variant
     * conditions of the object itself and of all its parent objects as well as the conditions
     * of any assigned object and that of its respective parent objects. The results will
     * depend on the configuration state for IC, revision rule, effectivity etc of the implied
     * windows, including reference windows.
     * <br>
     * If a variant rule supplied in the arguments list is not matched by the variant configuration
     * of any involved window a warning message will be added to the response structure,
     * which indicates that the visibility check regarding the specific variant rule cannot
     * be reliably performed because the configuration of the window contradicts the variant
     * rule.
     * <br>
     * This operation currently does not support modular variants. Only saved variant rules
     * (business object <b>VariantRule</b>) for the classic variant model are accepted or
     * alternatively,  product variants (type <b>Mfg0BvrProductVariant</b>) which are linked
     * to <b>VariantRule</b> objects.
     * <br>
     *
     * @param args
     *        A list of structures, where each entry describes a list of runtime objects and a
     *        list of variant rules or product variants that are matched against each other.
     *
     * @return
     *         A response structure which holds for each runtime object the list of matching variant
     *         rules and/or product variants. The following partial errors are returned in case
     *         invalid parameters are passed to the service:
     *         <br>
     *         300052: If an invalid object is passed to the operation.
     *         <br>
     *         300054: If an object of a wrong type is passed to the operation.
     *         <br>
     *         300062: If there is no variant rule associated with a product variant.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2013_05::Core::MatchObjectsAgainstVariantRulesResponse matchObjectsAgainstVariantRules ( const std::vector< Teamcenter::Services::Manufacturing::_2013_05::Core::MatchObjectsAgainstVariantRulesArg >& args ) = 0;


protected:
    virtual ~Core() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

