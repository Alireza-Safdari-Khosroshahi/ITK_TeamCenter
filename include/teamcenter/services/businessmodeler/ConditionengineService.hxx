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

#ifndef TEAMCENTER_SERVICES_BUSINESSMODELER_CONDITIONENGINESERVICE_HXX
#define TEAMCENTER_SERVICES_BUSINESSMODELER_CONDITIONENGINESERVICE_HXX

#include <teamcenter/services/businessmodeler/_2008_06/Conditionengine.hxx>



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
            class ConditionengineService;

/**
 * The <code>ConditionEngine</code> service provides an operation to evaluate a <b>Condition</b>
 * expression.  A <b>Condition</b> signature defines parameters (<b>ConditionParameter</b>)
 * that are required (and are order dependent) to evaluate a specific <b>Condition</b>.
 * These parameters represent object instances from the Teamcenter database that can
 * be used within the expression during evaluation.  The evaluation of a Condition is
 * performed by the <b>CLIPS</b> (3rd party) rules engine.  The evaluation of a Condition
 * expression will always provide either a <code>True</code> or <code>False</code> result.
 * All of these <b>Condition</b> components are maintained in the BMIDE.
 * <br>
 * <br>
 * Use case:
 * <br>
 * <ul>
 * <li type="disc">The ConditionEngine service can be used for supporting the following
 * usecases:
 * </li>
 * <li type="disc">Determine what List of Value (<b>LOV</b>) is applied when attaching
 * an <b>LOV</b> to a property.
 * </li>
 * <li type="disc">Determine when various kinds of rules (deep copy, naming, business
 * object display, extension) are applied.
 * </li>
 * <li type="disc">Determine when an Item Revision Definition Configuration (<b>IRDC</b>)
 * applies to an item revision to control how document management processes affect item
 * revision behavior in a document management system.
 * </li>
 * <li type="disc">Configure Bill of Material <b>(BOM</b>) grading for part validation.
 * </li>
 * <li type="disc">Configure user based access to project data.
 * </li>
 * <li type="disc">Determine when a property renderer attachment is applied.
 * </li>
 * <li type="disc">Determine when a business object constant is applied.
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

class TCSOABUSINESSMODELERSTRONGMNGD_API ConditionengineService
    : public Teamcenter::Services::Businessmodeler::_2008_06::Conditionengine
{
public:
    static ConditionengineService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ConditionengineService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/businessmodeler/BusinessModeler_undef.h>
#endif

