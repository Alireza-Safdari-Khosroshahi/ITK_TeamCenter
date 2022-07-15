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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT_STRUCTURESEARCHSERVICE_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT_STRUCTURESEARCHSERVICE_HXX

#include <teamcenter/services/structuremanagement/_2008_05/Structuresearch.hxx>
#include <teamcenter/services/structuremanagement/_2010_04/Structuresearch.hxx>
#include <teamcenter/services/structuremanagement/_2010_09/Structuresearch.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/structuremanagement/StructureManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Structuremanagement
        {
            class StructuresearchService;

/**
 * Contains StructureSearch Services
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoastructuremanagementstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoastructuremanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API StructuresearchService
    : public Teamcenter::Services::Structuremanagement::_2008_05::Structuresearch,
             public Teamcenter::Services::Structuremanagement::_2010_04::Structuresearch,
             public Teamcenter::Services::Structuremanagement::_2010_09::Structuresearch
{
public:
    static StructuresearchService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("StructuresearchService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

