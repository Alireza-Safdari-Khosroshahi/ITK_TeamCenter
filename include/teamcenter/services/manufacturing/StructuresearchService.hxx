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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING_STRUCTURESEARCHSERVICE_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING_STRUCTURESEARCHSERVICE_HXX

#include <teamcenter/services/manufacturing/_2009_10/Structuresearch.hxx>
#include <teamcenter/services/manufacturing/_2013_05/Structuresearch.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/manufacturing/Manufacturing_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Manufacturing
        {
            class StructuresearchService;

/**
 * Contains StructureSearch Services
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoamanufacturingstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoamanufacturingtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAMANUFACTURINGSTRONGMNGD_API StructuresearchService
    : public Teamcenter::Services::Manufacturing::_2009_10::Structuresearch,
             public Teamcenter::Services::Manufacturing::_2013_05::Structuresearch
{
public:
    static StructuresearchService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Process one additional step of the search identified by the cursor.
     *
     * @param searchCursor
     *        searchCursor
     *
     * @return
     *         - result of next search step
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Structuresearch::StructureSearchResultResponse nextSearch ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  searchCursor ) = 0;

    /**
     * Start searching a structure for a given search expression within the scope specified.
     * search can also be narrowed to a specific object type, item name, and logical designator
     *
     * @param scope
     *        scope lines within which to search
     *
     * @param searchExpression
     *        generic search expression
     *
     * @param mfgSearchCriteria
     *        The MFG addition search criteria
     *
     * @return
     *         - result of search startup
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Structuresearch::StructureSearchResultResponse startSearch ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& scope,
        const Teamcenter::Services::Manufacturing::_2009_10::Structuresearch::SearchExpressionSet&  searchExpression,
        const Teamcenter::Services::Manufacturing::_2009_10::Structuresearch::MFGSearchCriteria&  mfgSearchCriteria ) = 0;

    /**
     * Stop and close down a search identified by a cursor. Throws SearchAlreadyStoppedException
     * if the search has already been stopped.
     *
     * @param searchCursor
     *        the search identifier
     *
     * @return
     *         StructureSearchResultResponse
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Structuresearch::StructureSearchResultResponse stopSearch ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  searchCursor ) = 0;

    /**
     * This operation finds all study objects that reference a given process/operation business
     * object.
     *
     * @param inputNodes
     *        A list of business objects for which referencing studies should be searced (objects
     *        of type Mfg0BvrProcess or Mfg0BvrOperation).
     *
     * @return
     *         The Mfg0BvrStudy objects that refer to the input business objects.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2013_05::Structuresearch::FindStudiesResponse findStudies ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& inputNodes ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("StructuresearchService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

