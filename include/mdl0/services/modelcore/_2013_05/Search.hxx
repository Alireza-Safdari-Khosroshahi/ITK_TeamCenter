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

#ifndef MDL0_SERVICES_MODELCORE__2013_05_SEARCH_HXX
#define MDL0_SERVICES_MODELCORE__2013_05_SEARCH_HXX

#include <mdl0/services/modelcore/_2011_06/Search.hxx>
#include <teamcenter/soa/client/model/Mdl0SearchDef.hxx>
#include <teamcenter/soa/client/model/TransferOptionSet.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <mdl0/services/modelcore/ModelCore_exports.h>

namespace Mdl0
{
    namespace Services
    {
        namespace Modelcore
        {
            namespace _2013_05
            {
                class Search;

class MDL0SOAMODELCORESTRONGMNGD_API Search
{
public:

    struct OptionSetExpression;
    struct OptionSetExpressionInput;
    struct SearchExpressionInput;

    /**
     * Map containing &lt;b&gt;TransferOptionSet&lt;/b&gt; option names and values
     */
    typedef std::map< std::string, std::string > OptionSetMap;

    /**
     * Elemental Transfer Option Set Expression
     */
    struct OptionSetExpression
    {
        /**
         * Reference to the &lt;b&gt;TransferOptionSet&lt;/b&gt;
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferOptionSet>  optionSet;
        /**
         * Map containing names and values of options to be used with the &lt;b&gt;TransferOptionSet&lt;/b&gt;
         */
        OptionSetMap optionSetMap;
        /**
         * Reference to the <b>Mdl0SearchDef</b> object that represents the rest of the search
         * expression.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0SearchDef>  searchDef;
    };

    /**
     * Option Set Expression Input - Request Structure
     */
    struct OptionSetExpressionInput
    {
        /**
         * Search expression representing the &lt;b&gt;TransferOptionSet&lt;/b&gt;
         */
        Mdl0::Services::Modelcore::_2013_05::Search::OptionSetExpression optionSetExpression;
        /**
         * A unique string sent by the calling function, so that the output Search Expression
         * object could be mapped back to the input.
         */
        std::string clientid;
    };

    /**
     * Input Data Structure to create the Group of Elemental Search Expressions
     */
    struct SearchExpressionInput
    {
        /**
         * Input for creating Proximity Search Expressions. Contains reference to a set of <code>ModelElements</code>
         * (that are targets) and the proximity distance.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::ProximitySearchExpressionInput > proximitySearchExpressions;
        /**
         * input for creating box zone search expressions. Contains the Min and Max coordinated
         * of a test Box definition.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::BoxZoneExpressionInput > boxZoneExpressions;
        /**
         * input for creating plane zone search expressions. Contains a point in the plane and
         * the normal vector definition.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::PlaneZoneExpressionInput > planeZoneExpressions;
        /**
         * input for creating saved query search expressions. Contains reference to a stored
         * saved query object and a coordinated list of entries and values to be used in the
         * saved query. Some queries may contain empty list for entries and values (depends
         * on the definition of the Saved Query). Wildcards are accepted for values in the Saved
         * Query.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::SavedQueryExpressionInput > savedQueryExpressions;
        /**
         * Closure Query Expression  that traverses results using a closure rule  Not implemented
         * in Tc9.1.0 or Tc10.1.0.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::ClosureQueryExpressionInput > closureQueryExpression;
        /**
         * Option Set Expression that defines the Transfer Option Set and option values that
         * are used traverse the closure defined for the Transfer Option Oet
         */
        std::vector< Mdl0::Services::Modelcore::_2013_05::Search::OptionSetExpressionInput > optionSetExpressions;
        /**
         * References to elements to be included into the search results. The server creates
         * a Search Expression for this input as well, so that it could be combined with other
         * search expressions in a search recipe.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::ModelElementInput > includeElements;
        /**
         * Reference to elements that should be explicitly excluded in the search results. Again
         * a search expression is returned for the exclude elements so that it could be combined
         * with other search expressions in a search recipe.
         */
        std::vector< Mdl0::Services::Modelcore::_2011_06::Search::ModelElementInput > excludeElements;
    };




    /**
     * This operation creates the elemental search expressions that could be combined using
     * logical operators to build up a complex search recipe in CPD application. The createSearchExpressions
     * operation could be used to create multiple search expressions at the same time. The
     * following types of expressions could be created by this operation
     * <br>
     * <ul>
     * <li type="disc">Bounding Box Expression (<b>Mdl0SearchBoxZone</b>)
     * </li>
     * <li type="disc">Plane Zone Expression (<b>Mdl0SearchPlaneZone</b>)
     * </li>
     * <li type="disc">Proximity Expression (<b>Mdl0SearchProximity</b>)
     * </li>
     * <li type="disc">Saved Query Expression (<b>Mdl0SearchSavedQuery</b>)
     * </li>
     * <li type="disc">Include Content Expression (<b>Mdl0SearchSlctContent</b>)
     * </li>
     * <li type="disc">Exclude Content Expression (<b>Mdl0SearchGroup</b>)
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The createSearchExpressions is a required operation before an executeSearch or setRecipes
     * call is made. This operation creates the runtime Search Definition objects based
     * on the input search expression data structures. The intent of this operation is to
     * create all the individual elemental search expressions so that they could be combined
     * using logical operators (AND/OR/NOT) to create a complex search recipe.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createSearchExpressions
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Model Elements - Defines the basic data management operations(revise,saveAs,deepcopy)
     * for Application Model Elements,defines operations to create search expressions and
     * execute search on Model Elements in an Application Model.
     *
     * @param searchExpInput
     *        Search Expression Input Structure
     *
     * @return
     *         SearchExpressionResponse data structure that returns the Search Expression objects
     *         created for the given Search Expression Input data structures.
     *
     */
    virtual Mdl0::Services::Modelcore::_2011_06::Search::SearchExpressionResponse createSearchExpressions ( const Mdl0::Services::Modelcore::_2013_05::Search::SearchExpressionInput&  searchExpInput ) = 0;


protected:
    virtual ~Search() {}
};
            }
        }
    }
}

#include <mdl0/services/modelcore/ModelCore_undef.h>
#endif

