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

#ifndef TEAMCENTER_SERVICES_BUSINESSMODELER_CONSTANTSSERVICE_HXX
#define TEAMCENTER_SERVICES_BUSINESSMODELER_CONSTANTSSERVICE_HXX

#include <teamcenter/services/businessmodeler/_2007_06/Constants.hxx>
#include <teamcenter/services/businessmodeler/_2011_06/Constants.hxx>



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
            class ConstantsService;

/**
 * Constants are a configuration point within the data model. There are three kinds
 * of constants global, business object and property. <i>Global constants</i> provide
 * consistent definitions that can be used throughout the system. These constants have
 * one value, either the default value or the value user set. You can also provide multi
 * value global constants.  <i>Business object constant</i> provide default values to
 * business objects. Because these constants are attached to business objects, they
 * are inherited and can be overridden in the hierarchy. <i>Property constants</i> are
 * a configuration point within the data model that provides default values to business
 * object properties. You can define a property constant to have a specific scope so
 * that it is available only on certain properties on certain business objects.
 * <br>
 * <br>
 * The <code>Constants</code> service provides operation to query the value of global,
 * property, and type constants. The user will need to use these operations to retrieve
 * the values of the constants and determine the system behavior based on the values.
 * <br>
 * <br>
 * Use case
 * <br>
 * The Constants service can be used for supporting following usecases
 * <br>
 * <ul>
 * <li type="disc">Query value of global constants
 * </li>
 * <li type="disc">Query value of property constant
 * </li>
 * <li type="disc">Query value of type constant
 * </li>
 * </ul>
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

class TCSOABUSINESSMODELERSTRONGMNGD_API ConstantsService
    : public Teamcenter::Services::Businessmodeler::_2007_06::Constants,
             public Teamcenter::Services::Businessmodeler::_2011_06::Constants
{
public:
    static ConstantsService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Global constants provide consistent definitions that can be used throughout the system.
     * These constants have one or multiple values.  User can retrieve the values of global
     * constants to determine the system behavior based on values. This operation gets the
     * values of the named global constants (<code>keys</code>). This operation only supports
     * single valued global constants, for multivalued constants use the <code>getGlobalConstantValues2</code>
     * operation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * BMIDE (Server) - Set of services provided by BMIDE that allow efficiently underyling
     * capabilities to develop/modify business objects
     *
     * @param keys
     *        A list of the desired global constant names.
     *
     * @return
     *         The values of the requested global constants. A partial error is returned if the
     *         name global constant cannot be added to the global default cache (74502), or if the
     *         named constant is multivalued(74528)
     *
     * @deprecated
     *         As of Teamcenter 9, use the getGlobalConstantValues2 operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 9, use the getGlobalConstantValues2 operation."))
#endif
    virtual Teamcenter::Services::Businessmodeler::_2007_06::Constants::GlobalConstantValueResponse getGlobalConstantValues ( const std::vector< std::string >& keys ) = 0;

    /**
     * This operation gets the values of the named property constants (<code>keys</code>).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * BMIDE (Server) - Set of services provided by BMIDE that allow efficiently underyling
     * capabilities to develop/modify business objects
     *
     * @param keys
     *        A list of the desired property constant names.
     *
     * @return
     *         The values of the requested propoerty constants. A partial error is returned if the
     *         name prooperty constant cannot be added to the type attach cache (74507), or if the
     *         prooperty constant value cannot be retrieved (74521)
     *
     */
    virtual Teamcenter::Services::Businessmodeler::_2007_06::Constants::PropertyConstantValueResponse getPropertyConstantValues ( const std::vector< Teamcenter::Services::Businessmodeler::_2007_06::Constants::PropertyConstantKey >& keys ) = 0;

    /**
     * This operation gets the values of the named type constants (<code>keys</code>).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * BMIDE (Server) - Set of services provided by BMIDE that allow efficiently underyling
     * capabilities to develop/modify business objects
     *
     * @param keys
     *        A list of the desired type constants.
     *
     * @return
     *         The values of the requested type constants. A partial error is returned if the name
     *         type constant cannot be added to the type attach cache (74505), or if the type constant
     *         value cannot be retrieved (74515)
     *
     */
    virtual Teamcenter::Services::Businessmodeler::_2007_06::Constants::TypeConstantValueResponse getTypeConstantValues ( const std::vector< Teamcenter::Services::Businessmodeler::_2007_06::Constants::TypeConstantKey >& keys ) = 0;

    /**
     * Global constants provide consistent definitions that can be used throughout the system.
     * These constants have one or multiple values.  User can retrieve the values of global
     * constants to determine the system behavior based on values. This operation gets the
     * values of the named global constants (<code>keys</code>). This operation supports
     * single value and multi valued global constants. This operation replaces deprecated
     * operation <code>getGlobalConstantValues</code>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * BMIDE (Server) - Set of services provided by BMIDE that allow efficiently underyling
     * capabilities to develop/modify business objects
     *
     * @param keys
     *        A list of the desired global constant names.
     *
     * @return
     *         The values of the requested global constants. A partial error is returned If the
     *         name global constant cannot be added to the global default cache (74502).
     *
     */
    virtual Teamcenter::Services::Businessmodeler::_2011_06::Constants::GlobalConstantValueResponse2 getGlobalConstantValues2 ( const std::vector< std::string >& keys ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ConstantsService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/businessmodeler/BusinessModeler_undef.h>
#endif

