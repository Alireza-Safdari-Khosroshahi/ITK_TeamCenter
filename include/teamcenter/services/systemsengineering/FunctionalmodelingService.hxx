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

#ifndef TEAMCENTER_SERVICES_SYSTEMSENGINEERING_FUNCTIONALMODELINGSERVICE_HXX
#define TEAMCENTER_SERVICES_SYSTEMSENGINEERING_FUNCTIONALMODELINGSERVICE_HXX

#include <teamcenter/services/systemsengineering/_2011_06/Functionalmodeling.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/systemsengineering/SystemsEngineering_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Systemsengineering
        {
            class FunctionalmodelingService;

/**
 * The FunctionalModeling service provides operations to manage Functional Modeling
 * structures. At present the service provides operation to delete an entire functional
 * structure.
 * <br>
 * <br>
 * The FunctionalModeling service can be used to support the following:
 * <br>
 * <ul>
 * <li type="disc">Delete an entire Functional structure including all the interfaces
 * and relations.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoasystemsengineeringstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoasystemsengineeringtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOASYSTEMSENGINEERINGSTRONGMNGD_API FunctionalmodelingService
    : public Teamcenter::Services::Systemsengineering::_2011_06::Functionalmodeling
{
public:
    static FunctionalmodelingService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation deletes a <b>BOMLine</b> object and optionally deletes its entire
     * BOM structure. It not only deletes the structure relations but also deletes the objects
     * underlying the BOM lines. If user chooses to delete the entire BOM structure, the
     * structure is traversed and every node is validated for deletion. If the Teamcenter
     * business object is released or referenced or there are more than one revisions of
     * it, it cannot be deleted.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Systems Engineering - Application to construct Systems Engineering view of the product
     *
     * @param input
     *        holds the required information to delete a line or structure.
     *
     * @return
     *         There are no objects returned but in case of failure to delete the objects, following
     *         errors are returned in the <b>ServiceData</b>.
     *         <br>
     *         <ul>
     *         <li type="disc">292052&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If there are
     *         multiple revisions of the Item, it cannot be deleted.
     *         </li>
     *         <li type="disc">292053&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If the Teamcenter
     *         business object is released, it cannot be deleted.
     *         </li>
     *         <li type="disc">292054&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If the Teamcenter
     *         business object is referenced, it cannot be deleted.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteFunctionStructure ( const std::vector< Teamcenter::Services::Systemsengineering::_2011_06::Functionalmodeling::DeleteFunctionStructInfo >& input ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("FunctionalmodelingService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/systemsengineering/SystemsEngineering_undef.h>
#endif

