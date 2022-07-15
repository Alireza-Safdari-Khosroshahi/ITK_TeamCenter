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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VARIANTRULE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VARIANTRULE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class VariantExpressionBlock;


class TCSOACLIENTMNGD_API VariantRule : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<VariantExpressionBlock> get_expression_block();
    const Teamcenter::Soa::Client::StringVector& get_contents();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("VariantRule")

   virtual ~VariantRule();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
