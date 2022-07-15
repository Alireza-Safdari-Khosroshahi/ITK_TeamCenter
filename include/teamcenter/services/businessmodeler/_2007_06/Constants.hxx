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

#ifndef TEAMCENTER_SERVICES_BUSINESSMODELER__2007_06_CONSTANTS_HXX
#define TEAMCENTER_SERVICES_BUSINESSMODELER__2007_06_CONSTANTS_HXX



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
            namespace _2007_06
            {
                class Constants;

class TCSOABUSINESSMODELERSTRONGMNGD_API Constants
{
public:

    struct GlobalConstantValue;
    struct GlobalConstantValueResponse;
    struct PropertyConstantKey;
    struct PropertyConstantValue;
    struct PropertyConstantValueResponse;
    struct TypeConstantKey;
    struct TypeConstantValue;
    struct TypeConstantValueResponse;

    /**
     * The <code>GlobalConstantValue</code> data structure holds a the name of the global
     * constant corresponding global constant value
     */
    struct GlobalConstantValue
    {
        /**
         * Name of the global constant.
         */
        std::string key;
        /**
         * The global constant value corresponding to the specified constant.
         */
        std::string value;
    };

    /**
     * Holds the response for the getGlobalConstantValues operation.
     */
    struct GlobalConstantValueResponse
    {
        /**
         * The requested global constants.
         */
        std::vector< Teamcenter::Services::Businessmodeler::_2007_06::Constants::GlobalConstantValue > constantValues;
        /**
         * This contains the status of the operation. A partial error is returned if the name
         * global constant cannot be added to the global default cache (74502), or if the named
         * constant is multivalued(74528) .
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Holds the name of the constant, name of the type and name of the property which are
     * required to get the value of a property constant.
     */
    struct PropertyConstantKey
    {
        /**
         * Name of the constant.
         */
        std::string constantName;
        /**
         * Name of the type.
         */
        std::string typeName;
        /**
         * Name of the property.
         */
        std::string propertyName;
    };

    /**
     * Holds a the name of the property constant and corresponding property constant value
     */
    struct PropertyConstantValue
    {
        /**
         * The requested property constant.
         */
        Teamcenter::Services::Businessmodeler::_2007_06::Constants::PropertyConstantKey key;
        /**
         * The property constant value corresponding to the specified constant
         */
        std::string value;
    };

    /**
     * The <code>PropertyConstantValueResponse</code> data structure holds the response
     * for the <code>getPropertyConstantValues</code> method.
     */
    struct PropertyConstantValueResponse
    {
        /**
         * The resultant property constant values are returned as keyvalue pairs using <code>PropertyConstantValue</code>
         * structure.
         */
        std::vector< Teamcenter::Services::Businessmodeler::_2007_06::Constants::PropertyConstantValue > constantValues;
        /**
         * This contains the status of the operation.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Holds the name of the constant, name of the type which are required to get the value
     * of a type constant.
     */
    struct TypeConstantKey
    {
        /**
         * Name of the constant.
         */
        std::string constantName;
        /**
         * Name of the type.
         */
        std::string typeName;
    };

    /**
     * Holds a the name of the type constant and corresponding type constant value.
     */
    struct TypeConstantValue
    {
        /**
         * The requested type constant.
         */
        Teamcenter::Services::Businessmodeler::_2007_06::Constants::TypeConstantKey key;
        /**
         * The type constant value corresponding to the specified constant.
         */
        std::string value;
    };

    /**
     * Holds the response for the <code>getTypeConstantValues</code> operation.
     */
    struct TypeConstantValueResponse
    {
        /**
         * The resultant type constant values are returned as key/value pairs using <code>TypeConstantValue</code>
         * structure.
         */
        std::vector< Teamcenter::Services::Businessmodeler::_2007_06::Constants::TypeConstantValue > constantValues;
        /**
         * This contains the status of the operation.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Constants() {}
};
            }
        }
    }
}

#include <teamcenter/services/businessmodeler/BusinessModeler_undef.h>
#endif

