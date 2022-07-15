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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2010_04_STRUCTURESEARCH_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2010_04_STRUCTURESEARCH_HXX

#include <teamcenter/services/structuremanagement/_2008_05/Structuresearch.hxx>


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
            namespace _2010_04
            {
                class Structuresearch;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Structuresearch
{
public:

    struct PlaneZoneExpression;
    struct SearchExpressionSet;

    /**
     * PlaneZoneOperator enumerated type defines the operator to use as part of a plane-zone
     * search expression
     */
    enum PlaneZoneOperator{ PlaneZone_above,
                 PlaneZone_below,
                 PlaneZone_intersects,
                 PlaneZone_aboveOrIntersects,
                 PlaneZone_belowOrIntersects
                 };

    /**
     * PlaneZoneExpression represents a 3D plane to search against. It may define a search
     * for all parts that intersect with the plane, or a search for all parts on one side
     * of the plane.
     */
    struct PlaneZoneExpression
    {
        /**
         * planeZone
         */
        Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::PlaneZone planeZone;
        /**
         * Operator to use forExpression
         */
        PlaneZoneOperator planeZoneOperator;
    };

    /**
     * SearchExpression data structure specifies the full set of search expressions that
     * are to be used to perform a single structure search. Each one of the expressions
     * provided are combined together using a logical 'AND' between them.
     */
    struct SearchExpressionSet
    {
        /**
         * A collection of item and item revision attribute search expressions
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::AttributeExpression > itemAndRevisionAttributeExpressions;
        /**
         * A collection of Occurrence Note attribute search expressions
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::OccurrenceNoteExpression > occurrenceNoteExpressions;
        /**
         * A collection of Form attribute search expressions
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::FormAttributeExpression > formAttributeExpressions;
        /**
         * A collection of spatial proximity search expressions
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::ProximityExpression > proximitySearchExpressions;
        /**
         * A collection of spatial box zone expressions
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::BoxZoneExpression > boxZoneExpressions;
        /**
         * A collection of spatial plane zone search expressions
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2010_04::Structuresearch::PlaneZoneExpression > planeZoneExpressions;
        /**
         * A collection of saved query search expressions
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::SavedQueryExpression > savedQueryExpressions;
        /**
         * A collection of inclass attribute search expressions
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::InClassExpression > inClassQueryExpressions;
        /**
         * A collection of spatial size search expressions
         */
        Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::SearchBySizeExpression sizeSearchExpression;
        /**
         * Specifies whether to perform trueshape refinement on the spatial search or not
         */
        bool doTrushapeRefinement;
        /**
         * Specifies whether the search result should return only the sub-set of scopeBomLines&#x0A;given
         * as input as part of the SearchScope
         */
        bool returnScopedSubTreesHit;
    };




    /**
     * Start searching a structure for a given search expression within the scope specified.
     *
     * @param scope
     *        - scope within which to search
     *
     * @param searchExpression
     *        searchExpression  data structure specifies the full set of search expressions that
     *        are to be used to perform this structure search
     *
     * @return
     *         - result of search startup
     *
     *
     * @exception ServiceException
     *           
     * @deprecated
     *         As of Teamcenter 8.3, use the startSearch operation from the _2010_05 namespace.
     *         The new operation has an updated the SearchExpressionSet with one more boolean variable
     *         for passing the VOO filter requirement.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.3, use the startSearch operation from the _2010_05 namespace. The new operation has an updated the SearchExpressionSet with one more boolean variable for passing the VOO filter requirement."))
#endif
    virtual Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::StructureSearchResultResponse startSearch ( const Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::SearchScope&  scope,
        const Teamcenter::Services::Structuremanagement::_2010_04::Structuresearch::SearchExpressionSet&  searchExpression ) = 0;


protected:
    virtual ~Structuresearch() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

