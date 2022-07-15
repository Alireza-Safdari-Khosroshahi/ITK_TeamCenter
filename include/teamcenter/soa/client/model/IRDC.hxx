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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IRDC_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IRDC_HXX

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
                class ImanType;
                class Tool;
                class DatasetType;
                class IRDCRender;
                class IRDCNaming;
                class IRDCDerNaming;
                class DerivedObj;
                class SourceObj;


class TCSOACLIENTMNGD_API IRDC : public Teamcenter::Soa::Client::Model::BusinessElement
{
public:
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_app_bus_obj();
    const std::string& get_create_template();
    const std::string& get_export_template();
    const std::string& get_object_template();
    const std::string& get_spec_template();
    bool get_delete_files();
    const std::string& get_der_ds_create();
    const std::string& get_der_files_checkin();
    bool get_ftr_index_create();
    Teamcenter::Soa::Common::AutoPtr<Tool> get_mk_app();
    Teamcenter::Soa::Common::AutoPtr<DatasetType> get_mk_dataset_type_name();
    const std::string& get_mk_default_acl();
    bool get_mk_official();
    bool get_view_mk();
    size_t count_render_objs();
    Teamcenter::Soa::Common::AutoPtr<IRDCRender> get_render_objs_at( size_t inx );
    size_t count_irdc_naming();
    Teamcenter::Soa::Common::AutoPtr<IRDCNaming> get_irdc_naming_at( size_t inx );
    size_t count_irdc_der_naming();
    Teamcenter::Soa::Common::AutoPtr<IRDCDerNaming> get_irdc_der_naming_at( size_t inx );
    size_t count_der_dataset_type_names();
    Teamcenter::Soa::Common::AutoPtr<DerivedObj> get_der_dataset_type_names_at( size_t inx );
    size_t count_src_dataset_type_names();
    Teamcenter::Soa::Common::AutoPtr<SourceObj> get_src_dataset_type_names_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IRDC")

   virtual ~IRDC();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
