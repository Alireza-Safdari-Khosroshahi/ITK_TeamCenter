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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT_COMPOSITIONSERVICE_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT_COMPOSITIONSERVICE_HXX

#include <teamcenter/services/structuremanagement/_2008_03/Composition.hxx>



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
            class CompositionService;

/**
 * Contains Composition Services
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

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API CompositionService
    : public Teamcenter::Services::Structuremanagement::_2008_03::Composition
{
public:
    static CompositionService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Assign lines from one or more parent to a new parent line.
     *
     * @param input
     *        BomLines to be assigned from one or more parent  to new parent line
     *
     * @return
     *         including newLines, lines without predecessors and exceptions.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2008_03::Composition::AssignChildLinesResponse assignChildLines ( const std::vector< Teamcenter::Services::Structuremanagement::_2008_03::Composition::AssignChildLinesParameter >& input ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CompositionService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

