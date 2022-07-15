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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CONSTANT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CONSTANT_HXX

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
                class ConstantChoice;


class TCSOACLIENTMNGD_API Constant : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_default_value();
    int get_data_type();
    size_t count_constant_choices();
    Teamcenter::Soa::Common::AutoPtr<ConstantChoice> get_constant_choices_at( size_t inx );
    const std::string& get_description();
    const Teamcenter::Soa::Client::StringVector& get_default_values();
    bool get_is_multivalued();
    bool get_is_attachment_secured();
    bool get_allowOpsDataUpdate();
    bool get_allowOpsDataUpdateOverride();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Constant")

   virtual ~Constant();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
