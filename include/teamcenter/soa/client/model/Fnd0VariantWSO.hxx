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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0VARIANTWSO_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0VARIANTWSO_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0ConfiguratorWSO.hxx>

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


class TCSOACLIENTMNGD_API Fnd0VariantWSO : public Teamcenter::Soa::Client::Model::Fnd0ConfiguratorWSO
{
public:
    Teamcenter::Soa::Common::AutoPtr<VariantExpression> get_fnd0target();
    const std::string& get_fnd0TargetExpressionAsText();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0VariantWSO")

   virtual ~Fnd0VariantWSO();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
