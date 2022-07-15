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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CAEBCITEMREVISION_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CAEBCITEMREVISION_MASTER_HXX

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


class TCSOACLIENTMNGD_API CAEBCItemRevision_Master : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_bc_name();
    const std::string& get_bc_desc();
    const std::string& get_bc_type();
    const std::string& get_geometry();
    const std::string& get_constraint_type();
    const std::string& get_coord_type();
    const std::string& get_components();
    const std::string& get_magnitude();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_owner_form_obj();
    const std::string& get_bc_link_path();
    const std::string& get_bc_eint_form_type();
    const std::string& get_bc_vault_mode();
    const std::string& get_bc_rev_id();
    const std::string& get_bc_rev_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CAEBCItemRevision_Master")

   virtual ~CAEBCItemRevision_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
