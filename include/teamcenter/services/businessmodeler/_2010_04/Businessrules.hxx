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

#ifndef TEAMCENTER_SERVICES_BUSINESSMODELER__2010_04_BUSINESSRULES_HXX
#define TEAMCENTER_SERVICES_BUSINESSMODELER__2010_04_BUSINESSRULES_HXX

#include <teamcenter/soa/client/model/VerificationRule.hxx>


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
            namespace _2010_04
            {
                class Businessrules;

class TCSOABUSINESSMODELERSTRONGMNGD_API Businessrules
{
public:

    struct GetVerificationRulesResponse;
    struct VerificationRuleInput;
    struct VerificationRulesInfo;

    /**
     * The response information returned by <i>getVerificationRules</i>.
     */
    struct GetVerificationRulesResponse
    {
        /**
         * The <i>ServiceData</i> object  which contains generic information like error number
         * and error information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * The list of <b>VerificationRule</b> objects information.
         */
        std::vector< Teamcenter::Services::Businessmodeler::_2010_04::Businessrules::VerificationRulesInfo > outputs;
    };

    /**
     * The criteria to get <b>VerificationRule</b> objects.
     */
    struct VerificationRuleInput
    {
        /**
         * The desired value of the <i>functionality</i> property of the <b>VerificationRule</b>
         * objects.
         */
        std::string functionality;
        /**
         * The desired value of the <i>condition_reference</i> property of the <b>VerificationRule</b>
         * objects.
         */
        std::string conditionName;
        /**
         * The desired value (business object type name) of the <i>type</i> property of the
         * <b>VerificationRule</b> objects.
         */
        std::string typeName;
        /**
         * The desired value of the <i>subGroup</i> property of the <b>VerificationRule</b>
         * objects. It should be the value of LOV in <i>subGroupLOV</i>  property of <b>FunctionalityRule</b>
         * object associated with the <b>VerificationRule</b> object.
         */
        std::string subGroup;
    };

    /**
     * The returned <b>VerificationRule</b> objects and it associated <i>VerificationRuleInput</i>
     * index.
     */
    struct VerificationRulesInfo
    {
        /**
         * The index of <i>VerificationRuleInput</i> in parameter vector that this list of rules
         * is associated with.
         */
        int index;
        /**
         * The list of <b>VerificationRule</b> objects which match the desired criteria.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::VerificationRule>  > verificationRules;
    };




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


protected:
    virtual ~Businessrules() {}
};
            }
        }
    }
}

#include <teamcenter/services/businessmodeler/BusinessModeler_undef.h>
#endif

