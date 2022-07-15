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

#ifndef TEAMCENTER_SERVICES_BUSINESSMODELER_RULESBASEDFRAMEWORKSERVICE_HXX
#define TEAMCENTER_SERVICES_BUSINESSMODELER_RULESBASEDFRAMEWORKSERVICE_HXX

#include <teamcenter/services/businessmodeler/_2007_06/Rulesbasedframework.hxx>



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
            class RulesbasedframeworkService;

/**
 * The <code>RulesBasedFramework</code> (RBF) service provides an operation to evaluate
 * an application extension rule (<b>AppExtensionRule</b>).  The application extension
 * rules are based on the definition of an application extension point (<b>AppExtensionPoint</b>)
 * in a specified business context (<b>BusinessContext</b>).  The evaluation of an application
 * extension rule is performed by the CLIPS (3rd party) rules engine.  All of these
 * RBF components are maintained in the BMIDE.
 * <br>
 * <ul>
 * <li type="disc">An application extension point exposes a point of configurability
 * in Teamcenter using a decision table.  The decision table defines inputs and outputs
 * that can be configured.
 * </li>
 * <li type="disc">An application extension rule defines a set of input and output values
 * based on the application extension point configuration.  It also defines a set of
 * business contexts in which the rule can be applied.
 * </li>
 * <li type="disc">A business context constrains an application extension rule to a
 * specific environment in which a user works (organizational groups and roles).
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

class TCSOABUSINESSMODELERSTRONGMNGD_API RulesbasedframeworkService
    : public Teamcenter::Services::Businessmodeler::_2007_06::Rulesbasedframework
{
public:
    static RulesbasedframeworkService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RulesbasedframeworkService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/businessmodeler/BusinessModeler_undef.h>
#endif

