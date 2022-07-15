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

#ifndef TEAMCENTER_SERVICES_BUSINESSMODELER_DEEPCOPYRULESSERVICE_HXX
#define TEAMCENTER_SERVICES_BUSINESSMODELER_DEEPCOPYRULESSERVICE_HXX

#include <teamcenter/services/businessmodeler/_2008_06/Deepcopyrules.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/businessmodeler/BusinessModeler_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Businessmodeler
        {
            class DeepcopyrulesService;

/**
 * The <code>DeepCopyRules</code> service exposes the operations that are used to perform
 * <code>revise</code> or <code>saveas</code> operation on item revision objects. Deep
 * copy rules define whether objects belonging to an item revision can be copied when
 * a user performs a save as or revise operation on an item revision. Deep copy rules
 * are applied only to item revision business objects and are inherited by children
 * business objects.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoabusinessmodelerstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoabusinessmodelertypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOABUSINESSMODELERSTRONGMNGD_API DeepcopyrulesService
    : public Teamcenter::Services::Businessmodeler::_2008_06::Deepcopyrules
{
public:
    static DeepcopyrulesService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Deep copy rules define whether objects belonging to a business object instance can
     * be copied when a user performs a save as or revise operation on that instance. Deep
     * copy rules can be applied to any business object type, and are inherited by children
     * business object types. This operation gets the applicable deep copy rules for the
     * given list of objects and the operation specified for each object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * BMIDE (Server) - Set of services provided by BMIDE that allow efficiently underyling
     * capabilities to develop/modify business objects
     *
     * @param keys
     *        List of itemRevision object tag and the operation name for which deep copy information
     *        is needed.
     *
     * @return
     *         A structure containing the values of the applicable deep copy rules and status of
     *         the operation. This operation does not return any error other than propagating the
     *         errors received from low level functions which are called from within the operation.
     *
     */
    virtual Teamcenter::Services::Businessmodeler::_2008_06::Deepcopyrules::DeepCopyInfoResponse getDeepCopyInfo ( const std::vector< Teamcenter::Services::Businessmodeler::_2008_06::Deepcopyrules::DeepCopyInfoKey >& keys ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DeepcopyrulesService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/businessmodeler/BusinessModeler_undef.h>
#endif

