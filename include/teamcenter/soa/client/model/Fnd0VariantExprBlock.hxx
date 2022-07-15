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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0VARIANTEXPRBLOCK_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0VARIANTEXPRBLOCK_HXX

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
                class Fnd0VariantExpression;


class TCSOACLIENTMNGD_API Fnd0VariantExprBlock : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_fnd0affectedObject();
    size_t count_fnd0expressions();
    Teamcenter::Soa::Common::AutoPtr<Fnd0VariantExpression> get_fnd0expressions_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0VariantExprBlock")

   virtual ~Fnd0VariantExprBlock();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
