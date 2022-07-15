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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CAELOADITEMREVISION_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CAELOADITEMREVISION_MASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API CAELoadItemRevision_Master : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_load_name();
    const std::string& get_load_desc();
    const std::string& get_load_type();
    const std::string& get_geometry();
    const std::string& get_load_component_type();
    const std::string& get_load_component_value();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_owner_form_obj();
    const std::string& get_load_rev_name();
    const std::string& get_load_rev_id();
    const std::string& get_load_link_path();
    const std::string& get_load_eint_form_type();
    const std::string& get_load_vault_mode();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CAELoadItemRevision_Master")

   virtual ~CAELoadItemRevision_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
