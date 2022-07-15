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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPEXTENSIONPOINT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPEXTENSIONPOINT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/BusinessElement.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class RBFInput;
                class RBFOutput;


class TCSOACLIENTMNGD_API AppExtensionPoint : public Teamcenter::Soa::Client::Model::BusinessElement
{
public:
    const std::string& get_id();
    int get_rule_type();
    const std::string& get_category();
    size_t count_inputs();
    Teamcenter::Soa::Common::AutoPtr<RBFInput> get_inputs_at( size_t inx );
    size_t count_outputs();
    Teamcenter::Soa::Common::AutoPtr<RBFOutput> get_outputs_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AppExtensionPoint")

   virtual ~AppExtensionPoint();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
