/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

  Auto-generated source from Teamcenter Data Model.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VARIANTEXPRESSIONBLOCK_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VARIANTEXPRESSIONBLOCK_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class VariantExpression;
                class Fnd0OptionFamilyGroup;
                class Fnd0ConstraintRule;
                class Fnd0DerivedDefaultRule;
                class Fnd0FixedDefaultRule;
                class Fnd0OptionValue;


class TCSOACLIENTMNGD_API VariantExpressionBlock : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    size_t count_expressions();
    Teamcenter::Soa::Common::AutoPtr<VariantExpression> get_expressions_at( size_t inx );
    size_t count_fnd0option_groups();
    Teamcenter::Soa::Common::AutoPtr<Fnd0OptionFamilyGroup> get_fnd0option_groups_at( size_t inx );
    size_t count_fnd0constraint_rules();
    Teamcenter::Soa::Common::AutoPtr<Fnd0ConstraintRule> get_fnd0constraint_rules_at( size_t inx );
    size_t count_fnd0derived_default_rules();
    Teamcenter::Soa::Common::AutoPtr<Fnd0DerivedDefaultRule> get_fnd0derived_default_rules_at( size_t inx );
    size_t count_fnd0fixed_default_rules();
    Teamcenter::Soa::Common::AutoPtr<Fnd0FixedDefaultRule> get_fnd0fixed_default_rules_at( size_t inx );
    size_t count_fnd0option_values();
    Teamcenter::Soa::Common::AutoPtr<Fnd0OptionValue> get_fnd0option_values_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("VariantExpressionBlock")

   virtual ~VariantExpressionBlock();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
