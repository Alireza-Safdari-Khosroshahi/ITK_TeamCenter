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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TYPECANNEDMETHOD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TYPECANNEDMETHOD_HXX

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
                class ImanParameters;


class TCSOACLIENTMNGD_API TypeCannedMethod : public Teamcenter::Soa::Client::Model::BusinessRule
{
public:
    const std::string& get_type_name();
    const std::string& get_msg_name();
    int get_action_type();
    const std::string& get_method_name();
    int get_exec_seq();
    size_t count_method_options();
    Teamcenter::Soa::Common::AutoPtr<ImanParameters> get_method_options_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TypeCannedMethod")

   virtual ~TypeCannedMethod();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
