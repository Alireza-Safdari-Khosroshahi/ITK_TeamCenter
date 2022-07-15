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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DEEPCOPYRULE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DEEPCOPYRULE_HXX

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
                class ImanType;


class TCSOACLIENTMNGD_API DeepCopyRule : public Teamcenter::Soa::Client::Model::BusinessRule
{
public:
    const std::string& get_type_name();
    int get_operation();
    int get_copy_type();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_relation();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_attach_type();
    bool get_is_required();
    bool get_is_target_primary();
    bool get_copy_relation_attributes();
    const std::string& get_reference_property_name();
    int get_propertyType();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DeepCopyRule")

   virtual ~DeepCopyRule();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
