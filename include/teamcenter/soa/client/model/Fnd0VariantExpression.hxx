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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0VARIANTEXPRESSION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0VARIANTEXPRESSION_HXX

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
                class ConfigurationCNF;


class TCSOACLIENTMNGD_API Fnd0VariantExpression : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_fnd0formula_state();
    const std::string& get_fnd0formula();
    int get_fnd0operator();
    const std::string& get_fnd0product_name();
    const std::string& get_fnd0product_namespace();
    size_t count_fnd0cnfs();
    Teamcenter::Soa::Common::AutoPtr<ConfigurationCNF> get_fnd0cnfs_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0VariantExpression")

   virtual ~Fnd0VariantExpression();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
