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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0EFFECTIVITYCRITERIAEXPR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0EFFECTIVITYCRITERIAEXPR_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0EffectivityExpression.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Fnd0EffectivityCritValidatn;


class TCSOACLIENTMNGD_API Fnd0EffectivityCriteriaExpr : public Teamcenter::Soa::Client::Model::Fnd0EffectivityExpression
{
public:
    int get_fnd0solve_type();
    size_t count_fnd0validation_records();
    Teamcenter::Soa::Common::AutoPtr<Fnd0EffectivityCritValidatn> get_fnd0validation_records_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0EffectivityCriteriaExpr")

   virtual ~Fnd0EffectivityCriteriaExpr();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
