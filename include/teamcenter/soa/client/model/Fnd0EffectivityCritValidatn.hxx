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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0EFFECTIVITYCRITVALIDATN_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0EFFECTIVITYCRITVALIDATN_HXX

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
                class ConfigurationFamily;


class TCSOACLIENTMNGD_API Fnd0EffectivityCritValidatn : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_fnd0validation_result();
    const Teamcenter::Soa::Client::StringVector& get_fnd0violated_rules();
    const Teamcenter::Soa::Client::BoolVector& get_fnd0is_partial_default();
    const Teamcenter::Soa::Client::StringVector& get_fnd0applied_to_expr();
    const Teamcenter::Soa::Client::StringVector& get_fnd0restrictive_conditions();
    bool get_fnd0valid();
    bool get_fnd0complete();
    const std::string& get_fnd0product_name();
    const std::string& get_fnd0product_namespace();
    size_t count_fnd0unset_families();
    Teamcenter::Soa::Common::AutoPtr<ConfigurationFamily> get_fnd0unset_families_at( size_t inx );
    const Teamcenter::Soa::Client::StringVector& get_fnd0applied_defaults();
    const Teamcenter::Soa::Client::StringVector& get_fnd0validation_errors();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0EffectivityCritValidatn")

   virtual ~Fnd0EffectivityCritValidatn();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
