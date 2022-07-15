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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_NAMEDVARIANTEXPRESSION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_NAMEDVARIANTEXPRESSION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/VariantExpression.hxx>

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


class TCSOACLIENTMNGD_API NamedVariantExpression : public Teamcenter::Soa::Client::Model::VariantExpression
{
public:
    const std::string& get_code();
    const std::string& get_description();
    int get_fingerprint();
    size_t count_literal();
    Teamcenter::Soa::Common::AutoPtr<VariantExpression> get_literal_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("NamedVariantExpression")

   virtual ~NamedVariantExpression();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
