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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2010_09_STRUCTURESEARCH_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2010_09_STRUCTURESEARCH_HXX

#include <teamcenter/services/structuremanagement/_2008_05/Structuresearch.hxx>
#include <teamcenter/services/structuremanagement/_2010_04/Structuresearch.hxx>
#include <teamcenter/soa/client/model/Item.hxx>


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
            namespace _2010_09
            {
                class Structuresearch;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Structuresearch
{
public:

    struct BoundingBoxInfo;
    struct BoundingBoxInfoResponse;
    struct SearchExpressionSet;

    /**
     * Item and corresponding bbox coordinates are mapped
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item> , BoundingBoxInfo > BoundingBoxs;

    /**
     * Contains the six Coordinates of the Bbox
     */
    struct BoundingBoxInfo
    {
        /**
         * Xmin value
         */
        double xmin;
        /**
         * Ymin value
         */
        double ymin;
        /**
         * Zmin value
         */
        double zmin;
        /**
         * Xmax value
         */
        double xmax;
        /**
         * Ymax value
         */
        double ymax;
        /**
         * Zmax value
         */
        double zmax;
    };

    /**
     * List of BoundingBoxInfo
     */
    struct BoundingBoxInfoResponse
    {
        /**
         * Map of Item and  BoundingBoxInfo
         */
        BoundingBoxs boundingBoxes;
        /**
         * service Data object
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
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
        /**
         * Specifies whether to apply VOO filter prior to returning results from the server
         */
        bool executeVOOFilter;
        /**
         * Specifies whether the search should include results from the remote site in response
         */
        bool executeRemoteSearch;
        /**
         * This is optional parameter that will be used to provide the remote site id to search
         * from. By default the search will use the site id that is configured by admin in teamcenter
         */
        std::string remoteSiteID;
    };




    /**
     * This operation will return an object of structure type BoundingBoxInfoResponse which
     * will contain the map of items passed in as input with the six co-ordinates that represent
     * the bounding box for that item.
     *
     * @param items
     *        A list of items whose bounding box information is expected in the response
     *
     * @return
     *         returns the list of BoundingBoxInfo for the given list of items
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2010_09::Structuresearch::BoundingBoxInfoResponse getAssemblyBoundingBox ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  >& items ) = 0;

    /**
     * This operation will return true if the spatial data is available for the assembly
     * provided in input top line item. False otherwise.
     *
     * @param topItem
     *        Specifies the top item of the assembly for which user wants to find out whether the
     *        spatial data exists or not
     *
     * @return
     *         return true or false
     *
     */
    virtual bool isSpatialDataAvailable ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  topItem ) = 0;

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
     */
    virtual Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::StructureSearchResultResponse startSearch ( const Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch::SearchScope&  scope,
        const Teamcenter::Services::Structuremanagement::_2010_09::Structuresearch::SearchExpressionSet&  searchExpression ) = 0;


protected:
    virtual ~Structuresearch() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

