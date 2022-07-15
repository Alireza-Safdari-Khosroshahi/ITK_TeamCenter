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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CADATTRMAPPINGDEFINITION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CADATTRMAPPINGDEFINITION_HXX

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
                class CadAttrMappingDefPart;


class TCSOACLIENTMNGD_API CadAttrMappingDefinition : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_attr_title();
    const std::string& get_item_type_name();
    const std::string& get_dataset_type_name();
    bool get_cad_master();
    bool get_iman_master();
    bool get_freezable();
    bool get_required();
    bool get_write_once();
    bool get_allow_null_value();
    const std::string& get_description();
    const std::string& get_default_value();
    int get_state();
    int get_mapping_type();
    const std::string& get_constant_value();
    const std::string& get_preference_name();
    int get_preference_scope();
    size_t count_mapping_parts();
    Teamcenter::Soa::Common::AutoPtr<CadAttrMappingDefPart> get_mapping_parts_at( size_t inx );
    bool get_is_hard_coded();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CadAttrMappingDefinition")

   virtual ~CadAttrMappingDefinition();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
