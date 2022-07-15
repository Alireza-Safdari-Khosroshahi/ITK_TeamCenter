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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_BMOPERATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_BMOPERATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/BusinessRule.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ExtensionPoint;


class TCSOACLIENTMNGD_API BMOperation : public Teamcenter::Soa::Client::Model::BusinessRule
{
public:
    const std::string& get_operation_name();
    size_t count_extensionpoints();
    Teamcenter::Soa::Common::AutoPtr<ExtensionPoint> get_extensionpoints_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("BMOperation")

   virtual ~BMOperation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
