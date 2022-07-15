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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VARIANTEXPRESSION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VARIANTEXPRESSION_HXX

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
                class POM_object;
                class POM_object;
                class ConfigurationCNF;


class TCSOACLIENTMNGD_API VariantExpression : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_variable_one();
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_variable_two();
    int get_operator();
    const std::string& get_string();
    const std::string& get_formula();
    const std::string& get_product_name();
    const std::string& get_product_namespace();
    int get_formula_state();
    size_t count_cnfs();
    Teamcenter::Soa::Common::AutoPtr<ConfigurationCNF> get_cnfs_at( size_t inx );
    const std::string& get_as_string();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("VariantExpression")

   virtual ~VariantExpression();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
