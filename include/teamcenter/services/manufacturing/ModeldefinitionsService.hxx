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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING_MODELDEFINITIONSSERVICE_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING_MODELDEFINITIONSSERVICE_HXX

#include <teamcenter/services/manufacturing/_2009_10/Modeldefinitions.hxx>



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
            class ModeldefinitionsService;

/**
 * Meta data
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

class TCSOAMANUFACTURINGSTRONGMNGD_API ModeldefinitionsService
    : public Teamcenter::Services::Manufacturing::_2009_10::Modeldefinitions
{
public:
    static ModeldefinitionsService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Get the attached property descriptor based on input type name and property names
     * structure.
     *
     * @param inputs
     *        - vector of structure of PropDescInfo with type name and property names vector.
     *
     * @return
     *         AttachedPropDescsResponse - Response structure with Map of input typeName to PropDesc
     *         structure and serviceData
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Modeldefinitions::AttachedPropDescsResponse getManufacturingPropretyDescs ( const std::vector< Teamcenter::Services::Manufacturing::_2009_10::Modeldefinitions::PropDescInfo >& inputs ) = 0;

    /**
     * This service returns a list of occurrence types that are valid for assignment between
     * two received object types.
     *
     * @param relationTypesInput
     *        Vector of source and target types pairs.
     *
     * @return
     *         List of valid occurrence types.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Modeldefinitions::GetValidRelationTypesResponse getValidRelationTypes ( const std::vector< Teamcenter::Services::Manufacturing::_2009_10::Modeldefinitions::RelationTypesInput >& relationTypesInput ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ModeldefinitionsService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

