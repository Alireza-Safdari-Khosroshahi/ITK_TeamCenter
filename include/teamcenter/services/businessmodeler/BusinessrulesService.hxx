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

#ifndef TEAMCENTER_SERVICES_BUSINESSMODELER_BUSINESSRULESSERVICE_HXX
#define TEAMCENTER_SERVICES_BUSINESSMODELER_BUSINESSRULESSERVICE_HXX

#include <teamcenter/services/businessmodeler/_2010_04/Businessrules.hxx>



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
            class BusinessrulesService;

/**
 * The <b>BusinessRule</b>s service exposes operations that are used to fetch or maintain
 * <b>BusinessRule</b> objects. Common use includes Teamcenter Rich Client applications
 * require BusinessRule objects administrator creates in <b>Business Modeler IDE</b>.
 * <br>
 * This service provides following use case to deal with <b>BusinessRule</b> objects.
 * <br>
 * <ul>
 * <li type="disc">Query a set of VerificationRule objects defined in <b>Business Modeler
 * IDE</b> with given search criteria
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

class TCSOABUSINESSMODELERSTRONGMNGD_API BusinessrulesService
    : public Teamcenter::Services::Businessmodeler::_2010_04::Businessrules
{
public:
    static BusinessrulesService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation gets a list of <b>VerificationRule</b> objects which match the given
     * criteria each <i>VerificationRuleInput</i> supplied and its <i>context_filter</i>
     * attribute which refers to a <b>Condition</b> object defined in <b>Business Modeler
     * IDE</b> equals to true; Wild cards can be specified in strings using * in <i>VerificationRuleInput</i>
     * which mean to match all cases for the criteria strings. This operation not only returns
     * all <b>VerificationRule</b> objects which full match criteria in <i>VerificationRuleInput</i>,
     * it also returns <b>VerificationRule</b> objects whose <i>type</i> attribute is the
     * parent of the <i>typeName</i> defined in the <i>VerificationRuleInput</i>, meanwhile
     * other criteria are matched.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * 4 samples Verification Rules created in <b>Business Modeler IDE</b>
     * <br>
     * {Functionality= Fnd0BOMGrading, Business Object=Item, Context Filter =isTrue, Condition
     * Rule=Condition1, Sub Group=*}
     * <br>
     * {Functionality= Fnd0BOMGrading, Business Object=Part, Context Filter = isEngineeringGroup,
     * Condition Rule=Condition1, Sub Group=*}
     * <br>
     * {Functionality= Fnd0BOMGrading, Business Object= CommericalPart, Context Filter =isTrue,
     * Condition Rule=Condition2, Sub Group= Americas}
     * <br>
     * {Functionality= Fnd0APS, Business Object=Item, Context Filter =isTrue, Condition
     * Rule=Condition1, Sub Group= *}
     * <br>
     * Login Teamcenter as dba group and get <b>VerificationRule</b> objects by setting
     * <i>functionality</i> as Fnd0BOMGrading and <i>typeName</i> as CommericalPart. Following
     * <b>VerificationRule</b> objects in will be returned.
     * <br>
     * {Functionality= Fnd0BOMGrading, Business Object=Item, Context Filter =isTrue, Condition
     * Rule=Condition1, Sub Group=*}
     * <br>
     * {Functionality= Fnd0BOMGrading, Business Object= CommericalPart, Context Filter =isTrue,
     * Condition Rule=Condition2, Sub Group=Americas}
     * <br>
     * The first rule applies to <b>Item</b>, if Condition1 could check <b>Item</b>, it
     * could check <b>CommericalPart</b>, since <b>CommericalPart</b> is a sub type of <b>Item</b>
     * and it is sure that <b>CommericalPart</b> contains all properties checked in Condition1,
     * so it is valid. The second rule applies to all <b>CommericalPart</b>, so it is also
     * valid. The other <b>VerificationRule</b> objects either do not match <i>functionality</i>
     * or <i>typeName</i>, or else <i>context_filter</i> equals to false.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * BMIDE (Server) - Set of services provided by BMIDE that allow efficiently underyling
     * capabilities to develop/modify business objects
     *
     * @param input
     *        The criteria for filtering the list of <b>VericationRule</b> objects.
     *
     * @return
     *         The <b>VerificationRule</b> objects which match criteria. A partial error 265005
     *         is returned if there are errors in the input parameters; a partial error 265006 is
     *         returned for any error encountered while retrieving the <b>VerificationRule</b> objects.
     *
     */
    virtual Teamcenter::Services::Businessmodeler::_2010_04::Businessrules::GetVerificationRulesResponse getVerificationRules ( const std::vector< Teamcenter::Services::Businessmodeler::_2010_04::Businessrules::VerificationRuleInput >& input ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("BusinessrulesService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/businessmodeler/BusinessModeler_undef.h>
#endif

