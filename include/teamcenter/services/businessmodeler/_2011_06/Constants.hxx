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

#ifndef TEAMCENTER_SERVICES_BUSINESSMODELER__2011_06_CONSTANTS_HXX
#define TEAMCENTER_SERVICES_BUSINESSMODELER__2011_06_CONSTANTS_HXX



#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/businessmodeler/BusinessModeler_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Businessmodeler
        {
            namespace _2011_06
            {
                class Constants;

class TCSOABUSINESSMODELERSTRONGMNGD_API Constants
{
public:

    struct GlobalConstantValue2;
    struct GlobalConstantValueResponse2;

    /**
     * Holds the name of the global constant and corresponding global constant value.
     */
    struct GlobalConstantValue2
    {
        /**
         * Name of the global constant.
         */
        std::string key;
        /**
         * The global constant value(s) corresponding to the specified constant.
         */
        std::vector< std::string > value;
    };

    /**
     * Holds the response for the <code>getGlobalConstantValues</code> operation.
     */
    struct GlobalConstantValueResponse2
    {
        /**
         * The requested global constants.
         */
        std::vector< Teamcenter::Services::Businessmodeler::_2011_06::Constants::GlobalConstantValue2 > constantValues;
        /**
         * This contains the status of the operation. A partial error is returned If the name
         * global constant cannot be added to the global default cache (74502).
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Constants() {}
};
            }
        }
    }
}

#include <teamcenter/services/businessmodeler/BusinessModeler_undef.h>
#endif

