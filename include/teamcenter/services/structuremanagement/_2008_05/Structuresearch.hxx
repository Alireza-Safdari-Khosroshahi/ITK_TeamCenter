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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2008_05_STRUCTURESEARCH_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2008_05_STRUCTURESEARCH_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/BOMWindow.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


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
            namespace _2008_05
            {
                class Structuresearch;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Structuresearch
{
public:

    struct AttributeValues;
    struct AttributeExpression;
    struct BoxZoneExpression;
    struct FormAttributeExpression;
    struct InClassExpression;
    struct OccurrenceNoteExpression;
    struct PlaneZone;
    struct PlaneZoneExpression;
    struct ProximityExpression;
    struct SavedQueryExpression;
    struct SearchBox;
    struct SearchBySizeExpression;
    struct SearchExpressionSet;
    struct SearchScope;
    struct StructureSearchResultResponse;

    /**
     * AttributeType enumerated type defines the type of data passed in an attribute search
     * expression
     */
    enum AttributeType{ BooleanType,
                 IntegerType,
                 DoubleType,
                 StringType,
                 DateType,
                 TagType
                 };

    /**
     * BoxOperator defines the operator to apply as part of a box-zone search expression.
     */
    enum BoxOperator{ Inside,
                 Outside,
                 Intersects,
                 InsideOrIntersects,
                 OutsideOrIntersects
                 };

    /**
     * PlaneZoneOperator enumerated type defines the operator to use as part of a plane-zone
     * search expression
     */
    enum PlaneZoneOperator{ Plane_above,
                 Plane_below,
                 Plane_intersects,
                 Plane_aboveOrIntersects,
                 Plane_belowOrIntersects
                 };

    /**
     * QueryOperator  enumerated type defines the operator to be used for comparison in
     * a attribute search expression
     */
    enum QueryOperator{ Equal,
                 GreaterThan,
                 GreaterThanOrEqual,
                 LessThan,
                 LessThanOrEqual,
                 NotEqual,
                 IsNull,
                 IsNotNull,
                 Like,
                 NotLike
                 };

    /**
     * AttributeValues data structure specifies data values to be bound to the various search
     * expressions for execution of the search. It encapsulates the values to be specified
     * for each of the data types that can occur in any of the attribute search expressions.
     */
    struct AttributeValues
    {
        /**
         * boolean values that any of the accompanying set of search expressions may use
         */
        std::vector< bool > boolValues;
        /**
         * integer values that any of the accompanying set of search expressions may use
         */
        std::vector< int > intValues;
        /**
         * double values that any of the accompanying set of search expressions may use
         */
        std::vector< double > doubleValues;
        /**
         * string values that any of the accompanying set of search expressions may use
         */
        std::vector< std::string > stringValues;
        /**
         * date values that any of the accompanying set of search expressions may use
         */
        Teamcenter::Soa::Common::DateTime dateValues;
        /**
         * tag values that any of the accompanying set of search expressions may use
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > tagValues;
    };

    /**
     * AttributeExpression encapsulates information to build a query on the attribute of
     * an Item or ItemRevision or their sub-classes in the structure search scope. * A set
     * of these attribute expressions is contained inside a SearchExpressionInfo object.
     * Search on multiple values specified within one AttributeExpression are combined with
     * a logical 'OR' operation.
     */
    struct AttributeExpression
    {
        /**
         * Item or ItemRevision or their sub-classes
         */
        std::string className;
        /**
         * The attribute of the above 'className' to be searched on
         */
        std::string attributeName;
        /**
         * The type of the attribute to be searched on
         */
        AttributeType attributeType;
        /**
         * operator to use for search value comparison
         */
        QueryOperator queryOperator;
        /**
         * values
         */
        Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::AttributeValues values;
    };

    /**
     * BoxZoneExpression specifies one set of Box zone criteria. The search results from
     * each SearchBox are combined together using an 'OR' operation. The spatial search
     * returns a match with the search expression if a object either lies inside or intersects
     * the search boxes
     */
    struct BoxZoneExpression
    {
        /**
         * Boxes around which to search
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::SearchBox > searchBoxes;
        /**
         * Operator to use for expression
         */
        BoxOperator boxOperator;
    };

    /**
     * FormAttributeExpression contains information to search on a single Form Attribute
     * within a containing SearchExpressionInfo object. The search on the multiple values
     * specified within one FormAttributeExpression are combined with a logical 'OR' operation.
     */
    struct FormAttributeExpression
    {
        /**
         * Item or ItemRevision form
         */
        bool isItemForm;
        /**
         * The Form relation type
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  relationType;
        /**
         * Form type to be searched
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  formType;
        /**
         * The attribute of the above Form type to be searched
         */
        std::string attributeName;
        /**
         * The type of the attribute to be searched on
         */
        AttributeType attributeType;
        /**
         * operator to use for search value comparison
         */
        QueryOperator queryOperator;
        /**
         * The values to test for
         */
        Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::AttributeValues values;
    };

    /**
     * InClassExpression
     */
    struct InClassExpression
    {
        /**
         * inClassClassNames
         */
        std::vector< std::string > inClassClassNames;
        /**
         * inClassAttributeIDs
         */
        std::vector< int > inClassAttributeIDs;
        /**
         * inClassAttributeValues
         */
        std::vector< std::string > inClassAttributeValues;
    };

    /**
     * OccurrenceNoteExpression contains information to search on a single occurrence note
     * type within a containing SearchExpressionInfo object. The search on the multiple
     * values specified within one OccurrenceNoteExpression are combined with a logical
     * 'OR' operation.
     */
    struct OccurrenceNoteExpression
    {
        /**
         * Occurrence note type to search
         */
        std::string noteType;
        /**
         * operator to use for search value comparison
         */
        QueryOperator queryOperator;
        /**
         * The list of values to search for
         */
        std::vector< std::string > values;
    };

    /**
     * Planezone defines a single plane to search against.
     */
    struct PlaneZone
    {
        /**
         * X value of the direction unit vector of the plane
         */
        double xValue;
        /**
         * Y value of the direction unit vector of the plane
         */
        double yValue;
        /**
         * Z value of the direction unit vector of the plane
         */
        double zValue;
        /**
         * Plane displacement in metres along the direction vector specified above
         */
        double displacement;
    };

    /**
     * PlaneZoneExpression represents a 3D plane to search against. It may define a search
     * for all parts that intersect with the plane, or a search for all parts on one side
     * of the plane.
     */
    struct PlaneZoneExpression
    {
        /**
         * planzeZone
         */
        Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::PlaneZone planzeZone;
        /**
         * Operator to use for expression
         */
        PlaneZoneOperator planeZoneOperator;
    };

    /**
     * ProximityExpression specifies one set of proximity criteria. The search results from
     * each bomLine are combined together using an 'OR' operation.
     */
    struct ProximityExpression
    {
        /**
         * BOM lines around which to search
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > bomLines;
        /**
         * Proximity distance in metres from the outer surface of the BomLine geometry
         */
        double distance;
        /**
         * includeChildBomLines
         */
        bool includeChildBomLines;
    };

    /**
     * SavedQueryExpression defines a search expression encapsulated as a Teamcenter saved-query
     * that returns an Item, ItemRevision or any of their sub-types. The saved query may
     * be a pre-defined out of the box saved query or one created using the Teamcenter QueryBuilder
     * application
     */
    struct SavedQueryExpression
    {
        /**
         * Tag of an existing saved query
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  savedQuery;
        /**
         * Attribute entries that are to be searched for
         */
        std::vector< std::string > entries;
        /**
         * Values of the above entries to be searched for
         */
        std::vector< std::string > values;
    };

    /**
     * SearchBox defines a single box zone to search in. It contains the definition of an
     * axis-aligned box and an accompanying transform to describe it orientation.
     */
    struct SearchBox
    {
        /**
         * Plane defining the minimum extent along the x-axis
         */
        double xmin;
        /**
         * Plane defining the minimum extent along the y-axis
         */
        double ymin;
        /**
         * Plane defining the minimum extent along the z-axis
         */
        double zmin;
        /**
         * Plane defining the maximum extent along the x-axis
         */
        double xmax;
        /**
         * Plane defining the maximum extent along the y-axis
         */
        double ymax;
        /**
         * Plane defining the maximum extent along the z-axis
         */
        double zmax;
        /**
         * Transform defining the orientation of the box ( empty vector denotes identity transform
         * )
         */
        std::vector< double > transform;
    };

    /**
     * SearchBySizeExpression defines a search for parts with bounding boxes that are larger
     * than or smaller than a specified size
     */
    struct SearchBySizeExpression
    {
        /**
         * Search for larger than if this is set to true, smaller than if set to false
         */
        bool largerThan;
        /**
         * Length of the largest bounding box diagonal in metres
         */
        double diagonalLength;
    };

    /**
     * SearchExpression data structure specifies the full set of search expressions that
     * are to be used to perform a single structure search. Each one of the expressions
     * provided are combined together using a logical 'AND' between them.
     */
    struct SearchExpressionSet
    {
        /**
         * itemAndRevisionAttributeExpressions
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
        std::vector< Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::PlaneZoneExpression > planeZoneExpressions;
        /**
         * A collection of saved query search expressions
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::SavedQueryExpression > savedQueryExpressions;
        /**
         * inClassQueryExpressions
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::InClassExpression > inClassQueryExpressions;
        /**
         * sizeSearchExpression
         */
        Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::SearchBySizeExpression sizeSearchExpression;
        /**
         * Specifies whether to perform trueshape refinement on the spatial search or not
         */
        bool doTrushapeRefinement;
        /**
         * Specifies whether the search result should return only the sub-set of scopeBomLines
         * given as input as part of the SearchScope
         */
        bool returnScopedSubTreesHit;
    };

    /**
     * The SearchScope specifies the scope of a search
     */
    struct SearchScope
    {
        /**
         * BOMWindowImpl specifying a structure context within which to search
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  window;
        /**
         * scopeBomLines
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > scopeBomLines;
        /**
         * specifies whether to include sub-structure under scopeBOMLines as part of the search
         * scope
         */
        std::vector< std::string > ignoreOccurrenceTypes;
    };

    /**
     * StructureSearchResultResponse is the result set received from a single step in a
     * structure search.
     */
    struct StructureSearchResultResponse
    {
        /**
         * serviceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * A batch of BomLines that satisfy the search criteria for this search
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > bomLines;
        /**
         * The number of lines in the structure that have been processed so far
         */
        int linesDone;
        /**
         * An estimate of the number of lines yet to be processed
         */
        int estimatedLinesLeft;
        /**
         * percentComplete
         */
        double percentComplete;
        /**
         * Search cursor object that holds the current state of the search in the BOM session
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  searchCursor;
        /**
         * A boolean value which when 'true' specifies the search is finished
         */
        bool finished;
    };




    /**
     * Process one additional step of the search identified by the cursor.
     *
     * @param searchCursor
     *        - search cursor
     *
     * @return
     *         - result of next search step
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::StructureSearchResultResponse nextSearch ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  searchCursor ) = 0;

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
     *         As of Teamcenter 8.2, use the startSearch opertaion from the _2010_04 namespace.
     *         The new operation has an updated the SearchExpressionSet with correct PlaneZoneExpression
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.2, use the startSearch opertaion from the _2010_04 namespace. The new operation has an updated the SearchExpressionSet with correct PlaneZoneExpression"))
#endif
    virtual Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::StructureSearchResultResponse startSearch ( const Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::SearchScope&  scope,
        const Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::SearchExpressionSet&  searchExpression ) = 0;

    /**
     * Stop and close down a search identified by a cursor. Throws SearchAlreadyStoppedException
     * if the search has already been stopped.
     *
     * @param searchCursor
     *        searchCursor object holds the current state of the search. It is used as a handle
     *        to identify this search when executing the next step of the search or stopping the
     *        search
     *
     * @return
     *         StructureSearchResultResponse
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::StructureSearchResultResponse stopSearch ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  searchCursor ) = 0;


protected:
    virtual ~Structuresearch() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

