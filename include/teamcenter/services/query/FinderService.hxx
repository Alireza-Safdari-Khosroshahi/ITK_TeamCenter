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

#ifndef TEAMCENTER_SERVICES_QUERY_FINDERSERVICE_HXX
#define TEAMCENTER_SERVICES_QUERY_FINDERSERVICE_HXX

#include <teamcenter/services/query/_2007_06/Finder.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/query/Query_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Query
        {
            class FinderService;

/**
 * The Finder service provides operations to find objects by given type name, attribute
 * names and values or a set of criteria against workspace objects.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaquerystrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaquerytypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAQUERYSTRONGMNGD_API FinderService
    : public Teamcenter::Services::Query::_2007_06::Finder
{
public:
    static FinderService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Query the database for <b>WorkspaceObjects</b>. A collection of WSOFindSets are used
     * to do the queries. For each WSOFindSet , a FindWorkspaceObjectsOutput will be generated
     * if any <b>WorkspaceObjects</b> are found that meet all the criteria.  Each FindWorkspaceObjectsOutput
     * will contain the tags of the <b>WorkspaceObjects</b> that meet all the criteria and
     * the index of the WSOFindSet in the findList that generated the output.  If an error
     * is encountered, then no FindWorkspaceObjectsOutput will be generated for that WSOFindSet
     * (no partial data returned) and the index for the WSOFindSet in the findList will
     * be the client ID in the partial error.  If no WSOFindSet generates any output, a
     * null outputList is returned.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Find workspace object using basic attributes such as object type, object name, owner,
     * group, created before, created after etc.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Business Intelligence - Capability to create and manage report definitions and generate
     * reports
     *
     * @param findList
     *        A list of WSOFindSet used to find workspace objects.
     *
     * @return
     *         Contains a list of FindWorkspaceObjectsOutput structures (which contain the found
     *         workspace objects). Any found workspace objects will be sent back in the standard
     *         ServiceData list of plain objects. Any failure will be returned as partial errors
     *         in ServiceData with index for the WSOFindSet in the findList.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Query::_2007_06::Finder::FindWorkspaceObjectsResponse findWorkspaceObjects ( const std::vector< Teamcenter::Services::Query::_2007_06::Finder::WSOFindSet >& findList ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("FinderService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/query/Query_undef.h>
#endif

