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

#ifndef TEAMCENTER_SERVICES_BUSINESSMODELER__2008_06_CONDITIONENGINE_HXX
#define TEAMCENTER_SERVICES_BUSINESSMODELER__2008_06_CONDITIONENGINE_HXX

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
            namespace _2008_06
            {
                class Conditionengine;

class TCSOABUSINESSMODELERSTRONGMNGD_API Conditionengine
{
public:

    struct ConditionInput;
    struct ConditionOutput;
    struct EvaluateConditionsResponse;

    /**
     * Holds the name of the condition to be evaluated along with the set of input parameter
     * business object values.
     */
    struct ConditionInput
    {
        /**
         * This is the name of the condition to be evaluated.
         */
        std::string conditionName;
        /**
         * This is set of condition parameters (<b>tag_t</b>) required by the specified condition
         * name.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > conditionSignature;
    };

    /**
     * Holds the results of a condition evaluation along with any exit code that was captured
     * during the condition evaluation.
     */
    struct ConditionOutput
    {
        /**
         * This is the result of the rules engine evaluation (<b>True</b> or <b>False</b>).
         */
        bool result;
        /**
         * This is the exit code (zero for success or non zero indicating an error) captured
         * during the condition evaluation.
         */
        int exitCode;
    };

    /**
     * Holds the response for the <code>evaluateConditions</code> operation.
     */
    struct EvaluateConditionsResponse
    {
        /**
         * This is a set of condition evaluation results from the rules engine execution.
         */
        std::vector< Teamcenter::Services::Businessmodeler::_2008_06::Conditionengine::ConditionOutput > outputs;
        /**
         * This contains the status of the operation.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation tells the CLIPS rules engine to evaluate the expression defined on
     * the specified <b>Condition</b> using the specified input parameter(s) defined on
     * the <b>ConditionParameter</b>.  This operation takes as input a set of conditions
     * along with parameters for each condition and returns a set of outputs containing
     * the result (true/false) and exit code of each condition evaluation. There is a one
     * to one correspondence between the elements in the input set and the elements in the
     * output set.  This allows for evaluation of multiple conditions in one operation call.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * BMIDE (Server) - Set of services provided by BMIDE that allow efficiently underyling
     * capabilities to develop/modify business objects
     *
     * @param inputs
     *        This is a set of condition(s) along with the corresponding input parameter value(s)
     *        for each condition.
     *
     * @return
     *         A list of ConditionOutput results containing the result of each condition evaluation,
     *         any exit code captured during the evaluation, and the status of the operation.
     *         <br>
     *         The following partial errors could be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">74707&nbsp;&nbsp;&nbsp;&nbsp;The number of arguments is out of range
     *         for the specified function call.
     *         </li>
     *         <li type="disc">74708&nbsp;&nbsp;&nbsp;&nbsp;The argument data type does not match
     *         what the specified function call expects.
     *         </li>
     *         <li type="disc">74711&nbsp;&nbsp;&nbsp;&nbsp;The tag specified as a condition tag
     *         is invalid.
     *         </li>
     *         <li type="disc">74714&nbsp;&nbsp;&nbsp;&nbsp;No condition engine def module is found
     *         in the rules engine.
     *         </li>
     *         <li type="disc">74726&nbsp;&nbsp;&nbsp;&nbsp;Unable to find condition with matching
     *         name.
     *         </li>
     *         <li type="disc">74731&nbsp;&nbsp;&nbsp;&nbsp;More than one CLIPS Rules datasets exist.
     *         </li>
     *         <li type="disc">74902&nbsp;&nbsp;&nbsp;&nbsp;CLIPS could not initialize and start
     *         the rules engine.
     *         </li>
     *         <li type="disc">74905&nbsp;&nbsp;&nbsp;&nbsp;The rules file could not be opened when
     *         loading the CLIPS environment.
     *         </li>
     *         <li type="disc">74906&nbsp;&nbsp;&nbsp;&nbsp;The rules file contains a syntax error.
     *         </li>
     *         <li type="disc">74907&nbsp;&nbsp;&nbsp;&nbsp;The CLIPS Rules dataset cannot be found
     *         in the database.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Businessmodeler::_2008_06::Conditionengine::EvaluateConditionsResponse evaluateConditions ( const std::vector< Teamcenter::Services::Businessmodeler::_2008_06::Conditionengine::ConditionInput >& inputs ) = 0;


protected:
    virtual ~Conditionengine() {}
};
            }
        }
    }
}

#include <teamcenter/services/businessmodeler/BusinessModeler_undef.h>
#endif

