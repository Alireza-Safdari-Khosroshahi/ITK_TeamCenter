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

#ifndef TEAMCENTER_SERVICES_BUSINESSMODELER__2007_06_RULESBASEDFRAMEWORK_HXX
#define TEAMCENTER_SERVICES_BUSINESSMODELER__2007_06_RULESBASEDFRAMEWORK_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


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
                class Rulesbasedframework;

class TCSOABUSINESSMODELERSTRONGMNGD_API Rulesbasedframework
{
public:

    struct ExecuteRbfRulesResponse;
    struct RbfValue;
    struct RbfNameValue;

    /**
     * Holds the response for the <code>executeRbfRules</code> operation.
     */
    struct ExecuteRbfRulesResponse
    {
        /**
         * This is a set of output name/value pairs from the rules engine execution.
         */
        std::vector< Teamcenter::Services::Businessmodeler::_2007_06::Rulesbasedframework::RbfNameValue > outputs;
        /**
         * This contains the status of the operation.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The value for an input or output column on an Application Extension Rule.
     */
    struct RbfValue
    {
        /**
         * The type of data the structure is holding. It will have one of the following values:
         * <code> STRING, BOOLEAN, INTEGER, DOUBLE, FLOAT, DATE, or TAG</code>.
         */
        std::string dataType;
        /**
         * The <code>STRING</code> value for the column.
         */
        std::string stringValue;
        /**
         * The <code>BOOLEAN</code> value for the column.
         */
        bool booleanValue;
        /**
         * The <code>INTEGER</code> value for the column.
         */
        int integerValue;
        /**
         * The <code>DOUBLE</code> value for the column.
         */
        double doubleValue;
        /**
         * The <code>FLOAT</code> value for the column.
         */
        float floatValue;
        /**
         * The <code>DATE</code> value for the column.
         */
        Teamcenter::Soa::Common::DateTime dateValue;
        /**
         * The <code>TAG</code> value for the column.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  tagValue;
    };

    /**
     * The name of the input or output column along with the data value on a application
     * extension rule.
     */
    struct RbfNameValue
    {
        /**
         * The input or output column name from the application extension rule.
         */
        std::string name;
        /**
         * The value of the named column.
         */
        Teamcenter::Services::Businessmodeler::_2007_06::Rulesbasedframework::RbfValue value;
    };




    /**
     * This operation invokes the CLIPS rules engine to apply the set of application extension
     * rules that belong to the specified application extension point for the specified
     * input name/value pairs.  The result of the execution is returned in the output name/value
     * pairs.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * BMIDE (Server) - Set of services provided by BMIDE that allow efficiently underyling
     * capabilities to develop/modify business objects
     *
     * @param id
     *        The application extension point ID for which this application extension rule is configured.
     *
     * @param inputs
     *        A set of input name/value pairs for the rules engine execution.
     *
     * @return
     *         The output columns and their name/values pairs that satisfy the input and the status
     *         of the operation.
     *         <br>
     *         The following partial errors could be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">74306&nbsp;&nbsp;&nbsp;&nbsp;No defmodule with the supplied id is
     *         found in the rules engine.
     *         </li>
     *         <li type="disc">74307&nbsp;&nbsp;&nbsp;&nbsp;No application point with the supplied
     *         id is found in the database.
     *         </li>
     *         <li type="disc">74308&nbsp;&nbsp;&nbsp;&nbsp;The input object is not of the expected
     *         type defined in the application extension point.
     *         </li>
     *         <li type="disc">74309&nbsp;&nbsp;&nbsp;&nbsp;At least one input name does not match
     *         any of the ones expected by the application extension point.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Businessmodeler::_2007_06::Rulesbasedframework::ExecuteRbfRulesResponse executeRbfRules ( const std::string&  id,
        const std::vector< Teamcenter::Services::Businessmodeler::_2007_06::Rulesbasedframework::RbfNameValue >& inputs ) = 0;


protected:
    virtual ~Rulesbasedframework() {}
};
            }
        }
    }
}

#include <teamcenter/services/businessmodeler/BusinessModeler_undef.h>
#endif

