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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING_MFGPROPERTYCOLLECTORSERVICE_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING_MFGPROPERTYCOLLECTORSERVICE_HXX

#include <teamcenter/services/manufacturing/_2009_10/Mfgpropertycollector.hxx>



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
            class MfgpropertycollectorService;

/**
 * This service will provide server functionality to collect property values for every
 * node in the BOP structure.
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

class TCSOAMANUFACTURINGSTRONGMNGD_API MfgpropertycollectorService
    : public Teamcenter::Services::Manufacturing::_2009_10::Mfgpropertycollector
{
public:
    static MfgpropertycollectorService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This function will call a Mfg function that takes the MfgNode, traversal rules and
     * property names to collect and return a list of property values of input properties
     * for every MfgNode in the BOP structure based on traversal rules.
     *
     * @param input
     *        MfgNode, traversal rules and property names to collect
     *
     * @return
     *         a list of property values of input properties for every MfgNode in the BOP structure
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Mfgpropertycollector::CollectPropertiesResponse collectProperties ( const std::vector< Teamcenter::Services::Manufacturing::_2009_10::Mfgpropertycollector::CollectPropertiesInputInfo >& input ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MfgpropertycollectorService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

